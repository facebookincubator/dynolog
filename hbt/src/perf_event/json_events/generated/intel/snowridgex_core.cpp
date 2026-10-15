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
namespace snowridgex_core {
namespace {

/*
  Events from snowridgex_core.json (305 events).

  Supported SKUs:
      - Arch: x86, Model: SNR id: 134
*/
constexpr std::array<StaticEventDef, 11> kAllowlistedEvents{{
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_RETIRED.ALL_BRANCHES",
        .encoding =
            {
                .code = 0xC4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Counts the total number of branch instructions retired for all branch types.",
        .full_desc =
            "Counts the total number of instructions in which the instruction pointer (IP) of the processor is resteered due to a branch instruction and the branch instruction successfully retires.  All branch type instructions are accounted for.",
        .default_sampling_period = 0x30D43ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_RETIRED.ALL_BRANCHES",
        .encoding =
            {
                .code = 0xC5ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Counts the total number of mispredicted branch instructions retired for all branch types.",
        .full_desc =
            "Counts the total number of mispredicted branch instructions retired.  All branch type instructions are accounted for.  Prediction of the branch target address enables the processor to begin executing instructions before the non-speculative execution path is known. The branch prediction unit (BPU) predicts the target address based on the instruction pointer (IP) of the branch and on the execution path through which execution reached this IP.    A branch misprediction occurs when the prediction is wrong, and results in discarding all instructions executed in the speculative path and re-fetching from the correct path.",
        .default_sampling_period = 0x30D43ULL,
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
            "Counts the number of unhalted reference clock cycles at TSC frequency. (Fixed event)",
        .full_desc =
            "Counts the number of reference cycles that the core is not in a halt state. The core enters the halt state when it is running the HLT instruction. This event is not affected by core frequency changes and increments at a fixed frequency that is also used for the Time Stamp Counter (TSC). This event uses fixed counter 2.",
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.WALK_COMPLETED",
        .encoding =
            {
                .code = 0x8ULL,
                .umask = 0xEULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of page walks completed due to load DTLB misses to any page size.",
        .full_desc =
            "Counts the number of page walks completed due to loads (including SW prefetches) whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to any page size. Includes page walks that page fault.",
        .default_sampling_period = 0x30D43ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_STORE_MISSES.WALK_COMPLETED",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0xEULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of page walks completed due to store DTLB misses to any page size.",
        .full_desc =
            "Counts the number of page walks completed due to stores whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to any page size.  Includes page walks that page fault.",
        .default_sampling_period = 0x30D43ULL,
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
        .brief_desc = "Counts the number of instruction cache misses.",
        .full_desc =
            "Counts the number of missed requests to the instruction cache.  The event only counts new cache line accesses, so that multiple back to back fetches to the exact same cache line and byte chunk count as one.  Specifically, the event counts when accesses from sequential code crosses the cache line boundary, or when a branch target is moved to a new line or to a non-sequential byte chunk of the same line.",
        .default_sampling_period = 0x30D43ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISSES.WALK_COMPLETED",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0xEULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of page walks completed due to instruction fetch misses to any page size.",
        .full_desc =
            "Counts the number of page walks completed due to instruction fetches whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to any page size.  Includes page walks that page fault.",
        .default_sampling_period = 0x30D43ULL,
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
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Counts the number of retired loads that are blocked because its address partially overlapped with an older store.",
        .full_desc =
            "Counts the number of retired loads that are blocked because its address partially overlapped with an older store.",
        .default_sampling_period = 0xF4243ULL,
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
            "Counts the number of cacheable memory requests that miss in the LLC. Counts on a per core basis.",
        .full_desc = "Counts the number of cacheable memory requests that miss in the Last Level Cache (LLC). Requests include demand loads, reads for ownership (RFO), instruction fetches and L1 HW prefetches. If the platform has an L3 cache, the LLC is the L3 cache, otherwise it is the L2 cache. Counts on a per core basis.",
        .default_sampling_period = 0x30D43ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_ISSUED.ANY",
        .encoding =
            {
                .code = 0xEULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts the number of uops issued by the front end every cycle.",
        .full_desc =
            "Counts the number of uops issued by the front end every cycle. When 4-uops are requested and only 2-uops are delivered, the event counts 2.  Uops_issued correlates to the number of ROB entries.  If uop takes 2 ROB slots it counts as 2 uops_issued.",
        .default_sampling_period = 0x30D43ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_RETIRED.ALL",
        .encoding =
            {
                .code = 0xC2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Counts the total number of uops retired.",
        .full_desc = "Counts the total number of uops retired.",
        .default_sampling_period = 0x1E8483ULL,
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::
    array<StaticEventDef, 273>
        kFullOnlyEvents{
            {
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BACLEARS.ANY",
                    .encoding =
                        {
                            .code = 0xE6ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the total number of BACLEARS due to all branch types including conditional and unconditional jumps, returns, and indirect branches.",
                    .full_desc =
                        "Counts the total number of BACLEARS, which occur when the Branch Target Buffer (BTB) prediction or lack thereof, was corrected by a later branch predictor in the frontend.  Includes BACLEARS due to all branch types including conditional and unconditional jumps, returns, and indirect branches.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BACLEARS.COND",
                    .encoding =
                        {
                            .code = 0xE6ULL,
                            .umask = 0x10ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of BACLEARS due to a conditional jump.",
                    .full_desc =
                        "Counts the number of BACLEARS due to a conditional jump.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BACLEARS.INDIRECT",
                    .encoding =
                        {
                            .code = 0xE6ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of BACLEARS due to an indirect branch.",
                    .full_desc =
                        "Counts the number of BACLEARS due to an indirect branch.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BACLEARS.RETURN",
                    .encoding =
                        {
                            .code = 0xE6ULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of BACLEARS due to a return branch.",
                    .full_desc =
                        "Counts the number of BACLEARS due to a return branch.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BACLEARS.UNCOND",
                    .encoding =
                        {
                            .code = 0xE6ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of BACLEARS due to a direct, unconditional jump.",
                    .full_desc =
                        "Counts the number of BACLEARS due to a direct, unconditional jump.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_INST_RETIRED.CALL",
                    .encoding =
                        {
                            .code = 0xC4ULL,
                            .umask = 0xF9ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of near CALL branch instructions retired.",
                    .full_desc =
                        "Counts the number of near CALL branch instructions retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_INST_RETIRED.FAR_BRANCH",
                    .encoding =
                        {
                            .code = 0xC4ULL,
                            .umask = 0xBFULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of far branch instructions retired, includes far jump, far call and return, and interrupt call and return.",
                    .full_desc =
                        "Counts the number of far branch instructions retired, includes far jump, far call and return, and interrupt call and return.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_INST_RETIRED.IND_CALL",
                    .encoding =
                        {
                            .code = 0xC4ULL,
                            .umask = 0xFBULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of near indirect CALL branch instructions retired.",
                    .full_desc =
                        "Counts the number of near indirect CALL branch instructions retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_INST_RETIRED.JCC",
                    .encoding =
                        {
                            .code = 0xC4ULL,
                            .umask = 0x7EULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of retired JCC (Jump on Conditional Code) branch instructions retired, includes both taken and not taken branches.",
                    .full_desc =
                        "Counts the number of retired JCC (Jump on Conditional Code) branch instructions retired, includes both taken and not taken branches.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_INST_RETIRED.NON_RETURN_IND",
                    .encoding =
                        {
                            .code = 0xC4ULL,
                            .umask = 0xEBULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of near indirect JMP and near indirect CALL branch instructions retired.",
                    .full_desc =
                        "Counts the number of near indirect JMP and near indirect CALL branch instructions retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_INST_RETIRED.REL_CALL",
                    .encoding =
                        {
                            .code = 0xC4ULL,
                            .umask = 0xFDULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of near relative CALL branch instructions retired.",
                    .full_desc =
                        "Counts the number of near relative CALL branch instructions retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_INST_RETIRED.RETURN",
                    .encoding =
                        {
                            .code = 0xC4ULL,
                            .umask = 0xF7ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of near RET branch instructions retired.",
                    .full_desc =
                        "Counts the number of near RET branch instructions retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_INST_RETIRED.TAKEN_JCC",
                    .encoding =
                        {
                            .code = 0xC4ULL,
                            .umask = 0xFEULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of taken JCC (Jump on Conditional Code) branch instructions retired.",
                    .full_desc =
                        "Counts the number of taken JCC (Jump on Conditional Code) branch instructions retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_MISP_RETIRED.IND_CALL",
                    .encoding =
                        {
                            .code = 0xC5ULL,
                            .umask = 0xFBULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of mispredicted near indirect CALL branch instructions retired.",
                    .full_desc =
                        "Counts the number of mispredicted near indirect CALL branch instructions retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_MISP_RETIRED.JCC",
                    .encoding =
                        {
                            .code = 0xC5ULL,
                            .umask = 0x7EULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of mispredicted JCC (Jump on Conditional Code) branch instructions retired.",
                    .full_desc =
                        "Counts the number of mispredicted JCC (Jump on Conditional Code) branch instructions retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_MISP_RETIRED.NON_RETURN_IND",
                    .encoding =
                        {
                            .code = 0xC5ULL,
                            .umask = 0xEBULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of mispredicted near indirect JMP and near indirect CALL branch instructions retired.",
                    .full_desc =
                        "Counts the number of mispredicted near indirect JMP and near indirect CALL branch instructions retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_MISP_RETIRED.RETURN",
                    .encoding =
                        {
                            .code = 0xC5ULL,
                            .umask = 0xF7ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of mispredicted near RET branch instructions retired.",
                    .full_desc =
                        "Counts the number of mispredicted near RET branch instructions retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BR_MISP_RETIRED.TAKEN_JCC",
                    .encoding =
                        {
                            .code = 0xC5ULL,
                            .umask = 0xFEULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of mispredicted taken JCC (Jump on Conditional Code) branch instructions retired.",
                    .full_desc =
                        "Counts the number of mispredicted taken JCC (Jump on Conditional Code) branch instructions retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BTCLEAR.ANY",
                    .encoding =
                        {
                            .code = 0xE8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Counts the total number of BTCLEARS.",
                    .full_desc =
                        "Counts the total number of BTCLEARS which occurs when the Branch Target Buffer (BTB) predicts a taken branch.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BUS_LOCK.BLOCK_CYCLES",
                    .encoding =
                        {
                            .code = 0x63ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of unhalted cycles a core is blocked due to an accepted lock issued by other cores.",
                    .full_desc =
                        "Counts the number of unhalted cycles a core is blocked due to an accepted lock issued by other cores. Counts on a per core basis.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BUS_LOCK.LOCK_CYCLES",
                    .encoding =
                        {
                            .code = 0x63ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of unhalted cycles a core is blocked due to an accepted lock it issued.",
                    .full_desc =
                        "Counts the number of unhalted cycles a core is blocked due to an accepted lock it issued. Counts on a per core basis.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "BUS_LOCK.SELF_LOCKS",
                    .encoding =
                        {
                            .code = 0x63ULL,
                            .edge = true,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of bus locks a core issued its self (e.g. lock to UC or Split Lock) and does not include cache locks.",
                    .full_desc =
                        "Counts the number of bus locks a core issued its self (e.g. lock to UC or Split Lock) and does not include cache locks. Counts on a per core basis.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "CORE_REJECT_L2Q.ANY",
                    .encoding =
                        {
                            .code = 0x31ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of core requests (demand and L1 prefetchers) rejected by the L2 queue (L2Q) due to a full condition.",
                    .full_desc =
                        "Counts the number of (demand and L1 prefetchers) core requests rejected by the L2 queue (L2Q) due to a full or nearly full condition, which likely indicates back pressure from L2Q.  It also counts requests that would have gone directly to the External Queue (XQ), but are rejected due to a full or nearly full condition, indicating back pressure from the IDI link.  The L2Q may also reject transactions  from a core to ensure fairness between cores, or to delay a cores dirty eviction when the address conflicts incoming external snoops.  (Note that L2 prefetcher requests that are dropped are not counted by this event).  Counts on a per core basis.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "CPU_CLK_UNHALTED.CORE",
                    .encoding =
                        {
                            .code = 0x0ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of unhalted core clock cycles. (Fixed event)",
                    .full_desc =
                        "Counts the number of core cycles while the core is not in a halt state. The core enters the halt state when it is running the HLT instruction. The core frequency may change from time to time. For this reason this event may have a changing ratio with regards to time. This event uses fixed counter 1.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "CPU_CLK_UNHALTED.CORE_P",
                    .encoding =
                        {
                            .code = 0x3CULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of unhalted core clock cycles.",
                    .full_desc =
                        "Counts the number of core cycles while the core is not in a halt state. The core enters the halt state when it is running the HLT instruction. The core frequency may change from time to time. For this reason this event may have a changing ratio with regards to time. This event uses a programmable general purpose performance counter.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "CPU_CLK_UNHALTED.REF",
                    .encoding =
                        {
                            .code = 0x3CULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of unhalted reference clock cycles at TSC frequency.",
                    .full_desc =
                        "Counts the number of reference cycles that the core is not in a halt state. The core enters the halt state when it is running the HLT instruction. This event is not affected by core frequency changes and increments at a fixed frequency that is also used for the Time Stamp Counter (TSC). This event uses fixed counter 2.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "CPU_CLK_UNHALTED.REF_TSC_P",
                    .encoding =
                        {
                            .code = 0x3CULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of unhalted reference clock cycles at TSC frequency.",
                    .full_desc =
                        "Counts the number of reference cycles that the core is not in a halt state. The core enters the halt state when it is running the HLT instruction. This event is not affected by core frequency changes and increments at a fixed frequency that is also used for the Time Stamp Counter (TSC). This event uses a programmable general purpose performance counter.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "CYCLES_DIV_BUSY.FPDIV",
                    .encoding =
                        {
                            .code = 0xCDULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of cycles the floating point divider is busy.",
                    .full_desc =
                        "Counts the number of cycles the floating point divider is busy.  Does not imply a stall waiting for the divider.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "CYCLES_DIV_BUSY.IDIV",
                    .encoding =
                        {
                            .code = 0xCDULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of cycles the integer divider is busy.",
                    .full_desc =
                        "Counts the number of cycles the integer divider is busy.  Does not imply a stall waiting for the divider.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DECODE_RESTRICTION.PREDECODE_WRONG",
                    .encoding =
                        {
                            .code = 0xE9ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of times a decode restriction reduces the decode throughput due to wrong instruction length prediction.",
                    .full_desc =
                        "Counts the number of times a decode restriction reduces the decode throughput due to wrong instruction length prediction.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DL1.DIRTY_EVICTION",
                    .encoding =
                        {
                            .code = 0x51ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of L1D cacheline (dirty) evictions caused by load misses, stores, and prefetches.",
                    .full_desc =
                        "Counts the number of L1D cacheline (dirty) evictions caused by load misses, stores, and prefetches.  Does not count evictions or dirty writebacks caused by snoops.  Does not count a replacement unless a (dirty) line was written back.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_LOAD_MISSES.PDE_CACHE_MISS",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x80ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks due to loads that miss the PDE (Page Directory Entry) cache.",
                    .full_desc =
                        "Counts the number of page walks due to loads that miss the PDE (Page Directory Entry) cache.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_LOAD_MISSES.STLB_HIT",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x20ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of first level TLB misses but second level hits due to a demand load that did not start a page walk. Account for all page sizes. Will result in a DTLB write from STLB.",
                    .full_desc = "Counts the number of first level TLB misses but second level hits due to a demand load that did not start a page walk. Account for all page sizes. Will result in a DTLB write from STLB.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_LOAD_MISSES.WALK_COMPLETED_1G",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks completed due to load DTLB misses to a 1G page.",
                    .full_desc =
                        "Counts the number of page walks completed due to loads (including SW prefetches) whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 1GB pages. Includes page walks that page fault.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_LOAD_MISSES.WALK_COMPLETED_2M_4M",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks completed due to load DTLB misses to a 2M or 4M page.",
                    .full_desc =
                        "Counts the number of page walks completed due to loads (including SW prefetches) whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 2M or 4M pages. Includes page walks that page fault.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_LOAD_MISSES.WALK_COMPLETED_4K",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks completed due to load DTLB misses to a 4K page.",
                    .full_desc =
                        "Counts the number of page walks completed due to loads (including SW prefetches) whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 4K pages. Includes page walks that page fault.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_LOAD_MISSES.WALK_PENDING",
                    .encoding =
                        {
                            .code = 0x8ULL,
                            .umask = 0x10ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks outstanding in the page miss handler (PMH) for demand loads every cycle.",
                    .full_desc =
                        "Counts the number of page walks outstanding in the page miss handler (PMH) for demand loads every cycle.  A page walk is outstanding from start till PMH becomes idle again (ready to serve next walk). Includes EPT-walk intervals.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_STORE_MISSES.PDE_CACHE_MISS",
                    .encoding =
                        {
                            .code = 0x49ULL,
                            .umask = 0x80ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks due to stores that miss the PDE (Page Directory Entry) cache.",
                    .full_desc =
                        "Counts the number of page walks due to stores that miss the PDE (Page Directory Entry) cache.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_STORE_MISSES.STLB_HIT",
                    .encoding =
                        {
                            .code = 0x49ULL,
                            .umask = 0x20ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of first level TLB misses but second level hits due to stores that did not start a page walk. Account for all pages sizes. Will result in a DTLB write from STLB.",
                    .full_desc =
                        "Counts the number of first level TLB misses but second level hits due to stores that did not start a page walk. Account for all pages sizes. Will result in a DTLB write from STLB.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_STORE_MISSES.WALK_COMPLETED_1G",
                    .encoding =
                        {
                            .code = 0x49ULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks completed due to store DTLB misses to a 1G page.",
                    .full_desc =
                        "Counts the number of page walks completed due to stores whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 1G pages.  Includes page walks that page fault.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_STORE_MISSES.WALK_COMPLETED_2M_4M",
                    .encoding =
                        {
                            .code = 0x49ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks completed due to store DTLB misses to a 2M or 4M page.",
                    .full_desc =
                        "Counts the number of page walks completed due to stores whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 2M or 4M pages.  Includes page walks that page fault.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_STORE_MISSES.WALK_COMPLETED_4K",
                    .encoding =
                        {
                            .code = 0x49ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks completed due to store DTLB misses to a 4K page.",
                    .full_desc =
                        "Counts the number of page walks completed due to stores whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 4K pages.  Includes page walks that page fault.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "DTLB_STORE_MISSES.WALK_PENDING",
                    .encoding =
                        {
                            .code = 0x49ULL,
                            .umask = 0x10ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks outstanding in the page miss handler (PMH) for stores every cycle.",
                    .full_desc =
                        "Counts the number of page walks outstanding in the page miss handler (PMH) for stores every cycle.  A page walk is outstanding from start till PMH becomes idle again (ready to serve next walk). Includes EPT-walk intervals.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "EPT.EPDE_HIT",
                    .encoding =
                        {
                            .code = 0x4FULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of Extended Page Directory Entry hits.",
                    .full_desc =
                        "Counts the number of Extended Page Directory Entry hits.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "EPT.EPDE_MISS",
                    .encoding =
                        {
                            .code = 0x4FULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of Extended Page Directory Entry misses.",
                    .full_desc =
                        "Counts the number Extended Page Directory Entry misses.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "EPT.EPDPE_HIT",
                    .encoding =
                        {
                            .code = 0x4FULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of Extended Page Directory Pointer Entry hits.",
                    .full_desc =
                        "Counts the number Extended Page Directory Pointer Entry hits.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "EPT.EPDPE_MISS",
                    .encoding =
                        {
                            .code = 0x4FULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of Extended Page Directory Pointer Entry misses.",
                    .full_desc =
                        "Counts the number Extended Page Directory Pointer Entry misses.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "EPT.WALK_PENDING",
                    .encoding =
                        {
                            .code = 0x4FULL,
                            .umask = 0x10ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks outstanding for an Extended Page table walk including GTLB hits per cycle.",
                    .full_desc =
                        "Counts the number of page walks outstanding for an Extended Page table walk including GTLB hits per cycle.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "HW_INTERRUPTS.MASKED",
                    .encoding =
                        {
                            .code = 0xCBULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of core cycles during which interrupts are masked (disabled).",
                    .full_desc =
                        "Counts the number of core cycles during which interrupts are masked (disabled). Increments by 1 each core cycle that EFLAGS.IF is 0, regardless of whether interrupts are pending or not.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "HW_INTERRUPTS.PENDING_AND_MASKED",
                    .encoding =
                        {
                            .code = 0xCBULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of core cycles during which there are pending interrupts while interrupts are masked (disabled).",
                    .full_desc =
                        "Counts the number of core cycles during which there are pending interrupts while interrupts are masked (disabled). Increments by 1 each core cycle that both EFLAGS.IF is 0 and an INTR is pending (which means the APIC is telling the ROB to cause an INTR). This event does not increment if EFLAGS.IF is 0 but all interrupt in the APICs Interrupt Request Register (IRR) are inhibited by the PPR (thus either by ISRV or TPR)  because in these cases the interrupts would be held up in the APIC and would not be pended to the ROB. This event does count when an interrupt is only inhibited by MOV/POP SS state machines or the STI state machine. These extra inhibits only last for a single instructions and would not be important.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "HW_INTERRUPTS.RECEIVED",
                    .encoding =
                        {
                            .code = 0xCBULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of hardware interrupts received by the processor.",
                    .full_desc =
                        "Counts the number of hardware interrupts received by the processor.",
                    .default_sampling_period = 0xCBULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "ICACHE.ACCESSES",
                    .encoding =
                        {
                            .code = 0x80ULL,
                            .umask = 0x3ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of requests to the instruction cache for one or more bytes of a cache line.",
                    .full_desc =
                        "Counts the total number of requests to the instruction cache.  The event only counts new cache line accesses, so that multiple back to back fetches to the exact same cache line or byte chunk count as one.  Specifically, the event counts when accesses from sequential code crosses the cache line boundary, or when a branch target is moved to a new line or to a non-sequential byte chunk of the same line.",
                    .default_sampling_period = 0x30D43ULL,
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
                        "Counts the number of instruction cache hits.",
                    .full_desc =
                        "Counts the number of requests that hit in the instruction cache.  The event only counts new cache line accesses, so that multiple back to back fetches to the exact same cache line and byte chunk count as one.  Specifically, the event counts when accesses from sequential code crosses the cache line boundary, or when a branch target is moved to a new line or to a non-sequential byte chunk of the same line.",
                    .default_sampling_period = 0x30D43ULL,
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
                    .features =
                        StaticEventDef::
                            IntelFeatures{
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the total number of instructions retired. (Fixed event)",
                    .full_desc =
                        "Counts the total number of instructions that retired. For instructions that consist of multiple uops, this event counts the retirement of the last uop of the instruction. This event continues counting during hardware interrupts, traps, and inside interrupt handlers. This event uses fixed counter 0.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "INST_RETIRED.ANY_P",
                    .encoding =
                        {
                            .code = 0xC0ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::
                            IntelFeatures{
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the total number of instructions retired.",
                    .full_desc =
                        "Counts the total number of instructions that retired. For instructions that consist of multiple uops, this event counts the retirement of the last uop of the instruction. This event continues counting during hardware interrupts, traps, and inside interrupt handlers. This event uses a programmable general purpose performance counter.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "ITLB.FILLS",
                    .encoding =
                        {
                            .code = 0x81ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of times there was an ITLB miss and a new translation was filled into the ITLB.",
                    .full_desc =
                        "Counts the number of times the machine was unable to find a translation in the Instruction Translation Lookaside Buffer (ITLB) and a new translation was filled into the ITLB. The event is speculative in nature, but will not count translations (page walks) that are begun and not finished, or translations that are finished but not filled into the ITLB.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "ITLB_MISSES.PDE_CACHE_MISS",
                    .encoding =
                        {
                            .code = 0x85ULL,
                            .umask = 0x80ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks due to an instruction fetch that miss the PDE (Page Directory Entry) cache.",
                    .full_desc =
                        "Counts the number of page walks due to an instruction fetch that miss the PDE (Page Directory Entry) cache.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "ITLB_MISSES.STLB_HIT",
                    .encoding =
                        {
                            .code = 0x85ULL,
                            .umask = 0x20ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of first level TLB misses but second level hits due to an instruction fetch that did not start a page walk. Account for all pages sizes. Will result in an ITLB write from STLB.",
                    .full_desc =
                        "Counts the number of first level TLB misses but second level hits due to an instruction fetch that did not start a page walk. Account for all pages sizes. Will result in an ITLB write from STLB.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "ITLB_MISSES.WALK_COMPLETED_1G",
                    .encoding =
                        {
                            .code = 0x85ULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks completed due to instruction fetch misses to a 1G page.",
                    .full_desc =
                        "Counts the number of page walks completed due to instruction fetches whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 1G pages.  Includes page walks that page fault.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "ITLB_MISSES.WALK_COMPLETED_2M_4M",
                    .encoding =
                        {
                            .code = 0x85ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks completed due to instruction fetch misses to a 2M or 4M page.",
                    .full_desc =
                        "Counts the number of page walks completed due to instruction fetches whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 2M or 4M pages.  Includes page walks that page fault.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "ITLB_MISSES.WALK_COMPLETED_4K",
                    .encoding =
                        {
                            .code = 0x85ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks completed due to instruction fetch misses to a 4K page.",
                    .full_desc =
                        "Counts the number of page walks completed due to instruction fetches whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 4K pages.  Includes page walks that page fault.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "ITLB_MISSES.WALK_PENDING",
                    .encoding =
                        {
                            .code = 0x85ULL,
                            .umask = 0x10ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of page walks outstanding in the page miss handler (PMH) for instruction fetches every cycle.",
                    .full_desc =
                        "Counts the number of page walks outstanding in the page miss handler (PMH) for instruction fetches every cycle.  A page walk is outstanding from start till PMH becomes idle again (ready to serve next walk).",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "L2_REJECT_XQ.ANY",
                    .encoding =
                        {
                            .code = 0x30ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of demand and prefetch transactions that the External Queue (XQ) rejects due to a full or near full condition.",
                    .full_desc =
                        "Counts the number of demand and prefetch transactions that the External Queue (XQ) rejects due to a full or near full condition which likely indicates back pressure from the IDI link.  The XQ may reject transactions from the L2Q (non-cacheable requests), BBL (L2 misses) and WOB (L2 write-back victims).",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "L2_REQUEST.ALL",
                    .encoding =
                        {
                            .code = 0x24ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the total number of L2 Cache accesses. Counts on a per core basis.",
                    .full_desc =
                        "Counts the total number of L2 Cache Accesses, includes hits, misses, rejects  front door requests for CRd/DRd/RFO/ItoM/L2 Prefetches only.  Counts on a per core basis.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "L2_REQUEST.HIT",
                    .encoding =
                        {
                            .code = 0x24ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of L2 Cache accesses that resulted in a hit. Counts on a per core basis.",
                    .full_desc =
                        "Counts the number of L2 Cache accesses that resulted in a hit from a front door request only (does not include rejects or recycles), Counts on a per core basis.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "L2_REQUEST.MISS",
                    .encoding =
                        {
                            .code = 0x24ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of L2 Cache accesses that resulted in a miss. Counts on a per core basis.",
                    .full_desc =
                        "Counts the number of L2 Cache accesses that resulted in a miss from a front door request only (does not include rejects or recycles). Counts on a per core basis.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "L2_REQUEST.REJECTS",
                    .encoding =
                        {
                            .code = 0x24ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of L2 Cache accesses that miss the L2 and get rejected. Counts on a per core basis.",
                    .full_desc =
                        "Counts the number of L2 Cache accesses that miss the L2 and get BBL reject  short and long rejects (includes those counted in L2_reject_XQ.any). Counts on a per core basis.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "LD_BLOCKS.4K_ALIAS",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::
                            IntelFeatures{
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of retired loads that are blocked because it initially appears to be store forward blocked, but subsequently is shown not to be blocked based on 4K alias check.",
                    .full_desc =
                        "Counts the number of retired loads that are blocked because it initially appears to be store forward blocked, but subsequently is shown not to be blocked based on 4K alias check.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "LD_BLOCKS.ALL",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x10ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::
                            IntelFeatures{
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of retired loads that are blocked for any of the following reasons:  DTLB miss, address alias, store forward or data unknown (includes memory disambiguation blocks and ESP consuming load blocks).",
                    .full_desc =
                        "Counts the number of retired loads that are blocked for any of the following reasons:  DTLB miss, address alias, store forward or data unknown (includes memory disambiguation blocks and ESP consuming load blocks).",
                    .default_sampling_period = 0xF4243ULL,
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
                    .features =
                        StaticEventDef::
                            IntelFeatures{
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of retired loads that are blocked because its address exactly matches an older store whose data is not ready.",
                    .full_desc =
                        "Counts the number of retired loads that are blocked because its address exactly matches an older store whose data is not ready.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "LD_BLOCKS.DTLB_MISS",
                    .encoding =
                        {
                            .code = 0x3ULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::
                            IntelFeatures{
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of retired loads that are blocked due to a first level TLB miss.",
                    .full_desc =
                        "Counts the number of retired loads that are blocked due to a first level TLB miss.",
                    .default_sampling_period = 0xF4243ULL,
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
                        "Counts the number of cacheable memory requests that access the LLC. Counts on a per core basis.",
                    .full_desc =
                        "Counts the number of cacheable memory requests that access the Last Level Cache (LLC). Requests include demand loads, reads for ownership (RFO), instruction fetches and L1 HW prefetches. If the platform has an L3 cache, the LLC is the L3 cache, otherwise it is the L2 cache. Counts on a per core basis.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MACHINE_CLEARS.ANY",
                    .encoding =
                        {
                            .code = 0xC3ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the total number of machine clears for any reason including, but not limited to, memory ordering, memory disambiguation, SMC, and FP assist.",
                    .full_desc =
                        "Counts the total number of machine clears for any reason including, but not limited to, memory ordering, memory disambiguation, SMC, and FP assist.",
                    .default_sampling_period = 0x4E23ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MACHINE_CLEARS.DISAMBIGUATION",
                    .encoding =
                        {
                            .code = 0xC3ULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of machine clears due to memory ordering in which an internal load passes an older store within the same CPU.",
                    .full_desc =
                        "Counts the number of machine clears due to memory ordering in which an internal load passes an older store within the same CPU.",
                    .default_sampling_period = 0x4E23ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MACHINE_CLEARS.FP_ASSIST",
                    .encoding =
                        {
                            .code = 0xC3ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of floating point operations retired that required microcode assist.",
                    .full_desc =
                        "Counts the number of floating point operations retired that required microcode assist, which is not a reflection of the number of FP operations, instructions or uops.",
                    .default_sampling_period = 0x4E23ULL,
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
                        "Counts the number of machine clears due to memory ordering caused by a snoop from an external agent. Does not count internally generated machine clears such as those due to memory disambiguation.",
                    .full_desc =
                        "Counts the number of machine clears due to memory ordering caused by a snoop from an external agent. Does not count internally generated machine clears such as those due to memory disambiguation.",
                    .default_sampling_period = 0x4E23ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MACHINE_CLEARS.PAGE_FAULT",
                    .encoding =
                        {
                            .code = 0xC3ULL,
                            .umask = 0x20ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of machine clears due to a page fault.  Counts both I-Side and D-Side (Loads/Stores) page faults.  A page fault occurs when either the page is not present, or an access violation occurs.",
                    .full_desc =
                        "Counts the number of machine clears due to a page fault.  Counts both I-Side and D-Side (Loads/Stores) page faults.  A page fault occurs when either the page is not present, or an access violation occurs.",
                    .default_sampling_period = 0x4E23ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MACHINE_CLEARS.SMC",
                    .encoding =
                        {
                            .code = 0xC3ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of machine clears due to program modifying data (self modifying code) within 1K of a recently fetched code page.",
                    .full_desc =
                        "Counts the number of machine clears due to program modifying data (self modifying code) within 1K of a recently fetched code page.",
                    .default_sampling_period = 0x4E23ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_BOUND_STALLS.IFETCH",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x38ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of cycles the core is stalled due to an instruction cache or TLB miss which hit in the L2, LLC, DRAM or MMIO (Non-DRAM).",
                    .full_desc =
                        "Counts the number of cycles the core is stalled due to an instruction cache or translation lookaside buffer (TLB) miss which hit in the L2, LLC, DRAM or MMIO (Non-DRAM).",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_BOUND_STALLS.IFETCH_DRAM_HIT",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x20ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of cycles the core is stalled due to an instruction cache or TLB miss which hit in DRAM or MMIO (Non-DRAM).",
                    .full_desc =
                        "Counts the number of cycles the core is stalled due to an instruction cache or translation lookaside buffer (TLB) miss which hit in DRAM or MMIO (non-DRAM).",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_BOUND_STALLS.IFETCH_L2_HIT",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of cycles the core is stalled due to an instruction cache or TLB miss which hit in the L2 cache.",
                    .full_desc =
                        "Counts the number of cycles the core is stalled due to an instruction cache or Translation Lookaside Buffer (TLB) miss which hit in the L2 cache.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_BOUND_STALLS.IFETCH_LLC_HIT",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x10ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of cycles the core is stalled due to an instruction cache or TLB miss which hit in the LLC or other core with HITE/F/M.",
                    .full_desc =
                        "Counts the number of cycles the core is stalled due to an instruction cache or Translation Lookaside Buffer (TLB) miss which hit in the Last Level Cache (LLC) or other core with HITE/F/M.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_BOUND_STALLS.LOAD",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x7ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of cycles the core is stalled due to a demand load miss which hit in the L2, LLC, DRAM or MMIO (Non-DRAM).",
                    .full_desc =
                        "Counts the number of cycles the core is stalled due to a demand load miss which hit in the L2, LLC, DRAM or MMIO (Non-DRAM).",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_BOUND_STALLS.LOAD_DRAM_HIT",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of cycles the core is stalled due to a demand load miss which hit in DRAM or MMIO (Non-DRAM).",
                    .full_desc =
                        "Counts the number of cycles the core is stalled due to a demand load miss which hit in DRAM or MMIO (Non-DRAM).",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_BOUND_STALLS.LOAD_L2_HIT",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of cycles the core is stalled due to a demand load which hit in the L2 cache.",
                    .full_desc =
                        "Counts the number of cycles the core is stalled due to a demand load which hit in the L2 cache.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_BOUND_STALLS.LOAD_LLC_HIT",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of cycles the core is stalled due to a demand load which hit in the LLC or other core with HITE/F/M.",
                    .full_desc =
                        "Counts the number of cycles the core is stalled due to a demand load which hit in the Last Level Cache (LLC) or other core with HITE/F/M.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_BOUND_STALLS.STORE_BUFFER_FULL",
                    .encoding =
                        {
                            .code = 0x34ULL,
                            .umask = 0x40ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of cycles the core is stalled due to a store buffer being full.",
                    .full_desc =
                        "Counts the number of cycles the core is stalled due to a store buffer being full.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_LOAD_UOPS_RETIRED.DRAM_HIT",
                    .encoding =
                        {
                            .code = 0xD1ULL,
                            .umask = 0x80ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::
                            IntelFeatures{
                                .data_la = true,
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of load uops retired that hit in DRAM.",
                    .full_desc =
                        "Counts the number of load uops retired that hit in DRAM.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_LOAD_UOPS_RETIRED.HITM",
                    .encoding =
                        {
                            .code = 0xD1ULL,
                            .umask = 0x20ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::
                            IntelFeatures{
                                .data_la = true,
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of load uops retired that hit in the L3 cache, in which a snoop was required and modified data was forwarded from another core or module.",
                    .full_desc =
                        "Counts the number of load uops retired that hit in the L3 cache, in which a snoop was required and modified data was forwarded from another core or module.",
                    .default_sampling_period = 0x30D43ULL,
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
                        StaticEventDef::
                            IntelFeatures{
                                .data_la = true,
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of load uops retired that hit in the L1 data cache.",
                    .full_desc =
                        "Counts the number of load uops retired that hit in the L1 data cache.",
                    .default_sampling_period = 0x30D43ULL,
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
                        StaticEventDef::
                            IntelFeatures{
                                .data_la = true,
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of load uops retired that miss in the L1 data cache.",
                    .full_desc =
                        "Counts the number of load uops retired that miss in the L1 data cache.",
                    .default_sampling_period = 0x30D43ULL,
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
                        StaticEventDef::
                            IntelFeatures{
                                .data_la = true,
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of load uops retired that hit in the L2 cache.",
                    .full_desc =
                        "Counts the number of load uops retired that hit in the L2 cache.",
                    .default_sampling_period = 0x30D43ULL,
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
                        StaticEventDef::
                            IntelFeatures{
                                .data_la = true,
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of load uops retired that miss in the L2 cache.",
                    .full_desc =
                        "Counts the number of load uops retired that miss in the L2 cache.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_LOAD_UOPS_RETIRED.L3_HIT",
                    .encoding =
                        {
                            .code = 0xD1ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::
                            IntelFeatures{
                                .data_la = true,
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of load uops retired that hit in the L3 cache.",
                    .full_desc =
                        "Counts the number of load uops retired that hit in the L3 cache.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_UOPS_RETIRED.ALL",
                    .encoding =
                        {
                            .code = 0xD0ULL,
                            .umask = 0x83ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::
                            IntelFeatures{
                                .data_la = true,
                                .pebs = 1,
                            },
                    .brief_desc = "Counts the number of memory uops retired.",
                    .full_desc =
                        "Counts the number of memory uops retired.  A single uop that performs both a load AND a store will be counted as 1, not 2 (e.g. ADD [mem], CONST)",
                    .default_sampling_period = 0x30D43ULL,
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
                        StaticEventDef::
                            IntelFeatures{
                                .data_la = true,
                                .pebs = 1,
                            },
                    .brief_desc = "Counts the number of load uops retired.",
                    .full_desc =
                        "Counts the total number of load uops retired.",
                    .default_sampling_period = 0x30D43ULL,
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
                        StaticEventDef::
                            IntelFeatures{
                                .data_la = true,
                                .pebs = 1,
                            },
                    .brief_desc = "Counts the number of store uops retired.",
                    .full_desc =
                        "Counts the total number of store uops retired.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_UOPS_RETIRED.DTLB_MISS",
                    .encoding =
                        {
                            .code = 0xD0ULL,
                            .umask = 0x13ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::
                            IntelFeatures{
                                .data_la = true,
                                .pebs = 1,
                            },
                    .brief_desc =
                        "Counts the number of memory uops retired that missed in the second level TLB.",
                    .full_desc =
                        "Counts the number of memory uops retired that missed in the second level TLB.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_UOPS_RETIRED.DTLB_MISS_LOADS",
                    .encoding =
                        {
                            .code = 0xD0ULL,
                            .umask = 0x11ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .data_la = true,
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of load uops retired that miss in the second Level TLB.",
                    .full_desc =
                        "Counts the number of load uops retired that miss in the second Level TLB.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_UOPS_RETIRED.DTLB_MISS_STORES",
                    .encoding =
                        {
                            .code = 0xD0ULL,
                            .umask = 0x12ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .data_la = true,
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of store uops retired that miss in the second level TLB.",
                    .full_desc =
                        "Counts the number of store uops retired that miss in the second level TLB.",
                    .default_sampling_period = 0x30D43ULL,
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
                            .data_la = true,
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of load uops retired that performed one or more locks.",
                    .full_desc =
                        "Counts the number of load uops retired that performed one or more locks.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MEM_UOPS_RETIRED.SPLIT",
                    .encoding =
                        {
                            .code = 0xD0ULL,
                            .umask = 0x43ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .data_la = true,
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of memory uops retired that were splits.",
                    .full_desc =
                        "Counts the number of memory uops retired that were splits.",
                    .default_sampling_period = 0x30D43ULL,
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
                            .data_la = true,
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of retired split load uops.",
                    .full_desc =
                        "Counts the number of retired split load uops.",
                    .default_sampling_period = 0x30D43ULL,
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
                            .data_la = true,
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of retired split store uops.",
                    .full_desc =
                        "Counts the number of retired split store uops.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MISALIGN_MEM_REF.LOAD_PAGE_SPLIT",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of misaligned load uops that are 4K page splits.",
                    .full_desc =
                        "Counts the number of misaligned load uops that are 4K page splits.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "MISALIGN_MEM_REF.STORE_PAGE_SPLIT",
                    .encoding =
                        {
                            .code = 0x13ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of misaligned store uops that are 4K page splits.",
                    .full_desc =
                        "Counts the number of misaligned store uops that are 4K page splits.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that have any type of response.",
                    .full_desc =
                        "Counts all code reads that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that were supplied by DRAM.",
                    .full_desc =
                        "Counts all code reads that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1F803C0044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts all code reads that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.L3_HIT.SNOOP_HITM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10003C0044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .full_desc =
                        "Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.L3_HIT.SNOOP_HIT_NO_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x4003C0044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .full_desc =
                        "Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8003C0044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .full_desc =
                        "Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.L3_HIT.SNOOP_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2003C0044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .full_desc =
                        "Counts all code reads that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.L3_HIT.SNOOP_NOT_NEEDED",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1003C0044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .full_desc =
                        "Counts all code reads that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts all code reads that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts all code reads that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.LOCAL_DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that were supplied by DRAM.",
                    .full_desc =
                        "Counts all code reads that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.ALL_CODE_RD.OUTSTANDING",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8000000000000044ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all code reads that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .full_desc =
                        "Counts all code reads that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.COREWB_M.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x3000000010000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writebacks from L1 cache and L2 cache that have any type of response.",
                    .full_desc =
                        "Counts modified writebacks from L1 cache and L2 cache that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.COREWB_M.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x3001F803C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writebacks from L1 cache and L2 cache that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts modified writebacks from L1 cache and L2 cache that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.COREWB_M.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x3002184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writebacks from L1 cache and L2 cache that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts modified writebacks from L1 cache and L2 cache that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.COREWB_M.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x3002184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writebacks from L1 cache and L2 cache that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts modified writebacks from L1 cache and L2 cache that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.COREWB_M.OUTSTANDING",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8003000000000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writebacks from L1 cache and L2 cache that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .full_desc =
                        "Counts modified writebacks from L1 cache and L2 cache that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_CODE_RD.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10004ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that have any type of response.",
                    .full_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_CODE_RD.DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000004ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM.",
                    .full_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_CODE_RD.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1F803C0004ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_HITM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10003C0004ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .full_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_HIT_NO_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x4003C0004ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .full_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8003C0004ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .full_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2003C0004ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .full_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_NOT_NEEDED",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1003C0004ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .full_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_CODE_RD.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000004ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_CODE_RD.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000004ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_CODE_RD.LOCAL_DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000004ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM.",
                    .full_desc =
                        "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_DATA_AND_L1PF_RD.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that have any type of response.",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_DATA_AND_L1PF_RD.DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by DRAM.",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1F803C0001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HITM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10003C0001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HIT_NO_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x4003C0001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id =
                        "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8003C0001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2003C0001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_NOT_NEEDED",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1003C0001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_DATA_AND_L1PF_RD.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_DATA_AND_L1PF_RD.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_DATA_AND_L1PF_RD.LOCAL_DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by DRAM.",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_DATA_AND_L1PF_RD.OUTSTANDING",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8000000000000001ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .full_desc =
                        "Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that have any type of response.",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM.",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1F803C0002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.L3_HIT.SNOOP_HITM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10003C0002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.L3_HIT.SNOOP_HIT_NO_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x4003C0002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8003C0002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.L3_HIT.SNOOP_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2003C0002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.L3_HIT.SNOOP_NOT_NEEDED",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1003C0002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.LOCAL_DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM.",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.DEMAND_RFO.OUTSTANDING",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8000000000000002ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .full_desc =
                        "Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.FULL_STREAMING_WR.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x800000010000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores which modify a full 64 byte cacheline that have any type of response.",
                    .full_desc =
                        "Counts streaming stores which modify a full 64 byte cacheline that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.FULL_STREAMING_WR.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x801F803C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores which modify a full 64 byte cacheline that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts streaming stores which modify a full 64 byte cacheline that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.FULL_STREAMING_WR.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x802184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores which modify a full 64 byte cacheline that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts streaming stores which modify a full 64 byte cacheline that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.FULL_STREAMING_WR.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x802184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores which modify a full 64 byte cacheline that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts streaming stores which modify a full 64 byte cacheline that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L1D_AND_SWPF.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10400ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L1 data cache hardware prefetches and software prefetches (except PREFETCHW and PFRFO) that have any type of response.",
                    .full_desc =
                        "Counts L1 data cache hardware prefetches and software prefetches (except PREFETCHW and PFRFO) that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L1D_AND_SWPF.L3_HIT.SNOOP_HITM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10003C0400ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L1 data cache hardware prefetches and software prefetches (except PREFETCHW and PFRFO) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .full_desc =
                        "Counts L1 data cache hardware prefetches and software prefetches (except PREFETCHW and PFRFO) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that have any type of response.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by DRAM.",
                    .full_desc = "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1F803C0040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.L3_HIT.SNOOP_HITM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10003C0040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.L3_HIT.SNOOP_HIT_NO_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x4003C0040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8003C0040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.L3_HIT.SNOOP_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2003C0040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.L3_HIT.SNOOP_NOT_NEEDED",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1003C0040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.LOCAL_DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by DRAM.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_CODE_RD.OUTSTANDING",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8000000000000040ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .full_desc =
                        "Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_DATA_RD.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10010ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that have any type of response.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_DATA_RD.DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000010ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by DRAM.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_DATA_RD.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1F803C0010ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_HITM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10003C0010ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_HIT_NO_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x4003C0010ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8003C0010ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2003C0010ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_NOT_NEEDED",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1003C0010ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_DATA_RD.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000010ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_DATA_RD.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000010ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_DATA_RD.LOCAL_DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000010ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by DRAM.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that have any type of response.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by DRAM.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1F803C0020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_HITM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10003C0020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_HIT_NO_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x4003C0020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8003C0020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2003C0020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_NOT_NEEDED",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1003C0020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.LOCAL_DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by DRAM.",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.HWPF_L2_RFO.OUTSTANDING",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8000000000000020ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .full_desc =
                        "Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.L1WB_M.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1000000010000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writebacks from L1 cache that miss the L2 cache that have any type of response.",
                    .full_desc =
                        "Counts modified writebacks from L1 cache that miss the L2 cache that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.L1WB_M.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1001F803C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writebacks from L1 cache that miss the L2 cache that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts modified writebacks from L1 cache that miss the L2 cache that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.L1WB_M.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1002184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writebacks from L1 cache that miss the L2 cache that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts modified writebacks from L1 cache that miss the L2 cache that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.L1WB_M.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1002184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writebacks from L1 cache that miss the L2 cache that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts modified writebacks from L1 cache that miss the L2 cache that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.L2WB_M.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2000000010000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writeBacks from L2 cache that miss the L3 cache that have any type of response.",
                    .full_desc =
                        "Counts modified writeBacks from L2 cache that miss the L3 cache that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.L2WB_M.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2001F803C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writeBacks from L2 cache that miss the L3 cache that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts modified writeBacks from L2 cache that miss the L3 cache that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.L2WB_M.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2002184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writeBacks from L2 cache that miss the L3 cache that were not supplied by the L3 cache.",
                    .full_desc = "Counts modified writeBacks from L2 cache that miss the L3 cache that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.L2WB_M.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2002184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts modified writeBacks from L2 cache that miss the L3 cache that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts modified writeBacks from L2 cache that miss the L3 cache that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.OTHER.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x18000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts miscellaneous requests, such as I/O accesses, that have any type of response.",
                    .full_desc =
                        "Counts miscellaneous requests, such as I/O accesses, that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.OTHER.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184008000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts miscellaneous requests, such as I/O accesses, that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts miscellaneous requests, such as I/O accesses, that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.OTHER.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184008000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts miscellaneous requests, such as I/O accesses, that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts miscellaneous requests, such as I/O accesses, that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.PARTIAL_STREAMING_WR.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x400000010000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores which modify only part of a 64 byte cacheline that have any type of response.",
                    .full_desc =
                        "Counts streaming stores which modify only part of a 64 byte cacheline that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.PARTIAL_STREAMING_WR.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x401F803C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores which modify only part of a 64 byte cacheline that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts streaming stores which modify only part of a 64 byte cacheline that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.PARTIAL_STREAMING_WR.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x402184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores which modify only part of a 64 byte cacheline that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts streaming stores which modify only part of a 64 byte cacheline that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.PARTIAL_STREAMING_WR.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x402184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores which modify only part of a 64 byte cacheline that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts streaming stores which modify only part of a 64 byte cacheline that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.PREFETCHES.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10470ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all hardware and software prefetches that have any type of response.",
                    .full_desc =
                        "Counts all hardware and software prefetches that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.PREFETCHES.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000470ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all hardware and software prefetches that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts all hardware and software prefetches that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that have any type of response.",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM.",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1F803C0477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.L3_HIT.SNOOP_HITM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10003C0477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.L3_HIT.SNOOP_HIT_NO_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x4003C0477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.L3_HIT.SNOOP_HIT_WITH_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8003C0477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.L3_HIT.SNOOP_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2003C0477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.L3_HIT.SNOOP_NOT_NEEDED",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1003C0477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.LOCAL_DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x184000477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM.",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.READS_TO_CORE.OUTSTANDING",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8000000000000477ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .full_desc =
                        "Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.STREAMING_WR.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x10800ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores that have any type of response.",
                    .full_desc =
                        "Counts streaming stores that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.STREAMING_WR.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1F803C0800ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts streaming stores that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.STREAMING_WR.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000800ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts streaming stores that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.STREAMING_WR.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x2184000800ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts streaming stores that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts streaming stores that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x100000010000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that have any type of response.",
                    .full_desc =
                        "Counts uncached memory reads that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x100184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that were supplied by DRAM.",
                    .full_desc =
                        "Counts uncached memory reads that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x101F803C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.L3_HIT.SNOOP_HITM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1010003C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .full_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.L3_HIT.SNOOP_HIT_NO_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1004003C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .full_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1008003C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .full_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.L3_HIT.SNOOP_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1002003C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .full_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent but the snoop missed.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.L3_HIT.SNOOP_NOT_NEEDED",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x1001003C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .full_desc =
                        "Counts uncached memory reads that were supplied by the L3 cache where no snoop was needed to satisfy the request.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x102184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts uncached memory reads that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x102184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts uncached memory reads that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.LOCAL_DRAM",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x100184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that were supplied by DRAM.",
                    .full_desc =
                        "Counts uncached memory reads that were supplied by DRAM.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_RD.OUTSTANDING",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x8000100000000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory reads that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .full_desc =
                        "Counts uncached memory reads that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_WR.ANY_RESPONSE",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x200000010000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory writes that have any type of response.",
                    .full_desc =
                        "Counts uncached memory writes that have any type of response.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_WR.L3_HIT",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x201F803C0000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory writes that were supplied by the L3 cache.",
                    .full_desc =
                        "Counts uncached memory writes that were supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_WR.L3_MISS",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x202184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory writes that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts uncached memory writes that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "OCR.UC_WR.L3_MISS_LOCAL",
                    .encoding =
                        {
                            .code = 0xB7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x202184000000ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts uncached memory writes that were not supplied by the L3 cache.",
                    .full_desc =
                        "Counts uncached memory writes that were not supplied by the L3 cache.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_BAD_SPECULATION.ALL",
                    .encoding =
                        {
                            .code = 0x73ULL,
                            .umask = 0x6ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear.",
                    .full_desc =
                        "Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear. Only issue slots wasted due to fast nukes such as memory ordering nukes are counted. Other nukes are not accounted for. Counts all issue slots blocked during this recovery window including relevant microcode flows and while uops are not yet available in the instruction queue (IQ) even if an FE_bound event occurs during this period. Also includes the issue slots that were consumed by the backend but were thrown away because they were younger than the mispredict or machine clear.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_BAD_SPECULATION.FASTNUKE",
                    .encoding =
                        {
                            .code = 0x73ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to fast nukes such as memory ordering and memory disambiguation machine clears.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to fast nukes such as memory ordering and memory disambiguation machine clears.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_BAD_SPECULATION.MACHINE_CLEARS",
                    .encoding =
                        {
                            .code = 0x73ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a machine clear (nuke) of any kind including memory ordering and memory disambiguation.",
                    .full_desc =
                        "Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a machine clear (nuke) of any kind including memory ordering and memory disambiguation.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_BAD_SPECULATION.MISPREDICT",
                    .encoding =
                        {
                            .code = 0x73ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to branch mispredicts.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to branch mispredicts.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_BE_BOUND.ALL",
                    .encoding =
                        {
                            .code = 0x74ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the total number of issue slots every cycle that were not consumed by the backend due to backend stalls.",
                    .full_desc =
                        "Counts the total number of issue slots every cycle that were not consumed by the backend due to backend stalls.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_BE_BOUND.ALLOC_RESTRICTIONS",
                    .encoding =
                        {
                            .code = 0x74ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to certain allocation restrictions.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to certain allocation restrictions.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_BE_BOUND.MEM_SCHEDULER",
                    .encoding =
                        {
                            .code = 0x74ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to memory reservation stalls in which a scheduler is not able to accept uops.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to memory reservation stalls in which a scheduler is not able to accept uops.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_BE_BOUND.NON_MEM_SCHEDULER",
                    .encoding =
                        {
                            .code = 0x74ULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to IEC or FPC RAT stalls, which can be due to FIQ or IEC reservation stalls in which the integer, floating point or SIMD scheduler is not able to accept uops.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to IEC or FPC RAT stalls, which can be due to FIQ or IEC reservation stalls in which the integer, floating point or SIMD scheduler is not able to accept uops.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_BE_BOUND.REGISTER",
                    .encoding =
                        {
                            .code = 0x74ULL,
                            .umask = 0x20ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to the physical register file unable to accept an entry (marble stalls).",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to the physical register file unable to accept an entry (marble stalls).",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_BE_BOUND.REORDER_BUFFER",
                    .encoding =
                        {
                            .code = 0x74ULL,
                            .umask = 0x40ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to the reorder buffer being full (ROB stalls).",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to the reorder buffer being full (ROB stalls).",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_BE_BOUND.SERIALIZATION",
                    .encoding =
                        {
                            .code = 0x74ULL,
                            .umask = 0x10ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to scoreboards from the instruction queue (IQ), jump execution unit (JEU), or microcode sequencer (MS).",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not consumed by the backend due to scoreboards from the instruction queue (IQ), jump execution unit (JEU), or microcode sequencer (MS).",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_FE_BOUND.ALL",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the total number of issue slots every cycle that were not consumed by the backend due to frontend stalls.",
                    .full_desc =
                        "Counts the total number of issue slots every cycle that were not consumed by the backend due to frontend stalls.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_FE_BOUND.BRANCH_DETECT",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to BACLEARS.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to BACLEARS, which occurs when the Branch Target Buffer (BTB) prediction or lack thereof, was corrected by a later branch predictor in the frontend. Includes BACLEARS due to all branch types including conditional and unconditional jumps, returns, and indirect branches.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_FE_BOUND.BRANCH_RESTEER",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x40ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to BTCLEARS.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to BTCLEARS, which occurs when the Branch Target Buffer (BTB) predicts a taken branch.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_FE_BOUND.CISC",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to the microcode sequencer (MS).",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to the microcode sequencer (MS).",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_FE_BOUND.DECODE",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to decode stalls.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to decode stalls.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_FE_BOUND.ICACHE",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x20ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to instruction cache misses.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to instruction cache misses.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_FE_BOUND.ITLB",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x10ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to ITLB misses.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to Instruction Table Lookaside Buffer (ITLB) misses.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_FE_BOUND.OTHER",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x80ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to other common frontend stalls not categorized.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to other common frontend stalls not categorized.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_FE_BOUND.PREDECODE",
                    .encoding =
                        {
                            .code = 0x71ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to wrong predecodes.",
                    .full_desc =
                        "Counts the number of issue slots every cycle that were not delivered by the frontend due to wrong predecodes.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "TOPDOWN_RETIRING.ALL",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the total number of consumed retirement slots.",
                    .full_desc =
                        "Counts the total number of consumed retirement slots.",
                    .default_sampling_period = 0xF4243ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "UOPS_RETIRED.FPDIV",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of floating point divide uops retired (x87 and SSE, including x87 sqrt).",
                    .full_desc =
                        "Counts the number of floating point divide uops retired (x87 and SSE, including x87 sqrt).",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "UOPS_RETIRED.IDIV",
                    .encoding =
                        {
                            .code = 0xC2ULL,
                            .umask = 0x10ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features =
                        StaticEventDef::IntelFeatures{
                            .pebs = 1,
                        },
                    .brief_desc =
                        "Counts the number of integer divide uops retired.",
                    .full_desc =
                        "Counts the number of integer divide uops retired.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "UOPS_RETIRED.MS",
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
                        "Counts the number of uops that are from complex flows issued by the micro-sequencer (MS).",
                    .full_desc =
                        "Counts the number of uops that are from complex flows issued by the Microcode Sequencer (MS). This includes uops from flows due to complex instructions, faults, assists, and inserted flows.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "UOPS_RETIRED.X87",
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
                        "Counts the number of x87 uops retired, includes those in MS flows.",
                    .full_desc =
                        "Counts the number of x87 uops retired, includes those in MS flows.",
                    .default_sampling_period = 0x1E8483ULL,
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

} // namespace snowridgex_core
} // namespace facebook::hbt::perf_event::generated
