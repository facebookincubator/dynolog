/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <chrono>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace dynolog::k8s {

// Caches enrichment data fetched from the K8s API for pods running on the
// local node. Each entry corresponds to one pod (key: "<ns>/<name>"), and
// stores a flat map of attribution columns (env vars + labels + owner refs)
// already resolved per-container.
//
// Phase 1b's PodResourcesClient gives us (namespace, name, container) per
// GPU. K8sPodCache then turns that into the actual attribution attributes
// (mast_job, mast_owner, controller_kind, etc.) that land in the Scuba
// row.
//
// Network access uses libcurl + the in-pod ServiceAccount bearer token and
// CA cert at /var/run/secrets/kubernetes.io/serviceaccount/{token,ca.crt}.
//
// Cache semantics: per-pod TTL. A miss triggers a single GET; subsequent
// lookups within ttl reuse the cached attributes. Stale entries are
// re-fetched on next access. Failed lookups are negatively cached for a
// short window to avoid hammering the API for pods that have been deleted.
class K8sPodCache {
 public:
  struct Options {
    // K8s API base URL. Inside a pod, kubernetes.default.svc resolves to
    // the in-cluster API server.
    std::string apiBase = "https://kubernetes.default.svc";
    std::string tokenPath =
        "/var/run/secrets/kubernetes.io/serviceaccount/token";
    std::string caPath = "/var/run/secrets/kubernetes.io/serviceaccount/ca.crt";
    // Per-pod cache TTL (seconds). Pod specs are immutable for the
    // attributes we care about, so a long TTL is safe.
    std::chrono::seconds ttl{300};
    std::chrono::seconds negativeTtl{30};
    long httpTimeoutMs = 2000;
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

  // Returns attribution attributes for (ns, name, container).
  // - Looks up env vars whose names appear in envMap, resolving them
  //   from spec.containers[<container>].env (literal values + downward-API
  //   fieldRefs we can resolve locally).
  // - Looks up labels whose keys appear in labelMap.
  // - Adds controller_kind + controller_name from
  //   metadata.ownerReferences[0] when present.
  // Returns empty map on cache miss / fetch failure.
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
