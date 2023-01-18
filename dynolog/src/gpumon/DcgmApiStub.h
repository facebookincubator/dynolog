// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <gflags/gflags.h>
#include "dynolog/src/gpumon/dcgm_fields.h"
#include "dynolog/src/gpumon/dcgm_structs.h"

DECLARE_int32(dcgm_major_version);

extern "C" {
/**
 * Used to create a entity group handle which can store one or more entity Ids
 * as an opaque handle returned in \a pDcgmGrpId. Instead of executing an
 * operation separately for each entity, the DCGM group enables the user to
 * execute same operation on all the entities present in the group as a single
 * API call.
 *
 * To create the group with all the entities present on the system, the \a type
 * field should be specified as \a DCGM_GROUP_DEFAULT or \a
 * DCGM_GROUP_ALL_NVSWITCHES. To create an empty group, the \a type field should
 * be specified as \a DCGM_GROUP_EMPTY. The empty group can be updated with the
 * desired set of entities using the APIs \ref dcgmGroupAddDevice, \ref
 * dcgmGroupAddEntity, \ref dcgmGroupRemoveDevice, and \ref
 * dcgmGroupRemoveEntity.
 *
 * @param pDcgmHandle    IN: DCGM Handle
 * @param type           IN: Type of Entity Group to be formed
 * @param groupName      IN: Desired name of the GPU group specified as NULL
 * terminated C string
 * @param pDcgmGrpId    OUT: Reference to group ID
 *
 * @return
 *  - \ref DCGM_ST_OK                if the group has been created
 *  - \ref DCGM_ST_BADPARAM          if any of \a type, \a groupName, \a length
 * or \a pDcgmGrpId is invalid
 *  - \ref DCGM_ST_MAX_LIMIT         if number of groups on the system has
 * reached the max limit \a DCGM_MAX_NUM_GROUPS
 *  - \ref DCGM_ST_INIT_ERROR        if the library has not been successfully
 * initialized
 */

dcgmReturn_t dcgmGroupCreate_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGroupType_t type,
    char* groupName,
    dcgmGpuGrp_t* pDcgmGrpId);

/**
 * Used to add specified entity to the group represented by \a groupId.
 *
 * @param pDcgmHandle   IN: DCGM Handle
 * @param groupId       IN: Group Id to which device should be added
 * @param entityGroupId IN: Entity group that entityId belongs to
 * @param entityId      IN: DCGM entityId
 *
 * @return
 *  - \ref DCGM_ST_OK                   if the entity has been successfully
 * added to the group
 *  - \ref DCGM_ST_INIT_ERROR           if the library has not been successfully
 * initialized
 *  - \ref DCGM_ST_NOT_CONFIGURED       if entry corresponding to the group (\a
 * groupId) does not exists
 *  - \ref DCGM_ST_BADPARAM             if \a entityId is invalid or already
 * part of the specified group
 */

dcgmReturn_t dcgmGroupAddEntity_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId,
    dcgm_field_entity_group_t entityGroupId,
    dcgm_field_eid_t entityId);

/**
 * Used to create a group of fields and return the handle in dcgmFieldGroupId
 *
 * @param dcgmHandle         IN: DCGM handle
 * @param fieldIds           IN: Field IDs to be added to the newly-created
 * field group
 * @param fieldGroupName     IN: Unique name for this group of fields. This must
 * not be the same as any existing field groups.
 * @param dcgmFieldGroupId  OUT: Handle to the newly-created field group
 *
 * @return
 * - \ref DCGM_ST_OK                   if the field group was successfully
 * created.
 * - \ref DCGM_ST_BADPARAM             if any parameters were bad
 * - \ref DCGM_ST_INIT_ERROR           if the library has not been successfully
 * initialized.
 * - \ref DCGM_ST_MAX_LIMIT            if too many field groups already exist
 *
 */
dcgmReturn_t dcgmFieldGroupCreate_stub(
    dcgmHandle_t dcgmHandle,
    const std::vector<unsigned short>& fieldIds,
    char* fieldGroupName,
    dcgmFieldGrp_t* dcgmFieldGroupId);

