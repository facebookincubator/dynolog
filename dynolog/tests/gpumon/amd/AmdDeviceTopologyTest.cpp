/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <glog/logging.h>
#include <gtest/gtest.h>

#include "dynolog/src/gpumon/amd/AmdDeviceTopology.h"

using namespace dynolog::gpumon;

constexpr char kTestRoot[] = "TESTROOT";

std::filesystem::path get_test_root() {
  if (const char* env_p = std::getenv(kTestRoot)) {
    return std::filesystem::path(env_p);
  }
  LOG(ERROR) << "Missing test root env: " << kTestRoot;
  return "";
}

class AmdDeviceTopologyTest : public ::testing::Test {
 protected:
  const std::filesystem::path kfdRoot =
      get_test_root() / "sys" / "class" / "kfd";
  const std::filesystem::path pciRoot =
      get_test_root() / "sys" / "bus" / "pci" / "drivers" / "amdgpu";
};

TEST_F(AmdDeviceTopologyTest, ParseKfdNodes) {
  auto devices =
      dynolog::gpumon::amdgpu::LogicalDevice::parseTopologyNodes(kfdRoot);
  EXPECT_EQ(devices.size(), 3);

  // Check first GPU node
  EXPECT_EQ(devices[0]->getKfdNodeId(), 1);
  EXPECT_EQ(devices[0]->getMinorId(), 177);
  EXPECT_EQ(devices[0]->getUniqueId(), 9847564688237960509ULL);

  // Check second GPU node
  EXPECT_EQ(devices[1]->getKfdNodeId(), 2);
  EXPECT_EQ(devices[1]->getMinorId(), 178);
  EXPECT_EQ(devices[1]->getUniqueId(), 9847564688237960510ULL);

  // Check second GPU node
  EXPECT_EQ(devices[2]->getKfdNodeId(), 3);
  EXPECT_EQ(devices[2]->getMinorId(), 179);
  EXPECT_EQ(devices[2]->getUniqueId(), 9847564688237960510ULL);
}

TEST_F(AmdDeviceTopologyTest, ParsePci) {
  auto devices = dynolog::gpumon::amdgpu::PhysicalDevice::parsePciDevices(
      {"pci_addr_1", "pci_addr_2"}, pciRoot);
  EXPECT_EQ(devices.size(), 2);

  // Check device 1
  EXPECT_EQ(devices[0]->getUniqueId(), 9847564688237960509ULL);
  EXPECT_EQ(devices[0]->getPciAddr(), "pci_addr_1");
  EXPECT_EQ(devices[0]->getOamId(), 0);
  EXPECT_EQ(devices[0]->getMinorId(), 128);

  // Check device 2
  EXPECT_EQ(devices[1]->getUniqueId(), 9847564688237960510ULL);
  EXPECT_EQ(devices[1]->getPciAddr(), "pci_addr_2");
  EXPECT_EQ(devices[1]->getOamId(), 1);
  EXPECT_EQ(devices[1]->getMinorId(), 129);
}

TEST_F(AmdDeviceTopologyTest, BuildTopology) {
  auto devices = amdgpu::buildAmdDeviceTopology(
      {"pci_addr_1", "pci_addr_2"}, get_test_root());
  EXPECT_EQ(devices[0]->getLogicalDevices().size(), 1);
  EXPECT_EQ(devices[1]->getLogicalDevices().size(), 2);
}
