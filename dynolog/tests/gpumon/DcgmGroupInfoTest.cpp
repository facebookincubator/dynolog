/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/DcgmGroupInfo.h"

#include <gtest/gtest.h>

#include <cstring>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

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

  static auto collectEntityMetrics(
      const DcgmGroupInfo& groupInfo,
      const std::vector<dcgmFieldValue_v1>& values) {
    return groupInfo.collectEntityMetrics(values);
  }
};

namespace {

dcgmFieldValue_v1 fieldValue(unsigned short fieldId, char fieldType) {
  dcgmFieldValue_v1 value{};
  value.version = dcgmFieldValue_version1;
  value.fieldId = fieldId;
  value.fieldType = fieldType;
  value.status = DCGM_ST_OK;
  return value;
}

dcgmFieldValue_v1 intField(unsigned short fieldId, int64_t i64) {
  auto value = fieldValue(fieldId, DCGM_FT_INT64);
  value.value.i64 = i64;
  return value;
}

dcgmFieldValue_v1 doubleField(unsigned short fieldId, double dbl) {
  auto value = fieldValue(fieldId, DCGM_FT_DOUBLE);
  value.value.dbl = dbl;
  return value;
}

dcgmFieldValue_v1 stringField(unsigned short fieldId, const std::string& str) {
  auto value = fieldValue(fieldId, DCGM_FT_STRING);
  strncpy(value.value.str, str.c_str(), sizeof(value.value.str) - 1);
  return value;
}

TEST(DcgmGroupInfoTest, BlankValuesAreNotStored) {
  auto groupInfo = DcgmGroupInfoTestPeer::create();
  const std::vector<dcgmFieldValue_v1> values{
      doubleField(DCGM_FI_DEV_POWER_USAGE, DCGM_FP64_BLANK),
      intField(DCGM_FI_DEV_GPU_UTIL, 42),
      intField(DCGM_FI_DEV_SM_CLOCK, DCGM_INT64_NOT_SUPPORTED),
      stringField(DCGM_FI_DEV_NAME, "NVIDIA GB300"),
      stringField(DCGM_FI_DEV_UUID, DCGM_STR_BLANK),
  };

  const auto metrics =
      DcgmGroupInfoTestPeer::collectEntityMetrics(*groupInfo, values);

  EXPECT_TRUE(metrics.hasBlankValue);
  EXPECT_TRUE(metrics.doubles.empty());
  const std::unordered_map<std::string, int64_t> expectedInts{
      {"gpu_device_utilization", 42}};
  EXPECT_EQ(metrics.ints, expectedInts);
  const std::unordered_map<std::string, std::string> expectedStrings{
      {"gpu_name", "NVIDIA GB300"}};
  EXPECT_EQ(metrics.strings, expectedStrings);
}

TEST(DcgmGroupInfoTest, NotSupportedValueDoesNotMarkSampleBlank) {
  auto groupInfo = DcgmGroupInfoTestPeer::create();
  const std::vector<dcgmFieldValue_v1> values{
      intField(DCGM_FI_DEV_GPU_UTIL, 42),
      intField(DCGM_FI_DEV_SM_CLOCK, DCGM_INT64_NOT_SUPPORTED),
  };

  const auto metrics =
      DcgmGroupInfoTestPeer::collectEntityMetrics(*groupInfo, values);

  EXPECT_FALSE(metrics.hasBlankValue);
  EXPECT_FALSE(metrics.ints.contains("gpu_frequency_mhz"));
}

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
