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
namespace nehalemex_core {
namespace {

/*
  Events from NehalemEX_core.json (553 events).

  Supported SKUs:
      - Arch: x86, Model: NHM-EX id: 46
*/
constexpr std::array<StaticEventDef, 9> kAllowlistedEvents{{
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_RETIRED.ALL_BRANCHES",
        .encoding =
            {
                .code = 0xC4ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired branch instructions (Precise Event)",
        .full_desc = "Retired branch instructions (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.THREAD",
        .encoding =
            {
                .code = 0x0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles when thread is not halted (fixed counter)",
        .full_desc = "Cycles when thread is not halted (fixed counter)",
        .default_sampling_period = 0x1E8480ULL,
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
        .brief_desc = "Cycles when thread is not halted (programmable counter)",
        .full_desc = "Cycles when thread is not halted (programmable counter)",
        .default_sampling_period = 0x1E8480ULL,
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
        .brief_desc = "DTLB load miss page walks complete",
        .full_desc = "DTLB load miss page walks complete",
        .default_sampling_period = 0x30D40ULL,
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
        .brief_desc = "ITLB miss page walks",
        .full_desc = "ITLB miss page walks",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.MISS",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0xAAULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All L2 misses",
        .full_desc = "All L2 misses",
        .default_sampling_period = 0x30D40ULL,
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
        .brief_desc = "Longest latency cache miss",
        .full_desc = "Longest latency cache miss",
        .default_sampling_period = 0x186A0ULL,
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
        .brief_desc = "Uops issued",
        .full_desc = "Uops issued",
        .default_sampling_period = 0x1E8480ULL,
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
        .brief_desc = "Retirement slots used (Precise Event)",
        .full_desc = "Retirement slots used (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 512> kFullOnlyEvents0{{
    {
        .pmu_type = PmuType::cpu,
        .id = "ARITH.CYCLES_DIV_BUSY",
        .encoding =
            {
                .code = 0x14ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles the divider is busy",
        .full_desc = "Cycles the divider is busy",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ARITH.DIV",
        .encoding =
            {
                .code = 0x14ULL,
                .umask = 0x1ULL,
                .edge = true,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Divide Operations executed",
        .full_desc = "Divide Operations executed",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ARITH.MUL",
        .encoding =
            {
                .code = 0x14ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Multiply operations executed",
        .full_desc = "Multiply operations executed",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BACLEAR.BAD_TARGET",
        .encoding =
            {
                .code = 0xE6ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "BACLEAR asserted with bad target address",
        .full_desc = "BACLEAR asserted with bad target address",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BACLEAR.CLEAR",
        .encoding =
            {
                .code = 0xE6ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "BACLEAR asserted, regardless of cause ",
        .full_desc = "BACLEAR asserted, regardless of cause ",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BACLEAR_FORCE_IQ",
        .encoding =
            {
                .code = 0xA7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Instruction queue forced BACLEAR",
        .full_desc = "Instruction queue forced BACLEAR",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BPU_CLEARS.EARLY",
        .encoding =
            {
                .code = 0xE8ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Early Branch Prediciton Unit clears",
        .full_desc = "Early Branch Prediciton Unit clears",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BPU_CLEARS.LATE",
        .encoding =
            {
                .code = 0xE8ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Late Branch Prediction Unit clears",
        .full_desc = "Late Branch Prediction Unit clears",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BPU_MISSED_CALL_RET",
        .encoding =
            {
                .code = 0xE5ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Branch prediction unit missed call or return",
        .full_desc = "Branch prediction unit missed call or return",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_DECODED",
        .encoding =
            {
                .code = 0xE0ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Branch instructions decoded",
        .full_desc = "Branch instructions decoded",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.ANY",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x7FULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Branch instructions executed",
        .full_desc = "Branch instructions executed",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.COND",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Conditional branch instructions executed",
        .full_desc = "Conditional branch instructions executed",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.DIRECT",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Unconditional branches executed",
        .full_desc = "Unconditional branches executed",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.DIRECT_NEAR_CALL",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Unconditional call branches executed",
        .full_desc = "Unconditional call branches executed",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.INDIRECT_NEAR_CALL",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Indirect call branches executed",
        .full_desc = "Indirect call branches executed",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.INDIRECT_NON_CALL",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Indirect non call branches executed",
        .full_desc = "Indirect non call branches executed",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.NEAR_CALLS",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x30ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Call branches executed",
        .full_desc = "Call branches executed",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.NON_CALLS",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x7ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All non call branches executed",
        .full_desc = "All non call branches executed",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.RETURN_NEAR",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Indirect return branches executed",
        .full_desc = "Indirect return branches executed",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_INST_EXEC.TAKEN",
        .encoding =
            {
                .code = 0x88ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Taken branches executed",
        .full_desc = "Taken branches executed",
        .default_sampling_period = 0x30D40ULL,
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
        .brief_desc = "Retired conditional branch instructions (Precise Event)",
        .full_desc = "Retired conditional branch instructions (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
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
        .brief_desc = "Retired near call instructions (Precise Event)",
        .full_desc = "Retired near call instructions (Precise Event)",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.ANY",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x7FULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Mispredicted branches executed",
        .full_desc = "Mispredicted branches executed",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.COND",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Mispredicted conditional branches executed",
        .full_desc = "Mispredicted conditional branches executed",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.DIRECT",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Mispredicted unconditional branches executed",
        .full_desc = "Mispredicted unconditional branches executed",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.DIRECT_NEAR_CALL",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Mispredicted non call branches executed",
        .full_desc = "Mispredicted non call branches executed",
        .default_sampling_period = 0x7D0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.INDIRECT_NEAR_CALL",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Mispredicted indirect call branches executed",
        .full_desc = "Mispredicted indirect call branches executed",
        .default_sampling_period = 0x7D0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.INDIRECT_NON_CALL",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Mispredicted indirect non call branches executed",
        .full_desc = "Mispredicted indirect non call branches executed",
        .default_sampling_period = 0x7D0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.NEAR_CALLS",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x30ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Mispredicted call branches executed",
        .full_desc = "Mispredicted call branches executed",
        .default_sampling_period = 0x7D0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.NON_CALLS",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x7ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Mispredicted non call branches executed",
        .full_desc = "Mispredicted non call branches executed",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.RETURN_NEAR",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Mispredicted return branches executed",
        .full_desc = "Mispredicted return branches executed",
        .default_sampling_period = 0x7D0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "BR_MISP_EXEC.TAKEN",
        .encoding =
            {
                .code = 0x89ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Mispredicted taken branches executed",
        .full_desc = "Mispredicted taken branches executed",
        .default_sampling_period = 0x4E20ULL,
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
        .brief_desc = "Mispredicted near retired calls (Precise Event)",
        .full_desc = "Mispredicted near retired calls (Precise Event)",
        .default_sampling_period = 0x7D0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CACHE_LOCK_CYCLES.L1D",
        .encoding =
            {
                .code = 0x63ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles L1D locked",
        .full_desc = "Cycles L1D locked",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CACHE_LOCK_CYCLES.L1D_L2",
        .encoding =
            {
                .code = 0x63ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles L1D and L2 locked",
        .full_desc = "Cycles L1D and L2 locked",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.REF",
        .encoding =
            {
                .code = 0x0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Reference cycles when thread is not halted (fixed counter)",
        .full_desc =
            "Reference cycles when thread is not halted (fixed counter)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.REF_P",
        .encoding =
            {
                .code = 0x3CULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Reference base clock (133 Mhz) cycles when thread is not halted (programmable counter)",
        .full_desc =
            "Reference base clock (133 Mhz) cycles when thread is not halted (programmable counter)",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "CPU_CLK_UNHALTED.TOTAL_CYCLES",
        .encoding =
            {
                .code = 0x3CULL,
                .inv = true,
                .cmask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Total CPU cycles",
        .full_desc = "Total CPU cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.ANY",
        .encoding =
            {
                .code = 0x8ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "DTLB load misses",
        .full_desc = "DTLB load misses",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.PDE_MISS",
        .encoding =
            {
                .code = 0x8ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "DTLB load miss caused by low part of address",
        .full_desc = "DTLB load miss caused by low part of address",
        .default_sampling_period = 0x30D40ULL,
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
        .brief_desc = "DTLB second level hit",
        .full_desc = "DTLB second level hit",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_MISSES.ANY",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "DTLB misses",
        .full_desc = "DTLB misses",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_MISSES.STLB_HIT",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "DTLB first level misses but second level hit",
        .full_desc = "DTLB first level misses but second level hit",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_MISSES.WALK_COMPLETED",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "DTLB miss page walks",
        .full_desc = "DTLB miss page walks",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ES_REG_RENAMES",
        .encoding =
            {
                .code = 0xD5ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ES segment renames",
        .full_desc = "ES segment renames",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_ASSIST.ALL",
        .encoding =
            {
                .code = 0xF7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "X87 Floating point assists (Precise Event)",
        .full_desc = "X87 Floating point assists (Precise Event)",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_ASSIST.INPUT",
        .encoding =
            {
                .code = 0xF7ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "X87 Floating point assists for invalid input value (Precise Event)",
        .full_desc =
            "X87 Floating point assists for invalid input value (Precise Event)",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_ASSIST.OUTPUT",
        .encoding =
            {
                .code = 0xF7ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "X87 Floating point assists for invalid output value (Precise Event)",
        .full_desc =
            "X87 Floating point assists for invalid output value (Precise Event)",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.MMX",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "MMX Uops",
        .full_desc = "MMX Uops",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.SSE2_INTEGER",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SSE2 integer Uops",
        .full_desc = "SSE2 integer Uops",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.SSE_DOUBLE_PRECISION",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SSE* FP double precision Uops",
        .full_desc = "SSE* FP double precision Uops",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.SSE_FP",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SSE and SSE2 FP Uops",
        .full_desc = "SSE and SSE2 FP Uops",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.SSE_FP_PACKED",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SSE FP packed Uops",
        .full_desc = "SSE FP packed Uops",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.SSE_FP_SCALAR",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SSE FP scalar Uops",
        .full_desc = "SSE FP scalar Uops",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_COMP_OPS_EXE.SSE_SINGLE_PRECISION",
        .encoding =
            {
                .code = 0x10ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SSE* FP single precision Uops",
        .full_desc = "SSE* FP single precision Uops",
        .default_sampling_period = 0x1E8480ULL,
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
        .brief_desc = "Computational floating-point operations executed",
        .full_desc = "Computational floating-point operations executed",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_MMX_TRANS.ANY",
        .encoding =
            {
                .code = 0xCCULL,
                .umask = 0x3ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All Floating Point to and from MMX transitions",
        .full_desc = "All Floating Point to and from MMX transitions",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_MMX_TRANS.TO_FP",
        .encoding =
            {
                .code = 0xCCULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Transitions from MMX to Floating Point instructions",
        .full_desc = "Transitions from MMX to Floating Point instructions",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_MMX_TRANS.TO_MMX",
        .encoding =
            {
                .code = 0xCCULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Transitions from Floating Point to MMX instructions",
        .full_desc = "Transitions from Floating Point to MMX instructions",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ILD_STALL.ANY",
        .encoding =
            {
                .code = 0x87ULL,
                .umask = 0xFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Any Instruction Length Decoder stall cycles",
        .full_desc = "Any Instruction Length Decoder stall cycles",
        .default_sampling_period = 0x1E8480ULL,
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
        .brief_desc = "Instruction Queue full stall cycles",
        .full_desc = "Instruction Queue full stall cycles",
        .default_sampling_period = 0x1E8480ULL,
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
        .brief_desc = "Length Change Prefix stall cycles",
        .full_desc = "Length Change Prefix stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ILD_STALL.MRU",
        .encoding =
            {
                .code = 0x87ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stall cycles due to BPU MRU bypass",
        .full_desc = "Stall cycles due to BPU MRU bypass",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ILD_STALL.REGEN",
        .encoding =
            {
                .code = 0x87ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Regen stall cycles",
        .full_desc = "Regen stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_DECODED.DEC0",
        .encoding =
            {
                .code = 0x18ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Instructions that must be decoded by decoder 0",
        .full_desc = "Instructions that must be decoded by decoder 0",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_QUEUE_WRITES",
        .encoding =
            {
                .code = 0x17ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Instructions written to instruction queue.",
        .full_desc = "Instructions written to instruction queue.",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_QUEUE_WRITE_CYCLES",
        .encoding =
            {
                .code = 0x1EULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles instructions are written to the instruction queue",
        .full_desc = "Cycles instructions are written to the instruction queue",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_RETIRED.ANY",
        .encoding =
            {
                .code = 0x0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Instructions retired (fixed counter)",
        .full_desc = "Instructions retired (fixed counter)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_RETIRED.ANY_P",
        .encoding =
            {
                .code = 0xC0ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Instructions retired (Programmable counter and Precise Event)",
        .full_desc =
            "Instructions retired (Programmable counter and Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_RETIRED.MMX",
        .encoding =
            {
                .code = 0xC0ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired MMX instructions (Precise Event)",
        .full_desc = "Retired MMX instructions (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_RETIRED.TOTAL_CYCLES",
        .encoding =
            {
                .code = 0xC0ULL,
                .umask = 0x1ULL,
                .inv = true,
                .cmask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Total cycles (Precise Event)",
        .full_desc = "Total cycles (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_RETIRED.TOTAL_CYCLES_PS",
        .encoding =
            {
                .code = 0xC0ULL,
                .umask = 0x1ULL,
                .inv = true,
                .cmask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc = "Total cycles (Precise Event)",
        .full_desc = "Total cycles (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INST_RETIRED.X87",
        .encoding =
            {
                .code = 0xC0ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired floating-point operations (Precise Event)",
        .full_desc = "Retired floating-point operations (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "IO_TRANSACTIONS",
        .encoding =
            {
                .code = 0x6CULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "I/O transactions",
        .full_desc = "I/O transactions",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_FLUSH",
        .encoding =
            {
                .code = 0xAEULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ITLB flushes",
        .full_desc = "ITLB flushes",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISSES.ANY",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ITLB miss",
        .full_desc = "ITLB miss",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISS_RETIRED",
        .encoding =
            {
                .code = 0xC8ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired instructions that missed the ITLB (Precise Event)",
        .full_desc =
            "Retired instructions that missed the ITLB (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D.M_EVICT",
        .encoding =
            {
                .code = 0x51ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D cache lines replaced in M state",
        .full_desc = "L1D cache lines replaced in M state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D.M_REPL",
        .encoding =
            {
                .code = 0x51ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D cache lines allocated in the M state",
        .full_desc = "L1D cache lines allocated in the M state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D.M_SNOOP_EVICT",
        .encoding =
            {
                .code = 0x51ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D snoop eviction of cache lines in M state",
        .full_desc = "L1D snoop eviction of cache lines in M state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D.REPL",
        .encoding =
            {
                .code = 0x51ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache lines allocated",
        .full_desc = "L1 data cache lines allocated",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_ALL_REF.ANY",
        .encoding =
            {
                .code = 0x43ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All references to the L1 data cache",
        .full_desc = "All references to the L1 data cache",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_ALL_REF.CACHEABLE",
        .encoding =
            {
                .code = 0x43ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cacheable reads and writes",
        .full_desc = "L1 data cacheable reads and writes",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_LD.E_STATE",
        .encoding =
            {
                .code = 0x40ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache read in E state",
        .full_desc = "L1 data cache read in E state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_LD.I_STATE",
        .encoding =
            {
                .code = 0x40ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache read in I state (misses)",
        .full_desc = "L1 data cache read in I state (misses)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_LD.MESI",
        .encoding =
            {
                .code = 0x40ULL,
                .umask = 0xFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache reads",
        .full_desc = "L1 data cache reads",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_LD.M_STATE",
        .encoding =
            {
                .code = 0x40ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache read in M state",
        .full_desc = "L1 data cache read in M state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_LD.S_STATE",
        .encoding =
            {
                .code = 0x40ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache read in S state",
        .full_desc = "L1 data cache read in S state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_LOCK.E_STATE",
        .encoding =
            {
                .code = 0x42ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache load locks in E state",
        .full_desc = "L1 data cache load locks in E state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_LOCK.HIT",
        .encoding =
            {
                .code = 0x42ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache load lock hits",
        .full_desc = "L1 data cache load lock hits",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_LOCK.M_STATE",
        .encoding =
            {
                .code = 0x42ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache load locks in M state",
        .full_desc = "L1 data cache load locks in M state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_LOCK.S_STATE",
        .encoding =
            {
                .code = 0x42ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache load locks in S state",
        .full_desc = "L1 data cache load locks in S state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_LOCK_FB_HIT",
        .encoding =
            {
                .code = 0x53ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D load lock accepted in fill buffer",
        .full_desc = "L1D load lock accepted in fill buffer",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_PREFETCH_LOCK_FB_HIT",
        .encoding =
            {
                .code = 0x52ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D prefetch load lock accepted in fill buffer",
        .full_desc = "L1D prefetch load lock accepted in fill buffer",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_ST.E_STATE",
        .encoding =
            {
                .code = 0x41ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache stores in E state",
        .full_desc = "L1 data cache stores in E state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_ST.M_STATE",
        .encoding =
            {
                .code = 0x41ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache stores in M state",
        .full_desc = "L1 data cache stores in M state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_CACHE_ST.S_STATE",
        .encoding =
            {
                .code = 0x41ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 data cache stores in S state",
        .full_desc = "L1 data cache stores in S state",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_PREFETCH.MISS",
        .encoding =
            {
                .code = 0x4EULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D hardware prefetch misses",
        .full_desc = "L1D hardware prefetch misses",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_PREFETCH.REQUESTS",
        .encoding =
            {
                .code = 0x4EULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D hardware prefetch requests",
        .full_desc = "L1D hardware prefetch requests",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_PREFETCH.TRIGGERS",
        .encoding =
            {
                .code = 0x4EULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D hardware prefetch requests triggered",
        .full_desc = "L1D hardware prefetch requests triggered",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_WB_L2.E_STATE",
        .encoding =
            {
                .code = 0x28ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 writebacks to L2 in E state",
        .full_desc = "L1 writebacks to L2 in E state",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_WB_L2.I_STATE",
        .encoding =
            {
                .code = 0x28ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 writebacks to L2 in I state (misses)",
        .full_desc = "L1 writebacks to L2 in I state (misses)",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_WB_L2.MESI",
        .encoding =
            {
                .code = 0x28ULL,
                .umask = 0xFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All L1 writebacks to L2",
        .full_desc = "All L1 writebacks to L2",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_WB_L2.M_STATE",
        .encoding =
            {
                .code = 0x28ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 writebacks to L2 in M state",
        .full_desc = "L1 writebacks to L2 in M state",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1D_WB_L2.S_STATE",
        .encoding =
            {
                .code = 0x28ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1 writebacks to L2 in S state",
        .full_desc = "L1 writebacks to L2 in S state",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1I.CYCLES_STALLED",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1I instruction fetch stall cycles",
        .full_desc = "L1I instruction fetch stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1I.HITS",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1I instruction fetch hits",
        .full_desc = "L1I instruction fetch hits",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1I.MISSES",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1I instruction fetch misses",
        .full_desc = "L1I instruction fetch misses",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L1I.READS",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x3ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1I Instruction fetches",
        .full_desc = "L1I Instruction fetches",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_DATA_RQSTS.ANY",
        .encoding =
            {
                .code = 0x26ULL,
                .umask = 0xFFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All L2 data requests",
        .full_desc = "All L2 data requests",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_DATA_RQSTS.DEMAND.E_STATE",
        .encoding =
            {
                .code = 0x26ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 data demand loads in E state",
        .full_desc = "L2 data demand loads in E state",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_DATA_RQSTS.DEMAND.I_STATE",
        .encoding =
            {
                .code = 0x26ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 data demand loads in I state (misses)",
        .full_desc = "L2 data demand loads in I state (misses)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_DATA_RQSTS.DEMAND.MESI",
        .encoding =
            {
                .code = 0x26ULL,
                .umask = 0xFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 data demand requests",
        .full_desc = "L2 data demand requests",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_DATA_RQSTS.DEMAND.M_STATE",
        .encoding =
            {
                .code = 0x26ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 data demand loads in M state",
        .full_desc = "L2 data demand loads in M state",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_DATA_RQSTS.DEMAND.S_STATE",
        .encoding =
            {
                .code = 0x26ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 data demand loads in S state",
        .full_desc = "L2 data demand loads in S state",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_DATA_RQSTS.PREFETCH.E_STATE",
        .encoding =
            {
                .code = 0x26ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 data prefetches in E state",
        .full_desc = "L2 data prefetches in E state",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_DATA_RQSTS.PREFETCH.I_STATE",
        .encoding =
            {
                .code = 0x26ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 data prefetches in the I state (misses)",
        .full_desc = "L2 data prefetches in the I state (misses)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_DATA_RQSTS.PREFETCH.MESI",
        .encoding =
            {
                .code = 0x26ULL,
                .umask = 0xF0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All L2 data prefetches",
        .full_desc = "All L2 data prefetches",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_DATA_RQSTS.PREFETCH.M_STATE",
        .encoding =
            {
                .code = 0x26ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 data prefetches in M state",
        .full_desc = "L2 data prefetches in M state",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_DATA_RQSTS.PREFETCH.S_STATE",
        .encoding =
            {
                .code = 0x26ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 data prefetches in the S state",
        .full_desc = "L2 data prefetches in the S state",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_IN.ANY",
        .encoding =
            {
                .code = 0xF1ULL,
                .umask = 0x7ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 lines allocated",
        .full_desc = "L2 lines allocated",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_IN.E_STATE",
        .encoding =
            {
                .code = 0xF1ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 lines allocated in the E state",
        .full_desc = "L2 lines allocated in the E state",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_IN.S_STATE",
        .encoding =
            {
                .code = 0xF1ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 lines allocated in the S state",
        .full_desc = "L2 lines allocated in the S state",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_OUT.ANY",
        .encoding =
            {
                .code = 0xF2ULL,
                .umask = 0xFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 lines evicted",
        .full_desc = "L2 lines evicted",
        .default_sampling_period = 0x186A0ULL,
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
        .brief_desc = "L2 lines evicted by a demand request",
        .full_desc = "L2 lines evicted by a demand request",
        .default_sampling_period = 0x186A0ULL,
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
        .brief_desc = "L2 modified lines evicted by a demand request",
        .full_desc = "L2 modified lines evicted by a demand request",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_OUT.PREFETCH_CLEAN",
        .encoding =
            {
                .code = 0xF2ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 lines evicted by a prefetch request",
        .full_desc = "L2 lines evicted by a prefetch request",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_OUT.PREFETCH_DIRTY",
        .encoding =
            {
                .code = 0xF2ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 modified lines evicted by a prefetch request",
        .full_desc = "L2 modified lines evicted by a prefetch request",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.IFETCHES",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x30ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 instruction fetches",
        .full_desc = "L2 instruction fetches",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.IFETCH_HIT",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 instruction fetch hits",
        .full_desc = "L2 instruction fetch hits",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.IFETCH_MISS",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 instruction fetch misses",
        .full_desc = "L2 instruction fetch misses",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.LD_HIT",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 load hits",
        .full_desc = "L2 load hits",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.LD_MISS",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 load misses",
        .full_desc = "L2 load misses",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.LOADS",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x3ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 requests",
        .full_desc = "L2 requests",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.PREFETCHES",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0xC0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All L2 prefetches",
        .full_desc = "All L2 prefetches",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.PREFETCH_HIT",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 prefetch hits",
        .full_desc = "L2 prefetch hits",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.PREFETCH_MISS",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 prefetch misses",
        .full_desc = "L2 prefetch misses",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.REFERENCES",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0xFFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All L2 requests",
        .full_desc = "All L2 requests",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.RFOS",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0xCULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 RFO requests",
        .full_desc = "L2 RFO requests",
        .default_sampling_period = 0x30D40ULL,
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
        .brief_desc = "L2 RFO hits",
        .full_desc = "L2 RFO hits",
        .default_sampling_period = 0x30D40ULL,
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
        .brief_desc = "L2 RFO misses",
        .full_desc = "L2 RFO misses",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANSACTIONS.ANY",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All L2 transactions",
        .full_desc = "All L2 transactions",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANSACTIONS.FILL",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 fill transactions",
        .full_desc = "L2 fill transactions",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANSACTIONS.IFETCH",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 instruction fetch transactions",
        .full_desc = "L2 instruction fetch transactions",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANSACTIONS.L1D_WB",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L1D writeback to L2 transactions",
        .full_desc = "L1D writeback to L2 transactions",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANSACTIONS.LOAD",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 Load transactions",
        .full_desc = "L2 Load transactions",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANSACTIONS.PREFETCH",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 prefetch transactions",
        .full_desc = "L2 prefetch transactions",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANSACTIONS.RFO",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 RFO transactions",
        .full_desc = "L2 RFO transactions",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_TRANSACTIONS.WB",
        .encoding =
            {
                .code = 0xF0ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 writeback to LLC transactions",
        .full_desc = "L2 writeback to LLC transactions",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_WRITE.LOCK.E_STATE",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 demand lock RFOs in E state",
        .full_desc = "L2 demand lock RFOs in E state",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_WRITE.LOCK.HIT",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0xE0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All demand L2 lock RFOs that hit the cache",
        .full_desc = "All demand L2 lock RFOs that hit the cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_WRITE.LOCK.I_STATE",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 demand lock RFOs in I state (misses)",
        .full_desc = "L2 demand lock RFOs in I state (misses)",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_WRITE.LOCK.MESI",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0xF0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All demand L2 lock RFOs",
        .full_desc = "All demand L2 lock RFOs",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_WRITE.LOCK.M_STATE",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 demand lock RFOs in M state",
        .full_desc = "L2 demand lock RFOs in M state",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_WRITE.LOCK.S_STATE",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 demand lock RFOs in S state",
        .full_desc = "L2 demand lock RFOs in S state",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_WRITE.RFO.HIT",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0xEULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All L2 demand store RFOs that hit the cache",
        .full_desc = "All L2 demand store RFOs that hit the cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_WRITE.RFO.I_STATE",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 demand store RFOs in I state (misses)",
        .full_desc = "L2 demand store RFOs in I state (misses)",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_WRITE.RFO.MESI",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0xFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All L2 demand store RFOs",
        .full_desc = "All L2 demand store RFOs",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_WRITE.RFO.M_STATE",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 demand store RFOs in M state",
        .full_desc = "L2 demand store RFOs in M state",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_WRITE.RFO.S_STATE",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 demand store RFOs in S state",
        .full_desc = "L2 demand store RFOs in S state",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LARGE_ITLB.HIT",
        .encoding =
            {
                .code = 0x82ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Large ITLB hit",
        .full_desc = "Large ITLB hit",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LOAD_DISPATCH.ANY",
        .encoding =
            {
                .code = 0x13ULL,
                .umask = 0x7ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All loads dispatched",
        .full_desc = "All loads dispatched",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LOAD_DISPATCH.MOB",
        .encoding =
            {
                .code = 0x13ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Loads dispatched from the MOB",
        .full_desc = "Loads dispatched from the MOB",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LOAD_DISPATCH.RS",
        .encoding =
            {
                .code = 0x13ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Loads dispatched that bypass the MOB",
        .full_desc = "Loads dispatched that bypass the MOB",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LOAD_DISPATCH.RS_DELAYED",
        .encoding =
            {
                .code = 0x13ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Loads dispatched from stage 305",
        .full_desc = "Loads dispatched from stage 305",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LOAD_HIT_PRE",
        .encoding =
            {
                .code = 0x4CULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Load operations conflicting with software prefetches",
        .full_desc = "Load operations conflicting with software prefetches",
        .default_sampling_period = 0x30D40ULL,
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
        .brief_desc = "Longest latency cache reference",
        .full_desc = "Longest latency cache reference",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LSD.ACTIVE",
        .encoding =
            {
                .code = 0xA8ULL,
                .umask = 0x1ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles when uops were delivered by the LSD",
        .full_desc = "Cycles when uops were delivered by the LSD",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LSD.INACTIVE",
        .encoding =
            {
                .code = 0xA8ULL,
                .umask = 0x1ULL,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles no uops were delivered by the LSD",
        .full_desc = "Cycles no uops were delivered by the LSD",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "LSD_OVERFLOW",
        .encoding =
            {
                .code = 0x20ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Loops that can't stream from the instruction queue",
        .full_desc = "Loops that can't stream from the instruction queue",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MACHINE_CLEARS.CYCLES",
        .encoding =
            {
                .code = 0xC3ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles machine clear asserted",
        .full_desc = "Cycles machine clear asserted",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MACHINE_CLEARS.MEM_ORDER",
        .encoding =
            {
                .code = 0xC3ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Execution pipeline restart due to Memory ordering conflicts",
        .full_desc =
            "Execution pipeline restart due to Memory ordering conflicts",
        .default_sampling_period = 0x4E20ULL,
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
        .brief_desc = "Self-Modifying Code detected",
        .full_desc = "Self-Modifying Code detected",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MACRO_INSTS.DECODED",
        .encoding =
            {
                .code = 0xD0ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Instructions decoded",
        .full_desc = "Instructions decoded",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MACRO_INSTS.FUSIONS_DECODED",
        .encoding =
            {
                .code = 0xA6ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Macro-fused instructions decoded",
        .full_desc = "Macro-fused instructions decoded",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_0",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 0 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 0 clocks (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_1024",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x400ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 1024 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 1024 clocks (Precise Event)",
        .default_sampling_period = 0x64ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_128",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x80ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 128 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 128 clocks (Precise Event)",
        .default_sampling_period = 0x3E8ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_16",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x10ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 16 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 16 clocks (Precise Event)",
        .default_sampling_period = 0x2710ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_16384",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x4000ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 16384 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 16384 clocks (Precise Event)",
        .default_sampling_period = 0x5ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_2048",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x800ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 2048 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 2048 clocks (Precise Event)",
        .default_sampling_period = 0x32ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_256",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x100ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 256 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 256 clocks (Precise Event)",
        .default_sampling_period = 0x1F4ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_32",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x20ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 32 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 32 clocks (Precise Event)",
        .default_sampling_period = 0x1388ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_32768",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x8000ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 32768 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 32768 clocks (Precise Event)",
        .default_sampling_period = 0x3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_4",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x4ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 4 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 4 clocks (Precise Event)",
        .default_sampling_period = 0xC350ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_4096",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x1000ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 4096 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 4096 clocks (Precise Event)",
        .default_sampling_period = 0x14ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_512",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x200ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 512 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 512 clocks (Precise Event)",
        .default_sampling_period = 0xC8ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_64",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x40ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 64 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 64 clocks (Precise Event)",
        .default_sampling_period = 0x7D0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_8",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x8ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 8 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 8 clocks (Precise Event)",
        .default_sampling_period = 0x4E20ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_8192",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x2000ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Memory instructions retired above 8192 clocks (Precise Event)",
        .full_desc =
            "Memory instructions retired above 8192 clocks (Precise Event)",
        .default_sampling_period = 0xAULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.LOADS",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Instructions retired which contains a load (Precise Event)",
        .full_desc =
            "Instructions retired which contains a load (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_INST_RETIRED.STORES",
        .encoding =
            {
                .code = 0xBULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Instructions retired which contains a store (Precise Event)",
        .full_desc =
            "Instructions retired which contains a store (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_RETIRED.DTLB_MISS",
        .encoding =
            {
                .code = 0xCBULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired loads that miss the DTLB (Precise Event)",
        .full_desc = "Retired loads that miss the DTLB (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_RETIRED.HIT_LFB",
        .encoding =
            {
                .code = 0xCBULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired loads that miss L1D and hit an previously allocated LFB (Precise Event)",
        .full_desc =
            "Retired loads that miss L1D and hit an previously allocated LFB (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_RETIRED.L1D_HIT",
        .encoding =
            {
                .code = 0xCBULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired loads that hit the L1 data cache (Precise Event)",
        .full_desc = "Retired loads that hit the L1 data cache (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_RETIRED.L2_HIT",
        .encoding =
            {
                .code = 0xCBULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired loads that hit the L2 cache (Precise Event)",
        .full_desc = "Retired loads that hit the L2 cache (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_RETIRED.LLC_MISS",
        .encoding =
            {
                .code = 0xCBULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired loads that miss the LLC cache (Precise Event)",
        .full_desc = "Retired loads that miss the LLC cache (Precise Event)",
        .default_sampling_period = 0x2710ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_RETIRED.LLC_UNSHARED_HIT",
        .encoding =
            {
                .code = 0xCBULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired loads that hit valid versions in the LLC cache (Precise Event)",
        .full_desc =
            "Retired loads that hit valid versions in the LLC cache (Precise Event)",
        .default_sampling_period = 0x9C40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_RETIRED.OTHER_CORE_L2_HIT_HITM",
        .encoding =
            {
                .code = 0xCBULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Retired loads that hit sibling core's L2 in modified or unmodified states (Precise Event)",
        .full_desc =
            "Retired loads that hit sibling core's L2 in modified or unmodified states (Precise Event)",
        .default_sampling_period = 0x9C40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_STORE_RETIRED.DTLB_MISS",
        .encoding =
            {
                .code = 0xCULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retired stores that miss the DTLB (Precise Event)",
        .full_desc = "Retired stores that miss the DTLB (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS.L1D_WRITEBACK",
        .encoding =
            {
                .code = 0xB0ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore L1 data cache writebacks",
        .full_desc = "Offcore L1 data cache writebacks",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_REQUESTS_SQ_FULL",
        .encoding =
            {
                .code = 0xB2ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests blocked due to Super Queue full",
        .full_desc = "Offcore requests blocked due to Super Queue full",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F11ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore data reads satisfied by any cache or DRAM",
        .full_desc = "Offcore data reads satisfied by any cache or DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6011ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore data reads satisfied by any DRAM",
        .full_desc = "Offcore data reads satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF811ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore data reads that missed the LLC",
        .full_desc = "Offcore data reads that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF11ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore data reads",
        .full_desc = "All offcore data reads",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8011ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore data reads satisfied by the IO, CSR, MMIO unit",
        .full_desc = "Offcore data reads satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x111ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore data reads satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x211ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore data reads satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x411ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore data reads satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x711ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore data reads satisfied by the LLC",
        .full_desc = "Offcore data reads satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4711ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore data reads satisfied by the LLC or local DRAM",
        .full_desc = "Offcore data reads satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4011ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore data reads satisfied by the local DRAM",
        .full_desc = "Offcore data reads satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1811ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore data reads satisfied by a remote cache",
        .full_desc = "Offcore data reads satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3811ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore data reads satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1011ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore data reads that HIT in a remote cache",
        .full_desc = "Offcore data reads that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x811ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore data reads that HITM in a remote cache",
        .full_desc = "Offcore data reads that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_DATA.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2011ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore data reads satisfied by a remote DRAM",
        .full_desc = "Offcore data reads satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F44ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code reads satisfied by any cache or DRAM",
        .full_desc = "Offcore code reads satisfied by any cache or DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6044ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code reads satisfied by any DRAM",
        .full_desc = "Offcore code reads satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF844ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code reads that missed the LLC",
        .full_desc = "Offcore code reads that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF44ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore code reads",
        .full_desc = "All offcore code reads",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8044ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code reads satisfied by the IO, CSR, MMIO unit",
        .full_desc = "Offcore code reads satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x144ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code reads satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore code reads satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x244ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code reads satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore code reads satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x444ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code reads satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore code reads satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x744ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code reads satisfied by the LLC",
        .full_desc = "Offcore code reads satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4744ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code reads satisfied by the LLC or local DRAM",
        .full_desc = "Offcore code reads satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4044ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code reads satisfied by the local DRAM",
        .full_desc = "Offcore code reads satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1844ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code reads satisfied by a remote cache",
        .full_desc = "Offcore code reads satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3844ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code reads satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore code reads satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1044ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code reads that HIT in a remote cache",
        .full_desc = "Offcore code reads that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x844ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code reads that HITM in a remote cache",
        .full_desc = "Offcore code reads that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_IFETCH.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2044ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code reads satisfied by a remote DRAM",
        .full_desc = "Offcore code reads satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7FFFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests satisfied by any cache or DRAM",
        .full_desc = "Offcore requests satisfied by any cache or DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x60FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests satisfied by any DRAM",
        .full_desc = "Offcore requests satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF8FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests that missed the LLC",
        .full_desc = "Offcore requests that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFFFFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore requests",
        .full_desc = "All offcore requests",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests satisfied by the IO, CSR, MMIO unit",
        .full_desc = "Offcore requests satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore requests satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore requests satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore requests satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore requests satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore requests satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore requests satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests satisfied by the LLC",
        .full_desc = "Offcore requests satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x47FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests satisfied by the LLC or local DRAM",
        .full_desc = "Offcore requests satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x40FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests satisfied by the local DRAM",
        .full_desc = "Offcore requests satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x18FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests satisfied by a remote cache",
        .full_desc = "Offcore requests satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x38FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore requests satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore requests satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests that HIT in a remote cache",
        .full_desc = "Offcore requests that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests that HITM in a remote cache",
        .full_desc = "Offcore requests that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_REQUEST.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20FFULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore requests satisfied by a remote DRAM",
        .full_desc = "Offcore requests satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F22ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore RFO requests satisfied by any cache or DRAM",
        .full_desc = "Offcore RFO requests satisfied by any cache or DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6022ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore RFO requests satisfied by any DRAM",
        .full_desc = "Offcore RFO requests satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF822ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore RFO requests that missed the LLC",
        .full_desc = "Offcore RFO requests that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF22ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore RFO requests",
        .full_desc = "All offcore RFO requests",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8022ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore RFO requests satisfied by the IO, CSR, MMIO unit",
        .full_desc = "Offcore RFO requests satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore RFO requests satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore RFO requests satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x222ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore RFO requests satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore RFO requests satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x422ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore RFO requests satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore RFO requests satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x722ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore RFO requests satisfied by the LLC",
        .full_desc = "Offcore RFO requests satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4722ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore RFO requests satisfied by the LLC or local DRAM",
        .full_desc = "Offcore RFO requests satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4022ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore RFO requests satisfied by the local DRAM",
        .full_desc = "Offcore RFO requests satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1822ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore RFO requests satisfied by a remote cache",
        .full_desc = "Offcore RFO requests satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3822ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore RFO requests satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore RFO requests satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1022ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore RFO requests that HIT in a remote cache",
        .full_desc = "Offcore RFO requests that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x822ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore RFO requests that HITM in a remote cache",
        .full_desc = "Offcore RFO requests that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.ANY_RFO.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2022ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore RFO requests satisfied by a remote DRAM",
        .full_desc = "Offcore RFO requests satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F08ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks to any cache or DRAM.",
        .full_desc = "Offcore writebacks to any cache or DRAM.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks to any DRAM",
        .full_desc = "Offcore writebacks to any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF808ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks that missed the LLC",
        .full_desc = "Offcore writebacks that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF08ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore writebacks",
        .full_desc = "All offcore writebacks",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks to the IO, CSR, MMIO unit.",
        .full_desc = "Offcore writebacks to the IO, CSR, MMIO unit.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x108ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore writebacks to the LLC and not found in a sibling core",
        .full_desc =
            "Offcore writebacks to the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x408ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore writebacks to the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore writebacks to the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x708ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks to the LLC",
        .full_desc = "Offcore writebacks to the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4708ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks to the LLC or local DRAM",
        .full_desc = "Offcore writebacks to the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks to the local DRAM",
        .full_desc = "Offcore writebacks to the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1808ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks to a remote cache",
        .full_desc = "Offcore writebacks to a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3808ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks to a remote cache or remote DRAM",
        .full_desc = "Offcore writebacks to a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks that HIT in a remote cache",
        .full_desc = "Offcore writebacks that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x808ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks that HITM in a remote cache",
        .full_desc = "Offcore writebacks that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.COREWB.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore writebacks to a remote DRAM",
        .full_desc = "Offcore writebacks to a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F77ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests satisfied by any cache or DRAM.",
        .full_desc =
            "Offcore code or data read requests satisfied by any cache or DRAM.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6077ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests satisfied by any DRAM",
        .full_desc = "Offcore code or data read requests satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF877ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code or data read requests that missed the LLC",
        .full_desc = "Offcore code or data read requests that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF77ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore code or data read requests",
        .full_desc = "All offcore code or data read requests",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8077ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests satisfied by the IO, CSR, MMIO unit.",
        .full_desc =
            "Offcore code or data read requests satisfied by the IO, CSR, MMIO unit.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x177ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore code or data read requests satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x277ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore code or data read requests satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x477ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore code or data read requests satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x777ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore code or data read requests satisfied by the LLC",
        .full_desc = "Offcore code or data read requests satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4777ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests satisfied by the LLC or local DRAM",
        .full_desc =
            "Offcore code or data read requests satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4077ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests satisfied by the local DRAM",
        .full_desc =
            "Offcore code or data read requests satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1877ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests satisfied by a remote cache",
        .full_desc =
            "Offcore code or data read requests satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3877ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore code or data read requests satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1077ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests that HIT in a remote cache",
        .full_desc =
            "Offcore code or data read requests that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x877ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests that HITM in a remote cache",
        .full_desc =
            "Offcore code or data read requests that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IFETCH.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2077ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore code or data read requests satisfied by a remote DRAM",
        .full_desc =
            "Offcore code or data read requests satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F33ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore request = all data, response = any cache_dram",
        .full_desc = "Offcore request = all data, response = any cache_dram",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6033ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore request = all data, response = any DRAM",
        .full_desc = "Offcore request = all data, response = any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF833ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore request = all data, response = any LLC miss",
        .full_desc = "Offcore request = all data, response = any LLC miss",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF33ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore request = all data, response = any location",
        .full_desc = "Offcore request = all data, response = any location",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8033ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the IO, CSR, MMIO unit",
        .full_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x133ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x233ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x433ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x733ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore request = all data, response = local cache",
        .full_desc = "Offcore request = all data, response = local cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4733ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore request = all data, response = local cache or dram",
        .full_desc =
            "Offcore request = all data, response = local cache or dram",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4033ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the local DRAM.",
        .full_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the local DRAM.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1833ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore request = all data, response = remote cache",
        .full_desc = "Offcore request = all data, response = remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3833ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore request = all data, response = remote cache or dram",
        .full_desc =
            "Offcore request = all data, response = remote cache or dram",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1033ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads, RFOs, and prefetches that HIT in a remote cache ",
        .full_desc =
            "Offcore data reads, RFOs, and prefetches that HIT in a remote cache ",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x833ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads, RFOs, and prefetches that HITM in a remote cache",
        .full_desc =
            "Offcore data reads, RFOs, and prefetches that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DATA_IN.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2033ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the remote DRAM",
        .full_desc =
            "Offcore data reads, RFOs, and prefetches satisfied by the remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F03ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data requests satisfied by any cache or DRAM",
        .full_desc =
            "Offcore demand data requests satisfied by any cache or DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6003ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data requests satisfied by any DRAM",
        .full_desc = "Offcore demand data requests satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF803ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data requests that missed the LLC",
        .full_desc = "Offcore demand data requests that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF03ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore demand data requests",
        .full_desc = "All offcore demand data requests",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8003ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data requests satisfied by the IO, CSR, MMIO unit.",
        .full_desc =
            "Offcore demand data requests satisfied by the IO, CSR, MMIO unit.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x103ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data requests satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore demand data requests satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x203ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data requests satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore demand data requests satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x403ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data requests satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore demand data requests satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x703ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data requests satisfied by the LLC",
        .full_desc = "Offcore demand data requests satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4703ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data requests satisfied by the LLC or local DRAM",
        .full_desc =
            "Offcore demand data requests satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data requests satisfied by the local DRAM",
        .full_desc = "Offcore demand data requests satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1803ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data requests satisfied by a remote cache",
        .full_desc = "Offcore demand data requests satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3803ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data requests satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore demand data requests satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data requests that HIT in a remote cache",
        .full_desc = "Offcore demand data requests that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data requests that HITM in a remote cache",
        .full_desc = "Offcore demand data requests that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data requests satisfied by a remote DRAM",
        .full_desc = "Offcore demand data requests satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F01ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data reads satisfied by any cache or DRAM.",
        .full_desc =
            "Offcore demand data reads satisfied by any cache or DRAM.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data reads satisfied by any DRAM",
        .full_desc = "Offcore demand data reads satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF801ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data reads that missed the LLC",
        .full_desc = "Offcore demand data reads that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF01ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore demand data reads",
        .full_desc = "All offcore demand data reads",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data reads satisfied by the IO, CSR, MMIO unit",
        .full_desc =
            "Offcore demand data reads satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x101ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data reads satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore demand data reads satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x201ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data reads satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore demand data reads satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x401ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data reads satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore demand data reads satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x701ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data reads satisfied by the LLC",
        .full_desc = "Offcore demand data reads satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4701ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data reads satisfied by the LLC or local DRAM",
        .full_desc =
            "Offcore demand data reads satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data reads satisfied by the local DRAM",
        .full_desc = "Offcore demand data reads satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1801ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data reads satisfied by a remote cache",
        .full_desc = "Offcore demand data reads satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3801ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand data reads satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore demand data reads satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data reads that HIT in a remote cache",
        .full_desc = "Offcore demand data reads that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x801ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data reads that HITM in a remote cache",
        .full_desc = "Offcore demand data reads that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand data reads satisfied by a remote DRAM",
        .full_desc = "Offcore demand data reads satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F04ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand code reads satisfied by any cache or DRAM.",
        .full_desc =
            "Offcore demand code reads satisfied by any cache or DRAM.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand code reads satisfied by any DRAM",
        .full_desc = "Offcore demand code reads satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF804ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand code reads that missed the LLC",
        .full_desc = "Offcore demand code reads that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF04ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore demand code reads",
        .full_desc = "All offcore demand code reads",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand code reads satisfied by the IO, CSR, MMIO unit",
        .full_desc =
            "Offcore demand code reads satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand code reads satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore demand code reads satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand code reads satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore demand code reads satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand code reads satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore demand code reads satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x704ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand code reads satisfied by the LLC",
        .full_desc = "Offcore demand code reads satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4704ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand code reads satisfied by the LLC or local DRAM",
        .full_desc =
            "Offcore demand code reads satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand code reads satisfied by the local DRAM",
        .full_desc = "Offcore demand code reads satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1804ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand code reads satisfied by a remote cache",
        .full_desc = "Offcore demand code reads satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3804ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand code reads satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore demand code reads satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand code reads that HIT in a remote cache",
        .full_desc = "Offcore demand code reads that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x804ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand code reads that HITM in a remote cache",
        .full_desc = "Offcore demand code reads that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_IFETCH.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand code reads satisfied by a remote DRAM",
        .full_desc = "Offcore demand code reads satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F02ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand RFO requests satisfied by any cache or DRAM.",
        .full_desc =
            "Offcore demand RFO requests satisfied by any cache or DRAM.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand RFO requests satisfied by any DRAM",
        .full_desc = "Offcore demand RFO requests satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF802ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand RFO requests that missed the LLC",
        .full_desc = "Offcore demand RFO requests that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF02ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore demand RFO requests",
        .full_desc = "All offcore demand RFO requests",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand RFO requests satisfied by the IO, CSR, MMIO unit",
        .full_desc =
            "Offcore demand RFO requests satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x102ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand RFO requests satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore demand RFO requests satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x202ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand RFO requests satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore demand RFO requests satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x402ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand RFO requests satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore demand RFO requests satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x702ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand RFO requests satisfied by the LLC",
        .full_desc = "Offcore demand RFO requests satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4702ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand RFO requests satisfied by the LLC or local DRAM",
        .full_desc =
            "Offcore demand RFO requests satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand RFO requests satisfied by the local DRAM",
        .full_desc = "Offcore demand RFO requests satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1802ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand RFO requests satisfied by a remote cache",
        .full_desc = "Offcore demand RFO requests satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3802ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore demand RFO requests satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore demand RFO requests satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand RFO requests that HIT in a remote cache",
        .full_desc = "Offcore demand RFO requests that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x802ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand RFO requests that HITM in a remote cache",
        .full_desc = "Offcore demand RFO requests that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.DEMAND_RFO.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore demand RFO requests satisfied by a remote DRAM",
        .full_desc = "Offcore demand RFO requests satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F80ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore other requests satisfied by any cache or DRAM.",
        .full_desc = "Offcore other requests satisfied by any cache or DRAM.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6080ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore other requests satisfied by any DRAM",
        .full_desc = "Offcore other requests satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF880ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore other requests that missed the LLC",
        .full_desc = "Offcore other requests that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF80ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore other requests",
        .full_desc = "All offcore other requests",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8080ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore other requests satisfied by the IO, CSR, MMIO unit",
        .full_desc =
            "Offcore other requests satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x180ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore other requests satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore other requests satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x280ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore other requests satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore other requests satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x480ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore other requests satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore other requests satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x780ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore other requests satisfied by the LLC",
        .full_desc = "Offcore other requests satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4780ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore other requests satisfied by the LLC or local DRAM",
        .full_desc =
            "Offcore other requests satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1880ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore other requests satisfied by a remote cache",
        .full_desc = "Offcore other requests satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3880ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore other requests satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore other requests satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1080ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore other requests that HIT in a remote cache",
        .full_desc = "Offcore other requests that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x880ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore other requests that HITM in a remote cache",
        .full_desc = "Offcore other requests that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.OTHER.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2080ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore other requests satisfied by a remote DRAM",
        .full_desc = "Offcore other requests satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F30ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests satisfied by any cache or DRAM",
        .full_desc =
            "Offcore prefetch data requests satisfied by any cache or DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6030ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch data requests satisfied by any DRAM",
        .full_desc = "Offcore prefetch data requests satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF830ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch data requests that missed the LLC",
        .full_desc = "Offcore prefetch data requests that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF30ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore prefetch data requests",
        .full_desc = "All offcore prefetch data requests",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8030ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests satisfied by the IO, CSR, MMIO unit.",
        .full_desc =
            "Offcore prefetch data requests satisfied by the IO, CSR, MMIO unit.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x130ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore prefetch data requests satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x230ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore prefetch data requests satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x430ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore prefetch data requests satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x730ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch data requests satisfied by the LLC",
        .full_desc = "Offcore prefetch data requests satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4730ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests satisfied by the LLC or local DRAM",
        .full_desc =
            "Offcore prefetch data requests satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4030ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests satisfied by the local DRAM",
        .full_desc =
            "Offcore prefetch data requests satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1830ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests satisfied by a remote cache",
        .full_desc =
            "Offcore prefetch data requests satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3830ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore prefetch data requests satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1030ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests that HIT in a remote cache",
        .full_desc =
            "Offcore prefetch data requests that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x830ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests that HITM in a remote cache",
        .full_desc =
            "Offcore prefetch data requests that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2030ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data requests satisfied by a remote DRAM",
        .full_desc =
            "Offcore prefetch data requests satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F10ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data reads satisfied by any cache or DRAM.",
        .full_desc =
            "Offcore prefetch data reads satisfied by any cache or DRAM.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch data reads satisfied by any DRAM",
        .full_desc = "Offcore prefetch data reads satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF810ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch data reads that missed the LLC",
        .full_desc = "Offcore prefetch data reads that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF10ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore prefetch data reads",
        .full_desc = "All offcore prefetch data reads",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data reads satisfied by the IO, CSR, MMIO unit",
        .full_desc =
            "Offcore prefetch data reads satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x110ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data reads satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore prefetch data reads satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x210ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data reads satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore prefetch data reads satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x410ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data reads satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore prefetch data reads satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x710ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch data reads satisfied by the LLC",
        .full_desc = "Offcore prefetch data reads satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4710ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data reads satisfied by the LLC or local DRAM",
        .full_desc =
            "Offcore prefetch data reads satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch data reads satisfied by the local DRAM",
        .full_desc = "Offcore prefetch data reads satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1810ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch data reads satisfied by a remote cache",
        .full_desc = "Offcore prefetch data reads satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3810ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch data reads satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore prefetch data reads satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch data reads that HIT in a remote cache",
        .full_desc = "Offcore prefetch data reads that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x810ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch data reads that HITM in a remote cache",
        .full_desc = "Offcore prefetch data reads that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_DATA_RD.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch data reads satisfied by a remote DRAM",
        .full_desc = "Offcore prefetch data reads satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F40ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch code reads satisfied by any cache or DRAM.",
        .full_desc =
            "Offcore prefetch code reads satisfied by any cache or DRAM.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch code reads satisfied by any DRAM",
        .full_desc = "Offcore prefetch code reads satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF840ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch code reads that missed the LLC",
        .full_desc = "Offcore prefetch code reads that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF40ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore prefetch code reads",
        .full_desc = "All offcore prefetch code reads",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch code reads satisfied by the IO, CSR, MMIO unit",
        .full_desc =
            "Offcore prefetch code reads satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x140ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch code reads satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore prefetch code reads satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch code reads satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore prefetch code reads satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x440ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch code reads satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore prefetch code reads satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x740ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch code reads satisfied by the LLC",
        .full_desc = "Offcore prefetch code reads satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4740ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch code reads satisfied by the LLC or local DRAM",
        .full_desc =
            "Offcore prefetch code reads satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch code reads satisfied by the local DRAM",
        .full_desc = "Offcore prefetch code reads satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1840ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch code reads satisfied by a remote cache",
        .full_desc = "Offcore prefetch code reads satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3840ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch code reads satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore prefetch code reads satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch code reads that HIT in a remote cache",
        .full_desc = "Offcore prefetch code reads that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x840ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch code reads that HITM in a remote cache",
        .full_desc = "Offcore prefetch code reads that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_IFETCH.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch code reads satisfied by a remote DRAM",
        .full_desc = "Offcore prefetch code reads satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F20ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests satisfied by any cache or DRAM.",
        .full_desc =
            "Offcore prefetch RFO requests satisfied by any cache or DRAM.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6020ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch RFO requests satisfied by any DRAM",
        .full_desc = "Offcore prefetch RFO requests satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF820ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch RFO requests that missed the LLC",
        .full_desc = "Offcore prefetch RFO requests that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF20ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore prefetch RFO requests",
        .full_desc = "All offcore prefetch RFO requests",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8020ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests satisfied by the IO, CSR, MMIO unit",
        .full_desc =
            "Offcore prefetch RFO requests satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore prefetch RFO requests satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x220ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore prefetch RFO requests satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x420ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore prefetch RFO requests satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x720ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch RFO requests satisfied by the LLC",
        .full_desc = "Offcore prefetch RFO requests satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4720ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests satisfied by the LLC or local DRAM",
        .full_desc =
            "Offcore prefetch RFO requests satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4020ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests satisfied by the local DRAM",
        .full_desc =
            "Offcore prefetch RFO requests satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1820ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests satisfied by a remote cache",
        .full_desc =
            "Offcore prefetch RFO requests satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3820ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore prefetch RFO requests satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1020ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests that HIT in a remote cache",
        .full_desc = "Offcore prefetch RFO requests that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x820ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests that HITM in a remote cache",
        .full_desc =
            "Offcore prefetch RFO requests that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PF_RFO.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2020ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch RFO requests satisfied by a remote DRAM",
        .full_desc = "Offcore prefetch RFO requests satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.ANY_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x7F70ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch requests satisfied by any cache or DRAM.",
        .full_desc =
            "Offcore prefetch requests satisfied by any cache or DRAM.",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.ANY_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x6070ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch requests satisfied by any DRAM",
        .full_desc = "Offcore prefetch requests satisfied by any DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.ANY_LLC_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xF870ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch requests that missed the LLC",
        .full_desc = "Offcore prefetch requests that missed the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.ANY_LOCATION",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xFF70ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All offcore prefetch requests",
        .full_desc = "All offcore prefetch requests",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.IO_CSR_MMIO",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x8070ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch requests satisfied by the IO, CSR, MMIO unit",
        .full_desc =
            "Offcore prefetch requests satisfied by the IO, CSR, MMIO unit",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.LLC_HIT_NO_OTHER_CORE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x170ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch requests satisfied by the LLC and not found in a sibling core",
        .full_desc =
            "Offcore prefetch requests satisfied by the LLC and not found in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.LLC_HIT_OTHER_CORE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x270ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch requests satisfied by the LLC and HIT in a sibling core",
        .full_desc =
            "Offcore prefetch requests satisfied by the LLC and HIT in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.LLC_HIT_OTHER_CORE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x470ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch requests satisfied by the LLC  and HITM in a sibling core",
        .full_desc =
            "Offcore prefetch requests satisfied by the LLC  and HITM in a sibling core",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.LOCAL_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x770ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch requests satisfied by the LLC",
        .full_desc = "Offcore prefetch requests satisfied by the LLC",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.LOCAL_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4770ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch requests satisfied by the LLC or local DRAM",
        .full_desc =
            "Offcore prefetch requests satisfied by the LLC or local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.LOCAL_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4070ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch requests satisfied by the local DRAM",
        .full_desc = "Offcore prefetch requests satisfied by the local DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.REMOTE_CACHE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1870ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch requests satisfied by a remote cache",
        .full_desc = "Offcore prefetch requests satisfied by a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.REMOTE_CACHE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3870ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Offcore prefetch requests satisfied by a remote cache or remote DRAM",
        .full_desc =
            "Offcore prefetch requests satisfied by a remote cache or remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.REMOTE_CACHE_HIT",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1070ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch requests that HIT in a remote cache",
        .full_desc = "Offcore prefetch requests that HIT in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.REMOTE_CACHE_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x870ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch requests that HITM in a remote cache",
        .full_desc = "Offcore prefetch requests that HITM in a remote cache",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE_0.PREFETCH.REMOTE_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2070ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Offcore prefetch requests satisfied by a remote DRAM",
        .full_desc = "Offcore prefetch requests satisfied by a remote DRAM",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "PARTIAL_ADDRESS_ALIAS",
        .encoding =
            {
                .code = 0x7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "False dependencies due to partial address aliasing",
        .full_desc = "False dependencies due to partial address aliasing",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RAT_STALLS.ANY",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0xFULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All RAT stall cycles",
        .full_desc = "All RAT stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RAT_STALLS.FLAGS",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Flag stall cycles",
        .full_desc = "Flag stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RAT_STALLS.REGISTERS",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Partial register stall cycles",
        .full_desc = "Partial register stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RAT_STALLS.ROB_READ_PORT",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ROB read port stalls cycles",
        .full_desc = "ROB read port stalls cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RAT_STALLS.SCOREBOARD",
        .encoding =
            {
                .code = 0xD2ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Scoreboard stall cycles",
        .full_desc = "Scoreboard stall cycles",
        .default_sampling_period = 0x1E8480ULL,
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
        .brief_desc = "Resource related stall cycles",
        .full_desc = "Resource related stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RESOURCE_STALLS.FPCW",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "FPU control word write stall cycles",
        .full_desc = "FPU control word write stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RESOURCE_STALLS.LOAD",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Load buffer stall cycles",
        .full_desc = "Load buffer stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RESOURCE_STALLS.MXCSR",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "MXCSR rename stall cycles",
        .full_desc = "MXCSR rename stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RESOURCE_STALLS.OTHER",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Other Resource related stall cycles",
        .full_desc = "Other Resource related stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RESOURCE_STALLS.ROB_FULL",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "ROB full stall cycles",
        .full_desc = "ROB full stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RESOURCE_STALLS.RS_FULL",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Reservation Station full stall cycles",
        .full_desc = "Reservation Station full stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "RESOURCE_STALLS.STORE",
        .encoding =
            {
                .code = 0xA2ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Store buffer stall cycles",
        .full_desc = "Store buffer stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SB_DRAIN.ANY",
        .encoding =
            {
                .code = 0x4ULL,
                .umask = 0x7ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "All Store buffer stall cycles",
        .full_desc = "All Store buffer stall cycles",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SEG_RENAME_STALLS",
        .encoding =
            {
                .code = 0xD4ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Segment rename stall cycles",
        .full_desc = "Segment rename stall cycles",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_128.PACK",
        .encoding =
            {
                .code = 0x12ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "128 bit SIMD integer pack operations",
        .full_desc = "128 bit SIMD integer pack operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_128.PACKED_ARITH",
        .encoding =
            {
                .code = 0x12ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "128 bit SIMD integer arithmetic operations",
        .full_desc = "128 bit SIMD integer arithmetic operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_128.PACKED_LOGICAL",
        .encoding =
            {
                .code = 0x12ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "128 bit SIMD integer logical operations",
        .full_desc = "128 bit SIMD integer logical operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_128.PACKED_MPY",
        .encoding =
            {
                .code = 0x12ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "128 bit SIMD integer multiply operations",
        .full_desc = "128 bit SIMD integer multiply operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_128.PACKED_SHIFT",
        .encoding =
            {
                .code = 0x12ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "128 bit SIMD integer shift operations",
        .full_desc = "128 bit SIMD integer shift operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_128.SHUFFLE_MOVE",
        .encoding =
            {
                .code = 0x12ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "128 bit SIMD integer shuffle/move operations",
        .full_desc = "128 bit SIMD integer shuffle/move operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_128.UNPACK",
        .encoding =
            {
                .code = 0x12ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "128 bit SIMD integer unpack operations",
        .full_desc = "128 bit SIMD integer unpack operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_64.PACK",
        .encoding =
            {
                .code = 0xFDULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SIMD integer 64 bit pack operations",
        .full_desc = "SIMD integer 64 bit pack operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_64.PACKED_ARITH",
        .encoding =
            {
                .code = 0xFDULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SIMD integer 64 bit arithmetic operations",
        .full_desc = "SIMD integer 64 bit arithmetic operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_64.PACKED_LOGICAL",
        .encoding =
            {
                .code = 0xFDULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SIMD integer 64 bit logical operations",
        .full_desc = "SIMD integer 64 bit logical operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_64.PACKED_MPY",
        .encoding =
            {
                .code = 0xFDULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SIMD integer 64 bit packed multiply operations",
        .full_desc = "SIMD integer 64 bit packed multiply operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_64.PACKED_SHIFT",
        .encoding =
            {
                .code = 0xFDULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SIMD integer 64 bit shift operations",
        .full_desc = "SIMD integer 64 bit shift operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_64.SHUFFLE_MOVE",
        .encoding =
            {
                .code = 0xFDULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SIMD integer 64 bit shuffle/move operations",
        .full_desc = "SIMD integer 64 bit shuffle/move operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SIMD_INT_64.UNPACK",
        .encoding =
            {
                .code = 0xFDULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "SIMD integer 64 bit unpack operations",
        .full_desc = "SIMD integer 64 bit unpack operations",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SNOOP_RESPONSE.HIT",
        .encoding =
            {
                .code = 0xB8ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Thread responded HIT to snoop",
        .full_desc = "Thread responded HIT to snoop",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SNOOP_RESPONSE.HITE",
        .encoding =
            {
                .code = 0xB8ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Thread responded HITE to snoop",
        .full_desc = "Thread responded HITE to snoop",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SNOOP_RESPONSE.HITM",
        .encoding =
            {
                .code = 0xB8ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Thread responded HITM to snoop",
        .full_desc = "Thread responded HITM to snoop",
        .default_sampling_period = 0x186A0ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SQ_FULL_STALL_CYCLES",
        .encoding =
            {
                .code = 0xF6ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Super Queue full stall cycles",
        .full_desc = "Super Queue full stall cycles",
        .default_sampling_period = 0x1E8480ULL,
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
        .brief_desc = "Super Queue lock splits across a cache line",
        .full_desc = "Super Queue lock splits across a cache line",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SSEX_UOPS_RETIRED.PACKED_DOUBLE",
        .encoding =
            {
                .code = 0xC7ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "SIMD Packed-Double Uops retired (Precise Event)",
        .full_desc = "SIMD Packed-Double Uops retired (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SSEX_UOPS_RETIRED.PACKED_SINGLE",
        .encoding =
            {
                .code = 0xC7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "SIMD Packed-Single Uops retired (Precise Event)",
        .full_desc = "SIMD Packed-Single Uops retired (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SSEX_UOPS_RETIRED.SCALAR_DOUBLE",
        .encoding =
            {
                .code = 0xC7ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "SIMD Scalar-Double Uops retired (Precise Event)",
        .full_desc = "SIMD Scalar-Double Uops retired (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SSEX_UOPS_RETIRED.SCALAR_SINGLE",
        .encoding =
            {
                .code = 0xC7ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "SIMD Scalar-Single Uops retired (Precise Event)",
        .full_desc = "SIMD Scalar-Single Uops retired (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "SSEX_UOPS_RETIRED.VECTOR_INTEGER",
        .encoding =
            {
                .code = 0xC7ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "SIMD Vector Integer Uops retired (Precise Event)",
        .full_desc = "SIMD Vector Integer Uops retired (Precise Event)",
        .default_sampling_period = 0x30D40ULL,
    },
}};
static_assert(isStaticEventDefTableSorted(kFullOnlyEvents0));

constexpr std::array<StaticEventDef, 32> kFullOnlyEvents1{{
    {
        .pmu_type = PmuType::cpu,
        .id = "STORE_BLOCKS.AT_RET",
        .encoding =
            {
                .code = 0x6ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Loads delayed with at-Retirement block code",
        .full_desc = "Loads delayed with at-Retirement block code",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "STORE_BLOCKS.L1D_BLOCK",
        .encoding =
            {
                .code = 0x6ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cacheable loads delayed with L1D block code",
        .full_desc = "Cacheable loads delayed with L1D block code",
        .default_sampling_period = 0x30D40ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "TWO_UOP_INSTS_DECODED",
        .encoding =
            {
                .code = 0x19ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Two Uop instructions decoded",
        .full_desc = "Two Uop instructions decoded",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DECODED.ESP_FOLDING",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stack pointer instructions decoded",
        .full_desc = "Stack pointer instructions decoded",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DECODED.ESP_SYNC",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Stack pointer sync operations",
        .full_desc = "Stack pointer sync operations",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DECODED.MS_CYCLES_ACTIVE",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x2ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uops decoded by Microcode Sequencer",
        .full_desc = "Uops decoded by Microcode Sequencer",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_DECODED.STALL_CYCLES",
        .encoding =
            {
                .code = 0xD1ULL,
                .umask = 0x1ULL,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles no Uops are decoded",
        .full_desc = "Cycles no Uops are decoded",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE_ACTIVE_CYCLES",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x3FULL,
                .any = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles Uops executed on any port (core count)",
        .full_desc = "Cycles Uops executed on any port (core count)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE_ACTIVE_CYCLES_NO_PORT5",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x1FULL,
                .any = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles Uops executed on ports 0-4 (core count)",
        .full_desc = "Cycles Uops executed on ports 0-4 (core count)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE_STALL_COUNT",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x3FULL,
                .edge = true,
                .any = true,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uops executed on any port (core count)",
        .full_desc = "Uops executed on any port (core count)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE_STALL_COUNT_NO_PORT5",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x1FULL,
                .edge = true,
                .any = true,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uops executed on ports 0-4 (core count)",
        .full_desc = "Uops executed on ports 0-4 (core count)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE_STALL_CYCLES",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x3FULL,
                .any = true,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles no Uops issued on any port (core count)",
        .full_desc = "Cycles no Uops issued on any port (core count)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.CORE_STALL_CYCLES_NO_PORT5",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x1FULL,
                .any = true,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles no Uops issued on ports 0-4 (core count)",
        .full_desc = "Cycles no Uops issued on ports 0-4 (core count)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.PORT0",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uops executed on port 0",
        .full_desc = "Uops executed on port 0",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.PORT015",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uops issued on ports 0, 1 or 5",
        .full_desc = "Uops issued on ports 0, 1 or 5",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.PORT015_STALL_CYCLES",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x40ULL,
                .inv = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles no Uops issued on ports 0, 1 or 5",
        .full_desc = "Cycles no Uops issued on ports 0, 1 or 5",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.PORT1",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uops executed on port 1",
        .full_desc = "Uops executed on port 1",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.PORT234_CORE",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x80ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uops issued on ports 2, 3 or 4",
        .full_desc = "Uops issued on ports 2, 3 or 4",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.PORT2_CORE",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x4ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uops executed on port 2 (core count)",
        .full_desc = "Uops executed on port 2 (core count)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.PORT3_CORE",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x8ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uops executed on port 3 (core count)",
        .full_desc = "Uops executed on port 3 (core count)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.PORT4_CORE",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x10ULL,
                .any = true,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uops executed on port 4 (core count)",
        .full_desc = "Uops executed on port 4 (core count)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_EXECUTED.PORT5",
        .encoding =
            {
                .code = 0xB1ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uops executed on port 5",
        .full_desc = "Uops executed on port 5",
        .default_sampling_period = 0x1E8480ULL,
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
        .brief_desc = "Cycles no Uops were issued on any thread",
        .full_desc = "Cycles no Uops were issued on any thread",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_ISSUED.CYCLES_ALL_THREADS",
        .encoding =
            {
                .code = 0xEULL,
                .umask = 0x1ULL,
                .any = true,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles Uops were issued on either thread",
        .full_desc = "Cycles Uops were issued on either thread",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_ISSUED.FUSED",
        .encoding =
            {
                .code = 0xEULL,
                .umask = 0x2ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Fused Uops issued",
        .full_desc = "Fused Uops issued",
        .default_sampling_period = 0x1E8480ULL,
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
        .brief_desc = "Cycles no Uops were issued",
        .full_desc = "Cycles no Uops were issued",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_RETIRED.ACTIVE_CYCLES",
        .encoding =
            {
                .code = 0xC2ULL,
                .umask = 0x1ULL,
                .cmask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Cycles Uops are being retired",
        .full_desc = "Cycles Uops are being retired",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_RETIRED.ANY",
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
        .brief_desc = "Uops retired (Precise Event)",
        .full_desc = "Uops retired (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_RETIRED.MACRO_FUSED",
        .encoding =
            {
                .code = 0xC2ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Macro-fused Uops retired (Precise Event)",
        .full_desc = "Macro-fused Uops retired (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
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
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Cycles Uops are not retiring (Precise Event)",
        .full_desc = "Cycles Uops are not retiring (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOPS_RETIRED.TOTAL_CYCLES",
        .encoding =
            {
                .code = 0xC2ULL,
                .umask = 0x1ULL,
                .inv = true,
                .cmask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc =
            "Total cycles using precise uop retired event (Precise Event)",
        .full_desc =
            "Total cycles using precise uop retired event (Precise Event)",
        .default_sampling_period = 0x1E8480ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "UOP_UNFUSION",
        .encoding =
            {
                .code = 0xDBULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Uop unfusions due to FP exceptions",
        .full_desc = "Uop unfusions due to FP exceptions",
        .default_sampling_period = 0x1E8480ULL,
    },
}};
static_assert(isStaticEventDefTableSorted(kFullOnlyEvents1));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

} // namespace

void addEvents(PmuDeviceManager& pmu_manager) {
  pmu_manager.addStaticEventDefs(kAllowlistedEvents);
#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addStaticEventDefs(kFullOnlyEvents0);
  pmu_manager.addStaticEventDefs(kFullOnlyEvents1);
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace nehalemex_core
} // namespace facebook::hbt::perf_event::generated
