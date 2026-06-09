/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/OtlpMetricsLogger.h"
#include "dynolog/src/String.h"
#include "hbt/src/common/System.h"

#include <fmt/format.h>
#include <glog/logging.h>

#ifdef USE_OTLP

#include <unistd.h>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <map>
#include <regex>
#include <unordered_set>

#include <curl/curl.h>

#include "opentelemetry/proto/collector/metrics/v1/metrics_service.pb.h"
#include "opentelemetry/proto/common/v1/common.pb.h"
#include "opentelemetry/proto/metrics/v1/metrics.pb.h"
#include "opentelemetry/proto/resource/v1/resource.pb.h"

// Stringify macro to turn DYNOLOG_VERSION into a string literal.
#define OTLP_STRINGIFY_HELPER(x) #x
#define OTLP_STRINGIFY(x) OTLP_STRINGIFY_HELPER(x)

DEFINE_string(
    otlp_endpoint,
    "",
    "OTLP HTTP endpoint (e.g., http://localhost:4318/v1/metrics). "
    "The /v1/metrics path is appended automatically if not present.");
DEFINE_string(
    otlp_service_name,
    "dynolog",
    "Service name for OTLP resource attributes");
DEFINE_string(otlp_headers, "", "OTLP headers (key1=value1,key2=value2)");
DEFINE_int32(otlp_timeout_ms, 30000, "OTLP export timeout in milliseconds");
DEFINE_int32(
    otlp_max_queue_size,
    1000,
    "Maximum number of serialized OTLP payloads to buffer; "
    "oldest payloads are dropped when the queue is full");
DEFINE_string(
    otlp_ssl_ca_cert_path,
    "",
    "Path to CA certificate file for verifying the OTLP server");
DEFINE_string(
    otlp_ssl_client_cert_path,
    "",
    "Path to client certificate file for mTLS authentication");
DEFINE_string(
    otlp_ssl_client_key_path,
    "",
    "Path to client private key file for mTLS authentication");

