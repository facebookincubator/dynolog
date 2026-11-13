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
#include <set>
#include <sstream>
#include <utility>

#include "dynolog/src/k8s/kubelet_podresources/api.grpc.pb.h"

namespace dynolog::k8s {
namespace {

std::set<std::string> parseResourceNames(const std::string& resourceNames) {
  std::set<std::string> result;
  std::istringstream input(resourceNames);
  for (std::string name; std::getline(input, name, ',');) {
    const auto first = name.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
      continue;
    }
    const auto last = name.find_last_not_of(" \t\r\n");
    result.insert(name.substr(first, last - first + 1));
  }
  return result;
}

void addAssignment(
    const std::string& deviceId,
    const PodInfo& owner,
    std::unordered_map<std::string, PodInfo>& result,
    std::set<std::string>& ambiguousIds) {
  if (deviceId.empty() || owner.pod_namespace.empty() ||
      owner.pod_name.empty() || owner.container_name.empty() ||
      ambiguousIds.count(deviceId) != 0) {
    return;
  }
  const auto [it, inserted] = result.emplace(deviceId, owner);
  if (inserted ||
      (it->second.pod_namespace == owner.pod_namespace &&
       it->second.pod_name == owner.pod_name &&
       it->second.container_name == owner.container_name)) {
    return;
  }
  result.erase(it);
  ambiguousIds.insert(deviceId);
  LOG_EVERY_N(WARNING, 100) << "PodResourcesClient: ambiguous owner for device "
                            << deviceId << "; skipping attribution";
}

} // namespace

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
      const std::string& resourceNames,
      std::chrono::milliseconds rpcTimeout)
      : socketPath_(std::move(socketPath)),
        resourceNames_(parseResourceNames(resourceNames)),
        rpcTimeout_(rpcTimeout) {
    if (resourceNames_.empty()) {
      LOG(WARNING) << "PodResourcesClient: empty device resource allowlist; "
                      "pod attribution is disabled";
    }
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

    std::set<std::string> ambiguousIds;
    for (const auto& pod : resp.pod_resources()) {
      for (const auto& container : pod.containers()) {
        const PodInfo owner{
            .pod_namespace = pod.namespace_(),
            .pod_name = pod.name(),
            .container_name = container.name(),
        };
        for (const auto& dev : container.devices()) {
          if (resourceNames_.count(dev.resource_name()) == 0) {
            continue;
          }
          for (const auto& deviceId : dev.device_ids()) {
            addAssignment(deviceId, owner, result, ambiguousIds);
          }
        }
      }
    }
    VLOG(1) << "PodResourcesClient: List() returned "
            << resp.pod_resources_size() << " pods, " << result.size()
            << " unambiguous device assignments";
    return result;
  }

  const std::string socketPath_;
  const std::set<std::string> resourceNames_;
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
    const std::string& resourceNames,
    std::chrono::milliseconds rpcTimeout)
    : impl_(
          std::make_unique<Impl>(
              std::move(socketPath),
              resourceNames,
              rpcTimeout)) {}

PodResourcesClient::~PodResourcesClient() = default;

std::unordered_map<std::string, PodInfo> PodResourcesClient::listGpuPods() {
  return impl_->listGpuPods();
}

} // namespace dynolog::k8s
