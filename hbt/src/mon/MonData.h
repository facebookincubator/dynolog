// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"

#ifdef HBT_ENABLE_TRACING
#include "hbt/src/phase/PerCpuMetaDataConsumer.h"
#include "hbt/src/tagstack/IntervalSlicer.h"
#include "hbt/src/tagstack/Slicer.h"
#endif // HBT_ENABLE_TRACING

#include <fmt/core.h>
#include <fmt/ostream.h>
#include <pfs/parser_error.hpp>
#include <pfs/procfs.hpp>

#include <algorithm>
#include <chrono>
#include <deque>
#include <filesystem>
#include <unordered_set>

namespace facebook::hbt::mon {

#ifdef HBT_ENABLE_TRACING
struct SliceFreq {
  // Total duration
  TimeStamp duration = 0;
  // Total number of times slice appears.
  size_t num_obs = 0;
  // Number of distinct interval that slice appears.
  size_t num_intervals = 0;

  bool seen() const {
    if (num_obs > 0) {
      HBT_DCHECK_GT(num_intervals, 0);
    }
    return num_obs > 0;
  }

  void accum(const SliceFreq& other) {
    duration += other.duration;
    num_obs += other.num_obs;
    num_intervals += other.num_intervals;
  }
};

inline std::ostream& operator<<(std::ostream& os, const SliceFreq& freq) {
  os << "<SliceFreq"
     << " duration: " << tstampToStr(freq.duration)
     << " num_obs: " << freq.num_obs << " num_intervals: " << freq.num_intervals
     << ">\n";
  return os;
}

/// Per TagStackId frequencies.
using Freqs = std::unordered_map<tagstack::slice::TagStackId, SliceFreq>;

using PerCuFreqs =
    std::unordered_map<tagstack::CompUnitId, std::optional<Freqs>>;

/// A bin is a grouping of multiple slices for analysis purposes.
using BinId = uint32_t;

struct CountData {
  const std::vector<std::string> event_names;
  // Stride in number of elements.
  const size_t kRowStride;

  explicit CountData(const std::vector<std::string>& event_names)
      : event_names{event_names}, kRowStride{(event_names.size() + 2)} {}

  auto numEvents() const noexcept {
    return event_names.size();
  }

  void write(const uint64_t* d) {
    HBT_DCHECK_EQ(data.size() % kRowStride, 0);
    data.insert(data.end(), d, d + (2 + numEvents()));
    HBT_DCHECK_EQ(data.size() % kRowStride, 0);
  }

  size_t numIntervals() const {
    HBT_DCHECK_EQ(data.size() % kRowStride, 0)
        << "data size of: " << data.size() << " not a multiple of "
        << kRowStride;
    return data.size() / kRowStride;
  }

  std::optional<TimeStampRange> getTimeStampRange() const {
    HBT_THROW_ASSERT_IF(data.size() % kRowStride != 0);
    if (data.size() == 0) {
      return std::nullopt;
    }
    // index of last tstamp, duration is at next position.
    auto end_start_idx = data.size() - (2 + numEvents());
    return TimeStampRange{
        data[0], data[end_start_idx] + data[end_start_idx + 1]};
  }

  std::unique_ptr<CountData> filter(const std::vector<bool>& sel) {
    auto new_cd = std::make_unique<CountData>(event_names);
    for (size_t r = 0, i = 0; r < data.size(); r += kRowStride, ++i) {
      if (sel[i]) {
        new_cd->write(&data[r]);
      }
    }
    return new_cd;
  }

  std::optional<size_t> findCountAt(TimeStamp tstamp) const {
    for (size_t r = 0, i = 0; r < data.size(); r += kRowStride, ++i) {
      auto start_tstamp = data[r];
      auto end_tstamp = start_tstamp + data[r + 1];
      if (start_tstamp <= tstamp && end_tstamp > tstamp) {
        return i;
      }
    }
    return std::nullopt;
  }

