/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/OtlpLogger.h"

#ifdef USE_OTEL

#include <opentelemetry/exporters/otlp/otlp_http_log_record_exporter_factory.h>
#include <opentelemetry/exporters/otlp/otlp_http_log_record_exporter_options.h>
#include <opentelemetry/sdk/logs/batch_log_record_processor_factory.h>
#include <opentelemetry/sdk/logs/batch_log_record_processor_options.h>
#include <opentelemetry/sdk/logs/logger_provider_factory.h>
#include <opentelemetry/sdk/resource/resource.h>

#include <glog/logging.h>
#include <unistd.h>

#include <algorithm>
#include <fstream>
#include <sstream>

namespace logs_sdk = opentelemetry::v1::sdk::logs;
namespace otlp = opentelemetry::v1::exporter::otlp;
namespace resource = opentelemetry::v1::sdk::resource;

DEFINE_string(
    otel_endpoint,
    "http://localhost:4318",
    "OTLP HTTP endpoint for OpenTelemetry export");

DEFINE_string(
    otel_resource_env_file,
    "",
    "Path to a KEY=VALUE file with additional OTLP resource attributes "
    "(keys are lowercased before being set). "
    "Empty means disabled.");

DEFINE_string(
    otel_resource_attrs,
    "",
    "Comma-separated KEY=VALUE pairs to set as OTLP resource attributes. "
    "These are set in addition to host_name.");

DEFINE_string(
    otel_metric_mappings_file,
    "",
    "Path to a CSV file defining DCGM metric name mappings. Each line is:\n"
    "  dcgm_name,output_name,scale_factor   (numeric metrics)\n"
    "  dcgm_name,output_name                (string metrics, no scale)\n"
    "When empty, built-in default mappings are used (pass-through).");

namespace dynolog {

namespace {

// Parse the metric mappings file. Returns true if file was loaded.
// Populates numeric_mappings (3-field lines) and string_mappings (2-field
// lines).
bool loadMappingsFile(
    const std::string& path,
    std::unordered_map<std::string, MetricMapping>& numeric_mappings,
    std::unordered_map<std::string, std::string>& string_mappings) {
  std::ifstream file(path);
  if (!file.is_open()) {
    LOG(WARNING) << "Could not open otel_metric_mappings_file: " << path;
    return false;
  }
  std::string line;
  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '#') {
      continue;
    }
    // Split on commas: dcgm_name,output_name[,scale_factor]
    std::stringstream ss(line);
    std::string dcgm_name, output_name, scale_str;
    if (!std::getline(ss, dcgm_name, ',') ||
        !std::getline(ss, output_name, ',')) {
      continue;
    }
    if (std::getline(ss, scale_str, ',') && !scale_str.empty()) {
      try {
        double scale = std::stod(scale_str);
        numeric_mappings[dcgm_name] = {output_name, scale};
      } catch (const std::exception&) {
        LOG(WARNING) << "Invalid scale in mappings file: " << line;
      }
    } else {
      string_mappings[dcgm_name] = output_name;
    }
  }
  LOG(INFO) << "Loaded " << numeric_mappings.size() << " numeric and "
            << string_mappings.size() << " string metric mappings from "
            << path;
  return true;
}

} // namespace

const std::unordered_map<std::string, std::string>& getStringMappings() {
  static const auto mappings = [] {
    std::unordered_map<std::string, std::string> m;
    if (!FLAGS_otel_metric_mappings_file.empty()) {
      std::unordered_map<std::string, MetricMapping> unused;
      loadMappingsFile(FLAGS_otel_metric_mappings_file, unused, m);
    }
    // Default: pass-through (no renaming) when no file is provided.
    return m;
  }();
  return mappings;
}

