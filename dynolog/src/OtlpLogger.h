/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "dynolog/src/Logger.h"

#ifdef USE_OTEL

#include <opentelemetry/logs/provider.h>
#include <opentelemetry/sdk/logs/logger_provider.h>

#include <memory>
#include <string>
#include <unordered_map>

DECLARE_string(otel_endpoint);
DECLARE_string(otel_resource_env_file);
DECLARE_string(otel_resource_attrs);
DECLARE_string(otel_metric_mappings_file);

namespace dynolog {

// Holds a metric name mapping with optional scale factor.
struct MetricMapping {
  std::string output_name;
  double scale_factor{}; // 1.0 = pass-through, 100.0 = percentage conversion
};

// Returns the DCGM -> output name mapping tables (loaded from
// --otel_metric_mappings_file, or empty if not configured).
const std::unordered_map<std::string, MetricMapping>& getMetricMappings();
const std::unordered_map<std::string, std::string>& getStringMappings();

// Singleton that owns the OTel SDK stack:
// LoggerProvider -> BatchLogRecordProcessor -> OtlpHttpLogRecordExporter
class OtlpManager {
 public:
  OtlpManager();
  ~OtlpManager();
  OtlpManager(const OtlpManager&) = delete;
  OtlpManager& operator=(const OtlpManager&) = delete;
  OtlpManager(OtlpManager&&) = delete;
  OtlpManager& operator=(OtlpManager&&) = delete;

  void emitLog(
      Logger::Timestamp ts,
      const std::unordered_map<std::string, double>& numeric_attrs,
      const std::unordered_map<std::string, int64_t>& int_attrs,
      const std::unordered_map<std::string, std::string>& string_attrs);

  static std::shared_ptr<OtlpManager> singleton();

 private:
  opentelemetry::nostd::shared_ptr<opentelemetry::logs::Logger> logger_;
  std::shared_ptr<opentelemetry::sdk::logs::LoggerProvider> provider_;
};

// Per-cycle logger that buffers metrics and emits one LogRecord per finalize().
// Each LogRecord represents one GPU device snapshot.
class OtlpLogger : public Logger {
 public:
  OtlpLogger() = default;

  void setTimestamp(Timestamp ts) override;
  void logInt(const std::string& key, int64_t val) override;
  void logFloat(const std::string& key, float val) override;
  void logUint(const std::string& key, uint64_t val) override;
  void logStr(const std::string& key, const std::string& val) override;
  void finalize() override;

 private:
  Timestamp ts_;
  std::unordered_map<std::string, double> float_kvs_;
  std::unordered_map<std::string, int64_t> int_kvs_;
  std::unordered_map<std::string, std::string> string_kvs_;

  friend class OtlpLoggerTest_ScaleTransformBuffering_Test;
  friend class OtlpLoggerTest_StringMappingAppliedOnFinalize_Test;
  friend class OtlpLoggerTest_EmptyMetrics_Test;
  friend class OtlpLoggerTest_UnmappedMetricsPassThrough_Test;
  friend class OtlpLoggerTest_MultipleFinalizeCycles_Test;
  friend class OtlpLoggerTest_IntPreservation_Test;
};

} // namespace dynolog
#endif // USE_OTEL
