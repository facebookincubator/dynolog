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
namespace skylakex_core {
namespace {

/*
  Events from skylakex_core.json (470 events).

  Supported SKUs:
      - Arch: x86, Model: SKX id: 85 Steps: ['0', '1', '2', '3', '4']
*/
constexpr std::
    array<StaticEventDef, 37>
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
                    .full_desc =
                        "Counts all (macro) branch instructions retired.",
                    .default_sampling_period = 0x61A89ULL,
                    .errata = "SKL091",
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
                    .full_desc =
                        "This event counts taken branch instructions retired.",
                    .default_sampling_period = 0x61A89ULL,
                    .errata = "SKL091",
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
                        "Counts all the retired branch instructions that were mispredicted by the processor. A branch misprediction occurs when the processor incorrectly predicts the destination of the branch.  When the misprediction is discovered at execution, all the instructions executed in the wrong (speculative) path must be discarded, and the processor must start fetching from the correct path.",
                    .default_sampling_period = 0x61A89ULL,
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
                        "Counts the number of reference cycles when the core is not in a halt state. The core enters the halt state when it is running the HLT instruction or the MWAIT instruction. This event is not affected by core frequency changes (for example, P states, TM2 transitions) but has the same incrementing frequency as the time stamp counter. This event can approximate elapsed time while the core was not in a halt state. This event has a constant ratio with the CPU_CLK_UNHALTED.REF_XCLK event. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. Note: On all current platforms this event stops counting during 'throttling (TM)' states duty off periods the processor is 'halted'.  The counter update is done at a lower clock rate then the core clock the overflow status bit for this counter may appear 'sticky'.  After the counter has overflowed and software clears the overflow status bit and resets the counter to less than MAX. The reset value to the counter is not clocked immediately so the overflow status bit will flip 'high (1)' and generate another PMI (if enabled) after which the reset value gets clocked into the counter. Therefore, software will get the interrupt, read the overflow status bit '1 for bit 34 while the counter value is less than MAX. Software should ignore this case.",
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
                        "Core cycles when the thread is not in halt state",
                    .full_desc =
                        "Counts the number of core cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. This event is a component in many key event ratios. The core frequency may change from time to time due to transitions associated with Enhanced Intel SpeedStep Technology or TM2. For this reason this event may have a changing ratio with regards to time. When the core frequency is constant, this event can approximate elapsed time while the core was not in the halt state. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events.",
                    .default_sampling_period = 0x1E8483ULL,
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
                        "Thread cycles when thread is not in halt state",
                    .full_desc =
                        "This is an architectural event that counts the number of thread cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. The core frequency may change from time to time due to power or thermal throttling. For this reason, this event may have a changing ratio with regards to wall clock time.",
                    .default_sampling_period = 0x1E8483ULL,
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
                        "Execution stalls while L2 cache miss demand load is outstanding.",
                    .full_desc =
                        "Execution stalls while L2 cache miss demand load is outstanding.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "CYCLE_ACTIVITY.STALLS_MEM_ANY",
                    .encoding =
                        {
                            .code = 0xA3ULL,
                            .umask = 0x14ULL,
                            .cmask = 0x14ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Execution stalls while memory subsystem has an outstanding load.",
                    .full_desc =
                        "Execution stalls while memory subsystem has an outstanding load.",
                    .default_sampling_period = 0x1E8483ULL,
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
                        "Load miss in all TLB levels causes a page walk that completes. (All page sizes)",
                    .full_desc =
                        "Counts completed page walks  (all page sizes) caused by demand data loads. This implies it missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
                    .default_sampling_period = 0x186A3ULL,
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
                        "Store misses in all TLB levels causes a page walk that completes. (All page sizes)",
                    .full_desc =
                        "Counts completed page walks  (all page sizes) caused by demand data stores. This implies it missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "FP_ARITH_INST_RETIRED.128B_PACKED_DOUBLE",
                    .encoding =
                        {
                            .code = 0xC7ULL,
                            .umask = 0x4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts once for most SIMD 128-bit packed computational double precision floating-point instructions retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.",
                    .full_desc =
                        "Counts once for most SIMD 128-bit packed computational double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "FP_ARITH_INST_RETIRED.128B_PACKED_SINGLE",
                    .encoding =
                        {
                            .code = 0xC7ULL,
                            .umask = 0x8ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts once for most SIMD 128-bit packed computational single precision floating-point instruction retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.",
                    .full_desc =
                        "Counts once for most SIMD 128-bit packed computational single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "FP_ARITH_INST_RETIRED.256B_PACKED_DOUBLE",
                    .encoding =
                        {
                            .code = 0xC7ULL,
                            .umask = 0x10ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts once for most SIMD 256-bit packed double computational precision floating-point instructions retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.",
                    .full_desc =
                        "Counts once for most SIMD 256-bit packed double computational precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "FP_ARITH_INST_RETIRED.256B_PACKED_SINGLE",
                    .encoding =
                        {
                            .code = 0xC7ULL,
                            .umask = 0x20ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts once for most SIMD 256-bit packed single computational precision floating-point instructions retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.",
                    .full_desc =
                        "Counts once for most SIMD 256-bit packed single computational precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "FP_ARITH_INST_RETIRED.512B_PACKED_DOUBLE",
                    .encoding =
                        {
                            .code = 0xC7ULL,
                            .umask = 0x40ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts number of SSE/AVX computational 512-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
                    .full_desc =
                        "Number of SSE/AVX computational 512-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "FP_ARITH_INST_RETIRED.512B_PACKED_SINGLE",
                    .encoding =
                        {
                            .code = 0xC7ULL,
                            .umask = 0x80ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts number of SSE/AVX computational 512-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 16 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
                    .full_desc =
                        "Number of SSE/AVX computational 512-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 16 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "FP_ARITH_INST_RETIRED.SCALAR_DOUBLE",
                    .encoding =
                        {
                            .code = 0xC7ULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts once for most SIMD scalar computational double precision floating-point instructions retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.",
                    .full_desc =
                        "Counts once for most SIMD scalar computational double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SIMD scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "FP_ARITH_INST_RETIRED.SCALAR_SINGLE",
                    .encoding =
                        {
                            .code = 0xC7ULL,
                            .umask = 0x2ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Counts once for most SIMD scalar computational single precision floating-point instructions retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.",
                    .full_desc =
                        "Counts once for most SIMD scalar computational single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SIMD scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                    .default_sampling_period = 0x1E8483ULL,
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
                        "Counts the number of uops not delivered to Resource Allocation Table (RAT) per thread adding 4  x when Resource Allocation Table (RAT) is not stalled and Instruction Decode Queue (IDQ) delivers x uops to Resource Allocation Table (RAT) (where x belongs to {0,1,2,3}). Counting does not cover cases when: a. IDQ-Resource Allocation Table (RAT) pipe serves the other thread. b. Resource Allocation Table (RAT) is stalled for the thread (including uop drops and clear BE conditions).  c. Instruction Decode Queue (IDQ) delivers four uops.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "INT_MISC.RECOVERY_CYCLES",
                    .encoding =
                        {
                            .code = 0xDULL,
                            .umask = 0x1ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Core cycles the allocator was stalled due to recovery from earlier clear event for this thread (e.g. misprediction or memory nuke)",
                    .full_desc =
                        "Core cycles the Resource allocator was stalled due to recovery from an earlier branch misprediction or machine clear event.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "INT_MISC.RECOVERY_CYCLES_ANY",
                    .encoding =
                        {
                            .code = 0xDULL,
                            .umask = 0x1ULL,
                            .any = true,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc =
                        "Core cycles the allocator was stalled due to recovery from earlier clear event for any thread running on the physical core (e.g. misprediction or memory nuke).",
                    .full_desc =
                        "Core cycles the allocator was stalled due to recovery from earlier clear event for any thread running on the physical core (e.g. misprediction or memory nuke).",
                    .default_sampling_period = 0x1E8483ULL,
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
                        "Code miss in all TLB levels causes a page walk that completes. (All page sizes)",
                    .full_desc =
                        "Counts completed page walks (all page sizes) caused by a code fetch. This implies it missed in the ITLB (Instruction TLB) and further levels of TLB. The page walk can end with or without a fault.",
                    .default_sampling_period = 0x186A3ULL,
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
                        "Counts L1D data line replacements including opportunistic replacements, and replacements that require stall-for-replace or block-for-replace.",
                    .default_sampling_period = 0x1E8483ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "L2_LINES_IN.ALL",
                    .encoding =
                        {
                            .code = 0xF1ULL,
                            .umask = 0x1FULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "L2 cache lines filling L2",
                    .full_desc =
                        "Counts the number of L2 cache lines filling the L2. Counting does not cover rejects.",
                    .default_sampling_period = 0x186A3ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "L2_RQSTS.ALL_CODE_RD",
                    .encoding =
                        {
                            .code = 0x24ULL,
                            .umask = 0xE4ULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "L2 code requests",
                    .full_desc = "Counts the total number of L2 code requests.",
                    .default_sampling_period = 0x30D43ULL,
                },
                {
                    .pmu_type = PmuType::cpu,
                    .id = "L2_RQSTS.MISS",
                    .encoding =
                        {
                            .code = 0x24ULL,
                            .umask = 0x3FULL,
                            .msr_values = uint64_t{0x0ULL},
                        },
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "All requests that miss L2 cache",
                    .full_desc = "All requests that miss L2 cache.",
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
                        "Loads blocked due to overlapping with a preceding store that cannot be forwarded.",
                    .full_desc =
                        "Counts the number of times where store forwarding was prevented for a load operation. The most common case is a load blocked due to the address of memory access (partially) overlapping with a preceding uncompleted store. Note: See the table of not supported store forwards in the Optimization Guide.",
                    .default_sampling_period = 0x186A3ULL,
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
                        "Core-originated cacheable demand requests missed L3",
                    .full_desc =
                        "Counts core-originated cacheable requests that miss the L3 cache (Longest Latency cache). Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches from L1 and L2. It does not include all misses to the L3.",
                    .default_sampling_period = 0x186A3ULL,
                    .errata = "SKL057",
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
                        "Counts the number of offcore outstanding cacheable Core Data Read transactions in the super queue every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.",
                    .default_sampling_period = 0x1E8483ULL,
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
                        "Counts cycles when offcore outstanding cacheable Core Data Read transactions are present in the super queue. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.",
                    .default_sampling_period = 0x1E8483ULL,
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
                        "Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction",
                    .full_desc =
                        "Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction.",
                    .default_sampling_period = 0x186A3ULL,
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
                        "Counts the number of uops that the Resource Allocation Table (RAT) issues to the Reservation Station (RS).",
                    .default_sampling_period = 0x1E8483ULL,
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
                    .features = StaticEventDef::IntelFeatures{},
                    .brief_desc = "Retirement slots used.",
                    .full_desc = "Counts the retirement slots used.",
                    .default_sampling_period = 0x1E8483ULL,
                },
            }};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 432>
    kFullOnlyEvents{
        {
            {
                .pmu_type = PmuType::cpu,
                .id = "ARITH.DIVIDER_ACTIVE",
                .encoding =
                    {
                        .code = 0x14ULL,
                        .umask = 0x1ULL,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles when divide unit is busy executing divide or square root operations. Accounts for integer and floating-point operations.",
                .full_desc =
                    "Cycles when divide unit is busy executing divide or square root operations. Accounts for integer and floating-point operations.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the total number when the front end is resteered, mainly when the BPU cannot provide a correct prediction and this is corrected by other branch handling mechanisms at the front end.",
                .full_desc =
                    "Counts the number of times the front-end is resteered when it finds a branch instruction in a fetch line. This occurs for the first time a branch instruction is fetched or when the branch is not tracked by the BPU (Branch Prediction Unit) anymore.",
                .default_sampling_period = 0x186A3ULL,
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
                .full_desc =
                    "This is a precise version of BR_INST_RETIRED.ALL_BRANCHES that counts all (macro) branch instructions retired.",
                .default_sampling_period = 0x61A89ULL,
                .errata = "SKL091",
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_INST_RETIRED.COND",
                .encoding =
                    {
                        .code = 0xC4ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Conditional branch instructions retired. [This event is alias to BR_INST_RETIRED.CONDITIONAL]",
                .full_desc =
                    "This event counts conditional branch instructions retired. [This event is alias to BR_INST_RETIRED.CONDITIONAL]",
                .default_sampling_period = 0x61A89ULL,
                .errata = "SKL091",
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
                    "Conditional branch instructions retired. [This event is alias to BR_INST_RETIRED.COND]",
                .full_desc =
                    "This event counts conditional branch instructions retired. [This event is alias to BR_INST_RETIRED.COND]",
                .default_sampling_period = 0x61A89ULL,
                .errata = "SKL091",
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_INST_RETIRED.COND_NTAKEN",
                .encoding =
                    {
                        .code = 0xC4ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Not taken branch instructions retired.",
                .full_desc =
                    "This event counts not taken branch instructions retired.",
                .default_sampling_period = 0x61A89ULL,
                .errata = "SKL091",
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
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc = "Far branch instructions retired.",
                .full_desc =
                    "This event counts far branch instructions retired.",
                .default_sampling_period = 0x186A7ULL,
                .errata = "SKL091",
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
                    "Direct and indirect near call instructions retired.",
                .full_desc =
                    "This event counts both direct and indirect near call instructions retired.",
                .default_sampling_period = 0x186A7ULL,
                .errata = "SKL091",
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
                .full_desc = "This event counts return instructions retired.",
                .default_sampling_period = 0x186A7ULL,
                .errata = "SKL091",
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
                    "This event counts not taken branch instructions retired.",
                .default_sampling_period = 0x61A89ULL,
                .errata = "SKL091",
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
                    "This event counts both taken and not taken speculative and retired mispredicted branch instructions.",
                .default_sampling_period = 0x30D43ULL,
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
                .full_desc =
                    "This is a precise version of BR_MISP_RETIRED.ALL_BRANCHES that counts all mispredicted macro branch instructions retired.",
                .default_sampling_period = 0x61A89ULL,
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
                    "Mispredicted conditional branch instructions retired.",
                .full_desc =
                    "This event counts mispredicted conditional branch instructions retired.",
                .default_sampling_period = 0x61A89ULL,
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
                    "Mispredicted direct and indirect near call instructions retired.",
                .full_desc =
                    "Counts both taken and not taken retired mispredicted direct and indirect near calls, including both register and memory indirect.",
                .default_sampling_period = 0x61A89ULL,
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
                    "Number of near branch instructions retired that were mispredicted and taken.",
                .full_desc =
                    "Number of near branch instructions retired that were mispredicted and taken.",
                .default_sampling_period = 0x61A89ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "BR_MISP_RETIRED.RET",
                .encoding =
                    {
                        .code = 0xC5ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "This event counts the number of mispredicted ret instructions retired. Non PEBS",
                .full_desc =
                    "This is a non-precise version (that is, does not use PEBS) of the event that counts mispredicted return instructions retired.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_POWER.LVL0_TURBO_LICENSE",
                .encoding =
                    {
                        .code = 0x28ULL,
                        .umask = 0x7ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Core cycles where the core was running in a manner where Turbo may be clipped to the Non-AVX turbo schedule.",
                .full_desc =
                    "Core cycles where the core was running with power-delivery for baseline license level 0.  This includes non-AVX codes, SSE, AVX 128-bit, and low-current AVX 256-bit codes.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_POWER.LVL1_TURBO_LICENSE",
                .encoding =
                    {
                        .code = 0x28ULL,
                        .umask = 0x18ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Core cycles where the core was running in a manner where Turbo may be clipped to the AVX2 turbo schedule.",
                .full_desc =
                    "Core cycles where the core was running with power-delivery for license level 1.  This includes high current AVX 256-bit instructions as well as low current AVX 512-bit instructions.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_POWER.LVL2_TURBO_LICENSE",
                .encoding =
                    {
                        .code = 0x28ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Core cycles where the core was running in a manner where Turbo may be clipped to the AVX512 turbo schedule.",
                .full_desc =
                    "Core cycles where the core was running with power-delivery for license level 2 (introduced in Skylake Server microarchitecture).  This includes high current AVX 512-bit instructions.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_POWER.THROTTLE",
                .encoding =
                    {
                        .code = 0x28ULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Core cycles the core was throttled due to a pending power level request.",
                .full_desc =
                    "Core cycles the out-of-order engine was throttled due to a pending power level request.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_SNOOP_RESPONSE.RSP_IFWDFE",
                .encoding =
                    {
                        .code = 0xEFULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CORE_SNOOP_RESPONSE.RSP_IFWDFE",
                .full_desc = "CORE_SNOOP_RESPONSE.RSP_IFWDFE",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_SNOOP_RESPONSE.RSP_IFWDM",
                .encoding =
                    {
                        .code = 0xEFULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CORE_SNOOP_RESPONSE.RSP_IFWDM",
                .full_desc = "CORE_SNOOP_RESPONSE.RSP_IFWDM",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_SNOOP_RESPONSE.RSP_IHITFSE",
                .encoding =
                    {
                        .code = 0xEFULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CORE_SNOOP_RESPONSE.RSP_IHITFSE",
                .full_desc = "CORE_SNOOP_RESPONSE.RSP_IHITFSE",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_SNOOP_RESPONSE.RSP_IHITI",
                .encoding =
                    {
                        .code = 0xEFULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CORE_SNOOP_RESPONSE.RSP_IHITI",
                .full_desc = "CORE_SNOOP_RESPONSE.RSP_IHITI",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_SNOOP_RESPONSE.RSP_SFWDFE",
                .encoding =
                    {
                        .code = 0xEFULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CORE_SNOOP_RESPONSE.RSP_SFWDFE",
                .full_desc = "CORE_SNOOP_RESPONSE.RSP_SFWDFE",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_SNOOP_RESPONSE.RSP_SFWDM",
                .encoding =
                    {
                        .code = 0xEFULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CORE_SNOOP_RESPONSE.RSP_SFWDM",
                .full_desc = "CORE_SNOOP_RESPONSE.RSP_SFWDM",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CORE_SNOOP_RESPONSE.RSP_SHITFSE",
                .encoding =
                    {
                        .code = 0xEFULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "CORE_SNOOP_RESPONSE.RSP_SHITFSE",
                .full_desc = "CORE_SNOOP_RESPONSE.RSP_SHITFSE",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Core crystal clock cycles when this thread is unhalted and the other thread is halted.",
                .full_desc =
                    "Core crystal clock cycles when this thread is unhalted and the other thread is halted.",
                .default_sampling_period = 0x61ABULL,
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
                    "Core crystal clock cycles when the thread is unhalted.",
                .full_desc =
                    "Core crystal clock cycles when the thread is unhalted.",
                .default_sampling_period = 0x61ABULL,
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
                    "Core crystal clock cycles when at least one thread on the physical core is unhalted.",
                .full_desc =
                    "Core crystal clock cycles when at least one thread on the physical core is unhalted.",
                .default_sampling_period = 0x61ABULL,
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
                    "Core crystal clock cycles when this thread is unhalted and the other thread is halted.",
                .full_desc =
                    "Core crystal clock cycles when this thread is unhalted and the other thread is halted.",
                .default_sampling_period = 0x61ABULL,
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
                    "Core crystal clock cycles when the thread is unhalted.",
                .full_desc =
                    "Core crystal clock cycles when the thread is unhalted.",
                .default_sampling_period = 0x61ABULL,
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
                    "Core crystal clock cycles when at least one thread on the physical core is unhalted.",
                .full_desc =
                    "Core crystal clock cycles when at least one thread on the physical core is unhalted.",
                .default_sampling_period = 0x61ABULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CPU_CLK_UNHALTED.RING0_TRANS",
                .encoding =
                    {
                        .code = 0x3CULL,
                        .edge = true,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts when there is a transition from ring 1, 2 or 3 to ring 0.",
                .full_desc =
                    "Counts when the Current Privilege Level (CPL) transitions from ring 1, 2 or 3 to ring 0 (Kernel).",
                .default_sampling_period = 0x186A7ULL,
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
                .brief_desc =
                    "Cycles while L1 cache miss demand load is outstanding.",
                .full_desc =
                    "Cycles while L1 cache miss demand load is outstanding.",
                .default_sampling_period = 0x1E8483ULL,
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
                .brief_desc =
                    "Cycles while L2 cache miss demand load is outstanding.",
                .full_desc =
                    "Cycles while L2 cache miss demand load is outstanding.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CYCLE_ACTIVITY.CYCLES_L3_MISS",
                .encoding =
                    {
                        .code = 0xA3ULL,
                        .umask = 0x2ULL,
                        .cmask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles while L3 cache miss demand load is outstanding.",
                .full_desc =
                    "Cycles while L3 cache miss demand load is outstanding.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CYCLE_ACTIVITY.CYCLES_MEM_ANY",
                .encoding =
                    {
                        .code = 0xA3ULL,
                        .umask = 0x10ULL,
                        .cmask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles while memory subsystem has an outstanding load.",
                .full_desc =
                    "Cycles while memory subsystem has an outstanding load.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "CYCLE_ACTIVITY.STALLS_L3_MISS",
                .encoding =
                    {
                        .code = 0xA3ULL,
                        .umask = 0x6ULL,
                        .cmask = 0x6ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Execution stalls while L3 cache miss demand load is outstanding.",
                .full_desc =
                    "Execution stalls while L3 cache miss demand load is outstanding.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "DECODE.LCP",
                .encoding =
                    {
                        .code = 0x87ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Stalls caused by changing prefix length of the instruction. [This event is alias to ILD_STALL.LCP]",
                .full_desc =
                    "Counts cycles that the Instruction Length decoder (ILD) stalls occurred due to dynamically changing prefix length of the decoded instruction (by operand size prefix instruction 0x66, address size prefix instruction 0x67 or REX.W for Intel64). Count is proportional to the number of prefixes in a 16B-line. This may result in a three-cycle penalty for each LCP (Length changing prefix) in a 16-byte chunk. [This event is alias to ILD_STALL.LCP]",
                .default_sampling_period = 0x1E8483ULL,
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
                .full_desc =
                    "This event counts the number of the Decode Stream Buffer (DSB)-to-MITE switches including all misses because of missing Decode Stream Buffer (DSB) cache and u-arch forced misses. Note: Invoking MITE requires two or three cycles delay.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts Decode Stream Buffer (DSB)-to-MITE switch true penalty cycles. These cycles do not include uops routed through because of the switch itself, for example, when Instruction Decode Queue (IDQ) pre-allocation is unavailable, or Instruction Decode Queue (IDQ) is full. SBD-to-MITE switch true penalty cycles happen after the merge mux (MM) receives Decode Stream Buffer (DSB) Sync-indication until receiving the first MITE uop. MM is placed before Instruction Decode Queue (IDQ) to merge uops being fed from the MITE and Decode Stream Buffer (DSB) paths. Decode Stream Buffer (DSB) inserts the Sync-indication whenever a Decode Stream Buffer (DSB)-to-MITE switch occurs.Penalty: A Decode Stream Buffer (DSB) hit followed by a Decode Stream Buffer (DSB) miss can cost up to six cycles in which no uops are delivered to the IDQ. Most often, such switches from the Decode Stream Buffer (DSB) to the legacy pipeline cost 02 cycles.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Load misses in all DTLB levels that cause page walks",
                .full_desc =
                    "Counts demand data loads that caused a page walk of any page size (4K/2M/4M/1G). This implies it missed in all TLB levels, but the walk need not have completed.",
                .default_sampling_period = 0x186A3ULL,
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
                .brief_desc = "Loads that miss the DTLB and hit the STLB.",
                .full_desc =
                    "Counts loads that miss the DTLB (Data TLB) and hit the STLB (Second level TLB).",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "DTLB_LOAD_MISSES.WALK_ACTIVE",
                .encoding =
                    {
                        .code = 0x8ULL,
                        .umask = 0x10ULL,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles when at least one PMH is busy with a page walk for a load. EPT page walk duration are excluded in Skylake.",
                .full_desc =
                    "Counts cycles when at least one PMH (Page Miss Handler) is busy with a page walk for a load.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Page walk completed due to a demand data load to a 1G page",
                .full_desc =
                    "Counts completed page walks  (1G sizes) caused by demand data loads. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Page walk completed due to a demand data load to a 2M/4M page",
                .full_desc =
                    "Counts completed page walks  (2M/4M sizes) caused by demand data loads. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Page walk completed due to a demand data load to a 4K page",
                .full_desc =
                    "Counts completed page walks  (4K sizes) caused by demand data loads. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts 1 per cycle for each PMH that is busy with a page walk for a load. EPT page walk duration are excluded in Skylake.",
                .full_desc =
                    "Counts 1 per cycle for each PMH that is busy with a page walk for a load. EPT page walk duration are excluded in Skylake microarchitecture.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Store misses in all DTLB levels that cause page walks",
                .full_desc = "Counts demand data stores that caused a page walk of any page size (4K/2M/4M/1G). This implies it missed in all TLB levels, but the walk need not have completed.",
                .default_sampling_period = 0x186A3ULL,
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
                .brief_desc = "Stores that miss the DTLB and hit the STLB.",
                .full_desc =
                    "Stores that miss the DTLB (Data TLB) and hit the STLB (2nd Level TLB).",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "DTLB_STORE_MISSES.WALK_ACTIVE",
                .encoding =
                    {
                        .code = 0x49ULL,
                        .umask = 0x10ULL,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles when at least one PMH is busy with a page walk for a store. EPT page walk duration are excluded in Skylake.",
                .full_desc =
                    "Counts cycles when at least one PMH (Page Miss Handler) is busy with a page walk for a store.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Page walk completed due to a demand data store to a 1G page",
                .full_desc =
                    "Counts completed page walks  (1G sizes) caused by demand data stores. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Page walk completed due to a demand data store to a 2M/4M page",
                .full_desc =
                    "Counts completed page walks  (2M/4M sizes) caused by demand data stores. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Page walk completed due to a demand data store to a 4K page",
                .full_desc =
                    "Counts completed page walks  (4K sizes) caused by demand data stores. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Counts 1 per cycle for each PMH that is busy with a page walk for a store. EPT page walk duration are excluded in Skylake.",
                .full_desc =
                    "Counts 1 per cycle for each PMH that is busy with a page walk for a store. EPT page walk duration are excluded in Skylake microarchitecture.",
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
                    "Counts 1 per cycle for each PMH that is busy with a EPT (Extended Page Table) walk for any request type.",
                .full_desc =
                    "Counts cycles for each PMH (Page Miss Handler) that is busy with an EPT (Extended Page Table) walk for any request type.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "EXE_ACTIVITY.1_PORTS_UTIL",
                .encoding =
                    {
                        .code = 0xA6ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles total of 1 uop is executed on all ports and Reservation Station was not empty.",
                .full_desc =
                    "Counts cycles during which a total of 1 uop was executed on all ports and Reservation Station (RS) was not empty.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "EXE_ACTIVITY.2_PORTS_UTIL",
                .encoding =
                    {
                        .code = 0xA6ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles total of 2 uops are executed on all ports and Reservation Station was not empty.",
                .full_desc =
                    "Counts cycles during which a total of 2 uops were executed on all ports and Reservation Station (RS) was not empty.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "EXE_ACTIVITY.3_PORTS_UTIL",
                .encoding =
                    {
                        .code = 0xA6ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles total of 3 uops are executed on all ports and Reservation Station was not empty.",
                .full_desc =
                    "Cycles total of 3 uops are executed on all ports and Reservation Station (RS) was not empty.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "EXE_ACTIVITY.4_PORTS_UTIL",
                .encoding =
                    {
                        .code = 0xA6ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles total of 4 uops are executed on all ports and Reservation Station was not empty.",
                .full_desc =
                    "Cycles total of 4 uops are executed on all ports and Reservation Station (RS) was not empty.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "EXE_ACTIVITY.BOUND_ON_STORES",
                .encoding =
                    {
                        .code = 0xA6ULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles where the Store Buffer was full and no outstanding load.",
                .full_desc =
                    "Cycles where the Store Buffer was full and no outstanding load.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "EXE_ACTIVITY.EXE_BOUND_0_PORTS",
                .encoding =
                    {
                        .code = 0xA6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles where no uops were executed, the Reservation Station was not empty, the Store Buffer was full and there was no outstanding load.",
                .full_desc =
                    "Counts cycles during which no uops were executed on all ports and Reservation Station (RS) was not empty.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_ARITH_INST_RETIRED.4_FLOPS",
                .encoding =
                    {
                        .code = 0xC7ULL,
                        .umask = 0x18ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of SSE/AVX computational 128-bit packed single and 256-bit packed double precision FP instructions retired; some instructions will count twice as noted below.  Each count represents 2 or/and 4 computation operations, 1 for each element.  Applies to SSE* and AVX* packed single precision and packed double precision FP instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX RCP14 RSQRT14 SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB count twice as they perform 2 calculations per element.",
                .full_desc =
                    "Number of SSE/AVX computational 128-bit packed single precision and 256-bit packed double precision  floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 or/and 4 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point and packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX RCP14 RSQRT14 SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_ARITH_INST_RETIRED.8_FLOPS",
                .encoding =
                    {
                        .code = 0xC7ULL,
                        .umask = 0x18ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of SSE/AVX computational 256-bit packed single precision and 512-bit packed double precision  FP instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, 1 for each element.  Applies to SSE* and AVX* packed single precision and double precision FP instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RSQRT14 RCP RCP14 DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB count twice as they perform 2 calculations per element.",
                .full_desc =
                    "Number of SSE/AVX computational 256-bit packed single precision and 512-bit packed double precision  floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision and double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RSQRT14 RCP RCP14 DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_ARITH_INST_RETIRED.SCALAR",
                .encoding =
                    {
                        .code = 0xC7ULL,
                        .umask = 0x3ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts once for most SIMD scalar computational floating-point instructions retired. Counts twice for DPP and FM(N)ADD/SUB instructions retired.",
                .full_desc =
                    "Counts once for most SIMD scalar computational single precision and double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SIMD scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FP_ARITH_INST_RETIRED.VECTOR",
                .encoding =
                    {
                        .code = 0xC7ULL,
                        .umask = 0xFCULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of any Vector retired FP arithmetic instructions",
                .full_desc =
                    "Number of any Vector retired FP arithmetic instructions",
                .default_sampling_period = 0x1E8483ULL,
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
                .full_desc =
                    "Counts cycles with any input and output SSE or x87 FP assist. If an input and output assist are detected on the same cycle the event increments by 1.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.ANY_DSB_MISS",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc = "Retired Instructions who experienced DSB miss.",
                .full_desc =
                    "Counts retired Instructions that experienced DSB (Decode stream buffer i.e. the decoded instruction-cache) miss.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.DSB_MISS",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x11ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired Instructions who experienced a critical DSB miss.",
                .full_desc =
                    "Number of retired Instructions that experienced a critical DSB (Decode stream buffer i.e. the decoded instruction-cache) miss. Critical means stalls were exposed to the back-end as a result of the DSB miss.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.ITLB_MISS",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x14ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired Instructions who experienced iTLB true miss.",
                .full_desc =
                    "Counts retired Instructions that experienced iTLB (Instruction TLB) true miss.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.L1I_MISS",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x12ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired Instructions who experienced Instruction L1 Cache true miss.",
                .full_desc =
                    "Retired Instructions who experienced Instruction L1 Cache true miss.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.L2_MISS",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x13ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired Instructions who experienced Instruction L2 Cache true miss.",
                .full_desc =
                    "Retired Instructions who experienced Instruction L2 Cache true miss.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_1",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x400106ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 2,
                    },
                .brief_desc =
                    "Retired instructions after front-end starvation of at least 1 cycle",
                .full_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of at least 1 cycle which was not interrupted by a back-end stall.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_128",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x408006ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 128 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 128 cycles which was not interrupted by a back-end stall.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_16",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x401006ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 16 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Counts retired instructions that are delivered to the back-end after a front-end stall of at least 16 cycles. During this period the front-end delivered no uops.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_2",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x400206ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 2 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 2 cycles which was not interrupted by a back-end stall.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_256",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x410006ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 256 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 256 cycles which was not interrupted by a back-end stall.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_2_BUBBLES_GE_1",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x100206ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end had at least 1 bubble-slot for a period of 2 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Counts retired instructions that are delivered to the back-end after the front-end had at least 1 bubble-slot for a period of 2 cycles. A bubble-slot is an empty issue-pipeline slot while there was no RAT stall.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_2_BUBBLES_GE_2",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x200206ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end had at least 2 bubble-slots for a period of 2 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Retired instructions that are fetched after an interval where the front-end had at least 2 bubble-slots for a period of 2 cycles which was not interrupted by a back-end stall.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_2_BUBBLES_GE_3",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x300206ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end had at least 3 bubble-slots for a period of 2 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Retired instructions that are fetched after an interval where the front-end had at least 3 bubble-slots for a period of 2 cycles which was not interrupted by a back-end stall.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_32",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x402006ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 32 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Counts retired instructions that are delivered to the back-end after a front-end stall of at least 32 cycles. During this period the front-end delivered no uops.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_4",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x400406ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 4 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 4 cycles which was not interrupted by a back-end stall.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_512",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x420006ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 512 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 512 cycles which was not interrupted by a back-end stall.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_64",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x404006ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 64 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 64 cycles which was not interrupted by a back-end stall.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.LATENCY_GE_8",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x400806ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 8 cycles which was not interrupted by a back-end stall.",
                .full_desc =
                    "Counts retired instructions that are delivered to the back-end after a front-end stall of at least 8 cycles. During this period the front-end delivered no uops.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "FRONTEND_RETIRED.STLB_MISS",
                .encoding =
                    {
                        .code = 0xC6ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x15ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired Instructions who experienced STLB (2nd level TLB) true miss.",
                .full_desc =
                    "Counts retired Instructions that experienced STLB (2nd level TLB) true miss.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "HLE_RETIRED.ABORTED",
                .encoding =
                    {
                        .code = 0xC8ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 1,
                    },
                .brief_desc =
                    "Number of times an HLE execution aborted due to any reasons (multiple categories may count as one).",
                .full_desc = "Number of times HLE abort was triggered.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "HLE_RETIRED.ABORTED_EVENTS",
                .encoding =
                    {
                        .code = 0xC8ULL,
                        .umask = 0x80ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an HLE execution aborted due to unfriendly events (such as interrupts).",
                .full_desc =
                    "Number of times an HLE execution aborted due to unfriendly events (such as interrupts).",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "HLE_RETIRED.ABORTED_MEM",
                .encoding =
                    {
                        .code = 0xC8ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an HLE execution aborted due to various memory events (e.g., read/write capacity and conflicts).",
                .full_desc =
                    "Number of times an HLE execution aborted due to various memory events (e.g., read/write capacity and conflicts).",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "HLE_RETIRED.ABORTED_MEMTYPE",
                .encoding =
                    {
                        .code = 0xC8ULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an HLE execution aborted due to incompatible memory type",
                .full_desc =
                    "Number of times an HLE execution aborted due to incompatible memory type.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "HLE_RETIRED.ABORTED_TIMER",
                .encoding =
                    {
                        .code = 0xC8ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an HLE execution aborted due to hardware timer expiration.",
                .full_desc =
                    "Number of times an HLE execution aborted due to hardware timer expiration.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "HLE_RETIRED.ABORTED_UNFRIENDLY",
                .encoding =
                    {
                        .code = 0xC8ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an HLE execution aborted due to HLE-unfriendly instructions and certain unfriendly events (such as AD assists etc.).",
                .full_desc =
                    "Number of times an HLE execution aborted due to HLE-unfriendly instructions and certain unfriendly events (such as AD assists etc.).",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "HLE_RETIRED.COMMIT",
                .encoding =
                    {
                        .code = 0xC8ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an HLE execution successfully committed",
                .full_desc = "Number of times HLE commit succeeded.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "HLE_RETIRED.START",
                .encoding =
                    {
                        .code = 0xC8ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Number of times an HLE execution started.",
                .full_desc =
                    "Number of times we entered an HLE region. Does not count nested transactions.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Number of hardware interrupts received by the processor.",
                .full_desc =
                    "Counts the number of hardware interruptions received by the processor.",
                .default_sampling_period = 0xCBULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "ICACHE_16B.IFDATA_STALL",
                .encoding =
                    {
                        .code = 0x80ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles where a code fetch is stalled due to L1 instruction cache miss.",
                .full_desc =
                    "Cycles where a code line fetch is stalled due to an L1 instruction cache miss. The legacy decode pipeline works at a 16 Byte granularity.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "ICACHE_64B.IFTAG_HIT",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Instruction fetch tag lookups that hit in the instruction cache (L1I). Counts at 64-byte cache-line granularity.",
                .full_desc =
                    "Instruction fetch tag lookups that hit in the instruction cache (L1I). Counts at 64-byte cache-line granularity.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "ICACHE_64B.IFTAG_MISS",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Instruction fetch tag lookups that miss in the instruction cache (L1I). Counts at 64-byte cache-line granularity.",
                .full_desc =
                    "Instruction fetch tag lookups that miss in the instruction cache (L1I). Counts at 64-byte cache-line granularity.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "ICACHE_64B.IFTAG_STALL",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles where a code fetch is stalled due to L1 instruction cache tag miss. [This event is alias to ICACHE_TAG.STALLS]",
                .full_desc =
                    "Cycles where a code fetch is stalled due to L1 instruction cache tag miss. [This event is alias to ICACHE_TAG.STALLS]",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "ICACHE_TAG.STALLS",
                .encoding =
                    {
                        .code = 0x83ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles where a code fetch is stalled due to L1 instruction cache tag miss. [This event is alias to ICACHE_64B.IFTAG_STALL]",
                .full_desc =
                    "Cycles where a code fetch is stalled due to L1 instruction cache tag miss. [This event is alias to ICACHE_64B.IFTAG_STALL]",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "IDI_MISC.WB_DOWNGRADE",
                .encoding =
                    {
                        .code = 0xFEULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts number of cache lines that are dropped and not written back to L3 as they are deemed to be less likely to be reused shortly",
                .full_desc =
                    "Counts number of cache lines that are dropped and not written back to L3 as they are deemed to be less likely to be reused shortly.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "IDI_MISC.WB_UPGRADE",
                .encoding =
                    {
                        .code = 0xFEULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts number of cache lines that are allocated and written back to L3 with the intention that they are more likely to be reused shortly",
                .full_desc =
                    "Counts number of cache lines that are allocated and written back to L3 with the intention that they are more likely to be reused shortly.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Cycles Decode Stream Buffer (DSB) is delivering 4 or more Uops [This event is alias to IDQ.DSB_CYCLES_OK]",
                .full_desc =
                    "Counts the number of cycles 4 or more uops were delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Count includes uops that may 'bypass' the IDQ. [This event is alias to IDQ.DSB_CYCLES_OK]",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Cycles Decode Stream Buffer (DSB) is delivering any Uop [This event is alias to IDQ.DSB_CYCLES_ANY]",
                .full_desc =
                    "Counts the number of cycles uops were delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Count includes uops that may 'bypass' the IDQ. [This event is alias to IDQ.DSB_CYCLES_ANY]",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the number of cycles 4 uops were delivered to the Instruction Decode Queue (IDQ) from the MITE (legacy decode pipeline) path. Counting includes uops that may 'bypass' the IDQ. During these cycles uops are not being delivered from the Decode Stream Buffer (DSB).",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the number of cycles uops were delivered to the Instruction Decode Queue (IDQ) from the MITE (legacy decode pipeline) path. Counting includes uops that may 'bypass' the IDQ. During these cycles uops are not being delivered from the Decode Stream Buffer (DSB).",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may 'bypass' the IDQ.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "IDQ.DSB_CYCLES_ANY",
                .encoding =
                    {
                        .code = 0x79ULL,
                        .umask = 0x18ULL,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles Decode Stream Buffer (DSB) is delivering any Uop [This event is alias to IDQ.ALL_DSB_CYCLES_ANY_UOPS]",
                .full_desc =
                    "Counts the number of cycles uops were delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Count includes uops that may 'bypass' the IDQ. [This event is alias to IDQ.ALL_DSB_CYCLES_ANY_UOPS]",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "IDQ.DSB_CYCLES_OK",
                .encoding =
                    {
                        .code = 0x79ULL,
                        .umask = 0x18ULL,
                        .cmask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles Decode Stream Buffer (DSB) is delivering 4 or more Uops [This event is alias to IDQ.ALL_DSB_CYCLES_4_UOPS]",
                .full_desc =
                    "Counts the number of cycles 4 or more uops were delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Count includes uops that may 'bypass' the IDQ. [This event is alias to IDQ.ALL_DSB_CYCLES_4_UOPS]",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the number of uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may 'bypass' the IDQ.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may 'bypass' the IDQ.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the number of uops delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may 'bypass' the IDQ. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may 'bypass' the IDQ. Uops maybe initiated by Decode Stream Buffer (DSB) or MITE.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts cycles during which uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may 'bypass' the IDQ.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the number of uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may 'bypass' the IDQ.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the total number of uops delivered by the Microcode Sequencer (MS). Any instruction over 4 uops will be delivered by the MS. Some instructions such as transcendentals may additionally generate uops from the MS.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Cycles per thread when 4 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled",
                .full_desc =
                    "Counts, on the per-thread basis, cycles when no uops are delivered to Resource Allocation Table (RAT). IDQ_Uops_Not_Delivered.core =4.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Cycles per thread when 3 or more uops are not delivered to Resource Allocation Table (RAT) when backend of the machine is not stalled",
                .full_desc =
                    "Counts, on the per-thread basis, cycles when less than 1 uop is delivered to Resource Allocation Table (RAT). IDQ_Uops_Not_Delivered.core >= 3.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Cycles with less than 2 uops delivered by the front-end.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Cycles with less than 3 uops delivered by the front-end.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Stalls caused by changing prefix length of the instruction. [This event is alias to DECODE.LCP]",
                .full_desc =
                    "Counts cycles that the Instruction Length decoder (ILD) stalls occurred due to dynamically changing prefix length of the decoded instruction (by operand size prefix instruction 0x66, address size prefix instruction 0x67 or REX.W for Intel64). Count is proportional to the number of prefixes in a 16B-line. This may result in a three-cycle penalty for each LCP (Length changing prefix) in a 16-byte chunk. [This event is alias to DECODE.LCP]",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "INST_DECODED.DECODERS",
                .encoding =
                    {
                        .code = 0x55ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Instruction decoders utilized in a cycle",
                .full_desc =
                    "Number of decoders utilized in a cycle when the MITE (legacy decode pipeline) fetches instructions.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the number of instructions retired from execution. For instructions that consist of multiple micro-ops, Counts the retirement of the last micro-op of the instruction. Counting continues during hardware interrupts, traps, and inside interrupt handlers. Notes: INST_RETIRED.ANY is counted by a designated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. INST_RETIRED.ANY_P is counted by a programmable counter and it is an architectural performance event. Counting: Faulting executions of GETSEC/VM entry/VM Exit/MWait will not count as retired instructions.",
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
                .brief_desc =
                    "Number of instructions retired. General Counter - architectural event",
                .full_desc =
                    "Counts the number of instructions (EOMs) retired. Counting covers macro-fused instructions individually (that is, increments by two).",
                .default_sampling_period = 0x1E8483ULL,
                .errata = "SKL091, SKL044",
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "INST_RETIRED.NOP",
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
                .brief_desc = "Number of all retired NOP instructions.",
                .full_desc = "Number of all retired NOP instructions.",
                .default_sampling_period = 0x1E8483ULL,
                .errata = "SKL091, SKL044",
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
                    "A version of INST_RETIRED that allows for a more unbiased distribution of samples across instructions retired. It utilizes the Precise Distribution of Instructions Retired (PDIR) feature to mitigate some bias in how retired instructions get sampled.",
                .default_sampling_period = 0x1E8483ULL,
                .errata = "SKL091, SKL044",
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "INST_RETIRED.TOTAL_CYCLES_PS",
                .encoding =
                    {
                        .code = 0xC0ULL,
                        .umask = 0x1ULL,
                        .inv = true,
                        .cmask = 0xAULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 2,
                    },
                .brief_desc =
                    "Number of cycles using always true condition applied to  PEBS instructions retired event.",
                .full_desc =
                    "Number of cycles using an always true condition applied to  PEBS instructions retired event. (inst_ret< 16)",
                .default_sampling_period = 0x1E8483ULL,
                .errata = "SKL091, SKL044",
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "INT_MISC.CLEARS_COUNT",
                .encoding =
                    {
                        .code = 0xDULL,
                        .umask = 0x1ULL,
                        .edge = true,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Clears speculative count",
                .full_desc =
                    "Counts the number of speculative clears due to any type of branch misprediction or machine clears",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "INT_MISC.CLEAR_RESTEER_CYCLES",
                .encoding =
                    {
                        .code = 0xDULL,
                        .umask = 0x80ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles the issue-stage is waiting for front-end to fetch from resteered path following branch misprediction or machine clear events.",
                .full_desc =
                    "Cycles the issue-stage is waiting for front-end to fetch from resteered path following branch misprediction or machine clear events.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the number of flushes of the big or small ITLB pages. Counting include both TLB Flush (covering all sets) and TLB Set Clear (set-specific).",
                .default_sampling_period = 0x186A7ULL,
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
                .full_desc =
                    "Counts page walks of any page size (4K/2M/4M/1G) caused by a code fetch. This implies it missed in the ITLB and further levels of TLB, but the walk need not have completed.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Instruction fetch requests that miss the ITLB and hit the STLB.",
                .full_desc =
                    "Instruction fetch requests that miss the ITLB and hit the STLB.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "ITLB_MISSES.WALK_ACTIVE",
                .encoding =
                    {
                        .code = 0x85ULL,
                        .umask = 0x10ULL,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles when at least one PMH is busy with a page walk for code (instruction fetch) request. EPT page walk duration are excluded in Skylake.",
                .full_desc =
                    "Cycles when at least one PMH is busy with a page walk for code (instruction fetch) request. EPT page walk duration are excluded in Skylake microarchitecture.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Code miss in all TLB levels causes a page walk that completes. (1G)",
                .full_desc =
                    "Counts completed page walks (1G page sizes) caused by a code fetch. This implies it missed in the ITLB (Instruction TLB) and further levels of TLB. The page walk can end with or without a fault.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Code miss in all TLB levels causes a page walk that completes. (2M/4M)",
                .full_desc =
                    "Counts completed page walks (2M/4M page sizes) caused by a code fetch. This implies it missed in the ITLB (Instruction TLB) and further levels of TLB. The page walk can end with or without a fault.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Code miss in all TLB levels causes a page walk that completes. (4K)",
                .full_desc =
                    "Counts completed page walks (4K page sizes) caused by a code fetch. This implies it missed in the ITLB (Instruction TLB) and further levels of TLB. The page walk can end with or without a fault.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Counts 1 per cycle for each PMH that is busy with a page walk for an instruction fetch request. EPT page walk duration are excluded in Skylake.",
                .full_desc =
                    "Counts 1 per cycle for each PMH (Page Miss Handler) that is busy with a page walk for an instruction fetch request. EPT page walk duration are excluded in Skylake microarchitecture.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L1D_PEND_MISS.FB_FULL",
                .encoding =
                    {
                        .code = 0x48ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times a request needed a FB entry but there was no entry available for it. That is the FB unavailability was dominant reason for blocking the request. A request includes cacheable/uncacheable demands that is load, store or SW prefetch.",
                .full_desc =
                    "Number of times a request needed a FB (Fill Buffer) entry but there was no entry available for it. A request includes cacheable/uncacheable demands that are load, store or SW prefetch instructions.",
                .default_sampling_period = 0x1E8483ULL,
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
                .brief_desc = "L1D miss outstandings duration in cycles",
                .full_desc =
                    "Counts duration of L1D miss outstanding, that is each cycle number of Fill Buffers (FB) outstanding required by Demand Reads. FB either is held by demand loads, or it is held by non-demand loads and gets hit at least once by demand. The valid outstanding interval is defined until the FB deallocation by one of the following ways: from FB allocation, if FB is allocated by demand from the demand Hit FB, if it is allocated by hardware or software prefetch.Note: In the L1D, a Demand Read contains cacheable or noncacheable demand loads, including ones causing cache-line splits and reads due to page walks resulted from any request type.",
                .default_sampling_period = 0x1E8483ULL,
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
                .full_desc =
                    "Counts duration of L1D miss outstanding in cycles.",
                .default_sampling_period = 0x1E8483ULL,
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
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_LINES_OUT.NON_SILENT",
                .encoding =
                    {
                        .code = 0xF2ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of lines that are evicted by L2 cache when triggered by an L2 cache fill. Those lines can be either in modified state or clean state. Modified lines may either be written back to L3 or directly written to memory and not allocated in L3.  Clean lines may either be allocated in L3 or dropped",
                .full_desc =
                    "Counts the number of lines that are evicted by L2 cache when triggered by an L2 cache fill. Those lines can be either in modified state or clean state. Modified lines may either be written back to L3 or directly written to memory and not allocated in L3.  Clean lines may either be allocated in L3 or dropped.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_LINES_OUT.SILENT",
                .encoding =
                    {
                        .code = 0xF2ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of lines that are silently dropped by L2 cache when triggered by an L2 cache fill. These lines are typically in Shared state. A non-threaded event.",
                .full_desc =
                    "Counts the number of lines that are silently dropped by L2 cache when triggered by an L2 cache fill. These lines are typically in Shared state. A non-threaded event.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_LINES_OUT.USELESS_HWPF",
                .encoding =
                    {
                        .code = 0xF2ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of lines that have been hardware prefetched but not used and now evicted by L2 cache",
                .full_desc =
                    "Counts the number of lines that have been hardware prefetched but not used and now evicted by L2 cache",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.ALL_DEMAND_DATA_RD",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0xE1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Demand Data Read requests",
                .full_desc =
                    "Counts the number of demand Data Read requests (including requests from L1D hardware prefetchers). These loads may hit or miss L2 cache. Only non rejected loads are counted.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.ALL_DEMAND_MISS",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0x27ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Demand requests that miss L2 cache",
                .full_desc = "Demand requests that miss L2 cache.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.ALL_DEMAND_REFERENCES",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0xE7ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Demand requests to L2 cache",
                .full_desc = "Demand requests to L2 cache.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.ALL_PF",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0xF8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Requests from the L1/L2/L3 hardware prefetchers or Load software prefetches",
                .full_desc =
                    "Counts the total number of requests from the L2 hardware prefetchers.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.ALL_RFO",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0xE2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "RFO requests to L2 cache",
                .full_desc =
                    "Counts the total number of RFO (read for ownership) requests to L2 cache. L2 RFO requests include both L1D demand RFO misses as well as L1D RFO prefetches.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.CODE_RD_HIT",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0xC4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "L2 cache hits when fetching instructions, code reads.",
                .full_desc =
                    "Counts L2 cache hits when fetching instructions, code reads.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.CODE_RD_MISS",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0x24ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "L2 cache misses when fetching instructions",
                .full_desc =
                    "Counts L2 cache misses when fetching instructions.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.DEMAND_DATA_RD_HIT",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0xC1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Demand Data Read requests that hit L2 cache",
                .full_desc =
                    "Counts the number of demand Data Read requests, initiated by load instructions, that hit L2 cache",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.DEMAND_DATA_RD_MISS",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0x21ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Demand Data Read miss L2, no rejects",
                .full_desc =
                    "Counts the number of demand Data Read requests that miss L2 cache. Only not rejected loads are counted.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.PF_HIT",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0xD8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Requests from the L1/L2/L3 hardware prefetchers or Load software prefetches that hit L2 cache",
                .full_desc =
                    "Counts requests from the L1/L2/L3 hardware prefetchers or Load software prefetches that hit L2 cache.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.PF_MISS",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0x38ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Requests from the L1/L2/L3 hardware prefetchers or Load software prefetches that miss L2 cache",
                .full_desc =
                    "Counts requests from the L1/L2/L3 hardware prefetchers or Load software prefetches that miss L2 cache.",
                .default_sampling_period = 0x30D43ULL,
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
                .full_desc = "All L2 requests.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.RFO_HIT",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0xC2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "RFO requests that hit L2 cache",
                .full_desc =
                    "Counts the RFO (Read-for-Ownership) requests that hit L2 cache.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.RFO_MISS",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0x22ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "RFO requests that miss L2 cache",
                .full_desc =
                    "Counts the RFO (Read-for-Ownership) requests that miss L2 cache.",
                .default_sampling_period = 0x30D43ULL,
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
                .full_desc = "Counts L2 writebacks that access L2 cache.",
                .default_sampling_period = 0x30D43ULL,
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
                    "The number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use",
                .full_desc =
                    "The number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.",
                .default_sampling_period = 0x186A3ULL,
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
                    "False dependencies in MOB due to partial compare on address.",
                .full_desc =
                    "Counts false dependencies in MOB when the partial comparison upon loose net check and dependency was resolved by the Enhanced Loose net mechanism. This may not result in high performance penalties. Loose net checks can fail when loads and stores are 4k aliased.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Demand load dispatches that hit L1D fill buffer (FB) allocated for software prefetch.",
                .full_desc =
                    "Counts all not software-prefetch load dispatches that hit the fill buffer (FB) allocated for the software prefetch. It can also be incremented by some lock instructions. So it should only be used with profiling so that the locks can be excluded by ASM (Assembly File) inspection of the nearby instructions.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Core-originated cacheable demand requests that refer to L3",
                .full_desc =
                    "Counts core-originated cacheable requests to the  L3 cache (Longest Latency cache). Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches from L1 and L2.  It does not include all accesses to the L3.",
                .default_sampling_period = 0x186A3ULL,
                .errata = "SKL057",
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
                    "Cycles 4 Uops delivered by the LSD, but didn't come from the decoder. [This event is alias to LSD.CYCLES_OK]",
                .full_desc =
                    "Counts the cycles when 4 uops are delivered by the LSD (Loop-stream detector). [This event is alias to LSD.CYCLES_OK]",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the cycles when at least one uop is delivered by the LSD (Loop-stream detector).",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "LSD.CYCLES_OK",
                .encoding =
                    {
                        .code = 0xA8ULL,
                        .umask = 0x1ULL,
                        .cmask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles 4 Uops delivered by the LSD, but didn't come from the decoder. [This event is alias to LSD.CYCLES_4_UOPS]",
                .full_desc =
                    "Counts the cycles when 4 uops are delivered by the LSD (Loop-stream detector). [This event is alias to LSD.CYCLES_4_UOPS]",
                .default_sampling_period = 0x1E8483ULL,
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
                .full_desc =
                    "Number of uops delivered to the back-end by the LSD(Loop Stream Detector).",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the number of memory ordering Machine Clears detected. Memory Ordering Machine Clears can result from one of the following:a. memory disambiguation,b. external snoop, orc. cross SMT-HW-thread snoop (stores) hitting load buffer.",
                .default_sampling_period = 0x186A3ULL,
                .errata = "SKL089",
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
                    "Counts self-modifying code (SMC) detected, which causes a machine clear.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEMORY_DISAMBIGUATION.HISTORY_RESET",
                .encoding =
                    {
                        .code = 0x9ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "MEMORY_DISAMBIGUATION.HISTORY_RESET",
                .full_desc = "MEMORY_DISAMBIGUATION.HISTORY_RESET",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_INST_RETIRED.ALL_LOADS",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x81ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc = "Retired load instructions.",
                .full_desc =
                    "Counts all retired load instructions. This event accounts for SW prefetch instructions of PREFETCHNTA or PREFETCHT0/1/2 or PREFETCHW.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_INST_RETIRED.ALL_STORES",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x82ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                        .pebs = 1,
                    },
                .brief_desc = "Retired store instructions.",
                .full_desc = "Counts all retired store instructions.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_INST_RETIRED.ANY",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x83ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                        .pebs = 1,
                    },
                .brief_desc = "All retired memory instructions.",
                .full_desc =
                    "Counts all retired memory instructions - loads and stores.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_INST_RETIRED.LOCK_LOADS",
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
                .brief_desc = "Retired load instructions with locked access.",
                .full_desc = "Retired load instructions with locked access.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_INST_RETIRED.SPLIT_LOADS",
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
                    "Retired load instructions that split across a cacheline boundary.",
                .full_desc =
                    "Counts retired load instructions that split across a cacheline boundary.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_INST_RETIRED.SPLIT_STORES",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x42ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired store instructions that split across a cacheline boundary.",
                .full_desc =
                    "Counts retired store instructions that split across a cacheline boundary.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_INST_RETIRED.STLB_MISS_LOADS",
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
                .brief_desc = "Retired load instructions that miss the STLB.",
                .full_desc =
                    "Number of retired load instructions that (start a) miss in the 2nd-level TLB (STLB).",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_INST_RETIRED.STLB_MISS_STORES",
                .encoding =
                    {
                        .code = 0xD0ULL,
                        .umask = 0x12ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .l1_hit_indication = true,
                        .pebs = 1,
                    },
                .brief_desc = "Retired store instructions that miss the STLB.",
                .full_desc =
                    "Number of retired store instructions that (start a) miss in the 2nd-level TLB (STLB).",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_L3_HIT_RETIRED.XSNP_HIT",
                .encoding =
                    {
                        .code = 0xD2ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions which data sources were L3 and cross-core snoop hits in on-pkg core cache",
                .full_desc =
                    "Retired load instructions which data sources were L3 and cross-core snoop hits in on-pkg core cache.",
                .default_sampling_period = 0x4E2BULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_L3_HIT_RETIRED.XSNP_HITM",
                .encoding =
                    {
                        .code = 0xD2ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions which data sources were HitM responses from shared L3",
                .full_desc =
                    "Retired load instructions which data sources were HitM responses from shared L3.",
                .default_sampling_period = 0x4E2BULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_L3_HIT_RETIRED.XSNP_MISS",
                .encoding =
                    {
                        .code = 0xD2ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions which data sources were L3 hit and cross-core snoop missed in on-pkg core cache.",
                .full_desc =
                    "Retired load instructions which data sources were L3 hit and cross-core snoop missed in on-pkg core cache.",
                .default_sampling_period = 0x4E2BULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_L3_HIT_RETIRED.XSNP_NONE",
                .encoding =
                    {
                        .code = 0xD2ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions which data sources were hits in L3 without snoops required",
                .full_desc =
                    "Retired load instructions which data sources were hits in L3 without snoops required.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_L3_MISS_RETIRED.LOCAL_DRAM",
                .encoding =
                    {
                        .code = 0xD3ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions which data sources missed L3 but serviced from local dram",
                .full_desc =
                    "Retired load instructions which data sources missed L3 but serviced from local DRAM.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_L3_MISS_RETIRED.REMOTE_DRAM",
                .encoding =
                    {
                        .code = 0xD3ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions which data sources missed L3 but serviced from remote dram",
                .full_desc =
                    "Retired load instructions which data sources missed L3 but serviced from remote dram",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_L3_MISS_RETIRED.REMOTE_FWD",
                .encoding =
                    {
                        .code = 0xD3ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions whose data sources was forwarded from a remote cache",
                .full_desc =
                    "Retired load instructions whose data sources was forwarded from a remote cache.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_L3_MISS_RETIRED.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xD3ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions whose data sources was remote HITM",
                .full_desc =
                    "Retired load instructions whose data sources was remote HITM.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_MISC_RETIRED.UC",
                .encoding =
                    {
                        .code = 0xD4ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired instructions with at least 1 uncacheable load or lock.",
                .full_desc =
                    "Retired instructions with at least 1 uncacheable load or lock.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_RETIRED.FB_HIT",
                .encoding =
                    {
                        .code = 0xD1ULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions which data sources were load missed L1 but hit FB due to preceding miss to the same cache line with data not ready",
                .full_desc =
                    "Counts retired load instructions with at least one uop was load missed in L1 but hit FB (Fill Buffers) due to preceding miss to the same cache line with data not ready.",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_RETIRED.L1_HIT",
                .encoding =
                    {
                        .code = 0xD1ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions with L1 cache hits as data sources",
                .full_desc =
                    "Counts retired load instructions with at least one uop that hit in the L1 data cache. This event includes all SW prefetches and lock instructions regardless of the data source.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_RETIRED.L1_MISS",
                .encoding =
                    {
                        .code = 0xD1ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions missed L1 cache as data sources",
                .full_desc =
                    "Counts retired load instructions with at least one uop that missed in the L1 cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_RETIRED.L2_HIT",
                .encoding =
                    {
                        .code = 0xD1ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions with L2 cache hits as data sources",
                .full_desc =
                    "Retired load instructions with L2 cache hits as data sources.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_RETIRED.L2_MISS",
                .encoding =
                    {
                        .code = 0xD1ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions missed L2 cache as data sources",
                .full_desc =
                    "Retired load instructions missed L2 cache as data sources.",
                .default_sampling_period = 0xC365ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_RETIRED.L3_HIT",
                .encoding =
                    {
                        .code = 0xD1ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions with L3 cache hits as data sources",
                .full_desc =
                    "Counts retired load instructions with at least one uop that hit in the L3 cache.",
                .default_sampling_period = 0xC365ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "MEM_LOAD_RETIRED.L3_MISS",
                .encoding =
                    {
                        .code = 0xD1ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .data_la = true,
                        .pebs = 1,
                    },
                .brief_desc =
                    "Retired load instructions missed L3 cache as data sources",
                .full_desc =
                    "Counts retired load instructions with at least one uop that missed in the L3 cache.",
                .default_sampling_period = 0x186A7ULL,
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
                        .data_la = true,
                        .pebs = 2,
                    },
                .brief_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 128 cycles.",
                .full_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 128 cycles.  Reported latency may be longer than just the memory latency.",
                .default_sampling_period = 0x3F1ULL,
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
                        .data_la = true,
                        .pebs = 2,
                    },
                .brief_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 16 cycles.",
                .full_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 16 cycles.  Reported latency may be longer than just the memory latency.",
                .default_sampling_period = 0x4E2BULL,
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
                        .data_la = true,
                        .pebs = 2,
                    },
                .brief_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 256 cycles.",
                .full_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 256 cycles.  Reported latency may be longer than just the memory latency.",
                .default_sampling_period = 0x1F7ULL,
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
                        .data_la = true,
                        .pebs = 2,
                    },
                .brief_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 32 cycles.",
                .full_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 32 cycles.  Reported latency may be longer than just the memory latency.",
                .default_sampling_period = 0x186A7ULL,
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
                        .data_la = true,
                        .pebs = 2,
                    },
                .brief_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 4 cycles.",
                .full_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 4 cycles.  Reported latency may be longer than just the memory latency.",
                .default_sampling_period = 0x186A3ULL,
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
                        .data_la = true,
                        .pebs = 2,
                    },
                .brief_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 512 cycles.",
                .full_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 512 cycles.  Reported latency may be longer than just the memory latency.",
                .default_sampling_period = 0x65ULL,
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
                        .data_la = true,
                        .pebs = 2,
                    },
                .brief_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 64 cycles.",
                .full_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 64 cycles.  Reported latency may be longer than just the memory latency.",
                .default_sampling_period = 0x7D3ULL,
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
                        .data_la = true,
                        .pebs = 2,
                    },
                .brief_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 8 cycles.",
                .full_desc =
                    "Counts randomly selected loads when the latency from first dispatch to completion is greater than 8 cycles.  Reported latency may be longer than just the memory latency.",
                .default_sampling_period = 0xC365ULL,
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
                .full_desc =
                    "Counts the demand and prefetch data reads. All Core Data Reads include cacheable 'Demands' and L2 prefetchers (not L3 prefetchers). Counting also covers reads due to page walks resulted from any request type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_REQUESTS.ALL_REQUESTS",
                .encoding =
                    {
                        .code = 0xB0ULL,
                        .umask = 0x80ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Any memory transaction that reached the SQ.",
                .full_desc =
                    "Counts memory transactions reached the super queue including requests initiated by the core, all L3 prefetches, page walks, etc..",
                .default_sampling_period = 0x186A3ULL,
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
                .brief_desc = "Cacheable and non-cacheable code read requests",
                .full_desc =
                    "Counts both cacheable and non-cacheable code read requests.",
                .default_sampling_period = 0x186A3ULL,
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
                .full_desc =
                    "Counts the Demand Data Read requests sent to uncore. Use it in conjunction with OFFCORE_REQUESTS_OUTSTANDING to determine average latency in the uncore.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Demand RFO requests including regular RFOs, locks, ItoM",
                .full_desc =
                    "Counts the demand RFO (read for ownership) requests including regular RFOs, locks, ItoM.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_REQUESTS.L3_MISS_DEMAND_DATA_RD",
                .encoding =
                    {
                        .code = 0xB0ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Demand Data Read requests who miss L3 cache",
                .full_desc = "Demand Data Read requests who miss L3 cache.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Offcore requests buffer cannot take more entries for this thread core.",
                .full_desc =
                    "Counts the number of cases when the offcore requests buffer cannot take more entries for the core. This can happen when the superqueue does not contain eligible entries, or when L1D writeback pending FIFO requests is full.Note: Writeback pending FIFO has six entries.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Cycles with offcore outstanding Code Reads transactions in the SuperQueue (SQ), queue to uncore.",
                .full_desc =
                    "Counts the number of offcore outstanding Code Reads transactions in the super queue every cycle. The 'Offcore outstanding' state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts cycles when offcore outstanding Demand Data Read transactions are present in the super queue (SQ). A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation).",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Cycles with offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore.",
                .full_desc =
                    "Counts the number of offcore outstanding demand rfo Reads transactions in the super queue every cycle. The 'Offcore outstanding' state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_L3_MISS_DEMAND_DATA_RD",
                .encoding =
                    {
                        .code = 0x60ULL,
                        .umask = 0x10ULL,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles with at least 1 Demand Data Read requests who miss L3 cache in the superQ.",
                .full_desc =
                    "Cycles with at least 1 Demand Data Read requests who miss L3 cache in the superQ.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Offcore outstanding Code Reads transactions in the SuperQueue (SQ), queue to uncore, every cycle.",
                .full_desc =
                    "Counts the number of offcore outstanding Code Reads transactions in the super queue every cycle. The 'Offcore outstanding' state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts the number of offcore outstanding Demand Data Read transactions in the super queue (SQ) every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor. See the corresponding Umask under OFFCORE_REQUESTS.Note: A prefetch promoted to Demand is counted from the promotion point.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Cycles with at least 6 offcore outstanding Demand Data Read transactions in uncore queue.",
                .full_desc =
                    "Cycles with at least 6 offcore outstanding Demand Data Read transactions in uncore queue.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Offcore outstanding demand rfo reads transactions in SuperQueue (SQ), queue to uncore, every cycle",
                .full_desc =
                    "Counts the number of offcore outstanding RFO (store) transactions in the super queue (SQ) every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_REQUESTS_OUTSTANDING.L3_MISS_DEMAND_DATA_RD",
                .encoding =
                    {
                        .code = 0x60ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts number of Offcore outstanding Demand Data Read requests that miss L3 cache in the superQ every cycle.",
                .full_desc =
                    "Counts number of Offcore outstanding Demand Data Read requests that miss L3 cache in the superQ every cycle.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_REQUESTS_OUTSTANDING.L3_MISS_DEMAND_DATA_RD_GE_6",
                .encoding =
                    {
                        .code = 0x60ULL,
                        .umask = 0x10ULL,
                        .cmask = 0x6ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles with at least 6 Demand Data Read requests that miss L3 cache in the superQ.",
                .full_desc =
                    "Cycles with at least 6 Demand Data Read requests that miss L3 cache in the superQ.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_DATA_RD.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch data reads that have any response type.",
                .full_desc =
                    "Counts all demand & prefetch data reads that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch data reads that hit in the L3.",
                .full_desc =
                    "Counts all demand & prefetch data reads that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all demand & prefetch data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all demand & prefetch data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch data reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts all demand & prefetch data reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch data reads that miss in the L3.",
                .full_desc =
                    "Counts all demand & prefetch data reads that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch data reads that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts all demand & prefetch data reads that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch data reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts all demand & prefetch data reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch data reads that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts all demand & prefetch data reads that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch data reads that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts all demand & prefetch data reads that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800491ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch data reads that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts all demand & prefetch data reads that miss the L3 and the data is returned from remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch data reads that have any response type.",
                .full_desc =
                    "Counts all prefetch data reads that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch data reads that hit in the L3.",
                .full_desc =
                    "Counts all prefetch data reads that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all prefetch data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all prefetch data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch data reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts all prefetch data reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch data reads that miss in the L3.",
                .full_desc =
                    "Counts all prefetch data reads that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch data reads that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts all prefetch data reads that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch data reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts all prefetch data reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch data reads that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts all prefetch data reads that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch data reads that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts all prefetch data reads that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800490ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch data reads that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts all prefetch data reads that miss the L3 and the data is returned from remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_RFO.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch RFOs that have any response type.",
                .full_desc =
                    "Counts prefetch RFOs that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts prefetch RFOs that hit in the L3.",
                .full_desc = "Counts prefetch RFOs that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts prefetch RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts prefetch RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch RFOs that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts prefetch RFOs that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts prefetch RFOs that miss in the L3.",
                .full_desc = "Counts prefetch RFOs that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch RFOs that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts prefetch RFOs that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch RFOs that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts prefetch RFOs that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch RFOs that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts prefetch RFOs that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch RFOs that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts prefetch RFOs that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800120ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch RFOs that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts prefetch RFOs that miss the L3 and the data is returned from remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_READS.L3_HIT.HIT_OTHER_CORE_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C07F7ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.ALL_READS.L3_HIT.HIT_OTHER_CORE_FWD hit in the L3 and the snoop to one of the sibling cores hits the line in E/S/F state and the line is forwarded.",
                .full_desc =
                    "OFFCORE_RESPONSE.ALL_READS.L3_HIT.HIT_OTHER_CORE_FWD hit in the L3 and the snoop to one of the sibling cores hits the line in E/S/F state and the line is forwarded.",
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
                .brief_desc =
                    "Counts all demand & prefetch RFOs that have any response type.",
                .full_desc =
                    "Counts all demand & prefetch RFOs that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0122ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch RFOs that hit in the L3.",
                .full_desc =
                    "Counts all demand & prefetch RFOs that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0122ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all demand & prefetch RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0122ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all demand & prefetch RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0122ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch RFOs that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts all demand & prefetch RFOs that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0122ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000122ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch RFOs that miss in the L3.",
                .full_desc =
                    "Counts all demand & prefetch RFOs that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00122ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch RFOs that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts all demand & prefetch RFOs that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00122ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch RFOs that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts all demand & prefetch RFOs that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00122ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch RFOs that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts all demand & prefetch RFOs that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000122ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch RFOs that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts all demand & prefetch RFOs that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.ALL_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800122ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand & prefetch RFOs that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts all demand & prefetch RFOs that miss the L3 and the data is returned from remote dram.",
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
                .brief_desc =
                    "Counts all demand code reads that have any response type.",
                .full_desc =
                    "Counts all demand code reads that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand code reads that hit in the L3.",
                .full_desc = "Counts all demand code reads that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand code reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all demand code reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand code reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all demand code reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand code reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts all demand code reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand code reads that miss in the L3.",
                .full_desc =
                    "Counts all demand code reads that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand code reads that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts all demand code reads that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand code reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts all demand code reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand code reads that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts all demand code reads that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand code reads that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts all demand code reads that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800004ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand code reads that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts all demand code reads that miss the L3 and the data is returned from remote dram.",
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
                .brief_desc =
                    "Counts demand data reads that have any response type.",
                .full_desc =
                    "Counts demand data reads that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts demand data reads that hit in the L3.",
                .full_desc = "Counts demand data reads that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts demand data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts demand data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts demand data reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts demand data reads that miss in the L3.",
                .full_desc = "Counts demand data reads that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts demand data reads that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts demand data reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts demand data reads that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts demand data reads that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800001ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts demand data reads that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts demand data reads that miss the L3 and the data is returned from remote dram.",
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
                .brief_desc =
                    "Counts all demand data writes (RFOs) that have any response type.",
                .full_desc =
                    "Counts all demand data writes (RFOs) that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand data writes (RFOs) that hit in the L3.",
                .full_desc =
                    "Counts all demand data writes (RFOs) that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand data writes (RFOs) that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all demand data writes (RFOs) that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand data writes (RFOs) that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all demand data writes (RFOs) that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand data writes (RFOs) that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts all demand data writes (RFOs) that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand data writes (RFOs) that miss in the L3.",
                .full_desc =
                    "Counts all demand data writes (RFOs) that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand data writes (RFOs) that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts all demand data writes (RFOs) that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand data writes (RFOs) that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts all demand data writes (RFOs) that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_RFO.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand data writes (RFOs) that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts all demand data writes (RFOs) that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand data writes (RFOs) that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts all demand data writes (RFOs) that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.DEMAND_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800002ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all demand data writes (RFOs) that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts all demand data writes (RFOs) that miss the L3 and the data is returned from remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1D_AND_SW.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that have any response type.",
                .full_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that hit in the L3.",
                .full_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss in the L3.",
                .full_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L1D_AND_SW.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800400ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts L1 data cache hardware prefetch requests and software prefetch requests that miss the L3 and the data is returned from remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch (that bring data to L2) data reads that have any response type.",
                .full_desc =
                    "Counts prefetch (that bring data to L2) data reads that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch (that bring data to L2) data reads that hit in the L3.",
                .full_desc =
                    "Counts prefetch (that bring data to L2) data reads that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch (that bring data to L2) data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc = "Counts prefetch (that bring data to L2) data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch (that bring data to L2) data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts prefetch (that bring data to L2) data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch (that bring data to L2) data reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts prefetch (that bring data to L2) data reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss in the L3.",
                .full_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800010ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts prefetch (that bring data to L2) data reads that miss the L3 and the data is returned from remote dram.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Counts all prefetch (that bring data to L2) RFOs that have any response type.",
                .full_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that hit in the L3.",
                .full_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss in the L3.",
                .full_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800020ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts all prefetch (that bring data to L2) RFOs that miss the L3 and the data is returned from remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that have any response type.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that hit in the L3.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss in the L3.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800080ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) data reads that miss the L3 and the data is returned from remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_RFO.ANY_RESPONSE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that have any response type.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that have any response type.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3F803C0100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that hit in the L3.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that hit in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.HITM_OTHER_CORE",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x10003C0100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.HIT_OTHER_CORE_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x4003C0100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that hit in the L3 and the snoop to one of the sibling cores hits the line in M state and the line is forwarded.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.NO_SNOOP_NEEDED",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x1003C0100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that hit in the L3 and sibling core snoops are not needed as either the core-valid bit is not set or the shared line is present in multiple cores.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x8003C0100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .full_desc =
                    "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS.ANY_SNOOP",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x3FBC000100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss in the L3.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss in the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS.REMOTE_HITM",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x103FC00100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss the L3 and the modified data is transferred from remote cache.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss the L3 and the modified data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS.REMOTE_HIT_FORWARD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x83FC00100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss the L3 and clean or shared data is transferred from remote cache.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss the L3 and clean or shared data is transferred from remote cache.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63FC00100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss the L3 and the data is returned from local or remote dram.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss the L3 and the data is returned from local or remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x604000100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss the L3 and the data is returned from local dram.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss the L3 and the data is returned from local dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id =
                    "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS_REMOTE_DRAM.SNOOP_MISS_OR_NO_FWD",
                .encoding =
                    {
                        .code = 0xB7ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x63B800100ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss the L3 and the data is returned from remote dram.",
                .full_desc =
                    "Counts all prefetch (that bring data to LLC only) RFOs that miss the L3 and the data is returned from remote dram.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OTHER_ASSISTS.ANY",
                .encoding =
                    {
                        .code = 0xC1ULL,
                        .umask = 0x3FULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times a microcode assist is invoked by HW other than FP-assist. Examples include AD (page Access Dirty) and AVX* related assists.",
                .full_desc =
                    "Number of times a microcode assist is invoked by HW other than FP-assist. Examples include AD (page Access Dirty) and AVX* related assists.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "PARTIAL_RAT_STALLS.SCOREBOARD",
                .encoding =
                    {
                        .code = 0x59ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles where the pipeline is stalled due to serializing operations.",
                .full_desc =
                    "This event counts cycles during which the microcode scoreboard stalls happen.",
                .default_sampling_period = 0x1E8483ULL,
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
                .full_desc = "Counts resource-related stall cycles.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts allocation stall cycles caused by the store buffer (SB) being full. This counts cycles that the pipeline back-end blocked uop delivery from the front-end.",
                .default_sampling_period = 0x1E8483ULL,
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
                .brief_desc =
                    "Increments whenever there is an update to the LBR array.",
                .full_desc =
                    "Increments when an entry is added to the Last Branch Record (LBR) array (or removed from the array in case of RETURNs in call stack mode). The event requires LBR enable via IA32_DEBUGCTL MSR and branch type selection via MSR_LBR_SELECT.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "ROB_MISC_EVENTS.PAUSE_INST",
                .encoding =
                    {
                        .code = 0xCCULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of retired PAUSE instructions (that do not end up with a VMExit to the VMM; TSX aborted Instructions may be counted). This event is not supported on first SKL and KBL products.",
                .full_desc =
                    "Number of retired PAUSE instructions (that do not end up with a VMExit to the VMM; TSX aborted Instructions may be counted). This event is not supported on first SKL and KBL products.",
                .default_sampling_period = 0x1E8483ULL,
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
                .full_desc =
                    "Counts cycles during which the reservation station (RS) is empty for the thread.; Note: In ST-mode, not active thread should drive 0. This is usually caused by severely costly branch mispredictions, or allocator/FE issues.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts end of periods where the Reservation Station (RS) was empty. Could be useful to precisely locate front-end Latency Bound issues.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RTM_RETIRED.ABORTED",
                .encoding =
                    {
                        .code = 0xC9ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features =
                    StaticEventDef::IntelFeatures{
                        .pebs = 2,
                    },
                .brief_desc =
                    "Number of times an RTM execution aborted due to any reasons (multiple categories may count as one).",
                .full_desc = "Number of times RTM abort was triggered.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RTM_RETIRED.ABORTED_EVENTS",
                .encoding =
                    {
                        .code = 0xC9ULL,
                        .umask = 0x80ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an RTM execution aborted due to none of the previous 4 categories (e.g. interrupt)",
                .full_desc =
                    "Number of times an RTM execution aborted due to none of the previous 4 categories (e.g. interrupt).",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RTM_RETIRED.ABORTED_MEM",
                .encoding =
                    {
                        .code = 0xC9ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an RTM execution aborted due to various memory events (e.g. read/write capacity and conflicts)",
                .full_desc =
                    "Number of times an RTM execution aborted due to various memory events (e.g. read/write capacity and conflicts).",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RTM_RETIRED.ABORTED_MEMTYPE",
                .encoding =
                    {
                        .code = 0xC9ULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an RTM execution aborted due to incompatible memory type",
                .full_desc =
                    "Number of times an RTM execution aborted due to incompatible memory type.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RTM_RETIRED.ABORTED_TIMER",
                .encoding =
                    {
                        .code = 0xC9ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an RTM execution aborted due to uncommon conditions.",
                .full_desc =
                    "Number of times an RTM execution aborted due to uncommon conditions.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RTM_RETIRED.ABORTED_UNFRIENDLY",
                .encoding =
                    {
                        .code = 0xC9ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an RTM execution aborted due to HLE-unfriendly instructions",
                .full_desc =
                    "Number of times an RTM execution aborted due to HLE-unfriendly instructions.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RTM_RETIRED.COMMIT",
                .encoding =
                    {
                        .code = 0xC9ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an RTM execution successfully committed",
                .full_desc = "Number of times RTM commit succeeded.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "RTM_RETIRED.START",
                .encoding =
                    {
                        .code = 0xC9ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Number of times an RTM execution started.",
                .full_desc =
                    "Number of times we entered an RTM region. Does not count nested transactions.",
                .default_sampling_period = 0x1E8483ULL,
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
                .brief_desc =
                    "Number of cache line split locks sent to uncore.",
                .full_desc =
                    "Counts the number of cache line split locks sent to the uncore.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "SW_PREFETCH_ACCESS.ANY",
                .encoding =
                    {
                        .code = 0x32ULL,
                        .umask = 0xFULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of PREFETCHNTA, PREFETCHW, PREFETCHT0, PREFETCHT1 or PREFETCHT2 instructions executed.",
                .full_desc =
                    "Counts the number of PREFETCHNTA, PREFETCHW, PREFETCHT0, PREFETCHT1 or PREFETCHT2 instructions executed.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "SW_PREFETCH_ACCESS.NTA",
                .encoding =
                    {
                        .code = 0x32ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Number of PREFETCHNTA instructions executed.",
                .full_desc = "Number of PREFETCHNTA instructions executed.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "SW_PREFETCH_ACCESS.PREFETCHW",
                .encoding =
                    {
                        .code = 0x32ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Number of PREFETCHW instructions executed.",
                .full_desc = "Number of PREFETCHW instructions executed.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "SW_PREFETCH_ACCESS.T0",
                .encoding =
                    {
                        .code = 0x32ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Number of PREFETCHT0 instructions executed.",
                .full_desc = "Number of PREFETCHT0 instructions executed.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "SW_PREFETCH_ACCESS.T1_T2",
                .encoding =
                    {
                        .code = 0x32ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of PREFETCHT1 or PREFETCHT2 instructions executed.",
                .full_desc =
                    "Number of PREFETCHT1 or PREFETCHT2 instructions executed.",
                .default_sampling_period = 0x1E8483ULL,
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
                .brief_desc =
                    "DTLB flush attempts of the thread-specific entries",
                .full_desc =
                    "Counts the number of DTLB flush attempts of the thread-specific entries.",
                .default_sampling_period = 0x186A7ULL,
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
                .full_desc =
                    "Counts the number of any STLB flush attempts (such as entire, VPID, PCID, InvPage, CR3 write, etc.).",
                .default_sampling_period = 0x186A7ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_EXEC.MISC1",
                .encoding =
                    {
                        .code = 0x5DULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of times a class of instructions that may cause a transactional abort was executed. Since this is the count of execution, it may not always cause a transactional abort.",
                .full_desc =
                    "Counts the number of times a class of instructions that may cause a transactional abort was executed. Since this is the count of execution, it may not always cause a transactional abort.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_EXEC.MISC2",
                .encoding =
                    {
                        .code = 0x5DULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of times a class of instructions (e.g., vzeroupper) that may cause a transactional abort was executed inside a transactional region",
                .full_desc =
                    "Unfriendly TSX abort triggered by a vzeroupper instruction.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_EXEC.MISC3",
                .encoding =
                    {
                        .code = 0x5DULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of times an instruction execution caused the transactional nest count supported to be exceeded",
                .full_desc =
                    "Unfriendly TSX abort triggered by a nest count that is too deep.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_EXEC.MISC4",
                .encoding =
                    {
                        .code = 0x5DULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of times a XBEGIN instruction was executed inside an HLE transactional region.",
                .full_desc = "RTM region detected inside HLE.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_EXEC.MISC5",
                .encoding =
                    {
                        .code = 0x5DULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of times an HLE XACQUIRE instruction was executed inside an RTM transactional region",
                .full_desc =
                    "Counts the number of times an HLE XACQUIRE instruction was executed inside an RTM transactional region.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_MEM.ABORT_CAPACITY",
                .encoding =
                    {
                        .code = 0x54ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times a transactional abort was signaled due to a data capacity limitation for transactional reads or writes.",
                .full_desc =
                    "Number of times a transactional abort was signaled due to a data capacity limitation for transactional reads or writes.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_MEM.ABORT_CONFLICT",
                .encoding =
                    {
                        .code = 0x54ULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times a transactional abort was signaled due to a data conflict on a transactionally accessed address",
                .full_desc = "Number of times a TSX line had a cache conflict.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_MEM.ABORT_HLE_ELISION_BUFFER_MISMATCH",
                .encoding =
                    {
                        .code = 0x54ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an HLE transactional execution aborted due to XRELEASE lock not satisfying the address and value requirements in the elision buffer",
                .full_desc =
                    "Number of times a TSX Abort was triggered due to release/commit but data and address mismatch.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_MEM.ABORT_HLE_ELISION_BUFFER_NOT_EMPTY",
                .encoding =
                    {
                        .code = 0x54ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an HLE transactional execution aborted due to NoAllocatedElisionBuffer being non-zero.",
                .full_desc =
                    "Number of times a TSX Abort was triggered due to commit but Lock Buffer not empty.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_MEM.ABORT_HLE_ELISION_BUFFER_UNSUPPORTED_ALIGNMENT",
                .encoding =
                    {
                        .code = 0x54ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times an HLE transactional execution aborted due to an unsupported read alignment from the elision buffer.",
                .full_desc =
                    "Number of times a TSX Abort was triggered due to attempting an unsupported alignment from Lock Buffer.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_MEM.ABORT_HLE_STORE_TO_ELIDED_LOCK",
                .encoding =
                    {
                        .code = 0x54ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times a HLE transactional region aborted due to a non XRELEASE prefixed instruction writing to an elided lock in the elision buffer",
                .full_desc =
                    "Number of times a TSX Abort was triggered due to a non-release/commit store to lock.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TX_MEM.HLE_ELISION_BUFFER_FULL",
                .encoding =
                    {
                        .code = 0x54ULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of times HLE lock could not be elided due to ElisionBufferAvailable being zero.",
                .full_desc =
                    "Number of times we could not allocate Lock Buffer.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Cycles per thread when uops are executed in port 0",
                .full_desc =
                    "Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 0.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Cycles per thread when uops are executed in port 1",
                .full_desc =
                    "Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 1.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_DISPATCHED_PORT.PORT_2",
                .encoding =
                    {
                        .code = 0xA1ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles per thread when uops are executed in port 2",
                .full_desc =
                    "Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 2.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_DISPATCHED_PORT.PORT_3",
                .encoding =
                    {
                        .code = 0xA1ULL,
                        .umask = 0x8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles per thread when uops are executed in port 3",
                .full_desc =
                    "Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 3.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_DISPATCHED_PORT.PORT_4",
                .encoding =
                    {
                        .code = 0xA1ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles per thread when uops are executed in port 4",
                .full_desc =
                    "Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 4.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_DISPATCHED_PORT.PORT_5",
                .encoding =
                    {
                        .code = 0xA1ULL,
                        .umask = 0x20ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles per thread when uops are executed in port 5",
                .full_desc =
                    "Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 5.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_DISPATCHED_PORT.PORT_6",
                .encoding =
                    {
                        .code = 0xA1ULL,
                        .umask = 0x40ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles per thread when uops are executed in port 6",
                .full_desc =
                    "Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 6.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_DISPATCHED_PORT.PORT_7",
                .encoding =
                    {
                        .code = 0xA1ULL,
                        .umask = 0x80ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles per thread when uops are executed in port 7",
                .full_desc =
                    "Counts, on the per-thread basis, cycles during which at least one uop is dispatched from the Reservation Station (RS) to port 7.",
                .default_sampling_period = 0x1E8483ULL,
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
                .full_desc = "Number of uops executed from any thread.",
                .default_sampling_period = 0x1E8483ULL,
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
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_EXECUTED.CORE_CYCLES_NONE",
                .encoding =
                    {
                        .code = 0xB1ULL,
                        .umask = 0x2ULL,
                        .inv = true,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Cycles with no micro-ops executed from any thread on physical core.",
                .full_desc =
                    "Cycles with no micro-ops executed from any thread on physical core.",
                .default_sampling_period = 0x1E8483ULL,
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
                .brief_desc =
                    "Cycles where at least 1 uop was executed per-thread",
                .full_desc =
                    "Cycles where at least 1 uop was executed per-thread.",
                .default_sampling_period = 0x1E8483ULL,
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
                .brief_desc =
                    "Cycles where at least 2 uops were executed per-thread",
                .full_desc =
                    "Cycles where at least 2 uops were executed per-thread.",
                .default_sampling_period = 0x1E8483ULL,
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
                .brief_desc =
                    "Cycles where at least 3 uops were executed per-thread",
                .full_desc =
                    "Cycles where at least 3 uops were executed per-thread.",
                .default_sampling_period = 0x1E8483ULL,
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
                .brief_desc =
                    "Cycles where at least 4 uops were executed per-thread",
                .full_desc =
                    "Cycles where at least 4 uops were executed per-thread.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts cycles during which no uops were dispatched from the Reservation Station (RS) per thread.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Number of uops to be executed per-thread each cycle.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_EXECUTED.X87",
                .encoding =
                    {
                        .code = 0xB1ULL,
                        .umask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Counts the number of x87 uops dispatched.",
                .full_desc = "Counts the number of x87 uops executed.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Number of slow LEA uops being allocated. A uop is generally considered SlowLea if it has 3 sources (e.g. 2 sources + immediate) regardless if as a result of LEA instruction or not.",
                .default_sampling_period = 0x1E8483ULL,
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
                    "Counts cycles during which the Resource Allocation Table (RAT) does not issue any Uops to the reservation station (RS) for the current thread.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_ISSUED.VECTOR_WIDTH_MISMATCH",
                .encoding =
                    {
                        .code = 0xEULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Uops inserted at issue-stage in order to preserve upper bits of vector registers.",
                .full_desc =
                    "Counts the number of Blend Uops issued by the Resource Allocation Table (RAT) to the reservation station (RS) in order to preserve upper bits of vector registers. Starting with the Skylake microarchitecture, these Blend uops are needed since every Intel SSE instruction executed in Dirty Upper State needs to preserve bits 128-255 of the destination register. For more information, refer to Mixing Intel AVX and Intel SSE Code section of the Optimization Guide.",
                .default_sampling_period = 0x1E8483ULL,
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Number of macro-fused uops retired. (non precise)",
                .full_desc =
                    "Counts the number of macro-fused uops retired. (non precise)",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_RETIRED.STALL_CYCLES",
                .encoding =
                    {
                        .code = 0xC2ULL,
                        .umask = 0x2ULL,
                        .inv = true,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Cycles without actually retired uops.",
                .full_desc =
                    "This event counts cycles without actually retired uops.",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_RETIRED.TOTAL_CYCLES",
                .encoding =
                    {
                        .code = 0xC2ULL,
                        .umask = 0x2ULL,
                        .inv = true,
                        .cmask = 0x10ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Cycles with less than 10 actually retired uops.",
                .full_desc =
                    "Number of cycles using always true condition (uops_ret < 16) applied to non PEBS uops retired event.",
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

} // namespace skylakex_core
} // namespace facebook::hbt::perf_event::generated
