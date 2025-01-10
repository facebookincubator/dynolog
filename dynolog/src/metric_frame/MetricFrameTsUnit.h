// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "dynolog/src/metric_frame/MetricFrameTsUnitInterface.h"
#include "dynolog/src/metric_frame/MetricSeries.h"

#include <optional>

namespace facebook::dynolog {

class MetricFrameTsUnit : public MetricFrameTsUnitInterface {
 public:
  explicit MetricFrameTsUnit(size_t frameLength);
  virtual void addSample(TimePoint time) override;
  virtual std::optional<TimePoint> firstSampleTime() const override;
  virtual std::optional<TimePoint> lastSampleTime() const override;
  virtual std::vector<TimePoint> getTimeVector() const override;
  virtual size_t length() const override;
  virtual size_t maxLength() const override;
  virtual std::optional<MetricFrameRange> getRange(
      TimePoint startTime,
      TimePoint endTime,
      MATCH_POLICY startTimePolicy,
      MATCH_POLICY endTimePolicy) const override;

 protected:
  MetricSeries<TimePoint> timeSeries_;

  std::optional<MetricFrameOffset> findMatchingOffset(
      TimePoint time,
      MATCH_POLICY policy) const;
  std::optional<MetricFrameOffset> closestPolicy(TimePoint time) const;
  std::optional<MetricFrameOffset> prevClosestPolicy(TimePoint time) const;
  std::optional<MetricFrameOffset> nextClosestPolicy(TimePoint time) const;
};

class MetricFrameTsUnitFixInterval : public MetricFrameTsUnitInterface {
 public:
  MetricFrameTsUnitFixInterval(
      std::chrono::microseconds interval,
      size_t frameLength);
  virtual void addSample(TimePoint time) override;
  virtual std::optional<TimePoint> firstSampleTime() const override;
  virtual std::optional<TimePoint> lastSampleTime() const override;
  virtual std::vector<TimePoint> getTimeVector() const override;
  virtual size_t length() const override;
  virtual size_t maxLength() const override;
  virtual std::optional<MetricFrameRange> getRange(
      TimePoint startTime,
      TimePoint endTime,
      MATCH_POLICY startTimePolicy,
      MATCH_POLICY endTimePolicy) const override;

 protected:
  const std::chrono::microseconds interval_;
  const size_t frameLength_;
  size_t sampleCount_ = 0;
  TimePoint lastSampleTime_;

  TimePoint offsetToTime(size_t offset) const;
  std::optional<MetricFrameOffset> findMatchingOffset(
      TimePoint requestedTime,
      MATCH_POLICY policy) const;

  std::optional<size_t> closestPolicy(double offsetFloat) const;
  std::optional<size_t> prevClosestPolicy(double offsetFloat) const;
  std::optional<size_t> nextClosestPolicy(double offsetFloat) const;
};

} // namespace facebook::dynolog
