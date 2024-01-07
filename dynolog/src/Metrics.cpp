// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/Metrics.h"

#include <fmt/format.h>
#include <unordered_map>

namespace dynolog {

const std::vector<MetricDesc> getAllMetrics() {
  static std::vector<MetricDesc> metrics_ = {
      {.name = "cpu_util",
       .type = MetricType::Ratio,
       .desc = "Fraction of total CPU time spend on user or system mode."},
      {.name = "cpu_u",
       .type = MetricType::Ratio,
       .desc = "Fraction of total CPU time spent in user mode."},
      {.name = "cpu_s",
       .type = MetricType::Ratio,
       .desc = "Fraction of total CPU time spent in system mode."},
      {.name = "cpu_i",
       .type = MetricType::Ratio,
       .desc = "Fraction of total CPU time spent in idle mode."},
      {.name = "mips",
       .type = MetricType::Ratio,
       .desc = "Number of million instructions executed per second."},
      {.name = "mega_cycles_per_second",
       .type = MetricType::Ratio,
       .desc = "Number of active CPU clock cycles per second."},
      {.name = "uptime",
       .type = MetricType::Instant,
       .desc = "How long the system has been running in seconds."},
  };
  static std::unordered_map<std::string, std::string> cpustats = {
      {"cpu_u_ms", "user"},
      {"cpu_s_ms", "system"},
      {"cpu_n_ms", "nice"},
      {"cpu_w_ms", "iowait"},
      {"cpu_x_ms", "irq"},
      {"cpu_y_ms", "softirq"},
  };

  auto metrics = metrics_;

  for (const auto& [name, cpu_mode] : cpustats) {
    MetricDesc m{
        .name = name,
        .type = MetricType::Delta,
        .desc = fmt::format(
            "Total CPU time in milliseconds spent in {} mode. "
            "For more details please see man page for /proc/stat",
            cpu_mode)};
    metrics.push_back(m);
  }

  return metrics;
}

} // namespace dynolog
