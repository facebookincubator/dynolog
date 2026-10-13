/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <chrono>
#include <cstdint>
#include <filesystem>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <thread>
#include <vector>

#include "dynolog/src/Logger.h"
#include "dynolog/src/gpumon/amd/AmdDeviceTopology.h"
#include "dynolog/src/gpumon/amd/AmdSmiWrapper.h"

namespace dynolog::gpumon {

class AmdRdcCollector;

// AMD counterpart to DcgmGroupInfo. Collects every logical device from KFD
// and PCI sysfs, amd-smi and RDC, and merges them into one record per device,
// with `device` set to its KFD node id. When both libraries report a metric,
// amd-smi is used and RDC is the fallback.
class AmdGpuMonitor {
 public:
  // Uses the given sources; a null library source is skipped. Use factory() to
  // initialize the sources from the host.
  AmdGpuMonitor(
      std::vector<std::shared_ptr<amdgpu::PhysicalDevice>> gpus,
      std::shared_ptr<AmdSmiWrapper> amdSmi,
      std::shared_ptr<AmdRdcCollector> rdc);
  ~AmdGpuMonitor();
  AmdGpuMonitor(const AmdGpuMonitor&) = delete;
  AmdGpuMonitor& operator=(const AmdGpuMonitor&) = delete;
  AmdGpuMonitor(AmdGpuMonitor&&) = delete;
  AmdGpuMonitor& operator=(AmdGpuMonitor&&) = delete;

  // Initializes sysfs, amd-smi, then RDC (with --enable_amd_rdc), skipping any
  // library that fails. Returns nullptr if sysfs has no AMD GPUs or neither
  // library initialized.
  static std::shared_ptr<AmdGpuMonitor> factory(
      const std::filesystem::path& sysfsRoot = "/");

  static bool hostHasAmdGpus(const std::filesystem::path& sysfsRoot = "/");

  // Runs update() and log() every `interval` on a new thread, forever.
  static std::unique_ptr<std::thread> startMonitoring(
      std::shared_ptr<AmdGpuMonitor> monitor,
      std::unique_ptr<Logger> logger,
      std::chrono::seconds interval);

  void update();
  void log(Logger& logger) const;

  // True if no initialized source could be read in the last update().
  bool isFailing() const {
    return failing_;
  }

 private:
  struct Record {
    std::map<std::string, int64_t> ints;
    std::map<std::string, double> floats;
  };

  // GPUs and their logical devices from KFD/PCI sysfs; always present.
  const std::vector<std::shared_ptr<amdgpu::PhysicalDevice>> gpus_;
  // Library sources; null if they failed to initialize.
  const std::shared_ptr<AmdSmiWrapper> amdSmi_;
  const std::shared_ptr<AmdRdcCollector> rdc_;
  std::string modelName_;
  std::optional<double> hbmPeakBytesPerSec_;
  bool failing_ = false;
  std::map<uint32_t, Record> records_;
};

} // namespace dynolog::gpumon
