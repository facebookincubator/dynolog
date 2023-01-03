// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace broadwell_uncore {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from broadwell_uncore.json (23 events).

    Supported SKUs:
        - Arch: x86, Model: BDW id: 61
        - Arch: x86, Model: BDW id: 71
  */
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
      "UNC_CBO_CACHE_LOOKUP.READ_M",
      EventDef::Encoding{.code = 0x34, .umask = 0x11, .cmask = 0},
      R"(L3 Lookup read request that access cache and found line in M-state)",
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
      R"(L3 Lookup write request that access cache and found line in M-state)",
      R"(L3 Lookup write request that access cache and found line in M-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.ANY_M",
      EventDef::Encoding{.code = 0x34, .umask = 0x81, .cmask = 0},
      R"(L3 Lookup any request that access cache and found line in M-state)",
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
      R"(L3 Lookup read request that access cache and found line in I-state)",
      R"(L3 Lookup read request that access cache and found line in I-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.ANY_I",
      EventDef::Encoding{.code = 0x34, .umask = 0x88, .cmask = 0},
      R"(L3 Lookup any request that access cache and found line in I-state)",
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
      R"(L3 Lookup read request that access cache and found line in any MESI-state)",
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
      R"(L3 Lookup write request that access cache and found line in MESI-state)",
      R"(L3 Lookup write request that access cache and found line in MESI-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.ANY_MESI",
      EventDef::Encoding{.code = 0x34, .umask = 0x8f, .cmask = 0},
      R"(L3 Lookup any request that access cache and found line in MESI-state)",
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
      R"(L3 Lookup any request that access cache and found line in E or S-state)",
      R"(L3 Lookup any request that access cache and found line in E or S-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cbox,
      "UNC_CBO_CACHE_LOOKUP.READ_ES",
      EventDef::Encoding{.code = 0x34, .umask = 0x16, .cmask = 0},
      R"(L3 Lookup read request that access cache and found line in E or S-state)",
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
      R"(L3 Lookup write request that access cache and found line in E or S-state)",
      R"(L3 Lookup write request that access cache and found line in E or S-state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ncu,
      "UNC_CLOCK.SOCKET",
      EventDef::Encoding{.code = 0x0, .umask = 0x01, .cmask = 0},
      R"(This 48-bit fixed counter counts the UCLK cycles)",
      R"(This 48-bit fixed counter counts the UCLK cycles.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0x80, .umask = 0x01, .cmask = 0},
      R"(Each cycle count number of all Core outgoing valid entries. Such entry is defined as valid from it's allocation till first of IDI0 or DRS0 messages is sent out. Accounts for Coherent and non-coherent traffic.)",
      R"(Each cycle count number of all Core outgoing valid entries. Such entry is defined as valid from it's allocation till first of IDI0 or DRS0 messages is sent out. Accounts for Coherent and non-coherent traffic.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_OCCUPANCY.DRD_DIRECT",
      EventDef::Encoding{.code = 0x80, .umask = 0x02, .cmask = 0},
      R"(Each cycle count number of 'valid' coherent Data Read entries that are in DirectData mode. Such entry is defined as valid when it is allocated till data sent to Core (first chunk, IDI0). Applicable for IA Cores' requests in normal case.)",
      R"(Each cycle count number of valid coherent Data Read entries that are in DirectData mode. Such entry is defined as valid when it is allocated till data sent to Core (first chunk, IDI0). Applicable for IA Cores' requests in normal case.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_REQUESTS.ALL",
      EventDef::Encoding{.code = 0x81, .umask = 0x01, .cmask = 0},
      R"(Total number of Core outgoing entries allocated. Accounts for Coherent and non-coherent traffic.)",
      R"(Total number of Core outgoing entries allocated. Accounts for Coherent and non-coherent traffic.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_REQUESTS.DRD_DIRECT",
      EventDef::Encoding{.code = 0x81, .umask = 0x02, .cmask = 0},
      R"(Number of Core coherent Data Read entries allocated in DirectData mode)",
      R"(Number of Core coherent Data Read entries allocated in DirectData mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_REQUESTS.WRITES",
      EventDef::Encoding{.code = 0x81, .umask = 0x20, .cmask = 0},
      R"(Number of Writes allocated - any write transactions: full/partials writes and evictions.)",
      R"(Number of Writes allocated - any write transactions: full/partials writes and evictions.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_COH_TRK_REQUESTS.ALL",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .cmask = 0},
      R"(Number of entries allocated. Account for Any type: e.g. Snoop, Core aperture, etc.)",
      R"(Number of entries allocated. Account for Any type: e.g. Snoop, Core aperture, etc.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_OCCUPANCY.CYCLES_WITH_ANY_REQUEST",
      EventDef::Encoding{.code = 0x80, .umask = 0x01, .cmask = 1},
      R"(Cycles with at least one request outstanding is waiting for data return from memory controller. Account for coherent and non-coherent requests initiated by IA Cores, Processor Graphics Unit, or LLC.;)",
      R"(Cycles with at least one request outstanding is waiting for data return from memory controller. Account for coherent and non-coherent requests initiated by IA Cores, Processor Graphics Unit, or LLC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace broadwell_uncore
} // namespace facebook::hbt::perf_event::generated
