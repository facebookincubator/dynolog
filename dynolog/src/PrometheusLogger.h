// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "dynolog/src/Logger.h"

#ifdef USE_PROMETHEUS
#include <prometheus/counter.h>
#include <prometheus/exposer.h>
#include <prometheus/gauge.h>
#include <prometheus/registry.h>
#endif

#include <memory>
#include <mutex>
#include <unordered_map>

#ifdef USE_PROMETHEUS

DECLARE_string(prometheus_address);
DECLARE_int32(prometheus_port);

namespace dynolog {

class PrometheusManager {
 public:
  struct LoggingGuard {
    std::shared_ptr<PrometheusManager> manager;
    std::lock_guard<std::mutex> lock_guard;
  };

  PrometheusManager();

  // Add dynamic metrics if required
  // returns true if a key was added
  bool ensureDynamicKey(const std::string& key);

  // Note that this method is not thread-safe and so
  // should only be used with the LoggingGuard in scope
  void log(const std::string& key, double val);

  static LoggingGuard singleton();

 private:
  using GaugeFamily = prometheus::Family<prometheus::Gauge>;
  std::lock_guard<std::mutex> lock() {
    return std::lock_guard{mutex_};
  }

  std::mutex mutex_;
  prometheus::Exposer exposer_;
  std::shared_ptr<prometheus::Registry> registry_;

  // only store a reference to Gauge because copying is not allowed
  std::unordered_map<std::string, prometheus::Gauge*> gauges_;

  // metric families that need dynamic dimensions
  std::unordered_map<std::string, GaugeFamily*> dynamic_metrics_;

  // Should match googletest/include/gtest/gtest_prod.h
  // friend class test_case_name##_##test_name##_Test
  friend class PrometheusLoggerTest_ExporterTest_Test;
};

class PrometheusLogger : public Logger {
 public:
  // Timestamp is set during logging part.
  void setTimestamp(Timestamp /*ts*/) override {}

  void logInt(const std::string& key, int64_t val) override {
    logImpl(key, static_cast<double>(val));
  }

  void logFloat(const std::string& key, float val) override {
    logImpl(key, static_cast<double>(val));
  }

  void logUint(const std::string& key, uint64_t val) override {
    logImpl(key, static_cast<double>(val));
  }

  // not supported
  void logStr(const std::string& /*key*/, const std::string& /*val*/) override {
  }

  void finalize() override;

 private:
  void logImpl(const std::string& key, double val);

  std::unordered_map<std::string, double> kvs_;

  friend class PrometheusLoggerTest_BasicTest_Test;
  friend class PrometheusLoggerTest_ExporterTest_Test;
};

} // namespace dynolog
#endif // USE_PROMETHEUS