namespace dynolog {

// ---- Slurm attribution keys that become metric attributes ----
static const std::unordered_set<std::string> kSlurmAttributionKeys = {
    "job_id",
    "username",
    "slurm_account",
    "slurm_partition",
};

// ---- Helper to get env var with fallback ----
std::string getEnvOr(const char* name, const std::string& fallback) {
  const char* val = std::getenv(name);
  return (val && val[0] != '\0') ? std::string(val) : fallback;
}

// ---- Parse OTLP headers from comma-separated key=value string ----
std::vector<std::pair<std::string, std::string>> parseHeaders(
    const std::string& raw) {
  std::vector<std::pair<std::string, std::string>> result;
  if (raw.empty()) {
    return result;
  }
  auto trim = [](const std::string& s) {
    const auto begin = s.find_first_not_of(" \t");
    if (begin == std::string::npos) {
      return std::string();
    }
    const auto end = s.find_last_not_of(" \t");
    return s.substr(begin, end - begin + 1);
  };
  auto tokens = facebook::dynolog::split(raw, ',');
  for (const auto& token : tokens) {
    auto eq = token.find('=');
    if (eq == std::string::npos || eq == 0) {
      continue;
    }
    // Trim whitespace so values like "k1=v1, k2=v2" don't yield a key of
    // " k2", which would be an invalid HTTP header forwarded to libcurl.
    std::string key = trim(token.substr(0, eq));
    std::string value = trim(token.substr(eq + 1));
    if (!key.empty()) {
      result.emplace_back(std::move(key), std::move(value));
    }
  }
  return result;
}

// ---- Metric key parsing ----

// CPU utilization metrics that need divide-by-100.
static const std::unordered_map<std::string, std::string> kCpuUtilMetrics = {
    {"cpu_util", "active"},
    {"cpu_u", "user"},
    {"cpu_s", "system"},
    {"cpu_i", "idle"},
    {"cpu_guest", "guest"},
    {"cpu_guest_nice", "guest_nice"},
};

// CPU time metrics — dynolog reports per-interval deltas, exported as gauges.
static const std::unordered_map<std::string, std::string> kCpuTimeMetrics = {
    {"cpu_u_ms", "user"},
    {"cpu_s_ms", "system"},
    {"cpu_n_ms", "nice"},
    {"cpu_w_ms", "iowait"},
    {"cpu_x_ms", "irq"},
    {"cpu_y_ms", "softirq"},
    {"cpu_z_ms", "steal"},
    {"cpu_guest_ms", "guest"},
    {"cpu_guest_nice_ms", "guest_nice"},
};

// Network metric info: unit and direction for attribute decomposition.
struct NetworkMetricInfo {
  std::string unit;
  std::string direction;
};

static const std::unordered_map<std::string, NetworkMetricInfo>
    kNetworkMetrics = {
        {"rx_bytes", {"By", "receive"}},
        {"tx_bytes", {"By", "transmit"}},
        {"rx_packets", {"{packet}", "receive"}},
        {"tx_packets", {"{packet}", "transmit"}},
        {"rx_errors", {"{error}", "receive"}},
        {"tx_errors", {"{error}", "transmit"}},
        {"rx_drops", {"{packet}", "receive"}},
        {"tx_drops", {"{packet}", "transmit"}},
};

// ARM hardware counter metrics: unit and attributes for decomposition.
struct ArmHwCounterMetricInfo {
  std::string unit;
  std::vector<std::pair<std::string, std::string>> extra_attrs;
};

static const std::unordered_map<std::string, ArmHwCounterMetricInfo>
    kArmHwCounterMetrics = {
        {"l1d_tlb", {"{event}", {{"level", "l1d"}, {"type", "access"}}}},
        {"l1d_tlb_refill", {"{event}", {{"level", "l1d"}, {"type", "miss"}}}},
        {"l1i_tlb", {"{event}", {{"level", "l1i"}, {"type", "access"}}}},
        {"l1i_tlb_refill", {"{event}", {{"level", "l1i"}, {"type", "miss"}}}},
        {"l2d_tlb", {"{event}", {{"level", "l2"}, {"type", "access"}}}},
        {"l2d_tlb_refill", {"{event}", {{"level", "l2"}, {"type", "miss"}}}},
        {"stall_backend_mem", {"{cycle}", {{"reason", "backend_mem"}}}},
        {"ll_cache_miss_rd", {"{event}", {{"level", "ll"}}}},
        {"br_mis_pred", {"{event}", {}}},
        {"br_retired", {"{instruction}", {}}},
        {"l1i_cache_refill", {"{event}", {{"level", "l1i"}, {"type", "miss"}}}},
        {"l1d_cache_refill", {"{event}", {{"level", "l1d"}, {"type", "miss"}}}},
        {"l2d_cache_refill", {"{event}", {{"level", "l2"}, {"type", "miss"}}}},
        {"l3d_cache_refill", {"{event}", {{"level", "l3"}, {"type", "miss"}}}},
        {"FP_HP_SPEC", {"{operation}", {{"precision", "half"}}}},
        {"FP_SP_SPEC", {"{operation}", {{"precision", "single"}}}},
        {"FP_DP_SPEC", {"{operation}", {{"precision", "double"}}}},
        {"dtlb_walk", {"{event}", {{"type", "data"}}}},
        {"itlb_walk", {"{event}", {{"type", "instruction"}}}},
};

// GPU metrics: unit, attributes, skip flag, and optional scaling.
struct GPUMetricInfo {
  std::string unit;
  std::vector<std::pair<std::string, std::string>> extra_attrs;
  bool skip = false;
  double scale_factor = 1.0;
};

static const std::unordered_map<std::string, GPUMetricInfo> kGpuMetrics = {
    {"graphics_engine_active_ratio", {"1", {{"hw.gpu.task", "general"}}}},
    {"sm_active_ratio", {"1", {}}},
    {"sm_occupancy", {"1", {}}},
    {"gpu_frequency_mhz", {"MHz", {}}},
    {"fp16_active", {"1", {{"pipe", "fp16"}}}},
    {"fp32_active", {"1", {{"pipe", "fp32"}}}},
    {"fp64_active", {"1", {{"pipe", "fp64"}}}},
    {"tensorcore_active", {"1", {{"pipe", "tensorcore"}}}},
    {"hbm_mem_bw_util", {"1", {}}},
    {"pcie_tx_bytes", {"By/s", {{"direction", "transmit"}}}},
    {"pcie_rx_bytes", {"By/s", {{"direction", "receive"}}}},
    {"nvlink_tx_bytes", {"By/s", {{"direction", "transmit"}}}},
    {"nvlink_rx_bytes", {"By/s", {{"direction", "receive"}}}},
    {"gpu_device_utilization",
     {"1",
      {{"hw.gpu.task", "device"}},
      /* skip */ false,
      /* scale_factor */ 0.01}},
    {"gpu_memory_utilization",
     {"1", {}, /* skip */ false, /* scale_factor */ 0.01}},
    {"gpu_power_draw", {"W", {{"hw.type", "gpu"}}}},
    {"dcgm_error", {"{error}", {{"hw.type", "gpu"}}}},
    // Metadata keys: skip export
    {"minor_id", {"", {}, /* skip */ true}},
    {"device", {"", {}, /* skip */ true}},
};

ParsedMetricKey parseMetricKey(const std::string& key) {
  ParsedMetricKey result;
  result.matched = false;

  if (key.empty()) {
    return result;
  }

  // 1. Check CPU utilization metrics.
  {
    auto it = kCpuUtilMetrics.find(key);
    if (it != kCpuUtilMetrics.end()) {
      result.matched = true;
      result.mapping.otel_name = key;
      result.mapping.unit = "1";

      result.mapping.attributes = {{"cpu.mode", it->second}};
      result.mapping.scale_factor = 0.01;
      return result;
    }
  }

  // 2. Check per-NUMA-socket CPU utilization: cpu_{u,s,i}_node{N}
  {
    static const std::regex kNumaRegex(R"(cpu_(u|s|i)_node(\d+))");
    std::smatch match;
    if (std::regex_match(key, match, kNumaRegex)) {
      result.matched = true;
      result.mapping.otel_name = key;
      result.mapping.unit = "1";

      result.mapping.scale_factor = 0.01;

      const std::string& mode = match[1].str();
      std::string state;
      if (mode == "u") {
        state = "user";
      } else if (mode == "s") {
        state = "system";
      } else {
        state = "idle";
      }
      result.mapping.attributes = {{"cpu.mode", state}};
      result.dynamic_attributes = {{"cpu.socket", match[2].str()}};
      return result;
    }
  }

  // 3. Check CPU time metrics.
  {
    auto it = kCpuTimeMetrics.find(key);
    if (it != kCpuTimeMetrics.end()) {
      result.matched = true;
      result.mapping.otel_name = key;
      result.mapping.unit = "s";
      result.mapping.scale_factor = 0.001;

      result.mapping.attributes = {{"cpu.mode", it->second}};
      return result;
    }
  }

  // 4. Check special CPU metrics.
  if (key == "uptime") {
    result.matched = true;
    result.mapping.otel_name = "uptime";
    result.mapping.unit = "s";

    return result;
  }
  // 5. Check network metrics (key format: "metric_base.device_name").
  {
    auto dot = key.find('.');
    if (dot != std::string::npos) {
      std::string base = key.substr(0, dot);
      std::string device = key.substr(dot + 1);

      auto it = kNetworkMetrics.find(base);
      if (it != kNetworkMetrics.end()) {
        result.matched = true;
        result.mapping.otel_name = base;
        result.mapping.unit = it->second.unit;

        result.mapping.attributes = {
            {"network.io.direction", it->second.direction}};
        if (!device.empty()) {
          result.dynamic_attributes = {{"network.interface.name", device}};
        }
        return result;
      }
    }
  }

  // 6. Check GPU metrics.
  {
    auto it = kGpuMetrics.find(key);
    if (it != kGpuMetrics.end()) {
      result.matched = true;
      result.mapping.otel_name = key;
      result.mapping.unit = it->second.unit;

      result.mapping.attributes = it->second.extra_attrs;
      result.mapping.skip = it->second.skip;
      result.mapping.scale_factor = it->second.scale_factor;
      return result;
    }
  }

  // 7. Check ARM hardware counter metrics.
  {
    auto it = kArmHwCounterMetrics.find(key);
    if (it != kArmHwCounterMetrics.end()) {
      result.matched = true;
      result.mapping.otel_name = key;
      result.mapping.unit = it->second.unit;

      result.mapping.attributes = it->second.extra_attrs;
      return result;
    }
  }

  // 8. Unrecognized key: pass through with raw name.
  result.matched = true;
  result.mapping.otel_name = key;
  result.mapping.unit = "";
  return result;
}

// ---- Helper to add a string attribute to a protobuf KeyValue ----
static void addStringAttribute(
    opentelemetry::proto::common::v1::KeyValue* kv,
    const std::string& key,
    const std::string& value) {
  kv->set_key(key);
  kv->mutable_value()->set_string_value(value);
}

// ---- OTLPManager implementation ----

OTLPManager::OTLPManager() {
  max_queue_size_ = FLAGS_otlp_max_queue_size;
  if (max_queue_size_ < 1) {
    LOG(WARNING) << "OTLPManager: invalid --otlp_max_queue_size="
                 << max_queue_size_ << "; using 1";
    max_queue_size_ = 1;
  }

  // Resolve endpoint: flag -> env var override.
  endpoint_ = getEnvOr("OTEL_EXPORTER_OTLP_ENDPOINT", FLAGS_otlp_endpoint);
  if (endpoint_.empty()) {
    LOG(WARNING) << "OTLPManager: no endpoint configured "
                 << "(set --otlp_endpoint or OTEL_EXPORTER_OTLP_ENDPOINT). "
                 << "OTLP metrics export is disabled.";
    return;
  }

  // Ensure endpoint ends with /v1/metrics for HTTP proto transport.
  const std::string kMetricsPath = "/v1/metrics";
  // Strip any trailing slash first so an endpoint already ending in
  // "/v1/metrics/" is not turned into "/v1/metrics/v1/metrics".
  if (!endpoint_.empty() && endpoint_.back() == '/') {
    endpoint_.pop_back();
  }
  if (endpoint_.size() < kMetricsPath.size() ||
      endpoint_.compare(
          endpoint_.size() - kMetricsPath.size(),
          kMetricsPath.size(),
          kMetricsPath) != 0) {
    endpoint_ += kMetricsPath;
  }

  // Resolve service name: flag -> env var override.
  service_name_ = getEnvOr("OTEL_SERVICE_NAME", FLAGS_otlp_service_name);

  // Parse headers.
  headers_ = parseHeaders(FLAGS_otlp_headers);

  // Timeout.
  timeout_ms_ = FLAGS_otlp_timeout_ms;

  // mTLS paths.
  ssl_ca_cert_path_ = FLAGS_otlp_ssl_ca_cert_path;
  ssl_client_cert_path_ = FLAGS_otlp_ssl_client_cert_path;
  ssl_client_key_path_ = FLAGS_otlp_ssl_client_key_path;

  // Build the Resource proto (done once, reused for every export).
  buildResource();

  // libcurl requires a one-time global init before any other curl call. The
  // background export thread invokes curl_easy_init() per payload; doing the
  // global init here (once per process, via the singleton) avoids the implicit
  // and thread-unsafe lazy initialization inside curl_easy_init().
  CURLcode curl_init_res = curl_global_init(CURL_GLOBAL_DEFAULT);
  if (curl_init_res != CURLE_OK) {
    LOG(ERROR) << "OTLPManager: curl_global_init() failed: "
               << curl_easy_strerror(curl_init_res)
               << "; OTLP metrics export is disabled.";
    endpoint_.clear();
    return;
  }
  curl_global_initialized_ = true;

  // Start background export thread.
  export_thread_ = std::thread(&OTLPManager::exportLoop, this);

  LOG(INFO) << "OTLPManager: initialized, endpoint=" << endpoint_;
}

OTLPManager::~OTLPManager() {
  // Publish the shutdown flag while holding export_mutex_ so the change is
  // visible to the export thread's cv.wait() predicate. Storing+notifying
  // without the lock races with the waiter and can drop the wakeup, hanging
  // export_thread_.join() below.
  {
    std::lock_guard<std::mutex> lk(export_mutex_);
    shutdown_.store(true);
  }
  export_cv_.notify_one();
  if (export_thread_.joinable()) {
    export_thread_.join();
  }
  if (curl_global_initialized_) {
    curl_global_cleanup();
  }
  LOG(INFO) << "OTLPManager: export thread stopped";
}

void OTLPManager::queuePayload(std::string payload) {
  bool dropped = false;
  {
    std::lock_guard<std::mutex> lk(export_mutex_);
    if (export_queue_.size() >= static_cast<size_t>(max_queue_size_)) {
      export_queue_.pop();
      dropped = true;
    }
    export_queue_.push(std::move(payload));
  }
  if (dropped) {
    LOG_EVERY_N(WARNING, 100)
        << "OTLP export queue full; dropping oldest payload "
        << "(max_queue_size=" << max_queue_size_ << ")";
  }
  export_cv_.notify_one();
}

void OTLPManager::exportLoop() {
  while (true) {
    std::string payload;
    {
      std::unique_lock<std::mutex> lk(export_mutex_);
      export_cv_.wait(
          lk, [this] { return !export_queue_.empty() || shutdown_.load(); });
      if (shutdown_.load() && export_queue_.empty()) {
        break;
      }
      if (export_queue_.empty()) {
        continue;
      }
      payload = std::move(export_queue_.front());
      export_queue_.pop();
    }
    httpPost(payload);
  }
  // Drain any remaining payloads before exiting. Dequeue under the lock, then
  // release it before the blocking httpPost() call -- matching the main loop
  // above. Holding export_mutex_ across httpPost() would block queuePayload()
  // (deadlock risk) and could stall shutdown for minutes per queued payload.
  while (true) {
    std::string payload;
    {
      std::lock_guard<std::mutex> lk(export_mutex_);
      if (export_queue_.empty()) {
        break;
      }
      payload = std::move(export_queue_.front());
      export_queue_.pop();
    }
    httpPost(payload);
  }
}

bool OTLPManager::httpPost(const std::string& payload) {
  CURL* curl = curl_easy_init();
  if (curl == nullptr) {
    LOG(ERROR) << "OTLP: curl_easy_init() failed";
    return false;
  }

  struct curl_slist* hdrs = nullptr;
  hdrs = curl_slist_append(hdrs, "Content-Type: application/x-protobuf");
  for (const auto& [key, value] : headers_) {
    std::string header = key + ": " + value;
    hdrs = curl_slist_append(hdrs, header.c_str());
  }

  curl_easy_setopt(curl, CURLOPT_URL, endpoint_.c_str());
  curl_easy_setopt(curl, CURLOPT_POST, 1L);
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.data());
  curl_easy_setopt(
      curl, CURLOPT_POSTFIELDSIZE, static_cast<long>(payload.size()));
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hdrs);
  curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, static_cast<long>(timeout_ms_));
  // httpPost() runs on the background export thread. libcurl recommends
  // CURLOPT_NOSIGNAL in multi-threaded programs to avoid SIGALRM-based
  // timeout handling, which is not thread-safe.
  curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

  // TLS is automatic when URL starts with https://.
  // mTLS: set client cert, key, and CA cert if configured.
  if (!ssl_ca_cert_path_.empty()) {
    curl_easy_setopt(curl, CURLOPT_CAINFO, ssl_ca_cert_path_.c_str());
  }
  if (!ssl_client_cert_path_.empty()) {
    curl_easy_setopt(curl, CURLOPT_SSLCERT, ssl_client_cert_path_.c_str());
  }
  if (!ssl_client_key_path_.empty()) {
    curl_easy_setopt(curl, CURLOPT_SSLKEY, ssl_client_key_path_.c_str());
  }

  // Suppress response body output.
  curl_easy_setopt(
      curl,
      CURLOPT_WRITEFUNCTION,
      +[](char* /*ptr*/, size_t size, size_t nmemb, void* /*userdata*/)
          -> size_t { return size * nmemb; });

  CURLcode res = curl_easy_perform(curl);
  bool success = false;
  if (res != CURLE_OK) {
    LOG(WARNING) << "OTLP export failed: " << curl_easy_strerror(res);
  } else {
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code >= 200 && http_code < 300) {
      success = true;
      LOG_EVERY_N(INFO, 100) << "OTLP: exported " << payload.size()
                             << " bytes, HTTP " << http_code;
    } else {
      LOG(WARNING) << "OTLP export HTTP error: " << http_code;
    }
  }

  curl_slist_free_all(hdrs);
  curl_easy_cleanup(curl);
  return success;
}

