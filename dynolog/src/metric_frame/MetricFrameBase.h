// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "dynolog/src/metric_frame/MetricFrameTsUnitInterface.h"
#include "dynolog/src/metric_frame/MetricSeries.h"

#include <memory>
#include <stdexcept>
#include <string>
#include <variant>

namespace facebook::dynolog {

using SampleVarT = std::variant<int64_t, double, PerfReadValues>;
using MetricSeriesInt64Ptr = std::shared_ptr<MetricSeries<int64_t>>;
using MetricSeriesDoublePtr = std::shared_ptr<MetricSeries<double>>;
using MetricSeriesPerfReadValuePtr =
    std::shared_ptr<MetricSeries<PerfReadValues>>;
using MetricSeriesVar = std::variant<
    MetricSeriesInt64Ptr,
    MetricSeriesDoublePtr,
    MetricSeriesPerfReadValuePtr>;

class MetricFrameSlice;

class MetricFrameBase {
 public:
  MetricFrameBase(
      std::string name,
      std::string description,
      std::shared_ptr<MetricFrameTsUnitInterface> ts);
  virtual ~MetricFrameBase() = default;
  const std::string& name() const;
  const std::string& description() const;
  size_t length() const;
  size_t maxLength() const;
  std::optional<TimePoint> firstSampleTime() const;
  std::optional<TimePoint> lastSampleTime() const;
  std::optional<MetricFrameSlice> slice(
      TimePoint startTime,
      TimePoint endTime,
      MATCH_POLICY startTimePolicy = MATCH_POLICY::CLOSEST,
      MATCH_POLICY endTimePolicy = MATCH_POLICY::CLOSEST) const;
  virtual size_t width() const = 0;
  virtual std::optional<MetricSeriesVar> series(
      const std::string& name) const = 0;
  virtual std::optional<MetricSeriesVar> series(int name) const = 0;

 protected:
  void addSample(const SampleVarT& sample, MetricSeriesVar& seriesVar);
  std::string name_;
  std::string description_;
  std::shared_ptr<MetricFrameTsUnitInterface> ts_;
};

template <typename T>
class MetricSeriesSlice {
 public:
  const std::string& name() const {
    return series_.name();
  }
  const std::string& description() const {
    return series_.description();
  }
  size_t size() const {
    return series_.size();
  }

  template <typename R>
  R rate(std::chrono::steady_clock::duration period) const {
    return series_.template rate<R>(
        period,
        range_.end.time - range_.start.time,
        series_.begin() + range_.start.offset,
        series_.begin() + range_.end.offset + 1);
  }
  template <typename R>
  R avg() const {
    return series_.template avg<R>(
        series_.begin() + range_.start.offset,
        series_.begin() + range_.end.offset + 1);
  }
  T percentile(float percentage) const {
    return series_.percentile(
        percentage,
        series_.begin() + range_.start.offset,
        series_.begin() + range_.end.offset + 1);
  }
  T diff() const {
    return series_.diff(
        series_.begin() + range_.start.offset,
        series_.begin() + range_.end.offset + 1);
  }

 protected:
  MetricSeriesSlice(
      const MetricSeries<T>& series,
      const MetricFrameRange& range)
      : series_{series}, range_{range} {}
  const MetricSeries<T>& series_;
  MetricFrameRange range_;

  friend class MetricFrameSlice;
};

class MetricFrameSlice {
 public:
  template <typename T>
  std::optional<MetricSeriesSlice<T>> series(const std::string& name) const {
    auto seriesVar = frame_.series(name);
    if (!seriesVar.has_value()) {
      return std::nullopt;
    }
    return getSeriesFromVar<T>(seriesVar.value(), range_);
  }
  template <typename T>
  std::optional<MetricSeriesSlice<T>> series(int name) const {
    auto seriesVar = frame_.series(name);
    if (!seriesVar.has_value()) {
      return std::nullopt;
    }
    return getSeriesFromVar<T>(seriesVar.value(), range_);
  }

 protected:
  MetricFrameSlice(const MetricFrameBase& frame, MetricFrameRange range);
  const MetricFrameBase& frame_;
  MetricFrameRange range_;

 private:
  template <typename T>
  static std::optional<MetricSeriesSlice<T>> getSeriesFromVar(
      const MetricSeriesVar& seriesVar,
      const MetricFrameRange& range) {
    auto seriesPtrMaybe =
        std::get_if<std::shared_ptr<MetricSeries<T>>>(&seriesVar);
    if (!seriesPtrMaybe) {
      return std::nullopt;
    }
    return MetricSeriesSlice<T>(**seriesPtrMaybe, range);
  }

  friend class MetricFrameBase;
};

} // namespace facebook::dynolog
