// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/Defaults.h"
#include "hbt/src/common/System.h"
#include "hbt/src/mon/PerCpuSliceGenerator.h"
#include "hbt/src/perf_event/PerCpuCountSampleGenerator.h"
#include "hbt/src/perf_event/PerCpuDummyGenerator.h"
#include "hbt/src/phase/PerCpuMetaDataConsumer.h"
#include "hbt/src/ringbuffer/Shm.h"
#include "hbt/src/tagstack/IntervalSlicer.h"

#include <sched.h>
#include <exception>
#include <mutex>

namespace facebook::hbt::mon {

/// Collects context switch slices, count samples and combines them
/// into TagStack slices.
/// This class slices outputs that can be "raw" (context switches slices only)
/// or split by count intervals of a PerCpuCountGenerator.
/// It owns threads to process events from RingBuffers and generate slices and
/// count samples.
class TraceCollector {
  enum class State {
    Closed, // No perf_events are opened.
    Open, // perf_events are opened but disabled.
    Enabled // perf_events are opened and enabled.
  };

 public:
  using TPerCpuCountSampleGenerator = perf_event::PerCpuCountSampleGenerator;
  using TPerCpuThreadGenerator =
      typename perf_event::PerCpuThreadSwitchGenerator;
  using TPerCpuSliceGenerator = PerCpuSliceGenerator<tagstack::IntervalSlicer>;
  using TPhasesPerCpuRingBuffer =
      typename TPerCpuSliceGenerator::TPhasesPerCpuRingBuffer;
  using TGroupedSlices = typename TPerCpuSliceGenerator::TGroupedSlices;
  using TMetaDataPerCpuRingBuffer =
      typename phase::PerCpuMetaDataConsumer::TPerCpuRingBuffer;

  static constexpr tagstack::Level kTidLevel = 0;

  struct ThreadSwitchGenParams {
    size_t perf_event_per_cpu_num_pages;
    size_t thread_switch_aux_rb_min_num_events;
  };

  struct ThreadSwitchGenCtxt {
    ThreadSwitchGenCtxt(
        ThreadSwitchGenParams& params,
        std::shared_ptr<TPerCpuThreadGenerator> per_cpu_thread_gen)
        : params(params), per_cpu_thread_gen(per_cpu_thread_gen) {}

    ThreadSwitchGenParams params;
    std::shared_ptr<TPerCpuThreadGenerator> per_cpu_thread_gen;
  };

  /// Helper struct with all context necessary to initialize
  /// and manage a SliceGenerator.
  struct SliceGenCtxt {
    size_t perf_event_per_cpu_num_pages;
    std::unique_ptr<TPerCpuSliceGenerator> slice_gen;
    std::unique_ptr<phase::PerCpuMetaDataConsumer> md_gen;

    SliceGenCtxt(
        size_t perf_event_per_cpu_num_pages,
        std::unique_ptr<TPerCpuSliceGenerator> slice_gen,
        std::unique_ptr<phase::PerCpuMetaDataConsumer> md_gen);

    auto getIntervalSlicer(CpuId cpu_id) {
      return slice_gen->getSlices()->at(cpu_id);
    }
  };

  /// Helper struct with all context necessary to initialize
  /// and manage a source of CountSampleGenerator.
  struct CountGenCtxt {
    using RbExtraData = TPerCpuCountSampleGenerator::TCpuGenerator::RbExtraData;
    using TCountConsumer = ringbuffer::Consumer<RbExtraData>;

    size_t perf_event_per_cpu_num_pages;
    std::optional<uint64_t> sampling_period;
    std::unique_ptr<TPerCpuCountSampleGenerator> count_gen;
    std::unordered_map<CpuId, TCountConsumer> count_gen_consumers;

    CountGenCtxt(
        const CpuSet& mon_cpus,
        size_t perf_event_per_cpu_num_pages,
        std::optional<uint64_t> sampling_period,
        std::shared_ptr<const perf_event::MetricDesc> metric_desc,
        std::shared_ptr<const perf_event::PmuDeviceManager> pmu_manager,
        std::shared_ptr<FdWrapper> cgroup_fd_wrapper,
        size_t rb_min_num_entries,
        size_t num_counts_drop_if_full);
  };

  explicit TraceCollector(const CpuSet& mon_cpus)
      : state_{State::Closed}, mon_cpus_{mon_cpus}, dummy_gen_{0} {
    dummy_gen_.open();
    dummy_gen_.enable();
  }

  auto getMonCpus() const {
    return mon_cpus_;
  }

