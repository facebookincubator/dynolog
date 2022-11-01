// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/tagstack/Slicer.h"

#include <deque>
#include <memory>
#include <mutex>
#include <numeric>

namespace facebook::hbt::tagstack {

class PerIntervalSlices : public std::deque<slice::Slices> {
 public:
  // Number of all slices in all count intervals.
  size_t countSlices() const {
    auto count_fun = [](size_t cumm, const auto& s) -> size_t {
      return cumm + s.size();
    };
    return std::accumulate(cbegin(), cend(), 0ull, count_fun);
  }

  size_t numIntervals() const {
    return size();
  }

  auto filter(const std::vector<std::vector<bool>>& sel) {
    HBT_ARG_CHECK_EQ(sel.size(), numIntervals())
        << "sel and this PerIntervalSlices have inconsistent number "
           "of slice intervals.";

    auto new_pis = std::make_unique<PerIntervalSlices>();
    for (size_t c = 0; c < sel.size(); ++c) {
      HBT_DCHECK_EQ(sel[c].size(), this->operator[](c).size());
      auto& sgroup = new_pis->emplace_back();
      for (size_t s = 0; s < sel[c].size(); ++s) {
        if (!sel[c][s]) {
          continue;
        }
        sgroup.push_back(this->operator[](c)[s]);
      }
    }
    return new_pis;
  }

  std::optional<TimeStampRange> getTimeStampRange() const {
    // Go from front to back, looking for front-most non-empty Slices.
    auto it_begin = cbegin();
    for (; it_begin != cend(); ++it_begin) {
      if (it_begin->size() > 0) {
        break;
      }
    }

    // Finish if there is no non-empty Slices.
    if (it_begin == end()) {
      return std::nullopt;
    }

    // Go from back to front, looking for back-most non-empty Slices.
    auto it_rbegin = crbegin();
    for (; it_rbegin != crend(); ++it_rbegin) {
      if (it_rbegin->size() > 0) {
        break;
      }
    }

    // Because at this point it was guaranteed that there is at least one slice,
    // then backwards iterators must have found that one or a later one.
    HBT_DCHECK(it_rbegin != rend());

    TimeStamp start = it_begin->front().tstamp;
    TimeStamp end = it_rbegin->back().tstamp + it_rbegin->back().duration;
    return TimeStampRange{start, end};
  }
};

std::ostream& operator<<(std::ostream&, const PerIntervalSlices&);

/// A handy container of slices.
/// Suitable for sequential consumption. Keeps tracks of what slices
/// are no longer needed and releases them on <resize>.
/// Can be used as SliceProducer in tagstack::Slicer.
///
/// It does not memory allocations. If <n_slices_drop_if_full> it will
/// drop slices when the internal ringbuffer is full. If it is std::nullopt,
/// it will drop slices.
class IntervalSlicer {
 public:
  struct RbExtraData {};

  // transient synchronization errors and ENOSPC.
  // A retry value of 2 is sane.
  static constexpr int kMaxNumRetries = 2;
  const size_t kBytesDropIfFull;

  IntervalSlicer(const IntervalSlicer&) = delete;

  IntervalSlicer(IntervalSlicer&&) = delete;

  IntervalSlicer(size_t min_num_slices, size_t num_slices_drop_if_full)
      : kBytesDropIfFull{num_slices_drop_if_full * sizeof(slice::Slice)} {
    HBT_ARG_CHECK_GT(min_num_slices, 0);
    slices_rb_ = std::make_shared<ringbuffer::RingBuffer<RbExtraData>>(
        min_num_slices * sizeof(slice::Slice));
    slices_cons_ =
        std::make_shared<ringbuffer::Consumer<RbExtraData>>(slices_rb_);
    slices_prod_ =
        std::make_shared<ringbuffer::Producer<RbExtraData>>(slices_rb_);
  }

  ssize_t write(const slice::Slice& slice) {
    HBT_ARG_CHECK_NE(slice.tstamp, kInvalidTimeStamp) << "Invalid timestamp";

    ssize_t ret = 0;
    // IntervalSlicer is only writer
    for (int i = 0; i < kMaxNumRetries; ++i) {
      ret = slices_prod_->write(slice);
      if (likely(0 < ret)) {
        break;
      }
      if (unlikely(kBytesDropIfFull > 0 && ret == -ENOSPC)) {
        auto err = slices_prod_->dropN(kBytesDropIfFull);
        HBT_DCHECK_GE(err, 0);
      }
    }
    HBT_LOG_ERROR_IF(0 > ret) << "Failed to write slice after retrying "
                              << kMaxNumRetries << " times. "
                              << "\"" << toErrorCode(-ret).message() << "\"";
    return ret;
  }

