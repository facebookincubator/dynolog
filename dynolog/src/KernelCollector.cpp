// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/KernelCollector.h"
#include <fmt/format.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/prctl.h>
#include <iostream>

namespace dynolog {

inline int64_t ticksToMs(int64_t ticks) {
  return ticks * 10;
}
KernelCollector::KernelCollector() : KernelCollectorBase() {}

void KernelCollector::step() {
  uptime_ = readUptime();
  readCpuStats();
  readNetworkStats();
}

void KernelCollector::log(Logger& log) {
  log.logInt("uptime", uptime_);

  // Avoid logging first sample of metrics requiring delta computation
  if (first_) {
    first_ = false;
    return;
  }

  float total_ticks = cpuDelta_.total();
  auto cpuMs = ticksToMs(cpuDelta_.total());

  // Relative utilization in percentage
  log.logFloat("cpu_u", cpuDelta_.u / total_ticks * 100.0);
  log.logFloat("cpu_i", cpuDelta_.i / total_ticks * 100.0);
  log.logFloat("cpu_s", cpuDelta_.s / total_ticks * 100.0);

  // CPU utilization is 1 - idle/total
  log.logFloat("cpu_util", 100 * (1 - cpuDelta_.i / total_ticks));

  log.logInt("cpu_u_ms", ticksToMs(cpuDelta_.u));
  log.logInt("cpu_s_ms", ticksToMs(cpuDelta_.s));
  log.logInt("cpu_w_ms", ticksToMs(cpuDelta_.w));
  log.logInt("cpu_n_ms", ticksToMs(cpuDelta_.n));
  log.logInt("cpu_x_ms", ticksToMs(cpuDelta_.x));
  log.logInt("cpu_y_ms", ticksToMs(cpuDelta_.y));
  log.logInt("cpu_z_ms", ticksToMs(cpuDelta_.z));

  if (numCpuSockets_ > 1) {
    for (int i = 0; i < numCpuSockets_; i++) {
      auto node_ticks = nodeCpuTime_[i].total();
      log.logFloat(
          fmt::format("cpu_u_node{}", i),
          nodeCpuTime_[i].u / node_ticks * 100.0);
      log.logFloat(
          fmt::format("cpu_s_node{}", i),
          nodeCpuTime_[i].s / node_ticks * 100.0);
      log.logFloat(
          fmt::format("cpu_i_node{}", i),
          nodeCpuTime_[i].i / node_ticks * 100.0);
    }
  }

  for (const auto& [devName, devRxtx] : rxtxDelta_) {
    log.logUint(fmt::format("rx_bytes_{}", devName), devRxtx.rxBytes);
    log.logUint(fmt::format("rx_packets_{}", devName), devRxtx.rxPackets);
    log.logUint(fmt::format("rx_errors_{}", devName), devRxtx.rxErrors);
    log.logUint(fmt::format("rx_drops_{}", devName), devRxtx.rxDrops);
    log.logUint(fmt::format("tx_bytes_{}", devName), devRxtx.txBytes);
    log.logUint(fmt::format("tx_packets_{}", devName), devRxtx.txPackets);
    log.logUint(fmt::format("tx_errors_{}", devName), devRxtx.txErrors);
    log.logUint(fmt::format("tx_drops_{}", devName), devRxtx.txDrops);
  }

  log.setTimestamp();
}

} // namespace dynolog
