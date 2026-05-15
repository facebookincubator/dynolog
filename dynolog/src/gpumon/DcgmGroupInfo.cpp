/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/DcgmGroupInfo.h"
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <unistd.h>
#include <cstdint>
#include <map>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include "dynolog/src/gpumon/DcgmApiStub.h"
#include "dynolog/src/gpumon/Entity.h"
#include "dynolog/src/gpumon/Utils.h"
#include "dynolog/src/gpumon/dcgm_fields.h"

#ifdef USE_K8S_PODRESOURCES
#include "dynolog/src/k8s/K8sPodCache.h"
#include "dynolog/src/k8s/PodResourcesClient.h"
#endif

namespace dynolog::gpumon {

DEFINE_string(
    dcgm_fields,
    kDcgmDefaultFieldIds,
    "The field ids to monitor on DCGM (GPUs), comma separated");

DEFINE_string(
    dcgm_standalone_address,
    "",
    "Connect to a standalone DCGM hostengine at this address "
    "(e.g., localhost:5555). When empty, starts an embedded hostengine.");

constexpr double maxKeepAgeSec = 2;
constexpr int maxKeepSamples = 2;

// DCGM field group names must be unique per client on a shared hostengine.
// Include PID to avoid collisions with other DCGM clients (e.g.,
// dcgm-exporter).
const std::string groupName = "DcgmGroupInfo_" + std::to_string(getpid());
const std::string fieldGroupName = "DcgmFieldGroup_" + std::to_string(getpid());

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
    {DCGM_FI_DEV_POWER_USAGE, "gpu_power_draw"},
    {DCGM_FI_DEV_NAME, "gpu_name"},
    {DCGM_FI_DEV_UUID, "gpu_uuid"}};

// Mapping of attribution environment variable name to scuba column name.
// Loaded once on first use:
//   - From --env_attribution_mappings_file CSV, when set
//   - Otherwise from getDefaultEnvAttributionMap() (Slurm built-in defaults)
DEFINE_string(
    env_attribution_mappings_file,
    "",
    "Path to a CSV file defining env-var → column-name attribution mappings. "
    "Each non-empty, non-'#' line is: <env_var_name>,<output_column_name>. "
    "When empty, the built-in Slurm default mapping is used.");

const std::unordered_map<std::string, std::string>&
getEnvAttributionMappings() {
  static const auto mappings = [] {
    if (!FLAGS_env_attribution_mappings_file.empty()) {
      return loadEnvAttributionMap(FLAGS_env_attribution_mappings_file);
    }
    return getDefaultEnvAttributionMap();
  }();
  return mappings;
}

DEFINE_bool(
    enable_env_var_attribution,
    true,
    "Enable environment variable attribution for GPUs."
    "Currently this support SLURM job scheduler environment variables.");

#ifdef USE_K8S_PODRESOURCES
DEFINE_bool(
    enable_pod_resources_attribution,
    false,
    "Enable kubelet pod-resources attribution: query the local kubelet's "
    "pod-resources gRPC socket each cycle and join the (pod_namespace, "
    "pod_name, container_name) onto each GPU record by GPU UUID. "
    "Requires DCGM_FI_DEV_UUID (54) in --dcgm_fields.");

DEFINE_string(
    pod_resources_socket,
    "/var/lib/kubelet/pod-resources/kubelet.sock",
    "Path to kubelet pod-resources gRPC unix socket.");

DEFINE_string(
    pod_resources_gpu_resource,
    "nvidia.com/gpu",
    "K8s extended resource name to filter for GPU device assignments.");

namespace {
::dynolog::k8s::PodResourcesClient* getPodResourcesClient() {
  static auto client = std::make_unique<::dynolog::k8s::PodResourcesClient>(
      FLAGS_pod_resources_socket, FLAGS_pod_resources_gpu_resource);
  return client.get();
}

::dynolog::k8s::K8sPodCache* getK8sPodCache() {
  static auto cache = std::make_unique<::dynolog::k8s::K8sPodCache>();
  return cache.get();
}
} // namespace
#endif // USE_K8S_PODRESOURCES

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

