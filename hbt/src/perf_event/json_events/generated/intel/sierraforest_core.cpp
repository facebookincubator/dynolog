// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace sierraforest_core {

void addEvents(PmuDeviceManager& pmu_manager) {
/*
  Events from sierraforest_core.json (38 events).

  Supported SKUs:
      - Arch: x86, Model: SRF id: 175
*/
#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Fixed Counter: Counts the number of instructions retired)",
      R"(Fixed Counter: Counts the number of instructions retired)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.CORE",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Fixed Counter: Counts the number of unhalted core clock cycles)",
      R"(Fixed Counter: Counts the number of unhalted core clock cycles)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Fixed Counter: Counts the number of unhalted core clock cycles)",
      R"(Fixed Counter: Counts the number of unhalted core clock cycles)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event CPU_CLK_UNHALTED.REF_TSC is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_TSC",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Fixed Counter: Counts the number of unhalted reference clock cycles)",
      R"(Fixed Counter: Counts the number of unhalted reference clock cycles)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x0e, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to load DTLB misses to a 1G page.)",
      R"(Counts the number of page walks completed due to load DTLB misses to a 1G page.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event LONGEST_LAT_CACHE.MISS is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.MISS",
      EventDef::Encoding{
          .code = 0x2e, .umask = 0x41, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cacheable memory requests that miss in the LLC. Counts on a per core basis.)",
      R"(Counts the number of cacheable memory requests that miss in the Last Level Cache (LLC). Requests include demand loads, reads for ownership (RFO), instruction fetches and L1 HW prefetches. If the platform has an L3 cache, the LLC is the L3 cache, otherwise it is the L2 cache. Counts on a per core basis.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.REFERENCE",
      EventDef::Encoding{
          .code = 0x2e, .umask = 0x4f, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cacheable memory requests that access the LLC. Counts on a per core basis.)",
      R"(Counts the number of cacheable memory requests that access the Last Level Cache (LLC). Requests include demand loads, reads for ownership (RFO), instruction fetches and L1 HW prefetches. If the platform has an L3 cache, the LLC is the L3 cache, otherwise it is the L2 cache. Counts on a per core basis.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.CORE_P",
      EventDef::Encoding{
          .code = 0x3c, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted core clock cycles [This event is alias to CPU_CLK_UNHALTED.THREAD_P])",
      R"(Counts the number of unhalted core clock cycles [This event is alias to CPU_CLK_UNHALTED.THREAD_P])",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD_P",
      EventDef::Encoding{
          .code = 0x3c, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted core clock cycles [This event is alias to CPU_CLK_UNHALTED.CORE_P])",
      R"(Counts the number of unhalted core clock cycles [This event is alias to CPU_CLK_UNHALTED.CORE_P])",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_TSC_P",
      EventDef::Encoding{
          .code = 0x3c, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted reference clock cycles at TSC frequency.)",
      R"(Counts the number of reference cycles that the core is not in a halt state. The core enters the halt state when it is running the HLT instruction. This event is not affected by core frequency changes and increments at a fixed frequency that is also used for the Time Stamp Counter (TSC). This event uses a programmable general purpose performance counter.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x0e, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to store DTLB misses to a 1G page.)",
      R"(Counts the number of page walks completed due to store DTLB misses to a 1G page.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.ALL",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retirement slots not consumed due to front end stalls)",
      R"(Counts the number of retirement slots not consumed due to front end stalls)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_RETIRING.ALL",
      EventDef::Encoding{
          .code = 0x72, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of consumed retirement slots.  Similar to UOPS_RETIRED.ALL)",
      R"(Counts the number of consumed retirement slots.  Similar to UOPS_RETIRED.ALL)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.ALL",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear.)",
      R"(Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear. Only issue slots wasted due to fast nukes such as memory ordering nukes are counted. Other nukes are not accounted for. Counts all issue slots blocked during this recovery window, including relevant microcode flows, and while uops are not yet available in the instruction queue (IQ) or until an FE_BOUND event occurs besides OTHER and CISC. Also includes the issue slots that were consumed by the backend but were thrown away because they were younger than the mispredict or machine clear.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.ALL",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retirement slots not consumed due to backend stalls)",
      R"(Counts the number of retirement slots not consumed due to backend stalls)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.MISSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts every time the code stream enters into a new cache line by walking sequential from the previous line or being redirected by a jump and the instruction cache registers bytes are not present. -)",
      R"(Counts every time the code stream enters into a new cache line by walking sequential from the previous line or being redirected by a jump and the instruction cache registers bytes are not present. -)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.ACCESSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Counts every time the code stream enters into a new cache line by walking sequential from the previous line or being redirected by a jump.)",
      R"(Counts every time the code stream enters into a new cache line by walking sequential from the previous line or being redirected by a jump.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x0e, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to instruction fetch misses to any page size.)",
      R"(Counts the number of page walks completed due to instruction fetches whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to any page size.  Includes page walks that page fault.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY_P",
      EventDef::Encoding{
          .code = 0xc0, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of instructions retired)",
      R"(Counts the number of instructions retired)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of branch instructions retired for all branch types.)",
      R"(Counts the total number of instructions in which the instruction pointer (IP) of the processor is resteered due to a branch instruction and the branch instruction successfully retires.  All branch type instructions are accounted for.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event BR_MISP_RETIRED.ALL_BRANCHES is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of mispredicted branch instructions retired for all branch types.)",
      R"(Counts the total number of mispredicted branch instructions retired.  All branch type instructions are accounted for.  Prediction of the branch target address enables the processor to begin executing instructions before the non-speculative execution path is known. The branch prediction unit (BPU) predicts the target address based on the instruction pointer (IP) of the branch and on the execution path through which execution reached this IP.    A branch misprediction occurs when the prediction is wrong, and results in discarding all instructions executed in the speculative path and re-fetching from the correct path.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_8",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x05, .cmask = 0, .msr_values = {0x8}},
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_64",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x05, .cmask = 0, .msr_values = {0x40}},
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_512",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x05, .cmask = 0, .msr_values = {0x200}},
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_4",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x05, .cmask = 0, .msr_values = {0x4}},
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_32",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x05, .cmask = 0, .msr_values = {0x20}},
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_256",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x05, .cmask = 0, .msr_values = {0x100}},
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_16",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x05, .cmask = 0, .msr_values = {0x10}},
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_128",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x05, .cmask = 0, .msr_values = {0x80}},
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_2048",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x05, .cmask = 0, .msr_values = {0x800}},
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOAD_LATENCY_GT_1024",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x05, .cmask = 0, .msr_values = {0x400}},
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      R"(Counts the number of tagged load uops retired that exceed the latency threshold defined in MEC_CR_PEBS_LD_LAT_THRESHOLD - Only counts with PEBS enabled.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.STORE_LATENCY",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x06, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of  stores uops retired same as MEM_UOPS_RETIRED.ALL_STORES)",
      R"(Counts the number of  stores uops retired same as MEM_UOPS_RETIRED.ALL_STORES)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 2},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_LOADS",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x81, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load ops retired.)",
      R"(Counts the number of load ops retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_STORES",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x82, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of store ops retired.)",
      R"(Counts the number of store ops retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10001}},
      R"(Counts demand data reads that have any type of response.)",
      R"(Counts demand data reads that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00001}},
      R"(Counts demand data reads that were not supplied by the L3 cache.)",
      R"(Counts demand data reads that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that have any type of response.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3FBFC00002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the L3 cache.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace sierraforest_core
} // namespace facebook::hbt::perf_event::generated
