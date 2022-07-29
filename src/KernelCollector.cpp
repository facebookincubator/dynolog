// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "KernelCollector.h"

#include <fmt/format.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/prctl.h>

namespace dynolog {

inline int64_t ticksToMs(int64_t ticks) {
  return ticks * 10;
}
KernelCollector::KernelCollector() : KernelCollectorBase() {}

void KernelCollector::step() {
  uptime_ = readUptime();
  readCpuStats();
}

void KernelCollector::log(Logger& log) {
  log.log("uptime", uptime_);

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
  log.log("cpu_util", 100 * (1 - cpuDelta_.i / total_ticks));

  log.log("cpu_u_ms", ticksToMs(cpuDelta_.u));
  log.log("cpu_s_ms", ticksToMs(cpuDelta_.s));
  log.log("cpu_w_ms", ticksToMs(cpuDelta_.w));
  log.log("cpu_n_ms", ticksToMs(cpuDelta_.n));
  log.log("cpu_x_ms", ticksToMs(cpuDelta_.x));
  log.log("cpu_y_ms", ticksToMs(cpuDelta_.y));
  log.log("cpu_z_ms", ticksToMs(cpuDelta_.z));

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

  log.setTimestamp();
}

} // namespace dynolog
