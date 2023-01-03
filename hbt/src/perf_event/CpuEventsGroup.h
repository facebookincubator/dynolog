// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/PmuEvent.h"

#include <cstring>
#include <sstream>

#include <inttypes.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <syscall.h>
#include <unistd.h>

#include <linux/perf_event.h>

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <iostream>
#include <vector>

// If this version of linux/perf_event.h does not provide,
// then add it.
#ifndef PERF_RECORD_MISC_SWITCH_OUT_PREEMPT
// #warning "Version of linux perf_event does not provide PREEMPT, "\
//          "the preempt VS yield field is bogus. "\
//          "Ignore this warning if you do not trace context switches."
// Indicates that thread explicitly yielded cpu due to
// a call of some synchronization API e.g. futex system call
#define PERF_RECORD_MISC_SWITCH_OUT_PREEMPT (1 << 14)

#endif

namespace facebook::hbt::perf_event {

// Represent a slice of data with size `size` starting from `from`.
struct DataSlice {
  DataSlice(const void* from, size_t size) : from{from}, size{size} {}
  const void* from;
  size_t size;
};

// Represents a ring buffer.
// The first slice will always initialized, but the second slice is only
// initialized when the ring buffer has wrapped.
struct RbDataSlices {
  RbDataSlices(const void* ptr1, size_t size1)
      : first{ptr1, size1}, second{std::nullopt} {}
  RbDataSlices(const void* ptr1, size_t size1, const void* ptr2, size_t size2)
      : first{ptr1, size1}, second{DataSlice{ptr2, size2}} {}

  DataSlice first;
  std::optional<DataSlice> second;
};

using OnRbReadCallback = std::function<void(CpuId, const RbDataSlices&)>;

// Supported operation mode.
namespace mode {

///
/// Mode to access to perf_event's ringbuffer first page without consuming any
/// record.
///
struct Dummy {
  using sample_id_t = void;
  using Lost = void;
  using Comm_Lower = void;
  using Exit = void;
  using Fork = void;
  using Read = void;
  using Sample = void;
  using Aux = void;
  using ItraceStart = void;
  using SwitchCpuWide = void;
};

///
/// Mode to access counter reads only, without sampling or perf_event's
/// ringbuffer.
///
struct Counting {
  using sample_id_t = void;
  using Lost = void;
  using Comm_Lower = void;
  using Exit = void;
  using Read = void;
  using Fork = void;
  using Sample = void;
  using Aux = void;
  using ItraceStart = void;
  using SwitchCpuWide = void;
};

///
/// Mode for tracking context switches in a CPU.
///
struct ContextSwitch {
  struct sample_id_t {
    uint32_t pid, tid;
    uint64_t tstamp; // time
  };

  /// PERF_RECORD_LOST.
  struct Lost {
    struct perf_event_header header;
    uint64_t id;
    uint64_t num_lost;

    struct sample_id_t sample_id;

    Lost(const Lost&) = delete;
  };

  /// PERF_RECORD_MISC_COMM_EXEC.
  ///
  /// This record has a variable size char[] before sample_id and therefore
  /// cannot be handled as a pointer to a POD. Instead, we use two
  /// pointers, one to the lower part with the char[] as a variable size array.
  ///
  /// And the higher part will be a pointer to sample_id.
  struct Comm_Lower {
    struct perf_event_header header;
    uint32_t pid, tid;
    const char comm[];
  };

  /// PERF_RECORD_EXIT.
  struct Exit {
    struct perf_event_header header;
    uint32_t pid, ppid;
    uint32_t tid, ptid;
    uint64_t time;

    struct sample_id_t sample_id;
  };

  /// PERF_RECORD_FORK.
  using Fork = Exit;

  /// PERF_RECORD_READ.
  using Read = void;

  ///  PERF_RECORD_SAMPLE.
  using Sample = void;

  /// PERF_RECORD_AUX.
  using Aux = void;

  /// PERF_RECORD_ITRACE_START.
  using ItraceStart = void;

  /// PERF_RECORD_SWITCH_CPU_WIDE.
  struct SwitchCpuWide {
    struct perf_event_header header;
    uint32_t next_prev_pid; // next or prev depending on
                            // PERF_RECORD_MISC_SWITCH_OUT in misc
    uint32_t next_prev_tid; // next or prev depending on
                            // PERF_RECORD_MISC_SWITCH_OUT in misc

    struct sample_id_t sample_id;

    SwitchCpuWide(const SwitchCpuWide&) = delete;

    bool isSwitchIn() const {
      return !isSwitchOut();
    }

    bool isSwitchOut() const {
      return header.misc & PERF_RECORD_MISC_SWITCH_OUT;
    }

    bool isSwitchOutPreempt() const {
      return header.misc & PERF_RECORD_MISC_SWITCH_OUT_PREEMPT;
    }
  };
};

inline std::ostream& operator<<(
    std::ostream& os,
    const struct ContextSwitch::SwitchCpuWide& r) {
  HBT_ARG_CHECK_EQ(r.header.type, PERF_RECORD_SWITCH_CPU_WIDE);
  os << "<SWITCHCPUWIDE "
     << (r.isSwitchOut() ? (r.isSwitchOutPreempt() ? "OUT_PREEMPT" : " OUT ")
                         : " IN ");

  os << (r.isSwitchOut() ? " next_pid: " : " prev_pid: ") << r.next_prev_pid;
  os << (r.isSwitchOut() ? " next_tid: " : " prev_tid: ") << r.next_prev_tid;
  os << " pid: " << r.sample_id.pid;
  os << " tid: " << r.sample_id.tid;
  os << " time: " << r.sample_id.tstamp << ">";
  return os;
}

///
/// Mode for tracking AUX space activities
///
struct AUXSpace {
  using sample_id_t = void;
  using Lost = void;
  using Comm_Lower = void;
  using Exit = void;
  using Fork = void;
  using Read = void;
  using Sample = void;
  // PERF_RECORD_AUX
  struct Aux {
    struct perf_event_header header;
    uint64_t aux_offset;
    uint64_t aux_size;
    uint64_t flags;
  };
  // PERF_RECORD_ITRACE_START
  struct ItraceStart {
    struct perf_event_header header;
    uint32_t pid;
    uint32_t tid;
  };
  using SwitchCpuWide = void;
};

///
/// Mode for sampling counts of events.
///
struct Sampling {
  using sample_id_t = void;

  /// PERF_RECORD_LOST.
  struct Lost {
    struct perf_event_header header;
    uint64_t id;
    uint64_t num_lost;

    Lost(const Lost&) = delete;
  };

  /// PERF_RECORD_COMM.
  using Comm_Lower = void;

  /// PERF_RECORD_EXIT.
  using Exit = void;

  /// PERF_RECORD_FORK.
  using Fork = void;

  /// PERF_RECORD_READ
  struct Read {
    struct perf_event_header header;
    uint32_t pid; // Reader's pid.
    uint32_t tid; // Reader's tid.
    uint64_t nr; // Number of events.
    uint64_t time_enabled; // The time that the group has been enabled (ready to
                           // run and running).
    uint64_t time_running; // The time that the group has been running.
    uint64_t value[];
    // sample_id has size zero for this record because no element in sample_id
    // is set.
  };