  // Use deque instead of vector because in modern implementations
  // it outperforms std::vector::push_back (when size is not reserved).
  // Appending data at the end is the most common and critical operation:
  // https://baptiste-wicht.com/posts/2017/05/cpp-containers-benchmark-vector-list-deque-plf-colony.html
  std::deque<uint64_t> data;
};

inline std::ostream& operator<<(std::ostream& os, const CountData& cd) {
  os << "<CountData num_events: " << cd.numEvents()
     << " num_count_intervals: " << cd.numIntervals() << "\n";

  for (size_t r = 0; r < cd.data.size(); r += cd.kRowStride) {
    os << "[" << tstampToStr(cd.data[r]) << ", "
       << tstampToStr(cd.data[r] + cd.data[r + 1]) << ") ";

    for (unsigned e = 0; e < cd.numEvents(); ++e) {
      os << cd.data[r + 2 + e] << " ";
    }
    os << "]\n";
  }
  os << "</CountData>";
  return os;
}

/// Convenience class to group slices and sample counts of one Compute Unit.
struct CuMonData {
  std::shared_ptr<CountData> count_data;
  std::shared_ptr<tagstack::PerIntervalSlices> per_interval_slices;

  CuMonData(
      std::shared_ptr<CountData> count_data,
      std::shared_ptr<tagstack::PerIntervalSlices> per_interval_slices)
      : count_data{std::move(count_data)},
        per_interval_slices{std::move(per_interval_slices)} {
    if (count_data && per_interval_slices) {
      HBT_ARG_CHECK_EQ(*numCountIntervals(), *numSliceIntervals());
    }
  }

  std::optional<size_t> numCountIntervals() const {
    if (!count_data) {
      return std::nullopt;
    }
    return count_data->numIntervals();
  }

  // Number of slice interval. It is equal to number
  // of count intervals when both are present.
  std::optional<size_t> numSliceIntervals() const {
    if (!per_interval_slices) {
      return std::nullopt;
    }
    return per_interval_slices->size();
  }

  /// Number of all slices in all count intervals.
  std::optional<size_t> countSlices() const {
    if (!per_interval_slices) {
      return std::nullopt;
    }
    return per_interval_slices->countSlices();
  }

  /// If there are any counts, return timestamp range for counts.
  /// If not, return range for slices.
  std::optional<TimeStampRange> getTimeStampRange() const {
    auto r = getCountDataTimeStampRange();
    if (!r.has_value()) {
      return getPerIntervalSlicesTimeStampRange();
    }
    return r;
  }

  std::optional<TimeStampRange> getCountDataTimeStampRange() const {
    if (!count_data) {
      return std::nullopt;
    }
    return count_data->getTimeStampRange();
  }

  std::optional<TimeStampRange> getPerIntervalSlicesTimeStampRange() const {
    if (!per_interval_slices) {
      return std::nullopt;
    }
    return per_interval_slices->getTimeStampRange();
  }

  std::optional<size_t> findCountAt(TimeStamp tstamp) const {
    if (!count_data) {
      return std::nullopt;
    }
    return count_data->findCountAt(tstamp);
  }

  std::optional<size_t> findSliceIntervalAt(TimeStamp tstamp) const {
    if (!per_interval_slices) {
      return std::nullopt;
    }
    const auto& pi_slices = *per_interval_slices;
    auto it_begin = pi_slices.cbegin();
    for (; it_begin != pi_slices.cend(); ++it_begin) {
      if (it_begin->size() > 0) {
        const auto& slices = *it_begin;
        if (slices.front().tstamp > tstamp ||
            slices.back().tstampEnd() <= tstamp) {
          continue;
        }
        auto d = it_begin - pi_slices.cbegin();
        HBT_THROW_ASSERT_IF(d < 0);
        return static_cast<size_t>(d);
      }
    }
    return std::nullopt;
  }

  /// Count how many times each slice appears in num_obs,
  /// the total duraton and in how many distinct count intervals.
  std::optional<Freqs> stackIdFreqs() const {
    if (!per_interval_slices) {
      return std::nullopt;
    }
    Freqs freqs;
    std::set<tagstack::slice::TagStackId> seen;
    const auto& pi_slices = *per_interval_slices;
    for (const auto& slices : pi_slices) {
      seen.clear();
      for (const auto& s : slices) {
        auto& freq = freqs[s.stack_id];
        ++freq.num_obs;
        freq.duration += s.duration;
        if (!seen.count(s.stack_id)) {
          ++freq.num_intervals;
          seen.insert(s.stack_id);
        }
      }
    }
    return freqs;
  }
};

inline std::ostream& operator<<(std::ostream& os, const CuMonData& cu_d) {
  os << "<CuMonData\n";
  if (cu_d.count_data) {
    os << "count_data: " << *cu_d.numCountIntervals() << " count intervals\n";
  } else {
    os << "count_data: None\n";
  }
  if (!cu_d.per_interval_slices) {
    os << "per_interval_slices: None\n";
  } else {
    os << "per_interval_slices: " << *cu_d.numSliceIntervals()
       << " slice intervals\n";
  }
  os << "</CuMonData>\n";
  return os;
}

/// Convenience class to group slices and sample counts of one
/// count interval source together for multiple compute units
/// (e.g. all the IPC count and slices for CPUs).
///
/// If <partition_source_key> is associated with a SampleCountGenerator,
/// then tagstack's <per_interval_slices> has one Slices per row in
/// <count_data>. Otherwise, tagstack's per_interval_slices is a list with an
/// arbitrary number of Slices objects.
struct MonData {
  std::string short_desc;
  std::string long_desc;