std::shared_ptr<DcgmGroupInfo> DcgmGroupInfo::factory(
    const std::string& fields_str,
    int updateIntervalMs) {
  std::stringstream field_ss(fields_str);
  std::string field;
  std::vector<unsigned short> fields;
  std::vector<unsigned short> prof_fields;

  // parsing the fields_str to a list of field ids
  while (getline(field_ss, field, ',')) {
    unsigned short field_id = 0;
    try {
      field_id = (unsigned short)std::stoi(field);
    } catch (std::invalid_argument&) {
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

  auto dcgmGroupInfo = std::shared_ptr<DcgmGroupInfo>(
      new DcgmGroupInfo(fields, prof_fields, updateIntervalMs));
  if (dcgmGroupInfo->isFailing()) {
    LOG(ERROR) << "Failed to create DcgmGroupInfo instance";
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
    return;
  }

  if (!FLAGS_dcgm_standalone_address.empty()) {
    // Standalone mode: connect to an existing nv-hostengine
    standaloneMode_ = true;
    LOG(INFO) << "Connecting to standalone DCGM hostengine at "
              << FLAGS_dcgm_standalone_address;
    if (retCode_ = dcgmConnect_stub(
            FLAGS_dcgm_standalone_address.c_str(), &dcgmHandle_);
        retCode_ != DCGM_ST_OK) {
      errorCode_ = retCode_;
      LOG(ERROR) << "Failed dcgmConnect() to " << FLAGS_dcgm_standalone_address
                 << ", return: " << retCode_;
    } else {
      LOG(INFO) << "Connected to standalone DCGM hostengine";
    }
  } else {
    // Embedded mode: start an in-process hostengine
    standaloneMode_ = false;
    if (retCode_ =
            dcgmStartEmbedded_stub(DCGM_OPERATION_MODE_AUTO, &dcgmHandle_);
        retCode_ != DCGM_ST_OK) {
      errorCode_ = retCode_;
      LOG(ERROR) << "Failed dcgmStartEmbedded() return: " << retCode_;
    }
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
  if (isFailing() || fields.empty()) {
    // initialization failed, no group will be created
    return;
  }
  dcgmFieldGrp_t fieldGroupId = 0;
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
  if (isFailing() || prof_fields.empty()) {
    // setup failed
    return;
  }
  dcgmProfWatchFields_t watchFields;
  memset(&watchFields, 0, sizeof(watchFields));
  watchFields.version = dcgmProfWatchFields_version;
  watchFields.groupId = groupId_;
  watchFields.numFieldIds = prof_fields.size();
  for (size_t i = 0; i < watchFields.numFieldIds; i++) {
    watchFields.fieldIds[i] = prof_fields[i];
  }
  watchFields.updateFreq = updateIntervalMs_ * 1000;
  watchFields.maxKeepAge = maxKeepAgeSec;
  watchFields.maxKeepSamples = maxKeepSamples;
  if (retCode_ = dcgmProfWatchFields_stub(dcgmHandle_, &watchFields);
      retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmProfWatchFields() return: " << retCode_;
    profEnabled_ = false;
  } else {
    profEnabled_ = true;
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
      metricsMapString_.clear();
      for (auto& [entity, readValues] : dcgmValues) {
        LOG(INFO) << "Got " << readValues.size()
                  << " values for entity: " << entity;
        std::unordered_map<std::string, double> metricsDouble;
        std::unordered_map<std::string, int64_t> metricsInt;
        std::unordered_map<std::string, std::string> metricsString;
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
            if (!profEnabled_ && isProfField(v.fieldId)) {
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
            } else if (v.fieldType == 's') {
              metricsString[FieldIdToName[v.fieldId]] = v.value.str;
            }
          }
        }
        metricsInt["dcgm_error"] = blank_value_field ? 1 : 0;
        rpcStatus_ = blank_value_field ? 0 : 1;
        metricsMapDouble_[entity.m_entityId] = metricsDouble;
        metricsMapInt_[entity.m_entityId] = metricsInt;
        metricsMapString_[entity.m_entityId] = metricsString;
      }

      if (FLAGS_enable_env_var_attribution) {
        std::vector<pid_t> pids = getPidsOnGpu();
        const auto& env_mappings = getEnvAttributionMappings();
        for (size_t device_id = 0; device_id < pids.size(); device_id++) {
          envMetadataMapString_[device_id] =
              getMetadataForPid(pids[device_id], env_mappings);
        }
      }

#ifdef USE_K8S_PODRESOURCES
      if (FLAGS_enable_pod_resources_attribution) {
        // Phase 1b: kubelet pod-resources gives universal pod identity per
        // GPU UUID. Join onto GPU records using DCGM_FI_DEV_UUID, which
        // lands in metricsMapString_[device_id]["gpu_uuid"].
        auto gpuPods = getPodResourcesClient()->listGpuPods();
        const auto& env_mappings = getEnvAttributionMappings();
        const auto& label_mappings =
            ::dynolog::k8s::getDefaultLabelAttributionMap();
        for (auto& [device_id, str_metrics] : metricsMapString_) {
          auto uuid_it = str_metrics.find("gpu_uuid");
          if (uuid_it == str_metrics.end() || uuid_it->second.empty()) {
            continue;
          }
          auto pod_it = gpuPods.find(uuid_it->second);
          if (pod_it == gpuPods.end()) {
            continue;
          }
          auto& env = envMetadataMapString_[device_id];
          env["pod_namespace"] = pod_it->second.pod_namespace;
          env["pod_name"] = pod_it->second.pod_name;
          env["container_name"] = pod_it->second.container_name;

          // Phase 1c: enrich with env vars + labels + ownerRefs from the
          // K8s pod spec. Cached per pod, refreshed on TTL.
          auto attrs = getK8sPodCache()->lookupAttribution(
              pod_it->second.pod_namespace,
              pod_it->second.pod_name,
              pod_it->second.container_name,
              env_mappings,
              label_mappings);
          for (auto& [k, v] : attrs) {
            env[k] = std::move(v);
          }
        }
      }
#endif // USE_K8S_PODRESOURCES
    }
  }

  // if profiling disabled, check countdown timer to see if we should
  // re-enable dcgm profiling
  if (!profEnabled_) {
    if (profPauseTimer_.count() <= 0) {
      resumeProfiling();
    } else {
      std::lock_guard<std::mutex> wguard(profLock_);
      profPauseTimer_ -= std::chrono::seconds(updateIntervalMs_ / 1000);
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
    if (metricsMapString_.find(index) != metricsMapString_.end()) {
      for (const auto& [key, val] : metricsMapString_[index]) {
        logger.logStr(key, val);
      }
    }
    logger.logInt("device", index);
    logger.finalize();
  }
}

bool DcgmGroupInfo::pauseProfiling(int duration) {
  std::lock_guard<std::mutex> wguard(profLock_);
  LOG(INFO) << "Pausing dcgm profiling";
  profPauseTimer_ = std::chrono::seconds(duration);
  profEnabled_ = false;

  if (retCode_ = dcgmProfPause_stub(dcgmHandle_); retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmProfPause() return: " << retCode_;
    return false;
  }

  return true;
}

bool DcgmGroupInfo::resumeProfiling() {
  std::lock_guard<std::mutex> wguard(profLock_);
  LOG(INFO) << "Resuming dcgm profiling";
  profEnabled_ = true;
  if (retCode_ = dcgmProfResume_stub(dcgmHandle_); retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmProfResume() return: " << retCode_;
    return false;
  }

  return true;
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
  if (standaloneMode_) {
    if (retCode_ = dcgmDisconnect_stub(dcgmHandle_); retCode_ != DCGM_ST_OK) {
      errorCode_ = retCode_;
      LOG(ERROR) << "Failed dcgmDisconnect() return: " << retCode_;
    } else {
      LOG(INFO) << "Disconnected from standalone hostengine";
    }
  } else {
    if (retCode_ = dcgmStopEmbedded_stub(dcgmHandle_); retCode_ != DCGM_ST_OK) {
      errorCode_ = retCode_;
      LOG(ERROR) << "Failed dcgmStopEmbedded() return: " << retCode_;
    } else {
      LOG(INFO) << "Stopped embedded mode";
    }
  }
  if (retCode_ = dcgmShutdown_stub(); retCode_ != DCGM_ST_OK) {
    errorCode_ = retCode_;
    LOG(ERROR) << "Failed dcgmShutdown() return: " << retCode_;
  } else {
    LOG(INFO) << "Shutdown DCGM";
  }
}

} // namespace dynolog::gpumon
