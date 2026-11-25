/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <glog/logging.h>
#include <stdint.h>
#include <unistd.h>
#include <filesystem>
#include <map>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
#include "dynolog/src/rdmamon/SysfsCounter.h"

namespace dynolog::rdmamon {

class RdmaCounters {
 public:
  // net_path and ib_path are the sysfs net and infiniband class directories,
  // with a trailing '/'; tests point them at a fake tree.
  explicit RdmaCounters(
      const std::string& if_name,
      const std::string& net_path = "/sys/class/net/",
      const std::string& ib_path = "/sys/class/infiniband/")
      : ifname_(if_name) {
    std::string netdev_path = net_path + if_name;
    for (const auto& entry : std::filesystem::directory_iterator(net_path)) {
      if (0 == netdev_path.compare(entry.path())) {
        std::string ibdev_path = netdev_path + "/device/infiniband";
        for (const auto& deventry :
             std::filesystem::directory_iterator(ibdev_path)) {
          std::string ib_devname = deventry.path().stem();
          std::string ib_dev_path = ib_path;
          ib_dev_path += ib_devname;
          if (rdma_port_counter_path_.empty()) {
            rdma_port_counter_path_ = ib_dev_path + "/ports/1/counters/";
          }
          if (rdma_hw_counter_path_.empty()) {
            rdma_hw_counter_path_ = ib_dev_path + "/ports/1/hw_counters/";
          }
        }
      }
    }
  }

  virtual ~RdmaCounters() {
    rdma_counters_.clear();
  }

  RdmaCounters(const RdmaCounters&) = delete;
  RdmaCounters& operator=(const RdmaCounters&) = delete;
  RdmaCounters(RdmaCounters&&) = default;
  RdmaCounters& operator=(RdmaCounters&&) = default;

  bool setupRdmaCounters();
  bool sampleRdmaCounters(std::map<std::string, int64_t>& rdmaCountersMap);

  // The RDMA port counter directory this netdev resolved to at construction
  // ("" if it has no RDMA device).
  const std::string& getRdmaPortCounterPath() const {
    return rdma_port_counter_path_;
  }

  // True once a counter read has failed, e.g. because the RDMA device was
  // re-probed and the sysfs file this object opened is gone.
  bool hasReadFailure() const {
    return read_failure_;
  }

  // True if the last setupRdmaCounters() could not open every counter, e.g.
  // because the RDMA device's sysfs files did not exist yet.
  bool hasSetupFailure() const {
    return setup_failure_;
  }

 private:
  struct rdma_counter {
    std::unique_ptr<SysfsCounter> sysfs_counter;
    uint64_t prev;
    uint64_t cur;

    explicit rdma_counter(std::unique_ptr<SysfsCounter> sysfs_counter) {
      this->sysfs_counter = std::move(sysfs_counter);
      this->prev = 0;
      this->cur = 0;
    }
  };
  std::vector<std::unique_ptr<rdma_counter>> rdma_counters_;
  std::string ifname_;
  std::string rdma_port_counter_path_;
  std::string rdma_hw_counter_path_;
  bool first_sample_ = true;
  bool read_failure_ = false;
  bool setup_failure_ = false;

  bool init_rdma_counters_(
      const std::string& path,
      const std::vector<std::string>& counters) {
    for (const auto& counter : counters) {
      std::string path_to_name = path + counter;
      auto sysfs_counter =
          std::make_unique<SysfsCounter>(counter, path_to_name);
      if (!sysfs_counter->openSysfsCounter()) {
        LOG(WARNING) << "Unable to initialize rdma counter " << path_to_name;
        return false;
      }
      auto rdma_counter_obj =
          std::make_unique<rdma_counter>(std::move(sysfs_counter));
      rdma_counters_.push_back(std::move(rdma_counter_obj));
    }
    return true;
  }
};

} // namespace dynolog::rdmamon
