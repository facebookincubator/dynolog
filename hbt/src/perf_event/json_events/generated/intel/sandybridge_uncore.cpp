// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace sandybridge_uncore {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from sandybridge_uncore.json (34 events).

    Supported SKUs:
        - Arch: x86, Model: SNB id: 42
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0x80, .umask = 0x01, .cmask = 0},
      R"(Counts cycles weighted by the number of requests waiting for data returning from the memory controller. Accounts for coherent and non-coherent requests initiated by IA cores, processor graphic units, or LLC.)",
      R"(Counts cycles weighted by the number of requests waiting for data returning from the memory controller. Accounts for coherent and non-coherent requests initiated by IA cores, processor graphic units, or LLC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_REQUESTS.ALL",
      EventDef::Encoding{.code = 0x81, .umask = 0x01, .cmask = 0},
      R"(Counts the number of coherent and in-coherent requests initiated by IA cores, processor graphic units, or LLC.)",
      R"(Counts the number of coherent and in-coherent requests initiated by IA cores, processor graphic units, or LLC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_REQUESTS.WRITES",
      EventDef::Encoding{.code = 0x81, .umask = 0x20, .cmask = 0},
      R"(Counts the number of allocated write entries, include full, partial, and LLC evictions.)",
      R"(Counts the number of allocated write entries, include full, partial, and LLC evictions.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_REQUESTS.EVICTIONS",
      EventDef::Encoding{.code = 0x81, .umask = 0x80, .cmask = 0},
      R"(Counts the number of LLC evictions allocated.)",
      R"(Counts the number of LLC evictions allocated.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_COH_TRK_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .cmask = 0},
      R"(Cycles weighted by number of requests pending in Coherency Tracker.)",
      R"(Cycles weighted by number of requests pending in Coherency Tracker.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_COH_TRK_REQUESTS.ALL",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .cmask = 0},
      R"(Number of requests allocated in Coherency Tracker.)",
      R"(Number of requests allocated in Coherency Tracker.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_OCCUPANCY.CYCLES_WITH_ANY_REQUEST",
      EventDef::Encoding{.code = 0x80, .umask = 0x01, .cmask = 1},
      R"(Cycles with at least one request outstanding is waiting for data return from memory controller. Account for coherent and non-coherent requests initiated by IA Cores, Processor Graphics Unit, or LLC.)",
      R"(Cycles with at least one request outstanding is waiting for data return from memory controller. Account for coherent and non-coherent requests initiated by IA Cores, Processor Graphics Unit, or LLC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_OCCUPANCY.CYCLES_OVER_HALF_FULL",
      EventDef::Encoding{.code = 0x80, .umask = 0x01, .cmask = 10},
      R"(Cycles with at least half of the requests outstanding are waiting for data return from memory controller. Account for coherent and non-coherent requests initiated by IA Cores, Processor Graphics Unit, or LLC.)",
      R"(Cycles with at least half of the requests outstanding are waiting for data return from memory controller. Account for coherent and non-coherent requests initiated by IA Cores, Processor Graphics Unit, or LLC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_CLOCK.SOCKET",
      EventDef::Encoding{.code = 0x0, .umask = 0x01, .cmask = 0},
      R"(This 48-bit fixed counter counts the UCLK cycles.)",
      R"(This 48-bit fixed counter counts the UCLK cycles.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_XSNP_RESPONSE.MISS_EXTERNAL",
      EventDef::Encoding{.code = 0x22, .umask = 0x21, .cmask = 0},
      R"(An external snoop misses in some processor core.)",
      R"(An external snoop misses in some processor core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_XSNP_RESPONSE.MISS_XCORE",
      EventDef::Encoding{.code = 0x22, .umask = 0x41, .cmask = 0},
      R"(A cross-core snoop initiated by this Cbox due to processor core memory request which misses in some processor core.)",
      R"(A cross-core snoop initiated by this Cbox due to processor core memory request which misses in some processor core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_XSNP_RESPONSE.MISS_EVICTION",
      EventDef::Encoding{.code = 0x22, .umask = 0x81, .cmask = 0},
      R"(A cross-core snoop resulted from L3 Eviction which misses in some processor core.)",
      R"(A cross-core snoop resulted from L3 Eviction which misses in some processor core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_XSNP_RESPONSE.HIT_EXTERNAL",
      EventDef::Encoding{.code = 0x22, .umask = 0x24, .cmask = 0},
      R"(An external snoop hits a non-modified line in some processor core.)",
      R"(An external snoop hits a non-modified line in some processor core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_XSNP_RESPONSE.HIT_XCORE",
      EventDef::Encoding{.code = 0x22, .umask = 0x44, .cmask = 0},
      R"(A cross-core snoop initiated by this Cbox due to processor core memory request which hits a non-modified line in some processor core.)",
      R"(A cross-core snoop initiated by this Cbox due to processor core memory request which hits a non-modified line in some processor core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_XSNP_RESPONSE.HIT_EVICTION",
      EventDef::Encoding{.code = 0x22, .umask = 0x84, .cmask = 0},
      R"(A cross-core snoop resulted from L3 Eviction which hits a non-modified line in some processor core.)",
      R"(A cross-core snoop resulted from L3 Eviction which hits a non-modified line in some processor core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_XSNP_RESPONSE.HITM_EXTERNAL",
      EventDef::Encoding{.code = 0x22, .umask = 0x28, .cmask = 0},
      R"(An external snoop hits a modified line in some processor core.)",
      R"(An external snoop hits a modified line in some processor core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_XSNP_RESPONSE.HITM_XCORE",
      EventDef::Encoding{.code = 0x22, .umask = 0x48, .cmask = 0},
      R"(A cross-core snoop initiated by this Cbox due to processor core memory request which hits a modified line in some processor core.)",
      R"(A cross-core snoop initiated by this Cbox due to processor core memory request which hits a modified line in some processor core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_XSNP_RESPONSE.HITM_EVICTION",
      EventDef::Encoding{.code = 0x22, .umask = 0x88, .cmask = 0},
      R"(A cross-core snoop resulted from L3 Eviction which hits a modified line in some processor core.)",
      R"(A cross-core snoop resulted from L3 Eviction which hits a modified line in some processor core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.READ_M",
      EventDef::Encoding{.code = 0x34, .umask = 0x11, .cmask = 0},
      R"(L3 Lookup read request that access cache and found line in M-state.)",
      R"(L3 Lookup read request that access cache and found line in M-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.WRITE_M",
      EventDef::Encoding{.code = 0x34, .umask = 0x21, .cmask = 0},
      R"(L3 Lookup write request that access cache and found line in M-state.)",
      R"(L3 Lookup write request that access cache and found line in M-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.EXTSNP_M",
      EventDef::Encoding{.code = 0x34, .umask = 0x41, .cmask = 0},
      R"(L3 Lookup external snoop request that access cache and found line in M-state.)",
      R"(L3 Lookup external snoop request that access cache and found line in M-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.ANY_M",
      EventDef::Encoding{.code = 0x34, .umask = 0x81, .cmask = 0},
      R"(L3 Lookup any request that access cache and found line in M-state.)",
      R"(L3 Lookup any request that access cache and found line in M-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.READ_I",
      EventDef::Encoding{.code = 0x34, .umask = 0x18, .cmask = 0},
      R"(L3 Lookup read request that access cache and found line in I-state.)",
      R"(L3 Lookup read request that access cache and found line in I-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.WRITE_I",
      EventDef::Encoding{.code = 0x34, .umask = 0x28, .cmask = 0},
      R"(L3 Lookup write request that access cache and found line in I-state.)",
      R"(L3 Lookup write request that access cache and found line in I-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.EXTSNP_I",
      EventDef::Encoding{.code = 0x34, .umask = 0x48, .cmask = 0},
      R"(L3 Lookup external snoop request that access cache and found line in I-state.)",
      R"(L3 Lookup external snoop request that access cache and found line in I-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.ANY_I",
      EventDef::Encoding{.code = 0x34, .umask = 0x88, .cmask = 0},
      R"(L3 Lookup any request that access cache and found line in I-state.)",
      R"(L3 Lookup any request that access cache and found line in I-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.READ_MESI",
      EventDef::Encoding{.code = 0x34, .umask = 0x1f, .cmask = 0},
      R"(L3 Lookup read request that access cache and found line in any MESI-state.)",
      R"(L3 Lookup read request that access cache and found line in any MESI-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.WRITE_MESI",
      EventDef::Encoding{.code = 0x34, .umask = 0x2f, .cmask = 0},
      R"(L3 Lookup write request that access cache and found line in MESI-state.)",
      R"(L3 Lookup write request that access cache and found line in MESI-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.EXTSNP_MESI",
      EventDef::Encoding{.code = 0x34, .umask = 0x4f, .cmask = 0},
      R"(L3 Lookup external snoop request that access cache and found line in MESI-state.)",
      R"(L3 Lookup external snoop request that access cache and found line in MESI-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.ANY_MESI",
      EventDef::Encoding{.code = 0x34, .umask = 0x8f, .cmask = 0},
      R"(L3 Lookup any request that access cache and found line in MESI-state.)",
      R"(L3 Lookup any request that access cache and found line in MESI-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.ANY_ES",
      EventDef::Encoding{.code = 0x34, .umask = 0x86, .cmask = 0},
      R"(L3 Lookup any request that access cache and found line in E or S-state.)",
      R"(L3 Lookup any request that access cache and found line in E or S-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.EXTSNP_ES",
      EventDef::Encoding{.code = 0x34, .umask = 0x46, .cmask = 0},
      R"(L3 Lookup external snoop request that access cache and found line in E or S-state.)",
      R"(L3 Lookup external snoop request that access cache and found line in E or S-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.READ_ES",
      EventDef::Encoding{.code = 0x34, .umask = 0x16, .cmask = 0},
      R"(L3 Lookup read request that access cache and found line in E or S-state.)",
      R"(L3 Lookup read request that access cache and found line in E or S-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.WRITE_ES",
      EventDef::Encoding{.code = 0x34, .umask = 0x26, .cmask = 0},
      R"(L3 Lookup write request that access cache and found line in E or S-state.)",
      R"(L3 Lookup write request that access cache and found line in E or S-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace sandybridge_uncore
} // namespace facebook::hbt::perf_event::generated
