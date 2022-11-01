// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/Metrics.h"
#include "hbt/src/perf_event/PerCpuSampleGeneratorBase.h"
#include "hbt/src/ringbuffer/Producer.h"
#include "hbt/src/ringbuffer/RingBuffer.h"
#include "hbt/src/tagstack/Event.h"
#include "hbt/src/tagstack/TagStack.h"
#include "hbt/src/utils/ValueTimeSeries.h"

#include <functional>
#include <memory>
#include <unordered_map>

namespace facebook::hbt::perf_event {

struct ThreadNameChange {
  std::string new_name;
  bool is_exec;

  ThreadNameChange(const std::string& new_name, bool is_exec)
      : new_name{new_name}, is_exec{is_exec} {}

  ThreadNameChange(std::string&& new_name, bool is_exec)
      : new_name{new_name}, is_exec{is_exec} {}
};

struct ThreadInfo {
  tagstack::Tag
      vid; // unique virtual id to avoid collisions when tid is reused.
  pid_t ppid = -1;
  pid_t ptid = -1;
  pid_t pid = -1;
  pid_t tid = -1;
  TimeStamp fork_timestamp = kInvalidTimeStamp;
  TimeStamp end_timestamp = kInvalidTimeStamp;
  std::optional<std::string> cmdline;
  utils::value_time_series::Series<ThreadNameChange> names;
};

// Key is virtual ID.
using ThreadsInfo = std::unordered_map<tagstack::Tag, ThreadInfo>;

// State and name history for threads that
// have been observed running.
// XXX: Current implementation's memory occupancy will grow unbounded.
struct PerThreadStats {
  tagstack::Tag next_vid = 1; // Use selectNextVid to find the next_value.
  ThreadsInfo info;
  // Map from virtual IDs to tids to threads that are known to be running.
  std::unordered_map<pid_t, tagstack::Tag> active_tids;

  ThreadInfo& createThreadInfo(pid_t ppid, pid_t ptid, pid_t pid, pid_t tid) {
    auto new_vid = next_vid++;
    HBT_DCHECK_GE(pid, 0);
    HBT_DCHECK_GE(tid, 0);
    // DLOG(INFO) << "createThreadInfo for tid: " << tid << " new next_vid: " <<
    // new_vid;
    auto [new_info_iter, success] = info.emplace(
        new_vid,
        ThreadInfo{
            .vid = new_vid,
            .ppid = ppid,
            .ptid = ptid,
            .pid = pid,
            .tid = tid,
            .cmdline = readProcFsCmdLine(tid)});
    HBT_THROW_ASSERT_IF(!success)
        << "ThreadInfo with vid: " << new_vid << " already created";

    HBT_DCHECK_EQ(active_tids.count(tid), 0)
        << "tid: " << tid << " already active";
    active_tids[tid] = new_vid;
    HBT_THROW_ASSERT_IF(
        next_vid == std::numeric_limits<decltype(next_vid)>::max())
        << "Virtual ID for processes is about to overflow. "
        << "Future samples will be corrupted"
        << "Consider choosing wider numeric type to hold it.";

    // if (new_info_iter->second.cmdline.has_value())
    //  HBT_LOG_INFO() << "Found cmdline: " << *new_info_iter->second.cmdline;
    return new_info_iter->second;
  }

  // Returns the value for the next vid and true if needs to create a new
  // ThreadInfo. tid 0 is special because it's the non-process, do not remap it
  // to keep things simple in parts that need to special case that id.
  std::pair<tagstack::Tag, bool> selectNextVid(pid_t tid) {
    if (tid == 0) {
      // tid 0 is special Linux kernel process without no proc fs file, comm,
      // fork, etc.
      return {0, false};
    }
    auto it = active_tids.find(tid);
    if (it == active_tids.end()) {
      return {next_vid, true};
    } else {
      return {it->second, false};
    }
  }