void OTLPManager::buildResource() {
  // service.name
  addStringAttribute(resource_.add_attributes(), "service.name", service_name_);

  // service.version (from build-time DYNOLOG_VERSION macro)
#ifdef DYNOLOG_VERSION
  addStringAttribute(
      resource_.add_attributes(),
      "service.version",
      OTLP_STRINGIFY(DYNOLOG_VERSION));
#endif

  // host.name
  char hostname[HOST_NAME_MAX + 1];
  if (gethostname(hostname, sizeof(hostname)) == 0) {
    hostname[sizeof(hostname) - 1] = '\0';
    addStringAttribute(resource_.add_attributes(), "host.name", hostname);
  }

  // os.type
  addStringAttribute(resource_.add_attributes(), "os.type", "linux");
}

static std::shared_ptr<OTLPManager> singleton_() {
  static std::shared_ptr<OTLPManager> manager_ =
      []() -> std::shared_ptr<OTLPManager> {
    try {
      return std::make_shared<OTLPManager>();
    } catch (const std::exception& e) {
      LOG(ERROR) << "Failed to create OTLPManager: " << e.what()
                 << ". OTLP metrics will not be exported.";
      return nullptr;
    }
  }();
  return manager_;
}

// static
bool OTLPManager::isInitialized() {
  auto mgr = singleton_();
  return mgr != nullptr && !mgr->endpoint_.empty();
}

