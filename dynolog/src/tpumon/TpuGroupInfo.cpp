/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/tpumon/TpuGroupInfo.h"

#include <fmt/format.h>
#include <gflags/gflags.h>
#include <glog/logging.h>

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <string_view>
#include <utility>

#include "dynolog/src/tpumon/TpuScraper.h"

#ifdef USE_K8S_PODRESOURCES
#include "dynolog/src/k8s/EnvAttribution.h"
#include "dynolog/src/k8s/Flags.h"
#include "dynolog/src/k8s/K8sPodCache.h"
#include "dynolog/src/k8s/PodResourcesClient.h"
#endif

namespace dynolog::tpumon {

DEFINE_string(
    tpu_device_plugin_url,
    "http://localhost:2112/metrics",
    "Prometheus /metrics URL exposed by tpu-device-plugin on the local "
    "node. On GKE with hostNetwork:true device-plugin, the canonical form "
    "is http://$(NODE_IP):2112/metrics where NODE_IP is injected via the "
    "K8s downward API (fieldRef: status.hostIP).");

#ifdef USE_K8S_PODRESOURCES
namespace {
// Process-wide singletons. Function-local static (Meyers singleton,
// thread-safe init). Mirrors gpumon/DcgmGroupInfo.cpp's getPodResourcesClient()
// pattern; the TPU instance uses FLAGS_pod_resources_tpu_resource
// ("google.com/tpu") to filter pod-resources gRPC responses to TPU claims
// only. The K8sPodCache singleton is TPU-local rather than shared with the
// GPU one to keep the change surface small; sharing would save a few pod-
// spec fetches when the same pod holds both GPU and TPU resources (rare in
// practice) — can be hoisted later if that becomes worth it.
::dynolog::k8s::PodResourcesClient* getPodResourcesClient() {
  static auto client = std::make_unique<::dynolog::k8s::PodResourcesClient>(
      FLAGS_pod_resources_socket, FLAGS_pod_resources_tpu_resource);
  return client.get();
}

::dynolog::k8s::K8sPodCache* getK8sPodCache() {
  static auto cache = std::make_unique<::dynolog::k8s::K8sPodCache>();
  return cache.get();
}

TpuPodAttributionProviders makeProductionPodAttributionProviders() {
  return {
      .listCurrentOwners =
          [] {
            const auto tpuPods = getPodResourcesClient()->listGpuPods();
            std::vector<TpuPodIdentity> owners;
            owners.reserve(tpuPods.size());
            for (const auto& deviceAndPod : tpuPods) {
              const auto& pod = deviceAndPod.second;
              owners.push_back({
                  .podNamespace = pod.pod_namespace,
                  .podName = pod.pod_name,
                  .containerName = pod.container_name,
              });
            }
            return owners;
          },
      .lookupAttributes =
          [](const TpuPodIdentity& identity) {
            return getK8sPodCache()->lookupAttribution(
                identity.podNamespace,
                identity.podName,
                identity.containerName,
                ::dynolog::getEnvAttributionMappings(),
                ::dynolog::k8s::getDefaultLabelAttributionMap());
          },
  };
}
} // namespace
#endif // USE_K8S_PODRESOURCES

namespace {

// Metric-name allowlist for the record-shape logic below. Kept in sync
// with kDefaultTpuMetricAllowlist in TpuScraper.h; the scraper filters
// on prefixes so both _node and _container variants get through.
constexpr std::string_view kDutyCycle = "duty_cycle";
constexpr std::string_view kDutyCycleNode = "duty_cycle_node";
constexpr std::string_view kMemoryTotal = "memory_total";
constexpr std::string_view kMemoryTotalNode = "memory_total_node";
constexpr std::string_view kMemoryUsed = "memory_used";
constexpr std::string_view kMemoryUsedNode = "memory_used_node";

struct ChipId {
  std::string serial; // uuid prefix, shared across all chips on this node
  int index = -1; // 0..N-1 per host
};

// tpu-device-plugin's accelerator_id label is `<uuid>-<idx>`. We split
// the two so the uuid populates accelerator_serial_number and the
// per-host int populates the Hive-bucket-shaped `device_id`. See plan
// §2 "Hive bucket compatibility".
bool parseAcceleratorId(const std::string& accel_id, ChipId& out) {
  const size_t dash = accel_id.rfind('-');
  if (dash == std::string::npos || dash == 0 || dash + 1 >= accel_id.size()) {
    return false;
  }
  const std::string idx_str = accel_id.substr(dash + 1);
  char* endp = nullptr;
  const long idx = std::strtol(idx_str.c_str(), &endp, 10);
  // strtol's contract guarantees endp is non-null after the call (it
  // writes the first non-consumed character position), but static
  // analysis can't prove that; the explicit `endp == nullptr` check
  // silences NULLSAFECLANG / CLANGTIDY facebook-hte-NullableDereference.
  if (endp == nullptr || endp == idx_str.c_str() || *endp != '\0' || idx < 0) {
    return false;
  }
  out.serial = accel_id.substr(0, dash);
  out.index = static_cast<int>(idx);
  return true;
}

// True if the sample carries pod attribution labels (namespace/pod);
// used to pick container variant over node fallback when both are
// present for the same chip.
bool sampleHasPodLabels(const TpuSample& s) {
  return s.labels.find("namespace") != s.labels.end() &&
      s.labels.find("pod") != s.labels.end();
}

struct RawPodIdentityState {
  std::vector<TpuPodIdentity> identities;
  bool invalid = false;
};

void collectRawPodIdentity(
    const TpuSample& sample,
    RawPodIdentityState& state) {
  const auto namespaceIt = sample.labels.find("namespace");
  const auto podIt = sample.labels.find("pod");
  const auto containerIt = sample.labels.find("container");
  const bool hasAnyIdentityLabel = namespaceIt != sample.labels.end() ||
      podIt != sample.labels.end() || containerIt != sample.labels.end();
  if (!hasAnyIdentityLabel) {
    return;
  }
  if (namespaceIt == sample.labels.end() || podIt == sample.labels.end() ||
      containerIt == sample.labels.end() || namespaceIt->second.empty() ||
      podIt->second.empty() || containerIt->second.empty()) {
    state.invalid = true;
    return;
  }

  TpuPodIdentity identity{
      .podNamespace = namespaceIt->second,
      .podName = podIt->second,
      .containerName = containerIt->second,
  };
  if (std::find(state.identities.begin(), state.identities.end(), identity) ==
      state.identities.end()) {
    state.identities.push_back(std::move(identity));
  }
}

bool isCurrentOwner(
    const TpuPodIdentity& identity,
    const std::vector<TpuPodIdentity>& currentOwners) {
  return std::find(currentOwners.begin(), currentOwners.end(), identity) !=
      currentOwners.end();
}

} // namespace

std::shared_ptr<TpuGroupInfo> TpuGroupInfo::factory(
    std::string device_plugin_url,
    int scrape_timeout_ms,
    int updateIntervalMs) {
  LOG(INFO) << "Creating TpuGroupInfo scraping " << device_plugin_url
            << " every " << updateIntervalMs << " ms";
#ifdef USE_K8S_PODRESOURCES
  auto providers = makeProductionPodAttributionProviders();
#else
  TpuPodAttributionProviders providers;
#endif
  return std::shared_ptr<TpuGroupInfo>(new TpuGroupInfo(
      std::move(device_plugin_url),
      scrape_timeout_ms,
      updateIntervalMs,
      std::move(providers),
      /*forcePodAttribution=*/false));
}

std::shared_ptr<TpuGroupInfo> TpuGroupInfo::factoryForTesting(
    std::string device_plugin_url,
    int scrape_timeout_ms,
    int updateIntervalMs,
    TpuPodAttributionProviders podAttributionProviders) {
  return std::shared_ptr<TpuGroupInfo>(new TpuGroupInfo(
      std::move(device_plugin_url),
      scrape_timeout_ms,
      updateIntervalMs,
      std::move(podAttributionProviders),
      /*forcePodAttribution=*/true));
}

TpuGroupInfo::TpuGroupInfo(
    std::string device_plugin_url,
    int scrape_timeout_ms,
    int updateIntervalMs,
    TpuPodAttributionProviders podAttributionProviders,
    bool forcePodAttribution)
    : scraper_{std::make_unique<TpuScraper>(
          std::move(device_plugin_url),
          scrape_timeout_ms)},
      updateIntervalMs_{updateIntervalMs},
      podAttributionProviders_{std::move(podAttributionProviders)},
      forcePodAttribution_{forcePodAttribution} {}

TpuGroupInfo::~TpuGroupInfo() = default;

void TpuGroupInfo::update() {
  const auto samples = scraper_->scrape();
  updateFromSamples(samples, scraper_->isFailing());
}

void TpuGroupInfo::updateFromSamples(
    const std::vector<TpuSample>& samples,
    bool scrape_failed) {
  metricsMapDouble_.clear();
  metricsMapInt_.clear();
  metricsMapString_.clear();
  envMetadataMapString_.clear();

  if (scrape_failed) {
    failing_ = true;
    // We can't attribute an error to a specific chip when the scrape
    // itself failed (we don't know how many chips are on the node), so
    // set a single sentinel row at index 0 with tpu_error=1.
    metricsMapInt_[0]["tpu_error"] = 1;
    metricsMapString_[0]["accelerator_vendor"] = "cloud-tpu";
    return;
  }
  failing_ = false;

  // First pass: discover chips by their (uuid, index) and stash string
  // metadata from any sample we see (labels are identical across
  // samples for the same chip).
  //
  // Two-pass structure keeps the container-vs-node fallback simple:
  // container samples "win" for duty_cycle / memory_*, node samples are
  // fallbacks. tensorcore_utilization_node and
  // memory_bandwidth_utilization_node are intentionally NOT emitted at
  // per-chip granularity (host-aggregate only — see plan §5a).
  //
  // Raw pod labels are reconciled by identity tuple against current
  // PodResources owners below. PodResources device IDs are intentionally
  // ignored because GKE exposes PCI BDFs there and serial-index IDs here.
  std::unordered_map<int, RawPodIdentityState> rawPodIdentities;
  for (const auto& s : samples) {
    const auto id_it = s.labels.find("accelerator_id");
    if (id_it == s.labels.end()) {
      continue;
    }
    ChipId chip;
    if (!parseAcceleratorId(id_it->second, chip)) {
      LOG_EVERY_N(WARNING, 60)
          << "TpuGroupInfo: unparseable accelerator_id: " << id_it->second;
      continue;
    }
    collectRawPodIdentity(s, rawPodIdentities[chip.index]);
    auto& str_map = metricsMapString_[chip.index];
    if (str_map.count("accelerator_serial_number") == 0) {
      str_map["accelerator_serial_number"] = chip.serial;
    }
    const auto model_it = s.labels.find("model");
    if (model_it != s.labels.end() && str_map.count("accelerator_model") == 0) {
      str_map["accelerator_model"] = model_it->second;
    }
    const auto make_it = s.labels.find("make");
    if (make_it != s.labels.end() && str_map.count("accelerator_vendor") == 0) {
      str_map["accelerator_vendor"] = make_it->second;
    }
    // Ensure error column is populated (0 = healthy scrape).
    if (metricsMapInt_[chip.index].count("tpu_error") == 0) {
      metricsMapInt_[chip.index]["tpu_error"] = 0;
    }
  }

  // Second pass: pull numeric values with the container>node fallback.
  // Track (chip_index, metric_family) tuples; once we've stored a
  // container-scoped value for a chip, subsequent node-scoped samples
  // for the same chip are ignored.
  std::unordered_map<int, bool> has_container_dc;
  std::unordered_map<int, bool> has_container_mem_total;
  std::unordered_map<int, bool> has_container_mem_used;
  std::unordered_map<int, double> mem_total;
  std::unordered_map<int, double> mem_used;

  for (const auto& s : samples) {
    const auto id_it = s.labels.find("accelerator_id");
    if (id_it == s.labels.end()) {
      continue;
    }
    ChipId chip;
    if (!parseAcceleratorId(id_it->second, chip)) {
      continue;
    }
    const bool has_pod = sampleHasPodLabels(s);
    auto& dbl = metricsMapDouble_[chip.index];

    if (s.name == kDutyCycle && has_pod) {
      dbl["accelerator_utilization"] = s.value;
      has_container_dc[chip.index] = true;
    } else if (s.name == kDutyCycleNode) {
      if (!has_container_dc[chip.index]) {
        dbl["accelerator_utilization"] = s.value;
      }
    } else if (s.name == kMemoryTotal && has_pod) {
      mem_total[chip.index] = s.value;
      has_container_mem_total[chip.index] = true;
    } else if (s.name == kMemoryTotalNode) {
      if (!has_container_mem_total[chip.index]) {
        mem_total[chip.index] = s.value;
      }
    } else if (s.name == kMemoryUsed && has_pod) {
      mem_used[chip.index] = s.value;
      has_container_mem_used[chip.index] = true;
    } else if (s.name == kMemoryUsedNode) {
      if (!has_container_mem_used[chip.index]) {
        mem_used[chip.index] = s.value;
      }
    }
    // tensorcore_utilization_node and memory_bandwidth_utilization_node
    // are intentionally dropped for per-chip rows (see plan §5a).
  }

  // Compose memory_utilization from the two capacity gauges.
  for (const auto& [idx, total] : mem_total) {
    const auto used_it = mem_used.find(idx);
    if (used_it == mem_used.end() || total <= 0.0) {
      continue;
    }
    metricsMapDouble_[idx]["memory_utilization"] =
        (used_it->second / total) * 100.0;
  }

  // Validate raw metric identity against current TPU owners from the latest
  // PodResources List response. Raw labels may outlive a deleted pod, while
  // PodResources device IDs use a different namespace from accelerator_id,
  // so only exact namespace/pod/container membership is authoritative.
  bool podAttributionEnabled = forcePodAttribution_;
#ifdef USE_K8S_PODRESOURCES
  podAttributionEnabled =
      podAttributionEnabled || FLAGS_enable_pod_resources_attribution;
#endif
  if (podAttributionEnabled && podAttributionProviders_.listCurrentOwners) {
    const auto currentOwners = podAttributionProviders_.listCurrentOwners();
    for (const auto& [chipIndex, state] : rawPodIdentities) {
      if (state.invalid || state.identities.size() != 1) {
        continue;
      }
      const auto& identity = state.identities.front();
      if (!isCurrentOwner(identity, currentOwners)) {
        continue;
      }

      auto& env = envMetadataMapString_[chipIndex];
      if (podAttributionProviders_.lookupAttributes) {
        auto attrs = podAttributionProviders_.lookupAttributes(identity);
        for (auto& [key, value] : attrs) {
          env[key] = std::move(value);
        }
      }
      // Write verified identity last so configurable enrichment cannot
      // overwrite these reserved fields.
      env["pod_namespace"] = identity.podNamespace;
      env["pod_name"] = identity.podName;
      env["container_name"] = identity.containerName;
    }
  }
}

void TpuGroupInfo::log(Logger& logger) {
  const auto t = std::chrono::system_clock::now();
  logger.setTimestamp(t);
  for (const auto& [index, dbl_map] : metricsMapDouble_) {
    for (const auto& [k, v] : dbl_map) {
      logger.logFloat(k, v);
    }
    const auto int_it = metricsMapInt_.find(index);
    if (int_it != metricsMapInt_.end()) {
      for (const auto& [k, v] : int_it->second) {
        logger.logInt(k, v);
      }
    }
    const auto str_it = metricsMapString_.find(index);
    if (str_it != metricsMapString_.end()) {
      for (const auto& [k, v] : str_it->second) {
        logger.logStr(k, v);
      }
    }
    const auto env_it = envMetadataMapString_.find(index);
    if (env_it != envMetadataMapString_.end()) {
      for (const auto& [k, v] : env_it->second) {
        logger.logStr(k, v);
      }
    }
    logger.logInt("device", index);
    logger.finalize();
  }
  // Emit the sentinel error row when no chips were discovered.
  if (metricsMapDouble_.empty()) {
    const auto int_it = metricsMapInt_.find(0);
    if (int_it != metricsMapInt_.end()) {
      for (const auto& [k, v] : int_it->second) {
        logger.logInt(k, v);
      }
      const auto str_it = metricsMapString_.find(0);
      if (str_it != metricsMapString_.end()) {
        for (const auto& [k, v] : str_it->second) {
          logger.logStr(k, v);
        }
      }
      logger.logInt("device", 0);
      logger.finalize();
    }
  }
}

} // namespace dynolog::tpumon
