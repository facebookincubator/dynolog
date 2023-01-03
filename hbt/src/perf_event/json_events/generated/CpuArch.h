// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#pragma once

namespace facebook::hbt::perf_event {

enum class CpuFamily { AMD, INTEL, UNKNOWN };

inline std::ostream& operator<<(std::ostream& os, CpuFamily f) {
  switch (f) {
    case CpuFamily::AMD:
      return os << "AMD";
    case CpuFamily::INTEL:
      return os << "INTEL";
    case CpuFamily::UNKNOWN:
      return os << "UNKNOWN";
  }
}
// Create CpuFamily enumeration from integer.
inline CpuFamily makeCpuFamily(uint32_t cpu_family) {
  switch (cpu_family) {
    case 6:
      return CpuFamily::INTEL;
    case 25:
      return CpuFamily::AMD;
    // Not recognized CPU model.
    default:
      return CpuFamily::UNKNOWN;
  }
}

enum class CpuArch {
  // AMD Architectures
  MILAN,
  // Intel Architectures Sorted by model id.
  BDW,
  BDW_DE,
  BDX,
  CLX,
  GLM,
  HSX,
  ICL,
  IVB,
  KNL,
  KNM,
  NHM_EX,
  SKL,
  SKX,
  SNB,
  SNR,
  SPR,
  // Not recognized CPU model.
  UNKNOWN
};

inline std::ostream& operator<<(std::ostream& os, CpuArch ev) {
  switch (ev) {
    case CpuArch::MILAN:
      return os << "MILAN";
    case CpuArch::BDW:
      return os << "BDW";
    case CpuArch::BDW_DE:
      return os << "BDW-DE";
    case CpuArch::BDX:
      return os << "BDX";
    case CpuArch::CLX:
      return os << "CLX";
    case CpuArch::GLM:
      return os << "GLM";
    case CpuArch::HSX:
      return os << "HSX";
    case CpuArch::ICL:
      return os << "ICL";
    case CpuArch::IVB:
      return os << "IVB";
    case CpuArch::KNL:
      return os << "KNL";
    case CpuArch::KNM:
      return os << "KNM";
    case CpuArch::NHM_EX:
      return os << "NHM-EX";
    case CpuArch::SKL:
      return os << "SKL";
    case CpuArch::SKX:
      return os << "SKX";
    case CpuArch::SNB:
      return os << "SNB";
    case CpuArch::SNR:
      return os << "SNR";
    case CpuArch::SPR:
      return os << "SPR";
    default:
      return os << "<UnknownCPU>";
  }
}

// Create CpuArch from CPU information in integers.
inline CpuArch makeCpuArch(
    uint32_t cpu_family_num,
    uint32_t cpu_model_num,
    uint32_t cpu_step_num) {
  auto cpu_family = makeCpuFamily(cpu_family_num);
  if (cpu_family == CpuFamily::AMD) {
    switch (cpu_model_num) {
      case 1:
        return CpuArch::MILAN;
    }
  } else if (cpu_family == CpuFamily::INTEL) {
    switch (cpu_model_num) {
      case 42:
        return CpuArch::SNB;
      case 46:
        return CpuArch::NHM_EX;
      case 58:
        return CpuArch::IVB;
      case 61:
        return CpuArch::BDW;
      case 63:
        return CpuArch::HSX;
      case 71:
        return CpuArch::BDW;
      case 78:
        return CpuArch::SKL;
      case 79:
        return CpuArch::BDX;
      case 85:
        switch (cpu_step_num) {
          case 0x0:
            [[fallthrough]];
          case 0x1:
            [[fallthrough]];
          case 0x2:
            [[fallthrough]];
          case 0x3:
            [[fallthrough]];
          case 0x4:
            return CpuArch::SKX;
          case 0x5:
            [[fallthrough]];
          case 0x6:
            [[fallthrough]];
          case 0x7:
            [[fallthrough]];
          case 0x8:
            [[fallthrough]];
          case 0x9:
            [[fallthrough]];
          case 0xA:
            [[fallthrough]];
          case 0xB:
            [[fallthrough]];
          case 0xC:
            [[fallthrough]];
          case 0xD:
            [[fallthrough]];
          case 0xE:
            [[fallthrough]];
          case 0xF:
            return CpuArch::CLX;
            // Step count is extensive. No need for default
        } // End of step switch

      case 86:
        return CpuArch::BDW_DE;
      case 87:
        return CpuArch::KNL;
      case 92:
        return CpuArch::GLM;
      case 94:
        return CpuArch::SKL;
      case 95:
        return CpuArch::GLM;
      case 125:
        return CpuArch::ICL;
      case 126:
        return CpuArch::ICL;
      case 133:
        return CpuArch::KNM;
      case 134:
        return CpuArch::SNR;
      case 142:
        return CpuArch::SKL;
      case 143:
        return CpuArch::SPR;
      case 158:
        return CpuArch::SKL;
      case 165:
        return CpuArch::SKL;
      case 166:
        return CpuArch::SKL;
      case 167:
        return CpuArch::ICL;
      default:
        return CpuArch::UNKNOWN;
    } // End of model switch case
  } // End of Intel Family if case

  // Unknown CPU Family.
  return CpuArch::UNKNOWN;
}

} // namespace facebook::hbt::perf_event
