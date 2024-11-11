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
namespace emeraldrapids_uncore {

void addEvents(PmuDeviceManager& pmu_manager) {
/*
  Events from emeraldrapids_uncore.json (287 events).

  Supported SKUs:
      - Arch: x86, Model: EMR id: 207
*/
#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(PCU PCLK Clockticks)",
      R"(Number of PCU PCLK Clock cycles while the event is enabled)",
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
      R"(Number of IRP clock cycles while the event is enabled)",
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
      EventDef::Encoding{.code = 0x16, .umask = 0x00, .umaskExt = 0x00000000},
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
      PmuType::uncore_irp,
      "UNC_I_FAF_FULL",
      EventDef::Encoding{.code = 0x17, .umask = 0x00, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x18, .umask = 0x00, .umaskExt = 0x00000000},
      R"(FAF - request insert from TC.)",
      R"(FAF - request insert from TC.)",
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
      "UNC_I_MISC1.LOST_FWD",
      EventDef::Encoding{.code = 0x1f, .umask = 0x10, .umaskExt = 0x00000000},
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
      "UNC_I_IRP_ALL.INBOUND_INSERTS",
      EventDef::Encoding{.code = 0x20, .umask = 0x01, .umaskExt = 0x00000000},
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
      PmuType::uncore_m2pcie,
      "UNC_M2P_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(M2P Clockticks)",
      R"(Number of M2P clock cycles while the event is enabled)",
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
      PmuType::uncore_iio,
      "UNC_IIO_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(IIO Clockticks)",
      R"(Number of IIO clock cycles while the event is enabled)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of 4 bytes made by IIO Part0 to Memory)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of 4 bytes made by IIO Part1 to Memory)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of 4 bytes made by IIO Part2 to Memory)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of 4 bytes made by IIO Part3 to Memory)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for 4 bytes made by IIO Part0 to Memory)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for 4 bytes made by IIO Part1 to Memory)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for 4 bytes made by IIO Part2 to Memory)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for 4 bytes made by IIO Part3 to Memory)",
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
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Data requested of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Data requested of the CPU : Card writing to DRAM)",
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
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Data requested of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Data requested of the CPU : Card writing to DRAM)",
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
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Data requested of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Data requested of the CPU : Card reading from DRAM)",
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
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Data requested of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Data requested of the CPU : Card reading from DRAM)",
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
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of up to a 64 byte transaction is made by IIO Part0 to Memory)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of up to a 64 byte transaction is made by IIO Part1 to Memory)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of up to a 64 byte transaction is made by IIO Part2 to Memory)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of up to a 64 byte transaction is made by IIO Part3 to Memory)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for up to a 64 byte transaction is made by IIO Part0 to Memory)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for up to a 64 byte transaction is  made by IIO Part1 to Memory)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for up to a 64 byte transaction is made by IIO Part2 to Memory)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for up to a 64 byte transaction is made by IIO Part3 to Memory)",
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
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00000000},
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
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .umaskExt = 0x00000000},
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
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART4",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00000000},
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
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART6",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .umaskExt = 0x00000000},
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
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of 4 bytes made to IIO Part0 by the CPU)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of 4 bytes made to IIO Part1 by the CPU)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of 4 bytes made to IIO Part2 by the CPU)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of 4 bytes made to IIO Part3 by the CPU)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00070010},
      R"(Read request for 4 bytes made by the CPU to IIO Part0)",
      R"(Data requested by the CPU : Core reading from Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00070020},
      R"(Read request for 4 bytes made by the CPU to IIO Part1)",
      R"(Data requested by the CPU : Core reading from Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00070040},
      R"(Read request for 4 bytes made by the CPU to IIO Part2)",
      R"(Data requested by the CPU : Core reading from Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00070080},
      R"(Read request for 4 bytes made by the CPU to IIO Part3)",
      R"(Data requested by the CPU : Core reading from Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      R"(Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      R"(Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      R"(Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      R"(Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00070100},
      R"(Data requested by the CPU : Core reading from Cards MMIO space)",
      R"(Data requested by the CPU : Core reading from Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00070200},
      R"(Data requested by the CPU : Core reading from Cards MMIO space)",
      R"(Data requested by the CPU : Core reading from Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00070400},
      R"(Data requested by the CPU : Core reading from Cards MMIO space)",
      R"(Data requested by the CPU : Core reading from Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x04, .umaskExt = 0x00070800},
      R"(Data requested by the CPU : Core reading from Cards MMIO space)",
      R"(Data requested by the CPU : Core reading from Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of up to a 64 byte transaction is made to IIO Part0 by the CPU)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of up to a 64 byte transaction is made to IIO Part1 by the CPU)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of up to a 64 byte transaction is made to IIO Part2 by the CPU)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of up to a 64 byte transaction is made to IIO Part3 by the CPU)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part0)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part1)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part2)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part3)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
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
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
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
      R"(IMC Clockticks at DCLK frequency)",
      R"(Number of DRAM DCLK clock cycles while the event is enabled)",
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
      R"(IMC Clockticks at HCLK frequency)",
      R"(Number of DRAM HCLK clock cycles while the event is enabled)",
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
      EventDef::Encoding{.code = 0x02, .umask = 0xff, .umaskExt = 0x00000000},
      R"(Activate due to read, write, underfill, or bypass)",
      R"(DRAM Activate Count : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.)",
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
      EventDef::Encoding{.code = 0x03, .umask = 0x11, .umaskExt = 0x00000000},
      R"(Precharge due to read on page miss)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
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
      EventDef::Encoding{.code = 0x03, .umask = 0x22, .umaskExt = 0x00000000},
      R"(Precharge due to write on page miss)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
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
      EventDef::Encoding{.code = 0x03, .umask = 0x88, .umaskExt = 0x00000000},
      R"(DRAM Precharge commands)",
      R"(DRAM Precharge commands.  Counts the number of DRAM Precharge commands sent on this channel.)",
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
      EventDef::Encoding{.code = 0x03, .umask = 0xff, .umaskExt = 0x00000000},
      R"(Precharge due to read, write, underfill, or PGT.)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
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
      EventDef::Encoding{.code = 0x05, .umask = 0xcf, .umaskExt = 0x00000000},
      R"(All DRAM read CAS commands issued (including underfills))",
      R"(DRAM RD_CAS and WR_CAS Commands : Counts the total number of DRAM Read CAS commands issued on this channel.  This includes underfills.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_M_CAS_COUNT.WR is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR",
      EventDef::Encoding{.code = 0x05, .umask = 0xf0, .umaskExt = 0x00000000},
      R"(All DRAM write CAS commands issued)",
      R"(DRAM RD_CAS and WR_CAS Commands : Counts the total number of DRAM Write CAS commands issued on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.ALL",
      EventDef::Encoding{.code = 0x05, .umask = 0xff, .umaskExt = 0x00000000},
      R"(All DRAM CAS commands issued)",
      R"(DRAM RD_CAS and WR_CAS Commands. : All DRAM Read and Write actions : DRAM RD_CAS and WR_CAS Commands : Counts the total number of DRAM CAS commands issued on this channel.)",
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
      EventDef::Encoding{.code = 0x10, .umask = 0x01, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x10, .umask = 0x02, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x20, .umask = 0x01, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x20, .umask = 0x02, .umaskExt = 0x00000000},
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
      "UNC_M_RPQ_OCCUPANCY_PCH0",
      EventDef::Encoding{.code = 0x80, .umask = 0x00, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x81, .umask = 0x00, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x82, .umask = 0x00, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x83, .umask = 0x00, .umaskExt = 0x00000000},
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
      "UNC_M_TAGCHK.HIT",
      EventDef::Encoding{.code = 0xd3, .umask = 0x01, .umaskExt = 0x00000000},
      R"(2LM Tag check hit in near memory cache (DDR4))",
      R"(2LM Tag check hit in near memory cache (DDR4))",
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
      EventDef::Encoding{.code = 0xd3, .umask = 0x02, .umaskExt = 0x00000000},
      R"(2LM Tag check miss, no data at this line)",
      R"(2LM Tag check miss, no data at this line)",
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
      EventDef::Encoding{.code = 0xd3, .umask = 0x04, .umaskExt = 0x00000000},
      R"(2LM Tag check miss, existing data may be evicted to PMM)",
      R"(2LM Tag check miss, existing data may be evicted to PMM)",
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
      EventDef::Encoding{.code = 0xd3, .umask = 0x08, .umaskExt = 0x00000000},
      R"(2LM Tag check hit due to memory read)",
      R"(2LM Tag check hit due to memory read)",
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
      EventDef::Encoding{.code = 0xd3, .umask = 0x10, .umaskExt = 0x00000000},
      R"(2LM Tag check hit due to memory write)",
      R"(2LM Tag check hit due to memory write)",
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
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(M2M Clockticks)",
      R"(Clockticks of the mesh to memory (M2M))",
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
      EventDef::Encoding{.code = 0x20, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Multi-socket cacheline Directory lookups (any state found))",
      R"(Counts the number of hit data returns to egress with any directory to non persistent memory)",
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
      EventDef::Encoding{.code = 0x20, .umask = 0x08, .umaskExt = 0x00000000},
      R"(Multi-socket cacheline Directory lookups (cacheline found in A state))",
      R"(Counts the number of hit data returns to egress with directory A to non persistent memory)",
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
      EventDef::Encoding{.code = 0x20, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Multi-socket cacheline Directory lookup (cacheline found in I state))",
      R"(Counts the number of hit data returns to egress with directory I to non persistent memory)",
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
      EventDef::Encoding{.code = 0x20, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Multi-socket cacheline Directory lookup (cacheline found in S state))",
      R"(Counts the number of hit data returns to egress with directory S to non persistent memory)",
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
      EventDef::Encoding{.code = 0x21, .umask = 0x01, .umaskExt = 0x03},
      R"(Multi-socket cacheline Directory update from/to Any state)",
      R"(Multi-socket cacheline Directory update from/to Any state)",
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
      EventDef::Encoding{.code = 0xc0, .umask = 0x00, .umaskExt = 0x800000},
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
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(M3UPI Clockticks)",
      R"(Number of M2UPI clock cycles while the event is enabled)",
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
      R"(UPI Clockticks)",
      R"(Number of UPI LL clock cycles while the event is enabled)",
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
      EventDef::Encoding{.code = 0x02, .umask = 0x0f, .umaskExt = 0x00000000},
      R"(Valid Flits Sent : All Data)",
      R"(Valid Flits Sent : All Data : Counts number of data flits across this UPI link.)",
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
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.ALL_NULL",
      EventDef::Encoding{.code = 0x02, .umask = 0x27, .umaskExt = 0x00000000},
      R"(All Null Flits)",
      R"(All Null Flits)",
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
      EventDef::Encoding{.code = 0x03, .umask = 0x0f, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x03, .umask = 0x97, .umaskExt = 0x00000000},
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
      "UNC_UPI_RxL_FLITS.ALL_NULL",
      EventDef::Encoding{.code = 0x03, .umask = 0x27, .umaskExt = 0x00000000},
      R"(Null FLITs received from any slot)",
      R"(Null FLITs received from any slot)",
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
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.INVITOE_LOCAL",
      EventDef::Encoding{.code = 0x50, .umask = 0x10, .umaskExt = 0x00000000},
      R"(Local requests for exclusive ownership of a cache line  without receiving data)",
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
      R"(Remote requests for exclusive ownership of a cache line  without receiving data)",
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
      EventDef::Encoding{.code = 0x50, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Read requests from a unit on this socket)",
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
      R"(Read requests from a remote socket)",
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
      R"(Write Requests from a unit on this socket)",
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
      R"(Read and Write Requests; Writes Remote)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.READS",
      EventDef::Encoding{.code = 0x50, .umask = 0x03, .umaskExt = 0x00000000},
      R"(Read requests made into the CHA)",
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
      EventDef::Encoding{.code = 0x50, .umask = 0x0c, .umaskExt = 0x00000000},
      R"(Write requests made into the CHA)",
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
      "UNC_CHA_DIR_UPDATE.HA",
      EventDef::Encoding{.code = 0x54, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Multi-socket cacheline Directory state updates; Directory Updated memory write from the HA pipe)",
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
      R"(Multi-socket cacheline Directory state updates; Directory Updated memory write from TOR pipe)",
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
      "UNC_CHA_IMC_READS_COUNT.NORMAL",
      EventDef::Encoding{.code = 0x59, .umask = 0x01, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x5b, .umask = 0x01, .umaskExt = 0x00000000},
      R"(CHA to iMC Full Line Writes Issued; Full Line Non-ISOCH)",
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
      "UNC_CHA_CMS_CLOCKTICKS",
      EventDef::Encoding{.code = 0xc0, .umask = 0x00, .umaskExt = 0x00000000},
      R"(CMS Clockticks)",
      R"(CMS Clockticks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event UNC_CHA_CLOCKTICKS is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .umaskExt = 0x00000000},
      R"(CHA Clockticks)",
      R"(Number of CHA clock cycles while the event is enabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c001ff},
      R"(TOR Inserts; All from Local IA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; All locally initiated requests from IA Cores)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c001fd},
      R"(TOR Inserts; Hits from Local IA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c80ffd},
      R"(TOR Inserts; CRd hits from local IA)",
      R"(TOR Inserts; Code read from local IA that hits in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c817fd},
      R"(TOR Inserts; DRd hits from local IA)",
      R"(TOR Inserts; Data read from local IA that hits in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00ccc7fd},
      R"(TOR Inserts; LLCPrefRFO hits from local IA)",
      R"(TOR Inserts; Last level cache prefetch read for ownership from local IA that hits in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c807fd},
      R"(TOR Inserts; RFO hits from local IA)",
      R"(TOR Inserts; Read for ownership from local IA that hits in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c001fe},
      R"(TOR Inserts; misses from Local IA)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c80ffe},
      R"(TOR Inserts for CRd misses from local IA)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode CRd)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c817fe},
      R"(TOR Inserts for DRd misses from local IA)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00ccc7fe},
      R"(TOR Inserts; LLCPrefRFO misses from local IA)",
      R"(TOR Inserts; Last level cache prefetch read for ownership from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c807fe},
      R"(TOR Inserts; RFO misses from local IA)",
      R"(TOR Inserts; Read for ownership from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00c001ff},
      R"(TOR Inserts; All from local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00c001fd},
      R"(TOR Inserts; Hits from local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00c001fe},
      R"(TOR Inserts; Misses from local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00cc43fe},
      R"(TOR Inserts : ItoM, indicating a full cacheline write request, from IO Devices that missed the LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00c803fe},
      R"(TOR Inserts; RFO misses from local IO)",
      R"(TOR Inserts : RFOs issued by IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c88ffd},
      R"(TOR Inserts; CRd Pref hits from local IA)",
      R"(TOR Inserts; Code read prefetch from local IA that hits in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c897fd},
      R"(TOR Inserts; DRd Pref hits from local IA)",
      R"(TOR Inserts; Data read prefetch from local IA that hits in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c887fd},
      R"(TOR Inserts; RFO Pref hits from local IA)",
      R"(TOR Inserts; Read for ownership prefetch from local IA that hits in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c88ffe},
      R"(TOR Inserts; CRd Pref misses from local IA)",
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
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c897fe},
      R"(TOR Inserts for DRd Pref misses from local IA)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c887fe},
      R"(TOR Inserts; RFO pref misses from local IA)",
      R"(TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00cc43fd},
      R"(TOR Inserts; ItoM hits from local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00c803fd},
      R"(TOR Inserts; RFO hits from local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00c803ff},
      R"(TOR Inserts; RFO from local IO)",
      R"(TOR Inserts : RFOs issued by IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00cc43ff},
      R"(TOR Inserts for ItoM from local IO)",
      R"(Inserts into the TOR from local IO with the opcode ItoM)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c887ff},
      R"(TOR Inserts; RFO pref from local IA)",
      R"(TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c807ff},
      R"(TOR Inserts; RFO from local IA)",
      R"(TOR Inserts; Read for ownership from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00ccc7ff},
      R"(TOR Inserts; LLCPrefRFO from local IA)",
      R"(TOR Inserts; Last level cache prefetch read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_DRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c817ff},
      R"(TOR Inserts; DRd from local IA)",
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
      "UNC_CHA_TOR_INSERTS.IA_DRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c897ff},
      R"(TOR Inserts; DRd Pref from local IA)",
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
      "UNC_CHA_TOR_INSERTS.IA_CRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c80fff},
      R"(TOR Inserts; CRd from local IA)",
      R"(TOR Inserts; Code read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

  // Event UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c816fe},
      R"(TOR Inserts for DRd misses from local IA targeting local memory)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target local memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c8177e},
      R"(TOR Inserts for DRd misses from local IA targeting remote memory)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and target remote memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C896FE},
      R"(TOR Inserts for DRd Pref misses from local IA targeting local memory)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF, and target local memory)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00C8977E},
      R"(TOR Inserts for DRd Pref misses from local IA targeting remote memory)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF, and target remote memory)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c806fe},
      R"(TOR Inserts RFO misses from local IA)",
      R"(TOR Inserts; Read for ownership from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c8077e},
      R"(TOR Inserts; RFO misses from local IA)",
      R"(TOR Inserts Read for ownership from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c886fe},
      R"(TOR Inserts; RFO prefetch misses from local IA)",
      R"(TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c8877e},
      R"(TOR Inserts; RFO prefetch misses from local IA)",
      R"(TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c8c7ff},
      R"(TOR Inserts;CLFlush from Local IA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; CLFlush events that are initiated from the Core)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00cc57ff},
      R"(TOR Inserts;SpecItoM from Local IA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; SpecItoM events that are initiated from the Core)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c001ff},
      R"(TOR Occupancy; All from local IA)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c001fd},
      R"(TOR Occupancy; Hits from local IA)",
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
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_CRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c80ffd},
      R"(TOR Occupancy; CRd hits from local IA)",
      R"(TOR Occupancy; Code read from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c817fd},
      R"(TOR Occupancy; DRd hits from local IA)",
      R"(TOR Occupancy; Data read from local IA that hits in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00ccc7fd},
      R"(TOR Occupancy; LLCPrefRFO hits from local IA)",
      R"(TOR Occupancy; Last level cache prefetch read for ownership from local IA that hits in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c807fd},
      R"(TOR Occupancy; RFO hits from local IA)",
      R"(TOR Occupancy; Read for ownership from local IA that hits in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c001fe},
      R"(TOR Occupancy; Misses from Local IA)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c80ffe},
      R"(TOR Occupancy; CRd misses from local IA)",
      R"(TOR Occupancy; Code read from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c817fe},
      R"(TOR Occupancy for DRd misses from local IA)",
      R"(Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00ccc7fe},
      R"(TOR Occupancy; LLCPrefRFO misses from local IA)",
      R"(TOR Occupancy; Last level cache prefetch read for ownership from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c807fe},
      R"(TOR Occupancy; RFO misses from local IA)",
      R"(TOR Occupancy; Read for ownership from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00c001ff},
      R"(TOR Occupancy; All from local IO)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00c001fd},
      R"(TOR Occupancy; Hits from local IO)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00c001fe},
      R"(TOR Occupancy; Misses from local IO)",
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
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00cc43fe},
      R"(TOR Occupancy; ITOM misses from local IO)",
      R"(TOR Occupancy : ItoMs issued by IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c88ffd},
      R"(TOR Occupancy; CRd Pref hits from local IA)",
      R"(TOR Occupancy; Code read prefetch from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c897fd},
      R"(TOR Occupancy; DRd Pref hits from local IA)",
      R"(TOR Occupancy; Data read prefetch from local IA that hits in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c887fd},
      R"(TOR Occupancy; RFO Pref hits from local IA)",
      R"(TOR Occupancy; Read for ownership prefetch from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c897fe},
      R"(TOR Occupancy; DRd Pref misses from local IA)",
      R"(TOR Occupancy; Data read prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c887fe},
      R"(TOR Occupancy; RFO prefetch misses from local IA)",
      R"(TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00cc43fd},
      R"(TOR Occupancy; ITOM hits from local IO)",
      R"(TOR Occupancy : ItoMs issued by IO Devices that Hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00cc43ff},
      R"(TOR Occupancy; ITOM from local IO)",
      R"(TOR Occupancy : ItoMs issued by IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c807ff},
      R"(TOR Occupancy; RFO from local IA)",
      R"(TOR Occupancy; Read for ownership from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c887ff},
      R"(TOR Occupancy; RFO prefetch from local IA)",
      R"(TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00ccc7ff},
      R"(TOR Occupancy; LLCPrefRFO from local IA)",
      R"(TOR Occupancy; Last level cache prefetch read for ownership from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c817ff},
      R"(TOR Occupancy; DRd from local IA)",
      R"(TOR Occupancy; Data read from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c80fff},
      R"(TOR Occupancy; CRd from local IA)",
      R"(TOR Occupancy; Code read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_DRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c897ff},
      R"(TOR Occupancy; DRd Pref from local IA)",
      R"(TOR Occupancy; Data read prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c816fe},
      R"(TOR Occupancy for DRd misses from local IA targeting local memory)",
      R"(Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target local memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  // Event UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE is allowlisted
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c8177e},
      R"(TOR Occupancy for DRd misses from local IA targeting remote memory)",
      R"(Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target remote memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00C8977E},
      R"(TOR Occupancy; DRd Pref misses from local IA)",
      R"(TOR Occupancy; Data read prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c806fe},
      R"(TOR Occupancy; RFO misses from local IA)",
      R"(TOR Occupancy; Read for ownership from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c8077e},
      R"(TOR Occupancy; RFO misses from local IA)",
      R"(TOR Occupancy; Read for ownership from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c886fe},
      R"(TOR Occupancy; RFO prefetch misses from local IA)",
      R"(TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c8877e},
      R"(TOR Occupancy; RFO prefetch misses from local IA)",
      R"(TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c8178a},
      R"(TOR Inserts for DRds issued by iA Cores targeting PMM Mem that Missed the LLC)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target PMM memory)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c81786},
      R"(TOR Inserts for DRds issued by IA Cores targeting DDR Mem that Missed the LLC)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target DDR memory)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00cd43fd},
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00cd43fe},
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
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c81786},
      R"(TOR Occupancy for DRds issued by iA Cores targeting DDR Mem that Missed the LLC)",
      R"(Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target DDR memory)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c8178a},
      R"(TOR Occupancy for DRds issued by iA Cores targeting PMM Mem that Missed the LLC)",
      R"(Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target PMM memory)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00c8f3fd},
      R"(TOR Inserts; RdCur and FsRdCur hits from local IO)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x24, .umask = 0x20, .umaskExt = 0x00000003},
      R"(UNC_M2M_IMC_READS.TO_PMM)",
      R"(UNC_M2M_IMC_READS.TO_PMM)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00c8f3fe},
      R"(TOR Inserts; RdCur and FsRdCur requests from local IO that miss LLC)",
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
      "UNC_CHA_TOR_INSERTS.IO_PCIRDCUR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00c8f3ff},
      R"(TOR Inserts for RdCur from local IO)",
      R"(Inserts into the TOR from local IO with the opcode RdCur)",
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
      EventDef::Encoding{.code = 0x25, .umask = 0x80, .umaskExt = 0x00000018},
      R"(PMM - All Channels)",
      R"(PMM - All Channels)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00c8f3fd},
      R"(TOR Occupancy; RdCur and FsRdCur hits from local IO)",
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00c8f3fe},
      R"(TOR Occupancy; RdCur and FsRdCur misses from local IO)",
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
      "UNC_CHA_TOR_OCCUPANCY.IO_PCIRDCUR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00c8f3ff},
      R"(TOR Occupancy; RdCur and FsRdCur from local IO)",
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
      "UNC_CHA_TOR_INSERTS.IA_LLCPREFDATA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00ccd7ff},
      R"(TOR Inserts; LLCPrefData from local IA)",
      R"(TOR Inserts; Last level cache prefetch data read from local IA.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00ccd7fe},
      R"(TOR Inserts; LLCPrefData misses from local IA)",
      R"(TOR Inserts; Last level cache prefetch data read from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00ccd7ff},
      R"(TOR Occupancy; LLCPrefData from local IA)",
      R"(TOR Occupancy; Last level cache prefetch data read from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00ccd7fe},
      R"(TOR Occupancy; LLCPrefData misses from local IA)",
      R"(TOR Occupancy; Last level cache prefetch data read from local IA that misses in the snoop filter)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00cd43ff},
      R"(TOR Inserts for ItoMCacheNears from IO devices.)",
      R"(Inserts into the TOR from local IO devices with the opcode ItoMCacheNears.  This event indicates a partial write request.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_RPQ_OCCUPANCY.ALL_SCH0",
      EventDef::Encoding{.code = 0xe0, .umask = 0x01, .umaskExt = 0x00000000},
      R"(PMM Read Pending Queue occupancy)",
      R"(Accumulates the per cycle occupancy of the PMM Read Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_RPQ_OCCUPANCY.ALL_SCH1",
      EventDef::Encoding{.code = 0xe0, .umask = 0x02, .umaskExt = 0x00000000},
      R"(PMM Read Pending Queue occupancy)",
      R"(Accumulates the per cycle occupancy of the PMM Read Pending Queue.)",
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
      EventDef::Encoding{.code = 0xe3, .umask = 0x00, .umaskExt = 0x00000000},
      R"(PMM Read Pending Queue inserts)",
      R"(Counts number of read requests allocated in the PMM Read Pending Queue.)",
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
      EventDef::Encoding{.code = 0xe4, .umask = 0x03, .umaskExt = 0x00},
      R"(PMM Write Pending Queue Occupancy)",
      R"(PMM Write Pending Queue Occupancy : Accumulates the per cycle occupancy of the Write Pending Queue to the PMM DIMM.)",
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
      EventDef::Encoding{.code = 0xe7, .umask = 0x00, .umaskExt = 0x00000000},
      R"(PMM Write Pending Queue inserts)",
      R"(Counts number of  write requests allocated in the PMM Write Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RDB_INSERTS.PCH0",
      EventDef::Encoding{.code = 0x17, .umask = 0x01, .umaskExt = 0x00},
      R"(Read Data Buffer Inserts)",
      R"(Read Data Buffer Inserts)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RDB_INSERTS.PCH1",
      EventDef::Encoding{.code = 0x17, .umask = 0x02, .umaskExt = 0x00},
      R"(Read Data Buffer Inserts)",
      R"(Read Data Buffer Inserts)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_WPQ_OCCUPANCY.ALL_SCH0",
      EventDef::Encoding{.code = 0xE4, .umask = 0x01, .umaskExt = 0x00000000},
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
      PmuType::uncore_imc,
      "UNC_M_PMM_WPQ_OCCUPANCY.ALL_SCH1",
      EventDef::Encoding{.code = 0xE4, .umask = 0x02, .umaskExt = 0x00000000},
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
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c8168a},
      R"(TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c8170a},
      R"(TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c81686},
      R"(TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .umaskExt = 0x00c81706},
      R"(TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      R"(TOR Inserts : WbMtoIs issued by IO Devices)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      R"(TOR Inserts : CLFlushes issued by IO Devices)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c8168a},
      R"(TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally)",
      R"(TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c8170a},
      R"(TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c81686},
      R"(TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally)",
      R"(TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c81706},
      R"(TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00c8c7ff},
      R"(TOR Occupancy : CLFlushes issued by iA Cores)",
      R"(TOR Occupancy : CLFlushes issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .umaskExt = 0x00cc57ff},
      R"(TOR Occupancy : SpecItoMs issued by iA Cores)",
      R"(TOR Occupancy : SpecItoMs issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00cd43fd},
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC)",
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .umaskExt = 0x00cd43fe},
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC)",
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
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
      EventDef::Encoding{.code = 0x1F, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Clean NearMem Read Hit)",
      R"(Counts clean full line read hits (reads and RFOs).)",
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
      EventDef::Encoding{.code = 0x1F, .umask = 0x02, .umaskExt = 0x00000000},
      R"(Dirty NearMem Read Hit)",
      R"(Counts dirty full line read hits (reads and RFOs).)",
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
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .umaskExt = 0x00000000},
      R"(Free running counter that increments for IIO clocktick)",
      R"(0)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00000000},
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
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .umaskExt = 0x00000000},
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
      "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00000000},
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
      "UNC_IIO_TXN_REQ_OF_CPU.CMPD.PART4",
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00000000},
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
      EventDef::Encoding{.code = 0x84, .umask = 0x80, .umaskExt = 0x00000000},
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
      PmuType::uncore_iio,
      "UNC_IIO_NUM_REQ_OF_CPU.COMMIT.ALL",
      EventDef::Encoding{.code = 0x85, .umask = 0x01, .umaskExt = 0x00000000},
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
      PmuType::uncore_irp,
      "UNC_I_SNOOP_RESP.ALL_HIT_M",
      EventDef::Encoding{.code = 0x12, .umask = 0x78, .umaskExt = 0x00000000},
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
      PmuType::uncore_irp,
      "UNC_I_TRANSACTIONS.WR_PREF",
      EventDef::Encoding{.code = 0x11, .umask = 0x08, .umaskExt = 0x00000000},
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
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.ALL_PARTS",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .umaskExt = 0x00000000},
      R"(Read request for 4 bytes made by IIO Part0-7 to Memory)",
      R"(Read request for 4 bytes made by IIO Part0-7 to Memory)",
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
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .umaskExt = 0x00000000},
      R"(Write request of 4 bytes made by IIO Part0-7 to Memory)",
      R"(Write request of 4 bytes made by IIO Part0-7 to Memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS

#ifdef HBT_ADD_ALL_GENERATED_EVENTS
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_mchbm,
      "UNC_MCHBM_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x01, .umaskExt = 0x00000000},
      R"(IMC Clockticks at DCLK frequency)",
      R"(IMC Clockticks at DCLK frequency)",
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
      R"(PCIRDCUR (read) transactions from an IO device that addresses memory on a remote socket)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      R"(PCIRDCUR (read) transactions from an IO device that addresses memory on the local socket)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      "UNC_CHA_TOR_INSERTS.IO_ITOMCACHENEAR_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .umaskExt = 0x00CD42FF},
      R"(ItoMCacheNear (partial write) transactions from an IO device that addresses memory on the local socket)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
#endif // HBT_ADD_ALL_GENERATED_EVENTS
}

} // namespace emeraldrapids_uncore
} // namespace facebook::hbt::perf_event::generated
