/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/amd/AmdRdcCollector.h"

#include <dlfcn.h>
#include <glog/logging.h>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <utility>
#include <variant>

namespace dynolog::gpumon {

namespace {

constexpr int kMaxKeepSamples = 2;
// RDC reports memory bandwidth in KB/s and XGMI traffic in KB.
constexpr double kBytesPerKb = 1000;
constexpr double kMicroPerUnit = 1e6;
constexpr double kBytesPerMegabit = 1e6 / 8;

std::vector<rdc_field_t> enabledFields() {
  return {
      RDC_FI_OAM_ID,
      RDC_FI_GPU_UTIL,
      RDC_FI_POWER_USAGE,
      RDC_FI_PCIE_BANDWIDTH,
      RDC_FI_PROF_OCCUPANCY_PERCENT,
      RDC_FI_PROF_ACTIVE_CYCLES,
      RDC_FI_PROF_ELAPSED_CYCLES,
      RDC_FI_PROF_EVAL_MEM_R_BW,
      RDC_FI_PROF_EVAL_MEM_W_BW,
      RDC_FI_PROF_EVAL_FLOPS_16,
      RDC_FI_PROF_EVAL_FLOPS_32,
      RDC_FI_PROF_EVAL_FLOPS_64,
      RDC_FI_XGMI_0_READ_KB,
      RDC_FI_XGMI_1_READ_KB,
      RDC_FI_XGMI_2_READ_KB,
      RDC_FI_XGMI_3_READ_KB,
      RDC_FI_XGMI_4_READ_KB,
      RDC_FI_XGMI_5_READ_KB,
      RDC_FI_XGMI_6_READ_KB,
      RDC_FI_XGMI_7_READ_KB,
      RDC_FI_XGMI_0_WRITE_KB,
      RDC_FI_XGMI_1_WRITE_KB,
      RDC_FI_XGMI_2_WRITE_KB,
      RDC_FI_XGMI_3_WRITE_KB,
      RDC_FI_XGMI_4_WRITE_KB,
      RDC_FI_XGMI_5_WRITE_KB,
      RDC_FI_XGMI_6_WRITE_KB,
      RDC_FI_XGMI_7_WRITE_KB,
      RDC_FI_PROF_SIMD_UTILIZATION,
      kRdcKfdIdField,
  };
}

constexpr std::array<rdc_field_t, 8> kXgmiReadFields = {
    RDC_FI_XGMI_0_READ_KB,
    RDC_FI_XGMI_1_READ_KB,
    RDC_FI_XGMI_2_READ_KB,
    RDC_FI_XGMI_3_READ_KB,
    RDC_FI_XGMI_4_READ_KB,
    RDC_FI_XGMI_5_READ_KB,
    RDC_FI_XGMI_6_READ_KB,
    RDC_FI_XGMI_7_READ_KB,
};
constexpr std::array<rdc_field_t, 8> kXgmiWriteFields = {
    RDC_FI_XGMI_0_WRITE_KB,
    RDC_FI_XGMI_1_WRITE_KB,
    RDC_FI_XGMI_2_WRITE_KB,
    RDC_FI_XGMI_3_WRITE_KB,
    RDC_FI_XGMI_4_WRITE_KB,
    RDC_FI_XGMI_5_WRITE_KB,
    RDC_FI_XGMI_6_WRITE_KB,
    RDC_FI_XGMI_7_WRITE_KB,
};

std::optional<double> getValue(
    const RdcMetricsMap& metrics,
    rdc_field_t field) {
  const auto it = metrics.find(field);
  if (it == metrics.end()) {
    return std::nullopt;
  }
  return std::visit(
      [](auto value) { return static_cast<double>(value); }, it->second);
}

// RDC reports ids as integers; anything else is treated as missing.
std::optional<int64_t> getId(const RdcMetricsMap& metrics, rdc_field_t field) {
  const auto it = metrics.find(field);
  if (it == metrics.end()) {
    return std::nullopt;
  }
  if (const auto* id = std::get_if<int64_t>(&it->second)) {
    return *id;
  }
  return std::nullopt;
}

// Sum of all XGMI link counters; nullopt unless every link reported.
template <size_t N>
std::optional<double> sumLinks(
    const RdcMetricsMap& metrics,
    const std::array<rdc_field_t, N>& fields) {
  double total = 0;
  for (auto field : fields) {
    const auto value = getValue(metrics, field);
    if (!value.has_value() || *value < 0) {
      return std::nullopt;
    }
    total += *value;
  }
  return total;
}

// Metrics RDC reports for both devices and partition instances, except GPU
// util which it only reports for devices.
void addComputeMetrics(const RdcMetricsMap& metrics, AmdRdcMetrics& out) {
  if (const auto v = getValue(metrics, RDC_FI_PROF_OCCUPANCY_PERCENT)) {
    out.occupancyRatio = *v / 100;
  }
  const auto active = getValue(metrics, RDC_FI_PROF_ACTIVE_CYCLES);
  const auto elapsed = getValue(metrics, RDC_FI_PROF_ELAPSED_CYCLES);
  if (active.has_value() && elapsed.has_value() && *elapsed > 0) {
    out.activeCyclesRatio = *active / *elapsed;
  }
  out.simdUtilization = getValue(metrics, RDC_FI_PROF_SIMD_UTILIZATION);
  out.fp16FlopsPerSec = getValue(metrics, RDC_FI_PROF_EVAL_FLOPS_16);
  out.fp32FlopsPerSec = getValue(metrics, RDC_FI_PROF_EVAL_FLOPS_32);
  out.fp64FlopsPerSec = getValue(metrics, RDC_FI_PROF_EVAL_FLOPS_64);
  out.gpuUtilPercent = getValue(metrics, RDC_FI_GPU_UTIL);
}

// Metrics RDC only reports for devices, not partition instances.
void addDeviceMetrics(const RdcMetricsMap& metrics, AmdRdcMetrics& out) {
  if (const auto v = getValue(metrics, RDC_FI_PROF_EVAL_MEM_R_BW)) {
    out.hbmReadBytesPerSec = *v * kBytesPerKb;
  }
  if (const auto v = getValue(metrics, RDC_FI_PROF_EVAL_MEM_W_BW)) {
    out.hbmWriteBytesPerSec = *v * kBytesPerKb;
  }
  if (const auto v = getValue(metrics, RDC_FI_POWER_USAGE)) {
    out.powerWatts = *v / kMicroPerUnit;
  }
  if (const auto v = getValue(metrics, RDC_FI_PCIE_BANDWIDTH)) {
    out.pcieBytesPerSec = *v * kBytesPerMegabit;
  }
}

// RDC's profiler and validation plugins fail to resolve their dependencies
// unless they are loaded globally before RDC starts.
void preloadRocmLibs() {
  const char* rocmHome = std::getenv("ROCM_PATH");
  const std::filesystem::path rocmPath(rocmHome ? rocmHome : "/opt/rocm");
  // Some installs otherwise resolve this to <rocm>/lib/share/rocprofiler-sdk,
  // which doesn't exist and makes RDC crash on init.
  const auto metricsPath = rocmPath / "share" / "rocprofiler-sdk";
  if (std::getenv("ROCPROFILER_METRICS_PATH") == nullptr) {
    setenv("ROCPROFILER_METRICS_PATH", metricsPath.c_str(), 0);
  }
  for (const char* lib :
       {"lib/rdc/librdc_rocp.so",
        "lib/rdc/librdc_rvs.so",
        "lib/rdc/librdc_rocr.so"}) {
    const auto path = rocmPath / lib;
    if (dlopen(path.c_str(), RTLD_LAZY | RTLD_GLOBAL) == nullptr) {
      LOG(WARNING) << "Failed to preload " << path << ": " << dlerror();
    }
  }
}

} // namespace

AmdRdcCollector::AmdRdcCollector(std::shared_ptr<RdcWrapper> rdc)
    : rdc_(std::move(rdc)),
      deviceEntities_(rdc_->getMonitoredDeviceEntities()),
      partitionEntities_(rdc_->getMonitoredPartitionsEntities()) {
  LOG(INFO) << "RDC monitoring " << deviceEntities_.size() << " GPUs and "
            << partitionEntities_.size() << " partitions";
}

std::shared_ptr<AmdRdcCollector> AmdRdcCollector::factory(
    std::chrono::milliseconds updateInterval) {
  preloadRocmLibs();
  // Keep enough history for one sample to survive a missed refresh.
  const auto maxKeepAge = std::max(
      std::chrono::seconds(1),
      std::chrono::ceil<std::chrono::seconds>(updateInterval * 2));
  std::shared_ptr<RdcWrapper> wrapper;
  try {
    wrapper = std::make_shared<RdcWrapper>(
        enabledFields(), updateInterval, maxKeepAge, kMaxKeepSamples);
  } catch (const std::exception& e) {
    LOG(ERROR) << "Failed to initialize RDC: " << e.what();
    return nullptr;
  }
  return std::make_shared<AmdRdcCollector>(std::move(wrapper));
}

std::map<uint32_t, AmdRdcMetrics> AmdRdcCollector::collect(
    const std::vector<std::shared_ptr<amdgpu::PhysicalDevice>>& gpus,
    std::chrono::steady_clock::time_point now) {
  std::map<int64_t, RdcMetricsMap> deviceByOam;
  for (auto entity : deviceEntities_) {
    auto metrics = rdc_->getRdcMetricsForDevice(entity);
    if (const auto oam = getId(metrics, RDC_FI_OAM_ID)) {
      deviceByOam[*oam] = std::move(metrics);
    }
  }
  std::map<int64_t, RdcMetricsMap> partitionByKfd;
  for (auto entity : partitionEntities_) {
    auto metrics = rdc_->getRdcMetricsForDevice(entity);
    if (const auto kfd = getId(metrics, kRdcKfdIdField)) {
      partitionByKfd[*kfd] = std::move(metrics);
    }
  }

  std::map<uint32_t, AmdRdcMetrics> res;
  for (const auto& gpu : gpus) {
    const auto logicalDevices = gpu->getLogicalDevices();
    const auto deviceIt = deviceByOam.find(gpu->getOamId());
    const RdcMetricsMap* device =
        deviceIt == deviceByOam.end() ? nullptr : &deviceIt->second;

    // GPU-wide metrics, repeated on every partition of the GPU.
    AmdRdcMetrics gpuWide;
    if (device != nullptr) {
      addDeviceMetrics(*device, gpuWide);
      addXgmiRates(gpu->getOamId(), *device, now, gpuWide);
    }

    for (const auto& logical : logicalDevices) {
      const RdcMetricsMap* compute = device;
      if (logicalDevices.size() > 1) {
        const auto it =
            partitionByKfd.find(static_cast<int64_t>(logical->getKfdGpuId()));
        compute = it == partitionByKfd.end() ? nullptr : &it->second;
      }
      if (compute == nullptr && device == nullptr) {
        continue;
      }
      AmdRdcMetrics out = gpuWide;
      if (compute != nullptr) {
        addComputeMetrics(*compute, out);
      }
      res[logical->getKfdNodeId()] = out;
    }
  }
  return res;
}

void AmdRdcCollector::addXgmiRates(
    int oamId,
    const RdcMetricsMap& metrics,
    std::chrono::steady_clock::time_point now,
    AmdRdcMetrics& out) {
  const auto rxKb = sumLinks(metrics, kXgmiReadFields);
  const auto txKb = sumLinks(metrics, kXgmiWriteFields);
  if (!rxKb.has_value() || !txKb.has_value()) {
    return;
  }
  const auto prev = lastXgmi_.find(oamId);
  if (prev != lastXgmi_.end()) {
    const double seconds =
        std::chrono::duration<double>(now - prev->second.time).count();
    // Counters going backwards means a reset; skip the rate for this cycle.
    if (seconds > 0 && *rxKb >= prev->second.rxKb &&
        *txKb >= prev->second.txKb) {
      out.xgmiRxBytesPerSec =
          (*rxKb - prev->second.rxKb) * kBytesPerKb / seconds;
      out.xgmiTxBytesPerSec =
          (*txKb - prev->second.txKb) * kBytesPerKb / seconds;
    }
  }
  lastXgmi_[oamId] = {.time = now, .rxKb = *rxKb, .txKb = *txKb};
}

} // namespace dynolog::gpumon
