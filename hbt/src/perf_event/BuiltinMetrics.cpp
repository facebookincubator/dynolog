// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <sys/types.h>
#include <unistd.h>

#include "hbt/src/common/System.h"
#include "hbt/src/intel_pt/IptEventBuilder.h"
#include "hbt/src/perf_event/AmdEvents.h"
#include "hbt/src/perf_event/ArmEvents.h"
#include "hbt/src/perf_event/BuiltinMetrics.h"
#include "hbt/src/perf_event/CpuArch.h"
#include "hbt/src/perf_event/Metrics.h"
#include "hbt/src/perf_event/PmuDevices.h"
#include "hbt/src/perf_event/PmuEvent.h"
#ifdef USE_JSON_GENERATED_PERF_EVENTS
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"
#endif // USE_JSON_GENERATED_PERF_EVENTS

#include <map>
#include <memory>

namespace facebook::hbt::perf_event {

typedef std::pair<std::string, HwCacheEventInfo> HwCacheEventInfoMap;

const static std::vector<HwCacheEventInfoMap> kHWCacheTypes = {
    {"l1_dcache",
     HwCacheEventInfo(PERF_COUNT_HW_CACHE_L1D, "Level 1 data cache ")},
    {"l1_icache",
     HwCacheEventInfo(PERF_COUNT_HW_CACHE_L1I, "Level 1 instruction cache ")},
    {"llc", HwCacheEventInfo(PERF_COUNT_HW_CACHE_LL, "Last level cache ")},
    {"dtlb",
     HwCacheEventInfo(
         PERF_COUNT_HW_CACHE_DTLB,
         "Data translation-lookaside-buffer ")},
    {"itlb",
     HwCacheEventInfo(
         PERF_COUNT_HW_CACHE_ITLB,
         "Instruction translation-look-aside-buffer ")},
    {"branch",
     HwCacheEventInfo(PERF_COUNT_HW_CACHE_BPU, "Branch prediction unit ")},
    {"node",
     HwCacheEventInfo(PERF_COUNT_HW_CACHE_NODE, "Local memory accesses ")}};

const static std::vector<HwCacheEventInfoMap> kHWCacheOpTypes = {
    {"load", HwCacheEventInfo(PERF_COUNT_HW_CACHE_OP_READ, "load operation ")},
    {"store",
     HwCacheEventInfo(PERF_COUNT_HW_CACHE_OP_WRITE, "write operation ")},
    {"prefetch",
     HwCacheEventInfo(PERF_COUNT_HW_CACHE_OP_PREFETCH, "prefetch operation ")}};

const static std::vector<HwCacheEventInfoMap> kHWCacheResultTypes = {
    {"hits", HwCacheEventInfo(PERF_COUNT_HW_CACHE_RESULT_ACCESS, "hits")},
    {"misses", HwCacheEventInfo(PERF_COUNT_HW_CACHE_RESULT_MISS, "misses")}};

static inline std::string constructName(
    const HwCacheEventInfoMap& type,
    const HwCacheEventInfoMap& operation,
    const HwCacheEventInfoMap& result) {
  std::stringstream ss;
  ss << type.first << "_" << operation.first << "_" << result.first;
  return ss.str();
}

static inline uint64_t constructEncoding(
    const HwCacheEventInfoMap& type,
    const HwCacheEventInfoMap& operation,
    const HwCacheEventInfoMap& result) {
  // Constructing encoding based on perf_event_open(2)
  // (perf_hw_cache_id) | (perf_hw_cache_op_id << 8) |
  //                  (perf_hw_cache_op_result_id << 16)
  // See http://man7.org/linux/man-pages/man2/perf_event_open.2.html
  return (type.second.id) | (operation.second.id << 8) |
      (result.second.id << 16);
}

static inline std::string constructDescription(
    const HwCacheEventInfoMap& type,
    const HwCacheEventInfoMap& operation,
    const HwCacheEventInfoMap& result) {
  std::stringstream ss;
  ss << type.second.description << operation.second.description
     << result.second.description;
  return ss.str();
}

// A simple reducer that adds all metrics up
const ReducerFunc& getAddReducer() {
  static ReducerFunc add_reducer =
      [](const std::vector<uint64_t>& metrics) -> std::optional<double> {
    if (metrics.size() == 0) {
      return std::nullopt;
    }
    return std::accumulate(metrics.begin(), metrics.end(), 0);
  };
  return add_reducer;
}

// Reducer that computes rate of two metrics
// Note: this assumes event[0] is the numerator and event[1] is the denominator
//  please be aware and setup event definitions accordingly.
const ReducerFunc& getRateReducer() {
  static ReducerFunc rate_reducer =
      [](const std::vector<uint64_t>& metrics) -> std::optional<double> {
    if (metrics.size() != 2) {
      HBT_DLOG_INFO() << "Ratio Metrics are too few/many " << metrics.size();
      return std::nullopt;
    }
    const auto& num = metrics[0];
    const auto& denom = metrics[1];
    if (denom == 0) {
      HBT_DLOG_INFO() << "Ratio denom = 0";
      return std::nullopt;
    }
    return static_cast<double>(num) / static_cast<double>(denom);
  };
  return rate_reducer;
}

/// Kernel abstracted HW events.
/// The ones exposed in kernel headers
/// (linux/include/uapi/perf_event.h) as PERF_TYPE_HARDWARE.
/// PERF_TYPE_HARDWARE mapped to PmuType::generic_hardware
void populateGenericEventsHardware(
    std::shared_ptr<PmuDeviceManager> pmu_manager) {
  pmu_manager->addEvent(
      std::make_shared<EventDef>(
          PmuType::generic_hardware,
          "cpu_cycles",
          EventDef::Encoding{.code = PERF_COUNT_HW_CPU_CYCLES},
          "CPU cycles.",
          "Actual CPU cycles. Depends on frequency scaling, turbo mode and other effects."),
      std::vector<EventId>({"cpu-cycles", "cycles"}));

  pmu_manager->addEvent(
      std::make_shared<EventDef>(
          PmuType::generic_hardware,
          "instructions",
          EventDef::Encoding{.code = PERF_COUNT_HW_INSTRUCTIONS},
          "Instructions retired.",
          "Instructions executed. Does not count speculative execution."),
      std::vector<EventId>({"retired_instructions", "retired-instructions"}));

  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::generic_hardware,
      "cache_references",
      EventDef::Encoding{.code = PERF_COUNT_HW_CACHE_REFERENCES},
      "Cache references.",
      "Cache references."));

  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::generic_hardware,
      "cache_misses",
      EventDef::Encoding{.code = PERF_COUNT_HW_CACHE_MISSES},
      "Cache misses.",
      "Cache misses."));

  pmu_manager->addEvent(
      std::make_shared<EventDef>(
          PmuType::generic_hardware,
          "branch_instructions",
          EventDef::Encoding{.code = PERF_COUNT_HW_BRANCH_INSTRUCTIONS},
          "Branch instructions executed.",
          "Branch instructions executed."),
      std::vector<EventId>({"branch-instructions", "branches"}));

  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::generic_hardware,
      "branch_misses",
      EventDef::Encoding{.code = PERF_COUNT_HW_BRANCH_MISSES},
      "Retired branch instructions incorrectly predicted.",
      "Retired branch instructions incorrectly predicted."));

  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::generic_hardware,
      "bus_cycles",
      EventDef::Encoding{.code = PERF_COUNT_HW_BUS_CYCLES},
      "Bus cycles.",
      "Bus cycles."));

  pmu_manager->addEvent(
      std::make_shared<EventDef>(
          PmuType::generic_hardware,
          "ref_cycles",
          EventDef::Encoding{.code = PERF_COUNT_HW_REF_CPU_CYCLES},
          "Reference CPU cycles.",
          "CPU cycles unchanged by frequency scaling, turbo mode and other effects. "
          "In Intel this means TSC cycles."),
      std::vector<EventId>({"ref_cpu_cycles"}));

  // XXX: blacklist or do something like that to avoid showing this events
  // when unsupported.
  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::generic_hardware,
      "stalled_cycles_frontend",
      EventDef::Encoding{.code = PERF_COUNT_HW_STALLED_CYCLES_FRONTEND},
      "Stalled cycles frontend",
      "Number of Cycles that Front End was stalled (could not perform forward "
      "progress). Usually due to I-Cache misses. Unsupported in most CPUs Haswell and newer"));

  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::generic_hardware,
      "stalled_cycles_backend",
      EventDef::Encoding{.code = PERF_COUNT_HW_STALLED_CYCLES_BACKEND},
      "Stalled cycles backend",
      "Number of Cycles that Back End was stalled (could not perform forward "
      "progress). Usually due to memory bandwidth contention. Unsupported in most CPUs Haswell and newer."));
}

