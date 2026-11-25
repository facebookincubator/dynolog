/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <stdint.h>
#include <chrono>
#include <filesystem>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "dynolog/src/rdmamon/EthtoolCounters.h"
#include "dynolog/src/rdmamon/RdmaCounters.h"

namespace dynolog::rdmamon {

class RdmaPortMonitor {
 public:
  explicit RdmaPortMonitor(
      const std::string& ifname,
      const std::string& net_path = "/sys/class/net/",
      const std::string& ib_path = "/sys/class/infiniband/")
      : ifname_(ifname) {
    eth_counters_ = std::make_unique<EthtoolCounters>(ifname);
    rdma_counters_ = std::make_unique<RdmaCounters>(ifname, net_path, ib_path);
  }

  [[nodiscard]] bool setupRdmaPortMonitor();
  [[nodiscard]] bool sampleRdmaPortMonitor(
      std::map<std::string, int64_t>& rdmaPortCounterMap);

  std::string getRdmaIfname() const {
    return ifname_;
  }

  const std::string& getRdmaPortCounterPath() const {
    return rdma_counters_->getRdmaPortCounterPath();
  }

  // True if the RDMA counters could not be set up or a read of them failed,
  // so RdmaMonitor::refreshRdmaMonitor() sets this monitor up again. The
  // ethtool counters are not counted: they set themselves up again on their
  // own.
  bool needsRebuild() const {
    return rdma_counters_->hasSetupFailure() ||
        rdma_counters_->hasReadFailure();
  }

 private:
  std::string ifname_;
  std::unique_ptr<EthtoolCounters> eth_counters_;
  std::unique_ptr<RdmaCounters> rdma_counters_;
};

class RdmaMonitor {
 public:
  // How often sampleRdmaMonitor() re-lists the netdevs.
  static constexpr std::chrono::seconds kRefreshInterval{60};

  // Throws std::filesystem::filesystem_error if a netdev has no RDMA device.
  explicit RdmaMonitor(
      std::string net_path = "/sys/class/net/",
      std::string ib_path = "/sys/class/infiniband/")
      : net_path_(std::move(net_path)),
        ib_path_(std::move(ib_path)),
        last_refresh_(std::chrono::steady_clock::now()) {
    for (const auto& ifname : listNetdevs()) {
      auto monitor =
          std::make_unique<RdmaPortMonitor>(ifname, net_path_, ib_path_);
      monitors_.push_back(std::move(monitor));
    }
  }

  virtual ~RdmaMonitor() {
    monitors_.clear();
  }

  RdmaMonitor(const RdmaMonitor&) = delete;
  RdmaMonitor& operator=(const RdmaMonitor&) = delete;
  RdmaMonitor(RdmaMonitor&&) = default;
  RdmaMonitor& operator=(RdmaMonitor&&) = default;

  [[nodiscard]] bool setupRdmaMonitor();
  // Re-lists the netdevs first when kRefreshInterval has passed since the
  // last listing.
  [[nodiscard]] bool sampleRdmaMonitor(
      std::map<std::string, int64_t>& rdmaCounterMap);

  // Re-lists the netdevs, since udev can rename them after the monitor was
  // created (e.g. ethN/tmpN to bethN at boot). Keeps the monitor of a netdev
  // whose name and RDMA device are unchanged and whose setup and reads still
  // work, sets up a new monitor for a new netdev with an RDMA device, or one
  // whose RDMA device changed, failed to set up or stopped reading, and drops
  // the monitors of netdevs that are gone. A monitor whose setup fails is kept
  // and set up again on the next refresh. Never throws. Returns true if the
  // monitored set changed.
  bool refreshRdmaMonitor();

  // The netdevs whose counters sampleRdmaMonitor() reports.
  std::vector<std::string> getRdmaIfnames() const;

 private:
  std::vector<std::string> listNetdevs() const;

  std::string net_path_;
  std::string ib_path_;
  std::chrono::steady_clock::time_point last_refresh_;
  std::vector<std::unique_ptr<RdmaPortMonitor>> monitors_;
};

} // namespace dynolog::rdmamon
