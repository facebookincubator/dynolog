/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/k8s/Flags.h"

#ifdef USE_K8S_PODRESOURCES

#include <gflags/gflags.h>

DEFINE_bool(
    enable_pod_resources_attribution,
    false,
    "Enable kubelet pod-resources attribution: query the local kubelet's "
    "pod-resources gRPC socket each cycle and join the (pod_namespace, "
    "pod_name, container_name) onto each accelerator record by device id. "
    "Used by both GPU (DcgmGroupInfo) and TPU (TpuGroupInfo) modules; "
    "filtered to a specific accelerator resource via "
    "--pod_resources_gpu_resource / --pod_resources_tpu_resource.");

DEFINE_string(
    pod_resources_socket,
    "/var/lib/kubelet/pod-resources/kubelet.sock",
    "Path to kubelet pod-resources gRPC unix socket.");

DEFINE_string(
    pod_resources_gpu_resource,
    "nvidia.com/gpu",
    "K8s extended resource name to filter for GPU device assignments. "
    "DCGM_FI_DEV_UUID values join against this resource's device_ids.");

DEFINE_string(
    pod_resources_tpu_resource,
    "google.com/tpu",
    "K8s extended resource name to filter for TPU device assignments. "
    "tpu-device-plugin accelerator_id values join against this "
    "resource's device_ids.");

#endif // USE_K8S_PODRESOURCES
