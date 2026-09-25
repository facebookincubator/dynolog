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
namespace sapphirerapids_core {
namespace {

/*
  Events from sapphirerapids_core.json (396 events).

  Supported SKUs:
      - Arch: x86, Model: SPR id: 143
*/
constexpr std::array<StaticEventDef, 37>
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
                .brief_desc = "All branch instructions retired.",
                .full_desc = "Counts all branch instructions retired.",
                .default_sampling_period = 0x61A89ULL,
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
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Taken branch instructions retired.",
                .full_desc = "Counts taken branch instructions retired.",
                .default_sampling_period = 0x61A89ULL,
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
                .brief_desc = "All mispredicted branch instructions retired.",
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
                    "Counts the number of reference cycles when the core is not in a halt state. The core enters the halt state when it is running the HLT instruction or the MWAIT instruction. This event is not affected by core frequency changes (for example, P states, TM2 transitions) but has the same incrementing frequency as the time stamp counter. This event can approximate elapsed time while the core was not in a halt state. It is counted on a dedicated fixed counter, leaving the eight programmable counters available for other events. Note: On all current platforms this event stops counting during 'throttling (TM)' states duty off periods the processor is 'halted'.  The counter update is done at a lower clock rate then the core clock the overflow status bit for this counter may appear 'sticky'.  After the counter has overflowed and software clears the overflow status bit and resets the counter to less than MAX. The reset value to the counter is not clocked immediately so the overflow status bit will flip 'high (1)' and generate another PMI (if enabled) after which the reset value gets clocked into the counter. Therefore, software will get the interrupt, read the overflow status bit '1 for bit 34 while the counter value is less than MAX. Software should ignore this case.",
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
                    "Counts the number of core cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. This event is a component in many key event ratios. The core frequency may change from time to time due to transitions associated with Enhanced Intel SpeedStep Technology or TM2. For this reason this event may have a changing ratio with regards to time. When the core frequency is constant, this event can approximate elapsed time while the core was not in the halt state. It is counted on a dedicated fixed counter, leaving the eight programmable counters available for other events.",
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
                .brief_desc = "Thread cycles when thread is not in halt state",
                .full_desc =
                    "This is an architectural event that counts the number of thread cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. The core frequency may change from time to time due to power or thermal throttling. For this reason, this event may have a changing ratio with regards to wall clock time.",
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
                .default_sampling_period = 0xF4243ULL,
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
                .default_sampling_period = 0xF4243ULL,
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
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "DTLB_LOAD_MISSES.WALK_COMPLETED",
                .encoding =
                    {
                        .code = 0x12ULL,
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
                        .code = 0x13ULL,
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
                    "Counts number of SSE/AVX computational 128-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
                .full_desc =
                    "Number of SSE/AVX computational 128-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Number of SSE/AVX computational 128-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB MUL DIV MIN MAX RCP14 RSQRT14 SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
                .full_desc =
                    "Number of SSE/AVX computational 128-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Counts number of SSE/AVX computational 256-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
                .full_desc =
                    "Number of SSE/AVX computational 256-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Counts number of SSE/AVX computational 256-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
                .full_desc =
                    "Number of SSE/AVX computational 256-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                .default_sampling_period = 0x186A3ULL,
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
                .default_sampling_period = 0x186A3ULL,
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
                .default_sampling_period = 0x186A3ULL,
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
                    "Counts number of SSE/AVX computational scalar double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
                .full_desc =
                    "Number of SSE/AVX computational scalar double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Counts number of SSE/AVX computational scalar single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
                .full_desc =
                    "Number of SSE/AVX computational scalar single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
                .default_sampling_period = 0x186A3ULL,
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
                    "Uops not delivered by IDQ when backend of the machine is not stalled [This event is alias to IDQ_BUBBLES.CORE]",
                .full_desc =
                    "Counts the number of uops not delivered to by the Instruction Decode Queue (IDQ) to the back-end of the pipeline when there was no back-end stalls. This event counts for one SMT thread in a given cycle. [This event is alias to IDQ_BUBBLES.CORE]",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "INT_MISC.RECOVERY_CYCLES",
                .encoding =
                    {
                        .code = 0xADULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Core cycles the allocator was stalled due to recovery from earlier clear event for this thread",
                .full_desc =
                    "Counts core cycles when the Resource allocator was stalled due to recovery from an earlier branch misprediction or machine clear event.",
                .default_sampling_period = 0x7A129ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "ITLB_MISSES.WALK_COMPLETED",
                .encoding =
                    {
                        .code = 0x11ULL,
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
                .brief_desc =
                    "Counts the number of cache lines replaced in L1 data cache.",
                .full_desc =
                    "Counts L1D data line replacements including opportunistic replacements, and replacements that require stall-for-replace or block-for-replace.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_LINES_IN.ALL",
                .encoding =
                    {
                        .code = 0x25ULL,
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
                .brief_desc =
                    "Read requests with true-miss in L2 cache. [This event is alias to L2_REQUEST.MISS]",
                .full_desc =
                    "Counts read requests of any type with true-miss in the L2 cache. True-miss excludes L2 misses that were merged with ongoing L2 misses. [This event is alias to L2_REQUEST.MISS]",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.SWPF_HIT",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0xC8ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "SW prefetch requests that hit L2 cache.",
                .full_desc =
                    "Counts Software prefetch requests that hit the L2 cache. Accounts for PREFETCHNTA and PREFETCHT0/1/2 instructions when FB is not full.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "L2_RQSTS.SWPF_MISS",
                .encoding =
                    {
                        .code = 0x24ULL,
                        .umask = 0x28ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "SW prefetch requests that miss L2 cache.",
                .full_desc =
                    "Counts Software prefetch requests that miss the L2 cache. Accounts for PREFETCHNTA and PREFETCHT0/1/2 instructions when FB is not full.",
                .default_sampling_period = 0x30D43ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "LD_BLOCKS.STORE_FORWARD",
                .encoding =
                    {
                        .code = 0x3ULL,
                        .umask = 0x82ULL,
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
                    "Core-originated cacheable requests that missed L3  (Except hardware prefetches to the L3)",
                .full_desc =
                    "Counts core-originated cacheable requests that miss the L3 cache (Longest Latency cache). Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches to the L1 and L2.  It does not include hardware prefetches to the L3, and may not count other types of requests to the L3.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DATA_RD",
                .encoding =
                    {
                        .code = 0x20ULL,
                        .umask = 0x8ULL,
                        .cmask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DATA_RD",
                .full_desc = "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DATA_RD",
                .default_sampling_period = 0xF4243ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "SW_PREFETCH_ACCESS.ANY",
                .encoding =
                    {
                        .code = 0x40ULL,
                        .umask = 0xFULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "Counts the number of PREFETCHNTA, PREFETCHW, PREFETCHT0, PREFETCHT1 or PREFETCHT2 instructions executed.",
                .full_desc =
                    "Counts the number of PREFETCHNTA, PREFETCHW, PREFETCHT0, PREFETCHT1 or PREFETCHT2 instructions executed.",
                .default_sampling_period = 0x186A3ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN.BACKEND_BOUND_SLOTS",
                .encoding =
                    {
                        .code = 0xA4ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TMA slots where no uops were being issued due to lack of back-end resources.",
                .full_desc =
                    "Number of slots in TMA method where no micro-operations were being issued from front-end to back-end of the machine due to lack of back-end resources.",
                .default_sampling_period = 0x989683ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN.BAD_SPEC_SLOTS",
                .encoding =
                    {
                        .code = 0xA4ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "TMA slots wasted due to incorrect speculations.",
                .full_desc =
                    "Number of slots of TMA method that were wasted due to incorrect speculation. It covers all types of control-flow or data-related mis-speculations.",
                .default_sampling_period = 0x989683ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "TOPDOWN.SLOTS",
                .encoding =
                    {
                        .code = 0x0ULL,
                        .umask = 0x4ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc =
                    "TMA slots available for an unhalted logical processor. Fixed counter - architectural event",
                .full_desc =
                    "Number of available slots for an unhalted logical processor. The event increments by machine-width of the narrowest pipeline as employed by the Top-down Microarchitecture Analysis method (TMA). The count is distributed among unhalted logical processors (hyper-threads) who share the same physical core. Software can use this event as the denominator for the top-level metrics of the TMA method. This architectural event is counted on a designated fixed counter (Fixed Counter 3).",
                .default_sampling_period = 0x989683ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_ISSUED.ANY",
                .encoding =
                    {
                        .code = 0xAEULL,
                        .umask = 0x1ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Uops that RAT issues to RS",
                .full_desc =
                    "Counts the number of uops that the Resource Allocation Table (RAT) issues to the Reservation Station (RS).",
                .default_sampling_period = 0x1E8483ULL,
            },
            {
                .pmu_type = PmuType::cpu,
                .id = "UOPS_RETIRED.SLOTS",
                .encoding =
                    {
                        .code = 0xC2ULL,
                        .umask = 0x2ULL,
                        .msr_values = uint64_t{0x0ULL},
                    },
                .features = StaticEventDef::IntelFeatures{},
                .brief_desc = "Retirement slots used.",
                .full_desc = "Counts the retirement slots used each cycle.",
                .default_sampling_period = 0x1E8483ULL,
            },
        }};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 350> kFullOnlyEvents{
    {
        {
            .pmu_type = PmuType::cpu,
            .id = "ARITH.DIV_ACTIVE",
            .encoding =
                {
                    .code = 0xB0ULL,
                    .umask = 0x9ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when divide unit is busy executing divide or square root operations.",
            .full_desc =
                "Counts cycles when divide unit is busy executing divide or square root operations. Accounts for integer and floating-point operations.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ARITH.FPDIV_ACTIVE",
            .encoding =
                {
                    .code = 0xB0ULL,
                    .umask = 0x1ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "ARITH.FPDIV_ACTIVE",
            .full_desc = "ARITH.FPDIV_ACTIVE",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ARITH.IDIV_ACTIVE",
            .encoding =
                {
                    .code = 0xB0ULL,
                    .umask = 0x8ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "This event counts the cycles the integer divider is busy.",
            .full_desc =
                "This event counts the cycles the integer divider is busy.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ASSISTS.ANY",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x1BULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of occurrences where a microcode assist is invoked by hardware.",
            .full_desc =
                "Counts the number of occurrences where a microcode assist is invoked by hardware. Examples include AD (page Access Dirty), FP and AVX related assists.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ASSISTS.FP",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all microcode FP assists.",
            .full_desc = "Counts all microcode Floating Point assists.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ASSISTS.PAGE_FAULT",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "ASSISTS.PAGE_FAULT",
            .full_desc = "ASSISTS.PAGE_FAULT",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ASSISTS.SSE_AVX_MIX",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "ASSISTS.SSE_AVX_MIX",
            .full_desc = "ASSISTS.SSE_AVX_MIX",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BACLEARS.ANY",
            .encoding =
                {
                    .code = 0x60ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Clears due to Unknown Branches.",
            .full_desc =
                "Number of times the front-end is resteered when it finds a branch instruction in a fetch line. This is called Unknown Branch which occurs for the first time a branch instruction is fetched or when the branch is not tracked by the BPU (Branch Prediction Unit) anymore.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_INST_RETIRED.COND",
            .encoding =
                {
                    .code = 0xC4ULL,
                    .umask = 0x11ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Conditional branch instructions retired.",
            .full_desc = "Counts conditional branch instructions retired.",
            .default_sampling_period = 0x61A89ULL,
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
            .full_desc = "Counts not taken branch instructions retired.",
            .default_sampling_period = 0x61A89ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_INST_RETIRED.COND_TAKEN",
            .encoding =
                {
                    .code = 0xC4ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Taken conditional branch instructions retired.",
            .full_desc =
                "Counts taken conditional branch instructions retired.",
            .default_sampling_period = 0x61A89ULL,
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
            .full_desc = "Counts far branch instructions retired.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_INST_RETIRED.INDIRECT",
            .encoding =
                {
                    .code = 0xC4ULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Indirect near branch instructions retired (excluding returns)",
            .full_desc =
                "Counts near indirect branch instructions retired excluding returns. TSX abort is an indirect branch.",
            .default_sampling_period = 0x186A3ULL,
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
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Direct and indirect near call instructions retired.",
            .full_desc =
                "Counts both direct and indirect near call instructions retired.",
            .default_sampling_period = 0x186A7ULL,
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
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Return instructions retired.",
            .full_desc = "Counts return instructions retired.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_MISP_RETIRED.COND",
            .encoding =
                {
                    .code = 0xC5ULL,
                    .umask = 0x11ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Mispredicted conditional branch instructions retired.",
            .full_desc =
                "Counts mispredicted conditional branch instructions retired.",
            .default_sampling_period = 0x61A89ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_MISP_RETIRED.COND_NTAKEN",
            .encoding =
                {
                    .code = 0xC5ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Mispredicted non-taken conditional branch instructions retired.",
            .full_desc =
                "Counts the number of conditional branch instructions retired that were mispredicted and the branch direction was not taken.",
            .default_sampling_period = 0x61A89ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_MISP_RETIRED.COND_TAKEN",
            .encoding =
                {
                    .code = 0xC5ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "number of branch instructions retired that were mispredicted and taken.",
            .full_desc =
                "Counts taken conditional mispredicted branch instructions retired.",
            .default_sampling_period = 0x61A89ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_MISP_RETIRED.INDIRECT",
            .encoding =
                {
                    .code = 0xC5ULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Miss-predicted near indirect branch instructions retired (excluding returns)",
            .full_desc =
                "Counts miss-predicted near indirect branch instructions retired excluding returns. TSX abort is an indirect branch.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "BR_MISP_RETIRED.INDIRECT_CALL",
            .encoding =
                {
                    .code = 0xC5ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Mispredicted indirect CALL retired.",
            .full_desc =
                "Counts retired mispredicted indirect (near taken) CALL instructions, including both register and memory indirect.",
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
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of near branch instructions retired that were mispredicted and taken.",
            .full_desc =
                "Counts number of near branch instructions retired that were mispredicted and taken.",
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
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "This event counts the number of mispredicted ret instructions retired. Non PEBS",
            .full_desc =
                "This is a non-precise version (that is, does not use PEBS) of the event that counts mispredicted return instructions retired.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "CPU_CLK_UNHALTED.C01",
            .encoding =
                {
                    .code = 0xECULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Core clocks when the thread is in the C0.1 light-weight slower wakeup time but more power saving optimized state.",
            .full_desc =
                "Counts core clocks when the thread is in the C0.1 light-weight slower wakeup time but more power saving optimized state.  This state can be entered via the TPAUSE or UMWAIT instructions.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "CPU_CLK_UNHALTED.C02",
            .encoding =
                {
                    .code = 0xECULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Core clocks when the thread is in the C0.2 light-weight faster wakeup time but less power saving optimized state.",
            .full_desc =
                "Counts core clocks when the thread is in the C0.2 light-weight faster wakeup time but less power saving optimized state.  This state can be entered via the TPAUSE or UMWAIT instructions.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "CPU_CLK_UNHALTED.C0_WAIT",
            .encoding =
                {
                    .code = 0xECULL,
                    .umask = 0x70ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Core clocks when the thread is in the C0.1 or C0.2 or running a PAUSE in C0 ACPI state.",
            .full_desc =
                "Counts core clocks when the thread is in the C0.1 or C0.2 power saving optimized states (TPAUSE or UMWAIT instructions) or running the PAUSE instruction.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "CPU_CLK_UNHALTED.DISTRIBUTED",
            .encoding =
                {
                    .code = 0xECULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycle counts are evenly distributed between active threads in the Core.",
            .full_desc =
                "This event distributes cycle counts between active hyperthreads, i.e., those in C0.  A hyperthread becomes inactive when it executes the HLT or MWAIT instructions.  If all other hyperthreads are inactive (or disabled or do not exist), all counts are attributed to this hyperthread. To obtain the full count when the Core is active, sum the counts from each hyperthread.",
            .default_sampling_period = 0x1E8483ULL,
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
                "Counts Core crystal clock cycles when current thread is unhalted and the other thread is halted.",
            .default_sampling_period = 0x61ABULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "CPU_CLK_UNHALTED.PAUSE",
            .encoding =
                {
                    .code = 0xECULL,
                    .umask = 0x40ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CPU_CLK_UNHALTED.PAUSE",
            .full_desc = "CPU_CLK_UNHALTED.PAUSE",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "CPU_CLK_UNHALTED.PAUSE_INST",
            .encoding =
                {
                    .code = 0xECULL,
                    .umask = 0x40ULL,
                    .edge = true,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "CPU_CLK_UNHALTED.PAUSE_INST",
            .full_desc = "CPU_CLK_UNHALTED.PAUSE_INST",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "CPU_CLK_UNHALTED.REF_DISTRIBUTED",
            .encoding =
                {
                    .code = 0x3CULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Core crystal clock cycles. Cycle counts are evenly distributed between active threads in the Core.",
            .full_desc =
                "This event distributes Core crystal clock cycle counts between active hyperthreads, i.e., those in C0 sleep-state. A hyperthread becomes inactive when it executes the HLT or MWAIT instructions. If one thread is active in a core, all counts are attributed to this hyperthread. To obtain the full count when the Core is active, sum the counts from each hyperthread.",
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
                "Reference cycles when the core is not in halt state.",
            .full_desc =
                "Counts the number of reference cycles when the core is not in a halt state. The core enters the halt state when it is running the HLT instruction or the MWAIT instruction. This event is not affected by core frequency changes (for example, P states, TM2 transitions) but has the same incrementing frequency as the time stamp counter. This event can approximate elapsed time while the core was not in a halt state. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. Note: On all current platforms this event stops counting during 'throttling (TM)' states duty off periods the processor is 'halted'.  The counter update is done at a lower clock rate then the core clock the overflow status bit for this counter may appear 'sticky'.  After the counter has overflowed and software clears the overflow status bit and resets the counter to less than MAX. The reset value to the counter is not clocked immediately so the overflow status bit will flip 'high (1)' and generate another PMI (if enabled) after which the reset value gets clocked into the counter. Therefore, software will get the interrupt, read the overflow status bit '1 for bit 34 while the counter value is less than MAX. Software should ignore this case.",
            .default_sampling_period = 0x1E8483ULL,
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
            .default_sampling_period = 0xF4243ULL,
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
            .default_sampling_period = 0xF4243ULL,
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
            .default_sampling_period = 0xF4243ULL,
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
            .default_sampling_period = 0xF4243ULL,
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
                "Stalls caused by changing prefix length of the instruction.",
            .full_desc =
                "Counts cycles that the Instruction Length decoder (ILD) stalls occurred due to dynamically changing prefix length of the decoded instruction (by operand size prefix instruction 0x66, address size prefix instruction 0x67 or REX.W for Intel64). Count is proportional to the number of prefixes in a 16B-line. This may result in a three-cycle penalty for each LCP (Length changing prefix) in a 16-byte chunk.",
            .default_sampling_period = 0x7A129ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DECODE.MS_BUSY",
            .encoding =
                {
                    .code = 0x87ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles the Microcode Sequencer is busy.",
            .full_desc = "Cycles the Microcode Sequencer is busy.",
            .default_sampling_period = 0x7A129ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DSB2MITE_SWITCHES.PENALTY_CYCLES",
            .encoding =
                {
                    .code = 0x61ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "DSB-to-MITE switch true penalty cycles.",
            .full_desc =
                "Decode Stream Buffer (DSB) is a Uop-cache that holds translations of previously fetched instructions that were decoded by the legacy x86 decode pipeline (MITE). This event counts fetch penalty cycles when a transition occurs from DSB to MITE.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_LOAD_MISSES.STLB_HIT",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Loads that miss the DTLB and hit the STLB.",
            .full_desc =
                "Counts loads that miss the DTLB (Data TLB) and hit the STLB (Second level TLB).",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_LOAD_MISSES.WALK_ACTIVE",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x10ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when at least one PMH is busy with a page walk for a demand load.",
            .full_desc =
                "Counts cycles when at least one PMH (Page Miss Handler) is busy with a page walk for a demand load.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_LOAD_MISSES.WALK_COMPLETED_1G",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Page walks completed due to a demand data load to a 1G page.",
            .full_desc =
                "Counts completed page walks  (1G sizes) caused by demand data loads. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_LOAD_MISSES.WALK_COMPLETED_2M_4M",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Page walks completed due to a demand data load to a 2M/4M page.",
            .full_desc =
                "Counts completed page walks  (2M/4M sizes) caused by demand data loads. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_LOAD_MISSES.WALK_COMPLETED_4K",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Page walks completed due to a demand data load to a 4K page.",
            .full_desc =
                "Counts completed page walks  (4K sizes) caused by demand data loads. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_LOAD_MISSES.WALK_PENDING",
            .encoding =
                {
                    .code = 0x12ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of page walks outstanding for a demand load in the PMH each cycle.",
            .full_desc =
                "Counts the number of page walks outstanding for a demand load in the PMH (Page Miss Handler) each cycle.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_STORE_MISSES.STLB_HIT",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Stores that miss the DTLB and hit the STLB.",
            .full_desc =
                "Counts stores that miss the DTLB (Data TLB) and hit the STLB (2nd Level TLB).",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_STORE_MISSES.WALK_ACTIVE",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x10ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when at least one PMH is busy with a page walk for a store.",
            .full_desc =
                "Counts cycles when at least one PMH (Page Miss Handler) is busy with a page walk for a store.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_STORE_MISSES.WALK_COMPLETED_1G",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Page walks completed due to a demand data store to a 1G page.",
            .full_desc =
                "Counts completed page walks  (1G sizes) caused by demand data stores. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_STORE_MISSES.WALK_COMPLETED_2M_4M",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Page walks completed due to a demand data store to a 2M/4M page.",
            .full_desc =
                "Counts completed page walks  (2M/4M sizes) caused by demand data stores. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_STORE_MISSES.WALK_COMPLETED_4K",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Page walks completed due to a demand data store to a 4K page.",
            .full_desc =
                "Counts completed page walks  (4K sizes) caused by demand data stores. This implies address translations missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "DTLB_STORE_MISSES.WALK_PENDING",
            .encoding =
                {
                    .code = 0x13ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of page walks outstanding for a store in the PMH each cycle.",
            .full_desc =
                "Counts the number of page walks outstanding for a store in the PMH (Page Miss Handler) each cycle.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "EXE.AMX_BUSY",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts the cycles where the AMX (Advance Matrix Extension) unit is busy performing an operation.",
            .full_desc =
                "Counts the cycles where the AMX (Advance Matrix Extension) unit is busy performing an operation.",
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
            .id = "EXE_ACTIVITY.2_3_PORTS_UTIL",
            .encoding =
                {
                    .code = 0xA6ULL,
                    .umask = 0xCULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles total of 2 or 3 uops are executed on all ports and Reservation Station (RS) was not empty.",
            .full_desc =
                "Cycles total of 2 or 3 uops are executed on all ports and Reservation Station (RS) was not empty.",
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
            .id = "EXE_ACTIVITY.BOUND_ON_LOADS",
            .encoding =
                {
                    .code = 0xA6ULL,
                    .umask = 0x21ULL,
                    .cmask = 0x5ULL,
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
            .id = "EXE_ACTIVITY.BOUND_ON_STORES",
            .encoding =
                {
                    .code = 0xA6ULL,
                    .umask = 0x40ULL,
                    .cmask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles where the Store Buffer was full and no loads caused an execution stall.",
            .full_desc =
                "Counts cycles where the Store Buffer was full and no loads caused an execution stall.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "EXE_ACTIVITY.EXE_BOUND_0_PORTS",
            .encoding =
                {
                    .code = 0xA6ULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles no uop executed while RS was not empty, the SB was not full and there was no outstanding load.",
            .full_desc =
                "Number of cycles total of 0 uops executed on all ports, Reservation Station (RS) was not empty, the Store Buffer (SB) was not full and there was no outstanding load.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_DISPATCHED.PORT_0",
            .encoding =
                {
                    .code = 0xB3ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "FP_ARITH_DISPATCHED.PORT_0 [This event is alias to FP_ARITH_DISPATCHED.V0]",
            .full_desc =
                "FP_ARITH_DISPATCHED.PORT_0 [This event is alias to FP_ARITH_DISPATCHED.V0]",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_DISPATCHED.PORT_1",
            .encoding =
                {
                    .code = 0xB3ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "FP_ARITH_DISPATCHED.PORT_1 [This event is alias to FP_ARITH_DISPATCHED.V1]",
            .full_desc =
                "FP_ARITH_DISPATCHED.PORT_1 [This event is alias to FP_ARITH_DISPATCHED.V1]",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_DISPATCHED.PORT_5",
            .encoding =
                {
                    .code = 0xB3ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "FP_ARITH_DISPATCHED.PORT_5 [This event is alias to FP_ARITH_DISPATCHED.V2]",
            .full_desc =
                "FP_ARITH_DISPATCHED.PORT_5 [This event is alias to FP_ARITH_DISPATCHED.V2]",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_DISPATCHED.V0",
            .encoding =
                {
                    .code = 0xB3ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "FP_ARITH_DISPATCHED.V0 [This event is alias to FP_ARITH_DISPATCHED.PORT_0]",
            .full_desc =
                "FP_ARITH_DISPATCHED.V0 [This event is alias to FP_ARITH_DISPATCHED.PORT_0]",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_DISPATCHED.V1",
            .encoding =
                {
                    .code = 0xB3ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "FP_ARITH_DISPATCHED.V1 [This event is alias to FP_ARITH_DISPATCHED.PORT_1]",
            .full_desc =
                "FP_ARITH_DISPATCHED.V1 [This event is alias to FP_ARITH_DISPATCHED.PORT_1]",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_DISPATCHED.V2",
            .encoding =
                {
                    .code = 0xB3ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "FP_ARITH_DISPATCHED.V2 [This event is alias to FP_ARITH_DISPATCHED.PORT_5]",
            .full_desc =
                "FP_ARITH_DISPATCHED.V2 [This event is alias to FP_ARITH_DISPATCHED.PORT_5]",
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
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_INST_RETIRED.8_FLOPS",
            .encoding =
                {
                    .code = 0xC7ULL,
                    .umask = 0x60ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of SSE/AVX computational 256-bit packed single precision and 512-bit packed double precision  FP instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, 1 for each element.  Applies to SSE* and AVX* packed single precision and double precision FP instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RSQRT14 RCP RCP14 DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB count twice as they perform 2 calculations per element.",
            .full_desc =
                "Number of SSE/AVX computational 256-bit packed single precision and 512-bit packed double precision  floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision and double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RSQRT14 RCP RCP14 DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
            .default_sampling_period = 0x186A3ULL,
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
                "Number of SSE/AVX computational scalar floating-point instructions retired; some instructions will count twice as noted below.  Applies to SSE* and AVX* scalar, double and single precision floating-point: ADD SUB MUL DIV MIN MAX RCP14 RSQRT14 RANGE SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.",
            .full_desc =
                "Number of SSE/AVX computational scalar single precision and double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
            .default_sampling_period = 0xF4243ULL,
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
                "Number of any Vector retired FP arithmetic instructions.  The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_INST_RETIRED2.128B_PACKED_HALF",
            .encoding =
                {
                    .code = 0xCFULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "FP_ARITH_INST_RETIRED2.128B_PACKED_HALF",
            .full_desc = "FP_ARITH_INST_RETIRED2.128B_PACKED_HALF",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_INST_RETIRED2.256B_PACKED_HALF",
            .encoding =
                {
                    .code = 0xCFULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "FP_ARITH_INST_RETIRED2.256B_PACKED_HALF",
            .full_desc = "FP_ARITH_INST_RETIRED2.256B_PACKED_HALF",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_INST_RETIRED2.512B_PACKED_HALF",
            .encoding =
                {
                    .code = 0xCFULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "FP_ARITH_INST_RETIRED2.512B_PACKED_HALF",
            .full_desc = "FP_ARITH_INST_RETIRED2.512B_PACKED_HALF",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_INST_RETIRED2.COMPLEX_SCALAR_HALF",
            .encoding =
                {
                    .code = 0xCFULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "FP_ARITH_INST_RETIRED2.COMPLEX_SCALAR_HALF",
            .full_desc = "FP_ARITH_INST_RETIRED2.COMPLEX_SCALAR_HALF",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_INST_RETIRED2.SCALAR",
            .encoding =
                {
                    .code = 0xCFULL,
                    .umask = 0x3ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of all Scalar Half-Precision FP arithmetic instructions(1) retired - regular and complex.",
            .full_desc = "FP_ARITH_INST_RETIRED2.SCALAR",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_INST_RETIRED2.SCALAR_HALF",
            .encoding =
                {
                    .code = 0xCFULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "FP_ARITH_INST_RETIRED2.SCALAR_HALF",
            .full_desc = "FP_ARITH_INST_RETIRED2.SCALAR_HALF",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FP_ARITH_INST_RETIRED2.VECTOR",
            .encoding =
                {
                    .code = 0xCFULL,
                    .umask = 0x1CULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of all Vector (also called packed) Half-Precision FP arithmetic instructions(1) retired.",
            .full_desc = "FP_ARITH_INST_RETIRED2.VECTOR",
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
            .features = StaticEventDef::IntelFeatures{},
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
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired Instructions who experienced a critical DSB miss.",
            .full_desc = "Number of retired Instructions that experienced a critical DSB (Decode stream buffer i.e. the decoded instruction-cache) miss. Critical means stalls were exposed to the back-end as a result of the DSB miss.",
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
            .features = StaticEventDef::IntelFeatures{},
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
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired Instructions who experienced Instruction L1 Cache true miss.",
            .full_desc =
                "Counts retired Instructions who experienced Instruction L1 Cache true miss.",
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
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired Instructions who experienced Instruction L2 Cache true miss.",
            .full_desc =
                "Counts retired Instructions who experienced Instruction L2 Cache true miss.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FRONTEND_RETIRED.LATENCY_GE_1",
            .encoding =
                {
                    .code = 0xC6ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x600106ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
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
                    .msr_values = uint64_t{0x608006ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 128 cycles which was not interrupted by a back-end stall.",
            .full_desc =
                "Counts retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 128 cycles which was not interrupted by a back-end stall.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FRONTEND_RETIRED.LATENCY_GE_16",
            .encoding =
                {
                    .code = 0xC6ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x601006ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
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
                    .msr_values = uint64_t{0x600206ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired instructions after front-end starvation of at least 2 cycles",
            .full_desc =
                "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of at least 2 cycles which was not interrupted by a back-end stall.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FRONTEND_RETIRED.LATENCY_GE_256",
            .encoding =
                {
                    .code = 0xC6ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x610006ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 256 cycles which was not interrupted by a back-end stall.",
            .full_desc =
                "Counts retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 256 cycles which was not interrupted by a back-end stall.",
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
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired instructions that are fetched after an interval where the front-end had at least 1 bubble-slot for a period of 2 cycles which was not interrupted by a back-end stall.",
            .full_desc =
                "Counts retired instructions that are delivered to the back-end after the front-end had at least 1 bubble-slot for a period of 2 cycles. A bubble-slot is an empty issue-pipeline slot while there was no RAT stall.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FRONTEND_RETIRED.LATENCY_GE_32",
            .encoding =
                {
                    .code = 0xC6ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x602006ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
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
                    .msr_values = uint64_t{0x600406ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 4 cycles which was not interrupted by a back-end stall.",
            .full_desc =
                "Counts retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 4 cycles which was not interrupted by a back-end stall.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FRONTEND_RETIRED.LATENCY_GE_512",
            .encoding =
                {
                    .code = 0xC6ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x620006ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 512 cycles which was not interrupted by a back-end stall.",
            .full_desc =
                "Counts retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 512 cycles which was not interrupted by a back-end stall.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FRONTEND_RETIRED.LATENCY_GE_64",
            .encoding =
                {
                    .code = 0xC6ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x604006ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 64 cycles which was not interrupted by a back-end stall.",
            .full_desc =
                "Counts retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 64 cycles which was not interrupted by a back-end stall.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FRONTEND_RETIRED.LATENCY_GE_8",
            .encoding =
                {
                    .code = 0xC6ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x600806ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired instructions that are fetched after an interval where the front-end delivered no uops for a period of 8 cycles which was not interrupted by a back-end stall.",
            .full_desc =
                "Counts retired instructions that are delivered to the back-end after a front-end stall of at least 8 cycles. During this period the front-end delivered no uops.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FRONTEND_RETIRED.MS_FLOWS",
            .encoding =
                {
                    .code = 0xC6ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x8ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "FRONTEND_RETIRED.MS_FLOWS",
            .full_desc = "FRONTEND_RETIRED.MS_FLOWS",
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
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired Instructions who experienced STLB (2nd level TLB) true miss.",
            .full_desc =
                "Counts retired Instructions that experienced STLB (2nd level TLB) true miss.",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "FRONTEND_RETIRED.UNKNOWN_BRANCH",
            .encoding =
                {
                    .code = 0xC6ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x17ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "FRONTEND_RETIRED.UNKNOWN_BRANCH",
            .full_desc = "FRONTEND_RETIRED.UNKNOWN_BRANCH",
            .default_sampling_period = 0x186A7ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ICACHE_DATA.STALLS",
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
                "Counts cycles where a code line fetch is stalled due to an L1 instruction cache miss. The decode pipeline works at a 32 Byte granularity.",
            .default_sampling_period = 0x7A129ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ICACHE_DATA.STALL_PERIODS",
            .encoding =
                {
                    .code = 0x80ULL,
                    .umask = 0x4ULL,
                    .edge = true,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "ICACHE_DATA.STALL_PERIODS",
            .full_desc = "ICACHE_DATA.STALL_PERIODS",
            .default_sampling_period = 0x7A129ULL,
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
                "Cycles where a code fetch is stalled due to L1 instruction cache tag miss.",
            .full_desc =
                "Counts cycles where a code fetch is stalled due to L1 instruction cache tag miss.",
            .default_sampling_period = 0x30D43ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "IDQ.DSB_CYCLES_ANY",
            .encoding =
                {
                    .code = 0x79ULL,
                    .umask = 0x8ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles Decode Stream Buffer (DSB) is delivering any Uop",
            .full_desc =
                "Counts the number of cycles uops were delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "IDQ.DSB_CYCLES_OK",
            .encoding =
                {
                    .code = 0x79ULL,
                    .umask = 0x8ULL,
                    .cmask = 0x6ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles DSB is delivering optimal number of Uops",
            .full_desc =
                "Counts the number of cycles where optimal number of uops was delivered to the Instruction Decode Queue (IDQ) from the DSB (Decode Stream Buffer) path. Count includes uops that may 'bypass' the IDQ.",
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
                "Counts the number of uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "IDQ.MITE_CYCLES_ANY",
            .encoding =
                {
                    .code = 0x79ULL,
                    .umask = 0x4ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles MITE is delivering any Uop",
            .full_desc =
                "Counts the number of cycles uops were delivered to the Instruction Decode Queue (IDQ) from the MITE (legacy decode pipeline) path. During these cycles uops are not being delivered from the Decode Stream Buffer (DSB).",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "IDQ.MITE_CYCLES_OK",
            .encoding =
                {
                    .code = 0x79ULL,
                    .umask = 0x4ULL,
                    .cmask = 0x6ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles MITE is delivering optimal number of Uops",
            .full_desc =
                "Counts the number of cycles where optimal number of uops was delivered to the Instruction Decode Queue (IDQ) from the MITE (legacy decode pipeline) path. During these cycles uops are not being delivered from the Decode Stream Buffer (DSB).",
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
                "Counts the number of uops delivered to Instruction Decode Queue (IDQ) from the MITE path. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "IDQ.MS_CYCLES_ANY",
            .encoding =
                {
                    .code = 0x79ULL,
                    .umask = 0x20ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when uops are being delivered to IDQ while MS is busy",
            .full_desc =
                "Counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Uops maybe initiated by Decode Stream Buffer (DSB) or MITE.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "IDQ.MS_SWITCHES",
            .encoding =
                {
                    .code = 0x79ULL,
                    .umask = 0x20ULL,
                    .edge = true,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of switches from DSB or MITE to the MS",
            .full_desc =
                "Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "IDQ.MS_UOPS",
            .encoding =
                {
                    .code = 0x79ULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Uops delivered to IDQ while MS is busy",
            .full_desc =
                "Counts the total number of uops delivered by the Microcode Sequencer (MS).",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "IDQ_BUBBLES.CORE",
            .encoding =
                {
                    .code = 0x9CULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Uops not delivered by IDQ when backend of the machine is not stalled [This event is alias to IDQ_UOPS_NOT_DELIVERED.CORE]",
            .full_desc =
                "Counts the number of uops not delivered to by the Instruction Decode Queue (IDQ) to the back-end of the pipeline when there was no back-end stalls. This event counts for one SMT thread in a given cycle. [This event is alias to IDQ_UOPS_NOT_DELIVERED.CORE]",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "IDQ_BUBBLES.CYCLES_0_UOPS_DELIV.CORE",
            .encoding =
                {
                    .code = 0x9CULL,
                    .umask = 0x1ULL,
                    .cmask = 0x6ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when no uops are not delivered by the IDQ when backend of the machine is not stalled [This event is alias to IDQ_UOPS_NOT_DELIVERED.CYCLES_0_UOPS_DELIV.CORE]",
            .full_desc =
                "Counts the number of cycles when no uops were delivered by the Instruction Decode Queue (IDQ) to the back-end of the pipeline when there was no back-end stalls. This event counts for one SMT thread in a given cycle. [This event is alias to IDQ_UOPS_NOT_DELIVERED.CYCLES_0_UOPS_DELIV.CORE]",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "IDQ_BUBBLES.CYCLES_FE_WAS_OK",
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
                "Cycles when optimal number of uops was delivered to the back-end when the back-end is not stalled [This event is alias to IDQ_UOPS_NOT_DELIVERED.CYCLES_FE_WAS_OK]",
            .full_desc =
                "Counts the number of cycles when the optimal number of uops were delivered by the Instruction Decode Queue (IDQ) to the back-end of the pipeline when there was no back-end stalls. This event counts for one SMT thread in a given cycle. [This event is alias to IDQ_UOPS_NOT_DELIVERED.CYCLES_FE_WAS_OK]",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "IDQ_UOPS_NOT_DELIVERED.CYCLES_0_UOPS_DELIV.CORE",
            .encoding =
                {
                    .code = 0x9CULL,
                    .umask = 0x1ULL,
                    .cmask = 0x6ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when no uops are not delivered by the IDQ when backend of the machine is not stalled [This event is alias to IDQ_BUBBLES.CYCLES_0_UOPS_DELIV.CORE]",
            .full_desc =
                "Counts the number of cycles when no uops were delivered by the Instruction Decode Queue (IDQ) to the back-end of the pipeline when there was no back-end stalls. This event counts for one SMT thread in a given cycle. [This event is alias to IDQ_BUBBLES.CYCLES_0_UOPS_DELIV.CORE]",
            .default_sampling_period = 0xF4243ULL,
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
                "Cycles when optimal number of uops was delivered to the back-end when the back-end is not stalled [This event is alias to IDQ_BUBBLES.CYCLES_FE_WAS_OK]",
            .full_desc =
                "Counts the number of cycles when the optimal number of uops were delivered by the Instruction Decode Queue (IDQ) to the back-end of the pipeline when there was no back-end stalls. This event counts for one SMT thread in a given cycle. [This event is alias to IDQ_BUBBLES.CYCLES_FE_WAS_OK]",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INST_DECODED.DECODERS",
            .encoding =
                {
                    .code = 0x75ULL,
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
            .brief_desc =
                "Number of instructions retired. Fixed Counter - architectural event",
            .full_desc =
                "Counts the number of X86 instructions retired - an Architectural PerfMon event. Counting continues during hardware interrupts, traps, and inside interrupt handlers. Notes: INST_RETIRED.ANY is counted by a designated fixed counter freeing up programmable counters to count other events. INST_RETIRED.ANY_P is counted by a programmable counter.",
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
                "Counts the number of X86 instructions retired - an Architectural PerfMon event. Counting continues during hardware interrupts, traps, and inside interrupt handlers. Notes: INST_RETIRED.ANY is counted by a designated fixed counter freeing up programmable counters to count other events. INST_RETIRED.ANY_P is counted by a programmable counter.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INST_RETIRED.MACRO_FUSED",
            .encoding =
                {
                    .code = 0xC0ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "INST_RETIRED.MACRO_FUSED",
            .full_desc = "INST_RETIRED.MACRO_FUSED",
            .default_sampling_period = 0x1E8483ULL,
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
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Retired NOP instructions.",
            .full_desc = "Counts all retired NOP or ENDBR32/64 instructions",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INST_RETIRED.PREC_DIST",
            .encoding =
                {
                    .code = 0x0ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Precise instruction retired with PEBS precise-distribution",
            .full_desc =
                "A version of INST_RETIRED that allows for a precise distribution of samples across instructions retired. It utilizes the Precise Distribution of Instructions Retired (PDIR++) feature to fix bias in how retired instructions get sampled. Use on Fixed Counter 0.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INST_RETIRED.REP_ITERATION",
            .encoding =
                {
                    .code = 0xC0ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Iterations of Repeat string retired instructions.",
            .full_desc =
                "Number of iterations of Repeat (REP) string retired instructions such as MOVS, CMPS, and SCAS. Each has a byte, word, and doubleword version and string instructions can be repeated using a repetition prefix, REP, that allows their architectural execution to be repeated a number of times as specified by the RCX register. Note the number of iterations is implementation-dependent.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_MISC.CLEARS_COUNT",
            .encoding =
                {
                    .code = 0xADULL,
                    .umask = 0x1ULL,
                    .edge = true,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Clears speculative count",
            .full_desc =
                "Counts the number of speculative clears due to any type of branch misprediction or machine clears",
            .default_sampling_period = 0x7A129ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_MISC.CLEAR_RESTEER_CYCLES",
            .encoding =
                {
                    .code = 0xADULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts cycles after recovery from a branch misprediction or machine clear till the first uop is issued from the resteered path.",
            .full_desc =
                "Cycles after recovery from a branch misprediction or machine clear till the first uop is issued from the resteered path.",
            .default_sampling_period = 0x7A129ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_MISC.MBA_STALLS",
            .encoding =
                {
                    .code = 0xADULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "INT_MISC.MBA_STALLS",
            .full_desc = "INT_MISC.MBA_STALLS",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_MISC.UNKNOWN_BRANCH_CYCLES",
            .encoding =
                {
                    .code = 0xADULL,
                    .umask = 0x40ULL,
                    .msr_values = uint64_t{0x7ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Bubble cycles of BAClear (Unknown Branch).",
            .full_desc = "Bubble cycles of BAClear (Unknown Branch).",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_MISC.UOP_DROPPING",
            .encoding =
                {
                    .code = 0xADULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "TMA slots where uops got dropped",
            .full_desc =
                "Estimated number of Top-down Microarchitecture Analysis slots that got dropped due to non front-end reasons",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_VEC_RETIRED.128BIT",
            .encoding =
                {
                    .code = 0xE7ULL,
                    .umask = 0x13ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "INT_VEC_RETIRED.128BIT",
            .full_desc = "INT_VEC_RETIRED.128BIT",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_VEC_RETIRED.256BIT",
            .encoding =
                {
                    .code = 0xE7ULL,
                    .umask = 0xACULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "INT_VEC_RETIRED.256BIT",
            .full_desc = "INT_VEC_RETIRED.256BIT",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_VEC_RETIRED.ADD_128",
            .encoding =
                {
                    .code = 0xE7ULL,
                    .umask = 0x3ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "integer ADD, SUB, SAD 128-bit vector instructions.",
            .full_desc =
                "Number of retired integer ADD/SUB (regular or horizontal), SAD 128-bit vector instructions.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_VEC_RETIRED.ADD_256",
            .encoding =
                {
                    .code = 0xE7ULL,
                    .umask = 0xCULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "integer ADD, SUB, SAD 256-bit vector instructions.",
            .full_desc =
                "Number of retired integer ADD/SUB (regular or horizontal), SAD 256-bit vector instructions.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_VEC_RETIRED.MUL_256",
            .encoding =
                {
                    .code = 0xE7ULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "INT_VEC_RETIRED.MUL_256",
            .full_desc = "INT_VEC_RETIRED.MUL_256",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_VEC_RETIRED.SHUFFLES",
            .encoding =
                {
                    .code = 0xE7ULL,
                    .umask = 0x40ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "INT_VEC_RETIRED.SHUFFLES",
            .full_desc = "INT_VEC_RETIRED.SHUFFLES",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_VEC_RETIRED.VNNI_128",
            .encoding =
                {
                    .code = 0xE7ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "INT_VEC_RETIRED.VNNI_128",
            .full_desc = "INT_VEC_RETIRED.VNNI_128",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "INT_VEC_RETIRED.VNNI_256",
            .encoding =
                {
                    .code = 0xE7ULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "INT_VEC_RETIRED.VNNI_256",
            .full_desc = "INT_VEC_RETIRED.VNNI_256",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ITLB_MISSES.STLB_HIT",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Instruction fetch requests that miss the ITLB and hit the STLB.",
            .full_desc =
                "Counts instruction fetch requests that miss the ITLB (Instruction TLB) and hit the STLB (Second-level TLB).",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ITLB_MISSES.WALK_ACTIVE",
            .encoding =
                {
                    .code = 0x11ULL,
                    .umask = 0x10ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when at least one PMH is busy with a page walk for code (instruction fetch) request.",
            .full_desc =
                "Counts cycles when at least one PMH (Page Miss Handler) is busy with a page walk for a code (instruction fetch) request.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "ITLB_MISSES.WALK_COMPLETED_2M_4M",
            .encoding =
                {
                    .code = 0x11ULL,
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
                    .code = 0x11ULL,
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
                    .code = 0x11ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of page walks outstanding for an outstanding code request in the PMH each cycle.",
            .full_desc =
                "Counts the number of page walks outstanding for an outstanding code (instruction fetch) request in the PMH (Page Miss Handler) each cycle.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L1D.HWPF_MISS",
            .encoding =
                {
                    .code = 0x51ULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "L1D.HWPF_MISS",
            .full_desc = "L1D.HWPF_MISS",
            .default_sampling_period = 0xF4243ULL,
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
                "Number of cycles a demand request has waited due to L1D Fill Buffer (FB) unavailability.",
            .full_desc =
                "Counts number of cycles a demand request has waited due to L1D Fill Buffer (FB) unavailability. Demand requests include cacheable/uncacheable demand load, store, lock or SW prefetch accesses.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L1D_PEND_MISS.FB_FULL_PERIODS",
            .encoding =
                {
                    .code = 0x48ULL,
                    .umask = 0x2ULL,
                    .edge = true,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of phases a demand request has waited due to L1D Fill Buffer (FB) unavailability.",
            .full_desc =
                "Counts number of phases a demand request has waited due to L1D Fill Buffer (FB) unavailability. Demand requests include cacheable/uncacheable demand load, store, lock or SW prefetch accesses.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L1D_PEND_MISS.L2_STALLS",
            .encoding =
                {
                    .code = 0x48ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of cycles a demand request has waited due to L1D due to lack of L2 resources.",
            .full_desc =
                "Counts number of cycles a demand request has waited due to L1D due to lack of L2 resources. Demand requests include cacheable/uncacheable demand load, store, lock or SW prefetch accesses.",
            .default_sampling_period = 0xF4243ULL,
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
            .brief_desc = "Number of L1D misses that are outstanding",
            .full_desc =
                "Counts number of L1D misses that are outstanding in each cycle, that is each cycle the number of Fill Buffers (FB) outstanding required by Demand Reads. FB either is held by demand loads, or it is held by non-demand loads and gets hit at least once by demand. The valid outstanding interval is defined until the FB deallocation by one of the following ways: from FB allocation, if FB is allocated by demand from the demand Hit FB, if it is allocated by hardware or software prefetch. Note: In the L1D, a Demand Read contains cacheable or noncacheable demand loads, including ones causing cache-line splits and reads due to page walks resulted from any request type.",
            .default_sampling_period = 0xF4243ULL,
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
            .full_desc = "Counts duration of L1D miss outstanding in cycles.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L2_LINES_OUT.NON_SILENT",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Modified cache lines that are evicted by L2 cache when triggered by an L2 cache fill.",
            .full_desc =
                "Counts the number of lines that are evicted by L2 cache when triggered by an L2 cache fill. Those lines are in Modified state. Modified lines are written back to L3",
            .default_sampling_period = 0x30D43ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L2_LINES_OUT.SILENT",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Non-modified cache lines that are silently dropped by L2 cache.",
            .full_desc =
                "Counts the number of lines that are silently dropped by L2 cache. These lines are typically in Shared or Exclusive state. A non-threaded event.",
            .default_sampling_period = 0x30D43ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L2_LINES_OUT.USELESS_HWPF",
            .encoding =
                {
                    .code = 0x26ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cache lines that have been L2 hardware prefetched but not used by demand accesses",
            .full_desc =
                "Counts the number of cache lines that have been prefetched by the L2 hardware prefetcher but not used by demand access when evicted from the L2 cache",
            .default_sampling_period = 0x30D43ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L2_REQUEST.ALL",
            .encoding =
                {
                    .code = 0x24ULL,
                    .umask = 0xFFULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "All accesses to L2 cache [This event is alias to L2_RQSTS.REFERENCES]",
            .full_desc =
                "Counts all requests that were hit or true misses in L2 cache. True-miss excludes misses that were merged with ongoing L2 misses. [This event is alias to L2_RQSTS.REFERENCES]",
            .default_sampling_period = 0x30D43ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L2_REQUEST.MISS",
            .encoding =
                {
                    .code = 0x24ULL,
                    .umask = 0x3FULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Read requests with true-miss in L2 cache. [This event is alias to L2_RQSTS.MISS]",
            .full_desc =
                "Counts read requests of any type with true-miss in the L2 cache. True-miss excludes L2 misses that were merged with ongoing L2 misses. [This event is alias to L2_RQSTS.MISS]",
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
            .brief_desc = "Demand Data Read access L2 cache",
            .full_desc =
                "Counts Demand Data Read requests accessing the L2 cache. These requests may hit or miss L2 cache. True-miss exclude misses that were merged with ongoing L2 misses. An access is counted once.",
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
            .full_desc = "Counts demand requests that miss L2 cache.",
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
            .full_desc = "Counts demand requests to L2 cache.",
            .default_sampling_period = 0x30D43ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L2_RQSTS.ALL_HWPF",
            .encoding =
                {
                    .code = 0x24ULL,
                    .umask = 0xF0ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "L2_RQSTS.ALL_HWPF",
            .full_desc = "L2_RQSTS.ALL_HWPF",
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
            .full_desc = "Counts L2 cache misses when fetching instructions.",
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
                "Counts the number of demand Data Read requests initiated by load instructions that hit L2 cache.",
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
            .brief_desc = "Demand Data Read miss L2 cache",
            .full_desc =
                "Counts demand Data Read requests with true-miss in the L2 cache. True-miss excludes misses that were merged with ongoing L2 misses. An access is counted once.",
            .default_sampling_period = 0x30D43ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "L2_RQSTS.HWPF_MISS",
            .encoding =
                {
                    .code = 0x24ULL,
                    .umask = 0x30ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "L2_RQSTS.HWPF_MISS",
            .full_desc = "L2_RQSTS.HWPF_MISS",
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
            .brief_desc =
                "All accesses to L2 cache [This event is alias to L2_REQUEST.ALL]",
            .full_desc =
                "Counts all requests that were hit or true misses in L2 cache. True-miss excludes misses that were merged with ongoing L2 misses. [This event is alias to L2_REQUEST.ALL]",
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
                    .code = 0x23ULL,
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
            .id = "LD_BLOCKS.ADDRESS_ALIAS",
            .encoding =
                {
                    .code = 0x3ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "False dependencies in MOB due to partial compare on address.",
            .full_desc =
                "Counts the number of times a load got blocked due to false dependencies in MOB due to partial compare on address.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "LD_BLOCKS.NO_SR",
            .encoding =
                {
                    .code = 0x3ULL,
                    .umask = 0x88ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "The number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.",
            .full_desc =
                "Counts the number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "LOAD_HIT_PREFETCH.SWPF",
            .encoding =
                {
                    .code = 0x4CULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts the number of demand load dispatches that hit L1D fill buffer (FB) allocated for software prefetch.",
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
                "Core-originated cacheable requests that refer to L3 (Except hardware prefetches to the L3)",
            .full_desc =
                "Counts core-originated cacheable requests to the L3 cache (Longest Latency cache). Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches to the L1 and L2.  It does not include hardware prefetches to the L3, and may not count other types of requests to the L3.",
            .default_sampling_period = 0x186A3ULL,
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
                    .cmask = 0x6ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles optimal number of Uops delivered by the LSD, but did not come from the decoder.",
            .full_desc =
                "Counts the cycles when optimal number of uops is delivered by the LSD (Loop-stream detector).",
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
                "Counts the number of uops delivered to the back-end by the LSD(Loop Stream Detector).",
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
            .full_desc =
                "Counts the number of machine clears (nukes) of any type.",
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
                "Number of machine clears due to memory ordering conflicts.",
            .full_desc =
                "Counts the number of Machine Clears detected dye to memory ordering. Memory Ordering Machine Clears may apply when a memory read may not conform to the memory ordering rules of the x86 architecture",
            .default_sampling_period = 0x186A3ULL,
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
            .id = "MEMORY_ACTIVITY.CYCLES_L1D_MISS",
            .encoding =
                {
                    .code = 0x47ULL,
                    .umask = 0x2ULL,
                    .cmask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles while L1 cache miss demand load is outstanding.",
            .full_desc =
                "Cycles while L1 cache miss demand load is outstanding.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEMORY_ACTIVITY.STALLS_L1D_MISS",
            .encoding =
                {
                    .code = 0x47ULL,
                    .umask = 0x3ULL,
                    .cmask = 0x3ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Execution stalls while L1 cache miss demand load is outstanding.",
            .full_desc =
                "Execution stalls while L1 cache miss demand load is outstanding.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEMORY_ACTIVITY.STALLS_L2_MISS",
            .encoding =
                {
                    .code = 0x47ULL,
                    .umask = 0x5ULL,
                    .cmask = 0x5ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Execution stalls while L2 cache miss demand cacheable load request is outstanding.",
            .full_desc =
                "Execution stalls while L2 cache miss demand cacheable load request is outstanding (will not count for uncacheable demand requests e.g. bus lock).",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEMORY_ACTIVITY.STALLS_L3_MISS",
            .encoding =
                {
                    .code = 0x47ULL,
                    .umask = 0x9ULL,
                    .cmask = 0x9ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Execution stalls while L3 cache miss demand cacheable load request is outstanding.",
            .full_desc =
                "Execution stalls while L3 cache miss demand cacheable load request is outstanding (will not count for uncacheable demand requests e.g. bus lock).",
            .default_sampling_period = 0xF4243ULL,
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
                },
            .brief_desc = "Retired load instructions.",
            .full_desc =
                "Counts all retired load instructions. This event accounts for SW prefetch instructions of PREFETCHNTA or PREFETCHT0/1/2 or PREFETCHW.",
            .default_sampling_period = 0xF4243ULL,
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
                },
            .brief_desc = "Retired store instructions.",
            .full_desc = "Counts all retired store instructions.",
            .default_sampling_period = 0xF4243ULL,
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
                },
            .brief_desc = "All retired memory instructions.",
            .full_desc =
                "Counts all retired memory instructions - loads and stores.",
            .default_sampling_period = 0xF4243ULL,
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
                },
            .brief_desc = "Retired load instructions with locked access.",
            .full_desc = "Counts retired load instructions with locked access.",
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
                },
            .brief_desc = "Retired store instructions that miss the STLB.",
            .full_desc =
                "Number of retired store instructions that (start a) miss in the 2nd-level TLB (STLB).",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEM_LOAD_COMPLETED.L1_MISS_ANY",
            .encoding =
                {
                    .code = 0x43ULL,
                    .umask = 0xFDULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Completed demand load uops that miss the L1 d-cache.",
            .full_desc =
                "Number of completed demand load requests that missed the L1 data cache including shadow misses (FB hits, merge to an ongoing L1D miss)",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEM_LOAD_L3_HIT_RETIRED.XSNP_FWD",
            .encoding =
                {
                    .code = 0xD2ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .data_la = true,
                },
            .brief_desc =
                "Retired load instructions whose data sources were HitM responses from shared L3",
            .full_desc =
                "Counts retired load instructions whose data sources were HitM responses from shared L3.",
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
                },
            .brief_desc =
                "Retired load instructions whose data sources were L3 hit and cross-core snoop missed in on-pkg core cache.",
            .full_desc =
                "Counts the retired load instructions whose data sources were L3 hit and cross-core snoop missed in on-pkg core cache.",
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
                },
            .brief_desc =
                "Retired load instructions whose data sources were hits in L3 without snoops required",
            .full_desc =
                "Counts retired load instructions whose data sources were hits in L3 without snoops required.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEM_LOAD_L3_HIT_RETIRED.XSNP_NO_FWD",
            .encoding =
                {
                    .code = 0xD2ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .data_la = true,
                },
            .brief_desc =
                "Retired load instructions whose data sources were L3 and cross-core snoop hits in on-pkg core cache",
            .full_desc =
                "Counts retired load instructions whose data sources were L3 and cross-core snoop hits in on-pkg core cache.",
            .default_sampling_period = 0x4E2BULL,
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
                },
            .brief_desc = "MEM_LOAD_L3_MISS_RETIRED.REMOTE_DRAM",
            .full_desc = "MEM_LOAD_L3_MISS_RETIRED.REMOTE_DRAM",
            .default_sampling_period = 0xF4243ULL,
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
                },
            .brief_desc = "MEM_LOAD_L3_MISS_RETIRED.REMOTE_HITM",
            .full_desc = "MEM_LOAD_L3_MISS_RETIRED.REMOTE_HITM",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEM_LOAD_L3_MISS_RETIRED.REMOTE_PMM",
            .encoding =
                {
                    .code = 0xD3ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired load instructions with remote Intel(R) Optane(TM) DC persistent memory as the data source where the data request missed all caches.",
            .full_desc =
                "Counts retired load instructions with remote Intel(R) Optane(TM) DC persistent memory as the data source and the data request missed L3.",
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
                },
            .brief_desc =
                "Retired instructions with at least 1 uncacheable load or lock.",
            .full_desc =
                "Retired instructions with at least one load to uncacheable memory-type, or at least one cache-line split locked access (Bus Lock).",
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
                },
            .brief_desc =
                "Number of completed demand load requests that missed the L1, but hit the FB(fill buffer), because a preceding miss to the same cacheline initiated the line to be brought into L1, but data is not yet ready in L1.",
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
                },
            .brief_desc =
                "Retired load instructions with L1 cache hits as data sources",
            .full_desc =
                "Counts retired load instructions with at least one uop that hit in the L1 data cache. This event includes all SW prefetches and lock instructions regardless of the data source.",
            .default_sampling_period = 0xF4243ULL,
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
                },
            .brief_desc =
                "Retired load instructions missed L1 cache as data sources",
            .full_desc =
                "Counts retired load instructions with at least one uop that missed in the L1 cache.",
            .default_sampling_period = 0x30D43ULL,
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
                },
            .brief_desc =
                "Retired load instructions with L2 cache hits as data sources",
            .full_desc =
                "Counts retired load instructions with L2 cache hits as data sources.",
            .default_sampling_period = 0x30D43ULL,
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
                },
            .brief_desc =
                "Retired load instructions missed L2 cache as data sources",
            .full_desc =
                "Counts retired load instructions missed L2 cache as data sources.",
            .default_sampling_period = 0x186B5ULL,
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
                },
            .brief_desc =
                "Retired load instructions with L3 cache hits as data sources",
            .full_desc =
                "Counts retired load instructions with at least one uop that hit in the L3 cache.",
            .default_sampling_period = 0x186B5ULL,
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
                },
            .brief_desc =
                "Retired load instructions missed L3 cache as data sources",
            .full_desc =
                "Counts retired load instructions with at least one uop that missed in the L3 cache.",
            .default_sampling_period = 0xC365ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEM_LOAD_RETIRED.LOCAL_PMM",
            .encoding =
                {
                    .code = 0xD1ULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .data_la = true,
                },
            .brief_desc =
                "Retired load instructions with local Intel(R) Optane(TM) DC persistent memory as the data source where the data request missed all caches.",
            .full_desc =
                "Counts retired load instructions with local Intel(R) Optane(TM) DC persistent memory as the data source and the data request missed L3.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEM_STORE_RETIRED.L2_HIT",
            .encoding =
                {
                    .code = 0x44ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "MEM_STORE_RETIRED.L2_HIT",
            .full_desc = "MEM_STORE_RETIRED.L2_HIT",
            .default_sampling_period = 0x30D43ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEM_TRANS_RETIRED.LOAD_LATENCY_GT_1024",
            .encoding =
                {
                    .code = 0xCDULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .data_la = true,
                },
            .brief_desc =
                "Counts randomly selected loads when the latency from first dispatch to completion is greater than 1024 cycles.",
            .full_desc =
                "Counts randomly selected loads when the latency from first dispatch to completion is greater than 1024 cycles.  Reported latency may be longer than just the memory latency.",
            .default_sampling_period = 0x35ULL,
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
                },
            .brief_desc =
                "Counts randomly selected loads when the latency from first dispatch to completion is greater than 8 cycles.",
            .full_desc =
                "Counts randomly selected loads when the latency from first dispatch to completion is greater than 8 cycles.  Reported latency may be longer than just the memory latency.",
            .default_sampling_period = 0xC365ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEM_TRANS_RETIRED.STORE_SAMPLE",
            .encoding =
                {
                    .code = 0xCDULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features =
                StaticEventDef::IntelFeatures{
                    .data_la = true,
                },
            .brief_desc =
                "Retired memory store access operations. A PDist event for PEBS Store Latency Facility.",
            .full_desc =
                "Counts Retired memory accesses with at least 1 store operation. This PEBS event is the precisely-distributed (PDist) trigger covering all stores uops for sampling by the PEBS Store Latency Facility. The facility is described in Intel SDM Volume 3 section 19.9.8",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MEM_UOP_RETIRED.ANY",
            .encoding =
                {
                    .code = 0xE5ULL,
                    .umask = 0x3ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Retired memory uops for any access",
            .full_desc =
                "Number of retired micro-operations (uops) for load or store memory accesses",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MISC2_RETIRED.LFENCE",
            .encoding =
                {
                    .code = 0xE0ULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "LFENCE instructions retired",
            .full_desc = "number of LFENCE retired instructions",
            .default_sampling_period = 0x61A89ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "MISC_RETIRED.LBR_INSERTS",
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
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_CODE_RD.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0x2AULL,
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
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x73C000004ULL},
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
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that hit in the L3 or were snooped from another core's caches on the same socket.",
            .full_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that hit in the L3 or were snooped from another core's caches on the same socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_HITM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that resulted in a snoop hit a modified line in another core's caches which forwarded the data.",
            .full_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that resulted in a snoop hit a modified line in another core's caches which forwarded the data.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_CODE_RD.L3_MISS",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3FBFC00004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that were not supplied by the local socket's L1, L2, or L3 caches.",
            .full_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that were not supplied by the local socket's L1, L2, or L3 caches.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_CODE_RD.LOCAL_DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x104000004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM attached to this socket, unless in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts only those DRAM accesses that are controlled by the close SNC Cluster.",
            .full_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM attached to this socket, unless in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts only those DRAM accesses that are controlled by the close SNC Cluster.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_CODE_RD.SNC_CACHE.HITM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1008000004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that hit a modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that hit a modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_CODE_RD.SNC_CACHE.HIT_WITH_FWD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x808000004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that either hit a non-modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that either hit a non-modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_CODE_RD.SNC_DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x708000004ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM on a distant memory controller of this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc =
                "Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM on a distant memory controller of this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0x2AULL,
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
            .id = "OCR.DEMAND_DATA_RD.DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x73C000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that were supplied by DRAM.",
            .full_desc = "Counts demand data reads that were supplied by DRAM.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.L3_HIT",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that hit in the L3 or were snooped from another core's caches on the same socket.",
            .full_desc =
                "Counts demand data reads that hit in the L3 or were snooped from another core's caches on the same socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HITM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that resulted in a snoop hit a modified line in another core's caches which forwarded the data.",
            .full_desc =
                "Counts demand data reads that resulted in a snoop hit a modified line in another core's caches which forwarded the data.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that resulted in a snoop that hit in another core, which did not forward the data.",
            .full_desc =
                "Counts demand data reads that resulted in a snoop that hit in another core, which did not forward the data.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x8003C0001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that resulted in a snoop hit in another core's caches which forwarded the unmodified data to the requesting core.",
            .full_desc =
                "Counts demand data reads that resulted in a snoop hit in another core's caches which forwarded the unmodified data to the requesting core.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.L3_MISS",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3FBFC00001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that were not supplied by the local socket's L1, L2, or L3 caches.",
            .full_desc =
                "Counts demand data reads that were not supplied by the local socket's L1, L2, or L3 caches.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.LOCAL_DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x104000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that were supplied by DRAM attached to this socket, unless in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts only those DRAM accesses that are controlled by the close SNC Cluster.",
            .full_desc =
                "Counts demand data reads that were supplied by DRAM attached to this socket, unless in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts only those DRAM accesses that are controlled by the close SNC Cluster.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.LOCAL_SOCKET_PMM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x700C00001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that were supplied by PMM attached to this socket, whether or not in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts PMM accesses that are controlled by the close or distant SNC Cluster.",
            .full_desc =
                "Counts demand data reads that were supplied by PMM attached to this socket, whether or not in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts PMM accesses that are controlled by the close or distant SNC Cluster.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.PMM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x703C00001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts demand data reads that were supplied by PMM.",
            .full_desc = "Counts demand data reads that were supplied by PMM.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.REMOTE_CACHE.SNOOP_HITM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1030000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that were supplied by a cache on a remote socket where a snoop hit a modified line in another core's caches which forwarded the data.",
            .full_desc =
                "Counts demand data reads that were supplied by a cache on a remote socket where a snoop hit a modified line in another core's caches which forwarded the data.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.REMOTE_CACHE.SNOOP_HIT_WITH_FWD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x830000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that were supplied by a cache on a remote socket where a snoop hit in another core's caches which forwarded the unmodified data to the requesting core.",
            .full_desc =
                "Counts demand data reads that were supplied by a cache on a remote socket where a snoop hit in another core's caches which forwarded the unmodified data to the requesting core.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.REMOTE_DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
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
            .id = "OCR.DEMAND_DATA_RD.REMOTE_PMM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x703000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that were supplied by PMM attached to another socket.",
            .full_desc =
                "Counts demand data reads that were supplied by PMM attached to another socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.SNC_CACHE.HITM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1008000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that hit a modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc = "Counts demand data reads that hit a modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.SNC_CACHE.HIT_WITH_FWD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x808000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that either hit a non-modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc =
                "Counts demand data reads that either hit a non-modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_DATA_RD.SNC_DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x708000001ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data reads that were supplied by DRAM on a distant memory controller of this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc =
                "Counts demand data reads that were supplied by DRAM on a distant memory controller of this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_RFO.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F3FFC0002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that have any type of response.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that have any type of response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_RFO.DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x73C000002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_RFO.L3_HIT",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit in the L3 or were snooped from another core's caches on the same socket.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit in the L3 or were snooped from another core's caches on the same socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_RFO.L3_HIT.SNOOP_HITM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that resulted in a snoop hit a modified line in another core's caches which forwarded the data.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that resulted in a snoop hit a modified line in another core's caches which forwarded the data.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_RFO.L3_MISS",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F3FC00002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the local socket's L1, L2, or L3 caches.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the local socket's L1, L2, or L3 caches.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_RFO.LOCAL_DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x104000002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM attached to this socket, unless in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts only those DRAM accesses that are controlled by the close SNC Cluster.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM attached to this socket, unless in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts only those DRAM accesses that are controlled by the close SNC Cluster.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_RFO.SNC_CACHE.HITM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1008000002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that hit a modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_RFO.SNC_CACHE.HIT_WITH_FWD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x808000002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that either hit a non-modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that either hit a non-modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.DEMAND_RFO.SNC_DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x708000002ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM on a distant memory controller of this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc =
                "Counts demand reads for ownership (RFO) requests and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM on a distant memory controller of this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.HWPF_L1D.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10400ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts data load hardware prefetch requests to the L1 data cache that have any type of response.",
            .full_desc =
                "Counts data load hardware prefetch requests to the L1 data cache that have any type of response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.HWPF_L2.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10070ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts hardware prefetches (which bring data to L2) that have any type of response.",
            .full_desc =
                "Counts hardware prefetches (which bring data to L2) that have any type of response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.HWPF_L3.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x12380ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts hardware prefetches to the L3 only that have any type of response.",
            .full_desc =
                "Counts hardware prefetches to the L3 only that have any type of response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.HWPF_L3.L3_HIT",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x80082380ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts hardware prefetches to the L3 only that hit in the L3 or were snooped from another core's caches on the same socket.",
            .full_desc =
                "Counts hardware prefetches to the L3 only that hit in the L3 or were snooped from another core's caches on the same socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.HWPF_L3.L3_MISS",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x94002380ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts hardware prefetches to the L3 only that missed the local socket's L1, L2, and L3 caches.",
            .full_desc =
                "Counts hardware prefetches to the L3 only that missed the local socket's L1, L2, and L3 caches.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.HWPF_L3.L3_MISS_LOCAL",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x84002380ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts hardware prefetches to the L3 only that were not supplied by the local socket's L1, L2, or L3 caches and the cacheline is homed locally.",
            .full_desc =
                "Counts hardware prefetches to the L3 only that were not supplied by the local socket's L1, L2, or L3 caches and the cacheline is homed locally.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.HWPF_L3.REMOTE",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x90002380ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts hardware prefetches to the L3 only that were not supplied by the local socket's L1, L2, or L3 caches and the cacheline was homed in a remote socket.",
            .full_desc =
                "Counts hardware prefetches to the L3 only that were not supplied by the local socket's L1, L2, or L3 caches and the cacheline was homed in a remote socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.MODIFIED_WRITE.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10808ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts writebacks of modified cachelines and streaming stores that have any type of response.",
            .full_desc =
                "Counts writebacks of modified cachelines and streaming stores that have any type of response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F3FFC4477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that have any type of response.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that have any type of response.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x73C004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM.",
            .full_desc = "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.L3_HIT",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F003C4477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that hit in the L3 or were snooped from another core's caches on the same socket.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that hit in the L3 or were snooped from another core's caches on the same socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.L3_HIT.SNOOP_HITM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C4477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that resulted in a snoop hit a modified line in another core's caches which forwarded the data.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that resulted in a snoop hit a modified line in another core's caches which forwarded the data.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.L3_HIT.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C4477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that resulted in a snoop that hit in another core, which did not forward the data.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that resulted in a snoop that hit in another core, which did not forward the data.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.L3_HIT.SNOOP_HIT_WITH_FWD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x8003C4477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that resulted in a snoop hit in another core's caches which forwarded the unmodified data to the requesting core.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that resulted in a snoop hit in another core's caches which forwarded the unmodified data to the requesting core.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.L3_MISS",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F3FC04477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the local socket's L1, L2, or L3 caches.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the local socket's L1, L2, or L3 caches.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.L3_MISS_LOCAL",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F04C04477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the local socket's L1, L2, or L3 caches and the cacheline is homed locally.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the local socket's L1, L2, or L3 caches and the cacheline is homed locally.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.L3_MISS_LOCAL_SOCKET",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x70CC04477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that missed the L3 Cache and were supplied by the local socket (DRAM or PMM), whether or not in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts PMM or DRAM accesses that are controlled by the close or distant SNC Cluster.  It does not count misses to the L3 which go to Local CXL Type 2 Memory or Local Non DRAM.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that missed the L3 Cache and were supplied by the local socket (DRAM or PMM), whether or not in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts PMM or DRAM accesses that are controlled by the close or distant SNC Cluster.  It does not count misses to the L3 which go to Local CXL Type 2 Memory or Local Non DRAM.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.LOCAL_DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x104004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM attached to this socket, unless in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts only those DRAM accesses that are controlled by the close SNC Cluster.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM attached to this socket, unless in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts only those DRAM accesses that are controlled by the close SNC Cluster.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.LOCAL_SOCKET_DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x70C004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM attached to this socket, whether or not in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts DRAM accesses that are controlled by the close or distant SNC Cluster.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM attached to this socket, whether or not in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts DRAM accesses that are controlled by the close or distant SNC Cluster.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.LOCAL_SOCKET_PMM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x700C04477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by PMM attached to this socket, whether or not in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts PMM accesses that are controlled by the close or distant SNC Cluster.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by PMM attached to this socket, whether or not in Sub NUMA Cluster(SNC) Mode.  In SNC Mode counts PMM accesses that are controlled by the close or distant SNC Cluster.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.REMOTE",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F33004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the local socket's L1, L2, or L3 caches and were supplied by a remote socket.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the local socket's L1, L2, or L3 caches and were supplied by a remote socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.REMOTE_CACHE.SNOOP_FWD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1830004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by a cache on a remote socket where a snoop was sent and data was returned (Modified or Not Modified).",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by a cache on a remote socket where a snoop was sent and data was returned (Modified or Not Modified).",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.REMOTE_CACHE.SNOOP_HITM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1030004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by a cache on a remote socket where a snoop hit a modified line in another core's caches which forwarded the data.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by a cache on a remote socket where a snoop hit a modified line in another core's caches which forwarded the data.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.REMOTE_CACHE.SNOOP_HIT_WITH_FWD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x830004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by a cache on a remote socket where a snoop hit in another core's caches which forwarded the unmodified data to the requesting core.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by a cache on a remote socket where a snoop hit in another core's caches which forwarded the unmodified data to the requesting core.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.REMOTE_DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x730004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM attached to another socket.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM attached to another socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.REMOTE_MEMORY",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x733004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM or PMM attached to another socket.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM or PMM attached to another socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.REMOTE_PMM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x703004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by PMM attached to another socket.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by PMM attached to another socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.SNC_CACHE.HITM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1008004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that hit a modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that hit a modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.SNC_CACHE.HIT_WITH_FWD",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x808004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that either hit a non-modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that either hit a non-modified line in a distant L3 Cache or were snooped from a distant core's L1/L2 caches on this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.READS_TO_CORE.SNC_DRAM",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x708004477ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM on a distant memory controller of this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .full_desc =
                "Counts all (cacheable) data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM on a distant memory controller of this socket when the system is in SNC (sub-NUMA cluster) mode.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.RFO_TO_CORE.L3_HIT_M",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1F80040022ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand reads for ownership (RFO), hardware prefetch RFOs (which bring data to L2), and software prefetches for exclusive ownership (PREFETCHW) that hit to a (M)odified cacheline in the L3 or snoop filter.",
            .full_desc =
                "Counts demand reads for ownership (RFO), hardware prefetch RFOs (which bring data to L2), and software prefetches for exclusive ownership (PREFETCHW) that hit to a (M)odified cacheline in the L3 or snoop filter.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.STREAMING_WR.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0x2AULL,
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
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x80080800ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts streaming stores that hit in the L3 or were snooped from another core's caches on the same socket.",
            .full_desc =
                "Counts streaming stores that hit in the L3 or were snooped from another core's caches on the same socket.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.STREAMING_WR.L3_MISS",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x94000800ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts streaming stores that missed the local socket's L1, L2, and L3 caches.",
            .full_desc =
                "Counts streaming stores that missed the local socket's L1, L2, and L3 caches.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.STREAMING_WR.L3_MISS_LOCAL",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x84000800ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts streaming stores that were not supplied by the local socket's L1, L2, or L3 caches and the cacheline is homed locally.",
            .full_desc =
                "Counts streaming stores that were not supplied by the local socket's L1, L2, or L3 caches and the cacheline is homed locally.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OCR.WRITE_ESTIMATE.MEMORY",
            .encoding =
                {
                    .code = 0x2AULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0xFBFF80822ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts Demand RFOs, ItoM's, PREFECTHW's, Hardware RFO Prefetches to the L1/L2 and Streaming stores that likely resulted in a store to Memory (DRAM or PMM)",
            .full_desc =
                "Counts Demand RFOs, ItoM's, PREFECTHW's, Hardware RFO Prefetches to the L1/L2 and Streaming stores that likely resulted in a store to Memory (DRAM or PMM)",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_REQUESTS.ALL_REQUESTS",
            .encoding =
                {
                    .code = 0x21ULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "OFFCORE_REQUESTS.ALL_REQUESTS",
            .full_desc = "OFFCORE_REQUESTS.ALL_REQUESTS",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_REQUESTS.DATA_RD",
            .encoding =
                {
                    .code = 0x21ULL,
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
            .id = "OFFCORE_REQUESTS.DEMAND_CODE_RD",
            .encoding =
                {
                    .code = 0x21ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cacheable and noncacheable code read requests",
            .full_desc =
                "Counts both cacheable and non-cacheable code read requests.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_REQUESTS.DEMAND_DATA_RD",
            .encoding =
                {
                    .code = 0x21ULL,
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
                    .code = 0x21ULL,
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
                    .code = 0x21ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts demand data read requests that miss the L3 cache.",
            .full_desc =
                "Counts demand data read requests that miss the L3 cache.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_CODE_RD",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x2ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles with offcore outstanding Code Reads transactions in the SuperQueue (SQ), queue to uncore.",
            .full_desc =
                "Counts the number of offcore outstanding Code Reads transactions in the super queue every cycle. The 'Offcore outstanding' state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_DATA_RD",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x1ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles where at least 1 outstanding demand data read request is pending.",
            .full_desc =
                "Cycles where at least 1 outstanding demand data read request is pending.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_RFO",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x4ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_RFO",
            .full_desc = "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DEMAND_RFO",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_REQUESTS_OUTSTANDING.DATA_RD",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "OFFCORE_REQUESTS_OUTSTANDING.DATA_RD",
            .full_desc = "OFFCORE_REQUESTS_OUTSTANDING.DATA_RD",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_CODE_RD",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Offcore outstanding Code Reads transactions in the SuperQueue (SQ), queue to uncore, every cycle.",
            .full_desc =
                "Counts the number of offcore outstanding Code Reads transactions in the super queue every cycle. The 'Offcore outstanding' state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_REQUESTS_OUTSTANDING.DEMAND_DATA_RD",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "For every cycle, increments by the number of outstanding demand data read requests pending.",
            .full_desc =
                "For every cycle, increments by the number of outstanding demand data read requests pending.   Requests are considered outstanding from the time they miss the core's L2 cache until the transaction completion message is sent to the requestor.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_REQUESTS_OUTSTANDING.L3_MISS_DEMAND_DATA_RD",
            .encoding =
                {
                    .code = 0x20ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "For every cycle, increments by the number of demand data read requests pending that are known to have missed the L3 cache.",
            .full_desc =
                "For every cycle, increments by the number of demand data read requests pending that are known to have missed the L3 cache.  Note that this does not capture all elapsed cycles while requests are outstanding - only cycles from when the requests were known by the requesting core to have missed the L3 cache.",
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
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RESOURCE_STALLS.SCOREBOARD",
            .encoding =
                {
                    .code = 0xA2ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts cycles where the pipeline is stalled due to serializing operations.",
            .full_desc =
                "Counts cycles where the pipeline is stalled due to serializing operations.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RS.EMPTY",
            .encoding =
                {
                    .code = 0xA5ULL,
                    .umask = 0x7ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when Reservation Station (RS) is empty for the thread.",
            .full_desc =
                "Counts cycles during which the reservation station (RS) is empty for this logical processor. This is usually caused when the front-end pipeline runs into starvation periods (e.g. branch mispredictions or i-cache misses)",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RS.EMPTY_COUNT",
            .encoding =
                {
                    .code = 0xA5ULL,
                    .umask = 0x7ULL,
                    .edge = true,
                    .inv = true,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts end of periods where the Reservation Station (RS) was empty.",
            .full_desc =
                "Counts end of periods where the Reservation Station (RS) was empty. Could be useful to closely sample on front-end latency issues (see the FRONTEND_RETIRED event of designated precise events)",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RS.EMPTY_RESOURCE",
            .encoding =
                {
                    .code = 0xA5ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Cycles when Reservation Station (RS) is empty due to a resource in the back-end",
            .full_desc =
                "Cycles when Reservation Station (RS) is empty due to a resource in the back-end",
            .default_sampling_period = 0xF4243ULL,
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
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of times an RTM execution aborted.",
            .full_desc = "Counts the number of times RTM abort was triggered.",
            .default_sampling_period = 0x186A3ULL,
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
                "Number of times an RTM execution aborted due to none of the previous 3 categories (e.g. interrupt)",
            .full_desc =
                "Counts the number of times an RTM execution aborted due to none of the previous 3 categories (e.g. interrupt).",
            .default_sampling_period = 0x186A3ULL,
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
                "Counts the number of times an RTM execution aborted due to various memory events (e.g. read/write capacity and conflicts).",
            .default_sampling_period = 0x186A3ULL,
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
                "Counts the number of times an RTM execution aborted due to incompatible memory type.",
            .default_sampling_period = 0x186A3ULL,
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
                "Counts the number of times an RTM execution aborted due to HLE-unfriendly instructions.",
            .default_sampling_period = 0x186A3ULL,
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
            .full_desc = "Counts the number of times RTM commit succeeded.",
            .default_sampling_period = 0x186A3ULL,
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
                "Counts the number of times we entered an RTM region. Does not count nested transactions.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "SQ_MISC.BUS_LOCK",
            .encoding =
                {
                    .code = 0x2CULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts bus locks, accounts for cache line split locks and UC locks.",
            .full_desc =
                "Counts the more expensive bus lock needed to enforce cache coherency for certain memory accesses that need to be done atomically.  Can be created by issuing an atomic instruction (via the LOCK prefix) which causes a cache line split or accesses uncacheable memory.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "SW_PREFETCH_ACCESS.NTA",
            .encoding =
                {
                    .code = 0x40ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of PREFETCHNTA instructions executed.",
            .full_desc =
                "Counts the number of PREFETCHNTA instructions executed.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "SW_PREFETCH_ACCESS.PREFETCHW",
            .encoding =
                {
                    .code = 0x40ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of PREFETCHW instructions executed.",
            .full_desc =
                "Counts the number of PREFETCHW instructions executed.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "SW_PREFETCH_ACCESS.T0",
            .encoding =
                {
                    .code = 0x40ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of PREFETCHT0 instructions executed.",
            .full_desc =
                "Counts the number of PREFETCHT0 instructions executed.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "SW_PREFETCH_ACCESS.T1_T2",
            .encoding =
                {
                    .code = 0x40ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of PREFETCHT1 or PREFETCHT2 instructions executed.",
            .full_desc =
                "Counts the number of PREFETCHT1 or PREFETCHT2 instructions executed.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "TOPDOWN.BR_MISPREDICT_SLOTS",
            .encoding =
                {
                    .code = 0xA4ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TMA slots wasted due to incorrect speculation by branch mispredictions",
            .full_desc =
                "Number of TMA slots that were wasted due to incorrect speculation by (any type of) branch mispredictions. This event estimates number of speculative operations that were issued but not retired as well as the out-of-order engine recovery past a branch misprediction.",
            .default_sampling_period = 0x989683ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "TOPDOWN.MEMORY_BOUND_SLOTS",
            .encoding =
                {
                    .code = 0xA4ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "TOPDOWN.MEMORY_BOUND_SLOTS",
            .full_desc = "TOPDOWN.MEMORY_BOUND_SLOTS",
            .default_sampling_period = 0x989683ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "TOPDOWN.SLOTS_P",
            .encoding =
                {
                    .code = 0xA4ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "TMA slots available for an unhalted logical processor. General counter - architectural event",
            .full_desc =
                "Counts the number of available slots for an unhalted logical processor. The event increments by machine-width of the narrowest pipeline as employed by the Top-down Microarchitecture Analysis method. The count is distributed among unhalted logical processors (hyper-threads) who share the same physical core.",
            .default_sampling_period = 0x989683ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "TX_MEM.ABORT_CAPACITY_READ",
            .encoding =
                {
                    .code = 0x54ULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Speculatively counts the number of TSX aborts due to a data capacity limitation for transactional reads",
            .full_desc =
                "Speculatively counts the number of Transactional Synchronization Extensions (TSX) aborts due to a data capacity limitation for transactional reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "TX_MEM.ABORT_CAPACITY_WRITE",
            .encoding =
                {
                    .code = 0x54ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Speculatively counts the number of TSX aborts due to a data capacity limitation for transactional writes.",
            .full_desc =
                "Speculatively counts the number of Transactional Synchronization Extensions (TSX) aborts due to a data capacity limitation for transactional writes.",
            .default_sampling_period = 0x186A3ULL,
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
            .full_desc =
                "Counts the number of times a TSX line had a cache conflict.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_DECODED.DEC0_UOPS",
            .encoding =
                {
                    .code = 0x76ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UOPS_DECODED.DEC0_UOPS",
            .full_desc = "UOPS_DECODED.DEC0_UOPS",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_DISPATCHED.PORT_0",
            .encoding =
                {
                    .code = 0xB2ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Uops executed on port 0",
            .full_desc = "Number of uops dispatch to execution  port 0.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_DISPATCHED.PORT_1",
            .encoding =
                {
                    .code = 0xB2ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Uops executed on port 1",
            .full_desc = "Number of uops dispatch to execution  port 1.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_DISPATCHED.PORT_2_3_10",
            .encoding =
                {
                    .code = 0xB2ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Uops executed on ports 2, 3 and 10",
            .full_desc =
                "Number of uops dispatch to execution ports 2, 3 and 10",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_DISPATCHED.PORT_4_9",
            .encoding =
                {
                    .code = 0xB2ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Uops executed on ports 4 and 9",
            .full_desc = "Number of uops dispatch to execution ports 4 and 9",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_DISPATCHED.PORT_5_11",
            .encoding =
                {
                    .code = 0xB2ULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Uops executed on ports 5 and 11",
            .full_desc = "Number of uops dispatch to execution ports 5 and 11",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_DISPATCHED.PORT_6",
            .encoding =
                {
                    .code = 0xB2ULL,
                    .umask = 0x40ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Uops executed on port 6",
            .full_desc = "Number of uops dispatch to execution  port 6.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_DISPATCHED.PORT_7_8",
            .encoding =
                {
                    .code = 0xB2ULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Uops executed on ports 7 and 8",
            .full_desc = "Number of uops dispatch to execution  ports 7 and 8.",
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
            .full_desc = "Counts the number of uops executed from any thread.",
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
                "Counts cycles when at least 1 micro-op is executed from any thread on physical core.",
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
                "Counts cycles when at least 2 micro-ops are executed from any thread on physical core.",
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
                "Counts cycles when at least 3 micro-ops are executed from any thread on physical core.",
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
                "Counts cycles when at least 4 micro-ops are executed from any thread on physical core.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED.CYCLES_GE_1",
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
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED.CYCLES_GE_2",
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
            .id = "UOPS_EXECUTED.CYCLES_GE_3",
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
            .id = "UOPS_EXECUTED.CYCLES_GE_4",
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
            .id = "UOPS_EXECUTED.STALLS",
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
                "Counts the number of uops to be executed per-thread each cycle.",
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
            .id = "UOPS_ISSUED.CYCLES",
            .encoding =
                {
                    .code = 0xAEULL,
                    .umask = 0x1ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UOPS_ISSUED.CYCLES",
            .full_desc = "UOPS_ISSUED.CYCLES",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_RETIRED.CYCLES",
            .encoding =
                {
                    .code = 0xC2ULL,
                    .umask = 0x2ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles with retired uop(s).",
            .full_desc = "Counts cycles where at least one uop has retired.",
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_RETIRED.HEAVY",
            .encoding =
                {
                    .code = 0xC2ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Retired uops except the last uop of each instruction.",
            .full_desc =
                "Counts the number of retired micro-operations (uops) except the last uop of each instruction. An instruction that is decoded into less than two uops does not contribute to the count.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_RETIRED.MS",
            .encoding =
                {
                    .code = 0xC2ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x8ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "UOPS_RETIRED.MS",
            .full_desc = "UOPS_RETIRED.MS",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_RETIRED.STALLS",
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
            .default_sampling_period = 0xF4243ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "XQ.FULL_CYCLES",
            .encoding =
                {
                    .code = 0x2DULL,
                    .umask = 0x1ULL,
                    .cmask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles the uncore cannot take further requests",
            .full_desc =
                "number of cycles when the thread is active and the uncore cannot take any further requests (for example prefetches, loads or stores initiated by the Core that miss the L2 cache).",
            .default_sampling_period = 0xF4243ULL,
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

} // namespace sapphirerapids_core
} // namespace facebook::hbt::perf_event::generated