const std::unordered_map<std::string, MetricMapping>& getMetricMappings() {
  static const auto mappings = [] {
    std::unordered_map<std::string, MetricMapping> m;
    if (!FLAGS_otel_metric_mappings_file.empty()) {
      std::unordered_map<std::string, std::string> unused;
      loadMappingsFile(FLAGS_otel_metric_mappings_file, m, unused);
    }
    // Default: pass-through (no renaming) when no file is provided.
    return m;
  }();
  return mappings;
}

OtlpManager::OtlpManager() {
  std::string endpoint = FLAGS_otel_endpoint;
  const char* env_endpoint = std::getenv("OTEL_EXPORTER_OTLP_ENDPOINT");
  if (env_endpoint) {
    endpoint = env_endpoint;
  }
  // Strip trailing slash to avoid double-slash in URL
  if (!endpoint.empty() && endpoint.back() == '/') {
    endpoint.pop_back();
  }

  otlp::OtlpHttpLogRecordExporterOptions exporter_opts;
  exporter_opts.url = endpoint + "/v1/logs";
  exporter_opts.content_type = otlp::HttpRequestContentType::kBinary;
  exporter_opts.ssl_insecure_skip_verify = true;
  auto exporter = otlp::OtlpHttpLogRecordExporterFactory::Create(exporter_opts);

  logs_sdk::BatchLogRecordProcessorOptions processor_opts;
  processor_opts.max_queue_size = 2048;
  processor_opts.schedule_delay_millis = std::chrono::milliseconds(5000);
  processor_opts.max_export_batch_size = 512;
  auto processor = logs_sdk::BatchLogRecordProcessorFactory::Create(
      std::move(exporter), processor_opts);

  // Resolve hostname: prefer K8S_NODE_NAME env var (Downward API) over
  // gethostname() which returns the pod name in containerized environments.
  std::string hostname;
  const char* node_name = std::getenv("K8S_NODE_NAME");
  if (node_name && node_name[0] != '\0') {
    hostname = node_name;
  } else {
    char hostbuf[256];
    if (::gethostname(hostbuf, sizeof(hostbuf)) == 0) {
      hostbuf[sizeof(hostbuf) - 1] = '\0';
      hostname = hostbuf;
    } else {
      hostname = "unknown";
    }
  }

  // Build resource attributes: start with built-in attrs, then layer on
  // --otel_resource_attrs (flag), then --otel_resource_env_file (file).
  // Later sources can override earlier ones.
  auto resource_attrs = resource::ResourceAttributes{
      {"service.name", "dynolog"},
      {"host_name", hostname},
  };

  // Helper: lowercase a string for attribute key normalization.
  auto toLower = [](std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
  };

  // Parse --otel_resource_attrs flag (comma-separated KEY=VALUE pairs).
  if (!FLAGS_otel_resource_attrs.empty()) {
    std::stringstream ss(FLAGS_otel_resource_attrs);
    std::string pair;
    while (std::getline(ss, pair, ',')) {
      auto pos = pair.find('=');
      if (pos != std::string::npos && pos + 1 <= pair.size()) {
        resource_attrs.SetAttribute(
            toLower(pair.substr(0, pos)), pair.substr(pos + 1));
      }
    }
  }

  // Parse --otel_resource_env_file (KEY=VALUE lines, one per line).
  // Typically written by an init container that reads platform-specific
  // metadata (e.g., K8s node labels). Keys are lowercased.
  if (!FLAGS_otel_resource_env_file.empty()) {
    std::ifstream meta_file(FLAGS_otel_resource_env_file);
    if (meta_file.is_open()) {
      std::string line;
      while (std::getline(meta_file, line)) {
        auto pos = line.find('=');
        if (pos != std::string::npos && pos + 1 <= line.size()) {
          auto val = line.substr(pos + 1);
          if (!val.empty()) {
            resource_attrs.SetAttribute(toLower(line.substr(0, pos)), val);
          }
        }
      }
    } else {
      LOG(WARNING) << "Could not open otel_resource_env_file: "
                   << FLAGS_otel_resource_env_file;
    }
  }

  auto res = resource::Resource::Create(resource_attrs);

  provider_ =
      logs_sdk::LoggerProviderFactory::Create(std::move(processor), res);
  logger_ = provider_->GetLogger("dynolog", "dynolog", "1.0.0");

  LOG(INFO) << "OTel OTLP logger initialized, endpoint=" << exporter_opts.url
            << ", host_name=" << hostname;
  for (const auto& [key, val] : res.GetAttributes()) {
    // val is opentelemetry::sdk::common::OwnedAttributeValue
    if (auto* s = std::get_if<std::string>(&val)) {
      LOG(INFO) << "  resource attr: " << key << "=" << *s;
    }
  }
}

