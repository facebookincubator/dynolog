// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/PrometheusLogger.h"
#include <fmt/format.h>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include "dynolog/src/Metrics.h"

namespace dynolog {

TEST(PrometheusLoggerTest, BasicTest) {
  // check that basic logger class is collecting values
  // from various log functions.

  PrometheusLogger logger;

  logger.logInt("uptime", 10000);
  logger.logFloat("pi", 3.1457);
  logger.logUint("cpu_util", 25);
  logger.logUint("rx_bytes.eth0", 42);

  auto& kvs = logger.kvs_;
  EXPECT_FLOAT_EQ(kvs["uptime"], 10000);
  EXPECT_FLOAT_EQ(kvs["pi"], 3.1457);
  EXPECT_FLOAT_EQ(kvs["cpu_util"], 25);
  EXPECT_FLOAT_EQ(kvs["rx_bytes.eth0"], 42);

  // DO NOT RUN finalize() on logger to avoid sending data to prometheus
  // exporter.
}

TEST(PrometheusLoggerTest, ExporterTest) {
  /* Allow Prometheus exporter to use any available port*/
  FLAGS_prometheus_port = 0;
  auto ethm = [](const std::string& name) -> std::string {
    return fmt::format("{}.eth0", name);
  };

  float i = 0, j = 0;
  {
    PrometheusLogger logger;
    for (const auto& m : getAllMetrics()) {
      logger.logFloat(m.name, i++);
    }
    for (const auto& m : getNetworkMetrics()) {
      logger.logFloat(ethm(m.name), i++);
    }
    logger.finalize();

    auto logging_guard = PrometheusManager::singleton();
    auto prom = logging_guard.manager;
    for (const auto& m : getAllMetrics()) {
      EXPECT_FLOAT_EQ(prom->gauges_[m.name]->Value(), j)
          << "Metric " << m.name << " did not match expected value";
      j++;
    }
    // match network metrics that are generated dynamically
    for (const auto& m : getNetworkMetrics()) {
      EXPECT_FLOAT_EQ(prom->gauges_[ethm(m.name)]->Value(), j)
          << "Metric " << ethm(m.name) << " did not match expected value";
      j++;
    }
  }
  ASSERT_GT(i, 0) << "No metrics were logged!";
  ASSERT_EQ(i, j);
}

} // namespace dynolog
