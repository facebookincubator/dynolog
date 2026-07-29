/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#ifdef USE_K8S_PODRESOURCES

#include <gflags/gflags.h>

// Shared kubelet pod-resources attribution flags. Defined once in Flags.cpp
// so both gpumon (DcgmGroupInfo) and tpumon (TpuGroupInfo) can reference
// the same FLAGS_* symbols without producing duplicate-symbol link errors.
DECLARE_bool(enable_pod_resources_attribution);
DECLARE_string(pod_resources_socket);
DECLARE_string(pod_resources_gpu_resource);
DECLARE_string(pod_resources_tpu_resource);

#endif // USE_K8S_PODRESOURCES
