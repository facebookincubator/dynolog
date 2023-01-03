// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace sapphirerapids_uncore_experimental {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from sapphirerapids_uncore_experimental.json (470 experimental
    events).

    Supported SKUs:
        - Arch: x86, Model: SPR id: 143
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_FAF_TRANSACTIONS",
      EventDef::Encoding{.code = 0x16, .umask = 0x00, .msr_values = {0x00}},
      R"(FAF allocation -- sent to ADQ)",
      R"(FAF allocation -- sent to ADQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_FAF_INSERTS",
      EventDef::Encoding{.code = 0x18, .umask = 0x00, .msr_values = {0x00}},
      R"(FAF - request insert from TC.)",
      R"(FAF - request insert from TC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_FAF_OCCUPANCY",
      EventDef::Encoding{.code = 0x19, .umask = 0x00, .msr_values = {0x00}},
      R"(FAF occupancy)",
      R"(FAF occupancy)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_IRP_ALL.INBOUND_INSERTS",
      EventDef::Encoding{.code = 0x20, .umask = 0x01, .msr_values = {0x00}},
      R"(: All Inserts Inbound (p2p + faf + cset))",
      R"(: All Inserts Inbound (p2p + faf + cset))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_CMS_CLOCKTICKS",
      EventDef::Encoding{.code = 0xc0, .umask = 0x00, .msr_values = {0x00}},
      R"(CMS Clockticks)",
      R"(CMS Clockticks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.MISSES",
      EventDef::Encoding{.code = 0x40, .umask = 0x20, .msr_values = {0x00}},
      R"(IOTLB Fills (same as IOTLB miss))",
      R"(IOTLB Fills (same as IOTLB miss) : When a transaction misses IOTLB, it does a page walk to look up memory and bring in the relevant page translation. Counts when this page translation is written to IOTLB.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_PWT_OCCUPANCY",
      EventDef::Encoding{.code = 0x42, .umask = 0xff, .msr_values = {0x00}},
      R"(PWT occupancy.  Does not include 9th bit of occupancy (will undercount if PWT is greater than 255 per cycle).)",
      R"(PWT occupancy : Indicates how many page walks are outstanding at any point in time.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by IIO Part0 to Memory)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by IIO Part1 to Memory)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by IIO Part2 to Memory)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by IIO Part3 to Memory)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART5",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART7",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made by IIO Part0 to Memory)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made by IIO Part1 to Memory)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made by IIO Part2 to Memory)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made by IIO Part3 to Memory)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by IIO Part0 to Memory)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is  made by IIO Part1 to Memory)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by IIO Part2 to Memory)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by IIO Part3 to Memory)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART5",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART7",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to DRAM)",
      R"(Number Transactions requested of the CPU : Card writing to DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART4",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART5",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART6",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART7",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card reading from DRAM)",
      R"(Number Transactions requested of the CPU : Card reading from DRAM : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made to IIO Part0 by the CPU)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made to IIO Part1 by the CPU)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made to IIO Part2 by the CPU)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made to IIO Part3 by the CPU)",
      R"(Data requested by the CPU : Core writing to Card's MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .msr_values = {0x00}},
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      R"(Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART5",
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .msr_values = {0x00}},
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      R"(Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .msr_values = {0x00}},
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      R"(Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART7",
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .msr_values = {0x00}},
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      R"(Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made to IIO Part0 by the CPU)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made to IIO Part1 by the CPU)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made to IIO Part2 by the CPU)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made to IIO Part3 by the CPU)",
      R"(Number Transactions requested by the CPU : Core writing to Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part0)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part1)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART2",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part2)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part3)",
      R"(Number Transactions requested by the CPU : Core reading from Card's MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .msr_values = {0x00}},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART5",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .msr_values = {0x00}},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .msr_values = {0x00}},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART7",
      EventDef::Encoding{.code = 0xc1, .umask = 0x01, .msr_values = {0x00}},
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core writing to Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART4",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .msr_values = {0x00}},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART5",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .msr_values = {0x00}},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART6",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .msr_values = {0x00}},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART7",
      EventDef::Encoding{.code = 0xc1, .umask = 0x04, .msr_values = {0x00}},
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space)",
      R"(Number Transactions requested by the CPU : Core reading from Cards MMIO space : Also known as Outbound.  Number of requests initiated by the main die, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_ACT_COUNT.ALL",
      EventDef::Encoding{.code = 0x02, .umask = 0xff, .msr_values = {0x00}},
      R"(Activate due to read, write, underfill, or bypass)",
      R"(DRAM Activate Count : Counts the number of DRAM Activate commands sent on this channel.  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS.  One can calculate the number of Page Misses by subtracting the number of Page Miss precharges from the number of Activates.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.RD",
      EventDef::Encoding{.code = 0x03, .umask = 0x11, .msr_values = {0x00}},
      R"(Precharge due to read on page miss)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.WR",
      EventDef::Encoding{.code = 0x03, .umask = 0x22, .msr_values = {0x00}},
      R"(Precharge due to write on page miss)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.PGT",
      EventDef::Encoding{.code = 0x03, .umask = 0x88, .msr_values = {0x00}},
      R"(DRAM Precharge commands. : Precharge due to (?))",
      R"(DRAM Precharge commands. : Precharge due to (?) : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.ALL",
      EventDef::Encoding{.code = 0x03, .umask = 0xff, .msr_values = {0x00}},
      R"(Precharge due to read, write, underfill, or PGT.)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.ALL",
      EventDef::Encoding{.code = 0x05, .umask = 0xff, .msr_values = {0x00}},
      R"(All DRAM CAS commands issued)",
      R"(DRAM RD_CAS and WR_CAS Commands. : All DRAM Read and Write actions : DRAM RD_CAS and WR_CAS Commands : Counts the total number of DRAM CAS commands issued on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD_PRE_REG",
      EventDef::Encoding{.code = 0x05, .umask = 0xc2, .msr_values = {0x00}},
      R"(DRAM RD_CAS and WR_CAS Commands.)",
      R"(DRAM RD_CAS and WR_CAS Commands. : DRAM RD_CAS and WR_CAS Commands)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD_PRE_UNDERFILL",
      EventDef::Encoding{.code = 0x05, .umask = 0xc8, .msr_values = {0x00}},
      R"(DRAM RD_CAS and WR_CAS Commands.)",
      R"(DRAM RD_CAS and WR_CAS Commands. : DRAM RD_CAS and WR_CAS Commands)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR_PRE",
      EventDef::Encoding{.code = 0x05, .umask = 0xe0, .msr_values = {0x00}},
      R"(DRAM RD_CAS and WR_CAS Commands.)",
      R"(DRAM RD_CAS and WR_CAS Commands. : DRAM RD_CAS and WR_CAS Commands)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_SELF_REFRESH",
      EventDef::Encoding{.code = 0x43, .umask = 0x00, .msr_values = {0x00}},
      R"(Clock-Enabled Self-Refresh)",
      R"(Clock-Enabled Self-Refresh : Counts the number of cycles when the iMC is in self-refresh and the iMC still has a clock.  This happens in some package C-states.  For example, the PCU may ask the iMC to enter self-refresh even though some of the cores are still processing.  One use of this is for Monroe technology.  Self-refresh is required during package C3 and C6, but there is no clock in the iMC at this time, so it is not possible to count these cases.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.LOW_0",
      EventDef::Encoding{.code = 0x47, .umask = 0x01, .msr_values = {0x00}},
      R"(CKE_ON_CYCLES by Rank : DIMM ID)",
      R"(CKE_ON_CYCLES by Rank : DIMM ID : Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.LOW_1",
      EventDef::Encoding{.code = 0x47, .umask = 0x02, .msr_values = {0x00}},
      R"(CKE_ON_CYCLES by Rank : DIMM ID)",
      R"(CKE_ON_CYCLES by Rank : DIMM ID : Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.LOW_2",
      EventDef::Encoding{.code = 0x47, .umask = 0x04, .msr_values = {0x00}},
      R"(CKE_ON_CYCLES by Rank : DIMM ID)",
      R"(CKE_ON_CYCLES by Rank : DIMM ID : Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CKE_CYCLES.LOW_3",
      EventDef::Encoding{.code = 0x47, .umask = 0x08, .msr_values = {0x00}},
      R"(CKE_ON_CYCLES by Rank : DIMM ID)",
      R"(CKE_ON_CYCLES by Rank : DIMM ID : Number of cycles spent in CKE ON mode.  The filter allows you to select a rank to monitor.  If multiple ranks are in CKE ON mode at one time, the counter will ONLY increment by one rather than doing accumulation.  Multiple counters will need to be used to track multiple ranks simultaneously.  There is no distinction between the different CKE modes (APD, PPDS, PPDF).  This can be determined based on the system programming.  These events should commonly be used with Invert to get the number of cycles in power saving mode.  Edge Detect is also useful here.  Make sure that you do NOT use Invert with Edge Detect (this just confuses the system and is not necessary).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CHANNEL_PPD",
      EventDef::Encoding{.code = 0x85, .umask = 0x00, .msr_values = {0x00}},
      R"(Channel PPD Cycles)",
      R"(Channel PPD Cycles : Number of cycles when all the ranks in the channel are in PPD mode.  If IBT=off is enabled, then this can be used to count those cycles.  If it is not enabled, then this can count the number of cycles when that could have been taken advantage of.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_RxC_AD_INSERTS",
      EventDef::Encoding{.code = 0x02, .umask = 0x01, .msr_values = {0x00}},
      R"(AD Ingress (from CMS) : AD Ingress (from CMS) Allocations)",
      R"(AD Ingress (from CMS) : AD Ingress (from CMS) Allocations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_RxC_AD_OCCUPANCY",
      EventDef::Encoding{.code = 0x03, .umask = 0x00, .msr_values = {0x00}},
      R"(AD Ingress (from CMS) Occupancy)",
      R"(AD Ingress (from CMS) Occupancy)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2CORE_TAKEN",
      EventDef::Encoding{.code = 0x16, .umask = 0x07, .msr_values = {0x00}},
      R"(Messages sent direct to core (bypassing the CHA))",
      R"(Messages sent direct to core (bypassing the CHA))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2CORE_NOT_TAKEN_DIRSTATE",
      EventDef::Encoding{.code = 0x17, .umask = 0x07, .msr_values = {0x00}},
      R"(Cycles when direct to core mode (which bypasses the CHA) was disabled)",
      R"(Cycles when direct to core mode (which bypasses the CHA) was disabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2CORE_TXN_OVERRIDE",
      EventDef::Encoding{.code = 0x18, .umask = 0x03, .msr_values = {0x00}},
      R"(Number of reads in which direct to core transaction were overridden)",
      R"(Number of reads in which direct to core transaction were overridden)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2UPI_TAKEN",
      EventDef::Encoding{.code = 0x19, .umask = 0x07, .msr_values = {0x00}},
      R"(Messages sent direct to the Intel UPI)",
      R"(Messages sent direct to the Intel UPI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2UPI_NOT_TAKEN_DIRSTATE",
      EventDef::Encoding{.code = 0x1a, .umask = 0x07, .msr_values = {0x00}},
      R"(Cycles when direct to Intel UPI was disabled)",
      R"(Cycles when direct to Intel UPI was disabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2UPI_NOT_TAKEN_CREDITS",
      EventDef::Encoding{.code = 0x1b, .umask = 0x07, .msr_values = {0x00}},
      R"(Number of reads in which direct to Intel UPI transactions were overridden)",
      R"(Number of reads in which direct to Intel UPI transactions were overridden)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2UPI_TXN_OVERRIDE",
      EventDef::Encoding{.code = 0x1c, .umask = 0x03, .msr_values = {0x00}},
      R"(Number of reads that a message sent direct2 Intel UPI was overridden)",
      R"(Number of reads that a message sent direct2 Intel UPI was overridden)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.ANY",
      EventDef::Encoding{.code = 0x20, .umask = 0x01, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory lookups (any state found))",
      R"(Multi-socket cacheline Directory lookups (any state found))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.STATE_A",
      EventDef::Encoding{.code = 0x20, .umask = 0x08, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory lookups (cacheline found in A state))",
      R"(Multi-socket cacheline Directory lookups (cacheline found in A state))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.STATE_I",
      EventDef::Encoding{.code = 0x20, .umask = 0x02, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory lookup (cacheline found in I state))",
      R"(Multi-socket cacheline Directory lookup (cacheline found in I state))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.STATE_S",
      EventDef::Encoding{.code = 0x20, .umask = 0x04, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory lookup (cacheline found in S state))",
      R"(Multi-socket cacheline Directory lookup (cacheline found in S state))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.A2I",
      EventDef::Encoding{.code = 0x21, .umask = 0x20, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from A to I)",
      R"(Multi-socket cacheline Directory update from A to I)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.A2S",
      EventDef::Encoding{.code = 0x21, .umask = 0x40, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from A to S)",
      R"(Multi-socket cacheline Directory update from A to S)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.I2A",
      EventDef::Encoding{.code = 0x21, .umask = 0x04, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from I to A)",
      R"(Multi-socket cacheline Directory update from I to A)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.I2S",
      EventDef::Encoding{.code = 0x21, .umask = 0x02, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from I to S)",
      R"(Multi-socket cacheline Directory update from I to S)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.S2A",
      EventDef::Encoding{.code = 0x21, .umask = 0x10, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from S to A)",
      R"(Multi-socket cacheline Directory update from S to A)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.S2I",
      EventDef::Encoding{.code = 0x21, .umask = 0x08, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from S to I)",
      R"(Multi-socket cacheline Directory update from S to I)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_TRACKER_INSERTS.CH0",
      EventDef::Encoding{.code = 0x32, .umask = 0x04, .msr_values = {0x00}},
      R"(Tracker Inserts : Channel 0)",
      R"(Tracker Inserts : Channel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_TRACKER_INSERTS.CH1",
      EventDef::Encoding{.code = 0x32, .umask = 0x04, .msr_values = {0x00}},
      R"(Tracker Inserts : Channel 1)",
      R"(Tracker Inserts : Channel 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_TRACKER_OCCUPANCY.CH0",
      EventDef::Encoding{.code = 0x33, .umask = 0x01, .msr_values = {0x00}},
      R"(Tracker Occupancy : Channel 0)",
      R"(Tracker Occupancy : Channel 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_TRACKER_OCCUPANCY.CH1",
      EventDef::Encoding{.code = 0x33, .umask = 0x02, .msr_values = {0x00}},
      R"(Tracker Occupancy : Channel 1)",
      R"(Tracker Occupancy : Channel 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_PREFCAM_DEMAND_DROPS.CH0_XPT",
      EventDef::Encoding{.code = 0x58, .umask = 0x01, .msr_values = {0x00}},
      R"(Data Prefetches Dropped)",
      R"(Data Prefetches Dropped)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_PREFCAM_DEMAND_DROPS.CH0_UPI",
      EventDef::Encoding{.code = 0x58, .umask = 0x02, .msr_values = {0x00}},
      R"(Data Prefetches Dropped)",
      R"(Data Prefetches Dropped)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_PREFCAM_DEMAND_DROPS.CH1_XPT",
      EventDef::Encoding{.code = 0x58, .umask = 0x04, .msr_values = {0x00}},
      R"(Data Prefetches Dropped)",
      R"(Data Prefetches Dropped)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_PREFCAM_DEMAND_DROPS.CH1_UPI",
      EventDef::Encoding{.code = 0x58, .umask = 0x08, .msr_values = {0x00}},
      R"(Data Prefetches Dropped)",
      R"(Data Prefetches Dropped)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m3upi,
      "UNC_M3UPI_UPI_PREFETCH_SPAWN",
      EventDef::Encoding{.code = 0x29, .umask = 0x00, .msr_values = {0x00}},
      R"(FlowQ Generated Prefetch)",
      R"(FlowQ Generated Prefetch : Count cases where FlowQ causes spawn of Prefetch to iMC/SMI3 target)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m3upi,
      "UNC_M3UPI_D2U_SENT",
      EventDef::Encoding{.code = 0x2a, .umask = 0x00, .msr_values = {0x00}},
      R"(D2U Sent)",
      R"(D2U Sent : Cases where SMI3 sends D2U command)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m3upi,
      "UNC_M3UPI_D2C_SENT",
      EventDef::Encoding{.code = 0x2b, .umask = 0x00, .msr_values = {0x00}},
      R"(D2C Sent)",
      R"(D2C Sent : Count cases BL sends direct to core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m3upi,
      "UNC_M3UPI_CMS_CLOCKTICKS",
      EventDef::Encoding{.code = 0xc0, .umask = 0x00, .msr_values = {0x00}},
      R"(M3UPI CMS Clockticks)",
      R"(CMS Clockticks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.SLOT0",
      EventDef::Encoding{.code = 0x02, .umask = 0x01, .msr_values = {0x00}},
      R"(Valid Flits Sent : Slot 0)",
      R"(Valid Flits Sent : Slot 0 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 0 - Other mask bits determine types of headers to count.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.SLOT1",
      EventDef::Encoding{.code = 0x02, .umask = 0x02, .msr_values = {0x00}},
      R"(Valid Flits Sent : Slot 1)",
      R"(Valid Flits Sent : Slot 1 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 1 - Other mask bits determine types of headers to count.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.SLOT2",
      EventDef::Encoding{.code = 0x02, .umask = 0x04, .msr_values = {0x00}},
      R"(Valid Flits Sent : Slot 2)",
      R"(Valid Flits Sent : Slot 2 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 2 - Other mask bits determine types of headers to count.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.DATA",
      EventDef::Encoding{.code = 0x02, .umask = 0x08, .msr_values = {0x00}},
      R"(Valid Flits Sent : Data)",
      R"(Valid Flits Sent : Data : Shows legal flit time (hides impact of L0p and L0c). : Count Data Flits (which consume all slots), but how much to count is based on Slot0-2 mask, so count can be 0-3 depending on which slots are enabled for counting..)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.LLCRD",
      EventDef::Encoding{.code = 0x02, .umask = 0x10, .msr_values = {0x00}},
      R"(Valid Flits Sent : LLCRD Not Empty)",
      R"(Valid Flits Sent : LLCRD Not Empty : Shows legal flit time (hides impact of L0p and L0c). : Enables counting of LLCRD (with non-zero payload). This only applies to slot 2 since LLCRD is only allowed in slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.NULL",
      EventDef::Encoding{.code = 0x02, .umask = 0x20, .msr_values = {0x00}},
      R"(Valid Flits Sent : Slot NULL or LLCRD Empty)",
      R"(Valid Flits Sent : Slot NULL or LLCRD Empty : Shows legal flit time (hides impact of L0p and L0c). : LLCRD with all zeros is treated as NULL. Slot 1 is not treated as NULL if slot 0 is a dual slot. This can apply to slot 0,1, or 2.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.LLCTRL",
      EventDef::Encoding{.code = 0x02, .umask = 0x40, .msr_values = {0x00}},
      R"(Valid Flits Sent : LLCTRL)",
      R"(Valid Flits Sent : LLCTRL : Shows legal flit time (hides impact of L0p and L0c). : Equivalent to an idle packet.  Enables counting of slot 0 LLCTRL messages.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.PROTHDR",
      EventDef::Encoding{.code = 0x02, .umask = 0x80, .msr_values = {0x00}},
      R"(Valid Flits Sent : Protocol Header)",
      R"(Valid Flits Sent : Protocol Header : Shows legal flit time (hides impact of L0p and L0c). : Enables count of protocol headers in slot 0,1,2 (depending on slot uMask bits))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.NON_DATA",
      EventDef::Encoding{.code = 0x02, .umask = 0x97, .msr_values = {0x00}},
      R"(Valid Flits Sent : All Non Data)",
      R"(Valid Flits Sent : All Non Data : Shows legal flit time (hides impact of L0p and L0c).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.IDLE",
      EventDef::Encoding{.code = 0x02, .umask = 0x47, .msr_values = {0x00}},
      R"(Valid Flits Sent : Idle)",
      R"(Valid Flits Sent : Idle : Shows legal flit time (hides impact of L0p and L0c).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.ALL_NULL",
      EventDef::Encoding{.code = 0x02, .umask = 0x27, .msr_values = {0x00}},
      R"(All Null Flits)",
      R"(All Null Flits)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.SLOT0",
      EventDef::Encoding{.code = 0x03, .umask = 0x01, .msr_values = {0x00}},
      R"(Valid Flits Received : Slot 0)",
      R"(Valid Flits Received : Slot 0 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 0 - Other mask bits determine types of headers to count.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.SLOT1",
      EventDef::Encoding{.code = 0x03, .umask = 0x02, .msr_values = {0x00}},
      R"(Valid Flits Received : Slot 1)",
      R"(Valid Flits Received : Slot 1 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 1 - Other mask bits determine types of headers to count.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.SLOT2",
      EventDef::Encoding{.code = 0x03, .umask = 0x04, .msr_values = {0x00}},
      R"(Valid Flits Received : Slot 2)",
      R"(Valid Flits Received : Slot 2 : Shows legal flit time (hides impact of L0p and L0c). : Count Slot 2 - Other mask bits determine types of headers to count.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.DATA",
      EventDef::Encoding{.code = 0x03, .umask = 0x08, .msr_values = {0x00}},
      R"(Valid Flits Received : Data)",
      R"(Valid Flits Received : Data : Shows legal flit time (hides impact of L0p and L0c). : Count Data Flits (which consume all slots), but how much to count is based on Slot0-2 mask, so count can be 0-3 depending on which slots are enabled for counting..)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.LLCRD",
      EventDef::Encoding{.code = 0x03, .umask = 0x10, .msr_values = {0x00}},
      R"(Valid Flits Received : LLCRD Not Empty)",
      R"(Valid Flits Received : LLCRD Not Empty : Shows legal flit time (hides impact of L0p and L0c). : Enables counting of LLCRD (with non-zero payload). This only applies to slot 2 since LLCRD is only allowed in slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.NULL",
      EventDef::Encoding{.code = 0x03, .umask = 0x20, .msr_values = {0x00}},
      R"(Valid Flits Received : Slot NULL or LLCRD Empty)",
      R"(Valid Flits Received : Slot NULL or LLCRD Empty : Shows legal flit time (hides impact of L0p and L0c). : LLCRD with all zeros is treated as NULL. Slot 1 is not treated as NULL if slot 0 is a dual slot. This can apply to slot 0,1, or 2.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.LLCTRL",
      EventDef::Encoding{.code = 0x03, .umask = 0x40, .msr_values = {0x00}},
      R"(Valid Flits Received : LLCTRL)",
      R"(Valid Flits Received : LLCTRL : Shows legal flit time (hides impact of L0p and L0c). : Equivalent to an idle packet.  Enables counting of slot 0 LLCTRL messages.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.PROTHDR",
      EventDef::Encoding{.code = 0x03, .umask = 0x80, .msr_values = {0x00}},
      R"(Valid Flits Received : Protocol Header)",
      R"(Valid Flits Received : Protocol Header : Shows legal flit time (hides impact of L0p and L0c). : Enables count of protocol headers in slot 0,1,2 (depending on slot uMask bits))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.ALL_DATA",
      EventDef::Encoding{.code = 0x03, .umask = 0x0f, .msr_values = {0x00}},
      R"(Valid Flits Received : All Data)",
      R"(Valid Flits Received : All Data : Shows legal flit time (hides impact of L0p and L0c).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.NON_DATA",
      EventDef::Encoding{.code = 0x03, .umask = 0x97, .msr_values = {0x00}},
      R"(Valid Flits Received : All Non Data)",
      R"(Valid Flits Received : All Non Data : Shows legal flit time (hides impact of L0p and L0c).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.IDLE",
      EventDef::Encoding{.code = 0x03, .umask = 0x47, .msr_values = {0x00}},
      R"(Valid Flits Received : Idle)",
      R"(Valid Flits Received : Idle : Shows legal flit time (hides impact of L0p and L0c).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.ALL_NULL",
      EventDef::Encoding{.code = 0x03, .umask = 0x27, .msr_values = {0x00}},
      R"(Null FLITs received from any slot)",
      R"(Null FLITs received from any slot)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.NCB",
      EventDef::Encoding{.code = 0x04, .umask = 0x0e, .msr_values = {0x00}},
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Bypass)",
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Bypass : Matches on Transmit path of a UPI port.
Match based on UMask specific bits:
Z: Message Class (3-bit)
Y: Message Class Enable
W: Opcode (4-bit)
V: Opcode Enable
U: Local Enable
T: Remote Enable
S: Data Hdr Enable
R: Non-Data Hdr Enable
Q: Dual Slot Hdr Enable
P: Single Slot Hdr Enable
Link Layer control types are excluded (LL CTRL, slot NULL, LLCRD) even under specific opcode match_en cases.
Note: If Message Class is disabled, we expect opcode to also be disabled.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.NCB_OPC",
      EventDef::Encoding{.code = 0x04, .umask = 0x0e, .msr_values = {0x00}},
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Bypass, Match Opcode)",
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Bypass, Match Opcode : Matches on Transmit path of a UPI port.
Match based on UMask specific bits:
Z: Message Class (3-bit)
Y: Message Class Enable
W: Opcode (4-bit)
V: Opcode Enable
U: Local Enable
T: Remote Enable
S: Data Hdr Enable
R: Non-Data Hdr Enable
Q: Dual Slot Hdr Enable
P: Single Slot Hdr Enable
Link Layer control types are excluded (LL CTRL, slot NULL, LLCRD) even under specific opcode match_en cases.
Note: If Message Class is disabled, we expect opcode to also be disabled.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.NCS",
      EventDef::Encoding{.code = 0x04, .umask = 0x0f, .msr_values = {0x00}},
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Standard)",
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Standard : Matches on Transmit path of a UPI port.
Match based on UMask specific bits:
Z: Message Class (3-bit)
Y: Message Class Enable
W: Opcode (4-bit)
V: Opcode Enable
U: Local Enable
T: Remote Enable
S: Data Hdr Enable
R: Non-Data Hdr Enable
Q: Dual Slot Hdr Enable
P: Single Slot Hdr Enable
Link Layer control types are excluded (LL CTRL, slot NULL, LLCRD) even under specific opcode match_en cases.
Note: If Message Class is disabled, we expect opcode to also be disabled.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BASIC_HDR_MATCH.NCS_OPC",
      EventDef::Encoding{.code = 0x04, .umask = 0x0f, .msr_values = {0x00}},
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Standard, Match Opcode)",
      R"(Matches on Transmit path of a UPI Port : Non-Coherent Standard, Match Opcode : Matches on Transmit path of a UPI port.
