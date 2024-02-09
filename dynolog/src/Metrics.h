// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <string>
#include <vector>

namespace dynolog {

enum class MetricType {
  Delta,
  Instant,
  Ratio,
  Rate,
};

struct MetricDesc {
  std::string name;
  MetricType type;
  std::string desc;
};

const std::vector<MetricDesc> getAllMetrics();

const std::vector<MetricDesc> getNetworkMetrics();

} // namespace dynolog