OtlpManager::~OtlpManager() {
  if (provider_) {
    provider_->ForceFlush();
    provider_->Shutdown();
  }
}

// static
std::shared_ptr<OtlpManager> OtlpManager::singleton() {
  static auto manager = std::make_shared<OtlpManager>();
  return manager;
}

void OtlpManager::emitLog(
    Logger::Timestamp ts,
    const std::unordered_map<std::string, double>& numeric_attrs,
    const std::unordered_map<std::string, int64_t>& int_attrs,
    const std::unordered_map<std::string, std::string>& string_attrs) {
  if (!logger_) {
    return;
  }

  auto record = logger_->CreateLogRecord();
  if (!record) {
    return;
  }

  record->SetTimestamp(opentelemetry::common::SystemTimestamp(ts));

  for (const auto& [key, val] : numeric_attrs) {
    record->SetAttribute(key, val);
  }
  for (const auto& [key, val] : int_attrs) {
    record->SetAttribute(key, val);
  }
  for (const auto& [key, val] : string_attrs) {
    record->SetAttribute(key, val);
  }

  logger_->EmitLogRecord(std::move(record));
}

void OtlpLogger::setTimestamp(Timestamp ts) {
  ts_ = ts;
}

void OtlpLogger::logInt(const std::string& key, int64_t val) {
  int_kvs_[key] = val;
}

void OtlpLogger::logFloat(const std::string& key, float val) {
  float_kvs_[key] = static_cast<double>(val);
}

void OtlpLogger::logUint(const std::string& key, uint64_t val) {
  int_kvs_[key] = static_cast<int64_t>(val);
}

void OtlpLogger::logStr(const std::string& key, const std::string& val) {
  string_kvs_[key] = val;
}

void OtlpLogger::finalize() {
  const auto& mappings = getMetricMappings();

  std::unordered_map<std::string, double> mapped_floats;
  std::unordered_map<std::string, int64_t> mapped_ints;

  for (const auto& [key, val] : float_kvs_) {
    auto it = mappings.find(key);
    if (it != mappings.end()) {
      mapped_floats[it->second.output_name] = val * it->second.scale_factor;
    } else {
      mapped_floats[key] = val;
    }
  }

  for (const auto& [key, val] : int_kvs_) {
    auto it = mappings.find(key);
    if (it != mappings.end()) {
      mapped_ints[it->second.output_name] =
          static_cast<int64_t>(val * it->second.scale_factor);
    } else {
      mapped_ints[key] = val;
    }
  }

  // Apply string key mappings.
  const auto& str_mappings = getStringMappings();
  std::unordered_map<std::string, std::string> mapped_strings;
  for (const auto& [key, val] : string_kvs_) {
    auto it = str_mappings.find(key);
    if (it != str_mappings.end()) {
      mapped_strings[it->second] = val;
    } else {
      mapped_strings[key] = val;
    }
  }

  OtlpManager::singleton()->emitLog(
      ts_, mapped_floats, mapped_ints, mapped_strings);

  float_kvs_.clear();
  int_kvs_.clear();
  string_kvs_.clear();
}

} // namespace dynolog
#endif // USE_OTEL