  auto getRingBuffer() {
    return slices_rb_;
  }

  /// Register a consumer of slices to track.
  /// It wll keep track of consumer's position to avoid
  /// releasing slices not yet consumed.
  void registerConsumerMark(const std::string& key) {
    HBT_ARG_CHECK(consumer_marks_.count(key) == 0)
        << "Consumer with key " << key << " already registered.";
    consumer_marks_[key] = num_processed_slices_;
  }

  void updateConsumerMark(const std::string& key, size_t new_offset) {
    auto it = consumer_marks_.find(key);
    HBT_ARG_CHECK(it != consumer_marks_.end())
        << "No consumer mark for key: \"" << key << "\"";
    it->second = new_offset;
  }

  void removeConsumerMark(const std::string& key_to_erase) {
    consumer_marks_.erase(key_to_erase);
  }

  size_t& getMark(const std::string& key) {
    auto it = consumer_marks_.find(key);
    HBT_ARG_CHECK(it != consumer_marks_.end())
        << "No consumer mark for key: \"" << key << "\"";
    return it->second;
  }

  auto numActiveSlices() const noexcept {
    auto s = slices_rb_->getHeader().usedSizeWeak();
    HBT_DCHECK_EQ(s % sizeof(slice::Slice), 0);
    return s / sizeof(slice::Slice);
  }

  size_t numProcessedSlices() const noexcept {
    return num_processed_slices_;
  }

  /// Resize by erasing all slices that have been consumed by all consumers.
  /// Must be called as consumer marks advance.
  void discardConsumed() {
    std::lock_guard<std::mutex> lock{slices_cons_mutex_};

    if (consumer_marks_.size() == 0) {
      return;
    }
    auto min_discarded = std::numeric_limits<size_t>::max();
    for (const auto& [k, mark] : consumer_marks_) {
      min_discarded = std::min(min_discarded, mark);
    }

    HBT_DCHECK_GE(min_discarded, num_processed_slices_);
    auto delta = static_cast<size_t>(min_discarded - num_processed_slices_);
    auto prev_num_active_slices = numActiveSlices();
    auto num_bytes_to_drop = delta * sizeof(slice::Slice);
    auto err = slices_cons_->dropN(num_bytes_to_drop);
    HBT_THROW_SYSTEM_CODE_IF(0 > err, toErrorCode(-err))
        << "Error dropping " << num_bytes_to_drop << " bytes";
    HBT_DCHECK_EQ(prev_num_active_slices - numActiveSlices(), delta)
        << "min_discarded: " << min_discarded
        << " num_processed_slices_: " << num_processed_slices_
        << " prev_num_active_slices: " << prev_num_active_slices
        << " num_bytes_to_drop: " << num_bytes_to_drop
        << " num bytes dropped: " << err;

    num_processed_slices_ = min_discarded;
  }

  /// Returns a set of slices that cover the time interval [tstamp, tstamp +
  /// duration). If <trim>, slices that cross the interval boundaries will be
  /// trimmed and have <Slice::TransitionType::Analysis> in the transition type.
  /// If <abort_on_missing_slices> if available slices don't fully cover the
  /// interval, then the attemp will be aborted and no slices will be
  /// tried to be released.
  std::pair<std::unique_ptr<slice::Slices>, size_t>
  makeIntervalIntersectingSlices(
      size_t offset,
      TimeStamp tstamp,
      TimeStamp duration,
      bool trim,
      bool abort_on_missing_slices);

  // Consume Slices for an interval.
  std::unique_ptr<PerIntervalSlices> consumeSlices(
      const std::string& key,
      uint64_t tstamp,
      uint64_t duration,
      bool trim,
      bool abort_on_missing_slices);

  std::ostream& toStream(std::ostream& os) const;

 protected:
  std::shared_ptr<ringbuffer::RingBuffer<RbExtraData>> slices_rb_;
  std::shared_ptr<ringbuffer::Producer<RbExtraData>> slices_prod_;
  std::shared_ptr<ringbuffer::Consumer<RbExtraData>> slices_cons_;

  // Protects slices_cons_ from multiple readers because
  // consumers may be concurrent with threads that read-only
  // explore the slices.
  mutable std::mutex slices_cons_mutex_;

  size_t num_processed_slices_ = 0;
  std::unordered_map<std::string, size_t> consumer_marks_;
};

inline std::ostream& operator<<(
    std::ostream& os,
    const IntervalSlicer& islicer) {
  return islicer.toStream(os);
}

} // namespace facebook::hbt::tagstack
