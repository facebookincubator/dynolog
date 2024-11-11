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
namespace sierraforest_uncore_experimental {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from sierraforest_uncore_experimental.json (405 experimental events).

    Supported SKUs:
        - Arch: x86, Model: SRF id: 175
  */

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.RFO",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001BC8},
      R"(Cache Lookups: All RFO and RFO Prefetches)",
      R"(Cache Lookups : All RFOs - Demand and Prefetches)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.DATA_RD",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001BC1},
      R"(Cache Lookups: Read Requests and Read Prefetches)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.CODE",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001BD0},
      R"(Cache Lookups: CRd Requests)",
      R"(Cache Lookups : CRd Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCALLY_HOMED_ADDRESS",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00000BDF},
      R"(Cache Lookups: All Requests to Locally Homed Memory)",
      R"(Cache Lookups : Transactions homed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.REMOTELY_HOMED_ADDRESS",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x000015DF},
      R"(Cache Lookups: All Requests to Remotely Homed Memory)",
      R"(Cache Lookups : Transactions homed remotely : Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing. : Transaction whose address resides in a remote MC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.REMOTE_DATA_RD",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001A01},
      R"(Cache Lookups: Data Read/Prefetch Requests from a Remote Socket)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.REMOTE_RFO",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001A08},
      R"(Cache Lookups: RFO Requests/Prefetches from a Remote Socket)",
      R"(Cache Lookups : RFO Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.REMOTE_CODE",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001A10},
      R"(Cache Lookups: Code Read/Prefetch Requests from a Remote Socket)",
      R"(Cache Lookups : CRd Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.REMOTE_SNP",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001C19},
      R"(Cache Lookups: Snoop Requests from a Remote Socket)",
      R"(Counts the number of times the LLC was accessed)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCAL_DATA_RD",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x000019C1},
      R"(Cache Lookups: Read Requests and Read Prefetches to Locally Homed Memory)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCAL_RFO",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x000019C8},
      R"(Cache Lookups: RFO Requests and RFO Prefetches to Locally Homed Memory)",
      R"(Cache Lookups : RFO Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCAL_CODE",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x000019D0},
      R"(Cache Lookups: Code Read Requests and Code Read Prefetches to Locally Homed Memory)",
      R"(Cache Lookups : CRd Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCAL_DMND_DATA_RD",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001841},
      R"(Cache Lookups: Read Requests to Locally Homed Memory)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCAL_DMND_RFO",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001848},
      R"(Cache Lookups: RFO Requests to Locally Homed Memory)",
      R"(Cache Lookups : RFO Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCAL_DMND_CODE",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001850},
      R"(Cache Lookups: Code Read Requests to Locally Homed Memory)",
      R"(Cache Lookups : CRd Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCAL_PF_DATA_RD",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001981},
      R"(Cache Lookups: Read Prefetches to Locally Homed Memory)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCAL_PF_RFO",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001908},
      R"(Cache Lookups: RFO Prefetches to Locally Homed Memory)",
      R"(Cache Lookups : RFO Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCAL_PF_CODE",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001910},
      R"(Cache Lookups: Code Prefetches to Locally Homed Memory)",
      R"(Cache Lookups : CRd Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCAL_LLC_PF",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x0000189D},
      R"(Cache Lookups: LLC Prefetch Requests to Locally Homed Memory)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.LOCAL_PF",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x0000199D},
      R"(Cache Lookups: All Prefetches to Locally Homed Memory)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.DATA_READ_ALL",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00001FC1},
      R"(Cache Lookups: Read Requests, Read Prefetches, and Snoops)",
      R"(Cache Lookups : Data Reads)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.DATA_READ_MISS",
      EventDef::Encoding{.code = 0x34, .umask = 0x01, .umaskExt = 0x00001FC1},
      R"(Cache Lookups: Read Requests, Read Prefetches, and Snoops which miss the Cache)",
      R"(Cache Lookups : Data Read Misses)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.DATA_READ_LOCAL",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00000841},
      R"(Cache Lookups: Read Requests to Locally Homed Memory)",
      R"(Cache Lookups : Demand Data Reads, Core and LLC prefetches)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.WRITE_LOCAL",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x00000842},
      R"(Cache Lookups: Writes to Locally Homed Memory (includes writebacks from L1/L2))",
      R"(Cache Lookups : Writes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.RFO_LOCAL",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x000009C8},
      R"(Cache Lookups: RFO Requests and RFO Prefetches to Locally Homed Memory)",
      R"(Cache Lookups : Locally HOMed RFOs - Demand and Prefetches)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.WRITE_REMOTE",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x000017C2},
      R"(Cache Lookups: Writes to Remotely Homed Memory (includes writebacks from L1/L2))",
      R"(Cache Lookups : Remote Writes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.ALL_REMOTE",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x000017E0},
      R"(Cache Lookups: All Requests to Remotely Homed Memory)",
      R"(Cache Lookups : All transactions from Remote Agents)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.ALL",
      EventDef::Encoding{.code = 0x35, .umask = 0xFF, .umaskExt = 0x00C001FF},
      R"(All TOR Inserts)",
      R"(TOR Inserts : All)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C001FF},
      R"(All locally initiated requests from IA Cores)",
      R"(TOR Inserts : All requests from iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C001FD},
      R"(All locally initiated requests from IA Cores which hit the cache)",
      R"(TOR Inserts : All requests from iA Cores that Hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C001FF},
      R"(All TOR inserts from local IO devices)",
      R"(TOR Inserts : All requests from IO Devices)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_HIT",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C001FD},
      R"(All TOR inserts from local IO devices which hit the cache)",
      R"(TOR Inserts : All requests from IO Devices that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C001FE},
      R"(All TOR inserts from local IO devices which miss the cache)",
      R"(TOR Inserts : All requests from IO Devices that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.LOC_IO",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C000FF},
      R"(All from Local IO)",
      R"(TOR Inserts : All from Local IO)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.LOC_IA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C000FF},
      R"(All from Local iA)",
      R"(TOR Inserts : All from Local iA)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.LOC_ALL",
      EventDef::Encoding{.code = 0x35, .umask = 0x05, .umaskExt = 0x00C000FF},
      R"(All locally initiated requests)",
      R"(TOR Inserts : All from Local iA and IO)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.REM_SNPS",
      EventDef::Encoding{.code = 0x35, .umask = 0x08, .umaskExt = 0x00C001FF},
      R"(All snoops to this LLC that came from remote sockets)",
      R"(TOR Inserts : All Snoops from Remote)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.REM_ALL",
      EventDef::Encoding{.code = 0x35, .umask = 0xC8, .umaskExt = 0x00C001FF},
      R"(All remote requests (e.g. snoops, writebacks) that came from remote sockets)",
      R"(TOR Inserts : All Remote Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCILF_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8678A},
      R"(WCILF requests from local IA cores to PMM homed addresses which miss the cache)",
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting PMM that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCILF_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8668A},
      R"(WCILF requests from local IA cores to locally homed PMM addresses which miss the cache)",
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCILF_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8670A},
      R"(WCILF requests from local IA cores to remotely homed PMM addresses which miss the cache)",
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCIL_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C86F8A},
      R"(WCIL requests from a local IA core to PMM homed addresses that miss the cache)",
      R"(TOR Inserts : WCiLs issued by iA Cores targeting PMM that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCIL_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C86E8A},
      R"(WCIL requests from local IA cores to locally homed PMM addresses which miss the cache)",
      R"(TOR Inserts : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCIL_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C86F0A},
      R"(WCIL requests from local IA cores to remotely homed PMM addresses which miss the cache)",
      R"(TOR Inserts : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_HIT_FSRDCUR",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C8EFFD},
      R"(FsRdCur transactions from a CXL device which hit in the L3.)",
      R"(FsRdCur transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_HIT_FSRDCURPTL",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C9EFFD},
      R"(FsRdCurPtl transactions from a CXL device which hit in the L3.)",
      R"(FsRdCurPtl transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_HIT_MEMPUSHWR",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78CC6FFD},
      R"(MemPushWr transactions from a CXL device which hit in the L3.)",
      R"(MemPushWr transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_HIT_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78CC47FD},
      R"(ItoM transactions from a CXL device which hit in the L3.)",
      R"(ItoM transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_HIT_ITOMWR",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78CC4FFD},
      R"(ItoMWr transactions from a CXL device which hit in the L3.)",
      R"(ItoMWr transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_HIT_CLFLUSH",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C8C7FD},
      R"(CLFlush transactions from a CXL device which hit in the L3.)",
      R"(CLFlush transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_HIT_WIL",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C87FFD},
      R"(WiL transactions from a CXL device which hit in the L3.)",
      R"(WiL transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_HIT_WCILF",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C867FD},
      R"(WcilF transactions from a CXL device which hit in the L3.)",
      R"(WcilF transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_HIT_WCIL",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C86FFD},
      R"(WCiL transactions from a CXL device which hit in the L3.)",
      R"(WCiL transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_MISS_FSRDCUR",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C8EFFE},
      R"(FsRdCur transactions from a CXL device which miss the L3.)",
      R"(FsRdCur transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_MISS_FSRDCURPTL",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C9EFFE},
      R"(FsRdCurPtl transactions from a CXL device which miss the L3.)",
      R"(FsRdCurPtl transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_MISS_MEMPUSHWR",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78CC6FFE},
      R"(MemPushWr transactions from a CXL device which miss the L3.)",
      R"(MemPushWr transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_MISS_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78CC47FE},
      R"(ItoM transactions from a CXL device which miss the L3.)",
      R"(ItoM transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_MISS_ITOMWR",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78CC4FFE},
      R"(ItoMWr transactions from a CXL device which miss the L3.)",
      R"(ItoMWr transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_MISS_CLFLUSH",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C8C7FE},
      R"(CLFlush transactions from a CXL device which miss the L3.)",
      R"(CLFlush transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_MISS_WIL",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C87FFE},
      R"(WiL transactions from a CXL device which miss the L3.)",
      R"(WiL transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_MISS_WCILF",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C867FE},
      R"(WcilF transactions from a CXL device which miss the L3.)",
      R"(WcilF transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.CXL_MISS_WCIL",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .umaskExt = 0x78C86FFE},
      R"(WCiL transactions from a CXL device which miss the L3.)",
      R"(WCiL transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0x36, .umask = 0xFF, .umaskExt = 0x00C001FF},
      R"(Occupancy for all TOR entries)",
      R"(TOR Occupancy : All)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C001FF},
      R"(TOR Occupancy for All locally initiated requests from IA Cores)",
      R"(TOR Occupancy : All requests from iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C001FD},
      R"(TOR Occupancy for All locally initiated requests from IA Cores which hit the cache)",
      R"(TOR Occupancy : All requests from iA Cores that Hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C001FE},
      R"(TOR Occupancy for All locally initiated requests from IA Cores which miss the cache)",
      R"(TOR Occupancy : All requests from iA Cores that Missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C001FF},
      R"(TOR Occupancy for All TOR inserts from local IO devices)",
      R"(TOR Occupancy : All requests from IO Devices)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_HIT",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C001FD},
      R"(TOR Occupancy for All TOR inserts from local IO devices which hit the cache)",
      R"(TOR Occupancy : All requests from IO Devices that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C001FE},
      R"(TOR Occupancy for All TOR inserts from local IO devices which miss the cache)",
      R"(TOR Occupancy : All requests from IO Devices that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.LOC_IO",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C000FF},
      R"(TOR Occupancy for All from Local IO)",
      R"(TOR Occupancy : All from Local IO)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.LOC_IA",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C000FF},
      R"(TOR Occupancy for All from Local iA)",
      R"(TOR Occupancy : All from Local iA)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.LOC_ALL",
      EventDef::Encoding{.code = 0x36, .umask = 0x05, .umaskExt = 0x00C000FF},
      R"(TOR Occupancy for All locally initiated requests)",
      R"(TOR Occupancy : All from Local iA and IO)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.REM_SNPS",
      EventDef::Encoding{.code = 0x36, .umask = 0x08, .umaskExt = 0x00C001FF},
      R"(TOR Occupancy for All snoops to this LLC that came from remote sockets)",
      R"(TOR Occupancy : All Snoops from Remote)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.REM_ALL",
      EventDef::Encoding{.code = 0x36, .umask = 0xC8, .umaskExt = 0x00C001FF},
      R"(TOR Occupancy for All remote requests (e.g. snoops, writebacks) that came from remote sockets)",
      R"(TOR Occupancy : All Remote Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_DRD_OPT",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C827FF},
      R"(TOR Occupancy for Data read opt from local IA that miss the cache)",
      R"(TOR Occupancy : DRd_Opts issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C8A7FF},
      R"(TOR Occupancy for Data read opt prefetch from local IA that miss the cache)",
      R"(TOR Occupancy : DRd_Opt_Prefs issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCILF_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C8678A},
      R"(TOR Occupancy for WCILF requests from local IA cores to PMM homed addresses which miss the cache)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCILF_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C8668A},
      R"(TOR Occupancy for WCILF requests from local IA cores to locally homed PMM addresses which miss the cache)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCILF_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C8670A},
      R"(TOR Occupancy for WCILF requests from local IA cores to remotely homed PMM addresses which miss the cache)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCIL_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C86F8A},
      R"(TOR Occupancy for WCIL requests from a local IA core to PMM homed addresses that miss the cache)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCIL_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C86E8A},
      R"(TOR Occupancy for WCIL requests from local IA cores to locally homed PMM addresses which miss the cache)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCIL_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C86F0A},
      R"(TOR Occupancy for WCIL requests from local IA cores to remotely homed PMM addresses which miss the cache)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_FSRDCUR",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C8EFFD},
      R"(TOR Occupancy for FsRdCur transactions from a CXL device which hit in the L3.)",
      R"(TOR Occupancy for FsRdCur transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_FSRDCURPTL",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C9EFFD},
      R"(TOR Occupancy for FsRdCurPtl transactions from a CXL device which hit in the L3.)",
      R"(TOR Occupancy for FsRdCurPtl transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_MEMPUSHWR",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78CC6FFD},
      R"(TOR Occupancy for MemPushWr transactions from a CXL device which hit in the L3.)",
      R"(TOR Occupancy for MemPushWr transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78CC47FD},
      R"(TOR Occupancy for ItoM transactions from a CXL device which hit in the L3.)",
      R"(TOR Occupancy for ItoM transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_ITOMWR",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78CC4FFD},
      R"(TOR Occupancy for ItoMWr transactions from a CXL device which hit in the L3.)",
      R"(TOR Occupancy for ItoMWr transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_CLFLUSH",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C8C7FD},
      R"(TOR Occupancy for CLFlush transactions from a CXL device which hit in the L3.)",
      R"(TOR Occupancy for CLFlush transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_WIL",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C87FFD},
      R"(TOR Occupancy for WiL transactions from a CXL device which hit in the L3.)",
      R"(TOR Occupancy for WiL transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_WCILF",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C867FD},
      R"(TOR Occupancy for WcilF transactions from a CXL device which hit in the L3.)",
      R"(TOR Occupancy for WcilF transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_HIT_WCIL",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C86FFD},
      R"(TOR Occupancy for WCiL transactions from a CXL device which hit in the L3.)",
      R"(TOR Occupancy for WCiL transactions from a CXL device which hit in the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_FSRDCUR",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C8EFFE},
      R"(TOR Occupancy for FsRdCur transactions from a CXL device which miss the L3.)",
      R"(TOR Occupancy for FsRdCur transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_FSRDCURPTL",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C9EFFE},
      R"(TOR Occupancy for FsRdCurPtl transactions from a CXL device which miss the L3.)",
      R"(TOR Occupancy for FsRdCurPtl transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_MEMPUSHWR",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78CC6FFE},
      R"(TOR Occupancy for MemPushWr transactions from a CXL device which miss the L3.)",
      R"(TOR Occupancy for MemPushWr transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78CC47FE},
      R"(TOR Occupancy for ItoM transactions from a CXL device which miss the L3.)",
      R"(TOR Occupancy for ItoM transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_ITOMWR",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78CC4FFE},
      R"(TOR Occupancy for ItoMWr transactions from a CXL device which miss the L3.)",
      R"(TOR Occupancy for ItoMWr transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_CLFLUSH",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C8C7FE},
      R"(TOR Occupancy for CLFlush transactions from a CXL device which miss the L3.)",
      R"(TOR Occupancy for CLFlush transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_WIL",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C87FFE},
      R"(TOR Occupancy for WiL transactions from a CXL device which miss the L3.)",
      R"(TOR Occupancy for WiL transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_WCILF",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C867FE},
      R"(TOR Occupancy for WcilF transactions from a CXL device which miss the L3.)",
      R"(TOR Occupancy for WcilF transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.CXL_MISS_WCIL",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .umaskExt = 0x78C86FFE},
      R"(TOR Occupancy for WCiL transactions from a CXL device which miss the L3.)",
      R"(TOR Occupancy for WCiL transactions from a CXL device which miss the L3.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.IO",
      EventDef::Encoding{.code = 0x37, .umask = 0x10, .umaskExt = 0x00000000},
      R"(Lines Victimized : IO traffic : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : IO traffic)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.IA",
      EventDef::Encoding{.code = 0x37, .umask = 0x20, .umaskExt = 0x00000000},
      R"(Lines Victimized : IA traffic : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : IA traffic)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.LOCAL_ALL",
      EventDef::Encoding{.code = 0x37, .umask = 0x0F, .umaskExt = 0x00000020},
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Local - All Lines)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.REMOTE_ALL",
      EventDef::Encoding{.code = 0x37, .umask = 0x0F, .umaskExt = 0x00000080},
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Remote - All Lines)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.ALL",
      EventDef::Encoding{.code = 0x37, .umask = 0x0F, .umaskExt = 0x00000000},
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : All Lines Victimized)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.TOTAL_M",
      EventDef::Encoding{.code = 0x37, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Lines in M state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.TOTAL_E",
      EventDef::Encoding{.code = 0x37, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Lines in E state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.TOTAL_S",
      EventDef::Encoding{.code = 0x37, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Lines in S State)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_LOOKUP.NO_SNP",
      EventDef::Encoding{.code = 0x53, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Counts transactions that looked into the multi-socket cacheline Directory state, and therefore did not send a snoop because the Directory indicated it was not needed.)",
      R"(Counts transactions that looked into the multi-socket cacheline Directory state, and therefore did not send a snoop because the Directory indicated it was not needed.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_LOOKUP.SNP",
      EventDef::Encoding{.code = 0x53, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Counts  transactions that looked into the multi-socket cacheline Directory state, and sent one or more snoops, because the Directory indicated it was needed.)",
      R"(Counts  transactions that looked into the multi-socket cacheline Directory state, and sent one or more snoops, because the Directory indicated it was needed.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_UPDATE.HA",
      EventDef::Encoding{.code = 0x54, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Counts only multi-socket cacheline Directory state updates memory writes issued from the HA pipe. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.)",
      R"(Counts only multi-socket cacheline Directory state updates memory writes issued from the HA pipe. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_UPDATE.TOR",
      EventDef::Encoding{.code = 0x54, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Counts only multi-socket cacheline Directory state updates due to memory writes issued from the TOR pipe which are the result of remote transaction hitting the SF/LLC and returning data Core2Core. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.)",
      R"(Counts only multi-socket cacheline Directory state updates due to memory writes issued from the TOR pipe which are the result of remote transaction hitting the SF/LLC and returning data Core2Core. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_OSB.LOCAL_INVITOE",
      EventDef::Encoding{.code = 0x55, .umask = 0x01, .umaskExt = 0x00000000},
      R"(OSB Snoop Broadcast : Local InvItoE : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      R"(OSB Snoop Broadcast : Local InvItoE)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_OSB.LOCAL_READ",
      EventDef::Encoding{.code = 0x55, .umask = 0x02, .umaskExt = 0x00000000},
      R"(OSB Snoop Broadcast : Local Rd : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      R"(OSB Snoop Broadcast : Local Rd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_OSB.REMOTE_READ",
      EventDef::Encoding{.code = 0x55, .umask = 0x04, .umaskExt = 0x00000000},
      R"(OSB Snoop Broadcast : Remote Rd : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      R"(OSB Snoop Broadcast : Remote Rd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_OSB.OFF_PWRHEURISTIC",
      EventDef::Encoding{.code = 0x55, .umask = 0x20, .umaskExt = 0x00000000},
      R"(OSB Snoop Broadcast : Off : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      R"(OSB Snoop Broadcast : Off)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_IMC_WRITES_COUNT.FULL",
      EventDef::Encoding{.code = 0x5b, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Counts when a normal (Non-Isochronous) full line write is issued from the CHA to the any of the memory controller channels.)",
      R"(Counts when a normal (Non-Isochronous) full line write is issued from the CHA to the any of the memory controller channels.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_IMC_WRITES_COUNT.PARTIAL",
      EventDef::Encoding{.code = 0x5b, .umask = 0x02, .umaskExt = 0x00000000},
      R"(CHA to iMC Full Line Writes Issued : Partial Non-ISOCH : Counts the total number of full line writes issued from the HA into the memory controller.)",
      R"(CHA to iMC Full Line Writes Issued : Partial Non-ISOCH)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_IMC_WRITES_COUNT.FULL_PRIORITY",
      EventDef::Encoding{.code = 0x5b, .umask = 0x04, .umaskExt = 0x00000000},
      R"(CHA to iMC Full Line Writes Issued : ISOCH Full Line : Counts the total number of full line writes issued from the HA into the memory controller.)",
      R"(CHA to iMC Full Line Writes Issued : ISOCH Full Line)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_IMC_WRITES_COUNT.PARTIAL_PRIORITY",
      EventDef::Encoding{.code = 0x5b, .umask = 0x08, .umaskExt = 0x00000000},
      R"(CHA to iMC Full Line Writes Issued : ISOCH Partial : Counts the total number of full line writes issued from the HA into the memory controller.)",
      R"(CHA to iMC Full Line Writes Issued : ISOCH Partial)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_HCLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Number of DRAM HCLK clock cycles while the event is enabled)",
      R"(DRAM Clockticks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_ACT_COUNT.RD",
      EventDef::Encoding{.code = 0x02, .umask = 0xF1, .umaskExt = 0x00000000},
      R"(DRAM Activate Count : Read transaction on Page Empty or Page Miss : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.)",
      R"(DRAM Activate Count : Read transaction on Page Empty or Page Miss)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_ACT_COUNT.WR",
      EventDef::Encoding{.code = 0x02, .umask = 0xF2, .umaskExt = 0x00000000},
      R"(DRAM Activate Count : Write transaction on Page Empty or Page Miss : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.)",
      R"(DRAM Activate Count : Write transaction on Page Empty or Page Miss)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_ACT_COUNT.UFILL",
      EventDef::Encoding{.code = 0x02, .umask = 0xF4, .umaskExt = 0x00000000},
      R"(DRAM Activate Count : Underfill Read transaction on Page Empty or Page Miss : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.)",
      R"(DRAM Activate Count : Underfill Read transaction on Page Empty or Page Miss)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.RD",
      EventDef::Encoding{.code = 0x03, .umask = 0xF1, .umaskExt = 0x00000000},
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      R"(DRAM Precharge commands.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.WR",
      EventDef::Encoding{.code = 0x03, .umask = 0xF2, .umaskExt = 0x00000000},
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      R"(DRAM Precharge commands.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.UFILL",
      EventDef::Encoding{.code = 0x03, .umask = 0xF4, .umaskExt = 0x00000000},
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      R"(DRAM Precharge commands.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH0.WR_PRE",
      EventDef::Encoding{.code = 0x05, .umask = 0xE0, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 0 auto-precharge writes)",
      R"(CAS count for SubChannel 0 auto-precharge writes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH0.WR_NONPRE",
      EventDef::Encoding{.code = 0x05, .umask = 0xD0, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 0 regular writes)",
      R"(CAS count for SubChannel 0 regular writes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH1.WR_PRE",
      EventDef::Encoding{.code = 0x06, .umask = 0xE0, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 1 auto-precharge writes)",
      R"(CAS count for SubChannel 1 auto-precharge writes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH1.WR_NONPRE",
      EventDef::Encoding{.code = 0x06, .umask = 0xD0, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 1 regular writes)",
      R"(CAS count for SubChannel 1 regular writes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_INSERTS.PCH0",
      EventDef::Encoding{.code = 0x10, .umask = 0x50, .umaskExt = 0x00000000},
      R"(Read Pending Queue Allocations : Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.)",
      R"(Read Pending Queue Allocations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_INSERTS.PCH1",
      EventDef::Encoding{.code = 0x10, .umask = 0xA0, .umaskExt = 0x00000000},
      R"(Read Pending Queue Allocations : Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.)",
      R"(Read Pending Queue Allocations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_INSERTS.PCH0",
      EventDef::Encoding{.code = 0x22, .umask = 0x50, .umaskExt = 0x00000000},
      R"(Write Pending Queue Allocations)",
      R"(Write Pending Queue Allocations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_INSERTS.PCH1",
      EventDef::Encoding{.code = 0x22, .umask = 0xA0, .umaskExt = 0x00000000},
      R"(Write Pending Queue Allocations)",
      R"(Write Pending Queue Allocations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RDB_INSERTS.SCH0",
      EventDef::Encoding{.code = 0x17, .umask = 0x40, .umaskExt = 0x00000000},
      R"(Read buffer inserts on subchannel 0)",
      R"(Read buffer inserts on subchannel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RDB_INSERTS.SCH1",
      EventDef::Encoding{.code = 0x17, .umask = 0x80, .umaskExt = 0x00000000},
      R"(Read buffer inserts on subchannel 1)",
      R"(Read buffer inserts on subchannel 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .umaskExt = 0x00070010},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .umaskExt = 0x00070010},
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .umaskExt = 0x00070010},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .umaskExt = 0x00070010},
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .umaskExt = 0x00070010},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.ALL_PARTS",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00070FF0},
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.ALL_PARTS",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .umaskExt = 0x00070FF0},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART0",
      EventDef::Encoding{.code = 0xC2, .umask = 0x04, .umaskExt = 0x00070010},
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART1",
      EventDef::Encoding{.code = 0xC2, .umask = 0x04, .umaskExt = 0x00070020},
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART2",
      EventDef::Encoding{.code = 0xC2, .umask = 0x04, .umaskExt = 0x00070040},
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART3",
      EventDef::Encoding{.code = 0xC2, .umask = 0x04, .umaskExt = 0x00070080},
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART4",
      EventDef::Encoding{.code = 0xC2, .umask = 0x04, .umaskExt = 0x00070100},
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART5",
      EventDef::Encoding{.code = 0xC2, .umask = 0x04, .umaskExt = 0x00070200},
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART6",
      EventDef::Encoding{.code = 0xC2, .umask = 0x04, .umaskExt = 0x00070400},
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART7",
      EventDef::Encoding{.code = 0xC2, .umask = 0x04, .umaskExt = 0x00070800},
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.ALL_PARTS",
      EventDef::Encoding{.code = 0xC2, .umask = 0x04, .umaskExt = 0x00070FF0},
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      R"(PCIE Completion Buffer Inserts.  Counts once per 64 byte read issued from this PCIE device.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.4K_HITS",
      EventDef::Encoding{.code = 0x40, .umask = 0x04, .umaskExt = 0x00000000},
      R"(IOTLB Hits to a 4K Page)",
      R"(IOTLB Hits to a 4K Page)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.2M_HITS",
      EventDef::Encoding{.code = 0x40, .umask = 0x08, .umaskExt = 0x00000000},
      R"(IOTLB Hits to a 2M Page)",
      R"(IOTLB Hits to a 2M Page)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.1G_HITS",
      EventDef::Encoding{.code = 0x40, .umask = 0x10, .umaskExt = 0x00000000},
      R"(IOTLB Hits to a 1G Page)",
      R"(IOTLB Hits to a 1G Page)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.CTXT_CACHE_LOOKUPS",
      EventDef::Encoding{.code = 0x40, .umask = 0x40, .umaskExt = 0x00000000},
      R"(Context cache lookups)",
      R"(Context cache lookups)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.CTXT_CACHE_HITS",
      EventDef::Encoding{.code = 0x40, .umask = 0x80, .umaskExt = 0x00000000},
      R"(Context cache hits)",
      R"(Context cache hits)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.NUM_MEM_ACCESSES",
      EventDef::Encoding{.code = 0x41, .umask = 0xC0, .umaskExt = 0x00000000},
      R"(IOMMU memory access (both low and high priority))",
      R"(IOMMU memory access (both low and high priority))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_CACHE_TOTAL_OCCUPANCY.MEM",
      EventDef::Encoding{.code = 0x0F, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Total Write Cache Occupancy : Mem)",
      R"(Total Write Cache Occupancy : Mem)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.ALL_MISS",
      EventDef::Encoding{.code = 0x12, .umask = 0x71, .umaskExt = 0x00000000},
      R"(Snoop miss responses)",
      R"(Snoop miss responses)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.ALL_HIT_I",
      EventDef::Encoding{.code = 0x12, .umask = 0x72, .umaskExt = 0x00000000},
      R"(Snoop Hit I responses)",
      R"(Snoop Hit I responses)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.ALL_HIT_ES",
      EventDef::Encoding{.code = 0x12, .umask = 0x74, .umaskExt = 0x00000000},
      R"(Snoop Hit E/S responses)",
      R"(Snoop Hit E/S responses)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.ALL_HIT_M",
      EventDef::Encoding{.code = 0x12, .umask = 0x78, .umaskExt = 0x00000000},
      R"(Snoop Hit M responses)",
      R"(Snoop Hit M responses)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_FAF_OCCUPANCY",
      EventDef::Encoding{.code = 0x19, .umask = 0x00, .umaskExt = 0x00000000},
      R"(FAF occupancy)",
      R"(FAF occupancy)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC0.FAST_REQ",
      EventDef::Encoding{.code = 0x1E, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Counts Timeouts - Set 0 : Fastpath Requests)",
      R"(Counts Timeouts - Set 0 : Fastpath Requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC0.FAST_REJ",
      EventDef::Encoding{.code = 0x1E, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Counts Timeouts - Set 0 : Fastpath Rejects)",
      R"(Counts Timeouts - Set 0 : Fastpath Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC1.LOST_FWD",
      EventDef::Encoding{.code = 0x1F, .umask = 0x10, .umaskExt = 0x00000000},
      R"(Misc Events - Set 1 : Lost Forward : Snoop pulled away ownership before a write was committed)",
      R"(Misc Events - Set 1 : Lost Forward : Snoop pulled away ownership before a write was committed)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.SLOT0",
      EventDef::Encoding{.code = 0x02, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : Slot 0 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 0 - Other mask bits determine types of headers to count.)",
      R"(Valid Flits Sent : Slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.SLOT1",
      EventDef::Encoding{.code = 0x02, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : Slot 1 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 1 - Other mask bits determine types of headers to count.)",
      R"(Valid Flits Sent : Slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.SLOT2",
      EventDef::Encoding{.code = 0x02, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : Slot 2 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 2 - Other mask bits determine types of headers to count.)",
      R"(Valid Flits Sent : Slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.DATA",
      EventDef::Encoding{.code = 0x02, .umask = 0x08, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : Data : Shows legal flit time (hides impact of L0p and L0c). : Count Data Flits (which consume all slots), but how much to count is based on Slot0-2 mask, so count can be 0-3 depending on which slots are enabled for counting..)",
      R"(Valid Flits Sent : Data)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.LLCRD",
      EventDef::Encoding{.code = 0x02, .umask = 0x10, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : LLCRD Not Empty : Shows legal flit time (hides impact of L0p and L0c). : Enables counting of LLCRD (with non-zero payload). This only applies to slot 2 since LLCRD is only allowed in slot 2)",
      R"(Valid Flits Sent : LLCRD Not Empty)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.NULL",
      EventDef::Encoding{.code = 0x02, .umask = 0x20, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : Slot NULL or LLCRD Empty : Shows legal flit time (hides impact of L0p and L0c). : LLCRD with all zeros is treated as NULL. Slot 1 is not treated as NULL if slot 0 is a dual slot. This can apply to slot 0,1, or 2.)",
      R"(Valid Flits Sent : Slot NULL or LLCRD Empty)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.LLCTRL",
      EventDef::Encoding{.code = 0x02, .umask = 0x40, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : LLCTRL : Shows legal flit time (hides impact of L0p and L0c). : Equivalent to an idle packet.  Enables counting of slot 0 LLCTRL messages.)",
      R"(Valid Flits Sent : LLCTRL)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.PROTHDR",
      EventDef::Encoding{.code = 0x02, .umask = 0x80, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : Protocol Header : Shows legal flit time (hides impact of L0p and L0c). : Enables count of protocol headers in slot 0,1,2 (depending on slot uMask bits))",
      R"(Valid Flits Sent : Protocol Header)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.SLOT0",
      EventDef::Encoding{.code = 0x03, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Valid Flits Received : Slot 0 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 0 - Other mask bits determine types of headers to count.)",
      R"(Valid Flits Received : Slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.SLOT1",
      EventDef::Encoding{.code = 0x03, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Valid Flits Received : Slot 1 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 1 - Other mask bits determine types of headers to count.)",
      R"(Valid Flits Received : Slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.SLOT2",
      EventDef::Encoding{.code = 0x03, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Valid Flits Received : Slot 2 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 2 - Other mask bits determine types of headers to count.)",
      R"(Valid Flits Received : Slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.DATA",
      EventDef::Encoding{.code = 0x03, .umask = 0x08, .umaskExt = 0x00000000},
      R"(Valid Flits Received : Data : Shows legal flit time (hides impact of L0p and L0c). : Count Data Flits (which consume all slots), but how much to count is based on Slot0-2 mask, so count can be 0-3 depending on which slots are enabled for counting..)",
      R"(Valid Flits Received : Data)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.LLCRD",
      EventDef::Encoding{.code = 0x03, .umask = 0x10, .umaskExt = 0x00000000},
      R"(Valid Flits Received : LLCRD Not Empty : Shows legal flit time (hides impact of L0p and L0c). : Enables counting of LLCRD (with non-zero payload). This only applies to slot 2 since LLCRD is only allowed in slot 2)",
      R"(Valid Flits Received : LLCRD Not Empty)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.NULL",
      EventDef::Encoding{.code = 0x03, .umask = 0x20, .umaskExt = 0x00000000},
      R"(Valid Flits Received : Slot NULL or LLCRD Empty : Shows legal flit time (hides impact of L0p and L0c). : LLCRD with all zeros is treated as NULL. Slot 1 is not treated as NULL if slot 0 is a dual slot. This can apply to slot 0,1, or 2.)",
      R"(Valid Flits Received : Slot NULL or LLCRD Empty)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.ALL_NULL",
      EventDef::Encoding{.code = 0x03, .umask = 0x27, .umaskExt = 0x00000000},
      R"(Null FLITs received from any slot)",
      R"(Valid Flits Received : Null FLITs received from any slot)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.LLCTRL",
      EventDef::Encoding{.code = 0x03, .umask = 0x40, .umaskExt = 0x00000000},
      R"(Valid Flits Received : LLCTRL : Shows legal flit time (hides impact of L0p and L0c). : Equivalent to an idle packet.  Enables counting of slot 0 LLCTRL messages.)",
      R"(Valid Flits Received : LLCTRL)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.IDLE",
      EventDef::Encoding{.code = 0x03, .umask = 0x47, .umaskExt = 0x00000000},
      R"(Valid Flits Received : Idle : Shows legal flit time (hides impact of L0p and L0c).)",
      R"(Valid Flits Received : Idle)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.PROTHDR",
      EventDef::Encoding{.code = 0x03, .umask = 0x80, .umaskExt = 0x00000000},
      R"(Valid Flits Received : Protocol Header : Shows legal flit time (hides impact of L0p and L0c). : Enables count of protocol headers in slot 0,1,2 (depending on slot uMask bits))",
      R"(Valid Flits Received : Protocol Header)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.REQ",
      EventDef::Encoding{.code = 0x04, .umask = 0x08, .umaskExt = 0x00000000},
      R"(Matches on Transmit path of a UPI Port : Request)",
      R"(Matches on Transmit path of a UPI Port : Request)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.REQ_OPC",
      EventDef::Encoding{.code = 0x04, .umask = 0x08, .umaskExt = 0x00000001},
      R"(Matches on Transmit path of a UPI Port : Request, Match Opcode)",
      R"(Matches on Transmit path of a UPI Port : Request, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.SNP",
      EventDef::Encoding{.code = 0x04, .umask = 0x09, .umaskExt = 0x00000000},
      R"(Matches on Transmit path of a UPI Port : Snoop)",
      R"(Matches on Transmit path of a UPI Port : Snoop)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.SNP_OPC",
      EventDef::Encoding{.code = 0x04, .umask = 0x09, .umaskExt = 0x00000001},
      R"(Matches on Transmit path of a UPI Port : Snoop, Match Opcode)",
      R"(Matches on Transmit path of a UPI Port : Snoop, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.RSP_NODATA",
      EventDef::Encoding{.code = 0x04, .umask = 0x0A, .umaskExt = 0x00000000},
      R"(Matches on Transmit path of a UPI Port : Response - No Data)",
      R"(Matches on Transmit path of a UPI Port : Response - No Data)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.RSP_NODATA_OPC",
      EventDef::Encoding{.code = 0x04, .umask = 0x0A, .umaskExt = 0x00000001},
      R"(Matches on Transmit path of a UPI Port : Response - No Data, Match Opcode)",
      R"(Matches on Transmit path of a UPI Port : Response - No Data, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.RSP_DATA",
      EventDef::Encoding{.code = 0x04, .umask = 0x0C, .umaskExt = 0x00000000},
      R"(Matches on Transmit path of a UPI Port : Response - Data)",
      R"(Matches on Transmit path of a UPI Port : Response - Data)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.RSP_DATA_OPC",
      EventDef::Encoding{.code = 0x04, .umask = 0x0C, .umaskExt = 0x00000001},
      R"(Matches on Transmit path of a UPI Port : Response - Data, Match Opcode)",
      R"(Matches on Transmit path of a UPI Port : Response - Data, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.WB",
      EventDef::Encoding{.code = 0x04, .umask = 0x0D, .umaskExt = 0x00000000},
      R"(Matches on Transmit path of a UPI Port : Writeback)",
      R"(Matches on Transmit path of a UPI Port : Writeback)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.WB_OPC",
      EventDef::Encoding{.code = 0x04, .umask = 0x0D, .umaskExt = 0x00000001},
      R"(Matches on Transmit path of a UPI Port : Writeback, Match Opcode)",
      R"(Matches on Transmit path of a UPI Port : Writeback, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.NCB",
      EventDef::Encoding{.code = 0x04, .umask = 0x0E, .umaskExt = 0x00000000},
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Bypass)",
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Bypass)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.NCB_OPC",
      EventDef::Encoding{.code = 0x04, .umask = 0x0E, .umaskExt = 0x00000001},
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Bypass, Match Opcode)",
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Bypass, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.NCS",
      EventDef::Encoding{.code = 0x04, .umask = 0x0F, .umaskExt = 0x00000000},
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Standard)",
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Standard)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.NCS_OPC",
      EventDef::Encoding{.code = 0x04, .umask = 0x0F, .umaskExt = 0x00000001},
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Standard, Match Opcode)",
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Standard, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.REQ_OPC",
      EventDef::Encoding{.code = 0x05, .umask = 0x08, .umaskExt = 0x00000001},
      R"(Matches on Receive path of a UPI Port : Request, Match Opcode)",
      R"(Matches on Receive path of a UPI Port : Request, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.SNP",
      EventDef::Encoding{.code = 0x05, .umask = 0x09, .umaskExt = 0x00000000},
      R"(Matches on Receive path of a UPI Port : Snoop)",
      R"(Matches on Receive path of a UPI Port : Snoop)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.SNP_OPC",
      EventDef::Encoding{.code = 0x05, .umask = 0x09, .umaskExt = 0x00000001},
      R"(Matches on Receive path of a UPI Port : Snoop, Match Opcode)",
      R"(Matches on Receive path of a UPI Port : Snoop, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.RSP_NODATA",
      EventDef::Encoding{.code = 0x05, .umask = 0x0A, .umaskExt = 0x00000000},
      R"(Matches on Receive path of a UPI Port : Response - No Data)",
      R"(Matches on Receive path of a UPI Port : Response - No Data)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.RSP_NODATA_OPC",
      EventDef::Encoding{.code = 0x05, .umask = 0x0A, .umaskExt = 0x00000001},
      R"(Matches on Receive path of a UPI Port : Response - No Data, Match Opcode)",
      R"(Matches on Receive path of a UPI Port : Response - No Data, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.RSP_DATA",
      EventDef::Encoding{.code = 0x05, .umask = 0x0C, .umaskExt = 0x00000000},
      R"(Matches on Receive path of a UPI Port : Response - Data)",
      R"(Matches on Receive path of a UPI Port : Response - Data)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.RSP_DATA_OPC",
      EventDef::Encoding{.code = 0x05, .umask = 0x0C, .umaskExt = 0x00000001},
      R"(Matches on Receive path of a UPI Port : Response - Data, Match Opcode)",
      R"(Matches on Receive path of a UPI Port : Response - Data, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.WB_OPC",
      EventDef::Encoding{.code = 0x05, .umask = 0x0D, .umaskExt = 0x00000001},
      R"(Matches on Receive path of a UPI Port : Writeback, Match Opcode)",
      R"(Matches on Receive path of a UPI Port : Writeback, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.NCB",
      EventDef::Encoding{.code = 0x05, .umask = 0x0E, .umaskExt = 0x00000000},
      R"(Matches on Receive path of a UPI Port : Non-Coherent Bypass)",
      R"(Matches on Receive path of a UPI Port : Non-Coherent Bypass)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.NCB_OPC",
      EventDef::Encoding{.code = 0x05, .umask = 0x0E, .umaskExt = 0x00000001},
      R"(Matches on Receive path of a UPI Port : Non-Coherent Bypass, Match Opcode)",
      R"(Matches on Receive path of a UPI Port : Non-Coherent Bypass, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.NCS",
      EventDef::Encoding{.code = 0x05, .umask = 0x0F, .umaskExt = 0x00000000},
      R"(Matches on Receive path of a UPI Port : Non-Coherent Standard)",
      R"(Matches on Receive path of a UPI Port : Non-Coherent Standard)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.NCS_OPC",
      EventDef::Encoding{.code = 0x05, .umask = 0x0F, .umaskExt = 0x00000001},
      R"(Matches on Receive path of a UPI Port : Non-Coherent Standard, Match Opcode)",
      R"(Matches on Receive path of a UPI Port : Non-Coherent Standard, Match Opcode)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_L1_POWER_CYCLES",
      EventDef::Encoding{.code = 0x21, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Cycles in L1 : Number of UPI qfclk cycles spent in L1 power mode.  L1 is a mode that totally shuts down a UPI link.  Use edge detect to count the number of instances when the UPI link entered L1.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another. Because L1 totally shuts down the link, it takes a good amount of time to exit this mode.)",
      R"(Cycles in L1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL0P_POWER_CYCLES",
      EventDef::Encoding{.code = 0x27, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Cycles in L0p)",
      R"(Cycles in L0p)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL0P_POWER_CYCLES_LL_ENTER",
      EventDef::Encoding{.code = 0x28, .umask = 0x00, .umaskExt = 0x00000000},
      R"(UNC_UPI_TxL0P_POWER_CYCLES_LL_ENTER)",
      R"(UNC_UPI_TxL0P_POWER_CYCLES_LL_ENTER)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL0P_POWER_CYCLES_M3_EXIT",
      EventDef::Encoding{.code = 0x29, .umask = 0x00, .umaskExt = 0x00000000},
      R"(UNC_UPI_TxL0P_POWER_CYCLES_M3_EXIT)",
      R"(UNC_UPI_TxL0P_POWER_CYCLES_M3_EXIT)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_FREQ_MAX_LIMIT_THERMAL_CYCLES",
      EventDef::Encoding{.code = 0x04, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Thermal Strongest Upper Limit Cycles)",
      R"(Thermal Strongest Upper Limit Cycles : Number of cycles any frequency is reduced due to a thermal limit.  Count only if throttling is occurring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_FREQ_MAX_POWER_CYCLES",
      EventDef::Encoding{.code = 0x05, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Power Strongest Upper Limit Cycles)",
      R"(Power Strongest Upper Limit Cycles : Counts the number of cycles when power is the upper limit on frequency.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_FREQ_TRANS_CYCLES",
      EventDef::Encoding{.code = 0x74, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Cycles spent changing Frequency)",
      R"(Cycles spent changing Frequency : Counts the number of cycles when the system is changing frequency.  This can not be filtered by thread ID.  One can also use it with the occupancy counter that monitors number of threads in C0 to estimate the performance impact that frequency transitions had on the system.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PKG_RESIDENCY_C2E_CYCLES",
      EventDef::Encoding{.code = 0x2b, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Package C State Residency - C2E)",
      R"(Package C State Residency - C2E : Counts the number of cycles when the package was in C2E.  This event can be used in conjunction with edge detect to count C2E entrances (or exits using invert).  Residency events do not include transition times.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PKG_RESIDENCY_C6_CYCLES",
      EventDef::Encoding{.code = 0x2d, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Package C State Residency - C6)",
      R"(Package C State Residency - C6 : Counts the number of cycles when the package was in C6.  This event can be used in conjunction with edge detect to count C6 entrances (or exits using invert).  Residency events do not include transition times.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_POWER_STATE_OCCUPANCY_CORES_C3",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Number of cores in C3)",
      R"(Number of cores in C3 : This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PROCHOT_EXTERNAL_CYCLES",
      EventDef::Encoding{.code = 0x0a, .umask = 0x00, .umaskExt = 0x00000000},
      R"(External Prochot)",
      R"(External Prochot : Counts the number of cycles that we are in external PROCHOT mode.  This mode is triggered when a sensor off the die determines that something off-die (like DRAM) is too hot and must throttle to avoid damaging the chip.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PROCHOT_INTERNAL_CYCLES",
      EventDef::Encoding{.code = 0x09, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Internal Prochot)",
      R"(Internal Prochot : Counts the number of cycles that we are in Internal PROCHOT mode.  This mode is triggered when a sensor on the die determines that we are too hot and must throttle to avoid damaging the chip.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART0",
      EventDef::Encoding{.code = 0xD5, .umask = 0x01, .umaskExt = 0x00070010},
      R"(Count of allocations in the completion buffer)",
      R"(Count of allocations in the completion buffer)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART1",
      EventDef::Encoding{.code = 0xD5, .umask = 0x02, .umaskExt = 0x00070020},
      R"(Count of allocations in the completion buffer)",
      R"(Count of allocations in the completion buffer)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART2",
      EventDef::Encoding{.code = 0xD5, .umask = 0x04, .umaskExt = 0x00070040},
      R"(Count of allocations in the completion buffer)",
      R"(Count of allocations in the completion buffer)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART3",
      EventDef::Encoding{.code = 0xD5, .umask = 0x08, .umaskExt = 0x00070080},
      R"(Count of allocations in the completion buffer)",
      R"(Count of allocations in the completion buffer)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART4",
      EventDef::Encoding{.code = 0xD5, .umask = 0x10, .umaskExt = 0x00070100},
      R"(Count of allocations in the completion buffer)",
      R"(Count of allocations in the completion buffer)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART5",
      EventDef::Encoding{.code = 0xD5, .umask = 0x20, .umaskExt = 0x00070200},
      R"(Count of allocations in the completion buffer)",
      R"(Count of allocations in the completion buffer)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART6",
      EventDef::Encoding{.code = 0xD5, .umask = 0x40, .umaskExt = 0x00070400},
      R"(Count of allocations in the completion buffer)",
      R"(Count of allocations in the completion buffer)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART7",
      EventDef::Encoding{.code = 0xD5, .umask = 0x80, .umaskExt = 0x00070800},
      R"(Count of allocations in the completion buffer)",
      R"(Count of allocations in the completion buffer)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.ALL_PARTS",
      EventDef::Encoding{.code = 0xD5, .umask = 0xFF, .umaskExt = 0x00070FF0},
      R"(Count of allocations in the completion buffer)",
      R"(Count of allocations in the completion buffer)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_INSERTS.SLOT0",
      EventDef::Encoding{.code = 0x30, .umask = 0x01, .umaskExt = 0x00000000},
      R"(RxQ Flit Buffer Allocations : Slot 0 : Number of allocations into the UPI Rx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.)",
      R"(RxQ Flit Buffer Allocations : Slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_INSERTS.SLOT1",
      EventDef::Encoding{.code = 0x30, .umask = 0x02, .umaskExt = 0x00000000},
      R"(RxQ Flit Buffer Allocations : Slot 1 : Number of allocations into the UPI Rx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.)",
      R"(RxQ Flit Buffer Allocations : Slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_INSERTS.SLOT2",
      EventDef::Encoding{.code = 0x30, .umask = 0x04, .umaskExt = 0x00000000},
      R"(RxQ Flit Buffer Allocations : Slot 2 : Number of allocations into the UPI Rx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.)",
      R"(RxQ Flit Buffer Allocations : Slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_OCCUPANCY.SLOT0",
      EventDef::Encoding{.code = 0x32, .umask = 0x01, .umaskExt = 0x00000000},
      R"(RxQ Occupancy - All Packets : Slot 0)",
      R"(RxQ Occupancy - All Packets : Slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_OCCUPANCY.SLOT1",
      EventDef::Encoding{.code = 0x32, .umask = 0x02, .umaskExt = 0x00000000},
      R"(RxQ Occupancy - All Packets : Slot 1)",
      R"(RxQ Occupancy - All Packets : Slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_OCCUPANCY.SLOT2",
      EventDef::Encoding{.code = 0x32, .umask = 0x04, .umaskExt = 0x00000000},
      R"(RxQ Occupancy - All Packets : Slot 2)",
      R"(RxQ Occupancy - All Packets : Slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_INSERTS",
      EventDef::Encoding{.code = 0x40, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Tx Flit Buffer Allocations : Number of allocations into the UPI Tx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used with L0p and when LLR occurs, increasing latency to transfer out to the link.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.)",
      R"(Tx Flit Buffer Allocations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_OCCUPANCY",
      EventDef::Encoding{.code = 0x42, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Tx Flit Buffer Occupancy : Accumulates the number of flits in the TxQ.  Generally, when data is transmitted across UPI, it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used with L0p and when LLR occurs, increasing latency to transfer out to the link. This can be used with the cycles not empty event to track average occupancy, or the allocations event to track average lifetime in the TxQ.)",
      R"(Tx Flit Buffer Occupancy)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .umaskExt = 0x00070020},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .umaskExt = 0x00070020},
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .umaskExt = 0x00070040},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .umaskExt = 0x00070040},
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .umaskExt = 0x00070080},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .umaskExt = 0x00070080},
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .umaskExt = 0x00070100},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .umaskExt = 0x00070100},
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART5",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .umaskExt = 0x00070200},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART5",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .umaskExt = 0x00070200},
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .umaskExt = 0x00070400},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .umaskExt = 0x00070400},
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART7",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .umaskExt = 0x00070800},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART7",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .umaskExt = 0x00070800},
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Data requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.ALL_PARTS",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .umaskExt = 0x00070FF0},
      R"(Counts once for every 4 bytes written from this card to a peer device's IO space.)",
      R"(Counts once for every 4 bytes written from this card to a peer device's IO space.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .umaskExt = 0x00070020},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .umaskExt = 0x00070020},
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .umaskExt = 0x00070040},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .umaskExt = 0x00070040},
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .umaskExt = 0x00070080},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .umaskExt = 0x00070080},
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART4",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .umaskExt = 0x00070100},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART4",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .umaskExt = 0x00070100},
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART5",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .umaskExt = 0x00070200},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART5",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .umaskExt = 0x00070200},
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART6",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .umaskExt = 0x00070400},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART6",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .umaskExt = 0x00070400},
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART7",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .umaskExt = 0x00070800},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART7",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .umaskExt = 0x00070800},
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card reading from another Card (same or different stack))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .umaskExt = 0x00070020},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART2",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .umaskExt = 0x00070040},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .umaskExt = 0x00070080},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART4",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .umaskExt = 0x00070100},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART5",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .umaskExt = 0x00070200},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART6",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .umaskExt = 0x00070400},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART7",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .umaskExt = 0x00070800},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.IOMMU_REQ",
      EventDef::Encoding{.code = 0x88, .umask = 0x01, .umaskExt = 0x000700F0},
      R"(Issuing to IOMMU)",
      R"(Issuing to IOMMU)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.IOMMU_HIT",
      EventDef::Encoding{.code = 0x88, .umask = 0x02, .umaskExt = 0x000700F0},
      R"(Processing response from IOMMU)",
      R"(Processing response from IOMMU)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.REQ_OWN",
      EventDef::Encoding{.code = 0x88, .umask = 0x04, .umaskExt = 0x000700F0},
      R"(Request Ownership)",
      R"(Request Ownership)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.FINAL_RD_WR",
      EventDef::Encoding{.code = 0x88, .umask = 0x08, .umaskExt = 0x000700F0},
      R"(Issuing final read or write of line)",
      R"(Issuing final read or write of line)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.WR",
      EventDef::Encoding{.code = 0x88, .umask = 0x10, .umaskExt = 0x000700F0},
      R"(Writing line)",
      R"(Writing line)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_OUTSTANDING_REQ_OF_CPU.DATA",
      EventDef::Encoding{.code = 0x88, .umask = 0x20, .umaskExt = 0x000700F0},
      R"(Passing data to be written)",
      R"(Passing data to be written)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.FIRST_LOOKUPS",
      EventDef::Encoding{.code = 0x40, .umask = 0x01, .umaskExt = 0x00000000},
      R"(IOTLB lookups first)",
      R"(IOTLB lookups first)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.ALL_LOOKUPS",
      EventDef::Encoding{.code = 0x40, .umask = 0x02, .umaskExt = 0x00000000},
      R"(IOTLB lookups all)",
      R"(IOTLB lookups all)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.MISSES",
      EventDef::Encoding{.code = 0x40, .umask = 0x20, .umaskExt = 0x00000000},
      R"(IOTLB Fills (same as IOTLB miss))",
      R"(IOTLB Fills (same as IOTLB miss))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.SLPWC_CACHE_LOOKUPS",
      EventDef::Encoding{.code = 0x41, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Second Level Page Walk Cache lookup)",
      R"(Second Level Page Walk Cache lookup)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.SLPWC_2M_HITS",
      EventDef::Encoding{.code = 0x41, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Second Level Page Walk Cache Hit to a 2M page)",
      R"(Second Level Page Walk Cache Hit to a 2M page)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.SLPWC_1G_HITS",
      EventDef::Encoding{.code = 0x41, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Second Level Page Walk Cache Hit to a 1G page)",
      R"(Second Level Page Walk Cache Hit to a 1G page)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.SLPWC_512G_HITS",
      EventDef::Encoding{.code = 0x41, .umask = 0x08, .umaskExt = 0x00000000},
      R"(Second Level Page Walk Cache Hit to a 512G page)",
      R"(Second Level Page Walk Cache Hit to a 512G page)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.SLPWC_256T_HITS",
      EventDef::Encoding{.code = 0x41, .umask = 0x10, .umaskExt = 0x00000000},
      R"(Second Level Page Walk Cache Hit to a 256T page)",
      R"(Second Level Page Walk Cache Hit to a 256T page)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.SLPWC_CACHE_FILLS",
      EventDef::Encoding{.code = 0x41, .umask = 0x20, .umaskExt = 0x00000000},
      R"(Second Level Page Walk Cache fill)",
      R"(Second Level Page Walk Cache fill)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.NUM_MEM_ACCESSES_LOW",
      EventDef::Encoding{.code = 0x41, .umask = 0x40, .umaskExt = 0x00000000},
      R"(IOMMU low priority memory access)",
      R"(IOMMU low priority memory access)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.NUM_MEM_ACCESSES_HIGH",
      EventDef::Encoding{.code = 0x41, .umask = 0x80, .umaskExt = 0x00000000},
      R"(IOMMU high priority memory access)",
      R"(IOMMU high priority memory access)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU3.CYC_PWT_FULL",
      EventDef::Encoding{.code = 0x43, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Cycles PWT full)",
      R"(Cycles PWT full)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU3.NUM_INVAL_IOTLB",
      EventDef::Encoding{.code = 0x43, .umask = 0x04, .umaskExt = 0x00000000},
      R"(IOTLB invalidation events)",
      R"(IOTLB invalidation events)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU3.NUM_INVAL_CTXT_CACHE",
      EventDef::Encoding{.code = 0x43, .umask = 0x08, .umaskExt = 0x00000000},
      R"(Context Cache invalidation events)",
      R"(Context Cache invalidation events)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU3.NUM_INVAL_PASID_CACHE",
      EventDef::Encoding{.code = 0x43, .umask = 0x10, .umaskExt = 0x00000000},
      R"(PASID Cache invalidation events)",
      R"(PASID Cache invalidation events)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU3.NUM_INVAL_INT_CACHE",
      EventDef::Encoding{.code = 0x43, .umask = 0x20, .umaskExt = 0x00000000},
      R"(Interrupt Entry Cache invalidation events)",
      R"(Interrupt Entry Cache invalidation events)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU3.INT_CACHE_LOOKUPS",
      EventDef::Encoding{.code = 0x43, .umask = 0x40, .umaskExt = 0x00000000},
      R"(Interrupt Entry cache lookup)",
      R"(Interrupt Entry cache lookup)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU3.INT_CACHE_HITS",
      EventDef::Encoding{.code = 0x43, .umask = 0x80, .umaskExt = 0x00000000},
      R"(Interrupt Entry cache hit)",
      R"(Interrupt Entry cache hit)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.LOCAL_M",
      EventDef::Encoding{.code = 0x37, .umask = 0x01, .umaskExt = 0x00000020},
      R"(Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Local - Lines in M State)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.LOCAL_E",
      EventDef::Encoding{.code = 0x37, .umask = 0x02, .umaskExt = 0x00000020},
      R"(Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Local - Lines in E State)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.LOCAL_S",
      EventDef::Encoding{.code = 0x37, .umask = 0x04, .umaskExt = 0x00000020},
      R"(Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Local - Lines in S State)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.LOCAL_F",
      EventDef::Encoding{.code = 0x37, .umask = 0x08, .umaskExt = 0x00000020},
      R"(Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Local - Lines in F State)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.REMOTE_M",
      EventDef::Encoding{.code = 0x37, .umask = 0x01, .umaskExt = 0x00000080},
      R"(Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Remote - Lines in M State)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.REMOTE_E",
      EventDef::Encoding{.code = 0x37, .umask = 0x02, .umaskExt = 0x00000080},
      R"(Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Remote - Lines in E State)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.REMOTE_S",
      EventDef::Encoding{.code = 0x37, .umask = 0x04, .umaskExt = 0x00000080},
      R"(Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      R"(Lines Victimized : Remote - Lines in S State)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWERDOWN_CYCLES.SCH0_RANK0",
      EventDef::Encoding{.code = 0x47, .umask = 0x01, .umaskExt = 0x00000000},
      R"(# of cycles a given rank is in Power Down Mode)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWERDOWN_CYCLES.SCH0_RANK1",
      EventDef::Encoding{.code = 0x47, .umask = 0x02, .umaskExt = 0x00000000},
      R"(# of cycles a given rank is in Power Down Mode)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWERDOWN_CYCLES.SCH0_RANK2",
      EventDef::Encoding{.code = 0x47, .umask = 0x04, .umaskExt = 0x00000000},
      R"(# of cycles a given rank is in Power Down Mode)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWERDOWN_CYCLES.SCH0_RANK3",
      EventDef::Encoding{.code = 0x47, .umask = 0x08, .umaskExt = 0x00000000},
      R"(# of cycles a given rank is in Power Down Mode)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWERDOWN_CYCLES.SCH1_RANK0",
      EventDef::Encoding{.code = 0x47, .umask = 0x10, .umaskExt = 0x00000000},
      R"(# of cycles a given rank is in Power Down Mode)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWERDOWN_CYCLES.SCH1_RANK1",
      EventDef::Encoding{.code = 0x47, .umask = 0x20, .umaskExt = 0x00000000},
      R"(# of cycles a given rank is in Power Down Mode)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWERDOWN_CYCLES.SCH1_RANK2",
      EventDef::Encoding{.code = 0x47, .umask = 0x40, .umaskExt = 0x00000000},
      R"(# of cycles a given rank is in Power Down Mode)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWERDOWN_CYCLES.SCH1_RANK3",
      EventDef::Encoding{.code = 0x47, .umask = 0x80, .umaskExt = 0x00000000},
      R"(# of cycles a given rank is in Power Down Mode)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CHANNEL_PPD_CYCLES",
      EventDef::Encoding{.code = 0x88, .umask = 0x00, .umaskExt = 0x00000000},
      R"(# of cycles a given rank is in Power Down Mode and all pages are closed)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_SELF_REFRESH.ENTER_SUCCESS_CYCLES",
      EventDef::Encoding{.code = 0x43, .umask = 0x01, .umaskExt = 0x00000000},
      R"(# of cycles all ranks were in SR)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_PWT_OCCUPANCY",
      EventDef::Encoding{.code = 0x42, .umask = 0x00, .umaskExt = 0x00000000},
      R"(All 9 bits of Page Walk Tracker Occupancy)",
      R"(All 9 bits of Page Walk Tracker Occupancy)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.MSGB",
      EventDef::Encoding{.code = 0x8e, .umask = 0x01, .umaskExt = 0x00070FF0},
      R"(-)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.MCAST",
      EventDef::Encoding{.code = 0x8e, .umask = 0x02, .umaskExt = 0x00070FF0},
      R"(-)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.UBOX",
      EventDef::Encoding{.code = 0x8e, .umask = 0x04, .umaskExt = 0x00070FF0},
      R"(-)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.MEM",
      EventDef::Encoding{.code = 0x8e, .umask = 0x08, .umaskExt = 0x00070FF0},
      R"(-)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.REM_P2P",
      EventDef::Encoding{.code = 0x8e, .umask = 0x10, .umaskExt = 0x00070FF0},
      R"(-)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.LOC_P2P",
      EventDef::Encoding{.code = 0x8e, .umask = 0x20, .umaskExt = 0x00070FF0},
      R"(-)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.CONFINED_P2P",
      EventDef::Encoding{.code = 0x8e, .umask = 0x40, .umaskExt = 0x00070FF0},
      R"(-)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_REQ_OF_CPU_BY_TGT.ABORT",
      EventDef::Encoding{.code = 0x8e, .umask = 0x80, .umaskExt = 0x00070FF0},
      R"(-)",
      R"(-)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_OUSTANDING_REQ_FROM_CPU.TO_IO",
      EventDef::Encoding{.code = 0xc5, .umask = 0x08, .umaskExt = 0x00070FF0},
      R"(Occupancy of outbound request queue : To device : Counts number of outbound requests/completions IIO is currently processing)",
      R"(Occupancy of outbound request queue : To device : Counts number of outbound requests/completions IIO is currently processing)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.HIT_SHARED",
      EventDef::Encoding{.code = 0x69, .umask = 0x01, .umaskExt = 0x00000000},
      R"(UNC_CHA_REMOTE_SF.HIT_SHARED)",
      R"(UNC_CHA_REMOTE_SF.HIT_SHARED)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.HIT_EXCLUSIVE",
      EventDef::Encoding{.code = 0x69, .umask = 0x02, .umaskExt = 0x00000000},
      R"(UNC_CHA_REMOTE_SF.HIT_EXCLUSIVE)",
      R"(UNC_CHA_REMOTE_SF.HIT_EXCLUSIVE)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.ALLOC_SHARED",
      EventDef::Encoding{.code = 0x69, .umask = 0x08, .umaskExt = 0x00000000},
      R"(UNC_CHA_REMOTE_SF.ALLOC_SHARED)",
      R"(UNC_CHA_REMOTE_SF.ALLOC_SHARED)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.ALLOC_EXCLUSIVE",
      EventDef::Encoding{.code = 0x69, .umask = 0x10, .umaskExt = 0x00000000},
      R"(UNC_CHA_REMOTE_SF.ALLOC_EXCLUSIVE)",
      R"(UNC_CHA_REMOTE_SF.ALLOC_EXCLUSIVE)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.DEALLOC_EVCTCLN",
      EventDef::Encoding{.code = 0x69, .umask = 0x40, .umaskExt = 0x00000000},
      R"(UNC_CHA_REMOTE_SF.DEALLOC_EVCTCLN)",
      R"(UNC_CHA_REMOTE_SF.DEALLOC_EVCTCLN)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.UPDATE_SHARED",
      EventDef::Encoding{.code = 0x69, .umask = 0x80, .umaskExt = 0x00000000},
      R"(UNC_CHA_REMOTE_SF.UPDATE_SHARED)",
      R"(UNC_CHA_REMOTE_SF.UPDATE_SHARED)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.UPDATE_EXCLUSIVE",
      EventDef::Encoding{.code = 0x69, .umask = 0x00, .umaskExt = 0x00000001},
      R"(UNC_CHA_REMOTE_SF.UPDATE_EXCLUSIVE)",
      R"(UNC_CHA_REMOTE_SF.UPDATE_EXCLUSIVE)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.VICTIM_SHARED",
      EventDef::Encoding{.code = 0x69, .umask = 0x00, .umaskExt = 0x00000002},
      R"(UNC_CHA_REMOTE_SF.VICTIM_SHARED)",
      R"(UNC_CHA_REMOTE_SF.VICTIM_SHARED)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.VICTIM_EXCLUSIVE",
      EventDef::Encoding{.code = 0x69, .umask = 0x00, .umaskExt = 0x00000004},
      R"(UNC_CHA_REMOTE_SF.VICTIM_EXCLUSIVE)",
      R"(UNC_CHA_REMOTE_SF.VICTIM_EXCLUSIVE)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.INCLUSIVE_ONLY",
      EventDef::Encoding{.code = 0x69, .umask = 0x00, .umaskExt = 0x00000020},
      R"(UNC_CHA_REMOTE_SF.INCLUSIVE_ONLY)",
      R"(UNC_CHA_REMOTE_SF.INCLUSIVE_ONLY)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.DIRBACKED_ONLY",
      EventDef::Encoding{.code = 0x69, .umask = 0x00, .umaskExt = 0x00000040},
      R"(UNC_CHA_REMOTE_SF.DIRBACKED_ONLY)",
      R"(UNC_CHA_REMOTE_SF.DIRBACKED_ONLY)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.RSPI",
      EventDef::Encoding{.code = 0x04, .umask = 0x2a, .umaskExt = 0x00000001},
      R"(Matches on Transmit path of a UPI Port : Response - Invalid)",
      R"(Matches on Transmit path of a UPI Port : Response - Invalid)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.RSPCNFLT",
      EventDef::Encoding{.code = 0x04, .umask = 0xaa, .umaskExt = 0x00000001},
      R"(Matches on Transmit path of a UPI Port : Response - Conflict)",
      R"(Matches on Transmit path of a UPI Port : Response - Conflict)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.RSPI",
      EventDef::Encoding{.code = 0x05, .umask = 0x2a, .umaskExt = 0x00000001},
      R"(Matches on Receive path of a UPI Port : Response - Invalid)",
      R"(Matches on Receive path of a UPI Port : Response - Invalid)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.RSPCNFLT",
      EventDef::Encoding{.code = 0x05, .umask = 0xaa, .umaskExt = 0x00000001},
      R"(Matches on Receive path of a UPI Port : Response - Conflict)",
      R"(Matches on Receive path of a UPI Port : Response - Conflict)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_SELF_REFRESH.ENTER_SUCCESS",
      EventDef::Encoding{.code = 0x43, .umask = 0x02, .umaskExt = 0x00000000},
      R"(subevent0 - # of cycles all ranks were in SR subevent1 - # of times all ranks went into SR subevent2 -# of times  ps_sr_active asserted (SRE) subevent3 - # of times ps_sr_active deasserted (SRX) subevent4 - # of times PS-&>Refresh ps_sr_req asserted (SRE) subevent5 - # of times PS-&>Refresh ps_sr_req deasserted (SRX) subevent6 - # of cycles PSCtrlr FSM was in FATAL)",
      R"(UNC_M_SELF_REFRESH.ENTER_SUCCESS)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_PCIRDCUR_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C8F37E},
      R"(TOR Occupancy for PCIRDCUR transactions from an IO device on a remote socket that miss the cache)",
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_PCIRDCUR_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C8F2FE},
      R"(TOR Occupancy for PCIRDCUR transactions from an IO device on the local socket that miss the cache)",
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOM_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00CC437E},
      R"(TOR Occupancy for ItoM transactions from an IO device on a remote socket that miss the cache)",
      R"(TOR Occupancy : ItoMs issued by IO Devices that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOM_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00CC42FE},
      R"(TOR Occupancy for ItoM transactions from an IO device on the local socket that miss the cache)",
      R"(TOR Occupancy : ItoMs issued by IO Devices that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOMCACHENEAR_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00CD437E},
      R"(TOR Occupancy for ItoMCacheNear transactions from an IO device on a remote socket that miss the cache)",
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOMCACHENEAR_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00CD42FE},
      R"(TOR Occupancy for ItoMCacheNear transactions from an IO device on the local socket that miss the cache)",
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace sierraforest_uncore_experimental
} // namespace facebook::hbt::perf_event::generated