  TimeStampNsConverter ts_converter;

  std::string partition_source_key;

  using PerCuMonData =
      std::unordered_map<tagstack::CompUnitId, std::shared_ptr<CuMonData>>;

  PerCuMonData per_cu_mon_data;

  std::shared_ptr<phase::MetaDataContainer> metadata;

  MonData(
      const std::string& short_desc,
      const std::string& long_desc,
      TimeStampNsConverter ts_converter,
      const std::string& partition_source_key,
      PerCuMonData&& per_cu_mon_data,
      std::shared_ptr<phase::MetaDataContainer> metadata)
      : short_desc{short_desc},
        long_desc{long_desc},
        ts_converter{ts_converter},
        partition_source_key{partition_source_key},
        per_cu_mon_data{std::move(per_cu_mon_data)},
        metadata{metadata} {
    HBT_ARG_CHECK_GT(partition_source_key.size(), 0);
  }

  /// Number of all slices in all count intervals.
  auto countSlices(std::optional<CpuSet> cpu_set) const {
    auto count_fun = [cpu_set](size_t cumm, const auto& cu_kv) -> size_t {
      if (cpu_set.has_value() && !cpu_set->hasCpu(cu_kv.first)) {
        return cumm;
      }
      return cumm + cu_kv.second->countSlices().value_or(0);
    };
    return std::accumulate(
        per_cu_mon_data.cbegin(), per_cu_mon_data.cend(), 0u, count_fun);
  }

  size_t numCountIntervals(std::optional<CpuSet> cpu_set) const {
    size_t n = 0;
    for (const auto& [k, cu_md] : per_cu_mon_data) {
      if (!cpu_set.has_value() || cpu_set->hasCpu(k)) {
        auto new_n = cu_md->numCountIntervals();
        if (new_n.has_value()) {
          n += *new_n;
        }
      }
    }
    return n;
  }

  /// If there are any counts, return timestamp range for counts.
  /// If not, return range for slices.
  std::optional<TimeStampRange> getTimeStampRange(
      std::optional<CpuSet> cpu_set) const {
    TimeStamp start = std::numeric_limits<TimeStamp>::max();
    TimeStamp end = std::numeric_limits<TimeStamp>::min();

    for (const auto& [k, cu_md] : per_cu_mon_data) {
      if (cpu_set.has_value() && !cpu_set->hasCpu(k)) {
        continue;
      }
      auto r = cu_md->getTimeStampRange();
      if (!r.has_value()) {
        continue;
      }
      if (r->first < start) {
        start = r->first;
      }
      if (r->second > end) {
        end = r->second;
      }
    }
    if (start <= end) {
      return TimeStampRange{start, end};
    }
    return std::nullopt;
  }

  // Obtain statistics for each TagStackId
  PerCuFreqs perCuStackIdFreqs() const {
    PerCuFreqs per_cu_freqs;

    for (const auto& [cu_id, md] : per_cu_mon_data) {
      per_cu_freqs[cu_id] = md->stackIdFreqs();
    }
    return per_cu_freqs;
  }

