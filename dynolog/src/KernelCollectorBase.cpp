// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/KernelCollectorBase.h"
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <sstream>
#include <string>
#include <vector>

DEFINE_bool(
    filter_nic_interfaces,
    false,
    "Filter NIC interfaces based on list specified with '-allow_interface_prefixes'");
DEFINE_string(
    allow_interface_prefixes,
    "eno,ens,enp,enx,eth",
    "Comma-separated list of NIC interface prefixes allowed for monitoring");

namespace dynolog {

// This class provides a minimal version of Kernel based metric collection.
// All logic written here :
//   1. Can assume compatible Linux operating system.
//   2. Must not use Meta specific infrastructure.
//   3. Try to leverage std:: instead of folly:: library.

KernelCollectorBase::KernelCollectorBase(const std::string& rootDir)
    : uptime_(readUptime()),
      rootDir_(rootDir),
      pfs_(rootDir_ + "/proc"),
      numCpuSockets_(1), // TODO discover sockets from /proc/cpuinfo
      cpuCoresTotal_(pfs_.get_stat().cpus.per_item.size()),
      filterInteraces_(FLAGS_filter_nic_interfaces) {
  perCoreCpuTime_.resize(cpuCoresTotal_);

  std::istringstream iss(FLAGS_allow_interface_prefixes);
  std::string prefix;
  while (std::getline(iss, prefix, ',')) {
    nicInterfacePrefixes_.push_back(prefix);
  }
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

void KernelCollectorBase::readNetworkStats() {
  auto devices = pfs_.get_net().get_dev();

  std::map<std::string, struct RxTx> rxtxNew_;

  size_t nicDevCount = 0;
  for (const auto& device : devices) {
    if (!isMonitoringInterfaceActive(device.interface)) {
      continue;
    }

    nicDevCount++;

    auto& devRxtx = rxtxNew_[device.interface];

    devRxtx.rxBytes = device.rx_bytes;
    devRxtx.rxPackets = device.rx_packets;
    devRxtx.rxErrors = device.rx_errs;
    devRxtx.rxDrops = device.rx_drop;
    devRxtx.txBytes = device.tx_bytes;
    devRxtx.txPackets = device.tx_packets;
    devRxtx.txErrors = device.tx_errs;
    devRxtx.txDrops = device.tx_drop;
  }

  updateNetworkStatsDelta(rxtxNew_);

  if (nicDevCount == 0) {
    LOG_EVERY_N(WARNING, 10) << "No NIC devices being monitored.";
  } else if (!first_ && nicDevCount != nicDevCount_) {
    LOG(WARNING) << "Number of NIC devices changed, previously " << nicDevCount_
                 << " and now " << nicDevCount;
  }
  nicDevCount_ = nicDevCount;
}

bool KernelCollectorBase::isMonitoringInterfaceActive(std::string interface) {
  if (interface.length() >= IFNAMSIZ) {
    LOG(ERROR) << "invalid device name found: " << interface;
    // Device name is too long to be valid, so consider the line malformed and
    // not monitor interface
    return false;
  }

  if (!filterInteraces_) {
    // Device name is valid and no prefix filtering, so always return true
    return true;
  }

  for (const auto& prefix : nicInterfacePrefixes_) {
    if (interface.find(prefix) == 0) {
      // Device name is valid length and matches a prefix
      return true;
    }
  }

  // Device name is valid but does not match any prefixes
  return false;
}

void KernelCollectorBase::updateNetworkStatsDelta(
    const std::map<std::string, struct RxTx>& rxtxNew) {
  rxtxDelta_.clear();
  for (const auto& [devName, devRxtxNew] : rxtxNew) {
    if (rxtx_.find(devName) == rxtx_.end()) {
      // New device not in last sample, so rxtxDelta_ will be zeros.
      rxtxDelta_[devName] = RxTx{};
    } else {
      rxtxDelta_[devName] = devRxtxNew - rxtx_[devName];
    }
  }
  rxtx_ = rxtxNew;
}

} // namespace dynolog