/**
 * Used to destroy a group represented by \a groupId.
 * Since DCGM group is a logical grouping of entities, the properties applied on
 * the group stay intact for the individual entities even after the group is
 * destroyed.
 *
 * @param pDcgmHandle   IN: DCGM Handle
 * @param groupId       IN: Group ID
 *
 * @return
 *  - \ref DCGM_ST_OK                   if the group has been destroyed
 *  - \ref DCGM_ST_BADPARAM             if \a groupId is invalid
 *  - \ref DCGM_ST_INIT_ERROR           if the library has not been successfully
 * initialized
 *  - \ref DCGM_ST_NOT_CONFIGURED       if entry corresponding to the group does
 * not exists
 */
dcgmReturn_t dcgmGroupDestroy_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId);

/**
 * Used to remove a field group that was created with \ref dcgmFieldGroupCreate
 *
 * @param dcgmHandle         IN: DCGM handle
 * @param dcgmFieldGroupId   IN: Field group to remove
 *
 * @return
 * - \ref DCGM_ST_OK                   if the field group was successfully
 * removed
 * - \ref DCGM_ST_BADPARAM             if any parameters were bad
 * - \ref DCGM_ST_INIT_ERROR           if the library has not been successfully
 * initialized.
 *
 */
dcgmReturn_t dcgmFieldGroupDestroy_stub(
    dcgmHandle_t dcgmHandle,
    dcgmFieldGrp_t dcgmFieldGroupId);

/**
 * This method is used to initialize DCGM within this process. This must be
 * called before dcgmStartEmbedded() or dcgmConnect()
 *
 *  * @return
 *        - \ref DCGM_ST_OK                   if DCGM has been properly
 * initialized
 *        - \ref DCGM_ST_INIT_ERROR           if there was an error initializing
 * the library
 */
dcgmReturn_t dcgmInit_stub(void);

/**
 * Start an embedded host engine agent within this process.
 *
 * The agent is loaded as a shared library. This mode is provided to avoid any
 * extra jitter associated with an additional autonomous agent needs to be
 * managed. In this mode, the user has to periodically call APIs such as \ref
 * dcgmPolicyTrigger and \ref dcgmUpdateAllFields which tells DCGM to wake up
 * and perform data collection and operations needed for policy management.
 *
 * @param opMode       IN: Collect data automatically or manually when asked by
 * the user.
 * @param pDcgmHandle OUT: DCGM Handle to use for API calls
 *
 * @return
 *         - \ref DCGM_ST_OK                if DCGM was started successfully
 * within our process
 *         - \ref DCGM_ST_UNINITIALIZED     if DCGM has not been initialized
 * with \ref dcgmInit yet
 *
 */
dcgmReturn_t dcgmStartEmbedded_stub(
    dcgmOperationMode_t opMode,
    dcgmHandle_t* pDcgmHandle);

/**
 * Request that DCGM start recording updates for a given field collection.
 *
 * Note that the first update of the field will not occur until the next field
 * update cycle. To force a field update cycle, call dcgmUpdateAllFields(1).
 *
 * @param pDcgmHandle         IN: DCGM Handle
 * @param groupId             IN: Group ID representing collection of one or
 * more entities. Look at \ref dcgmGroupCreate for details on creating the
 * group. Alternatively, pass in the group id as \a DCGM_GROUP_ALL_GPUS to
 * perform operation on all the GPUs or \a DCGM_GROUP_ALL_NVSWITCHES to to
 * perform the operation on all NvSwitches.
 * @param fieldGroupId        IN: Fields to watch.
 * @param updateFreq          IN: How often to update this field in usec
 * @param maxKeepAge          IN: How long to keep data for this field in
 * seconds
 * @param maxKeepSamples      IN: Maximum number of samples to keep. 0=no limit
 *
 * @return
 *        - \ref DCGM_ST_OK                   if the call was successful
 *        - \ref DCGM_ST_BADPARAM             if a parameter is invalid
 *
 */

dcgmReturn_t dcgmWatchFields_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId,
    dcgmFieldGrp_t fieldGroupId,
    long long updateFreq,
    double maxKeepAge,
    int maxKeepSamples);

