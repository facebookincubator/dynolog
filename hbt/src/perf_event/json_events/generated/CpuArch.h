// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto generated for hbt. Do not manually edit.
// @generated

#pragma once

namespace facebook::hbt::perf_event {

enum class CpuArch {
  // ARM Architectures
  NEOVERSE_N1,
  NEOVERSE_N2,
  NEOVERSE_V2,
  AMPERE_ONE,
  // AMD Architectures
  MILAN,
  GENOA,
  BERGAMO,
  TURIN,
  // Intel Architectures Sorted by model id.
  BDW,
  BDW_DE,
  BDX,
  CLX,
  EMR,
  GLM,
  HSX,
  ICL,
  ICX,
  IVB,
  KNL,
  NHM_EX,
  SKL,
  SKX,
  SNB,
  SNR,
  SPR,
  SRF,
  // Not recognized CPU model.
  UNKNOWN
};

inline std::ostream& operator<<(std::ostream& os, CpuArch ev) {
  switch (ev) {
    case CpuArch::NEOVERSE_N1:
      return os << "NEOVERSE_N1";
    case CpuArch::NEOVERSE_N2:
      return os << "NEOVERSE_N2";
    case CpuArch::NEOVERSE_V2:
      return os << "NEOVERSE_V2";
    case CpuArch::AMPERE_ONE:
      return os << "AMPERE_ONE";
    case CpuArch::MILAN:
      return os << "MILAN";
    case CpuArch::GENOA:
      return os << "GENOA";
    case CpuArch::BERGAMO:
      return os << "BERGAMO";
    case CpuArch::TURIN:
      return os << "TURIN";
    case CpuArch::BDW:
      return os << "BDW";
    case CpuArch::BDW_DE:
      return os << "BDW-DE";
    case CpuArch::BDX:
      return os << "BDX";
    case CpuArch::CLX:
      return os << "CLX";
    case CpuArch::EMR:
      return os << "EMR";
    case CpuArch::GLM:
      return os << "GLM";
    case CpuArch::HSX:
      return os << "HSX";
    case CpuArch::ICL:
      return os << "ICL";
    case CpuArch::ICX:
      return os << "ICX";
    case CpuArch::IVB:
      return os << "IVB";
    case CpuArch::KNL:
      return os << "KNL";
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
    case CpuArch::SRF:
      return os << "SRF";
    default:
      return os << "<UnknownCPU>";
  }
}

// Create CpuArch from CPU information in integers.
inline CpuArch makeCpuArchX86(
    uint32_t /*vendor_id*/,
    uint32_t cpu_family_num,
    uint32_t cpu_model_num,
    uint32_t cpu_step_num) {
  auto cpu_family = makeCpuFamily(cpu_family_num);
  if (cpu_family == CpuFamily::AMDZEN3) {
    switch (cpu_model_num) {
      case 1:
        return CpuArch::MILAN;
      case 17:
        return CpuArch::GENOA;
      case 160:
        return CpuArch::BERGAMO;
    }
  } else if (cpu_family == CpuFamily::AMDZEN5) {
    switch (cpu_model_num) {
      case 17:
        return CpuArch::TURIN;
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
      case 106:
        return CpuArch::ICX;
      case 108:
        return CpuArch::ICX;
      case 125:
        return CpuArch::ICL;
      case 126:
        return CpuArch::ICL;
      case 133:
        return CpuArch::KNL;
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
      case 175:
        return CpuArch::SRF;
      case 207:
        return CpuArch::EMR;
      default:
        return CpuArch::UNKNOWN;
    } // End of model switch case
  } // End of Intel Family if case

  // Unknown CPU Family.
  return CpuArch::UNKNOWN;
}

} // namespace facebook::hbt::perf_event
