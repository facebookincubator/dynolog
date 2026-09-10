// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <cstdint>

namespace facebook::hbt::perf_event {

/// Linux's perf_event has PMUs that are statically enumerated, present
/// in linux/include/perf_event.h, and PMUs that are instantiated dynamically.
/// /sys/devices exposes some of the statically enumerated PMUs and all of the
/// dynamic ones.
///
/// This enumeration handles both static and dynamic PMUs.
///
/// Kept in its own header so that generated event tables can name PmuType
/// without pulling in PmuEvent.h and its transitive includes.
enum class PmuType : uint16_t {

  generic_hardware, // Equivalent to PERF_TYPE_HARDWARE: architecture
                    // independent CPU events
  software, // Equivalent to PERF_TYPE_SOFTWARE
  tracepoint, // Equivalent to PERF_TYPE_TRACEPOINT
  generic_hw_cache, // Equivalent to PERF_TYPE_HW_CACHE
  cpu, // Equivalent to PERF_TYPE_RAW: architecture specific CPU events
  breakpoint, // Equivalent to PERF_TYPE_BREAKPOINT

  kprobe,
  uprobe,
  power,

  // Intel Uncore caching
  uncore_cbox,
  uncore_cha,
  uncore_ha,
  // In SRF, there is a Converged/Common Mesh Stop attached to each CHA
  uncore_chacms,

  // Intel Uncore
  uncore_imc,
  uncore_iio,
  uncore_irp,
  uncore_m2m,
  uncore_m3upi,
  uncore_pcu,
  uncore_qpi,
  uncore_r2pcie,
  uncore_r3qpi,
  uncore_sbox,
  uncore_ubox,
  uncore_upi,

  // XXX: Below are Icelake PMUs, need to test them.
  uncore_ncu, // Similar to cbox
  uncore_arb, // Arbitration unit.
  uncore_edc_uclk, // EDC is a memory controller for MCDRAM (3D-stacked)
  uncore_edc_eclk,

  // Memory controller.
  uncore_imc_uclk,
  uncore_imc_dclk,

  // Memory to PCIe.
  uncore_m2pcie,

  // Intel PT
  intel_pt,

  // HBM Memory Controller
  // XXX: Need to test them?
  uncore_mchbm,

  // Arm
  armv8_pmuv3,

  // Nvidia Uncores (Grace-Hopper)
  nvidia_scf_pmu,
  nvidia_nvlink_c2c0_pmu,
  nvidia_nvlink_c2c1_pmu,
  nvidia_pcie_pmu,

  // Nvidia Uncores (Vera-Rubin / Vera). The sysfs names differ from
  // Grace-Hopper: nvidia_ucf_pmu replaces nvidia_scf_pmu, a single
  // nvidia_nvlink_c2c_pmu (per-socket instances) replaces c2c0/c2c1, and
  // nvidia_pcie{,_tgt}_pmu are enumerated per root complex
  // (<pmu>_<sock>_rc_<n>).
  nvidia_ucf_pmu,
  nvidia_nvlink_c2c_pmu,
  nvidia_cmem_latency_pmu,
  nvidia_nvclink_pmu,
  nvidia_nvdlink_pmu,
  nvidia_pcie_tgt_pmu,

  // AMD L3
  amd_l3,

  // AMD Zen5 UMC
  amd_umc,

  // AMD Data Fabric (used for Zen6/Venice CCM CXL bandwidth counters)
  amd_df,

  // Arm
  cs_etm,

  // Arm uncores
  arm_cspmu_mc,
  arm_cmn,
};

} // namespace facebook::hbt::perf_event
