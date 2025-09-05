// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include <cstdint>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <unordered_map>
#include <variant>
#include <vector>

#include "rdc/rdc.h"

#pragma once

namespace dynolog {
namespace gpumon {

using RdcMetricsValue = std::variant<double, int64_t>;
using RdcMetricsMap = std::unordered_map<rdc_field_t, RdcMetricsValue>;

struct RdcRuntimeContext {
  std::vector<rdc_field_t> enabledMetrics_;
  // entity = physical GPUs + partitions
  std::vector<uint32_t> monitoredEntities_;
  rdc_handle_t rdcHandle_;
  rdc_gpu_group_t gpuGroupId_;
  rdc_gpu_group_t partitionGroupId_{};
  rdc_field_grp_t fieldGroupId_;
  rdc_field_grp_t partitionFieldGroupId_{};
};

struct RdcRuntimeContextWithWLock {
  RdcRuntimeContextWithWLock(
      RdcRuntimeContext& data,
      std::shared_mutex& sharedDataLock)
      : data{data} {
    lockGuard_ = std::unique_lock<std::shared_mutex>(sharedDataLock);
  }
  RdcRuntimeContext& data;

 private:
  std::unique_lock<std::shared_mutex> lockGuard_;
};

struct RdcRuntimeContextWithRLock {
  RdcRuntimeContextWithRLock(
      RdcRuntimeContext& data,
      std::shared_mutex& sharedDataLock)
      : data{data} {
    lockGuard_ = std::shared_lock<std::shared_mutex>(sharedDataLock);
  }
  RdcRuntimeContext& data;

 private:
  std::shared_lock<std::shared_mutex> lockGuard_;
};

class RdcRuntimeContextSynchronized {
 public:
  RdcRuntimeContextWithRLock rlock() {
    return RdcRuntimeContextWithRLock(data_, sharedDataLock_);
  }
  RdcRuntimeContextWithWLock wlock() {
    return RdcRuntimeContextWithWLock(data_, sharedDataLock_);
  }

 protected:
  RdcRuntimeContext data_;
  std::shared_mutex sharedDataLock_;
};

class RdcWrapper {
 public:
  RdcWrapper(std::vector<rdc_field_t> enabledMetrics);
  ~RdcWrapper();
  void init(std::vector<rdc_field_t> enabledMetrics);
  void clean();
  RdcMetricsMap getRdcMetricsForDevice(uint32_t device);
  std::vector<uint32_t> getMonitoredEntities();

 protected:
  void init_(
      std::vector<rdc_field_t> enabledMetrics,
      RdcRuntimeContextWithWLock& context);
  void clean_(RdcRuntimeContextWithWLock& context);
  std::vector<uint32_t> getMonitoredEntities_(RdcRuntimeContext& context);
  std::vector<uint32_t> listDeviceIds_(RdcRuntimeContext& context);
  std::vector<uint32_t> listPartitionIds_(RdcRuntimeContext& context);
  void initGpu_(RdcRuntimeContext& context);
  void initPartition_(RdcRuntimeContext& context);

  RdcRuntimeContextSynchronized context_;
};

} // namespace gpumon
} // namespace dynolog
