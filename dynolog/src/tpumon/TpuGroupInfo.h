/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "dynolog/src/Logger.h"
#include "dynolog/src/tpumon/TpuScraper.h"

namespace dynolog::tpumon {

DECLARE_string(tpu_device_plugin_url);

class TpuScraper;

struct TpuPodIdentity {
  std::string podNamespace;
  std::string podName;
  std::string containerName;

  bool operator==(const TpuPodIdentity& other) const {
    return podNamespace == other.podNamespace && podName == other.podName &&
        containerName == other.containerName;
  }
};

struct TpuPodAttributionProviders {
  std::function<std::vector<TpuPodIdentity>()> listCurrentOwners;
  std::function<std::unordered_map<std::string, std::string>(
      const TpuPodIdentity&)>
      lookupAttributes;
};

// TPU counterpart to gpumon::DcgmGroupInfo. Owns the periodic
// scrape-and-emit for TPU chips on the local node:
//
//   1. update()   — HTTP-scrape tpu-device-plugin, pivot samples per chip
//                   into metricsMap{Double,Int,String}_. If pod-resources
//                   attribution is enabled, also populates
//                   envMetadataMapString_ per chip from the K8s API.
//   2. log(Logger&) — emit one record per chip (float/int/string kv +
//                   `device` id) followed by finalize().
//
// Mirrors DcgmGroupInfo's public contract so Main.cpp wiring is
// symmetric (factory -> shared_ptr -> loop thread).
class TpuGroupInfo {
 public:
  ~TpuGroupInfo();
  TpuGroupInfo(const TpuGroupInfo&) = delete;
  TpuGroupInfo& operator=(const TpuGroupInfo&) = delete;
  TpuGroupInfo(TpuGroupInfo&&) = delete;
  TpuGroupInfo& operator=(TpuGroupInfo&&) = delete;

  // Constructs a TpuGroupInfo. `device_plugin_url` is the HTTP endpoint
  // exposing tpu-device-plugin's Prometheus /metrics; typically
  // "http://<NODE_IP>:2112/metrics". `scrape_timeout_ms` bounds each
  // per-cycle scrape. Returns nullptr on unrecoverable init failure
  // (currently: never — the scraper is lazy and tolerates absent
  // endpoints). `updateIntervalMs` is informational only (the caller's
  // loop drives the actual cadence).
  static std::shared_ptr<TpuGroupInfo> factory(
      std::string device_plugin_url,
      int scrape_timeout_ms,
      int updateIntervalMs);

  // Test-only factory that injects current TPU owners and pod-attribute lookup.
  // This keeps unit tests independent of the kubelet gRPC socket and K8s API.
  static std::shared_ptr<TpuGroupInfo> factoryForTesting(
      std::string device_plugin_url,
      int scrape_timeout_ms,
      int updateIntervalMs,
      TpuPodAttributionProviders podAttributionProviders);

  // Scrape once and pivot into per-chip metric maps.
  void update();

  // Test seam: skip HTTP and inject scrape results directly. Never
  // called from production code — invoked only by TpuGroupInfoTest,
  // which cannot bind loopback under buck2's default network sandbox.
  void updateFromSamples(
      const std::vector<TpuSample>& samples,
      bool scrape_failed);

  // Emit one OTLP record per chip. See class doc for shape.
  void log(Logger& logger);

  bool isFailing() const {
    return failing_;
  }
  int getChipCount() const {
    return static_cast<int>(metricsMapDouble_.size());
  }

 private:
  TpuGroupInfo(
      std::string device_plugin_url,
      int scrape_timeout_ms,
      int updateIntervalMs,
      TpuPodAttributionProviders podAttributionProviders,
      bool forcePodAttribution);

  std::unique_ptr<TpuScraper> scraper_;
  [[maybe_unused]] const int updateIntervalMs_;
  TpuPodAttributionProviders podAttributionProviders_;
  const bool forcePodAttribution_;
  bool failing_ = false;

  // Keyed by per-host chip index (0..N-1). N is not known ahead of
  // time; it's the count of unique accelerator_id suffixes observed on
  // the last successful scrape.
  std::unordered_map<int, std::unordered_map<std::string, double>>
      metricsMapDouble_;
  std::unordered_map<int, std::unordered_map<std::string, int64_t>>
      metricsMapInt_;
  std::unordered_map<int, std::unordered_map<std::string, std::string>>
      metricsMapString_;
  // Pod attribution: a raw metric namespace/pod/container identity that
  // exactly matches a current kubelet pod-resources TPU owner, plus
  // operator-configured env vars and pod labels (via
  // --env_attribution_mappings_file and K8sPodCache's default label map).
  // Populated by update() when attribution is enabled. Empty otherwise.
  std::unordered_map<int, std::unordered_map<std::string, std::string>>
      envMetadataMapString_;
};

} // namespace dynolog::tpumon