  std::optional<TscConversionParams> readTscConversionParams() const {
    HBT_DCHECK(dummy_gen_.isOpen());
    // No need for lock because the fields in the perf_event's
    // mapped memory header page that TPerCpuThreadGenerator accesses to
    // service this function are independent from the head/tail used
    // on event processing.
    return dummy_gen_.readTscConversionParams();
  }

  TimeStamp tstampFromTsc(TimeStamp tsc) const {
    HBT_DCHECK(dummy_gen_.isOpen());
    // No need for lock because the fields in the perf_event's
    // mapped memory header page that TPerCpuThreadGenerator accesses to
    // service this function are independent from the head/tail used
    // on event processing.
    return dummy_gen_.kernelTimeFromTsc(tsc);
  }

  TimeStamp now() const {
    HBT_DCHECK(dummy_gen_.isOpen());
    // No need for lock because the fields in the perf_event's
    // mapped memory header page that TPerCpuThreadGenerator accesses
    // to service this function are independent from the head/tail used
    // on event processing.
    return dummy_gen_.now();
  }

  auto buildTimeStampNsConverter() const {
    HBT_DCHECK(dummy_gen_.isOpen());
    // A functor to call <now>.
    return TimeStampNsConverter::makeFromNow(
        [=]() { return dummy_gen_.now(); });
  }

  std::unique_ptr<tagstack::slice::TagStackStatsDump> getTagStackStatsDump()
      const {
    std::lock_guard<std::mutex> lock{slices_mutex_};

    if (slice_gen_ctxt_ == nullptr) {
      return nullptr;
    }
    HBT_THROW_ASSERT_IF(slice_gen_ctxt_->slice_gen == nullptr);
    return slice_gen_ctxt_->slice_gen->getTagStackStatsDump();
  }

  std::unique_ptr<perf_event::ThreadsInfo> cloneThreadsInfo() const {
    std::lock_guard<std::mutex> lock{slices_mutex_};
    if (slice_gen_ctxt_ == nullptr) {
      return nullptr;
    }
    HBT_THROW_ASSERT_IF(slice_gen_ctxt_->slice_gen == nullptr);
    auto tinfo = std::make_unique<perf_event::ThreadsInfo>(
        slice_gen_ctxt_->slice_gen->getPerCpuThreadGenerator()
            .getThreadsInfo());
    return tinfo;
  }

  void open() {
    std::lock_guard<std::mutex> slices_lock{slices_mutex_};
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};
    state_ = State::Open;
    sync_();
  }

