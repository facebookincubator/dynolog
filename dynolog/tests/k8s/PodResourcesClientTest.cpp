/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/k8s/PodResourcesClient.h"
#include "dynolog/src/k8s/Flags.h"

#include <grpcpp/grpcpp.h>
#include <gtest/gtest.h>
#include <unistd.h>

#include <cstdio>
#include <cstdlib>
#include <initializer_list>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <tuple>
#include <utility>

#include "dynolog/src/k8s/kubelet_podresources/api.grpc.pb.h"

namespace dynolog::k8s {
namespace {

constexpr char kConfiguredResources[] =
    "nvidia.com/gpu,example.com/accelerator";

using Owners =
    std::map<std::string, std::tuple<std::string, std::string, std::string>>;

Owners owners(PodResourcesClient& client) {
  Owners result;
  for (const auto& [id, pod] : client.listGpuPods()) {
    result.emplace(
        id,
        std::make_tuple(pod.pod_namespace, pod.pod_name, pod.container_name));
  }
  return result;
}

void addAssignment(
    v1::ListPodResourcesResponse& response,
    const std::string& resource,
    std::initializer_list<std::string> ids,
    const std::string& podName = "pod-a",
    const std::string& containerName = "worker",
    const std::string& podNamespace = "test-ns") {
  auto* pod = response.add_pod_resources();
  pod->set_name(podName);
  pod->set_namespace_(podNamespace);
  auto* container = pod->add_containers();
  container->set_name(containerName);
  auto* device = container->add_devices();
  device->set_resource_name(resource);
  for (const auto& id : ids) {
    device->add_device_ids(id);
  }
}

class PodResourcesService : public v1::PodResourcesLister::Service {
 public:
  void setResponse(v1::ListPodResourcesResponse response) {
    std::lock_guard<std::mutex> lock(mutex_);
    response_ = std::move(response);
    status_ = grpc::Status::OK;
  }

  void setFailure(grpc::StatusCode code) {
    std::lock_guard<std::mutex> lock(mutex_);
    status_ = grpc::Status(code, "test RPC failure");
  }

  grpc::Status List(
      grpc::ServerContext*,
      const v1::ListPodResourcesRequest*,
      v1::ListPodResourcesResponse* response) override {
    std::lock_guard<std::mutex> lock(mutex_);
    if (status_.ok()) {
      *response = response_;
    }
    return status_;
  }

 private:
  std::mutex mutex_;
  v1::ListPodResourcesResponse response_;
  grpc::Status status_;
};

class PodResourcesClientTest : public ::testing::Test {
 protected:
  void SetUp() override {
    char directory[] = "/tmp/pod-resources-test-XXXXXX";
    const char* created = mkdtemp(directory);
    ASSERT_NE(created, nullptr);
    directory_ = created;
    socketPath_ = directory_ + "/kubelet.sock";
    grpc::ServerBuilder builder;
    builder.AddListeningPort(
        "unix://" + socketPath_, grpc::InsecureServerCredentials());
    builder.RegisterService(&service_);
    server_ = builder.BuildAndStart();
    ASSERT_NE(server_, nullptr);
  }

  void TearDown() override {
    if (server_) {
      server_->Shutdown();
      server_->Wait();
      server_.reset();
    }
    if (!socketPath_.empty()) {
      std::remove(socketPath_.c_str());
    }
    if (!directory_.empty()) {
      rmdir(directory_.c_str());
    }
  }

  std::string directory_;
  std::string socketPath_;
  PodResourcesService service_;
  std::unique_ptr<grpc::Server> server_;
};

TEST_F(PodResourcesClientTest, ConfiguredResourcesIncludeMultipleDeviceTypes) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "nvidia.com/gpu", {"GPU-nvidia"}, "nvidia-pod");
  addAssignment(
      response,
      "example.com/accelerator",
      {"GPU-custom"},
      "custom-pod",
      "worker");
  addAssignment(response, "rdma/ib", {"GPU-unrelated"});
  addAssignment(response, "devic.es/fuse", {"GPU-unrelated"});
  addAssignment(response, "google.com/tpu", {"TPU-unrelated"});
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_, kConfiguredResources);

  const Owners expected{
      {"GPU-nvidia", {"test-ns", "nvidia-pod", "worker"}},
      {"GPU-custom", {"test-ns", "custom-pod", "worker"}},
  };
  EXPECT_EQ(expected, owners(client));
}

