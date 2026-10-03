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

#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <mutex>
#include <sstream>
#include <thread>
#include <unordered_set>
#include <utility>

#include "dynolog/src/k8s/Flags.h"

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
  const size_t b = s.find_first_not_of(" \t\r\n");
  if (b == std::string::npos) {
    return {};
  }
  const size_t e = s.find_last_not_of(" \t\r\n");
  return s.substr(b, e - b + 1);
}

std::string urlEncode(std::string_view input) {
  std::ostringstream encoded;
  encoded << std::uppercase << std::hex;
  for (const unsigned char c : input) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.' ||
        c == '~') {
      encoded << static_cast<char>(c);
    } else {
      encoded << '%' << std::setw(2) << std::setfill('0')
              << static_cast<unsigned int>(c);
    }
  }
  return encoded.str();
}

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
    if (const char* nodeName = std::getenv("K8S_NODE_NAME"); nodeName) {
      return nodeName;
    }
  }
  return {};
}

K8sPodCache::Options defaultOptions() {
  K8sPodCache::Options opts;
  opts.enableWatch = isK8sPodWatchEnabled();
  if (const char* nodeName = std::getenv("K8S_NODE_NAME"); nodeName) {
    opts.nodeName = nodeName;
  }
  return opts;
}

} // namespace

const K8sPodCache::LabelKeyMap& getDefaultLabelAttributionMap() {
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

  Clock::time_point fetchedAt;
  bool ok = false;
  bool watchOwned = false;
  std::string uid;
  std::string resourceVersion;
  std::string phase;
  std::unordered_map<std::string, std::unordered_map<std::string, std::string>>
      envByContainer;
  std::unordered_map<std::string, std::string> labels;
  std::string serviceAccount;
  std::string controllerKind;
  std::string controllerName;
};

struct K8sPodCache::Impl {
  enum class ListOutcome { kSuccess, kRetry };
  enum class WatchOutcome { kReconnect, kRetry, kRelist };
  enum class EventOutcome { kContinue, kRelist };

  struct CurlWriteContext {
    const ChunkCallback* callback;
  };

  struct CurlProgressContext {
    const StopCallback* shouldStop;
  };

  explicit Impl(Options opts) : opts_(std::move(opts)) {
    if (opts_.nodeName.empty()) {
      if (const char* nodeName = std::getenv("K8S_NODE_NAME"); nodeName) {
        opts_.nodeName = nodeName;
      }
    }
    if (!std::filesystem::exists(opts_.tokenPath)) {
      LOG(WARNING) << "K8sPodCache: serviceaccount token not present at "
                   << opts_.tokenPath
                   << "; Kubernetes API requests will fail until it appears.";
    }
    watchEnabled_ = opts_.enableWatch && !opts_.nodeName.empty();
    if (opts_.enableWatch && opts_.nodeName.empty()) {
      LOG(WARNING) << "K8sPodCache: watch requested without K8S_NODE_NAME; "
                      "using fallback Pod GETs only";
    }
  }

  Impl(const Impl&) = delete;
  Impl& operator=(const Impl&) = delete;
  Impl(Impl&&) = delete;
  Impl& operator=(Impl&&) = delete;

  ~Impl() {
    {
      std::lock_guard<std::mutex> lock(mu_);
      stopping_.store(true, std::memory_order_relaxed);
    }
    cv_.notify_all();
    if (watchThread_.joinable()) {
      watchThread_.join();
    }
  }

  void start() {
    if (watchEnabled_) {
      watchThread_ = std::thread([this] { watchLoop(); });
    }
  }

  std::string readToken() const {
    return trim(readFile(opts_.tokenPath));
  }

  static size_t
  curlWrite(char* ptr, size_t size, size_t nmemb, void* userdata) {
    const size_t bytes = size * nmemb;
    auto* context = static_cast<CurlWriteContext*>(userdata);
    if (!context || !context->callback) {
      return 0;
    }
    return (*context->callback)(std::string_view(ptr, bytes)) ? bytes : 0;
  }