Match based on UMask specific bits:
Z: Message Class (3-bit)
Y: Message Class Enable
W: Opcode (4-bit)
V: Opcode Enable
U: Local Enable
T: Remote Enable
S: Data Hdr Enable
R: Non-Data Hdr Enable
Q: Dual Slot Hdr Enable
P: Single Slot Hdr Enable
Link Layer control types are excluded (LL CTRL, slot NULL, LLCRD) even under specific opcode match_en cases.
Note: If Message Class is disabled, we expect opcode to also be disabled.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.NCB",
      EventDef::Encoding{.code = 0x05, .umask = 0x0e, .msr_values = {0x00}},
      R"(Matches on Receive path of a UPI Port : Non-Coherent Bypass)",
      R"(Matches on Receive path of a UPI Port : Non-Coherent Bypass : Matches on Receive path of a UPI port.
Match based on UMask specific bits:
Z: Message Class (3-bit)
Y: Message Class Enable
W: Opcode (4-bit)
V: Opcode Enable
U: Local Enable
T: Remote Enable
S: Data Hdr Enable
R: Non-Data Hdr Enable
Q: Dual Slot Hdr Enable
P: Single Slot Hdr Enable
Link Layer control types are excluded (LL CTRL, slot NULL, LLCRD) even under specific opcode match_en cases.
Note: If Message Class is disabled, we expect opcode to also be disabled.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.NCB_OPC",
      EventDef::Encoding{.code = 0x05, .umask = 0x0e, .msr_values = {0x00}},
      R"(Matches on Receive path of a UPI Port : Non-Coherent Bypass, Match Opcode)",
      R"(Matches on Receive path of a UPI Port : Non-Coherent Bypass, Match Opcode : Matches on Receive path of a UPI port.
