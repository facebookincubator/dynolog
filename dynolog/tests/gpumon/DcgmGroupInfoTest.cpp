/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/DcgmGroupInfo.h"

#include <gtest/gtest.h>

#include <memory>
#include <string>

namespace dynolog::gpumon {

class DcgmGroupInfoTestPeer {
 public:
  static std::unique_ptr<DcgmGroupInfo> create() {
    return std::unique_ptr<DcgmGroupInfo>(new DcgmGroupInfo());
  }

  static void addEnvironmentMetadata(
      DcgmGroupInfo& groupInfo,
      int deviceId,
      const std::string& key,
      const std::string& value) {
    groupInfo.envMetadataMapString_[deviceId][key] = value;
  }

  static bool hasEnvironmentMetadata(
      const DcgmGroupInfo& groupInfo,
      int deviceId,
      const std::string& key) {
    const auto deviceIt = groupInfo.envMetadataMapString_.find(deviceId);
    return deviceIt != groupInfo.envMetadataMapString_.end() &&
        deviceIt->second.contains(key);
  }

  static void clearMetricCachesForSuccessfulRefresh(DcgmGroupInfo& groupInfo) {
    groupInfo.clearMetricCachesForSuccessfulRefresh();
  }
};

namespace {

TEST(DcgmGroupInfoTest, SuccessfulRefreshClearsEnvironmentMetadata) {
  auto groupInfo = DcgmGroupInfoTestPeer::create();
  DcgmGroupInfoTestPeer::addEnvironmentMetadata(
      *groupInfo, 0, "pod_name", "old-pod");
  ASSERT_TRUE(
      DcgmGroupInfoTestPeer::hasEnvironmentMetadata(*groupInfo, 0, "pod_name"));

  DcgmGroupInfoTestPeer::clearMetricCachesForSuccessfulRefresh(*groupInfo);

  EXPECT_FALSE(
      DcgmGroupInfoTestPeer::hasEnvironmentMetadata(*groupInfo, 0, "pod_name"));
}

} // namespace
} // namespace dynolog::gpumon