/**
 * Request updates for all field values that have updated since a given
 * timestamp
 *
 * This version works with non-GPU entities like NvSwitches
 *
 * @param pDcgmHandle         IN: DCGM Handle
 * @param groupId             IN: Group ID representing collection of one or
 * more entities. Look at \ref dcgmGroupCreate for details on creating the
 * group. Alternatively, pass in the group id as \a DCGM_GROUP_ALL_GPUS to
 * perform operation on all the GPUs or \a DCGM_GROUP_ALL_NVSWITCHES to perform
 * the operation on all NvSwitches.
 * @param fieldGroupId        IN: Fields to return data for
 * @param sinceTimestamp      IN: Timestamp to request values since in usec
 * since 1970. This will be returned in nextSinceTimestamp for subsequent calls
 * 0 = request all data
 * @param nextSinceTimestamp OUT: Timestamp to use for sinceTimestamp on next
 * call to this function
 * @param enumCB              IN: Callback to invoke for every field value
 * update. Note that multiple updates can be returned in each invocation
 * @param userData            IN: User data pointer to pass to the userData
 * field of enumCB.
 *
 * @return
 *        - \ref DCGM_ST_OK                   if the call was successful
 *        - \ref DCGM_ST_BADPARAM             if a parameter is invalid
 *
 */

dcgmReturn_t dcgmGetValuesSince_v2_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId,
    dcgmFieldGrp_t fieldGroupId,
    long long sinceTimestamp,
    long long* nextSinceTimestamp,
    dcgmFieldValueEntityEnumeration_f enumCB,
    void* userData);
}

/**
 * This method is used to get identifiers corresponding to all the
 * DCGM-supported devices on the system. The identifier represents DCGM GPU Id
 * corresponding to each GPU on the system and is immutable during the lifespan
 * of the engine. The list should be queried again if the engine is restarted.
 *
 * The GPUs returned from this function ONLY includes gpuIds of GPUs that are
 * supported by DCGM. To get gpuIds of all GPUs in the system, use
 * dcgmGetAllDevices().
 *
 *
 * @param pDcgmHandle                    IN: DCGM Handle
 * @param gpuIdList                     OUT: Array reference to fill GPU Ids
 * present on the system.
 * @param count                         OUT: Number of GPUs returned in \a
 * gpuIdList.
 *
 * @return
 *        - \ref DCGM_ST_OK                   if the call was successful.
 *        - \ref DCGM_ST_BADPARAM             if \a gpuIdList or \a count were
 * not valid.
 */
dcgmReturn_t dcgmGetAllSupportedDevices_stub(
    dcgmHandle_t pDcgmHandle,
    unsigned int gpuIdList[DCGM_MAX_NUM_DEVICES],
    int* count);

/**
 * Request latest cached field value for a field value collection
 *
 * This version works with non-GPU entities like NvSwitches
 *
 * @param pDcgmHandle        IN: DCGM Handle
 * @param groupId            IN: Group ID representing collection of one or more
 * entities. Look at \ref dcgmGroupCreate for details on creating the group.
 * Alternatively, pass in the group id as \a DCGM_GROUP_ALL_GPUS to perform
 * operation on all the GPUs or \a DCGM_GROUP_ALL_NVSWITCHES to perform the
 * operation on all NvSwitches.
 * @param fieldGroupId       IN: Fields to return data for.
 * @param enumCB             IN: Callback to invoke for every field value
 * update. Note that multiple updates can be returned in each invocation
 * @param userData           IN: User data pointer to pass to the userData field
 * of enumCB.
 *
 * @return
 *        - \ref DCGM_ST_OK                   if the call was successful
 *        - \ref DCGM_ST_NOT_SUPPORTED        if one of the entities was from a
 * non-GPU type
 *        - \ref DCGM_ST_BADPARAM             if a parameter is invalid
 *
 */
dcgmReturn_t dcgmGetLatestValues_v2_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId,
    dcgmFieldGrp_t fieldGroupId,
    dcgmFieldValueEntityEnumeration_f enumCB,
    void* userData);

/**
 * Stop the embedded host engine within this process that was started with
 * dcgmStartEmbedded
 *
 * @param pDcgmHandle IN : DCGM Handle of the embedded host engine that came
 * from dcgmStartEmbedded
 *
 * @return
 *         - \ref DCGM_ST_OK                if DCGM was stopped successfully
 * within our process
 *         - \ref DCGM_ST_UNINITIALIZED     if DCGM has not been initialized
 * with \ref dcgmInit or the embedded host engine was not running.
 *         - \ref DCGM_ST_BADPARAM          if an invalid parameter was provided
 *         - \ref DCGM_ST_INIT_ERROR        if an error occurred while trying to
 * start the host engine.
 */