  // Obtain combined statistics of all TagStackIds.
  Freqs stackIdFreqs(std::optional<CpuSet> cpu_set) const {
    Freqs freqs;
    for (const auto& [k, cu_md] : per_cu_mon_data) {
      if (cpu_set.has_value() && !cpu_set->hasCpu(k)) {
        continue;
      }

      auto fs = cu_md->stackIdFreqs();
      if (!fs.has_value()) {
        continue;
      }
      for (const auto& [sid, f] : *fs) {
        freqs[sid].accum(f);
      }
    }
    return freqs;
  }
};

inline std::ostream& operator<<(std::ostream& os, const MonData& d) {
  os << "<MonData partition_source_key: \"" << d.partition_source_key << "\">";
  for (const auto& [k, cu_d] : d.per_cu_mon_data) {
    os << "\nCompUnitId: " << k << "\n";
    os << *cu_d;
  }
  if (d.metadata) {
    os << "metadata: \n" << *d.metadata << "\n";
  } else {
    os << "metadata: None\n";
  }
  os << "</MonData>";
  return os;
}

namespace binmap {

/// Rows are count intervals, columns are BinIds.
// XXX: Explore if it's better to replace by ATen, XTensor or another
// specialized library.
template <class T>
class IntervalBinMatrix {
 public:
  const unsigned kNumIntervals;
  const unsigned kNumBids;

  // Initialize all entries in <data> to zero.
  IntervalBinMatrix(unsigned num_intervals, unsigned num_bins)
      : kNumIntervals{num_intervals},
        kNumBids{num_bins},
        data_(kNumIntervals * kNumBids, 0) {
    HBT_THROW_ASSERT_IF(data_.size() != kNumIntervals * kNumBids);
  }

  T get(unsigned i, unsigned j) const {
    return data_[i * kNumBids + j];
  }

  T& get(unsigned i, unsigned j) {
    return data_[i * kNumBids + j];
  }

  void set(unsigned i, unsigned j, T v) {
    data_[i * kNumBids + j] = v;
  }

  void inc(unsigned i, unsigned j, T v) {
    data_[i * kNumBids + j] += v;
  }

  auto getSize() const {
    return data_.size();
  }

  const uint64_t* getDataPtr() const {
    return data_.data();
  }

 protected:
  std::vector<uint64_t> data_;
};

/// Map stacks, identified by BinKeys, to BinIds.
/// Binning maps slices to BinIds.
/// BinIds are dense identifiers used to construct a dense matrix.
/// (it can be a TagStackId, or having a substring in comm's name).
/// BinIds is a dense index, one for each distinct of BinKey.
/// This is done to have a space efficient and fast way to refer to each Bin.
template <class TBinKey>
struct BinMapper {
  /// Map BinKeys to BinIds.
  std::unordered_map<TBinKey, BinId> binkey_to_bid;

  /// Reverse map, dense. Position is BinId.
  std::unordered_multimap<BinId, TBinKey> bid_to_binkey;

  BinId nextBinId = 0;

  auto reserveBinId() {
    return nextBinId++;
  }

  // BinIds are sequential from zero to numBinIds - 1.
  size_t numBinIds() const {
    return nextBinId;
  }

  auto allBinKeys() const {
    std::vector<TBinKey> out;
    std::transform(
        binkey_to_bid.cbegin(),
        binkey_to_bid.cend(),
        std::back_inserter(out),
        [](auto p) { return p.first; });
    return out;
  }

  /// Mark <binkey> as used (if previously unused)
  /// and update maps. Return a dense BinId.
  BinId markBinKey(const TBinKey& binkey, std::optional<BinId> bid_opt) {
    if (auto it = binkey_to_bid.find(binkey); it != binkey_to_bid.end()) {
      if (bid_opt.has_value()) {
        HBT_ARG_CHECK_EQ(it->second, *bid_opt)
            << "Binkey already assigned to another bin ID";
      }
      return it->second;
    }
    BinId bid;
    if (bid_opt.has_value()) {
      bid = *bid_opt;
    } else {
      bid = reserveBinId();
    }
    auto [_bid_it, bid_inserted] = binkey_to_bid.emplace(binkey, bid);
    if (bid_inserted) {
      bid_to_binkey.emplace(bid, binkey);
    }
    return bid;
  }
};

/// Maps each TagStackId to a different BinId if fills the given conditions.
/// Otherwise bucket in an ignored sids bucket.
struct TagStackIdBinner {
  using TagStackId = tagstack::slice::TagStackId;
  using TBinMapper = BinMapper<TagStackId>;
  using TDurations = IntervalBinMatrix<uint64_t>;

  TBinMapper bin_mapper;
  // One row per count interval, columns are BinIds.
  std::unique_ptr<TDurations> durations;
  BinId ignored_bid;

