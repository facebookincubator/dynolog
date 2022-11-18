// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/metric_frame/MetricFrameTsUnit.h"

#include <cmath>
#include <stdexcept>

namespace facebook::dynolog {

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
};

std::optional<TimePoint> MetricFrameTsUnitFixInterval::lastSampleTime() const {
  if (sampleCount_ == 0) {
    return std::nullopt;
  }
  return lastSampleTime_;
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
