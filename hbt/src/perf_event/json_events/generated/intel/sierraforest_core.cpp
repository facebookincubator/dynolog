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
namespace sierraforest_core {
namespace {

/*
  Events from sierraforest_core.json (160 events).

  Supported SKUs:
      - Arch: x86, Model: SRF id: 175
*/
constexpr std::array<StaticEventDef, 19>
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
                .features = StaticEventDef::IntelFeatures{},
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
                    "Fixed Counter: Counts the number of unhalted reference clock cycles",
                .full_desc =
                    "Fixed Counter: Counts the number of unhalted reference clock cycles",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Fixed Counter: Counts the number of unhalted core clock cycles",
                .full_desc =
                    "Fixed Counter: Counts the number of unhalted core clock cycles",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the number of unhalted core clock cycles [This event is alias to CPU_CLK_UNHALTED.CORE_P]",
                .full_desc =
                    "Counts the number of unhalted core clock cycles [This event is alias to CPU_CLK_UNHALTED.CORE_P]",
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
                    "Counts the number of page walks completed due to load DTLB misses.",
                .full_desc =
                    "Counts the number of page walks completed due to load DTLB misses.",
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
                    "Counts the number of page walks completed due to store DTLB misses to a 1G page.",
                .full_desc =
                    "Counts the number of page walks completed due to store DTLB misses to a 1G page.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_FLOPS_RETIRED.FP32",
                .encoding =
                    {
                        .code = 0xC8ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of floating point operations that produce 32 bit single precision results [This event is alias to FP_FLOPS_RETIRED.SP]",
                .full_desc =
                    "Counts the number of floating point operations that produce 32 bit single precision results [This event is alias to FP_FLOPS_RETIRED.SP]",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_FLOPS_RETIRED.FP64",
                .encoding =
                    {
                        .code = 0xC8ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of floating point operations that produce 64 bit double precision results [This event is alias to FP_FLOPS_RETIRED.DP]",
                .full_desc =
                    "Counts the number of floating point operations that produce 64 bit double precision results [This event is alias to FP_FLOPS_RETIRED.DP]",
                .default_sampling_period = 0xF4243ULL,
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
                    "Counts every time the code stream enters into a new cache line by walking sequential from the previous line or being redirected by a jump and the instruction cache registers bytes are not present. -",
                .full_desc =
                    "Counts every time the code stream enters into a new cache line by walking sequential from the previous line or being redirected by a jump and the instruction cache registers bytes are not present. -",
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
                .features = StaticEventDef::IntelFeatures{},
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
                .full_desc =
                    "Counts the number of cacheable memory requests that miss in the Last Level Cache (LLC). Requests include demand loads, reads for ownership (RFO), instruction fetches and L1 HW prefetches. If the core has access to an L3 cache, the LLC is the L3 cache, otherwise it is the L2 cache. Counts on a per core basis.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN_BAD_SPECULATION.ALL_P",
                .encoding =
                    {
                        .code = 0x73ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear. [This event is alias to TOPDOWN_BAD_SPECULATION.ALL]",
                .full_desc =
                    "Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear. Only issue slots wasted due to fast nukes such as memory ordering nukes are counted. Other nukes are not accounted for. Counts all issue slots blocked during this recovery window, including relevant microcode flows, and while uops are not yet available in the instruction queue (IQ) or until an FE_BOUND event occurs besides OTHER and CISC. Also includes the issue slots that were consumed by the backend but were thrown away because they were younger than the mispredict or machine clear. [This event is alias to TOPDOWN_BAD_SPECULATION.ALL]",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN_BE_BOUND.ALL_P",
                .encoding =
                    {
                        .code = 0x74ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of retirement slots not consumed due to backend stalls [This event is alias to TOPDOWN_BE_BOUND.ALL]",
                .full_desc =
                    "Counts the number of retirement slots not consumed due to backend stalls [This event is alias to TOPDOWN_BE_BOUND.ALL]",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN_FE_BOUND.ALL_P",
                .encoding =
                    {
                        .code = 0x71ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of retirement slots not consumed due to front end stalls [This event is alias to TOPDOWN_FE_BOUND.ALL]",
                .full_desc =
                    "Counts the number of retirement slots not consumed due to front end stalls [This event is alias to TOPDOWN_FE_BOUND.ALL]",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN_RETIRING.ALL_P",
                .encoding =
                    {
                        .code = 0x72ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of consumed retirement slots. [This event is alias to TOPDOWN_RETIRING.ALL]",
                .full_desc =
                    "Counts the number of consumed retirement slots. [This event is alias to TOPDOWN_RETIRING.ALL]",
                .default_sampling_period = 0xF4243ULL,
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
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_RETIRED.ALL",
                .encoding =
                    {
                        .code = 0xC2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts the total number of uops retired.",
                .full_desc = "Counts the total number of uops retired.",
                .default_sampling_period = 0x1E8483ULL,
            },
        }};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 136>
    kFullOnlyEvents{
        {
            {
                .pmu_type = PmuType::cpu,
                .id = "ARITH.DIV_ACTIVE",
                .encoding =
                    {
                        .code = 0xCDULL,
                        .umask = 0x3ULL,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles when any of the floating point or integer dividers are active.",
                .full_desc =
                    "Counts the number of cycles when any of the floating point or integer dividers are active.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "ARITH.FPDIV_ACTIVE",
                .encoding =
                    {
                        .code = 0xCDULL,
                        .umask = 0x2ULL,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles when any of the floating point dividers are active.",
                .full_desc =
                    "Counts the number of cycles when any of the floating point dividers are active.",
                .default_sampling_period = 0xF4243ULL,
            },
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
                .id = "BR_INST_RETIRED.COND",
                .encoding =
                    {
                        .code = 0xC4ULL,
                        .umask = 0x7EULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of retired JCC (Jump on Conditional Code) branch instructions retired, includes both taken and not taken branches.",
                .full_desc =
                    "Counts the number of retired JCC (Jump on Conditional Code) branch instructions retired, includes both taken and not taken branches.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_INST_RETIRED.COND_TAKEN",
                .encoding =
                    {
                        .code = 0xC4ULL,
                        .umask = 0xFEULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of taken JCC (Jump on Conditional Code) branch instructions retired.",
                .full_desc =
                    "Counts the number of taken JCC (Jump on Conditional Code) branch instructions retired.",
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of far branch instructions retired, includes far jump, far call and return, and interrupt call and return.",
                .full_desc =
                    "Counts the number of far branch instructions retired, includes far jump, far call and return, and interrupt call and return.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_INST_RETIRED.INDIRECT",
                .encoding =
                    {
                        .code = 0xC4ULL,
                        .umask = 0xEBULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of near indirect JMP and near indirect CALL branch instructions retired.",
                .full_desc =
                    "Counts the number of near indirect JMP and near indirect CALL branch instructions retired.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_INST_RETIRED.INDIRECT_CALL",
                .encoding =
                    {
                        .code = 0xC4ULL,
                        .umask = 0xFBULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of near indirect CALL branch instructions retired.",
                .full_desc =
                    "Counts the number of near indirect CALL branch instructions retired.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_INST_RETIRED.NEAR_CALL",
                .encoding =
                    {
                        .code = 0xC4ULL,
                        .umask = 0xF9ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of near CALL branch instructions retired.",
                .full_desc =
                    "Counts the number of near CALL branch instructions retired.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_INST_RETIRED.NEAR_RETURN",
                .encoding =
                    {
                        .code = 0xC4ULL,
                        .umask = 0xF7ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of near RET branch instructions retired.",
                .full_desc =
                    "Counts the number of near RET branch instructions retired.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_MISP_RETIRED.COND",
                .encoding =
                    {
                        .code = 0xC5ULL,
                        .umask = 0x7EULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of mispredicted JCC (Jump on Conditional Code) branch instructions retired.",
                .full_desc =
                    "Counts the number of mispredicted JCC (Jump on Conditional Code) branch instructions retired.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_MISP_RETIRED.COND_TAKEN",
                .encoding =
                    {
                        .code = 0xC5ULL,
                        .umask = 0xFEULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of mispredicted taken JCC (Jump on Conditional Code) branch instructions retired.",
                .full_desc =
                    "Counts the number of mispredicted taken JCC (Jump on Conditional Code) branch instructions retired.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_MISP_RETIRED.INDIRECT",
                .encoding =
                    {
                        .code = 0xC5ULL,
                        .umask = 0xEBULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of mispredicted near indirect JMP and near indirect CALL branch instructions retired.",
                .full_desc =
                    "Counts the number of mispredicted near indirect JMP and near indirect CALL branch instructions retired.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_MISP_RETIRED.INDIRECT_CALL",
                .encoding =
                    {
                        .code = 0xC5ULL,
                        .umask = 0xFBULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of mispredicted near indirect CALL branch instructions retired.",
                .full_desc =
                    "Counts the number of mispredicted near indirect CALL branch instructions retired.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_MISP_RETIRED.NEAR_TAKEN",
                .encoding =
                    {
                        .code = 0xC5ULL,
                        .umask = 0x80ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of mispredicted near taken branch instructions retired.",
                .full_desc =
                    "Counts the number of mispredicted near taken branch instructions retired.",
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of mispredicted near RET branch instructions retired.",
                .full_desc =
                    "Counts the number of mispredicted near RET branch instructions retired.",
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
                    "Fixed Counter: Counts the number of unhalted core clock cycles",
                .full_desc =
                    "Fixed Counter: Counts the number of unhalted core clock cycles",
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
                    "Counts the number of unhalted core clock cycles [This event is alias to CPU_CLK_UNHALTED.THREAD_P]",
                .full_desc =
                    "Counts the number of unhalted core clock cycles [This event is alias to CPU_CLK_UNHALTED.THREAD_P]",
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
                .id = "DTLB_LOAD_MISSES.STLB_HIT",
                .encoding =
                    {
                        .code = 0x8ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of first level TLB misses but second level hits due to a demand load that did not start a page walk. Accounts for all page sizes. Will result in a DTLB write from STLB.",
                .full_desc =
                    "Counts the number of first level TLB misses but second level hits due to a demand load that did not start a page walk. Accounts for all page sizes. Will result in a DTLB write from STLB.",
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
                    "Counts the number of page walks outstanding for Loads (demand or SW prefetch) in PMH every cycle.",
                .full_desc =
                    "Counts the number of page walks outstanding for Loads (demand or SW prefetch) in PMH every cycle.  A PMH page walk is outstanding from page walk start till PMH becomes idle again (ready to serve next walk). Includes EPT-walk intervals.",
                .default_sampling_period = 0x30D43ULL,
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
                    "Counts the number of first level TLB misses but second level hits due to stores that did not start a page walk. Accounts for all pages sizes. Will result in a DTLB write from STLB.",
                .full_desc =
                    "Counts the number of first level TLB misses but second level hits due to stores that did not start a page walk. Accounts for all pages sizes. Will result in a DTLB write from STLB.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the number of page walks outstanding in the page miss handler (PMH) for stores every cycle. A PMH page walk is outstanding from page walk start till PMH becomes idle again (ready to serve next walk). Includes EPT-walk intervals.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_FLOPS_RETIRED.ALL",
                .encoding =
                    {
                        .code = 0xC8ULL,
                        .umask = 0x3ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of all types of floating point operations per uop with all default weighting",
                .full_desc =
                    "Counts the number of all types of floating point operations per uop with all default weighting",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_INST_RETIRED.128B_DP",
                .encoding =
                    {
                        .code = 0xC7ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total number of  floating point retired instructions.",
                .full_desc =
                    "Counts the total number of  floating point retired instructions.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_INST_RETIRED.128B_SP",
                .encoding =
                    {
                        .code = 0xC7ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of retired instructions whose sources are a packed 128 bit single precision floating point. This may be SSE or AVX.128 operations.",
                .full_desc =
                    "Counts the number of retired instructions whose sources are a packed 128 bit single precision floating point. This may be SSE or AVX.128 operations.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_INST_RETIRED.256B_DP",
                .encoding =
                    {
                        .code = 0xC7ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of retired instructions whose sources are a packed 256 bit double precision floating point.",
                .full_desc =
                    "Counts the number of retired instructions whose sources are a packed 256 bit double precision floating point.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_INST_RETIRED.32B_SP",
                .encoding =
                    {
                        .code = 0xC7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of retired instructions whose sources are a scalar 32bit single precision floating point.",
                .full_desc =
                    "Counts the number of retired instructions whose sources are a scalar 32bit single precision floating point.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_INST_RETIRED.64B_DP",
                .encoding =
                    {
                        .code = 0xC7ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of retired instructions whose sources are a scalar 64 bit double precision floating point.",
                .full_desc =
                    "Counts the number of retired instructions whose sources are a scalar 64 bit double precision floating point.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.ITLB_MISS",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of instructions retired that were tagged because empty issue slots were seen before the uop due to ITLB miss",
                .full_desc =
                    "Counts the number of instructions retired that were tagged because empty issue slots were seen before the uop due to ITLB miss",
                .default_sampling_period = 0xF4243ULL,
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
                    "Counts every time the code stream enters into a new cache line by walking sequential from the previous line or being redirected by a jump.",
                .full_desc =
                    "Counts every time the code stream enters into a new cache line by walking sequential from the previous line or being redirected by a jump.",
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Fixed Counter: Counts the number of instructions retired",
                .full_desc =
                    "Fixed Counter: Counts the number of instructions retired",
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts the number of instructions retired",
                .full_desc = "Counts the number of instructions retired",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "ITLB_MISSES.MISS_CAUSED_WALK",
                .encoding =
                    {
                        .code = 0x85ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of page walks initiated by a instruction fetch that missed the first and second level TLBs.",
                .full_desc =
                    "Counts the number of page walks initiated by a instruction fetch that missed the first and second level TLBs.",
                .default_sampling_period = 0xF4243ULL,
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
                    "Counts the number of page walks outstanding for iside in PMH every cycle.",
                .full_desc =
                    "Counts the number of page walks outstanding for iside in PMH every cycle.  A PMH page walk is outstanding from page walk start till PMH becomes idle again (ready to serve next walk). Includes EPT-walk intervals.  Walks could be counted by edge detecting on this event, but would count restarted suspended walks.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "LD_BLOCKS.ADDRESS_ALIAS",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of retired loads that are blocked because it initially appears to be store forward blocked, but subsequently is shown not to be blocked based on 4K alias check.",
                .full_desc =
                    "Counts the number of retired loads that are blocked because it initially appears to be store forward blocked, but subsequently is shown not to be blocked based on 4K alias check.",
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of retired loads that are blocked because its address exactly matches an older store whose data is not ready.",
                .full_desc =
                    "Counts the number of retired loads that are blocked because its address exactly matches an older store whose data is not ready.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "LD_HEAD.ANY_AT_RET",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0xFFULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer is stalled due to any number of reasons, including an L1 miss, WCB full, pagewalk, store address block or store data block, on a load that retires.",
                .full_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer is stalled due to any number of reasons, including an L1 miss, WCB full, pagewalk, store address block or store data block, on a load that retires.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "LD_HEAD.DTLB_MISS_AT_RET",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0x90ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a DTLB miss.",
                .full_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a DTLB miss.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "LD_HEAD.L1_BOUND_AT_RET",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0xF4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer is stalled due to a core bound stall including a store address match, a DTLB miss or a page walk that detains the load from retiring.",
                .full_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer is stalled due to a core bound stall including a store address match, a DTLB miss or a page walk that detains the load from retiring.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "LD_HEAD.L1_MISS_AT_RET",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0x81ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a DL1 miss.",
                .full_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a DL1 miss.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "LD_HEAD.OTHER_AT_RET",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0xC0ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to other block cases.",
                .full_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to other block cases such as pipeline conflicts, fences, etc.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "LD_HEAD.PGWALK_AT_RET",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0xA0ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a pagewalk.",
                .full_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a pagewalk.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "LD_HEAD.ST_ADDR_AT_RET",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0x84ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a store address match.",
                .full_desc =
                    "Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a store address match.",
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
                    "Counts the number of cacheable memory requests that access the Last Level Cache (LLC). Requests include demand loads, reads for ownership (RFO), instruction fetches and L1 HW prefetches. If the core has access to an L3 cache, the LLC is the L3 cache, otherwise it is the L2 cache. Counts on a per core basis.",
                .default_sampling_period = 0x30D43ULL,
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
                .id = "MACHINE_CLEARS.SLOW",
                .encoding =
                    {
                        .code = 0xC3ULL,
                        .umask = 0x6FULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of machine clears that flush the pipeline and restart the machine with the use of microcode due to SMC, MEMORY_ORDERING, FP_ASSISTS, PAGE_FAULT, DISAMBIGUATION, and FPC_VIRTUAL_TRAP.",
                .full_desc =
                    "Counts the number of machine clears that flush the pipeline and restart the machine with the use of microcode due to SMC, MEMORY_ORDERING, FP_ASSISTS, PAGE_FAULT, DISAMBIGUATION, and FPC_VIRTUAL_TRAP.",
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
                .id = "MEM_BOUND_STALLS_IFETCH.ALL",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x7FULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of unhalted cycles when the core is stalled due to an instruction cache or TLB miss.",
                .full_desc = "Counts the number of unhalted cycles when the core is stalled due to an instruction cache or TLB miss.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_BOUND_STALLS_IFETCH.L2_HIT",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles the core is stalled due to an instruction cache or TLB miss which hit in the L2 cache.",
                .full_desc =
                    "Counts the number of cycles the core is stalled due to an instruction cache or Translation Lookaside Buffer (TLB) miss which hit in the L2 cache.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_BOUND_STALLS_IFETCH.LLC_HIT",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x6ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of unhalted cycles when the core is stalled due to an icache or itlb miss which hit in the LLC.",
                .full_desc =
                    "Counts the number of unhalted cycles when the core is stalled due to an icache or itlb miss which hit in the LLC.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_BOUND_STALLS_IFETCH.LLC_MISS",
                .encoding =
                    {
                        .code = 0x35ULL,
                        .umask = 0x78ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of unhalted cycles when the core is stalled due to an icache or itlb miss which missed all the caches.",
                .full_desc =
                    "Counts the number of unhalted cycles when the core is stalled due to an icache or itlb miss which missed all the caches.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_BOUND_STALLS_LOAD.ALL",
                .encoding =
                    {
                        .code = 0x34ULL,
                        .umask = 0x7FULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of unhalted cycles when the core is stalled due to an L1 demand load miss.",
                .full_desc =
                    "Counts the number of unhalted cycles when the core is stalled due to an L1 demand load miss.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_BOUND_STALLS_LOAD.L2_HIT",
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
                    "Counts the number of cycles a core is stalled due to a demand load which hit in the L2 cache.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_BOUND_STALLS_LOAD.LLC_HIT",
                .encoding =
                    {
                        .code = 0x34ULL,
                        .umask = 0x6ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of unhalted cycles when the core is stalled due to a demand load miss which hit in the LLC.",
                .full_desc =
                    "Counts the number of unhalted cycles when the core is stalled due to a demand load miss which hit in the LLC.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_BOUND_STALLS_LOAD.LLC_MISS",
                .encoding =
                    {
                        .code = 0x34ULL,
                        .umask = 0x78ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of unhalted cycles when the core is stalled due to a demand load miss which missed all the local caches.",
                .full_desc =
                    "Counts the number of unhalted cycles when the core is stalled due to a demand load miss which missed all the local caches.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_UOPS_L3_MISS_RETIRED.LOCAL_DRAM",
                .encoding =
                    {
                        .code = 0xD3ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of load ops retired that miss the L3 cache and hit in DRAM",
                .full_desc =
                    "Counts the number of load ops retired that miss the L3 cache and hit in DRAM",
                .default_sampling_period = 0xF4243ULL,
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of load ops retired that hit the L1 data cache.",
                .full_desc =
                    "Counts the number of load ops retired that hit the L1 data cache.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_UOPS_RETIRED.L1_MISS",
                .encoding =
                    {
                        .code = 0xD1ULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of load ops retired that miss in the L1 data cache.",
                .full_desc =
                    "Counts the number of load ops retired that miss in the L1 data cache.",
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of load ops retired that hit in the L2 cache.",
                .full_desc =
                    "Counts the number of load ops retired that hit in the L2 cache.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_UOPS_RETIRED.L2_MISS",
                .encoding =
                    {
                        .code = 0xD1ULL,
                        .umask = 0x80ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of load ops retired that miss in the L2 cache.",
                .full_desc =
                    "Counts the number of load ops retired that miss in the L2 cache.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_UOPS_RETIRED.L3_HIT",
                .encoding =
                    {
                        .code = 0xD1ULL,
                        .umask = 0x1CULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of load ops retired that hit in the L3 cache.",
                .full_desc =
                    "Counts the number of load ops retired that hit in the L3 cache.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_UOPS_RETIRED.WCB_HIT",
                .encoding =
                    {
                        .code = 0xD1ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of loads that hit in a write combining buffer (WCB), excluding the first load that caused the WCB to allocate.",
                .full_desc =
                    "Counts the number of loads that hit in a write combining buffer (WCB), excluding the first load that caused the WCB to allocate.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_SCHEDULER_BLOCK.ALL",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x7ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles that uops are blocked for any of the following reasons:  load buffer, store buffer or RSV full.",
                .full_desc =
                    "Counts the number of cycles that uops are blocked for any of the following reasons:  load buffer, store buffer or RSV full.",
                .default_sampling_period = 0x4E23ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_SCHEDULER_BLOCK.LD_BUF",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles that uops are blocked due to a load buffer full condition.",
                .full_desc =
                    "Counts the number of cycles that uops are blocked due to a load buffer full condition.",
                .default_sampling_period = 0x4E23ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_SCHEDULER_BLOCK.RSV",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles that uops are blocked due to an RSV full condition.",
                .full_desc =
                    "Counts the number of cycles that uops are blocked due to an RSV full condition.",
                .default_sampling_period = 0x4E23ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_SCHEDULER_BLOCK.ST_BUF",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of cycles that uops are blocked due to a store buffer full condition.",
                .full_desc =
                    "Counts the number of cycles that uops are blocked due to a store buffer full condition.",
                .default_sampling_period = 0x4E23ULL,
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
                        .data_la = true,
                    },
                .brief_desc = "Counts the number of load ops retired.",
                .full_desc = "Counts the number of load ops retired.",
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
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                    },
                .brief_desc = "Counts the number of store ops retired.",
                .full_desc = "Counts the number of store ops retired.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_1024",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x5ULL,
                        .msr_values = uint64_t{0x400ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                    },
                .brief_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .full_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_128",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x5ULL,
                        .msr_values = uint64_t{0x80ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                    },
                .brief_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .full_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_16",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x5ULL,
                        .msr_values = uint64_t{0x10ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                    },
                .brief_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .full_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_2048",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x5ULL,
                        .msr_values = uint64_t{0x800ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                    },
                .brief_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .full_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_256",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x5ULL,
                        .msr_values = uint64_t{0x100ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                    },
                .brief_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .full_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_32",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x5ULL,
                        .msr_values = uint64_t{0x20ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                    },
                .brief_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .full_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_4",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x5ULL,
                        .msr_values = uint64_t{0x4ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                    },
                .brief_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .full_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_512",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x5ULL,
                        .msr_values = uint64_t{0x200ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                    },
                .brief_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .full_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_64",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x5ULL,
                        .msr_values = uint64_t{0x40ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                    },
                .brief_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .full_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_8",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x5ULL,
                        .msr_values = uint64_t{0x8ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                    },
                .brief_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .full_desc =
                    "Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.",
                .default_sampling_period = 0xF4243ULL,
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
                    },
                .brief_desc =
                    "Counts the number of load uops retired that performed one or more locks",
                .full_desc =
                    "Counts the number of load uops retired that performed one or more locks",
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
                    },
                .brief_desc = "Counts the number of retired split load uops.",
                .full_desc = "Counts the number of retired split load uops.",
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
                    },
                .brief_desc = "Counts the number of retired split store uops.",
                .full_desc = "Counts the number of retired split store uops.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.STORE_LATENCY",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x6ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                    },
                .brief_desc =
                    "Counts the number of  stores uops retired same as MEM_UOPS_RETIRED.ALL_STORES",
                .full_desc =
                    "Counts the number of  stores uops retired same as MEM_UOPS_RETIRED.ALL_STORES",
                .default_sampling_period = 0xF4243ULL,
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts misaligned loads that are 4K page splits.",
                .full_desc = "Counts misaligned loads that are 4K page splits.",
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts misaligned stores that are 4K page splits.",
                .full_desc =
                    "Counts misaligned stores that are 4K page splits.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MISC_RETIRED.LBR_INSERTS",
                .encoding =
                    {
                        .code = 0xE4ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of Last Branch Record (LBR) entries. Requires LBRs to be enabled and configured in IA32_LBR_CTL. [This event is alias to LBR_INSERTS.ANY]",
                .full_desc =
                    "Counts the number of Last Branch Record (LBR) entries. Requires LBRs to be enabled and configured in IA32_LBR_CTL. [This event is alias to LBR_INSERTS.ANY]",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OCR.DEMAND_DATA_RD.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that have any type of response.",
                .full_desc =
                    "Counts demand data reads that have any type of response.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                .full_desc =
                    "Counts demand data reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                .full_desc =
                    "Counts demand data reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OCR.DEMAND_DATA_RD.L3_MISS",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBFC00001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that were not supplied by the L3 cache.",
                .full_desc =
                    "Counts demand data reads that were not supplied by the L3 cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OCR.DEMAND_DATA_RD.LOCAL_DRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x184000001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that were supplied by DRAM attached to this socket.",
                .full_desc =
                    "Counts demand data reads that were supplied by DRAM attached to this socket.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OCR.DEMAND_DATA_RD.REMOTE_DRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x730000001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that were supplied by DRAM attached to another socket.",
                .full_desc =
                    "Counts demand data reads that were supplied by DRAM attached to another socket.",
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
                .id = "OCR.DEMAND_RFO.L3_MISS",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBFC00002ULL},
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
                .id = "SERIALIZATION.C01_MS_SCB",
                .encoding =
                    {
                        .code = 0x75ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of issue slots in a UMWAIT or TPAUSE instruction where no uop issues due to the instruction putting the CPU into the C0.1 activity state.",
                .full_desc =
                    "Counts the number of issue slots in a UMWAIT or TPAUSE instruction where no uop issues due to the instruction putting the CPU into the C0.1 activity state.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN_BAD_SPECULATION.ALL",
                .encoding =
                    {
                        .code = 0x73ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear. [This event is alias to TOPDOWN_BAD_SPECULATION.ALL_P]",
                .full_desc =
                    "Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear. Only issue slots wasted due to fast nukes such as memory ordering nukes are counted. Other nukes are not accounted for. Counts all issue slots blocked during this recovery window, including relevant microcode flows, and while uops are not yet available in the instruction queue (IQ) or until an FE_BOUND event occurs besides OTHER and CISC. Also includes the issue slots that were consumed by the backend but were thrown away because they were younger than the mispredict or machine clear. [This event is alias to TOPDOWN_BAD_SPECULATION.ALL_P]",
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
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to Fast Nukes such as  Memory Ordering Machine clears and MRN nukes",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to Fast Nukes such as  Memory Ordering Machine clears and MRN nukes",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN_BAD_SPECULATION.MACHINE_CLEARS",
                .encoding =
                    {
                        .code = 0x73ULL,
                        .umask = 0x3ULL,
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
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to Branch Mispredict",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to Branch Mispredict",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN_BAD_SPECULATION.NUKE",
                .encoding =
                    {
                        .code = 0x73ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to a machine clear (nuke).",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to a machine clear (nuke).",
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
                    "Counts the number of retirement slots not consumed due to backend stalls [This event is alias to TOPDOWN_BE_BOUND.ALL_P]",
                .full_desc =
                    "Counts the number of retirement slots not consumed due to backend stalls [This event is alias to TOPDOWN_BE_BOUND.ALL_P]",
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
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to due to certain allocation restrictions",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to due to certain allocation restrictions",
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
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to memory reservation stall (scheduler not being able to accept another uop).  This could be caused by RSV full or load/store buffer block.",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to memory reservation stall (scheduler not being able to accept another uop).  This could be caused by RSV full or load/store buffer block.",
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
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to IEC and FPC RAT stalls - which can be due to the FIQ and IEC reservation station stall (integer, FP and SIMD scheduler not being able to accept another uop. )",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to IEC and FPC RAT stalls - which can be due to the FIQ and IEC reservation station stall (integer, FP and SIMD scheduler not being able to accept another uop. )",
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
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to mrbl stall.  A 'marble' refers to a physical register file entry, also known as the physical destination (PDST).",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to mrbl stall.  A 'marble' refers to a physical register file entry, also known as the physical destination (PDST).",
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
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to ROB full",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to ROB full",
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
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to iq/jeu scoreboards or ms scb",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not consumed by the backend due to iq/jeu scoreboards or ms scb",
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
                    "Counts the number of retirement slots not consumed due to front end stalls [This event is alias to TOPDOWN_FE_BOUND.ALL_P]",
                .full_desc =
                    "Counts the number of retirement slots not consumed due to front end stalls [This event is alias to TOPDOWN_FE_BOUND.ALL_P]",
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
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to BAClear",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to BAClear",
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
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to BTClear",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to BTClear",
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
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to ms",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to ms",
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
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to decode stall",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to decode stall",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN_FE_BOUND.FRONTEND_BANDWIDTH",
                .encoding =
                    {
                        .code = 0x71ULL,
                        .umask = 0x8DULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to frontend bandwidth restrictions due to decode, predecode, cisc, and other limitations.",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to frontend bandwidth restrictions due to decode, predecode, cisc, and other limitations.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN_FE_BOUND.FRONTEND_LATENCY",
                .encoding =
                    {
                        .code = 0x71ULL,
                        .umask = 0x72ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to latency related stalls including BACLEARs, BTCLEARs, ITLB misses, and ICache misses.",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to latency related stalls including BACLEARs, BTCLEARs, ITLB misses, and ICache misses.",
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
                .brief_desc = "Counts the number of issue slots every cycle that were not delivered by the frontend due to an icache miss",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to an icache miss",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN_FE_BOUND.ITLB_MISS",
                .encoding =
                    {
                        .code = 0x71ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to itlb miss [This event is alias to TOPDOWN_FE_BOUND.ITLB]",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to itlb miss [This event is alias to TOPDOWN_FE_BOUND.ITLB]",
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
                    "Counts the number of issue slots every cycle that were not delivered by the frontend that do not categorize into any other common frontend stall",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend that do not categorize into any other common frontend stall",
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
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to predecode wrong",
                .full_desc =
                    "Counts the number of issue slots every cycle that were not delivered by the frontend due to predecode wrong",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN_RETIRING.ALL",
                .encoding =
                    {
                        .code = 0x72ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of consumed retirement slots. [This event is alias to TOPDOWN_RETIRING.ALL_P]",
                .full_desc =
                    "Counts the number of consumed retirement slots. [This event is alias to TOPDOWN_RETIRING.ALL_P]",
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of floating point divide uops retired (x87 and sse, including x87 sqrt).",
                .full_desc =
                    "Counts the number of floating point divide uops retired (x87 and sse, including x87 sqrt).",
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
                .features = StaticEventDef::IntelFeatures{},
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of uops that are from the complex flows issued by the micro-sequencer (MS).  This includes uops from flows due to complex instructions, faults, assists, and inserted flows.",
                .full_desc =
                    "Counts the number of uops that are from the complex flows issued by the micro-sequencer (MS).  This includes uops from flows due to complex instructions, faults, assists, and inserted flows.",
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of x87 uops retired, includes those in ms flows",
                .full_desc =
                    "Counts the number of x87 uops retired, includes those in ms flows",
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

} // namespace sierraforest_core
} // namespace facebook::hbt::perf_event::generated