// static
OTLPManager::LoggingGuard OTLPManager::singleton() {
  auto s = singleton_();
  CHECK(s != nullptr)
      << "OTLPManager::singleton() called but initialization failed. "
      << "Call isInitialized() before singleton().";
  return LoggingGuard{.manager = s, .lock_guard = s->lock()};
}

// ---- Protobuf serialization ----

std::string OTLPManager::serializeMetrics(
    const std::unordered_map<std::string, double>& metrics,
    const std::unordered_map<std::string, std::string>& attributes) {
  namespace otlp_collector = opentelemetry::proto::collector::metrics::v1;
  namespace otlp_metrics = opentelemetry::proto::metrics::v1;

  otlp_collector::ExportMetricsServiceRequest request;
  auto* rm = request.add_resource_metrics();
  *rm->mutable_resource() = resource_;

  auto* sm = rm->add_scope_metrics();
  sm->mutable_scope()->set_name("dynolog");

  // Current timestamp in nanoseconds since Unix epoch.
  auto now = std::chrono::system_clock::now();
  uint64_t time_ns = static_cast<uint64_t>(
      std::chrono::duration_cast<std::chrono::nanoseconds>(
          now.time_since_epoch())
          .count());

  // Look up "device" key for GPU hw.id attribute. Guard the int64_t cast with
  // an isfinite check: casting a NaN/Inf double to an integer is undefined
  // behavior, and the per-metric NaN/Inf filter below does not cover this key.
  std::string gpu_device_id;
  auto device_it = metrics.find("device");
  if (device_it != metrics.end() && std::isfinite(device_it->second)) {
    gpu_device_id = fmt::format("{}", static_cast<int64_t>(device_it->second));
  }

  for (const auto& [key, val] : metrics) {
    auto parsed = parseMetricKey(key);
    if (!parsed.matched || parsed.mapping.skip) {
      continue;
    }

    // SER-06: Filter NaN and Inf values.
    if (std::isnan(val) || std::isinf(val)) {
      continue;
    }

    // SER-04: Apply scale_factor.
    double export_val = (parsed.mapping.scale_factor != 1.0)
        ? val * parsed.mapping.scale_factor
        : val;

    auto* metric = sm->add_metrics();
    metric->set_name(parsed.mapping.otel_name);
    metric->set_unit(parsed.mapping.unit);

    auto* gauge = metric->mutable_gauge();
    auto* dp = gauge->add_data_points();
    dp->set_as_double(export_val);
    dp->set_time_unix_nano(time_ns);

    // Add static attributes from the mapping.
    for (const auto& [attr_key, attr_val] : parsed.mapping.attributes) {
      addStringAttribute(dp->add_attributes(), attr_key, attr_val);
    }

    // Add dynamic attributes extracted from the key.
    for (const auto& [attr_key, attr_val] : parsed.dynamic_attributes) {
      addStringAttribute(dp->add_attributes(), attr_key, attr_val);
    }

    // Add GPU-specific attributes: hw.id and Slurm attribution.
    bool is_gpu_metric = kGpuMetrics.find(key) != kGpuMetrics.end();
    if (is_gpu_metric && !gpu_device_id.empty()) {
      addStringAttribute(dp->add_attributes(), "hw.id", gpu_device_id);
    }
    if (is_gpu_metric) {
      for (const auto& [attr_key, attr_val] : attributes) {
        addStringAttribute(dp->add_attributes(), attr_key, attr_val);
      }
    }
  }

  return request.SerializeAsString();
}

// ---- OTLPLogger implementation ----

void OTLPLogger::logStr(const std::string& key, const std::string& val) {
  if (kSlurmAttributionKeys.count(key)) {
    pending_attributes_[key] = val;
  }
  // Non-attribution string keys are silently ignored
  // (same as PrometheusLogger).
}

void OTLPLogger::finalize() {
  if (pending_metrics_.empty()) {
    pending_attributes_.clear();
    return;
  }

  if (!OTLPManager::isInitialized()) {
    pending_metrics_.clear();
    pending_attributes_.clear();
    return;
  }

  auto logging_guard = OTLPManager::singleton();
  auto mgr = logging_guard.manager;
  std::string payload =
      mgr->serializeMetrics(pending_metrics_, pending_attributes_);

  if (!payload.empty()) {
    mgr->queuePayload(std::move(payload));
  }

  pending_metrics_.clear();
  pending_attributes_.clear();
}

} // namespace dynolog
#endif // USE_OTLP
