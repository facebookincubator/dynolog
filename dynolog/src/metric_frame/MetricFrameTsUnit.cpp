// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/metric_frame/MetricFrameTsUnit.h"

#include <cmath>
#include <stdexcept>

namespace facebook::dynolog {

MetricFrameTsUnit::MetricFrameTsUnit(size_t frameLength)
    : timeSeries_{
          frameLength,
          "MetricFrameTsUnit",
          "Ring buffer for recording timepoint of samples"} {}

void MetricFrameTsUnit::addSample(TimePoint time) {
  if (timeSeries_.size() > 0 &&
      time <= timeSeries_.at(timeSeries_.size() - 1)) {
    throw std::invalid_argument(
        "new timepoint value " +
        std::to_string(time.time_since_epoch().count()) +
        "is not larger than the previous value " +
        std::to_string(
            timeSeries_.at(timeSeries_.size() - 1).time_since_epoch().count()));
  }
  timeSeries_.addSample(time);
}

std::optional<TimePoint> MetricFrameTsUnit::firstSampleTime() const {
  if (timeSeries_.size() == 0) {
    return std::nullopt;
  }
  return *timeSeries_.begin();
}

std::optional<TimePoint> MetricFrameTsUnit::lastSampleTime() const {
  if (timeSeries_.size() == 0) {
    return std::nullopt;
  }
  return *(timeSeries_.end() - 1);
}

std::vector<TimePoint> MetricFrameTsUnit::getTimeVector() const {
  return std::vector<TimePoint>(timeSeries_.begin(), timeSeries_.end());
}

size_t MetricFrameTsUnit::length() const {
  return timeSeries_.size();
}

size_t MetricFrameTsUnit::maxLength() const {
  return timeSeries_.maxLength();
}

std::optional<MetricFrameRange> MetricFrameTsUnit::getRange(
    TimePoint startTime,
    TimePoint endTime,
    MATCH_POLICY startTimePolicy,
    MATCH_POLICY endTimePolicy) const {
  auto startOffset = findMatchingOffset(startTime, startTimePolicy);
  auto endOffset = findMatchingOffset(endTime, endTimePolicy);
  if (!startOffset.has_value() || !endOffset.has_value()) {
    return std::nullopt;
  }
  return MetricFrameRange{
      .start = startOffset.value(), .end = endOffset.value()};
}

std::optional<MetricFrameOffset> MetricFrameTsUnit::findMatchingOffset(
    TimePoint time,
    MATCH_POLICY policy) const {
  switch (policy) {
    case MATCH_POLICY::CLOSEST:
      return closestPolicy(time);
    case MATCH_POLICY::PREV_CLOSEST:
      return prevClosestPolicy(time);
    case MATCH_POLICY::NEXT_CLOSEST:
      return nextClosestPolicy(time);
  }
}

std::optional<MetricFrameOffset> MetricFrameTsUnit::closestPolicy(
    TimePoint time) const {
  auto prevClosest = prevClosestPolicy(time);
  auto nextClosest = nextClosestPolicy(time);
  if (!prevClosest.has_value() && !nextClosest.has_value()) {
    return std::nullopt;
  }
  if (!prevClosest.has_value()) {
    return nextClosest.value();
  }
  if (!nextClosest.has_value()) {
    return prevClosest.value();
  }
  if (time - prevClosest.value().time < nextClosest.value().time - time) {
    return prevClosest.value();
  }
  return nextClosest.value();
}

std::optional<MetricFrameOffset> MetricFrameTsUnit::prevClosestPolicy(
    TimePoint time) const {
  auto it = std::upper_bound(timeSeries_.begin(), timeSeries_.end(), time);
  if (timeSeries_.size() == 0 || it == timeSeries_.begin()) {
    return std::nullopt;
  }
  return MetricFrameOffset{
      .offset = static_cast<size_t>(it - 1 - timeSeries_.begin()),
      .time = *(it - 1)};
}

std::optional<MetricFrameOffset> MetricFrameTsUnit::nextClosestPolicy(
    TimePoint time) const {
  auto it = std::lower_bound(timeSeries_.begin(), timeSeries_.end(), time);
  if (it == timeSeries_.end()) {
    return std::nullopt;
  }
  return MetricFrameOffset{
      .offset = static_cast<size_t>(it - timeSeries_.begin()), .time = *it};
}

MetricFrameTsUnitFixInterval::MetricFrameTsUnitFixInterval(
    std::chrono::microseconds interval,
    size_t frameLength)
    : interval_{interval}, frameLength_{frameLength} {
  if (interval_.count() == 0) {
    throw std::invalid_argument(
        "interval of MetricFrameTsUnitFixInterval cannot be 0");
  }
}

void MetricFrameTsUnitFixInterval::addSample(TimePoint time) {
  sampleCount_ = std::min(frameLength_, sampleCount_ + 1);
  lastSampleTime_ = time;
}

std::optional<TimePoint> MetricFrameTsUnitFixInterval::firstSampleTime() const {
  if (sampleCount_ == 0) {
    return std::nullopt;
  }
  return lastSampleTime_ - (sampleCount_ - 1) * interval_;
}

std::optional<TimePoint> MetricFrameTsUnitFixInterval::lastSampleTime() const {
  if (sampleCount_ == 0) {
    return std::nullopt;
  }
  return lastSampleTime_;
}

std::vector<TimePoint> MetricFrameTsUnitFixInterval::getTimeVector() const {
  std::vector<TimePoint> res(length());
  for (size_t i = 0; i < length(); i++) {
    res[i] = lastSampleTime_ - (length() - i - 1) * interval_;
  }
  return res;
}

size_t MetricFrameTsUnitFixInterval::length() const {
  return sampleCount_;
}

size_t MetricFrameTsUnitFixInterval::maxLength() const {
  return frameLength_;
}

std::optional<MetricFrameRange> MetricFrameTsUnitFixInterval::getRange(
    TimePoint startTime,
    TimePoint endTime,
    MATCH_POLICY startTimePolicy,
    MATCH_POLICY endTimePolicy) const {
  auto startMaybe = findMatchingOffset(startTime, startTimePolicy);
  auto endMaybe = findMatchingOffset(endTime, endTimePolicy);
  if (!startMaybe.has_value() || !endMaybe.has_value()) {
    return std::nullopt;
  }

  return MetricFrameRange{.start = startMaybe.value(), .end = endMaybe.value()};
}

TimePoint MetricFrameTsUnitFixInterval::offsetToTime(size_t offset) const {
  return lastSampleTime_ - (sampleCount_ - offset - 1) * interval_;
}

std::optional<MetricFrameOffset>
MetricFrameTsUnitFixInterval::findMatchingOffset(
    TimePoint requestedTime,
    MATCH_POLICY policy) const {
  if (sampleCount_ == 0) {
    return std::nullopt;
  }
  double offsetFloat = sampleCount_ - 1 +
      static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(
                              requestedTime - lastSampleTime_)
                              .count()) /
          std::chrono::duration_cast<std::chrono::microseconds>(interval_)
              .count();

