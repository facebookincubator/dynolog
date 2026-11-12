/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <chrono>
#include <memory>
#include <string>
#include <unordered_map>

namespace dynolog::k8s {

// Device-to-pod attribution returned by the kubelet pod-resources API.
// Device IDs are opaque; the GPU monitor joins them to DCGM_FI_DEV_UUID.
struct PodInfo {
  std::string pod_namespace;
  std::string pod_name;
  std::string container_name;
};

// Thin gRPC client for the kubelet pod-resources List RPC over a unix
// domain socket (default /var/lib/kubelet/pod-resources/kubelet.sock).
//
// listGpuPods() issues one List() RPC, walks per-pod/per-container device
// assignments, and returns a gpu_uuid -> PodInfo map for devices whose
// resource_name is in the comma-separated resourceNames allowlist. The
// default is "nvidia.com/gpu". Empty IDs and incomplete pod identities are
// ignored; IDs claimed by different pods or containers are omitted.
// Returns an empty map on RPC failure (logged).
//
// Thread-safe: RPCs use a snapshot of the stub under a mutex.
class PodResourcesClient {
 public:
  explicit PodResourcesClient(
      std::string socketPath,
      const std::string& resourceNames = "nvidia.com/gpu",
      std::chrono::milliseconds rpcTimeout = std::chrono::milliseconds(2000));
  ~PodResourcesClient();

  PodResourcesClient(const PodResourcesClient&) = delete;
  PodResourcesClient& operator=(const PodResourcesClient&) = delete;
  PodResourcesClient(PodResourcesClient&&) = delete;
  PodResourcesClient& operator=(PodResourcesClient&&) = delete;

  std::unordered_map<std::string, PodInfo> listGpuPods();

 private:
  // PIMPL keeps gRPC headers out of the public interface.
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

} // namespace dynolog::k8s
