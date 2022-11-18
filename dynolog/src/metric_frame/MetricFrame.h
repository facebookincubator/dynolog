// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "dynolog/src/metric_frame/MetricFrameBase.h"
#include "dynolog/src/metric_frame/MetricFrameTsUnitInterface.h"
#include "dynolog/src/metric_frame/MetricSeries.h"

#include <cmath>
#include <map>
#include <memory>
#include <variant>
#include <vector>

namespace facebook::dynolog {

using MapSamplesT = std::vector<std::pair<std::string, SampleVarT>>;
using VectorSamplesT = std::vector<SampleVarT>;

class MetricFrameMap : public MetricFrameBase {
 public:
  MetricFrameMap(
      size_t capacity,
      std::string name,
      std::string description,
      std::shared_ptr<MetricFrameTsUnitInterface> ts);
  bool addSeries(const std::string& key, MetricSeriesVar seriesVar);
  bool eraseSeries(const std::string& name);
  bool addSamples(const MapSamplesT& samples, TimePoint time);
  size_t width() const override;
  std::optional<MetricSeriesVar> series(const std::string& name) const override;
  std::optional<MetricSeriesVar> series(int name) const override;

 protected:
  std::map<std::string, MetricSeriesVar> series_;
};

using VectorSeriesDefList = std::vector<MetricSeriesVar>;

class MetricFrameVector : public MetricFrameBase {
 public:
  MetricFrameVector(
      VectorSeriesDefList defs,
      std::string name,
      std::string description,
      std::shared_ptr<MetricFrameTsUnitInterface> ts);
  bool addSamples(const VectorSamplesT& samples, TimePoint time);
  size_t width() const override;
  std::optional<MetricSeriesVar> series(const std::string& name) const override;
  std::optional<MetricSeriesVar> series(int name) const override;

 protected:
  VectorSeriesDefList series_;
};

} // namespace facebook::dynolog
