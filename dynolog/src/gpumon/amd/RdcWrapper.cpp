/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/amd/RdcWrapper.h"

#include <glog/logging.h>
#include <fstream>
#include <mutex>
#include <set>

namespace dynolog {
namespace gpumon {

// an id to identy gpu group, put all physical GPUs in a group and partitions in
// another group
const char* kGpuGroupName = "RdcGroupInfo";
const char* kPartitionGroupName = "RdcPartitionGroupInfo";
// an id to identify fields group, put metrics fro physical GPUs in a group and
// partitions in another group
const char* kFieldGroupName = "RdcFieldGroup";
const char* kPartitionFieldGroupName = "RdcPartitionFieldGroup";

const std::set<rdc_field_t> kPartitionSupportedMetrics = {
    RDC_FI_PROF_OCCUPANCY_PERCENT,
    RDC_FI_PROF_ACTIVE_CYCLES,
    RDC_FI_PROF_ELAPSED_CYCLES,
    RDC_FI_PROF_EVAL_FLOPS_16,
    RDC_FI_PROF_EVAL_FLOPS_32,
    RDC_FI_PROF_EVAL_FLOPS_64,
#if FB_ROCM_VERSION >= 60402
    RDC_FI_PROF_KFD_ID,
    RDC_FI_PROF_SIMD_UTILIZATION,
#endif
};

// how often RDC should query from underlying sources (amd-smi, rocprofiler...)
constexpr std::chrono::milliseconds kUpdateInterval{500};
// how long the buffer should be to keep historical data, since kMaxKeepSamples
// == 1, this should of no use when sufficiently large
constexpr std::chrono::seconds kMaxKeepAge{2};
// how many sample to keep in the RDC cache, we only use the latest value
constexpr int kMaxKeepSamples = 2;

// check the RDC API reference
// https://rocm.docs.amd.com/projects/rdc/en/docs-6.4.2/reference/api_ref.html
// for more information

RdcWrapper::RdcWrapper(std::vector<rdc_field_t> enabledMetrics) {
  auto contextWlocked = context_.wlock();
  init_(std::move(enabledMetrics), contextWlocked);
}

RdcWrapper::~RdcWrapper() {
  clean();
}

void RdcWrapper::init(std::vector<rdc_field_t> enabledMetrics) {
  LOG(INFO) << "initializing RDC in embedded mode";
  auto contextWlocked = context_.wlock();
  init_(std::move(enabledMetrics), contextWlocked);
}

void RdcWrapper::init_(
    std::vector<rdc_field_t> enabledMetrics,
    RdcRuntimeContextWithWLock& context) {
  context.data.enabledMetrics_ = std::move(enabledMetrics);
  if (context.data.enabledMetrics_.empty()) {
    throw std::runtime_error("enabledMetrics is empty");
  }
  rdc_status_t result = rdc_init(0);
  if (result != RDC_ST_OK) {
    throw std::runtime_error(
        "rdc_init() failed with error code: " + std::to_string(result));
  }
  result =
      rdc_start_embedded(RDC_OPERATION_MODE_AUTO, &context.data.rdcHandle_);
  if (result != RDC_ST_OK) {
    throw std::runtime_error(
        "rdc_start_embedded() failed with error code: " +
        std::to_string(result));
  }

  initGpu_(context.data);
  initPartition_(context.data);

  LOG(INFO) << "RDC is initialized";
}

void RdcWrapper::clean() {
  LOG(INFO) << "shutting down RDC";
  auto contextWlocked = context_.wlock();
  clean_(contextWlocked);
}

void RdcWrapper::clean_(RdcRuntimeContextWithWLock& context) {
  context.data.enabledMetrics_.clear();
  rdc_status_t result = rdc_shutdown();
  if (result != RDC_ST_OK) {
    LOG(WARNING) << "rdc_shutdown() failed with error code: " << result;
  }

  static const char* rocprofilerLockPath = "/tmp/rocprofiler.pid";
  std::ifstream rocprofilerLock(rocprofilerLockPath);
  if (rocprofilerLock.fail()) {
    // rdc may not start rocprofiler
    // it's fine if the lock file doesn't exist
    return;
  }
  pid_t rocprofilerPid = -1;
  if (rocprofilerLock >> rocprofilerPid) {
    if (rocprofilerPid == getpid()) {
      LOG(INFO) << "remove rocprofiler.pid";
      if (std::remove(rocprofilerLockPath) != 0) {
        LOG(ERROR) << "failed to remove rocprofiler lock at "
                   << rocprofilerLockPath;
      }
    }
  } else {
    LOG(WARNING) << "failed to read pid from rocprofiler lock file";
  }
}

RdcMetricsMap RdcWrapper::getRdcMetricsForDevice(uint32_t device) {
  RdcMetricsMap res;
  auto context = context_.wlock();
  if (context.data.enabledMetrics_.empty()) {
    return {};
  }
  rdc_status_t result;
  for (auto metric : context.data.enabledMetrics_) {
#if FB_ROCM_VERSION >= 60402
    rdc_entity_info_t deviceInfo = rdc_get_info_from_entity_index(device);
    // skip unsupported metrics for partitions
    if (deviceInfo.entity_role == RDC_DEVICE_ROLE_PARTITION_INSTANCE &&
        !kPartitionSupportedMetrics.count(metric)) {
      continue;
    }
#endif
    rdc_field_value value = {};
    result = rdc_field_get_latest_value(
        context.data.rdcHandle_, device, metric, &value);
    if (result != RDC_ST_OK) {
      LOG(ERROR) << "failed to get metric " << metric << " for device "
                 << device << " with error code: " << result;
      continue;
    }
    if (value.status != RDC_ST_OK) {
      LOG(ERROR) << "metric " << metric << " returned by device " << device
                 << " has a non RDC_ST_OK status: " << value.status;
      continue;
    }
    switch (value.type) {
      case rdc_field_type_t::DOUBLE:
        res[metric] = value.value.dbl;
        break;
      case rdc_field_type_t::INTEGER:
        res[metric] = value.value.l_int;
        break;
      default:
        LOG(ERROR) << "unsupported type returned by rdc: " << value.type;
        break;
    }
  }
  return res;
}

std::vector<uint32_t> RdcWrapper::getMonitoredEntities() {
  auto contextRlocked = context_.rlock();
  return getMonitoredEntities_(contextRlocked.data);
}

std::vector<uint32_t> RdcWrapper::getMonitoredEntities_(
    RdcRuntimeContext& context) {
  return context.monitoredEntities_;
}

std::vector<uint32_t> RdcWrapper::listDeviceIds_(RdcRuntimeContext& context) {
  uint32_t allDevices[RDC_MAX_NUM_DEVICES];
  uint32_t numDevices;
  auto result = rdc_device_get_all(context.rdcHandle_, allDevices, &numDevices);
  if (result != RDC_ST_OK) {
    LOG(ERROR) << "rdc_device_get_all() failed with error: " << result;
    return {};
  }
  std::vector<uint32_t> deviceIds(numDevices);
  for (int i = 0; i < numDevices; i++) {
    deviceIds[i] = allDevices[i];
  }
  return deviceIds;
}

std::vector<uint32_t> RdcWrapper::listPartitionIds_(
    RdcRuntimeContext& context) {
  std::vector<uint32_t> partitionIds;
#if FB_ROCM_VERSION >= 60402
  auto devices = listDeviceIds_(context);
  for (auto dev : devices) {
    uint16_t numPartitions;
    auto result =
        rdc_get_num_partition(context.rdcHandle_, dev, &numPartitions);
    if (result != RDC_ST_OK) {
      LOG(ERROR) << "rdc_get_num_partition() failed with error: " << result;
    } else if (numPartitions > 8) {
      // likely the driver is too old to properly support partitions
      continue;
    } else if (numPartitions > 1) {
      for (uint32_t partition = 0; partition < numPartitions; partition++) {
        rdc_entity_info_t partitionEntity{
            .device_index = dev,
            .instance_index = partition,
            .entity_role = RDC_DEVICE_ROLE_PARTITION_INSTANCE,
            .device_type = RDC_DEVICE_TYPE_GPU};
        partitionIds.push_back(rdc_get_entity_index_from_info(partitionEntity));
      }
    }
  }
#endif
  return partitionIds;
}

void RdcWrapper::initGpu_(RdcRuntimeContext& context) {
  // create GPU group
  auto result = rdc_group_gpu_create(
      context.rdcHandle_, RDC_GROUP_EMPTY, kGpuGroupName, &context.gpuGroupId_);
  if (result != RDC_ST_OK) {
    throw std::runtime_error(
        "rdc_group_gpu_create() failed when creating GPU group with error code: " +
        std::to_string(result));
  }
  auto deviceIds = listDeviceIds_(context);
  for (auto dev : deviceIds) {
    LOG(INFO) << "adding gpu: " << dev;
    result = rdc_group_gpu_add(context.rdcHandle_, context.gpuGroupId_, dev);
    if (result != RDC_ST_OK) {
      throw std::runtime_error(
          "rdc_group_gpu_add() failed when adding GPU to group with error code: " +
          std::to_string(result));
    }
    context.monitoredEntities_.push_back(dev);
  }
  // create GPU field group
  for (rdc_field_t metric : context.enabledMetrics_) {
    LOG(INFO) << "adding metric: " << metric;
  }
  result = rdc_group_field_create(
      context.rdcHandle_,
      context.enabledMetrics_.size(),
      context.enabledMetrics_.data(),
      kFieldGroupName,
      &context.fieldGroupId_);
  if (result != RDC_ST_OK) {
    throw std::runtime_error(
        "rdc_group_field_create() failed when creating GPU field group with error code: " +
        std::to_string(result));
  }
  // start collecting metrics
  result = rdc_field_watch(
      context.rdcHandle_,
      context.gpuGroupId_,
      context.fieldGroupId_,
      std::chrono::microseconds(kUpdateInterval).count(),
      std::chrono::seconds(kMaxKeepAge).count(),
      kMaxKeepSamples);
  if (result != RDC_ST_OK) {
    throw std::runtime_error(
        "rdc_field_watch() failed on GPU group with error code: " +
        std::to_string(result));
  }
}
void RdcWrapper::initPartition_(RdcRuntimeContext& context) {
#if FB_ROCM_VERSION >= 60402
  auto partitionIds = listPartitionIds_(context);
  if (partitionIds.empty()) {
    return;
  }
  auto result = rdc_group_gpu_create(
      context.rdcHandle_,
      RDC_GROUP_EMPTY,
      kPartitionGroupName,
      &context.partitionGroupId_);
  if (result != RDC_ST_OK) {
    throw std::runtime_error(
        "rdc_group_gpu_create() failed when creating partition group with error code: " +
        std::to_string(result));
  }
  for (auto partition : partitionIds) {
    LOG(INFO) << "adding partition: " << partition;
    result = rdc_group_gpu_add(
        context.rdcHandle_, context.partitionGroupId_, partition);
    if (result != RDC_ST_OK) {
      throw std::runtime_error(
          "rdc_group_gpu_add() failed when adding partition to group with error code: " +
          std::to_string(result));
    }
    context.monitoredEntities_.push_back(partition);
  }
  // create partition field group
  std::vector<rdc_field_t> partitionEnabledMetrics;
  for (rdc_field_t metric : context.enabledMetrics_) {
    if (kPartitionSupportedMetrics.count(metric)) {
      LOG(INFO) << "adding metric for partitions : " << metric;
      partitionEnabledMetrics.push_back(metric);
    }
  }
  result = rdc_group_field_create(
      context.rdcHandle_,
      partitionEnabledMetrics.size(),
      partitionEnabledMetrics.data(),
      kPartitionFieldGroupName,
      &context.partitionFieldGroupId_);
  if (result != RDC_ST_OK) {
    throw std::runtime_error(
        "rdc_group_field_create() failed when creating partition field group with error code: " +
        std::to_string(result));
  }
  result = rdc_field_watch(
      context.rdcHandle_,
      context.partitionGroupId_,
      context.partitionFieldGroupId_,
      std::chrono::microseconds(kUpdateInterval).count(),
      std::chrono::seconds(kMaxKeepAge).count(),
      kMaxKeepSamples);
  if (result != RDC_ST_OK) {
    throw std::runtime_error(
        "rdc_field_watch() failed on partition group with error code: " +
        std::to_string(result));
  }
#endif
}

} // namespace gpumon
} // namespace dynolog
