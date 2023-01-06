// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iterator>
#include <numeric>
#include <optional>
#include <ratio>
#include <stdexcept>
#include <vector>

#include "dynolog/src/metric_frame/ExtraTypes.h"

namespace facebook::dynolog {

template <typename T>
class MetricSeries final {
 public:
  class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
   public:
    using difference_type = int;
    using value_type = T;

    Iterator(
        const std::vector<T>& data,
        size_t size,
        size_t headIdx,
        size_t headDis)
        : data_{&data}, size_{size}, headIdx_{headIdx}, headDis_{headDis} {}
    // see P2325R3
    // default constructor should not be required in the future
    Iterator() {}

    const value_type& operator*() const {
      return data_->at(dataIdx());
    }

    Iterator& operator++() {
      headDis_++;
      return *this;
    }

    Iterator operator++(int) {
      Iterator temp = *this;
      ++*this;
      return temp;
    }

    Iterator& operator--() {
      headDis_--;
      return *this;
    }

    Iterator operator--(int) {
      Iterator temp = *this;
      --*this;
      return temp;
    }

    bool operator==(const Iterator& rhs) const {
      return headDis_ == rhs.headDis_;
    }

    bool operator!=(const Iterator& rhs) const {
      return headDis_ != rhs.headDis_;
    }

    bool operator<(const Iterator& rhs) const {
      return headDis_ < rhs.headDis_;
    }

    bool operator<=(const Iterator& rhs) const {
      return headDis_ <= rhs.headDis_;
    }

    bool operator>(const Iterator& rhs) const {
      return headDis_ > rhs.headDis_;
    }

    bool operator>=(const Iterator& rhs) const {
      return headDis_ >= rhs.headDis_;
    }

    Iterator operator+(difference_type dis) const {
      Iterator temp = *this;
      temp.headDis_ += dis;
      return temp;
    }

    friend Iterator operator+(const difference_type lhs, const Iterator& rhs) {
      return rhs + lhs;
    }

    Iterator& operator+=(difference_type dis) {
      headDis_ += dis;
      return *this;
    }

    difference_type operator-(const Iterator& rhs) const {
      return headDis_ - rhs.headDis_;
    }

    Iterator operator-(difference_type dis) const {
      Iterator temp = *this;
      temp.headDis_ -= dis;
      return temp;
    }

    Iterator& operator-=(difference_type dis) {
      headDis_ += dis;
      return *this;
    }

    const value_type& operator[](const difference_type dis) const {
      return *(*this + dis);
    }

   private:
    const std::vector<T>* data_ = nullptr;
    size_t size_;
    // current tail index in data_
    size_t headIdx_;
    // distance to head
    size_t headDis_;

    size_t dataIdx() const {
      return (headIdx_ + headDis_) % size_;
    }
  };

  MetricSeries(size_t bufferLen, std::string name, std::string description)
      : data_{std::vector<T>(bufferLen)},
        name_{std::move(name)},
        description_{std::move(description)} {}

  const std::string& name() const {
    return name_;
  }

  const std::string& description() const {
    return description_;
  }

  void addSample(const T& sample) {
    if (size_ == data_.size()) {
      data_[tail_] = sample;
      tail_ = idxNext(tail_);
      head_ = idxNext(head_);
    } else {
      data_[tail_] = sample;
      tail_ = idxNext(tail_);
      size_++;
    }
  }

  const T& at(size_t idx) {
    return *(begin() + idx);
  }

  Iterator begin() const {
    return Iterator(data_, size_, head_, 0);
  }

  Iterator end() const {
    return Iterator(data_, size_, head_, size_);
  }

  size_t size() const {
    return size_;
  }

  size_t maxLength() {
    return data_.size();
  }

  T& operator[](const size_t idx) {
    return *(begin() + idx);
  }

  const T& operator[](const size_t idx) const {
    return *(begin() + idx);
  }

  template <typename R>
  R rate(
      std::chrono::steady_clock::duration period,
      std::chrono::steady_clock::duration duration,
      std::optional<Iterator> beginMaybe = std::nullopt,
      std::optional<Iterator> endMaybe = std::nullopt) const {
    auto begin_ = beginMaybe.value_or(begin());
    auto end_ = endMaybe.value_or(end());
    auto value = diff(beginMaybe, endMaybe);
    return rate<R>(value, period, duration);
  }

  template <typename R>
  R avg(
      std::optional<Iterator> beginMaybe = std::nullopt,
      std::optional<Iterator> endMaybe = std::nullopt) const {
    auto begin_ = beginMaybe.value_or(begin());
    auto end_ = endMaybe.value_or(end());
    return std::accumulate(begin_, end_, R{0}) / (end_ - begin_);
  }

  T percentile(
      float percentage,
      std::optional<Iterator> beginMaybe = std::nullopt,
      std::optional<Iterator> endMaybe = std::nullopt) const {
    auto begin_ = beginMaybe.value_or(begin());
    auto end_ = endMaybe.value_or(end());
    std::vector<T> dataCopy(begin_, end_);
    auto nthIdx = lround(percentage * (dataCopy.size() - 1));
    std::nth_element(
        dataCopy.begin(), dataCopy.begin() + nthIdx, dataCopy.end());
    return dataCopy[nthIdx];
  }

  T diff(
      std::optional<Iterator> beginMaybe = std::nullopt,
      std::optional<Iterator> endMaybe = std::nullopt) const {
    auto begin_ = beginMaybe.value_or(begin());
    auto end_ = endMaybe.value_or(end());
    return *(end_ - 1) - *begin_;
  }

 private:
  template <typename R>
  static R rate(
      const T& value,
      std::chrono::steady_clock::duration period,
      std::chrono::steady_clock::duration duration) {
    if constexpr (std::is_integral_v<R>) {
      if (period > duration) {
        return value * (period / duration);
      } else {
        return value / (duration / period);
      }
    } else {
      return static_cast<R>(value) *
          static_cast<double>(
                 std::chrono::duration_cast<std::chrono::microseconds>(period)
                     .count()) /
          std::chrono::duration_cast<std::chrono::microseconds>(duration)
              .count();
    }
  }
  int idxNext(int idx) const {
    return (idx + 1) % data_.size();
  }
  std::vector<T> data_;
  size_t head_ = 0;
  size_t tail_ = 0;
  size_t size_ = 0;
  const std::string name_;
  const std::string description_;
};

} // namespace facebook::dynolog
