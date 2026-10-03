/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/LibkinetoConfigManager.h"
#include <gtest/gtest.h>
#include <chrono>
#include "dynolog/src/LibkinetoJobRegistry.h"

using namespace dynolog;

class LibkinetoConfigManagerTest : public ::testing::Test {
 protected:
  void SetUp() override {
    configManager_ = LibkinetoConfigManager::getInstance();
    registry_ = LibkinetoJobRegistry::getInstance();

    // Clear any existing state
    {
      std::lock_guard<std::mutex> guard(registry_->getMutex());
      auto& jobs = registry_->getAllJobs();
      jobs.clear();
    }
  }

  void TearDown() override {
    // Clean up after each test
    {
      std::lock_guard<std::mutex> guard(registry_->getMutex());
      auto& jobs = registry_->getAllJobs();
      jobs.clear();
    }
  }

  std::shared_ptr<LibkinetoConfigManager> configManager_;
  std::shared_ptr<LibkinetoJobRegistry> registry_;
};

// Test that namespace ID is stored when provided to obtainOnDemandConfig
TEST_F(LibkinetoConfigManagerTest, ObtainOnDemandConfigStoresNamespaceId) {
  const std::string jobId = "test_job_123";
  const std::vector<int32_t> pids = {12345};
  const uint64_t namespaceId = 4026531836; // typical namespace ID value

  // First call with namespace ID
  std::string config = configManager_->obtainOnDemandConfig(
      jobId, pids, int(LibkinetoConfigType::EVENTS), namespaceId);

  // Verify the process was registered with namespace ID
  {
    std::lock_guard<std::mutex> guard(registry_->getMutex());
    auto& jobs = registry_->getAllJobs();

    ASSERT_EQ(jobs.size(), 1);
    ASSERT_TRUE(jobs.find(jobId) != jobs.end());

    auto& processMap = jobs[jobId];
    ASSERT_EQ(processMap.size(), 1);

    auto& process = processMap.begin()->second;
    EXPECT_EQ(process.pid, 12345);
    ASSERT_TRUE(process.pidNamespaceId.has_value());
    EXPECT_EQ(process.pidNamespaceId.value(), namespaceId);
  }
}

// Test that namespace ID is optional
TEST_F(LibkinetoConfigManagerTest, ObtainOnDemandConfigWithoutNamespaceId) {
  const std::string jobId = "test_job_456";
  const std::vector<int32_t> pids = {67890};

  // Call without namespace ID (std::nullopt)
  std::string config = configManager_->obtainOnDemandConfig(
      jobId, pids, int(LibkinetoConfigType::EVENTS));

  // Verify the process was registered without namespace ID
  {
    std::lock_guard<std::mutex> guard(registry_->getMutex());
    auto& jobs = registry_->getAllJobs();

    ASSERT_EQ(jobs.size(), 1);
    ASSERT_TRUE(jobs.find(jobId) != jobs.end());

    auto& processMap = jobs[jobId];
    ASSERT_EQ(processMap.size(), 1);

    auto& process = processMap.begin()->second;
    EXPECT_EQ(process.pid, 67890);
    EXPECT_FALSE(process.pidNamespaceId.has_value());
  }
}

TEST_F(LibkinetoConfigManagerTest, DefaultJobIdsUseUndefinedRegistryEntry) {
  const std::vector<int32_t> emptyJobPids = {12345};
  const std::vector<int32_t> zeroJobPids = {67890};

  configManager_->obtainOnDemandConfig(
      "", emptyJobPids, int(LibkinetoConfigType::EVENTS));
  configManager_->obtainOnDemandConfig(
      "0", zeroJobPids, int(LibkinetoConfigType::EVENTS));

  std::lock_guard<std::mutex> guard(registry_->getMutex());
  const auto& jobs = registry_->getAllJobs();
  ASSERT_EQ(jobs.size(), 1);
  EXPECT_EQ(jobs.count("undefined"), 1);
  EXPECT_EQ(jobs.at("undefined").size(), 2);
}

TEST_F(LibkinetoConfigManagerTest, DefaultJobIdsShareRegisteredInstances) {
  constexpr int32_t kGpu = 12345;

  EXPECT_EQ(configManager_->registerLibkinetoContext("", 12345, kGpu), 1);
  EXPECT_EQ(configManager_->registerLibkinetoContext("0", 67890, kGpu), 2);
  EXPECT_EQ(
      configManager_->registerLibkinetoContext("undefined", 11111, kGpu), 3);
}

