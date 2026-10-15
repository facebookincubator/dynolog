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
namespace knightslanding_core {
namespace {

/*
  Events from knightslanding_core.json (376 events).

  Supported SKUs:
      - Arch: x86, Model: KNL id: 87
      - Arch: x86, Model: KNL id: 133
*/
constexpr std::array<StaticEventDef, 8> kAllowlistedEvents{{
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
            "Counts the number of branch instructions retired (Precise Event)",
        .full_desc =
            "Counts the number of branch instructions retired (Precise Event)",
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
            "Counts the number of mispredicted branch instructions retired (Precise Event)",
        .full_desc =
            "Counts the number of mispredicted branch instructions retired (Precise Event)",
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
            "This event counts the number of core cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. This event is a component in many key event ratios. The core frequency may change from time to time due to transitions associated with Enhanced Intel SpeedStep Technology or TM2. For this reason this event may have a changing ratio with regards to time. When the core frequency is constant, this event can approximate elapsed time while the core was not in the halt state. It is counted on a dedicated fixed counter",
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
        .brief_desc = "Counts the number of unhalted core clock cycles",
        .full_desc = "Counts the number of unhalted core clock cycles",
        .default_sampling_period = 0x1E8483ULL,
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
            "Counts all instruction fetches that miss the instruction cache or produce memory requests. An instruction fetch miss is counted only once and not once for every cycle it is outstanding.",
        .full_desc =
            "Counts all instruction fetches that miss the instruction cache or produce memory requests. An instruction fetch miss is counted only once and not once for every cycle it is outstanding.",
        .default_sampling_period = 0x30D43ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts the matrix events specified by MSR_OFFCORE_RESPx",
        .full_desc = "Counts the matrix events specified by MSR_OFFCORE_RESPx",
        .default_sampling_period = 0x186A7ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_RETIRED.ALL",
        .encoding =
            {
                .code = 0xC2ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts the number of micro-ops retired",
        .full_desc =
            "This event counts the number of micro-ops (uops) retired. The processor decodes complex macro instructions into a sequence of simpler uops. Most instructions are composed of one or two uops. Some instructions are decoded into longer sequences such as repeat instructions, floating point transcendental instructions, and assists.",
        .default_sampling_period = 0x1E8483ULL,
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 368>
    kFullOnlyEvents{
        {
            {
                .pmu_type = PmuType::cpu,
                .id = "BACLEARS.ALL",
                .encoding =
                    {
                        .code = 0xE6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of times the front end resteers for any branch as a result of another branch handling mechanism in the front end.",
                .full_desc =
                    "Counts the number of times the front end resteers for any branch as a result of another branch handling mechanism in the front end.",
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
                    "Counts the number of times the front end resteers for conditional branches as a result of another branch handling mechanism in the front end.",
                .full_desc =
                    "Counts the number of times the front end resteers for conditional branches as a result of another branch handling mechanism in the front end.",
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
                    "Counts the number of times the front end resteers for RET branches as a result of another branch handling mechanism in the front end.",
                .full_desc =
                    "Counts the number of times the front end resteers for RET branches as a result of another branch handling mechanism in the front end.",
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
                    "Counts the number of near CALL branch instructions retired. (Precise Event)",
                .full_desc =
                    "Counts the number of near CALL branch instructions retired. (Precise Event)",
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
                    "Counts the number of far branch instructions retired. (Precise Event)",
                .full_desc =
                    "Counts the number of far branch instructions retired. (Precise Event)",
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
                    "Counts the number of near indirect CALL branch instructions retired. (Precise Event)",
                .full_desc =
                    "Counts the number of near indirect CALL branch instructions retired. (Precise Event)",
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
                    "Counts the number of branch instructions retired that were conditional jumps. (Precise Event)",
                .full_desc =
                    "Counts the number of branch instructions retired that were conditional jumps. (Precise Event)",
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
                    "Counts the number of branch instructions retired that were near indirect CALL or near indirect JMP. (Precise Event)",
                .full_desc =
                    "Counts the number of branch instructions retired that were near indirect CALL or near indirect JMP. (Precise Event)",
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
                    "Counts the number of near relative CALL branch instructions retired. (Precise Event)",
                .full_desc =
                    "Counts the number of near relative CALL branch instructions retired. (Precise Event)",
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
                    "Counts the number of near RET branch instructions retired. (Precise Event)",
                .full_desc =
                    "Counts the number of near RET branch instructions retired. (Precise Event)",
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
                    "Counts the number of branch instructions retired that were conditional jumps and predicted taken. (Precise Event)",
                .full_desc =
                    "Counts the number of branch instructions retired that were conditional jumps and predicted taken. (Precise Event)",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_MISP_RETIRED.CALL",
                .encoding =
                    {
                        .code = 0xC5ULL,
                        .umask = 0xF9ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Counts the number of mispredicted near CALL branch instructions retired. (Precise Event)",
                .full_desc =
                    "Counts the number of mispredicted near CALL branch instructions retired. (Precise Event)",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_MISP_RETIRED.FAR_BRANCH",
                .encoding =
                    {
                        .code = 0xC5ULL,
                        .umask = 0xBFULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Counts the number of mispredicted far branch instructions retired. (Precise Event)",
                .full_desc =
                    "Counts the number of mispredicted far branch instructions retired. (Precise Event)",
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
                    "Counts the number of mispredicted near indirect CALL branch instructions retired. (Precise Event)",
                .full_desc =
                    "Counts the number of mispredicted near indirect CALL branch instructions retired. (Precise Event)",
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
                    "Counts the number of mispredicted branch instructions retired that were conditional jumps. (Precise Event)",
                .full_desc =
                    "Counts the number of mispredicted branch instructions retired that were conditional jumps. (Precise Event)",
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
                    "Counts the number of mispredicted branch instructions retired that were near indirect CALL or near indirect JMP. (Precise Event)",
                .full_desc =
                    "Counts the number of mispredicted branch instructions retired that were near indirect CALL or near indirect JMP. (Precise Event)",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_MISP_RETIRED.REL_CALL",
                .encoding =
                    {
                        .code = 0xC5ULL,
                        .umask = 0xFDULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Counts the number of mispredicted near relative CALL branch instructions retired. (Precise Event)",
                .full_desc =
                    "Counts the number of mispredicted near relative CALL branch instructions retired. (Precise Event)",
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
                    "Counts the number of mispredicted near RET branch instructions retired. (Precise Event)",
                .full_desc =
                    "Counts the number of mispredicted near RET branch instructions retired. (Precise Event)",
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
                    "Counts the number of mispredicted branch instructions retired that were conditional jumps and predicted taken. (Precise Event)",
                .full_desc =
                    "Counts the number of mispredicted branch instructions retired that were conditional jumps and predicted taken. (Precise Event)",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_REJECT_L2Q.ALL",
                .encoding =
                    {
                        .code = 0x31ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of MEC requests that were not accepted into the L2Q because of any L2  queue reject condition. There is no concept of at-ret here. It might include requests due to instructions in the speculative path.",
                .full_desc =
                    "Counts the number of MEC requests that were not accepted into the L2Q because of any L2  queue reject condition. There is no concept of at-ret here. It might include requests due to instructions in the speculative path.",
                .default_sampling_period = 0x30D43ULL,
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
                    "Counts the number of unhalted reference clock cycles",
                .full_desc =
                    "Counts the number of unhalted reference clock cycles",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CYCLES_DIV_BUSY.ALL",
                .encoding =
                    {
                        .code = 0xCDULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles the number of core cycles when divider is busy.  Does not imply a stall waiting for the divider.",
                .full_desc =
                    "This event counts cycles when the divider is busy. More specifically cycles when the divide unit is unable to accept a new divide uop because it is busy processing a previously dispatched uop. The cycles will be counted irrespective of whether or not another divide uop is waiting to enter the divide unit (from the RS). This event counts integer divides, x87 divides, divss, divsd, sqrtss, sqrtsd event and does not count vector divides.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FETCH_STALL.ICACHE_FILL_PENDING_CYCLES",
                .encoding =
                    {
                        .code = 0x86ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "This event counts the number of core cycles the fetch stalls because of an icache miss. This is a cumulative count of cycles the NIP stalled for all icache misses.",
                .full_desc =
                    "This event counts the number of core cycles the fetch stalls because of an icache miss. This is a cumulative count of cycles the NIP stalled for all icache misses.",
                .default_sampling_period = 0x30D43ULL,
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
                    "Counts all instruction fetches, including uncacheable fetches.",
                .full_desc =
                    "Counts all instruction fetches, including uncacheable fetches.",
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
                    "Counts all instruction fetches that hit the instruction cache.",
                .full_desc =
                    "Counts all instruction fetches that hit the instruction cache.",
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
                    "This event counts the number of instructions that retire.  For instructions that consist of multiple micro-ops, this event counts exactly once, as the last micro-op of the instruction retires.  The event continues counting while instructions retire, including during interrupt service routines caused by hardware interrupts, faults or traps.",
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
                .brief_desc = "Counts the total number of instructions retired",
                .full_desc = "Counts the total number of instructions retired",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "INST_RETIRED.ANY_PS",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 2,
                    },
                .brief_desc =
                    "Counts the number of instructions retired (Precise Event)",
                .full_desc =
                    "Counts the number of instructions retired (Precise Event)",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_PREFETCHER.ALLOC_XQ",
                .encoding =
                    {
                        .code = 0x3EULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts the number of L2HWP allocated into XQ GP",
                .full_desc = "Counts the number of L2HWP allocated into XQ GP",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_REQUESTS.MISS",
                .encoding =
                    {
                        .code = 0x2EULL,
                        .umask = 0x41ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts the number of L2 cache misses",
                .full_desc = "Counts the number of L2 cache misses",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_REQUESTS.REFERENCE",
                .encoding =
                    {
                        .code = 0x2EULL,
                        .umask = 0x4FULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts the total number of L2 cache references.",
                .full_desc = "Counts the total number of L2 cache references.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_REQUESTS_REJECT.ALL",
                .encoding =
                    {
                        .code = 0x30ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of MEC requests from the L2Q that reference a cache line (cacheable requests) excluding SW prefetches filling only to L2 cache and L1 evictions (automatically excludes L2HWP, UC, WC) that were rejected - Multiple repeated rejects should be counted multiple times",
                .full_desc =
                    "Counts the number of MEC requests from the L2Q that reference a cache line (cacheable requests) excluding SW prefetches filling only to L2 cache and L1 evictions (automatically excludes L2HWP, UC, WC) that were rejected - Multiple repeated rejects should be counted multiple times",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MACHINE_CLEARS.ALL",
                .encoding =
                    {
                        .code = 0xC3ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts all machine clears",
                .full_desc = "Counts all machine clears",
                .default_sampling_period = 0x30D43ULL,
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
                    "Counts the number of floating operations retired that required microcode assists",
                .full_desc =
                    "This event counts the number of times that the pipeline stalled due to FP operations needing assists.",
                .default_sampling_period = 0x30D43ULL,
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
                    "Counts the number of times the machine clears due to memory ordering hazards",
                .full_desc =
                    "Counts the number of times the machine clears due to memory ordering hazards",
                .default_sampling_period = 0x30D43ULL,
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
                    "Counts the number of times that the machine clears due to program modifying data within 1K of a recently fetched code page",
                .full_desc =
                    "Counts the number of times that the machine clears due to program modifying data within 1K of a recently fetched code page",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.ALL_LOADS",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts all the load micro-ops retired",
                .full_desc =
                    "This event counts the number of load micro-ops retired.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.ALL_STORES",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x80ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts all the store micro-ops retired",
                .full_desc =
                    "This event counts the number of store micro-ops retired.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.DTLB_MISS_LOADS",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Counts the number of load micro-ops retired that cause a DTLB miss (Precise Event)",
                .full_desc =
                    "Counts the number of load micro-ops retired that cause a DTLB miss (Precise Event)",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.HITM",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Counts the loads retired that get the data from the other core in the same tile in M state (Precise Event)",
                .full_desc =
                    "This event counts the number of load micro-ops retired that got data from another core's cache. (Precise Event).",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.L1_MISS_LOADS",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of load micro-ops retired that miss in L1 D cache",
                .full_desc =
                    "This event counts the number of load micro-ops retired that miss in L1 Data cache. Note that prefetch misses will not be counted.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.L2_HIT_LOADS",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Counts the number of load micro-ops retired that hit in the L2 (Precise Event)",
                .full_desc =
                    "This event counts the number of load micro-uops retired that hit in the L2 (Precise Event)",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.L2_MISS_LOADS",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Counts the number of load micro-ops retired that miss in the L2 (Precise Event)",
                .full_desc =
                    "This event counts the number of load micro-ops retired that miss in the L2 (Precise Event)",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_UOPS_RETIRED.UTLB_MISS_LOADS",
                .encoding =
                    {
                        .code = 0x4ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of load micro-ops retired that caused micro TLB miss",
                .full_desc =
                    "Counts the number of load micro-ops retired that caused micro TLB miss",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MS_DECODED.MS_ENTRY",
                .encoding =
                    {
                        .code = 0xE7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of times the MSROM starts a flow of uops.",
                .full_desc =
                    "Counts the number of times the MSROM starts a flow of uops.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "NO_ALLOC_CYCLES.ALL",
                .encoding =
                    {
                        .code = 0xCAULL,
                        .umask = 0x7FULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total number of core cycles when no micro-ops are allocated for any reason.",
                .full_desc =
                    "Counts the total number of core cycles when no micro-ops are allocated for any reason.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "NO_ALLOC_CYCLES.MISPREDICTS",
                .encoding =
                    {
                        .code = 0xCAULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of core cycles when no micro-ops are allocated and the alloc pipe is stalled waiting for a mispredicted branch to retire.",
                .full_desc =
                    "This event counts the number of core cycles when no uops are allocated and the alloc pipe is stalled waiting for a mispredicted branch to retire.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "NO_ALLOC_CYCLES.NOT_DELIVERED",
                .encoding =
                    {
                        .code = 0xCAULL,
                        .umask = 0x90ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of core cycles when no micro-ops are allocated, the IQ is empty, and no other condition is blocking allocation.",
                .full_desc =
                    "This event counts the number of core cycles when no uops are allocated, the instruction queue is empty and the alloc pipe is stalled waiting for instructions to be fetched.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "NO_ALLOC_CYCLES.RAT_STALL",
                .encoding =
                    {
                        .code = 0xCAULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of core cycles when no micro-ops are allocated and a RATstall (caused by reservation station full) is asserted.",
                .full_desc =
                    "Counts the number of core cycles when no micro-ops are allocated and a RATstall (caused by reservation station full) is asserted.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "NO_ALLOC_CYCLES.ROB_FULL",
                .encoding =
                    {
                        .code = 0xCAULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of core cycles when no micro-ops are allocated and the ROB is full",
                .full_desc =
                    "Counts the number of core cycles when no micro-ops are allocated and the ROB is full",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for any response",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181800044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800400044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800180044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8000044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180600044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_CODE_RD.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000000044ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand code reads and prefetch code read requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts Demand code reads and prefetch code read requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x13091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for any response",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181803091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101003091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80803091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800403091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800403091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000403091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800183091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800083091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000083091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2003091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180603091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100403091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80203091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_DATA_RD.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000003091ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts Demand cacheable data and L1 prefetch data read requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for any response",
                .full_desc =
                    "Counts any Prefetch requests that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts any Prefetch requests that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts any Prefetch requests that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800400070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts any Prefetch requests that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800180070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts any Prefetch requests that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts any Prefetch requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts any Prefetch requests that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180600070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts any Prefetch requests that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts any Prefetch requests that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts any Prefetch requests that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_PF_L2.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000000070ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Prefetch requests that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts any Prefetch requests that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x132F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for any response",
                .full_desc =
                    "Counts any Read request  that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1818032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts any Read request  that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1010032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts any Read request  that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x808032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts any Read request  that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x18004032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts any Read request  that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8004032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10004032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x18001832F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts any Read request  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8000832F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000832F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts any Read request  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x40032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts any Read request  that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts any Read request  that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x20032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts any Read request  that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts any Read request  that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1806032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts any Read request  that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1004032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts any Read request  that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x802032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts any Read request  that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_READ.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x40000032F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any Read request  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts any Read request  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x18000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for any response",
                .full_desc =
                    "Counts any request that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181808000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts any request that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101008000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts any request that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80808000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts any request that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800408000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts any request that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800408000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts any request that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000408000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc = "Counts any request that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800188000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts any request that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800088000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts any request that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000088000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts any request that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4008000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts any request that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10008000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts any request that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2008000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts any request that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8008000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts any request that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_MISS",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x18001981F8ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Accounts for responses which miss its own tile's L2.",
                .full_desc =
                    "Accounts for responses which miss its own tile's L2. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180608000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts any request that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100408000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts any request that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80208000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts any request that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_REQUEST.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000008000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any request that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts any request that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for any response",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181800022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800400022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800180022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8000022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180600022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts Demand cacheable data write requests  that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ANY_RFO.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000000022ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data write requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts Demand cacheable data write requests  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for any response",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181800400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800400400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800180400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8000400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180600400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts Bus locks and split lock requests that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.BUS_LOCKS.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000000400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Bus locks and split lock requests that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts Bus locks and split lock requests that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
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
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for any response",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181800004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800400004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800180004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8000004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180600004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000000004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand code reads and prefetch code reads that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts demand code reads and prefetch code reads that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
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
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for any response",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181800001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8000001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180600001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000000001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts demand cacheable data and L1 prefetch data reads that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
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
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for any response",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181800002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800400002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800180002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8000002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180600002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts Demand cacheable data writes that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000000002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Demand cacheable data writes that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts Demand cacheable data writes that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.FULL_STREAMING_STORES.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10800ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Full streaming stores (WC and should be programmed on PMC1) that accounts for any response",
                .full_desc =
                    "Counts Full streaming stores (WC and should be programmed on PMC1) that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for any response",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181800080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800400080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800180080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8000080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180600080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.NON_DRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000020080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from any NON_DRAM system address. This includes MMIO transactions",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that accounts for responses from any NON_DRAM system address. This includes MMIO transactions ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_READS.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000000080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts Partial reads (UC or WC and is valid only for Outstanding response type).  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x14000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial streaming stores (WC and should be programmed on PMC1) that accounts for any response",
                .full_desc =
                    "Counts Partial streaming stores (WC and should be programmed on PMC1) that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for any response",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800400100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800180100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8000100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180600100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts Partial writes (UC or WT or WP and should be programmed on PMC1) that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x12000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for any response",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181802000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101002000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80802000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800402000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800402000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000402000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800182000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800082000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000082000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4002000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10002000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2002000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8002000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100402000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc = "Counts L1 data HW prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80202000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts L1 data HW prefetches that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000002000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data HW prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts L1 data HW prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for any response",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181800040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800400040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800180040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts L2 code HW prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts L2 code HW prefetches that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000000040ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 code HW prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts L2 code HW prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for any response",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181800020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800180020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8000020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180600020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.NON_DRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000020020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from any NON_DRAM system address. This includes MMIO transactions",
                .full_desc =
                    "Counts L2 data RFO prefetches (includes PREFETCHW instruction) that accounts for responses from any NON_DRAM system address. This includes MMIO transactions ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x11000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for any response",
                .full_desc =
                    "Counts Software Prefetches that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181801000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101001000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts Software Prefetches that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80801000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts Software Prefetches that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_FAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800401000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800401000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000401000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800181000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800081000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000081000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4001000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10001000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2001000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8001000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180601000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts Software Prefetches that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100401000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts Software Prefetches that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80201000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts Software Prefetches that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_SOFTWARE.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000001000ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts Software Prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts Software Prefetches that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.STREAMING_STORES.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x14800ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all streaming stores (WC and should be programmed on PMC1) that accounts for any response",
                .full_desc =
                    "Counts all streaming stores (WC and should be programmed on PMC1) that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for any response",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for any response ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.DDR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x181800200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from DDR (local and far)",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from DDR (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.DDR_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x101000200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from DRAM Far. ",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from DRAM Far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.DDR_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80800200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from DRAM Local.",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from DRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_FAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800400200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_FAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000400200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state. ",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_NEAR_TILE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1800180200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_NEAR_TILE_E_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x800080200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state. ",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_NEAR_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1000080200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state. ",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_THIS_TILE_E",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in E state ",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in E state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_THIS_TILE_F",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10000200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in F state ",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in F state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_THIS_TILE_M",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x2000200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in M state ",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in M state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.L2_HIT_THIS_TILE_S",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8000200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in S state ",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses which hit its own tile's L2 with data in S state  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.MCDRAM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x180600200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from MCDRAM (local and far)",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for responses from MCDRAM (local and far) ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.MCDRAM_FAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100400200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from MCDRAM Far or Other tile L2 hit far. ",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from MCDRAM Far or Other tile L2 hit far.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.MCDRAM_NEAR",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x80200200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from MCDRAM Local.",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that accounts for data responses from MCDRAM Local. ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.UC_CODE_READS.OUTSTANDING",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4000000200ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0. ",
                .full_desc =
                    "Counts UC code reads (valid only for Outstanding response type)  that are outstanding, per weighted cycle, from the time of the request to when any response is received. The outstanding response should be programmed only on PMC0.  ",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "PAGE_WALKS.CYCLES",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0x3ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total number of core cycles for all the page walks. The cycles for page walks started in speculative path will also be included.",
                .full_desc =
                    "This event counts every cycle when a data (D) page walk or instruction (I) page walk is in progress.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "PAGE_WALKS.D_SIDE_CYCLES",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total number of core cycles for all the D-side page walks. The cycles for page walks started in speculative path will also be included.",
                .full_desc =
                    "Counts the total number of core cycles for all the D-side page walks. The cycles for page walks started in speculative path will also be included.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "PAGE_WALKS.D_SIDE_WALKS",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0x1ULL,
                        .edge = true,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total D-side page walks that are completed or started. The page walks started in the speculative path will also be counted",
                .full_desc =
                    "Counts the total D-side page walks that are completed or started. The page walks started in the speculative path will also be counted",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "PAGE_WALKS.I_SIDE_CYCLES",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total number of core cycles for all the I-side page walks. The cycles for page walks started in speculative path will also be included.",
                .full_desc =
                    "This event counts every cycle when an I-side (walks due to an instruction fetch) page walk is in progress.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "PAGE_WALKS.I_SIDE_WALKS",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0x2ULL,
                        .edge = true,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total I-side page walks that are completed.",
                .full_desc =
                    "Counts the total I-side page walks that are completed.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "PAGE_WALKS.WALKS",
                .encoding =
                    {
                        .code = 0x5ULL,
                        .umask = 0x3ULL,
                        .edge = true,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total page walks that are completed (I-side and D-side)",
                .full_desc =
                    "Counts the total page walks that are completed (I-side and D-side)",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RECYCLEQ.ANY_LD",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any retired load that was pushed into the recycle queue for any reason.",
                .full_desc =
                    "Counts any retired load that was pushed into the recycle queue for any reason.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RECYCLEQ.ANY_ST",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0x80ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts any retired store that was pushed into the recycle queue for any reason.",
                .full_desc =
                    "Counts any retired store that was pushed into the recycle queue for any reason.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RECYCLEQ.LD_BLOCK_STD_NOTREADY",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of occurrences a retired load gets blocked because its address overlaps with a store whose data is not ready",
                .full_desc =
                    "Counts the number of occurrences a retired load gets blocked because its address overlaps with a store whose data is not ready",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RECYCLEQ.LD_BLOCK_ST_FORWARD",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Counts the number of occurrences a retired load gets blocked because its address partially overlaps with a store  (Precise Event)",
                .full_desc =
                    "This event counts the number of retired loads that were prohibited from receiving forwarded data from a previous store because of address mismatch. ",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RECYCLEQ.LD_SPLITS",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Counts the number of occurrences a retired load was pushed into the rehab queue because it sees a cache line split. Each split should be counted only once. (Precise Event)",
                .full_desc =
                    "This event counts the number of retired loads which was pushed into the recycled queue that experienced cache line boundary splits (Precise event). Not that each split should be counted only once.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RECYCLEQ.LOCK",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all the retired locked loads. It does not include stores because we would double count if we count stores",
                .full_desc =
                    "Counts all the retired locked loads. It does not include stores because we would double count if we count stores",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RECYCLEQ.STA_FULL",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the store micro-ops retired that were pushed in the rehab queue because the store address buffer is full",
                .full_desc =
                    "Counts the store micro-ops retired that were pushed in the rehab queue because the store address buffer is full",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RECYCLEQ.ST_SPLITS",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of occurrences a retired store that is a cache line split. Each split should be counted only once.",
                .full_desc =
                    "This event counts the number of retired store that experienced a cache line boundary split(Precise Event). Note that each spilt should be counted only once.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RS_FULL_STALL.ALL",
                .encoding =
                    {
                        .code = 0xCBULL,
                        .umask = 0x1FULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the total number of core cycles allocation pipeline is stalled when any one of the reservation stations is full.",
                .full_desc =
                    "Counts the total number of core cycles allocation pipeline is stalled when any one of the reservation stations is full.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RS_FULL_STALL.MEC",
                .encoding =
                    {
                        .code = 0xCBULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of core cycles when allocation pipeline is stalled and is waiting for a free MEC reservation station entry.",
                .full_desc =
                    "Counts the number of core cycles when allocation pipeline is stalled and is waiting for a free MEC reservation station entry.",
                .default_sampling_period = 0x30D43ULL,
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
                    "Counts the number of micro-ops retired that are from the complex flows issued by the micro-sequencer (MS).",
                .full_desc =
                    "This event counts the number of micro-ops retired that were supplied from MSROM.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_RETIRED.PACKED_SIMD",
                .encoding =
                    {
                        .code = 0xC2ULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of packed SSE, AVX, AVX2, AVX-512 micro-ops (both floating point and integer) except for loads (memory-to-register mov-type micro-ops), packed byte and word multiplies.",
                .full_desc =
                    "The length of the packed operation (128bits, 256bits or 512bits) is not taken into account when updating the counter; all count the same (+1). \nMask (k) registers are ignored. For example: a micro-op operating with a mask that only enables one element or even zero elements will still trigger this counter (+1)\nThis event is defined at the micro-op level and not instruction level. Most instructions are implemented with one micro-op but not all.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_RETIRED.SCALAR_SIMD",
                .encoding =
                    {
                        .code = 0xC2ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of scalar SSE, AVX, AVX2, AVX-512 micro-ops except for loads (memory-to-register mov-type micro ops), division, sqrt.",
                .full_desc =
                    "This event is defined at the micro-op level and not instruction level. Most instructions are implemented with one micro-op but not all.",
                .default_sampling_period = 0x30D43ULL,
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

} // namespace knightslanding_core
} // namespace facebook::hbt::perf_event::generated