  /// Ignore sids that appear in less than <min_distinct_intervals>.
  TagStackIdBinner(
      const MonData& md,
      std::optional<CpuSet> cpu_set,
      size_t min_distinct_intervals,
      TimeStamp min_duration) {
    ignored_bid = bin_mapper.reserveBinId();
    auto freqs = md.stackIdFreqs(cpu_set);

    // Initialize bin_mapper by passing it all stack_ids.
    for (const auto& [sid, freq] : freqs) {
      if (freq.num_intervals >= min_distinct_intervals &&
          freq.duration >= min_duration) {
        // Calling markBinKey will populate the maps inside binner.
        this->bin_mapper.markBinKey(sid, std::nullopt);
      } else {
        this->bin_mapper.markBinKey(sid, ignored_bid);
      }
    }

    // One row per Count interval (each one is one observation).
    const auto num_rows = md.numCountIntervals(cpu_set);
    // One column per BinId
    const auto num_cols = this->bin_mapper.numBinIds();

    this->durations = std::make_unique<TDurations>(num_rows, num_cols);

    int num_skipped = 0;
    for (const auto& [cu_id, d] : md.per_cu_mon_data) {
      if (cpu_set.has_value() && !cpu_set->hasCpu(cu_id)) {
        continue;
      }
      if (!d->per_interval_slices) {
        continue;
      }
      unsigned i = 0;
      for (const auto& slices : *d->per_interval_slices) {
        HBT_DCHECK_LT(i, num_rows);
        if (slices.size() == 0) {
          continue;
        }
        uint64_t row_dur = 0;
        for (const auto& s : slices) {
          /// The mapping between slices and BinKeys is simply TagStackId.
          auto bin_key = s.stack_id;
          BinId bid = bin_mapper.binkey_to_bid.at(bin_key);
          HBT_DCHECK_LT(bid, num_cols)
              << "Bin index is out of bounds for bin_key: " << bin_key;
          if (s.duration == 0) {
            HBT_LOG_WARNING() << fmt::format(
                "Zero duration for stack_id: {}, bid: {}, row: {}, slice: {}",
                bin_key,
                bid,
                i,
                s);
            continue;
          }
          row_dur += s.duration;
          this->durations->inc(i, bid, s.duration);
        }
        if (row_dur) {
          // Skip rows with zero durations.
          ++i;
        } else {
          ++num_skipped;
        }
      }
    }
    HBT_LOG_WARNING_IF(num_skipped > 0)
        << fmt::format("Skipped {} rows due to zero duration.", num_skipped);
  }

  /// Returns a range (a pair with first and last elements) that
  /// batch the given bid.
  auto bidToSids(BinId bid) const {
    return bin_mapper.bid_to_binkey.equal_range(bid);
  }

  auto bidToSidsVector(BinId bid) const {
    auto [start_it, end_it] = bidToSids(bid);
    std::vector<TagStackId> out;
    std::transform(start_it, end_it, std::back_inserter(out), [](auto p) {
      return p.second;
    });
    return out;
  }

  auto ignoredSidsVector() const {
    return bidToSidsVector(ignored_bid);
  }

  auto allSids() const {
    bin_mapper.allBinKeys();
  }

  BinId sidToBid(TagStackId sid) const {
    return this->bin_mapper.binkey_to_bid.at(sid);
  }
};

} // namespace binmap
#endif // HBT_ENABLE_TRACING

struct ModuleInfo {
  ModuleInfo(const std::string& systemPath, size_t loadAddress)
      : systemPath{systemPath}, loadAddress{loadAddress} {}

  // The original path of the module at runtime.
  std::string systemPath;

  // Load address of the module.
  size_t loadAddress;

  bool operator==(const ModuleInfo& m) const {
    return std::tie(systemPath, loadAddress) ==
        std::tie(m.systemPath, m.loadAddress);
  }
};

namespace detail {
// Helper method to extract only the executable, file backed modules from all of
// a process' memory mappings.
//
// This method can easily be optimized in the future if it's determined that
// this filtering is a bottleneck. For now we take simple, readable approach to
// filtering.
std::vector<ModuleInfo> getFileBackedExecutableModules(
    const std::filesystem::path& root_path,
    std::vector<pfs::mem_region>& mem_regions);
} // namespace detail

} // namespace facebook::hbt::mon
