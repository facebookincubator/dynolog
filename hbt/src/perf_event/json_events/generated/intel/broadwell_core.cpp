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
namespace broadwell_core {
namespace {

/*
  Events from broadwell_core.json (744 events).

  Supported SKUs:
      - Arch: x86, Model: BDW id: 61
      - Arch: x86, Model: BDW id: 71
*/
constexpr std::array<StaticEventDef, 38> kAllowlistedEvents{{
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
            "This event counts all (macro) branch instructions retired.",
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
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Taken branch instructions retired.",
        .full_desc = "This event counts taken branch instructions retired.",
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
        .brief_desc = "All mispredicted macro branch instructions retired.",
        .full_desc =
            "This event counts all mispredicted macro branch instructions retired.",
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
        .brief_desc = "Reference cycles when the core is not in halt state.",
        .full_desc =
            "This event counts the number of reference cycles when the core is not in a halt state. The core enters the halt state when it is running the HLT instruction or the MWAIT instruction. This event is not affected by core frequency changes (for example, P states, TM2 transitions) but has the same incrementing frequency as the time stamp counter. This event can approximate elapsed time while the core was not in a halt state. This event has a constant ratio with the CPU_CLK_UNHALTED.REF_XCLK event. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events.  Note: On all current platforms this event stops counting during 'throttling (TM)' states duty off periods the processor is 'halted'.  This event is clocked by base clock (100 Mhz) on Sandy Bridge. The counter update is done at a lower clock rate then the core clock the overflow status bit for this counter may appear 'sticky'.  After the counter has overflowed and software clears the overflow status bit and resets the counter to less than MAX. The reset value to the counter is not clocked immediately so the overflow status bit will flip 'high (1)' and generate another PMI (if enabled) after which the reset value gets clocked into the counter. Therefore, software will get the interrupt, read the overflow status bit '1 for bit 34 while the counter value is less than MAX. Software should ignore this case.",
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
        .brief_desc = "Core cycles when the thread is not in halt state",
        .full_desc =
            "This event counts the number of core cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. This event is a component in many key event ratios. The core frequency may change from time to time due to transitions associated with Enhanced Intel SpeedStep Technology or TM2. For this reason this event may have a changing ratio with regards to time. When the core frequency is constant, this event can approximate elapsed time while the core was not in the halt state. It is counted on a dedicated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events.",
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
        .brief_desc = "Thread cycles when thread is not in halt state",
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
            "Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes of any page size.",
        .full_desc =
            "Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes of any page size.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
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
            "Store misses in all DTLB levels that cause completed page walks.",
        .full_desc =
            "Store misses in all DTLB levels that cause completed page walks.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
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
            "Number of SSE/AVX computational 128-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
        .full_desc =
            "Number of SSE/AVX computational 128-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
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
            "Number of SSE/AVX computational 128-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 4 calculations per element.",
        .full_desc =
            "Number of SSE/AVX computational 128-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
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
            "Number of SSE/AVX computational 256-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 4 calculations per element.",
        .full_desc =
            "Number of SSE/AVX computational 256-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
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
            "Number of SSE/AVX computational 256-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 8 calculations per element.",
        .full_desc =
            "Number of SSE/AVX computational 256-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
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
            "Number of SSE/AVX computational scalar double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.",
        .full_desc =
            "Number of SSE/AVX computational scalar double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
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
            "Number of SSE/AVX computational scalar single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.",
        .full_desc =
            "Number of SSE/AVX computational scalar single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ICACHE.IFDATA_STALL",
        .encoding =
            {
                .code = 0x80ULL,
                .umask = 0x4ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles where a code fetch is stalled due to L1 instruction-cache miss.",
        .full_desc =
            "This event counts cycles during which the demand fetch waits for data (wfdM104H) from L2 or iSB (opportunistic hit).",
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
            "Number of Instruction Cache, Streaming Buffer and Victim Cache Misses. Includes Uncacheable accesses.",
        .full_desc =
            "This event counts the number of instruction cache, streaming buffer and victim cache misses. Counting includes UC accesses.",
        .default_sampling_period = 0x30D43ULL,
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
            "This event counts the number of uops not delivered to Resource Allocation Table (RAT) per thread adding 4  x when Resource Allocation Table (RAT) is not stalled and Instruction Decode Queue (IDQ) delivers x uops to Resource Allocation Table (RAT) (where x belongs to {0,1,2,3}). Counting does not cover cases when:  a. IDQ-Resource Allocation Table (RAT) pipe serves the other thread;  b. Resource Allocation Table (RAT) is stalled for the thread (including uop drops and clear BE conditions);   c. Instruction Decode Queue (IDQ) delivers four uops.",
        .default_sampling_period = 0x1E8483ULL,
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
            "Core cycles the allocator was stalled due to recovery from earlier clear event for this thread (e.g. misprediction or memory nuke)",
        .full_desc =
            "Cycles checkpoints in Resource Allocation Table (RAT) are recovering from JEClear or machine clear.",
        .default_sampling_period = 0x1E8483ULL,
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
            "Misses in all ITLB levels that cause completed page walks.",
        .full_desc =
            "Misses in all ITLB levels that cause completed page walks.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
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
            "This event counts L1D data line replacements including opportunistic replacements, and replacements that require stall-for-replace or block-for-replace.",
        .default_sampling_period = 0x1E8483ULL,
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
        .full_desc =
            "This event counts the number of L2 cache lines filling the L2. Counting does not cover rejects.",
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
        .full_desc = "This event counts the total number of L2 code requests.",
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
        .brief_desc = "All requests that miss L2 cache.",
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
            "Cases when loads get true Block-on-Store blocking code preventing store forwarding",
        .full_desc =
            "This event counts how many times the load operation got the true Block-on-Store blocking code preventing store forwarding. This includes cases when:  - preceding store conflicts with the load (incomplete overlap);  - store forwarding is impossible due to u-arch limitations;  - preceding lock RMW operations are not forwarded;  - store has the no-forward bit set (uncacheable/page-split/masked stores);  - all-blocking stores are used (mostly, fences and port I/O); and others. The most common case is a load blocked due to its address range overlapping with a preceding smaller uncompleted store. Note: This event does not take into account cases of out-of-SW-control (for example, SbTailHit), unknown physical STA, and cases of blocking loads on store due to being non-WB memory type or a lock. These cases are covered by other events. See the table of not supported store forwards in the Optimization Guide.",
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
        .brief_desc = "Core-originated cacheable demand requests missed L3",
        .full_desc =
            "This event counts core-originated cacheable demand requests that miss the last level cache (LLC). Demand requests include loads, RFOs, and hardware prefetches from L1D, and instruction fetches from IFU.",
        .default_sampling_period = 0x186A3ULL,
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
            "This event counts the number of offcore outstanding cacheable Core Data Read transactions in the super queue every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM76",
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
            "This event counts cycles when offcore outstanding cacheable Core Data Read transactions are present in the super queue. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM76",
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
            "Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction.",
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
            "This event counts the number of Uops issued by the Resource Allocation Table (RAT) to the reservation station (RS).",
        .default_sampling_period = 0x1E8483ULL,
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
        .brief_desc = "Actually retired uops.",
        .full_desc =
            "This event counts all actually retired uops. Counting increments by two for micro-fused uops, and by one for macro-fused and other uops. Maximal increment value for one cycle is eight.",
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
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Retirement slots used.",
        .full_desc = "This event counts the number of retirement slots used.",
        .default_sampling_period = 0x1E8483ULL,
    },
}};
static_assert(isStaticEventDefTableSorted(kAllowlistedEvents));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
constexpr std::array<StaticEventDef, 512> kFullOnlyEvents0{{
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
            "This event counts the number of the divide operations executed. Uses edge-detect and a cmask value of 1 on ARITH.FPU_DIV_ACTIVE to get the number of the divide operations executed.",
        .default_sampling_period = 0x1E8483ULL,
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
            "This event counts both taken and not taken speculative and retired branch instructions.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc =
            "This event counts both taken and not taken speculative and retired macro-conditional branch instructions.",
        .default_sampling_period = 0x30D43ULL,
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
            "This event counts both taken and not taken speculative and retired macro-unconditional branch instructions, excluding calls and indirects.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc =
            "This event counts both taken and not taken speculative and retired direct near calls.",
        .default_sampling_period = 0x30D43ULL,
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
            "This event counts both taken and not taken speculative and retired indirect branches excluding calls and return branches.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc =
            "This event counts both taken and not taken speculative and retired indirect branches that have a return mnemonic.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc =
            "This event counts not taken macro-conditional branch instructions.",
        .default_sampling_period = 0x30D43ULL,
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
            "This event counts taken speculative and retired macro-conditional branch instructions.",
        .default_sampling_period = 0x30D43ULL,
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
            "This event counts taken speculative and retired macro-conditional branch instructions excluding calls and indirect branches.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc =
            "This event counts taken speculative and retired direct near calls.",
        .default_sampling_period = 0x30D43ULL,
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
            "This event counts taken speculative and retired indirect branches excluding calls and return branches.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc =
            "This event counts taken speculative and retired indirect calls including both register and memory indirect.",
        .default_sampling_period = 0x30D43ULL,
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
            "This event counts taken speculative and retired indirect branches that have a return mnemonic.",
        .default_sampling_period = 0x30D43ULL,
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
            "All (macro) branch instructions retired. (Precise Event - PEBS)",
        .full_desc =
            "This is a precise version of BR_INST_RETIRED.ALL_BRANCHES that counts all (macro) branch instructions retired.",
        .default_sampling_period = 0x61A89ULL,
        .errata = "BDW98",
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
        .full_desc =
            "This event counts conditional branch instructions retired.",
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
        .full_desc = "This event counts far branch instructions retired.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "BDW98",
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
        .full_desc =
            "This event counts both direct and indirect near call instructions retired.",
        .default_sampling_period = 0x186A7ULL,
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
            "This event counts both direct and indirect macro near call instructions retired (captured in ring 3).",
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
        .features =
            StaticEventDef::IntelFeatures{
                .pebs = 1,
            },
        .brief_desc = "Return instructions retired.",
        .full_desc = "This event counts return instructions retired.",
        .default_sampling_period = 0x186A7ULL,
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
        .full_desc = "This event counts not taken branch instructions retired.",
        .default_sampling_period = 0x61A89ULL,
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
            "This event counts both taken and not taken speculative and retired mispredicted macro conditional branch instructions.",
        .default_sampling_period = 0x30D43ULL,
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
            "This event counts both taken and not taken mispredicted indirect branches excluding calls and returns.",
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
            "This event counts not taken speculative and retired mispredicted macro conditional branch instructions.",
        .default_sampling_period = 0x30D43ULL,
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
            "This event counts taken speculative and retired mispredicted macro conditional branch instructions.",
        .default_sampling_period = 0x30D43ULL,
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
            "This event counts taken speculative and retired mispredicted indirect branches excluding calls and returns.",
        .default_sampling_period = 0x30D43ULL,
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
            "This event counts taken speculative and retired mispredicted indirect branches that have a return mnemonic.",
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
        .brief_desc =
            "Mispredicted macro branch instructions retired. (Precise Event - PEBS)",
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
        .brief_desc = "Mispredicted conditional branch instructions retired.",
        .full_desc =
            "This event counts mispredicted conditional branch instructions retired.",
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
            "number of near branch instructions retired that were mispredicted and taken.",
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
            "This event counts mispredicted return instructions retired.",
        .default_sampling_period = 0x186A7ULL,
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
        .full_desc =
            "This event counts the unhalted core cycles during which the thread is in the ring 0 privileged mode.",
        .default_sampling_period = 0x1E8483ULL,
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
            "This event counts when there is a transition from ring 1,2 or 3 to ring0.",
        .default_sampling_period = 0x186A7ULL,
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
        .full_desc =
            "This event counts unhalted core cycles during which the thread is in rings 1, 2, or 3.",
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
            "Count XClk pulses when this thread is unhalted and the other thread is halted.",
        .full_desc =
            "Count XClk pulses when this thread is unhalted and the other thread is halted.",
        .default_sampling_period = 0x186A3ULL,
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
            "This is a fixed-frequency event programmed to general counters. It counts when the core is unhalted at 100 Mhz.",
        .default_sampling_period = 0x186A3ULL,
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
        .default_sampling_period = 0x186A3ULL,
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
        .default_sampling_period = 0x186A3ULL,
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
            "Reference cycles when the thread is unhalted (counts at 100 MHz rate).",
        .default_sampling_period = 0x186A3ULL,
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
        .default_sampling_period = 0x186A3ULL,
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
        .brief_desc = "Cycles while L1 cache miss demand load is outstanding.",
        .full_desc =
            "Counts number of cycles the CPU has at least one pending  demand load request missing the L1 data cache.",
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
        .brief_desc = "Cycles while L2 cache miss demand load is outstanding.",
        .full_desc = "Cycles while L2 cache miss demand load is outstanding.",
        .default_sampling_period = 0x1E8483ULL,
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
        .brief_desc = "Cycles while L2 cache miss demand load is outstanding.",
        .full_desc =
            "Counts number of cycles the CPU has at least one pending  demand* load request missing the L2 cache.",
        .default_sampling_period = 0x1E8483ULL,
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
        .brief_desc = "Cycles while memory subsystem has an outstanding load.",
        .full_desc =
            "Counts number of cycles the CPU has at least one pending  demand load request (that is cycles with non-completed load waiting for its data from memory subsystem).",
        .default_sampling_period = 0x1E8483ULL,
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
        .full_desc =
            "Counts number of cycles nothing is executed on any execution port.",
        .default_sampling_period = 0x1E8483ULL,
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
        .brief_desc =
            "Execution stalls while L1 cache miss demand load is outstanding.",
        .full_desc =
            "Counts number of cycles nothing is executed on any execution port, while there was at least one pending demand load request missing the L1 data cache.",
        .default_sampling_period = 0x1E8483ULL,
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
            "Execution stalls while L2 cache miss demand load is outstanding.",
        .full_desc =
            "Counts number of cycles nothing is executed on any execution port, while there was at least one pending demand* load request missing the L2 cache.(as a footprint) * includes also L1 HW prefetch requests that may or may not be required by demands.",
        .default_sampling_period = 0x1E8483ULL,
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
        .brief_desc =
            "Execution stalls while memory subsystem has an outstanding load.",
        .full_desc =
            "Counts number of cycles nothing is executed on any execution port, while there was at least one pending demand load request.",
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
            "This event counts Decode Stream Buffer (DSB)-to-MITE switch true penalty cycles. These cycles do not include uops routed through because of the switch itself, for example, when Instruction Decode Queue (IDQ) pre-allocation is unavailable, or Instruction Decode Queue (IDQ) is full. SBD-to-MITE switch true penalty cycles happen after the merge mux (MM) receives Decode Stream Buffer (DSB) Sync-indication until receiving the first MITE uop.  MM is placed before Instruction Decode Queue (IDQ) to merge uops being fed from the MITE and Decode Stream Buffer (DSB) paths. Decode Stream Buffer (DSB) inserts the Sync-indication whenever a Decode Stream Buffer (DSB)-to-MITE switch occurs. Penalty: A Decode Stream Buffer (DSB) hit followed by a Decode Stream Buffer (DSB) miss can cost up to six cycles in which no uops are delivered to the IDQ. Most often, such switches from the Decode Stream Buffer (DSB) to the legacy pipeline cost 02 cycles.",
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
        .brief_desc = "Load misses in all DTLB levels that cause page walks",
        .full_desc =
            "This event counts load misses in all DTLB levels that cause page walks of any page size (4K/2M/4M/1G).",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.STLB_HIT",
        .encoding =
            {
                .code = 0x8ULL,
                .umask = 0x60ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Load operations that miss the first DTLB level but hit the second and do not cause page walks.",
        .full_desc =
            "Load operations that miss the first DTLB level but hit the second and do not cause page walks.",
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.STLB_HIT_2M",
        .encoding =
            {
                .code = 0x8ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Load misses that miss the  DTLB and hit the STLB (2M).",
        .full_desc = "Load misses that miss the  DTLB and hit the STLB (2M).",
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.STLB_HIT_4K",
        .encoding =
            {
                .code = 0x8ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Load misses that miss the  DTLB and hit the STLB (4K).",
        .full_desc = "Load misses that miss the  DTLB and hit the STLB (4K).",
        .default_sampling_period = 0x1E8483ULL,
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
            "Load miss in all TLB levels causes a page walk that completes. (1G)",
        .full_desc =
            "This event counts load misses in all DTLB levels that cause a completed page walk (1G  page size). The page walk can end with or without a fault.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM69",
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
            "Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes (2M/4M).",
        .full_desc =
            "This event counts load misses in all DTLB levels that cause a completed page walk (2M and 4M page sizes). The page walk can end with or without a fault.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM69",
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
            "Demand load Miss in all translation lookaside buffer (TLB) levels causes a page walk that completes (4K).",
        .full_desc =
            "This event counts load misses in all DTLB levels that cause a completed page walk (4K page size). The page walk can end with or without a fault.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM69",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_LOAD_MISSES.WALK_DURATION",
        .encoding =
            {
                .code = 0x8ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles when PMH is busy with page walks",
        .full_desc =
            "This event counts the number of cycles while PMH is busy with the page walk.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM69",
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
            "This event counts store misses in all DTLB levels that cause page walks of any page size (4K/2M/4M/1G).",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_STORE_MISSES.STLB_HIT",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0x60ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Store operations that miss the first TLB level but hit the second and do not cause page walks.",
        .full_desc =
            "Store operations that miss the first TLB level but hit the second and do not cause page walks.",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_STORE_MISSES.STLB_HIT_2M",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Store misses that miss the  DTLB and hit the STLB (2M).",
        .full_desc = "Store misses that miss the  DTLB and hit the STLB (2M).",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_STORE_MISSES.STLB_HIT_4K",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Store misses that miss the  DTLB and hit the STLB (4K).",
        .full_desc = "Store misses that miss the  DTLB and hit the STLB (4K).",
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
            "Store misses in all DTLB levels that cause completed page walks (1G)",
        .full_desc =
            "This event counts store misses in all DTLB levels that cause a completed page walk (1G  page size). The page walk can end with or without a fault.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
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
            "Store misses in all DTLB levels that cause completed page walks (2M/4M)",
        .full_desc =
            "This event counts store misses in all DTLB levels that cause a completed page walk (2M and 4M page sizes). The page walk can end with or without a fault.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
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
            "Store miss in all TLB levels causes a page walk that completes. (4K)",
        .full_desc =
            "This event counts store misses in all DTLB levels that cause a completed page walk (4K page size). The page walk can end with or without a fault.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "DTLB_STORE_MISSES.WALK_DURATION",
        .encoding =
            {
                .code = 0x49ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles when PMH is busy with page walks",
        .full_desc =
            "This event counts the number of cycles while PMH is busy with the page walk.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
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
        .brief_desc = "Cycle count for an Extended Page table walk.",
        .full_desc =
            "This event counts cycles for an extended page table walk. The Extended Page directory cache differs from standard TLB caches by the operating system that use it. Virtual machine operating systems use the extended page directory cache, while guest operating systems use the standard TLB caches.",
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
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_ARITH_INST_RETIRED.DOUBLE",
        .encoding =
            {
                .code = 0xC7ULL,
                .umask = 0x15ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of SSE/AVX computational double precision floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* scalar and packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.",
        .full_desc =
            "Number of SSE/AVX computational double precision floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* scalar and packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.",
        .default_sampling_period = 0x1E8486ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_ARITH_INST_RETIRED.PACKED",
        .encoding =
            {
                .code = 0xC7ULL,
                .umask = 0x3CULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of SSE/AVX computational packed floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* packed double and single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.",
        .full_desc =
            "Number of SSE/AVX computational packed floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* packed double and single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.",
        .default_sampling_period = 0x1E8484ULL,
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
            "Number of SSE/AVX computational scalar floating-point instructions retired; some instructions will count twice as noted below. Each count represents 1 computation operation.   Applies to SSE* and AVX* scalar double and single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.",
        .full_desc =
            "Number of SSE/AVX computational scalar single precision and double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "FP_ARITH_INST_RETIRED.SINGLE",
        .encoding =
            {
                .code = 0xC7ULL,
                .umask = 0x2AULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of SSE/AVX computational single precision floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* scalar and packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.",
        .full_desc =
            "Number of SSE/AVX computational single precision floating-point instructions retired; some instructions will count twice as noted below. Applies to SSE* and AVX* scalar and packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform multiple calculations per element.",
        .default_sampling_period = 0x1E8485ULL,
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
        .brief_desc = "Number of any Vector retired FP arithmetic instructions",
        .full_desc = "Number of any Vector retired FP arithmetic instructions",
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
            "This event counts cycles with any input and output SSE or x87 FP assist. If an input and output assist are detected on the same cycle the event increments by 1.",
        .default_sampling_period = 0x186A3ULL,
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
        .full_desc =
            "This event counts any input SSE* FP assist - invalid operation, denormal operand, dividing by zero, SNaN operand. Counting includes only cases involving penalties that required micro-code assist intervention.",
        .default_sampling_period = 0x186A3ULL,
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
        .full_desc =
            "This event counts the number of SSE* floating point (FP) micro-code assist (numeric overflow/underflow) when the output value (destination register) is invalid. Counting covers only cases involving penalties that require micro-code assist intervention.",
        .default_sampling_period = 0x186A3ULL,
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
        .full_desc =
            "This event counts x87 floating point (FP) micro-code assist (invalid operation, denormal operand, SNaN operand) when the input value (one of the source operands to an FP instruction) is invalid.",
        .default_sampling_period = 0x186A3ULL,
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
        .full_desc =
            "This event counts the number of x87 floating point (FP) micro-code assist (numeric overflow/underflow, inexact result) when the output value (destination register) is invalid.",
        .default_sampling_period = 0x186A3ULL,
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
        .brief_desc = "Number of times HLE abort was triggered",
        .full_desc = "Number of times HLE abort was triggered.",
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "HLE_RETIRED.ABORTED_MISC1",
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
            "Number of times an HLE abort was attributed to a Memory condition (See TSX_Memory event for additional details).",
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "HLE_RETIRED.ABORTED_MISC2",
        .encoding =
            {
                .code = 0xC8ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of times an HLE execution aborted due to uncommon conditions",
        .full_desc = "Number of times the TSX watchdog signaled an HLE abort.",
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "HLE_RETIRED.ABORTED_MISC3",
        .encoding =
            {
                .code = 0xC8ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of times an HLE execution aborted due to HLE-unfriendly instructions",
        .full_desc =
            "Number of times a disallowed operation caused an HLE abort.",
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "HLE_RETIRED.ABORTED_MISC4",
        .encoding =
            {
                .code = 0xC8ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of times an HLE execution aborted due to incompatible memory type",
        .full_desc = "Number of times HLE caused a fault.",
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "HLE_RETIRED.ABORTED_MISC5",
        .encoding =
            {
                .code = 0xC8ULL,
                .umask = 0x80ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Number of times an HLE execution aborted due to none of the previous 4 categories (e.g. interrupts)",
        .full_desc =
            "Number of times HLE aborted and was not due to the abort conditions in subevents 3-6.",
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
        .brief_desc = "Number of times HLE commit succeeded",
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
        .brief_desc =
            "Number of times we entered an HLE region; does not count nested transactions",
        .full_desc =
            "Number of times we entered an HLE region  does not count nested transactions.",
        .default_sampling_period = 0x1E8483ULL,
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
            "This event counts the number of both cacheable and noncacheable Instruction Cache, Streaming Buffer and Victim Cache Reads including UC fetches.",
        .default_sampling_period = 0x1E8483ULL,
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
        .full_desc =
            "This event counts the number of cycles 4  uops were  delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may bypass the IDQ.",
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
        .brief_desc = "Cycles Decode Stream Buffer (DSB) is delivering any Uop",
        .full_desc =
            "This event counts the number of cycles  uops were  delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may bypass the IDQ.",
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
            "This event counts the number of cycles 4  uops were  delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may bypass the IDQ. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).",
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
            "This event counts the number of cycles  uops were delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may bypass the IDQ. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).",
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
            "This event counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may bypass the IDQ.",
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
            "This event counts the number of uops delivered to Instruction Decode Queue (IDQ) from the Decode Stream Buffer (DSB) path. Counting includes uops that may bypass the IDQ.",
        .default_sampling_period = 0x1E8483ULL,
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
        .full_desc =
            "This counts the number of cycles that the instruction decoder queue is empty and can indicate that the application may be bound in the front end.  It does not determine whether there are uops being delivered to the Alloc stage since uops can be delivered by bypass skipping the Instruction Decode Queue (IDQ) when it is empty.",
        .default_sampling_period = 0x1E8483ULL,
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
        .full_desc =
            "This event counts the number of uops delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may bypass the IDQ. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).",
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
            "This event counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may bypass the IDQ.",
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
            "This event counts the number of uops delivered to Instruction Decode Queue (IDQ) from the MITE path. Counting includes uops that may bypass the IDQ. This also means that uops are not being delivered from the Decode Stream Buffer (DSB).",
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
            "This event counts cycles during which uops are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may bypass the IDQ. Uops maybe initiated by Decode Stream Buffer (DSB) or MITE.",
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
            "This event counts cycles during which uops initiated by Decode Stream Buffer (DSB) are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may bypass the IDQ.",
        .default_sampling_period = 0x1E8483ULL,
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
            "This event counts the number of deliveries to Instruction Decode Queue (IDQ) initiated by Decode Stream Buffer (DSB) while the Microcode Sequencer (MS) is busy. Counting includes uops that may bypass the IDQ.",
        .default_sampling_period = 0x1E8483ULL,
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
            "This event counts the number of uops initiated by Decode Stream Buffer (DSB) that are being delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may bypass the IDQ.",
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
            "This event counts the number of uops initiated by MITE and delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may bypass the IDQ.",
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
            "Number of switches from DSB (Decode Stream Buffer) or MITE (legacy decode pipeline) to the Microcode Sequencer.",
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
            "This event counts the total number of uops delivered to Instruction Decode Queue (IDQ) while the Microcode Sequencer (MS) is busy. Counting includes uops that may bypass the IDQ. Uops maybe initiated by Decode Stream Buffer (DSB) or MITE.",
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
            "This event counts, on the per-thread basis, cycles when no uops are delivered to Resource Allocation Table (RAT). IDQ_Uops_Not_Delivered.core =4.",
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
            "This event counts, on the per-thread basis, cycles when less than 1 uop is  delivered to Resource Allocation Table (RAT). IDQ_Uops_Not_Delivered.core >=3.",
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
        .full_desc = "Cycles with less than 2 uops delivered by the front end.",
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
        .full_desc = "Cycles with less than 3 uops delivered by the front end.",
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
            "Stalls caused by changing prefix length of the instruction.",
        .full_desc =
            "This event counts stalls occurred due to changing prefix length (66, 67 or REX.W when they change the length of the decoded instruction). Occurrences counting is proportional to the number of prefixes in a 16B-line. This may result in the following penalties: three-cycle penalty for each LCP in a 16-byte chunk.",
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
            "This event counts the number of instructions retired from execution. For instructions that consist of multiple micro-ops, this event counts the retirement of the last micro-op of the instruction. Counting continues during hardware interrupts, traps, and inside interrupt handlers.  Notes: INST_RETIRED.ANY is counted by a designated fixed counter, leaving the four (eight when Hyperthreading is disabled) programmable counters available for other events. INST_RETIRED.ANY_P is counted by a programmable counter and it is an architectural performance event.  Counting: Faulting executions of GETSEC/VM entry/VM Exit/MWait will not count as retired instructions.",
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
            "Number of instructions retired. General Counter   - architectural event",
        .full_desc =
            "This event counts the number of instructions (EOMs) retired. Counting covers macro-fused instructions individually (that is, increments by two).",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM61",
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
            "This is a precise version (that is, uses PEBS) of the event that counts instructions retired.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM11, BDM55",
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
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "FP operations  retired. X87 FP operations that have no exceptions:",
        .full_desc =
            "This event counts FP operations retired. For X87 FP operations that have no exceptions counting also includes flows that have several X87, or flows that use X87 uops in the exception handling.",
        .default_sampling_period = 0x1E8483ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "INT_MISC.RAT_STALL_CYCLES",
        .encoding =
            {
                .code = 0xDULL,
                .umask = 0x8ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles when Resource Allocation Table (RAT) external stall is sent to Instruction Decode Queue (IDQ) for the thread",
        .full_desc =
            "This event counts the number of cycles during which Resource Allocation Table (RAT) external stall is sent to Instruction Decode Queue (IDQ) for the current thread. This also includes the cycles during which the Allocator is serving another thread.",
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
            "This event counts the number of flushes of the big or small ITLB pages. Counting include both TLB Flush (covering all sets) and TLB Set Clear (set-specific).",
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
            "This event counts store misses in all DTLB levels that cause page walks of any page size (4K/2M/4M/1G).",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISSES.STLB_HIT",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x60ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Operations that miss the first ITLB level but hit the second and do not cause any page walks.",
        .full_desc =
            "Operations that miss the first ITLB level but hit the second and do not cause any page walks.",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISSES.STLB_HIT_2M",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x40ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Code misses that miss the  DTLB and hit the STLB (2M).",
        .full_desc = "Code misses that miss the  DTLB and hit the STLB (2M).",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISSES.STLB_HIT_4K",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x20ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Core misses that miss the  DTLB and hit the STLB (4K).",
        .full_desc = "Core misses that miss the  DTLB and hit the STLB (4K).",
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
            "Store miss in all TLB levels causes a page walk that completes. (1G)",
        .full_desc =
            "This event counts store misses in all DTLB levels that cause a completed page walk (1G  page size). The page walk can end with or without a fault.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
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
            "This event counts store misses in all DTLB levels that cause a completed page walk (2M and 4M page sizes). The page walk can end with or without a fault.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
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
            "This event counts store misses in all DTLB levels that cause a completed page walk (4K page size). The page walk can end with or without a fault.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "ITLB_MISSES.WALK_DURATION",
        .encoding =
            {
                .code = 0x85ULL,
                .umask = 0x10ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Cycles when PMH is busy with page walks",
        .full_desc =
            "This event counts the number of cycles while PMH is busy with the page walk.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM69",
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
            "This event counts duration of L1D miss outstanding, that is each cycle number of Fill Buffers (FB) outstanding required by Demand Reads. FB either is held by demand loads, or it is held by non-demand loads and gets hit at least once by demand. The valid outstanding interval is defined until the FB deallocation by one of the following ways: from FB allocation, if FB is allocated by demand; from the demand Hit FB, if it is allocated by hardware or software prefetch. Note: In the L1D, a Demand Read contains cacheable or noncacheable demand loads, including ones causing cache-line splits and reads due to page walks resulted from any request type.",
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
            "This event counts duration of L1D miss outstanding in cycles.",
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
        .id = "L2_DEMAND_RQSTS.WB_HIT",
        .encoding =
            {
                .code = 0x27ULL,
                .umask = 0x50ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Not rejected writebacks that hit L2 cache",
        .full_desc =
            "This event counts the number of WB requests that hit L2 cache.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc =
            "This event counts the number of L2 cache lines in the Exclusive state filling the L2. Counting does not cover rejects.",
        .default_sampling_period = 0x186A3ULL,
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
        .full_desc =
            "This event counts the number of L2 cache lines in the Invalidate state filling the L2. Counting does not cover rejects.",
        .default_sampling_period = 0x186A3ULL,
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
        .full_desc =
            "This event counts the number of L2 cache lines in the Shared state filling the L2. Counting does not cover rejects.",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_LINES_OUT.DEMAND_CLEAN",
        .encoding =
            {
                .code = 0xF2ULL,
                .umask = 0x5ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Clean L2 cache lines evicted by demand.",
        .full_desc = "Clean L2 cache lines evicted by demand.",
        .default_sampling_period = 0x186A3ULL,
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
            "This event counts the number of demand Data Read requests (including requests from L1D hardware prefetchers). These loads may hit or miss L2 cache. Only non rejected loads are counted.",
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
        .brief_desc = "Demand requests that miss L2 cache.",
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
        .brief_desc = "Demand requests to L2 cache.",
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
        .brief_desc = "Requests from L2 hardware prefetchers",
        .full_desc =
            "This event counts the total number of requests from the L2 hardware prefetchers.",
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
            "This event counts the total number of RFO (read for ownership) requests to L2 cache. L2 RFO requests include both L1D demand RFO misses as well as L1D RFO prefetches.",
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
        .brief_desc = "L2 cache hits when fetching instructions, code reads.",
        .full_desc = "L2 cache hits when fetching instructions, code reads.",
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
        .brief_desc = "L2 cache misses when fetching instructions.",
        .full_desc = "L2 cache misses when fetching instructions.",
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
            "Counts the number of demand Data Read requests, initiated by load instructions, that hit L2 cache.",
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
            "This event counts the number of demand Data Read requests that miss L2 cache. Only not rejected loads are counted.",
        .default_sampling_period = 0x30D43ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.L2_PF_HIT",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0xD0ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 prefetch requests that hit L2 cache",
        .full_desc =
            "This event counts the number of requests from the L2 hardware prefetchers that hit L2 cache. L3 prefetch new types.",
        .default_sampling_period = 0x30D43ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "L2_RQSTS.L2_PF_MISS",
        .encoding =
            {
                .code = 0x24ULL,
                .umask = 0x30ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "L2 prefetch requests that miss L2 cache",
        .full_desc =
            "This event counts the number of requests from the L2 hardware prefetchers that miss L2 cache.",
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
        .brief_desc = "All L2 requests.",
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
        .brief_desc = "RFO requests that hit L2 cache.",
        .full_desc = "RFO requests that hit L2 cache.",
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
        .brief_desc = "RFO requests that miss L2 cache.",
        .full_desc = "RFO requests that miss L2 cache.",
        .default_sampling_period = 0x30D43ULL,
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
        .brief_desc = "L2 or L3 HW prefetches that access L2 cache",
        .full_desc =
            "This event counts L2 or L3 HW prefetches that access L2 cache including rejects.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc =
            "This event counts transactions that access the L2 pipe including snoops, pagewalks, and so on.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc =
            "This event counts the number of L2 cache accesses when fetching instructions.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc =
            "This event counts Demand Data Read requests that access L2 cache, including rejects.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc = "This event counts L1D writebacks that access L2 cache.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc = "This event counts L2 fill requests that access L2 cache.",
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
        .full_desc = "This event counts L2 writebacks that access L2 cache.",
        .default_sampling_period = 0x30D43ULL,
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
        .full_desc =
            "This event counts Read for Ownership (RFO) requests that access L2 cache.",
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
            "This event counts the number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.",
        .full_desc =
            "This event counts the number of times that split load operations are temporarily blocked because all resources for handling the split accesses are in use.",
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
        .brief_desc = "False dependencies in MOB due to partial compare",
        .full_desc =
            "This event counts false dependencies in MOB when the partial comparison upon loose net check and dependency was resolved by the Enhanced Loose net mechanism. This may not result in high performance penalties. Loose net checks can fail when loads and stores are 4k aliased.",
        .default_sampling_period = 0x186A3ULL,
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
            "This event counts all not software-prefetch load dispatches that hit the fill buffer (FB) allocated for the hardware prefetch.",
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
            "Not software-prefetch load dispatches that hit FB allocated for software prefetch",
        .full_desc =
            "This event counts all not software-prefetch load dispatches that hit the fill buffer (FB) allocated for the software prefetch. It can also be incremented by some lock instructions. So it should only be used with profiling so that the locks can be excluded by asm inspection of the nearby instructions.",
        .default_sampling_period = 0x186A3ULL,
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
        .full_desc =
            "This event counts the number of cycles when the L1D is locked. It is a superset of the 0x1 mask (BUS_LOCK_CLOCKS.BUS_LOCK_DURATION).",
        .default_sampling_period = 0x1E8483ULL,
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
            "This event counts cycles in which the L1 and L2 are locked due to a UC lock or split lock. A lock is asserted in case of locked memory access, due to noncacheable memory, locked operation that spans two cache lines, or a page walk from the noncacheable page table. L1D and L2 locks have a very high performance penalty and it is highly recommended to avoid such access.",
        .default_sampling_period = 0x1E8483ULL,
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
            "This event counts core-originated cacheable demand requests that refer to the last level cache (LLC). Demand requests include loads, RFOs, and hardware prefetches from L1D, and instruction fetches from IFU.",
        .default_sampling_period = 0x186A3ULL,
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
        .id = "MACHINE_CLEARS.CYCLES",
        .encoding =
            {
                .code = 0xC3ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x0ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Cycles there was a Nuke. Account for both thread-specific and All Thread Nukes.",
        .full_desc =
            "This event counts both thread-specific (TS) and all-thread (AT) nukes.",
        .default_sampling_period = 0x1E8483ULL,
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
            "This event counts the number of memory ordering Machine Clears detected. Memory Ordering Machine Clears can result from one of the following: 1. memory disambiguation, 2. external snoop, or 3. cross SMT-HW-thread snoop (stores) hitting load buffer.",
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
            "This event counts self-modifying code (SMC) detected, which causes a machine clear.",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_HIT",
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
            "Retired load uops which data sources were L3 and cross-core snoop hits in on-pkg core cache.",
        .full_desc =
            "This event counts retired load uops which data sources were L3 hit and a cross-core snoop hit in the on-pkg core cache.",
        .default_sampling_period = 0x4E2BULL,
        .errata = "BDM100",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_HITM",
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
            "Retired load uops which data sources were HitM responses from shared L3.",
        .full_desc =
            "This event counts retired load uops which data sources were HitM responses from a core on same socket (shared L3).",
        .default_sampling_period = 0x4E2BULL,
        .errata = "BDM100",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_MISS",
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
            "Retired load uops which data sources were L3 hit and cross-core snoop missed in on-pkg core cache.",
        .full_desc =
            "This event counts retired load uops which data sources were L3 Hit and a cross-core snoop missed in the on-pkg core cache.",
        .default_sampling_period = 0x4E2BULL,
        .errata = "BDM100",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_L3_HIT_RETIRED.XSNP_NONE",
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
            "Retired load uops which data sources were hits in L3 without snoops required.",
        .full_desc =
            "This event counts retired load uops which data sources were hits in the last-level (L3) cache without snoops required.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM100",
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
        .features =
            StaticEventDef::IntelFeatures{
                .data_la = true,
                .pebs = 1,
            },
        .brief_desc =
            "Data from local DRAM either Snoop not needed or Snoop Miss (RspI)",
        .full_desc =
            "Retired load uop whose Data Source was: local DRAM either Snoop not needed or Snoop Miss (RspI).",
        .default_sampling_period = 0x186A7ULL,
        .errata = "BDE70, BDM100",
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
                .data_la = true,
                .pebs = 1,
            },
        .brief_desc =
            "Retired load uops which data sources were load uops missed L1 but hit FB due to preceding miss to the same cache line with data not ready.",
        .full_desc =
            "This event counts retired load uops which data sources were load uops missed L1 but hit a fill buffer due to a preceding miss to the same cache line with the data not ready. Note: Only two data-sources of L1/FB are applicable for AVX-256bit  even though the corresponding AVX load could be serviced by a deeper level in the memory hierarchy. Data source is reported for the Low-half load.",
        .default_sampling_period = 0x186A3ULL,
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
                .pebs = 1,
            },
        .brief_desc = "Retired load uops with L1 cache hits as data sources.",
        .full_desc =
            "This event counts retired load uops which data sources were hits in the nearest-level (L1) cache. Note: Only two data-sources of L1/FB are applicable for AVX-256bit  even though the corresponding AVX load could be serviced by a deeper level in the memory hierarchy. Data source is reported for the Low-half load. This event also counts SW prefetches independent of the actual data source.",
        .default_sampling_period = 0x1E8483ULL,
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
                .pebs = 1,
            },
        .brief_desc = "Retired load uops misses in L1 cache as data sources.",
        .full_desc =
            "This event counts retired load uops which data sources were misses in the nearest-level (L1) cache. Counting excludes unknown and UC data source.",
        .default_sampling_period = 0x186A3ULL,
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
                .pebs = 1,
            },
        .brief_desc = "Retired load uops with L2 cache hits as data sources.",
        .full_desc =
            "This event counts retired load uops which data sources were hits in the mid-level (L2) cache.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM35",
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
                .pebs = 1,
            },
        .brief_desc =
            "Miss in mid-level (L2) cache. Excludes Unknown data-source.",
        .full_desc =
            "This event counts retired load uops which data sources were misses in the mid-level (L2) cache. Counting excludes unknown and UC data source.",
        .default_sampling_period = 0xC365ULL,
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
            StaticEventDef::IntelFeatures{
                .data_la = true,
                .pebs = 1,
            },
        .brief_desc =
            "Retired load uops which data sources were data hits in L3 without snoops required.",
        .full_desc =
            "This event counts retired load uops which data sources were data hits in the last-level (L3) cache without snoops required.",
        .default_sampling_period = 0xC365ULL,
        .errata = "BDM100",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "MEM_LOAD_UOPS_RETIRED.L3_MISS",
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
            "Miss in last-level (L3) cache. Excludes Unknown data-source.",
        .full_desc =
            "Miss in last-level (L3) cache. Excludes Unknown data-source.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "BDM100, BDE70",
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
            "Randomly selected loads with latency value being above 128",
        .full_desc =
            "Counts randomly selected loads with latency value being above 128.",
        .default_sampling_period = 0x3F1ULL,
        .errata = "BDM100, BDM35",
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
            "Randomly selected loads with latency value being above 16",
        .full_desc =
            "Counts randomly selected loads with latency value being above 16.",
        .default_sampling_period = 0x4E2BULL,
        .errata = "BDM100, BDM35",
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
            "Randomly selected loads with latency value being above 256",
        .full_desc =
            "Counts randomly selected loads with latency value being above 256.",
        .default_sampling_period = 0x1F7ULL,
        .errata = "BDM100, BDM35",
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
            "Randomly selected loads with latency value being above 32",
        .full_desc =
            "Counts randomly selected loads with latency value being above 32.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "BDM100, BDM35",
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
            "Randomly selected loads with latency value being above 4",
        .full_desc =
            "Counts randomly selected loads with latency value being above four.",
        .default_sampling_period = 0x186A3ULL,
        .errata = "BDM100, BDM35",
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
            "Randomly selected loads with latency value being above 512",
        .full_desc =
            "Counts randomly selected loads with latency value being above 512.",
        .default_sampling_period = 0x65ULL,
        .errata = "BDM100, BDM35",
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
            "Randomly selected loads with latency value being above 64",
        .full_desc =
            "Counts randomly selected loads with latency value being above 64.",
        .default_sampling_period = 0x7D3ULL,
        .errata = "BDM100, BDM35",
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
            "Randomly selected loads with latency value being above 8",
        .full_desc =
            "Counts randomly selected loads with latency value being above eight.",
        .default_sampling_period = 0xC365ULL,
        .errata = "BDM100, BDM35",
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
                .pebs = 1,
            },
        .brief_desc = "Retired load uops.",
        .full_desc =
            "Counts all retired load uops. This event accounts for SW prefetch uops of PREFETCHNTA or PREFETCHT0/1/2 or PREFETCHW.",
        .default_sampling_period = 0x1E8483ULL,
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
                .l1_hit_indication = true,
                .pebs = 1,
            },
        .brief_desc = "Retired store uops.",
        .full_desc = "Counts all retired store uops.",
        .default_sampling_period = 0x1E8483ULL,
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
        .brief_desc = "Retired load uops with locked access.",
        .full_desc =
            "This event counts load uops with locked access retired to the architected path.",
        .default_sampling_period = 0x186A7ULL,
        .errata = "BDM35",
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
            "Retired load uops that split across a cacheline boundary.",
        .full_desc =
            "This event counts line-splitted load uops retired to the architected path. A line split is across 64B cache-line which includes a page split (4K).",
        .default_sampling_period = 0x186A3ULL,
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
                .l1_hit_indication = true,
                .pebs = 1,
            },
        .brief_desc =
            "Retired store uops that split across a cacheline boundary.",
        .full_desc =
            "This event counts line-splitted store uops retired to the architected path. A line split is across 64B cache-line which includes a page split (4K).",
        .default_sampling_period = 0x186A3ULL,
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
                .data_la = true,
                .pebs = 1,
            },
        .brief_desc = "Retired load uops that miss the STLB.",
        .full_desc =
            "This event counts load uops with true STLB miss retired to the architected path. True STLB miss is an uop triggering page walk that gets completed without blocks, and later gets retired. This page walk can end up with or without a fault.",
        .default_sampling_period = 0x186A3ULL,
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
                .data_la = true,
                .l1_hit_indication = true,
                .pebs = 1,
            },
        .brief_desc = "Retired store uops that miss the STLB.",
        .full_desc =
            "This event counts store uops with true STLB miss retired to the architected path. True STLB miss is an uop triggering page walk that gets completed without blocks, and later gets retired. This page walk can end up with or without a fault.",
        .default_sampling_period = 0x186A3ULL,
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
            "This event counts speculative cache-line split load uops dispatched to the L1 cache.",
        .default_sampling_period = 0x1E8483ULL,
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
            "This event counts speculative cache line split store-address (STA) uops dispatched to the L1 cache.",
        .default_sampling_period = 0x1E8483ULL,
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
            "This event counts the demand and prefetch data reads. All Core Data Reads include cacheable Demands and L2 prefetchers (not L3 prefetchers). Counting also covers reads due to page walks resulted from any request type.",
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
            "This event counts memory transactions reached the super queue including requests initiated by the core, all L3 prefetches, page walks, and so on.",
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
            "This event counts both cacheable and non-cacheable code read requests.",
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
            "This event counts the Demand Data Read requests sent to uncore. Use it in conjunction with OFFCORE_REQUESTS_OUTSTANDING to determine average latency in the uncore.",
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
        .brief_desc = "Demand RFO requests including regular RFOs, locks, ItoM",
        .full_desc =
            "This event counts the demand RFO (read for ownership) requests including regular RFOs, locks, ItoM.",
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
            "This event counts the number of cases when the offcore requests buffer cannot take more entries for the core. This can happen when the superqueue does not contain eligible entries, or when L1D writeback pending FIFO requests is full. Note: Writeback pending FIFO has six entries.",
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
            "This event counts cycles when offcore outstanding Demand Data Read transactions are present in the super queue (SQ). A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation).",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM76",
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
            "This event counts the number of offcore outstanding demand rfo Reads transactions in the super queue every cycle. The Offcore outstanding state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM76",
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
            "This event counts the number of offcore outstanding Code Reads transactions in the super queue every cycle. The Offcore outstanding state of the transaction lasts from the L2 miss until the sending transaction completion to requestor (SQ deallocation). See the corresponding Umask under OFFCORE_REQUESTS.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM76",
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
            "This event counts the number of offcore outstanding Demand Data Read transactions in the super queue (SQ) every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor. See the corresponding Umask under OFFCORE_REQUESTS. Note: A prefetch promoted to Demand is counted from the promotion point.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM76",
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
        .errata = "BDM76",
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
            "This event counts the number of offcore outstanding RFO (store) transactions in the super queue (SQ) every cycle. A transaction is considered to be in the Offcore outstanding state between L2 miss and transaction completion sent to requestor (SQ de-allocation). See corresponding Umask under OFFCORE_REQUESTS.",
        .default_sampling_period = 0x1E8483ULL,
        .errata = "BDM76",
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all demand & prefetch data reads have any response type.",
        .full_desc =
            "Counts all demand & prefetch data reads have any response type.",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C0091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C0091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C0091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C0091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C000091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C000091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC000091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C000091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84000091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004000091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404000091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204000091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x84000091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004000091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.ALL_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104000091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.SUPPLIER_NONE.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F80020091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1000020091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x400020091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x200020091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80020091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2000020091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_DATA_RD.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x100020091ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch data reads",
        .full_desc = "Counts all demand & prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads have any response type.",
        .full_desc = "Counts all prefetch code reads have any response type.",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_HIT.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C0240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C0240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C0240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C0240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C000240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C000240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC000240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C000240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84000240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004000240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404000240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204000240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x84000240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004000240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.ALL_PF_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104000240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.SUPPLIER_NONE.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F80020240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.SUPPLIER_NONE.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1000020240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x400020240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.SUPPLIER_NONE.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x200020240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.SUPPLIER_NONE.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80020240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.SUPPLIER_NONE.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2000020240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_CODE_RD.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x100020240ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch code reads",
        .full_desc = "Counts all prefetch code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.ANY_RESPONSE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads have any response type.",
        .full_desc = "Counts all prefetch data reads have any response type.",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C0090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C0090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C0090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C0090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C000090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C000090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC000090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C000090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84000090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004000090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404000090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204000090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x84000090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004000090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.ALL_PF_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104000090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.SUPPLIER_NONE.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F80020090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1000020090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x400020090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x200020090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80020090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2000020090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_DATA_RD.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x100020090ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all prefetch data reads",
        .full_desc = "Counts all prefetch data reads",
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
        .brief_desc = "Counts prefetch RFOs have any response type.",
        .full_desc = "Counts prefetch RFOs have any response type.",
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
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C0120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C0120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C0120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C000120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C000120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC000120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C000120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84000120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004000120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404000120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204000120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x84000120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004000120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104000120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.SUPPLIER_NONE.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F80020120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1000020120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x400020120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x200020120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80020120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2000020120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_PF_RFO.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x100020120ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch RFOs",
        .full_desc = "Counts prefetch RFOs",
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
            "Counts all demand & prefetch RFOs have any response type.",
        .full_desc =
            "Counts all demand & prefetch RFOs have any response type.",
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
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C0122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C0122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C0122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C000122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C000122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC000122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C000122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84000122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004000122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404000122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204000122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x84000122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004000122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104000122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.SUPPLIER_NONE.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F80020122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.SUPPLIER_NONE.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1000020122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x400020122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.SUPPLIER_NONE.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x200020122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.SUPPLIER_NONE.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80020122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.SUPPLIER_NONE.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2000020122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.ALL_RFO.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x100020122ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand & prefetch RFOs",
        .full_desc = "Counts all demand & prefetch RFOs",
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
        .brief_desc =
            "Counts writebacks (modified to exclusive) have any response type.",
        .full_desc =
            "Counts writebacks (modified to exclusive) have any response type.",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_HIT.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C0008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C0008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C0008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C0008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C000008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C000008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC000008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C000008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84000008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004000008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404000008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204000008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x84000008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004000008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104000008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.SUPPLIER_NONE.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F80020008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.SUPPLIER_NONE.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1000020008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x400020008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.SUPPLIER_NONE.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x200020008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.SUPPLIER_NONE.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80020008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.SUPPLIER_NONE.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2000020008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.COREWB.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x100020008ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts writebacks (modified to exclusive)",
        .full_desc = "Counts writebacks (modified to exclusive)",
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
        .brief_desc = "Counts all demand code reads have any response type.",
        .full_desc = "Counts all demand code reads have any response type.",
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
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C0004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C0004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C0004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C000004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C000004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC000004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C000004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84000004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004000004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404000004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204000004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x84000004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004000004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.DEMAND_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104000004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.SUPPLIER_NONE.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F80020004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.SUPPLIER_NONE.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1000020004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x400020004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.SUPPLIER_NONE.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x200020004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.SUPPLIER_NONE.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80020004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.SUPPLIER_NONE.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2000020004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_CODE_RD.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x100020004ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand code reads",
        .full_desc = "Counts all demand code reads",
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
        .brief_desc = "Counts demand data reads have any response type.",
        .full_desc = "Counts demand data reads have any response type.",
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
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C0001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C0001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C0001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C000001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C000001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC000001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C000001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84000001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004000001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404000001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204000001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x84000001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004000001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.DEMAND_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104000001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.SUPPLIER_NONE.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F80020001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.SUPPLIER_NONE.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1000020001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x400020001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.SUPPLIER_NONE.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x200020001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.SUPPLIER_NONE.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80020001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.SUPPLIER_NONE.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2000020001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_DATA_RD.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x100020001ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts demand data reads",
        .full_desc = "Counts demand data reads",
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
            "Counts all demand data writes (RFOs) have any response type.",
        .full_desc =
            "Counts all demand data writes (RFOs) have any response type.",
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
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C0002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C0002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C0002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C000002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C000002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC000002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C000002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.DEMAND_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84000002ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts all demand data writes (RFOs)",
        .full_desc = "Counts all demand data writes (RFOs)",
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
        .brief_desc = "Counts any other requests have any response type.",
        .full_desc = "Counts any other requests have any response type.",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_HIT.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C8000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C8000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C8000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C8000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C8000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C8000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C8000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C008000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C008000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC008000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C008000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84008000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004008000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404008000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204008000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x84008000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004008000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104008000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.SUPPLIER_NONE.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F80028000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.SUPPLIER_NONE.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1000028000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x400028000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.SUPPLIER_NONE.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x200028000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.SUPPLIER_NONE.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80028000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.SUPPLIER_NONE.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2000028000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.OTHER.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x100028000ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts any other requests",
        .full_desc = "Counts any other requests",
        .default_sampling_period = 0x186A3ULL,
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
            "Counts all prefetch (that bring data to LLC only) code reads have any response type.",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads have any response type.",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_HIT.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F803C0040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C0040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C0040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C0040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C000040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C000040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC000040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C000040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84000040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004000040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404000040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204000040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x84000040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004000040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.PF_L2_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104000040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.SUPPLIER_NONE.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F80020040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.SUPPLIER_NONE.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1000020040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x400020040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.SUPPLIER_NONE.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x200020040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.SUPPLIER_NONE.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x80020040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.SUPPLIER_NONE.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2000020040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_CODE_RD.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x100020040ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
        .full_desc =
            "Counts all prefetch (that bring data to LLC only) code reads",
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
            "Counts prefetch (that bring data to L2) data reads have any response type.",
        .full_desc =
            "Counts prefetch (that bring data to L2) data reads have any response type.",
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
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x10003C0010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x4003C0010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2003C0010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x803C0010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x20003C0010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_HIT.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1003C0010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x43C000010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x23C000010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0xBC000010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x13C000010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x3F84000010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x1004000010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x404000010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x204000010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x84000010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x2004000010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
    {
        .pmu_type = PmuType::cpu,
        .id =
            "OFFCORE_RESPONSE.PF_L2_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
        .encoding =
            {
                .code = 0xB7ULL,
                .umask = 0x1ULL,
                .msr_values = uint64_t{0x104000010ULL},
            },
        .features = StaticEventDef::IntelFeatures{},
        .brief_desc = "Counts prefetch (that bring data to L2) data reads",
        .full_desc = "Counts prefetch (that bring data to L2) data reads",
        .default_sampling_period = 0x186A3ULL,
    },
}};
static_assert(isStaticEventDefTableSorted(kFullOnlyEvents0));

constexpr std::array<StaticEventDef, 194> kFullOnlyEvents1{
    {
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.SUPPLIER_NONE.ANY_SNOOP",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F80020010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts prefetch (that bring data to L2) data reads",
            .full_desc = "Counts prefetch (that bring data to L2) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.SUPPLIER_NONE.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000020010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts prefetch (that bring data to L2) data reads",
            .full_desc = "Counts prefetch (that bring data to L2) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L2_DATA_RD.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400020010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts prefetch (that bring data to L2) data reads",
            .full_desc = "Counts prefetch (that bring data to L2) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.SUPPLIER_NONE.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200020010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts prefetch (that bring data to L2) data reads",
            .full_desc = "Counts prefetch (that bring data to L2) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.SUPPLIER_NONE.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x80020010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts prefetch (that bring data to L2) data reads",
            .full_desc = "Counts prefetch (that bring data to L2) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_DATA_RD.SUPPLIER_NONE.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2000020010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts prefetch (that bring data to L2) data reads",
            .full_desc = "Counts prefetch (that bring data to L2) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L2_DATA_RD.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x100020010ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts prefetch (that bring data to L2) data reads",
            .full_desc = "Counts prefetch (that bring data to L2) data reads",
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
                "Counts all prefetch (that bring data to L2) RFOs have any response type.",
            .full_desc =
                "Counts all prefetch (that bring data to L2) RFOs have any response type.",
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
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x803C0020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x20003C0020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_HIT.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x43C000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x23C000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0xBC000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x13C000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F84000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1004000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x404000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x204000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x84000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2004000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L2_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x104000020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.SUPPLIER_NONE.ANY_SNOOP",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F80020020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.SUPPLIER_NONE.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000020020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400020020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.SUPPLIER_NONE.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200020020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.SUPPLIER_NONE.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x80020020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.SUPPLIER_NONE.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2000020020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L2_RFO.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x100020020ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .full_desc = "Counts all prefetch (that bring data to L2) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.ANY_RESPONSE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads have any response type.",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads have any response type.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_HIT.ANY_SNOOP",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F803C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_HIT.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_HIT.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_HIT.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x803C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_HIT.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x20003C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_HIT.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_MISS.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x43C000200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_MISS.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x23C000200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_MISS.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0xBC000200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_MISS.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x13C000200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F84000200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1004000200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x404000200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x204000200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x84000200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2004000200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_CODE_RD.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x104000200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.SUPPLIER_NONE.ANY_SNOOP",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F80020200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.SUPPLIER_NONE.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000020200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_CODE_RD.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400020200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.SUPPLIER_NONE.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200020200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.SUPPLIER_NONE.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x80020200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_CODE_RD.SUPPLIER_NONE.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2000020200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_CODE_RD.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x100020200ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
            .full_desc =
                "Counts prefetch (that bring data to LLC only) code reads",
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
                "Counts all prefetch (that bring data to LLC only) data reads have any response type.",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads have any response type.",
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
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x803C0080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x20003C0080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_HIT.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x43C000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x23C000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0xBC000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x13C000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F84000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1004000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x404000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x204000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x84000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2004000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_DATA_RD.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x104000080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.SUPPLIER_NONE.ANY_SNOOP",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F80020080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.SUPPLIER_NONE.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000020080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_DATA_RD.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400020080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.SUPPLIER_NONE.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200020080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.SUPPLIER_NONE.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x80020080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_DATA_RD.SUPPLIER_NONE.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2000020080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_DATA_RD.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x100020080ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) data reads",
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
                "Counts all prefetch (that bring data to LLC only) RFOs have any response type.",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs have any response type.",
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
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x10003C0100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x4003C0100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2003C0100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x803C0100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x20003C0100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_HIT.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1003C0100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x43C000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x23C000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0xBC000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x13C000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS_LOCAL_DRAM.ANY_SNOOP",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F84000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1004000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x404000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x204000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x84000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2004000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id =
                "OFFCORE_RESPONSE.PF_L3_RFO.L3_MISS_LOCAL_DRAM.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x104000100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.SUPPLIER_NONE.ANY_SNOOP",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x3F80020100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.SUPPLIER_NONE.SNOOP_HITM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x1000020100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.SUPPLIER_NONE.SNOOP_HIT_NO_FWD",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x400020100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.SUPPLIER_NONE.SNOOP_MISS",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x200020100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.SUPPLIER_NONE.SNOOP_NONE",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x80020100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.SUPPLIER_NONE.SNOOP_NON_DRAM",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x2000020100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OFFCORE_RESPONSE.PF_L3_RFO.SUPPLIER_NONE.SNOOP_NOT_NEEDED",
            .encoding =
                {
                    .code = 0xB7ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x100020100ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .full_desc =
                "Counts all prefetch (that bring data to LLC only) RFOs",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OTHER_ASSISTS.ANY_WB_ASSIST",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x40ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of times any microcode assist is invoked by HW upon uop writeback.",
            .full_desc =
                "Number of times any microcode assist is invoked by HW upon uop writeback.",
            .default_sampling_period = 0x186A3ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OTHER_ASSISTS.AVX_TO_SSE",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of transitions from AVX-256 to legacy SSE when penalty applicable.",
            .full_desc =
                "This event counts the number of transitions from AVX-256 to legacy SSE when penalty is applicable.",
            .default_sampling_period = 0x186A3ULL,
            .errata = "BDM30",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "OTHER_ASSISTS.SSE_TO_AVX",
            .encoding =
                {
                    .code = 0xC1ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of transitions from SSE to AVX-256 when penalty applicable.",
            .full_desc =
                "This event counts the number of transitions from legacy SSE to AVX-256 when penalty is applicable.",
            .default_sampling_period = 0x186A3ULL,
            .errata = "BDM30",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "PAGE_WALKER_LOADS.DTLB_L1",
            .encoding =
                {
                    .code = 0xBCULL,
                    .umask = 0x11ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of DTLB page walker hits in the L1+FB.",
            .full_desc = "Number of DTLB page walker hits in the L1+FB.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "BDM69, BDM98",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "PAGE_WALKER_LOADS.DTLB_L2",
            .encoding =
                {
                    .code = 0xBCULL,
                    .umask = 0x12ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of DTLB page walker hits in the L2.",
            .full_desc = "Number of DTLB page walker hits in the L2.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "BDM69, BDM98",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "PAGE_WALKER_LOADS.DTLB_L3",
            .encoding =
                {
                    .code = 0xBCULL,
                    .umask = 0x14ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of DTLB page walker hits in the L3 + XSNP.",
            .full_desc = "Number of DTLB page walker hits in the L3 + XSNP.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "BDM69, BDM98",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "PAGE_WALKER_LOADS.DTLB_MEMORY",
            .encoding =
                {
                    .code = 0xBCULL,
                    .umask = 0x18ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of DTLB page walker hits in Memory.",
            .full_desc = "Number of DTLB page walker hits in Memory.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "BDM69, BDM98",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "PAGE_WALKER_LOADS.ITLB_L1",
            .encoding =
                {
                    .code = 0xBCULL,
                    .umask = 0x21ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of ITLB page walker hits in the L1+FB.",
            .full_desc = "Number of ITLB page walker hits in the L1+FB.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "BDM69, BDM98",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "PAGE_WALKER_LOADS.ITLB_L2",
            .encoding =
                {
                    .code = 0xBCULL,
                    .umask = 0x22ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of ITLB page walker hits in the L2.",
            .full_desc = "Number of ITLB page walker hits in the L2.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "BDM69, BDM98",
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "PAGE_WALKER_LOADS.ITLB_L3",
            .encoding =
                {
                    .code = 0xBCULL,
                    .umask = 0x24ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Number of ITLB page walker hits in the L3 + XSNP.",
            .full_desc = "Number of ITLB page walker hits in the L3 + XSNP.",
            .default_sampling_period = 0x1E8483ULL,
            .errata = "BDM69, BDM98",
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
            .full_desc = "This event counts resource-related stall cycles.",
            .default_sampling_period = 0x1E8483ULL,
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
            .full_desc =
                "This event counts ROB full stall cycles. This counts cycles that the pipeline backend blocked uop delivery from the front end.",
            .default_sampling_period = 0x1E8483ULL,
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
                "This event counts stall cycles caused by absence of eligible entries in the reservation station (RS). This may result from RS overflow, or from RS deallocation because of the RS array Write Port allocation scheme (each RS entry has two write ports instead of four. As a result, empty entries could not be used, although RS is not really full). This counts cycles that the pipeline backend blocked uop delivery from the front end.",
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
                "This event counts stall cycles caused by the store buffer (SB) overflow (excluding draining from synch). This counts cycles that the pipeline backend blocked uop delivery from the front end.",
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
            .brief_desc = "Count cases of saving new LBR",
            .full_desc =
                "This event counts cases of saving new LBR records by hardware. This assumes proper enabling of LBRs and takes into account LBR filtering done by the LBR_SELECT register.",
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
                "This event counts cycles during which the reservation station (RS) is empty for the thread. Note: In ST-mode, not active thread should drive 0. This is usually caused by severely costly branch mispredictions, or allocator/FE issues.",
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
                "Counts end of periods where the Reservation Station (RS) was empty. Could be useful to precisely locate Frontend Latency Bound issues.",
            .default_sampling_period = 0x30D43ULL,
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
                StaticEventDef::
                    IntelFeatures{
                        .pebs = 1,
                    },
            .brief_desc = "Number of times RTM abort was triggered",
            .full_desc = "Number of times RTM abort was triggered .",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RTM_RETIRED.ABORTED_MISC1",
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
                "Number of times an RTM abort was attributed to a Memory condition (See TSX_Memory event for additional details).",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RTM_RETIRED.ABORTED_MISC2",
            .encoding =
                {
                    .code = 0xC9ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of times an RTM execution aborted due to various memory events (e.g., read/write capacity and conflicts).",
            .full_desc =
                "Number of times the TSX watchdog signaled an RTM abort.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RTM_RETIRED.ABORTED_MISC3",
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
                "Number of times a disallowed operation caused an RTM abort.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RTM_RETIRED.ABORTED_MISC4",
            .encoding =
                {
                    .code = 0xC9ULL,
                    .umask = 0x40ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Number of times an RTM execution aborted due to incompatible memory type",
            .full_desc = "Number of times a RTM caused a fault.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "RTM_RETIRED.ABORTED_MISC5",
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
                "Number of times RTM aborted and was not due to the abort conditions in subevents 3-6.",
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
            .brief_desc = "Number of times RTM commit succeeded",
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
            .brief_desc =
                "Number of times we entered an RTM region; does not count nested transactions",
            .full_desc =
                "Number of times we entered an RTM region  does not count nested transactions.",
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
            .brief_desc = "Split locks in SQ",
            .full_desc =
                "This event counts the number of split locks in the super queue.",
            .default_sampling_period = 0x186A3ULL,
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
            .full_desc =
                "This event counts the number of DTLB flush attempts of the thread-specific entries.",
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
                "This event counts the number of any STLB flush attempts (such as entire, VPID, PCID, InvPage, CR3 write, and so on).",
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
                "Unfriendly TSX abort triggered by  a vzeroupper instruction.",
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
                "Counts the number of times an HLE XACQUIRE instruction was executed inside an RTM transactional region.",
            .full_desc =
                "Counts the number of times an HLE XACQUIRE instruction was executed inside an RTM transactional region.",
            .default_sampling_period = 0x1E8483ULL,
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
            .brief_desc = "Number of times a TSX Abort was triggered due to an evicted line caused by a transaction overflow",
            .full_desc =
                "Number of times a TSX Abort was triggered due to an evicted line caused by a transaction overflow.",
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
            .brief_desc = "Number of times a TSX line had a cache conflict",
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
                "Number of times a TSX Abort was triggered due to release/commit but data and address mismatch",
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
                "Number of times a TSX Abort was triggered due to commit but Lock Buffer not empty",
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
                "Number of times a TSX Abort was triggered due to attempting an unsupported alignment from Lock Buffer",
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
                "Number of times a TSX Abort was triggered due to a non-release/commit store to lock",
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
            .brief_desc = "Number of times we could not allocate Lock Buffer",
            .full_desc = "Number of times we could not allocate Lock Buffer.",
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
            .brief_desc = "Cycles per thread when uops are executed in port 0",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 0.",
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
            .brief_desc = "Cycles per thread when uops are executed in port 1",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 1.",
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
            .brief_desc = "Cycles per thread when uops are executed in port 2",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 2.",
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
            .brief_desc = "Cycles per thread when uops are executed in port 3",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 3.",
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
            .brief_desc = "Cycles per thread when uops are executed in port 4",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 4.",
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
            .brief_desc = "Cycles per thread when uops are executed in port 5",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 5.",
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
            .brief_desc = "Cycles per thread when uops are executed in port 6",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 6.",
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
            .brief_desc = "Cycles per thread when uops are executed in port 7",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 7.",
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
                "Cycles where at least 1 uop was executed per-thread.",
            .full_desc = "Cycles where at least 1 uop was executed per-thread.",
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
                "Cycles where at least 2 uops were executed per-thread.",
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
                "Cycles where at least 3 uops were executed per-thread.",
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
                "Cycles where at least 4 uops were executed per-thread.",
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
                "This event counts cycles during which no uops were dispatched from the Reservation Station (RS) per thread.",
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
            .full_desc = "Number of uops to be executed per-thread each cycle.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_0",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x1ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per thread when uops are executed in port 0",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 0.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_0_CORE",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x1ULL,
                    .any = true,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per core when uops are executed in port 0.",
            .full_desc = "Cycles per core when uops are executed in port 0.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_1",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x2ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per thread when uops are executed in port 1",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 1.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_1_CORE",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x2ULL,
                    .any = true,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per core when uops are executed in port 1.",
            .full_desc = "Cycles per core when uops are executed in port 1.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_2",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x4ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per thread when uops are executed in port 2",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 2.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_2_CORE",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x4ULL,
                    .any = true,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per core when uops are dispatched to port 2.",
            .full_desc = "Cycles per core when uops are dispatched to port 2.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_3",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x8ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per thread when uops are executed in port 3",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 3.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_3_CORE",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x8ULL,
                    .any = true,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per core when uops are dispatched to port 3.",
            .full_desc = "Cycles per core when uops are dispatched to port 3.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_4",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x10ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per thread when uops are executed in port 4",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 4.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_4_CORE",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x10ULL,
                    .any = true,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per core when uops are executed in port 4.",
            .full_desc = "Cycles per core when uops are executed in port 4.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_5",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x20ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per thread when uops are executed in port 5",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 5.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_5_CORE",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x20ULL,
                    .any = true,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per core when uops are executed in port 5.",
            .full_desc = "Cycles per core when uops are executed in port 5.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_6",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x40ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per thread when uops are executed in port 6",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 6.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_6_CORE",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x40ULL,
                    .any = true,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per core when uops are executed in port 6.",
            .full_desc = "Cycles per core when uops are executed in port 6.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_7",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x80ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per thread when uops are executed in port 7",
            .full_desc =
                "This event counts, on the per-thread basis, cycles during which uops are dispatched from the Reservation Station (RS) to port 7.",
            .default_sampling_period = 0x1E8483ULL,
        },
        {
            .pmu_type = PmuType::cpu,
            .id = "UOPS_EXECUTED_PORT.PORT_7_CORE",
            .encoding =
                {
                    .code = 0xA1ULL,
                    .umask = 0x80ULL,
                    .any = true,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc = "Cycles per core when uops are dispatched to port 7.",
            .full_desc = "Cycles per core when uops are dispatched to port 7.",
            .default_sampling_period = 0x1E8483ULL,
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
            .brief_desc =
                "Number of flags-merge uops being allocated. Such uops considered perf sensitive; added by GSR u-arch.",
            .full_desc =
                "Number of flags-merge uops being allocated. Such uops considered perf sensitive  added by GSR u-arch.",
            .default_sampling_period = 0x1E8483ULL,
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
                "Number of Multiply packed/scalar single precision uops allocated.",
            .full_desc =
                "Number of Multiply packed/scalar single precision uops allocated.",
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
                "This event counts cycles during which the Resource Allocation Table (RAT) does not issue any Uops to the reservation station (RS) for the current thread.",
            .default_sampling_period = 0x1E8483ULL,
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
                    .umask = 0x1ULL,
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
        {
            .pmu_type = PmuType::cpu,
            .id = "UOP_DISPATCHES_CANCELLED.SIMD_PRF",
            .encoding =
                {
                    .code = 0xA0ULL,
                    .umask = 0x3ULL,
                    .msr_values = uint64_t{0x0ULL},
                },
            .features = StaticEventDef::IntelFeatures{},
            .brief_desc =
                "Micro-op dispatches cancelled due to insufficient SIMD physical register file read ports",
            .full_desc =
                "This event counts the number of micro-operations cancelled after they were dispatched from the scheduler to the execution units when the total number of physical register read ports across all dispatch ports exceeds the read bandwidth of the physical register file.  The SIMD_PRF subevent applies to the following instructions: VDPPS, DPPS, VPCMPESTRI, PCMPESTRI, VPCMPESTRM, PCMPESTRM, VFMADD*, VFMADDSUB*, VFMSUB*, VMSUBADD*, VFNMADD*, VFNMSUB*.  See the Broadwell Optimization Guide for more information.",
            .default_sampling_period = 0x1E8483ULL,
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

} // namespace broadwell_core
} // namespace facebook::hbt::perf_event::generated