  /// PERF_RECORD_SAMPLE.
  struct Sample {
    struct perf_event_header header;
    uint64_t tstamp; // time
    // From here on corresponds to read_format (see man perf_event_open).
    // Note that the format of read_format is the same as the used for read
    // syscall.
    uint64_t nr; // Number of events.
    uint64_t time_enabled; // The time that the group has been enabled (ready to
                           // run and running).
    uint64_t time_running; // The time that the group has been running.
    uint64_t value[];

    Sample(const Sample&) = delete;
  };

  /// PERF_RECORD_AUX.
  using Aux = void;

  /// PERF_RECORD_ITRACE_START.
  using ItraceStart = void;

  /// PERF_RECORD_SWITCH_CPU_WIDE.
  using SwitchCpuWide = void;
};

inline std::ostream& operator<<(
    std::ostream& os,
    const struct Sampling::Read& r) {
  HBT_ARG_CHECK_EQ(r.header.type, PERF_RECORD_READ);
  os << "<READ ";
  os << " pid: " << r.pid;
  os << " tid: " << r.tid;
  os << " nr_events: " << r.nr;
  os << " time_enabled: " << r.time_enabled;
  os << " time_running: " << r.time_running;
  os << ">";
  return os;
}

/// Read values for all events in group.
/// Only enable it if Counting or Sampling modes.
template <class TMode, class T>
using enable_if_counting_or_sampling = std::enable_if_t<
    std::is_same_v<TMode, Counting> || std::is_same_v<TMode, Sampling>,
    T>;

inline std::ostream& operator<<(std::ostream& os, const Sampling::Sample& r) {
  HBT_ARG_CHECK_EQ(r.header.type, PERF_RECORD_SAMPLE);

  os << "<SAMPLE tstamp: " << r.tstamp << " mux" << r.time_running << "/"
     << r.time_enabled << " values: [";
  HBT_ARG_CHECK_GT(r.nr, 0);
  for (uint64_t i = 0; i < r.nr; ++i)
    os << " " << r.value[i];
  os << " ] >";
  return os;
}

/// Convenience function to estimate the number of bytes in a ringbuffer
/// sample record depending on the mode used.
template <class TRecord>
size_t recordSize(const TRecord& r) {
  if constexpr (std::is_same<TRecord, Sampling::Sample>::value) {
    // See init_perf_event_attrs.
    return sizeof(TRecord) + r.nr * sizeof(uint64_t);
  }
  if constexpr (std::is_same<TRecord, Sampling::Read>::value) {
    // See init_perf_event_attrs.
    return sizeof(TRecord) + r.nr * sizeof(uint64_t);
  } else {
    // See init_perf_event_attrs.
    return sizeof(TRecord);
  }
}

/// Convenience function to estimate the number of bytes in a read() syscall
/// depnding on the mode used.
template <class TMode>
size_t read_bytes_size(size_t num_events) {
  if constexpr (
      std::is_same_v<TMode, mode::Counting> ||
      std::is_same_v<TMode, mode::Sampling>) {
    // See init_perf_event_attrs.
    // PERF_FORMAT_GROUP | PERF_FORMAT_TOTAL_TIME_ENABLED |
    // PERF_FORMAT_TOTAL_TIME_RUNNING
    return sizeof(uint64_t) * (3 + num_events);
  } else {
    // Only nr of events.
    return sizeof(uint64_t) * 1;
  }
}

} // namespace mode

/// Structure to pass to ::read syscall when reading group events.
/// See `man perf_event_open` for details.
/// It contains a pointer to T in order to allow using flexible size arrays
/// and constructors/destructors. This way, GroupReadValues destructor
/// takes care of deallocating memory on t, without caller having to call
/// ::free.
template <class TMode>
struct GroupReadValues {
  // Struct populated by the kernel during read. Prefer to use get* methods.
  struct T {
    uint64_t n_events; // Number of events.
    uint64_t time_enabled; // The time that the group has been enabled (ready to
                           // run and running).
    uint64_t time_running; // The time that the group has been running.
    // Flexible size array, requires custom allocator. One count per event in
    // group.
    uint64_t count[];
  };
  // Prefer to use get*methods.
  T* t = nullptr;

  explicit GroupReadValues(size_t n_events) {
    HBT_ARG_CHECK_GT(n_events, 0);
    t = static_cast<T*>(::malloc(mode::read_bytes_size<TMode>(n_events)));
    // Do not use getNumEvents or getNumReadBytes because the object is not yet
    // initialized.
    ::memset(t, 0, mode::read_bytes_size<TMode>(n_events));
    t->n_events = n_events;
  }

  explicit GroupReadValues(const GroupReadValues& other)
      : GroupReadValues(other.getNumEvents()) {
    HBT_DCHECK_NOT_NULLPTR(other.t);
    HBT_DCHECK_NOT_NULLPTR(t);
    ::memcpy(t, other.t, other.getNumReadBytes());
  }

  GroupReadValues& operator=(const GroupReadValues& other) {
    HBT_DCHECK_NOT_NULLPTR(other.t);
    release_();
    new (this) GroupReadValues(other);
    return *this;
  }

  GroupReadValues(GroupReadValues&& other) noexcept
      : t(std::exchange(other.t, nullptr)) {
    HBT_DCHECK_NOT_NULLPTR(t);
  }

  GroupReadValues& operator=(GroupReadValues&& other) {
    release_();
    new (this) GroupReadValues(std::move(other));
    return *this;
  }

  size_t getNumEvents() const {
    return t->n_events;
  }

  size_t getNumReadBytes() const {
    return mode::read_bytes_size<TMode>(getNumEvents());
  }

  /// The time that the group of events has been enabled (running + ready to run
  /// but waiting for an available Hardware Performance Counter due to
  /// time-multiplexing).
  uint64_t getTimeEnabled() const {
    HBT_DCHECK_LE(t->time_running, t->time_enabled);
    return t->time_enabled;
  }

  /// The time that the group of events have been running in a Hardware
  /// Performance Counter.
  uint64_t getTimeRunning() const {
    HBT_DCHECK_LE(t->time_running, t->time_enabled);
    return t->time_running;
  }

  /// The actual count as repoted by the kernel.
  uint64_t getRawCount(size_t i) const {
    HBT_DCHECK_LE(t->time_running, t->time_enabled);
    HBT_ARG_CHECK_LT(i, getNumEvents()) << "Index out of range";
    return t->count[i];
  }

  /// The extrapolated count, taking into account time multiplexing.
  /// This is usually very accurate.
  uint64_t getCount(size_t i) const {
    HBT_DCHECK_LE(t->time_running, t->time_enabled);
    HBT_ARG_CHECK_LT(i, getNumEvents()) << "Index out of range";
    if (t->time_enabled == 0) {
      return 0;
    }

    return static_cast<uint64_t>(
        static_cast<double>(t->count[i]) *
        static_cast<double>(t->time_enabled) /
        static_cast<double>(t->time_running));
  }

  /// Actual counts reported by kernel as a std::vector.
  std::vector<uint64_t> getRawCounts() const {
    std::vector<uint64_t> v;
    v.reserve(t->n_events);
    v.assign(t->count, t->count + t->n_events);
    return v;
  }

  /// Extrapolated counts as a std::vector.
  std::vector<uint64_t> getCounts() const {
    std::vector<uint64_t> v;
    v.reserve(t->n_events);
    for (auto i = 0; i < t->n_events; ++i) {
      v.push_back(this->getCount(i));
    }
    return v;
  }