/// Kernel abstracted SW events.
/// The ones exposed in kernel headers
/// (linux/include/uapi/perf_event.h) as PERF_TYPE_SOFTWARE.
/// PERF_TYPE_SOFTWARE mapped to PmuType::software
void populateGenericEventsSoftware(
    std::shared_ptr<PmuDeviceManager> pmu_manager) {
  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::software,
      "cpu_clock",
      EventDef::Encoding{.code = PERF_COUNT_SW_CPU_CLOCK},
      "High-resolution per CPU timer",
      "High-resolution per CPU timer"));

  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::software,
      "task_clock",
      EventDef::Encoding{.code = PERF_COUNT_SW_TASK_CLOCK},
      "Software task clock",
      "Software task clock"));

  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::software,
      "page_faults",
      EventDef::Encoding{.code = PERF_COUNT_SW_PAGE_FAULTS},
      "Software page faults",
      "Software page faults. Both minor and major faults."));

  pmu_manager->addEvent(
      std::make_shared<EventDef>(
          PmuType::software,
          "context_switches",
          EventDef::Encoding{.code = PERF_COUNT_SW_CONTEXT_SWITCHES},
          "Software context switches.",
          "Software context switches."),
      std::vector<EventId>({"context-switches", "cs"}));

  pmu_manager->addEvent(
      std::make_shared<EventDef>(
          PmuType::software,
          "cpu_migrations",
          EventDef::Encoding{.code = PERF_COUNT_SW_CPU_MIGRATIONS},
          "Count of process/thread CPU migrations.",
          "Count of process/thread CPU migrations. "
          "These are usually triggered by imbalances in per-CPU process scheduler queues."),
      std::vector<EventId>({"cpu-migrations", "migrations"}));

  pmu_manager->addEvent(
      std::make_shared<EventDef>(
          PmuType::software,
          "page_faults_minor",
          EventDef::Encoding{.code = PERF_COUNT_SW_PAGE_FAULTS_MIN},
          "Minor software page faults",
          "Minor software page faults (those that did not require disk I/O)"),
      std::vector<EventId>(
          {"minor-faults", "minor_faults", "page-faults-minor"}));

  pmu_manager->addEvent(
      std::make_shared<EventDef>(
          PmuType::software,
          "page_faults_major",
          EventDef::Encoding{.code = PERF_COUNT_SW_PAGE_FAULTS_MAJ},
          "Major software page faults.",
          "Major software page faults (those that did require disk I/O)."),
      std::vector<EventId>(
          {"major-faults", "major_faults", "page-faults-major"}));

  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::software,
      "alignment_faults",
      EventDef::Encoding{.code = PERF_COUNT_SW_ALIGNMENT_FAULTS},
      "Alignment faults handled by kernel",
      "Alignment faults handled by kernel. "
      "These are instances where accesses are not aligned with pages. "
      "It usually has has a significant slowdown (100x or worse)."));

  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::software,
      "emulation_faults",
      EventDef::Encoding{.code = PERF_COUNT_SW_EMULATION_FAULTS},
      "Instruction emulation faults handled by kernel",
      "Instruction emulation faults handled by kernel. "
      "These are instances where software emulates an unsupported instruction. "
      "It usually has has a significant slowdown (100x or worse)."));

  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::software,
      "dummy",
      EventDef::Encoding{.code = PERF_COUNT_SW_DUMMY},
      "Dummy Event.",
      "Dummy software event that does nothing. Useful for side-band events."));

  pmu_manager->addEvent(std::make_shared<EventDef>(
      PmuType::software,
      "bpf_output",
      EventDef::Encoding{.code = PERF_COUNT_SW_BPF_OUTPUT},
      "eBPF Output.",
      "Event to receive output from eBPF probes."));
}

/// Kernel abstracted Tracepoint events.
/// (linux/include/uapi/perf_event.h) as PERF_TYPE_TRACEPOINT.
/// PERF_TYPE_TRACEPOINT mapped to PmuType::tracepoint
void populateGenericEventsTracepoint(
    std::shared_ptr<PmuDeviceManager> pmu_manager) {
  auto categories = pmu_manager->listTracepointCategories();
  for (const auto& category : categories) {
    auto category_events = pmu_manager->listTracepointEvents(category);
    for (const auto& [ev_name, ev_id] : category_events) {
      pmu_manager->addEvent(std::make_shared<EventDef>(
          PmuType::tracepoint,
          category + ":" + ev_name,
          EventDef::Encoding{.code = static_cast<uint64_t>(ev_id)},
          "Tracepoint",
          "[Tracepoint Event]"));
    }
  }
}

/// Kernel abstracted HW Cache events.
/// The ones exposed in kernel headers
/// (linux/include/uapi/perf_event.h) as PERF_TYPE_HW_CACHE.
/// PERF_TYPE_HW_CACHE mapped to PmuType::generic_hw_cache
void populateGenericEventsHardwareCache(
    std::shared_ptr<PmuDeviceManager> pmu_manager) {
  for (const auto& cache_type : kHWCacheTypes) {
    for (const auto& cache_op : kHWCacheOpTypes) {
      for (const auto& cache_result : kHWCacheResultTypes) {
        pmu_manager->addEvent(std::make_shared<EventDef>(
            PmuType::generic_hw_cache,
            constructName(cache_type, cache_op, cache_result),
            EventDef::Encoding{
                .code = constructEncoding(cache_type, cache_op, cache_result)},
            constructDescription(cache_type, cache_op, cache_result),
            constructDescription(cache_type, cache_op, cache_result)));
        static_assert(
            std::is_same_v<decltype(EventDef::Encoding::code), uint64_t>);
      }
    }
  }
}

void populateDefaultIptEvents(std::shared_ptr<PmuDeviceManager> pmu_manager) {
  // add a default event that should be supported by all Broadwell and later
  // Intel CPU
  auto iptEventBuilder =
      intel_pt::IptEventBuilder::createIptEventBuilder(*pmu_manager);
  if (iptEventBuilder) {
    try {
      iptEventBuilder->setPt(true).setBranch(true).setCyc(true, 0);
      pmu_manager->addEvent(iptEventBuilder->createHbtEventDef(
          "ipt-default",
          "Default Intel PT tracing event.",
          "Default Intel PT tracing event with branch and cycle count packets enabled. "
          "Cycle count threshold set to 0 (generate cyc for all eligible packet)"));
    } catch (const std::exception& e) {
      HBT_LOG_WARNING() << e.what();
    }
  }
}

void populatePredefinedEventsOffcore(
    std::shared_ptr<PmuDeviceManager> pmu_manager,
    const CpuInfo& cpu_info) {
  auto offcoreEventDef = pmu_manager->findEventDef("OFFCORE_RESPONSE");
  if (!offcoreEventDef) {
    // CLX doesn't have a general OFFCORE_RESPONSE event defined.
    // So we use OCR.ALL_PF_RFO.L3_MISS.ANY_SNOOP event instead, which has the
    // same code and umask but different msr.
    // This doesn't make any difference as we only use code and umask from the
    // generated event.
    offcoreEventDef =
        pmu_manager->findEventDef("OCR.ALL_PF_RFO.L3_MISS.ANY_SNOOP");
  }
  if (cpu_info.cpu_family == CpuFamily::INTEL && !offcoreEventDef) {
    HBT_LOG_ERROR()
        << "cannot find code and umask for offcore response event on architecture "
        << cpu_info.cpu_arch;
    return;
  }
  // define equivalent event to replace DynoPerfCounter::DRAM_ACCESS_READS
  // TODO support AMD
  if (cpu_info.cpu_family != CpuFamily::INTEL) {
    return;
  }
  switch (cpu_info.cpu_arch) {
    case CpuArch::BDW:
    case CpuArch::BDW_DE:
    case CpuArch::BDX:
      pmu_manager->addEvent(std::make_shared<EventDef>(
          offcoreEventDef->pmu_type,
          "DynoPerfCounter::DRAM_ACCESS_READS",
          EventDef::Encoding{
              .code = offcoreEventDef->encoding.code,
              .umask = offcoreEventDef->encoding.umask,
              .msr_values = {0x3fbfc001b3}},
          "DynoPerfCounter::DRAM_ACCESS_READS on BDW/BDW_DE/BDX host",
          "This event is copy from DynoPerfCounter DRAM_ACCESS_READS event. This event is meant to be used by BDW/BDW_DE CPU only"));
      break;
    case CpuArch::SKL:
    case CpuArch::SKX:
    case CpuArch::CLX:
      pmu_manager->addEvent(std::make_shared<EventDef>(
          offcoreEventDef->pmu_type,
          "DynoPerfCounter::DRAM_ACCESS_READS",
          EventDef::Encoding{
              .code = offcoreEventDef->encoding.code,
              .umask = offcoreEventDef->encoding.umask,
              .msr_values = {0x3fbfc005b3}},
          "DynoPerfCounter::DRAM_ACCESS_READS on SKL/SKX host",
          "This event is copy from DynoPerfCounter DRAM_ACCESS_READS event. This event is meant to be used by SKL/SKX CPU only"));
      break;
    default:
      break;
  }
}

