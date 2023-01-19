// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/metric_frame/MetricFrame.h"
#include "dynolog/src/metric_frame/MetricFrameTsUnitInterface.h"

#include <stdexcept>

namespace facebook::dynolog {

MetricFrameMap::MetricFrameMap(
    size_t maxLength,
    std::string name,
    std::string description,
    std::shared_ptr<MetricFrameTsUnitInterface> ts)
    : MetricFrameBase(std::move(name), std::move(description), std::move(ts)) {
  if (ts_->maxLength() != maxLength) {
    throw std::invalid_argument(
        "TsUnit maxLength (" + std::to_string(ts_->maxLength()) +
        ") is different from MetricFrame maxLength (" +
        std::to_string(maxLength) + ")");
  }
}

bool MetricFrameMap::addSeries(
    const std::string& key,
    MetricSeriesVar seriesVar) {
  if (series_.count(key)) {
    return false;
  }
  series_.insert({key, std::move(seriesVar)});
  return true;
}

bool MetricFrameMap::eraseSeries(const std::string& name) {
  return series_.erase(name) == 1;
}

bool MetricFrameMap::addSamples(const MapSamplesT& samples, TimePoint time) {
  for (const auto& [name, sampleVar] : samples) {
    if (!series_.count(name)) {
      return false;
    }
  }
  for (const auto& [name, sampleVar] : samples) {
    auto seriesIt = series_.find(name);
    auto& seriesVar = seriesIt->second;
    addSample(sampleVar, seriesVar);
  }
  ts_->addSample(time);
  return true;
}

size_t MetricFrameMap::width() const {
  return series_.size();
};

std::optional<MetricSeriesVar> MetricFrameMap::series(
    const std::string& name) const {
  auto it = series_.find(name);
  if (it == series_.end()) {
    return std::nullopt;
  }
  return it->second;
}

std::optional<MetricSeriesVar> MetricFrameMap::series(const int) const {
  return std::nullopt;
}

MetricFrameVector::MetricFrameVector(
    VectorSeriesDefList defs,
    std::string name,
    std::string description,
    std::shared_ptr<MetricFrameTsUnitInterface> ts)
    : MetricFrameBase(std::move(name), std::move(description), std::move(ts)),
      series_{defs} {}

bool MetricFrameVector::addSamples(
    const VectorSamplesT& samples,
    TimePoint time) {
  if (samples.size() != width()) {
    return false;
  }
  for (size_t idx = 0; idx < series_.size(); idx++) {
    auto& series = series_[idx];
    auto& sample = samples[idx];
    addSample(sample, series);
  }
  ts_->addSample(time);
  return true;
}

size_t MetricFrameVector::width() const {
  return series_.size();
}

std::optional<MetricSeriesVar> MetricFrameVector::series(
    const std::string&) const {
  return std::nullopt;
}

std::optional<MetricSeriesVar> MetricFrameVector::series(int idx) const {
  if (idx >= width()) {
    return std::nullopt;
  }
  return series_[idx];
}

} // namespace facebook::dynolog