TEST_F(PodResourcesClientTest, GpuFlagDefaultRetainsNvidiaOnlyFiltering) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "nvidia.com/gpu", {"GPU-a"});
  addAssignment(response, "example.com/accelerator", {"GPU-b"});
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_, FLAGS_pod_resources_gpu_resource);

  const Owners expected{{"GPU-a", {"test-ns", "pod-a", "worker"}}};
  EXPECT_EQ(expected, owners(client));
}

TEST_F(PodResourcesClientTest, ExplicitSingleResourceOverridesGpuDefaults) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "nvidia.com/gpu", {"GPU-a"});
  addAssignment(response, "example.com/accelerator", {"GPU-b"});
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_, "example.com/accelerator");

  const Owners expected{{"GPU-b", {"test-ns", "pod-a", "worker"}}};
  EXPECT_EQ(expected, owners(client));
}

TEST_F(PodResourcesClientTest, TpuSingleResourceAndDeviceIdsRemainSupported) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "google.com/tpu", {"123456789-0", "123456789-1"});
  addAssignment(response, "nvidia.com/gpu", {"GPU-a"});
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_, FLAGS_pod_resources_tpu_resource);

  const Owners expected{
      {"123456789-0", {"test-ns", "pod-a", "worker"}},
      {"123456789-1", {"test-ns", "pod-a", "worker"}},
  };
  EXPECT_EQ(expected, owners(client));
}

TEST_F(PodResourcesClientTest, TrimsAndDeduplicatesConfiguredResources) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "example.com/gpu", {"GPU-a"});
  addAssignment(response, "nvidia.com/gpu", {"GPU-b"});
  addAssignment(response, "example.com/gpu-extra", {"GPU-c"});
  service_.setResponse(std::move(response));
  PodResourcesClient client(
      socketPath_,
      " , example.com/gpu,\t nvidia.com/gpu\r\n,example.com/gpu, ");

  const Owners expected{
      {"GPU-a", {"test-ns", "pod-a", "worker"}},
      {"GPU-b", {"test-ns", "pod-a", "worker"}},
  };
  EXPECT_EQ(expected, owners(client));
}

TEST_F(PodResourcesClientTest, EmptyAllowlistMatchesNoResources) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "nvidia.com/gpu", {"GPU-a"});
  addAssignment(response, "", {"GPU-b"});
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_, " ,\t, ");

  EXPECT_EQ(Owners{}, owners(client));
}

TEST_F(PodResourcesClientTest, IgnoresEmptyDeviceIdsAndIncompleteOwners) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "nvidia.com/gpu", {"", "GPU-a"});
  addAssignment(response, "nvidia.com/gpu", {});
  addAssignment(response, "nvidia.com/gpu", {"GPU-no-pod"}, "");
  addAssignment(response, "nvidia.com/gpu", {"GPU-no-container"}, "pod-a", "");
  addAssignment(
      response, "nvidia.com/gpu", {"GPU-no-namespace"}, "pod-a", "worker", "");
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_);

  const Owners expected{{"GPU-a", {"test-ns", "pod-a", "worker"}}};
  EXPECT_EQ(expected, owners(client));
}

TEST_F(PodResourcesClientTest, IgnoredClaimsDoNotInvalidateValidOwners) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "nvidia.com/gpu", {"GPU-a"}, "pod-a");
  addAssignment(response, "rdma/ib", {"GPU-a"}, "unrelated-pod");
  addAssignment(response, "nvidia.com/gpu", {"GPU-a"}, "");
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_);

  const Owners expected{{"GPU-a", {"test-ns", "pod-a", "worker"}}};
  EXPECT_EQ(expected, owners(client));
}

