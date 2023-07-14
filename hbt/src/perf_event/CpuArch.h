// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#pragma once

#include <sstream>

namespace facebook::hbt::perf_event {

enum class CpuFamily { AMD, INTEL, ARM, UNKNOWN };

inline std::ostream& operator<<(std::ostream& os, CpuFamily f) {
  switch (f) {
    case CpuFamily::AMD:
      return os << "AMD";
    case CpuFamily::INTEL:
      return os << "INTEL";
    case CpuFamily::ARM:
      return os << "ARM";
    case CpuFamily::UNKNOWN:
      return os << "UNKNOWN";
  }
}

// Create CpuFamily enumeration from integer.
inline CpuFamily makeCpuFamily(uint32_t cpu_family) {
#if defined(__x86_64__)
  switch (cpu_family) {
    case 6:
      return CpuFamily::INTEL;
    case 25:
      return CpuFamily::AMD;
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

} // namespace facebook::hbt::perf_event

#include "hbt/src/perf_event/json_events/generated/CpuArch.h"
