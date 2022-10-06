// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <time.h>
#include <array>
#include <map>
#include <vector>
#include "dynolog/src/Types.h"
#include "pfs/procfs.hpp"

namespace dynolog {

/* KernelCollectorBase: Provides capabilities to measure system metrics using
 *  Linux kernel provided interfaces.
 */
class KernelCollectorBase {
 public:
  explicit KernelCollectorBase(const std::string& rootDir = "");

  time_t readUptime();

  void readCpuStats();
  void readNetworkStats();

 protected:
  time_t uptime_;
  bool first_ = true;

  // Root directory containing procfs for manual parsing
  std::string rootDir_;
  // proc fs parser
  pfs::procfs pfs_;

  size_t numCpuSockets_;
  const size_t cpuCoresTotal_;
  size_t nicDevCount_;
  bool filterInteraces_;
  std::vector<std::string> nicInterfacePrefixes_;

  // Save most recent CPU stats and delta from most recent
  struct CpuTime cpuTime_, cpuDelta_;
  std::array<CpuTime, MAX_CPU_SOCKETS> nodeCpuTime_;
  std::vector<CpuTime> perCoreCpuTime_;

  // Save more recent net device stats
  std::map<std::string, struct RxTx> rxtx_, rxtxDelta_;

  void updateNetworkStatsDelta(
      const std::map<std::string, struct RxTx>& rxtxNew);
  bool isMonitoringInterfaceActive(std::string interface);

  // Should match googletest/include/gtest/gtest_prod.h
  // friend class test_case_name##_##test_name##_Test
  friend class KernelCollecterTest_CpuStatsTest_Test;
  friend class KernelCollecterTest_NetworkStatsTest_Test;
  friend class KernelCollecterTest_UpdateNetworkStatsDeltaTest_Test;
  friend class KernelCollecterTest_MonitorInterfaceTest_Test;
};

} // namespace dynolog
