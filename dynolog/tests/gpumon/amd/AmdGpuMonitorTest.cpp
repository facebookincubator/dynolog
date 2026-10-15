/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/amd/AmdGpuMonitor.h"

#include <gtest/gtest.h>

#include <cstdlib>
#include <filesystem>
#include <memory>
#include <numeric>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "dynolog/src/Logger.h"
#include "dynolog/src/gpumon/amd/AmdRdcCollector.h"

namespace dynolog::gpumon {
namespace {

constexpr char kModelName[] = "AMD Instinct MI300X OAM";
constexpr int64_t kMiB = 1024 * 1024;

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

 private:
  CapturedRecord current_;
  std::vector<CapturedRecord> records_;
};

class FakeAmdSmi : public AmdSmiWrapper {
 public:
  void init() override {}
  bool isInitialized() const override {
    return true;
  }
  std::string getModelName() override {
    return kModelName;
  }
  std::map<AmdSmiNodeId, AmdSmiMetrics> getMetrics() override {
    if (fail) {
      throw std::runtime_error("amdsmi_get_gpu_metrics_info() failed");
    }
    return metrics;
  }

  std::map<AmdSmiNodeId, AmdSmiMetrics> metrics;
  bool fail = false;
};

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

// A GPU whose logical devices are `nodeIds`; node N has KFD gpu_id 1000 + N
// and render minor 176 + N.
std::shared_ptr<amdgpu::PhysicalDevice> makeGpu(
    int oamId,
    const std::vector<uint32_t>& nodeIds) {
  auto gpu = std::make_shared<amdgpu::PhysicalDevice>(
      /*uniqueId=*/oamId, /*pciAddr=*/"", oamId, /*minorId=*/0);
  for (auto nodeId : nodeIds) {
    gpu->addLogicalDevice(
        std::make_shared<amdgpu::LogicalDevice>(
            nodeId,
            /*uniqueId=*/oamId,
            /*minorId=*/176 + static_cast<int>(nodeId),
            /*kfdGpuId=*/1000 + nodeId));
  }
  return gpu;
}

AmdSmiMetrics makeMetrics(
    AmdSmiNodeId nodeId,
    uint32_t oamId,
    uint32_t partitionId,
    int utilPercent) {
  AmdSmiMetrics m;
  m.kfd_id = 1000 + nodeId;
  m.oam_id = oamId;
  m.partition_id = partitionId;
  m.node_id = nodeId;
  m.gpu_util_percent = utilPercent;
  m.vram_total_bytes = 196592 * kMiB;
  m.vram_used_bytes = 283 * kMiB;
  m.current_socket_power_watt = 148;
  m.power_limit_watt = 750;
  m.pcie_bandwidth_megabits_per_sec = 400;
  m.pcie_max_link_speed_mts = 32000;
  m.pcie_max_link_width = 16;
  m.gpu_frequency_mhz = 2100;
  m.temperature_hotspot_c = 50;
  return m;
}

std::vector<CapturedRecord> updateAndLog(AmdGpuMonitor& monitor) {
  monitor.update();
  RecordingLogger logger;
  monitor.log(logger);
  return logger.records();
}

std::filesystem::path testRoot() {
  const char* root = std::getenv("TESTROOT");
  return root ? std::filesystem::path(root) : std::filesystem::path();
}

TEST(AmdGpuMonitorTest, amdSmiMetricsWithSysfsIds) {
  auto amdSmi = std::make_shared<FakeAmdSmi>();
  amdSmi->metrics = {
      {2, makeMetrics(2, /*oamId=*/0, /*partitionId=*/0, /*utilPercent=*/40)},
      {3, makeMetrics(3, /*oamId=*/1, /*partitionId=*/0, /*utilPercent=*/60)},
  };
  AmdGpuMonitor monitor(
      {makeGpu(0, {2}), makeGpu(1, {3})}, amdSmi, /*rdc=*/nullptr);

  const auto records = updateAndLog(monitor);

  ASSERT_EQ(records.size(), 2);
  const auto& record = recordByDevice(records, 2);
  const std::unordered_map<std::string, int64_t> expectedInts{
      {"gpu_device_utilization", 40},
      {"gpu_frequency_mhz", 2100},
      {"gpu_memory_total_bytes", 196592 * kMiB},
      {"gpu_memory_used_bytes", 283 * kMiB},
      {"gpu_temperature_hotspot_c", 50},
      {"kfd_id", 1002},
      {"minor_id", 178},
      {"oam_id", 0},
      {"partition_id", 0},
      {"device", 2},
  };
  // 400 Mb/s is 50,000,000 bytes/s.
  const std::unordered_map<std::string, double> expectedFloats{
      {"gpu_power_draw", 148},
      {"gpu_power_limit", 750},
      {"pcie_total_bytes", 50'000'000},
  };
  const std::unordered_map<std::string, std::string> expectedStrings{
      {"gpu_name", kModelName},
  };
  EXPECT_EQ(record.ints, expectedInts);
  EXPECT_EQ(record.floats, expectedFloats);
  EXPECT_EQ(record.strings, expectedStrings);
  EXPECT_EQ(recordByDevice(records, 3).ints.at("gpu_device_utilization"), 60);
}

TEST(AmdGpuMonitorTest, partitionsShareGpuValuesButKeepTheirOwnIds) {
  auto amdSmi = std::make_shared<FakeAmdSmi>();
  amdSmi->metrics = {
      {4, makeMetrics(4, /*oamId=*/3, /*partitionId=*/0, /*utilPercent=*/10)},
      {5, makeMetrics(5, /*oamId=*/3, /*partitionId=*/1, /*utilPercent=*/90)},
  };
  AmdGpuMonitor monitor({makeGpu(3, {4, 5})}, amdSmi, /*rdc=*/nullptr);

  const auto records = updateAndLog(monitor);

  ASSERT_EQ(records.size(), 2);
  const auto& p0 = recordByDevice(records, 4);
  const auto& p1 = recordByDevice(records, 5);
  EXPECT_EQ(p0.ints.at("oam_id"), 3);
  EXPECT_EQ(p1.ints.at("oam_id"), 3);
  EXPECT_EQ(p0.ints.at("partition_id"), 0);
  EXPECT_EQ(p1.ints.at("partition_id"), 1);
  EXPECT_EQ(p0.ints.at("gpu_device_utilization"), 10);
  EXPECT_EQ(p1.ints.at("gpu_device_utilization"), 90);
  EXPECT_EQ(p0.floats, p1.floats);
}

TEST(AmdGpuMonitorTest, devicesWithoutMetricsAreNotLogged) {
  AmdSmiMetrics idsOnly;
  idsOnly.oam_id = 1;
  idsOnly.partition_id = 0;
  auto amdSmi = std::make_shared<FakeAmdSmi>();
  amdSmi->metrics = {{2, makeMetrics(2, 0, 0, 40)}, {3, idsOnly}};
  AmdGpuMonitor monitor(
      {makeGpu(0, {2}), makeGpu(1, {3}), makeGpu(2, {7})},
      amdSmi,
      /*rdc=*/nullptr);

  const auto records = updateAndLog(monitor);

  ASSERT_EQ(records.size(), 1);
  EXPECT_EQ(records[0].ints.at("device"), 2);
}

TEST(AmdGpuMonitorTest, failedUpdateDropsStaleMetrics) {
  auto amdSmi = std::make_shared<FakeAmdSmi>();
  amdSmi->metrics = {{2, makeMetrics(2, 0, 0, 40)}};
  AmdGpuMonitor monitor({makeGpu(0, {2})}, amdSmi, /*rdc=*/nullptr);
  EXPECT_EQ(updateAndLog(monitor).size(), 1);
  EXPECT_FALSE(monitor.isFailing());

  amdSmi->fail = true;
  EXPECT_TRUE(updateAndLog(monitor).empty());
  EXPECT_TRUE(monitor.isFailing());
}

// Serves whole-GPU RDC entities without starting RDC; entity ids are positions
// in `devices`.
class FakeRdcWrapper : public RdcWrapper {
 public:
  explicit FakeRdcWrapper(std::vector<RdcMetricsMap> devices)
      : devices_(std::move(devices)) {}

