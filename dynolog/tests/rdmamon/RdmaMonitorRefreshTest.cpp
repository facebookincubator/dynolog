/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <gtest/gtest.h>
#include <stdint.h>
#include <stdlib.h>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include "dynolog/src/rdmamon/RdmaMonitor.h"

using namespace dynolog::rdmamon;
namespace fs = std::filesystem;

namespace {

const std::vector<std::string> kPortCounters = {
    "port_xmit_data",
    "port_xmit_packets",
    "port_xmit_discards",
    "port_rcv_data",
    "port_rcv_packets",
    "port_rcv_errors",
};
const std::vector<std::string> kHwCounters = {
    "np_cnp_sent",
    "rp_cnp_handled",
    "np_ecn_marked_roce_packets",
    "rx_atomic_requests",
    "rx_read_requests",
    "rx_write_requests",
};

// A fake /sys/class/net and /sys/class/infiniband. NIC names are made up so
// that the ethtool ioctls RdmaPortMonitor also issues match no real NIC.
class FakeSysfs {
 public:
  FakeSysfs() {
    std::string tmpl = (fs::temp_directory_path() / "rdmamonXXXXXX").string();
    root_ = mkdtemp(tmpl.data());
    fs::create_directories(netPath());
    fs::create_directories(ibPath());
    fs::create_directories(netPath() + "lo");
  }
  ~FakeSysfs() {
    std::error_code ec;
    fs::remove_all(root_, ec);
  }

  std::string netPath() const {
    return root_ + "/net/";
  }
  std::string ibPath() const {
    return root_ + "/infiniband/";
  }

  void addIbDevice(const std::string& ibdev) {
    for (const auto& [dir, counters] :
         {std::pair{"counters", kPortCounters},
          std::pair{"hw_counters", kHwCounters}}) {
      fs::create_directories(ibPath() + ibdev + "/ports/1/" + dir);
      for (const auto& counter : counters) {
        setCounter(ibdev, dir, counter, "0");
      }
    }
  }
  void setCounter(
      const std::string& ibdev,
      const std::string& dir,
      const std::string& counter,
      const std::string& value) {
    // Truncates and rewrites the same inode, which the monitor keeps open.
    std::ofstream(ibPath() + ibdev + "/ports/1/" + dir + "/" + counter)
        << value << "\n";
  }
  void truncateCounter(const std::string& ibdev, const std::string& counter) {
    fs::resize_file(ibPath() + ibdev + "/ports/1/counters/" + counter, 0);
  }

  void addNic(const std::string& ifname, const std::string& ibdev) {
    fs::create_directories(netPath() + ifname + "/device/infiniband/" + ibdev);
  }
  void addNicWithoutRdma(const std::string& ifname) {
    fs::create_directories(netPath() + ifname);
  }
  void renameNic(const std::string& from, const std::string& to) {
    fs::rename(netPath() + from, netPath() + to);
  }
  void moveNicToIbDevice(const std::string& ifname, const std::string& ibdev) {
    fs::remove_all(netPath() + ifname + "/device/infiniband");
    fs::create_directories(netPath() + ifname + "/device/infiniband/" + ibdev);
  }

 private:
  std::string root_;
};

std::vector<std::string> sorted(std::vector<std::string> v) {
  std::sort(v.begin(), v.end());
  return v;
}

bool hasKeysOf(
    const std::map<std::string, int64_t>& counters,
    const std::string& ifname) {
  return std::any_of(counters.begin(), counters.end(), [&](const auto& kv) {
    return kv.first.starts_with(ifname + ".");
  });
}

std::map<std::string, int64_t> sample(RdmaMonitor& monitor) {
  std::map<std::string, int64_t> counters;
  // The ethtool part fails on the fake NICs; only the RDMA keys matter here.
  (void)monitor.sampleRdmaMonitor(counters);
  return counters;
}

} // namespace

