// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <time.h>
#include <array>
#include <vector>

#include <pfs/procfs.hpp>

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "Types.h"

namespace dynolog {

/* KernelCollectorBase: Provides capabilities to measure system metrics using
 *  Linux kernel provided interfaces.
 */
class KernelCollectorBase {
 public:
  explicit KernelCollectorBase(const std::string& root = "/proc");

  time_t readUptime();

  void readCpuStats();

 protected:
  time_t uptime_;
  // proc fs parser
  pfs::procfs pfs_;
  int numCpuSockets_{1};
  int cpuCoresTotal_;

  // Save most recent CPU stats and delta from most recent
  struct CpuTime cpuTime_, cpuDelta_;
  std::array<CpuTime, MAX_CPU_SOCKETS> nodeCpuTime_;
  std::vector<CpuTime> perCoreCpuTime_;
};

} // namespace dynolog
