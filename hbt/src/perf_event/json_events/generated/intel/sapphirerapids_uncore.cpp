// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace sapphirerapids_uncore {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from sapphirerapids_uncore.json (83 events).

    Supported SKUs:
        - Arch: x86, Model: SPR id: 143
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(PCU PCLK Clockticks)",
      R"(Number of PCU PCLK Clock cycles while the event is enabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(IRP Clockticks)",
      R"(Number of IRP clock cycles while the event is enabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_MISC1.LOST_FWD",
      EventDef::Encoding{.code = 0x1f, .umask = 0x10, .msr_values = {0x00}},
      R"(Misc Events - Set 1 : Lost Forward)",
      R"(Misc Events - Set 1 : Lost Forward : Snoop pulled away ownership before a write was committed)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(M2P Clockticks)",
      R"(Number of M2P clock cycles while the event is enabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(IIO Clockticks)",
      R"(Number of IIO clock cycles while the event is enabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made by IIO Part0 to Memory)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made by IIO Part1 to Memory)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made by IIO Part2 to Memory)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made by IIO Part3 to Memory)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target)",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack) : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target)",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack) : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target)",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack) : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target)",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack) : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART5",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART7",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack) : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to stack, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART5",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack) : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack) : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART7",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Data requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Data requested of the CPU : Card writing to another Card (same or different stack) : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x01, .msr_values = {0x00}},
      R"(IMC Clockticks at DCLK frequency)",
      R"(Number of DRAM DCLK clock cycles while the event is enabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_HCLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(IMC Clockticks at HCLK frequency)",
      R"(Number of DRAM HCLK clock cycles while the event is enabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD_REG",
      EventDef::Encoding{.code = 0x05, .umask = 0xc1, .msr_values = {0x00}},
      R"(All DRAM read CAS commands issued (does not include underfills))",
      R"(DRAM RD_CAS and WR_CAS Commands. : DRAM RD_CAS commands w/out auto-pre : DRAM RD_CAS and WR_CAS Commands : Counts the total number or DRAM Read CAS commands issued on this channel.  This includes both regular RD CAS commands as well as those with implicit Precharge.   We do not filter based on major mode, as RD_CAS is not issued during WMM (with the exception of underfills).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD_UNDERFILL",
      EventDef::Encoding{.code = 0x05, .umask = 0xc4, .msr_values = {0x00}},
      R"(DRAM underfill read CAS commands issued)",
      R"(DRAM RD_CAS and WR_CAS Commands. : Underfill Read Issued : DRAM RD_CAS and WR_CAS Commands)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD",
      EventDef::Encoding{.code = 0x05, .umask = 0xcf, .msr_values = {0x00}},
      R"(All DRAM read CAS commands issued (including underfills))",
      R"(DRAM RD_CAS and WR_CAS Commands : Counts the total number of DRAM Read CAS commands issued on this channel.  This includes underfills.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR",
      EventDef::Encoding{.code = 0x05, .umask = 0xf0, .msr_values = {0x00}},
      R"(All DRAM write CAS commands issued)",
      R"(DRAM RD_CAS and WR_CAS Commands : Counts the total number of DRAM Write CAS commands issued on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_INSERTS.PCH0",
      EventDef::Encoding{.code = 0x10, .umask = 0x01, .msr_values = {0x00}},
      R"(Read Pending Queue Allocations)",
      R"(Read Pending Queue Allocations : Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_INSERTS.PCH1",
      EventDef::Encoding{.code = 0x10, .umask = 0x02, .msr_values = {0x00}},
      R"(Read Pending Queue Allocations)",
      R"(Read Pending Queue Allocations : Counts the number of allocations into the Read Pending Queue.  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after the CAS command has been issued to memory.  This includes both ISOCH and non-ISOCH requests.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_INSERTS.PCH0",
      EventDef::Encoding{.code = 0x20, .umask = 0x01, .msr_values = {0x00}},
      R"(Write Pending Queue Allocations)",
      R"(Write Pending Queue Allocations : Counts the number of allocations into the Write Pending Queue.  This can then be used to calculate the average queuing latency (in conjunction with the WPQ occupancy count).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_INSERTS.PCH1",
      EventDef::Encoding{.code = 0x20, .umask = 0x02, .msr_values = {0x00}},
      R"(Write Pending Queue Allocations)",
      R"(Write Pending Queue Allocations : Counts the number of allocations into the Write Pending Queue.  This can then be used to calculate the average queuing latency (in conjunction with the WPQ occupancy count).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_OCCUPANCY_PCH0",
      EventDef::Encoding{.code = 0x80, .umask = 0x00, .msr_values = {0x00}},
      R"(Read Pending Queue Occupancy)",
      R"(Read Pending Queue Occupancy : Accumulates the occupancies of the Read Pending Queue each cycle.  This can then be used to calculate both the average occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The RPQ is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC. They deallocate after the CAS command has been issued to memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_OCCUPANCY_PCH1",
      EventDef::Encoding{.code = 0x81, .umask = 0x00, .msr_values = {0x00}},
      R"(Read Pending Queue Occupancy)",
      R"(Read Pending Queue Occupancy : Accumulates the occupancies of the Read Pending Queue each cycle.  This can then be used to calculate both the average occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The RPQ is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC. They deallocate after the CAS command has been issued to memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_OCCUPANCY_PCH0",
      EventDef::Encoding{.code = 0x82, .umask = 0x00, .msr_values = {0x00}},
      R"(Write Pending Queue Occupancy)",
      R"(Write Pending Queue Occupancy : Accumulates the occupancies of the Write Pending Queue each cycle.  This can then be used to calculate both the average queue occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.  This is not to be confused with actually performing the write to DRAM.  Therefore, the average latency for this queue is actually not useful for deconstruction intermediate write latencies.  So, we provide filtering based on if the request has posted or not.  By using the not posted filter, we can track how long writes spent in the iMC before completions were sent to the HA.  The posted filter, on the other hand, provides information about how much queueing is actually happening in the iMC for writes before they are actually issued to memory.  High average occupancies will generally coincide with high write major mode counts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_OCCUPANCY_PCH1",
      EventDef::Encoding{.code = 0x83, .umask = 0x00, .msr_values = {0x00}},
      R"(Write Pending Queue Occupancy)",
      R"(Write Pending Queue Occupancy : Accumulates the occupancies of the Write Pending Queue each cycle.  This can then be used to calculate both the average queue occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The WPQ is used to schedule write out to the memory controller and to track the writes.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the HA to the iMC.  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have posted to the iMC.  This is not to be confused with actually performing the write to DRAM.  Therefore, the average latency for this queue is actually not useful for deconstruction intermediate write latencies.  So, we provide filtering based on if the request has posted or not.  By using the not posted filter, we can track how long writes spent in the iMC before completions were sent to the HA.  The posted filter, on the other hand, provides information about how much queueing is actually happening in the iMC for writes before they are actually issued to memory.  High average occupancies will generally coincide with high write major mode counts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(M2M Clockticks)",
      R"(Clockticks of the mesh to memory (M2M))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.ANY",
      EventDef::Encoding{.code = 0x21, .umask = 0x01, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from/to Any state)",
      R"(Multi-socket cacheline Directory update from/to Any state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m3upi,
      "UNC_M3UPI_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(M3UPI Clockticks)",
      R"(Number of M2UPI clock cycles while the event is enabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(UPI Clockticks)",
      R"(Number of UPI LL clock cycles while the event is enabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.ALL_DATA",
      EventDef::Encoding{.code = 0x02, .umask = 0x0f, .msr_values = {0x00}},
      R"(Valid Flits Sent : All Data)",
      R"(Valid Flits Sent : All Data : Counts number of data flits across this UPI link.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.READS_LOCAL",
      EventDef::Encoding{.code = 0x50, .umask = 0x01, .msr_values = {0x00}},
      R"(Read requests from a unit on this socket)",
      R"(Counts read requests coming from a unit on this socket made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.READS_REMOTE",
      EventDef::Encoding{.code = 0x50, .umask = 0x02, .msr_values = {0x00}},
      R"(Read requests from a remote socket)",
      R"(Counts read requests coming from a remote socket made into the CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.WRITES_LOCAL",
      EventDef::Encoding{.code = 0x50, .umask = 0x04, .msr_values = {0x00}},
      R"(Write Requests from a unit on this socket)",
      R"(Counts  write requests coming from a unit on this socket made into this CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.WRITES_REMOTE",
      EventDef::Encoding{.code = 0x50, .umask = 0x08, .msr_values = {0x00}},
      R"(Read and Write Requests; Writes Remote)",
      R"(Counts the total number of read requests made into the Home Agent. Reads include all read opcodes (including RFO).  Writes include all writes (streaming, evictions, HitM, etc).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.INVITOE",
      EventDef::Encoding{.code = 0x50, .umask = 0x30, .msr_values = {0x00}},
      R"(Requests for exclusive ownership of a cache line without receiving data)",
      R"(Counts the total number of requests coming from a unit on this socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_UPDATE.HA",
      EventDef::Encoding{.code = 0x54, .umask = 0x01, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory state updates; Directory Updated memory write from the HA pipe)",
      R"(Counts only multi-socket cacheline Directory state updates memory writes issued from the HA pipe. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_UPDATE.TOR",
      EventDef::Encoding{.code = 0x54, .umask = 0x02, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory state updates; Directory Updated memory write from TOR pipe)",
      R"(Counts only multi-socket cacheline Directory state updates due to memory writes issued from the TOR pipe which are the result of remote transaction hitting the SF/LLC and returning data Core2Core. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(CHA Clockticks)",
      R"(Number of CHA clock cycles while the event is enabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts for CRd misses from local IA)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode CRd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts for DRd misses from local IA)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts for DRd Pref misses from local IA)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_ITOM",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts for ItoM from local IO)",
      R"(Inserts into the TOR from local IO with the opcode ItoM)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts for DRd misses from local IA targeting local memory)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target local memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts for DRd misses from local IA targeting remote memory)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and target remote memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_LOCAL",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts for DRd Pref misses from local IA targeting local memory)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF, and target local memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PREF_REMOTE",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts for DRd Pref misses from local IA targeting remote memory)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRD_PREF, and target remote memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy for DRd misses from local IA)",
      R"(Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_LOCAL",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy for DRd misses from local IA targeting local memory)",
      R"(Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target local memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_REMOTE",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy for DRd misses from local IA targeting remote memory)",
      R"(Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target remote memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_PMM",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts for DRds issued by iA Cores targeting PMM Mem that Missed the LLC)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target PMM memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_DDR",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts for DRds issued by IA Cores targeting DDR Mem that Missed the LLC)",
      R"(Inserts into the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target DDR memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_DDR",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy for DRds issued by iA Cores targeting DDR Mem that Missed the LLC)",
      R"(Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target DDR memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD_PMM",
      EventDef::Encoding{.code = 0x36, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Occupancy for DRds issued by iA Cores targeting PMM Mem that Missed the LLC)",
      R"(Number of cycles for elements in the TOR from local IA cores which miss the LLC and snoop filter with the opcode DRd, and which target PMM memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_PCIRDCUR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts for RdCur from local IO)",
      R"(Inserts into the TOR from local IO with the opcode RdCur)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_LLCPREFDATA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; LLCPrefData hits from local IA)",
      R"(TOR Inserts; Last level cache prefetch data read from local IA that hits in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_LLCPREFDATA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; LLCPrefData from local IA)",
      R"(TOR Inserts; Last level cache prefetch data read from local IA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LLCPREFDATA",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts; LLCPrefData misses from local IA)",
      R"(TOR Inserts; Last level cache prefetch data read from local IA that misses in the snoop filter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_ITOMCACHENEAR",
      EventDef::Encoding{.code = 0x35, .umask = 0x04, .msr_values = {0x00}},
      R"(TOR Inserts for ItoMCacheNears from IO devices.)",
      R"(Inserts into the TOR from local IO devices with the opcode ItoMCacheNears.  This event indicates a partial write request.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_RPQ_OCCUPANCY.ALL_SCH0",
      EventDef::Encoding{.code = 0xe0, .umask = 0x01, .msr_values = {0x00}},
      R"(PMM Read Pending Queue occupancy)",
      R"(Accumulates the per cycle occupancy of the PMM Read Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_RPQ_OCCUPANCY.ALL_SCH1",
      EventDef::Encoding{.code = 0xe0, .umask = 0x02, .msr_values = {0x00}},
      R"(PMM Read Pending Queue occupancy)",
      R"(Accumulates the per cycle occupancy of the PMM Read Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_RPQ_INSERTS",
      EventDef::Encoding{.code = 0xe3, .umask = 0x00, .msr_values = {0x00}},
      R"(PMM Read Pending Queue inserts)",
      R"(Counts number of read requests allocated in the PMM Read Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_WPQ_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0xe4, .umask = 0x03, .msr_values = {0x00}},
      R"(PMM Write Pending Queue Occupancy)",
      R"(PMM Write Pending Queue Occupancy : Accumulates the per cycle occupancy of the Write Pending Queue to the PMM DIMM.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_WPQ_INSERTS",
      EventDef::Encoding{.code = 0xe7, .umask = 0x00, .msr_values = {0x00}},
      R"(PMM Write Pending Queue inserts)",
      R"(Counts number of  write requests allocated in the PMM Write Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_WPQ_OCCUPANCY.ALL_SCH0",
      EventDef::Encoding{.code = 0xE4, .umask = 0x01, .msr_values = {0x00}},
      R"(PMM Write Pending Queue Occupancy)",
      R"(PMM Write Pending Queue Occupancy : Accumulates the per cycle occupancy of the PMM Write Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PMM_WPQ_OCCUPANCY.ALL_SCH1",
      EventDef::Encoding{.code = 0xE4, .umask = 0x02, .msr_values = {0x00}},
      R"(PMM Write Pending Queue Occupancy)",
      R"(PMM Write Pending Queue Occupancy : Accumulates the per cycle occupancy of the PMM Write Pending Queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack) : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack) : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack) : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack) : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART4",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack) : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART5",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack) : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART6",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack) : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART7",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack))",
      R"(Number Transactions requested of the CPU : Card writing to another Card (same or different stack) : Also known as Inbound.  Number of 64B cache line requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace sapphirerapids_uncore
} // namespace facebook::hbt::perf_event::generated
