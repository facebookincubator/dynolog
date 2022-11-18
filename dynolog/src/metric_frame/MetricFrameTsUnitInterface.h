// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <chrono>
#include <optional>

namespace facebook::dynolog {

using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;

enum class MATCH_POLICY {
  CLOSEST, // use the closest sample
  PREV_CLOSEST, // use the closest sample previous to provided timepoint
  NEXT_CLOSEST, // use the closest sample next to provided timepoint
};

struct MetricFrameOffset {
  size_t offset;
  TimePoint time;
};

struct MetricFrameRange {
  MetricFrameOffset start;
  MetricFrameOffset end;
};

class MetricFrameTsUnitInterface {
 public:
  virtual ~MetricFrameTsUnitInterface() = default;
  virtual void addSample(TimePoint time) = 0;
  virtual std::optional<TimePoint> firstSampleTime() const = 0;
  virtual std::optional<TimePoint> lastSampleTime() const = 0;
  virtual size_t length() const = 0;
  virtual size_t maxLength() const = 0;
  virtual std::optional<MetricFrameRange> getRange(
      TimePoint startTime,
      TimePoint endTime,
      MATCH_POLICY startTimePolicy = MATCH_POLICY::CLOSEST,
      MATCH_POLICY endTimePolicy = MATCH_POLICY::CLOSEST) const = 0;
};

} // namespace facebook::dynolog
