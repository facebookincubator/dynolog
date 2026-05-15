/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/k8s/K8sPodCache.h"

#include <curl/curl.h> // @manual=fbsource//third-party/curl:curl
#include <glog/logging.h>
#include <nlohmann/json.hpp>

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <sstream>
#include <utility>

namespace dynolog::k8s {

namespace {

using json = nlohmann::json;

std::string readFile(const std::string& path) {
  std::ifstream f(path);
  if (!f.is_open()) {
    return {};
  }
  std::stringstream buf;
  buf << f.rdbuf();
  return buf.str();
}

std::string trim(const std::string& s) {
  size_t b = s.find_first_not_of(" \t\r\n");
  if (b == std::string::npos) {
    return {};
  }
  size_t e = s.find_last_not_of(" \t\r\n");
  return s.substr(b, e - b + 1);
}

size_t curlWrite(char* ptr, size_t size, size_t nmemb, void* userdata) {
  auto* out = static_cast<std::string*>(userdata);
  out->append(ptr, size * nmemb);
  return size * nmemb;
}

// Resolve K8s Downward-API fieldRefs we can answer from data we already
// have, without making additional API calls.
std::string resolveFieldRef(
    const std::string& fieldPath,
    const std::string& podNamespace,
    const std::string& podName,
    const std::string& podUid) {
  if (fieldPath == "metadata.name") {
    return podName;
  }
  if (fieldPath == "metadata.namespace") {
    return podNamespace;
  }
  if (fieldPath == "metadata.uid") {
    return podUid;
  }
  if (fieldPath == "spec.nodeName") {
    if (const char* n = std::getenv("K8S_NODE_NAME"); n) {
      return n;
    }
  }
  // status.podIP and status.hostIP could be resolved from the pod-spec
  // response itself, but we don't currently extract them. Skip.
  return {};
}

} // namespace

const K8sPodCache::LabelKeyMap& getDefaultLabelAttributionMap() {
  // Selected K8s labels that are useful for GPU job attribution on CKS.
  // Adding more is cheap — they all come from the same pod GET response.
  static const K8sPodCache::LabelKeyMap kLabels = {
      {"mkube.meta.com/workload-name", "mkube_workload_name"},
      {"kueue.x-k8s.io/queue-name", "kueue_queue_name"},
      {"kueue.x-k8s.io/priority-class", "kueue_priority_class"},
      {"app.kubernetes.io/component", "app_component"},
  };
  return kLabels;
}

struct K8sPodCache::Entry {
  using Clock = std::chrono::steady_clock;
  Clock::time_point fetched_at;
  bool ok = false;
  // Resolved per-container env vars: container_name -> (env_name -> value).
  std::unordered_map<std::string, std::unordered_map<std::string, std::string>>
      env_by_container;
  std::unordered_map<std::string, std::string> labels;
  std::string controller_kind;
  std::string controller_name;
};

struct K8sPodCache::Impl {
  explicit Impl(Options opts) : opts_(std::move(opts)) {
    if (!std::filesystem::exists(opts_.tokenPath)) {
      LOG(WARNING) << "K8sPodCache: serviceaccount token not present at "
                   << opts_.tokenPath
                   << "; pod-spec fetches will fail until it appears.";
    }
  }

  // Re-read the projected ServiceAccount token from disk on every fetch.
  // K8s rotates these tokens (typically every ~hour); caching the value
  // would cause silent 401s after rotation. The file lives on tmpfs so
  // the cost is negligible.
  std::string readToken() {
    return trim(readFile(opts_.tokenPath));
  }

  // Fetch + parse pod spec; populate entry. Returns true on success.
  bool fetchPod(const std::string& ns, const std::string& name, Entry& out) {
    std::string url =
        opts_.apiBase + "/api/v1/namespaces/" + ns + "/pods/" + name;

    std::string body;
    long httpCode = 0;

    CURL* curl = curl_easy_init();
    if (!curl) {
      LOG(ERROR) << "K8sPodCache: curl_easy_init failed";
      return false;
    }

    std::string token = readToken();
    if (token.empty()) {
      LOG(WARNING) << "K8sPodCache: empty serviceaccount token at "
                   << opts_.tokenPath << "; skipping fetch for " << ns << "/"
                   << name;
      curl_easy_cleanup(curl);
      return false;
    }

    struct curl_slist* headers = nullptr;
    std::string authHeader = "Authorization: Bearer " + token;
    headers = curl_slist_append(headers, authHeader.c_str());
    headers = curl_slist_append(headers, "Accept: application/json");
    if (headers == nullptr) {
      LOG(WARNING) << "K8sPodCache: curl_slist_append failed for " << ns << "/"
                   << name;
      curl_easy_cleanup(curl);
      return false;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, opts_.httpTimeoutMs);
    if (!opts_.caPath.empty()) {
      curl_easy_setopt(curl, CURLOPT_CAINFO, opts_.caPath.c_str());
    }

    auto rc = curl_easy_perform(curl);
    if (rc == CURLE_OK) {
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    } else {
      LOG(WARNING) << "K8sPodCache: curl_easy_perform failed for " << ns << "/"
                   << name << ": " << curl_easy_strerror(rc);
    }
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (rc != CURLE_OK || httpCode < 200 || httpCode >= 300) {
      LOG(WARNING) << "K8sPodCache: GET " << url
                   << " returned http=" << httpCode;
      return false;
    }

    try {
      auto pod = json::parse(body);
      const auto& meta = pod.at("metadata");
      const auto& spec = pod.at("spec");

      std::string podUid = meta.value("uid", "");

      if (auto it = meta.find("labels"); it != meta.end() && it->is_object()) {
        for (auto label = it->begin(); label != it->end(); ++label) {
          if (label->is_string()) {
            out.labels[label.key()] = label->get<std::string>();
          }
        }
      }
      if (auto refs = meta.find("ownerReferences");
          refs != meta.end() && refs->is_array() && !refs->empty()) {
        const auto& first = refs->at(0);
        out.controller_kind = first.value("kind", "");
        out.controller_name = first.value("name", "");
      }

      if (auto containers = spec.find("containers");
          containers != spec.end() && containers->is_array()) {
        for (const auto& c : *containers) {
          std::string cname = c.value("name", "");
          if (cname.empty()) {
            continue;
          }
          auto& env_map = out.env_by_container[cname];
          if (auto envIt = c.find("env");
              envIt != c.end() && envIt->is_array()) {
            for (const auto& e : *envIt) {
              std::string ename = e.value("name", "");
              if (ename.empty()) {
                continue;
              }
              if (auto v = e.find("value"); v != e.end() && v->is_string()) {
                env_map[ename] = v->get<std::string>();
                continue;
              }
              if (auto vf = e.find("valueFrom");
                  vf != e.end() && vf->is_object()) {
                if (auto fr = vf->find("fieldRef");
                    fr != vf->end() && fr->is_object()) {
                  std::string fp = fr->value("fieldPath", "");
                  std::string resolved = resolveFieldRef(fp, ns, name, podUid);
                  if (!resolved.empty()) {
                    env_map[ename] = std::move(resolved);
                  }
                }
                // configMapKeyRef / secretKeyRef intentionally skipped.
              }
            }
          }
        }
      }
      out.ok = true;
      return true;
    } catch (const std::exception& e) {
      LOG(WARNING) << "K8sPodCache: failed to parse pod spec for " << ns << "/"
                   << name << ": " << e.what();
      return false;
    }
  }

