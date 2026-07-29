/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace dynolog::tpumon {

// One parsed Prometheus sample from tpu-device-plugin's /metrics endpoint.
// Example raw line:
//   duty_cycle{accelerator_id="1234567890123456789-4",make="cloud-tpu",
//              model="tpu7x",namespace="test-namespace",pod="...",
//              container="vllm-worker",tpu_topology="2x2x2"} 42.5
struct TpuSample {
  std::string name; // e.g. "duty_cycle" or "duty_cycle_node"
  double value = 0.0;
  std::unordered_map<std::string, std::string> labels;
};

// Default metric-name prefixes we care about from tpu-device-plugin.
// Everything else (Go runtime, promhttp self-metrics) is dropped.
// Kept in sync with the collector-side keep-regex in
// conf/node-collector/pipelines/tpu.yml.
constexpr const char* kDefaultTpuMetricAllowlist[] = {
    "duty_cycle",
    "tensorcore_utilization",
    "memory_total",
    "memory_used",
    "memory_bandwidth_utilization",
};

// HTTP-fetch + parse of the tpu-device-plugin Prometheus endpoint.
//
// Thread-safety: not intended for concurrent scrape() calls on the same
// instance. TpuGroupInfo owns exactly one TpuScraper and calls scrape()
// from the single tpu_monitor_loop thread.
class TpuScraper {
 public:
  explicit TpuScraper(
      std::string url,
      int timeout_ms = 2000,
      std::vector<std::string> allowlist = {});
  ~TpuScraper() = default;

  TpuScraper(const TpuScraper&) = delete;
  TpuScraper& operator=(const TpuScraper&) = delete;
  TpuScraper(TpuScraper&&) = delete;
  TpuScraper& operator=(TpuScraper&&) = delete;

  // Performs one HTTP GET against url_ and returns the parsed, filtered
  // samples. On HTTP failure returns an empty vector and sets isFailing()
  // = true; lastError() carries the curl error string. Callers are
  // expected to synthesize a tpu_error record when this returns empty.
  std::vector<TpuSample> scrape();

  bool isFailing() const {
    return failing_;
  }
  const std::string& lastError() const {
    return last_error_;
  }
  const std::string& url() const {
    return url_;
  }

 private:
  const std::string url_;
  const int timeout_ms_;
  const std::vector<std::string> allowlist_;
  bool failing_ = false;
  std::string last_error_;
};

// Prometheus text-format parser exposed for direct unit-testing.
// Returns every sample line; the caller applies any name allowlist.
//
// Handles:
//   - `# HELP` and `# TYPE` comment lines (skipped)
//   - `name{k1="v1",k2="v2"} 123.45`
//   - `name 123`
//   - Escape sequences \\, \", \n inside label values
//   - `+Inf`, `-Inf`, `NaN` values (dropped, not returned)
//   - Blank lines and unrecognized garbage (skipped, logged at V(2))
std::vector<TpuSample> parsePrometheusText(const std::string& body);

} // namespace dynolog::tpumon