Match based on UMask specific bits:
Z: Message Class (3-bit)
Y: Message Class Enable
W: Opcode (4-bit)
V: Opcode Enable
U: Local Enable
T: Remote Enable
S: Data Hdr Enable
R: Non-Data Hdr Enable
Q: Dual Slot Hdr Enable
P: Single Slot Hdr Enable
Link Layer control types are excluded (LL CTRL, slot NULL, LLCRD) even under specific opcode match_en cases.
Note: If Message Class is disabled, we expect opcode to also be disabled.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.NCS",
      EventDef::Encoding{.code = 0x05, .umask = 0x0f, .msr_values = {0x00}},
      R"(Matches on Receive path of a UPI Port : Non-Coherent Standard)",
      R"(Matches on Receive path of a UPI Port : Non-Coherent Standard : Matches on Receive path of a UPI port.
Match based on UMask specific bits:
Z: Message Class (3-bit)
Y: Message Class Enable
W: Opcode (4-bit)
V: Opcode Enable
U: Local Enable
T: Remote Enable
S: Data Hdr Enable
R: Non-Data Hdr Enable
Q: Dual Slot Hdr Enable
P: Single Slot Hdr Enable
Link Layer control types are excluded (LL CTRL, slot NULL, LLCRD) even under specific opcode match_en cases.
Note: If Message Class is disabled, we expect opcode to also be disabled.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BASIC_HDR_MATCH.NCS_OPC",
      EventDef::Encoding{.code = 0x05, .umask = 0x0f, .msr_values = {0x00}},
      R"(Matches on Receive path of a UPI Port : Non-Coherent Standard, Match Opcode)",
      R"(Matches on Receive path of a UPI Port : Non-Coherent Standard, Match Opcode : Matches on Receive path of a UPI port.
