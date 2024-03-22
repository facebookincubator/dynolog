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
namespace icelake_uncore_experimental {

void addEvents(PmuDeviceManager& pmu_manager) {
/*
  Events from icelake_uncore_experimental.json (7 experimental events).

  Supported SKUs:
      - Arch: x86, Model: ICL id: 125
      - Arch: x86, Model: ICL id: 126
*/
#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_REQ_TRK_OCCUPANCY.DRD",
      EventDef::Encoding{.code = 0x80, .umask = 0x02, .cmask = 0},
      R"(Each cycle count number of 'valid' coherent Data Read entries . Such entry is defined as valid when it is allocated till deallocation. Doesn't include prefetches. This event is not supported on ICL products but is supported on RKL products.)",
      R"(Each cycle count number of 'valid' coherent Data Read entries . Such entry is defined as valid when it is allocated till deallocation. Doesn't include prefetches. This event is not supported on ICL products but is supported on RKL products.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_REQ_TRK_REQUEST.DRD",
      EventDef::Encoding{.code = 0x81, .umask = 0x02, .cmask = 0},
      R"(Number of all coherent Data Read entries. Doesn't include prefetches)",
      R"(Number of all coherent Data Read entries. Doesn't include prefetches)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_DAT_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0x85, .umask = 0x01, .cmask = 0},
      R"(Each cycle counts number of any coherent request at memory controller that were issued by any core. This event is not supported on ICL products but is supported on RKL products.)",
      R"(Each cycle counts number of any coherent request at memory controller that were issued by any core. This event is not supported on ICL products but is supported on RKL products.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_DAT_OCCUPANCY.RD",
      EventDef::Encoding{.code = 0x85, .umask = 0x02, .cmask = 0},
      R"(Each cycle counts number of coherent reads pending on data return from memory controller that were issued by any core. This event is not supported on ICL products but is supported on RKL products.)",
      R"(Each cycle counts number of coherent reads pending on data return from memory controller that were issued by any core. This event is not supported on ICL products but is supported on RKL products.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_REQUESTS.RD",
      EventDef::Encoding{.code = 0x81, .umask = 0x02, .cmask = 0},
      R"(Number of all coherent Data Read entries. Doesn't include prefetches. This event is not supported on ICL products but is supported on RKL products.)",
      R"(Number of all coherent Data Read entries. Doesn't include prefetches. This event is not supported on ICL products but is supported on RKL products.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_OCCUPANCY.RD",
      EventDef::Encoding{.code = 0x80, .umask = 0x02, .cmask = 0},
      R"(Each cycle count number of 'valid' coherent Data Read entries . Such entry is defined as valid when it is allocated till deallocation. Doesn't include prefetches. This event is not supported on ICL products but is supported on RKL products.)",
      R"(Each cycle count number of 'valid' coherent Data Read entries . Such entry is defined as valid when it is allocated till deallocation. Doesn't include prefetches. This event is not supported on ICL products but is supported on RKL products.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_arb,
      "UNC_ARB_TRK_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0x80, .umask = 0x01, .cmask = 0},
      R"(Each cycle counts number of all outgoing valid entries in ReqTrk. Such entry is defined as valid from its allocation in ReqTrk till deallocation. Accounts for Coherent and non-coherent traffic. This event is not supported on ICL products but is supported on RKL products.)",
      R"(Each cycle counts number of all outgoing valid entries in ReqTrk. Such entry is defined as valid from its allocation in ReqTrk till deallocation. Accounts for Coherent and non-coherent traffic. This event is not supported on ICL products but is supported on RKL products.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace icelake_uncore_experimental
} // namespace facebook::hbt::perf_event::generated