  /// The fraction of time enabled that this counter has been running.
  /// It can be less than one due to Hardware Performance Counter multiplexing.
  float getRunningRatio() const {
    HBT_DCHECK_LE(t->time_running, t->time_enabled);
    if (t->time_enabled == 0) {
      // If time_enabled is zero, we've captured all of
      return 1.0;
    }
    return (float)t->time_enabled / (float)t->time_running;
  }

  /// The fraction of time enabled that this counter has been running scaled
  /// by given <scale>. Useful to avoid floating point operations.
  /// Default scale of 100 provides percentages.
  template <size_t scale = 100>
  uint64_t getRunningRatioInteger() const {
    HBT_DCHECK_LE(t->time_running, t->time_enabled);
    if (t->time_enabled == 0) {
      // If time_enabled is zero, we've captured all of it.
      return scale;
    }
    return (scale * t->time_running) / t->time_enabled;
  }

  /// True if events group has been time-multiplexed by Linux kernel.
  bool hasMultiplexing() const {
    return t->time_enabled != 0 && t->time_running != t->time_enabled;
  }

  void zero() {
    auto n_events = t->n_events;
    ::memset(t, 0, getNumReadBytes());
    t->n_events = n_events;
  }

  void accum(const GroupReadValues& a) {
    HBT_DCHECK_LE(t->time_running, t->time_enabled);
    HBT_DCHECK_EQ(getNumEvents(), a.getNumEvents());
    t->time_enabled += a.t->time_enabled;
    t->time_running += a.t->time_running;
    for (auto i = 0u; i < getNumEvents(); ++i) {
      t->count[i] += a.t->count[i];
    }
  }

  ~GroupReadValues() {
    release_();
  }

 protected:
  void release_() {
    if (t != nullptr) {
      ::free(t);
      t = nullptr;
    }
  }
};

template <class TMode>
std::ostream& operator<<(std::ostream& os, const GroupReadValues<TMode>& gv) {
  return os << fmt::format(
             "<GroupReadValues n_events: {} time_enabled: {} ({}% running) raw_counts: {}>",
             gv.getNumEvents(),
             gv.getTimeEnabled(),
             gv.getRunningRatioInteger(),
             gv.getRawCounts());
}

static_assert(std::is_pod_v<GroupReadValues<mode::Counting>::T>);
static_assert(std::is_pod_v<GroupReadValues<mode::Sampling>::T>);

/// CRTP to eliminate record handling overhead.
///
/// Must implement a handleRecord* for each record type support in <TMode>.

template <class TImpl, class TMode_>
class CpuEventsGroupBase {
 public:
  using TMode = TMode_;

  static constexpr size_t kPerfEventAttrSize = sizeof(perf_event_attr);

  CpuEventsGroupBase(const CpuEventsGroupBase&) = delete;

  CpuEventsGroupBase(
      CpuId cpu,
      pid_t pid,
      int cgroup_fd,
      const EventConfs& confs);

  virtual ~CpuEventsGroupBase();

  void close();

  void enable();

  void disable();

  bool isEnabled() const {
    return enabled_;
  }

  bool isOpen() const {
    return event_fds_[0] >= 0;
  }

  const auto& getEventConfs() const noexcept {
    return confs_;
  }

  CpuId getCpu() const {
    return cpu_;
  }

  /// Read a value from file descriptors.
  /// Enable only for Counting and Sampling modes because only those modes
  /// use not Dummy events.
  template <class T = TMode>
  mode::enable_if_counting_or_sampling<T, bool> read(
      GroupReadValues<TMode>& rv) const {
    HBT_ARG_CHECK_EQ(rv.getNumEvents(), event_fds_.size())
        << "GroupReadValues of " << rv.getNumEvents() << " but have "
        << event_fds_.size();
    // Read group of events from the leader.
    auto ret = ::read(event_fds_[0], rv.t, rv.getNumReadBytes());
    if (ret > 0) {
      HBT_DCHECK_EQ(rv.getNumEvents(), event_fds_.size())
          << "Unexpected number of events read.";
      HBT_DCHECK_EQ(static_cast<size_t>(ret), rv.getNumReadBytes())
          << "Unexpected number of bytes read for " << rv.getNumEvents()
          << " events.";
      return static_cast<size_t>(ret) == rv.getNumReadBytes();
    }
    auto err_code = toErrorCode(errno);
    HBT_LOG_WARNING() << "Failed to read counter error " << err_code.message();
    return false;
  }

  static void init_perf_event_attrs(
      const EventConfs& confs,
      uint64_t sample_period,
      struct perf_event_attr* attrs,
      bool pinned);

 protected:
  const CpuId cpu_;
  const pid_t pid_;
  const int cgroup_fd_;
  EventConfs confs_;
  std::vector<int> event_fds_;
  struct perf_event_attr* attrs_ = nullptr;

  uint64_t sample_period_;
  bool pinned_;
  bool enabled_ = false;

  // CRTP cast to implementation class.
  TImpl& asImpl_() noexcept {
    return static_cast<TImpl&>(*this);
  }

  void open_counting_(uint64_t sampling_period, bool pinned);
  void closeEvents_();
};

/// CRTP to eliminate record handling overhead.
///
/// Must implement a handleRecord* for each record type support in <TMode>.

template <class TImpl, class TMode_>
class CpuEventsGroup : public CpuEventsGroupBase<TImpl, TMode_> {
 public:
  using TMode = TMode_;
  using TSampleId = typename TMode::sample_id_t;
  using TRecordLost = typename TMode::Lost;
  using TRecordComm_Lower = typename TMode::Comm_Lower;
  using TRecordExit = typename TMode::Exit;
  using TRecordFork = typename TMode::Fork;
  using TRecordRead = typename TMode::Read;
  using TRecordSample = typename TMode::Sample;
  using TRecordAux = typename TMode::Aux;
  using TRecordItraceStart = typename TMode::ItraceStart;
  using TRecordSwitchCpuWide = typename TMode::SwitchCpuWide;

  static constexpr size_t kPerfEventAttrSize = sizeof(perf_event_attr);

  CpuEventsGroup(const CpuEventsGroup&) = delete;

  using CpuEventsGroupBase<TImpl, TMode_>::CpuEventsGroupBase;

  virtual ~CpuEventsGroup() {}

  void close();

  /// Change perf_event sample period.
  void changeSamplePeriod(uint64_t new_sample_period);

  /// Will enlarge <aux_buffer_> if needed to fit <size> bytes.
  void* enlargeAuxBuffer(size_t size);

  ssize_t consume(unsigned max_num_records);

  /// Pass the pointers denoting the CPU's perf_event data ring buffer to
  /// `callback`. If consume == True, then update data_tail to mark copied data
  /// as consumed.
  void onCpuDataBufferRead(OnRbReadCallback callback, bool consume);

  //
  // Stats related methods.
  //
  size_t usedSizeWeak() const noexcept {
    auto mmap_header =
        static_cast<volatile struct perf_event_mmap_page*>(mmap_base_);
    HBT_DCHECK_GE(mmap_header->data_head, mmap_header->data_tail);
    return mmap_header->data_head - mmap_header->data_tail;
  }

  size_t bufferSize() const noexcept {
    auto mmap_header =
        static_cast<volatile struct perf_event_mmap_page*>(mmap_base_);
    return mmap_header->data_size;
  }

