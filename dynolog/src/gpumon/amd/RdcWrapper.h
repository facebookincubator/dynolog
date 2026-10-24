/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <cstdint>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <unordered_map>
#include <variant>
#include <vector>

#include "rdc/rdc.h"

#pragma once

// Normalize the ROCm version macro. The buck build defines FB_ROCM_VERSION; the
// standalone CMake build defines DYNOLOG_ROCM_VERSION directly. Source guards
// key off DYNOLOG_ROCM_VERSION only.
#if defined(FB_ROCM_VERSION) && !defined(DYNOLOG_ROCM_VERSION)
#define DYNOLOG_ROCM_VERSION FB_ROCM_VERSION
#endif

#if !defined(DYNOLOG_ROCM_VERSION) || DYNOLOG_ROCM_VERSION < 70000
#error "dynolog AMD GPU support requires ROCm 7.0 or newer"
#endif

namespace dynolog {
namespace gpumon {

// The RDC field carrying the KFD id: RDC_FI_PROF_KFD_ID in upstream ROCm 7.0.2,
// RDC_FI_KFD_ID in Meta's ROCm 7.0 build and later releases. They're
// enumerators, not macros, so pick whichever rdc.h declares at compile time.
template <typename Field = rdc_field_t>
constexpr Field rdcKfdIdField() {
  if constexpr (requires { Field::RDC_FI_KFD_ID; }) {
    return Field::RDC_FI_KFD_ID;
  } else {
    return Field::RDC_FI_PROF_KFD_ID;
  }
}
inline constexpr rdc_field_t kRdcKfdIdField = rdcKfdIdField();

using RdcMetricsValue = std::variant<double, int64_t>;
using RdcMetricsMap = std::unordered_map<rdc_field_t, RdcMetricsValue>;

struct RdcRuntimeContext {
  std::vector<rdc_field_t> enabledMetrics_;
  // entity = physical GPUs + partitions
  std::vector<uint32_t> monitoredDeviceEntities_;
  std::vector<uint32_t> monitoredPartitionsEntities_;
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
  RdcWrapper(
      std::vector<rdc_field_t> enabledMetrics,
      std::chrono::milliseconds updateInterval,
      std::chrono::seconds maxKeepAge,
      int maxKeepSamples);
  virtual ~RdcWrapper();
  RdcWrapper(const RdcWrapper&) = delete;
  RdcWrapper& operator=(const RdcWrapper&) = delete;
  RdcWrapper(RdcWrapper&&) = delete;
  RdcWrapper& operator=(RdcWrapper&&) = delete;
  void init(std::vector<rdc_field_t> enabledMetrics);
  void clean();
  virtual RdcMetricsMap getRdcMetricsForDevice(uint32_t device);
  std::vector<uint32_t> getMonitoredEntities();
  // Whole-GPU entities only, without partitions.
  virtual std::vector<uint32_t> getMonitoredDeviceEntities();
  virtual std::vector<uint32_t> getMonitoredPartitionsEntities();

 protected:
  // For test fakes: doesn't start or shut down RDC.
  RdcWrapper();

  void init_(
      std::vector<rdc_field_t> enabledMetrics,
      RdcRuntimeContextWithWLock& context);
  void clean_(RdcRuntimeContextWithWLock& context);
  std::vector<uint32_t> getMonitoredPartitionsEntities_(
      RdcRuntimeContext& context);
  std::vector<uint32_t> getMonitoredEntities_(RdcRuntimeContext& context);
  std::vector<uint32_t> listDeviceIds_(RdcRuntimeContext& context);
  std::vector<uint32_t> listPartitionIds_(RdcRuntimeContext& context);
  void initGpu_(RdcRuntimeContext& context);
  void initPartition_(RdcRuntimeContext& context);

  RdcRuntimeContextSynchronized context_;

  const std::chrono::milliseconds updateInterval_;
  const std::chrono::seconds maxKeepAge_;
  const int maxKeepSamples_;
  const bool startedRdc_ = true;
};

} // namespace gpumon
} // namespace dynolog
