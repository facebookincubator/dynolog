// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace snowridgex_core_v1_07 {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from snowridgex_core_v1.07.json (32 events).

    Supported SKUs:
        - Arch: x86, Model: SNR id: 134
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of instructions retired. (Fixed event))",
      R"(Counts the number of instructions that retire. For instructions that consist of multiple uops, this event counts the retirement of the last uop of the instruction. The counter continues counting during hardware interrupts, traps, and inside interrupt handlers.  This event uses fixed counter 0.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.CORE",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted core clock cycles. (Fixed event))",
      R"(Counts the number of core cycles while the core is not in a halt state.  The core enters the halt state when it is running the HLT instruction. The core frequency may change from time to time. For this reason this event may have a changing ratio with regards to time.  This event uses fixed counter 1.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_TSC",
      EventDef::Encoding{
          .code = 0x00, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted reference clock cycles at TSC frequency. (Fixed event))",
      R"(Counts the number of reference cycles that the core is not in a halt state. The core enters the halt state when it is running the HLT instruction.  The core frequency may change from time.  This event is not affected by core frequency changes and at a fixed frequency.  This event uses fixed counter 2.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Page walk completed due to a demand load to a 4K page.)",
      R"(Counts page walks completed due to demand data loads (including SW prefetches) whose address translations missed in all TLB levels and were mapped to 4K pages.  The page walks can end with or without a page fault.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x08, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Page walk completed due to a demand load to a 2M or 4M page.)",
      R"(Counts page walks completed due to demand data loads (including SW prefetches) whose address translations missed in all TLB levels and were mapped to 2M or 4M pages.  The page walks can end with or without a page fault.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.MISS",
      EventDef::Encoding{
          .code = 0x2e, .umask = 0x41, .cmask = 0, .msr_values = {0x00}},
      R"(Counts memory requests originating from the core that miss in the last level cache. If the platform has an L3 cache, last level cache is the L3, otherwise it is the L2.)",
      R"(Counts cacheable memory requests that miss in the the Last Level Cache.  Requests include Demand Loads, Reads for Ownership(RFO), Instruction fetches and L1 HW prefetches. If the platform has an L3 cache, last level cache is the L3, otherwise it is the L2.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.REFERENCE",
      EventDef::Encoding{
          .code = 0x2e, .umask = 0x4f, .cmask = 0, .msr_values = {0x00}},
      R"(Counts memory requests originating from the core that reference a cache line in the last level cache. If the platform has an L3 cache, last level cache is the L3, otherwise it is the L2.)",
      R"(Counts cacheable memory requests that access the Last Level Cache.  Requests include Demand Loads, Reads for Ownership(RFO), Instruction fetches and L1 HW prefetches. If the platform has an L3 cache, last level cache is the L3, otherwise it is the L2.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.CORE_P",
      EventDef::Encoding{
          .code = 0x3c, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted core clock cycles.)",
      R"(Counts the number of core cycles while the core is not in a halt state.  The core enters the halt state when it is running the HLT instruction. The core frequency may change from time to time. For this reason this event may have a changing ratio with regards to time.  This event uses a programmable general purpose performance counter.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF",
      EventDef::Encoding{
          .code = 0x3c, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of unhalted reference clock cycles at TSC frequency.)",
      R"(Counts reference cycles (at TSC frequency) when core is not halted.  This event uses a programmable general purpose perfmon counter.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Page walk completed due to a demand data store to a 4K page.)",
      R"(Counts page walks completed due to demand data stores whose address translations missed in the TLB and were mapped to 4K pages.  The page walks can end with or without a page fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_STORE_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Page walk completed due to a demand data store to a 2M or 4M page.)",
      R"(Counts page walks completed due to demand data stores whose address translations missed in the TLB and were mapped to 2M or 4M pages.  The page walks can end with or without a page fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.MISSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts requests to the Instruction Cache (ICache) for one or more bytes in a cache line and they do not hit in the ICache (miss).)",
      R"(Counts requests to the Instruction Cache (ICache)  for one or more bytes in an ICache Line and that cache line is not in the ICache (miss).  The event strives to count on a cache line basis, so that multiple accesses which miss in a single cache line count as one ICACHE.MISS.  Specifically, the event counts when straight line code crosses the cache line boundary, or when a branch target is to a new line, and that cache line is not in the ICache.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ICACHE.ACCESSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x03, .cmask = 0, .msr_values = {0x00}},
      R"(Counts requests to the Instruction Cache (ICache) for one or more bytes cache Line.)",
      R"(Counts requests to the Instruction Cache (ICache) for one or more bytes in an ICache Line.  The event strives to count on a cache line basis, so that multiple fetches to a single cache line count as one ICACHE.ACCESS.  Specifically, the event counts when accesses from straight line code crosses the cache line boundary, or when a branch target is to a new line.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB.FILLS",
      EventDef::Encoding{
          .code = 0x81, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of times there was an ITLB miss and a new translation was filled into the ITLB.)",
      R"(Counts the number of times the machine was unable to find a translation in the Instruction Translation Lookaside Buffer (ITLB) and new translation was filled into the ITLB.  The event is speculative in nature, but will not count translations (page walks) that are begun and not finished, or translations that are finished but not filled into the ITLB.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_4K",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Page walk completed due to an instruction fetch in a 4K page.)",
      R"(Counts page walks completed due to instruction fetches whose address translations missed in the TLB and were mapped to 4K pages.  The page walks can end with or without a page fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED_2M_4M",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Page walk completed due to an instruction fetch in a 2M or 4M page.)",
      R"(Counts page walks completed due to instruction fetches whose address translations missed in the TLB and were mapped to 2M or 4M pages.  The page walks can end with or without a page fault.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY_P",
      EventDef::Encoding{
          .code = 0xc0, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of instructions retired.)",
      R"(Counts the number of instructions that retire execution. For instructions that consist of multiple uops, this event counts the retirement of the last uop of the instruction. The event continues counting during hardware interrupts, traps, and inside interrupt handlers.  This is an architectural performance event.  This event uses a Programmable general purpose perfmon counter. *This event is Precise Event capable:  The EventingRIP field in the PEBS record is precise to the address of the instruction which caused the event.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.ANY",
      EventDef::Encoding{
          .code = 0xc3, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts all machine clears due to, but not limited to memory ordering, memory disambiguation, SMC, page faults and FP assist.)",
      R"(Counts all machine clears due to, but not limited to memory ordering, memory disambiguation, SMC, page faults and FP assist.)",
      20003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xc4, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of branch instructions retired for all branch types.)",
      R"(Counts branch instructions retired for all branch types. This event is Precise Event capable. This is an architectural event.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xc5, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of mispredicted branch instructions retired.)",
      R"(Counts mispredicted branch instructions retired for all branch types. This event is Precise Event capable. This is an architectural event.)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CYCLES_DIV_BUSY.ANY",
      EventDef::Encoding{
          .code = 0xcd, .umask = 0x00, .cmask = 0, .msr_values = {0x00}},
      R"(Counts cycles the floating point divider or integer divider or both are busy.  Does not imply a stall waiting for either divider.)",
      R"(Counts cycles the floating point divider or integer divider or both are busy.  Does not imply a stall waiting for either divider.)",
      2000003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_LOADS",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x81, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired.)",
      R"(Counts the number of load uops retired. This event is Precise Event capable)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_UOPS_RETIRED.ALL_STORES",
      EventDef::Encoding{
          .code = 0xd0, .umask = 0x82, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of store uops retired.)",
      R"(Counts the number of store uops retired. This event is Precise Event capable)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x01, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that hit the level 1 data cache)",
      R"(Counts the number of load uops retired that hit the level 1 data cache)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x02, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that hit in the level 2 cache)",
      R"(Counts the number of load uops retired that hit in the level 2 cache)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L3_HIT",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x04, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that miss in the level 3 cache)",
      R"(Counts the number of load uops retired that miss in the level 3 cache)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L1_MISS",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x08, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that miss in the level 1 data cache)",
      R"(Counts the number of load uops retired that miss in the level 1 data cache)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_UOPS_RETIRED.L2_MISS",
      EventDef::Encoding{
          .code = 0xd1, .umask = 0x10, .cmask = 0, .msr_values = {0x00}},
      R"(Counts the number of load uops retired that miss in the level 2 cache)",
      R"(Counts the number of load uops retired that miss in the level 2 cache)",
      200003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.data_la = true, .pebs = 1},
      R"(0)"));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_DATA_RD.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x000000000000010001}},
      R"(Counts demand data reads that have any response type.)",
      R"(Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction.)",
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
          .msr_values = {0x000000003F04000001}},
      R"(Counts demand data reads that was not supplied by the L3 cache.)",
      R"(Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OCR.DEMAND_RFO.ANY_RESPONSE",
      EventDef::Encoding{
          .code = 0XB7,
          .umask = 0x01,
          .cmask = 0,
          .msr_values = {0x000000000000010002}},
      R"(Counts all demand reads for ownership (RFO) requests and software based prefetches for exclusive ownership (PREFETCHW) that have any response type.)",
      R"(Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction.)",
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
          .msr_values = {0x000000003F04000002}},
      R"(Counts all demand reads for ownership (RFO) requests and software based prefetches for exclusive ownership (PREFETCHW) that was not supplied by the L3 cache.)",
      R"(Offcore response can be programmed only with a specific pair of event select and counter MSR, and with specific event codes and predefine mask bit value in a dedicated MSR to specify attributes of the offcore transaction.)",
      100003,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace snowridgex_core_v1_07
} // namespace facebook::hbt::perf_event::generated
