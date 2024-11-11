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
namespace sierraforest_uncore {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from sierraforest_uncore.json (327 events).

    Supported SKUs:
        - Arch: x86, Model: SRF id: 175
  */

  // Event UNC_CHA_CLOCKTICKS is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Number of CHA clock cycles while the event is enabled)",
      R"(Clockticks of the uncore caching and home agent (CHA))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_CRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C80FFD},
      R"(Code read from local IA that hit the cache)",
      R"(TOR Inserts : CRds issued by iA Cores that Hit the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CCC7FD},
      R"(Last level cache prefetch read for ownership from local IA that hit the cache)",
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores that hit the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C807FD},
      R"(Read for ownership from local IA that hit the cache)",
      R"(TOR Inserts : RFOs issued by iA Cores that Hit the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C001FE},
      R"(All locally initiated requests from IA Cores which miss the cache)",
      R"(TOR Inserts : All requests from iA Cores that Missed the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C80FFE},
      R"(Code read from local IA that miss the cache)",
      R"(TOR Inserts : CRds issued by iA Cores that Missed the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CCC7FE},
      R"(Last level cache prefetch read for ownership from local IA that miss the cache)",
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores that missed the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C807FE},
      R"(Read for ownership from local IA that miss the cache)",
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CC43FE},
      R"(All TOR ItoM inserts from local IO devices which miss the cache)",
      R"(TOR Inserts : ItoMs issued by IO Devices that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_MISS_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C803FE},
      R"(All TOR RFO inserts from local IO devices which miss the cache)",
      R"(TOR Inserts : RFOs issued by IO Devices that missed the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C88FFD},
      R"(Code read prefetch from local IA that hit the cache)",
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_DRD_OPT",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C827FD},
      R"(Data read opt from local IA that hit the cache)",
      R"(TOR Inserts : DRd_Opts issued by iA Cores that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8A7FD},
      R"(Data read opt prefetch from local IA that hit the cache)",
      R"(TOR Inserts : DRd_Opt_Prefs issued by iA Cores that hit the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C887FD},
      R"(Read for ownership prefetch from local IA that hit the cache)",
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Hit the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C88FFE},
      R"(Code read prefetch from local IA that miss the cache)",
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C827FE},
      R"(Data read opt from local IA that miss the cache)",
      R"(TOR Inserts : DRd_Opt issued by iA Cores that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8A7FE},
      R"(Data read opt prefetch from local IA that miss the cache)",
      R"(TOR Inserts : DRd_Opt_Prefs issued by iA Cores that missed the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C887FE},
      R"(Read for ownership prefetch from local IA that miss the cache)",
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CC43FD},
      R"(ItoMs from local IO devices which hit the cache)",
      R"(TOR Inserts : ItoMs issued by IO Devices that Hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_HIT_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C803FD},
      R"(RFOs from local IO devices which hit the cache)",
      R"(TOR Inserts : RFOs issued by IO Devices that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C803FF},
      R"(RFOs from local IO devices)",
      R"(TOR Inserts : RFOs issued by IO Devices)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CC43FF},
      R"(All TOR ItoM inserts from local IO devices)",
      R"(TOR Inserts : ItoMs issued by IO Devices)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C887FF},
      R"(Read for ownership prefetch from local IA)",
      R"(TOR Inserts : RFO_Prefs issued by iA Cores)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C807FF},
      R"(Read for ownership from local IA)",
      R"(TOR Inserts : RFOs issued by iA Cores)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CCC7FF},
      R"(Last level cache prefetch read for ownership from local IA that miss the cache)",
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_DRD_OPT",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C827FF},
      R"(Data read opt from local IA)",
      R"(TOR Inserts : DRd_Opts issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8A7FF},
      R"(Data read opt prefetch from local IA)",
      R"(TOR Inserts : DRd_Opt_Prefs issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_CRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C88FFF},
      R"(Code read prefetch from local IA that miss the cache)",
      R"(TOR Inserts; Code read prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C80FFF},
      R"(Code read from local IA)",
      R"(TOR Inserts : CRDs issued by iA Cores)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C806FE},
      R"(Read for ownership from local IA that miss the LLC targeting local memory)",
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC - HOMed locally)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8077E},
      R"(Read for ownership from local IA that miss the LLC targeting remote memory)",
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC - HOMed remotely)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C886FE},
      R"(Read for ownership prefetch from local IA that miss the LLC targeting local memory)",
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed locally)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8877E},
      R"(Read for ownership prefetch from local IA that miss the LLC targeting remote memory)",
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed remotely)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8C7FF},
      R"(CLFlush events that are initiated from the Core)",
      R"(TOR Inserts : CLFlushes issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_CLFLUSHOPT",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8D7FF},
      R"(CLFlushOpt events that are initiated from the Core)",
      R"(TOR Inserts : CLFlushOpts issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CC47FF},
      R"(ItoM events that are initiated from the Core)",
      R"(TOR Inserts : ItoMs issued by iA Cores)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CC57FF},
      R"(SpecItoM events that are initiated from the Core)",
      R"(TOR Inserts : SpecItoMs issued by iA Cores)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CD43FD},
      R"(ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CD43FE},
      R"(ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_WBEFTOE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CC3FFF},
      R"(WbEFtoEs issued by iA Cores.  (Non Modified Write Backs))",
      R"(TOR Inserts : ItoMs issued by IO Devices that Hit the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C8F3FD},
      R"(PCIRDCURs issued by IO devices which hit the LLC)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices that hit the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C8F3FE},
      R"(PCIRDCURs issued by IO devices which miss the LLC)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices that missed the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C8F3FF},
      R"(PCIRDCURs issued by IO devices)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_LLCPREFCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CCCFFD},
      R"(Last level cache prefetch code read from local IA that hit the cache)",
      R"(TOR Inserts : LLCPrefCode issued by iA Cores that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_LLCPREFDATA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CCD7FD},
      R"(Last level cache prefetch data read from local IA that hit the cache)",
      R"(TOR Inserts : LLCPrefData issued by iA Cores that hit the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CCD7FF},
      R"(Last level cache prefetch data read from local IA.)",
      R"(TOR Inserts : LLCPrefData issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CCCFFE},
      R"(Last level cache prefetch code read from local IA that miss the cache)",
      R"(TOR Inserts : LLCPrefCode issued by iA Cores that missed the LLC)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CCD7FE},
      R"(Last level cache prefetch data read from local IA that miss the cache)",
      R"(TOR Inserts : LLCPrefData issued by iA Cores that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_LLCPREFCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CCCFFF},
      R"(Last level cache prefetch code read from local IA.)",
      R"(TOR Inserts : LLCPrefCode issued by iA Cores)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CD43FF},
      R"(ItoMCacheNears, indicating a partial write request, from IO Devices)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C80EFE},
      R"(CRDs from local IA cores to locally homed memory)",
      R"(TOR Inserts : CRd issued by iA Cores that Missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C80F7E},
      R"(CRDs from local IA cores to remotely homed memory)",
      R"(TOR Inserts : CRd issued by iA Cores that Missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_PREF_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C88EFE},
      R"(CRD Prefetches from local IA cores to locally homed memory)",
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_PREF_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C88F7E},
      R"(CRD Prefetches from local IA cores to remotely homed memory)",
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CD47FF},
      R"(ItoMCacheNear requests from local IA cores)",
      R"(TOR Inserts : ItoMCacheNears issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_WBMTOI",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CC27FF},
      R"(WbMtoI requests from local IA cores)",
      R"(TOR Inserts : WbMtoIs issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CC47FD},
      R"(ItoM requests from local IA cores that hit the cache)",
      R"(TOR Inserts : ItoMs issued by iA Cores that Hit LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CC47FE},
      R"(ItoM requests from local IA cores that miss the cache)",
      R"(TOR Inserts : ItoMs issued by iA Cores that Missed LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_UCRDF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C877DE},
      R"(UCRDF requests from local IA cores that miss the cache)",
      R"(TOR Inserts : UCRdFs issued by iA Cores that Missed LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WIL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C87FDE},
      R"(WIL requests from local IA cores that miss the cache)",
      R"(TOR Inserts : WiLs issued by iA Cores that Missed LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_WCILF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C867FF},
      R"(WCILF requests from local IA core)",
      R"(TOR Inserts : WCiLF issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCILF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C867FE},
      R"(WCILF requests from local IA core that miss the cache)",
      R"(TOR Inserts : WCiLF issued by iA Cores that Missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCILF_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C86786},
      R"(WCILF requests from local IA cores to DDR homed addresses which miss the cache)",
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting DDR that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCILF_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C86686},
      R"(WCILF requests from local IA cores to locally homed DDR addresses that miss the cache)",
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCILF_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C86706},
      R"(WCILF requests from local IA cores to remotely homed DDR addresses that miss the cache)",
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_WCIL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C86FFF},
      R"(WCIL requests from a local IA core)",
      R"(TOR Inserts : WCiLs issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCIL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C86FFE},
      R"(WCIL requests from a local IA core that miss the cache)",
      R"(TOR Inserts : WCiLs issued by iA Cores that Missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCIL_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C86F86},
      R"(WCIL requests from local IA cores to DDR homed addresses which miss the cache)",
      R"(TOR Inserts : WCiLs issued by iA Cores targeting DDR that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCIL_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C86E86},
      R"(WCIL requests from local IA cores to locally homed DDR addresses that miss the cache)",
      R"(TOR Inserts : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCIL_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C86F06},
      R"(WCIL requests from local IA cores to remotely homed DDR addresses that miss the cache)",
      R"(TOR Inserts : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_WBMTOI",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CC23FF},
      R"(WBMtoI requests from IO devices)",
      R"(TOR Inserts : WbMtoIs issued by IO Devices)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_CLFLUSH",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C8C3FF},
      R"(CLFlush requests from IO devices)",
      R"(TOR Inserts : CLFlushes issued by IO Devices)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_WBMTOE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CC2FFF},
      R"(WbMtoEs issued by iA Cores .  (Modified Write Backs))",
      R"(TOR Inserts : ItoMs issued by IO Devices that Hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_WBEFTOI",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CC37FF},
      R"(WbEFtoIs issued by iA Cores .  (Non Modified Write Backs))",
      R"(TOR Inserts : ItoMs issued by IO Devices that Hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_WBSTOI",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00CC67FF},
      R"(WbStoIs issued by iA Cores .  (Non Modified Write Backs))",
      R"(TOR Inserts : ItoMs issued by IO Devices that Hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_CXL_ACC",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x10C81782},
      R"(DRds and equivalent opcodes issued from an IA core which miss the L3 and target memory in a CXL type 2 memory expander card.)",
      R"(DRds issued from an IA core which miss the L3 and target memory in a CXL type 2 memory expander card.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_CXL_ACC",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x10C80782},
      R"(RFOs issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      R"(RFOs issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFRFO_CXL_ACC",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x10C88782},
      R"(L2 RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      R"(L2 RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF_CXL_ACC",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x10CCC782},
      R"(LLC RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      R"(LLC RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_CXL_ACC",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x10C89782},
      R"(L2 data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      R"(L2 data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFDATA_CXL_ACC",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x10CCD782},
      R"(LLC data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      R"(LLC data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CXL_ACC",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x10C00182},
      R"(All requests issued from IA cores to CXL accelerator memory regions that miss the LLC.)",
      R"(All requests issued from IA cores to CXL accelerator memory regions that miss the LLC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_CXL_ACC",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x10C00181},
      R"(All requests issued from IA cores to CXL accelerator memory regions that hit the LLC.)",
      R"(All requests issued from IA cores to CXL accelerator memory regions that hit the LLC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_CRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C80FFD},
      R"(TOR Occupancy for Code read from local IA that hit the cache)",
      R"(TOR Occupancy : CRds issued by iA Cores that Hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LLCPREFRFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CCC7FD},
      R"(TOR Occupancy for Last level cache prefetch read for ownership from local IA that hit the cache)",
      R"(TOR Occupancy : LLCPrefRFO issued by iA Cores that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C807FD},
      R"(TOR Occupancy for Read for ownership from local IA that hit the cache)",
      R"(TOR Occupancy : RFOs issued by iA Cores that Hit the LLC)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C80FFE},
      R"(TOR Occupancy for Code read from local IA that miss the cache)",
      R"(TOR Occupancy : CRds issued by iA Cores that Missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFRFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CCC7FE},
      R"(TOR Occupancy for Last level cache prefetch read for ownership from local IA that miss the cache)",
      R"(TOR Occupancy : LLCPrefRFO issued by iA Cores that missed the LLC)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C807FE},
      R"(TOR Occupancy for Read for ownership from local IA that miss the cache)",
      R"(TOR Occupancy : RFOs issued by iA Cores that Missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C803FE},
      R"(TOR Occupancy for All TOR RFO inserts from local IO devices which miss the cache)",
      R"(TOR Occupancy : RFOs issued by IO Devices that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00CC43FE},
      R"(TOR Occupancy for All TOR ItoM inserts from local IO devices which miss the cache)",
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
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_CRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C88FFD},
      R"(TOR Occupancy for Code read prefetch from local IA that hit the cache)",
      R"(TOR Occupancy : CRd_Prefs issued by iA Cores that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD_OPT",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C827FD},
      R"(TOR Occupancy for Data read opt from local IA that hit the cache)",
      R"(TOR Occupancy : DRd_Opts issued by iA Cores that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C8A7FD},
      R"(TOR Occupancy for Data read opt prefetch from local IA that hit the cache)",
      R"(TOR Occupancy : DRd_Opt_Prefs issued by iA Cores that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_RFO_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C887FD},
      R"(TOR Occupancy for Read for ownership prefetch from local IA that hit the cache)",
      R"(TOR Occupancy : RFO_Prefs issued by iA Cores that Hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C88FFE},
      R"(TOR Occupancy for Code read prefetch from local IA that miss the cache)",
      R"(TOR Occupancy : CRd_Prefs issued by iA Cores that Missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_OPT is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_OPT",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C827FE},
      R"(TOR Occupancy for Data read opt from local IA that miss the cache)",
      R"(TOR Occupancy : DRd_Opt issued by iA Cores that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C8A7FE},
      R"(TOR Occupancy for Data read opt prefetch from local IA that miss the cache)",
      R"(TOR Occupancy : DRd_Opt_Prefs issued by iA Cores that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C887FE},
      R"(TOR Occupancy for Read for ownership prefetch from local IA that miss the cache)",
      R"(TOR Occupancy : RFO_Prefs issued by iA Cores that Missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_HIT_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00CC43FD},
      R"(TOR Occupancy for ItoMs from local IO devices which hit the cache)",
      R"(TOR Occupancy : ItoMs issued by IO Devices that Hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_HIT_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C803FD},
      R"(TOR Occupancy for RFOs from local IO devices which hit the cache)",
      R"(TOR Occupancy : RFOs issued by IO Devices that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C803FF},
      R"(TOR Occupancy for RFOs from local IO devices)",
      R"(TOR Occupancy : RFOs issued by IO Devices)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00CC43FF},
      R"(TOR Occupancy for All TOR ItoM inserts from local IO devices)",
      R"(TOR Occupancy : ItoMs issued by IO Devices)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C807FF},
      R"(TOR Occupancy for Read for ownership from local IA that miss the cache)",
      R"(TOR Occupancy : RFOs issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_RFO_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C887FF},
      R"(TOR Occupancy for Read for ownership prefetch from local IA that miss the cache)",
      R"(TOR Occupancy : RFO_Prefs issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_LLCPREFRFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CCC7FF},
      R"(TOR Occupancy for Last level cache prefetch read for ownership from local IA that miss the cache)",
      R"(TOR Occupancy : LLCPrefRFO issued by iA Cores)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C80FFF},
      R"(TOR Occupancy for Code read from local IA that miss the cache)",
      R"(TOR Occupancy : CRDs issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_CRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C88FFF},
      R"(TOR Occupancy for Code read prefetch from local IA that miss the cache)",
      R"(TOR Occupancy; Code read prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C806FE},
      R"(TOR Occupancy for Read for ownership from local IA that miss the cache)",
      R"(TOR Occupancy : RFOs issued by iA Cores that Missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C8077E},
      R"(TOR Occupancy for Read for ownership from local IA that miss the cache)",
      R"(TOR Occupancy : RFOs issued by iA Cores that Missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_PREF_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C886FE},
      R"(TOR Occupancy for Read for ownership prefetch from local IA that miss the cache)",
      R"(TOR Occupancy : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_PREF_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C8877E},
      R"(TOR Occupancy for Read for ownership prefetch from local IA that miss the cache)",
      R"(TOR Occupancy : RFO_Prefs issued by iA Cores that Missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_HIT_PCIRDCUR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C8F3FD},
      R"(TOR Occupancy for PCIRDCURs issued by IO devices which hit the LLC)",
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices that hit the LLC)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C8F3FE},
      R"(TOR Occupancy for PCIRDCURs issued by IO devices which miss the LLC)",
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
      "UNC_CHA_TOR_OCCUPANCY.IO_PCIRDCUR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C8F3FF},
      R"(TOR Occupancy for PCIRDCURs issued by IO devices)",
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LLCPREFCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CCCFFD},
      R"(TOR Occupancy for Last level cache prefetch code read from local IA that hit the cache)",
      R"(TOR Occupancy : LLCPrefCode issued by iA Cores that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LLCPREFDATA",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CCD7FD},
      R"(TOR Occupancy for Last level cache prefetch data read from local IA that hit the cache)",
      R"(TOR Occupancy : LLCPrefData issued by iA Cores that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_LLCPREFDATA",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CCD7FF},
      R"(TOR Occupancy for Last level cache prefetch data read from local IA.)",
      R"(TOR Occupancy : LLCPrefData issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CCCFFE},
      R"(TOR Occupancy for Last level cache prefetch code read from local IA that miss the cache)",
      R"(TOR Occupancy : LLCPrefCode issued by iA Cores that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFDATA",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CCD7FE},
      R"(TOR Occupancy for Last level cache prefetch data read from local IA that miss the cache)",
      R"(TOR Occupancy : LLCPrefData issued by iA Cores that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_LLCPREFCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CCCFFF},
      R"(TOR Occupancy for Last level cache prefetch code read from local IA.)",
      R"(TOR Occupancy : LLCPrefCode issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C80EFE},
      R"(TOR Occupancy for CRDs from local IA cores to locally homed memory)",
      R"(TOR Occupancy : CRd issued by iA Cores that Missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C80F7E},
      R"(TOR Occupancy for CRDs from local IA cores to remotely homed memory)",
      R"(TOR Occupancy : CRd issued by iA Cores that Missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_PREF_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C88EFE},
      R"(TOR Occupancy for CRD Prefetches from local IA cores to locally homed memory)",
      R"(TOR Occupancy : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_PREF_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C88F7E},
      R"(TOR Occupancy for CRD Prefetches from local IA cores to remotely homed memory)",
      R"(TOR Occupancy : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_CLFLUSH",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C8C7FF},
      R"(TOR Occupancy for CLFlush events that are initiated from the Core)",
      R"(TOR Occupancy : CLFlushes issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_CLFLUSHOPT",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C8D7FF},
      R"(TOR Occupancy for CLFlushOpt events that are initiated from the Core)",
      R"(TOR Occupancy : CLFlushOpts issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CD47FF},
      R"(TOR Occupancy for ItoMCacheNear requests from local IA cores)",
      R"(TOR Occupancy : ItoMCacheNears issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_SPECITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CC57FF},
      R"(TOR Occupancy for SpecItoM events that are initiated from the Core)",
      R"(TOR Occupancy : SpecItoMs issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_WBMTOI",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CC27FF},
      R"(TOR Occupancy for WbMtoI requests from local IA cores)",
      R"(TOR Occupancy : WbMtoIs issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CC47FF},
      R"(TOR Occupancy for ItoM events that are initiated from the Core)",
      R"(TOR Occupancy : ItoMs issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CC47FD},
      R"(TOR Occupancy for ItoM requests from local IA cores that hit the cache)",
      R"(TOR Occupancy : ItoMs issued by iA Cores that Hit LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00CC47FE},
      R"(TOR Occupancy for ItoM requests from local IA cores that miss the cache)",
      R"(TOR Occupancy : ItoMs issued by iA Cores that Missed LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_UCRDF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C877DE},
      R"(TOR Occupancy for UCRDF requests from local IA cores that miss the cache)",
      R"(TOR Occupancy : UCRdFs issued by iA Cores that Missed LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WIL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C87FDE},
      R"(TOR Occupancy for WIL requests from local IA cores that miss the cache)",
      R"(TOR Occupancy : WiLs issued by iA Cores that Missed LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_WCILF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C867FF},
      R"(TOR Occupancy for WCILF requests from local IA core)",
      R"(TOR Occupancy : WCiLF issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCILF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C867FE},
      R"(TOR Occupancy for WCILF requests from local IA core that miss the cache)",
      R"(TOR Occupancy : WCiLF issued by iA Cores that Missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCILF_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C86786},
      R"(TOR Occupancy for WCILF requests from local IA cores to DDR homed addresses which miss the cache)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCILF_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C86686},
      R"(TOR Occupancy for WCILF requests from local IA cores to locally homed DDR addresses that miss the cache)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCILF_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C86706},
      R"(TOR Occupancy for WCILF requests from local IA cores to remotely homed DDR addresses that miss the cache)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_WCIL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C86FFF},
      R"(TOR Occupancy for WCIL requests from a local IA core)",
      R"(TOR Occupancy : WCiLs issued by iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCIL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C86FFE},
      R"(TOR Occupancy for WCIL requests from a local IA core that miss the cache)",
      R"(TOR Occupancy : WCiLs issued by iA Cores that Missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCIL_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C86F86},
      R"(TOR Occupancy for WCIL requests from local IA cores to DDR homed addresses which miss the cache)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCIL_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C86E86},
      R"(TOR Occupancy for WCIL requests from local IA cores to locally homed DDR addresses that miss the cache)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCIL_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C86F06},
      R"(TOR Occupancy for WCIL requests from local IA cores to remotely homed DDR addresses that miss the cache)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_WBMTOI",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00CC23FF},
      R"(TOR Occupancy for WBMtoI requests from IO devices)",
      R"(TOR Occupancy : WbMtoIs issued by IO Devices)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_CLFLUSH",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00C8C3FF},
      R"(TOR Occupancy for CLFlush requests from IO devices)",
      R"(TOR Occupancy : CLFlushes issued by IO Devices)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_HIT_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00CD43FD},
      R"(TOR Occupancy for ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC)",
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00CD43FE},
      R"(TOR Occupancy for ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC)",
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
      "UNC_CHA_TOR_OCCUPANCY.IO_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00CD43FF},
      R"(TOR Occupancy for ItoMCacheNears, indicating a partial write request, from IO Devices)",
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_CXL_ACC",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x10C80782},
      R"(TOR Occupancy for RFOs issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      R"(TOR Occupancy for RFOs issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_CXL_ACC",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x10C81782},
      R"(TOR Occupancy for DRds and equivalent opcodes issued from an IA core which miss the L3 and target memory in a CXL type 2 memory expander card.)",
      R"(TOR Occupancy for DRds and equivalent opcodes issued from an IA core which miss the L3 and target memory in a CXL type 2 memory expander card.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_CXL_ACC",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x10C89782},
      R"(TOR Occupancy for L2 data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      R"(TOR Occupancy for L2 data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFDATA_CXL_ACC",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x10CCD782},
      R"(TOR Occupancy for LLC data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      R"(TOR Occupancy for LLC data prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFRFO_CXL_ACC",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x10C88782},
      R"(TOR Occupancy for L2 RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      R"(TOR Occupancy for L2 RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_PREF_CXL_ACC",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x10CCC782},
      R"(TOR Occupancy for LLC RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      R"(TOR Occupancy for LLC RFO prefetches issued from an IA core which miss the L3 and target memory in a CXL type 2 accelerator.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CXL_ACC",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x10C00182},
      R"(TOR Occupancy for All requests issued from IA cores to CXL accelerator memory regions that miss the LLC.)",
      R"(TOR Occupancy for All requests issued from IA cores to CXL accelerator memory regions that miss the LLC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_CXL_ACC",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x10C00181},
      R"(TOR Occupancy for All requests issued from IA cores to CXL accelerator memory regions that hit the LLC.)",
      R"(TOR Occupancy for All requests issued from IA cores to CXL accelerator memory regions that hit the LLC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_MISC.RFO_HIT_S",
      EventDef::Encoding{.code = 0x39, .umask = 0x08, .umaskExt = 0x00000000},
      R"(Counts when a RFO (the Read for Ownership issued before a  write) request hit a cacheline in the S (Shared) state.)",
      R"(Cbo Misc : RFO HitS)",
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
      EventDef::Encoding{.code = 0x50, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Counts read requests coming from a unit on this socket made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).)",
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
      EventDef::Encoding{.code = 0x50, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Counts read requests coming from a remote socket made into the CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).)",
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
      EventDef::Encoding{.code = 0x50, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Counts  write requests coming from a unit on this socket made into this CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.)",
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
      EventDef::Encoding{.code = 0x50, .umask = 0x08, .umaskExt = 0x00000000},
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.INVITOE_LOCAL",
      EventDef::Encoding{.code = 0x50, .umask = 0x10, .umaskExt = 0x00000000},
      R"(Counts the total number of requests coming from a unit on this socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.)",
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
      EventDef::Encoding{.code = 0x50, .umask = 0x20, .umaskExt = 0x00000000},
      R"(Counts the total number of requests coming from a remote socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.)",
      R"(Counts the total number of requests coming from a remote socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.INVITOE",
      EventDef::Encoding{.code = 0x50, .umask = 0x30, .umaskExt = 0x00000000},
      R"(Counts the total number of requests coming from a unit on this socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.)",
      R"(HA Read and Write Requests : InvalItoE)",
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
      EventDef::Encoding{.code = 0x50, .umask = 0x03, .umaskExt = 0x00000000},
      R"(Counts read requests made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write) .)",
      R"(HA Read and Write Requests : Reads)",
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
      EventDef::Encoding{.code = 0x50, .umask = 0x0C, .umaskExt = 0x00000000},
      R"(Counts write requests made into the CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.)",
      R"(HA Read and Write Requests : Writes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_OSB.RFO_HITS_SNP_BCAST",
      EventDef::Encoding{.code = 0x55, .umask = 0x10, .umaskExt = 0x00000000},
      R"(OSB Snoop Broadcast : RFO HitS Snoop Broadcast : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      R"(OSB Snoop Broadcast : RFO HitS Snoop Broadcast)",
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
      EventDef::Encoding{.code = 0x01, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Number of DRAM DCLK clock cycles while the event is enabled.  DCLK is 1/4 of DRAM data rate.)",
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
      "UNC_M_ACT_COUNT.ALL",
      EventDef::Encoding{.code = 0x02, .umask = 0xF7, .umaskExt = 0x00000000},
      R"(DRAM Activate Count : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.)",
      R"(DRAM Activate Count)",
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
      EventDef::Encoding{.code = 0x03, .umask = 0xF8, .umaskExt = 0x00000000},
      R"(DRAM Precharge commands. : Precharge due to (?) : Counts the number of DRAM Precharge commands sent on this channel.)",
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
      "UNC_M_CAS_COUNT_SCH0.RD_REG",
      EventDef::Encoding{.code = 0x05, .umask = 0xC1, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 0 regular reads)",
      R"(CAS count for SubChannel 0 regular reads)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH0.RD_UNDERFILL",
      EventDef::Encoding{.code = 0x05, .umask = 0xC4, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 0 underfill reads)",
      R"(CAS count for SubChannel 0 underfill reads)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event UNC_M_CAS_COUNT_SCH0.RD is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH0.RD",
      EventDef::Encoding{.code = 0x05, .umask = 0xCF, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 0, all reads)",
      R"(CAS count for SubChannel 0, all reads)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_M_CAS_COUNT_SCH0.WR is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH0.WR",
      EventDef::Encoding{.code = 0x05, .umask = 0xF0, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 0, all writes)",
      R"(CAS count for SubChannel 0, all writes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH0.ALL",
      EventDef::Encoding{.code = 0x05, .umask = 0xFF, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 0, all CAS operations)",
      R"(CAS count for SubChannel 0, all CAS operations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH1.RD_REG",
      EventDef::Encoding{.code = 0x06, .umask = 0xC1, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 1 regular reads)",
      R"(CAS count for SubChannel 1 regular reads)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH1.RD_UNDERFILL",
      EventDef::Encoding{.code = 0x06, .umask = 0xC4, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 1 underfill reads)",
      R"(CAS count for SubChannel 1 underfill reads)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event UNC_M_CAS_COUNT_SCH1.RD is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH1.RD",
      EventDef::Encoding{.code = 0x06, .umask = 0xCF, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 1, all reads)",
      R"(CAS count for SubChannel 1, all reads)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_M_CAS_COUNT_SCH1.WR is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH1.WR",
      EventDef::Encoding{.code = 0x06, .umask = 0xF0, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 1, all writes)",
      R"(CAS count for SubChannel 1, all writes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT_SCH1.ALL",
      EventDef::Encoding{.code = 0x06, .umask = 0xFF, .umaskExt = 0x00000000},
      R"(CAS count for SubChannel 1, all CAS operations)",
      R"(CAS count for SubChannel 1, all CAS operations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RDB_OCCUPANCY_SCH0",
      EventDef::Encoding{.code = 0x1a, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Read buffer occupancy on subchannel 0)",
      R"(Read buffer occupancy on subchannel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RDB_OCCUPANCY_SCH1",
      EventDef::Encoding{.code = 0x1b, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Read buffer occupancy on subchannel 1)",
      R"(Read buffer occupancy on subchannel 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_OCCUPANCY_SCH0_PCH0",
      EventDef::Encoding{.code = 0x80, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Read pending queue occupancy for subchannel 0, pseudochannel 0)",
      R"(Read pending queue occupancy for subchannel 0, pseudochannel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_OCCUPANCY_SCH0_PCH1",
      EventDef::Encoding{.code = 0x81, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Read pending queue occupancy for subchannel 0, pseudochannel 1)",
      R"(Read pending queue occupancy for subchannel 0, pseudochannel 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_OCCUPANCY_SCH1_PCH0",
      EventDef::Encoding{.code = 0x82, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Read pending queue occupancy for subchannel 1, pseudochannel 0)",
      R"(Read pending queue occupancy for subchannel 1, pseudochannel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_OCCUPANCY_SCH1_PCH1",
      EventDef::Encoding{.code = 0x83, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Read pending queue occupancy for subchannel 1, pseudochannel 1)",
      R"(Read pending queue occupancy for subchannel 1, pseudochannel 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_OCCUPANCY_SCH0_PCH0",
      EventDef::Encoding{.code = 0x84, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Write pending queue occupancy for subchannel 0, pseudochannel 0)",
      R"(Write pending queue occupancy for subchannel 0, pseudochannel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_OCCUPANCY_SCH0_PCH1",
      EventDef::Encoding{.code = 0x85, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Write pending queue occupancy for subchannel 0, pseudochannel 1)",
      R"(Write pending queue occupancy for subchannel 0, pseudochannel 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_OCCUPANCY_SCH1_PCH0",
      EventDef::Encoding{.code = 0x86, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Write pending queue occupancy for subchannel 1, pseudochannel 0)",
      R"(Write pending queue occupancy for subchannel 1, pseudochannel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_OCCUPANCY_SCH1_PCH1",
      EventDef::Encoding{.code = 0x87, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Write pending queue occupancy for subchannel 1, pseudochannel 1)",
      R"(Write pending queue occupancy for subchannel 1, pseudochannel 1)",
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
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(IIO Clockticks)",
      R"(IIO Clockticks)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00070010},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Four byte data request of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00070010},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.ALL_PARTS",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00070FF0},
      R"(Counts once for every 4 bytes read from this card to memory.  This event does include reads to IO.)",
      R"(Counts once for every 4 bytes read from this card to memory.  This event does include reads to IO.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.ALL_PARTS",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00070FF0},
      R"(Counts once for every 4 bytes written from this card to memory.  This event does include writes to IO.)",
      R"(Counts once for every 4 bytes written from this card to memory.  This event does include writes to IO.)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00070010},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00070010},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00070010},
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
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .umaskExt = 0x00070010},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .umaskExt = 0x00070010},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
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
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(IRP Clockticks)",
      R"(IRP Clockticks)",
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
      EventDef::Encoding{.code = 0x11, .umask = 0x08, .umaskExt = 0x00000000},
      R"(Inbound write (fast path) requests to coherent memory, received by the IRP resulting in write ownership requests issued by IRP to the mesh.)",
      R"(Inbound write (fast path) requests to coherent memory, received by the IRP resulting in write ownership requests issued by IRP to the mesh.)",
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
      EventDef::Encoding{.code = 0x18, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Inbound read requests received by the IRP and inserted into the FAF queue)",
      R"(Inbound read requests received by the IRP and inserted into the FAF queue)",
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
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Number of UPI LL clock cycles while the event is enabled)",
      R"(Number of kfclks)",
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
      EventDef::Encoding{.code = 0x02, .umask = 0x0F, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : All Data : Counts number of data flits across this UPI link.)",
      R"(Valid Flits Sent : All Data)",
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
      EventDef::Encoding{.code = 0x02, .umask = 0x27, .umaskExt = 0x00000000},
      R"(All Null Flits)",
      R"(Valid Flits Sent : Idle)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.IDLE",
      EventDef::Encoding{.code = 0x02, .umask = 0x47, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : Idle : Shows legal flit time (hides impact of L0p and L0c).)",
      R"(Valid Flits Sent)",
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
      EventDef::Encoding{.code = 0x02, .umask = 0x97, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : All Non Data : Shows legal flit time (hides impact of L0p and L0c).)",
      R"(Valid Flits Sent : Null FLITs transmitted to any slot)",
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
      EventDef::Encoding{.code = 0x03, .umask = 0x0F, .umaskExt = 0x00000000},
      R"(Valid Flits Received : All Data : Shows legal flit time (hides impact of L0p and L0c).)",
      R"(Valid Flits Received : All Data)",
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
      EventDef::Encoding{.code = 0x03, .umask = 0x97, .umaskExt = 0x00000000},
      R"(Valid Flits Received : All Non Data : Shows legal flit time (hides impact of L0p and L0c).)",
      R"(Valid Flits Received : All Non Data)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.REQ",
      EventDef::Encoding{.code = 0x05, .umask = 0x08, .umaskExt = 0x00000000},
      R"(Matches on Receive path of a UPI Port : Request)",
      R"(Matches on Receive path of a UPI Port : Request)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.WB",
      EventDef::Encoding{.code = 0x05, .umask = 0x0D, .umaskExt = 0x00000000},
      R"(Matches on Receive path of a UPI Port : Writeback)",
      R"(Matches on Receive path of a UPI Port : Writeback)",
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
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(PCU Clockticks)",
      R"(PCU Clockticks:  The PCU runs off a fixed 1 GHz clock.  This event counts the number of pclk cycles measured while the counter was enabled.  The pclk, like the Memory Controller's dclk, counts at a constant rate making it a good measure of actual wall time.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_POWER_STATE_OCCUPANCY_CORES_C0",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Number of cores in C0)",
      R"(Number of cores in C0 : This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_POWER_STATE_OCCUPANCY_CORES_C6",
      EventDef::Encoding{.code = 0x37, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Number of cores in C6)",
      R"(Number of cores in C6 : This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.)",
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
      EventDef::Encoding{.code = 0x03, .umask = 0xFF, .umaskExt = 0x00000000},
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
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00070020},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Four byte data request of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00070040},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Four byte data request of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00070080},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Four byte data request of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00070100},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Four byte data request of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00070200},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Four byte data request of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00070400},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Four byte data request of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00070800},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Four byte data request of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00070020},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Four byte data request of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00070040},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Four byte data request of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00070080},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Four byte data request of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00070100},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Four byte data request of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00070200},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Four byte data request of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00070400},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Four byte data request of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00070800},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DISTRESS_ASSERTED.DPT_IRQ",
      EventDef::Encoding{.code = 0x59, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in IRQ (immediate cause for triggering).)",
      R"(Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in IRQ (immediate cause for triggering).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DISTRESS_ASSERTED.DPT_TOR",
      EventDef::Encoding{.code = 0x59, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in TOR (immediate cause for triggering).)",
      R"(Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in TOR (immediate cause for triggering).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DISTRESS_ASSERTED.DPT_ANY",
      EventDef::Encoding{.code = 0x59, .umask = 0x03, .umaskExt = 0x00000000},
      R"(Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in TOR or IRQ (immediate cause for triggering).)",
      R"(Distress signal assertion for dynamic prefetch throttle (DPT).  Threshold for distress signal assertion reached in TOR or IRQ (immediate cause for triggering).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_chacms,
      "UNC_CHACMS_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Clockticks for CMS units attached to CHA)",
      R"(UNC_CHACMS_CLOCKTICKS)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00070020},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00070020},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00070040},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00070040},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00070080},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00070080},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00070100},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00070100},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00070200},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00070200},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00070400},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00070400},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00070800},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00070800},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
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
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00070020},
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
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00070040},
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
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00070080},
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
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00070100},
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
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART5",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00070200},
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
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00070400},
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
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART7",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .umaskExt = 0x00070800},
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
      "UNC_IIO_DATA_REQ_BY_CPU.PEER_WRITE.ALL_PARTS",
      EventDef::Encoding{.code = 0xC0, .umask = 0x02, .umaskExt = 0x00070FF0},
      R"(Data requested by the CPU : Another card (different IIO stack) writing to this card.)",
      R"(Data requested by the CPU : Another card (different IIO stack) writing to this card.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.PEER_READ.ALL_PARTS",
      EventDef::Encoding{.code = 0xC0, .umask = 0x08, .umaskExt = 0x00070FF0},
      R"(Data requested by the CPU : Another card (different IIO stack) reading from this card.)",
      R"(Data requested by the CPU : Another card (different IIO stack) reading from this card.)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .umaskExt = 0x00070020},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .umaskExt = 0x00070020},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .umaskExt = 0x00070040},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .umaskExt = 0x00070040},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .umaskExt = 0x00070080},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .umaskExt = 0x00070080},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .umaskExt = 0x00070100},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .umaskExt = 0x00070100},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .umaskExt = 0x00070200},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .umaskExt = 0x00070200},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .umaskExt = 0x00070400},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .umaskExt = 0x00070400},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .umaskExt = 0x00070800},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
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
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .umaskExt = 0x00070800},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.ALL_PARTS",
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .umaskExt = 0x00070FF0},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.PEER_WRITE.ALL_PARTS",
      EventDef::Encoding{.code = 0xC1, .umask = 0x02, .umaskExt = 0x00070FF0},
      R"(Number Transactions requested by the CPU : Another card (different IIO stack) writing to this card.)",
      R"(Number Transactions requested by the CPU : Another card (different IIO stack) writing to this card.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.ALL_PARTS",
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .umaskExt = 0x00070FF0},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.PEER_READ.ALL_PARTS",
      EventDef::Encoding{.code = 0xC1, .umask = 0x08, .umaskExt = 0x00070FF0},
      R"(Number Transactions requested by the CPU : Another card (different IIO stack) reading from this card.)",
      R"(Number Transactions requested by the CPU : Another card (different IIO stack) reading from this card.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_INSERTS.SCH0_PCH0",
      EventDef::Encoding{.code = 0x10, .umask = 0x10, .umaskExt = 0x00000000},
      R"(Read Pending Queue inserts for subchannel 0, pseudochannel 0)",
      R"(Read Pending Queue inserts for subchannel 0, pseudochannel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_INSERTS.SCH0_PCH1",
      EventDef::Encoding{.code = 0x10, .umask = 0x20, .umaskExt = 0x00000000},
      R"(Read Pending Queue inserts for subchannel 0, pseudochannel 1)",
      R"(Read Pending Queue inserts for subchannel 0, pseudochannel 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_INSERTS.SCH1_PCH0",
      EventDef::Encoding{.code = 0x10, .umask = 0x40, .umaskExt = 0x00000000},
      R"(Read Pending Queue inserts for subchannel 1, pseudochannel 0)",
      R"(Read Pending Queue inserts for subchannel 1, pseudochannel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_INSERTS.SCH1_PCH1",
      EventDef::Encoding{.code = 0x10, .umask = 0x80, .umaskExt = 0x00000000},
      R"(Read Pending Queue inserts for subchannel 1, pseudochannel 1)",
      R"(Read Pending Queue inserts for subchannel 1, pseudochannel 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_INSERTS.SCH0_PCH0",
      EventDef::Encoding{.code = 0x22, .umask = 0x10, .umaskExt = 0x00000000},
      R"(Write Pending Queue inserts for subchannel 0, pseudochannel 0)",
      R"(Write Pending Queue inserts for subchannel 0, pseudochannel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_INSERTS.SCH0_PCH1",
      EventDef::Encoding{.code = 0x22, .umask = 0x20, .umaskExt = 0x00000000},
      R"(Write Pending Queue inserts for subchannel 0, pseudochannel 1)",
      R"(Write Pending Queue inserts for subchannel 0, pseudochannel 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_INSERTS.SCH1_PCH0",
      EventDef::Encoding{.code = 0x22, .umask = 0x40, .umaskExt = 0x00000000},
      R"(Write Pending Queue inserts for subchannel 1, pseudochannel 0)",
      R"(Write Pending Queue inserts for subchannel 1, pseudochannel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_INSERTS.SCH1_PCH1",
      EventDef::Encoding{.code = 0x22, .umask = 0x80, .umaskExt = 0x00000000},
      R"(Write Pending Queue inserts for subchannel 1, pseudochannel 1)",
      R"(Write Pending Queue inserts for subchannel 1, pseudochannel 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.LLC_OR_SF_EVICTIONS",
      EventDef::Encoding{.code = 0x35, .umask = 0x02, .umaskExt = 0x00C001FF},
      R"(TOR Inserts for SF or LLC Evictions)",
      R"(TOR allocation occurred as a result of SF/LLC evictions (came from the ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REMOTE_SF.MISS",
      EventDef::Encoding{.code = 0x69, .umask = 0x04, .umaskExt = 0x00000000},
      R"(UNC_CHA_REMOTE_SF.MISS)",
      R"(UNC_CHA_REMOTE_SF.MISS)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C826FE},
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd_Opt, and which target local memory)",
      R"(TOR Inserts : DRd_Opt issued by iA Cores that Missed the LLC - HOMed locally)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_PREF_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8A6FE},
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF_OPT, and target local memory)",
      R"(TOR Inserts : Data read opt prefetch from local iA that missed the LLC targeting local memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8277E},
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd_Opt, and target remote memory)",
      R"(TOR Inserts : Data read opt from local iA that missed the LLC targeting remote memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_PREF_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8A77E},
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF_OPT, and target remote memory)",
      R"(TOR Inserts : Data read opt prefetch from local iA that missed the LLC targeting remote memory)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CD42FF},
      R"(ItoMCacheNear (partial write) transactions from an IO device that addresses memory on the local socket)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that address memory on the local socket)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CD437F},
      R"(ItoMCacheNear (partial write) transactions from an IO device that addresses memory on a remote socket)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that address memory on a remote socket)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CC42FF},
      R"(ItoM (write) transactions from an IO device that addresses memory on the local socket)",
      R"(TOR Inserts : ItoM, indicating a write request, from IO Devices that address memory on the local socket)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CC437F},
      R"(ItoM (write) transactions from an IO device that addresses memory on a remote socket)",
      R"(TOR Inserts : ItoM, indicating a write request, from IO Devices that address memory on a remote socket)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C8F2FF},
      R"(PCIRDCUR (read) transactions from an IO device that addresses memory on the local socket)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices that addresses memory on the local socket)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00C8F37F},
      R"(PCIRDCUR (read) transactions from an IO device that addresses memory on a remote socket)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices that addresses memory on a remote socket)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace sierraforest_uncore
} // namespace facebook::hbt::perf_event::generated