dcgmReturn_t dcgmStopEmbedded_stub(dcgmHandle_t pDcgmHandle);

/**
 * This method is used to shut down DCGM. Any embedded host engines or remote
 * connections will automatically be shut down as well.
 *
 * @return
 *        - \ref DCGM_ST_OK                   if DCGM has been properly shut
 * down
 *        - \ref DCGM_ST_UNINITIALIZED        if the library was not shut down
 * properly
 */
dcgmReturn_t dcgmShutdown_stub(void);

/**
 * Get all of the profiling metric groups for a given GPU group.
 *
 * Profiling metrics are watched in groups of fields that are all watched
 * together. For instance, if you want to watch DCGM_FI_PROF_GR_ENGINE_ACTIVITY,
 * this might also be in the same group as DCGM_FI_PROF_SM_EFFICIENCY. Watching
 * this group would result in DCGM storing values for both of these metrics.
 *
 * Some groups cannot be watched concurrently as others as they utilize the same
 * hardware resource. For instance, you may not be able to watch
 * DCGM_FI_PROF_TENSOR_OP_UTIL at the same time as
 * DCGM_FI_PROF_GR_ENGINE_ACTIVITY on your hardware. At the same time, you may
 * be able to watch DCGM_FI_PROF_TENSOR_OP_UTIL at the same time as
 * DCGM_FI_PROF_NVLINK_TX_DATA.
 *
 * Metrics that can be watched concurrently will have different .majorId fields
 * in their dcgmProfMetricGroupInfo_t
 *
 * See \ref dcgmGroupCreate for details on creating a GPU group
 * See \ref dcgmProfWatchFields to actually watch a metric group
 *
 * @param pDcgmHandle        IN: DCGM Handle
 * @param metricGroups   IN/OUT: Metric groups supported for
 * metricGroups->groupId.<br> metricGroups->version should be set to
 * dcgmProfGetMetricGroups_version upon calling.
 *
 * @return
 *        - \ref DCGM_ST_OK                     if the request succeeds.
 *        - \ref DCGM_ST_BADPARAM               if a parameter is missing or
 * bad.
 *        - \ref DCGM_ST_GROUP_INCOMPATIBLE     if metricGroups->groupId's GPUs
 * are not identical GPUs.
 *        - \ref DCGM_ST_NOT_SUPPORTED          if profiling metrics are not
 * supported for the given GPU group.
 *
 */
dcgmReturn_t dcgmProfGetSupportedMetricGroups_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmProfGetMetricGroups_t* metricGroups);

/**
 * Request that DCGM start recording updates for a given list of profiling field
 * IDs.
 *
 * Once metrics have been watched by this API, any of the normal DCGM
 * field-value retrieval APIs can be used on the underlying fieldIds of this
 * metric group. See \ref dcgmGetLatestValues_v2, \ref
 * dcgmGetLatestValuesForFields, \ref dcgmEntityGetLatestValues, and \ref
 * dcgmEntitiesGetLatestValues.
 *
 * @param pDcgmHandle        IN: DCGM Handle
 * @param watchFields        IN: Details of which metric groups to watch for
 * which GPUs. See \ref dcgmProfWatchFields_v1 for details of what should be put
 * in each struct member. watchFields->version should be set to
 * dcgmProfWatchFields_version upon calling.
 *
 * @return
 *        - \ref DCGM_ST_OK                     if the call was successful
 *        - \ref DCGM_ST_BADPARAM               if a parameter is invalid
 *        - \ref DCGM_ST_NOT_SUPPORTED          if profiling metric group
 * metricGroupTag is not supported for the given GPU group.
 *        - \ref DCGM_ST_GROUP_INCOMPATIBLE     if groupId's GPUs are not
 * identical GPUs. Profiling metrics are only support for homogenous groups of
 * GPUs.
 *        - \ref DCGM_ST_PROFILING_MULTI_PASS   if any of the metric groups
 * could not be watched concurrently due to requiring the hardware to gather
 * them with multiple passes
 *
 */