  size_t auxSpaceSize() const noexcept {
    auto mmap_header =
        static_cast<volatile struct perf_event_mmap_page*>(mmap_base_);
    return mmap_header->aux_size;
  }

  void* auxSpaceBase() const noexcept {
    return aux_base_;
  }

  size_t auxSpaceHeadWeak() const noexcept {
    auto mmap_header =
        static_cast<volatile struct perf_event_mmap_page*>(mmap_base_);
    return mmap_header->aux_head;
  }

  // XXX: Use enableIf to hide some of these if the implementation doesn't
  // collect it.
  uint64_t getNumRecordLost() const noexcept {
    return num_record_lost_;
  }
  uint64_t getNumRecordComm() const noexcept {
    return num_record_comm_;
  }
  uint64_t getNumRecordExit() const noexcept {
    return num_record_exit_;
  }
  uint64_t getNumRecordThrottle() const noexcept {
    return num_record_throttle_;
  }
  uint64_t getNumRecordUnThrottle() const noexcept {
    return num_record_unthrottle_;
  }
  uint64_t getNumRecordFork() const noexcept {
    return num_record_fork_;
  }
  uint64_t getNumRecordSample() const noexcept {
    return num_record_sample_;
  }
  uint64_t getNumRecordRead() const noexcept {
    return num_record_read_;
  }
  uint64_t getNumRecordAux() const noexcept {
    return num_record_aux_;
  }
  uint64_t getNumRecordItraceStart() const noexcept {
    return num_record_itrace_start_;
  }
  uint64_t getNumRecordSwitchCpuWide() const noexcept {
    return num_record_switch_cpu_wide_;
  }

  // Add together all thread related events.
  uint64_t getNumRecordThreadSched() const noexcept {
    return getNumRecordFork() + getNumRecordExit() +
        getNumRecordSwitchCpuWide();
  }

  uint64_t kernelTimeFromTsc(uint64_t tsc_cycles) const;

  uint64_t tscFromKernelTime(uint64_t ktime) const;

  std::optional<TscConversionParams> readTscConversionParams() const {
    if (mmap_base_ == nullptr) {
      return std::nullopt;
    }

    auto mmap_header =
        static_cast<volatile struct perf_event_mmap_page*>(mmap_base_);

    return TscConversionParams{
        .time_shift = mmap_header->time_shift,
        .time_mult = mmap_header->time_mult,
        .time_zero = mmap_header->time_zero};
  }

#if defined(__i386__) || defined(__x86_64__)
  inline TimeStamp read_tsc() const noexcept {
    return __rdtsc();
  }

#elif defined(__aarch64__)
  inline TimeStamp read_tsc() const noexcept {
    TimeStamp tstamp;
    asm volatile("mrs %0, cntvct_el0" : "=r"(tstamp));
    return tstamp;
  }
#endif

  TimeStamp now() const {
    return kernelTimeFromTsc(read_tsc());
  }

  /// Build a TimeStampNsConverter to convert between TSC and kernel time
  /// timestamps.
  /// Useful to release MonData objects in Monitor.
  auto buildTimeStampNsConverter() const {
    HBT_DCHECK(this->isOpen());
    // Similar to <now>.
    return TimeStampNsConverter::makeFromNow([this]() { return this->now(); });
  }

 protected:
  // Number of pages in buffer to store samples (do not include header), always
  // power of 2.
  size_t num_data_pages_;
  // AUX space is a separated memory area to be used by hardware blocks that
  // will generate a high bandwidth of data stream, such as intel pt. always
  // power of 2.
  size_t num_aux_pages_;
  size_t page_size_;
  void* mmap_base_ = nullptr;
  void* aux_base_ = nullptr;

  // helper buffer to read when mmap_base wraps.
  struct {
    void* base = nullptr;
    size_t size = 0;
  } aux_buffer_;

  uint64_t num_record_lost_ = 0;
  uint64_t num_record_comm_ = 0;
  uint64_t num_record_exit_ = 0;
  uint64_t num_record_throttle_ = 0;
  uint64_t num_record_unthrottle_ = 0;
  uint64_t num_record_fork_ = 0;
  uint64_t num_record_sample_ = 0;
  uint64_t num_record_read_ = 0;
  uint64_t num_record_aux_ = 0;
  uint64_t num_record_itrace_start_ = 0;
  uint64_t num_record_switch_cpu_wide_ = 0;

  // Auxiliary value to use in TSC -> timestamp conversion.
  uint64_t tsc_rem_flags_;

