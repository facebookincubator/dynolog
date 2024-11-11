// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto generated for hbt. Do not manually edit.
// @generated

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace sierraforest_core {

void addEvents(PmuDeviceManager& pmu_manager) {
/*
  Events from sierraforest_core.json (160 events).

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
      EventDef::IntelFeatures{},
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
      "LD_BLOCKS.DATA_UNKNOWN",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired loads that are blocked because its address exactly matches an older store whose data is not ready.)",
      R"(Counts the number of retired loads that are blocked because its address exactly matches an older store whose data is not ready.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.STORE_FORWARD",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired loads that are blocked because its address partially overlapped with an older store.)",
      R"(Counts the number of retired loads that are blocked because its address partially overlapped with an older store.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.ADDRESS_ALIAS",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired loads that are blocked because it initially appears to be store forward blocked, but subsequently is shown not to be blocked based on 4K alias check.)",
      R"(Counts the number of retired loads that are blocked because it initially appears to be store forward blocked, but subsequently is shown not to be blocked based on 4K alias check.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_SCHEDULER_BLOCK.ST_BUF",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles that uops are blocked due to a store buffer full condition.)",
      R"(Counts the number of cycles that uops are blocked due to a store buffer full condition.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_SCHEDULER_BLOCK.LD_BUF",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles that uops are blocked due to a load buffer full condition.)",
      R"(Counts the number of cycles that uops are blocked due to a load buffer full condition.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_SCHEDULER_BLOCK.RSV",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles that uops are blocked due to an RSV full condition.)",
      R"(Counts the number of cycles that uops are blocked due to an RSV full condition.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_SCHEDULER_BLOCK.ALL",
      EventDef::Encoding{
          .code = 0x04, .umask = 0x07, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles that uops are blocked for any of the following reasons:  load buffer, store buffer or RSV full.)",
      R"(Counts the number of cycles that uops are blocked for any of the following reasons:  load buffer, store buffer or RSV full.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_HEAD.L1_MISS_AT_RET",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x81, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a DL1 miss.)",
      R"(Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a DL1 miss.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_HEAD.ST_ADDR_AT_RET",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x84, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a store address match.)",
      R"(Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a store address match.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_HEAD.DTLB_MISS_AT_RET",
      EventDef::Encoding{
          .code = 0x05, .umask = 0x90, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a DTLB miss.)",
      R"(Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a DTLB miss.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_HEAD.PGWALK_AT_RET",
      EventDef::Encoding{
          .code = 0x05, .umask = 0xa0, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a pagewalk.)",
      R"(Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to a pagewalk.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_HEAD.OTHER_AT_RET",
      EventDef::Encoding{
          .code = 0x05, .umask = 0xc0, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to other block cases.)",
      R"(Counts the number of cycles that the head (oldest load) of the load buffer and retirement are both stalled due to other block cases such as pipeline conflicts, fences, etc.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_HEAD.L1_BOUND_AT_RET",
      EventDef::Encoding{
          .code = 0x05, .umask = 0xf4, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles that the head (oldest load) of the load buffer is stalled due to a core bound stall including a store address match, a DTLB miss or a page walk that detains the load from retiring.)",
      R"(Counts the number of cycles that the head (oldest load) of the load buffer is stalled due to a core bound stall including a store address match, a DTLB miss or a page walk that detains the load from retiring.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_HEAD.ANY_AT_RET",
      EventDef::Encoding{
          .code = 0x05, .umask = 0xff, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles that the head (oldest load) of the load buffer is stalled due to any number of reasons, including an L1 miss, WCB full, pagewalk, store address block or store data block, on a load that retires.)",
      R"(Counts the number of cycles that the head (oldest load) of the load buffer is stalled due to any number of reasons, including an L1 miss, WCB full, pagewalk, store address block or store data block, on a load that retires.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to load DTLB misses to a 4K page.)",
      R"(Counts the number of page walks completed due to loads (including SW prefetches) whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 4K pages. Includes page walks that page fault.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to load DTLB misses to a 2M or 4M page.)",
      R"(Counts the number of page walks completed due to loads (including SW prefetches) whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 2M or 4M pages. Includes page walks that page fault.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event DTLB_LOAD_MISSES.WALK_COMPLETED is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x0e, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to load DTLB misses.)",
      R"(Counts the number of page walks completed due to load DTLB misses.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks outstanding for Loads (demand or SW prefetch) in PMH every cycle.)",
      R"(Counts the number of page walks outstanding for Loads (demand or SW prefetch) in PMH every cycle.  A PMH page walk is outstanding from page walk start till PMH becomes idle again (ready to serve next walk). Includes EPT-walk intervals.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of first level TLB misses but second level hits due to a demand load that did not start a page walk. Accounts for all page sizes. Will result in a DTLB write from STLB.)",
      R"(Counts the number of first level TLB misses but second level hits due to a demand load that did not start a page walk. Accounts for all page sizes. Will result in a DTLB write from STLB.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event UOPS_ISSUED.ANY is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.ANY",
      EventDef::Encoding{
          .code = 0x0e, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of uops issued by the front end every cycle.)",
      R"(Counts the number of uops issued by the front end every cycle. When 4-uops are requested and only 2-uops are delivered, the event counts 2.  Uops_issued correlates to the number of ROB entries.  If uop takes 2 ROB slots it counts as 2 uops_issued.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISALIGN_MEM_REF.LOAD_PAGE_SPLIT",
      EventDef::Encoding{
          .code = 0x13, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts misaligned loads that are 4K page splits.)",
      R"(Counts misaligned loads that are 4K page splits.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISALIGN_MEM_REF.STORE_PAGE_SPLIT",
      EventDef::Encoding{
          .code = 0x13, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts misaligned stores that are 4K page splits.)",
      R"(Counts misaligned stores that are 4K page splits.)",
      200003,
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
      R"(Counts the number of cacheable memory requests that miss in the Last Level Cache (LLC). Requests include demand loads, reads for ownership (RFO), instruction fetches and L1 HW prefetches. If the core has access to an L3 cache, the LLC is the L3 cache, otherwise it is the L2 cache. Counts on a per core basis.)",
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
      R"(Counts the number of cacheable memory requests that access the Last Level Cache (LLC). Requests include demand loads, reads for ownership (RFO), instruction fetches and L1 HW prefetches. If the core has access to an L3 cache, the LLC is the L3 cache, otherwise it is the L2 cache. Counts on a per core basis.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS_LOAD.L2_HIT",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the core is stalled due to a demand load which hit in the L2 cache.)",
      R"(Counts the number of cycles a core is stalled due to a demand load which hit in the L2 cache.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS_LOAD.LLC_HIT",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x06, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted cycles when the core is stalled due to a demand load miss which hit in the LLC.)",
      R"(Counts the number of unhalted cycles when the core is stalled due to a demand load miss which hit in the LLC.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS_LOAD.LLC_MISS",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x78, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted cycles when the core is stalled due to a demand load miss which missed all the local caches.)",
      R"(Counts the number of unhalted cycles when the core is stalled due to a demand load miss which missed all the local caches.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS_LOAD.ALL",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x7f, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted cycles when the core is stalled due to an L1 demand load miss.)",
      R"(Counts the number of unhalted cycles when the core is stalled due to an L1 demand load miss.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS_IFETCH.L2_HIT",
      EventDef::Encoding{
          .code = 0x35, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the core is stalled due to an instruction cache or TLB miss which hit in the L2 cache.)",
      R"(Counts the number of cycles the core is stalled due to an instruction cache or Translation Lookaside Buffer (TLB) miss which hit in the L2 cache.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS_IFETCH.LLC_HIT",
      EventDef::Encoding{
          .code = 0x35, .umask = 0x06, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted cycles when the core is stalled due to an icache or itlb miss which hit in the LLC.)",
      R"(Counts the number of unhalted cycles when the core is stalled due to an icache or itlb miss which hit in the LLC.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS_IFETCH.LLC_MISS",
      EventDef::Encoding{
          .code = 0x35, .umask = 0x78, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted cycles when the core is stalled due to an icache or itlb miss which missed all the caches.)",
      R"(Counts the number of unhalted cycles when the core is stalled due to an icache or itlb miss which missed all the caches.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS_IFETCH.ALL",
      EventDef::Encoding{
          .code = 0x35, .umask = 0x7f, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted cycles when the core is stalled due to an instruction cache or TLB miss.)",
      R"(Counts the number of unhalted cycles when the core is stalled due to an instruction cache or TLB miss.)",
      1000003,
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
      "DTLB_STORE_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to store DTLB misses to a 4K page.)",
      R"(Counts the number of page walks completed due to stores whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 4K pages.  Includes page walks that page fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to store DTLB misses to a 2M or 4M page.)",
      R"(Counts the number of page walks completed due to stores whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 2M or 4M pages.  Includes page walks that page fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event DTLB_STORE_MISSES.WALK_COMPLETED is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x0e, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to store DTLB misses to a 1G page.)",
      R"(Counts the number of page walks completed due to store DTLB misses to a 1G page.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks outstanding in the page miss handler (PMH) for stores every cycle.)",
      R"(Counts the number of page walks outstanding in the page miss handler (PMH) for stores every cycle. A PMH page walk is outstanding from page walk start till PMH becomes idle again (ready to serve next walk). Includes EPT-walk intervals.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of first level TLB misses but second level hits due to stores that did not start a page walk. Accounts for all pages sizes. Will result in a DTLB write from STLB.)",
      R"(Counts the number of first level TLB misses but second level hits due to stores that did not start a page walk. Accounts for all pages sizes. Will result in a DTLB write from STLB.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.ALL_P",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retirement slots not consumed due to front end stalls [This event is alias to TOPDOWN_FE_BOUND.ALL])",
      R"(Counts the number of retirement slots not consumed due to front end stalls [This event is alias to TOPDOWN_FE_BOUND.ALL])",
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
      R"(Counts the number of retirement slots not consumed due to front end stalls [This event is alias to TOPDOWN_FE_BOUND.ALL_P])",
      R"(Counts the number of retirement slots not consumed due to front end stalls [This event is alias to TOPDOWN_FE_BOUND.ALL_P])",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.CISC",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to ms)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to ms)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.BRANCH_DETECT",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to BAClear)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to BAClear)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.PREDECODE",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to predecode wrong)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to predecode wrong)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.DECODE",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to decode stall)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to decode stall)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.ITLB_MISS",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to itlb miss [This event is alias to TOPDOWN_FE_BOUND.ITLB])",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to itlb miss [This event is alias to TOPDOWN_FE_BOUND.ITLB])",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.ICACHE",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to an icache miss)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to an icache miss)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.BRANCH_RESTEER",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to BTClear)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to BTClear)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.FRONTEND_LATENCY",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x72, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to latency related stalls including BACLEARs, BTCLEARs, ITLB misses, and ICache misses.)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to latency related stalls including BACLEARs, BTCLEARs, ITLB misses, and ICache misses.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.OTHER",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend that do not categorize into any other common frontend stall)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend that do not categorize into any other common frontend stall)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.FRONTEND_BANDWIDTH",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x8d, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to frontend bandwidth restrictions due to decode, predecode, cisc, and other limitations.)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to frontend bandwidth restrictions due to decode, predecode, cisc, and other limitations.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_RETIRING.ALL_P",
      EventDef::Encoding{
          .code = 0x72, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of consumed retirement slots. [This event is alias to TOPDOWN_RETIRING.ALL])",
      R"(Counts the number of consumed retirement slots. [This event is alias to TOPDOWN_RETIRING.ALL])",
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
      R"(Counts the number of consumed retirement slots. [This event is alias to TOPDOWN_RETIRING.ALL_P])",
      R"(Counts the number of consumed retirement slots. [This event is alias to TOPDOWN_RETIRING.ALL_P])",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.ALL_P",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear. [This event is alias to TOPDOWN_BAD_SPECULATION.ALL])",
      R"(Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear. Only issue slots wasted due to fast nukes such as memory ordering nukes are counted. Other nukes are not accounted for. Counts all issue slots blocked during this recovery window, including relevant microcode flows, and while uops are not yet available in the instruction queue (IQ) or until an FE_BOUND event occurs besides OTHER and CISC. Also includes the issue slots that were consumed by the backend but were thrown away because they were younger than the mispredict or machine clear. [This event is alias to TOPDOWN_BAD_SPECULATION.ALL])",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.ALL",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear. [This event is alias to TOPDOWN_BAD_SPECULATION.ALL_P])",
      R"(Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear. Only issue slots wasted due to fast nukes such as memory ordering nukes are counted. Other nukes are not accounted for. Counts all issue slots blocked during this recovery window, including relevant microcode flows, and while uops are not yet available in the instruction queue (IQ) or until an FE_BOUND event occurs besides OTHER and CISC. Also includes the issue slots that were consumed by the backend but were thrown away because they were younger than the mispredict or machine clear. [This event is alias to TOPDOWN_BAD_SPECULATION.ALL_P])",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.NUKE",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to a machine clear (nuke).)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to a machine clear (nuke).)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.FASTNUKE",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to Fast Nukes such as  Memory Ordering Machine clears and MRN nukes)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to Fast Nukes such as  Memory Ordering Machine clears and MRN nukes)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.MACHINE_CLEARS",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a machine clear (nuke) of any kind including memory ordering and memory disambiguation.)",
      R"(Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a machine clear (nuke) of any kind including memory ordering and memory disambiguation.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.MISPREDICT",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to Branch Mispredict)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to Branch Mispredict)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.ALL_P",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retirement slots not consumed due to backend stalls [This event is alias to TOPDOWN_BE_BOUND.ALL])",
      R"(Counts the number of retirement slots not consumed due to backend stalls [This event is alias to TOPDOWN_BE_BOUND.ALL])",
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
      R"(Counts the number of retirement slots not consumed due to backend stalls [This event is alias to TOPDOWN_BE_BOUND.ALL_P])",
      R"(Counts the number of retirement slots not consumed due to backend stalls [This event is alias to TOPDOWN_BE_BOUND.ALL_P])",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.ALLOC_RESTRICTIONS",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to due to certain allocation restrictions)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to due to certain allocation restrictions)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.MEM_SCHEDULER",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to memory reservation stall (scheduler not being able to accept another uop).  This could be caused by RSV full or load/store buffer block.)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to memory reservation stall (scheduler not being able to accept another uop).  This could be caused by RSV full or load/store buffer block.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.NON_MEM_SCHEDULER",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to IEC and FPC RAT stalls - which can be due to the FIQ and IEC reservation station stall (integer, FP and SIMD scheduler not being able to accept another uop. ))",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to IEC and FPC RAT stalls - which can be due to the FIQ and IEC reservation station stall (integer, FP and SIMD scheduler not being able to accept another uop. ))",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.SERIALIZATION",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to iq/jeu scoreboards or ms scb)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to iq/jeu scoreboards or ms scb)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.REGISTER",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to mrbl stall.  A 'marble' refers to a physical register file entry, also known as the physical destination (PDST).)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to mrbl stall.  A 'marble' refers to a physical register file entry, also known as the physical destination (PDST).)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.REORDER_BUFFER",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to ROB full)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to ROB full)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SERIALIZATION.C01_MS_SCB",
      EventDef::Encoding{
          .code = 0x75, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots in a UMWAIT or TPAUSE instruction where no uop issues due to the instruction putting the CPU into the C0.1 activity state.)",
      R"(Counts the number of issue slots in a UMWAIT or TPAUSE instruction where no uop issues due to the instruction putting the CPU into the C0.1 activity state.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event ICACHE.MISSES is allowlisted
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
      "ITLB_MISSES.MISS_CAUSED_WALK",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks initiated by a instruction fetch that missed the first and second level TLBs.)",
      R"(Counts the number of page walks initiated by a instruction fetch that missed the first and second level TLBs.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to instruction fetch misses to a 4K page.)",
      R"(Counts the number of page walks completed due to instruction fetches whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 4K pages.  Includes page walks that page fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to instruction fetch misses to a 2M or 4M page.)",
      R"(Counts the number of page walks completed due to instruction fetches whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 2M or 4M pages.  Includes page walks that page fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event ITLB_MISSES.WALK_COMPLETED is allowlisted
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

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks outstanding for iside in PMH every cycle.)",
      R"(Counts the number of page walks outstanding for iside in PMH every cycle.  A PMH page walk is outstanding from page walk start till PMH becomes idle again (ready to serve next walk). Includes EPT-walk intervals.  Walks could be counted by edge detecting on this event, but would count restarted suspended walks.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of first level TLB misses but second level hits due to an instruction fetch that did not start a page walk. Account for all pages sizes. Will result in an ITLB write from STLB.)",
      R"(Counts the number of first level TLB misses but second level hits due to an instruction fetch that did not start a page walk. Account for all pages sizes. Will result in an ITLB write from STLB.)",
      2000003,
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
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event UOPS_RETIRED.ALL is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.ALL",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of uops retired.)",
      R"(Counts the total number of uops retired.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.MS",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of uops that are from the complex flows issued by the micro-sequencer (MS).  This includes uops from flows due to complex instructions, faults, assists, and inserted flows.)",
      R"(Counts the number of uops that are from the complex flows issued by the micro-sequencer (MS).  This includes uops from flows due to complex instructions, faults, assists, and inserted flows.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.X87",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of x87 uops retired, includes those in ms flows)",
      R"(Counts the number of x87 uops retired, includes those in ms flows)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.FPDIV",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of floating point divide uops retired (x87 and sse, including x87 sqrt).)",
      R"(Counts the number of floating point divide uops retired (x87 and sse, including x87 sqrt).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.IDIV",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of integer divide uops retired.)",
      R"(Counts the number of integer divide uops retired.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.SMC",
      EventDef::Encoding{
          .code = 0xc3, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of machine clears due to program modifying data (self modifying code) within 1K of a recently fetched code page.)",
      R"(Counts the number of machine clears due to program modifying data (self modifying code) within 1K of a recently fetched code page.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.MEMORY_ORDERING",
      EventDef::Encoding{
          .code = 0xc3, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of machine clears due to memory ordering caused by a snoop from an external agent. Does not count internally generated machine clears such as those due to memory disambiguation.)",
      R"(Counts the number of machine clears due to memory ordering caused by a snoop from an external agent. Does not count internally generated machine clears such as those due to memory disambiguation.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.FP_ASSIST",
      EventDef::Encoding{
          .code = 0xc3, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of floating point operations retired that required microcode assist.)",
      R"(Counts the number of floating point operations retired that required microcode assist, which is not a reflection of the number of FP operations, instructions or uops.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.DISAMBIGUATION",
      EventDef::Encoding{
          .code = 0xc3, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of machine clears due to memory ordering in which an internal load passes an older store within the same CPU.)",
      R"(Counts the number of machine clears due to memory ordering in which an internal load passes an older store within the same CPU.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.PAGE_FAULT",
      EventDef::Encoding{
          .code = 0xc3, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of machine clears due to a page fault.  Counts both I-Side and D-Side (Loads/Stores) page faults.  A page fault occurs when either the page is not present, or an access violation occurs.)",
      R"(Counts the number of machine clears due to a page fault.  Counts both I-Side and D-Side (Loads/Stores) page faults.  A page fault occurs when either the page is not present, or an access violation occurs.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.SLOW",
      EventDef::Encoding{
          .code = 0xc3, .umask = 0x6f, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of machine clears that flush the pipeline and restart the machine with the use of microcode due to SMC, MEMORY_ORDERING, FP_ASSISTS, PAGE_FAULT, DISAMBIGUATION, and FPC_VIRTUAL_TRAP.)",
      R"(Counts the number of machine clears that flush the pipeline and restart the machine with the use of microcode due to SMC, MEMORY_ORDERING, FP_ASSISTS, PAGE_FAULT, DISAMBIGUATION, and FPC_VIRTUAL_TRAP.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event BR_INST_RETIRED.ALL_BRANCHES is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of branch instructions retired for all branch types.)",
      R"(Counts the total number of instructions in which the instruction pointer (IP) of the processor is resteered due to a branch instruction and the branch instruction successfully retires.  All branch type instructions are accounted for.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.COND",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x7e, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired JCC (Jump on Conditional Code) branch instructions retired, includes both taken and not taken branches.)",
      R"(Counts the number of retired JCC (Jump on Conditional Code) branch instructions retired, includes both taken and not taken branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.FAR_BRANCH",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xbf, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of far branch instructions retired, includes far jump, far call and return, and interrupt call and return.)",
      R"(Counts the number of far branch instructions retired, includes far jump, far call and return, and interrupt call and return.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.INDIRECT",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xeb, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of near indirect JMP and near indirect CALL branch instructions retired.)",
      R"(Counts the number of near indirect JMP and near indirect CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_RETURN",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xf7, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of near RET branch instructions retired.)",
      R"(Counts the number of near RET branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_CALL",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xf9, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of near CALL branch instructions retired.)",
      R"(Counts the number of near CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.INDIRECT_CALL",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xfb, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of near indirect CALL branch instructions retired.)",
      R"(Counts the number of near indirect CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.COND_TAKEN",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xfe, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of taken JCC (Jump on Conditional Code) branch instructions retired.)",
      R"(Counts the number of taken JCC (Jump on Conditional Code) branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
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
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.COND",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x7e, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted JCC (Jump on Conditional Code) branch instructions retired.)",
      R"(Counts the number of mispredicted JCC (Jump on Conditional Code) branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NEAR_TAKEN",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted near taken branch instructions retired.)",
      R"(Counts the number of mispredicted near taken branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.INDIRECT",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0xeb, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted near indirect JMP and near indirect CALL branch instructions retired.)",
      R"(Counts the number of mispredicted near indirect JMP and near indirect CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.RETURN",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0xf7, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted near RET branch instructions retired.)",
      R"(Counts the number of mispredicted near RET branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.INDIRECT_CALL",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0xfb, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted near indirect CALL branch instructions retired.)",
      R"(Counts the number of mispredicted near indirect CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.COND_TAKEN",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0xfe, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted taken JCC (Jump on Conditional Code) branch instructions retired.)",
      R"(Counts the number of mispredicted taken JCC (Jump on Conditional Code) branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FRONTEND_RETIRED.ITLB_MISS",
      EventDef::Encoding{
          .code = 0xc6, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of instructions retired that were tagged because empty issue slots were seen before the uop due to ITLB miss)",
      R"(Counts the number of instructions retired that were tagged because empty issue slots were seen before the uop due to ITLB miss)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_INST_RETIRED.32B_SP",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired instructions whose sources are a scalar 32bit single precision floating point.)",
      R"(Counts the number of retired instructions whose sources are a scalar 32bit single precision floating point.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_INST_RETIRED.64B_DP",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired instructions whose sources are a scalar 64 bit double precision floating point.)",
      R"(Counts the number of retired instructions whose sources are a scalar 64 bit double precision floating point.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_INST_RETIRED.128B_SP",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired instructions whose sources are a packed 128 bit single precision floating point. This may be SSE or AVX.128 operations.)",
      R"(Counts the number of retired instructions whose sources are a packed 128 bit single precision floating point. This may be SSE or AVX.128 operations.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_INST_RETIRED.128B_DP",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of  floating point retired instructions.)",
      R"(Counts the total number of  floating point retired instructions.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_INST_RETIRED.256B_DP",
      EventDef::Encoding{
          .code = 0xc7, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired instructions whose sources are a packed 256 bit double precision floating point.)",
      R"(Counts the number of retired instructions whose sources are a packed 256 bit double precision floating point.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event FP_FLOPS_RETIRED.FP64 is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_FLOPS_RETIRED.FP64",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of floating point operations that produce 64 bit double precision results [This event is alias to FP_FLOPS_RETIRED.DP])",
      R"(Counts the number of floating point operations that produce 64 bit double precision results [This event is alias to FP_FLOPS_RETIRED.DP])",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event FP_FLOPS_RETIRED.FP32 is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_FLOPS_RETIRED.FP32",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of floating point operations that produce 32 bit single precision results [This event is alias to FP_FLOPS_RETIRED.SP])",
      R"(Counts the number of floating point operations that produce 32 bit single precision results [This event is alias to FP_FLOPS_RETIRED.SP])",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_FLOPS_RETIRED.ALL",
      EventDef::Encoding{
          .code = 0xc8, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of all types of floating point operations per uop with all default weighting)",
      R"(Counts the number of all types of floating point operations per uop with all default weighting)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.FPDIV_ACTIVE",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x02, .cmask = 1, .msr_values = {0x00}},
      R"(Counts the number of cycles when any of the floating point dividers are active.)",
      R"(Counts the number of cycles when any of the floating point dividers are active.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.DIV_ACTIVE",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x03, .cmask = 1, .msr_values = {0x00}},
      R"(Counts the number of cycles when any of the floating point or integer dividers are active.)",
      R"(Counts the number of cycles when any of the floating point or integer dividers are active.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

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
      EventDef::IntelFeatures{.data_la = true, .l1_hit_indication = true},
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
      EventDef::IntelFeatures{.data_la = true, .l1_hit_indication = true},
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
      EventDef::IntelFeatures{.data_la = true, .l1_hit_indication = true},
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
      EventDef::IntelFeatures{.data_la = true, .l1_hit_indication = true},
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
      EventDef::IntelFeatures{.data_la = true, .l1_hit_indication = true},
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
      EventDef::IntelFeatures{.data_la = true, .l1_hit_indication = true},
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
      EventDef::IntelFeatures{.data_la = true, .l1_hit_indication = true},
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
      EventDef::IntelFeatures{.data_la = true, .l1_hit_indication = true},
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
      EventDef::IntelFeatures{.data_la = true, .l1_hit_indication = true},
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
      EventDef::IntelFeatures{.data_la = true, .l1_hit_indication = true},
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
      EventDef::IntelFeatures{.data_la = true, .l1_hit_indication = true},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOCK_LOADS",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x21, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that performed one or more locks)",
      R"(Counts the number of load uops retired that performed one or more locks)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_LOADS",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x41, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired split load uops.)",
      R"(Counts the number of retired split load uops.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_STORES",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x42, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired split store uops.)",
      R"(Counts the number of retired split store uops.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x43, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of memory uops retired that were splits.)",
      R"(Counts the number of memory uops retired that were splits.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true},
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
      EventDef::IntelFeatures{.data_la = true},
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
      EventDef::IntelFeatures{.data_la = true},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load ops retired that hit the L1 data cache.)",
      R"(Counts the number of load ops retired that hit the L1 data cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load ops retired that hit in the L2 cache.)",
      R"(Counts the number of load ops retired that hit in the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L3_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x1c, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load ops retired that hit in the L3 cache.)",
      R"(Counts the number of load ops retired that hit in the L3 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.WCB_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of loads that hit in a write combining buffer (WCB), excluding the first load that caused the WCB to allocate.)",
      R"(Counts the number of loads that hit in a write combining buffer (WCB), excluding the first load that caused the WCB to allocate.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_MISS",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load ops retired that miss in the L1 data cache.)",
      R"(Counts the number of load ops retired that miss in the L1 data cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_MISS",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load ops retired that miss in the L2 cache.)",
      R"(Counts the number of load ops retired that miss in the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_L3_MISS_RETIRED.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xd3, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load ops retired that miss the L3 cache and hit in DRAM)",
      R"(Counts the number of load ops retired that miss the L3 cache and hit in DRAM)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISC_RETIRED.LBR_INSERTS",
      EventDef::Encoding{
          .code = 0xe4, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of Last Branch Record (LBR) entries. Requires LBRs to be enabled and configured in IA32_LBR_CTL. [This event is alias to LBR_INSERTS.ANY])",
      R"(Counts the number of Last Branch Record (LBR) entries. Requires LBRs to be enabled and configured in IA32_LBR_CTL. [This event is alias to LBR_INSERTS.ANY])",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.ANY",
      EventDef::Encoding{
          .code = 0xe6, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of BACLEARS due to all branch types including conditional and unconditional jumps, returns, and indirect branches.)",
      R"(Counts the total number of BACLEARS, which occur when the Branch Target Buffer (BTB) prediction or lack thereof, was corrected by a later branch predictor in the frontend.  Includes BACLEARS due to all branch types including conditional and unconditional jumps, returns, and indirect branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
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
      "OCR.DEMAND_DATA_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000001}},
      R"(Counts demand data reads that were supplied by DRAM attached to this socket.)",
      R"(Counts demand data reads that were supplied by DRAM attached to this socket.)",
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

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.STREAMING_WR.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10800}},
      R"(Counts streaming stores that have any type of response.)",
      R"(Counts streaming stores that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0001}},
      R"(Counts demand data reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      R"(Counts demand data reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0001}},
      R"(Counts demand data reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      R"(Counts demand data reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0xB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x01, .cmask = 0, .msr_values = {0x730000001}},
      R"(Counts demand data reads that were supplied by DRAM attached to another socket.)",
      R"(Counts demand data reads that were supplied by DRAM attached to another socket.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace sierraforest_core
} // namespace facebook::hbt::perf_event::generated
