// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/PrometheusLogger.h"
#include "dynolog/src/Metrics.h"

#include <fmt/format.h>
#include <glog/logging.h>

#ifdef USE_PROMETHEUS
using namespace prometheus;

DEFINE_int32(
    prometheus_port,
    8080,
    "Port to setup HTTP server for Prometheus to scrape.");

namespace dynolog {

inline auto& buildGaugeFromMetric(const MetricDesc& m, Registry& registry) {
  return BuildGauge().Name(m.name).Help(m.desc).Register(registry);
}

PrometheusManager::PrometheusManager()
    : exposer_(fmt::format("127.0.0.1:{}", FLAGS_prometheus_port)) {
  LOG(INFO) << "Initialized prometheus HTTP server on port = "
            << FLAGS_prometheus_port;

  // setup registry
  registry_ = std::make_shared<Registry>();

  // setup counters and gauges
  for (const auto& m : getAllMetrics()) {
    // all metric types fit with Gauges so far.
    auto& g = buildGaugeFromMetric(m, *registry_).Add({{"host_name", "test"}});
    gauges_[m.name] = &g;
  }

  // setup registry
  exposer_.RegisterCollectable(registry_);
}

void PrometheusManager::log(const std::string& key, double val) {
  auto it = gauges_.find(key);
  if (it == gauges_.end()) {
    return;
  }
  auto g = it->second;
  if (!g) {
    return;
  }
  g->Set(val);
}

static std::shared_ptr<PrometheusManager> singleton_() {
  static std::shared_ptr<PrometheusManager> manager_ =
      std::make_shared<PrometheusManager>();
  return manager_;
}

// static
PrometheusManager::LoggingGuard PrometheusManager::singleton() {
  auto s = singleton_();
  return LoggingGuard{.manager = s, .lock_guard = s->lock()};
}

void PrometheusLogger::logImpl(const std::string& key, double val) {
  kvs_[key] = val;
}

void PrometheusLogger::finalize() {
  auto logging_guard = PrometheusManager::singleton();
  auto prom = logging_guard.manager;
  for (const auto& [key, val] : kvs_) {
    prom->log(key, val);
  }
}

} // namespace dynolog
#endif // USE_PROMETHEUS
