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
namespace goldmont_core {
namespace {

/*
  Events from goldmont_core.json (169 events).

  Supported SKUs:
      - Arch: x86, Model: GLM id: 92
      - Arch: x86, Model: GLM id: 95
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
                .pebs = 2,
            },
        .brief_desc = "Retired branch instructions (Precise event capable)",
        .full_desc =
            "Counts branch instructions retired for all branch types.  This is an architectural performance event.",
        .default_sampling_period = 0x30D43ULL,
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
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Retired mispredicted branch instructions (Precise event capable)",
        .full_desc =
            "Counts mispredicted branch instructions retired including all branch types.",
        .default_sampling_period = 0x30D43ULL,
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
        .brief_desc = "Reference cycles when core is not halted  (Fixed event)",
        .full_desc =
            "Counts the number of reference cycles that the core is not in a halt state. The core enters the halt state when it is running the HLT instruction.  In mobile systems the core frequency may change from time.  This event is not affected by core frequency changes but counts as if the core is running at the maximum frequency all the time.  This event uses fixed counter 2.  You cannot collect a PEBs record for this event.",
        .default_sampling_period = 0x1E8483ULL,
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
            "References per ICache line that are not available in the ICache (miss). This event counts differently than Intel processors based on Silvermont microarchitecture",
        .full_desc =
            "Counts requests to the Instruction Cache (ICache)  for one or more bytes in an ICache Line and that cache line is not in the ICache (miss).  The event strives to count on a cache line basis, so that multiple accesses which miss in a single cache line count as one ICACHE.MISS.  Specifically, the event counts when straight line code crosses the cache line boundary, or when a branch target is to a new line, and that cache line is not in the ICache. This event counts differently than Intel processors based on Silvermont microarchitecture.",
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
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 2,
            },
        .brief_desc =
            "Loads blocked due to store forward restriction (Precise event capable)",
        .full_desc =
            "Counts a load blocked from using a store forward because of an address/size mismatch, only one of the loads blocked from each store will be counted.",
        .default_sampling_period = 0x30D43ULL,
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
        .brief_desc = "L2 cache request misses",
        .full_desc =
            "Counts memory requests originating from the core that miss in the L2 cache.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
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
        .brief_desc =
            "Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
        .full_desc =
            "Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
        .default_sampling_period = 0x186A7ULL,
        .errata = "0",
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
        .brief_desc = "Uops issued to the back end per cycle",
        .full_desc =
            "Counts uops issued by the front end and allocated into the back end of the machine.  This event counts uops that retire as well as uops that were speculatively executed but didn't retire. The sort of speculative uops that might be counted includes, but is not limited to those uops issued in the shadow of a miss-predicted branch, those uops that are inserted during an assist (such as for a denormal floating point result), and (previously allocated) uops that might be canceled during a machine clear.",
        .default_sampling_period = 0x30D43ULL,
        .errata = "0",
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 161> kFullOnlyEvents{
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
            .brief_desc = "BACLEARs asserted for any branch type",
            .full_desc =
                "Counts the number of times a BACLEAR is signaled for any reason, including, but not limited to indirect branch/call,  Jcc (Jump on Conditional Code/Jump if Condition is Met) branch, unconditional branch/call, and returns.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "BACLEARs asserted for conditional branch",
            .full_desc =
                "Counts BACLEARS on Jcc (Jump on Conditional Code/Jump if Condition is Met) branches.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "BACLEARs asserted for return branch",
            .full_desc = "Counts BACLEARS on return instructions.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_INST_RETIRED.ALL_TAKEN_BRANCHES",
            .encoding =
                {
                    .code = 0xC4ULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .pebs = 2,
                },
            .brief_desc =
                "Retired taken branch instructions (Precise event capable)",
            .full_desc =
                "Counts the number of taken branch instructions retired.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired near call instructions (Precise event capable)",
            .full_desc = "Counts near CALL branch instructions retired.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired far branch instructions (Precise event capable)",
            .full_desc =
                "Counts far branch instructions retired.  This includes far jump, far call and return, and Interrupt call and return.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired near indirect call instructions (Precise event capable)",
            .full_desc =
                "Counts near indirect CALL branch instructions retired.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired conditional branch instructions (Precise event capable)",
            .full_desc =
                "Counts retired Jcc (Jump on Conditional Code/Jump if Condition is Met) branch instructions retired, including both when the branch was taken and when it was not taken.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired instructions of near indirect Jmp or call (Precise event capable)",
            .full_desc =
                "Counts near indirect call or near indirect jmp branch instructions retired.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired near relative call instructions (Precise event capable)",
            .full_desc =
                "Counts near relative CALL branch instructions retired.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired near return instructions (Precise event capable)",
            .full_desc = "Counts near return branch instructions retired.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired conditional branch instructions that were taken (Precise event capable)",
            .full_desc =
                "Counts Jcc (Jump on Conditional Code/Jump if Condition is Met) branch instructions retired that were taken and does not count when the Jcc branch instruction were not taken.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired mispredicted near indirect call instructions (Precise event capable)",
            .full_desc =
                "Counts mispredicted near indirect CALL branch instructions retired, where the target address taken was not what the processor predicted.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired mispredicted conditional branch instructions (Precise event capable)",
            .full_desc =
                "Counts mispredicted retired Jcc (Jump on Conditional Code/Jump if Condition is Met) branch instructions retired, including both when the branch was supposed to be taken and when it was not supposed to be taken (but the processor predicted the opposite condition).",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired mispredicted instructions of near indirect Jmp or near indirect call. (Precise event capable)",
            .full_desc =
                "Counts mispredicted branch instructions retired that were near indirect call or near indirect jmp, where the target address taken was not what the processor predicted.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired mispredicted near return instructions (Precise event capable)",
            .full_desc =
                "Counts mispredicted near RET branch instructions retired, where the return address taken was not what the processor predicted.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Retired mispredicted conditional branch instructions that were taken (Precise event capable)",
            .full_desc =
                "Counts mispredicted retired Jcc (Jump on Conditional Code/Jump if Condition is Met) branch instructions retired that were supposed to be taken but the processor predicted that it would not be taken.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "Requests rejected by the L2Q",
            .full_desc =
                "Counts the number of demand and L1 prefetcher requests rejected by the L2Q due to a full or nearly full condition which likely indicates back pressure from L2Q. It also counts requests that would have gone directly to the XQ, but are rejected due to a full or nearly full condition, indicating back pressure from the IDI link. The L2Q may also reject transactions from a core to ensure fairness between cores, or to delay a core's dirty eviction when the address conflicts with incoming external snoops.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "Core cycles when core is not halted  (Fixed event)",
            .full_desc =
                "Counts the number of core cycles while the core is not in a halt state.  The core enters the halt state when it is running the HLT instruction. In mobile systems the core frequency may change from time to time. For this reason this event may have a changing ratio with regards to time.  This event uses fixed counter 1.  You cannot collect a PEBs record for this event.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
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
            .brief_desc = "Core cycles when core is not halted",
            .full_desc =
                "Core cycles when core is not halted.  This event uses a (_P)rogrammable general purpose performance counter.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
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
            .brief_desc = "Reference cycles when core is not halted",
            .full_desc =
                "Reference cycles when core is not halted.  This event uses a programmable general purpose performance counter.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "CYCLES_DIV_BUSY.ALL",
            .encoding =
                {
                    .code = 0xCDULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles a divider is busy",
            .full_desc = "Counts core cycles if either divide unit is busy.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
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
            .brief_desc = "Cycles the FP divide unit is busy",
            .full_desc =
                "Counts core cycles the floating point divide unit is busy.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "Cycles the integer divide unit is busy",
            .full_desc = "Counts core cycles the integer divide unit is busy.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                "Decode restrictions due to predicting wrong instruction length",
            .full_desc =
                "Counts the number of times the prediction (from the predecode cache) for instruction length is incorrect.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "L1 Cache evictions for dirty data",
            .full_desc =
                "Counts when a modified (dirty) cache line is evicted from the data L1 cache and needs to be written back to memory.  No count will occur if the evicted line is clean, and hence does not require a writeback.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FETCH_STALL.ALL",
            .encoding =
                {
                    .code = 0x86ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles code-fetch stalled due to any reason.",
            .full_desc =
                "Counts cycles that fetch is stalled due to any reason. That is, the decoder queue is able to accept bytes, but the fetch unit is unable to provide bytes.  This will include cycles due to an ITLB miss, ICache miss and other events. ",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FETCH_STALL.ICACHE_FILL_PENDING_CYCLES",
            .encoding =
                {
                    .code = 0x86ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles code-fetch stalled due to an outstanding ICache miss.",
            .full_desc =
                "Counts cycles that fetch is stalled due to an outstanding ICache miss. That is, the decoder queue is able to accept bytes, but the fetch unit is unable to provide bytes due to an ICache miss.  Note: this event is not the same as the total number of cycles spent retrieving instruction cache lines from the memory hierarchy.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FETCH_STALL.ITLB_FILL_PENDING_CYCLES",
            .encoding =
                {
                    .code = 0x86ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles code-fetch stalled due to an outstanding ITLB miss.",
            .full_desc =
                "Counts cycles that fetch is stalled due to an outstanding ITLB miss. That is, the decoder queue is able to accept bytes, but the fetch unit is unable to provide bytes due to an ITLB miss.  Note: this event is not the same as page walk cycles to retrieve an instruction translation.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "Cycles hardware interrupts are masked",
            .full_desc =
                "Counts the number of core cycles during which interrupts are masked (disabled). Increments by 1 each core cycle that EFLAGS.IF is 0, regardless of whether interrupts are pending or not.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "Cycles pending interrupts are masked",
            .full_desc =
                "Counts core cycles during which there are pending interrupts, but interrupts are masked (EFLAGS.IF = 0).",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "Hardware interrupts received",
            .full_desc =
                "Counts hardware interrupts received by the processor.",
            .default_sampling_period = 0xCBULL,
            .errata = "0",
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
                "References per ICache line. This event counts differently than Intel processors based on Silvermont microarchitecture",
            .full_desc =
                "Counts requests to the Instruction Cache (ICache) for one or more bytes in an ICache Line.  The event strives to count on a cache line basis, so that multiple fetches to a single cache line count as one ICACHE.ACCESS.  Specifically, the event counts when accesses from straight line code crosses the cache line boundary, or when a branch target is to a new line.\nThis event counts differently than Intel processors based on Silvermont microarchitecture.",
            .default_sampling_period = 0x30D43ULL,
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
                "References per ICache line that are available in the ICache (hit). This event counts differently than Intel processors based on Silvermont microarchitecture",
            .full_desc =
                "Counts requests to the Instruction Cache (ICache) for one or more bytes in an ICache Line and that cache line is in the ICache (hit).  The event strives to count on a cache line basis, so that multiple accesses which hit in a single cache line count as one ICACHE.HIT.  Specifically, the event counts when straight line code crosses the cache line boundary, or when a branch target is to a new line, and that cache line is in the ICache. This event counts differently than Intel processors based on Silvermont microarchitecture.",
            .default_sampling_period = 0x30D43ULL,
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
            .brief_desc = "Instructions retired (Fixed event)",
            .full_desc =
                "Counts the number of instructions that retire execution. For instructions that consist of multiple uops, this event counts the retirement of the last uop of the instruction. The counter continues counting during hardware interrupts, traps, and inside interrupt handlers.  This event uses fixed counter 0.  You cannot collect a PEBs record for this event.",
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
            .features =
                StaticEventDef::IntelFeatures{
                    .pebs = 2,
                },
            .brief_desc = "Instructions retired (Precise event capable)",
            .full_desc =
                "Counts the number of instructions that retire execution. For instructions that consist of multiple uops, this event counts the retirement of the last uop of the instruction. The event continues counting during hardware interrupts, traps, and inside interrupt handlers.  This is an architectural performance event.  This event uses a (_P)rogrammable general purpose performance counter. *This event is Precise Event capable:  The EventingRIP field in the PEBS record is precise to the address of the instruction which caused the event.  Note: Because PEBS records can be collected only on IA32_PMC0, only one event can use the PEBS facility at a time.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ISSUE_SLOTS_NOT_CONSUMED.ANY",
            .encoding =
                {
                    .code = 0xCAULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Unfilled issue slots per cycle",
            .full_desc =
                "Counts the number of issue slots per core cycle that were not consumed by the backend due to either a full resource  in the backend (RESOURCE_FULL) or due to the processor recovering from some event (RECOVERY).",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ISSUE_SLOTS_NOT_CONSUMED.RECOVERY",
            .encoding =
                {
                    .code = 0xCAULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Unfilled issue slots per cycle to recover",
            .full_desc =
                "Counts the number of issue slots per core cycle that were not consumed by the backend because allocation is stalled waiting for a mispredicted jump to retire or other branch-like conditions (e.g. the event is relevant during certain microcode flows).   Counts all issue slots blocked while within this window including slots where uops were not available in the Instruction Queue.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ISSUE_SLOTS_NOT_CONSUMED.RESOURCE_FULL",
            .encoding =
                {
                    .code = 0xCAULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Unfilled issue slots per cycle because of a full resource in the backend",
            .full_desc =
                "Counts the number of issue slots per core cycle that were not consumed because of a full resource in the backend.  Including but not limited to resources such as the Re-order Buffer (ROB), reservation stations (RS), load/store buffers, physical registers, or any other needed machine resource that is currently unavailable.   Note that uops must be available for consumption in order for this event to fire.  If a uop is not available (Instruction Queue is empty), this event will not count.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ITLB.MISS",
            .encoding =
                {
                    .code = 0x81ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "ITLB misses",
            .full_desc =
                "Counts the number of times the machine was unable to find a translation in the Instruction Translation Lookaside Buffer (ITLB) for a linear address of an instruction fetch.  It counts when new translation are filled into the ITLB.  The event is speculative in nature, but will not count translations (page walks) that are begun and not finished, or translations that are finished but not filled into the ITLB.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L2_REJECT_XQ.ALL",
            .encoding =
                {
                    .code = 0x30ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Requests rejected by the XQ",
            .full_desc =
                "Counts the number of demand and prefetch transactions that the L2 XQ rejects due to a full or near full condition which likely indicates back pressure from the intra-die interconnect (IDI) fabric. The XQ may reject transactions from the L2Q (non-cacheable requests), L2 misses and L2 write-back victims.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                StaticEventDef::IntelFeatures{
                    .pebs = 2,
                },
            .brief_desc = "Loads blocked because address has 4k partial address false dependence (Precise event capable)",
            .full_desc =
                "Counts loads that block because their address modulo 4K matches a pending store.",
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
            .features =
                StaticEventDef::IntelFeatures{
                    .pebs = 2,
                },
            .brief_desc = "Loads blocked (Precise event capable)",
            .full_desc =
                "Counts anytime a load that retires is blocked for any reason.",
            .default_sampling_period = 0x30D43ULL,
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
            .features =
                StaticEventDef::IntelFeatures{
                    .pebs = 2,
                },
            .brief_desc =
                "Loads blocked due to store data not ready (Precise event capable)",
            .full_desc =
                "Counts a load blocked from using a store forward, but did not occur because the store data was not available at the right time.  The forward might occur subsequently when the data is available.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "LD_BLOCKS.UTLB_MISS",
            .encoding =
                {
                    .code = 0x3ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .pebs = 2,
                },
            .brief_desc =
                "Loads blocked because address in not in the UTLB (Precise event capable)",
            .full_desc =
                "Counts loads blocked because they are unable to find their physical address in the micro TLB (UTLB).",
            .default_sampling_period = 0x30D43ULL,
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
            .brief_desc = "L2 cache requests",
            .full_desc =
                "Counts memory requests originating from the core that reference a cache line in the L2 cache.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MACHINE_CLEARS.ALL",
            .encoding =
                {
                    .code = 0xC3ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "All machine clears",
            .full_desc = "Counts machine clears for any reason.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "Machine clears due to memory disambiguation",
            .full_desc =
                "Counts machine clears due to memory disambiguation.  Memory disambiguation happens when a load which has been issued conflicts with a previous unretired store in the pipeline whose address was not known at issue time, but is later resolved to be the same as the load address.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "Machine clears due to FP assists",
            .full_desc =
                "Counts machine clears due to floating point (FP) operations needing assists.  For instance, if the result was a floating point denormal, the hardware clears the pipeline and reissues uops to produce the correct IEEE compliant denormal result.",
            .default_sampling_period = 0x30D43ULL,
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
            .brief_desc = "Machine clears due to memory ordering issue",
            .full_desc =
                "Counts machine clears due to memory ordering issues.  This occurs when a snoop request happens and the machine is uncertain if memory ordering will be preserved as another core is in the process of modifying the data.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "Self-Modifying Code detected",
            .full_desc =
                "Counts the number of times that the processor detects that a program is writing to a code section and has to perform a machine clear because of that modification.  Self-modifying code (SMC) causes a severe penalty in all Intel\302\256 architecture processors.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                StaticEventDef::IntelFeatures{
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc =
                "Loads retired that came from DRAM (Precise event capable)",
            .full_desc =
                "Counts memory load uops retired where the data is retrieved from DRAM.  Event is counted at retirement, so the speculative loads are ignored.  A memory load can hit (or miss) the L1 cache, hit (or miss) the L2 cache, hit DRAM, hit in the WCB or receive a HITM response.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                StaticEventDef::IntelFeatures{
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc =
                "Memory uop retired where cross core or cross module HITM occurred (Precise event capable)",
            .full_desc =
                "Counts load uops retired where the cache line containing the data was in the modified state of another core or modules cache (HITM).  More specifically, this means that when the load address was checked by other caching agents (typically another processor) in the system, one of those caching agents indicated that they had a dirty copy of the data.  Loads that obtain a HITM response incur greater latency than most is typical for a load.  In addition, since HITM indicates that some other processor had this data in its cache, it implies that the data was shared between processors, or potentially was a lock or semaphore value.  This event is useful for locating sharing, false sharing, and contended locks.",
            .default_sampling_period = 0x30D43ULL,
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
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc =
                "Load uops retired that hit L1 data cache (Precise event capable)",
            .full_desc = "Counts load uops retired that hit the L1 data cache.",
            .default_sampling_period = 0x30D43ULL,
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
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc =
                "Load uops retired that missed L1 data cache (Precise event capable)",
            .full_desc =
                "Counts load uops retired that miss the L1 data cache.",
            .default_sampling_period = 0x30D43ULL,
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
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc =
                "Load uops retired that hit L2 (Precise event capable)",
            .full_desc = "Counts load uops retired that hit in the L2 cache.",
            .default_sampling_period = 0x30D43ULL,
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
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc =
                "Load uops retired that missed L2 (Precise event capable)",
            .full_desc = "Counts load uops retired that miss in the L2 cache.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEM_LOAD_UOPS_RETIRED.WCB_HIT",
            .encoding =
                {
                    .code = 0xD1ULL,
                    .umask = 0x40ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc = "Loads retired that hit WCB (Precise event capable)",
            .full_desc =
                "Counts memory load uops retired where the data is retrieved from the WCB (or fill buffer), indicating that the load found its data while that data was in the process of being brought into the L1 cache.  Typically a load will receive this indication when some other load or prefetch missed the L1 cache and was in the process of retrieving the cache line containing the data, but that process had not yet finished (and written the data back to the cache). For example, consider load X and Y, both referencing the same cache line that is not in the L1 cache.  If load X misses cache first, it obtains and WCB (or fill buffer) and begins the process of requesting the data.  When load Y requests the data, it will either hit the WCB, or the L1 cache, depending on exactly what time the request to Y occurs.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                StaticEventDef::IntelFeatures{
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc = "Memory uops retired (Precise event capable)",
            .full_desc =
                "Counts the number of memory uops retired that is either a loads or a store or both.",
            .default_sampling_period = 0x30D43ULL,
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
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc = "Load uops retired (Precise event capable)",
            .full_desc = "Counts the number of load uops retired.",
            .default_sampling_period = 0x30D43ULL,
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
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc = "Store uops retired (Precise event capable)",
            .full_desc = "Counts the number of store uops retired.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                StaticEventDef::IntelFeatures{
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc =
                "Memory uops retired that missed the DTLB (Precise event capable)",
            .full_desc =
                "Counts uops retired that had a DTLB miss on load, store or either.  Note that when two distinct memory operations to the same page miss the DTLB, only one of them will be recorded as a DTLB miss.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Load uops retired that missed the DTLB (Precise event capable)",
            .full_desc = "Counts load uops retired that caused a DTLB miss.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Store uops retired that missed the DTLB (Precise event capable)",
            .full_desc = "Counts store uops retired that caused a DTLB miss.",
            .default_sampling_period = 0x30D43ULL,
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
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc = "Locked load uops retired (Precise event capable)",
            .full_desc =
                "Counts locked memory uops retired.  This includes regular locks and bus locks. (To specifically count bus locks only, see the Offcore response event.)  A locked access is one with a lock prefix, or an exchange to memory.  See the SDM for a complete description of which memory load accesses are locks.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Memory uops retired that split a cache-line (Precise event capable)",
            .full_desc =
                "Counts memory uops retired where the data requested spans a 64 byte cache line boundary.",
            .default_sampling_period = 0x30D43ULL,
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
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc =
                "Load uops retired that split a cache-line (Precise event capable)",
            .full_desc =
                "Counts load uops retired where the data requested spans a 64 byte cache line boundary.",
            .default_sampling_period = 0x30D43ULL,
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
                    .data_la = true,
                    .pebs = 2,
                },
            .brief_desc =
                "Stores uops retired that split a cache-line (Precise event capable)",
            .full_desc =
                "Counts store uops retired where the data requested spans a 64 byte cache line boundary.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc = "Load uops that split a page (Precise event capable)",
            .full_desc =
                "Counts when a memory load of a uop spans a page boundary (a split) is retired.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Store uops that split a page (Precise event capable)",
            .full_desc =
                "Counts when a memory store of a uop spans a page boundary (a split) is retired.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "MS decode starts",
            .full_desc =
                "Counts the number of times the Microcode Sequencer (MS) starts a flow of uops from the MSROM. It does not count every time a uop is read from the MSROM.  The most common case that this counts is when a micro-coded instruction is encountered by the front end of the machine.  Other cases include when an instruction encounters a fault, trap, or microcode assist of any sort that initiates a flow of uops.  The event will count MS startups for uops that are speculative, and subsequently cleared by branch mispredict or a machine clear.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x43091ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data reads (demand & prefetch) that hit the L2 cache.",
            .full_desc =
                "Counts data reads (demand & prefetch) that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600003091ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data reads (demand & prefetch) that miss the L2 cache.",
            .full_desc =
                "Counts data reads (demand & prefetch) that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000003091ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data reads (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts data reads (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_DATA_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400003091ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data reads (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts data reads (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.ANY_DATA_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200003091ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data reads (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts data reads (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_PF_DATA_RD.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x43010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data reads generated by L1 or L2 prefetchers that hit the L2 cache.",
            .full_desc =
                "Counts data reads generated by L1 or L2 prefetchers that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_PF_DATA_RD.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600003010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache.",
            .full_desc =
                "Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_PF_DATA_RD.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000003010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.ANY_PF_DATA_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400003010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts data reads generated by L1 or L2 prefetchers that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.ANY_PF_DATA_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200003010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data reads generated by L1 or L2 prefetchers that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts data reads generated by L1 or L2 prefetchers that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_READ.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x432B7ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that hit the L2 cache.",
            .full_desc =
                "Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_READ.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x36000032B7ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache.",
            .full_desc =
                "Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_READ.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10000032B7ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_READ.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4000032B7ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.ANY_READ.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2000032B7ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts data read, code read, and read for ownership (RFO) requests (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
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
                "Counts requests to the uncore subsystem that have any transaction responses from the uncore subsystem.",
            .full_desc =
                "Counts requests to the uncore subsystem that have any transaction responses from the uncore subsystem. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x48000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts requests to the uncore subsystem that hit the L2 cache.",
            .full_desc =
                "Counts requests to the uncore subsystem that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000008000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts requests to the uncore subsystem that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts requests to the uncore subsystem that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_REQUEST.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400008000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts requests to the uncore subsystem that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts requests to the uncore subsystem that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.ANY_REQUEST.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200008000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts requests to the uncore subsystem that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts requests to the uncore subsystem that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_RFO.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x40022ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts reads for ownership (RFO) requests (demand & prefetch) that hit the L2 cache.",
            .full_desc =
                "Counts reads for ownership (RFO) requests (demand & prefetch) that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_RFO.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600000022ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache.",
            .full_desc =
                "Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_RFO.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000000022ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.ANY_RFO.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400000022ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts reads for ownership (RFO) requests (demand & prefetch) that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.ANY_RFO.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200000022ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts reads for ownership (RFO) requests (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts reads for ownership (RFO) requests (demand & prefetch) that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
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
                "Counts bus lock and split lock requests that have any transaction responses from the uncore subsystem.",
            .full_desc =
                "Counts bus lock and split lock requests that have any transaction responses from the uncore subsystem. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.COREWB.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x40008ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts the number of writeback transactions caused by L1 or L2 cache evictions that hit the L2 cache.",
            .full_desc =
                "Counts the number of writeback transactions caused by L1 or L2 cache evictions that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.COREWB.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600000008ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache.",
            .full_desc =
                "Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.COREWB.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000000008ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.COREWB.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400000008ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts the number of writeback transactions caused by L1 or L2 cache evictions that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.COREWB.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200000008ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts the number of writeback transactions caused by L1 or L2 cache evictions that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts the number of writeback transactions caused by L1 or L2 cache evictions that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x40004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that hit the L2 cache.",
            .full_desc =
                "Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600000004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that miss the L2 cache.",
            .full_desc =
                "Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400000004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.DEMAND_CODE_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200000004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
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
                "Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that are outstanding, per cycle, from the time of the L2 miss to when any response is received.",
            .full_desc =
                "Counts demand instruction cacheline and I-side prefetch requests that miss the instruction cache that are outstanding, per cycle, from the time of the L2 miss to when any response is received. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x40001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand cacheable data reads of full cache lines that hit the L2 cache.",
            .full_desc =
                "Counts demand cacheable data reads of full cache lines that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand cacheable data reads of full cache lines that miss the L2 cache.",
            .full_desc =
                "Counts demand cacheable data reads of full cache lines that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand cacheable data reads of full cache lines that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts demand cacheable data reads of full cache lines that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand cacheable data reads of full cache lines that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts demand cacheable data reads of full cache lines that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.DEMAND_DATA_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand cacheable data reads of full cache lines that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts demand cacheable data reads of full cache lines that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
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
                "Counts demand cacheable data reads of full cache lines that are outstanding, per cycle, from the time of the L2 miss to when any response is received.",
            .full_desc =
                "Counts demand cacheable data reads of full cache lines that are outstanding, per cycle, from the time of the L2 miss to when any response is received. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x40002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that hit the L2 cache.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600000002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000000002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.DEMAND_RFO.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400000002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.DEMAND_RFO.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200000002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
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
            .brief_desc = "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that are outstanding, per cycle, from the time of the L2 miss to when any response is received.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests generated by a write to full data cache line that are outstanding, per cycle, from the time of the L2 miss to when any response is received. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.FULL_STREAMING_STORES.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x40800ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that hit the L2 cache.",
            .full_desc =
                "Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.FULL_STREAMING_STORES.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600000800ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache.",
            .full_desc =
                "Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.FULL_STREAMING_STORES.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000000800ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.FULL_STREAMING_STORES.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400000800ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.FULL_STREAMING_STORES.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200000800ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts full cache line data writes to uncacheable write combining (USWC) memory region and full cache-line non-temporal writes that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PARTIAL_READS.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data partial reads, including data in uncacheable (UC) or uncacheable write combining (USWC) memory types that miss the L2 cache.",
            .full_desc =
                "Counts demand data partial reads, including data in uncacheable (UC) or uncacheable write combining (USWC) memory types that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x44000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that hit the L2 cache.",
            .full_desc =
                "Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600004000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache.",
            .full_desc =
                "Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000004000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400004000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PARTIAL_STREAMING_STORES.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200004000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts partial cache line data writes to uncacheable write combining (USWC) memory region  that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PARTIAL_WRITES.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts the number of demand write requests (RFO) generated by a write to partial data cache line, including the writes to uncacheable (UC) and write through (WT), and write protected (WP) types of memory that miss the L2 cache.",
            .full_desc =
                "Counts the number of demand write requests (RFO) generated by a write to partial data cache line, including the writes to uncacheable (UC) and write through (WT), and write protected (WP) types of memory that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x42000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cache line reads generated by hardware L1 data cache prefetcher that hit the L2 cache.",
            .full_desc = "Counts data cache line reads generated by hardware L1 data cache prefetcher that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600002000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache.",
            .full_desc =
                "Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000002000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400002000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts data cache line reads generated by hardware L1 data cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L1_DATA_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200002000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cache line reads generated by hardware L1 data cache prefetcher that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts data cache line reads generated by hardware L1 data cache prefetcher that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x40010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cacheline reads generated by hardware L2 cache prefetcher that hit the L2 cache.",
            .full_desc =
                "Counts data cacheline reads generated by hardware L2 cache prefetcher that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600000010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache.",
            .full_desc =
                "Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000000010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L2_DATA_RD.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400000010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts data cacheline reads generated by hardware L2 cache prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L2_DATA_RD.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200000010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cacheline reads generated by hardware L2 cache prefetcher that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts data cacheline reads generated by hardware L2 cache prefetcher that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x40020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts reads for ownership (RFO) requests generated by L2 prefetcher that hit the L2 cache.",
            .full_desc =
                "Counts reads for ownership (RFO) requests generated by L2 prefetcher that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache.",
            .full_desc =
                "Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts reads for ownership (RFO) requests generated by L2 prefetcher that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L2_RFO.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts reads for ownership (RFO) requests generated by L2 prefetcher that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts reads for ownership (RFO) requests generated by L2 prefetcher that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.STREAMING_STORES.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x44800ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts any data writes to uncacheable write combining (USWC) memory region  that hit the L2 cache.",
            .full_desc =
                "Counts any data writes to uncacheable write combining (USWC) memory region  that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.STREAMING_STORES.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600004800ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts any data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache.",
            .full_desc =
                "Counts any data writes to uncacheable write combining (USWC) memory region  that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.SW_PREFETCH.L2_HIT",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x41000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cache lines requests by software prefetch instructions that hit the L2 cache.",
            .full_desc =
                "Counts data cache lines requests by software prefetch instructions that hit the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.SW_PREFETCH.L2_MISS.ANY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3600001000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cache lines requests by software prefetch instructions that miss the L2 cache.",
            .full_desc =
                "Counts data cache lines requests by software prefetch instructions that miss the L2 cache. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.SW_PREFETCH.L2_MISS.HITM_OTHER_CORE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000001000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cache lines requests by software prefetch instructions that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required.",
            .full_desc =
                "Counts data cache lines requests by software prefetch instructions that miss the L2 cache with a snoop hit in the other processor module, data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.SW_PREFETCH.L2_MISS.HIT_OTHER_CORE_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400001000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cache lines requests by software prefetch instructions that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required.",
            .full_desc =
                "Counts data cache lines requests by software prefetch instructions that miss the L2 cache with a snoop hit in the other processor module, no data forwarding is required. Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.SW_PREFETCH.L2_MISS.SNOOP_MISS_OR_NO_SNOOP_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200001000ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data cache lines requests by software prefetch instructions that true miss for the L2 cache with a snoop miss in the other processor module. ",
            .full_desc =
                "Counts data cache lines requests by software prefetch instructions that true miss for the L2 cache with a snoop miss in the other processor module.  Requires MSR_OFFCORE_RESP[0,1] to specify request type and response. (duplicated for both MSRs)",
            .default_sampling_period = 0x186A7ULL,
            .errata = "0",
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
            .brief_desc = "Duration of page-walks in cycles",
            .full_desc =
                "Counts every core cycle a page-walk is in progress due to either a data memory operation or an instruction fetch.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "Duration of D-side page-walks in cycles",
            .full_desc =
                "Counts every core cycle when a Data-side (walks due to a data operation) page walk is in progress.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
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
            .brief_desc = "Duration of I-side pagewalks in cycles",
            .full_desc =
                "Counts every core cycle when a Instruction-side (walks due to an instruction fetch) page walk is in progress.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_NOT_DELIVERED.ANY",
            .encoding =
                {
                    .code = 0x9CULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Uops requested but not-delivered to the back-end per cycle",
            .full_desc =
                "This event used to measure front-end inefficiencies. I.e. when front-end of the machine is not delivering uops to the back-end and the back-end has is not stalled. This event can be used to identify if the machine is truly front-end bound.  When this event occurs, it is an indication that the front-end of the machine is operating at less than its theoretical peak performance. Background: We can think of the processor pipeline as being divided into 2 broader parts: Front-end and Back-end. Front-end is responsible for fetching the instruction, decoding into uops in machine understandable format and putting them into a uop queue to be consumed by back end. The back-end then takes these uops, allocates the required resources.  When all resources are ready, uops are executed. If the back-end is not ready to accept uops from the front-end, then we do not want to count these as front-end bottlenecks.  However, whenever we have bottlenecks in the back-end, we will have allocation unit stalls and eventually forcing the front-end to wait until the back-end is ready to receive more uops. This event counts only when back-end is requesting more uops and front-end is not able to provide them. When 3 uops are requested and no uops are delivered, the event counts 3. When 3 are requested, and only 1 is delivered, the event counts 2. When only 2 are delivered, the event counts 1. Alternatively stated, the event will not count if 3 uops are delivered, or if the back end is stalled and not requesting any uops at all.  Counts indicate missed opportunities for the front-end to deliver a uop to the back end. Some examples of conditions that cause front-end efficiencies are: ICache misses, ITLB misses, and decoder restrictions that limit the front-end bandwidth. Known Issues: Some uops require multiple allocation slots.  These uops will not be charged as a front end 'not delivered' opportunity, and will be regarded as a back end problem. For example, the INC instruction has one uop that requires 2 issue slots.  A stream of INC instructions will not count as UOPS_NOT_DELIVERED, even though only one instruction can be issued per clock.  The low uop issue rate for a stream of INC instructions is considered to be a back end issue.",
            .default_sampling_period = 0x30D43ULL,
            .errata = "0",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_RETIRED.ANY",
            .encoding =
                {
                    .code = 0xC2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .pebs = 2,
                },
            .brief_desc = "Uops retired (Precise event capable)",
            .full_desc = "Counts uops which retired.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Floating point divide uops retired. (Precise Event Capable)",
            .full_desc =
                "Counts the number of floating point divide uops retired.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc =
                "Integer divide uops retired. (Precise Event Capable)",
            .full_desc = "Counts the number of integer divide uops retired.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "0",
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
                    .pebs = 2,
                },
            .brief_desc = "MS uops retired (Precise event capable)",
            .full_desc =
                "Counts uops retired that are from the complex flows issued by the micro-sequencer (MS).  Counts both the uops from a micro-coded instruction, and the uops that might be generated from a micro-coded assist.",
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

} // namespace goldmont_core
} // namespace facebook::hbt::perf_event::generated