/// Populate all events.
std::shared_ptr<PmuDeviceManager> makePmuDeviceManager() {
  // Load CPU Info
  auto cpu_info = CpuInfo::load();

  auto pmu_manager = std::make_shared<PmuDeviceManager>(cpu_info);
  pmu_manager->loadSysFsPmus();

  // Add manually made Intel PT event
  if (pmu_manager->getPmuGroupSize(PmuType::intel_pt) >= 1) {
    populateDefaultIptEvents(pmu_manager);
  }

  // Add generic PMUs that are not advertised dynamically.
  if (pmu_manager->getPmuGroupSize(PmuType::cpu) ||
      pmu_manager->getPmuGroupSize(PmuType::armv8_pmuv3)) {
    // Some systems will not have CPU PMU (like VMs).
    // Those ones neither support hw and hw_cache generic events.
    // NOTE: Currently we need to manually add 'generic' AMD events (see
    // AmdEvents.cpp) as Intel definitions for generic perf events are pulled
    // in during build.
    pmu_manager->addPmu(std::make_shared<PmuDevice>(
        PmuTypeToStr(PmuType::generic_hardware),
        PmuType::generic_hardware,
        std::nullopt,
        PERF_TYPE_HARDWARE,
        "PMU of Generic Hardware Events",
        false));
    populateGenericEventsHardware(pmu_manager);

    pmu_manager->addPmu(std::make_shared<PmuDevice>(
        PmuTypeToStr(PmuType::generic_hw_cache),
        PmuType::generic_hw_cache,
        std::nullopt,
        PERF_TYPE_HW_CACHE,
        "PMU of Generic Hardware Cache Events",
        false));
    populateGenericEventsHardwareCache(pmu_manager);
  }

  if (pmu_manager->getPmuGroupSize(PmuType::software)) {
    populateGenericEventsSoftware(pmu_manager);
  } else {
    HBT_LOG_WARNING() << "PMU for software events no found.";
  }

  if (pmu_manager->getPmuGroupSize(PmuType::tracepoint)) {
    populateGenericEventsTracepoint(pmu_manager);
  }

  if (cpu_info.cpu_family == CpuFamily::AMDZEN3 ||
      cpu_info.cpu_family == CpuFamily::AMDZEN5) {
    addAmdEvents(cpu_info, *pmu_manager);
  } else if (cpu_info.cpu_family == CpuFamily::INTEL) {
    //
    // Add Intel generated events
    //
#ifdef USE_JSON_GENERATED_PERF_EVENTS
    try {
      generated::addEvents(
          cpu_info.cpu_model_num, cpu_info.cpu_step_num, *pmu_manager);
    } catch (const std::invalid_argument& e) {
      HBT_LOG_ERROR() << "Could not load auto-generated events due to: \""
                      << e.what() << "\"";
    }
#endif // USE_JSON_GENERATED_PERF_EVENTS
  } else if (cpu_info.cpu_family == CpuFamily::ARM) {
    addArmEvents(cpu_info, *pmu_manager);
  } else {
    HBT_LOG_ERROR() << "Unknown CPU family\n";
  }

  // Add predefined offcore events
  if (pmu_manager->getPmuGroupSize(PmuType::cpu) >= 1) {
    populatePredefinedEventsOffcore(pmu_manager, cpu_info);
  }

  // All these will return -EINVAL if fail to add alias.
  pmu_manager->addAliases(
      "BR_MISP_RETIRED.ALL_BRANCHES",
      std::vector<EventId>({"MISPREDICTED_BRANCH_RETIRED"}));

  pmu_manager->addAliases(
      "CPU_CLK_UNHALTED.THREAD_P_ANY",
      std::vector<EventId>({"CPU_CLK_THREAD_UNHALTED.THREAD_P"}));

  pmu_manager->addAliases(
      "dtlb_load_misses", std::vector<EventId>({"dTLB-load-misses"}));

  pmu_manager->addAliases(
      "llc_load_misses", std::vector<EventId>({"LLC-load-misses"}));

  // Alias for Intel
  if (cpu_info.cpu_family == CpuFamily::INTEL) {
    pmu_manager->addAliases(
        "BR_INST_RETIRED.NEAR_TAKEN",
        std::vector<EventId>({"branch-instructions-ret-tkn"}));
    pmu_manager->addAliases(
        "L2_RQSTS.MISS", std::vector<EventId>({"l2_cache_misses"}));
  }

  // Alias for AMD
  if (cpu_info.cpu_family == CpuFamily::AMDZEN3 ||
      cpu_info.cpu_family == CpuFamily::AMDZEN5) {
    pmu_manager->addAliases(
        "ex_ret_brn_tkn",
        std::vector<EventId>({"branch-instructions-ret-tkn"}));
  }

  return pmu_manager;
}

