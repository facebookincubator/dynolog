/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <chrono>
#include <cstddef>
#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>

namespace dynolog::k8s {

// Caches enrichment data fetched from the K8s API for pods running on the
// local node. When watch mode is enabled, a paginated node-scoped LIST builds
// the initial snapshot and WATCH keeps it current. Cache misses retain the
// bounded per-Pod GET fallback.
//
// Each entry corresponds to one Pod (key: "<ns>/<name>") and stores its UID,
// phase, labels, owner reference, service account, and resolved per-container
// environment attribution. UID-aware updates prevent a delayed deletion for an
// old Pod from removing a same-name replacement.
class K8sPodCache {
 public:
  struct HttpResult {
    bool transportOk = false;
    long statusCode = 0;
  };

  using ChunkCallback = std::function<bool(std::string_view)>;
  using StopCallback = std::function<bool()>;
  using HttpRequest = std::function<HttpResult(
      const std::string& url,
      const std::string& bearerToken,
      bool streaming,
      const ChunkCallback& onChunk,
      const StopCallback& shouldStop)>;

  struct Options {
    // K8s API base URL. Inside a pod, kubernetes.default.svc resolves to
    // the in-cluster API server.
    std::string apiBase = "https://kubernetes.default.svc";
    std::string tokenPath =
        "/var/run/secrets/kubernetes.io/serviceaccount/token";
    std::string caPath = "/var/run/secrets/kubernetes.io/serviceaccount/ca.crt";
    // Per-pod cache TTL for fallback GETs. Entries populated by LIST/WATCH
    // remain valid until a later watch event or atomic LIST reconciliation.
    std::chrono::seconds ttl{300};
    std::chrono::seconds negativeTtl{30};
    long httpTimeoutMs = 2000;

    // When enabled, maintain a node-scoped cache using the Kubernetes Pod
    // LIST/WATCH protocol. nodeName defaults to K8S_NODE_NAME when empty.
    bool enableWatch = false;
    std::string nodeName;
    size_t listPageSize = 500;
    long watchTimeoutSeconds = 300;
    size_t maxWatchEventBytes = 1024 * 1024;
    std::chrono::milliseconds reconnectDelay{1000};

    // Optional deterministic seams for tests. Production callers leave these
    // empty and use libcurl without fallback-wait notifications.
    HttpRequest httpRequest;
    std::function<void()> onFallbackWait;
  };

  // Map: env-var name (as it appears in pod spec) -> output column name.
  // Same shape as the env-attribution CSV loaded by Utils.cpp.
  using EnvKeyMap = std::unordered_map<std::string, std::string>;
  // Map: K8s label key -> output column name. Hardcoded set of common
  // attribution labels (mkube workload-name, kueue queue-name, etc.).
  using LabelKeyMap = std::unordered_map<std::string, std::string>;

  K8sPodCache();
  explicit K8sPodCache(Options opts);
  ~K8sPodCache();

  K8sPodCache(const K8sPodCache&) = delete;
  K8sPodCache& operator=(const K8sPodCache&) = delete;
  K8sPodCache(K8sPodCache&&) = delete;
  K8sPodCache& operator=(K8sPodCache&&) = delete;

  // Returns attribution attributes for (ns, name, container), including
  // pod_uid and the raw Kubernetes pod_phase when present.
  std::unordered_map<std::string, std::string> lookupAttribution(
      const std::string& podNamespace,
      const std::string& podName,
      const std::string& containerName,
      const EnvKeyMap& envMap,
      const LabelKeyMap& labelMap);

 private:
  struct Entry; // PIMPL-style; defined in .cpp
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

// Built-in default label-attribution map. Exposed for callers (DcgmGroupInfo).
const K8sPodCache::LabelKeyMap& getDefaultLabelAttributionMap();

} // namespace dynolog::k8s
