// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include <glog/logging.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "KernelCollectorBase.h"

#include <pfs/procfs.hpp>
#include <chrono>

namespace dynolog {

// This class provides a minimal version of Kernel based metric collection.
// All logic written here :
//   1. Can assume compatible Linux operating system.
//   2. Must not use Meta specific infrastructure.
//   3. Try to leverage std:: instead of folly:: library.

KernelCollectorBase::KernelCollectorBase(const std::string& root)
    : uptime_(readUptime()),
      pfs_(root),
      numCpuSockets_(1), // TODO discover sockets from /proc/cpuinfo
      cpuCoresTotal_(pfs_.get_stat().cpus.per_item.size()) {
  perCoreCpuTime_.resize(cpuCoresTotal_);
}

time_t KernelCollectorBase::readUptime() {
  time_t t = 0;
  pfs::procfs pfs;

  t = std::chrono::duration_cast<typename std::chrono::seconds>(
          pfs.get_uptime().system_time)
          .count();

  return t;
}

void KernelCollectorBase::readCpuStats() {
  auto stats = pfs_.get_stat();
  if (stats.cpus.per_item.size() != cpuCoresTotal_) {
    LOG_EVERY_N(WARNING, 100)
        << "Number of cores changed, previously " << cpuCoresTotal_
        << " and now " << stats.cpus.per_item.size();
  }

  CpuTime newCpuTime{
      .u = stats.cpus.total.user,
      .n = stats.cpus.total.nice,
      .s = stats.cpus.total.system,
      .i = stats.cpus.total.idle,
      .w = stats.cpus.total.iowait,
      .x = stats.cpus.total.irq,
      .y = stats.cpus.total.softirq,
      .z = stats.cpus.total.guest,
  };

  // update delta
  cpuDelta_ = newCpuTime - cpuTime_;
  cpuTime_ = newCpuTime;

  // zero out per node calculation
  for (int node = 0; node < numCpuSockets_; node++) {
    nodeCpuTime_[node] = CpuTime{};
  }

  int core = 0;
  for (const auto& cpu : stats.cpus.per_item) {
    if (core >= cpuCoresTotal_) {
      break;
    }
    auto& coreCpu = perCoreCpuTime_[core];
    coreCpu.u = cpu.user;
    coreCpu.n = cpu.nice;
    coreCpu.s = cpu.system;
    coreCpu.i = cpu.idle;
    coreCpu.w = cpu.iowait;
    coreCpu.x = cpu.irq;
    coreCpu.y = cpu.softirq;
    coreCpu.z = cpu.guest;

    int node = core / (cpuCoresTotal_ / numCpuSockets_);
    nodeCpuTime_[node] += coreCpu;
    core++;
  }
}

} // namespace dynolog
