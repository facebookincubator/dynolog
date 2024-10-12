// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <optional>
#include <vector>

namespace facebook::dynolog {

/* MetricValues:
 *  An list of metric values that can be aggregated in various ways.
 *  MetricValues is similar to MetricSeries except it helps to track
 *  and aggregate values across space rather than time.
 *  For example, aggregate cpu time across cpu cores.
 */
template <typename T>
class MetricValues final {
 public:
  explicit MetricValues(size_t size = 0) : data_{std::vector<T>(size)} {}

  explicit MetricValues(std::vector<T>&& values) : data_{std::move(values)} {}

  size_t size() const {
    return data_.size();
  }

  void push_back(T val) {
    data_.push_back(val);
  }

  const T& at(size_t idx) {
    return data_.at(idx);
  }

  const T& operator[](const size_t idx) const {
    return *(begin() + idx);
  }

  void reserve(const size_t size) {
    data_.reserve(size);
  }

  void resize(const size_t size) {
    data_.resize(size);
  }

  T sum() const {
    return std::accumulate(begin(), end(), T{0});
  }

  std::optional<float> avg() const {
    if (size() == 0) {
      return std::nullopt;
    }
    return static_cast<float>(sum()) / size();
  }

  std::optional<T> percentile(float percentage) const {
    if (size() == 0) {
      return std::nullopt;
    }
    std::vector<T> dataCopy(begin(), end());
    auto nthIdx = lround(percentage * (dataCopy.size() - 1));
    std::nth_element(
        dataCopy.begin(), dataCopy.begin() + nthIdx, dataCopy.end());
    return dataCopy[nthIdx];
  }

  std::optional<std::pair<T, T>> minmax() const {
    if (size() == 0) {
      return std::nullopt;
    }
    const auto [min_it, max_it] = std::minmax_element(begin(), end());
    return std::make_pair(*min_it, *max_it);
  }

  void merge(const MetricValues<T>& other) {
    data_.reserve(data_.size() + other.data_.size());
    data_.insert(data_.end(), other.data_.begin(), other.data_.end());
  }

 private:
  auto begin() const {
    return data_.begin();
  }

  auto end() const {
    return data_.end();
  }

  std::vector<T> data_;
};

} // namespace facebook::dynolog