  std::optional<size_t> offset;
  switch (policy) {
    case MATCH_POLICY::CLOSEST:
      offset = closestPolicy(offsetFloat);
      break;
    case MATCH_POLICY::PREV_CLOSEST:
      offset = prevClosestPolicy(offsetFloat);
      break;
    case MATCH_POLICY::NEXT_CLOSEST:
      offset = nextClosestPolicy(offsetFloat);
      break;
  }

  if (!offset.has_value()) {
    return std::nullopt;
  }

  return MetricFrameOffset{
      .offset = offset.value(), .time = offsetToTime(offset.value())};
}

std::optional<size_t> MetricFrameTsUnitFixInterval::closestPolicy(
    double offsetFloat) const {
  if (offsetFloat < 0) {
    return 0;
  }
  if (offsetFloat > sampleCount_ - 1) {
    return sampleCount_ - 1;
  }
  return std::lround(offsetFloat);
}

std::optional<size_t> MetricFrameTsUnitFixInterval::prevClosestPolicy(
    double offsetFloat) const {
  if (offsetFloat < 0) {
    return std::nullopt;
  }
  if (offsetFloat > sampleCount_ - 1) {
    return sampleCount_ - 1;
  }
  return std::floor(offsetFloat);
}

std::optional<size_t> MetricFrameTsUnitFixInterval::nextClosestPolicy(
    double offsetFloat) const {
  if (offsetFloat < 0) {
    return 0;
  }
  if (offsetFloat > sampleCount_ - 1) {
    return std::nullopt;
  }
  return std::ceil(offsetFloat);
}

} // namespace facebook::dynolog
