// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/mon/TraceMonitor.h"

namespace facebook::hbt::mon {

std::unique_ptr<CuMonData> TraceMonitor::releasePerIntervalSlicesOnly_(
    CpuId cpu_id,
    const std::string& key,
    TimeStamp stop_ts) {
  if (slice_gen_ctxt_ == nullptr) {
    // There is no tagstack data.
    return std::make_unique<CuMonData>(nullptr, nullptr);
  }
  // There are no counts, so get all available slices without any modification.
  auto pislices = slice_gen_ctxt_->getIntervalSlicer(cpu_id)->consumeSlices(
      key, 0, stop_ts, false, false);

  return std::make_unique<CuMonData>(nullptr, std::move(pislices));
}

std::unique_ptr<CuMonData> TraceMonitor::releaseCountData_(
    CountGenCtxt& ctxt,
    uint64_t* slices_offset,
    CpuId cpu_id,
    TimeStamp stop_ts) {
  auto& cgen = ctxt.count_gen->getCpuGenerator(cpu_id);
  const size_t kBytesWriteSize = cgen.kWriteByteSize;

  auto& cons = ctxt.count_gen_consumers.at(cpu_id);

  // Open transaction in consumer, it will be closed once buffer is empty.
  {
    auto ret = cons.startTx();
    HBT_THROW_ASSERT_IF(0 > ret)
        << "Could not start transaction in Consumer in cpu_id " << cpu_id;
  }

  auto cd = std::make_unique<CountData>(cgen.getEventNames());
  std::unique_ptr<tagstack::PerIntervalSlices> pislices;

  if (slices_offset != nullptr) {
    HBT_DCHECK(slice_gen_ctxt_ != nullptr);
    // Initialize pislices that will be used inside the while loop.
    pislices = std::make_unique<tagstack::PerIntervalSlices>();
  }

  // Iterate over counts.
  while (true) {
    const uint64_t* p = nullptr;
    if (auto [nread, d] = cons.readInTx(kBytesWriteSize); 0 > nread) {
      HBT_THROW_ASSERT_IF(nread != -ENODATA);
      // Stop at first error.
      break;
    } else {
      HBT_DCHECK_EQ(nread, kBytesWriteSize);
      p = reinterpret_cast<const uint64_t*>(d);
    }
    HBT_DCHECK(p != nullptr);
    TimeStamp tstamp = *p, duration = *(p + 1);
    if (tstamp + duration >= stop_ts) {
      // Count end passes stop_ts. Revert reading last count and wrap it up.
      auto err = cons.relSeekInTx(-static_cast<ssize_t>(kBytesWriteSize));
      HBT_THROW_ASSERT_IF(0 > err) << "Error reverting read.";
      HBT_LOG_INFO() << "releaseCountsData breaking: " << tstamp << " "
                     << duration;
      break;
    }

    if (pislices != nullptr) {
      HBT_THROW_ASSERT_IF(slices_offset == nullptr);

      // There are slices.
      auto islicer = slice_gen_ctxt_->getIntervalSlicer(cpu_id);
      auto [slices, num_consumed] = islicer->makeIntervalIntersectingSlices(
          *slices_offset, tstamp, duration, true, true);
      if (slices == nullptr) {
        // HBT_LOG_INFO() << "Not enough slices to cover count interval.";
        // Not enough slices to completely cover interval, stop here.
        pislices->push_back({});
      } else {
        pislices->push_back(std::move(*slices));
      }
      (*slices_offset) += num_consumed;
    }
    HBT_DCHECK(p != nullptr);
    cd->write(p);
  }
  auto err = cons.commitTx();
  HBT_THROW_ASSERT_IF(0 > err);

  if (slice_gen_ctxt_) {
    slice_gen_ctxt_->getIntervalSlicer(cpu_id)->discardConsumed();
    HBT_DCHECK_EQ(cd->numIntervals(), pislices->size());
  }
  return std::make_unique<CuMonData>(std::move(cd), std::move(pislices));
}

std::shared_ptr<MonData> TraceMonitor::releaseMonData(
    const std::string& key,
    std::optional<TimeStamp> stop_ts_opt,
    const std::string& short_desc,
    const std::string& long_desc) {
  std::lock_guard<std::mutex> counts_lock{counts_mutex_};

  MonData::PerCuMonData per_cu_mon_data;

  // If stop_ts not provided, process data until now.
  auto stop_ts = stop_ts_opt.value_or(now());

  auto it = interval_sources_.find(key);
  HBT_ARG_CHECK(it != interval_sources_.end())
      << "No slices output or count generator registered under key \"" << key
      << "\"";
  auto& interval_gen = it->second;

  for_each_cpu(cpu_id, getMonCpus()) {
    std::lock_guard<std::mutex> slices_lock{slices_mutex_};

    // Safe because CompUnitId is always <= kMaxCpus.
    auto cu_id = static_cast<tagstack::CompUnitId>(cpu_id);

    // The type of data that is released depends on
    // what has been enabled in the TraceMonitor.
    if (interval_gen == nullptr) {
      // No count generator.
      per_cu_mon_data[cu_id] =
          releasePerIntervalSlicesOnly_(cpu_id, key, stop_ts);
    } else {
      // We are here because there is a count generator.

      uint64_t* offset = nullptr;
      if (slice_gen_ctxt_) {
        offset = &slice_gen_ctxt_->getIntervalSlicer(cpu_id)->getMark(key);
      }
      assert(interval_gen != nullptr);
      per_cu_mon_data[cu_id] =
          releaseCountData_(*interval_gen, offset, cpu_id, stop_ts);
    }
  }

  // XXX: Do not clone the whole MetaData, just the parts that are needed.
  std::unique_ptr<phase::MetaDataContainer> metadata;
  if (slice_gen_ctxt_) {
    HBT_DCHECK(slice_gen_ctxt_->md_gen != nullptr);
    metadata = slice_gen_ctxt_->md_gen->getMetaDataContainer()->clone();
    HBT_THROW_ASSERT_IF(metadata == nullptr);
  }
  return std::make_shared<MonData>(
      short_desc,
      long_desc,
      buildTimeStampNsConverter(),
      key,
      std::move(per_cu_mon_data),
      std::move(metadata));
}

} // namespace facebook::hbt::mon
