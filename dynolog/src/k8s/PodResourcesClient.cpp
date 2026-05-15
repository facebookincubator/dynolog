/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/k8s/PodResourcesClient.h"

#include <glog/logging.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include <atomic>
#include <mutex>
#include <utility>

#include "dynolog/src/k8s/kubelet_podresources/api.grpc.pb.h"

namespace dynolog::k8s {

struct PodResourcesClient::Impl {
  // Build a fresh channel + stub. Pure-local work; safe to call without
  // holding mu_, then swap into place under the lock.
  static std::pair<
      std::shared_ptr<grpc::Channel>,
      std::shared_ptr<v1::PodResourcesLister::Stub>>
  buildChannelAndStub(const std::string& socketPath) {
    // pod-resources socket is unauthenticated AF_UNIX — InsecureChannel.
    auto channel = grpc::CreateChannel(
        "unix://" + socketPath, grpc::InsecureChannelCredentials());
    std::shared_ptr<v1::PodResourcesLister::Stub> stub =
        v1::PodResourcesLister::NewStub(channel);
    return {std::move(channel), std::move(stub)};
  }

  // Determine whether an RPC failure status warrants tearing down and
  // rebuilding the gRPC channel. gRPC's own backoff/keepalive normally
  // handles transient deadlines and busy peers; only force a reconnect
  // when the channel itself looks broken (UNAVAILABLE / UNKNOWN), or
  // after several consecutive failures of any kind.
  bool shouldReconnect(grpc::StatusCode code) {
    if (code == grpc::StatusCode::UNAVAILABLE ||
        code == grpc::StatusCode::UNKNOWN) {
      return true;
    }
    return ++consecutive_failures_ >= 3;
  }

  Impl(
      std::string socketPath,
      std::string nvidiaResourceName,
      std::chrono::milliseconds rpcTimeout)
      : socketPath_(std::move(socketPath)),
        nvidiaResourceName_(std::move(nvidiaResourceName)),
        rpcTimeout_(rpcTimeout) {
    auto [ch, st] = buildChannelAndStub(socketPath_);
    channel_ = std::move(ch);
    stub_ = std::move(st);
    LOG(INFO) << "PodResourcesClient: connected to unix://" << socketPath_;
  }

  std::unordered_map<std::string, PodInfo> listGpuPods() {
    std::unordered_map<std::string, PodInfo> result;

    // Snapshot the stub under the lock; do the RPC unlocked. Avoids
    // serializing concurrent callers behind one in-flight List(). Using
    // a shared_ptr keeps the snapshotted stub alive until the in-flight
    // RPC completes, even if a concurrent caller swaps stub_ in a
    // reconnect.
    std::shared_ptr<v1::PodResourcesLister::Stub> stub;
    {
      std::lock_guard<std::mutex> lock(mu_);
      stub = stub_;
    }
    if (stub == nullptr) {
      LOG(ERROR) << "PodResourcesClient: stub is null";
      return result;
    }

    grpc::ClientContext ctx;
    ctx.set_deadline(std::chrono::system_clock::now() + rpcTimeout_);

    v1::ListPodResourcesRequest req;
    v1::ListPodResourcesResponse resp;

    auto status = stub->List(&ctx, req, &resp);
    if (!status.ok()) {
      LOG(WARNING) << "PodResourcesClient: List() RPC failed: "
                   << status.error_code() << " " << status.error_message();
      if (shouldReconnect(status.error_code())) {
        // Build the new channel + stub WITHOUT holding mu_ (DNS / channel
        // creation can be slow); then swap atomically.
        auto [ch, st] = buildChannelAndStub(socketPath_);
        std::lock_guard<std::mutex> lock(mu_);
        channel_ = std::move(ch);
        stub_ = std::move(st);
        consecutive_failures_ = 0;
        LOG(INFO) << "PodResourcesClient: reconnected to unix://"
                  << socketPath_;
      }
      return result;
    }
    consecutive_failures_ = 0;

    int gpu_assignments = 0;
    for (const auto& pod : resp.pod_resources()) {
      for (const auto& container : pod.containers()) {
        for (const auto& dev : container.devices()) {
          if (dev.resource_name() != nvidiaResourceName_) {
            continue;
          }
          for (const auto& uuid : dev.device_ids()) {
            // device_ids for nvidia.com/gpu are the GPU UUIDs
            // (e.g. "GPU-...."), which join with DCGM_FI_DEV_UUID.
            result[uuid] = PodInfo{
                .pod_namespace = pod.namespace_(),
                .pod_name = pod.name(),
                .container_name = container.name(),
            };
            gpu_assignments++;
          }
        }
      }
    }
    VLOG(1) << "PodResourcesClient: List() returned "
            << resp.pod_resources_size() << " pods, " << gpu_assignments
            << " GPU device assignments";
    return result;
  }

  const std::string socketPath_;
  const std::string nvidiaResourceName_;
  const std::chrono::milliseconds rpcTimeout_;
  std::mutex mu_;
  // Reconnect bookkeeping — atomic so it's safe to read/increment outside
  // the channel-swap critical section.
  std::atomic<int> consecutive_failures_{0};
  std::shared_ptr<grpc::Channel> channel_;
  std::shared_ptr<v1::PodResourcesLister::Stub> stub_;
};

PodResourcesClient::PodResourcesClient(
    std::string socketPath,
    std::string nvidiaResourceName,
    std::chrono::milliseconds rpcTimeout)
    : impl_(
          std::make_unique<Impl>(
              std::move(socketPath),
              std::move(nvidiaResourceName),
              rpcTimeout)) {}

PodResourcesClient::~PodResourcesClient() = default;

std::unordered_map<std::string, PodInfo> PodResourcesClient::listGpuPods() {
  return impl_->listGpuPods();
}

} // namespace dynolog::k8s
