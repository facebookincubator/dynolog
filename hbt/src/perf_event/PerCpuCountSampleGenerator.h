// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/CpuEventsGroup.h"
#include "hbt/src/perf_event/Metrics.h"
#include "hbt/src/perf_event/PerCpuSampleGeneratorBase.h"
#include "hbt/src/ringbuffer/Producer.h"
#include "hbt/src/ringbuffer/RingBuffer.h"
#include "hbt/src/tagstack/Event.h"

#include <memory>

namespace facebook::hbt::perf_event {

//
// CRTP extension of CpuEventsGroup<>.
//
// Sample counters from perf_event groups and stores them in
// internally maintained instances of OutputProducer.
// It relies on perf_events opened on sampling mode.
//
class CpuCountSampleGenerator final
    : public CpuEventsGroup<CpuCountSampleGenerator, mode::Sampling> {
 public:
  using TBase = CpuEventsGroup<CpuCountSampleGenerator, mode::Sampling>;

  struct RbExtraData {};

  // Store all samples as <tstamp>,<duration>,<count_0> ... <count_n>
  using TOutputProducer = ringbuffer::Producer<RbExtraData>;

  /// Convenience type definition to create structure to store read values.
  using ReadValues = GroupReadValues<mode::Sampling>;

  // Maximum possible number of counters supported. It is used to statically
  // allocate an auxiliar array and keep code simple.
  // It does not matter if its safely larger than a reasonable number of
  // counters.
  static constexpr size_t kMaxNumEvents = 64;

  // Actual number of events in <event_confs>.
  const size_t kNumEvents;

  // This class has a constant write size for records.
  // Used by classed that need to create a data type for the count.
  const size_t kWriteByteSize;

  // If zero then do not drop existing count intervals.
  const size_t kNumBytesDropIfFull;

  /// If <num_counts_drop_if_full> is not zero. It will drop that many
  /// count samples every time the ringbuffer is full,
  /// effectively turning the ringbuffer into a fixed size FIFO queue
  /// that only keeps the last-in values.
  CpuCountSampleGenerator(
      const std::vector<std::string>& ev_names,
      CpuId cpu,
      int cgroup_fd,
      EventConfs event_confs,
      size_t rb_min_num_entries,
      size_t num_counts_drop_if_full)
      : TBase{cpu, -1, cgroup_fd, event_confs},
        kNumEvents{event_confs.size()},
        kWriteByteSize{sizeof(uint64_t) * (2 + kNumEvents)},
        kNumBytesDropIfFull{num_counts_drop_if_full * kWriteByteSize},
        event_names_{ev_names},
        output_producer_{std::make_shared<ringbuffer::RingBuffer<RbExtraData>>(
            rb_min_num_entries * kWriteByteSize)} {
    HBT_ARG_CHECK_LE(kNumEvents, kMaxNumEvents);
  }

  auto getOutput() noexcept {
    return output_producer_.getRingBuffer();
  }

  const auto& getOutputRef() const noexcept {
    return output_producer_.getRingBufferRef();
  }

  size_t getNumEntries() const {
    HBT_DCHECK(
        output_producer_.getHeader().usedSizeWeak() % kWriteByteSize == 0);
    return output_producer_.getHeader().usedSizeWeak() / kWriteByteSize;
  }

  void enableImpl() {
    // Log values for start of next count period.
    count_.tstamp = this->now();

    for (size_t i = 0; i < kNumEvents; ++i) {
      uint64_t value = 0;
      const auto& ec = this->confs_[i];

      // Transform value if needed.
      if (ec.transforms.flags & EventValueTransforms::TscToKernelTime) {
        value = this->kernelTimeFromTsc(value);
      }
      // Save the transformed value.
      last_[i] = value;
    }
  }

  void disableImpl() {}

  ssize_t handleRecordLost(const mode::Sampling::Lost& r) noexcept {
    HBT_LOG_WARNING() << "CpuCountSampleGenerator handleRecordlost num_lost: "
                      << r.num_lost;

    // perf_event RecordLost timestamp corresponds to the time the event
    // is written to the perf_event ringbuffer. This usually happens
    // not when an event is dropped but when the first event after
    // the lost records is written. Therefore, the time is not useful.
    // When there are lost records, there is no way to accurately know
    // the length of the blackout period, so simply consider lost
    // everything between two succesful samples surrounding a RecordLost.
    HBT_DCHECK_LE(count_.tstamp, this->now()) << "Sanity check";
    count_.tstamp = kInvalidTimeStamp;
    return 0;
  }

  ssize_t handleRecordRead(const mode::Sampling::Read& r
                           __attribute__((unused))) noexcept {
    /// XXX: Do nothing, implement in the future.
    return 0;
  }

  ssize_t handleRecordSample(const mode::Sampling::Sample& r) noexcept {
    HBT_DCHECK_EQ(r.nr, kNumEvents);

    if (unlikely(count_.tstamp == kInvalidTimeStamp)) {
      // Discard this count because we don't know the start of
      // of the counting interval due to the lost package.

      count_.tstamp = r.tstamp;
      for (size_t i = 0; i < kNumEvents; ++i) {
        uint64_t value = r.value[i];
        const auto& ec = this->confs_[i];

        // Transform value if needed.
        if (ec.transforms.flags & EventValueTransforms::TscToKernelTime) {
          value = this->kernelTimeFromTsc(value);
        }
        // Save the transformed value.
        last_[i] = value;
      }

      ++num_unknown_count_interval_;
      return 0;
    }

    if (unlikely(count_.tstamp > r.tstamp)) {
      HBT_LOG_ERROR() << fmt::format(
          "New record's timestamp ({}) precedes last timestamp ({})",
          r.tstamp,
          count_.tstamp);
      count_.tstamp = kInvalidTimeStamp;
      return -EPERM;
    }

    count_.duration = r.tstamp - count_.tstamp;
    for (size_t i = 0; i < kNumEvents; ++i) {
      uint64_t value = r.value[i];
      const auto& ec = this->confs_[i];

      // Transform value if needed.
      if (ec.transforms.flags & EventValueTransforms::TscToKernelTime) {
        value = this->kernelTimeFromTsc(value);
      }

      HBT_DCHECK_GE(value, last_[i]);
      count_.deltas[i] = value - last_[i];
      // Save the transformed value.
      last_[i] = value;
    }

    // Do not write the "values" part of Count.
    auto ret = output_producer_.write(&count_, kWriteByteSize);
    if (unlikely(kNumBytesDropIfFull > 0 && ret == -ENOSPC)) {
      auto err = output_producer_.dropN(kNumBytesDropIfFull);
      HBT_THROW_ASSERT_IF(0 > err);
      // Retry now that space has been cleared. There is
      // no another producer for this ringbuffer so it
      // cannot fail due too lack of space again.
      ret = output_producer_.write(&count_, kWriteByteSize);
    }
    if (unlikely(0 > ret)) {
      count_.tstamp = kInvalidTimeStamp;
      return ret;
    }
    HBT_DCHECK(
        output_producer_.getHeader().usedSizeWeak() % kWriteByteSize == 0);

    // Prepare tstamp for start of next count interval.
    count_.tstamp = r.tstamp;

    return 0;
  }

  void open(size_t num_data_pages, uint64_t sampling_period, bool pinned) {
    this->open_(num_data_pages, sampling_period, pinned, 0);
    HBT_THROW_ASSERT_IF(!isOpen());
  }

  TimeStamp getLastTimeStamp() const noexcept {
    return count_.tstamp;
  }

  const auto& getEventNames() const noexcept {
    return event_names_;
  }

 protected:
  std::vector<std::string> event_names_;
  TOutputProducer output_producer_;

  // First part of this structure is passed to producer's write.
  struct Count {
    TimeStamp tstamp = kInvalidTimeStamp; // TimeStamp at start of count period.
    TimeStamp duration = kInvalidTimeStamp; // Duration of count period.
    uint64_t deltas[kMaxNumEvents];
  };
  Count count_;
  uint64_t last_[kMaxNumEvents];

  uint32_t num_unknown_count_interval_ = 0;
};

// Wrap many instances of CpuCountSampleGenerator, one per CPU.
class PerCpuCountSampleGenerator
    : public PerCpuSampleGeneratorBase<CpuCountSampleGenerator> {
 public:
  using TBase = PerCpuSampleGeneratorBase<CpuCountSampleGenerator>;
  using TCpuGenerator = CpuCountSampleGenerator;
  using ReadValues = typename TCpuGenerator::ReadValues;

  PerCpuCountSampleGenerator(
      const CpuSet& mon_cpus,
      std::shared_ptr<const MetricDesc> metric_desc_in,
      std::shared_ptr<const PmuDeviceManager> pmu_manager_in,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper,
      size_t rb_min_num_entries,
      size_t num_counts_drop_if_full)
      : TBase{mon_cpus, cgroup_fd_wrapper},
        pmu_manager{pmu_manager_in},
        metric_desc{metric_desc_in} {
    HBT_DCHECK(pmu_manager != nullptr);
    HBT_DCHECK(metric_desc != nullptr);

    // PMU may change the monitored CPUs for package events.
    auto per_cpu_event_confs =
        metric_desc->makePerCpuConfs(mon_cpus, *pmu_manager);

    int cgroup_fd = -1;
    if (this->cgroup_fd_wrapper_ != nullptr) {
      cgroup_fd = this->cgroup_fd_wrapper_->fd;
    }
    for_each_cpu(cpu, mon_cpus) {
      HBT_DCHECK_EQ(per_cpu_event_confs.count(cpu), 1);
      this->cpu_generators_[cpu] = std::make_shared<TCpuGenerator>(
          getEventNicknames(),
          cpu,
          cgroup_fd,
          per_cpu_event_confs.at(cpu),
          rb_min_num_entries,
          num_counts_drop_if_full);
    }
    HBT_ARG_CHECK_GT(getNumEvents(), 0)
        << "No events in metric_desc for architecture";
  }

  void open(
      size_t num_pages,
      std::optional<uint64_t> sampling_period,
      bool pinned = false) {
    uint64_t p = sampling_period.value_or(metric_desc->default_sampling_period);
    try {
      for_each_cpu(cpu, this->getMonCpus()) {
        this->getCpuGenerator(cpu).open(num_pages, p, pinned);
      }
    } catch (...) {
      close();
      throw;
    }
  }

  std::vector<std::string> getEventNicknames() const {
    return metric_desc->eventNicknames(pmu_manager->cpuInfo.cpu_arch);
  }

  size_t getNumEvents() const {
    auto opt = this->metric_desc->getNumEvents(pmu_manager->cpuInfo.cpu_arch);
    HBT_DCHECK(opt.has_value());
    return *opt;
  }

  ReadValues makeReadValues() const {
    return ReadValues{getNumEvents()};
  }

  using TBase::read;

  std::optional<ReadValues> read() const {
    auto rv = makeReadValues();
    if (TBase::read(rv)) {
      return std::make_optional(rv);
    } else {
      return std::nullopt;
    }
  }

  std::ostream& printStatus(std::ostream& os, cpu_set_t cpus) const {
    if (!CPU_COUNT(&cpus)) {
      return os << "Counter Sample Generator for " << metric_desc->id
                << " active.\n";
    }

    os << "Counter Sample Generator for " << metric_desc->id << ":\n";
    for_each_cpu_set_t(cpu_id, cpus) {
      const auto& gen = this->getCpuGenerator(cpu_id);
      os << "\tCPU: " << cpu_id << " is "
         << (gen.isEnabled() ? "enabled" : "disabled") << "\n";
      auto used = gen.usedSizeWeak();
      os << "\t\tperf_event rb used size: " << used << "/" << gen.bufferSize()
         << " bytes (" << (used * 100) / gen.bufferSize() << "%)\n";
      os << "\t\toutput: ";
      os << "\t\tNumber Stored Entries: " << gen.getNumEntries();
      os << "\t\tNumber Record Sample: " << gen.getNumRecordSample() << "\n";
      os << "\t\tNumber Record (Lost, Throttle, Unthrottle): ("
         << gen.getNumRecordLost() << ", " << gen.getNumRecordThrottle() << ", "
         << gen.getNumRecordUnThrottle() << ")\n";
      HBT_DCHECK_EQ(gen.getNumRecordComm(), 0);
      HBT_DCHECK_EQ(gen.getNumRecordExit(), 0);
      HBT_DCHECK_EQ(gen.getNumRecordFork(), 0);
      HBT_DCHECK_EQ(gen.getNumRecordSwitchCpuWide(), 0);
    }
    return os;
  }

  const std::shared_ptr<const PmuDeviceManager> pmu_manager;
  const std::shared_ptr<const MetricDesc> metric_desc;
};

} // namespace facebook::hbt::perf_event
