// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/tagstack/IntervalSlicer.h"

namespace facebook::hbt::tagstack {

std::ostream& operator<<(std::ostream& os, const PerIntervalSlices& pis) {
  os << "<PerIntervalSlices num_intervals: " << pis.numIntervals()
     << " num_slices: " << pis.countSlices() << " tstamp_range: ";
  auto r = pis.getTimeStampRange();
  if (r.has_value()) {
    os << *r << " ";
  } else {
    os << "<NA> ";
  }
  os << ">\n";

  for (const auto& ss : pis) {
    if (ss.size() > 0) {
      os << "[";
      for (const auto& s : ss) {
        os << s << " ";
      }
      os << "]\n";
    } else {
      os << "<NA>\n";
    }
  }
  os << "</PerIntervalSlices>\n";
  return os;
}

template <class TConsumer>
const slice::Slice* nextSlice(TConsumer& cons) {
  auto [ret, p] = cons.readInTx(sizeof(slice::Slice));
  if (ret == -ENODATA) {
    return nullptr;
  }
  HBT_THROW_ASSERT_IF(0 > ret);
  return static_cast<const slice::Slice*>(p);
}

/// Returns a set of slices that cover the time interval [tstamp, tstamp +
/// duration). If <trim>, slices that cross the interval boundaries will be
/// trimmed and have <Slice::TransitionType::Analysis> in the transition type.
/// If <abort_on_missing_slices> if available slices don't fully cover the
/// interval, then the attemp will be aborted and no slices will be
/// tried to be
std::pair<std::unique_ptr<slice::Slices>, size_t>
IntervalSlicer::makeIntervalIntersectingSlices(
    size_t num_slices_offset,
    TimeStamp tstamp,
    TimeStamp duration,
    bool trim,
    bool abort_on_missing_slices) {
  std::lock_guard<std::mutex> lock{slices_cons_mutex_};

  const TimeStamp tstamp_end = tstamp + duration;

  HBT_ARG_CHECK_GT(duration, 0);

  {
    auto ret = slices_cons_->startTx();
    HBT_THROW_ASSERT_IF(0 > ret) << toErrorCode(-ret).message();
    // Skip first <num_slices_offset> slices that have been already consumed.
    ret = slices_cons_->seekInTx(num_slices_offset * sizeof(slice::Slice));
    HBT_THROW_ASSERT_IF(0 > ret) << toErrorCode(-ret).message();
  }

  size_t num_consumed = 0;
  auto s = nextSlice(*slices_cons_);

  // Move until the first slice that ends after count has started.
  while (s && s->tstampEnd() < tstamp) {
    HBT_THROW_ASSERT_IF(s->duration == 0)
        << "Slices of zero duration are invalid";
    s = nextSlice(*slices_cons_);
    ++num_consumed;
  }

  // Not enough slices to cover count interval, abort.
  if (!s) {
    auto ret = slices_cons_->cancelTx();
    HBT_THROW_ASSERT_IF(0 > ret);
    return {nullptr, 0};
  }

  if (abort_on_missing_slices && s->tstamp > tstamp) {
    auto ret = slices_cons_->cancelTx();
    HBT_THROW_ASSERT_IF(0 > ret);
    return {nullptr, 0};
  }

  // Prepare for start
  TimeStamp slices_duration = 0;
  TimeStamp last_end = s->tstamp;
  auto partitioned_slices = std::make_unique<slice::Slices>();

  // Add slices until last one or end of time interval.
  while (s && s->tstamp < tstamp_end) {
    HBT_DCHECK_GT(s->duration, 0) << "Slices of zero duration are invalid";
    // Check if there is a hole in the time interval coverage.
    if (abort_on_missing_slices && last_end != s->tstamp) {
      auto ret = slices_cons_->cancelTx();
      HBT_THROW_ASSERT_IF(0 > ret);
      return {nullptr, 0};
    }

    // Without trimming there is no way to a slice within the desired interval.
    if (!trim && s->tstampEnd() > tstamp_end) {
      break;
    }

    // We have an intersection, create a slice to represent it, trim it later.
    slices_duration += s->duration;
    partitioned_slices->push_back(*s);
    last_end = s->tstampEnd();
    s = nextSlice(*slices_cons_);
    ++num_consumed;
  }

  if (s) {
    HBT_DCHECK_GE(s->tstamp, tstamp_end);
  }

  if (partitioned_slices->empty()) {
    HBT_DCHECK(!trim);
    auto ret = slices_cons_->cancelTx();
    HBT_THROW_ASSERT_IF(0 > ret);
    return {nullptr, 0};
  }

  // Check if coverage is complete (if required).
  auto& last_slice = partitioned_slices->back();
  TimeStamp last_slice_end = last_slice.tstampEnd();
  // Not enough slices to cover count interval, abort.
  if (abort_on_missing_slices && last_slice_end < tstamp_end) {
    auto ret = slices_cons_->cancelTx();
    HBT_THROW_ASSERT_IF(0 > ret);
    return {nullptr, 0};
  }

  // Trim first slice if needed.
  if (trim) {
    // Trim the start of the slice's copy that we store in
    // <partitioned_slices> to match count's start.
    auto& f = partitioned_slices->front();
    if (f.tstamp < tstamp) {
      TimeStamp overlap = f.tstampEnd() - tstamp;
      HBT_DCHECK_LT(overlap, f.duration);
      const auto diff = f.duration - overlap;
      f.duration = overlap;
      f.tstamp = tstamp;
      f.swin_type = tagstack::slice::Slice::TransitionType::Analysis;
      slices_duration -= diff;
    }
  }

  if (last_slice_end > tstamp_end) {
    // Last slice crosses boundary, so do not consume it.
    --num_consumed;
  }

  // Handle last slice, it may go beyond the count interval.
  if (trim && last_slice_end > tstamp_end) {
    TimeStamp delta = static_cast<TimeStamp>(last_slice_end - tstamp_end);
    HBT_DCHECK_GE(last_slice.duration, delta);
    last_slice.duration -= delta;
    last_slice.swout_type = tagstack::slice::Slice::TransitionType::Analysis;
    slices_duration -= delta;
  }

  HBT_THROW_ASSERT_IF(slices_duration > duration)
      << "trim: " << trim
      << " abort_on_missing_slices: " << abort_on_missing_slices;
  if (trim && abort_on_missing_slices) {
    HBT_THROW_ASSERT_IF(slices_duration != duration)
        << "Incosistent durations. \n"
        << "slices_duration: " << tstampToStr(slices_duration)
        << " interval_duration:" << tstampToStr(duration);
  }
  auto ret = slices_cons_->cancelTx();
  HBT_THROW_ASSERT_IF(0 > ret);
  return {std::move(partitioned_slices), num_consumed};
}

// Moves through a buffer ouf uint64_t with <elem_byte_size> bytes per element
// and with first two members of each element being timestamp and duration.
// Set <trim> to modify slices that cross an interval.
// Set <abort_on_missing_slices> to roll-back if not enough slices to cover an
// interval.
std::unique_ptr<PerIntervalSlices> IntervalSlicer::consumeSlices(
    const std::string& key,
    uint64_t tstamp,
    uint64_t duration,
    bool trim,
    bool abort_on_missing_slices) {
  auto per_sample_slices = std::make_unique<PerIntervalSlices>();

  auto& offset = getMark(key);

  auto [slices, num_consumed] = makeIntervalIntersectingSlices(
      offset, tstamp, duration, trim, abort_on_missing_slices);
  if (slices == nullptr) {
    // Not enough slices to cover interval, stop here.
    per_sample_slices->push_back({});
  } else {
    per_sample_slices->push_back(std::move(*slices));
  }
  offset += num_consumed;

  discardConsumed();
  return per_sample_slices;
}

std::ostream& IntervalSlicer::toStream(std::ostream& os) const {
  std::lock_guard<std::mutex> lock{slices_cons_mutex_};

  {
    auto ret = slices_cons_->startTx();
    HBT_THROW_ASSERT_IF(0 > ret);
  }
  std::ostringstream slices_ss;

  os << "slices [";

  int num_slices = 0;

  while (true) {
    auto [ret, p] = slices_cons_->readInTx(sizeof(slice::Slice));
    if (ret == -ENODATA) {
      break;
    }
    HBT_THROW_ASSERT_IF(0 > ret) << "Unexpected error: " << toErrorCode(-ret);
    auto s = static_cast<const slice::Slice*>(p);
    slices_ss << *s << " \n";
    ++num_slices;
  }
  return os << num_slices << "]\n" << slices_ss.str();
}

} // namespace facebook::hbt::tagstack
