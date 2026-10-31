/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/amd/AmdRdcCollector.h"

#include <gtest/gtest.h>

#include <chrono>
#include <map>
#include <memory>
#include <utility>
#include <vector>

namespace dynolog::gpumon {
namespace {

using namespace std::chrono_literals;

struct RdcEntity {
  bool isPartition = false;
  RdcMetricsMap metrics;
};

// Serves fixed RDC entities without starting RDC; entity ids are positions in
// `entities`.
class FakeRdcWrapper : public RdcWrapper {
 public:
  explicit FakeRdcWrapper(std::vector<RdcEntity> entities)
      : entities(std::move(entities)) {}

  RdcMetricsMap getRdcMetricsForDevice(uint32_t device) override {
    return entities.at(device).metrics;
  }
  std::vector<uint32_t> getMonitoredDeviceEntities() override {
    return idsWhere(/*isPartition=*/false);
  }
  std::vector<uint32_t> getMonitoredPartitionsEntities() override {
    return idsWhere(/*isPartition=*/true);
  }

  std::vector<RdcEntity> entities;

 private:
  std::vector<uint32_t> idsWhere(bool isPartition) const {
    std::vector<uint32_t> ids;
    for (uint32_t i = 0; i < entities.size(); i++) {
      if (entities[i].isPartition == isPartition) {
        ids.push_back(i);
      }
    }
    return ids;
  }
};

// A GPU with one logical device per (KFD node id, KFD gpu_id) pair.
std::shared_ptr<amdgpu::PhysicalDevice> makeGpu(
    int oamId,
    const std::vector<std::pair<uint32_t, uint64_t>>& nodeAndKfdIds) {
  auto gpu = std::make_shared<amdgpu::PhysicalDevice>(
      /*uniqueId=*/oamId, /*pciAddr=*/"", oamId, /*minorId=*/0);
  for (const auto& [nodeId, kfdId] : nodeAndKfdIds) {
    gpu->addLogicalDevice(
        std::make_shared<amdgpu::LogicalDevice>(
            nodeId, /*uniqueId=*/oamId, /*minorId=*/0, kfdId));
  }
  return gpu;
}

RdcEntity rdcDevice(int64_t oamId, RdcMetricsMap metrics) {
  metrics[RDC_FI_OAM_ID] = oamId;
  return {.isPartition = false, .metrics = std::move(metrics)};
}

RdcEntity rdcPartition(int64_t kfdId, RdcMetricsMap metrics) {
  metrics[kRdcKfdIdField] = kfdId;
  return {.isPartition = true, .metrics = std::move(metrics)};
}

RdcMetricsMap xgmiTotals(int64_t rxKbPerLink, int64_t txKbPerLink) {
  RdcMetricsMap m;
  for (auto field :
       {RDC_FI_XGMI_0_READ_KB,
        RDC_FI_XGMI_1_READ_KB,
        RDC_FI_XGMI_2_READ_KB,
        RDC_FI_XGMI_3_READ_KB,
        RDC_FI_XGMI_4_READ_KB,
        RDC_FI_XGMI_5_READ_KB,
        RDC_FI_XGMI_6_READ_KB,
        RDC_FI_XGMI_7_READ_KB}) {
    m[field] = rxKbPerLink;
  }
  for (auto field :
       {RDC_FI_XGMI_0_WRITE_KB,
        RDC_FI_XGMI_1_WRITE_KB,
        RDC_FI_XGMI_2_WRITE_KB,
        RDC_FI_XGMI_3_WRITE_KB,
        RDC_FI_XGMI_4_WRITE_KB,
        RDC_FI_XGMI_5_WRITE_KB,
        RDC_FI_XGMI_6_WRITE_KB,
        RDC_FI_XGMI_7_WRITE_KB}) {
    m[field] = txKbPerLink;
  }
  return m;
}

const auto kNow = std::chrono::steady_clock::time_point(100s);

TEST(AmdRdcCollectorTest, unpartitionedGpuMatchesRdcDeviceByOamId) {
  AmdRdcCollector collector(
      std::make_shared<FakeRdcWrapper>(std::vector<RdcEntity>{rdcDevice(
          5,
          {
              {RDC_FI_GPU_UTIL, int64_t{40}},
              {RDC_FI_POWER_USAGE, int64_t{350'000'000}},
              {RDC_FI_PCIE_BANDWIDTH, int64_t{800}},
              {RDC_FI_PROF_OCCUPANCY_PERCENT, 25.0},
              {RDC_FI_PROF_ACTIVE_CYCLES, 30.0},
              {RDC_FI_PROF_ELAPSED_CYCLES, 120.0},
              {RDC_FI_PROF_EVAL_FLOPS_16, 4e12},
              {RDC_FI_PROF_EVAL_FLOPS_32, 2e12},
              {RDC_FI_PROF_EVAL_FLOPS_64, 1e12},
              {RDC_FI_PROF_EVAL_MEM_R_BW, 3e6},
              {RDC_FI_PROF_EVAL_MEM_W_BW, 1e6},
          })}));

  const auto res = collector.collect({makeGpu(/*oamId=*/5, {{2, 111}})}, kNow);

  // 25% occupancy is a 0.25 ratio and 30 of 120 cycles active is 0.25. RDC
  // reports power in uW, PCIe in Mb/s and memory bandwidth in KB/s.
  ASSERT_EQ(res.size(), 1);
  const auto& m = res.at(2);
  EXPECT_EQ(m.occupancyRatio, 0.25);
  EXPECT_EQ(m.activeCyclesRatio, 0.25);
  EXPECT_EQ(m.fp16FlopsPerSec, 4e12);
  EXPECT_EQ(m.fp32FlopsPerSec, 2e12);
  EXPECT_EQ(m.fp64FlopsPerSec, 1e12);
  EXPECT_EQ(m.gpuUtilPercent, 40);
  EXPECT_EQ(m.powerWatts, 350);
  EXPECT_EQ(m.pcieBytesPerSec, 100'000'000);
  EXPECT_EQ(m.hbmReadBytesPerSec, 3e9);
  EXPECT_EQ(m.hbmWriteBytesPerSec, 1e9);
}

TEST(AmdRdcCollectorTest, partitionsUseTheirOwnComputeAndTheGpuBandwidth) {
  AmdRdcCollector collector(
      std::make_shared<FakeRdcWrapper>(std::vector<RdcEntity>{
          rdcDevice(
              3,
              {{RDC_FI_PROF_OCCUPANCY_PERCENT, 99.0},
               {RDC_FI_GPU_UTIL, int64_t{99}},
               {RDC_FI_PROF_EVAL_MEM_R_BW, 5e6}}),
          rdcPartition(101, {{RDC_FI_PROF_OCCUPANCY_PERCENT, 10.0}}),
          rdcPartition(102, {{RDC_FI_PROF_OCCUPANCY_PERCENT, 20.0}}),
      }));

  const auto res =
      collector.collect({makeGpu(/*oamId=*/3, {{4, 101}, {5, 102}})}, kNow);

  // The whole-GPU occupancy and util must not leak into the partitions.
  EXPECT_EQ(res.at(4).occupancyRatio, 0.10);
  EXPECT_EQ(res.at(5).occupancyRatio, 0.20);
  EXPECT_FALSE(res.at(4).gpuUtilPercent.has_value());
  EXPECT_EQ(res.at(4).hbmReadBytesPerSec, 5e9);
  EXPECT_EQ(res.at(5).hbmReadBytesPerSec, 5e9);
}

TEST(AmdRdcCollectorTest, xgmiRateIsComputedFromAccumulatedCounters) {
  auto rdc = std::make_shared<FakeRdcWrapper>(
      std::vector<RdcEntity>{rdcDevice(0, xgmiTotals(100, 50))});
  AmdRdcCollector collector(rdc);
  const std::vector<std::shared_ptr<amdgpu::PhysicalDevice>> gpus{
      makeGpu(0, {{2, 111}})};

  EXPECT_FALSE(collector.collect(gpus, kNow).at(2).xgmiRxBytesPerSec);

  // Each of 8 links moved 1250 KB rx and 250 KB tx in 10s.
  rdc->entities = {rdcDevice(0, xgmiTotals(1350, 300))};
  const auto res = collector.collect(gpus, kNow + 10s);
  EXPECT_EQ(res.at(2).xgmiRxBytesPerSec, 1'000'000);
  EXPECT_EQ(res.at(2).xgmiTxBytesPerSec, 200'000);

  rdc->entities = {rdcDevice(0, xgmiTotals(10, 10))};
  EXPECT_FALSE(collector.collect(gpus, kNow + 20s).at(2).xgmiRxBytesPerSec);
}

TEST(AmdRdcCollectorTest, devicesWithoutRdcDataAreOmitted) {
  AmdRdcCollector collector(
      std::make_shared<FakeRdcWrapper>(std::vector<RdcEntity>{
          rdcDevice(7, {{RDC_FI_PROF_OCCUPANCY_PERCENT, 50.0}})}));

  const auto res = collector.collect({makeGpu(0, {{2, 111}})}, kNow);

  EXPECT_TRUE(res.empty());
}

TEST(AmdRdcCollectorTest, nonIntegerIdsAreIgnored) {
  RdcMetricsMap device{
      {RDC_FI_OAM_ID, 0.0}, {RDC_FI_PROF_OCCUPANCY_PERCENT, 50.0}};
  AmdRdcCollector collector(
      std::make_shared<FakeRdcWrapper>(
          std::vector<RdcEntity>{{.isPartition = false, .metrics = device}}));

  EXPECT_TRUE(collector.collect({makeGpu(0, {{2, 111}})}, kNow).empty());
}

} // namespace
} // namespace dynolog::gpumon
