// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/Defs.h"

#include <vector>

namespace facebook::hbt::utils::value_time_series {

template <class T>
struct Point {
  TimeStamp tstamp;
  T value;

  Point(TimeStamp tstamp, const T& value) : tstamp{tstamp}, value{value} {}

  Point(TimeStamp tstamp, T&& value) : tstamp{tstamp}, value{value} {}
};

template <class T>
bool operator<(const Point<T>& a, const Point<T>& b) {
  return a.tstamp < b.tstamp;
}

// XXX: Underlying vector is good for small series. Do we need a map instead?
template <class T>
class Series {
 public:
  using TPoint = Point<T>;
  using TPoints = std::vector<TPoint>;

  Series() {}

  // Constructor for serialized data.
  Series(TPoints&& ps) : points_(std::move(ps)) {}

  Series(TPoint&& p) : points_{std::move(p)} {}

  /// Insert value and sorts the series by timestamp, if needed.
  // XXX: This is hacky and simple. Optimized for small number of elements.
  // Check if something more complex is needing.
  void emplace(TimeStamp tstamp, T&& value) {
    bool need_sort = points_.size() > 0 && points_.back().tstamp > tstamp;
    points_.emplace_back(tstamp, value);
    if (need_sort) {
      std::sort(points_.begin(), points_.end());
    }
  }

  /// Last value at or before <tstamp>.
  const T* valueAt(TimeStamp tstamp) const {
    const T* p = nullptr;
    TimeStamp last_tstamp = std::numeric_limits<TimeStamp>::min();

    for (const auto& next_p : points_) {
      if (next_p.tstamp > tstamp)
        break;
      HBT_DCHECK_LE(last_tstamp, next_p.tstamp);
      p = &next_p.value;
      last_tstamp = next_p.tstamp;
    }
    return p;
  }

  const T* last() const {
    return valueAt(kMaxTimeStamp);
  }

  size_t size() const {
    return points_.size();
  }

  const auto& getPoints() const {
    return points_;
  }

 protected:
  TPoints points_;
};

template <class T>
inline std::ostream& operator<<(std::ostream& os, const Series<T>& s) {
  for (const auto& p : s.getPoints()) {
    os << "<tstamp:" << p.tstamp << " " << p.value;
  }
  return os;
}

} // namespace facebook::hbt::utils::value_time_series