  static int
  curlProgress(void* userdata, curl_off_t, curl_off_t, curl_off_t, curl_off_t) {
    auto* context = static_cast<CurlProgressContext*>(userdata);
    if (!context || !context->shouldStop) {
      return 1;
    }
    return (*context->shouldStop)() ? 1 : 0;
  }

  HttpResult curlRequest(
      const std::string& url,
      const std::string& token,
      bool streaming,
      const ChunkCallback& onChunk,
      const StopCallback& shouldStop) const {
    CURL* curl = curl_easy_init();
    if (!curl) {
      LOG(ERROR) << "K8sPodCache: curl_easy_init failed";
      return {};
    }

    const std::string authHeader = "Authorization: Bearer " + token;
    struct curl_slist* headers = curl_slist_append(nullptr, authHeader.c_str());
    if (!headers) {
      LOG(WARNING) << "K8sPodCache: curl_slist_append failed for " << url;
      curl_easy_cleanup(curl);
      return {};
    }
    struct curl_slist* completeHeaders =
        curl_slist_append(headers, "Accept: application/json");
    if (!completeHeaders) {
      LOG(WARNING) << "K8sPodCache: curl_slist_append failed for " << url;
      curl_slist_free_all(headers);
      curl_easy_cleanup(curl);
      return {};
    }
    headers = completeHeaders;

    CurlWriteContext writeContext{&onChunk};
    CurlProgressContext progressContext{&shouldStop};
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_NOPROXY, "*");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &Impl::curlWrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &writeContext);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, opts_.httpTimeoutMs);
    if (streaming) {
      curl_easy_setopt(
          curl,
          CURLOPT_TIMEOUT_MS,
          opts_.watchTimeoutSeconds * 1000 + opts_.httpTimeoutMs);
    } else {
      curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, opts_.httpTimeoutMs);
    }
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, &Impl::curlProgress);
    curl_easy_setopt(curl, CURLOPT_XFERINFODATA, &progressContext);
    if (!opts_.caPath.empty()) {
      curl_easy_setopt(curl, CURLOPT_CAINFO, opts_.caPath.c_str());
    }

    const CURLcode rc = curl_easy_perform(curl);
    long statusCode = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &statusCode);
    if (rc != CURLE_OK && rc != CURLE_WRITE_ERROR &&
        !(rc == CURLE_ABORTED_BY_CALLBACK && shouldStop())) {
      LOG(WARNING) << "K8sPodCache: request failed for " << url << ": "
                   << curl_easy_strerror(rc);
    }
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    return {rc == CURLE_OK, statusCode};
  }

  HttpResult request(
      const std::string& url,
      bool streaming,
      const ChunkCallback& onChunk) const {
    const std::string token = readToken();
    if (token.empty()) {
      LOG(WARNING) << "K8sPodCache: empty serviceaccount token at "
                   << opts_.tokenPath << "; skipping request to " << url;
      return {};
    }
    const StopCallback shouldStop = [this] {
      return stopping_.load(std::memory_order_relaxed);
    };
    if (opts_.httpRequest) {
      return opts_.httpRequest(url, token, streaming, onChunk, shouldStop);
    }
    return curlRequest(url, token, streaming, onChunk, shouldStop);
  }

  static bool
  parsePod(const json& pod, Entry& out, std::string* key = nullptr) {
    try {
      const auto& metadata = pod.at("metadata");
      const auto& spec = pod.at("spec");
      const std::string podNamespace = metadata.value("namespace", "");
      const std::string podName = metadata.value("name", "");
      const std::string podUid = metadata.value("uid", "");
      if (podNamespace.empty() || podName.empty() || podUid.empty()) {
        return false;
      }

      Entry parsed;
      parsed.ok = true;
      parsed.uid = podUid;
      parsed.resourceVersion = metadata.value("resourceVersion", "");
      parsed.serviceAccount = spec.value("serviceAccountName", "");
      if (const auto status = pod.find("status");
          status != pod.end() && status->is_object()) {
        parsed.phase = status->value("phase", "");
      }

      if (const auto labels = metadata.find("labels");
          labels != metadata.end() && labels->is_object()) {
        for (auto label = labels->begin(); label != labels->end(); ++label) {
          if (label->is_string()) {
            parsed.labels[label.key()] = label->get<std::string>();
          }
        }
      }
      if (const auto refs = metadata.find("ownerReferences");
          refs != metadata.end() && refs->is_array() && !refs->empty()) {
        const auto& first = refs->at(0);
        parsed.controllerKind = first.value("kind", "");
        parsed.controllerName = first.value("name", "");
      }

      if (const auto containers = spec.find("containers");
          containers != spec.end() && containers->is_array()) {
        for (const auto& container : *containers) {
          const std::string containerName = container.value("name", "");
          if (containerName.empty()) {
            continue;
          }
          auto& envMap = parsed.envByContainer[containerName];
          if (const auto env = container.find("env");
              env != container.end() && env->is_array()) {
            for (const auto& variable : *env) {
              const std::string name = variable.value("name", "");
              if (name.empty()) {
                continue;
              }
              if (const auto value = variable.find("value");
                  value != variable.end() && value->is_string()) {
                envMap[name] = value->get<std::string>();
                continue;
              }
              if (const auto valueFrom = variable.find("valueFrom");
                  valueFrom != variable.end() && valueFrom->is_object()) {
                if (const auto fieldRef = valueFrom->find("fieldRef");
                    fieldRef != valueFrom->end() && fieldRef->is_object()) {
                  const std::string resolved = resolveFieldRef(
                      fieldRef->value("fieldPath", ""),
                      podNamespace,
                      podName,
                      podUid);
                  if (!resolved.empty()) {
                    envMap[name] = resolved;
                  }
                }
              }
            }
          }
        }
      }

      parsed.fetchedAt = Entry::Clock::now();
      out = std::move(parsed);
      if (key) {
        *key = podNamespace + "/" + podName;
      }
      return true;
    } catch (const std::exception& e) {
      LOG(WARNING) << "K8sPodCache: failed to parse Pod: " << e.what();
      return false;
    }
  }

  bool fetchPod(const std::string& ns, const std::string& name, Entry& out) {
    const std::string url = opts_.apiBase + "/api/v1/namespaces/" +
        urlEncode(ns) + "/pods/" + urlEncode(name);
    std::string body;
    const HttpResult response =
        request(url, false, [&body](std::string_view chunk) {
          body.append(chunk.data(), chunk.size());
          return true;
        });
    if (!response.transportOk || response.statusCode < 200 ||
        response.statusCode >= 300) {
      LOG(WARNING) << "K8sPodCache: GET " << url
                   << " returned http=" << response.statusCode;
      return false;
    }

    try {
      if (!parsePod(json::parse(body), out)) {
        LOG(WARNING) << "K8sPodCache: incomplete Pod response for " << ns << "/"
                     << name;
        return false;
      }
      return true;
    } catch (const std::exception& e) {
      LOG(WARNING) << "K8sPodCache: failed to parse Pod response for " << ns
                   << "/" << name << ": " << e.what();
      return false;
    }
  }

  std::string listUrl(const std::string& continueToken) const {
    std::string url = opts_.apiBase + "/api/v1/pods?fieldSelector=" +
        urlEncode("spec.nodeName=" + opts_.nodeName) +
        "&limit=" + std::to_string(opts_.listPageSize);
    if (!continueToken.empty()) {
      url += "&continue=" + urlEncode(continueToken);
    }
    return url;
  }

  std::string watchUrl(const std::string& resourceVersion) const {
    return opts_.apiBase +
        "/api/v1/pods?watch=true&allowWatchBookmarks=true&fieldSelector=" +
        urlEncode("spec.nodeName=" + opts_.nodeName) +
        "&resourceVersion=" + urlEncode(resourceVersion) +
        "&timeoutSeconds=" + std::to_string(opts_.watchTimeoutSeconds);
  }

  ListOutcome listPods(std::string& resourceVersion) {
    std::unordered_map<std::string, Entry> snapshot;
    std::string continueToken;
    std::string listResourceVersion;

    do {
      std::string body;
      const HttpResult response = request(
          listUrl(continueToken), false, [&body](std::string_view chunk) {
            body.append(chunk.data(), chunk.size());
            return true;
          });
      if (!response.transportOk || response.statusCode < 200 ||
          response.statusCode >= 300) {
        LOG(WARNING) << "K8sPodCache: Pod LIST returned http="
                     << response.statusCode;
        return ListOutcome::kRetry;
      }

      try {
        const auto page = json::parse(body);
        const auto& metadata = page.at("metadata");
        const std::string pageResourceVersion =
            metadata.value("resourceVersion", "");
        if (pageResourceVersion.empty()) {
          LOG(WARNING) << "K8sPodCache: Pod LIST omitted resourceVersion";
          return ListOutcome::kRetry;
        }
        if (listResourceVersion.empty()) {
          listResourceVersion = pageResourceVersion;
        } else if (listResourceVersion != pageResourceVersion) {
          LOG(WARNING) << "K8sPodCache: Pod LIST resourceVersion changed "
                          "during pagination";
          return ListOutcome::kRetry;
        }

        for (const auto& pod : page.at("items")) {
          Entry entry;
          std::string key;
          if (!parsePod(pod, entry, &key)) {
            LOG(WARNING) << "K8sPodCache: Pod LIST contained invalid item";
            return ListOutcome::kRetry;
          }
          entry.watchOwned = true;
          snapshot.insert_or_assign(std::move(key), std::move(entry));
        }
        continueToken = metadata.value("continue", "");
      } catch (const std::exception& e) {
        LOG(WARNING) << "K8sPodCache: failed to parse Pod LIST: " << e.what();
        return ListOutcome::kRetry;
      }
    } while (!continueToken.empty() &&
             !stopping_.load(std::memory_order_relaxed));

    if (stopping_.load(std::memory_order_relaxed)) {
      return ListOutcome::kRetry;
    }

    {
      std::lock_guard<std::mutex> lock(mu_);
      std::unordered_set<std::string> affected;
      affected.reserve(
          cache_.size() + snapshot.size() + fetchesInFlight_.size());
      for (const auto& [key, _] : cache_) {
        affected.insert(key);
      }
      for (const auto& [key, _] : snapshot) {
        affected.insert(key);
      }
      affected.insert(fetchesInFlight_.begin(), fetchesInFlight_.end());
      for (const auto& key : affected) {
        ++generations_[key];
      }

      for (const auto& key : fetchesInFlight_) {
        if (snapshot.count(key) == 0) {
          Entry tombstone;
          tombstone.fetchedAt = Entry::Clock::now();
          snapshot.emplace(key, std::move(tombstone));
        }
      }
      cache_ = std::move(snapshot);

      for (auto it = generations_.begin(); it != generations_.end();) {
        if (cache_.count(it->first) == 0 &&
            fetchesInFlight_.count(it->first) == 0) {
          it = generations_.erase(it);
        } else {
          ++it;
        }
      }
    }

    resourceVersion = std::move(listResourceVersion);
    cv_.notify_all();
    return ListOutcome::kSuccess;
  }

  EventOutcome handleWatchEvent(
      const std::string& line,
      std::string& resourceVersion) {
    try {
      const auto event = json::parse(line);
      const std::string type = event.value("type", "");
      const auto& object = event.at("object");
      if (type == "ERROR") {
        if (object.value("code", 0) == 410 ||
            object.value("reason", "") == "Expired") {
          return EventOutcome::kRelist;
        }
        LOG(WARNING) << "K8sPodCache: Pod WATCH error event: " << object.dump();
        return EventOutcome::kContinue;
      }

      const auto& metadata = object.at("metadata");
      const std::string eventResourceVersion =
          metadata.value("resourceVersion", "");
      if (type == "BOOKMARK") {
        if (!eventResourceVersion.empty()) {
          resourceVersion = eventResourceVersion;
        }
        return EventOutcome::kContinue;
      }

      if (type != "ADDED" && type != "MODIFIED" && type != "DELETED") {
        LOG(WARNING) << "K8sPodCache: unexpected Pod WATCH event type: "
                     << type;
        return EventOutcome::kRelist;
      }

      Entry entry;
      std::string key;
      if (!parsePod(object, entry, &key)) {
        LOG(WARNING) << "K8sPodCache: invalid Pod WATCH object";
        return EventOutcome::kRelist;
      }

      bool changed = false;
      {
        std::lock_guard<std::mutex> lock(mu_);
        if (type == "ADDED" || type == "MODIFIED") {
          ++generations_[key];
          entry.watchOwned = true;
          cache_.insert_or_assign(key, std::move(entry));
          changed = true;
        } else {
          const auto cached = cache_.find(key);
          if (cached == cache_.end() || cached->second.uid == entry.uid) {
            ++generations_[key];
            if (fetchesInFlight_.count(key) != 0) {
              Entry tombstone;
              tombstone.fetchedAt = Entry::Clock::now();
              cache_.insert_or_assign(key, std::move(tombstone));
            } else {
              cache_.erase(key);
              generations_.erase(key);
            }
            changed = true;
          }
        }
      }
      if (changed) {
        cv_.notify_all();
      }
      if (!eventResourceVersion.empty()) {
        resourceVersion = eventResourceVersion;
      }
      return EventOutcome::kContinue;
    } catch (const std::exception& e) {
      LOG(WARNING) << "K8sPodCache: failed to parse Pod WATCH event: "
                   << e.what();
      return EventOutcome::kRelist;
    }
  }

  WatchOutcome watchPods(std::string& resourceVersion) {
    std::string pending;
    bool relist = false;
    bool oversized = false;
    const HttpResult response =
        request(watchUrl(resourceVersion), true, [&](std::string_view chunk) {
          while (!chunk.empty()) {
            const size_t newline = chunk.find('\n');
            const size_t partSize =
                newline == std::string_view::npos ? chunk.size() : newline;
            if (partSize > opts_.maxWatchEventBytes ||
                pending.size() > opts_.maxWatchEventBytes - partSize) {
              oversized = true;
              return false;
            }
            pending.append(chunk.data(), partSize);
            if (newline == std::string_view::npos) {
              break;
            }

            const std::string line = trim(pending);
            pending.clear();
            chunk.remove_prefix(newline + 1);
            if (!line.empty() &&
                handleWatchEvent(line, resourceVersion) ==
                    EventOutcome::kRelist) {
              relist = true;
              return false;
            }
          }
          return !stopping_.load(std::memory_order_relaxed);
        });

    if (oversized) {
      LOG(WARNING) << "K8sPodCache: Pod WATCH event exceeded "
                   << opts_.maxWatchEventBytes << " bytes";
      return WatchOutcome::kRelist;
    }
    if (response.statusCode == 410 || relist) {
      return WatchOutcome::kRelist;
    }
    if (response.transportOk &&
        (response.statusCode < 200 || response.statusCode >= 300)) {
      LOG(WARNING) << "K8sPodCache: Pod WATCH returned http="
                   << response.statusCode;
      return WatchOutcome::kRelist;
    }
    if (!response.transportOk) {
      if (!stopping_.load(std::memory_order_relaxed)) {
        LOG(WARNING) << "K8sPodCache: Pod WATCH disconnected, http="
                     << response.statusCode;
      }
      return WatchOutcome::kRetry;
    }
    return WatchOutcome::kReconnect;
  }

  void waitForRetry() {
    std::unique_lock<std::mutex> lock(mu_);
    cv_.wait_for(lock, opts_.reconnectDelay, [this] {
      return stopping_.load(std::memory_order_relaxed);
    });
  }

  void watchLoop() {
    std::string resourceVersion;
    while (!stopping_.load(std::memory_order_relaxed)) {
      if (listPods(resourceVersion) != ListOutcome::kSuccess) {
        waitForRetry();
        continue;
      }

      while (!stopping_.load(std::memory_order_relaxed)) {
        const WatchOutcome outcome = watchPods(resourceVersion);
        if (outcome == WatchOutcome::kRelist) {
          waitForRetry();
          break;
        }
        if (outcome == WatchOutcome::kRetry) {
          waitForRetry();
        }
      }
    }
  }

  static void copyAttribution(
      const Entry& entry,
      const std::string& container,
      const EnvKeyMap& envMap,
      const LabelKeyMap& labelMap,
      std::unordered_map<std::string, std::string>& result) {
    if (const auto containerIt = entry.envByContainer.find(container);
        containerIt != entry.envByContainer.end()) {
      for (const auto& [envKey, column] : envMap) {
        const auto envIt = containerIt->second.find(envKey);
        if (envIt != containerIt->second.end() && !envIt->second.empty()) {
          result[column] = envIt->second;
        }
      }
    }
    if (!entry.uid.empty()) {
      result["pod_uid"] = entry.uid;
    }
    if (!entry.phase.empty()) {
      result["pod_phase"] = entry.phase;
    }
    if (!entry.serviceAccount.empty()) {
      result["service_account"] = entry.serviceAccount;
    }
    for (const auto& [labelKey, column] : labelMap) {
      const auto labelIt = entry.labels.find(labelKey);
      if (labelIt != entry.labels.end() && !labelIt->second.empty()) {
        result[column] = labelIt->second;
      }
    }
    if (!entry.controllerKind.empty()) {
      result["controller_kind"] = entry.controllerKind;
    }
    if (!entry.controllerName.empty()) {
      result["controller_name"] = entry.controllerName;
    }
  }

  std::unordered_map<std::string, std::string> lookupAttribution(
      const std::string& ns,
      const std::string& name,
      const std::string& container,
      const EnvKeyMap& envMap,
      const LabelKeyMap& labelMap) {
    const std::string key = ns + "/" + name;
    uint64_t fetchGeneration = 0;

    for (;;) {
      std::unique_lock<std::mutex> lock(mu_);
      const auto cached = cache_.find(key);
      if (cached != cache_.end()) {
        const auto ttl = cached->second.ok ? opts_.ttl : opts_.negativeTtl;
        const bool fresh = cached->second.watchOwned && cached->second.ok
            ? true
            : Entry::Clock::now() - cached->second.fetchedAt < ttl;
        if (fresh) {
          std::unordered_map<std::string, std::string> result;
          if (cached->second.ok) {
            copyAttribution(
                cached->second, container, envMap, labelMap, result);
          }
          return result;
        }
      }

      if (fetchesInFlight_.count(key) != 0) {
        if (opts_.onFallbackWait) {
          opts_.onFallbackWait();
        }
        cv_.wait(lock, [&] { return fetchesInFlight_.count(key) == 0; });
        continue;
      }

      fetchesInFlight_.insert(key);
      fetchGeneration = generations_[key];
      break;
    }

    Entry fresh;
    fresh.ok = fetchPod(ns, name, fresh);
    fresh.fetchedAt = Entry::Clock::now();

    std::unordered_map<std::string, std::string> result;
    {
      std::lock_guard<std::mutex> lock(mu_);
      if (generations_[key] == fetchGeneration) {
        cache_.insert_or_assign(key, std::move(fresh));
      }
      fetchesInFlight_.erase(key);
      const auto cached = cache_.find(key);
      if (cached != cache_.end() && cached->second.ok) {
        copyAttribution(cached->second, container, envMap, labelMap, result);
      }
    }
    cv_.notify_all();
    return result;
  }

  Options opts_;
  std::atomic<bool> stopping_{false};
  bool watchEnabled_ = false;
  std::thread watchThread_;
  std::mutex mu_;
  std::condition_variable cv_;
  std::unordered_map<std::string, Entry> cache_;
  std::unordered_map<std::string, uint64_t> generations_;
  std::unordered_set<std::string> fetchesInFlight_;
};

K8sPodCache::K8sPodCache() : K8sPodCache(defaultOptions()) {}

K8sPodCache::K8sPodCache(Options opts)
    : impl_(std::make_unique<Impl>(std::move(opts))) {
  impl_->start();
}

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
