// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/gpumon/DcgmApiStub.h"
#include <dlfcn.h>
#include <glog/logging.h>
#include <mutex>
#include <ostream>
#include <string>

constexpr char kDcgmDefaultLibPath[] = "/lib64/libdcgm.so";

DEFINE_string(
    dcgm_lib_path,
    kDcgmDefaultLibPath,
    "The path to dynamic loading DCGM shared libraries");

DEFINE_int32(
    dcgm_major_version,
    2,
    "Version of Nvidia DCGM library. Currently supports 2 and 3");

#define CHECK_NULL(val) CHECK_EQ((val), static_cast<void*>(NULL))

namespace detail {

/* a structure to hold function pointers after dynamically loading the library*/
struct dcgmApi {
  bool valid = false;
  dcgmReturn_t (*dcgmGroupCreate)(
      dcgmHandle_t pDcgmHandle,
      dcgmGroupType_t type,
      char* groupName,
      dcgmGpuGrp_t* pDcgmGrpId);
  dcgmReturn_t (*dcgmGroupAddEntity)(
      dcgmHandle_t pDcgmHandle,
      dcgmGpuGrp_t groupId,
      dcgm_field_entity_group_t entityGroupId,
      dcgm_field_eid_t entityId);
  dcgmReturn_t (*dcgmFieldGroupCreate)(
      dcgmHandle_t dcgmHandle,
      int numFieldIds,
      unsigned short* fieldIds,
      char* fieldGroupName,
      dcgmFieldGrp_t* dcgmFieldGroupId);
  dcgmReturn_t (
      *dcgmGroupDestroy)(dcgmHandle_t pDcgmHandle, dcgmGpuGrp_t groupId);
  dcgmReturn_t (*dcgmFieldGroupDestroy)(
      dcgmHandle_t dcgmHandle,
      dcgmFieldGrp_t dcgmFieldGroupId);
  dcgmReturn_t (*dcgmInit)(void);
  dcgmReturn_t (*dcgmStartEmbedded)(
      dcgmOperationMode_t opMode,
      dcgmHandle_t* pDcgmHandle);
  dcgmReturn_t (*dcgmWatchFields)(
      dcgmHandle_t pDcgmHandle,
      dcgmGpuGrp_t groupId,
      dcgmFieldGrp_t fieldGroupId,
      long long updateFreq,
      double maxKeepAge,
      int maxKeepSamples);
  dcgmReturn_t (*dcgmGetValuesSince_v2)(
      dcgmHandle_t pDcgmHandle,
      dcgmGpuGrp_t groupId,
      dcgmFieldGrp_t fieldGroupId,
      long long sinceTimestamp,
      long long* nextSinceTimestamp,
      dcgmFieldValueEntityEnumeration_f enumCB,
      void* userData);
  dcgmReturn_t (*dcgmGetAllSupportedDevices)(
      dcgmHandle_t pDcgmHandle,
      unsigned int gpuIdList[DCGM_MAX_NUM_DEVICES],
      int* count);
  dcgmReturn_t (*dcgmGetLatestValues_v2)(
      dcgmHandle_t pDcgmHandle,
      dcgmGpuGrp_t groupId,
      dcgmFieldGrp_t fieldGroupId,
      dcgmFieldValueEntityEnumeration_f enumCB,
      void* userData);
  dcgmReturn_t (*dcgmShutdown)(void);
  dcgmReturn_t (*dcgmStopEmbedded)(dcgmHandle_t pDcgmHandle);
  dcgmReturn_t (*dcgmProfGetSupportedMetricGroups)(
      dcgmHandle_t pDcgmHandle,
      dcgmProfGetMetricGroups_t* metricGroups);
  dcgmReturn_t (*dcgmProfWatchFields)(
      dcgmHandle_t pDcgmHandle,
      dcgmProfWatchFields_t* watchFields);
  dcgmReturn_t (*dcgmProfUnwatchFields)(
      dcgmHandle_t pDcgmHandle,
      dcgmProfUnwatchFields_t* unwatchFields);
  dcgmReturn_t (*dcgmUnwatchFields)(
      dcgmHandle_t pDcgmHandle,
      dcgmGpuGrp_t groupId,
      dcgmFieldGrp_t fieldGroupId);
  dcgmReturn_t (*dcgmProfPause)(dcgmHandle_t pDcgmHandle);
  dcgmReturn_t (*dcgmProfResume)(dcgmHandle_t pDcgmHandle);
  dcgmReturn_t (*dcgmGetGpuInstanceHierarchy)(
      dcgmHandle_t dcgmHandle,
      dcgmMigHierarchy_v2* hierarchy);
};

/* does dlopen and loads symbols */
dcgmApi* getDcgmAPI() {
  static std::once_flag once;
  static dcgmApi api;

  std::call_once(once, []() {
    // This is a workaround for glibc version mismatch in libdcgm.so and meta
    // Please see S278278 for more details
    void* hack = dlopen("librt.so.1", RTLD_LAZY);
    if (!hack) {
      LOG(ERROR) << "Couldn't load librt : " << dlerror();
      return;
    }
    void* handle = dlopen(FLAGS_dcgm_lib_path.c_str(), RTLD_LAZY);
    if (!handle) {
      LOG(ERROR) << "Couldn't load libdcgm : " << dlerror();
      return;
    }

#define SETAPI(name)                                        \
  api.name = (decltype(dcgmApi::name))dlsym(handle, #name); \
  CHECK_NULL(dlerror());

    SETAPI(dcgmGroupCreate);
    SETAPI(dcgmGroupAddEntity);
    SETAPI(dcgmFieldGroupCreate);
    SETAPI(dcgmGroupDestroy);
    SETAPI(dcgmFieldGroupDestroy);
    SETAPI(dcgmInit);
    SETAPI(dcgmStartEmbedded);
    SETAPI(dcgmWatchFields);
    SETAPI(dcgmGetValuesSince_v2);
    SETAPI(dcgmGetAllSupportedDevices);
    SETAPI(dcgmGetLatestValues_v2);
    SETAPI(dcgmShutdown);
    SETAPI(dcgmStopEmbedded);
    SETAPI(dcgmProfGetSupportedMetricGroups);
    SETAPI(dcgmProfWatchFields);
    SETAPI(dcgmProfUnwatchFields);
    SETAPI(dcgmUnwatchFields);
    SETAPI(dcgmProfPause);
    SETAPI(dcgmProfResume);
    SETAPI(dcgmGetGpuInstanceHierarchy);
#undef SETAPI
    api.valid = true;

    LOG(INFO) << "Loaded dcgm dynamic library";
  });

  return api.valid ? &api : nullptr;
}
} // namespace detail

inline void log_missing_api(const char* func) {
  LOG(ERROR) << " Nvidia libdcgm.so library call failed as the lib could not"
             << " be loaded : invoked from = " << func;
}

dcgmReturn_t dcgmGroupCreate_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGroupType_t type,
    char* groupName,
    dcgmGpuGrp_t* pDcgmGrpId) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmGroupCreate(pDcgmHandle, type, groupName, pDcgmGrpId);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmGroupAddEntity_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId,
    dcgm_field_entity_group_t entityGroupId,
    dcgm_field_eid_t entityId) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmGroupAddEntity(
        pDcgmHandle, groupId, entityGroupId, entityId);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmFieldGroupCreate_stub(
    dcgmHandle_t dcgmHandle,
    int numFieldIds,
    unsigned short* fieldIds,
    char* fieldGroupName,
    dcgmFieldGrp_t* dcgmFieldGroupId) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmFieldGroupCreate(
        dcgmHandle, numFieldIds, fieldIds, fieldGroupName, dcgmFieldGroupId);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmGroupDestroy_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmGroupDestroy(pDcgmHandle, groupId);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmFieldGroupDestroy_stub(
    dcgmHandle_t dcgmHandle,
    dcgmFieldGrp_t dcgmFieldGroupId) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmFieldGroupDestroy(dcgmHandle, dcgmFieldGroupId);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmInit_stub(void) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmInit();
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmStartEmbedded_stub(
    dcgmOperationMode_t opMode,
    dcgmHandle_t* pDcgmHandle) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmStartEmbedded(opMode, pDcgmHandle);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmWatchFields_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId,
    dcgmFieldGrp_t fieldGroupId,
    long long updateFreq,
    double maxKeepAge,
    int maxKeepSamples) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmWatchFields(
        pDcgmHandle,
        groupId,
        fieldGroupId,
        updateFreq,
        maxKeepAge,
        maxKeepSamples);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmGetValuesSince_v2_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId,
    dcgmFieldGrp_t fieldGroupId,
    long long sinceTimestamp,
    long long* nextSinceTimestamp,
    dcgmFieldValueEntityEnumeration_f enumCB,
    void* userData) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmGetValuesSince_v2(
        pDcgmHandle,
        groupId,
        fieldGroupId,
        sinceTimestamp,
        nextSinceTimestamp,
        enumCB,
        userData);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmGetAllSupportedDevices_stub(
    dcgmHandle_t pDcgmHandle,
    unsigned int gpuIdList[DCGM_MAX_NUM_DEVICES],
    int* count) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmGetAllSupportedDevices(pDcgmHandle, gpuIdList, count);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmGetLatestValues_v2_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId,
    dcgmFieldGrp_t fieldGroupId,
    dcgmFieldValueEntityEnumeration_f enumCB,
    void* userData) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmGetLatestValues_v2(
        pDcgmHandle, groupId, fieldGroupId, enumCB, userData);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmShutdown_stub() {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmShutdown();
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmStopEmbedded_stub(dcgmHandle_t pDcgmHandle) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmStopEmbedded(pDcgmHandle);
    ;
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmProfGetSupportedMetricGroups_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmProfGetMetricGroups_t* metricGroups) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmProfGetSupportedMetricGroups(pDcgmHandle, metricGroups);
    ;
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmProfWatchFields_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmProfWatchFields_t* watchFields) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmProfWatchFields(pDcgmHandle, watchFields);
    ;
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmProfUnwatchFields_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmProfUnwatchFields_t* unwatchFields) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmProfUnwatchFields(pDcgmHandle, unwatchFields);
    ;
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmUnwatchFields_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId,
    dcgmFieldGrp_t fieldGroupId) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmUnwatchFields(pDcgmHandle, groupId, fieldGroupId);
    ;
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmProfPause_stub(dcgmHandle_t pDcgmHandle) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmProfPause(pDcgmHandle);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmProfResume_stub(dcgmHandle_t pDcgmHandle) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmProfResume(pDcgmHandle);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}

dcgmReturn_t dcgmGetGpuInstanceHierarchy_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmMigHierarchy_v2* hierarchy) {
  if (auto api = detail::getDcgmAPI(); api) {
    return api->dcgmGetGpuInstanceHierarchy(pDcgmHandle, hierarchy);
  }
  log_missing_api(__func__);
  return DCGM_ST_LIBRARY_NOT_FOUND;
}
