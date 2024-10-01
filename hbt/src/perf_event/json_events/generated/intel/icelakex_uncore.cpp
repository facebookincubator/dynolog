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
namespace icelakex_uncore {

void addEvents(PmuDeviceManager& pmu_manager) {
/*
  Events from icelakex_uncore.json (269 events).

  Supported SKUs:
      - Arch: x86, Model: ICX id: 106
      - Arch: x86, Model: ICX id: 108
*/
#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_UPDATE.HA",
      EventDef::Encoding{.code = 0x54, .umask = 0x01, .umaskExt = 0x00},
      R"(Multi-socket cacheline directory state updates; memory write due to directory update from the home agent (HA) pipe)",
      R"(Counts only multi-socket cacheline directory state updates memory writes issued from the home agent (HA) pipe. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.)",
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
      EventDef::Encoding{.code = 0x54, .umask = 0x02, .umaskExt = 0x00},
      R"(Multi-socket cacheline directory state updates; memory write due to directory update from (table of requests) TOR pipe)",
      R"(Counts only multi-socket cacheline directory state updates due to memory writes issued from the table of requests (TOR) pipe which are the result of remote transaction hitting the SF/LLC and returning data Core2Core. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.INVITOE_LOCAL",
      EventDef::Encoding{.code = 0x50, .umask = 0x10, .umaskExt = 0x00},
      R"(Local INVITOE requests (exclusive ownership of a cache line without receiving data) that miss the SF/LLC and are sent to the CHA's home agent)",
      R"(Counts the total number of requests coming from a unit on this socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.INVITOE_REMOTE",
      EventDef::Encoding{.code = 0x50, .umask = 0x20, .umaskExt = 0x00},
      R"(Remote INVITOE requests (exclusive ownership of a cache line without receiving data) sent to the CHA's home agent)",
      R"(Counts the total number of requests coming from a remote socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event UNC_CHA_REQUESTS.READS_LOCAL is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.READS_LOCAL",
      EventDef::Encoding{.code = 0x50, .umask = 0x01, .umaskExt = 0x00},
      R"(Local read requests that miss the SF/LLC and are sent to the CHA's home agent)",
      R"(Counts read requests coming from a unit on this socket made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_CHA_REQUESTS.READS_REMOTE is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.READS_REMOTE",
      EventDef::Encoding{.code = 0x50, .umask = 0x02, .umaskExt = 0x00},
      R"(Remote read requests sent to the CHA's home agent)",
      R"(Counts read requests coming from a remote socket made into the CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_CHA_REQUESTS.WRITES_LOCAL is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.WRITES_LOCAL",
      EventDef::Encoding{.code = 0x50, .umask = 0x04, .umaskExt = 0x00},
      R"(Local write requests that miss the SF/LLC and are sent to the CHA's home agent)",
      R"(Counts  write requests coming from a unit on this socket made into this CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_CHA_REQUESTS.WRITES_REMOTE is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.WRITES_REMOTE",
      EventDef::Encoding{.code = 0x50, .umask = 0x08, .umaskExt = 0x00},
      R"(Remote write requests sent to the CHA's home agent)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_CHA_CLOCKTICKS is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .umaskExt = 0x00},
      R"(Clockticks of the uncore caching and home agent (CHA))",
      R"(Clockticks of the uncore caching and home agent (CHA))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_IMC_READS_COUNT.NORMAL",
      EventDef::Encoding{.code = 0x59, .umask = 0x01, .umaskExt = 0x00},
      R"(Normal priority reads issued to the memory controller from the CHA)",
      R"(Counts when a normal (Non-Isochronous) read is issued to any of the memory controller channels from the CHA.)",
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
      EventDef::Encoding{.code = 0x5B, .umask = 0x01, .umaskExt = 0x00},
      R"(CHA to iMC Full Line Writes Issued : Full Line Non-ISOCH)",
      R"(Counts when a normal (Non-Isochronous) full line write is issued from the CHA to any of the memory controller channels.)",
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
      EventDef::Encoding{.code = 0x37, .umask = 0x0F, .umaskExt = 0x00},
      R"(Lines Victimized : All Lines Victimized)",
      R"(Lines Victimized : All Lines Victimized : Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.READS",
      EventDef::Encoding{.code = 0x50, .umask = 0x03, .umaskExt = 0x00},
      R"(Local read requests that miss the SF/LLC and remote read requests sent to the CHA's home agent)",
      R"(Counts read requests made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write) .)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.WRITES",
      EventDef::Encoding{.code = 0x50, .umask = 0x0c, .umaskExt = 0x00},
      R"(Local write requests that miss the SF/LLC and remote write requests sent to the CHA's home agent)",
      R"(Counts write requests made into the CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SF_EVICTION.E_STATE",
      EventDef::Encoding{.code = 0x3D, .umask = 0x02, .umaskExt = 0x00},
      R"(Snoop filter capacity evictions for E-state entries.)",
      R"(Counts snoop filter capacity evictions for entries tracking exclusive lines in the cores? cache.? Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry.? Does not count clean evictions such as when a core?s cache replaces a tracked cacheline with a new cacheline.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SF_EVICTION.M_STATE",
      EventDef::Encoding{.code = 0x3D, .umask = 0x01, .umaskExt = 0x00},
      R"(Snoop filter capacity evictions for M-state entries.)",
      R"(Counts snoop filter capacity evictions for entries tracking modified lines in the cores? cache.? Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry.? Does not count clean evictions such as when a core?s cache replaces a tracked cacheline with a new cacheline.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SF_EVICTION.S_STATE",
      EventDef::Encoding{.code = 0x3D, .umask = 0x04, .umaskExt = 0x00},
      R"(Snoop filter capacity evictions for S-state entries.)",
      R"(Counts snoop filter capacity evictions for entries tracking shared lines in the cores? cache.? Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry.? Does not count clean evictions such as when a core?s cache replaces a tracked cacheline with a new cacheline.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC001FF},
      R"(TOR Inserts : All requests from iA Cores)",
      R"(TOR Inserts : All requests from iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC001FD},
      R"(TOR Inserts : All requests from iA Cores that Hit the LLC)",
      R"(TOR Inserts : All requests from iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_CRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC80FFD},
      R"(TOR Inserts : CRds issued by iA Cores that Hit the LLC)",
      R"(TOR Inserts : CRds issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_DRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC817FD},
      R"(TOR Inserts : DRds issued by iA Cores that Hit the LLC)",
      R"(TOR Inserts : DRds issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_LLCPREFRFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xCCC7FD},
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores that hit the LLC)",
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC807FD},
      R"(TOR Inserts : RFOs issued by iA Cores that Hit the LLC)",
      R"(TOR Inserts : RFOs issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC001FE},
      R"(TOR Inserts : All requests from iA Cores that Missed the LLC)",
      R"(TOR Inserts : All requests from iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC80FFE},
      R"(TOR Inserts : CRds issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : CRds issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC817FE},
      R"(TOR Inserts : DRds issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : DRds issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFRFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xCCC7FE},
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores that missed the LLC)",
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC807FE},
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xC001FF},
      R"(TOR Inserts : All requests from IO Devices)",
      R"(TOR Inserts : All requests from IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xC001FD},
      R"(TOR Inserts : All requests from IO Devices that hit the LLC)",
      R"(TOR Inserts : All requests from IO Devices that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xC001FE},
      R"(TOR Inserts : All requests from IO Devices that missed the LLC)",
      R"(TOR Inserts : All requests from IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC001FF},
      R"(TOR Occupancy : All requests from iA Cores)",
      R"(TOR Occupancy : All requests from iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC001FD},
      R"(TOR Occupancy : All requests from iA Cores that Hit the LLC)",
      R"(TOR Occupancy : All requests from iA Cores that Hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC001FE},
      R"(TOR Occupancy : All requests from iA Cores that Missed the LLC)",
      R"(TOR Occupancy : All requests from iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC80FFE},
      R"(TOR Occupancy : CRds issued by iA Cores that Missed the LLC)",
      R"(TOR Occupancy : CRds issued by iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC817FE},
      R"(TOR Occupancy : DRds issued by iA Cores that Missed the LLC)",
      R"(TOR Occupancy : DRds issued by iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC807FE},
      R"(TOR Occupancy : RFOs issued by iA Cores that Missed the LLC)",
      R"(TOR Occupancy : RFOs issued by iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0xC001FF},
      R"(TOR Occupancy : All requests from IO Devices)",
      R"(TOR Occupancy : All requests from IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0xC001FD},
      R"(TOR Occupancy : All requests from IO Devices that hit the LLC)",
      R"(TOR Occupancy : All requests from IO Devices that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0xC001FE},
      R"(TOR Occupancy : All requests from IO Devices that missed the LLC)",
      R"(TOR Occupancy : All requests from IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_MISS_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xCC43FE},
      R"(TOR Inserts : ItoMs issued by IO Devices that missed the LLC)",
      R"(TOR Inserts : ItoMs issued by IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00},
      R"(Clockticks of the integrated IO (IIO) traffic controller)",
      R"(Clockticks of the integrated IO (IIO) traffic controller : Increments counter once every Traffic Controller clock, the LSCLK (500MHz))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core writing to Card's MMIO space)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core writing to Card's MMIO space)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core writing to Card's MMIO space)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core writing to Card's MMIO space)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART2",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
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
      EventDef::Encoding{.code = 0x1F, .umask = 0x10, .umaskExt = 0x00},
      R"(Misc Events - Set 1 : Lost Forward)",
      R"(Misc Events - Set 1 : Lost Forward : Snoop pulled away ownership before a write was committed)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.PCITOM",
      EventDef::Encoding{.code = 0x10, .umask = 0x10, .umaskExt = 0x00},
      R"(PCIITOM request issued by the IRP unit to the mesh with the intention of writing a full cacheline.)",
      R"(PCIITOM request issued by the IRP unit to the mesh with the intention of writing a full cacheline to coherent memory, without a RFO.  PCIITOM is a speculative Invalidate to Modified command that requests ownership of the cacheline and does not move data from the mesh to IRP cache.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.WBMTOI",
      EventDef::Encoding{.code = 0x10, .umask = 0x40, .umaskExt = 0x00},
      R"(Coherent Ops : WbMtoI)",
      R"(Coherent Ops : WbMtoI : Counts the number of coherency related operations serviced by the IRP)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_TAGCHK.HIT",
      EventDef::Encoding{.code = 0xD3, .umask = 0x01, .umaskExt = 0x00},
      R"(2LM Tag Check : Hit in Near Memory Cache)",
      R"(2LM Tag Check : Hit in Near Memory Cache)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_TAGCHK.MISS_CLEAN",
      EventDef::Encoding{.code = 0xD3, .umask = 0x02, .umaskExt = 0x00},
      R"(2LM Tag Check : Miss, no data in this line)",
      R"(2LM Tag Check : Miss, no data in this line)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_TAGCHK.MISS_DIRTY",
      EventDef::Encoding{.code = 0xD3, .umask = 0x04, .umaskExt = 0x00},
      R"(2LM Tag Check : Miss, existing data may be evicted to Far Memory)",
      R"(2LM Tag Check : Miss, existing data may be evicted to Far Memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_TAGCHK.NM_RD_HIT",
      EventDef::Encoding{.code = 0xD3, .umask = 0x08, .umaskExt = 0x00},
      R"(2LM Tag Check : Read Hit in Near Memory Cache)",
      R"(2LM Tag Check : Read Hit in Near Memory Cache)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_TAGCHK.NM_WR_HIT",
      EventDef::Encoding{.code = 0xD3, .umask = 0x10, .umaskExt = 0x00},
      R"(2LM Tag Check : Write Hit in Near Memory Cache)",
      R"(2LM Tag Check : Write Hit in Near Memory Cache)",
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
      EventDef::Encoding{.code = 0x02, .umask = 0x04, .umaskExt = 0x00},
      R"(DRAM Precharge commands. : Precharge due to read)",
      R"(DRAM Precharge commands. : Precharge due to read : Counts the number of DRAM Precharge commands sent on this channel. : Precharge from read bank scheduler)",
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
      EventDef::Encoding{.code = 0x02, .umask = 0x08, .umaskExt = 0x00},
      R"(DRAM Precharge commands. : Precharge due to write)",
      R"(DRAM Precharge commands. : Precharge due to write : Counts the number of DRAM Precharge commands sent on this channel. : Precharge from write bank scheduler)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event UNC_M_CAS_COUNT.RD is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD",
      EventDef::Encoding{.code = 0x04, .umask = 0x0f, .umaskExt = 0x00},
      R"(All DRAM read CAS commands issued (including underfills))",
      R"(Counts the total number of DRAM Read CAS commands, w/ and w/o auto-pre, issued on this channel.  This includes underfills.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_M_CAS_COUNT.WR is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR",
      EventDef::Encoding{.code = 0x04, .umask = 0x30, .umaskExt = 0x00},
      R"(All DRAM write CAS commands issued)",
      R"(Counts the total number of DRAM Write CAS commands issued, w/ and w/o auto-pre, on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.ALL",
      EventDef::Encoding{.code = 0x04, .umask = 0x3f, .umaskExt = 0x00},
      R"(All DRAM CAS commands issued)",
      R"(Counts the total number of DRAM CAS commands issued on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.ANY",
      EventDef::Encoding{.code = 0x2D, .umask = 0x01, .umaskExt = 0x00},
      R"(Multi-socket cacheline Directory Lookups : Found in any state)",
      R"(Multi-socket cacheline Directory Lookups : Found in any state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.STATE_A",
      EventDef::Encoding{.code = 0x2D, .umask = 0x08, .umaskExt = 0x00},
      R"(Multi-socket cacheline Directory Lookups : Found in A state)",
      R"(Multi-socket cacheline Directory Lookups : Found in A state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.STATE_I",
      EventDef::Encoding{.code = 0x2D, .umask = 0x02, .umaskExt = 0x00},
      R"(Multi-socket cacheline Directory Lookups : Found in I state)",
      R"(Multi-socket cacheline Directory Lookups : Found in I state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.STATE_S",
      EventDef::Encoding{.code = 0x2D, .umask = 0x04, .umaskExt = 0x00},
      R"(Multi-socket cacheline Directory Lookups : Found in S state)",
      R"(Multi-socket cacheline Directory Lookups : Found in S state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.ANY",
      EventDef::Encoding{.code = 0x2e, .umask = 0x01, .umaskExt = 0x00},
      R"(Multi-socket cacheline Directory Updates : From/to any state. Note: event counts are incorrect in 2LM mode.)",
      R"(Multi-socket cacheline Directory Updates : From/to any state. Note: event counts are incorrect in 2LM mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_TAG_HIT.NM_RD_HIT_CLEAN",
      EventDef::Encoding{.code = 0x2C, .umask = 0x01, .umaskExt = 0x00},
      R"(Tag Hit : Clean NearMem Read Hit)",
      R"(Tag Hit : Clean NearMem Read Hit : Tag Hit indicates when a request sent to the iMC hit in Near Memory. : Counts clean full line read hits (reads and RFOs).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_TAG_HIT.NM_RD_HIT_DIRTY",
      EventDef::Encoding{.code = 0x2C, .umask = 0x02, .umaskExt = 0x00},
      R"(Tag Hit : Dirty NearMem Read Hit)",
      R"(Tag Hit : Dirty NearMem Read Hit : Tag Hit indicates when a request sent to the iMC hit in Near Memory. : Counts dirty full line read hits (reads and RFOs).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .umaskExt = 0x00},
      R"(Clockticks of the mesh to memory (M2M))",
      R"(Clockticks of the mesh to memory (M2M))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core writing to Card's MMIO space)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART5",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core writing to Card's MMIO space)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core writing to Card's MMIO space)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART7",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core writing to Card's MMIO space)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 7)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 5)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00},
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM)",
      R"(Data requested by the CPU : Core reporting completion of Card read from Core DRAM : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART5",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART7",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART5",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART7",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART5",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART7",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_NUM_REQ_OF_CPU.COMMIT.ALL",
      EventDef::Encoding{.code = 0x85, .umask = 0x01, .umaskExt = 0x00},
      R"(Number requests PCIe makes of the main die : All)",
      R"(Number requests PCIe makes of the main die : All : Counts full PCIe requests before they're broken into a series of cache-line size requests as measured by DATA_REQ_OF_CPU and TXN_REQ_OF_CPU.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART5",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART7",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART4",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART5",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART6",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART7",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART5",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART7",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART4",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART5",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART6",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART7",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART4",
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART5",
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART6",
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART7",
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00},
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Number Transactions requested of the CPU : CmpD - device sending completion to CPU request : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7)",
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
      EventDef::Encoding{.code = 0x0f, .umask = 0x04, .umaskExt = 0x00},
      R"(Total IRP occupancy of inbound read and write requests to coherent memory.)",
      R"(Total IRP occupancy of inbound read and write requests to coherent memory.  This is effectively the sum of read occupancy and write occupancy.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_IRP_ALL.INBOUND_INSERTS",
      EventDef::Encoding{.code = 0x20, .umask = 0x01, .umaskExt = 0x00},
      R"(: All Inserts Inbound (p2p + faf + cset))",
      R"(: All Inserts Inbound (p2p + faf + cset))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TRANSACTIONS.WR_PREF",
      EventDef::Encoding{.code = 0x11, .umask = 0x08, .umaskExt = 0x00},
      R"(Inbound write (fast path) requests received by the IRP.)",
      R"(Inbound write (fast path) requests to coherent memory, received by the IRP resulting in write ownership requests issued by IRP to the mesh.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.ALL_DATA",
      EventDef::Encoding{.code = 0x03, .umask = 0x0F, .umaskExt = 0x00},
      R"(Valid Flits Received : All Data)",
      R"(Valid Flits Received : All Data : Shows legal flit time (hides impact of L0p and L0c).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.NON_DATA",
      EventDef::Encoding{.code = 0x03, .umask = 0x97, .umaskExt = 0x00},
      R"(Valid Flits Received : All Non Data)",
      R"(Valid Flits Received : All Non Data : Shows legal flit time (hides impact of L0p and L0c).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.ALL_DATA",
      EventDef::Encoding{.code = 0x02, .umask = 0x0F, .umaskExt = 0x00},
      R"(Valid Flits Sent : All Data)",
      R"(Valid Flits Sent : All Data : Shows legal flit time (hides impact of L0p and L0c).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.NON_DATA",
      EventDef::Encoding{.code = 0x02, .umask = 0x97, .umaskExt = 0x00},
      R"(Valid Flits Sent : All Non Data)",
      R"(Valid Flits Sent : All Non Data : Shows legal flit time (hides impact of L0p and L0c).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_DRAM_REFRESH.OPPORTUNISTIC",
      EventDef::Encoding{.code = 0x45, .umask = 0x01, .umaskExt = 0x00},
      R"(Number of DRAM Refreshes Issued)",
      R"(Number of DRAM Refreshes Issued : Counts the number of refreshes issued.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_DRAM_REFRESH.PANIC",
      EventDef::Encoding{.code = 0x45, .umask = 0x02, .umaskExt = 0x00},
      R"(Number of DRAM Refreshes Issued)",
      R"(Number of DRAM Refreshes Issued : Counts the number of refreshes issued.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_DRAM_REFRESH.HIGH",
      EventDef::Encoding{.code = 0x45, .umask = 0x04, .umaskExt = 0x00},
      R"(Number of DRAM Refreshes Issued)",
      R"(Number of DRAM Refreshes Issued : Counts the number of refreshes issued.)",
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
      EventDef::Encoding{.code = 0x10, .umask = 0x01, .umaskExt = 0x00},
      R"(Read Pending Queue Allocations)",
      R"(Read Pending Queue Allocations : Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.)",
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
      EventDef::Encoding{.code = 0x10, .umask = 0x02, .umaskExt = 0x00},
      R"(Read Pending Queue Allocations)",
      R"(Read Pending Queue Allocations : Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.)",
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
      EventDef::Encoding{.code = 0x20, .umask = 0x01, .umaskExt = 0x00},
      R"(Write Pending Queue Allocations)",
      R"(Write Pending Queue Allocations : Counts the number of allocations into the Write Pending Queue.  This can then be used to calculate the average queuing latency (in conjunction with the WPQ occupancy count).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.)",
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
      EventDef::Encoding{.code = 0x20, .umask = 0x02, .umaskExt = 0x00},
      R"(Write Pending Queue Allocations)",
      R"(Write Pending Queue Allocations : Counts the number of allocations into the Write Pending Queue.  This can then be used to calculate the average queuing latency (in conjunction with the WPQ occupancy count).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.PGT",
      EventDef::Encoding{.code = 0x02, .umask = 0x10, .umaskExt = 0x00},
      R"(DRAM Precharge commands. : Precharge due to page table)",
      R"(DRAM Precharge commands. : Precharge due to page table : Counts the number of DRAM Precharge commands sent on this channel. : Precharges from Page Table)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_CMS_CLOCKTICKS",
      EventDef::Encoding{.code = 0xc0, .umask = 0x00, .umaskExt = 0x00},
      R"(CMS Clockticks)",
      R"(CMS Clockticks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00},
      R"(Clockticks of the IO coherency tracker (IRP))",
      R"(Clockticks of the IO coherency tracker (IRP))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_FAF_FULL",
      EventDef::Encoding{.code = 0x17, .umask = 0x00, .umaskExt = 0x00},
      R"(FAF RF full)",
      R"(FAF RF full)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_FAF_INSERTS",
      EventDef::Encoding{.code = 0x18, .umask = 0x00, .umaskExt = 0x00},
      R"(Inbound read requests received by the IRP and inserted into the FAF queue.)",
      R"(Inbound read requests to coherent memory, received by the IRP and inserted into the Fire and Forget queue (FAF), a queue used for processing inbound reads in the IRP.)",
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
      EventDef::Encoding{.code = 0x19, .umask = 0x00, .umaskExt = 0x00},
      R"(Occupancy of the IRP FAF queue.)",
      R"(Occupancy of the IRP Fire and Forget (FAF) queue, a queue used for processing inbound reads in the IRP.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_FAF_TRANSACTIONS",
      EventDef::Encoding{.code = 0x16, .umask = 0x00, .umaskExt = 0x00},
      R"(FAF allocation -- sent to ADQ)",
      R"(FAF allocation -- sent to ADQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_CMS_CLOCKTICKS",
      EventDef::Encoding{.code = 0xc0, .umask = 0x00, .umaskExt = 0x00},
      R"(CMS Clockticks)",
      R"(CMS Clockticks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00},
      R"(Clockticks of the mesh to PCI (M2P))",
      R"(Clockticks of the mesh to PCI (M2P) : Counts the number of uclks in the M3 uclk domain.  This could be slightly different than the count in the Ubox because of enable/freeze delays.  However, because the M3 is close to the Ubox, they generally should not diverge by more than a handful of cycles.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_CMS_CLOCKTICKS",
      EventDef::Encoding{.code = 0xc0, .umask = 0x00, .umaskExt = 0x00},
      R"(CMS Clockticks)",
      R"(CMS Clockticks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m3upi,
      "UNC_M3UPI_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00},
      R"(Clockticks of the mesh to UPI (M3UPI))",
      R"(Clockticks of the mesh to UPI (M3UPI) : Counts the number of uclks in the M3 uclk domain.  This could be slightly different than the count in the Ubox because of enable/freeze delays.  However, because the M3 is close to the Ubox, they generally should not diverge by more than a handful of cycles.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .umaskExt = 0x00},
      R"(Clockticks of the power control unit (PCU))",
      R"(Clockticks of the power control unit (PCU) : The PCU runs off a fixed 1 GHz clock.  This event counts the number of pclk cycles measured while the counter was enabled.  The pclk, like the Memory Controller's dclk, counts at a constant rate making it a good measure of actual wall time.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00},
      R"(Number of kfclks)",
      R"(Number of kfclks : Counts the number of clocks in the UPI LL.  This clock runs at 1/8th the GT/s speed of the UPI link.  For example, a 8GT/s link will have qfclk or 1GHz.  Current products do not support dynamic link speeds, so this frequency is fixed.)",
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
      EventDef::Encoding{.code = 0x21, .umask = 0x00, .umaskExt = 0x00},
      R"(Cycles in L1)",
      R"(Cycles in L1 : Number of UPI qfclk cycles spent in L1 power mode.  L1 is a mode that totally shuts down a UPI link.  Use edge detect to count the number of instances when the UPI link entered L1.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another. Because L1 totally shuts down the link, it takes a good amount of time to exit this mode.)",
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
      EventDef::Encoding{.code = 0x27, .umask = 0x00, .umaskExt = 0x00},
      R"(Cycles in L0p)",
      R"(Cycles in L0p : Number of UPI qfclk cycles spent in L0p power mode.  L0p is a mode where we disable 1/2 of the UPI lanes, decreasing our bandwidth in order to save power.  It increases snoop and data transfer latencies and decreases overall bandwidth.  This mode can be very useful in NUMA optimized workloads that largely only utilize UPI for snoops and their responses.  Use edge detect to count the number of instances when the UPI link entered L0p.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .umaskExt = 0x00},
      R"(DRAM Clockticks)",
      R"(DRAM Clockticks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_CRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC88FFD},
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that hit the LLC)",
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_DRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC897FD},
      R"(TOR Inserts : DRd_Prefs issued by iA Cores that Hit the LLC)",
      R"(TOR Inserts : DRd_Prefs issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_RFO_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC887FD},
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Hit the LLC)",
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC88FFE},
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC897FE},
      R"(TOR Inserts : DRd_Prefs issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : DRd_Prefs issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC887FE},
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_HIT_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xCC43FD},
      R"(TOR Inserts : ItoMs issued by IO Devices that Hit the LLC)",
      R"(TOR Inserts : ItoMs issued by IO Devices that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x01, .umaskExt = 0x00},
      R"(Clockticks in the UBOX using a dedicated 48-bit Fixed Counter)",
      R"(Clockticks in the UBOX using a dedicated 48-bit Fixed Counter)",
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
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .umaskExt = 0x00},
      R"(Half clockticks for IMC)",
      R"(Half clockticks for IMC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xCC43FF},
      R"(TOR Inserts : ItoMs issued by IO Devices)",
      R"(TOR Inserts : ItoMs issued by IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_RFO_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC887FF},
      R"(TOR Inserts : RFO_Prefs issued by iA Cores)",
      R"(TOR Inserts : RFO_Prefs issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC807FF},
      R"(TOR Inserts : RFOs issued by iA Cores)",
      R"(TOR Inserts : RFOs issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_LLCPREFRFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xCCC7FF},
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores)",
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_DRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC897FF},
      R"(TOR Inserts : DRd_Prefs issued by iA Cores)",
      R"(TOR Inserts : DRd_Prefs issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_CRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC80FFF},
      R"(TOR Inserts : CRDs issued by iA Cores)",
      R"(TOR Inserts : CRDs issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC807FF},
      R"(TOR Occupancy : RFOs issued by iA Cores)",
      R"(TOR Occupancy : RFOs issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_DRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC817FF},
      R"(TOR Occupancy : DRds issued by iA Cores)",
      R"(TOR Occupancy : DRds issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_CRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC80FFF},
      R"(TOR Occupancy : CRDs issued by iA Cores)",
      R"(TOR Occupancy : CRDs issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.ALL_NULL",
      EventDef::Encoding{.code = 0x02, .umask = 0x27, .umaskExt = 0x00},
      R"(Valid Flits Sent : Null FLITs transmitted to any slot)",
      R"(Valid Flits Sent : Null FLITs transmitted to any slot : Shows legal flit time (hides impact of L0p and L0c).)",
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
      EventDef::Encoding{.code = 0x03, .umask = 0x27, .umaskExt = 0x00},
      R"(Valid Flits Received : Null FLITs received from any slot)",
      R"(Valid Flits Received : Null FLITs received from any slot : Shows legal flit time (hides impact of L0p and L0c).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_OCCUPANCY_PCH0",
      EventDef::Encoding{.code = 0x80, .umask = 0x00, .umaskExt = 0x00},
      R"(Read Pending Queue Occupancy)",
      R"(Read Pending Queue Occupancy : Accumulates the occupancies of the Read Pending Queue each cycle.  This can then be used to calculate both the average occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The RPQ is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC. They deallocate after the CAS command has been issued to memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_OCCUPANCY_PCH1",
      EventDef::Encoding{.code = 0x81, .umask = 0x00, .umaskExt = 0x00},
      R"(Read Pending Queue Occupancy)",
      R"(Read Pending Queue Occupancy : Accumulates the occupancies of the Read Pending Queue each cycle.  This can then be used to calculate both the average occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The RPQ is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC. They deallocate after the CAS command has been issued to memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_OCCUPANCY_PCH0",
      EventDef::Encoding{.code = 0x82, .umask = 0x00, .umaskExt = 0x00},
      R"(Write Pending Queue Occupancy)",
      R"(Write Pending Queue Occupancy : Accumulates the occupancies of the Write Pending Queue each cycle.  This can then be used to calculate both the average queue occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.  This is not to be confused with actually performing the write to DRAM.  Therefore, the average latency for this queue is actually not useful for deconstruction intermediate write latencies.  So, we provide filtering based on if the request has posted or not.  By using the not posted filter, we can track how long writes spent in the iMC before completions were sent to the HA.  The posted filter, on the other hand, provides information about how much queueing is actually happening in the iMC for writes before they are actually issued to memory.  High average occupancies will generally coincide with high write major mode counts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_OCCUPANCY_PCH1",
      EventDef::Encoding{.code = 0x83, .umask = 0x00, .umaskExt = 0x00},
      R"(Write Pending Queue Occupancy)",
      R"(Write Pending Queue Occupancy : Accumulates the occupancies of the Write Pending Queue each cycle.  This can then be used to calculate both the average queue occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.  This is not to be confused with actually performing the write to DRAM.  Therefore, the average latency for this queue is actually not useful for deconstruction intermediate write latencies.  So, we provide filtering based on if the request has posted or not.  By using the not posted filter, we can track how long writes spent in the iMC before completions were sent to the HA.  The posted filter, on the other hand, provides information about how much queueing is actually happening in the iMC for writes before they are actually issued to memory.  High average occupancies will generally coincide with high write major mode counts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_ACT_COUNT.ALL",
      EventDef::Encoding{.code = 0x01, .umask = 0x0B, .umaskExt = 0x00},
      R"(DRAM Activate Count : All Activates)",
      R"(DRAM Activate Count : All Activates : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.ALL",
      EventDef::Encoding{.code = 0x02, .umask = 0x1C, .umaskExt = 0x00},
      R"(DRAM Precharge commands.)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC816FE},
      R"(TOR Occupancy : DRds issued by iA Cores that Missed the LLC - HOMed locally)",
      R"(TOR Occupancy : DRds issued by iA Cores that Missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC8177E},
      R"(TOR Occupancy : DRds issued by iA Cores that Missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : DRds issued by iA Cores that Missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC816FE},
      R"(TOR Inserts : DRds issued by iA Cores that Missed the LLC - HOMed locally)",
      R"(TOR Inserts : DRds issued by iA Cores that Missed the LLC - HOMed locally : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC8177E},
      R"(TOR Inserts : DRds issued by iA Cores that Missed the LLC - HOMed remotely)",
      R"(TOR Inserts : DRds issued by iA Cores that Missed the LLC - HOMed remotely : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC896FE},
      R"(TOR Inserts; DRd Pref misses from local IA)",
      R"(TOR Inserts; Data read prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC8977E},
      R"(TOR Inserts; DRd Pref misses from local IA)",
      R"(TOR Inserts; Data read prefetch from remote IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC806FE},
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC - HOMed locally)",
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC - HOMed locally : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC8077E},
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC - HOMed remotely)",
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC - HOMed remotely : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC886FE},
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed locally)",
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed locally : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC8877E},
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed remotely)",
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed remotely : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_CLFLUSH",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC8C7FF},
      R"(TOR Inserts : CLFlushes issued by iA Cores)",
      R"(TOR Inserts : CLFlushes issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_SPECITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xCC57FF},
      R"(TOR Inserts : SpecItoMs issued by iA Cores)",
      R"(TOR Inserts : SpecItoMs issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xCD43FF},
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_HIT_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xCD43FD},
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_MISS_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xCD43FE},
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC8178A},
      R"(TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC)",
      R"(TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC8168A},
      R"(TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally)",
      R"(TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC8170A},
      R"(TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely)",
      R"(TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_FULL_STREAMING_WR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xc867fe},
      R"(TOR Inserts; WCiLF misses from local IA)",
      R"(TOR Inserts; Data read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_PARTIAL_STREAMING_WR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xc86ffe},
      R"(TOR Inserts; WCiL misses from local IA)",
      R"(TOR Inserts; Data read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC8178A},
      R"(TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC)",
      R"(TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_CLOCKTICKS_FREERUN",
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .umaskExt = 0x00},
      R"(Free running counter that increments for IIO clocktick)",
      R"(Free running counter that increments for integrated IO (IIO) traffic controller clockticks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_RPQ_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0xE0, .umask = 0x01, .umaskExt = 0x00},
      R"(PMM Read Pending Queue Occupancy)",
      R"(PMM Read Pending Queue Occupancy : Accumulates the per cycle occupancy of the PMM Read Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_RPQ_INSERTS",
      EventDef::Encoding{.code = 0xE3, .umask = 0x00, .umaskExt = 0x00},
      R"(PMM Read Queue Inserts)",
      R"(PMM Read Queue Inserts : Counts number of read requests allocated in the PMM Read Pending Queue.   This includes both ISOCH and non-ISOCH requests.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_WPQ_INSERTS",
      EventDef::Encoding{.code = 0xE7, .umask = 0x00, .umaskExt = 0x00},
      R"(PMM Write Queue Inserts)",
      R"(PMM Write Queue Inserts : Counts number of  write requests allocated in the PMM Write Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_CMD1.ALL",
      EventDef::Encoding{.code = 0xEA, .umask = 0x01, .umaskExt = 0x00},
      R"(PMM Commands : All)",
      R"(PMM Commands : All : Counts all commands issued to PMM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_CMD1.RD",
      EventDef::Encoding{.code = 0xEA, .umask = 0x02, .umaskExt = 0x00},
      R"(PMM Commands : Reads - RPQ)",
      R"(PMM Commands : Reads - RPQ : Counts read requests issued to the PMM RPQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_CMD1.WR",
      EventDef::Encoding{.code = 0xEA, .umask = 0x04, .umaskExt = 0x00},
      R"(PMM Commands : Writes)",
      R"(PMM Commands : Writes : Counts write commands issued to PMM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_CMD1.UFILL_RD",
      EventDef::Encoding{.code = 0xEA, .umask = 0x08, .umaskExt = 0x00},
      R"(PMM Commands : Underfill reads)",
      R"(PMM Commands : Underfill reads : Counts underfill read commands, due to a partial write, issued to PMM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_WPQ_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0xE4, .umask = 0x01, .umaskExt = 0x00},
      R"(PMM Write Pending Queue Occupancy)",
      R"(PMM Write Pending Queue Occupancy : Accumulates the per cycle occupancy of the PMM Write Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_IMC_READS.TO_PMM",
      EventDef::Encoding{.code = 0x37, .umask = 0x20, .umaskExt = 0x07},
      R"(M2M Reads Issued to iMC : PMM - All Channels)",
      R"(M2M Reads Issued to iMC : PMM - All Channels)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_IMC_WRITES.TO_PMM",
      EventDef::Encoding{.code = 0x38, .umask = 0x80, .umaskExt = 0x1C},
      R"(M2M Writes Issued to iMC : PMM - All Channels)",
      R"(M2M Writes Issued to iMC : PMM - All Channels)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFDATA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xCCD7FE},
      R"(TOR Inserts : LLCPrefData issued by iA Cores that missed the LLC)",
      R"(TOR Inserts : LLCPrefData issued by iA Cores that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_MISS_PCIRDCUR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xC8F3FE},
      R"(TOR Inserts : PCIRdCurs issued by IO Devices that missed the LLC)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_PCIRDCUR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0xc8f3fe},
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices that missed the LLC)",
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC81786},
      R"(TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC)",
      R"(TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC81686},
      R"(TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally)",
      R"(TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xC81706},
      R"(TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely)",
      R"(TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0xC81786},
      R"(TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC)",
      R"(TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_HIT_PCIRDCUR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xC8F3FD},
      R"(TOR Inserts : PCIRdCurs issued by IO Devices that hit the LLC)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_PCIRDCUR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xC8F3FF},
      R"(TOR Inserts : PCIRdCurs issued by IO Devices)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_LLCPREFDATA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0xCCD7FF},
      R"(TOR Inserts : LLCPrefData issued by iA Cores)",
      R"(TOR Inserts : LLCPrefData issued by iA Cores : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_PCIRDCUR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0xC8F3FF},
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices)",
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.DATA_READ",
      EventDef::Encoding{.code = 0x34, .umask = 0xFF, .umaskExt = 0x1BC1},
      R"(Cache and Snoop Filter Lookups; Data Read Request)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions)",
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
      EventDef::Encoding{.code = 0xc2, .umask = 0x03, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 0)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 0 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0xc2, .umask = 0x03, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 1)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 1 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc2, .umask = 0x03, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 2)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 2)",
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
      EventDef::Encoding{.code = 0xc2, .umask = 0x03, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 3)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 3)",
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
      EventDef::Encoding{.code = 0xc2, .umask = 0x03, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 4)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 0 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 4)",
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
      EventDef::Encoding{.code = 0xc2, .umask = 0x03, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 5)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 1 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 5)",
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
      EventDef::Encoding{.code = 0xc2, .umask = 0x03, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 6)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 6)",
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
      EventDef::Encoding{.code = 0xc2, .umask = 0x03, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 7)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 7)",
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
      EventDef::Encoding{.code = 0xd5, .umask = 0x01, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Occupancy of completions with data : Part 0)",
      R"(PCIe Completion Buffer Occupancy : Part 0 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0xd5, .umask = 0x80, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Occupancy of completions with data : Part 7)",
      R"(PCIe Completion Buffer Occupancy : Part 7 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 7)",
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
      EventDef::Encoding{.code = 0xd5, .umask = 0x40, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Occupancy of completions with data : Part 6)",
      R"(PCIe Completion Buffer Occupancy : Part 6 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 6)",
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
      EventDef::Encoding{.code = 0xd5, .umask = 0x20, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Occupancy of completions with data : Part 5)",
      R"(PCIe Completion Buffer Occupancy : Part 5 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 5)",
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
      EventDef::Encoding{.code = 0xd5, .umask = 0x10, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Occupancy of completions with data : Part 4)",
      R"(PCIe Completion Buffer Occupancy : Part 4 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 4)",
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
      EventDef::Encoding{.code = 0xd5, .umask = 0x08, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Occupancy of completions with data : Part 3)",
      R"(PCIe Completion Buffer Occupancy : Part 3 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 3)",
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
      EventDef::Encoding{.code = 0xd5, .umask = 0x04, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Occupancy of completions with data : Part 2)",
      R"(PCIe Completion Buffer Occupancy : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 2)",
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
      EventDef::Encoding{.code = 0xd5, .umask = 0x02, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Occupancy of completions with data : Part 1)",
      R"(PCIe Completion Buffer Occupancy : Part 1 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0x12, .umask = 0x78, .umaskExt = 0x00},
      R"(Responses to snoops of any type that hit M line in the IIO cache)",
      R"(Responses to snoops of any type (code, data, invalidate) that hit M line in the IIO cache)",
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
      EventDef::Encoding{.code = 0xc2, .umask = 0x03, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 0-7)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 0-7)",
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
      EventDef::Encoding{.code = 0xd5, .umask = 0xff, .umaskExt = 0x00},
      R"(PCIe Completion Buffer Occupancy of completions with data : Part 0-7)",
      R"(PCIe Completion Buffer Occupancy : Part 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_ITOM_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xCC42FF},
      R"(TOR Inserts : ItoMs issued by IO Devices to locally HOMed memory)",
      R"(TOR Inserts : ItoMs issued by IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_ITOM_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xCC437F},
      R"(TOR Inserts : ItoMs issued by IO Devices to remotely HOMed memory)",
      R"(TOR Inserts : ItoMs issued by IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_ITOMCACHENEAR_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xCD42FF},
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices to locally HOMed memory)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_ITOMCACHENEAR_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xCD437F},
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices to remotely HOMed memory)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_PCIRDCUR_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xC8F37F},
      R"(PCIRDCUR (read) transactions from an IO device that addresses memory on a remote socket)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices and targets remote memory : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_PCIRDCUR_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0xC8F2FF},
      R"(PCIRDCUR (read) transactions from an IO device that addresses memory on the local socket)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices and targets local memory : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace icelakex_uncore
} // namespace facebook::hbt::perf_event::generated