  RdcMetricsMap getRdcMetricsForDevice(uint32_t device) override {
    return devices_.at(device);
  }
  std::vector<uint32_t> getMonitoredDeviceEntities() override {
    std::vector<uint32_t> ids(devices_.size());
    std::iota(ids.begin(), ids.end(), 0);
    return ids;
  }
  std::vector<uint32_t> getMonitoredPartitionsEntities() override {
    return {};
  }

 private:
  std::vector<RdcMetricsMap> devices_;
};

std::shared_ptr<AmdRdcCollector> fakeRdc(std::vector<RdcMetricsMap> devices) {
  return std::make_shared<AmdRdcCollector>(
      std::make_shared<FakeRdcWrapper>(std::move(devices)));
}

TEST(AmdGpuMonitorTest, rdcAddsProfilingMetricsAndFillsGapsInAmdSmi) {
  auto metrics = makeMetrics(2, 0, 0, 40);
  metrics.gpu_util_percent = -1;
  metrics.current_socket_power_watt = -1;
  auto amdSmi = std::make_shared<FakeAmdSmi>();
  amdSmi->metrics = {{2, metrics}};
  auto rdc = fakeRdc({{
      {RDC_FI_OAM_ID, int64_t{0}},
      {RDC_FI_GPU_UTIL, int64_t{30}},
      {RDC_FI_POWER_USAGE, int64_t{200'000'000}},
      {RDC_FI_PCIE_BANDWIDTH, int64_t{800}},
      {RDC_FI_PROF_OCCUPANCY_PERCENT, 25.0},
      {RDC_FI_PROF_EVAL_MEM_R_BW, 3e6},
      {RDC_FI_PROF_EVAL_MEM_W_BW, 1e6},
  }});
  AmdGpuMonitor monitor({makeGpu(0, {2})}, amdSmi, rdc);

  const auto records = updateAndLog(monitor);

  ASSERT_EQ(records.size(), 1);
  const auto& r = records[0];
  // amd-smi had no util or power, so RDC's are used (200,000,000 uW = 200 W).
  EXPECT_EQ(r.ints.at("gpu_device_utilization"), 30);
  EXPECT_EQ(r.floats.at("gpu_power_draw"), 200);
  // amd-smi's PCIe bandwidth wins over RDC's 800 Mb/s.
  EXPECT_EQ(r.floats.at("pcie_total_bytes"), 50'000'000);
  EXPECT_EQ(r.floats.at("sm_occupancy"), 0.25);
  EXPECT_EQ(r.floats.at("hbm_read_bytes"), 3e9);
  EXPECT_EQ(r.floats.at("hbm_write_bytes"), 1e9);
  // 4 GB/s of HBM traffic out of the MI300X's 5.3 TB/s peak.
  EXPECT_FLOAT_EQ(r.floats.at("hbm_mem_bw_util"), 4e9 / 5.3e12);
}

TEST(AmdGpuMonitorTest, rdcOnlyWithoutAmdSmi) {
  auto rdc = fakeRdc({{
      {RDC_FI_OAM_ID, int64_t{0}},
      {RDC_FI_GPU_UTIL, int64_t{30}},
  }});
  AmdGpuMonitor monitor({makeGpu(0, {2})}, /*amdSmi=*/nullptr, rdc);

  const auto records = updateAndLog(monitor);

  ASSERT_EQ(records.size(), 1);
  const std::unordered_map<std::string, int64_t> expectedInts{
      {"gpu_device_utilization", 30},
      {"kfd_id", 1002},
      {"minor_id", 178},
      {"oam_id", 0},
      {"device", 2},
  };
  EXPECT_EQ(records[0].ints, expectedInts);
  EXPECT_TRUE(records[0].strings.empty());
}

TEST(AmdGpuMonitorTest, detectsAmdGpusFromSysfs) {
  ASSERT_FALSE(testRoot().empty()) << "TESTROOT is not set";
  EXPECT_TRUE(AmdGpuMonitor::hostHasAmdGpus(testRoot()));
  EXPECT_FALSE(AmdGpuMonitor::hostHasAmdGpus(testRoot() / "does_not_exist"));
}

} // namespace
} // namespace dynolog::gpumon