/// Add Builtin-Metrics, other metrics can be added dynamically.
std::shared_ptr<Metrics> makeAvailableMetrics() {
  auto metrics = std::make_shared<Metrics>();

  // instructions replaces DynoPerfCounterType::INSTRUCTIONS
  metrics->add(std::make_shared<MetricDesc>(
      "instructions",
      "Number of CPU instructions retired since the counter is enabled.",
      "Number of CPU instructions retired since the counter is enabled.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "instructions",
               PmuType::generic_hardware,
               "retired_instructions",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  // cycles replaces DynoPerfCounterType::CPU_CYCLES
  metrics->add(std::make_shared<MetricDesc>(
      "cycles",
      "Number of CPU clock cycles since the counter is enabled.",
      "Number of CPU clock cycles since the counter is enabled.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "cycles",
               PmuType::generic_hardware,
               "cpu_cycles",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "instructions_cycles",
      "An events group containing instructions and cycles.",
      "An events group containing instructions and cycles. "
      "Instructions and cycles are often enabled all the time and measured together. "
      "Putting them in the same group for convenience.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "instructions",
                   PmuType::generic_hardware,
                   "retired_instructions",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "cycles",
                   PmuType::generic_hardware,
                   "cpu_cycles",
                   EventExtraAttr{},
                   {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{},
      getRateReducer()));

  metrics->add(std::make_shared<MetricDesc>(
      "instructions_per_cycle",
      "Average number of instructions executed each clock cycle.",
      "Average number of instructions executed each clock cycle.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "instructions",
                   PmuType::generic_hardware,
                   "retired_instructions",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "cycles",
                   PmuType::generic_hardware,
                   "cpu_cycles",
                   EventExtraAttr{},
                   {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{},
      getRateReducer()));

  // l2_cache_misses replaces DynoPerfCounterType::L2CACHE_MISS
  auto cpu_info = CpuInfo::load();
  if (cpu_info.cpu_family == CpuFamily::INTEL) {
    metrics->add(std::make_shared<MetricDesc>(
        "l2_cache_misses",
        "Core-originated cacheable demand requests missed L2",
        "Counts core-originated cacheable requests that miss the L2 cache. "
        "Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches from L1 and L2. ",
        std::map<TOptCpuArch, EventRefs>{
            {std::nullopt,
             EventRefs{EventRef{
                 "l2_cache_misses",
                 PmuType::cpu,
                 "l2_cache_misses",
                 EventExtraAttr{},
                 {}}}}},
        100'000'000,
        System::Permissions{},
        std::vector<std::string>{}));
  } else if (
      cpu_info.cpu_family == CpuFamily::AMDZEN3 ||
      cpu_info.cpu_family == CpuFamily::AMDZEN5) {
    metrics->add(std::make_shared<MetricDesc>(
        "l2_cache_misses",
        "Core-originated cacheable demand requests missed L2",
        "Counts core-originated cacheable requests that miss the L2 cache. "
        "Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches from L2. ",
        std::map<TOptCpuArch, EventRefs>{
            {std::nullopt,
             EventRefs{
                 EventRef{
                     "l2_cache_misses_no_prefetcher",
                     PmuType::cpu,
                     "l2_cache_misses_no_prefetcher",
                     EventExtraAttr{},
                     {}},
                 EventRef{
                     "l1_l2_pf_hit_in_l3",
                     PmuType::cpu,
                     "l1_l2_pf_hit_in_l3",
                     EventExtraAttr{},
                     {}},
                 EventRef{
                     "l1_l2_pf_miss_in_l3",
                     PmuType::cpu,
                     "l1_l2_pf_miss_in_l3",
                     EventExtraAttr{},
                     {}}}}},
        100'000'000,
        System::Permissions{},
        std::vector<std::string>{},
        getAddReducer()));
  }
  // l3_cache_misses replaces DynoPerfCounterType::L3CACHE_MISS
  metrics->add(std::make_shared<MetricDesc>(
      "l3_cache_misses",
      "Core-originated cacheable demand requests missed L3.",
      "Counts core-originated cacheable requests that miss the L3 cache (Longest Latency cache). "
      "Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches from L1 and L2. "
      "It does not include all misses to the L3.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "l3_cache_misses",
               PmuType::cpu,
               "LONGEST_LAT_CACHE.MISS",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{},
      getRateReducer()));
  metrics->add(std::make_shared<MetricDesc>(
      "l3_cache_misses_per_instruction",
      "Core-originated cacheable demand requests missed L3 normalized by number of instructions.",
      "Counts core-originated cacheable requests that miss the L3 cache (Longest Latency cache). "
      "Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches from L1 and L2. "
      "It does not include all misses to the L3."
      "Also count number of instructions in the same period to calculate l3 misses per instruction.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "l3_cache_misses",
                   PmuType::cpu,
                   "LONGEST_LAT_CACHE.MISS",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instructions",
                   PmuType::generic_hardware,
                   "retired_instructions",
                   EventExtraAttr{},
                   {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{},
      getRateReducer()));

  // dram_access_reads replaces DynoPerfCounter::DRAM_ACCESS_READS
  metrics->add(std::make_shared<MetricDesc>(
      "dram_access_reads",
      "Memory bandwidth used for read events.",
      "Memory bandwidth used for read events. The value is inferred from Intel offcore counters.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::BDW,
           EventRefs{EventRef{
               "dram_access_reads",
               PmuType::cpu,
               "DynoPerfCounter::DRAM_ACCESS_READS",
               EventExtraAttr{},
               {}}}},
          {CpuArch::BDW_DE,
           EventRefs{EventRef{
               "dram_access_reads",
               PmuType::cpu,
               "DynoPerfCounter::DRAM_ACCESS_READS",
               EventExtraAttr{},
               {}}}},
          {CpuArch::BDX,
           EventRefs{EventRef{
               "dram_access_reads",
               PmuType::cpu,
               "DynoPerfCounter::DRAM_ACCESS_READS",
               EventExtraAttr{},
               {}}}},
          {CpuArch::SKL,
           EventRefs{EventRef{
               "dram_access_reads",
               PmuType::cpu,
               "DynoPerfCounter::DRAM_ACCESS_READS",
               EventExtraAttr{},
               {}}}},
          {CpuArch::SKX,
           EventRefs{EventRef{
               "dram_access_reads",
               PmuType::cpu,
               "DynoPerfCounter::DRAM_ACCESS_READS",
               EventExtraAttr{},
               {}}}},
          {CpuArch::CLX,
           EventRefs{EventRef{
               "dram_access_reads",
               PmuType::cpu,
               "DynoPerfCounter::DRAM_ACCESS_READS",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  // fp_instrs_single_precision replaces DynoPerfCounterType::FLOPS_SP
  metrics->add(std::make_shared<MetricDesc>(
      "fp_instrs_single_precision",
      "Single Precision AVX Vector floating point operation count",
      "Counts number of floating points instructions of single precision type"
      " executed by AVX vector instruction set."
      "Each instruction can be converted to operations by multipying the count"
      " with 1, 4, 8, 16 respectively.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "instr_sp_scalar",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.SCALAR_SINGLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_sp_128b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.128B_PACKED_SINGLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_sp_256b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.256B_PACKED_SINGLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_sp_512b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.512B_PACKED_SINGLE",
                   EventExtraAttr{},
                   {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "fp_instrs_double_precision",
      "Double Precision AVX Vector floating point operation count",
      "Counts number of floating points instructions of double precision type"
      " executed by AVX vector instruction set."
      "Each instruction can be converted to operations by multipying the count"
      " with 1, 2, 4, 8 respectively.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "instr_dp_scalar",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.SCALAR_DOUBLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_dp_128b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.128B_PACKED_DOUBLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_dp_256b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.256B_PACKED_DOUBLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_dp_512b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.512B_PACKED_DOUBLE",
                   EventExtraAttr{},
                   {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "fp_ops_all",
      "Total floating points operations",
      "Counts number of floating points operations of single precision type, double precision type, and bfloat types "
      "executed by the processor. "
      "For AMD, each event counts the # retired floating point operations. "
      "For Intel, each event counts the # retired instructions "
      "Multiply # of instructions by # of operations packed inside an instruction to calculate # operations.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::MILAN,
           EventRefs{
               EventRef{
                   "flops_scalar",
                   PmuType::cpu,
                   "zen3/4::fp_ret_x87_fp_ops.all",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "flops_vector",
                   PmuType::cpu,
                   "zen3::fp_ret_sse_avx_ops.all",
                   EventExtraAttr{},
                   {}}}},
          {CpuArch::BERGAMO,
           EventRefs{
               EventRef{
                   "flops_scalar",
                   PmuType::cpu,
                   "zen3/4::fp_ret_x87_fp_ops.all",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "flops_vector",
                   PmuType::cpu,
                   "zen4::fp_ret_sse_avx_ops.all",
                   EventExtraAttr{},
                   {}}}},
          {CpuArch::GENOA,
           EventRefs{
               EventRef{
                   "flops_scalar",
                   PmuType::cpu,
                   "zen3/4::fp_ret_x87_fp_ops.all",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "flops_vector",
                   PmuType::cpu,
                   "zen4::fp_ret_sse_avx_ops.all",
                   EventExtraAttr{},
                   {}}}},
          {CpuArch::TURIN,
           EventRefs{
               EventRef{
                   "flops_scalar",
                   PmuType::cpu,
                   "zen3/4::fp_ret_x87_fp_ops.all",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "flops_vector",
                   PmuType::cpu,
                   "zen4::fp_ret_sse_avx_ops.all",
                   EventExtraAttr{},
                   {}}}},
          // Intel by default
          {std::nullopt,
           EventRefs{
               EventRef{
                   "instr_dp_scalar",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.SCALAR_DOUBLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_dp_128b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.128B_PACKED_DOUBLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_dp_256b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.256B_PACKED_DOUBLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_dp_512b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.512B_PACKED_DOUBLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_sp_scalar",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.SCALAR_SINGLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_sp_128b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.128B_PACKED_SINGLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_sp_256b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.256B_PACKED_SINGLE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instr_sp_512b_packed",
                   PmuType::cpu,
                   "FP_ARITH_INST_RETIRED.512B_PACKED_SINGLE",
                   EventExtraAttr{},
                   {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "cpu_clock",
      "High-resolution sys and user CPU clock",
      "High-resolution sys and user CPU clock",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "sys_cpu_clock",
                   PmuType::software,
                   "cpu_clock",
                   EventExtraAttr::makeCountAll(),
                   {}},
               EventRef{
                   "user_cpu_clock",
                   PmuType::software,
                   "cpu_clock",
                   EventExtraAttr::makeUserOnly(),
                   {}}}}},
      50 * (2.7 * 1'000'000), // About 1000 / 50 = 20 per sec in a 2.7 Ghz CPU.
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "generic_sw",
      "All generic software events every context switch",
      "All generic software events. They are never multiplexed.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "context_switches",
                   PmuType::software,
                   "context_switches",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "cpu_migrations",
                   PmuType::software,
                   "cpu_migrations",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "page_faults",
                   PmuType::software,
                   "page_faults",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "alignment_faults",
                   PmuType::software,
                   "alignment_faults",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "emulation_faults",
                   PmuType::software,
                   "emulation_faults",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "page_faults_minor",
                   PmuType::software,
                   "page_faults_minor",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "page_faults_major",
                   PmuType::software,
                   "page_faults_major",
                   EventExtraAttr{},
                   {}}}}},
      10'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "page_faults",
      "Software Page faults",
      "Major and minor page faults",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "page_faults",
                   PmuType::software,
                   "page_faults",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "page_faults_minor",
                   PmuType::software,
                   "page_faults_minor",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "page_faults_major",
                   PmuType::software,
                   "page_faults_major",
                   EventExtraAttr{},
                   {}},
           }}},
      10'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "system_calls",
      "System calls Tracepoint",
      "System calls Tracepoint Event",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "sys_enter_clone",
                   PmuType::tracepoint,
                   "syscalls:sys_enter_clone",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "sys_enter_clone",
                   PmuType::tracepoint,
                   "syscalls:sys_enter_mmap",
                   EventExtraAttr{},
                   {}},
           }}},
      10'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "dqos",
      "System-derived estimation of Dyno QoS",
      "IPC and Scheduler stats. Requires root. Make sure /proc/sys/kernel/sched_schedstats is set.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "cpu_clock",
                   PmuType::software,
                   "cpu_clock",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instructions",
                   PmuType::generic_hardware,
                   "retired_instructions",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "cycles",
                   PmuType::generic_hardware,
                   "cpu_cycles",
                   EventExtraAttr{},
                   {}},

               EventRef{
                   "context_switches",
                   PmuType::software,
                   "context_switches",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "page_faults_minor",
                   PmuType::software,
                   "page_faults_minor",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "page_faults_major",
                   PmuType::software,
                   "page_faults_major",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "alignment_faults",
                   PmuType::software,
                   "alignment_faults",
                   EventExtraAttr{},
                   {}},

               EventRef{
                   "blocked_ns",
                   PmuType::tracepoint,
                   "sched:sched_stat_blocked",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "iowait_ns",
                   PmuType::tracepoint,
                   "sched:sched_stat_iowait",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "runtime_ns",
                   PmuType::tracepoint,
                   "sched:sched_stat_runtime",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "sleep_ns",
                   PmuType::tracepoint,
                   "sched:sched_stat_sleep",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "wait_ns",
                   PmuType::tracepoint,
                   "sched:sched_stat_wait",
                   EventExtraAttr{},
                   {}}}}},
      100'000'000, // Approx. 10 times per second
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "ipc",
      "IPC including user, kernel, and hypervisor.",
      "Intructions-per-Cycle (IPC) including user, kernel, and hypervisor. ",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "cycles",
                   PmuType::generic_hardware,
                   "cpu_cycles",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instructions",
                   PmuType::generic_hardware,
                   "retired_instructions",
                   EventExtraAttr{},
                   {}}}}},
      50 * (2.7 * 1'000'000), // About 1000 / 50 = 20 per sec in a 2.7 Ghz CPU.
      System::Permissions{},
      std::vector<std::string>{"ipc"}));

  metrics->add(std::make_shared<MetricDesc>(
      "cs_ipc",
      "Context switch-based IPC including user, kernel, and hypervisor.",
      "Context switch-based Intructions-per-Cycle (IPC) including user, kernel, and hypervisor. ",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "context_switches",
                   PmuType::software,
                   "context_switches",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "cycles",
                   PmuType::generic_hardware,
                   "cpu_cycles",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "instructions",
                   PmuType::generic_hardware,
                   "retired_instructions",
                   EventExtraAttr{},
                   {}}}}},
      1, // Every 1 context switches.
      System::Permissions{},
      std::vector<std::string>{"ipc"}));

  metrics->add(std::make_shared<MetricDesc>(
      "cycles_breakdown",
      "Cycles in user, kernel and idle.",
      "Time (ref-cycles) and cycles spent in user (ring 3) or kernel (ring 0)",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{
               EventRef{
                   "ref_cycles",
                   PmuType::generic_hardware,
                   "ref_cpu_cycles",
                   EventExtraAttr::makeUserOnly(),
                   {}},
               EventRef{
                   "ucycles",
                   PmuType::generic_hardware,
                   "cpu_cycles",
                   EventExtraAttr::makeUserOnly(),
                   {}},
               EventRef{
                   "kcycles",
                   PmuType::generic_hardware,
                   "cpu_cycles",
                   EventExtraAttr::makeKernelOnly(),
                   {}},
           }}},
      50 * (2.7 * 1'000'000), // About 1000 / 50 = 20 per sec in a 2.7 Ghz CPU.
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "topdown_l4_mem",
      "External memory (DRAM) bandwidth and latency",
      "External memory (DRAM) bandwidth and latency.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::BDX,
           EventRefs{
               EventRef{
                   "unhalted",
                   PmuType::cpu,
                   "CPU_CLK_UNHALTED.THREAD_P_ANY",
                   EventExtraAttr::makeCountAll(),
                   {}},
               // BW requires require special countermasks which is currently
               // not supported. OFFCORE_REQUESTS_OUTSTANDING.ALL_DATA_RD:c4
               EventRef{
                   "outstanding_bw",
                   PmuType::cpu,
                   "OFFCORE_REQUESTS_OUTSTANDING.ALL_DATA_RD",
                   EventExtraAttr::makeCountAll(),
                   {}},
               EventRef{
                   "outstanding_lat",
                   PmuType::cpu,
                   "OFFCORE_REQUESTS_OUTSTANDING.CYCLES_WITH_DATA_RD",
                   EventExtraAttr::makeCountAll(),
                   {}},
               EventRef{
                   "cycles",
                   PmuType::generic_hardware,
                   "cpu_cycles",
                   EventExtraAttr{},
                   {}},
           }}},
      50 * (2.7 * 1'000'000), // About 1000 / 50 = 20 per sec in a 2.7 Ghz CPU.
      System::Permissions{},
      std::vector<std::string>{"topdown_l4_mem"}));

  metrics->add(std::make_shared<MetricDesc>(
      "topdown_l3_icache",
      "Fraction of cycles the CPU was stalled due to instruction cache misses",
      "Fraction of cycles the CPU was stalled due to instruction cache misses.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::BDX,
           EventRefs{
               EventRef{
                   "ifdata",
                   PmuType::cpu,
                   "ICACHE.IFDATA_STALL",
                   EventExtraAttr::makeCountAll(),
                   {}},
               EventRef{
                   "cycles",
                   PmuType::generic_hardware,
                   "cpu_cycles",
                   EventExtraAttr{},
                   {}},
           }}},
      50 * (2.7 * 1'000'000), // About 1000 / 50 = 20 per sec in a 2.7 Ghz CPU.
      System::Permissions{},
      std::vector<std::string>{"topdown_l3_icache"}));

  metrics->add(std::make_shared<MetricDesc>(
      "topdown_l3_L1_bound",
      "Fraction of cycles the CPU was stalled due to L1 data cache misses",
      "Fraction of cycles the CPU was stalled due to L1 data cache misses.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::BDX,
           EventRefs{
               EventRef{
                   "mem_stalls",
                   PmuType::cpu,
                   "CYCLE_ACTIVITY.STALLS_MEM_ANY",
                   EventExtraAttr::makeCountAll(),
                   {}},
               EventRef{
                   "l1_miss",
                   PmuType::cpu,
                   "CYCLE_ACTIVITY.STALLS_L1D_MISS",
                   EventExtraAttr::makeCountAll(),
                   {}},
               EventRef{
                   "cycles",
                   PmuType::generic_hardware,
                   "cpu_cycles",
                   EventExtraAttr{},
                   {}},
           }}},
      50 * (2.7 * 1'000'000), // About 1000 / 50 = 20 per sec in a 2.7 Ghz CPU.
      System::Permissions{},
      std::vector<std::string>{"topdown_l3_L1_bound"}));

  metrics->add(std::make_shared<MetricDesc>(
      "topdown_l3_L2_bound",
      "Estimates how often the CPU was stalled due to L2 cache accesses by loads.",
      "Estimates how often the CPU was stalled due to L2 cache accesses by loads.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::BDX,
           EventRefs{
               EventRef{
                   "cycles",
                   PmuType::generic_hardware,
                   "cpu_cycles",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "l1_miss",
                   PmuType::cpu,
                   "CYCLE_ACTIVITY.STALLS_L1D_MISS",
                   EventExtraAttr::makeCountAll(),
                   {}},
               EventRef{
                   "l2_miss",
                   PmuType::cpu,
                   "CYCLE_ACTIVITY.STALLS_L2_MISS",
                   EventExtraAttr::makeCountAll(),
                   {}}}}},
      50 * (2.7 * 1'000'000), // About 1000 / 50 = 20 per sec in a 2.7 Ghz CPU.
      System::Permissions{},
      std::vector<std::string>{"topdown_l3_L2_bound"}));

  ///
  /// Modified from original Intel's TopDown
  /// First three events go to fixed counters for all events to run
  /// without multiplexing.
  ///
  /// Add CPU_CLK_UNHALTED.REF_TSC without user space filter to
  /// estimate time spent outside of userspace.
  ///
  metrics->add(std::make_shared<MetricDesc>(
      "topdown_l1",
      "Improved version of Intel's Top-Down top level.",
      "Improved version of Intel's Top-Down top level.\n"
      "Identifies where and why CPU compute power is wasted."
      "Also have tsc_unhalted tracking userspace time. "
      "The ratio of tsc_unhalted/duration indicates the time spent in "
      "user space.\n"
      "Provides how many CPU is halted, how much is spent in kernel and user space "
      " and a breakdown of how many pipeline slots are wasted due "
      "to each hardware bottleneck.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::SKX,
           EventRefs{
               // Note: There are two events for CPU_CLK_UNHALTED:
               // CPU_CLK_UNHALTED.THREAD_ANY and CPU_CLK_UNHALTED.THREAD_P_ANY
               // but only the latter is scheduled in the fixed counter
               // (despite Intel's JSON description stating the opposite).
               EventRef{
                   "unhalted",
                   PmuType::cpu,
                   "CPU_CLK_UNHALTED.THREAD_P_ANY",
                   EventExtraAttr::makeCountAll(),
                   {}},

               EventRef{
                   "retired",
                   PmuType::cpu,
                   "UOPS_RETIRED.RETIRE_SLOTS",
                   EventExtraAttr::makeCountAll(),
                   {}},

               // Rescale to nanoseconds since boot (kernel time).
               // Useful to know what fraction of time was spent in kernel.
               // Use TSC counter because cycles counter is used time.
               EventRef{
                   "unhalted_time",
                   PmuType::cpu,
                   "CPU_CLK_UNHALTED.REF_TSC",
                   EventExtraAttr::makeUserOnly(),
                   {.flags = EventValueTransforms::TscToKernelTime}},

               EventRef{
                   "issued",
                   PmuType::cpu,
                   "UOPS_ISSUED.ANY",
                   EventExtraAttr::makeCountAll(),
                   {}},

               EventRef{
                   "recovery",
                   PmuType::cpu,
                   "INT_MISC.RECOVERY_CYCLES_ANY",
                   EventExtraAttr::makeCountAll(),
                   {}},

               EventRef{
                   "not_delivered",
                   PmuType::cpu,
                   "IDQ_UOPS_NOT_DELIVERED.CORE",
                   EventExtraAttr::makeCountAll(),
                   {}}}},
          {CpuArch::BDW,
           EventRefs{
               // Note: There are two events for CPU_CLK_UNHALTED:
               // CPU_CLK_UNHALTED.THREAD_ANY and CPU_CLK_UNHALTED.THREAD_P_ANY
               // but only the latter is scheduled in the fixed counter
               // (despite Intel's JSON description stating the opposite).
               EventRef{
                   "unhalted",
                   PmuType::cpu,
                   "CPU_CLK_UNHALTED.THREAD_P_ANY",
                   EventExtraAttr::makeCountAll(),
                   {}},

               EventRef{
                   "retired",
                   PmuType::cpu,
                   "UOPS_RETIRED.RETIRE_SLOTS",
                   EventExtraAttr::makeCountAll(),
                   {}},

               // Rescale to nanoseconds since boot (kernel time).
               // Useful to know what fraction of time was spent in kernel.
               // Use TSC counter because cycles counter is used time.
               EventRef{
                   "unhalted_time",
                   PmuType::cpu,
                   "CPU_CLK_UNHALTED.REF_TSC",
                   EventExtraAttr::makeUserOnly(),
                   {.flags = EventValueTransforms::TscToKernelTime}},

               EventRef{
                   "issued",
                   PmuType::cpu,
                   "UOPS_ISSUED.ANY",
                   EventExtraAttr::makeCountAll(),
                   {}},

               EventRef{
                   "recovery",
                   PmuType::cpu,
                   "INT_MISC.RECOVERY_CYCLES_ANY",
                   EventExtraAttr::makeCountAll(),
                   {}},

               EventRef{
                   "not_delivered",
                   PmuType::cpu,
                   "IDQ_UOPS_NOT_DELIVERED.CORE",
                   EventExtraAttr::makeCountAll(),
                   {}}}}},
      50 * (2.7 * 1'000'000), // About 1000 / 50 = 20 per sec in a 2.7 Ghz CPU.
      System::Permissions{},
      std::vector<std::string>{"topdown"}));

  return metrics;
}

