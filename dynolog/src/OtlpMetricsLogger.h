/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include "dynolog/src/Logger.h"

#ifdef USE_OTLP

#  include "opentelemetry/proto/collector/metrics/v1/metrics_service.pb.h"
#  include "opentelemetry/proto/resource/v1/resource.pb.h"

DECLARE_string(otlp_endpoint);
DECLARE_string(otlp_service_name);
DECLARE_string(otlp_headers);
DECLARE_int32(otlp_timeout_ms);
DECLARE_int32(otlp_max_queue_size);
DECLARE_int32(otlp_export_interval_ms);

namespace dynolog {

// Describes how a dynolog metric key maps to an OTEL metric.
struct OTLPMetricMapping {
  std::string otel_name; // e.g. "cpu_util"
  std::string unit;      // e.g. "1", "ms", "By"
  // Static attributes to attach (e.g. state=user, direction=receive)
  std::vector<std::pair<std::string, std::string>> attributes;
  // Multiplier applied to raw value before export (1.0 = no scaling,
  // 0.01 = percent-to-ratio, 0.001 = ms-to-s).
  double scale_factor = 1.0;
  // If true, this key should not be exported (metadata only)
  bool skip = false;
};

// Result of parsing a dynolog metric key.
struct ParsedMetricKey {
  OTLPMetricMapping mapping;
  // Dynamic attributes extracted from the key (e.g. device name, socket id)
  std::vector<std::pair<std::string, std::string>> dynamic_attributes;
  bool matched = false; // true if key was recognized
};

// Parse a dynolog metric key into OTEL metric info.
// Exposed for testing.
ParsedMetricKey parseMetricKey(const std::string& key);

// Exposed for testing.
std::string getEnvOr(const char* name, const std::string& fallback);
std::vector<std::pair<std::string, std::string>> parseHeaders(
    const std::string& raw);

// OTLPManager is a process-wide singleton that owns configuration, the
// pre-built Resource proto, serialization, and async HTTP export. A single
// mutex serializes metric recording across all collector threads (kernel,
// perf, GPU). A separate export_mutex_ protects the payload queue consumed
// by a dedicated background thread that POSTs via libcurl.
class OTLPManager {
 public:
  struct LoggingGuard {
    std::shared_ptr<OTLPManager> manager;
    std::lock_guard<std::mutex> lock_guard;
  };

  OTLPManager();
  ~OTLPManager();

  static LoggingGuard singleton();
  static bool isInitialized();

  // Queue a serialized protobuf payload for async HTTP export.
  // Thread-safe: called from collector threads holding mutex_.
  void queuePayload(std::string payload);

  // Build a complete ExportMetricsServiceRequest protobuf from the given
  // metrics and string attributes. Returns the serialized protobuf bytes.
  std::string serializeMetrics(
      const std::unordered_map<std::string, double>& metrics,
      const std::unordered_map<std::string, std::string>& attributes);

  const std::string& endpoint() const {
    return endpoint_;
  }

 private:
  std::lock_guard<std::mutex> lock() {
    return std::lock_guard{mutex_};
  }

  // Populate resource_ with service.name, host.name, os.type attributes.
  void buildResource();

  // Configuration (resolved from flags + env var overrides in constructor).
  std::string endpoint_;
  std::string service_name_;
  std::vector<std::pair<std::string, std::string>> headers_;
  int32_t timeout_ms_ = 30000;
  int32_t max_queue_size_ = 1000;
  std::string ssl_ca_cert_path_;
  std::string ssl_client_cert_path_;
  std::string ssl_client_key_path_;

  // Pre-built Resource proto (populated once in constructor).
  opentelemetry::proto::resource::v1::Resource resource_;

  std::mutex mutex_;

  // Background export thread and queue (separate lock domain from mutex_).
  void exportLoop();
  bool httpPost(const std::string& payload);

  std::thread export_thread_;
  std::condition_variable export_cv_;
  std::mutex export_mutex_;
  std::queue<std::string> export_queue_;
  std::atomic<bool> shutdown_{false};

  // Should match googletest/include/gtest/gtest_prod.h
  friend class OTLPLoggerTest_MetricMappingCPU_Test;
  friend class OTLPLoggerTest_MetricMappingNetwork_Test;
  friend class OTLPLoggerTest_MetricMappingGPU_Test;
  friend class OTLPLoggerTest_SerializeBasic_Test;
  friend class OTLPLoggerTest_SerializeResource_Test;
  friend class OTLPLoggerTest_SerializeSkipAndNaN_Test;
  friend class OTLPLoggerTest_SerializeScaleFactor_Test;
  friend class OTLPLoggerTest_SerializeGPUAttributes_Test;
  friend class OTLPLoggerTest_ConfigEndpoint_Test;
  friend class OTLPLoggerTest_AsyncQueueAndSignal_Test;
  friend class OTLPLoggerTest_AsyncShutdownDrain_Test;
  friend class OTLPLoggerTest_SerializeEmptyMetrics_Test;
  friend class OTLPLoggerTest_SerializeAllSkipped_Test;
  friend class OTLPLoggerTest_SerializeAllNaN_Test;
};

class OTLPLogger : public Logger {
 public:
  // OTel SDK handles timestamps.
  void setTimestamp(Timestamp /*ts*/) override {}

  void logInt(const std::string& key, int64_t val) override {
    pending_metrics_[key] = static_cast<double>(val);
  }

  void logFloat(const std::string& key, float val) override {
    pending_metrics_[key] = static_cast<double>(val);
  }

  void logUint(const std::string& key, uint64_t val) override {
    pending_metrics_[key] = static_cast<double>(val);
  }

  void logStr(const std::string& key, const std::string& val) override;

  void finalize() override;

 private:
  // Accumulated numeric metrics for this collection cycle.
  std::unordered_map<std::string, double> pending_metrics_;
  // String attributes (e.g. Slurm job_id, username) for this cycle.
  std::unordered_map<std::string, std::string> pending_attributes_;

  friend class OTLPLoggerTest_BasicTest_Test;
  friend class OTLPLoggerTest_SlurmAttribution_Test;
  friend class OTLPLoggerTest_FinalizeEmpty_Test;
  friend class OTLPLoggerTest_FinalizeMultiple_Test;
  friend class OTLPLoggerTest_UnknownMetric_Test;
  friend class OTLPLoggerTest_LogStrNonAttribution_Test;
  friend class OTLPLoggerTest_NaNAndInfValues_Test;
  friend class OTLPLoggerTest_LargeUint64Values_Test;
  friend class OTLPLoggerTest_ZeroValues_Test;
  friend class OTLPLoggerTest_NegativeValues_Test;
  friend class OTLPLoggerTest_OverwriteMetricValue_Test;
  friend class OTLPLoggerTest_OverwriteStringAttribute_Test;
  friend class OTLPLoggerTest_EmptyStringLogStr_Test;
  friend class OTLPLoggerTest_MixedMetricTypes_Test;
  friend class OTLPLoggerTest_SetTimestampIsNoOp_Test;
  friend class OTLPLoggerTest_DeviceIdExtraction_Test;
  friend class OTLPLoggerTest_GPUAttributeMerging_Test;
  friend class OTLPLoggerTest_FinalizeClearsState_Test;
  friend class OTLPLoggerTest_CompleteMetricFlowWithoutNetwork_Test;
  friend class OTLPLoggerTest_MultiThreadedIsolation_Test;
};

} // namespace dynolog
#endif // USE_OTLP