  void addProcFsComm(TimeStamp ts, ThreadInfo& tinfo, bool is_exec) {
    // Read name from proc fs.
    auto comm = readProcFsComm(tinfo.tid);
    if (comm.has_value()) {
      tinfo.names.emplace(ts, ThreadNameChange{*comm, is_exec});
    }
  }

  // Returns virtual id.
  void
  registerFork(TimeStamp ts, pid_t ppid, pid_t ptid, pid_t pid, pid_t tid) {
    auto& tinfo = createThreadInfo(ppid, ptid, pid, tid);
    tinfo.fork_timestamp = ts;
    addProcFsComm(ts, tinfo, false);
  }

  void registerExit(TimeStamp ts, tagstack::Tag vid, pid_t tid) {
    // DLOG(INFO) << "registerExit at ts: " << ts << " for vid: " << vid;
    auto& s = info.at(vid);
    HBT_THROW_ASSERT_IF(s.end_timestamp != kInvalidTimeStamp);
    s.end_timestamp = ts;
    HBT_THROW_ASSERT_IF(
        s.fork_timestamp != kInvalidTimeStamp && ts <= s.fork_timestamp);
    HBT_DCHECK_EQ(active_tids.count(tid), 1);
    active_tids.erase(tid);
  }
};

inline std::ostream& operator<<(
    std::ostream& os,
    const ThreadNameChange& name_change) {
  os << "<ThreadNameChange new_name: \"" << name_change.new_name << "\""
     << (name_change.is_exec ? " is_exec" : "") << ">";
  return os;
}

inline std::ostream& operator<<(std::ostream& os, const ThreadInfo& info) {
  os << "<ThreadInfo "
     << " ppid: " << info.ppid << " ptid: " << info.ptid << " pid: " << info.pid
     << " tid: " << info.tid
     << " fork_timestamp: " << tstampToStr(info.fork_timestamp)
     << " end_timestamp: " << tstampToStr(info.end_timestamp);
  if (info.cmdline.has_value()) {
    os << " cmdline: \"" << *info.cmdline << "\"";
  }

  os << " names: [ ";
  for (const auto& p : info.names.getPoints()) {
    os << "(tstamp: " << tstampToStr(p.tstamp) << " " << p.value << ")";
  }
  os << "] >";
  return os;
}

//
// CRTP extension of CpuEventsGroup<>.
//
// Sample thread context switches and thread
// creation/destruction.
//
class CpuThreadSwitchGenerator final
    : public CpuEventsGroup<CpuThreadSwitchGenerator, mode::ContextSwitch> {
 public:
  using TBase = CpuEventsGroup<CpuThreadSwitchGenerator, mode::ContextSwitch>;
  using TMode = typename TBase::TMode;

  struct RbExtraData {};

  using TOutputProducer = ringbuffer::Producer<RbExtraData>;

  // This class has a constant write size for records.
  static constexpr size_t kWriteByteSize = sizeof(tagstack::Event);

  inline static const EventConfs event_confs = {EventConf{
      .id = "sw_dummy",
      .configs = EventConfigs{
          .type = PERF_TYPE_SOFTWARE,
          .config = PERF_COUNT_SW_DUMMY}}};

  CpuThreadSwitchGenerator(
      CpuId cpu,
      int cgroup_fd,
      tagstack::Level tid_level,
      std::shared_ptr<PerThreadStats> thread_stats,
      size_t rb_min_num_events)
      : TBase{cpu, -1, cgroup_fd, event_confs},
        tid_level_{tid_level},
        comp_unit_id_{static_cast<tagstack::CompUnitId>(cpu)},
        thread_stats_{thread_stats},
        output_producer_{std::make_shared<ringbuffer::RingBuffer<RbExtraData>>(
            kWriteByteSize * rb_min_num_events)} {}

  auto getOutput() noexcept {
    return output_producer_.getRingBuffer();
  }

  const auto& getOutputRef() const noexcept {
    return output_producer_.getRingBufferRef();
  }

  auto getNumEntries() const noexcept {
    HBT_DCHECK(
        output_producer_.getHeader().usedSizeWeak() % kWriteByteSize == 0);
    return output_producer_.getHeader().usedSizeWeak() / kWriteByteSize;
  }

  void open(size_t num_pages) {
    // XXX: Estimate num_pages needed based on
    // /proc/sys/kernel/sched_min_granularity_ns and pagesize().
    // DLOG(INFO) << "CpuThreadSwitchGenerator opening event in CPU: "
    //           << this->getCpu() << " with " << num_pages << " pages";
    // Open pinned, since otherwise there is no tracing of context switches.
    TBase::open_(num_pages, 0, true, 0);
    HBT_THROW_ASSERT_IF(!isOpen());
  }

  void enableImpl() noexcept {}

  void disableImpl() noexcept {}

  auto handleRecordLost(const mode::ContextSwitch::Lost& r) noexcept {
    auto ret = pendingRecordLost_(r.sample_id.tstamp);
    if (unlikely(0 > ret)) {
      return ret;
    }

    // perf_event sets the timestamp of lost records when the Lost record is
    // written into its ringbuffer. This break monotonicity because some events
    // have their time stamps set before triggering logging of dropped events,
    // potentially causing events with earlier timestamps to be logged after
    // RecordLost records. This makes the timestamp to correspond to
    // the end of a period where no events were registered.
    // There is no information about the start,
    // so use the last known valid tstamp instead.
    auto ev_start =
        tagstack::Event::makeWriteErrorsStart(last_tstamp_ + 1, comp_unit_id_);
    ret = output_producer_.write(ev_start);
    if (likely(ret >= 0)) {
      last_tstamp_ = r.sample_id.tstamp;
      in_write_errors_ = true;
      // We've lost track of which threads are active. TID could've wrapped
      // so active_tids must be cleared and start over. This may cause
      // the same TID to appear more than once but that's the correct behavior.
      thread_stats_->active_tids.clear();
    }
    HBT_LOG_WARNING_IF(0 > ret)
        << "Could not log WriteErrorStart due to error: "
        << toErrorCode(-ret).message();
    return ret;
  }

  ssize_t handleRecordComm(
      const mode::ContextSwitch::Comm_Lower& r,
      const size_t name_len,
      const mode::ContextSwitch::sample_id_t* sample_id_ptr) noexcept {
    // HBT_LOG_INFO() << "CpuThreadSwitchGenerator CPU: " << this->cpu_
    //          << " handleRecordComm tid: " << r.tid
    //          << " tstamp: " << sample_id_ptr->tstamp;

    TimeStamp new_tstamp = sample_id_ptr->tstamp;
    auto ret = pendingRecordLost_(new_tstamp);
    if (unlikely(0 > ret)) {
      return ret;
    }

    bool is_exec = r.header.misc | PERF_RECORD_MISC_COMM_EXEC;
    HBT_DCHECK_GE(r.tid, 0);
    auto [vid, is_new_vid] =
        thread_stats_->selectNextVid(static_cast<pid_t>(r.tid));
    if (is_new_vid) {
      thread_stats_->createThreadInfo(
          // Parent's pid and tid are not collected, so -1.
          -1,
          -1,
          static_cast<pid_t>(r.pid),
          static_cast<pid_t>(r.tid));
    }
    auto& tinfo = thread_stats_->info.at(vid);
    tinfo.names.emplace(
        new_tstamp, ThreadNameChange{std::string{r.comm, name_len}, is_exec});
    HBT_THROW_ASSERT_IF(
        tinfo.fork_timestamp != kInvalidTimeStamp &&
        new_tstamp <= tinfo.fork_timestamp);
    HBT_THROW_ASSERT_IF(tinfo.end_timestamp != kInvalidTimeStamp);

    last_tstamp_ = new_tstamp;
    return 0;
  }

  ssize_t handleRecordExit(const mode::ContextSwitch::Exit& r) noexcept {
    // DLOG(INFO) << "CpuThreadSwitchGenerator CPU: " << this->cpu_
    //          << " handleRecordExit tid: " << r.tid << " ptid: " << r.ptid
    //          << " pid: " << r.pid << " ppid: " << r.ppid
    //          << " r.time: " << r.time;

    TimeStamp new_tstamp = r.time;
    HBT_DCHECK_GE(r.tid, 0);

    auto ret = pendingRecordLost_(new_tstamp);
    if (unlikely(0 > ret)) {
      return ret;
    }
    auto [vid, is_new_vid] =
        thread_stats_->selectNextVid(static_cast<pid_t>(r.tid));
    auto ev = tagstack::Event::makeThreadDestruction(
        new_tstamp, tid_level_, vid, comp_unit_id_);
    ret = output_producer_.write(ev);
    if (likely(ret >= 0)) {
      if (is_new_vid) {
        auto& tinfo = thread_stats_->createThreadInfo(
            static_cast<pid_t>(r.ppid),
            static_cast<pid_t>(r.ptid),
            static_cast<pid_t>(r.pid),
            static_cast<pid_t>(r.tid));
        thread_stats_->addProcFsComm(new_tstamp, tinfo, false);
      }
      thread_stats_->registerExit(new_tstamp, vid, static_cast<pid_t>(r.tid));
      last_tstamp_ = new_tstamp;
    }
    return ret;
  }

  ssize_t handleRecordFork(const mode::ContextSwitch::Fork& r) noexcept {
    // DLOG(INFO) << "CpuThreadSwitchGenerator CPU: " << this->cpu_
    //          << " handleRecordFork tid: " << r.tid << " ptid: " << r.ptid
    //          << " pid: " << r.pid << " ppid: " << r.ppid
    //          << " r.time: " << r.time;

    TimeStamp new_tstamp = r.time;

    HBT_DCHECK_GE(r.ptid, 0);
    HBT_DCHECK_GE(r.tid, 0);

    auto ret = pendingRecordLost_(new_tstamp);
    if (unlikely(0 > ret)) {
      return ret;
    }

    auto [vid, is_new_vid] =
        thread_stats_->selectNextVid(static_cast<pid_t>(r.tid));
    auto ev = tagstack::Event::makeThreadCreation(
        new_tstamp, tid_level_, vid, comp_unit_id_);
    ret = output_producer_.write(ev);
    if (likely(ret >= 0)) {
      if (!is_new_vid) {
        // Has already been seen, probably coming from another CPU.
        auto& tinfo = thread_stats_->info.at(vid);
        HBT_THROW_ASSERT_IF(tinfo.fork_timestamp != kInvalidTimeStamp)
            << "tinfo: " << tinfo << " event: " << ev;
        tinfo.fork_timestamp = new_tstamp;
      } else {
        thread_stats_->registerFork(
            new_tstamp,
            static_cast<pid_t>(r.ppid),
            static_cast<pid_t>(r.ptid),
            static_cast<pid_t>(r.pid),
            static_cast<pid_t>(r.tid));
      }
      last_tstamp_ = new_tstamp;
    }
    return ret;
  }

  ssize_t handleRecordSwitchCpuWide(
      const mode::ContextSwitch::SwitchCpuWide& r) noexcept {
    // HBT_LOG_INFO() << "CpuThreadSwitchGenerator handleRecordSwitchCpuWide
    // r.tstamp:" << r.tstamp;
    TimeStamp new_tstamp = r.sample_id.tstamp;

    auto ret = pendingRecordLost_(new_tstamp);
    if (unlikely(0 > ret)) {
      return ret;
    }

    // XXX: Records are produced in sched_in and sched_out of each thread.
    // There is a context swith only period in between that could be captured.
    if (r.isSwitchOut()) {
      if (r.isSwitchOutPreempt()) {
        ret = output_producer_.write(tagstack::Event::makeSwitchOutPreempt(
            new_tstamp, tid_level_, comp_unit_id_));
      } else {
        ret = output_producer_.write(tagstack::Event::makeSwitchOutYield(
            new_tstamp, tid_level_, comp_unit_id_));
      }
    } else {
      // This will be a new vid (if record's event can be written in output).
      auto [vid, is_new_vid] =
          thread_stats_->selectNextVid(static_cast<pid_t>(r.sample_id.tid));
      ret = output_producer_.write(tagstack::Event::makeSwitchIn(
          new_tstamp, tid_level_, vid, comp_unit_id_));
      if (unlikely(is_new_vid && ret >= 0)) {
        // Add ThreadInfo if this is a new vid.
        pid_t pid = static_cast<pid_t>(r.sample_id.pid);
        pid_t tid = static_cast<pid_t>(r.sample_id.tid);
        auto& tinfo = thread_stats_->createThreadInfo(-1, -1, pid, tid);
        thread_stats_->addProcFsComm(new_tstamp, tinfo, false);
        HBT_DCHECK_EQ(tinfo.vid, vid) << "while record: " << r;
      }
    }

    if (likely(ret >= 0)) {
      last_tstamp_ = new_tstamp;
    }
    return ret;
  }

  TimeStamp getLastTimeStamp() const noexcept {
    return last_tstamp_;
  }

  auto getCompUnitId() const noexcept {
    return comp_unit_id_;
  }

 protected:
  const tagstack::Level tid_level_;
  const tagstack::CompUnitId comp_unit_id_;
  std::shared_ptr<PerThreadStats> thread_stats_;
  TimeStamp last_tstamp_ = std::numeric_limits<TimeStamp>::min();
  bool in_write_errors_ = false;
  TOutputProducer output_producer_;

  /// Try to write any pending record lost and clear error if succesful.
  inline ssize_t pendingRecordLost_(TimeStamp tstamp) noexcept {
    if (likely(!in_write_errors_)) {
      return 0;
    }
    auto ev_end = tagstack::Event::makeWriteErrorsEnd(tstamp, comp_unit_id_);
    auto ret = output_producer_.write(ev_end);
    if (likely(ret >= 0)) {
      last_tstamp_ = tstamp;
      in_write_errors_ = false;
    }
    return ret;
  }
};

// Wrap many instances of CpuThreadSwitchGenerator, one per CPU.
class PerCpuThreadSwitchGenerator
    : public PerCpuSampleGeneratorBase<CpuThreadSwitchGenerator> {
 public:
  using TCpuGenerator = CpuThreadSwitchGenerator;

  PerCpuThreadSwitchGenerator(
      const CpuSet& mon_cpus,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper,
      tagstack::Level tid_level,
      size_t rb_min_num_events)
      : PerCpuSampleGeneratorBase<CpuThreadSwitchGenerator>{
            mon_cpus,
            cgroup_fd_wrapper} {
    thread_stats_ = std::make_shared<PerThreadStats>();

    int cgroup_fd = -1;
    if (this->cgroup_fd_wrapper_ != nullptr) {
      cgroup_fd = this->cgroup_fd_wrapper_->fd;
    }

    for_each_cpu(cpu, mon_cpus) {
      this->cpu_generators_[cpu] = std::make_shared<TCpuGenerator>(
          cpu, cgroup_fd, tid_level, thread_stats_, rb_min_num_events);
    }
  }

  void open(size_t num_pages) {
    try {
      for_each_cpu(cpu, this->mon_cpus_) {
        this->cpu_generators_.at(cpu)->open(num_pages);
      }
    } catch (...) {
      close();
      throw;
    }
  }

  auto getThreadsInfo() const noexcept {
    return thread_stats_->info;
  }

  void onCpusThreadSwitchBufferRead(OnRbReadCallback callback, bool consume) {
    for_each_cpu(cpu, this->mon_cpus_) {
      this->cpu_generators_.at(cpu)->onCpuDataBufferRead(callback, consume);
    }
  }

 protected:
  std::shared_ptr<PerThreadStats> thread_stats_;
};

} // namespace facebook::hbt::perf_event
