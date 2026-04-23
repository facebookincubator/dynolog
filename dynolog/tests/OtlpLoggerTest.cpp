/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <gtest/gtest.h>

#ifndef USE_OTEL

TEST(OtlpLoggerTest, Disabled) {
  GTEST_SKIP() << "USE_OTEL not defined";
}

#else
#include "dynolog/src/OtlpLogger.h"

#include <cstdio>
#include <fstream>

namespace dynolog {

// Write a temporary mappings file and set the flag before the static
// initializers in getMetricMappings()/getStringMappings() run.
// This fixture must be used for all tests that depend on mappings.
class OtlpLoggerTest : public ::testing::Test {
 protected:
  static void SetUpTestSuite() {
    // Create a temp mappings file with a representative subset.
    tmpFile_ = std::tmpnam(nullptr);
    std::ofstream f(tmpFile_);
    f << "# Test mappings\n";
    f << "gpu_device_utilization,accelerator_utilization,100.0\n";
    f << "gpu_frequency_mhz,compute_unit_frequency_mhz,1.0\n";
    f << "sm_active_ratio,compute_unit_utilization,100.0\n";
    f << "gpu_power_draw,accelerator_power_usage_w,1.0\n";
    f << "device,device_id,1.0\n";
    f << "gpu_name,accelerator_model\n";
    f.close();
    FLAGS_otel_metric_mappings_file = tmpFile_;
  }

  static void TearDownTestSuite() {
    std::remove(tmpFile_.c_str());
  }

  static std::string tmpFile_;
};

std::string OtlpLoggerTest::tmpFile_;

TEST_F(OtlpLoggerTest, NumericMappingsLoadedFromFile) {
  const auto& mappings = getMetricMappings();

  // Verify mappings loaded from file.
  EXPECT_EQ(mappings.size(), 5u);

  auto it = mappings.find("gpu_device_utilization");
  ASSERT_NE(it, mappings.end());
  EXPECT_EQ(it->second.output_name, "accelerator_utilization");
  EXPECT_DOUBLE_EQ(it->second.scale_factor, 100.0);

  it = mappings.find("gpu_frequency_mhz");
  ASSERT_NE(it, mappings.end());
  EXPECT_EQ(it->second.output_name, "compute_unit_frequency_mhz");
  EXPECT_DOUBLE_EQ(it->second.scale_factor, 1.0);

  it = mappings.find("device");
  ASSERT_NE(it, mappings.end());
  EXPECT_EQ(it->second.output_name, "device_id");
}

TEST_F(OtlpLoggerTest, StringMappingsLoadedFromFile) {
  const auto& mappings = getStringMappings();

  EXPECT_EQ(mappings.size(), 1u);
  auto it = mappings.find("gpu_name");
  ASSERT_NE(it, mappings.end());
  EXPECT_EQ(it->second, "accelerator_model");
}

TEST_F(OtlpLoggerTest, ScaleTransformBuffering) {
  OtlpLogger logger;
  logger.logFloat("gpu_device_utilization", 0.75f);
  logger.logInt("gpu_frequency_mhz", 1500);

  EXPECT_DOUBLE_EQ(logger.float_kvs_.at("gpu_device_utilization"), 0.75);
  EXPECT_EQ(logger.int_kvs_.at("gpu_frequency_mhz"), 1500);

  logger.finalize();
  EXPECT_TRUE(logger.float_kvs_.empty());
  EXPECT_TRUE(logger.int_kvs_.empty());
}

TEST_F(OtlpLoggerTest, StringMappingAppliedOnFinalize) {
  OtlpLogger logger;
  logger.logStr("gpu_name", "NVIDIA GB300");
  logger.logStr("unmapped_key", "some_value");

  logger.finalize();
  EXPECT_TRUE(logger.string_kvs_.empty());
}

TEST_F(OtlpLoggerTest, EmptyMetrics) {
  OtlpLogger logger;
  logger.setTimestamp(std::chrono::system_clock::now());
  logger.finalize();
  EXPECT_TRUE(logger.float_kvs_.empty());
  EXPECT_TRUE(logger.int_kvs_.empty());
  EXPECT_TRUE(logger.string_kvs_.empty());
}

TEST_F(OtlpLoggerTest, UnmappedMetricsPassThrough) {
  OtlpLogger logger;
  logger.logFloat("unknown_metric", 42.0f);
  logger.logStr("custom_tag", "value");

  EXPECT_EQ(logger.float_kvs_.size(), 1u);
  EXPECT_DOUBLE_EQ(logger.float_kvs_.at("unknown_metric"), 42.0);
  EXPECT_EQ(logger.string_kvs_.at("custom_tag"), "value");

  logger.finalize();
  EXPECT_TRUE(logger.float_kvs_.empty());
  EXPECT_TRUE(logger.string_kvs_.empty());
}

TEST_F(OtlpLoggerTest, MultipleFinalizeCycles) {
  OtlpLogger logger;

  logger.logFloat("gpu_device_utilization", 0.5f);
  logger.logStr("gpu_name", "NVIDIA H100");
  logger.finalize();
  EXPECT_TRUE(logger.float_kvs_.empty());
  EXPECT_TRUE(logger.string_kvs_.empty());

  logger.logFloat("gpu_device_utilization", 0.9f);
  logger.logStr("gpu_name", "NVIDIA H100");
  EXPECT_NEAR(logger.float_kvs_.at("gpu_device_utilization"), 0.9, 1e-6);
  EXPECT_EQ(logger.string_kvs_.at("gpu_name"), "NVIDIA H100");
  logger.finalize();
  EXPECT_TRUE(logger.float_kvs_.empty());
}

TEST_F(OtlpLoggerTest, IntPreservation) {
  OtlpLogger logger;
  logger.logInt("gpu_frequency_mhz", 1500);
  logger.logUint("some_counter", 42);

  EXPECT_EQ(logger.int_kvs_.at("gpu_frequency_mhz"), 1500);
  EXPECT_EQ(logger.int_kvs_.at("some_counter"), 42);

  logger.finalize();
  EXPECT_TRUE(logger.int_kvs_.empty());
}

TEST_F(OtlpLoggerTest, CommentsAndBlankLinesIgnored) {
  // The temp file has a comment line — verify it didn't create a bad mapping.
  const auto& mappings = getMetricMappings();
  EXPECT_EQ(mappings.find("#"), mappings.end());
  EXPECT_EQ(mappings.find("# Test mappings"), mappings.end());
}

} // namespace dynolog
#endif // USE_OTEL
