/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/amd/AmdSmiWrapper.h"

#include <algorithm>
#include <cstring>
#include <optional>
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
  // these metrics will be only available on partition 0
  std::optional<uint32_t> oamId;
  std::map<uint32_t, uint32_t> perXcpGfxBusyInst;

  const auto processorHandles = getProcessorHandles_(socketHandle);
  const size_t numPartitions = processorHandles.size();

  for (auto processorHandle : processorHandles) {
    amdsmi_asic_info_t asicInfo{};
    checkStatus(
        amdsmi_get_gpu_asic_info(processorHandle, &asicInfo),
        "amdsmi_get_gpu_asic_info");
    if (asicInfo.oam_id == std::numeric_limits<uint32_t>::max()) {
      // for partitioned GPUs, only the first partition will have a valid
      // OAM_ID and per XCP metrics.
      continue;
    }
    oamId = asicInfo.oam_id;

    amdsmi_gpu_metrics_t gpuMetrics{};
    checkStatus(
        amdsmi_get_gpu_metrics_info(processorHandle, &gpuMetrics),
        "amdsmi_get_gpu_metrics_info");
    // calculate average of the XCCs of each partition
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
        perXcpGfxBusyInst[xcp] = accUtil / numXcc;
      }
    }
    break;
  }

  if (!oamId.has_value()) {
    throw std::runtime_error("oamId is missing");
  }
  if (perXcpGfxBusyInst.size() < numPartitions) {
    throw std::runtime_error("failed to get gpu util for all partitions");
  }

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
    res[kfdInfo.node_id] = AmdSmiMetrics{
        .kfd_id = kfdInfo.kfd_id,
        .oam_id = oamId.value(),
        .partition_id = kfdInfo.current_partition_id,
        .node_id = kfdInfo.node_id,
        .gpu_util_percent = static_cast<int>(
            perXcpGfxBusyInst.at(kfdInfo.current_partition_id)),
    };
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