// udev renames a backend NIC after the monitor was created: the monitor must
// follow the new name and stop reporting the old one.
TEST(RdmaMonitorRefreshTest, FollowsRenamedNic) {
  FakeSysfs sysfs;
  sysfs.addIbDevice("mlx5_4");
  sysfs.addIbDevice("mlx5_5");
  sysfs.addNic("fketh4", "mlx5_4");
  sysfs.addNic("fketh5", "mlx5_5");

  RdmaMonitor monitor(sysfs.netPath(), sysfs.ibPath());
  (void)monitor.setupRdmaMonitor();
  EXPECT_EQ(
      sorted(monitor.getRdmaIfnames()),
      (std::vector<std::string>{"fketh4", "fketh5"}));
  sample(monitor); // baseline
  sysfs.setCounter("mlx5_4", "counters", "port_xmit_data", "100");
  auto counters = sample(monitor);
  EXPECT_EQ(counters.at("fketh4.port_xmit_data"), 100);
  EXPECT_EQ(counters.at("fketh5.port_xmit_data"), 0);

  // Nothing changed yet.
  EXPECT_FALSE(monitor.refreshRdmaMonitor());

  sysfs.renameNic("fketh4", "fkbeth10");
  sysfs.addNicWithoutRdma("fkveth0");
  EXPECT_TRUE(monitor.refreshRdmaMonitor());
  EXPECT_EQ(
      sorted(monitor.getRdmaIfnames()),
      (std::vector<std::string>{"fkbeth10", "fketh5"}));

  // The kept monitor keeps its baseline; the new one starts a new baseline.
  sysfs.setCounter("mlx5_5", "counters", "port_rcv_data", "7");
  counters = sample(monitor);
  EXPECT_FALSE(hasKeysOf(counters, "fketh4"));
  EXPECT_FALSE(hasKeysOf(counters, "fkbeth10"));
  EXPECT_EQ(counters.at("fketh5.port_rcv_data"), 7);

  sysfs.setCounter("mlx5_4", "counters", "port_xmit_data", "350");
  counters = sample(monitor);
  EXPECT_FALSE(hasKeysOf(counters, "fketh4"));
  EXPECT_EQ(counters.at("fkbeth10.port_xmit_data"), 250);
  EXPECT_EQ(counters.size(), 2 * (kPortCounters.size() + kHwCounters.size()));

  EXPECT_FALSE(monitor.refreshRdmaMonitor());
}

// udev can also hand an old name to a different device: a monitor whose name
// now resolves to another RDMA device is set up again.
TEST(RdmaMonitorRefreshTest, RebuildsNicMovedToOtherRdmaDevice) {
  FakeSysfs sysfs;
  sysfs.addIbDevice("mlx5_0");
  sysfs.addIbDevice("mlx5_9");
  sysfs.addNic("fketh0", "mlx5_0");

  RdmaMonitor monitor(sysfs.netPath(), sysfs.ibPath());
  (void)monitor.setupRdmaMonitor();
  sample(monitor);

  sysfs.moveNicToIbDevice("fketh0", "mlx5_9");
  EXPECT_TRUE(monitor.refreshRdmaMonitor());
  sample(monitor); // new baseline
  sysfs.setCounter("mlx5_9", "counters", "port_xmit_data", "40");
  sysfs.setCounter("mlx5_0", "counters", "port_xmit_data", "1000");
  EXPECT_EQ(sample(monitor).at("fketh0.port_xmit_data"), 40);
}

// A monitor whose counter reads fail (e.g. the RDMA device was re-probed under
// the same name) is set up again on the next refresh.
TEST(RdmaMonitorRefreshTest, RebuildsNicWithFailedReads) {
  FakeSysfs sysfs;
  sysfs.addIbDevice("mlx5_1");
  sysfs.addNic("fketh1", "mlx5_1");

  RdmaMonitor monitor(sysfs.netPath(), sysfs.ibPath());
  (void)monitor.setupRdmaMonitor();
  sample(monitor);
  EXPECT_FALSE(monitor.refreshRdmaMonitor());

  sysfs.truncateCounter("mlx5_1", "port_xmit_data");
  sample(monitor);
  sysfs.setCounter("mlx5_1", "counters", "port_xmit_data", "5");
  EXPECT_TRUE(monitor.refreshRdmaMonitor());
  EXPECT_EQ(monitor.getRdmaIfnames(), (std::vector<std::string>{"fketh1"}));
  EXPECT_FALSE(monitor.refreshRdmaMonitor());
}