dcgmReturn_t dcgmProfWatchFields_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmProfWatchFields_t* watchFields);

/**
 * Request that DCGM stop recording updates for all profiling field IDs for all
 * GPUs
 *
 * @param pDcgmHandle        IN: DCGM Handle
 * @param unwatchFields      IN: Details of which metric groups to unwatch for
 * which GPUs. See \ref dcgmProfUnwatchFields_v1 for details of what should be
 * put in each struct member. unwatchFields->version should be set to
 * dcgmProfUnwatchFields_version upon calling.
 *
 * @return
 *        - \ref DCGM_ST_OK                   if the call was successful
 *        - \ref DCGM_ST_BADPARAM             if a parameter is invalid
 *
 */
dcgmReturn_t dcgmProfUnwatchFields_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmProfUnwatchFields_t* unwatchFields);

/**
 * Request that DCGM stop recording updates for a given field collection.
 *
 * @param pDcgmHandle         IN: DCGM Handle
 * @param groupId             IN: Group ID representing collection of one or
 * more entities. Look at \ref dcgmGroupCreate for details on creating the
 * group. Alternatively, pass in the group id as \a DCGM_GROUP_ALL_GPUS to
 * perform operation on all the GPUs or \a DCGM_GROUP_ALL_NVSWITCHES to to
 * perform the operation on all NvSwitches.
 * @param fieldGroupId        IN: Fields to unwatch.
 *
 * @return
 *        - \ref DCGM_ST_OK                   if the call was successful
 *        - \ref DCGM_ST_BADPARAM             if a parameter is invalid
 *
 */
dcgmReturn_t dcgmUnwatchFields_stub(
    dcgmHandle_t pDcgmHandle,
    dcgmGpuGrp_t groupId,
    dcgmFieldGrp_t fieldGroupId);

/**
 * Pause profiling activities in DCGM. This should be used when you are
 * monitoring profiling fields from DCGM but want to be able to still run
 * developer tools like nvprof, nsight systems, and nsight compute. Profiling
 * fields start with DCGM_PROF_ and are in the field ID range 1001-1012.
 *
 * Call this API before you launch one of those tools and dcgmProfResume() after
 * the tool has completed.
 *
 * DCGM will save BLANK values while profiling is paused.
 *
 * Calling this while profiling activities are already paused is fine and will
 * be treated as a no-op.
 *
 * @param pDcgmHandle        IN: DCGM Handle
 *
 * @return
 *        - \ref DCGM_ST_OK                   If the call was successful.
 *        - \ref DCGM_ST_BADPARAM             if a parameter is invalid.
 *
 */
dcgmReturn_t dcgmProfPause_stub(dcgmHandle_t pDcgmHandle);

/**
 * Resume profiling activities in DCGM that were previously paused with
 * dcgmProfPause().
 *
 * Call this API after you have completed running other NVIDIA developer tools
 * to re-enable DCGM profiling metrics.
 *
 * DCGM will save BLANK values while profiling is paused.
 *
 * Calling this while profiling activities have already been resumed is fine and
 * will be treated as a no-op.
 *
 * @param pDcgmHandle        IN: DCGM Handle
 *
 * @return
 *        - \ref DCGM_ST_OK                   If the call was successful.
 *        - \ref DCGM_ST_BADPARAM             if a parameter is invalid.
 *
 */
dcgmReturn_t dcgmProfResume_stub(dcgmHandle_t pDcgmHandle);

/**
 * Gets the hierarchy of GPUs, GPU Instances, and Compute Instances by
 * populating a list of each entity with a reference to their parent
 *
 * @param dcgmHandle       IN: DCGM Handle
 * @param entities        OUT: array of entities in the hierarchy
 * @param numEntities  IN/OUT: Upon calling, this should be the capacity of
 * entities. Upon return, this will contain the number of entities actually
 * saved to entities.
 *
 * @return
 *        - \ref DCGM_ST_OK                if the call was successful.
 *        - \ref DCGM_ST_VER_MISMATCH      if the struct version is incorrect
 *        - \ref DCGM_ST_BADPARAM          if any parameter is invalid
 */
dcgmReturn_t dcgmGetGpuInstanceHierarchy_stub(
    dcgmHandle_t dcgmHandle,
    dcgmMigHierarchy_v2* hierarchy);
