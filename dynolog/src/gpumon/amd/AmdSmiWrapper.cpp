/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/amd/AmdSmiWrapper.h"

#include <algorithm>
#include <cstring>
#include <stdexcept>

namespace dynolog {
namespace gpumon {

namespace {

void checkStatus(amdsmi_status_t status, const char* apiName) {
  if (status != AMDSMI_STATUS_SUCCESS) {
    throw std::runtime_error(
        std::string(apiName) + "() failed with status " +
        std::to_string(static_cast<int>(status)));
  }
}

constexpr int64_t kMissing = -1;
constexpr int64_t kMicroPerUnit = 1000000;

// amd-smi reports an unavailable unsigned field as its type's max.
template <typename T>
int64_t missingIfSentinel(T value) {
  return value == std::numeric_limits<T>::max() ? kMissing
                                                : static_cast<int64_t>(value);
}

// amd-smi documents max_pcie_speed in GT/s, but some versions report MT/s.
int64_t normalizePcieSpeedMts(int64_t speed) {
  return speed > 0 && speed < 1000 ? speed * 1000 : speed;
}

// Average of the valid per-XCC gfx_busy_inst of each XCP, keyed by XCP index.
std::map<size_t, int> getPerXcpGfxBusyInst(
    const amdsmi_gpu_metrics_t& gpuMetrics,
    size_t numPartitions) {
  std::map<size_t, int> res;
  for (size_t xcp = 0; xcp < numPartitions; xcp++) {
    int numXcc = 0, accUtil = 0;
    for (auto xcc = 0; xcc < AMDSMI_MAX_NUM_XCC; xcc++) {
      if (gpuMetrics.xcp_stats[xcp].gfx_busy_inst[xcc] !=
          std::numeric_limits<uint32_t>::max()) {
        numXcc++;
        accUtil += gpuMetrics.xcp_stats[xcp].gfx_busy_inst[xcc];
      }
    }
    if (numXcc > 0) {
      res[xcp] = accUtil / numXcc;
    }
  }
  return res;
}

// The physical-device readers below are best effort: a metric amd-smi cannot
// report stays at -1 instead of failing the whole collection.
void readVram(amdsmi_processor_handle handle, AmdSmiMetrics& metrics) {
  uint64_t total = 0;
  if (amdsmi_get_gpu_memory_total(handle, AMDSMI_MEM_TYPE_VRAM, &total) ==
      AMDSMI_STATUS_SUCCESS) {
    metrics.vram_total_bytes = missingIfSentinel(total);
  }
  uint64_t used = 0;
  if (amdsmi_get_gpu_memory_usage(handle, AMDSMI_MEM_TYPE_VRAM, &used) ==
      AMDSMI_STATUS_SUCCESS) {
    metrics.vram_used_bytes = missingIfSentinel(used);
  }
}

void readPower(amdsmi_processor_handle handle, AmdSmiMetrics& metrics) {
  amdsmi_power_info_t info{};
  if (amdsmi_get_power_info(handle, &info) != AMDSMI_STATUS_SUCCESS) {
    return;
  }
  metrics.current_socket_power_watt =
      missingIfSentinel(info.current_socket_power);
  // amdsmi.h documents power_limit in W, but amd-smi fills it from the hwmon
  // power cap, which is in uW.
  const int64_t powerLimitMicroWatt = missingIfSentinel(info.power_limit);
  if (powerLimitMicroWatt >= 0) {
    metrics.power_limit_watt = powerLimitMicroWatt / kMicroPerUnit;
  }
}

void readPcie(amdsmi_processor_handle handle, AmdSmiMetrics& metrics) {
  amdsmi_pcie_info_t info{};
  if (amdsmi_get_pcie_info(handle, &info) != AMDSMI_STATUS_SUCCESS) {
    return;
  }
  metrics.pcie_bandwidth_megabits_per_sec =
      missingIfSentinel(info.pcie_metric.pcie_bandwidth);
  metrics.pcie_max_link_speed_mts =
      normalizePcieSpeedMts(missingIfSentinel(info.pcie_static.max_pcie_speed));
  metrics.pcie_max_link_width =
      missingIfSentinel(info.pcie_static.max_pcie_width);
}

void readGpuFrequency(amdsmi_processor_handle handle, AmdSmiMetrics& metrics) {
  amdsmi_frequencies_t freq{};
  if (amdsmi_get_clk_freq(handle, AMDSMI_CLK_TYPE_SYS, &freq) !=
          AMDSMI_STATUS_SUCCESS ||
      freq.current >= AMDSMI_MAX_NUM_FREQUENCIES) {
    return;
  }
  // amdsmi_get_clk_freq reports Hz
  metrics.gpu_frequency_mhz =
      static_cast<int64_t>(freq.frequency[freq.current]) / kMicroPerUnit;
}

AmdSmiMetrics readPhysicalMetrics(
    amdsmi_processor_handle handle,
    const amdsmi_gpu_metrics_t& gpuMetrics) {
  AmdSmiMetrics metrics{};
  readVram(handle, metrics);
  readPower(handle, metrics);
  readPcie(handle, metrics);
  readGpuFrequency(handle, metrics);
  metrics.temperature_hotspot_c =
      missingIfSentinel(gpuMetrics.temperature_hotspot);
  return metrics;
}

struct PrimaryProcessor {
  amdsmi_processor_handle handle;
  uint32_t oamId;
};

// For partitioned GPUs, only the first partition has a valid OAM_ID, and
// device-level metrics are only readable through it.
PrimaryProcessor findPrimaryProcessor(
    const std::vector<amdsmi_processor_handle>& processorHandles) {
  for (auto processorHandle : processorHandles) {
    amdsmi_asic_info_t asicInfo{};
    checkStatus(
        amdsmi_get_gpu_asic_info(processorHandle, &asicInfo),
        "amdsmi_get_gpu_asic_info");
    if (asicInfo.oam_id != std::numeric_limits<uint32_t>::max()) {
      return {.handle = processorHandle, .oamId = asicInfo.oam_id};
    }
  }
  throw std::runtime_error("oamId is missing");
}

} // namespace

// check the AMD SMI API reference
// https://rocm.docs.amd.com/projects/amdsmi/en/latest/reference/amdsmi-cpp-api.html
// for more information

void AmdSmiWrapper::init() {
  std::lock_guard<std::mutex> lock(amdsmiMutex_);
  if (initialized_) {
    return;
  }
  checkStatus(amdsmi_init(AMDSMI_INIT_AMD_GPUS), "amdsmi_init");
  initialized_ = true;
}

bool AmdSmiWrapper::isInitialized() const {
  std::lock_guard<std::mutex> lock(amdsmiMutex_);
  return initialized_;
}

std::string AmdSmiWrapper::getModelName() {
  std::lock_guard<std::mutex> lock(amdsmiMutex_);
  auto socketHandles = getSocketHandles_();
  if (socketHandles.empty()) {
    throw std::runtime_error("No socket handles returned");
  }
  return getModelNameFromSocket_(socketHandles[0]);
}

std::map<AmdSmiNodeId, AmdSmiMetrics> AmdSmiWrapper::getMetrics() {
  std::lock_guard<std::mutex> lock(amdsmiMutex_);
  if (!initialized_) {
    throw std::runtime_error("amdsmi has not been initialized");
  }
  std::map<AmdSmiNodeId, AmdSmiMetrics> res;
  for (auto socketHandle : getSocketHandles_()) {
    res.merge(getMetricsFromSocket_(socketHandle));
  }
  return res;
}

std::vector<amdsmi_socket_handle> AmdSmiWrapper::getSocketHandles_() {
  uint32_t numDevices = 0;
  checkStatus(
      amdsmi_get_socket_handles(&numDevices, nullptr),
      "amdsmi_get_socket_handles");
  std::vector<amdsmi_socket_handle> socketHandles(numDevices);
  checkStatus(
      amdsmi_get_socket_handles(&numDevices, socketHandles.data()),
      "amdsmi_get_socket_handles");
  return socketHandles;
}

std::vector<amdsmi_processor_handle> AmdSmiWrapper::getProcessorHandles_(
    amdsmi_socket_handle socketHandle) {
  uint32_t numPartitions = AMDSMI_MAX_NUM_XCP;
  amdsmi_processor_handle processorHandles[AMDSMI_MAX_NUM_XCP];
  checkStatus(
      amdsmi_get_processor_handles(
          socketHandle, &numPartitions, processorHandles),
      "amdsmi_get_processor_handles");
  numPartitions = std::min<uint32_t>(numPartitions, AMDSMI_MAX_NUM_XCP);
  return std::vector<amdsmi_processor_handle>(
      processorHandles, processorHandles + numPartitions);
}

std::map<AmdSmiNodeId, AmdSmiMetrics> AmdSmiWrapper::getMetricsFromSocket_(
    amdsmi_socket_handle socketHandle) {
  const auto processorHandles = getProcessorHandles_(socketHandle);
  const size_t numPartitions = processorHandles.size();
  const auto primary = findPrimaryProcessor(processorHandles);

  amdsmi_gpu_metrics_t gpuMetrics{};
  checkStatus(
      amdsmi_get_gpu_metrics_info(primary.handle, &gpuMetrics),
      "amdsmi_get_gpu_metrics_info");
  const auto perXcpGfxBusyInst =
      getPerXcpGfxBusyInst(gpuMetrics, numPartitions);
  if (perXcpGfxBusyInst.size() < numPartitions) {
    throw std::runtime_error("failed to get gpu util for all partitions");
  }
  const AmdSmiMetrics physicalMetrics =
      readPhysicalMetrics(primary.handle, gpuMetrics);

  // get per partition metadata and assemble per physical device metrics
  std::map<AmdSmiNodeId, AmdSmiMetrics> res;
  for (auto processorHandle : processorHandles) {
    amdsmi_kfd_info_t kfdInfo{};
    checkStatus(
        amdsmi_get_gpu_kfd_info(processorHandle, &kfdInfo),
        "amdsmi_get_gpu_kfd_info");
    if (kfdInfo.current_partition_id >= numPartitions) {
      throw std::runtime_error("current_partition_id is not valid");
    }
    AmdSmiMetrics metrics = physicalMetrics;
    metrics.kfd_id = kfdInfo.kfd_id;
    metrics.oam_id = primary.oamId;
    metrics.partition_id = kfdInfo.current_partition_id;
    metrics.node_id = kfdInfo.node_id;
    metrics.gpu_util_percent =
        perXcpGfxBusyInst.at(kfdInfo.current_partition_id);
    res[kfdInfo.node_id] = metrics;
  }
  return res;
}

std::string AmdSmiWrapper::getModelNameFromSocket_(
    amdsmi_socket_handle socketHandle) {
  const auto processorHandles = getProcessorHandles_(socketHandle);
  if (processorHandles.empty()) {
    throw std::runtime_error("No processor handle returned from socket");
  }
  amdsmi_board_info_t info{};
  checkStatus(
      amdsmi_get_gpu_board_info(processorHandles[0], &info),
      "amdsmi_get_gpu_board_info");
  return std::string(
      info.product_name, strnlen(info.product_name, AMDSMI_MAX_STRING_LENGTH));
}

} // namespace gpumon
} // namespace dynolog
