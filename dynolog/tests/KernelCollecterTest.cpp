// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <glog/logging.h>
#include <gtest/gtest.h>
#include <sys/stat.h>
#include "dynolog/src/KernelCollector.h"

namespace dynolog {

namespace {

constexpr char kTestRoot[] = "TESTROOT";

std::string get_test_root() {
  if (const char* env_p = std::getenv(kTestRoot)) {
    return env_p;
  }
  LOG(ERROR) << "Missing test root env: " << kTestRoot;
  return "";
}

int is_directory(const char* path) {
  struct stat statbuf;
  if (::stat(path, &statbuf) != 0) {
    return 0;
  }
  return S_ISDIR(statbuf.st_mode);
}

} // namespace

TEST(KernelCollecterTest, UptimeTest) {
  KernelCollectorBase kb;
  EXPECT_GT(kb.readUptime(), 0);
}

TEST(KernelCollecterTest, CpuStatsTest) {
  auto test_root = get_test_root();
  // ensure path
  ASSERT_NE(test_root, "");
  ASSERT_EQ(is_directory(test_root.c_str()), 1)
      << "Path for test root is invalid" << test_root;

  KernelCollectorBase kb{get_test_root()};
  kb.readCpuStats();

  EXPECT_EQ(kb.perCoreCpuTime_.size(), 32);
  EXPECT_EQ(kb.cpuCoresTotal_, 32);

  // cpu0 85923288 7559744 25071792 1175164067 39404260 4319 4746442 0 0 0
  EXPECT_EQ(kb.perCoreCpuTime_[0].u, 85923288);
  EXPECT_EQ(kb.perCoreCpuTime_[0].n, 7559744);
  EXPECT_EQ(kb.perCoreCpuTime_[0].s, 25071792);
  EXPECT_EQ(kb.perCoreCpuTime_[0].i, 1175164067);
  EXPECT_EQ(kb.perCoreCpuTime_[0].w, 39404260);
  EXPECT_EQ(kb.perCoreCpuTime_[0].x, 4319);
  EXPECT_EQ(kb.perCoreCpuTime_[0].y, 4746442);
  EXPECT_EQ(kb.perCoreCpuTime_[0].z, 0);
  // cpu31 6316214 2669639 4209634 1332212631 698635 0 25283 0 0 0
  EXPECT_EQ(kb.perCoreCpuTime_[31].u, 6316214);
  EXPECT_EQ(kb.perCoreCpuTime_[31].n, 2669639);
  EXPECT_EQ(kb.perCoreCpuTime_[31].s, 4209634);
  EXPECT_EQ(kb.perCoreCpuTime_[31].i, 1332212631);
  EXPECT_EQ(kb.perCoreCpuTime_[31].w, 698635);
  EXPECT_EQ(kb.perCoreCpuTime_[31].x, 0);
  EXPECT_EQ(kb.perCoreCpuTime_[31].y, 25283);
  EXPECT_EQ(kb.perCoreCpuTime_[31].z, 0);
}

TEST(KernelCollecterTest, NetworkStatsTest) {
  auto test_root = get_test_root();
  // ensure path
  ASSERT_NE(test_root, "");
  ASSERT_EQ(is_directory(test_root.c_str()), 1)
      << "Path for test root is invalid" << test_root;

  int numDev = 0;
  KernelCollectorBase kb{get_test_root()};

  kb.readNetworkStats();

  for (const auto& [devName, devRxtx] : kb.rxtx_) {
    if (devName.compare("eth0") == 0) {
      numDev++;
      EXPECT_EQ(devRxtx.rxBytes, 17566262828804);
      EXPECT_EQ(devRxtx.rxPackets, 18353492234);
      EXPECT_EQ(devRxtx.rxErrors, 0);
      EXPECT_EQ(devRxtx.rxDrops, 6734908);
      EXPECT_EQ(devRxtx.txBytes, 4485442728479);
      EXPECT_EQ(devRxtx.txPackets, 11129776879);
      EXPECT_EQ(devRxtx.txErrors, 0);
      EXPECT_EQ(devRxtx.txDrops, 0);
    } else if (devName.compare("eth1") == 0) {
      numDev++;
      EXPECT_EQ(devRxtx.rxBytes, 5651376349);
      EXPECT_EQ(devRxtx.rxPackets, 3826963);
      EXPECT_EQ(devRxtx.rxErrors, 0);
      EXPECT_EQ(devRxtx.rxDrops, 0);
      EXPECT_EQ(devRxtx.txBytes, 8626730);
      EXPECT_EQ(devRxtx.txPackets, 100254);
      EXPECT_EQ(devRxtx.txErrors, 0);
      EXPECT_EQ(devRxtx.txDrops, 0);
    }
  }
  EXPECT_EQ(numDev, 2);
}

TEST(KernelCollecterTest, UpdateNetworkStatsDeltaTest) {
  std::map<std::string, struct RxTx> oneDevice;
  std::map<std::string, struct RxTx> twoDevices;

  KernelCollectorBase kb{get_test_root()};

  oneDevice["eth0"] = RxTx{.rxBytes = 10};
  twoDevices["eth0"] = RxTx{.rxBytes = 100};
  twoDevices["eth1"] = RxTx{.rxBytes = 100};
  kb.rxtx_ = oneDevice;
  kb.updateNetworkStatsDelta(twoDevices);

  EXPECT_EQ(kb.rxtxDelta_.size(), 2);
  EXPECT_EQ(kb.rxtxDelta_["eth0"].rxBytes, 90);
  EXPECT_EQ(kb.rxtxDelta_["eth1"].rxBytes, 0);

  oneDevice["eth0"] = RxTx{.rxBytes = 50};
  twoDevices["eth0"] = RxTx{.rxBytes = 10};
  twoDevices["eth1"] = RxTx{.rxBytes = 100};
  kb.rxtx_ = twoDevices;
  kb.updateNetworkStatsDelta(oneDevice);

  EXPECT_EQ(kb.rxtxDelta_.size(), 1);
  EXPECT_EQ(kb.rxtxDelta_["eth0"].rxBytes, 40);
  EXPECT_EQ(kb.rxtxDelta_.find("eth1"), kb.rxtxDelta_.end());

  kb.rxtx_ = twoDevices;
  kb.updateNetworkStatsDelta(twoDevices);

  EXPECT_EQ(kb.rxtxDelta_.size(), 2);
  EXPECT_EQ(kb.rxtxDelta_["eth0"].rxBytes, 0);
  EXPECT_EQ(kb.rxtxDelta_["eth1"].rxBytes, 0);
}

TEST(KernelCollecterTest, MonitorInterfaceTest) {
  KernelCollectorBase kb{get_test_root()};

  kb.filterInteraces_ = false;
  EXPECT_FALSE(kb.isMonitoringInterfaceActive("enp0s0u1u2u3c2i3"));
  EXPECT_TRUE(kb.isMonitoringInterfaceActive("lo"));

  kb.filterInteraces_ = true;
  kb.nicInterfacePrefixes_ = {"eno", "ens", "enp", "enx", "eth"};
  EXPECT_FALSE(kb.isMonitoringInterfaceActive("lo"));
  EXPECT_TRUE(kb.isMonitoringInterfaceActive("enp8s0f1n2"));

  kb.filterInteraces_ = true;
  kb.nicInterfacePrefixes_ = {"lo", "vpn", "wlp"};
  EXPECT_TRUE(kb.isMonitoringInterfaceActive("lo"));
  EXPECT_TRUE(kb.isMonitoringInterfaceActive("wlp0s20f1"));
  EXPECT_FALSE(kb.isMonitoringInterfaceActive("enp8s0f1n2"));

  kb.filterInteraces_ = true;
  kb.nicInterfacePrefixes_ = {"br"};
  EXPECT_FALSE(kb.isMonitoringInterfaceActive("virbr0"));
  EXPECT_TRUE(kb.isMonitoringInterfaceActive("br0"));
  EXPECT_TRUE(kb.isMonitoringInterfaceActive("bridge0"));
}

} // namespace dynolog
