/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/rdmamon/RdmaMonitor.h"

#include <exception>
#include <filesystem>
#include <ostream>
#include <set>
#include <system_error>
#include <utility>

#include <glog/logging.h>

#include "dynolog/src/rdmamon/EthtoolCounters.h"
#include "dynolog/src/rdmamon/RdmaCounters.h"

namespace dynolog::rdmamon {

bool RdmaPortMonitor::setupRdmaPortMonitor() {
  bool r1 = eth_counters_->setupEthtoolCounters();
  bool r2 = rdma_counters_->setupRdmaCounters();
  return (r1 && r2);
}

bool RdmaPortMonitor::sampleRdmaPortMonitor(
    std::map<std::string, int64_t>& rdmaPortCounterMap) {
  bool r1 = eth_counters_->sampleEthtoolCounters(rdmaPortCounterMap);
  bool r2 = rdma_counters_->sampleRdmaCounters(rdmaPortCounterMap);
  return (r1 && r2);
}

bool RdmaMonitor::setupRdmaMonitor() {
  bool ret = true;
  for (auto const& monitor : monitors_) {
    if (!monitor->setupRdmaPortMonitor()) {
      LOG(ERROR) << "Unable to setup RDMA monitor for "
                 << monitor->getRdmaIfname();
      ret = false;
    }
  }
  return ret;
}

std::vector<std::string> RdmaMonitor::listNetdevs() const {
  std::vector<std::string> ifnames;
  for (const auto& entry : std::filesystem::directory_iterator(net_path_)) {
    std::string ifname = entry.path().stem();
    if (0 == ifname.compare("lo")) {
      continue;
    }
    ifnames.push_back(std::move(ifname));
  }
  return ifnames;
}

bool RdmaMonitor::refreshRdmaMonitor() {
  last_refresh_ = std::chrono::steady_clock::now();
  std::vector<std::string> ifnames;
  try {
    ifnames = listNetdevs();
  } catch (const std::exception& ex) {
    LOG(WARNING) << "Unable to list " << net_path_ << ": " << ex.what();
    return false;
  }

  std::map<std::string, std::unique_ptr<RdmaPortMonitor>> old;
  for (auto& monitor : monitors_) {
    // try_emplace leaves a duplicate name's monitor in place, to be dropped.
    old.try_emplace(monitor->getRdmaIfname(), std::move(monitor));
  }
  bool changed = old.size() != monitors_.size();

  std::vector<std::unique_ptr<RdmaPortMonitor>> monitors;
  std::set<std::string> seen;
  for (const auto& ifname : ifnames) {
    if (!seen.insert(ifname).second) {
      continue;
    }
    // Netdevs without an RDMA device (veth, bond, ...) are not monitored.
    std::error_code ec;
    if (!std::filesystem::exists(
            net_path_ + ifname + "/device/infiniband", ec)) {
      continue;
    }
    std::unique_ptr<RdmaPortMonitor> monitor;
    try {
      monitor = std::make_unique<RdmaPortMonitor>(ifname, net_path_, ib_path_);
    } catch (const std::exception& ex) {
      // E.g. the netdev went away during the listing; retried next refresh.
      LOG(WARNING) << "Unable to create RDMA monitor for " << ifname << ": "
                   << ex.what();
      continue;
    }
    auto it = old.find(ifname);
    if (it != old.end() && !it->second->needsRebuild() &&
        it->second->getRdmaPortCounterPath() ==
            monitor->getRdmaPortCounterPath()) {
      monitors.push_back(std::move(it->second));
      old.erase(it);
      continue;
    }
    if (it != old.end()) {
      LOG(INFO) << "Setting up RDMA monitor for " << ifname
                << " again (RDMA device changed, not set up or unreadable)";
      old.erase(it);
    } else {
      LOG(INFO) << "Setting up RDMA monitor for " << ifname;
    }
    if (!monitor->setupRdmaPortMonitor()) {
      // Kept: needsRebuild() makes the next refresh set it up again, e.g.
      // once the RDMA device's sysfs files exist after a udev rename.
      LOG(ERROR) << "Unable to setup RDMA monitor for " << ifname;
    }
    monitors.push_back(std::move(monitor));
    changed = true;
  }
  for (const auto& [ifname, monitor] : old) {
    LOG(INFO) << "Dropping RDMA monitor for " << ifname;
    changed = true;
  }
  monitors_ = std::move(monitors);
  return changed;
}

std::vector<std::string> RdmaMonitor::getRdmaIfnames() const {
  std::vector<std::string> ifnames;
  ifnames.reserve(monitors_.size());
  for (const auto& monitor : monitors_) {
    ifnames.push_back(monitor->getRdmaIfname());
  }
  return ifnames;
}

bool RdmaMonitor::sampleRdmaMonitor(
    std::map<std::string, int64_t>& rdmaCounterMap) {
  if (std::chrono::steady_clock::now() - last_refresh_ >= kRefreshInterval) {
    refreshRdmaMonitor();
  }
  bool ret = true;
  for (auto const& monitor : monitors_) {
    if (!monitor->sampleRdmaPortMonitor(rdmaCounterMap)) {
      LOG(ERROR) << "Unable to sample RDMA monitor for "
                 << monitor->getRdmaIfname();
      ret = false;
    }
  }
  return ret;
}

} // namespace dynolog::rdmamon
