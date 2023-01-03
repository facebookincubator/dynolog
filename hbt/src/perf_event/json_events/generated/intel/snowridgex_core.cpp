// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace snowridgex_core {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from snowridgex_core.json (305 events).

    Supported SKUs:
        - Arch: x86, Model: SNR id: 134
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of instructions retired. (Fixed event))",
      R"(Counts the total number of instructions that retired. For instructions that consist of multiple uops, this event counts the retirement of the last uop of the instruction. This event continues counting during hardware interrupts, traps, and inside interrupt handlers. This event uses fixed counter 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.CORE",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted core clock cycles. (Fixed event))",
      R"(Counts the number of core cycles while the core is not in a halt state. The core enters the halt state when it is running the HLT instruction. The core frequency may change from time to time. For this reason this event may have a changing ratio with regards to time. This event uses fixed counter 1.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_TSC",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted reference clock cycles at TSC frequency. (Fixed event))",
      R"(Counts the number of reference cycles that the core is not in a halt state. The core enters the halt state when it is running the HLT instruction. This event is not affected by core frequency changes and increments at a fixed frequency that is also used for the Time Stamp Counter (TSC). This event uses fixed counter 2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.DATA_UNKNOWN",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired loads that are blocked because its address exactly matches an older store whose data is not ready.)",
      R"(Counts the number of retired loads that are blocked because its address exactly matches an older store whose data is not ready.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.STORE_FORWARD",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired loads that are blocked because its address partially overlapped with an older store.)",
      R"(Counts the number of retired loads that are blocked because its address partially overlapped with an older store.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.4K_ALIAS",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired loads that are blocked because it initially appears to be store forward blocked, but subsequently is shown not to be blocked based on 4K alias check.)",
      R"(Counts the number of retired loads that are blocked because it initially appears to be store forward blocked, but subsequently is shown not to be blocked based on 4K alias check.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.DTLB_MISS",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired loads that are blocked due to a first level TLB miss.)",
      R"(Counts the number of retired loads that are blocked due to a first level TLB miss.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LD_BLOCKS.ALL",
      EventDef::Encoding{
          .code = 0x03, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired loads that are blocked for any of the following reasons:  DTLB miss, address alias, store forward or data unknown (includes memory disambiguation blocks and ESP consuming load blocks).)",
      R"(Counts the number of retired loads that are blocked for any of the following reasons:  DTLB miss, address alias, store forward or data unknown (includes memory disambiguation blocks and ESP consuming load blocks).)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

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

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_1G",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to load DTLB misses to a 1G page.)",
      R"(Counts the number of page walks completed due to loads (including SW prefetches) whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 1GB pages. Includes page walks that page fault.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x0e, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to load DTLB misses to any page size.)",
      R"(Counts the number of page walks completed due to loads (including SW prefetches) whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to any page size. Includes page walks that page fault.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks outstanding in the page miss handler (PMH) for demand loads every cycle.)",
      R"(Counts the number of page walks outstanding in the page miss handler (PMH) for demand loads every cycle.  A page walk is outstanding from start till PMH becomes idle again (ready to serve next walk). Includes EPT-walk intervals.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of first level TLB misses but second level hits due to a demand load that did not start a page walk. Account for all page sizes. Will result in a DTLB write from STLB.)",
      R"(Counts the number of first level TLB misses but second level hits due to a demand load that did not start a page walk. Account for all page sizes. Will result in a DTLB write from STLB.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.PDE_CACHE_MISS",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks due to loads that miss the PDE (Page Directory Entry) cache.)",
      R"(Counts the number of page walks due to loads that miss the PDE (Page Directory Entry) cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.ANY",
      EventDef::Encoding{
          .code = 0x0e, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of uops issued by the front end every cycle.)",
      R"(Counts the number of uops issued by the front end every cycle. When 4-uops are requested and only 2-uops are delivered, the event counts 2.  Uops_issued correlates to the number of ROB entries.  If uop takes 2 ROB slots it counts as 2 uops_issued.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISALIGN_MEM_REF.LOAD_PAGE_SPLIT",
      EventDef::Encoding{
          .code = 0x13, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of misaligned load uops that are 4K page splits.)",
      R"(Counts the number of misaligned load uops that are 4K page splits.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MISALIGN_MEM_REF.STORE_PAGE_SPLIT",
      EventDef::Encoding{
          .code = 0x13, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of misaligned store uops that are 4K page splits.)",
      R"(Counts the number of misaligned store uops that are 4K page splits.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_REQUEST.ALL",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of L2 Cache accesses. Counts on a per core basis.)",
      R"(Counts the total number of L2 Cache Accesses, includes hits, misses, rejects  front door requests for CRd/DRd/RFO/ItoM/L2 Prefetches only.  Counts on a per core basis.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_REQUEST.MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of L2 Cache accesses that resulted in a miss. Counts on a per core basis.)",
      R"(Counts the number of L2 Cache accesses that resulted in a miss from a front door request only (does not include rejects or recycles). Counts on a per core basis.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_REQUEST.HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of L2 Cache accesses that resulted in a hit. Counts on a per core basis.)",
      R"(Counts the number of L2 Cache accesses that resulted in a hit from a front door request only (does not include rejects or recycles), Counts on a per core basis.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_REQUEST.REJECTS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of L2 Cache accesses that miss the L2 and get rejected. Counts on a per core basis.)",
      R"(Counts the number of L2 Cache accesses that miss the L2 and get BBL reject  short and long rejects (includes those counted in L2_reject_XQ.any). Counts on a per core basis.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_REJECT_XQ.ANY",
      EventDef::Encoding{
          .code = 0x30, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of demand and prefetch transactions that the External Queue (XQ) rejects due to a full or near full condition.)",
      R"(Counts the number of demand and prefetch transactions that the External Queue (XQ) rejects due to a full or near full condition which likely indicates back pressure from the IDI link.  The XQ may reject transactions from the L2Q (non-cacheable requests), BBL (L2 misses) and WOB (L2 write-back victims).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CORE_REJECT_L2Q.ANY",
      EventDef::Encoding{
          .code = 0x31, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of core requests (demand and L1 prefetchers) rejected by the L2 queue (L2Q) due to a full condition.)",
      R"(Counts the number of (demand and L1 prefetchers) core requests rejected by the L2 queue (L2Q) due to a full or nearly full condition, which likely indicates back pressure from L2Q.  It also counts requests that would have gone directly to the External Queue (XQ), but are rejected due to a full or nearly full condition, indicating back pressure from the IDI link.  The L2Q may also reject transactions  from a core to ensure fairness between cores, or to delay a cores dirty eviction when the address conflicts incoming external snoops.  (Note that L2 prefetcher requests that are dropped are not counted by this event).  Counts on a per core basis.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "C0_STALLS.LOAD_L2_HIT",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(This event is deprecated. Refer to new event MEM_BOUND_STALLS.LOAD_L2_HIT)",
      R"(This event is deprecated. Refer to new event MEM_BOUND_STALLS.LOAD_L2_HIT)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS.LOAD_L2_HIT",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the core is stalled due to a demand load which hit in the L2 cache.)",
      R"(Counts the number of cycles the core is stalled due to a demand load which hit in the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "C0_STALLS.LOAD_LLC_HIT",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(This event is deprecated. Refer to new event MEM_BOUND_STALLS.LOAD_LLC_HIT)",
      R"(This event is deprecated. Refer to new event MEM_BOUND_STALLS.LOAD_LLC_HIT)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS.LOAD_LLC_HIT",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the core is stalled due to a demand load which hit in the LLC or other core with HITE/F/M.)",
      R"(Counts the number of cycles the core is stalled due to a demand load which hit in the Last Level Cache (LLC) or other core with HITE/F/M.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "C0_STALLS.LOAD_DRAM_HIT",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(This event is deprecated. Refer to new event MEM_BOUND_STALLS.LOAD_DRAM_HIT)",
      R"(This event is deprecated. Refer to new event MEM_BOUND_STALLS.LOAD_DRAM_HIT)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS.LOAD_DRAM_HIT",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the core is stalled due to a demand load miss which hit in DRAM or MMIO (Non-DRAM).)",
      R"(Counts the number of cycles the core is stalled due to a demand load miss which hit in DRAM or MMIO (Non-DRAM).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS.LOAD",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x07, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the core is stalled due to a demand load miss which hit in the L2, LLC, DRAM or MMIO (Non-DRAM).)",
      R"(Counts the number of cycles the core is stalled due to a demand load miss which hit in the L2, LLC, DRAM or MMIO (Non-DRAM).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS.IFETCH_L2_HIT",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the core is stalled due to an instruction cache or TLB miss which hit in the L2 cache.)",
      R"(Counts the number of cycles the core is stalled due to an instruction cache or Translation Lookaside Buffer (TLB) miss which hit in the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS.IFETCH_LLC_HIT",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the core is stalled due to an instruction cache or TLB miss which hit in the LLC or other core with HITE/F/M.)",
      R"(Counts the number of cycles the core is stalled due to an instruction cache or Translation Lookaside Buffer (TLB) miss which hit in the Last Level Cache (LLC) or other core with HITE/F/M.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS.IFETCH_DRAM_HIT",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the core is stalled due to an instruction cache or TLB miss which hit in DRAM or MMIO (Non-DRAM).)",
      R"(Counts the number of cycles the core is stalled due to an instruction cache or translation lookaside buffer (TLB) miss which hit in DRAM or MMIO (non-DRAM).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS.IFETCH",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x38, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the core is stalled due to an instruction cache or TLB miss which hit in the L2, LLC, DRAM or MMIO (Non-DRAM).)",
      R"(Counts the number of cycles the core is stalled due to an instruction cache or TLB miss which hit in the L2, LLC, DRAM or MMIO (Non-DRAM).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_BOUND_STALLS.STORE_BUFFER_FULL",
      EventDef::Encoding{
          .code = 0x34, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the core is stalled due to a store buffer being full.)",
      R"(Counts the number of cycles the core is stalled due to a store buffer being full.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.CORE_P",
      EventDef::Encoding{
          .code = 0x3c, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted core clock cycles.)",
      R"(Counts the number of core cycles while the core is not in a halt state. The core enters the halt state when it is running the HLT instruction. The core frequency may change from time to time. For this reason this event may have a changing ratio with regards to time. This event uses a programmable general purpose performance counter.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF",
      EventDef::Encoding{
          .code = 0x3c, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted reference clock cycles at TSC frequency.)",
      R"(Counts the number of reference cycles that the core is not in a halt state. The core enters the halt state when it is running the HLT instruction. This event is not affected by core frequency changes and increments at a fixed frequency that is also used for the Time Stamp Counter (TSC). This event uses fixed counter 2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED_1G",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to store DTLB misses to a 1G page.)",
      R"(Counts the number of page walks completed due to stores whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 1G pages.  Includes page walks that page fault.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x0e, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to store DTLB misses to any page size.)",
      R"(Counts the number of page walks completed due to stores whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to any page size.  Includes page walks that page fault.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks outstanding in the page miss handler (PMH) for stores every cycle.)",
      R"(Counts the number of page walks outstanding in the page miss handler (PMH) for stores every cycle.  A page walk is outstanding from start till PMH becomes idle again (ready to serve next walk). Includes EPT-walk intervals.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of first level TLB misses but second level hits due to stores that did not start a page walk. Account for all pages sizes. Will result in a DTLB write from STLB.)",
      R"(Counts the number of first level TLB misses but second level hits due to stores that did not start a page walk. Account for all pages sizes. Will result in a DTLB write from STLB.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.PDE_CACHE_MISS",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks due to stores that miss the PDE (Page Directory Entry) cache.)",
      R"(Counts the number of page walks due to stores that miss the PDE (Page Directory Entry) cache.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EPT.EPDE_HIT",
      EventDef::Encoding{
          .code = 0x4f, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of Extended Page Directory Entry hits.)",
      R"(Counts the number of Extended Page Directory Entry hits.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EPT.EPDE_MISS",
      EventDef::Encoding{
          .code = 0x4f, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of Extended Page Directory Entry misses.)",
      R"(Counts the number Extended Page Directory Entry misses.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EPT.EPDPE_HIT",
      EventDef::Encoding{
          .code = 0x4f, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of Extended Page Directory Pointer Entry hits.)",
      R"(Counts the number Extended Page Directory Pointer Entry hits.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EPT.EPDPE_MISS",
      EventDef::Encoding{
          .code = 0x4f, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of Extended Page Directory Pointer Entry misses.)",
      R"(Counts the number Extended Page Directory Pointer Entry misses.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "EPT.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x4f, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks outstanding for an Extended Page table walk including GTLB hits per cycle.)",
      R"(Counts the number of page walks outstanding for an Extended Page table walk including GTLB hits per cycle.  The Extended Page Directory cache is used by Virtual Machine operating systems while the guest operating systems use the standard TLB caches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DL1.DIRTY_EVICTION",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of L1D cacheline (dirty) evictions caused by load misses, stores, and prefetches.)",
      R"(Counts the number of L1D cacheline (dirty) evictions caused by load misses, stores, and prefetches.  Does not count evictions or dirty writebacks caused by snoops.  Does not count a replacement unless a (dirty) line was written back.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BUS_LOCK.ALL",
      EventDef::Encoding{
          .code = 0x63,
          .umask = 0x00,
          .edge = true,
          .cmask = 0,
          .msr_values = {0x00}},
      R"(This event is deprecated. Refer to new event BUS_LOCK.SELF_LOCKS)",
      R"(This event is deprecated. Refer to new event BUS_LOCK.SELF_LOCKS)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BUS_LOCK.SELF_LOCKS",
      EventDef::Encoding{
          .code = 0x63,
          .umask = 0x00,
          .edge = true,
          .cmask = 0,
          .msr_values = {0x00}},
      R"(Counts the number of bus locks a core issued its self (e.g. lock to UC or Split Lock) and does not include cache locks.)",
      R"(Counts the number of bus locks a core issued its self (e.g. lock to UC or Split Lock) and does not include cache locks. Counts on a per core basis.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BUS_LOCK.CYCLES_SELF_BLOCK",
      EventDef::Encoding{
          .code = 0x63, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(This event is deprecated. Refer to new event BUS_LOCK.LOCK_CYCLES)",
      R"(This event is deprecated. Refer to new event BUS_LOCK.LOCK_CYCLES)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BUS_LOCK.LOCK_CYCLES",
      EventDef::Encoding{
          .code = 0x63, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted cycles a core is blocked due to an accepted lock it issued.)",
      R"(Counts the number of unhalted cycles a core is blocked due to an accepted lock it issued. Counts on a per core basis.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BUS_LOCK.CYCLES_OTHER_BLOCK",
      EventDef::Encoding{
          .code = 0x63, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(This event is deprecated. Refer to new event BUS_LOCK.BLOCK_CYCLES)",
      R"(This event is deprecated. Refer to new event BUS_LOCK.BLOCK_CYCLES)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BUS_LOCK.BLOCK_CYCLES",
      EventDef::Encoding{
          .code = 0x63, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted cycles a core is blocked due to an accepted lock issued by other cores.)",
      R"(Counts the number of unhalted cycles a core is blocked due to an accepted lock issued by other cores. Counts on a per core basis.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.ALL",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of issue slots every cycle that were not consumed by the backend due to frontend stalls.)",
      R"(Counts the total number of issue slots every cycle that were not consumed by the backend due to frontend stalls.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.CISC",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to the microcode sequencer (MS).)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to the microcode sequencer (MS).)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.BRANCH_DETECT",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to BACLEARS.)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to BACLEARS, which occurs when the Branch Target Buffer (BTB) prediction or lack thereof, was corrected by a later branch predictor in the frontend. Includes BACLEARS due to all branch types including conditional and unconditional jumps, returns, and indirect branches.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.PREDECODE",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to wrong predecodes.)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to wrong predecodes.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.DECODE",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to decode stalls.)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to decode stalls.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.ITLB",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to ITLB misses.)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to Instruction Table Lookaside Buffer (ITLB) misses.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.ICACHE",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to instruction cache misses.)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to instruction cache misses.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.BRANCH_RESTEER",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to BTCLEARS.)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to BTCLEARS, which occurs when the Branch Target Buffer (BTB) predicts a taken branch.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_FE_BOUND.OTHER",
      EventDef::Encoding{
          .code = 0x71, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to other common frontend stalls not categorized.)",
      R"(Counts the number of issue slots every cycle that were not delivered by the frontend due to other common frontend stalls not categorized.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.MONUKE",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(This event is deprecated. Refer to new event TOPDOWN_BAD_SPECULATION.FASTNUKE)",
      R"(This event is deprecated. Refer to new event TOPDOWN_BAD_SPECULATION.FASTNUKE)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.FASTNUKE",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to fast nukes such as memory ordering and memory disambiguation machine clears.)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to fast nukes such as memory ordering and memory disambiguation machine clears.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.MACHINE_CLEARS",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a machine clear (nuke) of any kind including memory ordering and memory disambiguation.)",
      R"(Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a machine clear (nuke) of any kind including memory ordering and memory disambiguation.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.MISPREDICT",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to branch mispredicts.)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to branch mispredicts.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BAD_SPECULATION.ALL",
      EventDef::Encoding{
          .code = 0x73, .umask = 0x06, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear.)",
      R"(Counts the total number of issue slots that were not consumed by the backend because allocation is stalled due to a mispredicted jump or a machine clear. Only issue slots wasted due to fast nukes such as memory ordering nukes are counted. Other nukes are not accounted for. Counts all issue slots blocked during this recovery window including relevant microcode flows and while uops are not yet available in the instruction queue (IQ) even if an FE_bound event occurs during this period. Also includes the issue slots that were consumed by the backend but were thrown away because they were younger than the mispredict or machine clear.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.ALL",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of issue slots every cycle that were not consumed by the backend due to backend stalls.)",
      R"(Counts the total number of issue slots every cycle that were not consumed by the backend due to backend stalls.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.ALLOC_RESTRICTIONS",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to certain allocation restrictions.)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to certain allocation restrictions.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.MEM_SCHEDULER",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to memory reservation stalls in which a scheduler is not able to accept uops.)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to memory reservation stalls in which a scheduler is not able to accept uops.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.STORE_BUFFER",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(This event is deprecated. )",
      R"(This event is deprecated. )",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.NON_MEM_SCHEDULER",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to IEC or FPC RAT stalls, which can be due to FIQ or IEC reservation stalls in which the integer, floating point or SIMD scheduler is not able to accept uops.)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to IEC or FPC RAT stalls, which can be due to FIQ or IEC reservation stalls in which the integer, floating point or SIMD scheduler is not able to accept uops.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.SERIALIZATION",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to scoreboards from the instruction queue (IQ), jump execution unit (JEU), or microcode sequencer (MS).)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to scoreboards from the instruction queue (IQ), jump execution unit (JEU), or microcode sequencer (MS).)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.REGISTER",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to the physical register file unable to accept an entry (marble stalls).)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to the physical register file unable to accept an entry (marble stalls).)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_BE_BOUND.REORDER_BUFFER",
      EventDef::Encoding{
          .code = 0x74, .umask = 0x40, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to the reorder buffer being full (ROB stalls).)",
      R"(Counts the number of issue slots every cycle that were not consumed by the backend due to the reorder buffer being full (ROB stalls).)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.HIT",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of instruction cache hits.)",
      R"(Counts the number of requests that hit in the instruction cache.  The event only counts new cache line accesses, so that multiple back to back fetches to the exact same cache line and byte chunk count as one.  Specifically, the event counts when accesses from sequential code crosses the cache line boundary, or when a branch target is moved to a new line or to a non-sequential byte chunk of the same line.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.MISSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of instruction cache misses.)",
      R"(Counts the number of missed requests to the instruction cache.  The event only counts new cache line accesses, so that multiple back to back fetches to the exact same cache line and byte chunk count as one.  Specifically, the event counts when accesses from sequential code crosses the cache line boundary, or when a branch target is moved to a new line or to a non-sequential byte chunk of the same line.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.ACCESSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of requests to the instruction cache for one or more bytes of a cache line.)",
      R"(Counts the total number of requests to the instruction cache.  The event only counts new cache line accesses, so that multiple back to back fetches to the exact same cache line or byte chunk count as one.  Specifically, the event counts when accesses from sequential code crosses the cache line boundary, or when a branch target is moved to a new line or to a non-sequential byte chunk of the same line.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB.FILLS",
      EventDef::Encoding{
          .code = 0x81, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of times there was an ITLB miss and a new translation was filled into the ITLB.)",
      R"(Counts the number of times the machine was unable to find a translation in the Instruction Translation Lookaside Buffer (ITLB) and a new translation was filled into the ITLB. The event is speculative in nature, but will not count translations (page walks) that are begun and not finished, or translations that are finished but not filled into the ITLB.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_1G",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks completed due to instruction fetch misses to a 1G page.)",
      R"(Counts the number of page walks completed due to instruction fetches whose address translations missed in all Translation Lookaside Buffer (TLB) levels and were mapped to 1G pages.  Includes page walks that page fault.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_PENDING",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks outstanding in the page miss handler (PMH) for instruction fetches every cycle.)",
      R"(Counts the number of page walks outstanding in the page miss handler (PMH) for instruction fetches every cycle.  A page walk is outstanding from start till PMH becomes idle again (ready to serve next walk).)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.PDE_CACHE_MISS",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of page walks due to an instruction fetch that miss the PDE (Page Directory Entry) cache.)",
      R"(Counts the number of page walks due to an instruction fetch that miss the PDE (Page Directory Entry) cache.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY_P",
      EventDef::Encoding{
          .code = 0xc0, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of instructions retired.)",
      R"(Counts the total number of instructions that retired. For instructions that consist of multiple uops, this event counts the retirement of the last uop of the instruction. This event continues counting during hardware interrupts, traps, and inside interrupt handlers. This event uses a programmable general purpose performance counter.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.ALL",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of uops retired.)",
      R"(Counts the total number of uops retired.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TOPDOWN_RETIRING.ALL",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of consumed retirement slots.)",
      R"(Counts the total number of consumed retirement slots.)",
      1000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.MS",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of uops that are from complex flows issued by the micro-sequencer (MS).)",
      R"(Counts the number of uops that are from complex flows issued by the Microcode Sequencer (MS). This includes uops from flows due to complex instructions, faults, assists, and inserted flows.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.X87",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of x87 uops retired, includes those in MS flows.)",
      R"(Counts the number of x87 uops retired, includes those in MS flows.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.FPDIV",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of floating point divide uops retired (x87 and SSE, including x87 sqrt).)",
      R"(Counts the number of floating point divide uops retired (x87 and SSE, including x87 sqrt).)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.IDIV",
      EventDef::Encoding{
          .code = 0xc2, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of integer divide uops retired.)",
      R"(Counts the number of integer divide uops retired.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.ANY",
      EventDef::Encoding{
          .code = 0xc3, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of machine clears for any reason including, but not limited to, memory ordering, memory disambiguation, SMC, and FP assist.)",
      R"(Counts the total number of machine clears for any reason including, but not limited to, memory ordering, memory disambiguation, SMC, and FP assist.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

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

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.JCC",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x7e, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired JCC (Jump on Conditional Code) branch instructions retired, includes both taken and not taken branches.)",
      R"(Counts the number of retired JCC (Jump on Conditional Code) branch instructions retired, includes both taken and not taken branches.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.FAR_BRANCH",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xbf, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of far branch instructions retired, includes far jump, far call and return, and interrupt call and return.)",
      R"(Counts the number of far branch instructions retired, includes far jump, far call and return, and interrupt call and return.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NON_RETURN_IND",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xeb, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of near indirect JMP and near indirect CALL branch instructions retired.)",
      R"(Counts the number of near indirect JMP and near indirect CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.RETURN",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xf7, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of near RET branch instructions retired.)",
      R"(Counts the number of near RET branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.CALL",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xf9, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of near CALL branch instructions retired.)",
      R"(Counts the number of near CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.IND_CALL",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xfb, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of near indirect CALL branch instructions retired.)",
      R"(Counts the number of near indirect CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.REL_CALL",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xfd, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of near relative CALL branch instructions retired.)",
      R"(Counts the number of near relative CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.TAKEN_JCC",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0xfe, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of taken JCC (Jump on Conditional Code) branch instructions retired.)",
      R"(Counts the number of taken JCC (Jump on Conditional Code) branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

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

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.JCC",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x7e, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted JCC (Jump on Conditional Code) branch instructions retired.)",
      R"(Counts the number of mispredicted JCC (Jump on Conditional Code) branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NON_RETURN_IND",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0xeb, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted near indirect JMP and near indirect CALL branch instructions retired.)",
      R"(Counts the number of mispredicted near indirect JMP and near indirect CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.RETURN",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0xf7, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted near RET branch instructions retired.)",
      R"(Counts the number of mispredicted near RET branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.IND_CALL",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0xfb, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted near indirect CALL branch instructions retired.)",
      R"(Counts the number of mispredicted near indirect CALL branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.TAKEN_JCC",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0xfe, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted taken JCC (Jump on Conditional Code) branch instructions retired.)",
      R"(Counts the number of mispredicted taken JCC (Jump on Conditional Code) branch instructions retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HW_INTERRUPTS.RECEIVED",
      EventDef::Encoding{
          .code = 0xcb, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of hardware interrupts received by the processor.)",
      R"(Counts the number of hardware interrupts received by the processor.)",
      203,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HW_INTERRUPTS.MASKED",
      EventDef::Encoding{
          .code = 0xcb, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of core cycles during which interrupts are masked (disabled).)",
      R"(Counts the number of core cycles during which interrupts are masked (disabled). Increments by 1 each core cycle that EFLAGS.IF is 0, regardless of whether interrupts are pending or not.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "HW_INTERRUPTS.PENDING_AND_MASKED",
      EventDef::Encoding{
          .code = 0xcb, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of core cycles during which there are pending interrupts while interrupts are masked (disabled).)",
      R"(Counts the number of core cycles during which there are pending interrupts while interrupts are masked (disabled). Increments by 1 each core cycle that both EFLAGS.IF is 0 and an INTR is pending (which means the APIC is telling the ROB to cause an INTR). This event does not increment if EFLAGS.IF is 0 but all interrupt in the APICs Interrupt Request Register (IRR) are inhibited by the PPR (thus either by ISRV or TPR)  because in these cases the interrupts would be held up in the APIC and would not be pended to the ROB. This event does count when an interrupt is only inhibited by MOV/POP SS state machines or the STI state machine. These extra inhibits only last for a single instructions and would not be important.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLES_DIV_BUSY.ANY",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(This event is deprecated. )",
      R"(This event is deprecated. )",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLES_DIV_BUSY.IDIV",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the integer divider is busy.)",
      R"(Counts the number of cycles the integer divider is busy.  Does not imply a stall waiting for the divider.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLES_DIV_BUSY.FPDIV",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of cycles the floating point divider is busy.)",
      R"(Counts the number of cycles the floating point divider is busy.  Does not imply a stall waiting for the divider.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.DTLB_MISS_LOADS",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x11, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that miss in the second Level TLB.)",
      R"(Counts the number of load uops retired that miss in the second Level TLB.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.DTLB_MISS_STORES",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x12, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of store uops retired that miss in the second level TLB.)",
      R"(Counts the number of store uops retired that miss in the second level TLB.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.DTLB_MISS",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x13, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of memory uops retired that missed in the second level TLB.)",
      R"(Counts the number of memory uops retired that missed in the second level TLB.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.LOCK_LOADS",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x21, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that performed one or more locks.)",
      R"(Counts the number of load uops retired that performed one or more locks.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_LOADS",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x41, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired split load uops.)",
      R"(Counts the number of retired split load uops.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT_STORES",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x42, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of retired split store uops.)",
      R"(Counts the number of retired split store uops.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.SPLIT",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x43, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of memory uops retired that were splits.)",
      R"(Counts the number of memory uops retired that were splits.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_LOADS",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x81, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired.)",
      R"(Counts the total number of load uops retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_STORES",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x82, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of store uops retired.)",
      R"(Counts the total number of store uops retired.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x83, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of memory uops retired.)",
      R"(Counts the number of memory uops retired.  A single uop that performs both a load AND a store will be counted as 1, not 2 (e.g. ADD [mem], CONST))",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that hit in the L1 data cache.)",
      R"(Counts the number of load uops retired that hit in the L1 data cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that hit in the L2 cache.)",
      R"(Counts the number of load uops retired that hit in the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L3_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that hit in the L3 cache.)",
      R"(Counts the number of load uops retired that hit in the L3 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_MISS",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that miss in the L1 data cache.)",
      R"(Counts the number of load uops retired that miss in the L1 data cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_MISS",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that miss in the L2 cache.)",
      R"(Counts the number of load uops retired that miss in the L2 cache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.HITM",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x20, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that hit in the L3 cache, in which a snoop was required and modified data was forwarded from another core or module.)",
      R"(Counts the number of load uops retired that hit in the L3 cache, in which a snoop was required and modified data was forwarded from another core or module.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.DRAM_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x80, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that hit in DRAM.)",
      R"(Counts the number of load uops retired that hit in DRAM.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      std::nullopt // Errata
      ));

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

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.INDIRECT",
      EventDef::Encoding{
          .code = 0xe6, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of BACLEARS due to an indirect branch.)",
      R"(Counts the number of BACLEARS due to an indirect branch.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.UNCOND",
      EventDef::Encoding{
          .code = 0xe6, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of BACLEARS due to a direct, unconditional jump.)",
      R"(Counts the number of BACLEARS due to a direct, unconditional jump.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.RETURN",
      EventDef::Encoding{
          .code = 0xe6, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of BACLEARS due to a return branch.)",
      R"(Counts the number of BACLEARS due to a return branch.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEARS.COND",
      EventDef::Encoding{
          .code = 0xe6, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of BACLEARS due to a conditional jump.)",
      R"(Counts the number of BACLEARS due to a conditional jump.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BTCLEAR.ANY",
      EventDef::Encoding{
          .code = 0xe8, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the total number of BTCLEARS.)",
      R"(Counts the total number of BTCLEARS which occurs when the Branch Target Buffer (BTB) predicts a taken branch.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DECODE_RESTRICTION.PREDECODE_WRONG",
      EventDef::Encoding{
          .code = 0xe9, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of times a decode restriction reduces the decode throughput due to wrong instruction length prediction.)",
      R"(Counts the number of times a decode restriction reduces the decode throughput due to wrong instruction length prediction.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_NOT_NEEDED)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_NOT_NEEDED)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_MISS)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HIT_NO_FWD)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HIT_NO_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HIT_WITH_FWD)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HIT_WITH_FWD)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HITM)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HITM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0XB7,
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

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0010}},
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0010}},
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0010}},
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0010}},
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0010}},
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L1D_AND_SWPF.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0400}},
      R"(Counts L1 data cache hardware prefetches and software prefetches (except PREFETCHW and PFRFO) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      R"(Counts L1 data cache hardware prefetches and software prefetches (except PREFETCHW and PFRFO) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1001003C0000}},
      R"(Counts uncached memory reads that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      R"(Counts uncached memory reads that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1002003C0000}},
      R"(Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      R"(Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1004003C0000}},
      R"(Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      R"(Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1008003C0000}},
      R"(Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      R"(Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1010003C0000}},
      R"(Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      R"(Counts uncached memory reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0044}},
      R"(Counts all code reads that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      R"(Counts all code reads that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0044}},
      R"(Counts all code reads that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      R"(Counts all code reads that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0044}},
      R"(Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      R"(Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0044}},
      R"(Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      R"(Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0044}},
      R"(Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      R"(Counts all code reads that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PARTIAL_STREAMING_WR.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x400000010000}},
      R"(Counts streaming stores which modify only part of a 64 byte cacheline that have any type of response.)",
      R"(Counts streaming stores which modify only part of a 64 byte cacheline that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PARTIAL_STREAMING_WR.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x402184000000}},
      R"(Counts streaming stores which modify only part of a 64 byte cacheline that were not supplied by the L3 cache.)",
      R"(Counts streaming stores which modify only part of a 64 byte cacheline that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.FULL_STREAMING_WR.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x800000010000}},
      R"(Counts streaming stores which modify a full 64 byte cacheline that have any type of response.)",
      R"(Counts streaming stores which modify a full 64 byte cacheline that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.FULL_STREAMING_WR.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x802184000000}},
      R"(Counts streaming stores which modify a full 64 byte cacheline that were not supplied by the L3 cache.)",
      R"(Counts streaming stores which modify a full 64 byte cacheline that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.L1WB_M.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1000000010000}},
      R"(Counts modified writebacks from L1 cache that miss the L2 cache that have any type of response.)",
      R"(Counts modified writebacks from L1 cache that miss the L2 cache that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.L1WB_M.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1002184000000}},
      R"(Counts modified writebacks from L1 cache that miss the L2 cache that were not supplied by the L3 cache.)",
      R"(Counts modified writebacks from L1 cache that miss the L2 cache that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.L2WB_M.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2000000010000}},
      R"(Counts modified writeBacks from L2 cache that miss the L3 cache that have any type of response.)",
      R"(Counts modified writeBacks from L2 cache that miss the L3 cache that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.L2WB_M.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2002184000000}},
      R"(Counts modified writeBacks from L2 cache that miss the L3 cache that were not supplied by the L3 cache.)",
      R"(Counts modified writeBacks from L2 cache that miss the L3 cache that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10044}},
      R"(Counts all code reads that have any type of response.)",
      R"(Counts all code reads that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x8000000000000044}},
      R"(Counts all code reads that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      R"(Counts all code reads that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000044}},
      R"(Counts all code reads that were supplied by DRAM.)",
      R"(Counts all code reads that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000044}},
      R"(Counts all code reads that were not supplied by the L3 cache.)",
      R"(Counts all code reads that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.ANY_RESPONSE)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.ANY_RESPONSE)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x8000000000000001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.OUTSTANDING)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.OUTSTANDING)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.DRAM)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.DRAM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_MISS)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_MISS)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that have any type of response.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.OUTSTANDING",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x8000000000000002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the L3 cache.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that have any type of response.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were not supplied by the L3 cache.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.COREWB_M.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3000000010000}},
      R"(Counts modified writebacks from L1 cache and L2 cache that have any type of response.)",
      R"(Counts modified writebacks from L1 cache and L2 cache that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.COREWB_M.OUTSTANDING",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x8003000000000000}},
      R"(Counts modified writebacks from L1 cache and L2 cache that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      R"(Counts modified writebacks from L1 cache and L2 cache that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.COREWB_M.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3002184000000}},
      R"(Counts modified writebacks from L1 cache and L2 cache that were not supplied by the L3 cache.)",
      R"(Counts modified writebacks from L1 cache and L2 cache that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10010}},
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that have any type of response.)",
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000010}},
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by DRAM.)",
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000010}},
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were not supplied by the L3 cache.)",
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that have any type of response.)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.OUTSTANDING",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x8000000000000020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by DRAM.)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were not supplied by the L3 cache.)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that have any type of response.)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x8000000000000040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by DRAM.)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were not supplied by the L3 cache.)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L1D_AND_SWPF.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10400}},
      R"(Counts L1 data cache hardware prefetches and software prefetches (except PREFETCHW and PFRFO) that have any type of response.)",
      R"(Counts L1 data cache hardware prefetches and software prefetches (except PREFETCHW and PFRFO) that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.STREAMING_WR.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10800}},
      R"(Counts streaming stores that have any type of response.)",
      R"(Counts streaming stores that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.STREAMING_WR.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000800}},
      R"(Counts streaming stores that were not supplied by the L3 cache.)",
      R"(Counts streaming stores that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x18000}},
      R"(Counts miscellaneous requests, such as I/O accesses, that have any type of response.)",
      R"(Counts miscellaneous requests, such as I/O accesses, that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184008000}},
      R"(Counts miscellaneous requests, such as I/O accesses, that were not supplied by the L3 cache.)",
      R"(Counts miscellaneous requests, such as I/O accesses, that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x100000010000}},
      R"(Counts uncached memory reads that have any type of response.)",
      R"(Counts uncached memory reads that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x8000100000000000}},
      R"(Counts uncached memory reads that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      R"(Counts uncached memory reads that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.DRAM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x100184000000}},
      R"(Counts uncached memory reads that were supplied by DRAM.)",
      R"(Counts uncached memory reads that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x102184000000}},
      R"(Counts uncached memory reads that were not supplied by the L3 cache.)",
      R"(Counts uncached memory reads that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_WR.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x200000010000}},
      R"(Counts uncached memory writes that have any type of response.)",
      R"(Counts uncached memory writes that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_WR.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x202184000000}},
      R"(Counts uncached memory writes that were not supplied by the L3 cache.)",
      R"(Counts uncached memory writes that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that have any type of response.)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.OUTSTANDING",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x8000000000000001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by DRAM.)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were not supplied by the L3 cache.)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.LOCAL_DRAM)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.LOCAL_DRAM)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000010}},
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by DRAM.)",
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by DRAM.)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by DRAM.)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x100184000000}},
      R"(Counts uncached memory reads that were supplied by DRAM.)",
      R"(Counts uncached memory reads that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000044}},
      R"(Counts all code reads that were supplied by DRAM.)",
      R"(Counts all code reads that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by DRAM.)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_MISS_LOCAL)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_MISS_LOCAL)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the L3 cache.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were not supplied by the L3 cache.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.COREWB_M.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3002184000000}},
      R"(Counts modified writebacks from L1 cache and L2 cache that were not supplied by the L3 cache.)",
      R"(Counts modified writebacks from L1 cache and L2 cache that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000010}},
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were not supplied by the L3 cache.)",
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were not supplied by the L3 cache.)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were not supplied by the L3 cache.)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.STREAMING_WR.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000800}},
      R"(Counts streaming stores that were not supplied by the L3 cache.)",
      R"(Counts streaming stores that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.OTHER.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184008000}},
      R"(Counts miscellaneous requests, such as I/O accesses, that were not supplied by the L3 cache.)",
      R"(Counts miscellaneous requests, such as I/O accesses, that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x102184000000}},
      R"(Counts uncached memory reads that were not supplied by the L3 cache.)",
      R"(Counts uncached memory reads that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_WR.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x202184000000}},
      R"(Counts uncached memory writes that were not supplied by the L3 cache.)",
      R"(Counts uncached memory writes that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PARTIAL_STREAMING_WR.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x402184000000}},
      R"(Counts streaming stores which modify only part of a 64 byte cacheline that were not supplied by the L3 cache.)",
      R"(Counts streaming stores which modify only part of a 64 byte cacheline that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.FULL_STREAMING_WR.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x802184000000}},
      R"(Counts streaming stores which modify a full 64 byte cacheline that were not supplied by the L3 cache.)",
      R"(Counts streaming stores which modify a full 64 byte cacheline that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.L1WB_M.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1002184000000}},
      R"(Counts modified writebacks from L1 cache that miss the L2 cache that were not supplied by the L3 cache.)",
      R"(Counts modified writebacks from L1 cache that miss the L2 cache that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.L2WB_M.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2002184000000}},
      R"(Counts modified writeBacks from L2 cache that miss the L3 cache that were not supplied by the L3 cache.)",
      R"(Counts modified writeBacks from L2 cache that miss the L3 cache that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000044}},
      R"(Counts all code reads that were not supplied by the L3 cache.)",
      R"(Counts all code reads that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were not supplied by the L3 cache.)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PREFETCHES.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10470}},
      R"(Counts all hardware and software prefetches that have any type of response.)",
      R"(Counts all hardware and software prefetches that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PREFETCHES.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000470}},
      R"(Counts all hardware and software prefetches that were not supplied by the L3 cache.)",
      R"(Counts all hardware and software prefetches that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x10477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that have any type of response.)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that have any type of response.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.OUTSTANDING",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x8000000000000477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that have an outstanding request. Returns the number of cycles until the response is received (i.e. XQ to XQ latency).)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM.)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.L3_MISS",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the L3 cache.)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x184000477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM.)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by DRAM.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.L3_MISS_LOCAL",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2184000477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the L3 cache.)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were not supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.L3_HIT.SNOOP_NOT_NEEDED",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x1003C0477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where no snoop was needed to satisfy the request.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.L3_HIT.SNOOP_MISS",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x2003C0477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent but the snoop missed.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.L3_HIT.SNOOP_HIT_NO_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x4003C0477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, but no data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.L3_HIT.SNOOP_HIT_WITH_FWD",
      EventDef::Encoding{
          .code = 0XB7, .umask = 0x01, .cmask = 0, .msr_values = {0x8003C0477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and non-modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.L3_HIT.SNOOP_HITM",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x10003C0477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache where a snoop was sent, the snoop hit, and modified data was forwarded.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1F803C0001}},
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT)",
      R"(This event is deprecated. Refer to new event OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1F803C0002}},
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache.)",
      R"(Counts demand reads for ownership (RFO) and software prefetches for exclusive ownership (PREFETCHW) that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_CODE_RD.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1F803C0004}},
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache.)",
      R"(Counts demand instruction fetches and L1 instruction cache prefetches that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.COREWB_M.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x3001F803C0000}},
      R"(Counts modified writebacks from L1 cache and L2 cache that were supplied by the L3 cache.)",
      R"(Counts modified writebacks from L1 cache and L2 cache that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_DATA_RD.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1F803C0010}},
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache.)",
      R"(Counts L2 cache hardware prefetch data reads (written to the L2 cache only) that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_RFO.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1F803C0020}},
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache.)",
      R"(Counts L2 cache hardware prefetch RFOs (written to the L2 cache only) that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.HWPF_L2_CODE_RD.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1F803C0040}},
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache.)",
      R"(Counts L2 cache hardware prefetch code reads (written to the L2 cache only) that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.STREAMING_WR.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1F803C0800}},
      R"(Counts streaming stores that were supplied by the L3 cache.)",
      R"(Counts streaming stores that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_RD.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x101F803C0000}},
      R"(Counts uncached memory reads that were supplied by the L3 cache.)",
      R"(Counts uncached memory reads that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.UC_WR.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x201F803C0000}},
      R"(Counts uncached memory writes that were supplied by the L3 cache.)",
      R"(Counts uncached memory writes that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.PARTIAL_STREAMING_WR.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x401F803C0000}},
      R"(Counts streaming stores which modify only part of a 64 byte cacheline that were supplied by the L3 cache.)",
      R"(Counts streaming stores which modify only part of a 64 byte cacheline that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.FULL_STREAMING_WR.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x801F803C0000}},
      R"(Counts streaming stores which modify a full 64 byte cacheline that were supplied by the L3 cache.)",
      R"(Counts streaming stores which modify a full 64 byte cacheline that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.L1WB_M.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1001F803C0000}},
      R"(Counts modified writebacks from L1 cache that miss the L2 cache that were supplied by the L3 cache.)",
      R"(Counts modified writebacks from L1 cache that miss the L2 cache that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.L2WB_M.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x2001F803C0000}},
      R"(Counts modified writeBacks from L2 cache that miss the L3 cache that were supplied by the L3 cache.)",
      R"(Counts modified writeBacks from L2 cache that miss the L3 cache that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.ALL_CODE_RD.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1F803C0044}},
      R"(Counts all code reads that were supplied by the L3 cache.)",
      R"(Counts all code reads that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_AND_L1PF_RD.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1F803C0001}},
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache.)",
      R"(Counts cacheable demand data reads, L1 data cache hardware prefetches and software prefetches (except PREFETCHW) that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.READS_TO_CORE.L3_HIT",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x1F803C0477}},
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache.)",
      R"(Counts all data read, code read and RFO requests including demands and prefetches to the core caches (L1 or L2) that were supplied by the L3 cache.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace snowridgex_core
} // namespace facebook::hbt::perf_event::generated
