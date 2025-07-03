#include <glog/logging.h>
#include <gtest/gtest.h>

#include "dynolog/src/gpumon/amd/AmdDeviceTopology.h"

using namespace dynolog::gpumon;

constexpr char kTestRoot[] = "TESTROOT";

std::string get_test_root() {
  if (const char* env_p = std::getenv(kTestRoot)) {
    return std::filesystem::path(env_p) / "sys" / "class" / "kfd";
  }
  LOG(ERROR) << "Missing test root env: " << kTestRoot;
  return "";
}

class AmdDeviceTopologyTest : public ::testing::Test {
 protected:
  const std::filesystem::path testRoot = get_test_root();
};

TEST_F(AmdDeviceTopologyTest, ParseKfdNodes) {
  auto devices =
      dynolog::gpumon::amdgpu::LogicalDevice::parseTopologyNodes(testRoot);
  EXPECT_EQ(devices.size(), 3);

  // Check first GPU node
  EXPECT_EQ(devices[0].getKfdNodeId(), 1);
  EXPECT_EQ(devices[0].getMinorId(), 177);
  EXPECT_EQ(devices[0].getUniqueId(), 9847564688237960509ULL);
  EXPECT_FALSE(devices[0].isPartition());

  // Check second GPU node
  EXPECT_EQ(devices[1].getKfdNodeId(), 2);
  EXPECT_EQ(devices[1].getMinorId(), 178);
  EXPECT_EQ(devices[1].getUniqueId(), 9847564688237960510ULL);
  EXPECT_TRUE(devices[1].isPartition());

  // Check second GPU node
  EXPECT_EQ(devices[2].getKfdNodeId(), 3);
  EXPECT_EQ(devices[2].getMinorId(), 179);
  EXPECT_EQ(devices[2].getUniqueId(), 9847564688237960510ULL);
  EXPECT_TRUE(devices[2].isPartition());
}
