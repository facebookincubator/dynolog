// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/metric_frame/MetricFrameBase.h"

namespace facebook::dynolog {

MetricFrameBase::MetricFrameBase(
    std::string name,
    std::string description,
    std::shared_ptr<MetricFrameTsUnitInterface> ts)
    : name_{std::move(name)},
      description_{std::move(description)},
      ts_{std::move(ts)} {}

const std::string& MetricFrameBase::name() const {
  return name_;
}

const std::string& MetricFrameBase::description() const {
  return description_;
}

size_t MetricFrameBase::length() const {
  return ts_->length();
}

size_t MetricFrameBase::maxLength() const {
  return ts_->maxLength();
}

std::optional<TimePoint> MetricFrameBase::firstSampleTime() const {
  return ts_->firstSampleTime();
}

std::optional<TimePoint> MetricFrameBase::lastSampleTime() const {
  return ts_->lastSampleTime();
}

std::optional<MetricFrameSlice> MetricFrameBase::slice(
    TimePoint startTime,
    TimePoint endTime,
    MATCH_POLICY startTimePolicy,
    MATCH_POLICY endTimePolicy) const {
  auto rangeMaybe =
      ts_->getRange(startTime, endTime, startTimePolicy, endTimePolicy);
  if (!rangeMaybe.has_value()) {
    return std::nullopt;
  }
  return MetricFrameSlice(*this, rangeMaybe.value());
}

template <bool flag = false>
void unknown_type_assert() {
  static_assert(flag, "type provided to add samples is not supported");
}

void MetricFrameBase::addSample(
    const SampleVarT& sampleVar,
    MetricSeriesVar& seriesVar) {
  std::visit(
      [&sampleVar](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<MetricSeriesInt64Ptr, T>) {
          arg->addSample(std::get<int64_t>(sampleVar));
        } else if constexpr (std::is_same_v<T, MetricSeriesDoublePtr>) {
          arg->addSample(std::get<double>(sampleVar));
        } else if constexpr (std::is_same_v<T, MetricSeriesPerfReadValuePtr>) {
          arg->addSample(std::get<PerfReadValues>(sampleVar));
        } else {
          unknown_type_assert();
        }
      },
      seriesVar);
}

MetricFrameSlice::MetricFrameSlice(
    const MetricFrameBase& frame,
    MetricFrameRange range)
    : frame_{frame}, range_{range} {}

} // namespace facebook::dynolog
