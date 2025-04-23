// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/PrometheusLogger.h"
#include "dynolog/src/Metrics.h"
#include "hbt/src/common/System.h"

#include <fmt/format.h>
#include <glog/logging.h>

#ifdef USE_PROMETHEUS
using namespace prometheus;

DEFINE_string(
    prometheus_address,
    "127.0.0.1",
    "IP address to bind the Prometheus HTTP server to.");

DEFINE_int32(
    prometheus_port,
    8080,
    "Port to setup HTTP server for Prometheus to scrape.");

namespace dynolog {

inline auto& buildGaugeFromMetric(const MetricDesc& m, Registry& registry) {
  return BuildGauge().Name(m.name).Help(m.desc).Register(registry);
}

PrometheusManager::PrometheusManager()
    : exposer_(fmt::format(
          "{}:{}",
          FLAGS_prometheus_address,
          FLAGS_prometheus_port)) {
  LOG(INFO) << "Prometheus HTTP server listening at "
            << FLAGS_prometheus_address << ":" << FLAGS_prometheus_port;

  // setup registry
  registry_ = std::make_shared<Registry>();
  const std::string hostname = facebook::hbt::getHostName();

  // setup counters and gauges
  for (const auto& m : getAllMetrics()) {
    // all metric types fit with Gauges so far.
    auto& g =
        buildGaugeFromMetric(m, *registry_).Add({{"host_name", hostname}});
    gauges_[m.name] = &g;
  }

  // setup dynamic counters
  for (const auto& m : getNetworkMetrics()) {
    // creates metric families
    auto& mf = buildGaugeFromMetric(m, *registry_);
    dynamic_metrics_[m.name] = &mf;
  }

  // setup registry
  exposer_.RegisterCollectable(registry_);
}

bool PrometheusManager::ensureDynamicKey(const std::string& key) {
  if (key.find('.') == std::string::npos) {
    return false;
  }
  auto parts = splitKey(key);

  auto it = dynamic_metrics_.find(parts.metric);
  if (it == dynamic_metrics_.end()) {
    return false;
  }

  // Currently only kind of dynamic metrics include network metrics
  const std::string hostname = facebook::hbt::getHostName();
  auto& g = it->second->Add({{"host_name", hostname}, {"net", parts.entity}});

  DLOG(INFO) << "Adding dynamic metric " << parts.metric
             << " for entity = " << parts.entity << " overall key = " << key;

  gauges_[key] = &g;
  return true;
}

void PrometheusManager::log(const std::string& key, double val) {
  // First let's check if a gauge metric exists
  auto it = gauges_.find(key);
  if (it == gauges_.end()) {
    // Try to setup a dynamic metric on the fly
    if (ensureDynamicKey(key)) {
      // find it again
      it = gauges_.find(key);
    } else {
      return;
    }
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