  void open_(
      size_t num_data_pages,
      uint64_t sampling_period,
      bool pinned,
      size_t num_aux_pages);
  int mmap_(int fd);
};

inline uint64_t readDataHead(
    volatile struct perf_event_mmap_page* mmap_header) noexcept {
  uint64_t data_head = mmap_header->data_head;
  asm volatile("" ::: "memory");
  return data_head;
}

inline void writeDataTail(
    volatile struct perf_event_mmap_page* mmap_header,
    uint64_t data_tail) noexcept {
  asm volatile("" ::: "memory");
  mmap_header->data_tail = data_tail;
}

template <class TImpl, class TMode>
CpuEventsGroupBase<TImpl, TMode>::CpuEventsGroupBase(
    CpuId cpu,
    pid_t pid,
    int cgroup_fd,
    const EventConfs& confs)
    : cpu_{cpu}, pid_{pid}, cgroup_fd_{cgroup_fd}, confs_{confs} {
  HBT_ARG_CHECK_GE(cpu_, 0);
  HBT_ARG_CHECK_LT(cpu_, kMaxCpus);
  HBT_ARG_CHECK_GE(confs_.size(), 1);
  HBT_ARG_CHECK_FALSE(pid >= 0 && cgroup_fd >= 0);
  event_fds_.resize(confs.size(), -1);
}

template <class TImpl, class TMode>
CpuEventsGroupBase<TImpl, TMode>::~CpuEventsGroupBase() {
  if (isOpen()) {
    close();
  }
}

template <class TImpl, class TMode>
void CpuEventsGroupBase<TImpl, TMode>::init_perf_event_attrs(
    const EventConfs& confs,
    uint64_t sample_period,
    struct perf_event_attr* attrs,
    bool pinned) {
  if constexpr (std::is_same_v<TMode, mode::Counting>) {
    HBT_ARG_CHECK_EQ(sample_period, 0)
        << "sample_period != 0 does not make sense in counting mode";
  }

  // Leader event is at position zero in the attrs array.
  // It is special because is the only one configured
  // to generate samples and its record will contain counts
  // of all other events, reducing the overhead of using multiple events.
  attrs[0].sample_period = sample_period;
  attrs[0].sample_type = PERF_SAMPLE_TIME;

  if constexpr (std::is_same_v<TMode, mode::ContextSwitch>) {
    // Context Switches mode opens side-band events for ctxt switch and comm.
    attrs[0].task = 1;
    attrs[0].sample_type |= PERF_SAMPLE_TID;
    attrs[0].sample_id_all = 1;
    attrs[0].context_switch = 1;
    attrs[0].comm = 1;
    attrs[0].comm_exec = 1;
  } else if constexpr (std::is_same_v<TMode, mode::Sampling>) {
    // Sampling.
    attrs[0].sample_type |= PERF_SAMPLE_READ;
    // Record counts of all events in group in leader's PERF_RECORD_SAMPLE.
    attrs[0].read_format =
        (PERF_FORMAT_GROUP | PERF_FORMAT_TOTAL_TIME_ENABLED |
         PERF_FORMAT_TOTAL_TIME_RUNNING);
  } else if constexpr (std::is_same_v<TMode, mode::Counting>) {
    // Counting mode assumes this structure (See GroupReadValues) and
    // is the same and Sampling mode.
    attrs[0].read_format =
        (PERF_FORMAT_GROUP | PERF_FORMAT_TOTAL_TIME_ENABLED |
         PERF_FORMAT_TOTAL_TIME_RUNNING);
  } else {
    // Dummy mode. Intentionally left empty.
  }

  // HBT_LOG_INFO() << "Opening group sample_period: " << sample_period_
  //  << " num_data_pages: " << num_data_pages_;

  // Don't start until explicitly started.
  attrs[0].disabled = 1;
  attrs[0].pinned = pinned;

  for (size_t i = 0; i < confs.size(); ++i) {
    // HBT_LOG_INFO() << "Opening event: " << confs_[i];
    attrs[i].size = kPerfEventAttrSize;
    attrs[i].type = confs[i].configs.type;
    attrs[i].config = confs[i].configs.config;
    attrs[i].config1 = confs[i].configs.config1;
    attrs[i].config2 = confs[i].configs.config2;
    attrs[i].exclude_user = confs[i].extra_attr.exclude_user;
    attrs[i].exclude_kernel = confs[i].extra_attr.exclude_kernel;
    attrs[i].exclude_hv = confs[i].extra_attr.exclude_hv;
    attrs[i].exclude_idle = confs[i].extra_attr.exclude_idle;
    attrs[i].exclude_host = confs[i].extra_attr.exclude_host;
    attrs[i].exclude_guest = confs[i].extra_attr.exclude_guest;
    static_assert(
        std::is_same_v<std::underlying_type<PreciseIpLevel>::type, uint8_t>);
    attrs[i].precise_ip = static_cast<uint8_t>(confs[i].extra_attr.precise_ip);

    // HBT_LOG_INFO() << "Event " << i << " " << confs[i];
  }
}

///
/// Opens an event group in counting mode.
///
/// Note that even if sample_period == 0, there may be auxiliary events produced
/// to perf_event buffer.
/// Support Dummy events that have 0 pages, useful to expose perf_event's
/// head page info, such as clocks.
///
template <class TImpl, class TMode>
void CpuEventsGroupBase<TImpl, TMode>::open_counting_(
    uint64_t sample_period,
    bool pinned) {
  HBT_THROW_ASSERT_IF(attrs_ != nullptr) << "Events already opened";
  if constexpr (std::is_same_v<TMode, mode::Counting>) {
    HBT_ARG_CHECK_EQ(sample_period, 0)
        << "sample_period != 0 does not make sense in counting mode";
  }

  pinned_ = pinned;
  sample_period_ = sample_period;

  attrs_ = static_cast<struct perf_event_attr*>(
      calloc(confs_.size(), kPerfEventAttrSize));
  HBT_THROW_ASSERT_IF(attrs_ == nullptr)
      << "unable to allocate perf_event_attr array";

  init_perf_event_attrs(confs_, sample_period_, attrs_, pinned_);

  unsigned long flags = cgroup_fd_ >= 0 ? PERF_FLAG_PID_CGROUP : 0;
  for (size_t i = 0; i < confs_.size(); ++i) {
    // Non-leader events must pass leader's fd.
    int leader_fd = (i == 0) ? -1 : event_fds_[0];
    // There is no glibc wrapper for perf_event_open and the generic syscall
    // returns a long.
    event_fds_[i] = static_cast<int>(::syscall(
        __NR_perf_event_open,
        &attrs_[i],
        cgroup_fd_ >= 0 ? cgroup_fd_ : pid_,
        cpu_,
        leader_fd,
        flags));
    // HBT_LOG_INFO() << "Call to perf_event_open with cpu: " << cpu_
    //          << " leader_fd: " << leader_fd << " returned: " <<
    //          event_fds_[i];
    if (0 > event_fds_[i]) {
      auto failed_idx = i;
      int err = errno;
      // close opened events.
      while (i > 0) {
        ::close(event_fds_[--i]);
        event_fds_[i] = -1;
      }

      free(attrs_);
      attrs_ = nullptr;

      std::ostringstream oss;
      // Handle known errors.
      if (err == EACCES || err == EPERM) {
        oss << "User has no permission to open CPU event as requested. "
               "Do you want to run \"echo -1 > /proc/sys/kernel/perf_event_paranoid\" ? "
               "Or perhaps give CAP_SYS_ADMIN or CAP_PERFMON "
               "to user \""
            << ::getlogin() << "\" ?";
        HBT_THROW_ENVIRONMENT(EnvironmentError::Type::MissingPerfEventCaps)
            << oss.str();
      } else if (err == EOPNOTSUPP) {
        oss << "Unsupported hardware feature.";
        HBT_LOG_WARNING() << oss.str();
        HBT_THROW_SYSTEM(err) << oss.str();
      } else if (err == EINVAL) {
        oss << "Invalid " << (pinned_ ? "pinned " : "") << "event at index "
            << failed_idx << " with config: " << confs_[failed_idx] << std::dec;
        if (pinned_) {
          oss << "\nEvent group was created as pinned. "
                 "Are there enough available Performance Counters?";
        }
        oss << ".\nIt also may be due an invalid CPU ID. "
               "Or an invalid combination of events. CPU requested: "
            << cpu_ << ".\nSee man perf_event_open for other possible causes.";
        HBT_LOG_WARNING() << oss.str();
        HBT_THROW_SYSTEM(err) << oss.str();
      } else {
        auto err_code = toErrorCode(err);
        oss << "Unrecognized error while opening event[" << failed_idx << "] \""
            << confs_[failed_idx].id << "\" with leader_fd: " << leader_fd
            << " and pid: " << pid_ << " and cgroup_fd: " << cgroup_fd_;
        HBT_LOG_WARNING() << oss.str() << ". Error: " << err_code.message();
        HBT_THROW_SYSTEM_CODE(err_code) << oss.str();
      }
    }
  }
}

///
/// Opens an event group.
///
/// Note that even if sample_period == 0, there may be auxiliary events produced
/// to perf_event buffer.
/// Support Dummy events that have 0 pages, useful to expose perf_event's
/// head page info, such as clocks.
///
template <class TImpl, class TMode>
void CpuEventsGroup<TImpl, TMode>::open_(
    size_t num_data_pages,
    uint64_t sample_period,
    bool pinned,
    size_t num_aux_pages) {
  HBT_THROW_ASSERT_IF((std::is_same_v<TMode, mode::Counting>));
  HBT_THROW_ASSERT_IF(this->attrs_ != nullptr) << "Events already opened";

  // num_data_pages == 0 is useful for dummy events that only want to
  // access to perf_event ringbuffer header information, or only want
  // to access to aux space.
  HBT_ARG_CHECK(num_data_pages == 0 || isPow2(num_data_pages))
      << "Number of data pages must be a power of 2, got: " << num_data_pages;
  HBT_ARG_CHECK(num_aux_pages == 0 || isPow2(num_aux_pages))
      << "Number of aux pages must be a power of 2, got: " << num_aux_pages;
  num_data_pages_ = num_data_pages;
  num_aux_pages_ = num_aux_pages;

  this->open_counting_(sample_period, pinned);

  {
    int page_size = ::getpagesize();
    HBT_THROW_ASSERT_IF(page_size == 0);
    HBT_THROW_ASSERT_IF(page_size != 4 * 1024)
        << "Currently only supports 4 KB pages";
    page_size_ = static_cast<size_t>(page_size);
    HBT_DCHECK(isPow2(page_size_));
  }

  // Only map page to leader since it is the only one generating samples.
  if (int err = mmap_(this->event_fds_[0]); 0 > err) {
    int fd = this->event_fds_[0];
    this->closeEvents_();

    if (-err == EACCES || -err == EPERM) {
      HBT_THROW_ENVIRONMENT(EnvironmentError::Type::MissingPerfEventCaps)
          << "User has no permission to mmap perf_event memory page. "
          << "Do you want to run \"echo -1 > /proc/sys/kernel/perf_event_paranoid\" ? "
          << "Or perhaps give CAP_SYS_ADMIN to user \"" << ::getlogin()
          << "\" ?";
    } else if (-err == ENOMEM) {
      HBT_THROW_ENVIRONMENT(EnvironmentError::Type::NoMemory)
          << "mmap failed as system doesn't have enough memory under quota. "
          << "If memory usage is less than the physical limit, then it's likely "
          << "capped by kernel's resource limit. Try setrlimit(2)?";
    } else {
      HBT_THROW_SYSTEM(-err)
          << "mmap for perf_event at fd " << fd
          << " failed. Is perf_event_paranoid set at the right level?";
    }
  }

  // HBT_LOG_INFO() << "Opened " << confs_.size() << " events at CPU " << cpu_;
}

template <class TImpl, class TMode>
int CpuEventsGroup<TImpl, TMode>::mmap_(int fd) {
  HBT_DCHECK_GT(fd, 0);
  // Mmap sampling buffer for leader event.
  size_t mmap_size = page_size_ * (1 + num_data_pages_);
  // XXX: Try to use Huge Pages.
  void* base =
      ::mmap(NULL, mmap_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
  // HBT_LOG_INFO() << "Mmap perf_event buffer with " << num_data_pages_
  //               << " data pages and total size of " << mmap_size << " bytes";
  if (base == MAP_FAILED) {
    return -errno;
  }
  mmap_base_ = base;

  // Verify capability assumptions and update auxiliary variables.
  //
  // Note that the need for cap_user_time_zero is what prevents us from using
  // CLOCK_MONOTONIC_RAW
  auto mmap_header =
      static_cast<volatile struct perf_event_mmap_page*>(mmap_base_);

  HBT_THROW_ASSERT_IF(!mmap_header->cap_user_time_zero)
      << "cap_user_time_zero not supported. TSC cannot be converted to timestamp.";

  HBT_THROW_ASSERT_IF(!mmap_header->cap_user_time)
      << "cap_user_time not supported. rdpmc cannot be used as timer.";

  // HBT_LOG_INFO() << "Mmap'ed page with timer capabilities: \n"
  //               << "\tcap_user_time_zero: " <<
  //               mmap_header->cap_user_time_zero
  //               << "\tcap_user_time: " << mmap_header->cap_user_time
  //               << "\tcap_user_rdpmc: " << mmap_header->cap_user_rdpmc
  //               << "\ttime_zero: " << mmap_header->time_zero
  //               << "\ttime_mult: " << mmap_header->time_mult
  //               << "\ttime_shift: " << mmap_header->time_shift;

  tsc_rem_flags_ = ((((uint64_t)1) << mmap_header->time_shift) - 1);

  // mmap AUX space
  if (num_aux_pages_ > 0) {
    mmap_size = page_size_ * num_aux_pages_;
    mmap_header->aux_offset = mmap_header->data_offset + mmap_header->data_size;
    mmap_header->aux_size = mmap_header->data_size = mmap_size;
    base = ::mmap(
        mmap_base_,
        mmap_header->aux_size,
        PROT_READ,
        MAP_SHARED,
        fd,
        (long)mmap_header->aux_offset);
    if (base == MAP_FAILED) {
      return -errno;
    }
    aux_base_ = base;
  }
  return 0;
}

template <class TImpl, class TMode>
void CpuEventsGroupBase<TImpl, TMode>::closeEvents_() {
  HBT_THROW_ASSERT_IF(!isOpen());

  // Reverse order to delete leader last.
  HBT_DCHECK_GT(event_fds_.size(), 0);
  auto r = event_fds_.size();
  while (r > 0) {
    --r;
    if (event_fds_[r] != 1) {
      if (int ret = ::close(event_fds_[r]); 0 > ret) {
        HBT_LOG_ERROR() << "Error \"" << toErrorCode(errno).message()
                        << "\" while closing event fd ";
      }
      event_fds_[r] = -1;
    }
  }
}

template <class TImpl, class TMode>
void CpuEventsGroupBase<TImpl, TMode>::close() {
  if (!isOpen()) {
    return;
  }
  disable();
  closeEvents_();
  free(attrs_);
  attrs_ = nullptr;
}

template <class TImpl, class TMode>
void CpuEventsGroup<TImpl, TMode>::close() {
  if (!this->isOpen()) {
    return;
  }

  this->disable();

  size_t mmap_size;
  int ret;
  auto mmap_header =
      static_cast<volatile struct perf_event_mmap_page*>(mmap_base_);
  if (aux_base_) {
    ret = ::munmap(aux_base_, mmap_header->aux_size);
    HBT_LOG_ERROR_IF(0 > ret)
        << "munmap aux_base_ error: " << toErrorCode(errno).message()
        << " address: " << aux_base_ << " len: " << mmap_header->aux_size;
  }
  aux_base_ = nullptr;
  mmap_size = page_size_ * (1 + num_data_pages_);
  ret = ::munmap((void*)mmap_base_, mmap_size);
  HBT_LOG_ERROR_IF(0 > ret)
      << "munmap mmap_base_ error: " << toErrorCode(errno).message()
      << " address: " << mmap_base_ << " len: " << mmap_size;
  mmap_base_ = nullptr;

  num_data_pages_ = 0;
  num_aux_pages_ = 0;
  page_size_ = 0;

  this->closeEvents_();

  if (aux_buffer_.base) {
    free(aux_buffer_.base);
    aux_buffer_.base = nullptr;
    aux_buffer_.size = 0;
  }

  free(this->attrs_);
  this->attrs_ = nullptr;
}

template <class TImpl, class TMode>
void CpuEventsGroupBase<TImpl, TMode>::enable() {
  HBT_ARG_CHECK(isOpen()) << "Cannot enable events that are not open";

  if (enabled_) {
    HBT_LOG_WARNING() << "Enabling already enabled event";
    return;
  }

  if (int ret = ::ioctl(event_fds_[0], PERF_EVENT_IOC_RESET, 0); 0 > ret) {
    HBT_THROW_SYSTEM(errno) << "ioctl PERF_EVENT_IOC_RESET";
  }
  if (int ret = ::ioctl(event_fds_[0], PERF_EVENT_IOC_ENABLE, 0); 0 > ret) {
    HBT_THROW_SYSTEM(errno) << "ioctl PERF_EVENT_IOC_ENABLE";
  }

  if (pinned_) {
    void* buff = ::malloc(mode::read_bytes_size<TMode>(event_fds_.size()));
    ssize_t ret = ::read(
        event_fds_[0], buff, mode::read_bytes_size<TMode>(event_fds_.size()));
    ::free(buff);
    // Per perf_event_open doc, pinned events return 0 when there are no PMCs
    // available.
    if (ret == 0) {
      HBT_THROW_ASSERT()
          << "Pinned event could not be scheduled in CPU " << cpu_
          << ", possibly due to not enough Hardware Performance Counters available. "
          << "Are other processes using counters in monitored CPUs?"
          << " If running in a test suite, make sure that tests that open "
          << "events in the same CPUs do not run concurrently because the "
          << "number of HW counters in each CPU is limited.";
    } else if (0 > ret) {
      HBT_THROW_SYSTEM(errno)
          << "Failed to validate enabled perf_event. Ret: " << ret
          << " Num events: " << event_fds_.size()
          << " Size: " << mode::read_bytes_size<TMode>(event_fds_.size());
    }
  }
  enabled_ = true;
  asImpl_().enableImpl();
}

template <class TImpl, class TMode>
void CpuEventsGroupBase<TImpl, TMode>::disable() {
  HBT_ARG_CHECK(isOpen()) << "Cannot disable events that are not open";

  if (!enabled_)
    return;

  if (int ret = ::ioctl(event_fds_[0], PERF_EVENT_IOC_DISABLE, 0); 0 > ret) {
    HBT_THROW_SYSTEM(errno) << "ioctl PERF_EVENT_IOC_DISABLE";
  }
  enabled_ = false;
  asImpl_().disableImpl();
}

template <class TImpl, class TMode>
void CpuEventsGroup<TImpl, TMode>::changeSamplePeriod(
    uint64_t new_sample_period) {
  if (this->sample_period_ == new_sample_period)
    return;
  this->sample_period_ = new_sample_period;
  if (int ret = ::ioctl(
          this->event_fds_[0], PERF_EVENT_IOC_PERIOD, &this->sample_period_);
      0 > ret) {
    HBT_THROW_SYSTEM(errno) << "ioctl PERF_EVENT_IOC_PERIOD failed";
  }
}

template <class TImpl, class TMode>
void* CpuEventsGroup<TImpl, TMode>::enlargeAuxBuffer(size_t size) {
  if (aux_buffer_.size < size) {
    aux_buffer_.base = ::realloc(aux_buffer_.base, size);
    aux_buffer_.size = size;
  }
  return aux_buffer_.base;
}

///
/// If Implementation cannot consume a sample, then loop terminates. These
/// creates backpressure in the perf_event buffer because its data tail does not
/// make forward progress.
///
/// Will try up to collect <max_num_records> and return the number
/// of actually collected events. If an error, it will return a
/// negative value with error number.
template <class TImpl, class TMode>
ssize_t CpuEventsGroup<TImpl, TMode>::consume(unsigned max_num_records) {
  HBT_ARG_CHECK(this->isOpen())
      << "CpuEventsGroup must be open for events to be consumed "
      << " (event fd must be valid). Did you mean to only disable it?";

  ssize_t err = 0;
  unsigned num_records = 0;

  auto mmap_header =
      static_cast<volatile struct perf_event_mmap_page*>(mmap_base_);

  // Stop at <data_head> even if more data come while processing.
  const uint64_t data_head = readDataHead(mmap_header);
  uint64_t data_tail = mmap_header->data_tail;
  const uint64_t data_size = mmap_header->data_size;
  if (data_size == 0) {
    return 0;
  }
  HBT_DCHECK(isPow2(data_size));
  const uint64_t data_offset_mask = data_size - 1;

  while (data_tail < data_head && num_records < max_num_records) {
    auto data_start =
        static_cast<const uint8_t*>(mmap_base_) + mmap_header->data_offset;

    auto record_begin = data_start + (data_tail & data_offset_mask);
    // event header is u64, won't wrap.
    auto event_header =
        reinterpret_cast<const struct perf_event_header*>(record_begin);
    auto record_end =
        data_start + ((data_tail + event_header->size) & data_offset_mask);
    if (unlikely(record_end < record_begin)) {
      // perf event is wrapped around the ring buffer, make a contiguous copy.
      void* buffer = enlargeAuxBuffer(event_header->size);
      const uint8_t* sentinel = data_start + data_size;
      // We know sentinel >= record_begin.
      size_t len = static_cast<size_t>(sentinel - record_begin);
      ::memcpy(buffer, record_begin, len);
      ::memcpy(
          (void*)((unsigned long)buffer + len),
          data_start,
          event_header->size - len);
      event_header = static_cast<decltype(event_header)>(buffer);
    }

    switch (event_header->type) {
      case PERF_RECORD_LOST: {
        if constexpr (!std::is_void<TRecordLost>::value) {
          auto r = reinterpret_cast<const TRecordLost*>(event_header);
          HBT_DCHECK_EQ(r->header.size, recordSize(*r));
          err = this->asImpl_().handleRecordLost(*r);
          if (unlikely(0 > err)) {
            goto exit;
          }
          num_record_lost_ += r->num_lost;
        }
      } break;
      case PERF_RECORD_COMM: {
        if constexpr (!std::is_void<TRecordComm_Lower>::value) {
          auto r = reinterpret_cast<const TRecordComm_Lower*>(event_header);
          constexpr size_t non_name_size =
              sizeof(TRecordComm_Lower) + sizeof(TSampleId);
          HBT_DCHECK_GE(r->header.size, non_name_size);
          auto name_len =
              static_cast<const size_t>(r->header.size - non_name_size);
          auto sample_id_ptr =
              reinterpret_cast<const TSampleId*>(r->comm + name_len);
          err = this->asImpl_().handleRecordComm(*r, name_len, sample_id_ptr);
          ++num_record_comm_;
        }
      } break;
      case PERF_RECORD_EXIT: {
        if constexpr (!std::is_void<TRecordExit>::value) {
          auto r = reinterpret_cast<const TRecordExit*>(event_header);
          HBT_DCHECK_EQ(r->header.size, recordSize(*r));
          err = this->asImpl_().handleRecordExit(*r);
          if (unlikely(0 > err)) {
            goto exit;
          }
          ++num_record_exit_;
        }
      } break;
      case PERF_RECORD_THROTTLE:
        HBT_LOG_WARNING()
            << "Record throttling. Is sample_period too small? "
            << "Need to change /proc/sys/kernel/perf_event_max_sample_rate?";
        ++num_record_throttle_;
        break;
      case PERF_RECORD_UNTHROTTLE:
        HBT_LOG_WARNING()
            << "Record unthrottling. Is sample_period too small? "
            << "Need to change /proc/sys/kernel/perf_event_max_sample_rate?";
        ++num_record_unthrottle_;
        break;
      case PERF_RECORD_FORK: {
        if constexpr (!std::is_void<TRecordFork>::value) {
          auto r = reinterpret_cast<const TRecordFork*>(event_header);
          HBT_DCHECK_EQ(r->header.size, recordSize(*r));
          err = this->asImpl_().handleRecordFork(*r);
          if (unlikely(0 > err)) {
            goto exit;
          }
          ++num_record_fork_;
        }
      } break;
      case PERF_RECORD_SAMPLE: {
        if constexpr (!std::is_void<TRecordSample>::value) {
          auto r = reinterpret_cast<const TRecordSample*>(event_header);
          if (unlikely(r->header.size != recordSize(*r))) {
            HBT_LOG_ERROR() << "Invalid record size of: " << r->header.size
                            << " expected " << recordSize(*r);
            err = -EPERM;
            goto exit;
          }
          err = this->asImpl_().handleRecordSample(*r);
          if (unlikely(0 > err)) {
            goto exit;
          }
          ++num_record_sample_;
        }
      } break;
      case PERF_RECORD_READ: {
        if constexpr (!std::is_void<TRecordRead>::value) {
          auto r = reinterpret_cast<const TRecordRead*>(event_header);
          if (unlikely(r->header.size != recordSize(*r))) {
            HBT_LOG_ERROR() << "Invalid record read size of: " << r->header.size
                            << " expected " << recordSize(*r);
            err = -EPERM;
            goto exit;
          }
          err = this->asImpl_().handleRecordRead(*r);
          if (unlikely(0 > err)) {
            goto exit;
          }
          ++num_record_read_;
        }
      } break;
      case PERF_RECORD_AUX: {
        if constexpr (!std::is_void<TRecordAux>::value) {
          auto r = reinterpret_cast<const TRecordAux*>(event_header);
          HBT_DCHECK_EQ(r->header.size, recordSize(*r));
          err = this->asImpl_().handleRecordAux(*r);
          if (unlikely(0 > err)) {
            goto exit;
          }
          ++num_record_aux_;
        }
      } break;
      case PERF_RECORD_ITRACE_START: {
        if constexpr (!std::is_void<TRecordItraceStart>::value) {
          auto r = reinterpret_cast<const TRecordItraceStart*>(event_header);
          HBT_DCHECK_EQ(r->header.size, recordSize(*r));
          err = this->asImpl_().handleRecordItraceStart(*r);
          if (unlikely(0 > err)) {
            goto exit;
          }
          ++num_record_itrace_start_;
        }
      } break;
      case PERF_RECORD_SWITCH_CPU_WIDE: {
        if constexpr (!std::is_void<TRecordSwitchCpuWide>::value) {
          auto r = reinterpret_cast<const TRecordSwitchCpuWide*>(event_header);
          HBT_DCHECK_EQ(r->header.size, recordSize(*r));
          err = this->asImpl_().handleRecordSwitchCpuWide(*r);
          if (unlikely(0 > err)) {
            goto exit;
          }
          ++num_record_switch_cpu_wide_;
        }
      } break;

      default:
        HBT_LOG_ERROR() << "Unknown record type:" << event_header->type
                        << std::endl;
    }
    ++num_records;
    data_tail += event_header->size;
    HBT_DCHECK_LE(data_tail, data_head);
  }
  HBT_DCHECK_GE(err, 0);
  if (data_tail == data_head && num_records < max_num_records) {
    err = -ENODATA;
  }

exit:
  HBT_DCHECK_GE(max_num_records, num_records);
  // HBT_LOG_INFO() << "CpuEventsGroup::consume err: " << err
  //    << " data_head: " << data_head << " data_tail: " << data_tail
  //    << " num_records: " << num_records
  //    << " max_num_records: " << max_num_records;

  // Updates tail after loop have finished to avoid unnecessary contention with
  // kernel.
  writeDataTail(mmap_header, data_tail);
  return err >= 0 ? num_records : err;
}

template <class TImpl, class TMode>
void CpuEventsGroup<TImpl, TMode>::onCpuDataBufferRead(
    OnRbReadCallback callback,
    bool consume) {
  HBT_ARG_CHECK(this->isOpen())
      << "CpuEventsGroup must be open for events to be consumed "
      << " (event fd must be valid). Did you mean to only disable it?";

  auto mmap_header =
      static_cast<volatile struct perf_event_mmap_page*>(mmap_base_);

  // Stop at <data_head> even if more data come while processing.
  const uint64_t data_head = readDataHead(mmap_header);
  const uint64_t data_tail = mmap_header->data_tail;
  const uint64_t data_size = mmap_header->data_size;
  HBT_DCHECK(isPow2(data_size));
  const auto rb_num_bytes = static_cast<size_t>(data_head - data_tail);

  const uint64_t data_offset_mask = data_size - 1;

  const auto data_start =
      static_cast<const uint8_t*>(mmap_base_) + mmap_header->data_offset;

  const auto begin_ptr = data_start + (data_tail & data_offset_mask);
  const auto end_ptr = data_start + (data_head & data_offset_mask);
  // Pointer to end of circular ringbuffer,
  // to serve as sentinel of end of ringbuffer.
  const uint8_t* sentinel = data_start + data_size;

  // Write contiguous slices starting at begin_ptr, will stop at head or at
  // sentinel.
  size_t len =
      std::min(rb_num_bytes, static_cast<size_t>(sentinel - begin_ptr));
  CpuId cpuId = this->getCpu();

  if (unlikely(end_ptr < begin_ptr)) {
    // Ring buffer wrapped, so there are two slices
    callback(cpuId, RbDataSlices(begin_ptr, len, data_start, data_size - len));
  } else {
    // Ring buffer hasn't wrapped, so there's only one slice
    callback(cpuId, RbDataSlices(begin_ptr, len));
  }
  if (consume) {
    // Update mmap's tail to indicate kernel that data has been consumed.
    writeDataTail(mmap_header, data_head);
  }
}

// perf_event samples use kernel time.
// The following methods are helpers to convert to/from tsc into kernel time,
// as described in man 2 perf_event_open .

/// Convert TSC to kernel time (reference bus-cycles to nanoseconds since boot).
template <class TImpl, class TMode>
uint64_t CpuEventsGroup<TImpl, TMode>::kernelTimeFromTsc(
    uint64_t tsc_cycles) const {
  HBT_DCHECK(mmap_base_ != nullptr)
      << "Cannot call kernelTimeFromTsc in closed CpuEventsGroup "
      << "because perf_event mmap page is not available";
  auto mmap_header =
      static_cast<volatile struct perf_event_mmap_page*>(mmap_base_);

  uint64_t quot = tsc_cycles >> mmap_header->time_shift;
  uint64_t rem = tsc_cycles & tsc_rem_flags_;
  uint64_t ts = mmap_header->time_zero + quot * mmap_header->time_mult +
      ((rem * mmap_header->time_mult) >> mmap_header->time_shift);
  return ts;
}

/// Convert kernel time to TSC (nanoseconds since boot to reference bus-cycles).
template <class TImpl, class TMode>
uint64_t CpuEventsGroup<TImpl, TMode>::tscFromKernelTime(uint64_t ktime) const {
  HBT_THROW_ASSERT_IF(mmap_base_ == nullptr)
      << "Cannot call tscFromKernelTimec in closed CpuEventsGroup "
         "because perf_event mmap page is not available";

  // XXX: It's likely that time_mult is usually a hardware division friendly
  // constant. If that's the case, this could be templated to get a faster
  // division and modulo.
  auto mmap_header =
      static_cast<volatile struct perf_event_mmap_page*>(mmap_base_);
  uint64_t delta = ktime - mmap_header->time_zero;
  uint64_t quot = delta / mmap_header->time_mult;
  uint64_t rem = delta % mmap_header->time_mult;
  return (quot << mmap_header->time_shift) +
      (rem << mmap_header->time_shift) / mmap_header->time_mult;
}

} // namespace facebook::hbt::perf_event