  // Enabled implies open.
  bool isOpen() const {
    std::lock_guard<std::mutex> slices_lock{slices_mutex_};
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};
    return state_ == State::Open || state_ == State::Enabled;
  }

  void close() {
    std::lock_guard<std::mutex> slices_lock{slices_mutex_};
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};
    state_ = State::Closed;
    sync_();
  }

  void enable() {
    std::lock_guard<std::mutex> slices_lock{slices_mutex_};
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};
    state_ = State::Enabled;
    sync_();
  }

  bool isEnabled() const {
    std::lock_guard<std::mutex> slices_lock{slices_mutex_};
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};
    return state_ == State::Enabled;
  }

  void disable() {
    std::lock_guard<std::mutex> slices_lock{slices_mutex_};
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};
    state_ = State::Open;
    sync_();
  }

  /// Read events in PerCpuCountSampleGenerator.
  /// This is possible because perf_events opened in sample
  /// mode can be read as regular events.
  auto readCounts() const {
    std::lock_guard<std::mutex> slices_lock{slices_mutex_};
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};
    std::
        map<std::string, std::optional<TPerCpuCountSampleGenerator::ReadValues>>
            rvs;

    for (auto& [k, igen] : interval_sources_) {
      if (igen == nullptr) {
        // This are the cases where there is no
        // CountGenerator associated to the interval source.
        // This is the scenario wher unmodified Slices are produced.
        continue;
      } else {
        HBT_THROW_ASSERT_IF(igen->count_gen == nullptr);
        rvs.emplace(k, igen->count_gen->read());
      }
    }
    return rvs;
  }

  /// Create a ThreadGenerator object with the provided parameters.
  /// If no parameters are provided, TraceCollector::kDefaultThreadGenParams are
  /// used.
  void emplaceThreadGenerator(
      std::optional<ThreadSwitchGenParams> thread_gen_params = std::nullopt);

  /// Create RingBuffer objects for Phases and then use them to
  /// emplace a TagStackGenerator.
  void emplaceTagStackGeneratorFromRbs(
      std::shared_ptr<TPhasesPerCpuRingBuffer> phases_per_cpu_rb,
      std::shared_ptr<TMetaDataPerCpuRingBuffer> metadata_per_cpu_rb,
      size_t min_num_slices,
      std::optional<ThreadSwitchGenParams> hint_thread_gen_params,
      size_t num_slices_drop_if_full);

  /// Create a TagStackGenerator and create RingBuffer objects.
  void emplaceTagStackGenerator(
      std::optional<std::string> shm_base_path,
      size_t min_num_slices,
      std::optional<ThreadSwitchGenParams> hint_thread_gen_params,
      size_t num_slices_drop_if_full,
      size_t cpu_phases_rb_size,
      size_t cpu_metadata_rb_size,
      bool persistent) {
    auto [events_rbs_path, metadata_rbs_path] =
        defaults::shmRbNames(shm_base_path);

    emplaceTagStackGeneratorFromRbs(
        ringbuffer::shm::create<TPhasesPerCpuRingBuffer>(
            events_rbs_path, cpu_phases_rb_size, persistent, getMonCpus()),
        ringbuffer::shm::create<TMetaDataPerCpuRingBuffer>(
            metadata_rbs_path, cpu_metadata_rb_size, persistent, getMonCpus()),
        min_num_slices,
        hint_thread_gen_params,
        num_slices_drop_if_full);
  }

  /// Create a new output of unmodified slices.
  void emplaceSlicesOutput(const std::string& new_key);

  /// Register a new source of partitions for IntervalSlicer.
  /// This generates slices partitioned according to the count
  /// intervals (each slice interval corresponds to one
  /// count's [tstamp, tstamp + duration) interval).
  void emplaceCountGenerator(
      const std::string& new_key,
      std::shared_ptr<const perf_event::MetricDesc> metric_desc,
      std::shared_ptr<const perf_event::PmuDeviceManager> pmu_manager,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper,
      size_t perf_event_per_cpu_num_pages,
      std::optional<uint64_t> sampling_period,
      size_t rb_min_num_entries,
      size_t num_counts_drop_if_full);

  /// Removes a source of partitions from IntervalSlicer.
  void cleanupCountGenerator(const std::string& key_to_erase);

  std::ostream& printSliceGenStatus(std::ostream& os, const cpu_set_t& cpus)
      const;

  std::ostream& printCountGeneratorsStatus(
      std::ostream& os,
      const cpu_set_t& cpus) const;

  std::ostream& printSlicerStatus(std::ostream& oss) const;

  std::string statusStr(std::optional<CpuSet> cpus) const {
    std::ostringstream os;

    {
      std::lock_guard<std::mutex> slices_lock{slices_mutex_};
      std::lock_guard<std::mutex> counts_lock{counts_mutex_};
      os << "State: ";
      switch (state_) {
        case State::Closed:
          os << "Closed\n";
          break;
        case State::Open:
          os << "Open\n";
          break;
        case State::Enabled:
          os << "Enabled\n";
          break;
      }
    }

    auto cpuset = cpus.value_or(getMonCpus()).cpu_set;

    printSliceGenStatus(os, cpuset);
    printCountGeneratorsStatus(os, cpuset);
    printSlicerStatus(os);
    return os.str();
  }

  virtual ~TraceCollector() {
    joinAccumThreads();
    state_ = State::Closed;
    sync_();
    dummy_gen_.close();
  }

  /// Process until <stop_ts>, halts at any empty stream.
  void processNextSlices(unsigned batch_size, TimeStamp stop_ts) {
    {
      // TagStack Events (Slices).
      std::lock_guard<std::mutex> lock{slices_mutex_};
      HBT_THROW_ASSERT_IF(slice_gen_ctxt_->slice_gen == nullptr);
      slice_gen_ctxt_->slice_gen->processNext(batch_size, stop_ts);
    }
    {
      // MetaData
      std::lock_guard<std::mutex> lock{slices_mutex_};
      HBT_THROW_ASSERT_IF(slice_gen_ctxt_->md_gen == nullptr);
      slice_gen_ctxt_->md_gen->processNext(batch_size, stop_ts);
    }
  }

  /// Process until <stop_ts>, halts at any empty stream.
  void processNextCounts(unsigned batch_size, TimeStamp stop_ts) {
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};
    // Count Intervals
    for (auto& [k, igen] : interval_sources_) {
      if (igen == nullptr) {
        // This interval source has no count generator associated
        // (it produces raw slices).
        continue;
      }
      HBT_THROW_ASSERT_IF(igen->count_gen == nullptr) << k;
      igen->count_gen->accumUntil(batch_size, stop_ts);
    }
  }

  /// Pass the pointers denoting the CPUs' perf_event data ring buffer to
  /// `callback`. If consume == True, then update data_tail to mark copied data
  /// as consumed.
  void onCpusDataBufferRead(
      perf_event::OnRbReadCallback callback,
      bool consume) {
    HBT_ARG_CHECK(thread_gen_ctxt_ != nullptr)
        << "Context switch data unavailable. Emplace trace monitor"
           " or context switch generator before calling this method.";

    auto th_sw_gen = thread_gen_ctxt_->per_cpu_thread_gen;

    HBT_ARG_CHECK(th_sw_gen != nullptr)
        << "Context switch data unavailable."
           " Ensure PerCpuThreadGenerator is initialized before calling this method.";

    th_sw_gen->onCpusThreadSwitchBufferRead(callback, consume);
  }

  /// Process until <stop_ts_opt> (or now() if stop_ts_opt is nullopt.
  /// If <pipeline_max_lat_secs> is provided, then stop that many seconds
  /// before stop_ts. This is useful to allow data to propagate through
  /// pipeline.
  void processNext(
      unsigned batch_size,
      std::optional<TimeStamp> stop_ts_opt,
      std::optional<std::chrono::seconds> pipeline_max_lat_secs_opt) {
    auto stop_ts = stop_ts_opt.value_or(now());
    if (pipeline_max_lat_secs_opt.has_value()) {
      stop_ts = tagstack::stream::toStopTs(stop_ts, *pipeline_max_lat_secs_opt);
    }
    processNextSlices(batch_size, stop_ts);
    processNextCounts(batch_size, stop_ts);
  }

  /// Creates and start a thread that will loop accumulating slices in all
  /// CPUs and another that will acccumulate counts.
  /// <slices_accum_period> how often slices routine should run.
  /// <counts_accum_period> how often counts routine should run.
  /// <pipeline_max_lat_secs> the assumed max latency of the pipeline.
  /// <min_pause> minimum wait time between executions.
  void launchAccumThreads(
      unsigned batch_size,
      std::chrono::milliseconds slices_accum_period,
      std::chrono::milliseconds counts_accum_period,
      std::chrono::seconds pipeline_max_lat_secs,
      std::chrono::milliseconds min_pause) {
    std::lock_guard<std::mutex> slices_lock{slices_mutex_};
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};

    auto slices_accum_fun = [this,
                             batch_size,
                             slices_accum_period,
                             pipeline_max_lat_secs,
                             min_pause]() {
      {
        // Set a human-readable name for the slices accumulator thread.
        int ret = setProcName("hbt__acc_phases");
        HBT_THROW_ASSERT_IF(ret != 0);
      }
      while (this->do_accum_threads_) {
        TimeStamp stop_ts;
        {
          // This code block access interval_sources_ and therefore is protected
          // with counts_mutex_.
          std::lock_guard<std::mutex> slices_lock{slices_mutex_};
          if (this->slice_gen_ctxt_ == nullptr) {
            // No slice generator, so sleep for a while and try again later in
            // case one is added in the future.
            std::this_thread::sleep_for(min_pause);
            continue;
          }
          HBT_THROW_ASSERT_IF(this->slice_gen_ctxt_ == nullptr);
          HBT_THROW_ASSERT_IF(this->slice_gen_ctxt_->slice_gen == nullptr);
          auto nowKernelTime = this->slice_gen_ctxt_->slice_gen->now();
          stop_ts =
              tagstack::stream::toStopTs(nowKernelTime, pipeline_max_lat_secs);
        }
        auto before_update = std::chrono::system_clock::now();
        processNextSlices(batch_size, stop_ts);
        auto after_update = std::chrono::system_clock::now();

        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            after_update - before_update);
        if (elapsed_ms > slices_accum_period) {
          HBT_LOG_WARNING()
              << "slices_accum_thread is falling behind, elapsed "
              << elapsed_ms.count() << "ms when expect to be up to "
              << slices_accum_period.count() << "ms";
          // Always wait some time regardless of how behind we are to allow
          // other threads to get the lock.
          std::this_thread::sleep_for(min_pause);
        } else {
          std::this_thread::sleep_for(slices_accum_period - elapsed_ms);
        }
      }
    };

    auto counts_accum_fun = [this,
                             batch_size,
                             counts_accum_period,
                             pipeline_max_lat_secs,
                             min_pause]() {
      {
        // Set a human-readable name for the counts accumulator thread.
        int ret = setProcName("hbt__acc_counts");
        HBT_THROW_ASSERT_IF(ret != 0);
      }

      while (this->do_accum_threads_) {
        TimeStamp stop_ts;

        {
          // This code block access interval_sources_ and therefore is protected
          // with counts_mutex_.
          std::lock_guard<std::mutex> counts_lock{counts_mutex_};

          if (interval_sources_.size() == 0) {
            // No count generator, so sleep for a while and try again later in
            // case one is added in the future.
            std::this_thread::sleep_for(min_pause);
            continue;
          }

          auto nowKernelTime = this->now();
          stop_ts =
              tagstack::stream::toStopTs(nowKernelTime, pipeline_max_lat_secs);
        }
        auto before_update = std::chrono::system_clock::now();
        processNextCounts(batch_size, stop_ts);
        // HBT_LOG_WARNING_IF(!success) << "Could not process until deadline";
        auto after_update = std::chrono::system_clock::now();

        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            after_update - before_update);
        if (elapsed_ms >= counts_accum_period) {
          HBT_LOG_WARNING()
              << "counts_accum_thread is falling behind, elapsed "
              << elapsed_ms.count() << "ms when expect to be up to "
              << counts_accum_period.count() << "ms";
          // Always wait some time regardless of how behind we are to allow
          // other threads to get the lock.
          std::this_thread::sleep_for(min_pause);
        } else {
          std::this_thread::sleep_for(counts_accum_period - elapsed_ms);
        }
      }
    };

    if (slices_accum_thread_) {
      HBT_LOG_ERROR()
          << "Launching slices accumulating thread when already started";
      return;
    }
    if (counts_accum_thread_) {
      HBT_LOG_ERROR()
          << "Launching counts accumulating thread when already started";
      return;
    }

    do_accum_threads_ = true;
    if (slice_gen_ctxt_) {
      slices_accum_thread_ = std::make_unique<std::thread>(slices_accum_fun);
    }
    if (numCountGenerators_() >= 0) {
      counts_accum_thread_ = std::make_unique<std::thread>(counts_accum_fun);
    }
  }

  void joinAccumThreads() {
    // Unset variable that control the loop all accumulator threads.
    do_accum_threads_ = false;

    if (slices_accum_thread_) {
      slices_accum_thread_->join();
      slices_accum_thread_ = nullptr;
    }
    if (counts_accum_thread_) {
      counts_accum_thread_->join();
      counts_accum_thread_ = nullptr;
    }
  }

  /// Get a string of vectors with the ids of all interval_sources
  /// (count trace generators).
  auto getIntervalSourceKeys(bool allow_nullptr) const {
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};
    std::vector<std::string> keys;
    for (const auto& [k, g] : interval_sources_) {
      if (allow_nullptr || g != nullptr) {
        keys.push_back(k);
      }
    }
    return keys;
  }

  size_t numCountGenerators() const {
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};
    return numCountGenerators_();
  }

 protected:
  State state_;

  const CpuSet mon_cpus_;

  // Always keep a Dummy Generator to be able to access to Linux kernel
  // sched clock information and TSCr information anly available in
  // perf_event's ringbuffer header page.
  // Note that we are only keeping for one arbitrary CPU which suffices because
  // sched clock is consistent to enough accuracy between all CPUs
  // and/or sockets.
  // CpuDummyGenerator never transitions state after TraceMonitor has been
  // initialized and using it does not need synchronization.
  perf_event::CpuDummyGenerator dummy_gen_;

  std::unique_ptr<ThreadSwitchGenCtxt> thread_gen_ctxt_;

  std::unique_ptr<SliceGenCtxt> slice_gen_ctxt_;

  /// Key is used to query for data. If value is nullptr,
  /// this interval source produces raw slices (not split by count intervals),
  /// otherwise the slices are split by count interval boundaries.
  std::unordered_map<std::string, std::unique_ptr<CountGenCtxt>>
      interval_sources_;

  // Mark as mutable to allow usage from const methods.
  mutable std::mutex slices_mutex_;
  mutable std::mutex counts_mutex_;

  std::unique_ptr<std::thread> slices_accum_thread_;
  std::unique_ptr<std::thread> counts_accum_thread_;
  std::atomic<bool> do_accum_threads_ = false;

  void sync_();

  size_t numCountGenerators_() const {
    size_t n = 0;
    for (const auto& [k, ptr] : interval_sources_) {
      // Do not count interval_sources_ that are used for unmodified slices.
      // Those ones have nullptr CountGenCtxt.
      if (ptr != nullptr) {
        ++n;
      }
    }
    return n;
  }
};

constexpr TraceCollector::ThreadSwitchGenParams kDefaultThreadGenParams = {
    .perf_event_per_cpu_num_pages = 32,
    .thread_switch_aux_rb_min_num_events = 1024};

} // namespace facebook::hbt::mon
