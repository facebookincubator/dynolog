// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include "dynolog/src/gpumon/amd/RdcWrapper.h"

#include <glog/logging.h>
#include <fstream>
#include <mutex>

namespace dynolog {
namespace gpumon {

// an id to identy gpu group, since we only have one gpu group, this can be any
// random string
const char* kGpuGroupName = "RdcGroupInfo";
// and id to identify fields group, since we only have one field group, this can
// ben any random string
const char* kFieldGroupName = "RdcFieldGroup";
// how often RDC should query from underlying sources (amd-smi, rocprofiler...)
constexpr std::chrono::milliseconds kUpdateInterval{500};
// how long the buffer should be to keep historical data, since kMaxKeepSamples
// == 1, this should of no use when sufficiently large
constexpr std::chrono::seconds kMaxKeepAge{2};
// how many sample to keep in the RDC cache, we only use the latest value
constexpr int kMaxKeepSamples = 2;

// check the RDC API reference
// https://rocm.docs.amd.com/projects/rdc/en/docs-6.2.0/reference/api_ref.html
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
  LOG(INFO) << "adding all GPUs to the group " << kGpuGroupName;
  result = rdc_group_gpu_create(
      context.data.rdcHandle_,
      RDC_GROUP_DEFAULT,
      kGpuGroupName,
      &context.data.gpuGroupId_);
  if (result != RDC_ST_OK) {
    throw std::runtime_error(
        "rdc_group_gpu_create() failed with error code: " +
        std::to_string(result));
  }

  for (rdc_field_t metric : context.data.enabledMetrics_) {
    LOG(INFO) << "adding metric: " << metric;
  }
  result = rdc_group_field_create(
      context.data.rdcHandle_,
      context.data.enabledMetrics_.size(),
      context.data.enabledMetrics_.data(),
      kFieldGroupName,
      &context.data.fieldGroupId_);
  if (result != RDC_ST_OK) {
    throw std::runtime_error(
        "rdc_group_field_create() failed with error code: " +
        std::to_string(result));
  }
  result = rdc_field_watch(
      context.data.rdcHandle_,
      context.data.gpuGroupId_,
      context.data.fieldGroupId_,
      std::chrono::microseconds(kUpdateInterval).count(),
      std::chrono::seconds(kMaxKeepAge).count(),
      kMaxKeepSamples);
  if (result != RDC_ST_OK) {
    throw std::runtime_error(
        "rdc_field_watch() failed with error code: " + std::to_string(result));
  }

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

RdcMetricsMap RdcWrapper::getRdcMetricsForDevice(size_t device) {
  RdcMetricsMap res;
  auto context = context_.rlock();
  if (context.data.enabledMetrics_.empty()) {
    return {};
  }
  rdc_status_t result;
  for (auto metric : context.data.enabledMetrics_) {
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

} // namespace gpumon
} // namespace dynolog
