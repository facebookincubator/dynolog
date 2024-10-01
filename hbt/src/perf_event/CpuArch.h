// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#pragma once

#include <cstdint>
#include <sstream>

namespace facebook::hbt::perf_event {

enum class CpuFamily { AMDZEN3, AMDZEN5, INTEL, ARM, UNKNOWN };

inline std::ostream& operator<<(std::ostream& os, CpuFamily f) {
  switch (f) {
    case CpuFamily::AMDZEN3:
      return os << "AMD Zen 3 / Zen 3+ / Zen 4";
    case CpuFamily::AMDZEN5:
      return os << "AMD Zen 5";
    case CpuFamily::INTEL:
      return os << "INTEL";
    case CpuFamily::ARM:
      return os << "ARM";
    case CpuFamily::UNKNOWN:
      return os << "UNKNOWN";
  }
}

// Create CpuFamily enumeration from integer.
inline CpuFamily makeCpuFamily(
#if defined(__x86_64__)
    uint32_t cpu_family
#else
    uint32_t /* cpu_family */
#endif
) {
#if defined(__x86_64__)
  switch (cpu_family) {
    case 6:
      return CpuFamily::INTEL;
    case 25:
      return CpuFamily::AMDZEN3;
    case 26:
      return CpuFamily::AMDZEN5;
    // Not recognized CPU model.
    default:
      return CpuFamily::UNKNOWN;
  }
#elif defined(__aarch64__)
  return CpuFamily::ARM;
#else
  return CpuFamily::UNKNOWN;
#endif
}

inline const char* armVendorIDFromInt(uint32_t vid) {
  switch (vid) {
    case 0x00:
      return "Reserved";
    case 0xC0:
      return "Ampere Computing";
    case 0x41:
      return "Arm Limited";
    case 0x42:
      return "Broadcom Corporation";
    case 0x43:
      return "Cavium Inc.";
    case 0x44:
      return "Digital Equipment Corporation";
    case 0x46:
      return "Fujitsu Ltd.";
    case 0x49:
      return "Infineon Technologies AG";
    case 0x4D:
      return "Motorola or Freescale Semiconductor Inc.";
    case 0x4E:
      return "NVIDIA Corporation";
    case 0x50:
      return "Applied Micro Circuits Corporation";
    case 0x51:
      return "Qualcomm Inc.";
    case 0x56:
      return "Marvell International Ltd.";
    case 0x69:
      return "Intel Corporation";
    default:
      return "Unknown";
  }
}

} // namespace facebook::hbt::perf_event

#include "hbt/src/perf_event/json_events/generated/CpuArch.h"

namespace facebook::hbt::perf_event {

inline CpuArch makeCpuArchArm(
    uint32_t vendor_id,
    uint32_t /*cpu_family_num*/,
    uint32_t cpu_model_num,
    uint32_t /*cpu_step_num*/) {
  switch (vendor_id) {
    case 0x41: // ARM Limited
      switch (cpu_model_num) {
        case 0xD0C:
          return CpuArch::NEOVERSE_N1;
        case 0xD49:
          return CpuArch::NEOVERSE_N2;
        case 0xD4F:
          return CpuArch::NEOVERSE_V2;
        default:
          return CpuArch::UNKNOWN;
      }
    case 0xC0: // Ampere Computing
      switch (cpu_model_num) {
        case 0xAC3:
          return CpuArch::AMPERE_ONE;
        default:
          return CpuArch::UNKNOWN;
      }
  }
  return CpuArch::UNKNOWN;
}

inline CpuArch makeCpuArch(
    uint32_t vendor_id,
    uint32_t cpu_family_num,
    uint32_t cpu_model_num,
    uint32_t cpu_step_num) {
#if defined(__aarch64__)
  return makeCpuArchArm(vendor_id, cpu_family_num, cpu_model_num, cpu_step_num);
#else
  return makeCpuArchX86(vendor_id, cpu_family_num, cpu_model_num, cpu_step_num);
#endif
}

} // namespace facebook::hbt::perf_event