Match based on UMask specific bits:
Z: Message Class (3-bit)
Y: Message Class Enable
W: Opcode (4-bit)
V: Opcode Enable
U: Local Enable
T: Remote Enable
S: Data Hdr Enable
R: Non-Data Hdr Enable
Q: Dual Slot Hdr Enable
P: Single Slot Hdr Enable
Link Layer control types are excluded (LL CTRL, slot NULL, LLCRD) even under specific opcode match_en cases.
Note: If Message Class is disabled, we expect opcode to also be disabled.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_DIRECT_ATTEMPTS.D2C",
      EventDef::Encoding{.code = 0x12, .umask = 0x01, .msr_values = {0x00}},
      R"(Direct packet attempts : D2C)",
      R"(Direct packet attempts : D2C : Counts the number of DRS packets that we attempted to do direct2core/direct2UPI on.  There are 4 mutually exclusive filters.  Filter [0] can be used to get successful spawns, while [1:3] provide the different failure cases.  Note that this does not count packets that are not candidates for Direct2Core.  The only candidates for Direct2Core are DRS packets destined for Cbos.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_L1_POWER_CYCLES",
      EventDef::Encoding{.code = 0x21, .umask = 0x00, .msr_values = {0x00}},
      R"(Cycles in L1)",
      R"(Cycles in L1 : Number of UPI qfclk cycles spent in L1 power mode.  L1 is a mode that totally shuts down a UPI link.  Use edge detect to count the number of instances when the UPI link entered L1.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another. Because L1 totally shuts down the link, it takes a good amount of time to exit this mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL0P_POWER_CYCLES",
      EventDef::Encoding{.code = 0x27, .umask = 0x00, .msr_values = {0x00}},
      R"(Cycles in L0p)",
      R"(Cycles in L0p : Number of UPI qfclk cycles spent in L0p power mode.  L0p is a mode where we disable 1/2 of the UPI lanes, decreasing our bandwidth in order to save power.  It increases snoop and data transfer latencies and decreases overall bandwidth.  This mode can be very useful in NUMA optimized workloads that largely only utilize UPI for snoops and their responses.  Use edge detect to count the number of instances when the UPI link entered L0p.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_INSERTS.SLOT0",
      EventDef::Encoding{.code = 0x30, .umask = 0x01, .msr_values = {0x00}},
      R"(RxQ Flit Buffer Allocations : Slot 0)",
      R"(RxQ Flit Buffer Allocations : Slot 0 : Number of allocations into the UPI Rx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_INSERTS.SLOT1",
      EventDef::Encoding{.code = 0x30, .umask = 0x02, .msr_values = {0x00}},
      R"(RxQ Flit Buffer Allocations : Slot 1)",
      R"(RxQ Flit Buffer Allocations : Slot 1 : Number of allocations into the UPI Rx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_INSERTS.SLOT2",
      EventDef::Encoding{.code = 0x30, .umask = 0x04, .msr_values = {0x00}},
      R"(RxQ Flit Buffer Allocations : Slot 2)",
      R"(RxQ Flit Buffer Allocations : Slot 2 : Number of allocations into the UPI Rx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BYPASSED.SLOT0",
      EventDef::Encoding{.code = 0x31, .umask = 0x01, .msr_values = {0x00}},
      R"(RxQ Flit Buffer Bypassed : Slot 0)",
      R"(RxQ Flit Buffer Bypassed : Slot 0 : Counts the number of times that an incoming flit was able to bypass the flit buffer and pass directly across the BGF and into the Egress.  This is a latency optimization, and should generally be the common case.  If this value is less than the number of flits transferred, it implies that there was queueing getting onto the ring, and thus the transactions saw higher latency.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BYPASSED.SLOT1",
      EventDef::Encoding{.code = 0x31, .umask = 0x02, .msr_values = {0x00}},
      R"(RxQ Flit Buffer Bypassed : Slot 1)",
      R"(RxQ Flit Buffer Bypassed : Slot 1 : Counts the number of times that an incoming flit was able to bypass the flit buffer and pass directly across the BGF and into the Egress.  This is a latency optimization, and should generally be the common case.  If this value is less than the number of flits transferred, it implies that there was queueing getting onto the ring, and thus the transactions saw higher latency.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BYPASSED.SLOT2",
      EventDef::Encoding{.code = 0x31, .umask = 0x04, .msr_values = {0x00}},
      R"(RxQ Flit Buffer Bypassed : Slot 2)",
      R"(RxQ Flit Buffer Bypassed : Slot 2 : Counts the number of times that an incoming flit was able to bypass the flit buffer and pass directly across the BGF and into the Egress.  This is a latency optimization, and should generally be the common case.  If this value is less than the number of flits transferred, it implies that there was queueing getting onto the ring, and thus the transactions saw higher latency.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_OCCUPANCY.SLOT0",
      EventDef::Encoding{.code = 0x32, .umask = 0x01, .msr_values = {0x00}},
      R"(RxQ Occupancy - All Packets : Slot 0)",
      R"(RxQ Occupancy - All Packets : Slot 0 : Accumulates the number of elements in the UPI RxQ in each cycle.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_OCCUPANCY.SLOT1",
      EventDef::Encoding{.code = 0x32, .umask = 0x02, .msr_values = {0x00}},
      R"(RxQ Occupancy - All Packets : Slot 1)",
      R"(RxQ Occupancy - All Packets : Slot 1 : Accumulates the number of elements in the UPI RxQ in each cycle.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_OCCUPANCY.SLOT2",
      EventDef::Encoding{.code = 0x32, .umask = 0x04, .msr_values = {0x00}},
      R"(RxQ Occupancy - All Packets : Slot 2)",
      R"(RxQ Occupancy - All Packets : Slot 2 : Accumulates the number of elements in the UPI RxQ in each cycle.  Generally, when data is transmitted across UPI, it will bypass the RxQ and pass directly to the ring interface.  If things back up getting transmitted onto the ring, however, it may need to allocate into this buffer, thus increasing the latency.  This event can be used in conjunction with the Flit Buffer Not Empty event to calculate average occupancy, or with the Flit Buffer Allocations event to track average lifetime.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_INSERTS",
      EventDef::Encoding{.code = 0x40, .umask = 0x00, .msr_values = {0x00}},
      R"(Tx Flit Buffer Allocations)",
      R"(Tx Flit Buffer Allocations : Number of allocations into the UPI Tx Flit Buffer.  Generally, when data is transmitted across UPI, it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used with L0p and when LLR occurs, increasing latency to transfer out to the link.  This event can be used in conjunction with the Flit Buffer Occupancy event in order to calculate the average flit buffer lifetime.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BYPASSED",
      EventDef::Encoding{.code = 0x41, .umask = 0x00, .msr_values = {0x00}},
      R"(Tx Flit Buffer Bypassed)",
      R"(Tx Flit Buffer Bypassed : Counts the number of times that an incoming flit was able to bypass the Tx flit buffer and pass directly out the UPI Link. Generally, when data is transmitted across UPI, it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used with L0p and when LLR occurs, increasing latency to transfer out to the link.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_OCCUPANCY",
      EventDef::Encoding{.code = 0x42, .umask = 0x00, .msr_values = {0x00}},
      R"(Tx Flit Buffer Occupancy)",
      R"(Tx Flit Buffer Occupancy : Accumulates the number of flits in the TxQ.  Generally, when data is transmitted across UPI, it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used with L0p and when LLR occurs, increasing latency to transfer out to the link. This can be used with the cycles not empty event to track average occupancy, or the allocations event to track average lifetime in the TxQ.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.INVITOE_LOCAL",
      EventDef::Encoding{.code = 0x50, .umask = 0x10, .msr_values = {0x00}},
      R"(Local requests for exclusive ownership of a cache line  without receiving data)",
      R"(Counts the total number of requests coming from a unit on this socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.READS",
      EventDef::Encoding{.code = 0x50, .umask = 0x03, .msr_values = {0x00}},
      R"(Read requests made into the CHA)",
      R"(Counts read requests made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write) .)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.WRITES",
      EventDef::Encoding{.code = 0x50, .umask = 0x0c, .msr_values = {0x00}},
      R"(Write requests made into the CHA)",
      R"(Counts write requests made into the CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_LOOKUP.NO_SNP",
      EventDef::Encoding{.code = 0x53, .umask = 0x02, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory state lookups; Snoop Not Needed)",
      R"(Counts transactions that looked into the multi-socket cacheline Directory state, and therefore did not send a snoop because the Directory indicated it was not needed.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_LOOKUP.SNP",
      EventDef::Encoding{.code = 0x53, .umask = 0x01, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory state lookups; Snoop Needed)",
      R"(Counts  transactions that looked into the multi-socket cacheline Directory state, and sent one or more snoops, because the Directory indicated it was needed.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_OSB.LOCAL_INVITOE",
      EventDef::Encoding{.code = 0x55, .umask = 0x01, .msr_values = {0x00}},
      R"(OSB Snoop Broadcast : Local InvItoE)",
      R"(OSB Snoop Broadcast : Local InvItoE : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_OSB.LOCAL_READ",
      EventDef::Encoding{.code = 0x55, .umask = 0x02, .msr_values = {0x00}},
      R"(OSB Snoop Broadcast : Local Rd)",
      R"(OSB Snoop Broadcast : Local Rd : Count of OSB snoop broadcasts. Counts by 1 per request causing OSB snoops to be broadcast. Does not count all the snoops generated by OSB.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_CMS_CLOCKTICKS",
      EventDef::Encoding{.code = 0xc0, .umask = 0x00, .msr_values = {0x00}},
      R"(CMS Clockticks)",
      R"(CMS Clockticks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.DATA_RD",
      EventDef::Encoding{.code = 0x34, .umask = 0xff, .msr_values = {0x00}},
      R"(Cache and Snoop Filter Lookups; Data Read Request)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state. Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_LOOKUP.REMOTE_SNP",
      EventDef::Encoding{.code = 0x34, .umask = 0xff, .msr_values = {0x00}},
      R"(Cache and Snoop Filter Lookups; Snoop Requests from a Remote Socket)",
      R"(Counts the number of times the LLC was accessed - this includes code, data, prefetches and hints coming from L2.  This has numerous filters available.  Note the non-standard filtering equation.  This event will count requests that lookup the cache multiple times with multiple increments.  One must ALWAYS set umask bit 0 and select a state or states to match.  Otherwise, the event will count nothing.   CHAFilter0[24:21,17] bits correspond to [FMESI] state.; Filters for any transaction originating from the IPQ or IRQ.  This does not include lookups originating from the ISMQ.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.SNPS_FROM_REM",
      EventDef::Encoding{.code = 0x35, .umask = 0x08, .msr_values = {0x00}},
      R"(TOR Inserts; All Snoops from Remote)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent. All snoops to this LLC that came from remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.ALL",
      EventDef::Encoding{.code = 0x35, .umask = 0xff, .msr_values = {0x00}},
      R"(TOR Inserts : All)",
      R"(TOR Inserts : All : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; All from Local IA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; All locally initiated requests from IA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; Hits from Local IA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_CRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; CRd hits from local IA)",
      R"(TOR Inserts; Code read from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_DRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; DRd hits from local IA)",
      R"(TOR Inserts; Data read from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_LLCPREFRFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; LLCPrefRFO hits from local IA)",
      R"(TOR Inserts; Last level cache prefetch read for ownership from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; RFO hits from local IA)",
      R"(TOR Inserts; Read for ownership from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; misses from Local IA)",
      R"(TOR Inserts : All requests from iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFRFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; LLCPrefRFO misses from local IA)",
      R"(TOR Inserts; Last level cache prefetch read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; RFO misses from local IA)",
      R"(TOR Inserts; Read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts; All from local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_HIT",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts; Hits from local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts; Misses from local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_MISS_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts; ItoM misses from local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_MISS_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts; RFO misses from local IO)",
      R"(TOR Inserts : RFOs issued by IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IRQ_IA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : IRQ - iA)",
      R"(TOR Inserts : IRQ - iA : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent. : From an iA Core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.EVICT",
      EventDef::Encoding{.code = 0x35, .umask = 0x02, .msr_values = {0x00}},
      R"(TOR Inserts : SF/LLC Evictions)",
      R"(TOR Inserts : SF/LLC Evictions : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent. : TOR allocation occurred as a result of SF/LLC evictions (came from the ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.PRQ_IOSF",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts : PRQ - IOSF)",
      R"(TOR Inserts : PRQ - IOSF : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent. : From a PCIe Device)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IPQ",
      EventDef::Encoding{.code = 0x35, .umask = 0x08, .msr_values = {0x00}},
      R"(TOR Inserts : IPQ)",
      R"(TOR Inserts : IPQ : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IRQ_NON_IA",
      EventDef::Encoding{.code = 0x35, .umask = 0x10, .msr_values = {0x00}},
      R"(TOR Inserts : IRQ - Non iA)",
      R"(TOR Inserts : IRQ - Non iA : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.PRQ_NON_IOSF",
      EventDef::Encoding{.code = 0x35, .umask = 0x20, .msr_values = {0x00}},
      R"(TOR Inserts : PRQ - Non IOSF)",
      R"(TOR Inserts : PRQ - Non IOSF : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.RRQ",
      EventDef::Encoding{.code = 0x35, .umask = 0x40, .msr_values = {0x00}},
      R"(TOR Inserts : RRQ)",
      R"(TOR Inserts : RRQ : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.WBQ",
      EventDef::Encoding{.code = 0x35, .umask = 0x80, .msr_values = {0x00}},
      R"(TOR Inserts : WBQ)",
      R"(TOR Inserts : WBQ : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.LOC_IO",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts : All from Local IO)",
      R"(TOR Inserts : All from Local IO : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent. : All locally generated IO traffic)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.LOC_IA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : All from Local iA)",
      R"(TOR Inserts : All from Local iA : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent. : All locally initiated requests from iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.LOC_ALL",
      EventDef::Encoding{.code = 0x35, .umask = 0x05, .msr_values = {0x00}},
      R"(TOR Inserts : All from Local iA and IO)",
      R"(TOR Inserts : All from Local iA and IO : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent. : All locally initiated requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.REM_SNPS",
      EventDef::Encoding{.code = 0x35, .umask = 0x08, .msr_values = {0x00}},
      R"(TOR Inserts : All Snoops from Remote)",
      R"(TOR Inserts : All Snoops from Remote : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent. : All snoops to this LLC that came from remote sockets)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.REM_ALL",
      EventDef::Encoding{.code = 0x35, .umask = 0xC8, .msr_values = {0x00}},
      R"(TOR Inserts : All from Remote)",
      R"(TOR Inserts : All from Remote : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent. : All remote requests (e.g. snoops, writebacks) that came from remote sockets)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.HIT",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : Just Hits)",
      R"(TOR Inserts : Just Hits : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : Just Misses)",
      R"(TOR Inserts : Just Misses : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.MMCFG",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : MMCFG Access)",
      R"(TOR Inserts : MMCFG Access : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.MMIO",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : MMIO Access)",
      R"(TOR Inserts : MMIO Access : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.LOCAL_TGT",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : Just Local Targets)",
      R"(TOR Inserts : Just Local Targets : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.REMOTE_TGT",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : Just Remote Targets)",
      R"(TOR Inserts : Just Remote Targets : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.MATCH_OPC",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : Match the Opcode in b[29:19] of the extended umask field)",
      R"(TOR Inserts : Match the Opcode in b[29:19] of the extended umask field : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.PREMORPH_OPC",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : Match the PreMorphed Opcode in b[29:19] of the extended umask field)",
      R"(TOR Inserts : Match the PreMorphed Opcode in b[29:19] of the extended umask field : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.NONCOH",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : Just NonCoherent)",
      R"(TOR Inserts : Just NonCoherent : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.ISOC",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : Just ISOC)",
      R"(TOR Inserts : Just ISOC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_CRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; CRd Pref hits from local IA)",
      R"(TOR Inserts; Code read prefetch from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_DRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; DRd Pref hits from local IA)",
      R"(TOR Inserts; Data read prefetch from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_DRD_OPT",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; DRd Opt hits from local IA)",
      R"(TOR Inserts; Data read opt from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; DRd Opt Pref hits from local IA)",
      R"(TOR Inserts; Data read opt prefetch from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_RFO_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; RFO Pref hits from local IA)",
      R"(TOR Inserts; Read for ownership prefetch from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; CRd Pref misses from local IA)",
      R"(TOR Inserts; Code read prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; DRd Opt misses from local IA)",
      R"(TOR Inserts; Data read opt from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; DRd Opt Pref misses from local IA)",
      R"(TOR Inserts; Data read opt prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; RFO pref misses from local IA)",
      R"(TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_HIT_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts; ItoM hits from local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_HIT_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts; RFO hits from local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts; RFO from local IO)",
      R"(TOR Inserts : RFOs issued by IO Devices : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_RFO_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; RFO pref from local IA)",
      R"(TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; RFO from local IA)",
      R"(TOR Inserts; Read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_LLCPREFRFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; LLCPrefRFO from local IA)",
      R"(TOR Inserts; Last level cache prefetch read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_DRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; DRd from local IA)",
      R"(TOR Inserts; Data read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_DRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; DRd Pref from local IA)",
      R"(TOR Inserts; Data read prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_DRD_OPT",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; DRd Opt from local IA)",
      R"(TOR Inserts; Data read opt from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; DRd Opt Pref from local IA)",
      R"(TOR Inserts; Data read opt prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_CRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; CRd Pref from local IA)",
      R"(TOR Inserts; Code read prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_CRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; CRd from local IA)",
      R"(TOR Inserts; Code read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts RFO misses from local IA)",
      R"(TOR Inserts; Read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; RFO misses from local IA)",
      R"(TOR Inserts Read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; RFO prefetch misses from local IA)",
      R"(TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; RFO prefetch misses from local IA)",
      R"(TOR Inserts; Read for ownership prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_CLFLUSH",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts;CLFlush from Local IA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; CLFlush events that are initiated from the Core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_CLFLUSHOPT",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts;CLFlushOpt from Local IA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; CLFlushOpt events that are initiated from the Core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts;ItoM from Local IA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; ItoM events that are initiated from the Core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_SPECITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts;SpecItoM from Local IA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; SpecItoM events that are initiated from the Core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.SNPS_FROM_REM",
      EventDef::Encoding{.code = 0x36, .umask = 0x08, .msr_values = {0x00}},
      R"(TOR Occupancy; All Snoops from Remote)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   All snoops to this LLC that came from remote sockets.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0x36, .umask = 0xff, .msr_values = {0x00}},
      R"(TOR Occupancy : All)",
      R"(TOR Occupancy : All : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; All from local IA)",
      R"(TOR Occupancy : All requests from iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; Hits from local IA)",
      R"(TOR Occupancy : All requests from iA Cores that Hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_CRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; CRd hits from local IA)",
      R"(TOR Occupancy; Code read from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd hits from local IA)",
      R"(TOR Occupancy; Data read from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LLCPREFRFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; LLCPrefRFO hits from local IA)",
      R"(TOR Occupancy; Last level cache prefetch read for ownership from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO hits from local IA)",
      R"(TOR Occupancy; Read for ownership from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; Misses from Local IA)",
      R"(TOR Occupancy : All requests from iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; CRd misses from local IA)",
      R"(TOR Occupancy; Code read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFRFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; LLCPrefRFO misses from local IA)",
      R"(TOR Occupancy; Last level cache prefetch read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO misses from local IA)",
      R"(TOR Occupancy; Read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; All from local IO)",
      R"(TOR Occupancy : All requests from IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_HIT",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; Hits from local IO)",
      R"(TOR Occupancy : All requests from IO Devices that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; Misses from local IO)",
      R"(TOR Occupancy : All requests from IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO misses from local IO)",
      R"(TOR Occupancy : RFOs issued by IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; ITOM misses from local IO)",
      R"(TOR Occupancy : ItoMs issued by IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IRQ_IA",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : IRQ - iA)",
      R"(TOR Occupancy : IRQ - iA : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T : From an iA Core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.EVICT",
      EventDef::Encoding{.code = 0x36, .umask = 0x02, .msr_values = {0x00}},
      R"(TOR Occupancy : SF/LLC Evictions)",
      R"(TOR Occupancy : SF/LLC Evictions : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T : TOR allocation occurred as a result of SF/LLC evictions (came from the ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.PRQ",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy : PRQ - IOSF)",
      R"(TOR Occupancy : PRQ - IOSF : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T : From a PCIe Device)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IPQ",
      EventDef::Encoding{.code = 0x36, .umask = 0x08, .msr_values = {0x00}},
      R"(TOR Occupancy : IPQ)",
      R"(TOR Occupancy : IPQ : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IRQ_NON_IA",
      EventDef::Encoding{.code = 0x36, .umask = 0x10, .msr_values = {0x00}},
      R"(TOR Occupancy : IRQ - Non iA)",
      R"(TOR Occupancy : IRQ - Non iA : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.PRQ_NON_IOSF",
      EventDef::Encoding{.code = 0x36, .umask = 0x20, .msr_values = {0x00}},
      R"(TOR Occupancy : PRQ - Non IOSF)",
      R"(TOR Occupancy : PRQ - Non IOSF : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.RRQ",
      EventDef::Encoding{.code = 0x36, .umask = 0x40, .msr_values = {0x00}},
      R"(TOR Occupancy : RRQ)",
      R"(TOR Occupancy : RRQ : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.WBQ",
      EventDef::Encoding{.code = 0x36, .umask = 0x80, .msr_values = {0x00}},
      R"(TOR Occupancy : WBQ)",
      R"(TOR Occupancy : WBQ : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.LOC_IO",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy : All from Local IO)",
      R"(TOR Occupancy : All from Local IO : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T : All locally generated IO traffic)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.LOC_IA",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : All from Local iA)",
      R"(TOR Occupancy : All from Local iA : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T : All locally initiated requests from iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.LOC_ALL",
      EventDef::Encoding{.code = 0x36, .umask = 0x05, .msr_values = {0x00}},
      R"(TOR Occupancy : All from Local iA and IO)",
      R"(TOR Occupancy : All from Local iA and IO : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T : All locally initiated requests)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.REM_SNPS",
      EventDef::Encoding{.code = 0x36, .umask = 0x08, .msr_values = {0x00}},
      R"(TOR Occupancy : All Snoops from Remote)",
      R"(TOR Occupancy : All Snoops from Remote : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T : All snoops to this LLC that came from remote sockets)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.REM_ALL",
      EventDef::Encoding{.code = 0x36, .umask = 0xC8, .msr_values = {0x00}},
      R"(TOR Occupancy : All from Remote)",
      R"(TOR Occupancy : All from Remote : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T : All remote requests (e.g. snoops, writebacks) that came from remote sockets)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.HIT",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : Just Hits)",
      R"(TOR Occupancy : Just Hits : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.MISS",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : Just Misses)",
      R"(TOR Occupancy : Just Misses : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.MMCFG",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : MMCFG Access)",
      R"(TOR Occupancy : MMCFG Access : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.MMIO",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : MMIO Access)",
      R"(TOR Occupancy : MMIO Access : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.LOCAL_TGT",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : Just Local Targets)",
      R"(TOR Occupancy : Just Local Targets : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.REMOTE_TGT",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : Just Remote Targets)",
      R"(TOR Occupancy : Just Remote Targets : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.MATCH_OPC",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : Match the Opcode in b[29:19] of the extended umask field)",
      R"(TOR Occupancy : Match the Opcode in b[29:19] of the extended umask field : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.PREMORPH_OPC",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : Match the PreMorphed Opcode in b[29:19] of the extended umask field)",
      R"(TOR Occupancy : Match the PreMorphed Opcode in b[29:19] of the extended umask field : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.NONCOH",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : Just NonCoherent)",
      R"(TOR Occupancy : Just NonCoherent : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.ISOC",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : Just ISOC)",
      R"(TOR Occupancy : Just ISOC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_CRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; CRd Pref hits from local IA)",
      R"(TOR Occupancy; Code read prefetch from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd Pref hits from local IA)",
      R"(TOR Occupancy; Data read prefetch from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD_OPT",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd Opt hits from local IA)",
      R"(TOR Occupancy; Data read opt from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd Opt Pref hits from local IA)",
      R"(TOR Occupancy; Data read opt prefetch from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_RFO_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO Pref hits from local IA)",
      R"(TOR Occupancy; Read for ownership prefetch from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; CRd Pref misses from local IA)",
      R"(TOR Occupancy; Code read prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd Pref misses from local IA)",
      R"(TOR Occupancy; Data read prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_OPT",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd Opt misses from local IA)",
      R"(TOR Occupancy; Data read opt from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd Opt Pref misses from local IA)",
      R"(TOR Occupancy; Data read opt prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO prefetch misses from local IA)",
      R"(TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_HIT_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; ITOM hits from local IO)",
      R"(TOR Occupancy : ItoMs issued by IO Devices that Hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_HIT_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO hits from local IO)",
      R"(TOR Occupancy : RFOs issued by IO Devices that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; ItoM from local IO)",
      R"(TOR Occupancy : RFOs issued by IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; ITOM from local IO)",
      R"(TOR Occupancy : ItoMs issued by IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO from local IA)",
      R"(TOR Occupancy; Read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_RFO_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO prefetch from local IA)",
      R"(TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_LLCPREFRFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; LLCPrefRFO from local IA)",
      R"(TOR Occupancy; Last level cache prefetch read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_DRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd from local IA)",
      R"(TOR Occupancy; Data read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_DRD_OPT",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd Opt from local IA)",
      R"(TOR Occupancy; Data read opt from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd Opt Pref from local IA)",
      R"(TOR Occupancy; Data read opt prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_CRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; CRd from local IA)",
      R"(TOR Occupancy; Code read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_CRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; CRd Pref from local IA)",
      R"(TOR Occupancy; Code read prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_DRD_PREF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd Pref from local IA)",
      R"(TOR Occupancy; Data read prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd Pref misses from local IA)",
      R"(TOR Occupancy; Data read prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; DRd Pref misses from local IA)",
      R"(TOR Occupancy; Data read prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO misses from local IA)",
      R"(TOR Occupancy; Read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO misses from local IA)",
      R"(TOR Occupancy; Read for ownership from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_PREF_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO prefetch misses from local IA)",
      R"(TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO_PREF_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; RFO prefetch misses from local IA)",
      R"(TOR Occupancy; Read for ownership prefetch from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.TOTAL_E",
      EventDef::Encoding{.code = 0x37, .umask = 0x02, .msr_values = {0x00}},
      R"(All LLC lines in E state that are victimized on a fill)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.TOTAL_M",
      EventDef::Encoding{.code = 0x37, .umask = 0x01, .msr_values = {0x00}},
      R"(All LLC lines in M state that are victimized on a fill)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.TOTAL_S",
      EventDef::Encoding{.code = 0x37, .umask = 0x04, .msr_values = {0x00}},
      R"(All LLC lines in S state that are victimized on a fill)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_HIT_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_MISS_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC)",
      R"(TOR Inserts : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_PREFCAM_INSERTS.UPI_ALLCH",
      EventDef::Encoding{.code = 0x56, .umask = 0x0a, .msr_values = {0x00}},
      R"(Prefetch CAM Inserts : UPI - All Channels)",
      R"(Prefetch CAM Inserts : UPI - All Channels)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_PREFCAM_INSERTS.XPT_ALLCH",
      EventDef::Encoding{.code = 0x56, .umask = 0x05, .msr_values = {0x00}},
      R"(Prefetch CAM Inserts : XPT - All Channels)",
      R"(Prefetch CAM Inserts : XPT -All Channels)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_PREFCAM_DEMAND_DROPS.XPT_ALLCH",
      EventDef::Encoding{.code = 0x58, .umask = 0x05, .msr_values = {0x00}},
      R"(Data Prefetches Dropped)",
      R"(Data Prefetches Dropped)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_PREFCAM_DEMAND_MERGE.UPI_ALLCH",
      EventDef::Encoding{.code = 0x5d, .umask = 0x0a, .msr_values = {0x00}},
      R"(: UPI - All Channels)",
      R"(: UPI - All Channels)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_PREFCAM_DEMAND_MERGE.XPT_ALLCH",
      EventDef::Encoding{.code = 0x5d, .umask = 0x05, .msr_values = {0x00}},
      R"(: XPT - All Channels)",
      R"(: XPT - All Channels)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRDPTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRd PTEs issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : DRd PTEs issued by iA Cores due to a page walk that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_DRDPTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRd PTEs issued by iA Cores that Hit the LLC)",
      R"(TOR Inserts : DRd PTEs issued by iA Cores due to page walks that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_DRDPTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRd PTEs issued by iA Cores)",
      R"(TOR Inserts : DRd PTEs issued by iA Cores due to a page walk : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_WBEFTOE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WBEFtoEs issued by an IA Core.  Non Modified Write Backs)",
      R"(WbEFtoEs issued by iA Cores .  (Non Modified Write Backs)  :Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.  Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_HIT_PCIRDCUR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts; RdCur and FsRdCur hits from local IO)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_IMC_READS.TO_PMM",
      EventDef::Encoding{.code = 0x24, .umask = 0x20, .msr_values = {0x00}},
      R"(UNC_M2M_IMC_READS.TO_PMM)",
      R"(UNC_M2M_IMC_READS.TO_PMM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_MISS_PCIRDCUR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts; RdCur and FsRdCur misses from local IO)",
      R"(TOR Inserts : PCIRdCurs issued by IO Devices that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_IMC_WRITES.TO_PMM",
      EventDef::Encoding{.code = 0x25, .umask = 0x80, .msr_values = {0x00}},
      R"(PMM - All Channels)",
      R"(PMM - All Channels)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_HIT_PCIRDCUR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; RdCur and FsRdCur hits from local IO)",
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_PCIRDCUR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; RdCur and FsRdCur misses from local IO)",
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_PCIRDCUR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy; RdCur and FsRdCur from local IO)",
      R"(TOR Occupancy : PCIRdCurs issued by IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_LLCPREFCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; LLCPrefCode hits from local IA)",
      R"(TOR Inserts; Last level cache prefetch code read from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; LLCPrefCode misses from local IA)",
      R"(TOR Inserts; Last level cache prefetch code read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LLCPREFCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; LLCPrefCode hits from local IA)",
      R"(TOR Occupancy; Last level cache prefetch code read from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LLCPREFDATA",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; LLCPrefData hits from local IA)",
      R"(TOR Occupancy; Last level cache prefetch data read from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_LLCPREFDATA",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; LLCPrefData from local IA)",
      R"(TOR Occupancy; Last level cache prefetch data read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; LLCPrefCode misses from local IA)",
      R"(TOR Occupancy; Last level cache prefetch code read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LLCPREFDATA",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; LLCPrefData misses from local IA)",
      R"(TOR Occupancy; Last level cache prefetch data read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_LLCPREFCODE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; LLCPrefCode from local IA)",
      R"(TOR Inserts; Last level cache prefetch code read from local IA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_LLCPREFCODE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy; LLCPrefCode from local IA)",
      R"(TOR Occupancy; Last level cache prefetch data read from local IA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_RPQ_OCCUPANCY.NO_GNT_SCH0",
      EventDef::Encoding{.code = 0xe0, .umask = 0x04, .msr_values = {0x00}},
      R"(PMM Read Pending Queue Occupancy)",
      R"(Accumulates the per cycle occupancy of the PMM Read Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_RPQ_OCCUPANCY.NO_GNT_SCH1",
      EventDef::Encoding{.code = 0xe0, .umask = 0x08, .msr_values = {0x00}},
      R"(PMM Read Pending Queue Occupancy)",
      R"(Accumulates the per cycle occupancy of the PMM Read Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.RD_PCH0",
      EventDef::Encoding{.code = 0x03, .umask = 0x01, .msr_values = {0x00}},
      R"(DRAM Precharge commands. : Precharge due to read)",
      R"(DRAM Precharge commands. : Precharge due to read : Counts the number of DRAM Precharge commands sent on this channel. : Precharge from read bank scheduler)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.WR_PCH0",
      EventDef::Encoding{.code = 0x03, .umask = 0x02, .msr_values = {0x00}},
      R"(DRAM Precharge commands. : Precharge due to write)",
      R"(DRAM Precharge commands. : Precharge due to write : Counts the number of DRAM Precharge commands sent on this channel. : Precharge from write bank scheduler)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.UFILL_PCH0",
      EventDef::Encoding{.code = 0x03, .umask = 0x04, .msr_values = {0x00}},
      R"(DRAM Precharge commands.)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.PGT_PCH0",
      EventDef::Encoding{.code = 0x03, .umask = 0x08, .msr_values = {0x00}},
      R"(DRAM Precharge commands. : Prechages from Page Table)",
      R"(DRAM Precharge commands. : Prechages from Page Table : Counts the number of DRAM Precharge commands sent on this channel. : Equivalent to PAGE_EMPTY)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.RD_PCH1",
      EventDef::Encoding{.code = 0x03, .umask = 0x10, .msr_values = {0x00}},
      R"(DRAM Precharge commands.)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.WR_PCH1",
      EventDef::Encoding{.code = 0x03, .umask = 0x20, .msr_values = {0x00}},
      R"(DRAM Precharge commands.)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.UFILL_PCH1",
      EventDef::Encoding{.code = 0x03, .umask = 0x40, .msr_values = {0x00}},
      R"(DRAM Precharge commands.)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.PGT_PCH1",
      EventDef::Encoding{.code = 0x03, .umask = 0x80, .msr_values = {0x00}},
      R"(DRAM Precharge commands.)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.UFILL",
      EventDef::Encoding{.code = 0x03, .umask = 0x44, .msr_values = {0x00}},
      R"(DRAM Precharge commands.)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR_NONPRE",
      EventDef::Encoding{.code = 0x05, .umask = 0xD0, .msr_values = {0x00}},
      R"(DRAM RD_CAS and WR_CAS Commands. : DRAM WR_CAS commands w/o auto-pre)",
      R"(DRAM RD_CAS and WR_CAS Commands. : DRAM WR_CAS commands w/o auto-pre : DRAM RD_CAS and WR_CAS Commands)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.PCH0",
      EventDef::Encoding{.code = 0x05, .umask = 0x40, .msr_values = {0x00}},
      R"(DRAM RD_CAS and WR_CAS Commands. : Pseudo Channel 0)",
      R"(DRAM RD_CAS and WR_CAS Commands. : Pseudo Channel 0 : DRAM RD_CAS and WR_CAS Commands)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.PCH1",
      EventDef::Encoding{.code = 0x05, .umask = 0x80, .msr_values = {0x00}},
      R"(DRAM RD_CAS and WR_CAS Commands. : Pseudo Channel 1)",
      R"(DRAM RD_CAS and WR_CAS Commands. : Pseudo Channel 1 : DRAM RD_CAS and WR_CAS Commands)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_RPQ_OCCUPANCY.GNT_WAIT_SCH0",
      EventDef::Encoding{.code = 0xE0, .umask = 0x10, .msr_values = {0x00}},
      R"(PMM Read Pending Queue Occupancy)",
      R"(PMM Read Pending Queue Occupancy : Accumulates the per cycle occupancy of the PMM Read Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_RPQ_OCCUPANCY.GNT_WAIT_SCH1",
      EventDef::Encoding{.code = 0xE0, .umask = 0x20, .msr_values = {0x00}},
      R"(PMM Read Pending Queue Occupancy)",
      R"(PMM Read Pending Queue Occupancy : Accumulates the per cycle occupancy of the PMM Read Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRd_Prefs issued by iA Cores targeting PMM Mem that Missed the LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_LOCAL_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRd_Prefs issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_REMOTE_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRd_Prefs issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRd_Prefs issued by iA Cores targeting DDR Mem that Missed the LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_LOCAL_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRd_Prefs issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_REMOTE_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRd_Prefs issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : CRd issued by iA Cores that Missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : CRd issued by iA Cores that Missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_PREF_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_PREF_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : ItoMCacheNears issued by iA Cores)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_WBMTOI",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WbMtoIs issued by an iA Cores. Modified Write Backs)",
      R"(WbMtoIs issued by iA Cores .  (Modified Write Backs)  :Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.  Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : ItoMs issued by iA Cores that Hit LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : ItoMs issued by iA Cores that Missed LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_UCRDF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : UCRdFs issued by iA Cores that Missed LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WIL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WiLs issued by iA Cores that Missed LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_WCILF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLF issued by iA Cores)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCILF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLF issued by iA Cores that Missed the LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCILF_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting PMM that missed the LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCILF_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCILF_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCILF_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting DDR that missed the LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCILF_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCILF_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_WCIL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLs issued by iA Cores)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCIL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLs issued by iA Cores that Missed the LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCIL_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLs issued by iA Cores targeting PMM that missed the LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCIL_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCIL_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_WCIL_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLs issued by iA Cores targeting DDR that missed the LLC)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LOCAL_WCIL_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed locally)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_REMOTE_WCIL_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_WBMTOI",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts : WbMtoIs issued by IO Devices)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_CLFLUSH",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts : CLFlushes issued by IO Devices)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally)",
      R"(TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : DRds issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally)",
      R"(TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : DRds issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting PMM Mem that Missed the LLC)",
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting PMM Mem that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_LOCAL_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally)",
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_REMOTE_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting PMM Mem that Missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting DDR Mem that Missed the LLC)",
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting DDR Mem that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_LOCAL_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally)",
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PREF_REMOTE_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : DRd_Prefs issued by iA Cores targeting DDR Mem that Missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : CRd issued by iA Cores that Missed the LLC - HOMed locally)",
      R"(TOR Occupancy : CRd issued by iA Cores that Missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : CRd issued by iA Cores that Missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : CRd issued by iA Cores that Missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_PREF_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed locally)",
      R"(TOR Occupancy : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD_PREF_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : CRd_Prefs issued by iA Cores that Missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_CLFLUSH",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : CLFlushes issued by iA Cores)",
      R"(TOR Occupancy : CLFlushes issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_CLFLUSHOPT",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : CLFlushOpts issued by iA Cores)",
      R"(TOR Occupancy : CLFlushOpts issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : ItoMCacheNears issued by iA Cores)",
      R"(TOR Occupancy : ItoMCacheNears issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_SPECITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : SpecItoMs issued by iA Cores)",
      R"(TOR Occupancy : SpecItoMs issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_WBMTOI",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WbMtoIs issued by iA Cores)",
      R"(TOR Occupancy : WbMtoIs issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : ItoMs issued by iA Cores)",
      R"(TOR Occupancy : ItoMs issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : ItoMs issued by iA Cores that Hit LLC)",
      R"(TOR Occupancy : ItoMs issued by iA Cores that Hit LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_ITOM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : ItoMs issued by iA Cores that Missed LLC)",
      R"(TOR Occupancy : ItoMs issued by iA Cores that Missed LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_UCRDF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : UCRdFs issued by iA Cores that Missed LLC)",
      R"(TOR Occupancy : UCRdFs issued by iA Cores that Missed LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WIL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WiLs issued by iA Cores that Missed LLC)",
      R"(TOR Occupancy : WiLs issued by iA Cores that Missed LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_WCILF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLF issued by iA Cores)",
      R"(TOR Occupancy : WCiLF issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCILF",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLF issued by iA Cores that Missed the LLC)",
      R"(TOR Occupancy : WCiLF issued by iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCILF_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCILF_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed locally)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCILF_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCILF_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCILF_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed locally)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCILF_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : WCiLFs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_WCIL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLs issued by iA Cores)",
      R"(TOR Occupancy : WCiLs issued by iA Cores : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCIL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLs issued by iA Cores that Missed the LLC)",
      R"(TOR Occupancy : WCiLs issued by iA Cores that Missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCIL_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCIL_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed locally)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCIL_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting PMM that missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_WCIL_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LOCAL_WCIL_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed locally)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed locally : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_REMOTE_WCIL_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely)",
      R"(TOR Occupancy : WCiLs issued by iA Cores targeting DDR that missed the LLC - HOMed remotely : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_WBMTOI",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy : WbMtoIs issued by IO Devices)",
      R"(TOR Occupancy : WbMtoIs issued by IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_CLFLUSH",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy : CLFlushes issued by IO Devices)",
      R"(TOR Occupancy : CLFlushes issued by IO Devices : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_HIT_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC)",
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that hit the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IO_MISS_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x36, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC)",
      R"(TOR Occupancy : ItoMCacheNears, indicating a partial write request, from IO Devices that missed the LLC : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.     Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : PMM Access)",
      R"(TOR Occupancy : PMM Access : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : PMM Access)",
      R"(TOR Inserts : PM Access : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Occupancy : DDR Access)",
      R"(TOR Occupancy : DDR Access : For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(TOR Inserts : DDR Access)",
      R"(TOR Inserts : DDR Access : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.FIRST_LOOKUPS",
      EventDef::Encoding{.code = 0x40, .umask = 0x01, .msr_values = {0x00}},
      R"(: IOTLB lookups first)",
      R"(: IOTLB lookups first : Some transactions have to look up IOTLB multiple times.  Counts the first time a request looks up IOTLB.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.CTXT_CACHE_LOOKUPS",
      EventDef::Encoding{.code = 0x40, .umask = 0x40, .msr_values = {0x00}},
      R"(: Context cache lookups)",
      R"(: Context cache lookups : Counts each time a transaction looks up root context cache.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU0.CTXT_CACHE_HITS",
      EventDef::Encoding{.code = 0x40, .umask = 0x80, .msr_values = {0x00}},
      R"(: Context cache hits)",
      R"(: Context cache hits : Counts each time a first look up of the transaction hits the RCC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.NUM_MEM_ACCESSES",
      EventDef::Encoding{.code = 0x41, .umask = 0xc0, .msr_values = {0x00}},
      R"(: IOMMU memory access)",
      R"(: IOMMU memory access : IOMMU sends out memory fetches when it misses the cache look up which is indicated by this signal.  M2IOSF only uses low priority channel)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.PWC_2M_HITS",
      EventDef::Encoding{.code = 0x41, .umask = 0x02, .msr_values = {0x00}},
      R"(: PWC Hit to a 4K page)",
      R"(: PWC Hit to a 4K page : Counts each time a transaction's first look up hits the SLPWC at the 4K level)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.PWC_1G_HITS",
      EventDef::Encoding{.code = 0x41, .umask = 0x04, .msr_values = {0x00}},
      R"(: PWC Hit to a 2M page)",
      R"(: PWC Hit to a 2M page : Counts each time a transaction's first look up hits the SLPWC at the 2M level)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.PWC_512G_HITS",
      EventDef::Encoding{.code = 0x41, .umask = 0x08, .msr_values = {0x00}},
      R"(: PWC Hit to a 1G page)",
      R"(: PWC Hit to a 1G page : Counts each time a transaction's first look up hits the SLPWC at the 1G level)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU1.PWC_256T_HITS",
      EventDef::Encoding{.code = 0x41, .umask = 0x10, .msr_values = {0x00}},
      R"(: PWT Hit to a 256T page)",
      R"(: PWT Hit to a 256T page : Counts each time a transaction's first look up hits the SLPWC at the 512G level)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .msr_values = {0x00}},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .msr_values = {0x00}},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .msr_values = {0x00}},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .msr_values = {0x00}},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .msr_values = {0x00}},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART5",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .msr_values = {0x00}},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .msr_values = {0x00}},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.CMPD.PART7",
      EventDef::Encoding{.code = 0x83, .umask = 0x80, .msr_values = {0x00}},
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request)",
      R"(Data requested of the CPU : CmpD - device sending completion to CPU request : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.IOMMU0",
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .msr_values = {0x00}},
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      R"(Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : IOMMU - Type 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.IOMMU1",
      EventDef::Encoding{.code = 0xc0, .umask = 0x01, .msr_values = {0x00}},
      R"(Data requested by the CPU : Core writing to Cards MMIO space)",
      R"(Data requested by the CPU : Core writing to Cards MMIO space : Number of DWs (4 bytes) requested by the main die.  Includes all requests initiated by the main die, including reads and writes. : IOMMU - Type 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART0",
      EventDef::Encoding{.code = 0xc2, .umask = 0x04, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 0)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 0 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART1",
      EventDef::Encoding{.code = 0xc2, .umask = 0x04, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 1)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 1 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART2",
      EventDef::Encoding{.code = 0xc2, .umask = 0x04, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 2)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART3",
      EventDef::Encoding{.code = 0xc2, .umask = 0x04, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 3)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART4",
      EventDef::Encoding{.code = 0xc2, .umask = 0x04, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 4)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 0 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART5",
      EventDef::Encoding{.code = 0xc2, .umask = 0x04, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 5)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 1 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART6",
      EventDef::Encoding{.code = 0xc2, .umask = 0x04, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 6)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART7",
      EventDef::Encoding{.code = 0xc2, .umask = 0x04, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 7)",
      R"(PCIe Completion Buffer Inserts of completions with data : Part 2 : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.ALL_PARTS",
      EventDef::Encoding{.code = 0xd5, .umask = 0xff, .msr_values = {0x00}},
      R"(UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.ALL_PARTS)",
      R"(UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.ALL_PARTS)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TRANSACTIONS.WR_PREF",
      EventDef::Encoding{.code = 0x11, .umask = 0x08, .msr_values = {0x00}},
      R"(Inbound write (fast path) requests received by the IRP.)",
      R"(Inbound write (fast path) requests to coherent memory, received by the IRP resulting in write ownership requests issued by IRP to the mesh.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_FREQ_MAX_LIMIT_THERMAL_CYCLES",
      EventDef::Encoding{.code = 0x04, .umask = 0x00, .msr_values = {0x00}},
      R"(Thermal Strongest Upper Limit Cycles)",
      R"(Thermal Strongest Upper Limit Cycles : Number of cycles any frequency is reduced due to a thermal limit.  Count only if throttling is occurring.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_FREQ_MAX_POWER_CYCLES",
      EventDef::Encoding{.code = 0x05, .umask = 0x00, .msr_values = {0x00}},
      R"(Power Strongest Upper Limit Cycles)",
      R"(Power Strongest Upper Limit Cycles : Counts the number of cycles when power is the upper limit on frequency.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_FREQ_TRANS_CYCLES",
      EventDef::Encoding{.code = 0x74, .umask = 0x00, .msr_values = {0x00}},
      R"(Cycles spent changing Frequency)",
      R"(Cycles spent changing Frequency : Counts the number of cycles when the system is changing frequency.  This can not be filtered by thread ID.  One can also use it with the occupancy counter that monitors number of threads in C0 to estimate the performance impact that frequency transitions had on the system.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PKG_RESIDENCY_C2E_CYCLES",
      EventDef::Encoding{.code = 0x2b, .umask = 0x00, .msr_values = {0x00}},
      R"(Package C State Residency - C2E)",
      R"(Package C State Residency - C2E : Counts the number of cycles when the package was in C2E.  This event can be used in conjunction with edge detect to count C2E entrances (or exits using invert).  Residency events do not include transition times.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PKG_RESIDENCY_C6_CYCLES",
      EventDef::Encoding{.code = 0x2d, .umask = 0x00, .msr_values = {0x00}},
      R"(Package C State Residency - C6)",
      R"(Package C State Residency - C6 : Counts the number of cycles when the package was in C6.  This event can be used in conjunction with edge detect to count C6 entrances (or exits using invert).  Residency events do not include transition times.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_POWER_STATE_OCCUPANCY_CORES_C0",
      EventDef::Encoding{.code = 0x35, .umask = 0x00, .msr_values = {0x00}},
      R"(Number of cores in C0)",
      R"(Number of cores in C0 : This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_POWER_STATE_OCCUPANCY_CORES_C3",
      EventDef::Encoding{.code = 0x36, .umask = 0x00, .msr_values = {0x00}},
      R"(Number of cores in C3)",
      R"(Number of cores in C3 : This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_POWER_STATE_OCCUPANCY_CORES_C6",
      EventDef::Encoding{.code = 0x37, .umask = 0x00, .msr_values = {0x00}},
      R"(Number of cores in C6)",
      R"(Number of cores in C6 : This is an occupancy event that tracks the number of cores that are in the chosen C-State.  It can be used by itself to get the average number of cores in that C-state with thresholding to generate histograms, or with other PCU events and occupancy triggering to capture other details.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PROCHOT_EXTERNAL_CYCLES",
      EventDef::Encoding{.code = 0x0a, .umask = 0x00, .msr_values = {0x00}},
      R"(External Prochot)",
      R"(External Prochot : Counts the number of cycles that we are in external PROCHOT mode.  This mode is triggered when a sensor off the die determines that something off-die (like DRAM) is too hot and must throttle to avoid damaging the chip.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_PROCHOT_INTERNAL_CYCLES",
      EventDef::Encoding{.code = 0x09, .umask = 0x00, .msr_values = {0x00}},
      R"(Internal Prochot)",
      R"(Internal Prochot : Counts the number of cycles that we are in Internal PROCHOT mode.  This mode is triggered when a sensor on the die determines that we are too hot and must throttle to avoid damaging the chip.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_mchbm,
      "UNC_MCHBM_CAS_COUNT.RD_REG",
      EventDef::Encoding{.code = 0x05, .umask = 0xc1, .msr_values = {0x00}},
      R"(Regular read CAS commands issued (does not include underfills))",
      R"(Regular read CAS commands issued (does not include underfills))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_mchbm,
      "UNC_MCHBM_CAS_COUNT.RD_UNDERFILL",
      EventDef::Encoding{.code = 0x05, .umask = 0xc4, .msr_values = {0x00}},
      R"(Underfill read CAS commands issued)",
      R"(Underfill read CAS commands issued)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_mchbm,
      "UNC_MCHBM_CAS_COUNT.RD",
      EventDef::Encoding{.code = 0x05, .umask = 0xcf, .msr_values = {0x00}},
      R"(Read CAS commands issued (regular and underfill))",
      R"(Read CAS commands issued (regular and underfill))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_mchbm,
      "UNC_MCHBM_CAS_COUNT.WR",
      EventDef::Encoding{.code = 0x05, .umask = 0xf0, .msr_values = {0x00}},
      R"(Write CAS commands issued)",
      R"(Write CAS commands issued)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_mchbm,
      "UNC_MCHBM_CAS_COUNT.ALL",
      EventDef::Encoding{.code = 0x05, .umask = 0xff, .msr_values = {0x00}},
      R"(All CAS commands issued)",
      R"(All CAS commands issued)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_IOMMU3.PWT_OCCUPANCY_MSB",
      EventDef::Encoding{.code = 0x43, .umask = 0x01, .msr_values = {0x00}},
      R"(: Global IOTLB invalidation cycles)",
      R"(: Global IOTLB invalidation cycles : Indicates that IOMMU is doing global invalidation.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace sapphirerapids_uncore_experimental
} // namespace facebook::hbt::perf_event::generated