  std::unordered_map<std::string, std::string> lookupAttribution(
      const std::string& ns,
      const std::string& name,
      const std::string& container,
      const EnvKeyMap& envMap,
      const LabelKeyMap& labelMap) {
    std::unordered_map<std::string, std::string> result;
    std::string key = ns + "/" + name;

    bool needs_fetch = false;
    {
      std::lock_guard<std::mutex> lk(mu_);
      auto it = cache_.find(key);
      if (it == cache_.end()) {
        needs_fetch = true;
      } else {
        auto age = Entry::Clock::now() - it->second.fetched_at;
        auto ttl = it->second.ok ? opts_.ttl : opts_.negativeTtl;
        if (age >= ttl) {
          needs_fetch = true;
        }
      }
    }

    if (needs_fetch) {
      // Fetch outside the lock; concurrent fetches for the same key are
      // tolerated (rare, and idempotent).
      Entry fresh;
      fresh.ok = fetchPod(ns, name, fresh);
      // Stamp fetched_at AFTER the network call returns so the entry's
      // recorded age reflects when the data was actually fresh, not when
      // we started the (potentially slow) HTTP request.
      fresh.fetched_at = Entry::Clock::now();
      std::lock_guard<std::mutex> lk(mu_);
      // insert_or_assign returns the iterator; reuse it so we don't
      // re-find under the same lock.
      auto [it, _] = cache_.insert_or_assign(key, std::move(fresh));
      if (!it->second.ok) {
        return result;
      }
      copyAttribution(it->second, container, envMap, labelMap, result);
      return result;
    }

    std::lock_guard<std::mutex> lk(mu_);
    auto it = cache_.find(key);
    if (it == cache_.end() || !it->second.ok) {
      return result;
    }
    copyAttribution(it->second, container, envMap, labelMap, result);
    return result;
  }

  // Common projection from a cached Entry into the flat attribution map
  // returned to the caller. Caller must already hold mu_ (if reading from
  // cache_) or own the Entry (if just-inserted).
  static void copyAttribution(
      const Entry& entry,
      const std::string& container,
      const EnvKeyMap& envMap,
      const LabelKeyMap& labelMap,
      std::unordered_map<std::string, std::string>& result) {
    // env vars: look up requested keys in this container's env map.
    if (auto cit = entry.env_by_container.find(container);
        cit != entry.env_by_container.end()) {
      for (const auto& [env_key, column] : envMap) {
        auto eit = cit->second.find(env_key);
        if (eit != cit->second.end() && !eit->second.empty()) {
          result[column] = eit->second;
        }
      }
    }
    // labels.
    for (const auto& [label_key, column] : labelMap) {
      auto lit = entry.labels.find(label_key);
      if (lit != entry.labels.end() && !lit->second.empty()) {
        result[column] = lit->second;
      }
    }
    // owner refs.
    if (!entry.controller_kind.empty()) {
      result["controller_kind"] = entry.controller_kind;
    }
    if (!entry.controller_name.empty()) {
      result["controller_name"] = entry.controller_name;
    }
  }

  Options opts_;
  std::mutex mu_;
  std::unordered_map<std::string, Entry> cache_;
};

K8sPodCache::K8sPodCache() : K8sPodCache(Options{}) {}

K8sPodCache::K8sPodCache(Options opts)
    : impl_(std::make_unique<Impl>(std::move(opts))) {}

K8sPodCache::~K8sPodCache() = default;

std::unordered_map<std::string, std::string> K8sPodCache::lookupAttribution(
    const std::string& podNamespace,
    const std::string& podName,
    const std::string& containerName,
    const EnvKeyMap& envMap,
    const LabelKeyMap& labelMap) {
  return impl_->lookupAttribution(
      podNamespace, podName, containerName, envMap, labelMap);
}

} // namespace dynolog::k8s
