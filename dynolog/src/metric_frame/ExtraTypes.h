// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <ostream>

namespace facebook::dynolog {

struct PerfReadValues {
  uint64_t timeEnabled = 0;
  uint64_t timeRunning = 0;
  uint64_t count = 0;

  std::string toString() const {
    return std::string("<PerfReadValue timeEnabled=") +
        std::to_string(timeEnabled) +
        " timeRunning=" + std::to_string(timeRunning) +
        " count=" + std::to_string(count) + ">";
  }

  PerfReadValues operator-(const PerfReadValues& other) const {
    if (other.timeRunning > timeRunning || other.timeEnabled > timeEnabled ||
        other.count > count) {
      throw std::underflow_error(
          std::string("lhs value ") + toString() +
          " is smaller than rhs value " + other.toString());
    }
    PerfReadValues res;
    res.timeEnabled = timeEnabled - other.timeEnabled;
    res.timeRunning = timeRunning - other.timeRunning;
    res.count = count - other.count;
    return res;
  }

  template <typename R>
  R getCount() const {
    if (timeRunning == 0) {
      return static_cast<R>(0);
    }
    return static_cast<R>(
        static_cast<double>(count) * static_cast<double>(timeEnabled) /
        static_cast<double>(timeRunning));
  }

  // override type cast to double operator here.
  // when cast PerfReadValues to double, it will calculate a single double value
  // based on timeEnabled and timeRunning.
  operator double() const {
    return getCount<double>();
  }
};

std::ostream& operator<<(
    std::ostream& os,
    const PerfReadValues& perfReadValues);

} // namespace facebook::dynolog