void addArmCoreMetrics(std::shared_ptr<Metrics>& metrics) {
  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_L1_ICACHE_REFILL",
      "L1 instruction cache refill",
      "Counts any instruction fetch which misses in the cache.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "l1i_cache_refill",
               PmuType::armv8_pmuv3,
               "l1i_cache_refill",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_L1_DCACHE_REFILL",
      "L1 data cache refill",
      "Counts any load or store operation or page table walk access which causes data to be read from outside the L1, including accesses which do not allocate into L1.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "l1d_cache_refill",
               PmuType::armv8_pmuv3,
               "l1d_cache_refill",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_L2_CACHE_REFILL",
      "L2 cache refill",
      "Counts any cacheable transaction from L1 which causes data to be read from outside the core. L2 refills caused by stashes into L2 should not be counted.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "l2d_cache_refill",
               PmuType::armv8_pmuv3,
               "l2d_cache_refill",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_L3_CACHE_REFILL",
      "L3 cache refill",
      "Counts for any cacheable read transaction returning data from the SCU for which the data source was outside the cluster. Transactions such as ReadUnique are counted here as 'read' transactions, even though they can be generated by store instructions.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "l3d_cache_refill",
               PmuType::armv8_pmuv3,
               "l3d_cache_refill",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_FP_HP_SPEC",
      "Floating-point operation speculatively executed, half precision",
      "Counts speculatively executed half precision floating point operations.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "FP_HP_SPEC",
               PmuType::armv8_pmuv3,
               "FP_HP_SPEC",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_FP_SP_SPEC",
      "Floating-point operation speculatively executed, single precision",
      "Counts speculatively executed single precision floating point operations.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "FP_SP_SPEC",
               PmuType::armv8_pmuv3,
               "FP_SP_SPEC",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_FP_DP_SPEC",
      "Floating-point operation speculatively executed, double precision",
      "Counts speculatively executed double precision floating point operations.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "FP_DP_SPEC",
               PmuType::armv8_pmuv3,
               "FP_DP_SPEC",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));
}