TEST_F(PodResourcesClientTest, RepeatedSameOwnerAcrossResourcesIsNotAmbiguous) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "nvidia.com/gpu", {"GPU-a", "GPU-a"});
  addAssignment(response, "example.com/accelerator", {"GPU-a"});
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_, kConfiguredResources);

  const Owners expected{{"GPU-a", {"test-ns", "pod-a", "worker"}}};
  EXPECT_EQ(expected, owners(client));
}

TEST_F(PodResourcesClientTest, DifferentPodOwnersRemainAmbiguousAfterRepeats) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "nvidia.com/gpu", {"GPU-shared"}, "pod-a");
  addAssignment(response, "example.com/accelerator", {"GPU-shared"}, "pod-b");
  addAssignment(response, "nvidia.com/gpu", {"GPU-shared"}, "pod-a");
  addAssignment(response, "nvidia.com/gpu", {"GPU-unique"}, "pod-c");
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_, kConfiguredResources);

  const Owners expected{{"GPU-unique", {"test-ns", "pod-c", "worker"}}};
  EXPECT_EQ(expected, owners(client));
}

TEST_F(PodResourcesClientTest, DifferentContainerOwnersAreAmbiguous) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "nvidia.com/gpu", {"GPU-a"}, "pod-a", "worker-a");
  addAssignment(response, "nvidia.com/gpu", {"GPU-a"}, "pod-a", "worker-b");
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_);

  EXPECT_EQ(Owners{}, owners(client));
}

TEST_F(PodResourcesClientTest, DifferentNamespaceOwnersAreAmbiguous) {
  v1::ListPodResourcesResponse response;
  addAssignment(
      response, "nvidia.com/gpu", {"GPU-a"}, "pod-a", "worker", "namespace-a");
  addAssignment(
      response, "nvidia.com/gpu", {"GPU-a"}, "pod-a", "worker", "namespace-b");
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_);

  EXPECT_EQ(Owners{}, owners(client));
}

TEST_F(PodResourcesClientTest, AmbiguityDoesNotSurviveTheNextListReply) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "nvidia.com/gpu", {"GPU-a"}, "pod-a");
  addAssignment(response, "example.com/accelerator", {"GPU-a"}, "pod-b");
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_, kConfiguredResources);
  EXPECT_EQ(Owners{}, owners(client));

  v1::ListPodResourcesResponse next;
  addAssignment(next, "nvidia.com/gpu", {"GPU-a"}, "pod-c");
  service_.setResponse(std::move(next));

  const Owners expected{{"GPU-a", {"test-ns", "pod-c", "worker"}}};
  EXPECT_EQ(expected, owners(client));
}

TEST_F(PodResourcesClientTest, FailedRpcDoesNotReturnStaleOwnersAndCanRecover) {
  v1::ListPodResourcesResponse response;
  addAssignment(response, "nvidia.com/gpu", {"GPU-a"});
  service_.setResponse(std::move(response));
  PodResourcesClient client(socketPath_, kConfiguredResources);
  const Owners initial{{"GPU-a", {"test-ns", "pod-a", "worker"}}};
  ASSERT_EQ(initial, owners(client));

  service_.setFailure(grpc::StatusCode::UNAVAILABLE);
  EXPECT_EQ(Owners{}, owners(client));

  v1::ListPodResourcesResponse next;
  addAssignment(next, "example.com/accelerator", {"GPU-b"}, "pod-b");
  service_.setResponse(std::move(next));
  const Owners expected{{"GPU-b", {"test-ns", "pod-b", "worker"}}};
  EXPECT_EQ(expected, owners(client));

  service_.setResponse({});
  EXPECT_EQ(Owners{}, owners(client));
}

} // namespace
} // namespace dynolog::k8s
