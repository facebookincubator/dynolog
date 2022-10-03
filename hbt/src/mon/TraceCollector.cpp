// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/mon/TraceCollector.h"
#include <fmt/core.h>
#include <fmt/ranges.h>

namespace facebook::hbt::mon {

TraceCollector::SliceGenCtxt::SliceGenCtxt(
    size_t perf_event_per_cpu_num_pages,
    std::unique_ptr<TPerCpuSliceGenerator> slice_gen,
    std::unique_ptr<phase::PerCpuMetaDataConsumer> md_gen)
    : perf_event_per_cpu_num_pages{perf_event_per_cpu_num_pages},
      slice_gen{std::move(slice_gen)},
      md_gen{std::move(md_gen)} {
  HBT_ARG_CHECK(this->slice_gen != nullptr);
  HBT_ARG_CHECK(this->md_gen != nullptr);
}

void TraceCollector::emplaceThreadGenerator(
    std::optional<ThreadSwitchGenParams> thread_gen_params) {
  HBT_ARG_CHECK(thread_gen_ctxt_ == nullptr)
      << "Thread Generator already registered";

  auto cpus = this->getMonCpus();

  auto params = thread_gen_params.value_or(kDefaultThreadGenParams);

  HBT_LOG_INFO() << "Context Switch Trace Size: "
                 << params.perf_event_per_cpu_num_pages * (size_t)getpagesize();

  thread_gen_ctxt_ = std::make_unique<ThreadSwitchGenCtxt>(
      params,
      std::make_shared<TPerCpuThreadGenerator>(
          cpus,
          nullptr,
          TraceCollector::kTidLevel,
          params.thread_switch_aux_rb_min_num_events));
};

void TraceCollector::emplaceTagStackGeneratorFromRbs(
    std::shared_ptr<TPhasesPerCpuRingBuffer> phases_per_cpu_rb,
    std::shared_ptr<TMetaDataPerCpuRingBuffer> metadata_per_cpu_rb,
    size_t min_num_slices,
    std::optional<ThreadSwitchGenParams> hint_thread_gen_params,
    size_t num_slices_drop_if_full) {
  std::lock_guard<std::mutex> slices_lock{slices_mutex_};
  std::lock_guard<std::mutex> counts_lock{counts_mutex_};

  HBT_ARG_CHECK(slice_gen_ctxt_ == nullptr)
      << "TagStack generator already registered";

  HBT_DCHECK(phases_per_cpu_rb != nullptr);
  HBT_DCHECK(metadata_per_cpu_rb != nullptr);

  auto cpus = this->getMonCpus();
  HBT_ARG_CHECK_EQ(phases_per_cpu_rb->getCpuSet(), cpus)
      << "Inconsistent CpuSet for Phases ringbuffers. ";
  HBT_ARG_CHECK_EQ(metadata_per_cpu_rb->getCpuSet(), cpus)
      << "Inconsistent CpuSet for MetaData per-CPU ringbuffers. ";

  if (thread_gen_ctxt_ == nullptr) {
    emplaceThreadGenerator(hint_thread_gen_params);
  }
  HBT_DCHECK(thread_gen_ctxt_ != nullptr);
  HBT_DCHECK(thread_gen_ctxt_->per_cpu_thread_gen != nullptr);

  // Allocate vector to hold one IntervalSlicer for each CPU,
  // but only initialize actively monitored CPUs.
  auto interval_slicer = std::make_unique<TGroupedSlices>(cpus.max_cpu_id + 1);
  for_each_cpu(cpu, cpus) {
    auto sp = std::make_shared<tagstack::IntervalSlicer>(
        min_num_slices, num_slices_drop_if_full);
    interval_slicer->at(cpu) = sp;
  }

  auto slice_gen =
      std::make_unique<PerCpuSliceGenerator<tagstack::IntervalSlicer>>(
          phases_per_cpu_rb,
          thread_gen_ctxt_->per_cpu_thread_gen,
          std::move(interval_slicer));

  auto tstamp_converter = [this](TimeStamp tsc_tstamp) -> TimeStamp {
    return this->slice_gen_ctxt_->slice_gen->tstampFromTsc(tsc_tstamp);
  };

  auto md_gen = std::make_unique<phase::PerCpuMetaDataConsumer>(
      metadata_per_cpu_rb, tstamp_converter);

  slice_gen_ctxt_ = std::make_unique<SliceGenCtxt>(
      thread_gen_ctxt_->params.perf_event_per_cpu_num_pages,
      std::move(slice_gen),
      std::move(md_gen));

  // Register all Interval generators that have been created as consumers.
  for (auto& [k, igen_ctxt] : interval_sources_) {
    for_each_cpu(cpu_id, getMonCpus()) {
      auto islicer = slice_gen_ctxt_->getIntervalSlicer(cpu_id);
      islicer->registerConsumerMark(k);
    }
  }

  // Transition newly emplaced PerCpuThreadSwitchGenerator to TraceCollector's
  // state.
  sync_();
}

/// Create a new output of unmodified slices (context switch slices no split
/// by counting intervals)..
void TraceCollector::emplaceSlicesOutput(const std::string& new_key) {
  std::lock_guard<std::mutex> slices_lock{slices_mutex_};
  std::lock_guard<std::mutex> counts_lock{counts_mutex_};
  HBT_ARG_CHECK_EQ(interval_sources_.count(new_key), 0)
      << "There is already an interval source with key: \"" << new_key << "\"";
  interval_sources_[new_key] = nullptr;

  if (slice_gen_ctxt_) {
    for_each_cpu(cpu_id, getMonCpus()) {
      auto islicer = slice_gen_ctxt_->getIntervalSlicer(cpu_id);
      islicer->registerConsumerMark(new_key);
    }
  }
}

TraceCollector::CountGenCtxt::CountGenCtxt(
    const CpuSet& mon_cpus,
    size_t perf_event_per_cpu_num_pages,
    std::optional<uint64_t> sampling_period,
    std::shared_ptr<const perf_event::MetricDesc> metric_desc,
    std::shared_ptr<const perf_event::PmuDeviceManager> pmu_manager,
    std::shared_ptr<FdWrapper> cgroup_fd_wrapper,
    size_t rb_min_num_entries,
    size_t num_counts_drop_if_full)
    : perf_event_per_cpu_num_pages{perf_event_per_cpu_num_pages},
      sampling_period{sampling_period} {
  count_gen = std::make_unique<TPerCpuCountSampleGenerator>(
      mon_cpus,
      metric_desc,
      pmu_manager,
      cgroup_fd_wrapper,
      rb_min_num_entries,
      num_counts_drop_if_full);

  for_each_cpu(cpu, mon_cpus) {
    count_gen_consumers.emplace(
        cpu, count_gen->getCpuGenerator(cpu).getOutput());
  }
}

/// Register a new source of partitions for SlicerIntervalSlicer.
/// This generates slices partitioned according to the count
/// intervals (each slice interval corresponds to one
/// count's [tstamp, tstamp + duration) interval).
/// If <sampling_period> == nullopt, use metric's default.
void TraceCollector::emplaceCountGenerator(
    const std::string& new_key,
    std::shared_ptr<const perf_event::MetricDesc> metric_desc,
    std::shared_ptr<const perf_event::PmuDeviceManager> pmu_manager,
    std::shared_ptr<FdWrapper> cgroup_fd_wrapper,
    size_t perf_event_per_cpu_num_pages,
    std::optional<uint64_t> sampling_period,
    size_t rb_min_num_entries,
    size_t num_counts_drop_if_full) {
  std::lock_guard<std::mutex> slices_lock{slices_mutex_};
  std::lock_guard<std::mutex> counts_lock{counts_mutex_};

  // Check for key before creating new count generator.
  HBT_ARG_CHECK_EQ(interval_sources_.count(new_key), 0)
      << "There is already an interval source with key: \"" << new_key << "\"";

  interval_sources_.emplace(
      new_key,
      std::make_unique<CountGenCtxt>(
          getMonCpus(),
          perf_event_per_cpu_num_pages,
          sampling_period,
          metric_desc,
          pmu_manager,
          cgroup_fd_wrapper,
          rb_min_num_entries,
          num_counts_drop_if_full));

  if (slice_gen_ctxt_) {
    for_each_cpu(cpu_id, getMonCpus()) {
      auto islicer = slice_gen_ctxt_->getIntervalSlicer(cpu_id);
      islicer->registerConsumerMark(new_key);
    }
  }

  // Transition newly emplaced PerCpuCountSampleGenerator to TraceCollector's
  // state.
  sync_();
}

/// Removes a source of partitions from IntervalSlicer.
void TraceCollector::cleanupCountGenerator(const std::string& key_to_erase) {
  // Acquire both locks as it modifiy both interval_sources_ and slice_gen_ctxt_
  std::lock_guard<std::mutex> slices_lock{slices_mutex_};
  std::lock_guard<std::mutex> counts_lock{counts_mutex_};
  interval_sources_.erase(key_to_erase);

  if (slice_gen_ctxt_) {
    for_each_cpu(cpu_id, getMonCpus()) {
      auto islicer = slice_gen_ctxt_->getIntervalSlicer(cpu_id);
      islicer->removeConsumerMark(key_to_erase);
    }
  }
}

std::ostream& TraceCollector::printSliceGenStatus(
    std::ostream& os,
    const cpu_set_t& cpus) const {
  std::lock_guard<std::mutex> slices_lock{slices_mutex_};
  std::lock_guard<std::mutex> counts_lock{counts_mutex_};

  if (slice_gen_ctxt_ == nullptr) {
    os << "No Slice Generator\n";
  } else {
    HBT_THROW_ASSERT_IF(slice_gen_ctxt_->slice_gen == nullptr);
    HBT_THROW_ASSERT_IF(slice_gen_ctxt_->md_gen == nullptr);

    os << "<SliceGenerators>\n";
    slice_gen_ctxt_->slice_gen->printStatus(os, cpus);
    slice_gen_ctxt_->md_gen->printStatus(os, cpus);
    os << "<End of SliceGenerators>\n";
  }
  return os;
}

std::ostream& TraceCollector::printSlicerStatus(std::ostream& oss) const {
  std::lock_guard<std::mutex> slices_lock{slices_mutex_};
  if (slice_gen_ctxt_ != nullptr) {
    const auto& sg = slice_gen_ctxt_->slice_gen;
    auto ts_now = sg->now();
    auto last_ts = sg->getLastTimeStamp();
    auto slicer_stats = sg->getStats();
    oss << "Slicer (now: " << tstampToStr(ts_now)
        << ", behind: " << tstampToStr(ts_now - last_ts) << "):";
    oss << "\n\tlast_tstamp: " << tstampToStr(last_ts);
    oss << "\n\tnum_processed: " << slicer_stats.num_processed;
    oss << "\n\tnum_error_start: " << slicer_stats.num_error_start;
    oss << "\n\tnum_error_end: " << slicer_stats.num_error_end;
    oss << "\n\tnum_error_out_sync: " << slicer_stats.num_error_out_sync;
    oss << "\n\tnum_dropped: " << slicer_stats.num_dropped;
    oss << "\n\tnum_out_of_order: " << slicer_stats.num_out_of_order;
    oss << "\n\tnum_slices_completed: " << slicer_stats.num_slices_completed;
    oss << "\n";
  }
  return oss;
}

std::ostream& TraceCollector::printCountGeneratorsStatus(
    std::ostream& os,
    const cpu_set_t& cpus) const {
  std::lock_guard<std::mutex> counts_lock{counts_mutex_};
  if (numCountGenerators_() == 0) {
    os << "No Count Generators\n";
    return os;
  }
  os << "<PerCpuCountGenerators>\n";
  for (const auto& [k, ctxt] : interval_sources_) {
    os << "\nCountGenerator: \"" << k << "\"";
    if (ctxt == nullptr) {
      os << " <Empty>\n";
    } else {
      os << "\n";
      ctxt->count_gen->printStatus(os, cpus);
    }
  }
  os << "<End of PerCpuCountGenerators>\n";
  return os;
}

//
// Finite State Machine to handle state transitions.
//

template <class TGen, class... Args>
void tryOpen_(TGen& gen, Args&&... args) {
  if (!gen.isOpen()) {
    gen.open(std::forward<Args>(args)...);
  }
}

template <class TGen>
void tryEnable_(TGen& gen) {
  if (!gen.isEnabled()) {
    gen.enable();
  }
}

template <class TGen>
void tryClose_(TGen& gen) {
  if (gen.isOpen()) {
    gen.close();
  }
}

template <class TGen>
void tryDisable_(TGen& gen) {
  if (gen.isEnabled()) {
    gen.disable();
  }
}

/// Transitions (enable/disable, open/close)
/// all components in TraceCollector to the new state.
void TraceCollector::sync_() {
  if (thread_gen_ctxt_) {
    auto& th_sw_gen = *thread_gen_ctxt_->per_cpu_thread_gen;
    switch (state_) {
      case State::Closed:
        tryDisable_(th_sw_gen);
        tryClose_(th_sw_gen);
        break;
      case State::Open:
        tryDisable_(th_sw_gen);
        tryOpen_(
            th_sw_gen, thread_gen_ctxt_->params.perf_event_per_cpu_num_pages);
        break;
      case State::Enabled:
        tryOpen_(
            th_sw_gen, thread_gen_ctxt_->params.perf_event_per_cpu_num_pages);
        tryEnable_(th_sw_gen);
        break;
    }
  }

  for (auto& [k, cg_ctxt] : interval_sources_) {
    if (cg_ctxt == nullptr) {
      continue;
    }
    auto& cg = *cg_ctxt->count_gen;
    switch (state_) {
      case State::Closed:
        tryDisable_(cg);
        tryClose_(cg);
        break;
      case State::Open:
        tryDisable_(cg);
        tryOpen_(
            cg,
            cg_ctxt->perf_event_per_cpu_num_pages,
            cg_ctxt->sampling_period);
        break;
      case State::Enabled:
        tryOpen_(
            cg,
            cg_ctxt->perf_event_per_cpu_num_pages,
            cg_ctxt->sampling_period);
        tryEnable_(cg);
        break;
    }
  }
}

} // namespace facebook::hbt::mon
