// Copyright (c) Meta Platforms, Inc. and affiliates.

// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <unistd.h>
#include <filesystem>
#include <memory>
#include <string>
#include "dynolog/src/rdmamon/SysfsCounter.h"

namespace dynolog {
namespace rdmamon {

class RdmaCounters {
 public:
  explicit RdmaCounters(const std::string& if_name) : ifname_(if_name) {
    std::string path = "/sys/class/net/";
    std::string netdev_path = path + if_name;
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
      if (0 == netdev_path.compare(entry.path())) {
        std::string ibdev_path = netdev_path + "/device/infiniband";
        for (const auto& deventry :
             std::filesystem::directory_iterator(ibdev_path)) {
          std::string ib_devname = deventry.path().stem();
          std::string ib_dev_path = "/sys/class/infiniband/";
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

  bool setupRdmaCounters();
  bool sampleRdmaCounters(std::map<std::string, int64_t>& rdmaCountersMap);

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

  bool init_rdma_counters_(
      const std::string& path,
      const std::vector<std::string>& counters) {
    for (auto counter : counters) {
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

} // namespace rdmamon
} // namespace dynolog