// A NIC set up before its RDMA device's sysfs counters exist (e.g. right after
// a udev rename) is set up again on later refreshes until it has counters.
TEST(RdmaMonitorRefreshTest, RebuildsNicWhoseSetupFailed) {
  FakeSysfs sysfs;
  sysfs.addIbDevice("mlx5_6");
  sysfs.addNic("fketh6", "mlx5_6");
  RdmaMonitor monitor(sysfs.netPath(), sysfs.ibPath());
  (void)monitor.setupRdmaMonitor();
  sample(monitor);

  sysfs.addNic("fkbeth17", "mlx5_7"); // mlx5_7 has no counters yet
  EXPECT_TRUE(monitor.refreshRdmaMonitor());
  EXPECT_EQ(
      sorted(monitor.getRdmaIfnames()),
      (std::vector<std::string>{"fkbeth17", "fketh6"}));
  EXPECT_FALSE(hasKeysOf(sample(monitor), "fkbeth17"));
  // Still no counters: the next refresh tries again.
  EXPECT_TRUE(monitor.refreshRdmaMonitor());
  EXPECT_FALSE(hasKeysOf(sample(monitor), "fkbeth17"));

  sysfs.addIbDevice("mlx5_7");
  EXPECT_TRUE(monitor.refreshRdmaMonitor());
  sample(monitor); // baseline
  sysfs.setCounter("mlx5_7", "counters", "port_xmit_data", "30");
  sysfs.setCounter("mlx5_6", "counters", "port_rcv_data", "9");
  auto counters = sample(monitor);
  EXPECT_EQ(counters.at("fkbeth17.port_xmit_data"), 30);
  EXPECT_EQ(counters.at("fketh6.port_rcv_data"), 9);
  EXPECT_FALSE(monitor.refreshRdmaMonitor());
}

// The same holds for a NIC whose setup failed when dynologd started.
TEST(RdmaMonitorRefreshTest, RebuildsNicWhoseStartupSetupFailed) {
  FakeSysfs sysfs;
  sysfs.addNic("fketh8", "mlx5_8"); // mlx5_8 has no counters yet
  RdmaMonitor monitor(sysfs.netPath(), sysfs.ibPath());
  (void)monitor.setupRdmaMonitor();
  EXPECT_FALSE(hasKeysOf(sample(monitor), "fketh8"));

  sysfs.addIbDevice("mlx5_8");
  EXPECT_TRUE(monitor.refreshRdmaMonitor());
  EXPECT_EQ(monitor.getRdmaIfnames(), (std::vector<std::string>{"fketh8"}));
  sample(monitor); // baseline
  sysfs.setCounter("mlx5_8", "hw_counters", "np_cnp_sent", "12");
  EXPECT_EQ(sample(monitor).at("fketh8.np_cnp_sent"), 12);
  EXPECT_FALSE(monitor.refreshRdmaMonitor());
}

// A refresh never throws, even when the net directory is gone.
TEST(RdmaMonitorRefreshTest, RefreshSurvivesMissingNetDirectory) {
  auto sysfs = std::make_unique<FakeSysfs>();
  sysfs->addIbDevice("mlx5_2");
  sysfs->addNic("fketh2", "mlx5_2");
  RdmaMonitor monitor(sysfs->netPath(), sysfs->ibPath());
  (void)monitor.setupRdmaMonitor();
  sysfs.reset();
  EXPECT_FALSE(monitor.refreshRdmaMonitor());
  EXPECT_EQ(monitor.getRdmaIfnames(), (std::vector<std::string>{"fketh2"}));
}
