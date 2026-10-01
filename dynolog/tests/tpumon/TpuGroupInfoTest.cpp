/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/tpumon/TpuGroupInfo.h"

#include <gtest/gtest.h>

#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "dynolog/src/Logger.h"
#include "dynolog/src/tpumon/TpuScraper.h"

namespace dynolog::tpumon {
namespace {

struct CapturedRecord {
  std::unordered_map<std::string, double> floats;
  std::unordered_map<std::string, int64_t> ints;
  std::unordered_map<std::string, std::string> strings;
};

class RecordingLogger : public Logger {
 public:
  void logFloat(const std::string& key, float value) override {
    current_.floats[key] = value;
  }
  void logInt(const std::string& key, int64_t value) override {
    current_.ints[key] = value;
  }
  void logUint(const std::string& key, uint64_t value) override {
    current_.ints[key] = static_cast<int64_t>(value);
  }
  void logStr(const std::string& key, const std::string& value) override {
    current_.strings[key] = value;
  }
  void setTimestamp(Logger::Timestamp) override {}
  void finalize() override {
    records_.push_back(std::move(current_));
    current_ = {};
  }
  const std::vector<CapturedRecord>& records() const {
    return records_;
  }
  void clear() {
    current_ = {};
    records_.clear();
  }

 private:
  CapturedRecord current_;
  std::vector<CapturedRecord> records_;
};

// Real exposition captured from tpu-device-plugin v1.35.7-gke.0 on a
// tpu7x-standard-4t node in test-tpu-cluster. Chip -4/-5 bound to a
// vllm-worker pod; chip -0 unbound.
constexpr const char* kProbeOutputTpu7x =
    R"PROM(duty_cycle{accelerator_id="1234567890123456789-4",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 42
duty_cycle{accelerator_id="1234567890123456789-5",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 43
duty_cycle_node{accelerator_id="1234567890123456789-0",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 0
duty_cycle_node{accelerator_id="1234567890123456789-4",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 99
memory_total{accelerator_id="1234567890123456789-4",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 2.03465670656e+11
memory_used{accelerator_id="1234567890123456789-4",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 1.017328353e+11
memory_total_node{accelerator_id="1234567890123456789-0",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 2.03465670656e+11
memory_used_node{accelerator_id="1234567890123456789-0",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 0
tensorcore_utilization_node{accelerator_id="1234567890123456789-0",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 88
memory_bandwidth_utilization_node{accelerator_id="1234567890123456789-0",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 77
)PROM";

// Returns a reference to the matching record, or aborts the test via
// GTEST fatal ADD_FAILURE + a throw. Return-by-reference avoids the
// nullable-pointer deref pattern that NULLSAFECLANG flags after
// ASSERT_NE (which the static analyzer cannot see through).
const CapturedRecord& recordByDevice(
    const std::vector<CapturedRecord>& records,
    int64_t device) {
  for (const auto& r : records) {
    const auto it = r.ints.find("device");
    if (it != r.ints.end() && it->second == device) {
      return r;
    }
  }
  ADD_FAILURE() << "no record found for device=" << device;
  throw std::runtime_error("record not found");
}

TpuPodIdentity metricPodIdentity() {
  return {
      .podNamespace = "test-namespace",
      .podName = "test-workload-pod",
      .containerName = "vllm-worker",
  };
}

void expectNoPodIdentity(const CapturedRecord& record) {
  EXPECT_EQ(record.strings.count("pod_namespace"), 0u);
  EXPECT_EQ(record.strings.count("pod_name"), 0u);
  EXPECT_EQ(record.strings.count("container_name"), 0u);
}

// Fixture: parse the real exposition once, then drive TpuGroupInfo via
// the testing seam (skips HTTP because buck2's sandbox blocks loopback).
class TpuGroupInfoTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // URL not used — the seam bypasses TpuScraper::scrape().
    info_ = TpuGroupInfo::factoryForTesting(
        "http://unused",
        100,
        10000,
        {
            .listCurrentOwners = [this] { return currentOwners_; },
            .lookupAttributes =
                [this](const TpuPodIdentity& identity) {
                  lookedUpIdentities_.push_back(identity);
                  return lookupAttributes_;
                },
        });
    ASSERT_NE(info_, nullptr);
  }

  void updateFromExposition(const std::string& body) {
    const auto samples = parsePrometheusText(body);
    info_->updateFromSamples(samples, /*scrape_failed=*/false);
    info_->log(logger_);
  }

  std::vector<TpuPodIdentity> currentOwners_;
  std::unordered_map<std::string, std::string> lookupAttributes_;
  std::vector<TpuPodIdentity> lookedUpIdentities_;
  std::shared_ptr<TpuGroupInfo> info_;
  RecordingLogger logger_;
};

TEST_F(TpuGroupInfoTest, PopulatesPerChipRowsFromRealExposition) {
  updateFromExposition(kProbeOutputTpu7x);

  // Bound chip -4: container variant wins over node fallback (42 not 99).
  const auto& r4 = recordByDevice(logger_.records(), 4);
  EXPECT_DOUBLE_EQ(r4.floats.at("accelerator_utilization"), 42.0);
  // memory_utilization = 1.017328353e+11 / 2.03465670656e+11 * 100 = 50%.
  EXPECT_NEAR(r4.floats.at("memory_utilization"), 50.0, 0.01);
  EXPECT_EQ(r4.strings.at("accelerator_model"), "tpu7x");
  EXPECT_EQ(r4.strings.at("accelerator_vendor"), "cloud-tpu");
  EXPECT_EQ(r4.strings.at("accelerator_serial_number"), "1234567890123456789");
  EXPECT_EQ(r4.ints.at("tpu_error"), 0);

  // Unbound chip -0: only node variants — accelerator_utilization=0.
  const auto& r0 = recordByDevice(logger_.records(), 0);
  EXPECT_DOUBLE_EQ(r0.floats.at("accelerator_utilization"), 0.0);
  EXPECT_DOUBLE_EQ(r0.floats.at("memory_utilization"), 0.0);
}

TEST_F(TpuGroupInfoTest, DeviceIdBucketKeyMatchesGpuShape) {
  updateFromExposition(kProbeOutputTpu7x);

  // Every record must carry an integer `device` in [0, N) and share the
  // same accelerator_serial_number so the Hive bucket
  // (timestamp_10s, host_name, device_id, device_instance_id) stays
  // consistent with GPU rows.
  std::set<int64_t> device_ids;
  for (const auto& r : logger_.records()) {
    ASSERT_EQ(r.ints.count("device"), 1u);
    device_ids.insert(r.ints.at("device"));
    ASSERT_EQ(r.strings.at("accelerator_serial_number"), "1234567890123456789");
  }
  const std::set<int64_t> expected = {0, 4, 5};
  EXPECT_EQ(device_ids, expected);
}

TEST_F(TpuGroupInfoTest, ScrapeFailureEmitsErrorRow) {
  info_->updateFromSamples(/*samples=*/{}, /*scrape_failed=*/true);
  info_->log(logger_);

  ASSERT_EQ(logger_.records().size(), 1u);
  const auto& r = logger_.records()[0];
  EXPECT_EQ(r.ints.at("tpu_error"), 1);
  EXPECT_EQ(r.strings.at("accelerator_vendor"), "cloud-tpu");
  EXPECT_EQ(r.ints.at("device"), 0);
}

TEST_F(TpuGroupInfoTest, HostAggregateOnlyMetricsNotEmitted) {
  updateFromExposition(kProbeOutputTpu7x);

  // tensorcore_utilization_node and memory_bandwidth_utilization_node
  // are host-aggregate only — per plan §5a they MUST NOT be stuffed
  // into per-chip rows.
  for (const auto& r : logger_.records()) {
    EXPECT_EQ(r.floats.count("tensorcore_active"), 0u)
        << "tensorcore_active must not appear on TPU rows (plan §5a)";
    EXPECT_EQ(r.floats.count("mem_bw_util"), 0u)
        << "mem_bw_util must not appear on TPU rows (plan §5a)";
  }
}

TEST_F(TpuGroupInfoTest, EmitsPodIdentityOnlyForCurrentOwner) {
  const auto identity = metricPodIdentity();
  currentOwners_ = {identity};
  lookupAttributes_ = {
      {"service_account", "test-service-account"},
      {"pod_namespace", "unverified-namespace"},
      {"pod_name", "unverified-pod"},
      {"container_name", "unverified-container"},
  };

  updateFromExposition(kProbeOutputTpu7x);

  for (const int64_t device : {4, 5}) {
    const auto& record = recordByDevice(logger_.records(), device);
    EXPECT_EQ(record.strings.at("pod_namespace"), identity.podNamespace);
    EXPECT_EQ(record.strings.at("pod_name"), identity.podName);
    EXPECT_EQ(record.strings.at("container_name"), identity.containerName);
    EXPECT_EQ(record.strings.at("service_account"), "test-service-account");
  }
  expectNoPodIdentity(recordByDevice(logger_.records(), 0));
  const std::vector<TpuPodIdentity> expectedLookups = {identity, identity};
  EXPECT_EQ(lookedUpIdentities_, expectedLookups);
}

TEST_F(TpuGroupInfoTest, RejectsStaleRawIdentityWithoutCurrentOwner) {
  updateFromExposition(kProbeOutputTpu7x);

  expectNoPodIdentity(recordByDevice(logger_.records(), 4));
  expectNoPodIdentity(recordByDevice(logger_.records(), 5));
  EXPECT_TRUE(lookedUpIdentities_.empty());
  EXPECT_DOUBLE_EQ(
      recordByDevice(logger_.records(), 4).floats.at("accelerator_utilization"),
      42.0);
}

TEST_F(TpuGroupInfoTest, RejectsAnyDifferentCurrentOwnerField) {
  const std::vector<TpuPodIdentity> mismatchedOwners = {
      {
          .podNamespace = "different-namespace",
          .podName = "test-workload-pod",
          .containerName = "vllm-worker",
      },
      {
          .podNamespace = "test-namespace",
          .podName = "different-pod",
          .containerName = "vllm-worker",
      },
      {
          .podNamespace = "test-namespace",
          .podName = "test-workload-pod",
          .containerName = "different-container",
      },
  };

  for (const auto& owner : mismatchedOwners) {
    currentOwners_ = {owner};
    logger_.clear();
    lookedUpIdentities_.clear();
    updateFromExposition(kProbeOutputTpu7x);

    expectNoPodIdentity(recordByDevice(logger_.records(), 4));
    expectNoPodIdentity(recordByDevice(logger_.records(), 5));
    EXPECT_TRUE(lookedUpIdentities_.empty());
  }
}

TEST_F(TpuGroupInfoTest, RejectsPartialRawIdentity) {
  currentOwners_ = {metricPodIdentity()};
  constexpr const char* exposition =
      R"PROM(duty_cycle{accelerator_id="1234567890123456789-4",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 42
)PROM";

  updateFromExposition(exposition);

  const auto& record = recordByDevice(logger_.records(), 4);
  expectNoPodIdentity(record);
  EXPECT_DOUBLE_EQ(record.floats.at("accelerator_utilization"), 42.0);
  EXPECT_TRUE(lookedUpIdentities_.empty());
}

TEST_F(TpuGroupInfoTest, RejectsConflictingRawIdentitiesForOneDevice) {
  const auto identity = metricPodIdentity();
  const TpuPodIdentity conflictingIdentity{
      .podNamespace = "other-namespace",
      .podName = "other-pod",
      .containerName = "other-container",
  };
  currentOwners_ = {identity, conflictingIdentity};
  const std::string exposition = std::string(kProbeOutputTpu7x) +
      R"PROM(duty_cycle{accelerator_id="1234567890123456789-4",container="other-container",make="cloud-tpu",model="tpu7x",namespace="other-namespace",pod="other-pod",tpu_topology="2x2x2"} 42
)PROM";

  updateFromExposition(exposition);

  expectNoPodIdentity(recordByDevice(logger_.records(), 4));
  const auto& record5 = recordByDevice(logger_.records(), 5);
  EXPECT_EQ(record5.strings.at("pod_namespace"), identity.podNamespace);
  EXPECT_DOUBLE_EQ(
      recordByDevice(logger_.records(), 4).floats.at("accelerator_utilization"),
      42.0);
  const std::vector<TpuPodIdentity> expectedLookups = {identity};
  EXPECT_EQ(lookedUpIdentities_, expectedLookups);
}

TEST_F(TpuGroupInfoTest, ClearsPodIdentityWhenOwnerDisappears) {
  currentOwners_ = {metricPodIdentity()};
  updateFromExposition(kProbeOutputTpu7x);
  EXPECT_EQ(
      recordByDevice(logger_.records(), 4).strings.at("pod_name"),
      "test-workload-pod");

  currentOwners_.clear();
  lookedUpIdentities_.clear();
  logger_.clear();
  updateFromExposition(kProbeOutputTpu7x);

  expectNoPodIdentity(recordByDevice(logger_.records(), 4));
  expectNoPodIdentity(recordByDevice(logger_.records(), 5));
  EXPECT_TRUE(lookedUpIdentities_.empty());
}

} // namespace
} // namespace dynolog::tpumon
