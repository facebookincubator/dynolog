// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace knightslanding_uncore {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from KnightsLanding_uncore.json (459 events).

    Supported SKUs:
        - Arch: x86, Model: KNL id: 87
        - Arch: x86, Model: KNM id: 133
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_edc_uclk,
      "UNC_E_U_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00},
      R"(UCLK count)",
      R"(UCLK count)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_edc_uclk,
      "UNC_E_EDC_ACCESS.HIT_CLEAN",
      EventDef::Encoding{.code = 0x02, .umask = 0x01},
      R"(Counts the number of read requests and streaming stores that hit in MCDRAM cache and the data in MCDRAM is clean with respect to DDR. This event is only valid in cache and hybrid memory mode.)",
      R"(Counts the number of read requests and streaming stores that hit in MCDRAM cache and the data in MCDRAM is clean with respect to DDR. This event is only valid in cache and hybrid memory mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_edc_uclk,
      "UNC_E_EDC_ACCESS.HIT_DIRTY",
      EventDef::Encoding{.code = 0x02, .umask = 0x02},
      R"(Counts the number of read requests and streaming stores that hit in MCDRAM cache and the data in MCDRAM is dirty with respect to DDR. This event is only valid in cache and hybrid memory mode. )",
      R"(Counts the number of read requests and streaming stores that hit in MCDRAM cache and the data in MCDRAM is dirty with respect to DDR. This event is only valid in cache and hybrid memory mode. )",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_edc_uclk,
      "UNC_E_EDC_ACCESS.MISS_CLEAN",
      EventDef::Encoding{.code = 0x02, .umask = 0x04},
      R"(Counts the number of read requests and streaming stores that miss in MCDRAM cache and the data evicted from the MCDRAM is clean with respect to DDR. This event is only valid in cache and hybrid memory mode.)",
      R"(Counts the number of read requests and streaming stores that miss in MCDRAM cache and the data evicted from the MCDRAM is clean with respect to DDR. This event is only valid in cache and hybrid memory mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_edc_uclk,
      "UNC_E_EDC_ACCESS.MISS_DIRTY",
      EventDef::Encoding{.code = 0x02, .umask = 0x08},
      R"(Counts the number of read requests and streaming stores that miss in MCDRAM cache and the data evicted from the MCDRAM is dirty with respect to DDR. This event is only valid in cache and hybrid memory mode.)",
      R"(Counts the number of read requests and streaming stores that miss in MCDRAM cache and the data evicted from the MCDRAM is dirty with respect to DDR. This event is only valid in cache and hybrid memory mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_edc_uclk,
      "UNC_E_EDC_ACCESS.MISS_INVALID",
      EventDef::Encoding{.code = 0x02, .umask = 0x10},
      R"(Number of EDC Hits or Misses. Miss I)",
      R"(Number of EDC Hits or Misses. Miss I)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_edc_eclk,
      "UNC_E_E_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00},
      R"(ECLK count)",
      R"(ECLK count)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_edc_eclk,
      "UNC_E_RPQ_INSERTS",
      EventDef::Encoding{.code = 0x01, .umask = 0x01},
      R"(Counts the number of read requests received by the MCDRAM controller. This event is valid in all three memory modes: flat, cache and hybrid. In cache and hybrid memory mode, this event counts all read requests as well as streaming stores that hit or miss in the MCDRAM cache. )",
      R"(Counts the number of read requests received by the MCDRAM controller. This event is valid in all three memory modes: flat, cache and hybrid. In cache and hybrid memory mode, this event counts all read requests as well as streaming stores that hit or miss in the MCDRAM cache. )",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_edc_eclk,
      "UNC_E_WPQ_INSERTS",
      EventDef::Encoding{.code = 0x02, .umask = 0x01},
      R"(Counts the number of write requests received by the MCDRAM controller. This event is valid in all three memory modes: flat, cache and hybrid. In cache and hybrid memory mode, this event counts all streaming stores, writebacks and, read requests that miss in MCDRAM cache.)",
      R"(Counts the number of write requests received by the MCDRAM controller. This event is valid in all three memory modes: flat, cache and hybrid. In cache and hybrid memory mode, this event counts all streaming stores, writebacks and, read requests that miss in MCDRAM cache.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc_uclk,
      "UNC_M_U_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00},
      R"(UCLK count)",
      R"(UCLK count)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc_dclk,
      "UNC_M_D_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00},
      R"(DCLK count)",
      R"(DCLK count)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc_dclk,
      "UNC_M_CAS_COUNT.RD",
      EventDef::Encoding{.code = 0x03, .umask = 0x01},
      R"(CAS Reads)",
      R"(CAS Reads)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc_dclk,
      "UNC_M_CAS_COUNT.WR",
      EventDef::Encoding{.code = 0x03, .umask = 0x02},
      R"(CAS Writes)",
      R"(CAS Writes)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc_dclk,
      "UNC_M_CAS_COUNT.ALL",
      EventDef::Encoding{.code = 0x03, .umask = 0x03},
      R"(CAS All)",
      R"(CAS All)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_U_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00},
      R"(Uncore Clocks)",
      R"(Uncore Clocks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_OCCUPANCY.IRQ",
      EventDef::Encoding{.code = 0x11, .umask = 0x01},
      R"(Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IRQ)",
      R"(Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_OCCUPANCY.IRQ_REJ",
      EventDef::Encoding{.code = 0x11, .umask = 0x02},
      R"(Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IRQ Rejected)",
      R"(Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IRQ Rejected)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_OCCUPANCY.IPQ",
      EventDef::Encoding{.code = 0x11, .umask = 0x04},
      R"(Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IPQ)",
      R"(Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - IPQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_OCCUPANCY.PRQ",
      EventDef::Encoding{.code = 0x11, .umask = 0x10},
      R"(Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - PRQ)",
      R"(Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - PRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_OCCUPANCY.PRQ_REJ",
      EventDef::Encoding{.code = 0x11, .umask = 0x20},
      R"(Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - PRQ Rejected)",
      R"(Ingress Occupancy. Counts number of entries in the specified Ingress queue in each cycle. - PRQ Rejected)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_INSERTS.IRQ",
      EventDef::Encoding{.code = 0x13, .umask = 0x01},
      R"(Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IRQ)",
      R"(Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_INSERTS.IRQ_REJ",
      EventDef::Encoding{.code = 0x13, .umask = 0x02},
      R"(Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IRQ Rejected)",
      R"(Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IRQ Rejected)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_INSERTS.IPQ",
      EventDef::Encoding{.code = 0x13, .umask = 0x04},
      R"(Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IPQ)",
      R"(Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - IPQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_INSERTS.PRQ",
      EventDef::Encoding{.code = 0x13, .umask = 0x10},
      R"(Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - PRQ)",
      R"(Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - PRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_INSERTS.PRQ_REJ",
      EventDef::Encoding{.code = 0x13, .umask = 0x20},
      R"(Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - PRQ Rejected)",
      R"(Ingress Allocations. Counts number of allocations per cycle into the specified Ingress queue. - PRQ Rejected)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_INT_STARVED.IRQ",
      EventDef::Encoding{.code = 0x14, .umask = 0x01},
      R"(Cycles with the IRQ in Internal Starvation.)",
      R"(Cycles with the IRQ in Internal Starvation.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_INT_STARVED.IPQ",
      EventDef::Encoding{.code = 0x14, .umask = 0x04},
      R"(Cycles with the IPQ in Internal Starvation.)",
      R"(Cycles with the IPQ in Internal Starvation.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_INT_STARVED.ISMQ",
      EventDef::Encoding{.code = 0x14, .umask = 0x08},
      R"(Cycles with the ISMQ in Internal Starvation.)",
      R"(Cycles with the ISMQ in Internal Starvation.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_INT_STARVED.PRQ",
      EventDef::Encoding{.code = 0x14, .umask = 0x10},
      R"(Ingress internal starvation cycles. Counts cycles in internal starvation. This occurs when one or more of the entries in the ingress queue are being starved out by other entries in the queue.)",
      R"(Ingress internal starvation cycles. Counts cycles in internal starvation. This occurs when one or more of the entries in the ingress queue are being starved out by other entries in the queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ0_REJECT.AD_REQ_VN0",
      EventDef::Encoding{.code = 0x18, .umask = 0x01},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ0_REJECT.AD_RSP_VN0",
      EventDef::Encoding{.code = 0x18, .umask = 0x02},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ0_REJECT.BL_RSP_VN0",
      EventDef::Encoding{.code = 0x18, .umask = 0x04},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ0_REJECT.BL_WB_VN0",
      EventDef::Encoding{.code = 0x18, .umask = 0x08},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ0_REJECT.BL_NCB_VN0",
      EventDef::Encoding{.code = 0x18, .umask = 0x10},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ0_REJECT.BL_NCS_VN0",
      EventDef::Encoding{.code = 0x18, .umask = 0x20},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ0_REJECT.AK_NON_UPI",
      EventDef::Encoding{.code = 0x18, .umask = 0x40},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ0_REJECT.IV_NON_UPI",
      EventDef::Encoding{.code = 0x18, .umask = 0x80},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ1_REJECT.ANY_REJECT_IRQ0",
      EventDef::Encoding{.code = 0x19, .umask = 0x01},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ1_REJECT.SF_VICTIM",
      EventDef::Encoding{.code = 0x19, .umask = 0x08},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ1_REJECT.SF_WAY",
      EventDef::Encoding{.code = 0x19, .umask = 0x20},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ1_REJECT.ALLOW_SNP",
      EventDef::Encoding{.code = 0x19, .umask = 0x40},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IRQ1_REJECT.PA_MATCH",
      EventDef::Encoding{.code = 0x19, .umask = 0x80},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ0_REJECT.AD_REQ_VN0",
      EventDef::Encoding{.code = 0x20, .umask = 0x01},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ0_REJECT.AD_RSP_VN0",
      EventDef::Encoding{.code = 0x20, .umask = 0x02},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ0_REJECT.BL_RSP_VN0",
      EventDef::Encoding{.code = 0x20, .umask = 0x04},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ0_REJECT.BL_WB_VN0",
      EventDef::Encoding{.code = 0x20, .umask = 0x08},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ0_REJECT.BL_NCB_VN0",
      EventDef::Encoding{.code = 0x20, .umask = 0x10},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ0_REJECT.BL_NCS_VN0",
      EventDef::Encoding{.code = 0x20, .umask = 0x20},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ0_REJECT.AK_NON_UPI",
      EventDef::Encoding{.code = 0x20, .umask = 0x40},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ0_REJECT.IV_NON_UPI",
      EventDef::Encoding{.code = 0x20, .umask = 0x80},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ1_REJECT.ANY_REJECT_IRQ0",
      EventDef::Encoding{.code = 0x21, .umask = 0x01},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ1_REJECT.SF_VICTIM",
      EventDef::Encoding{.code = 0x21, .umask = 0x08},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ1_REJECT.SF_WAY",
      EventDef::Encoding{.code = 0x21, .umask = 0x20},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ1_REJECT.ALLOW_SNP",
      EventDef::Encoding{.code = 0x21, .umask = 0x40},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_PRQ1_REJECT.PA_MATCH",
      EventDef::Encoding{.code = 0x21, .umask = 0x80},
      R"(Ingress Request Queue Rejects)",
      R"(Ingress Request Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ0_REJECT.AD_REQ_VN0",
      EventDef::Encoding{.code = 0x22, .umask = 0x01},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ0_REJECT.AD_RSP_VN0",
      EventDef::Encoding{.code = 0x22, .umask = 0x02},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ0_REJECT.BL_RSP_VN0",
      EventDef::Encoding{.code = 0x22, .umask = 0x04},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ0_REJECT.BL_WB_VN0",
      EventDef::Encoding{.code = 0x22, .umask = 0x08},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ0_REJECT.BL_NCB_VN0",
      EventDef::Encoding{.code = 0x22, .umask = 0x10},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ0_REJECT.BL_NCS_VN0",
      EventDef::Encoding{.code = 0x22, .umask = 0x20},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ0_REJECT.AK_NON_UPI",
      EventDef::Encoding{.code = 0x22, .umask = 0x40},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ0_REJECT.IV_NON_UPI",
      EventDef::Encoding{.code = 0x22, .umask = 0x80},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ1_REJECT.ANY_REJECT_IPQ0",
      EventDef::Encoding{.code = 0x23, .umask = 0x01},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ1_REJECT.SF_VICTIM",
      EventDef::Encoding{.code = 0x23, .umask = 0x08},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ1_REJECT.SF_WAY",
      EventDef::Encoding{.code = 0x23, .umask = 0x20},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ1_REJECT.ALLOW_SNP",
      EventDef::Encoding{.code = 0x23, .umask = 0x40},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_IPQ1_REJECT.PA_MATCH",
      EventDef::Encoding{.code = 0x23, .umask = 0x80},
      R"(Ingress Probe Queue Rejects)",
      R"(Ingress Probe Queue Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.AD_REQ_VN0",
      EventDef::Encoding{.code = 0x24, .umask = 0x01},
      R"(ISMQ Rejects)",
      R"(ISMQ Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.AD_RSP_VN0",
      EventDef::Encoding{.code = 0x24, .umask = 0x02},
      R"(ISMQ Rejects)",
      R"(ISMQ Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.BL_RSP_VN0",
      EventDef::Encoding{.code = 0x24, .umask = 0x04},
      R"(ISMQ Rejects)",
      R"(ISMQ Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.BL_WB_VN0",
      EventDef::Encoding{.code = 0x24, .umask = 0x08},
      R"(ISMQ Rejects)",
      R"(ISMQ Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.BL_NCB_VN0",
      EventDef::Encoding{.code = 0x24, .umask = 0x10},
      R"(ISMQ Rejects)",
      R"(ISMQ Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.BL_NCS_VN0",
      EventDef::Encoding{.code = 0x24, .umask = 0x20},
      R"(ISMQ Rejects)",
      R"(ISMQ Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.AK_NON_UPI",
      EventDef::Encoding{.code = 0x24, .umask = 0x40},
      R"(ISMQ Rejects)",
      R"(ISMQ Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_REJECT.IV_NON_UPI",
      EventDef::Encoding{.code = 0x24, .umask = 0x80},
      R"(ISMQ Rejects)",
      R"(ISMQ Rejects)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.AD_REQ_VN0",
      EventDef::Encoding{.code = 0x2A, .umask = 0x01},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.AD_RSP_VN0",
      EventDef::Encoding{.code = 0x2A, .umask = 0x02},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.BL_RSP_VN0",
      EventDef::Encoding{.code = 0x2A, .umask = 0x04},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.BL_WB_VN0",
      EventDef::Encoding{.code = 0x2A, .umask = 0x08},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.BL_NCB_VN0",
      EventDef::Encoding{.code = 0x2A, .umask = 0x10},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.BL_NCS_VN0",
      EventDef::Encoding{.code = 0x2A, .umask = 0x20},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.AK_NON_UPI",
      EventDef::Encoding{.code = 0x2A, .umask = 0x40},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q0_RETRY.IV_NON_UPI",
      EventDef::Encoding{.code = 0x2A, .umask = 0x80},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q1_RETRY.ANY_REJECT_IRQ0",
      EventDef::Encoding{.code = 0x2B, .umask = 0x01},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q1_RETRY.SF_VICTIM",
      EventDef::Encoding{.code = 0x2B, .umask = 0x08},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q1_RETRY.SF_WAY",
      EventDef::Encoding{.code = 0x2B, .umask = 0x20},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q1_RETRY.ALLOW_SNP",
      EventDef::Encoding{.code = 0x2B, .umask = 0x40},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_REQ_Q1_RETRY.PA_MATCH",
      EventDef::Encoding{.code = 0x2B, .umask = 0x80},
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      R"(REQUESTQ'' includes:  IRQ, PRQ, IPQ, RRQ, WBQ (everything except for ISMQ))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.AD_REQ_VN0",
      EventDef::Encoding{.code = 0x2C, .umask = 0x01},
      R"(ISMQ Retries)",
      R"(ISMQ Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.AD_RSP_VN0",
      EventDef::Encoding{.code = 0x2C, .umask = 0x02},
      R"(ISMQ Retries)",
      R"(ISMQ Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.BL_RSP_VN0",
      EventDef::Encoding{.code = 0x2C, .umask = 0x04},
      R"(ISMQ Retries)",
      R"(ISMQ Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.BL_WB_VN0",
      EventDef::Encoding{.code = 0x2C, .umask = 0x08},
      R"(ISMQ Retries)",
      R"(ISMQ Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.BL_NCB_VN0",
      EventDef::Encoding{.code = 0x2C, .umask = 0x10},
      R"(ISMQ Retries)",
      R"(ISMQ Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.BL_NCS_VN0",
      EventDef::Encoding{.code = 0x2C, .umask = 0x20},
      R"(ISMQ Retries)",
      R"(ISMQ Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.AK_NON_UPI",
      EventDef::Encoding{.code = 0x2C, .umask = 0x40},
      R"(ISMQ Retries)",
      R"(ISMQ Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_ISMQ0_RETRY.IV_NON_UPI",
      EventDef::Encoding{.code = 0x2C, .umask = 0x80},
      R"(ISMQ Retries)",
      R"(ISMQ Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER0_RETRY.AD_REQ_VN0",
      EventDef::Encoding{.code = 0x2E, .umask = 0x01},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER0_RETRY.AD_RSP_VN0",
      EventDef::Encoding{.code = 0x2E, .umask = 0x02},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER0_RETRY.BL_RSP_VN0",
      EventDef::Encoding{.code = 0x2E, .umask = 0x04},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER0_RETRY.BL_WB_VN0",
      EventDef::Encoding{.code = 0x2E, .umask = 0x08},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER0_RETRY.BL_NCB_VN0",
      EventDef::Encoding{.code = 0x2E, .umask = 0x10},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER0_RETRY.BL_NCS_VN0",
      EventDef::Encoding{.code = 0x2E, .umask = 0x20},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER0_RETRY.AK_NON_UPI",
      EventDef::Encoding{.code = 0x2E, .umask = 0x40},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER0_RETRY.IV_NON_UPI",
      EventDef::Encoding{.code = 0x2E, .umask = 0x80},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER1_RETRY.ANY_REJECT_IRQ0",
      EventDef::Encoding{.code = 0x2F, .umask = 0x01},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER1_RETRY.SF_VICTIM",
      EventDef::Encoding{.code = 0x2F, .umask = 0x08},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER1_RETRY.SF_WAY",
      EventDef::Encoding{.code = 0x2F, .umask = 0x20},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER1_RETRY.ALLOW_SNP",
      EventDef::Encoding{.code = 0x2F, .umask = 0x40},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_INGRESS_RETRY_OTHER1_RETRY.PA_MATCH",
      EventDef::Encoding{.code = 0x2F, .umask = 0x80},
      R"(Other Queue Retries)",
      R"(Other Queue Retries)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_SF_LOOKUP.DATA_READ",
      EventDef::Encoding{.code = 0x34, .umask = 0x03},
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Read transactions)",
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_SF_LOOKUP.WRITE",
      EventDef::Encoding{.code = 0x34, .umask = 0x05},
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Writeback transactions from L2 to the LLC  This includes all write transactions -- both Cachable and UC.)",
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Writeback transactions from L2 to the LLC  This includes all write transactions -- both Cachable and UC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_SF_LOOKUP.REMOTE_SNOOP",
      EventDef::Encoding{.code = 0x34, .umask = 0x09},
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Filters for only snoop requests coming from the remote socket(s) through the IPQ.)",
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Filters for only snoop requests coming from the remote socket(s) through the IPQ.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_SF_LOOKUP.ANY",
      EventDef::Encoding{.code = 0x34, .umask = 0x11},
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Filters for any transaction originating from the IPQ or IRQ.  This does not include lookups originating from the ISMQ.)",
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Filters for any transaction originating from the IPQ or IRQ.  This does not include lookups originating from the ISMQ.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_CACHE_LINES_VICTIMIZED.M_STATE",
      EventDef::Encoding{.code = 0x37, .umask = 0x01},
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Read transactions)",
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Read transactions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_CACHE_LINES_VICTIMIZED.E_STATE",
      EventDef::Encoding{.code = 0x37, .umask = 0x02},
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Writeback transactions from L2 to the LLC  This includes all write transactions -- both Cachable and UC.)",
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Writeback transactions from L2 to the LLC  This includes all write transactions -- both Cachable and UC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_CACHE_LINES_VICTIMIZED.S_STATE",
      EventDef::Encoding{.code = 0x37, .umask = 0x04},
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Filters for only snoop requests coming from the remote socket(s) through the IPQ.)",
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Filters for only snoop requests coming from the remote socket(s) through the IPQ.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_CACHE_LINES_VICTIMIZED.F_STATE",
      EventDef::Encoding{.code = 0x37, .umask = 0x08},
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Filters for any transaction originating from the IPQ or IRQ.  This does not include lookups originating from the ISMQ.)",
      R"(Cache Lookups. Counts the number of times the LLC was accessed. Filters for any transaction originating from the IPQ or IRQ.  This does not include lookups originating from the ISMQ.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_CACHE_LINES_VICTIMIZED.LOCAL",
      EventDef::Encoding{.code = 0x37, .umask = 0x20},
      R"(Lines Victimized that Match NID)",
      R"(Lines Victimized that Match NID)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_CACHE_LINES_VICTIMIZED.REMOTE",
      EventDef::Encoding{.code = 0x37, .umask = 0x80},
      R"(Lines Victimized that Does Not Match NID)",
      R"(Lines Victimized that Does Not Match NID)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_INSERTS.IRQ",
      EventDef::Encoding{.code = 0x35, .umask = 0x31},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IRQ)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_INSERTS.EVICT",
      EventDef::Encoding{.code = 0x35, .umask = 0x32},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -SF/LLC Evictions)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -SF/LLC Evictions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_INSERTS.PRQ",
      EventDef::Encoding{.code = 0x35, .umask = 0x34},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -PRQ)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -PRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_INSERTS.IPQ",
      EventDef::Encoding{.code = 0x35, .umask = 0x38},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IPQ)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IPQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_INSERTS.HIT",
      EventDef::Encoding{.code = 0x35, .umask = 0x1F},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -Hit (Not a Miss))",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -Hit (Not a Miss))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_INSERTS.MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x2F},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -Miss)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -Miss)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.IRQ",
      EventDef::Encoding{.code = 0x36, .umask = 0x31},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.EVICT",
      EventDef::Encoding{.code = 0x36, .umask = 0x32},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -SF/LLC Evictions)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -SF/LLC Evictions)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.PRQ",
      EventDef::Encoding{.code = 0x36, .umask = 0x34},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.IPQ",
      EventDef::Encoding{.code = 0x36, .umask = 0x38},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.HIT",
      EventDef::Encoding{.code = 0x36, .umask = 0x1F},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -Hit (Not a Miss))",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -Hit (Not a Miss))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.MISS",
      EventDef::Encoding{.code = 0x36, .umask = 0x2F},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -Miss)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -Miss)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_MISC.RSPI_WAS_FSE",
      EventDef::Encoding{.code = 0x39, .umask = 0x01},
      R"(Miscellaneous events in the Cbo. Silent Snoop Eviction)",
      R"(Miscellaneous events in the Cbo. Silent Snoop Eviction)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_MISC.WC_ALIASING",
      EventDef::Encoding{.code = 0x39, .umask = 0x02},
      R"(Miscellaneous events in the Cbo. Write Combining Aliasing)",
      R"(Miscellaneous events in the Cbo. Write Combining Aliasing)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_MISC.RFO_HIT_S",
      EventDef::Encoding{.code = 0x39, .umask = 0x08},
      R"(Miscellaneous events in the Cbo. RFO HitS)",
      R"(Miscellaneous events in the Cbo. RFO HitS)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_MISC.CV0_PREF_VIC",
      EventDef::Encoding{.code = 0x39, .umask = 0x10},
      R"(Miscellaneous events in the Cbo. CV0 Prefetch Victim)",
      R"(Miscellaneous events in the Cbo. CV0 Prefetch Victim)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_MISC.CV0_PREF_MISS",
      EventDef::Encoding{.code = 0x39, .umask = 0x20},
      R"(Miscellaneous events in the Cbo. CV0 Prefetch Miss)",
      R"(Miscellaneous events in the Cbo. CV0 Prefetch Miss)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_INGRESS_CYCLES_NE.CBO_IDI",
      EventDef::Encoding{.code = 0x10, .umask = 0x01},
      R"(Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_IDI)",
      R"(Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_IDI)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_INGRESS_CYCLES_NE.CBO_NCB",
      EventDef::Encoding{.code = 0x10, .umask = 0x02},
      R"(Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_NCB)",
      R"(Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_NCB)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_INGRESS_CYCLES_NE.CBO_NCS",
      EventDef::Encoding{.code = 0x10, .umask = 0x04},
      R"(Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_NCS)",
      R"(Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.CBO_NCS)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_INGRESS_CYCLES_NE.ALL",
      EventDef::Encoding{.code = 0x10, .umask = 0x80},
      R"(Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.ALL)",
      R"(Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty.ALL)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_NE.AD_0",
      EventDef::Encoding{.code = 0x23, .umask = 0x01},
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AD_0)",
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AD_0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_NE.AK_0",
      EventDef::Encoding{.code = 0x23, .umask = 0x02},
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AK_0)",
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AK_0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_NE.BL_0",
      EventDef::Encoding{.code = 0x23, .umask = 0x04},
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  BL_0)",
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  BL_0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_NE.AD_1",
      EventDef::Encoding{.code = 0x23, .umask = 0x08},
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AD_1)",
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AD_1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_NE.AK_1",
      EventDef::Encoding{.code = 0x23, .umask = 0x10},
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AK_1)",
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  AK_1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_NE.BL_1",
      EventDef::Encoding{.code = 0x23, .umask = 0x20},
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  BL_1)",
      R"(Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty.  BL_1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_INSERTS.AD_0",
      EventDef::Encoding{.code = 0x24, .umask = 0x01},
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AD_0)",
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AD_0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_INSERTS.AK_0",
      EventDef::Encoding{.code = 0x24, .umask = 0x02},
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_0)",
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_INSERTS.BL_0",
      EventDef::Encoding{.code = 0x24, .umask = 0x04},
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. BL_0)",
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. BL_0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_INSERTS.AK_CRD_0",
      EventDef::Encoding{.code = 0x24, .umask = 0x08},
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_CRD_0)",
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_CRD_0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_INSERTS.AD_1",
      EventDef::Encoding{.code = 0x24, .umask = 0x10},
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AD_1)",
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AD_1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_INSERTS.AK_1",
      EventDef::Encoding{.code = 0x24, .umask = 0x20},
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_1)",
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_INSERTS.BL_1",
      EventDef::Encoding{.code = 0x24, .umask = 0x40},
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. BL_1)",
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. BL_1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_INSERTS.AK_CRD_1",
      EventDef::Encoding{.code = 0x24, .umask = 0x80},
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_CRD_1)",
      R"(Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue. AK_CRD_1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_FULL.AD_0",
      EventDef::Encoding{.code = 0x25, .umask = 0x01},
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AD_0)",
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AD_0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_FULL.AK_0",
      EventDef::Encoding{.code = 0x25, .umask = 0x02},
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AK_0)",
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AK_0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_FULL.BL_0",
      EventDef::Encoding{.code = 0x25, .umask = 0x04},
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  BL_0)",
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  BL_0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_FULL.AD_1",
      EventDef::Encoding{.code = 0x25, .umask = 0x08},
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AD_1)",
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AD_1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_FULL.AK_1",
      EventDef::Encoding{.code = 0x25, .umask = 0x10},
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AK_1)",
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  AK_1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2pcie,
      "UNC_M2P_EGRESS_CYCLES_FULL.BL_1",
      EventDef::Encoding{.code = 0x25, .umask = 0x20},
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  BL_1)",
      R"(Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full.  BL_1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_C_TOR_INSERTS.IRQ_HIT",
      EventDef::Encoding{.code = 0x35, .umask = 0x11},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IRQ)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_C_TOR_INSERTS.IRQ_MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x21},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IRQ )",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IRQ )",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_C_TOR_INSERTS.PRQ_HIT",
      EventDef::Encoding{.code = 0x35, .umask = 0x14},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -PRQ)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -PRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_C_TOR_INSERTS.PRQ_MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x24},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -PRQ)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -PRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_C_TOR_INSERTS.IPQ_HIT",
      EventDef::Encoding{.code = 0x35, .umask = 0x18},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IPQ)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IPQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_C_TOR_INSERTS.IPQ_MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x28},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IPQ)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IPQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_C_TOR_INSERTS.LOC_ALL",
      EventDef::Encoding{.code = 0x35, .umask = 0x37},
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IRQ or PRQ)",
      R"(Counts the number of entries successfuly inserted into the TOR that match  qualifications specified by the subevent -IRQ or PRQ)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.IRQ_HIT",
      EventDef::Encoding{.code = 0x36, .umask = 0x11},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ hit)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ hit)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.IRQ_MISS",
      EventDef::Encoding{.code = 0x36, .umask = 0x21},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ miss)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IRQ or PRQ miss)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.PRQ_HIT",
      EventDef::Encoding{.code = 0x36, .umask = 0x14},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ hit)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ hit)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.PRQ_MISS",
      EventDef::Encoding{.code = 0x36, .umask = 0x24},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ miss)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -PRQ miss)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.IPQ_HIT",
      EventDef::Encoding{.code = 0x36, .umask = 0x18},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ hit)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ hit)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TOR_OCCUPANCY.IPQ_MISS",
      EventDef::Encoding{.code = 0x36, .umask = 0x28},
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ miss)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent -IPQ miss)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_CLOCK",
      EventDef::Encoding{.code = 0xC0, .umask = 0x00},
      R"(Uncore Clocks)",
      R"(Uncore Clocks)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_ACQUIRED.TGR0",
      EventDef::Encoding{.code = 0x80, .umask = 0x01},
      R"(CMS Agent0 AD Credits Acquired For Transgress 0)",
      R"(CMS Agent0 AD Credits Acquired For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_ACQUIRED.TGR1",
      EventDef::Encoding{.code = 0x80, .umask = 0x02},
      R"(CMS Agent0 AD Credits Acquired For Transgress 1)",
      R"(CMS Agent0 AD Credits Acquired For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_ACQUIRED.TGR2",
      EventDef::Encoding{.code = 0x80, .umask = 0x04},
      R"(CMS Agent0 AD Credits Acquired For Transgress 2)",
      R"(CMS Agent0 AD Credits Acquired For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_ACQUIRED.TGR3",
      EventDef::Encoding{.code = 0x80, .umask = 0x08},
      R"(CMS Agent0 AD Credits Acquired For Transgress 3)",
      R"(CMS Agent0 AD Credits Acquired For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_ACQUIRED.TGR4",
      EventDef::Encoding{.code = 0x80, .umask = 0x10},
      R"(CMS Agent0 AD Credits Acquired For Transgress 4)",
      R"(CMS Agent0 AD Credits Acquired For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_ACQUIRED.TGR5",
      EventDef::Encoding{.code = 0x80, .umask = 0x20},
      R"(CMS Agent0 AD Credits Acquired For Transgress 5)",
      R"(CMS Agent0 AD Credits Acquired For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_ACQUIRED.TGR6",
      EventDef::Encoding{.code = 0x80, .umask = 0x40},
      R"(CMS Agent0 AD Credits Acquired For Transgress 6)",
      R"(CMS Agent0 AD Credits Acquired For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_ACQUIRED.TGR7",
      EventDef::Encoding{.code = 0x80, .umask = 0x80},
      R"(CMS Agent0 AD Credits Acquired For Transgress 7)",
      R"(CMS Agent0 AD Credits Acquired For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_ACQUIRED_EXT.TGR8",
      EventDef::Encoding{.code = 0x81, .umask = 0x01},
      R"(CMS Agent0 AD Credits Acquired For Transgress 8)",
      R"(CMS Agent0 AD Credits Acquired For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_ACQUIRED_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0x81, .umask = 0x02},
      R"(CMS Agent0 AD Credits Acquired For Transgress 0-7)",
      R"(CMS Agent0 AD Credits Acquired For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR0",
      EventDef::Encoding{.code = 0x82, .umask = 0x01},
      R"(CMS Agent0 AD Credits Occupancy For Transgress 0)",
      R"(CMS Agent0 AD Credits Occupancy For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR1",
      EventDef::Encoding{.code = 0x82, .umask = 0x02},
      R"(CMS Agent0 AD Credits Occupancy For Transgress 1)",
      R"(CMS Agent0 AD Credits Occupancy For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR2",
      EventDef::Encoding{.code = 0x82, .umask = 0x04},
      R"(CMS Agent0 AD Credits Occupancy For Transgress 2)",
      R"(CMS Agent0 AD Credits Occupancy For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR3",
      EventDef::Encoding{.code = 0x82, .umask = 0x08},
      R"(CMS Agent0 AD Credits Occupancy For Transgress 3)",
      R"(CMS Agent0 AD Credits Occupancy For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR4",
      EventDef::Encoding{.code = 0x82, .umask = 0x10},
      R"(CMS Agent0 AD Credits Occupancy For Transgress 4)",
      R"(CMS Agent0 AD Credits Occupancy For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR5",
      EventDef::Encoding{.code = 0x82, .umask = 0x20},
      R"(CMS Agent0 AD Credits Occupancy For Transgress 5)",
      R"(CMS Agent0 AD Credits Occupancy For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR6",
      EventDef::Encoding{.code = 0x82, .umask = 0x40},
      R"(CMS Agent0 AD Credits Occupancy For Transgress 6)",
      R"(CMS Agent0 AD Credits Occupancy For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_OCCUPANCY.TGR7",
      EventDef::Encoding{.code = 0x82, .umask = 0x80},
      R"(CMS Agent0 AD Credits Occupancy For Transgress 7)",
      R"(CMS Agent0 AD Credits Occupancy For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_OCCUPANCY_EXT.TGR8",
      EventDef::Encoding{.code = 0x83, .umask = 0x01},
      R"(CMS Agent0 AD Credits Occupancy For Transgress 8)",
      R"(CMS Agent0 AD Credits Occupancy For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_AD_CRD_OCCUPANCY_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0x83, .umask = 0x02},
      R"(CMS Agent0 AD Credits Occupancy For Transgress 0-7)",
      R"(CMS Agent0 AD Credits Occupancy For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_ACQUIRED.TGR0",
      EventDef::Encoding{.code = 0x84, .umask = 0x01},
      R"(CMS Agent1 AD Credits Acquired For Transgress 0)",
      R"(CMS Agent1 AD Credits Acquired For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_ACQUIRED.TGR1",
      EventDef::Encoding{.code = 0x84, .umask = 0x02},
      R"(CMS Agent1 AD Credits Acquired For Transgress 1)",
      R"(CMS Agent1 AD Credits Acquired For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_ACQUIRED.TGR2",
      EventDef::Encoding{.code = 0x84, .umask = 0x04},
      R"(CMS Agent1 AD Credits Acquired For Transgress 2)",
      R"(CMS Agent1 AD Credits Acquired For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_ACQUIRED.TGR3",
      EventDef::Encoding{.code = 0x84, .umask = 0x08},
      R"(CMS Agent1 AD Credits Acquired For Transgress 3)",
      R"(CMS Agent1 AD Credits Acquired For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_ACQUIRED.TGR4",
      EventDef::Encoding{.code = 0x84, .umask = 0x10},
      R"(CMS Agent1 AD Credits Acquired For Transgress 4)",
      R"(CMS Agent1 AD Credits Acquired For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_ACQUIRED.TGR5",
      EventDef::Encoding{.code = 0x84, .umask = 0x20},
      R"(CMS Agent1 AD Credits Acquired For Transgress 5)",
      R"(CMS Agent1 AD Credits Acquired For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_ACQUIRED.TGR6",
      EventDef::Encoding{.code = 0x84, .umask = 0x40},
      R"(CMS Agent1 AD Credits Acquired For Transgress 6)",
      R"(CMS Agent1 AD Credits Acquired For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_ACQUIRED.TGR7",
      EventDef::Encoding{.code = 0x84, .umask = 0x80},
      R"(CMS Agent1 AD Credits Acquired For Transgress 7)",
      R"(CMS Agent1 AD Credits Acquired For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_ACQUIRED_EXT.TGR8",
      EventDef::Encoding{.code = 0x85, .umask = 0x01},
      R"(CMS Agent1 AD Credits Acquired For Transgress 8)",
      R"(CMS Agent1 AD Credits Acquired For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_ACQUIRED_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0x85, .umask = 0x02},
      R"(CMS Agent1 AD Credits Acquired For Transgress 0-7)",
      R"(CMS Agent1 AD Credits Acquired For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR0",
      EventDef::Encoding{.code = 0x86, .umask = 0x01},
      R"(CMS Agent1 AD Credits Occupancy For Transgress 0)",
      R"(CMS Agent1 AD Credits Occupancy For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR1",
      EventDef::Encoding{.code = 0x86, .umask = 0x02},
      R"(CMS Agent1 AD Credits Occupancy For Transgress 1)",
      R"(CMS Agent1 AD Credits Occupancy For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR2",
      EventDef::Encoding{.code = 0x86, .umask = 0x04},
      R"(CMS Agent1 AD Credits Occupancy For Transgress 2)",
      R"(CMS Agent1 AD Credits Occupancy For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR3",
      EventDef::Encoding{.code = 0x86, .umask = 0x08},
      R"(CMS Agent1 AD Credits Occupancy For Transgress 3)",
      R"(CMS Agent1 AD Credits Occupancy For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR4",
      EventDef::Encoding{.code = 0x86, .umask = 0x10},
      R"(CMS Agent1 AD Credits Occupancy For Transgress 4)",
      R"(CMS Agent1 AD Credits Occupancy For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR5",
      EventDef::Encoding{.code = 0x86, .umask = 0x20},
      R"(CMS Agent1 AD Credits Occupancy For Transgress 5)",
      R"(CMS Agent1 AD Credits Occupancy For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR6",
      EventDef::Encoding{.code = 0x86, .umask = 0x40},
      R"(CMS Agent1 AD Credits Occupancy For Transgress 6)",
      R"(CMS Agent1 AD Credits Occupancy For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_OCCUPANCY.TGR7",
      EventDef::Encoding{.code = 0x86, .umask = 0x80},
      R"(CMS Agent1 AD Credits Occupancy For Transgress 7)",
      R"(CMS Agent1 AD Credits Occupancy For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_OCCUPANCY_EXT.TGR8",
      EventDef::Encoding{.code = 0x87, .umask = 0x01},
      R"(CMS Agent1 AD Credits Occupancy For Transgress 8)",
      R"(CMS Agent1 AD Credits Occupancy For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_AD_CRD_OCCUPANCY_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0x87, .umask = 0x02},
      R"(CMS Agent1 AD Credits Occupancy For Transgress 0-7)",
      R"(CMS Agent1 AD Credits Occupancy For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_ACQUIRED.TGR0",
      EventDef::Encoding{.code = 0x88, .umask = 0x01},
      R"(CMS Agent0 BL Credits Acquired For Transgress 0)",
      R"(CMS Agent0 BL Credits Acquired For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_ACQUIRED.TGR1",
      EventDef::Encoding{.code = 0x88, .umask = 0x02},
      R"(CMS Agent0 BL Credits Acquired For Transgress 1)",
      R"(CMS Agent0 BL Credits Acquired For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_ACQUIRED.TGR2",
      EventDef::Encoding{.code = 0x88, .umask = 0x04},
      R"(CMS Agent0 BL Credits Acquired For Transgress 2)",
      R"(CMS Agent0 BL Credits Acquired For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_ACQUIRED.TGR3",
      EventDef::Encoding{.code = 0x88, .umask = 0x08},
      R"(CMS Agent0 BL Credits Acquired For Transgress 3)",
      R"(CMS Agent0 BL Credits Acquired For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_ACQUIRED.TGR4",
      EventDef::Encoding{.code = 0x88, .umask = 0x10},
      R"(CMS Agent0 BL Credits Acquired For Transgress 4)",
      R"(CMS Agent0 BL Credits Acquired For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_ACQUIRED.TGR5",
      EventDef::Encoding{.code = 0x88, .umask = 0x20},
      R"(CMS Agent0 BL Credits Acquired For Transgress 5)",
      R"(CMS Agent0 BL Credits Acquired For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_ACQUIRED.TGR6",
      EventDef::Encoding{.code = 0x88, .umask = 0x40},
      R"(CMS Agent0 BL Credits Acquired For Transgress 6)",
      R"(CMS Agent0 BL Credits Acquired For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_ACQUIRED.TGR7",
      EventDef::Encoding{.code = 0x88, .umask = 0x80},
      R"(CMS Agent0 BL Credits Acquired For Transgress 7)",
      R"(CMS Agent0 BL Credits Acquired For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_ACQUIRED_EXT.TGR8",
      EventDef::Encoding{.code = 0x89, .umask = 0x01},
      R"(CMS Agent0 BL Credits Acquired For Transgress 8)",
      R"(CMS Agent0 BL Credits Acquired For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_ACQUIRED_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0x89, .umask = 0x02},
      R"(CMS Agent0 BL Credits Acquired For Transgress 0-7)",
      R"(CMS Agent0 BL Credits Acquired For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR0",
      EventDef::Encoding{.code = 0x8A, .umask = 0x01},
      R"(CMS Agent0 BL Credits Occupancy For Transgress 0)",
      R"(CMS Agent0 BL Credits Occupancy For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR1",
      EventDef::Encoding{.code = 0x8A, .umask = 0x02},
      R"(CMS Agent0 BL Credits Occupancy For Transgress 1)",
      R"(CMS Agent0 BL Credits Occupancy For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR2",
      EventDef::Encoding{.code = 0x8A, .umask = 0x04},
      R"(CMS Agent0 BL Credits Occupancy For Transgress 2)",
      R"(CMS Agent0 BL Credits Occupancy For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR3",
      EventDef::Encoding{.code = 0x8A, .umask = 0x08},
      R"(CMS Agent0 BL Credits Occupancy For Transgress 3)",
      R"(CMS Agent0 BL Credits Occupancy For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR4",
      EventDef::Encoding{.code = 0x8A, .umask = 0x10},
      R"(CMS Agent0 BL Credits Occupancy For Transgress 4)",
      R"(CMS Agent0 BL Credits Occupancy For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR5",
      EventDef::Encoding{.code = 0x8A, .umask = 0x20},
      R"(CMS Agent0 BL Credits Occupancy For Transgress 5)",
      R"(CMS Agent0 BL Credits Occupancy For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR6",
      EventDef::Encoding{.code = 0x8A, .umask = 0x40},
      R"(CMS Agent0 BL Credits Occupancy For Transgress 6)",
      R"(CMS Agent0 BL Credits Occupancy For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_OCCUPANCY.TGR7",
      EventDef::Encoding{.code = 0x8A, .umask = 0x80},
      R"(CMS Agent0 BL Credits Occupancy For Transgress 7)",
      R"(CMS Agent0 BL Credits Occupancy For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_OCCUPANCY_EXT.TGR8",
      EventDef::Encoding{.code = 0x8B, .umask = 0x01},
      R"(CMS Agent0 BL Credits Occupancy For Transgress 8)",
      R"(CMS Agent0 BL Credits Occupancy For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_BL_CRD_OCCUPANCY_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0x8B, .umask = 0x02},
      R"(CMS Agent0 BL Credits Occupancy For Transgress 0-7)",
      R"(CMS Agent0 BL Credits Occupancy For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_ACQUIRED.TGR0",
      EventDef::Encoding{.code = 0x8C, .umask = 0x01},
      R"(CMS Agent1 BL Credits Acquired For Transgress 0)",
      R"(CMS Agent1 BL Credits Acquired For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_ACQUIRED.TGR1",
      EventDef::Encoding{.code = 0x8C, .umask = 0x02},
      R"(CMS Agent1 BL Credits Acquired For Transgress 1)",
      R"(CMS Agent1 BL Credits Acquired For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_ACQUIRED.TGR2",
      EventDef::Encoding{.code = 0x8C, .umask = 0x04},
      R"(CMS Agent1 BL Credits Acquired For Transgress 2)",
      R"(CMS Agent1 BL Credits Acquired For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_ACQUIRED.TGR3",
      EventDef::Encoding{.code = 0x8C, .umask = 0x08},
      R"(CMS Agent1 BL Credits Acquired For Transgress 3)",
      R"(CMS Agent1 BL Credits Acquired For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_ACQUIRED.TGR4",
      EventDef::Encoding{.code = 0x8C, .umask = 0x10},
      R"(CMS Agent1 BL Credits Acquired For Transgress 4)",
      R"(CMS Agent1 BL Credits Acquired For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_ACQUIRED.TGR5",
      EventDef::Encoding{.code = 0x8C, .umask = 0x20},
      R"(CMS Agent1 BL Credits Acquired For Transgress 5)",
      R"(CMS Agent1 BL Credits Acquired For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_ACQUIRED.TGR6",
      EventDef::Encoding{.code = 0x8C, .umask = 0x40},
      R"(CMS Agent1 BL Credits Acquired For Transgress 6)",
      R"(CMS Agent1 BL Credits Acquired For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_ACQUIRED.TGR7",
      EventDef::Encoding{.code = 0x8C, .umask = 0x80},
      R"(CMS Agent1 BL Credits Acquired For Transgress 7)",
      R"(CMS Agent1 BL Credits Acquired For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_ACQUIRED_EXT.TGR8",
      EventDef::Encoding{.code = 0x8D, .umask = 0x01},
      R"(CMS Agent1 BL Credits Acquired For Transgress 8)",
      R"(CMS Agent1 BL Credits Acquired For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_ACQUIRED_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0x8D, .umask = 0x02},
      R"(CMS Agent1 BL Credits Acquired For Transgress 0-7)",
      R"(CMS Agent1 BL Credits Acquired For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR0",
      EventDef::Encoding{.code = 0x8E, .umask = 0x01},
      R"(CMS Agent1 BL Credits Occupancy For Transgress 0)",
      R"(CMS Agent1 BL Credits Occupancy For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR1",
      EventDef::Encoding{.code = 0x8E, .umask = 0x02},
      R"(CMS Agent1 BL Credits Occupancy For Transgress 1)",
      R"(CMS Agent1 BL Credits Occupancy For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR2",
      EventDef::Encoding{.code = 0x8E, .umask = 0x04},
      R"(CMS Agent1 BL Credits Occupancy For Transgress 2)",
      R"(CMS Agent1 BL Credits Occupancy For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR3",
      EventDef::Encoding{.code = 0x8E, .umask = 0x08},
      R"(CMS Agent1 BL Credits Occupancy For Transgress 3)",
      R"(CMS Agent1 BL Credits Occupancy For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR4",
      EventDef::Encoding{.code = 0x8E, .umask = 0x10},
      R"(CMS Agent1 BL Credits Occupancy For Transgress 4)",
      R"(CMS Agent1 BL Credits Occupancy For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR5",
      EventDef::Encoding{.code = 0x8E, .umask = 0x20},
      R"(CMS Agent1 BL Credits Occupancy For Transgress 5)",
      R"(CMS Agent1 BL Credits Occupancy For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR6",
      EventDef::Encoding{.code = 0x8E, .umask = 0x40},
      R"(CMS Agent1 BL Credits Occupancy For Transgress 6)",
      R"(CMS Agent1 BL Credits Occupancy For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_OCCUPANCY.TGR7",
      EventDef::Encoding{.code = 0x8E, .umask = 0x80},
      R"(CMS Agent1 BL Credits Occupancy For Transgress 7)",
      R"(CMS Agent1 BL Credits Occupancy For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_OCCUPANCY_EXT.TGR8",
      EventDef::Encoding{.code = 0x8F, .umask = 0x01},
      R"(CMS Agent1 BL Credits Occupancy For Transgress 8)",
      R"(CMS Agent1 BL Credits Occupancy For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_BL_CRD_OCCUPANCY_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0x8F, .umask = 0x02},
      R"(CMS Agent1 BL Credits Occupancy For Transgress 0-7)",
      R"(CMS Agent1 BL Credits Occupancy For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR0",
      EventDef::Encoding{.code = 0xD0, .umask = 0x01},
      R"(Stall on No AD Transgress Credits For Transgress 0)",
      R"(Stall on No AD Transgress Credits For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR1",
      EventDef::Encoding{.code = 0xD0, .umask = 0x02},
      R"(Stall on No AD Transgress Credits For Transgress 1)",
      R"(Stall on No AD Transgress Credits For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR2",
      EventDef::Encoding{.code = 0xD0, .umask = 0x04},
      R"(Stall on No AD Transgress Credits For Transgress 2)",
      R"(Stall on No AD Transgress Credits For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR3",
      EventDef::Encoding{.code = 0xD0, .umask = 0x08},
      R"(Stall on No AD Transgress Credits For Transgress 3)",
      R"(Stall on No AD Transgress Credits For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR4",
      EventDef::Encoding{.code = 0xD0, .umask = 0x10},
      R"(Stall on No AD Transgress Credits For Transgress 4)",
      R"(Stall on No AD Transgress Credits For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR5",
      EventDef::Encoding{.code = 0xD0, .umask = 0x20},
      R"(Stall on No AD Transgress Credits For Transgress 5)",
      R"(Stall on No AD Transgress Credits For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR6",
      EventDef::Encoding{.code = 0xD0, .umask = 0x40},
      R"(Stall on No AD Transgress Credits For Transgress 6)",
      R"(Stall on No AD Transgress Credits For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD.TGR7",
      EventDef::Encoding{.code = 0xD0, .umask = 0x80},
      R"(Stall on No AD Transgress Credits For Transgress 7)",
      R"(Stall on No AD Transgress Credits For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD_EXT.TGR8",
      EventDef::Encoding{.code = 0xD1, .umask = 0x01},
      R"(Stall on No AD Transgress Credits For Transgress 8)",
      R"(Stall on No AD Transgress Credits For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_AD_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0xD1, .umask = 0x02},
      R"(Stall on No AD Transgress Credits For Transgress 0-7)",
      R"(Stall on No AD Transgress Credits For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR0",
      EventDef::Encoding{.code = 0xD2, .umask = 0x01},
      R"(Stall on No AD Transgress Credits For Transgress 0)",
      R"(Stall on No AD Transgress Credits For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR1",
      EventDef::Encoding{.code = 0xD2, .umask = 0x02},
      R"(Stall on No AD Transgress Credits For Transgress 1)",
      R"(Stall on No AD Transgress Credits For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR2",
      EventDef::Encoding{.code = 0xD2, .umask = 0x04},
      R"(Stall on No AD Transgress Credits For Transgress 2)",
      R"(Stall on No AD Transgress Credits For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR3",
      EventDef::Encoding{.code = 0xD2, .umask = 0x08},
      R"(Stall on No AD Transgress Credits For Transgress 3)",
      R"(Stall on No AD Transgress Credits For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR4",
      EventDef::Encoding{.code = 0xD2, .umask = 0x10},
      R"(Stall on No AD Transgress Credits For Transgress 4)",
      R"(Stall on No AD Transgress Credits For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR5",
      EventDef::Encoding{.code = 0xD2, .umask = 0x20},
      R"(Stall on No AD Transgress Credits For Transgress 5)",
      R"(Stall on No AD Transgress Credits For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR6",
      EventDef::Encoding{.code = 0xD2, .umask = 0x40},
      R"(Stall on No AD Transgress Credits For Transgress 6)",
      R"(Stall on No AD Transgress Credits For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD.TGR7",
      EventDef::Encoding{.code = 0xD2, .umask = 0x80},
      R"(Stall on No AD Transgress Credits For Transgress 7)",
      R"(Stall on No AD Transgress Credits For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD_EXT.TGR8",
      EventDef::Encoding{.code = 0xD3, .umask = 0x01},
      R"(Stall on No AD Transgress Credits For Transgress 8)",
      R"(Stall on No AD Transgress Credits For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_AD_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0xD3, .umask = 0x02},
      R"(Stall on No AD Transgress Credits For Transgress 0-7)",
      R"(Stall on No AD Transgress Credits For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR0",
      EventDef::Encoding{.code = 0xD4, .umask = 0x01},
      R"(Stall on No AD Transgress Credits For Transgress 0)",
      R"(Stall on No AD Transgress Credits For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR1",
      EventDef::Encoding{.code = 0xD4, .umask = 0x02},
      R"(Stall on No AD Transgress Credits For Transgress 1)",
      R"(Stall on No AD Transgress Credits For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR2",
      EventDef::Encoding{.code = 0xD4, .umask = 0x04},
      R"(Stall on No AD Transgress Credits For Transgress 2)",
      R"(Stall on No AD Transgress Credits For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR3",
      EventDef::Encoding{.code = 0xD4, .umask = 0x08},
      R"(Stall on No AD Transgress Credits For Transgress 3)",
      R"(Stall on No AD Transgress Credits For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR4",
      EventDef::Encoding{.code = 0xD4, .umask = 0x10},
      R"(Stall on No AD Transgress Credits For Transgress 4)",
      R"(Stall on No AD Transgress Credits For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR5",
      EventDef::Encoding{.code = 0xD4, .umask = 0x20},
      R"(Stall on No AD Transgress Credits For Transgress 5)",
      R"(Stall on No AD Transgress Credits For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR6",
      EventDef::Encoding{.code = 0xD4, .umask = 0x40},
      R"(Stall on No AD Transgress Credits For Transgress 6)",
      R"(Stall on No AD Transgress Credits For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL.TGR7",
      EventDef::Encoding{.code = 0xD4, .umask = 0x80},
      R"(Stall on No AD Transgress Credits For Transgress 7)",
      R"(Stall on No AD Transgress Credits For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL_EXT.TGR8",
      EventDef::Encoding{.code = 0xD5, .umask = 0x01},
      R"(Stall on No AD Transgress Credits For Transgress 8)",
      R"(Stall on No AD Transgress Credits For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG0_STALL_NO_CRD_EGRESS_HORZ_BL_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0xD5, .umask = 0x02},
      R"(Stall on No AD Transgress Credits For Transgress 0-7)",
      R"(Stall on No AD Transgress Credits For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR0",
      EventDef::Encoding{.code = 0xD6, .umask = 0x01},
      R"(Stall on No AD Transgress Credits For Transgress 0)",
      R"(Stall on No AD Transgress Credits For Transgress 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR1",
      EventDef::Encoding{.code = 0xD6, .umask = 0x02},
      R"(Stall on No AD Transgress Credits For Transgress 1)",
      R"(Stall on No AD Transgress Credits For Transgress 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR2",
      EventDef::Encoding{.code = 0xD6, .umask = 0x04},
      R"(Stall on No AD Transgress Credits For Transgress 2)",
      R"(Stall on No AD Transgress Credits For Transgress 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR3",
      EventDef::Encoding{.code = 0xD6, .umask = 0x08},
      R"(Stall on No AD Transgress Credits For Transgress 3)",
      R"(Stall on No AD Transgress Credits For Transgress 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR4",
      EventDef::Encoding{.code = 0xD6, .umask = 0x10},
      R"(Stall on No AD Transgress Credits For Transgress 4)",
      R"(Stall on No AD Transgress Credits For Transgress 4)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR5",
      EventDef::Encoding{.code = 0xD6, .umask = 0x20},
      R"(Stall on No AD Transgress Credits For Transgress 5)",
      R"(Stall on No AD Transgress Credits For Transgress 5)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR6",
      EventDef::Encoding{.code = 0xD6, .umask = 0x40},
      R"(Stall on No AD Transgress Credits For Transgress 6)",
      R"(Stall on No AD Transgress Credits For Transgress 6)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL.TGR7",
      EventDef::Encoding{.code = 0xD6, .umask = 0x80},
      R"(Stall on No AD Transgress Credits For Transgress 7)",
      R"(Stall on No AD Transgress Credits For Transgress 7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL_EXT.TGR8",
      EventDef::Encoding{.code = 0xD7, .umask = 0x01},
      R"(Stall on No AD Transgress Credits For Transgress 8)",
      R"(Stall on No AD Transgress Credits For Transgress 8)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_AG1_STALL_NO_CRD_EGRESS_HORZ_BL_EXT.ANY_OF_TGR0_THRU_TGR7",
      EventDef::Encoding{.code = 0xD7, .umask = 0x02},
      R"(Stall on No AD Transgress Credits For Transgress 0-7)",
      R"(Stall on No AD Transgress Credits For Transgress 0-7)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_OCCUPANCY.AD_AG0",
      EventDef::Encoding{.code = 0x90, .umask = 0x01},
      R"(CMS Vert Egress Occupancy AD - Agent 0)",
      R"(CMS Vert Egress Occupancy AD - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_OCCUPANCY.AK_AG0",
      EventDef::Encoding{.code = 0x90, .umask = 0x02},
      R"(CMS Vert Egress Occupancy AK - Agent 0)",
      R"(CMS Vert Egress Occupancy AK - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_OCCUPANCY.BL_AG0",
      EventDef::Encoding{.code = 0x90, .umask = 0x04},
      R"(CMS Vert Egress Occupancy BL - Agent 0)",
      R"(CMS Vert Egress Occupancy BL - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_OCCUPANCY.IV_AG0",
      EventDef::Encoding{.code = 0x90, .umask = 0x08},
      R"(CMS Vert Egress Occupancy IV - Agent 0)",
      R"(CMS Vert Egress Occupancy IV - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_OCCUPANCY.AD_AG1",
      EventDef::Encoding{.code = 0x90, .umask = 0x10},
      R"(CMS Vert Egress Occupancy AD - Agent 1)",
      R"(CMS Vert Egress Occupancy AD - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_OCCUPANCY.AK_AG1",
      EventDef::Encoding{.code = 0x90, .umask = 0x20},
      R"(CMS Vert Egress Occupancy AK - Agent 1)",
      R"(CMS Vert Egress Occupancy AK - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_OCCUPANCY.BL_AG1",
      EventDef::Encoding{.code = 0x90, .umask = 0x40},
      R"(CMS Vert Egress Occupancy BL - Agent 1)",
      R"(CMS Vert Egress Occupancy BL - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_INSERTS.AD_AG0",
      EventDef::Encoding{.code = 0x91, .umask = 0x01},
      R"(CMS Vert Egress Allocations AD - Agent 0)",
      R"(CMS Vert Egress Allocations AD - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_INSERTS.AK_AG0",
      EventDef::Encoding{.code = 0x91, .umask = 0x02},
      R"(CMS Vert Egress Allocations AK - Agent 0)",
      R"(CMS Vert Egress Allocations AK - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_INSERTS.BL_AG0",
      EventDef::Encoding{.code = 0x91, .umask = 0x04},
      R"(CMS Vert Egress Allocations BL - Agent 0)",
      R"(CMS Vert Egress Allocations BL - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_INSERTS.IV_AG0",
      EventDef::Encoding{.code = 0x91, .umask = 0x08},
      R"(CMS Vert Egress Allocations IV - Agent 0)",
      R"(CMS Vert Egress Allocations IV - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_INSERTS.AD_AG1",
      EventDef::Encoding{.code = 0x91, .umask = 0x10},
      R"(CMS Vert Egress Allocations AD - Agent 1)",
      R"(CMS Vert Egress Allocations AD - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_INSERTS.AK_AG1",
      EventDef::Encoding{.code = 0x91, .umask = 0x20},
      R"(CMS Vert Egress Allocations AK - Agent 1)",
      R"(CMS Vert Egress Allocations AK - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_INSERTS.BL_AG1",
      EventDef::Encoding{.code = 0x91, .umask = 0x40},
      R"(CMS Vert Egress Allocations BL - Agent 1)",
      R"(CMS Vert Egress Allocations BL - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_FULL.AD_AG0",
      EventDef::Encoding{.code = 0x92, .umask = 0x01},
      R"(Cycles CMS Vertical Egress Queue Is Full AD - Agent 0)",
      R"(Cycles CMS Vertical Egress Queue Is Full AD - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_FULL.AK_AG0",
      EventDef::Encoding{.code = 0x92, .umask = 0x02},
      R"(Cycles CMS Vertical Egress Queue Is Full AK - Agent 0)",
      R"(Cycles CMS Vertical Egress Queue Is Full AK - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_FULL.BL_AG0",
      EventDef::Encoding{.code = 0x92, .umask = 0x04},
      R"(Cycles CMS Vertical Egress Queue Is Full BL - Agent 0)",
      R"(Cycles CMS Vertical Egress Queue Is Full BL - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_FULL.IV_AG0",
      EventDef::Encoding{.code = 0x92, .umask = 0x08},
      R"(Cycles CMS Vertical Egress Queue Is Full IV - Agent 0)",
      R"(Cycles CMS Vertical Egress Queue Is Full IV - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_FULL.AD_AG1",
      EventDef::Encoding{.code = 0x92, .umask = 0x10},
      R"(Cycles CMS Vertical Egress Queue Is Full AD - Agent 1)",
      R"(Cycles CMS Vertical Egress Queue Is Full AD - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_FULL.AK_AG1",
      EventDef::Encoding{.code = 0x92, .umask = 0x20},
      R"(Cycles CMS Vertical Egress Queue Is Full AK - Agent 1)",
      R"(Cycles CMS Vertical Egress Queue Is Full AK - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_FULL.BL_AG1",
      EventDef::Encoding{.code = 0x92, .umask = 0x40},
      R"(Cycles CMS Vertical Egress Queue Is Full BL - Agent 1)",
      R"(Cycles CMS Vertical Egress Queue Is Full BL - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_NE.AD_AG0",
      EventDef::Encoding{.code = 0x93, .umask = 0x01},
      R"(Cycles CMS Vertical Egress Queue Is Not Empty AD - Agent 0)",
      R"(Cycles CMS Vertical Egress Queue Is Not Empty AD - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_NE.AK_AG0",
      EventDef::Encoding{.code = 0x93, .umask = 0x02},
      R"(Cycles CMS Vertical Egress Queue Is Not Empty AK - Agent 0)",
      R"(Cycles CMS Vertical Egress Queue Is Not Empty AK - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_NE.BL_AG0",
      EventDef::Encoding{.code = 0x93, .umask = 0x04},
      R"(Cycles CMS Vertical Egress Queue Is Not Empty BL - Agent 0)",
      R"(Cycles CMS Vertical Egress Queue Is Not Empty BL - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_NE.IV_AG0",
      EventDef::Encoding{.code = 0x93, .umask = 0x08},
      R"(Cycles CMS Vertical Egress Queue Is Not Empty IV - Agent 0)",
      R"(Cycles CMS Vertical Egress Queue Is Not Empty IV - Agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_NE.AD_AG1",
      EventDef::Encoding{.code = 0x93, .umask = 0x10},
      R"(Cycles CMS Vertical Egress Queue Is Not Empty AD - Agent 1)",
      R"(Cycles CMS Vertical Egress Queue Is Not Empty AD - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_NE.AK_AG1",
      EventDef::Encoding{.code = 0x93, .umask = 0x20},
      R"(Cycles CMS Vertical Egress Queue Is Not Empty AK - Agent 1)",
      R"(Cycles CMS Vertical Egress Queue Is Not Empty AK - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_CYCLES_NE.BL_AG1",
      EventDef::Encoding{.code = 0x93, .umask = 0x40},
      R"(Cycles CMS Vertical Egress Queue Is Not Empty BL - Agent 1)",
      R"(Cycles CMS Vertical Egress Queue Is Not Empty BL - Agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_NACK.AD_AG0",
      EventDef::Encoding{.code = 0x98, .umask = 0x01},
      R"(CMS Vertical Egress NACKs)",
      R"(CMS Vertical Egress NACKs)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_NACK.AK_AG0",
      EventDef::Encoding{.code = 0x98, .umask = 0x02},
      R"(CMS Vertical Egress NACKs Onto AK Ring)",
      R"(CMS Vertical Egress NACKs Onto AK Ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_NACK.BL_AG0",
      EventDef::Encoding{.code = 0x98, .umask = 0x04},
      R"(CMS Vertical Egress NACKs Onto BL Ring)",
      R"(CMS Vertical Egress NACKs Onto BL Ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_NACK.IV_AG0",
      EventDef::Encoding{.code = 0x98, .umask = 0x08},
      R"(CMS Vertical Egress NACKs)",
      R"(CMS Vertical Egress NACKs)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_NACK.AD_AG1",
      EventDef::Encoding{.code = 0x98, .umask = 0x10},
      R"(CMS Vertical Egress NACKs)",
      R"(CMS Vertical Egress NACKs)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_NACK.AK_AG1",
      EventDef::Encoding{.code = 0x98, .umask = 0x20},
      R"(CMS Vertical Egress NACKs)",
      R"(CMS Vertical Egress NACKs)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_NACK.BL_AG1",
      EventDef::Encoding{.code = 0x98, .umask = 0x40},
      R"(CMS Vertical Egress NACKs)",
      R"(CMS Vertical Egress NACKs)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_STARVED.AD_AG0",
      EventDef::Encoding{.code = 0x9A, .umask = 0x01},
      R"(CMS Vertical Egress Injection Starvation)",
      R"(CMS Vertical Egress Injection Starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_STARVED.AK_AG0",
      EventDef::Encoding{.code = 0x9A, .umask = 0x02},
      R"(CMS Vertical Egress Injection Starvation Onto AK Ring)",
      R"(CMS Vertical Egress Injection Starvation Onto AK Ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_STARVED.BL_AG0",
      EventDef::Encoding{.code = 0x9A, .umask = 0x04},
      R"(CMS Vertical Egress Injection Starvation Onto BL Ring)",
      R"(CMS Vertical Egress Injection Starvation Onto BL Ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_STARVED.IV_AG0",
      EventDef::Encoding{.code = 0x9A, .umask = 0x08},
      R"(CMS Vertical Egress Injection Starvation)",
      R"(CMS Vertical Egress Injection Starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_STARVED.AD_AG1",
      EventDef::Encoding{.code = 0x9A, .umask = 0x10},
      R"(CMS Vertical Egress Injection Starvation)",
      R"(CMS Vertical Egress Injection Starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_STARVED.AK_AG1",
      EventDef::Encoding{.code = 0x9A, .umask = 0x20},
      R"(CMS Vertical Egress Injection Starvation)",
      R"(CMS Vertical Egress Injection Starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_STARVED.BL_AG1",
      EventDef::Encoding{.code = 0x9A, .umask = 0x40},
      R"(CMS Vertical Egress Injection Starvation)",
      R"(CMS Vertical Egress Injection Starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_ADS_USED.AD_AG0",
      EventDef::Encoding{.code = 0x9C, .umask = 0x01},
      R"(CMS Vertical ADS Used)",
      R"(CMS Vertical ADS Used)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_ADS_USED.AK_AG0",
      EventDef::Encoding{.code = 0x9C, .umask = 0x02},
      R"(CMS Vertical ADS Used)",
      R"(CMS Vertical ADS Used)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_ADS_USED.BL_AG0",
      EventDef::Encoding{.code = 0x9C, .umask = 0x04},
      R"(CMS Vertical ADS Used)",
      R"(CMS Vertical ADS Used)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_ADS_USED.AD_AG1",
      EventDef::Encoding{.code = 0x9C, .umask = 0x10},
      R"(CMS Vertical ADS Used)",
      R"(CMS Vertical ADS Used)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_ADS_USED.AK_AG1",
      EventDef::Encoding{.code = 0x9C, .umask = 0x20},
      R"(CMS Vertical ADS Used)",
      R"(CMS Vertical ADS Used)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_ADS_USED.BL_AG1",
      EventDef::Encoding{.code = 0x9C, .umask = 0x40},
      R"(CMS Vertical ADS Used)",
      R"(CMS Vertical ADS Used)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_BYPASS.AD_AG0",
      EventDef::Encoding{.code = 0x9E, .umask = 0x01},
      R"(CMS Vertical Egress Bypass. AD ring agent 0)",
      R"(CMS Vertical Egress Bypass. AD ring agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_BYPASS.AK_AG0",
      EventDef::Encoding{.code = 0x9E, .umask = 0x02},
      R"(CMS Vertical Egress Bypass. AK ring agent 0)",
      R"(CMS Vertical Egress Bypass. AK ring agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_BYPASS.BL_AG0",
      EventDef::Encoding{.code = 0x9E, .umask = 0x04},
      R"(CMS Vertical Egress Bypass. BL ring agent 0)",
      R"(CMS Vertical Egress Bypass. BL ring agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_BYPASS.IV",
      EventDef::Encoding{.code = 0x9E, .umask = 0x08},
      R"(CMS Vertical Egress Bypass. IV ring agent 0)",
      R"(CMS Vertical Egress Bypass. IV ring agent 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_BYPASS.AD_AG1",
      EventDef::Encoding{.code = 0x9E, .umask = 0x10},
      R"(CMS Vertical Egress Bypass. AD ring agent 1)",
      R"(CMS Vertical Egress Bypass. AD ring agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_BYPASS.AK_AG1",
      EventDef::Encoding{.code = 0x9E, .umask = 0x20},
      R"(CMS Vertical Egress Bypass. AK ring agent 1)",
      R"(CMS Vertical Egress Bypass. AK ring agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_VERT_BYPASS.BL_AG1",
      EventDef::Encoding{.code = 0x9E, .umask = 0x40},
      R"(CMS Vertical Egress Bypass. BL ring agent 1)",
      R"(CMS Vertical Egress Bypass. BL ring agent 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_OCCUPANCY.AD",
      EventDef::Encoding{.code = 0x94, .umask = 0x01},
      R"(CMS Horizontal Egress Occupancy AD)",
      R"(CMS Horizontal Egress Occupancy AD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_OCCUPANCY.AK",
      EventDef::Encoding{.code = 0x94, .umask = 0x02},
      R"(CMS Horizontal Egress Occupancy AK)",
      R"(CMS Horizontal Egress Occupancy AK)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_OCCUPANCY.BL",
      EventDef::Encoding{.code = 0x94, .umask = 0x04},
      R"(CMS Horizontal Egress Occupancy BL)",
      R"(CMS Horizontal Egress Occupancy BL)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_OCCUPANCY.IV",
      EventDef::Encoding{.code = 0x94, .umask = 0x08},
      R"(CMS Horizontal Egress Occupancy IV)",
      R"(CMS Horizontal Egress Occupancy IV)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_INSERTS.AD",
      EventDef::Encoding{.code = 0x95, .umask = 0x01},
      R"(CMS Horizontal Egress Inserts AD)",
      R"(CMS Horizontal Egress Inserts AD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_INSERTS.AK",
      EventDef::Encoding{.code = 0x95, .umask = 0x02},
      R"(CMS Horizontal Egress Inserts AK)",
      R"(CMS Horizontal Egress Inserts AK)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_INSERTS.BL",
      EventDef::Encoding{.code = 0x95, .umask = 0x04},
      R"(CMS Horizontal Egress Inserts BL)",
      R"(CMS Horizontal Egress Inserts BL)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_INSERTS.IV",
      EventDef::Encoding{.code = 0x95, .umask = 0x08},
      R"(CMS Horizontal Egress Inserts IV)",
      R"(CMS Horizontal Egress Inserts IV)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_CYCLES_FULL.AD",
      EventDef::Encoding{.code = 0x96, .umask = 0x01},
      R"(Cycles CMS Horizontal Egress Queue is Full AD)",
      R"(Cycles CMS Horizontal Egress Queue is Full AD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_CYCLES_FULL.AK",
      EventDef::Encoding{.code = 0x96, .umask = 0x02},
      R"(Cycles CMS Horizontal Egress Queue is Full AK)",
      R"(Cycles CMS Horizontal Egress Queue is Full AK)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_CYCLES_FULL.BL",
      EventDef::Encoding{.code = 0x96, .umask = 0x04},
      R"(Cycles CMS Horizontal Egress Queue is Full BL)",
      R"(Cycles CMS Horizontal Egress Queue is Full BL)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_CYCLES_FULL.IV",
      EventDef::Encoding{.code = 0x96, .umask = 0x08},
      R"(Cycles CMS Horizontal Egress Queue is Full IV)",
      R"(Cycles CMS Horizontal Egress Queue is Full IV)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_CYCLES_NE.AD",
      EventDef::Encoding{.code = 0x97, .umask = 0x01},
      R"(Cycles CMS Horizontal Egress Queue is Not Empty AD)",
      R"(Cycles CMS Horizontal Egress Queue is Not Empty AD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_CYCLES_NE.AK",
      EventDef::Encoding{.code = 0x97, .umask = 0x02},
      R"(Cycles CMS Horizontal Egress Queue is Not Empty AK)",
      R"(Cycles CMS Horizontal Egress Queue is Not Empty AK)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_CYCLES_NE.BL",
      EventDef::Encoding{.code = 0x97, .umask = 0x04},
      R"(Cycles CMS Horizontal Egress Queue is Not Empty BL)",
      R"(Cycles CMS Horizontal Egress Queue is Not Empty BL)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_CYCLES_NE.IV",
      EventDef::Encoding{.code = 0x97, .umask = 0x08},
      R"(Cycles CMS Horizontal Egress Queue is Not Empty IV)",
      R"(Cycles CMS Horizontal Egress Queue is Not Empty IV)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_NACK.AD",
      EventDef::Encoding{.code = 0x99, .umask = 0x01},
      R"(CMS Horizontal Egress NACKs)",
      R"(CMS Horizontal Egress NACKs)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_NACK.AK",
      EventDef::Encoding{.code = 0x99, .umask = 0x02},
      R"(CMS Horizontal Egress NACKs)",
      R"(CMS Horizontal Egress NACKs)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_NACK.BL",
      EventDef::Encoding{.code = 0x99, .umask = 0x04},
      R"(CMS Horizontal Egress NACKs)",
      R"(CMS Horizontal Egress NACKs)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_NACK.IV",
      EventDef::Encoding{.code = 0x99, .umask = 0x08},
      R"(CMS Horizontal Egress NACKs)",
      R"(CMS Horizontal Egress NACKs)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_STARVED.AD",
      EventDef::Encoding{.code = 0x9B, .umask = 0x01},
      R"(CMS Horizontal Egress Injection Starvation)",
      R"(CMS Horizontal Egress Injection Starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_STARVED.AK",
      EventDef::Encoding{.code = 0x9B, .umask = 0x02},
      R"(CMS Horizontal Egress Injection Starvation)",
      R"(CMS Horizontal Egress Injection Starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_STARVED.BL",
      EventDef::Encoding{.code = 0x9B, .umask = 0x04},
      R"(CMS Horizontal Egress Injection Starvation)",
      R"(CMS Horizontal Egress Injection Starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_STARVED.IV",
      EventDef::Encoding{.code = 0x9B, .umask = 0x08},
      R"(CMS Horizontal Egress Injection Starvation)",
      R"(CMS Horizontal Egress Injection Starvation)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_ADS_USED.AD",
      EventDef::Encoding{.code = 0x9D, .umask = 0x01},
      R"(CMS Horizontal ADS Used)",
      R"(CMS Horizontal ADS Used)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_ADS_USED.AK",
      EventDef::Encoding{.code = 0x9D, .umask = 0x02},
      R"(CMS Horizontal ADS Used)",
      R"(CMS Horizontal ADS Used)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_ADS_USED.BL",
      EventDef::Encoding{.code = 0x9D, .umask = 0x04},
      R"(CMS Horizontal ADS Used)",
      R"(CMS Horizontal ADS Used)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_BYPASS.AD",
      EventDef::Encoding{.code = 0x9F, .umask = 0x01},
      R"(CMS Horizontal Egress Bypass. AD ring)",
      R"(CMS Horizontal Egress Bypass. AD ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_BYPASS.AK",
      EventDef::Encoding{.code = 0x9F, .umask = 0x02},
      R"(CMS Horizontal Egress Bypass. AK ring)",
      R"(CMS Horizontal Egress Bypass. AK ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_BYPASS.BL",
      EventDef::Encoding{.code = 0x9F, .umask = 0x04},
      R"(CMS Horizontal Egress Bypass. BL ring)",
      R"(CMS Horizontal Egress Bypass. BL ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_HORZ_BYPASS.IV",
      EventDef::Encoding{.code = 0x9F, .umask = 0x08},
      R"(CMS Horizontal Egress Bypass. IV ring)",
      R"(CMS Horizontal Egress Bypass. IV ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_BOUNCES_VERT.AD",
      EventDef::Encoding{.code = 0xA0, .umask = 0x01},
      R"(Number of incoming messages from the Vertical ring that were bounced, by ring type.)",
      R"(Number of incoming messages from the Vertical ring that were bounced, by ring type.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_BOUNCES_VERT.AK",
      EventDef::Encoding{.code = 0xA0, .umask = 0x02},
      R"(Number of incoming messages from the Vertical ring that were bounced, by ring type - Acknowledgements to core)",
      R"(Number of incoming messages from the Vertical ring that were bounced, by ring type - Acknowledgements to core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_BOUNCES_VERT.BL",
      EventDef::Encoding{.code = 0xA0, .umask = 0x04},
      R"(Number of incoming messages from the Vertical ring that were bounced, by ring type - Data Responses to core.)",
      R"(Number of incoming messages from the Vertical ring that were bounced, by ring type - Data Responses to core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_BOUNCES_VERT.IV",
      EventDef::Encoding{.code = 0xA0, .umask = 0x08},
      R"(Number of incoming messages from the Vertical ring that were bounced, by ring type - Snoops of processor's cache.)",
      R"(Number of incoming messages from the Vertical ring that were bounced, by ring type - Snoops of processor's cache.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_BOUNCES_HORZ.AD",
      EventDef::Encoding{.code = 0xA1, .umask = 0x01},
      R"(Number of incoming messages from the Horizontal ring that were bounced, by ring type.)",
      R"(Number of incoming messages from the Horizontal ring that were bounced, by ring type.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_BOUNCES_HORZ.AK",
      EventDef::Encoding{.code = 0xA1, .umask = 0x02},
      R"(Number of incoming messages from the Horizontal ring that were bounced, by ring type - Acknowledgements to core)",
      R"(Number of incoming messages from the Horizontal ring that were bounced, by ring type - Acknowledgements to core)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_BOUNCES_HORZ.BL",
      EventDef::Encoding{.code = 0xA1, .umask = 0x04},
      R"(Number of incoming messages from the Horizontal ring that were bounced, by ring type - Data Responses to core.)",
      R"(Number of incoming messages from the Horizontal ring that were bounced, by ring type - Data Responses to core.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_BOUNCES_HORZ.IV",
      EventDef::Encoding{.code = 0xA1, .umask = 0x08},
      R"(Number of incoming messages from the Horizontal ring that were bounced, by ring type - Snoops of processor's cache.)",
      R"(Number of incoming messages from the Horizontal ring that were bounced, by ring type - Snoops of processor's cache.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_SINK_STARVED_VERT.AD",
      EventDef::Encoding{.code = 0xA2, .umask = 0x01},
      R"(Vertical ring sink starvation count - AD ring)",
      R"(Vertical ring sink starvation count - AD ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_SINK_STARVED_VERT.AK",
      EventDef::Encoding{.code = 0xA2, .umask = 0x02},
      R"(Vertical ring sink starvation count - AK ring)",
      R"(Vertical ring sink starvation count - AK ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_SINK_STARVED_VERT.BL",
      EventDef::Encoding{.code = 0xA2, .umask = 0x04},
      R"(Vertical ring sink starvation count - BL ring)",
      R"(Vertical ring sink starvation count - BL ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_SINK_STARVED_VERT.IV",
      EventDef::Encoding{.code = 0xA2, .umask = 0x08},
      R"(Vertical ring sink starvation count - IV ring)",
      R"(Vertical ring sink starvation count - IV ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_SINK_STARVED_HORZ.AD",
      EventDef::Encoding{.code = 0xA3, .umask = 0x01},
      R"(Horizontal ring sink starvation count - AD ring)",
      R"(Horizontal ring sink starvation count - AD ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_SINK_STARVED_HORZ.AK",
      EventDef::Encoding{.code = 0xA3, .umask = 0x02},
      R"(Horizontal ring sink starvation count - AK ring)",
      R"(Horizontal ring sink starvation count - AK ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_SINK_STARVED_HORZ.BL",
      EventDef::Encoding{.code = 0xA3, .umask = 0x04},
      R"(Horizontal ring sink starvation count - BL ring)",
      R"(Horizontal ring sink starvation count - BL ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_SINK_STARVED_HORZ.IV",
      EventDef::Encoding{.code = 0xA3, .umask = 0x08},
      R"(Horizontal ring sink starvation count - IV ring)",
      R"(Horizontal ring sink starvation count - IV ring)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_RING_SRC_THRTL",
      EventDef::Encoding{.code = 0xA4, .umask = 0x00},
      R"(Counts cycles in throttle mode.)",
      R"(Counts cycles in throttle mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_FAST_ASSERTED.VERT",
      EventDef::Encoding{.code = 0xA5, .umask = 0x00},
      R"(Counts cycles source throttling is adderted - vertical)",
      R"(Counts cycles source throttling is adderted - vertical)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_FAST_ASSERTED.HORZ",
      EventDef::Encoding{.code = 0xA5, .umask = 0x01},
      R"(Counts cycles source throttling is adderted - horizontal)",
      R"(Counts cycles source throttling is adderted - horizontal)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_AD_IN_USE.UP_EVEN",
      EventDef::Encoding{.code = 0xA6, .umask = 0x01},
      R"(Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Up and Even)",
      R"(Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Up and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_AD_IN_USE.UP_ODD",
      EventDef::Encoding{.code = 0xA6, .umask = 0x02},
      R"(Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Up and Odd)",
      R"(Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Up and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_AD_IN_USE.DN_EVEN",
      EventDef::Encoding{.code = 0xA6, .umask = 0x04},
      R"(Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Down and Even)",
      R"(Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Down and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_AD_IN_USE.DN_ODD",
      EventDef::Encoding{.code = 0xA6, .umask = 0x08},
      R"(Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Down and Odd)",
      R"(Counts the number of cycles that the Vertical AD ring is being used at this ring stop - Down and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_AD_IN_USE.LEFT_EVEN",
      EventDef::Encoding{.code = 0xA7, .umask = 0x01},
      R"(Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Left and Even)",
      R"(Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Left and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_AD_IN_USE.LEFT_ODD",
      EventDef::Encoding{.code = 0xA7, .umask = 0x02},
      R"(Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Left and Odd)",
      R"(Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Left and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_AD_IN_USE.RIGHT_EVEN",
      EventDef::Encoding{.code = 0xA7, .umask = 0x04},
      R"(Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Right and Even)",
      R"(Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Right and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_AD_IN_USE.RIGHT_ODD",
      EventDef::Encoding{.code = 0xA7, .umask = 0x08},
      R"(Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Right and Odd)",
      R"(Counts the number of cycles that the Horizontal AD ring is being used at this ring stop - Right and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_AK_IN_USE.UP_EVEN",
      EventDef::Encoding{.code = 0xA8, .umask = 0x01},
      R"(Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Up and Even)",
      R"(Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Up and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_AK_IN_USE.UP_ODD",
      EventDef::Encoding{.code = 0xA8, .umask = 0x02},
      R"(Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Up and Odd)",
      R"(Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Up and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_AK_IN_USE.DN_EVEN",
      EventDef::Encoding{.code = 0xA8, .umask = 0x04},
      R"(Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Down and Even)",
      R"(Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Down and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_AK_IN_USE.DN_ODD",
      EventDef::Encoding{.code = 0xA8, .umask = 0x08},
      R"(Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Down and Odd)",
      R"(Counts the number of cycles that the Vertical AK ring is being used at this ring stop - Down and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_AK_IN_USE.LEFT_EVEN",
      EventDef::Encoding{.code = 0xA9, .umask = 0x01},
      R"(Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Left and Even)",
      R"(Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Left and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_AK_IN_USE.LEFT_ODD",
      EventDef::Encoding{.code = 0xA9, .umask = 0x02},
      R"(Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Left and Odd)",
      R"(Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Left and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_AK_IN_USE.RIGHT_EVEN",
      EventDef::Encoding{.code = 0xA9, .umask = 0x04},
      R"(Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Right and Even)",
      R"(Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Right and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_AK_IN_USE.RIGHT_ODD",
      EventDef::Encoding{.code = 0xA9, .umask = 0x08},
      R"(Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Right and Odd)",
      R"(Counts the number of cycles that the Horizontal AK ring is being used at this ring stop - Right and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_BL_IN_USE.UP_EVEN",
      EventDef::Encoding{.code = 0xAA, .umask = 0x01},
      R"(Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Up and Even)",
      R"(Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Up and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_BL_IN_USE.UP_ODD",
      EventDef::Encoding{.code = 0xAA, .umask = 0x02},
      R"(Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Up and Odd)",
      R"(Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Up and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_BL_IN_USE.DN_EVEN",
      EventDef::Encoding{.code = 0xAA, .umask = 0x04},
      R"(Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Down and Even)",
      R"(Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Down and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_BL_IN_USE.DN_ODD",
      EventDef::Encoding{.code = 0xAA, .umask = 0x08},
      R"(Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Down and Odd)",
      R"(Counts the number of cycles that the Vertical BL ring is being used at this ring stop - Down and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_BL_IN_USE.LEFT_EVEN",
      EventDef::Encoding{.code = 0xAB, .umask = 0x01},
      R"(Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Left and Even)",
      R"(Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Left and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_BL_IN_USE.LEFT_ODD",
      EventDef::Encoding{.code = 0xAB, .umask = 0x02},
      R"(Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Left and Odd)",
      R"(Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Left and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_BL_IN_USE.RIGHT_EVEN",
      EventDef::Encoding{.code = 0xAB, .umask = 0x04},
      R"(Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Right and Even)",
      R"(Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Right and Even)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_BL_IN_USE.RIGHT_ODD",
      EventDef::Encoding{.code = 0xAB, .umask = 0x08},
      R"(Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Right and Odd)",
      R"(Counts the number of cycles that the Horizontal BL ring is being used at this ring stop - Right and Odd)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_IV_IN_USE.UP",
      EventDef::Encoding{.code = 0xAC, .umask = 0x01},
      R"(Counts the number of cycles that the Vertical IV ring is being used at this ring stop - Up)",
      R"(Counts the number of cycles that the Vertical IV ring is being used at this ring stop - Up)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_VERT_RING_IV_IN_USE.DN",
      EventDef::Encoding{.code = 0xAC, .umask = 0x04},
      R"(Counts the number of cycles that the Vertical IV ring is being used at this ring stop - Down)",
      R"(Counts the number of cycles that the Vertical IV ring is being used at this ring stop - Down)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_IV_IN_USE.LEFT",
      EventDef::Encoding{.code = 0xAD, .umask = 0x01},
      R"(Counts the number of cycles that the Horizontal IV ring is being used at this ring stop - Left)",
      R"(Counts the number of cycles that the Horizontal IV ring is being used at this ring stop - Left)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_HORZ_RING_IV_IN_USE.RIGHT",
      EventDef::Encoding{.code = 0xAD, .umask = 0x04},
      R"(Counts the number of cycles that the Horizontal IV ring is being used at this ring stop - Right)",
      R"(Counts the number of cycles that the Horizontal IV ring is being used at this ring stop - Right)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_ORDERING.IV_SNP_GO_UP",
      EventDef::Encoding{.code = 0xAE, .umask = 0x01},
      R"(Counts number of cycles IV was blocked in the TGR Egress due to SNP/GO Ordering requirements)",
      R"(Counts number of cycles IV was blocked in the TGR Egress due to SNP/GO Ordering requirements)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_EGRESS_ORDERING.IV_SNP_GO_DN",
      EventDef::Encoding{.code = 0xAE, .umask = 0x04},
      R"(Counts number of cycles IV was blocked in the TGR Egress due to SNP/GO Ordering requirements)",
      R"(Counts number of cycles IV was blocked in the TGR Egress due to SNP/GO Ordering requirements)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_OCCUPANCY.AD_BNC",
      EventDef::Encoding{.code = 0xB0, .umask = 0x01},
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_OCCUPANCY.AK_BNC",
      EventDef::Encoding{.code = 0xB0, .umask = 0x02},
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_OCCUPANCY.BL_BNC",
      EventDef::Encoding{.code = 0xB0, .umask = 0x04},
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_OCCUPANCY.IV_BNC",
      EventDef::Encoding{.code = 0xB0, .umask = 0x08},
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_OCCUPANCY.AD_CRD",
      EventDef::Encoding{.code = 0xB0, .umask = 0x10},
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_OCCUPANCY.BL_CRD",
      EventDef::Encoding{.code = 0xB0, .umask = 0x40},
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Occupancy. Occupancy event for the Ingress buffers in the CMS  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_INSERTS.AD_BNC",
      EventDef::Encoding{.code = 0xB1, .umask = 0x01},
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_INSERTS.AK_BNC",
      EventDef::Encoding{.code = 0xB1, .umask = 0x02},
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_INSERTS.BL_BNC",
      EventDef::Encoding{.code = 0xB1, .umask = 0x04},
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_INSERTS.IV_BNC",
      EventDef::Encoding{.code = 0xB1, .umask = 0x08},
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_INSERTS.AD_CRD",
      EventDef::Encoding{.code = 0xB1, .umask = 0x10},
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_INSERTS.BL_CRD",
      EventDef::Encoding{.code = 0xB1, .umask = 0x40},
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      R"(Transgress Ingress Allocations. Number of allocations into the CMS Ingress  The Ingress is used to queue up requests received from the mesh)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_BYPASS.AD_BNC",
      EventDef::Encoding{.code = 0xB2, .umask = 0x01},
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_BYPASS.AK_BNC",
      EventDef::Encoding{.code = 0xB2, .umask = 0x02},
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_BYPASS.BL_BNC",
      EventDef::Encoding{.code = 0xB2, .umask = 0x04},
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_BYPASS.IV_BNC",
      EventDef::Encoding{.code = 0xB2, .umask = 0x08},
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_BYPASS.AD_CRD",
      EventDef::Encoding{.code = 0xB2, .umask = 0x10},
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_BYPASS.BL_CRD",
      EventDef::Encoding{.code = 0xB2, .umask = 0x40},
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      R"(Transgress Ingress Bypass. Number of packets bypassing the CMS Ingress .)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_CRD_STARVED.AD_BNC",
      EventDef::Encoding{.code = 0xB3, .umask = 0x01},
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_CRD_STARVED.AK_BNC",
      EventDef::Encoding{.code = 0xB3, .umask = 0x02},
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_CRD_STARVED.BL_BNC",
      EventDef::Encoding{.code = 0xB3, .umask = 0x04},
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_CRD_STARVED.IV_BNC",
      EventDef::Encoding{.code = 0xB3, .umask = 0x08},
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_CRD_STARVED.AD_CRD",
      EventDef::Encoding{.code = 0xB3, .umask = 0x10},
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_CRD_STARVED.BL_CRD",
      EventDef::Encoding{.code = 0xB3, .umask = 0x40},
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_CRD_STARVED.IFV",
      EventDef::Encoding{.code = 0xB3, .umask = 0x80},
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, the Ingress is unable to forward to the Egress due to a lack of credit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_BUSY_STARVED.AD_BNC",
      EventDef::Encoding{.code = 0xB4, .umask = 0x01},
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority)",
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_BUSY_STARVED.BL_BNC",
      EventDef::Encoding{.code = 0xB4, .umask = 0x04},
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority)",
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_BUSY_STARVED.AD_CRD",
      EventDef::Encoding{.code = 0xB4, .umask = 0x10},
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority)",
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_H_TG_INGRESS_BUSY_STARVED.BL_CRD",
      EventDef::Encoding{.code = 0xB4, .umask = 0x40},
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority)",
      R"(Transgress Injection Starvation. Counts cycles under injection starvation mode.  This starvation is triggered when the CMS Ingress cannot send a transaction onto the mesh for a long period of time.  In this case, because a message from the other queue has higher priority)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace knightslanding_uncore
} // namespace facebook::hbt::perf_event::generated
