// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace snowridgex_uncore_v1_07 {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from snowridgex_uncore_v1.07.json (39 events).

    Supported SKUs:
        - Arch: x86, Model: SNR id: 134
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .msr_values = {0x00}},
      R"(Clockticks of the uncore caching and home agent (CHA))",
      R"(Clockticks of the uncore caching and home agent (CHA))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : All requests from iA Cores that Missed the LLC)",
      R"(TOR Inserts : All requests from iA Cores that Missed the LLC : Counts the number of entries successfuly inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : CRds issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : CRds issued by iA Cores that Missed the LLC : Counts the number of entries successfuly inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC : Counts the number of entries successfuly inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : CRd_Prefs issued by iA Cores that Missed the LLC : Counts the number of entries successfuly inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRd_Opt issued by iA Cores that missed the LLC)",
      R"(TOR Inserts : DRd_Opt issued by iA Cores that missed the LLC : Counts the number of entries successfuly inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD_OPT_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : DRd_Opt_Prefs issued by iA Cores that missed the LLC)",
      R"(TOR Inserts : DRd_Opt_Prefs issued by iA Cores that missed the LLC : Counts the number of entries successfuly inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO_PREF",
      EventDef::Encoding{.code = 0x35, .umask = 0x01, .msr_values = {0x00}},
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : RFO_Prefs issued by iA Cores that Missed the LLC : Counts the number of entries successfuly inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      R"(TOR Inserts : WCiLs issued by iA Cores that Missed the LLC : Counts the number of entries successfuly inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
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
      R"(TOR Inserts : WCiLF issued by iA Cores that Missed the LLC : Counts the number of entries successfuly inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(Clockticks of the integrated IO (IIO) traffic controller)",
      R"(Clockticks of the integrated IO (IIO) traffic controller)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
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
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 0/1/2/3, Or x8 card plugged in to Lane 0/1, Or x4 card is plugged in to slot 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
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
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 2/3, Or x4 card is plugged in to slot 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART5",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART7",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card writing to DRAM)",
      R"(Data requested of the CPU : Card writing to DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART4",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x16 card plugged in to Lane 4/5/6/7, Or x8 card plugged in to Lane 4/5, Or x4 card is plugged in to slot 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART5",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART6",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x8 card plugged in to Lane 6/7, Or x4 card is plugged in to slot 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART7",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Four byte data request of the CPU : Card reading from DRAM)",
      R"(Data requested of the CPU : Card reading from DRAM : Number of DWs (4 bytes) the card requests of the main die.    Includes all requests initiated by the Card, including reads and writes. : x4 card is plugged in to slot 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(Clockticks of the IO coherency tracker (IRP))",
      R"(Clockticks of the IO coherency tracker (IRP))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.RD",
      EventDef::Encoding{.code = 0x02, .umask = 0x04, .msr_values = {0x00}},
      R"(DRAM Precharge commands. : Precharge due to read)",
      R"(DRAM Precharge commands. : Precharge due to read : Counts the number of DRAM Precharge commands sent on this channel. : Precharge from read bank scheduler)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.WR",
      EventDef::Encoding{.code = 0x02, .umask = 0x08, .msr_values = {0x00}},
      R"(DRAM Precharge commands. : Precharge due to write)",
      R"(DRAM Precharge commands. : Precharge due to write : Counts the number of DRAM Precharge commands sent on this channel. : Precharge from write bank scheduler)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD",
      EventDef::Encoding{.code = 0x04, .umask = 0x0f, .msr_values = {0x00}},
      R"(All DRAM read CAS commands issued (including underfills))",
      R"(Counts the total number of DRAM Read CAS commands, w/ and w/o auto-pre, issued on this channel.  This includes underfills.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR",
      EventDef::Encoding{.code = 0x04, .umask = 0x30, .msr_values = {0x00}},
      R"(All DRAM write CAS commands issued)",
      R"(Counts the total number of DRAM Write CAS commands issued, w/ and w/o auto-pre, on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.PGT",
      EventDef::Encoding{.code = 0x02, .umask = 0x10, .msr_values = {0x00}},
      R"(DRAM Precharge commands. : Precharge due to page table)",
      R"(DRAM Precharge commands. : Precharge due to page table : Counts the number of DRAM Precharge commands sent on this channel. : Prechages from Page Table)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .msr_values = {0x00}},
      R"(DRAM Clockticks)",
      R"(Clockticks of the integrated memory controller (IMC))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.ALL",
      EventDef::Encoding{.code = 0x02, .umask = 0x1C, .msr_values = {0x00}},
      R"(DRAM Precharge commands.)",
      R"(DRAM Precharge commands. : Counts the number of DRAM Precharge commands sent on this channel.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .msr_values = {0x00}},
      R"(Clockticks of the mesh to memory (M2M))",
      R"(Clockticks of the mesh to memory (M2M))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_CLOCKTICKS",
      EventDef::Encoding{.code = 0x01, .umask = 0x00, .msr_values = {0x00}},
      R"(Clockticks of the mesh to PCI (M2P))",
      R"(Clockticks of the mesh to PCI (M2P))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_ubox,
      "UNC_U_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x01, .msr_values = {0x00}},
      R"(Clockticks in the UBOX using a dedicated 48-bit Fixed Counter)",
      R"(Clockticks in the UBOX using a dedicated 48-bit Fixed Counter)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_pcu,
      "UNC_P_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .msr_values = {0x00}},
      R"(Clockticks of the power control unit (PCU))",
      R"(Clockticks of the power control unit (PCU))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace snowridgex_uncore_v1_07
} // namespace facebook::hbt::perf_event::generated
