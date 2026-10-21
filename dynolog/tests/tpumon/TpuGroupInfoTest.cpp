/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/tpumon/TpuGroupInfo.h"

#include <gtest/gtest.h>

#include <chrono>
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
  Logger::Timestamp timestamp;
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
  void setTimestamp(Logger::Timestamp ts) override {
    timestamp_ = ts;
  }
  void finalize() override {
    current_.timestamp = timestamp_;
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
  Logger::Timestamp timestamp_;
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
tensorcore_utilization_node{accelerator_id="1234567890123456789-4",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 11
tensorcore_utilization{accelerator_id="1234567890123456789-4",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 66
memory_total{accelerator_id="1234567890123456789-4",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 2.03465670656e+11
memory_used{accelerator_id="1234567890123456789-4",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 1.017328353e+11
memory_bandwidth_utilization{accelerator_id="1234567890123456789-4",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 55
memory_bandwidth_utilization_node{accelerator_id="1234567890123456789-4",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 22
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

// tpu_pod_label_rejected reason codes; 0 means the record carries none.
constexpr int64_t kNoRejection = 0;
constexpr int64_t kNotCurrentOwner = 1;
constexpr int64_t kConflictingPods = 2;
constexpr int64_t kIncompleteLabels = 3;

int64_t podLabelRejection(const CapturedRecord& record) {
  const auto it = record.ints.find("tpu_pod_label_rejected");
  return it == record.ints.end() ? kNoRejection : it->second;
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
            .lookupNodeLabels = [this] { return nodeLabels_; },
            .nodeLabelAttributionMap =
                {{"cloud.google.com/reservation-project",
                  "reservation_project"}},
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
  std::unordered_map<std::string, std::string> nodeLabels_;
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

TEST_F(TpuGroupInfoTest, PopulatesTensorcoreAndMemoryBandwidthMetrics) {
  updateFromExposition(kProbeOutputTpu7x);

  // Chip -0 only has node-scoped samples, so they provide the fallback values.
  const auto& r0 = recordByDevice(logger_.records(), 0);
  EXPECT_DOUBLE_EQ(r0.floats.at("tensorcore_utilization"), 88.0);
  EXPECT_DOUBLE_EQ(r0.floats.at("memory_bandwidth_utilization"), 77.0);

  // Chip -4 has both scopes. Container values win whether the node sample was
  // encountered before or after the container sample.
  const auto& r4 = recordByDevice(logger_.records(), 4);
  EXPECT_DOUBLE_EQ(r4.floats.at("tensorcore_utilization"), 66.0);
  EXPECT_DOUBLE_EQ(r4.floats.at("memory_bandwidth_utilization"), 55.0);
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
    EXPECT_EQ(podLabelRejection(record), kNoRejection);
  }
  expectNoPodIdentity(recordByDevice(logger_.records(), 0));
  // Chip 0 has no pod labels at all, so there is nothing to reject.
  EXPECT_EQ(
      podLabelRejection(recordByDevice(logger_.records(), 0)), kNoRejection);
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
  // No current owners at all may mean PodResources failed, so nothing is
  // flagged.
  EXPECT_EQ(
      podLabelRejection(recordByDevice(logger_.records(), 4)), kNoRejection);
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
    for (const int64_t device : {4, 5}) {
      EXPECT_EQ(
          podLabelRejection(recordByDevice(logger_.records(), device)),
          kNotCurrentOwner);
    }
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
  EXPECT_EQ(podLabelRejection(record), kIncompleteLabels);
}

TEST_F(TpuGroupInfoTest, FlagsLabelProblemsThatDoNotDependOnOwners) {
  // No current owners: chip 4 has labels from two pods and chip 5 has
  // incomplete labels, both wrong whatever PodResources returns.
  constexpr const char* exposition =
      R"PROM(duty_cycle{accelerator_id="1234567890123456789-4",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 42
tensorcore_utilization{accelerator_id="1234567890123456789-4",container="other-container",make="cloud-tpu",model="tpu7x",namespace="other-namespace",pod="other-pod",tpu_topology="2x2x2"} 10
duty_cycle{accelerator_id="1234567890123456789-5",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 43
)PROM";

  updateFromExposition(exposition);

  EXPECT_EQ(
      podLabelRejection(recordByDevice(logger_.records(), 4)),
      kConflictingPods);
  EXPECT_EQ(
      podLabelRejection(recordByDevice(logger_.records(), 5)),
      kIncompleteLabels);
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
  EXPECT_EQ(
      podLabelRejection(recordByDevice(logger_.records(), 4)),
      kConflictingPods);
  const auto& record5 = recordByDevice(logger_.records(), 5);
  EXPECT_EQ(record5.strings.at("pod_namespace"), identity.podNamespace);
  EXPECT_EQ(podLabelRejection(record5), kNoRejection);
  EXPECT_DOUBLE_EQ(
      recordByDevice(logger_.records(), 4).floats.at("accelerator_utilization"),
      42.0);
  const std::vector<TpuPodIdentity> expectedLookups = {identity};
  EXPECT_EQ(lookedUpIdentities_, expectedLookups);
}

std::string promLine(const std::string& name, int id, double value) {
  return name + R"({accelerator_id="1234567890123456789-)" +
      std::to_string(id) +
      R"(",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology=""} )" +
      std::to_string(value) + "\n";
}

std::set<int64_t> deviceIds(const std::vector<CapturedRecord>& records) {
  std::set<int64_t> ids;
  for (const auto& r : records) {
    ids.insert(r.ints.at("device"));
  }
  return ids;
}

TEST_F(TpuGroupInfoTest, FoldsPerCoreMemoryOntoDutyCycleChips) {
  // Second host of a 2x2x2 slice on a 2-core chip: duty cycle uses global
  // chip ids 4-7, memory uses global core ids 8-15, and host-side metrics
  // use local ids 0-3.
  std::string exposition;
  for (int chip = 4; chip < 8; ++chip) {
    exposition += promLine("duty_cycle", chip, 10.0 * chip);
    exposition += promLine("memory_total", 2 * chip, 100.0);
    exposition += promLine("memory_total", 2 * chip + 1, 100.0);
    exposition += promLine("memory_used", 2 * chip, 30.0);
    exposition += promLine("memory_used", 2 * chip + 1, 10.0);
  }
  for (int local = 0; local < 4; ++local) {
    exposition += promLine("tensorcore_utilization", local, 1.0);
    exposition += promLine("memory_bandwidth_utilization", local, 2.0);
  }

  updateFromExposition(exposition);

  const std::set<int64_t> expected = {0, 1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(deviceIds(logger_.records()), expected);
  const auto& chip4 = recordByDevice(logger_.records(), 4);
  EXPECT_DOUBLE_EQ(chip4.floats.at("accelerator_utilization"), 40.0);
  // (30 + 10) / (100 + 100) across the chip's two cores.
  EXPECT_NEAR(chip4.floats.at("memory_utilization"), 20.0, 0.01);
}

TEST_F(TpuGroupInfoTest, OmitsChipMemoryUtilizationWhenACoreIsUnpaired) {
  // Core 9 reports capacity but no usage, so chip 4's ratio would cover
  // only one of its two cores.
  const std::string exposition = promLine("duty_cycle", 4, 50.0) +
      promLine("memory_total", 8, 100.0) + promLine("memory_used", 8, 30.0) +
      promLine("memory_total", 9, 100.0);

  updateFromExposition(exposition);

  const auto& chip4 = recordByDevice(logger_.records(), 4);
  EXPECT_DOUBLE_EQ(chip4.floats.at("accelerator_utilization"), 50.0);
  EXPECT_EQ(chip4.floats.count("memory_utilization"), 0u);
}

TEST_F(TpuGroupInfoTest, KeepsMemoryOnDutyCycleIdsWhenReportedPerChip) {
  // Runtime reporting one device per chip: duty cycle and memory share the
  // same global chip ids.
  std::string exposition;
  for (const int chip : {250, 251, 254, 255}) {
    exposition += promLine("duty_cycle", chip, 50.0);
    exposition += promLine("memory_total", chip, 100.0);
    exposition += promLine("memory_used", chip, 25.0);
  }

  updateFromExposition(exposition);

  const std::set<int64_t> expected = {250, 251, 254, 255};
  EXPECT_EQ(deviceIds(logger_.records()), expected);
  EXPECT_NEAR(
      recordByDevice(logger_.records(), 254).floats.at("memory_utilization"),
      25.0,
      0.01);
}

TEST_F(TpuGroupInfoTest, DoesNotFoldMemoryIdsThatDoNotPairWithDutyCycleIds) {
  std::string exposition;
  for (const int chip : {4, 5}) {
    exposition += promLine("duty_cycle", chip, 50.0);
  }
  for (const int core : {8, 9, 12, 13}) {
    exposition += promLine("memory_total", core, 100.0);
    exposition += promLine("memory_used", core, 25.0);
  }

  updateFromExposition(exposition);

  const std::set<int64_t> expected = {4, 5, 8, 9, 12, 13};
  EXPECT_EQ(deviceIds(logger_.records()), expected);
}

TEST_F(TpuGroupInfoTest, DropsRowsWithoutMetrics) {
  const std::string exposition =
      promLine("duty_cycle", 4, 50.0) + promLine("memory_total", 3, 100.0);

  updateFromExposition(exposition);

  const std::set<int64_t> expected = {4};
  EXPECT_EQ(deviceIds(logger_.records()), expected);
}

TEST_F(TpuGroupInfoTest, AddsMappedNodeLabelsToEveryRow) {
  nodeLabels_ = {
      {"cloud.google.com/reservation-project", "test-reservation-project"},
      {"unmapped.example.com/label", "ignored"},
  };

  updateFromExposition(kProbeOutputTpu7x);

  for (const auto& record : logger_.records()) {
    EXPECT_EQ(
        record.strings.at("reservation_project"), "test-reservation-project");
    EXPECT_EQ(record.strings.count("unmapped.example.com/label"), 0u);
  }
}

TEST_F(TpuGroupInfoTest, ReportsPartitionForWorkloadSliceShape) {
  // The workload on chips 4-5 runs on a 2x2x2 slice while the node is
  // labelled with a 2x2x1 slice; unattributed chip 0 uses the node's shape.
  currentOwners_ = {metricPodIdentity()};
  lookupAttributes_ = {{"tpu_topology", "2x2x2"}};
  nodeLabels_ = {
      {"cloud.google.com/gke-tpu-topology", "2x2x1"},
      {"cloud.google.com/gke-tpu-partition-2x2x1-id", "partition-221"},
      {"cloud.google.com/gke-tpu-partition-2x2x2-id", "partition-222"},
      {"cloud.google.com/gke-tpu-partition-2x2x2-state", "HEALTHY"},
  };

  updateFromExposition(kProbeOutputTpu7x);

  const auto& attributed = recordByDevice(logger_.records(), 4);
  EXPECT_EQ(attributed.strings.at("tpu_partition_id"), "partition-222");
  EXPECT_EQ(attributed.strings.at("tpu_partition_state"), "HEALTHY");
  const auto& unattributed = recordByDevice(logger_.records(), 0);
  EXPECT_EQ(unattributed.strings.at("tpu_partition_id"), "partition-221");
  EXPECT_EQ(unattributed.strings.count("tpu_partition_state"), 0u);
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

TEST(TpuNextAlignedTickTest, RoundsUpToTheNextIntervalBoundary) {
  using std::chrono::seconds;
  using std::chrono::system_clock;
  const system_clock::time_point midInterval{
      seconds(1003) + std::chrono::milliseconds(300)};
  const system_clock::time_point onBoundary{seconds(1010)};

  EXPECT_EQ(
      nextAlignedTick(midInterval, seconds(10)),
      system_clock::time_point{seconds(1010)});
  EXPECT_EQ(
      nextAlignedTick(onBoundary, seconds(10)),
      system_clock::time_point{seconds(1020)});
}

TEST(TpuNextAlignedTickTest, ReturnsNowForNonPositiveInterval) {
  const std::chrono::system_clock::time_point now{std::chrono::seconds(1003)};

  EXPECT_EQ(nextAlignedTick(now, std::chrono::seconds(0)), now);
}

TEST_F(TpuGroupInfoTest, LogStampsEveryRecordWithTheSampleTime) {
  const Logger::Timestamp sampleTime{std::chrono::seconds(1792000000)};

  info_->updateFromSamples(
      parsePrometheusText(kProbeOutputTpu7x), /*scrape_failed=*/false);
  info_->log(logger_, sampleTime);

  ASSERT_FALSE(logger_.records().empty());
  for (const auto& record : logger_.records()) {
    EXPECT_EQ(record.timestamp, sampleTime);
  }
}

} // namespace
} // namespace dynolog::tpumon