void addIntelCoreMetrics(std::shared_ptr<Metrics>& metrics) {
  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_ICACHE_MISSES",
      "L2 code requests",
      "Counts the total number of L2 code requests.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "icache_misses",
               PmuType::cpu,
               "L2_RQSTS.ALL_CODE_RD",
               EventExtraAttr{},
               {}}}},
          {CpuArch::SRF,
           EventRefs{EventRef{
               "icache_misses",
               PmuType::cpu,
               "ICACHE.MISSES",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  // Generic cache events defined in populateGenericEventsHardwareCache()
  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_ICACHE_MISSES_PERF",
      "Level 1 instruction cache load operation misses",
      "Level 1 instruction cache load operation misses",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "icache_misses_perf",
               PmuType::generic_hw_cache,
               "l1_icache_load_misses",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_DCACHE_MISSES",
      "Counts the number of cache lines replaced in L1 data cache.",
      "Counts L1D data line replacements including opportunistic replacements, and replacements that require stall-for-replace or block-for-replace.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "dcache_misses",
               PmuType::cpu,
               "L1D.REPLACEMENT",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_ITLB_MISSES",
      "Code miss in all TLB levels causes a page walk that completes. (All page sizes)",
      "Counts completed page walks (all page sizes) caused by a code fetch. This implies it missed in the ITLB (Instruction TLB) and further levels of TLB. The page walk can end with or without a fault.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "itlb_misses",
               PmuType::cpu,
               "ITLB_MISSES.WALK_COMPLETED",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_L2_MISSES",
      "L2 cache lines filling L2",
      "Counts the number of L2 cache lines filling the L2. Counting does not cover rejects.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "core_l2_misses",
               PmuType::cpu,
               "L2_LINES_IN.ALL",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_LLC_MISSES",
      "Core-originated cacheable requests that missed L3  (Except hardware prefetches to the L3)",
      "Counts core-originated cacheable requests that miss the L3 cache (Longest Latency cache). Requests include data and code reads, Reads-for-Ownership (RFOs), speculative accesses and hardware prefetches to the L1 and L2.  It does not include hardware prefetches to the L3, and may not count other types of requests to the L3.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "llc_misses",
               PmuType::cpu,
               "LONGEST_LAT_CACHE.MISS",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_BRANCH_MISSES",
      "All mispredicted branch instructions retired.",
      "Counts all the retired branch instructions that were mispredicted by the processor. A branch misprediction occurs when the processor incorrectly predicts the destination of the branch.  When the misprediction is discovered at execution, all the instructions executed in the wrong (speculative) path must be discarded, and the processor must start fetching from the correct path.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "branch_misses",
               PmuType::cpu,
               "BR_MISP_RETIRED.ALL_BRANCHES",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_BRANCH_INSTRUCTIONS",
      "All branch instructions retired.",
      "Counts all branch instructions retired.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "branch_instructions",
               PmuType::cpu,
               "BR_INST_RETIRED.ALL_BRANCHES",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_L2_PREFETCH_HITS",
      "SW prefetch requests that hit L2 cache.",
      "Counts Software prefetch requests that hit the L2 cache. Accounts for PREFETCHNTA and PREFETCHT0/1/2 instructions when FB is not full.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "prefetch_hits",
               PmuType::cpu,
               "L2_RQSTS.SWPF_HIT",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_L2_PREFETCH_MISSES",
      "SW prefetch requests that miss L2 cache.",
      "Counts Software prefetch requests that miss the L2 cache. Accounts for PREFETCHNTA and PREFETCHT0/1/2 instructions when FB is not full.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "prefetch_misses",
               PmuType::cpu,
               "L2_RQSTS.SWPF_MISS",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_DTLB_LOAD_MISSES",
      "Load miss in all TLB levels causes a page walk that completes. (All page sizes).",
      "Counts completed page walks  (all page sizes) caused by demand data loads. This implies it missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "dtlb_load_misses",
               PmuType::cpu,
               "DTLB_LOAD_MISSES.WALK_COMPLETED",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_DTLB_STORE_MISSES",
      "Store misses in all TLB levels causes a page walk that completes. (All page sizes).",
      "Counts completed page walks  (all page sizes) caused by demand data stores. This implies it missed in the DTLB and further levels of TLB. The page walk can end with or without a fault.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "dtlb_load_misses",
               PmuType::cpu,
               "DTLB_STORE_MISSES.WALK_COMPLETED",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_FLOPS_DP_SCALAR",
      "Counts number of SSE/AVX computational scalar double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
      "Number of SSE/AVX computational scalar double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "flops_dp_scalar",
               PmuType::cpu,
               "FP_ARITH_INST_RETIRED.SCALAR_DOUBLE",
               EventExtraAttr{},
               {}}}},
          {CpuArch::SRF,
           EventRefs{EventRef{
               "flops_dp_scalar",
               PmuType::cpu,
               "FP_FLOPS_RETIRED.FP64",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_FLOPS_SP_SCALAR",
      "Counts number of SSE/AVX computational scalar single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
      "Number of SSE/AVX computational scalar single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 1 computational operation. Applies to SSE* and AVX* scalar single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT RCP FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "flops_sp_scalar",
               PmuType::cpu,
               "FP_ARITH_INST_RETIRED.SCALAR_SINGLE",
               EventExtraAttr{},
               {}}}},
          {CpuArch::SRF,
           EventRefs{EventRef{
               "flops_sp_scalar",
               PmuType::cpu,
               "FP_FLOPS_RETIRED.FP32",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_FLOPS_DP_SSE",
      "Counts number of SSE/AVX computational 128-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
      "Number of SSE/AVX computational 128-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 2 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "flops_dp_sse",
               PmuType::cpu,
               "FP_ARITH_INST_RETIRED.128B_PACKED_DOUBLE",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_FLOPS_SP_SSE",
      "Number of SSE/AVX computational 128-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB MUL DIV MIN MAX RCP14 RSQRT14 SQRT DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
      "Number of SSE/AVX computational 128-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "flops_sp_sse",
               PmuType::cpu,
               "FP_ARITH_INST_RETIRED.128B_PACKED_SINGLE",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_FLOPS_DP_AVX",
      "Counts number of SSE/AVX computational 256-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
      "Number of SSE/AVX computational 256-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 4 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT FM(N)ADD/SUB.  FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "flops_dp_avx",
               PmuType::cpu,
               "FP_ARITH_INST_RETIRED.256B_PACKED_DOUBLE",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_FLOPS_SP_AVX",
      "Counts number of SSE/AVX computational 256-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
      "Number of SSE/AVX computational 256-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB HADD HSUB SUBADD MUL DIV MIN MAX SQRT RSQRT RCP DPP FM(N)ADD/SUB.  DPP and FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "flops_sp_avx",
               PmuType::cpu,
               "FP_ARITH_INST_RETIRED.256B_PACKED_SINGLE",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_FLOPS_DP_AVX2",
      "Counts number of SSE/AVX computational 512-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
      "Number of SSE/AVX computational 512-bit packed double precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 8 computation operations, one for each element.  Applies to SSE* and AVX* packed double precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "flops_dp_avx2",
               PmuType::cpu,
               "FP_ARITH_INST_RETIRED.512B_PACKED_DOUBLE",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_FLOPS_SP_AVX2",
      "Counts number of SSE/AVX computational 512-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 16 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element.",
      "Number of SSE/AVX computational 512-bit packed single precision floating-point instructions retired; some instructions will count twice as noted below.  Each count represents 16 computation operations, one for each element.  Applies to SSE* and AVX* packed single precision floating-point instructions: ADD SUB MUL DIV MIN MAX SQRT RSQRT14 RCP14 FM(N)ADD/SUB. FM(N)ADD/SUB instructions count twice as they perform 2 calculations per element. The DAZ and FTZ flags in the MXCSR register need to be set when using these events.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "flops_sp_avx2",
               PmuType::cpu,
               "FP_ARITH_INST_RETIRED.512B_PACKED_SINGLE",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_STALLS_NO_EXECUTE",
      "Total execution stalls.",
      "Total execution stalls.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "cpu_stalls_cycles",
               PmuType::cpu,
               "CYCLE_ACTIVITY.STALLS_TOTAL",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_UOPS_UNDELIVERED",
      "Uops not delivered by IDQ when backend of the machine is not stalled.",
      "Counts the number of uops not delivered to by the Instruction Decode Queue (IDQ) to the back-end of the pipeline when there was no back-end stalls. This event counts for one SMT thread in a given cycle.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "uops_undelivered",
               PmuType::cpu,
               "IDQ_UOPS_NOT_DELIVERED.CORE",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  // CPU_CLK_UNHALTED.THREAD_P_ANY no longer available on ICL+
  // CPU_CLK_UNHALTED.THREAD's encoding does not work for some reason, see
  // https://pxl.cl/6406M
  // Use CPU_CLK_UNHALTED.THREAD_P, which works and is the most similar event
  metrics->add(std::make_shared<MetricDesc>(
      "HW_CORE_UNHALTED_CYCLES",
      "Thread cycles when thread is not in halt state.",
      "This is an architectural event that counts the number of thread cycles while the thread is not in a halt state. The thread enters the halt state when it is running the HLT instruction. The core frequency may change from time to time due to power or thermal throttling. For this reason, this event may have a changing ratio with regards to wall clock time.",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "unhalted_cycles",
               PmuType::cpu,
               "CPU_CLK_UNHALTED.THREAD_P",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));
}

void addUncoreMetrics(std::shared_ptr<Metrics>& metrics) {
#ifdef __aarch64__
  addArmUncoreMetrics(metrics);
#endif
  // TODO: Add x86_64 path in future
}

void addArmUncoreMetrics(std::shared_ptr<Metrics>& metrics) {
  metrics->add(std::make_shared<MetricDesc>(
      "HW_SCF_CYCLES",
      "Cycles on SCF uncore",
      "Cycles on SCF uncore",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "scf_cycles",
               PmuType::nvidia_scf_pmu,
               "cycles",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_SCF_CPU_WRITE_BYTES",
      "Write memory bandwidth in MBps from SCF to local CPU memory.",
      "Write memory bandwidth in MBps from SCF to local CPU memory.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "scf_cpu_write_bytes",
               PmuType::nvidia_scf_pmu,
               "cmem_wr_total_bytes",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_SCF_CPU_READ_BEATS",
      "Read memory beats (32 byte chunks) from SCF to local CPU memory.",
      "Read memory beats (32 byte chunks) from SCF to local CPU memory.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "scf_cpu_read_chunks",
               PmuType::nvidia_scf_pmu,
               "cmem_rd_data",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_SCF_CPU_WB_ACCESS",
      "Write-back requests from SCF to local CPU memory.",
      "Write-back requests from SCF to local CPU memory.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "scf_cpu_mem_wb_access",
               PmuType::nvidia_scf_pmu,
               "cmem_wb_access",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_SCF_CPU_WR_ACCESS",
      "Write-unique and non-coherent write requests from SCF to local CPU memory.",
      "Write-unique and non-coherent write requests from SCF to local CPU memory.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "scf_cpu_mem_wr_access",
               PmuType::nvidia_scf_pmu,
               "cmem_wr_access",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_SCF_CPU_RD_ACCESS",
      "Read requests from SCF to local CPU memory.",
      "Read and non-coherent write requests from SCF to local CPU memory.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "scf_cpu_mem_rd_access",
               PmuType::nvidia_scf_pmu,
               "cmem_rd_access",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_SCF_CPU_RD_OUTSTANDING",
      "Outstanding read requests from SCF to local CPU memory.",
      "Outstanding read requests from SCF to local CPU memory.",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "scf_cpu_mem_rd_outstanding",
               PmuType::nvidia_scf_pmu,
               "cmem_rd_outstanding",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_C2C0_CYCLES",
      "Cycles on C2C0 uncore",
      "Cycles on C2C0 uncore",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "c2c0_cycles",
               PmuType::nvidia_nvlink_c2c0_pmu,
               "cycles",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_C2C0_WRITE_BYTES_LOC",
      "NVLink C2C0 write bandwidth local",
      "NVLink C2C0 write bandwidth local",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "c2c0_wr_bytes_loc",
               PmuType::nvidia_nvlink_c2c0_pmu,
               "wr_bytes_loc",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_C2C0_WRITE_BYTES_REM",
      "NVLink C2C0 write bandwidth remote",
      "NVLink C2C0 write bandwidth remote",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "c2c0_wr_bytes_rem",
               PmuType::nvidia_nvlink_c2c0_pmu,
               "wr_bytes_rem",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_C2C0_READ_BYTES_LOC",
      "NVLink C2C0 read bandwidth local",
      "NVLink C2C0 read bandwidth local",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "c2c0_rd_bytes_loc",
               PmuType::nvidia_nvlink_c2c0_pmu,
               "rd_bytes_loc",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_C2C0_READ_BYTES_REM",
      "NVLink C2C0 read bandwidth remote",
      "NVLink C2C0 read bandwidth remote",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "c2c0_rd_bytes_rem",
               PmuType::nvidia_nvlink_c2c0_pmu,
               "rd_bytes_rem",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_C2C1_CYCLES",
      "Cycles on C2C1 uncore",
      "Cycles on C2C1 uncore",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "c2c1_cycles",
               PmuType::nvidia_nvlink_c2c1_pmu,
               "cycles",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_C2C1_WRITE_BYTES_LOC",
      "NVLink C2C1 write bandwidth local",
      "NVLink C2C1 write bandwidth local",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "c2c1_wr_bytes_loc",
               PmuType::nvidia_nvlink_c2c1_pmu,
               "wr_bytes_loc",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_C2C1_WRITE_BYTES_REM",
      "NVLink C2C1 write bandwidth remote",
      "NVLink C2C1 write bandwidth remote",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "c2c1_wr_bytes_rem",
               PmuType::nvidia_nvlink_c2c1_pmu,
               "wr_bytes_rem",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_C2C1_READ_BYTES_LOC",
      "NVLink C2C1 read bandwidth local",
      "NVLink C2C1 read bandwidth local",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "c2c1_rd_bytes_loc",
               PmuType::nvidia_nvlink_c2c1_pmu,
               "rd_bytes_loc",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_C2C1_READ_BYTES_REM",
      "NVLink C2C1 read bandwidth remote",
      "NVLink C2C1 read bandwidth remote",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::NEOVERSE_V2,
           EventRefs{EventRef{
               "c2c1_rd_bytes_rem",
               PmuType::nvidia_nvlink_c2c1_pmu,
               "rd_bytes_rem",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));
}

// Uncore events for modern Intel architectures using PerfCounterManagerHbt
// includes ICX, SPR, and SRF
// For now, enclose each event in a single metric since
// hbt will enable all events within a metric simultaneously
// and there may not be enough PMUs.
void addIntelUncoreMetrics(std::shared_ptr<Metrics>& metrics) {
  metrics->add(std::make_shared<MetricDesc>(
      "HW_UNCORE_MEM_BW_READ",
      "DDR memory read bandwidth (MB/sec)",
      "DDR memory read bandwidth (MB/sec)",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::ICX,
           EventRefs{EventRef{
               "uncore_cas_count_read",
               PmuType::uncore_imc,
               "UNC_M_CAS_COUNT.RD",
               EventExtraAttr{},
               {}}}},
          {CpuArch::SPR,
           EventRefs{EventRef{
               "uncore_cas_count_read",
               PmuType::uncore_imc,
               "UNC_M_CAS_COUNT.RD",
               EventExtraAttr{},
               {}}}},
          {CpuArch::SRF,
           EventRefs{
               EventRef{
                   "uncore_cas_count_sch_0_read",
                   PmuType::uncore_imc,
                   "UNC_M_CAS_COUNT_SCH0.RD",
                   EventExtraAttr{},
                   {},
               },
               EventRef{
                   "uncore_cas_count_sch_1_read",
                   PmuType::uncore_imc,
                   "UNC_M_CAS_COUNT_SCH1.RD",
                   EventExtraAttr{},
                   {},
               }}},
      },
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_UNCORE_MEM_BW_WRITE",
      "DDR memory write bandwidth (MB/sec)",
      "DDR memory write bandwidth (MB/sec)",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::ICX,
           EventRefs{EventRef{
               "uncore_cas_count_write",
               PmuType::uncore_imc,
               "UNC_M_CAS_COUNT.WR",
               EventExtraAttr{},
               {}}}},
          {CpuArch::SPR,
           EventRefs{EventRef{
               "uncore_cas_count_write",
               PmuType::uncore_imc,
               "UNC_M_CAS_COUNT.WR",
               EventExtraAttr{},
               {}}}},
          {CpuArch::SRF,
           EventRefs{
               EventRef{
                   "uncore_cas_count_sch_0_write",
                   PmuType::uncore_imc,
                   "UNC_M_CAS_COUNT_SCH0.WR",
                   EventExtraAttr{},
                   {},
               },
               EventRef{
                   "uncore_cas_count_sch_1_write",
                   PmuType::uncore_imc,
                   "UNC_M_CAS_COUNT_SCH1.WR",
                   EventExtraAttr{},
                   {},
               }}},
      },
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_UNCORE_CHA_READ_MEM_BW_LOCAL",
      "Bandwidth (MB/sec) of read requests that miss the last level cache (LLC) and go to local memory.",
      "Counts read requests coming from a unit on this socket made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a write).",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "uncore_cha_reads_local",
               PmuType::uncore_cha,
               "UNC_CHA_REQUESTS.READS_LOCAL",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_UNCORE_CHA_WRITE_MEM_BW_LOCAL",
      "Bandwidth (MB/sec) of write requests that miss the last level cache (LLC) and go to local memory.",
      "Counts read requests coming from a remote socket made into the CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "uncore_cha_writes_local",
               PmuType::uncore_cha,
               "UNC_CHA_REQUESTS.WRITES_LOCAL",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_UNCORE_CHA_READ_MEM_BW_REMOTE",
      "Bandwidth (MB/sec) of read requests that miss the last level cache (LLC) and go to remote memory.",
      "Counts read requests coming from a remote socket made into the CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "uncore_cha_reads_remote",
               PmuType::uncore_cha,
               "UNC_CHA_REQUESTS.READS_REMOTE",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_UNCORE_CHA_WRITE_MEM_BW_REMOTE",
      "Bandwidth (MB/sec) of write requests that miss the last level cache (LLC) and go to remote memory.",
      "Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "uncore_cha_writes_remote",
               PmuType::uncore_cha,
               "UNC_CHA_REQUESTS.WRITES_REMOTE",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_UNCORE_CHA_CLOCKTICKS",
      "Number of CHA clock cycles while the event is enabled",
      "Clockticks of the uncore caching and home agent (CHA)",
      std::map<TOptCpuArch, EventRefs>{
          {std::nullopt,
           EventRefs{EventRef{
               "uncore_cha_clocktics",
               PmuType::uncore_cha,
               "UNC_CHA_CLOCKTICKS",
               EventExtraAttr{},
               {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  // Memory latency events for ICX and SPR
  metrics->add(std::make_shared<MetricDesc>(
      "HW_UNCORE_MEMORY_LATENCY_LOCAL",
      "Average LLC demand data read miss latency for LOCAL requests (in ns)",
      "Average latency of a last level cache (LLC) demand data read miss (read memory access) addressed to local memory in nano seconds",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::ICX,
           EventRefs{
               EventRef{
                   "uncore_cha_tor_occupancy.ia_miss_drd_local",
                   PmuType::uncore_cha,
                   "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "uncore_cha_tor_inserts.ia_miss_drd_local",
                   PmuType::uncore_cha,
                   "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "uncore_cha_clocktics",
                   PmuType::uncore_cha,
                   "UNC_CHA_CLOCKTICKS",
                   EventExtraAttr{},
                   {}}}},
          {CpuArch::SPR,
           EventRefs{
               EventRef{
                   "uncore_cha_tor_occupancy.ia_miss_drd_local",
                   PmuType::uncore_cha,
                   "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "uncore_cha_tor_inserts.ia_miss_drd_local",
                   PmuType::uncore_cha,
                   "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "uncore_cha_clocktics",
                   PmuType::uncore_cha,
                   "UNC_CHA_CLOCKTICKS",
                   EventExtraAttr{},
                   {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  metrics->add(std::make_shared<MetricDesc>(
      "HW_UNCORE_MEMORY_LATENCY_REMOTE",
      "Average LLC demand data read miss latency for REMOTE requests (in ns)",
      "Average latency of a last level cache (LLC) demand data read miss (read memory access) addressed to remote memory in nano seconds",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::ICX,
           EventRefs{
               EventRef{
                   "uncore_cha_tor_occupancy.ia_miss_drd_remote",
                   PmuType::uncore_cha,
                   "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "uncore_cha_tor_inserts.ia_miss_drd_remote",
                   PmuType::uncore_cha,
                   "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "uncore_cha_clocktics",
                   PmuType::uncore_cha,
                   "UNC_CHA_CLOCKTICKS",
                   EventExtraAttr{},
                   {}}}},
          {CpuArch::SPR,
           EventRefs{
               EventRef{
                   "uncore_cha_tor_occupancy.ia_miss_drd_remote",
                   PmuType::uncore_cha,
                   "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "uncore_cha_tor_inserts.ia_miss_drd_remote",
                   PmuType::uncore_cha,
                   "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "uncore_cha_clocktics",
                   PmuType::uncore_cha,
                   "UNC_CHA_CLOCKTICKS",
                   EventExtraAttr{},
                   {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));

  // SRF machines are currently single socket only
  metrics->add(std::make_shared<MetricDesc>(
      "HW_UNCORE_MEMORY_LATENCY",
      "Average LLC demand data read miss latency (in ns)",
      "Average latency of a last level cache (LLC) demand data read miss (read memory access) in nano seconds",
      std::map<TOptCpuArch, EventRefs>{
          {CpuArch::SRF,
           EventRefs{
               EventRef{
                   "uncore_cha_tor_occupancy.ia_miss_drd_opt",
                   PmuType::uncore_cha,
                   "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_OPT",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "uncore_cha_tor_inserts.ia_miss_drd_opt",
                   PmuType::uncore_cha,
                   "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT",
                   EventExtraAttr{},
                   {}},
               EventRef{
                   "uncore_cha_clocktics",
                   PmuType::uncore_cha,
                   "UNC_CHA_CLOCKTICKS",
                   EventExtraAttr{},
                   {}}}}},
      100'000'000,
      System::Permissions{},
      std::vector<std::string>{}));
}
} // namespace facebook::hbt::perf_event
