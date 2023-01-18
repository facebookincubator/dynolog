// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/gpumon/DcgmGroupInfo.h"
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <cstdint>
#include <map>
#include <mutex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include "dynolog/src/gpumon/DcgmApiStub.h"
#include "dynolog/src/gpumon/Entity.h"
#include "dynolog/src/gpumon/Utils.h"
#include "dynolog/src/gpumon/dcgm_fields.h"

namespace dynolog {
namespace gpumon {

DEFINE_string(
    dcgm_fields,
    kDcgmDefaultFieldIds,
    "The field ids to monitor on DCGM (GPUs), comma separated");

constexpr double maxKeepAgeSec = 2;
constexpr int maxKeepSamples = 2;
const std::string groupName = "DcgmGroupInfo";
const std::string fieldGroupName = "DcgmFieldGroup";
constexpr int kDcgmBlankValueError = 2;

// fieldId -> metricName in metric cache
std::unordered_map<unsigned short, std::string> FieldIdToName{
    {DCGM_FI_PROF_GR_ENGINE_ACTIVE, "graphics_engine_active_ratio"},
    {DCGM_FI_PROF_SM_ACTIVE, "sm_active_ratio"},
    {DCGM_FI_PROF_SM_OCCUPANCY, "sm_occupancy"},
    {DCGM_FI_DEV_SM_CLOCK, "gpu_frequency_mhz"},
    {DCGM_FI_PROF_PIPE_FP16_ACTIVE, "fp16_active"},
    {DCGM_FI_PROF_PIPE_FP32_ACTIVE, "fp32_active"},
    {DCGM_FI_PROF_PIPE_FP64_ACTIVE, "fp64_active"},
    {DCGM_FI_PROF_PIPE_TENSOR_ACTIVE, "tensorcore_active"},
    {DCGM_FI_PROF_DRAM_ACTIVE, "hbm_mem_bw_util"},
    {DCGM_FI_PROF_PCIE_TX_BYTES, "pcie_tx_bytes"},
    {DCGM_FI_PROF_PCIE_RX_BYTES, "pcie_rx_bytes"},
    {DCGM_FI_PROF_NVLINK_TX_BYTES, "nvlink_tx_bytes"},
    {DCGM_FI_PROF_NVLINK_RX_BYTES, "nvlink_rx_bytes"},
    {DCGM_FI_DEV_MINOR_NUMBER, "minor_id"},
    {DCGM_FI_DEV_GPU_UTIL, "gpu_device_utilization"},
    {DCGM_FI_DEV_MEM_COPY_UTIL, "gpu_memory_utilization"},
    {DCGM_FI_DEV_POWER_USAGE, "gpu_power_draw"}};

// Mapping of attribution environment variable name to scuba column name
std::unordered_map<std::string, std::string> attributionEnvVarsToScubaColumns{
    {"SLURM_JOB_ID", "job_id"},
    {"USER", "username"},
    {"SLURM_JOB_ACCOUNT", "slurm_account"},
    {"SLURM_JOB_PARTITION", "slurm_partition"}};

DEFINE_bool(
    enable_env_var_attribution,
    true,
    "Enable environment variable attribution for GPUs."
    "Currently this support SLURM job scheduler environment variables.");

static inline void printValue(dcgmFieldValue_v1 v) {
  VLOG(1) << "====================================";
  VLOG(1) << "\tfieldid:" << FieldIdToName[v.fieldId];
  VLOG(2) << "\tfieldtype:" << (char)v.fieldType;
  VLOG(2) << "\tstatus:" << v.status;
  VLOG(2) << "\tts:" << v.ts;
  switch (v.fieldType) {
    case 'b':
      VLOG(1) << "\tvalue:" << v.value.blob;
      break;
    case 'd':
      VLOG(1) << "\tvalue:" << v.value.dbl;
      break;
    case 'i':
      VLOG(1) << "\tvalue:" << v.value.i64;
      break;
    case 's':
      VLOG(1) << "\tvalue:" << v.value.str;
      break;
    default:
      VLOG(1) << "Unknown field value type";
  }
}

static inline bool isProfField(unsigned short field_id) {
  // see https://github.com/NVIDIA/DCGM/blob/master/dcgmlib/dcgm_fields.h
  return field_id >= DCGM_FI_PROF_GR_ENGINE_ACTIVE;
}

std::unique_ptr<DcgmGroupInfo> DcgmGroupInfo::factory(
    const std::string& fields_str,
    int updateIntervalMs) {
  std::stringstream field_ss(fields_str);
  std::string field;
  std::vector<unsigned short> fields;
  std::vector<unsigned short> prof_fields;

  // parsing the fields_str to a list of field ids
  while (getline(field_ss, field, ',')) {
    unsigned short field_id;
    try {
      field_id = (unsigned short)std::stoi(field);
    } catch (std::invalid_argument& e) {
      LOG(ERROR) << "Field id must be number, instead got: " << field;
      continue;
    }
    if (isProfField(field_id)) {
      prof_fields.push_back(field_id);
    }
    fields.push_back(field_id);
  }

  std::stringstream ss;
  ss << "Creating DCGM instance with fields: ";
  for (const auto& field_id : fields) {
    ss << field_id << " ";
  }
  LOG(INFO) << ss.str();

  auto dcgmGroupInfo = std::unique_ptr<DcgmGroupInfo>(
      new DcgmGroupInfo(fields, prof_fields, updateIntervalMs));
  if (dcgmGroupInfo->isFailing()) {
    return nullptr;
  }
  return dcgmGroupInfo;
}

DcgmGroupInfo::DcgmGroupInfo(
    const std::vector<unsigned short>& fields,
    const std::vector<unsigned short>& prof_fields,
    int updateIntervalMs)
    : updateIntervalMs_(updateIntervalMs) {
  init();
  createGroups();
  createFieldGroups(fields);
  watchFields();
  watchProfFields(prof_fields);
}

void DcgmGroupInfo::init() {
  if (retCode_ = dcgmInit_stub(); retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed to init dcgm, dcgmInit() returned: " << retCode_;
  }

  if (retCode_ = dcgmStartEmbedded_stub(DCGM_OPERATION_MODE_AUTO, &dcgmHandle_);
      retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmStartEmbedded() return: " << retCode_;
  }
}

// Create a group for all GPU instances
void DcgmGroupInfo::createGroups() {
  if (isFailing()) {
    // initialization failed, no group will be created
    return;
  }
  if (retCode_ = dcgmGroupCreate_stub(
          dcgmHandle_, DCGM_GROUP_EMPTY, (char*)groupName.c_str(), &groupId_);
      retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmGroupCreate() return: " << retCode_;
  } else {
    LOG(INFO) << "Added group id " << groupId_;
  }

  unsigned int gpuIdList[DCGM_MAX_NUM_DEVICES];
  if (retCode_ = dcgmGetAllSupportedDevices_stub(
          dcgmHandle_, gpuIdList, &deviceCount_);
      retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmGetAllSupportedDevices() return: " << retCode_;
  } else if (deviceCount_ > 0) {
    LOG(INFO) << "Found " << deviceCount_ << " supported devices, with id: ";
    for (int i = 0; i < deviceCount_; i++) {
      if (retCode_ = dcgmGroupAddEntity_stub(
              dcgmHandle_, groupId_, DCGM_FE_GPU, gpuIdList[i]);
          retCode_ == DCGM_ST_OK) {
        LOG(INFO) << "Successfully add device: " << gpuIdList[i];
      } else {
        errorCode_ = retCode_;
        LOG(ERROR) << "Failed dcgmGroupAddEntity() for device " << gpuIdList[i]
                   << ", return: " << retCode_;
      }
    }
    gpuIdList_.insert(
        gpuIdList_.end(), &gpuIdList[0], &gpuIdList[deviceCount_]);
  }
}

// Init field groups to watch
// TODO: make field ids configurable from configerator
// TODO: make more than one field group configuration available
void DcgmGroupInfo::createFieldGroups(
    const std::vector<unsigned short>& fields) {
  if (isFailing() || fields.size() == 0) {
    // initialization failed, no group will be created
    return;
  }
  dcgmFieldGrp_t fieldGroupId;
  if (retCode_ = dcgmFieldGroupCreate_stub(
          dcgmHandle_, fields, (char*)fieldGroupName.c_str(), &fieldGroupId);
      retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmFieldGroupCreate() return: " << retCode_
               << " with group " << groupId_ << ", field group "
               << fieldGroupId;
  } else {
    fieldGroupIds_.push_back(fieldGroupId);
    LOG(INFO) << "Added field group " << fieldGroupId << " to group "
              << groupId_;
  }
}

void DcgmGroupInfo::watchFields() {
  if (isFailing()) {
    // initialization failed, no group will be created
    return;
  }
  LOG(INFO) << "Watching DCGM fields at interval (ms) = " << updateIntervalMs_;
  for (const auto& fieldGroupId : fieldGroupIds_) {
    if (retCode_ = dcgmWatchFields_stub(
            dcgmHandle_,
            groupId_,
            fieldGroupId,
            updateIntervalMs_ * 1000, // update interval in us
            maxKeepAgeSec,
            maxKeepSamples);
        retCode_ != DCGM_ST_OK) {
      errorCode_ = retCode_;
      LOG(ERROR) << "Failed dcgmWatchFields() return: " << retCode_
                 << " with group " << groupId_ << ", field group "
                 << fieldGroupId;
    }
  }
}

// TODO: make more than one profiling group configuration available
void DcgmGroupInfo::watchProfFields(
    const std::vector<unsigned short>& prof_fields) {
  if (isFailing() || prof_fields.size() == 0) {
    // setup failed
    return;
  }
  dcgmProfWatchFields_t watchFields;
  memset(&watchFields, 0, sizeof(watchFields));
  watchFields.version = dcgmProfWatchFields_version;
  watchFields.groupId = groupId_;
  watchFields.numFieldIds = prof_fields.size();
  for (int i = 0; i < watchFields.numFieldIds; i++) {
    watchFields.fieldIds[i] = prof_fields[i];
  }
  watchFields.updateFreq = updateIntervalMs_ * 1000;
  watchFields.maxKeepAge = maxKeepAgeSec;
  watchFields.maxKeepSamples = maxKeepSamples;
  if (retCode_ = dcgmProfWatchFields_stub(dcgmHandle_, &watchFields);
      retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmProfWatchFields() return: " << retCode_;
    prof_enabled_ = false;
  } else {
    prof_enabled_ = true;
  }
}

// Metrics are updated automatically by operation mode
// This function reads latest metrics from DCGM and update to metric cache
void DcgmGroupInfo::update() {
  std::map<Entity, std::vector<dcgmFieldValue_v1>> dcgmValues;
  cbData data(dcgmValues);
  LOG(INFO) << "fieldGroupIds_ size: " << fieldGroupIds_.size();

  for (const auto& fieldGroupId : fieldGroupIds_) {
    if (retCode_ = dcgmGetLatestValues_v2_stub(
            dcgmHandle_, groupId_, fieldGroupId, getLatestDcgmValueCB, &data);
        retCode_ != DCGM_ST_OK) {
      errorCode_ = retCode_;
      LOG(ERROR) << "Failed dcgmGetLatestValues_v2() return: " << retCode_;
    } else {
      // iterate over each GPU
      LOG(INFO) << "Got " << dcgmValues.size() << " GPU records";
      metricsMapDouble_.clear();
      metricsMapInt_.clear();
      for (auto& [entity, readValues] : dcgmValues) {
        LOG(INFO) << "Got " << readValues.size()
                  << " values for entity: " << entity;
        std::unordered_map<std::string, double> metricsDouble;
        std::unordered_map<std::string, int64_t> metricsInt;
        // sample invalid caused by DCGM bug
        // field failed at query stage will have DCGM_*_BLANK value
        bool blank_value_field = false;
        // iterate over each field for a GPU instance
        for (auto v : readValues) {
          printValue(v);
          if (v.status != DCGM_ST_OK) {
            LOG(ERROR) << "Value invalid status, got: " << v.status;
          } else if (FieldIdToName.find(v.fieldId) == FieldIdToName.end()) {
            LOG(ERROR) << "Field id not supported, got: " << v.fieldId;
          } else {
            // skip prof field reporting if profiling is disabled
            if (!prof_enabled_ && isProfField(v.fieldId)) {
              continue;
            }

            // Store value
            if (v.fieldType == 'd') {
              if (v.value.dbl == DCGM_FP64_BLANK) {
                blank_value_field = true;
              }
              metricsDouble[FieldIdToName[v.fieldId]] = v.value.dbl;
            } else if (v.fieldType == 'i') {
              if (v.value.i64 == DCGM_INT64_BLANK) {
                blank_value_field = true;
              }
              metricsInt[FieldIdToName[v.fieldId]] = v.value.i64;
            }
          }
        }
        metricsInt["dcgm_error"] = blank_value_field ? 1 : 0;
        metricsMapDouble_[entity.m_entityId] = metricsDouble;
        metricsMapInt_[entity.m_entityId] = metricsInt;
      }

      if (FLAGS_enable_env_var_attribution) {
        std::vector<pid_t> pids = getPidsOnGpu();
        for (int device_id = 0; device_id < pids.size(); device_id++) {
          envMetadataMapString_[device_id] = getMetadataForPid(
              pids[device_id], attributionEnvVarsToScubaColumns);
        }
      }
    }
  }
}

void DcgmGroupInfo::log(Logger& logger) {
  const auto t = std::chrono::system_clock::now();
  logger.setTimestamp(t);
  for (const auto& [index, metric_map] : metricsMapDouble_) {
    for (const auto& [key, val] : metric_map) {
      logger.logFloat(key, val);
    }
    if (metricsMapInt_.find(index) != metricsMapInt_.end()) {
      for (const auto& [key, val] : metricsMapInt_[index]) {
        logger.logInt(key, val);
      }
    }
    if (envMetadataMapString_.find(index) != envMetadataMapString_.end()) {
      for (const auto& [key, val] : envMetadataMapString_[index]) {
        logger.logStr(key, val);
      }
    }
    logger.logInt("device", index);
    logger.finalize();
  }
}

DcgmGroupInfo::~DcgmGroupInfo() {
  dcgmProfUnwatchFields_t unwatchFields;
  memset(&unwatchFields, 0, sizeof(unwatchFields));
  unwatchFields.version = dcgmProfUnwatchFields_version;
  unwatchFields.groupId = groupId_;
  if (retCode_ = dcgmProfUnwatchFields_stub(dcgmHandle_, &unwatchFields);
      retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmProfUnwatchFields(), return: " << retCode_;
  } else {
    LOG(INFO) << "Unwatched profiling fields for group id " << groupId_;
  }
  for (const auto& fieldGroupId : fieldGroupIds_) {
    if (retCode_ = dcgmUnwatchFields_stub(dcgmHandle_, groupId_, fieldGroupId);
        retCode_ != DCGM_ST_OK) {
      errorCode_ = retCode_;
      LOG(ERROR) << "Failed dcgmUnwatchFields() for field group "
                 << fieldGroupId << ", return: " << retCode_;
    } else {
      LOG(INFO) << "Unwatched fields for field group " << fieldGroupId;
    }
    if (retCode_ = dcgmFieldGroupDestroy_stub(dcgmHandle_, fieldGroupId);
        retCode_ != DCGM_ST_OK) {
      errorCode_ = retCode_;
      LOG(ERROR) << "Failed dcgmFieldGroupDestroy() for field group "
                 << fieldGroupId << ", return: " << retCode_;
    } else {
      LOG(INFO) << "Destroyed field group " << fieldGroupId;
    }
  }
  if (retCode_ = dcgmGroupDestroy_stub(dcgmHandle_, groupId_);
      retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmGroupDestroy() return: " << retCode_;
  } else {
    LOG(INFO) << "Destroyed group " << groupId_;
  }
  if (retCode_ = dcgmStopEmbedded_stub(dcgmHandle_); retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmStopEmbedded() return: " << retCode_;
  } else {
    LOG(INFO) << "Stopped embedded mode";
  }
  if (retCode_ = dcgmShutdown_stub(); retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmShutdown() return: " << retCode_;
  } else {
    LOG(INFO) << "Shutdown DCGM";
  }
}

} // namespace gpumon
} // namespace dynolog
