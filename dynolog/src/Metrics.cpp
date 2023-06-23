// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/Metrics.h"

namespace dynolog {

const std::vector<MetricDesc>& getAllMetrics() {
  static std::vector<MetricDesc> metrics_ = {
      {.name = "cpu_util",
       .type = MetricType::Ratio,
       .desc = "Fraction of total CPU time spend on user or system mode."},
      {.name = "uptime",
       .type = MetricType::Instant,
       .desc = "How long the system has been running in seconds."},
  };
  return metrics_;
}

} // namespace dynolog