TEST_F(LibkinetoConfigManagerTest, DefaultJobIdsMatchInterchangeably) {
  const std::vector<int32_t> pids = {12345};
  const std::set<int32_t> targetPids = {12345};
  const std::string config = "TEST_CONFIG";

  configManager_->obtainOnDemandConfig(
      "", pids, int(LibkinetoConfigType::EVENTS));
  const auto result = configManager_->setOnDemandConfig(
      "0", targetPids, config, int(LibkinetoConfigType::EVENTS), 1);

  EXPECT_EQ(result.processesMatched, std::vector<int32_t>({12345}));
  EXPECT_EQ(result.eventProfilersTriggered, std::vector<int32_t>({12345}));
  EXPECT_EQ(
      configManager_->obtainOnDemandConfig(
          "undefined", pids, int(LibkinetoConfigType::EVENTS)),
      config + "\n");
  EXPECT_EQ(configManager_->processCount(""), 1);
  EXPECT_EQ(configManager_->processCount("0"), 1);
  EXPECT_EQ(configManager_->processCount("undefined"), 1);
}

// Test that namespace ID is unable to be updated on subsequent calls
TEST_F(LibkinetoConfigManagerTest, NamespaceIdUnableToUpdate) {
  const std::string jobId = "test_job_789";
  const std::vector<int32_t> pids = {11111};
  const uint64_t namespaceId1 = 4026531836;
  const uint64_t namespaceId2 = 4026532000;

  // First call with namespace ID 1
  configManager_->obtainOnDemandConfig(
      jobId, pids, int(LibkinetoConfigType::EVENTS), namespaceId1);

  // Verify first namespace ID
  {
    std::lock_guard<std::mutex> guard(registry_->getMutex());
    auto& jobs = registry_->getAllJobs();
    auto& process = jobs[jobId].begin()->second;
    EXPECT_EQ(process.pidNamespaceId.value(), namespaceId1);
  }

  // Second call with namespace ID 2 (simulating namespace change)
  configManager_->obtainOnDemandConfig(
      jobId, pids, int(LibkinetoConfigType::EVENTS), namespaceId2);

  // Note: In the current implementation, namespace ID is only set for NEW
  // processes This is expected behavior since we set it during process
  // registration
  {
    std::lock_guard<std::mutex> guard(registry_->getMutex());
    auto& jobs = registry_->getAllJobs();
    auto& process = jobs[jobId].begin()->second;
    // Should still have the first namespace ID since process already existed
    EXPECT_EQ(process.pidNamespaceId.value(), namespaceId1);
  }
}

// Test process with multiple PIDs (ancestry chain)
TEST_F(LibkinetoConfigManagerTest, MultiPidProcessWithNamespaceId) {
  const std::string jobId = "test_job_multi";
  const std::vector<int32_t> pids = {
      12345, 12344, 12343}; // child, parent, grandparent
  const uint64_t namespaceId = 4026531836;

  configManager_->obtainOnDemandConfig(
      jobId, pids, int(LibkinetoConfigType::ACTIVITIES), namespaceId);

  {
    std::lock_guard<std::mutex> guard(registry_->getMutex());
    auto& jobs = registry_->getAllJobs();
    auto& processMap = jobs[jobId];

    ASSERT_EQ(processMap.size(), 1);
    auto& process = processMap.begin()->second;

    // Verify leaf PID
    EXPECT_EQ(process.pid, 12345);

    // Verify full PID ancestry
    EXPECT_EQ(process.pids.size(), 3);
    EXPECT_EQ(process.pids[0], 12345); // leaf
    EXPECT_EQ(process.pids[1], 12344); // parent
    EXPECT_EQ(process.pids[2], 12343); // grandparent

    // Verify namespace ID
    ASSERT_TRUE(process.pidNamespaceId.has_value());
    EXPECT_EQ(process.pidNamespaceId.value(), namespaceId);
  }
}

// Test lastRequestTime is updated
TEST_F(LibkinetoConfigManagerTest, LastRequestTimeIsUpdated) {
  const std::string jobId = "test_job_time";
  const std::vector<int32_t> pids = {33333};

  auto before = std::chrono::system_clock::now();

  configManager_->obtainOnDemandConfig(
      jobId, pids, int(LibkinetoConfigType::EVENTS));

  auto after = std::chrono::system_clock::now();

  {
    std::lock_guard<std::mutex> guard(registry_->getMutex());
    auto& jobs = registry_->getAllJobs();
    auto& process = jobs[jobId].begin()->second;

    // Verify lastRequestTime is between before and after
    EXPECT_GE(process.lastRequestTime, before);
    EXPECT_LE(process.lastRequestTime, after);
  }
}
