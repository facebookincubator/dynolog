/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <chrono>
#include <map>
#include <memory>
#include <optional>
#include <vector>

#include "dynolog/src/gpumon/amd/AmdDeviceTopology.h"
#include "dynolog/src/gpumon/amd/RdcWrapper.h"

namespace dynolog::gpumon {

// RDC metrics for one logical device
// report the value.
struct AmdRdcMetrics {
  // Per partition on partitioned GPUs.
  std::optional<double> occupancyRatio;
  std::optional<double> activeCyclesRatio;
  std::optional<double> simdUtilization;
  std::optional<double> fp16FlopsPerSec;
  std::optional<double> fp32FlopsPerSec;
  std::optional<double> fp64FlopsPerSec;
  // RDC only reports busy percent for whole GPUs, so this is unset on
  // partitions.
  std::optional<double> gpuUtilPercent;
  // GPU-wide, repeated on every partition.
  std::optional<double> hbmReadBytesPerSec;
  std::optional<double> hbmWriteBytesPerSec;
  std::optional<double> xgmiRxBytesPerSec;
  std::optional<double> xgmiTxBytesPerSec;
  std::optional<double> powerWatts;
  std::optional<double> pcieBytesPerSec;
};

// Collects AMD RDC metrics and matches them to the logical devices found in
// sysfs. Partitions of a partitioned GPU are matched to RDC partition entities
// by KFD id; unpartitioned GPUs are matched to RDC device entities by OAM id,
// since RDC's KFD id is unreliable for physical devices on some platforms
// (MI350X).
class AmdRdcCollector {
 public:
  // Starts RDC in embedded mode. Returns nullptr on failure, except that
  // loading RDC's libraries aborts the process if RDC can't initialize
  // amd-smi.
  static std::shared_ptr<AmdRdcCollector> factory(
      std::chrono::milliseconds updateInterval);

  // Uses an already started RDC.
  explicit AmdRdcCollector(std::shared_ptr<RdcWrapper> rdc);

  // Metrics for each logical device of `gpus`, keyed by KFD node id. Devices
  // RDC has no data for are omitted.
  std::map<uint32_t, AmdRdcMetrics> collect(
      const std::vector<std::shared_ptr<amdgpu::PhysicalDevice>>& gpus,
      std::chrono::steady_clock::time_point now);

 private:
  struct XgmiTotals {
    std::chrono::steady_clock::time_point time;
    double rxKb = 0;
    double txKb = 0;
  };

  void addXgmiRates(
      int oamId,
      const RdcMetricsMap& metrics,
      std::chrono::steady_clock::time_point now,
      AmdRdcMetrics& out);

  const std::shared_ptr<RdcWrapper> rdc_;
  // RDC entity ids of whole GPUs, and of partitions on partitioned GPUs.
  const std::vector<uint32_t> deviceEntities_;
  const std::vector<uint32_t> partitionEntities_;
  std::map<int, XgmiTotals> lastXgmi_;
};

} // namespace dynolog::gpumon
