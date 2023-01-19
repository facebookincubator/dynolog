// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <hbt/src/common/Defs.h>
#include "hbt/src/common/Defaults.h"
#include "hbt/src/common/System.h"
#include "hbt/src/mon/IntelPTMonitor.h"
#include "hbt/src/mon/MonData.h"
#include "hbt/src/perf_event/PerCpuCountReader.h"

#include <pfs/procfs.hpp>
#include <mutex>

#ifdef HBT_ENABLE_TRACING
#include "hbt/src/mon/TraceMonitor.h"
#endif // HBT_ENABLE_TRACING

#ifdef HBT_ENABLE_BPERF
#include "hbt/src/perf_event/BPerfCountReader.h"
#endif // HBT_ENABLE_BPERF

namespace facebook::hbt::mon {

/// Class to consolidate initialization, polling,  processing
/// and lifetime of TraceMonitor, CountReaders, and BPerfCountReaders.
///
/// It has a Dummy Generator to provide a convenient TSC converter.
/// Multiplexing:
/// Elements are arranged into MuxGroups, each contains multiple elements
/// (TraceMonitor, CountReaders, BPerfCountReaders, etc).
/// Groups are rotated in the MuxQueue. Only elements at the front of the
/// MuxQueue are enabled when the queue is enabled.
/// All elements in the queue are opened when the queue is open, regadless
/// of their position in the queue.
template <
    class MuxGroupIdType = std::optional<std::string>,
    class ElemIdType = std::string>
class Monitor {
  enum class State {
    Closed, // No perf_events are opened. Queue is inactive.
    Open, // perf_events are opened but disabled. Queue is inactive.
    Enabled // perf_events are opened and enabled. Queue is active.
  };

 public:
  using TCountReader = perf_event::PerCpuCountReader;
#ifdef HBT_ENABLE_BPERF
  using TBPerfCountReader = perf_event::BPerfCountReader;
#endif // HBT_ENABLE_BPERF

  using ElemId = ElemIdType;
  using MuxGroupId = MuxGroupIdType;
  using MuxGroup = std::set<ElemId>;

  void muxRotate() {
    std::lock_guard<std::mutex> lock{mutex_};
    if (mux_queue_.empty()) {
      return;
    }
    std::rotate(
        mux_queue_.rbegin(), mux_queue_.rbegin() + 1, mux_queue_.rend());
    sync_();
  }

  explicit Monitor() {}

  bool open() {
    std::lock_guard<std::mutex> lock{mutex_};
    return toState_(State::Open);
  }

  bool isOpen() const {
    std::lock_guard<std::mutex> lock{mutex_};
    return getState_() == State::Open;
  }

  bool close() {
    std::lock_guard<std::mutex> lock{mutex_};
    return toState_(State::Closed);
  }

  bool enable() {
    std::lock_guard<std::mutex> lock{mutex_};
    return toState_(State::Enabled);
  }

  bool isEnabled() const {
    std::lock_guard<std::mutex> lock{mutex_};
    return getState_() == State::Enabled;
  }

  bool disable() {
    std::lock_guard<std::mutex> lock{mutex_};
    return toState_(State::Open);
  }

#ifdef HBT_ENABLE_TRACING
  /// Process until <stop_ts_opt> (or now() if stop_ts_opt is nullopt.
  /// If <pipeline_max_lat_secs> is provided, then stop that many seconds
  /// before stop_ts. This is useful to allow data to propagate through
  /// pipeline.
  void processNext(
      unsigned batch_size,
      std::optional<TimeStamp> stop_ts_opt,
      std::optional<std::chrono::seconds> pipeline_max_lat_secs_opt) {
    std::lock_guard<std::mutex> lock{mutex_};
    for (auto& [k, tc] : trace_monitors_) {
      tc->processNext(batch_size, stop_ts_opt, pipeline_max_lat_secs_opt);
    }
  }

  std::shared_ptr<MonData> releaseMonData(
      const ElemId& mon_id,
      const std::string& count_gen_key,
      std::optional<TimeStamp> stop_ts_opt,
      const std::string& short_desc,
      const std::string& long_desc) {
    std::lock_guard<std::mutex> lock{mutex_};
    auto it = trace_monitors_.find(mon_id);
    if (it == trace_monitors_.end()) {
      HBT_LOG_WARNING() << fmt::format("No TraceMonitor with id {}", mon_id);
      return nullptr;
    }
    return it->second->releaseMonData(
        count_gen_key, stop_ts_opt, short_desc, long_desc);
  }
#endif // HBT_ENABLE_TRACING

  // Get the executable, file-backed modules per process.
  std::unordered_map<pid_t, std::vector<ModuleInfo>>
  collectFileBackedExecutableModules(const std::vector<pid_t>& pids) const {
    std::unordered_map<pid_t, std::vector<ModuleInfo>> module_info;
    pfs::procfs pfs;

    for (auto pid : pids) {
      auto root_path =
          std::filesystem::path("/proc") / std::to_string(pid) / "root";
      try {
        auto maps = pfs.get_task(pid).get_maps();
        module_info.emplace(
            pid, detail::getFileBackedExecutableModules(root_path, maps));
      } catch (const pfs::parser_error& ex) {
        HBT_LOG_ERROR() << "Exception parsing the memory maps file for PID "
                        << pid << ". Message " << ex.what();
      }
    }
    return module_info;
  }

  // Call the given function on each of the process' executable, file-backed
  // modules.
  //
  // Throws a pfs:parser exception if parsing /proc/<pid>/maps fails.
  void forEachFileBackedExecutableModules(
      const std::set<pid_t>& pids,
      std::function<void(pid_t, const std::vector<ModuleInfo>&)> func) const {
    pfs::procfs pfs;

    for (auto pid : pids) {
      auto maps = pfs.get_task(pid).get_maps();
      auto root_path =
          std::filesystem::path("/proc") / std::to_string(pid) / "root";
      auto modules = detail::getFileBackedExecutableModules(root_path, maps);
      func(pid, modules);
    }
  }

#ifdef HBT_ENABLE_TRACING
  template <class TFunc>
  bool applyToCountSamplesAndConsume(
      const ElemId& trace_mon_id,
      const std::string& count_gen_key,
      TFunc& func) {
    std::lock_guard<std::mutex> lock{mutex_};

    auto it = trace_monitors_.find(trace_mon_id);
    if (it == trace_monitors_.end()) {
      HBT_LOG_WARNING() << fmt::format(
          "No TraceMonitor with id {}", trace_mon_id);
      return false;
    }
    it->second->applyToCountSamplesAndConsume(count_gen_key, func);
    return true;
  }

  /// Read counts for all events opened in sampling mode
  /// in all TraceCollectors.
  auto readSamplingCounts() const {
    using TraceCollectorReadValues = std::map<
        std::string,
        std::optional<TraceCollector::TPerCpuCountSampleGenerator::ReadValues>>;

    std::lock_guard<std::mutex> lock{mutex_};

    std::map<ElemId, TraceCollectorReadValues> rvs;

    for (auto& [k, tm] : trace_monitors_) {
      HBT_THROW_ASSERT_IF(tm == nullptr);
      if (tm != nullptr) {
        rvs.emplace(k, tm->readCounts());
      }
    }
    return rvs;
  }
#endif // HBT_ENABLE_TRACING

  /// Read counts for all events opened in counting mode
  /// in all PerCpuCountReaders.
  std::map<ElemId, std::optional<TCountReader::ReadValues>> readAllCounts()
      const {
    std::lock_guard<std::mutex> lock{mutex_};
    std::map<ElemId, std::optional<TCountReader::ReadValues>> rvs;

    for (auto& [k, cr] : count_readers_) {
      HBT_THROW_ASSERT_IF(cr == nullptr);
      rvs.emplace(k, cr->read());
    }
    return rvs;
  }

  /// Read counts for all events opened in counting mode
  /// in PerCpuCountReader given by elem_id.
  std::optional<TCountReader::ReadValues> readCounts(
      const ElemId& elem_id) const {
    std::lock_guard<std::mutex> lock{mutex_};

    if (auto it = count_readers_.find(elem_id); it != count_readers_.end()) {
      HBT_THROW_ASSERT_IF(it->second == nullptr);
      return it->second->read();
    }
    HBT_LOG_WARNING() << fmt::format("No CountReader with id {}", elem_id);
    return std::nullopt;
  }

#ifdef HBT_ENABLE_TRACING
  std::shared_ptr<TraceMonitor> getTraceMonitor(const ElemId& mon_id) {
    std::lock_guard<std::mutex> lock{mutex_};
    auto it = trace_monitors_.find(mon_id);
    if (it == trace_monitors_.end()) {
      HBT_LOG_WARNING() << fmt::format("No TraceMonitor with id {}", mon_id);
      return nullptr;
    }
    return it->second;
  }

  /// Create and register a new TraceMonitor, it returns a shared ptr to
  /// newly created TraceMonitor, but it can also be retrieved later using
  /// the elem_id. Note that the state of this TraceMonitor will be managed
  /// by Monitor.
  std::shared_ptr<TraceMonitor> emplaceTraceMonitor(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id,
      const CpuSet& mon_cpus) {
    std::lock_guard<std::mutex> lock{mutex_};

    // Check for key before creating new count generator.
    HBT_ARG_CHECK_EQ(trace_monitors_.count(elem_id), 0)
        << "There is already an interval source with key: \"" << elem_id
        << "\"";

    addMuxEntry_(mux_group_id, elem_id);
    auto [it, emplaced] = trace_monitors_.emplace(
        elem_id, std::make_unique<TraceMonitor>(mon_cpus));
    HBT_THROW_ASSERT_IF(!emplaced);

    // Transition newly emplaced TraceMonitor to Monitor's state.
    sync_();

    return it->second;
  }
#endif // HBT_ENABLE_TRACING

  /// Create and register a new CountReader, it returns a shared ptr to
  /// newly created TraceMonitor, but it can also be retrieved later using
  /// the elem_id. Note that the state of this CountReader will be managed
  /// by Monitor.
  std::shared_ptr<TCountReader> emplaceCountReader(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id,
      std::shared_ptr<const perf_event::MetricDesc> metric_desc,
      std::shared_ptr<const perf_event::PmuDeviceManager> pmu_manager,
      const CpuSet& mon_cpus,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper) {
    std::lock_guard<std::mutex> lock{mutex_};

    // Check for key before creating new count generator.
    HBT_ARG_CHECK_EQ(count_readers_.count(elem_id), 0)
        << "There is already an interval source with key: \"" << elem_id
        << "\"";

    addMuxEntry_(mux_group_id, elem_id);
    auto [it, emplaced] = count_readers_.emplace(
        elem_id,
        std::make_unique<Monitor::TCountReader>(
            mon_cpus, metric_desc, pmu_manager, cgroup_fd_wrapper));

    // Transition newly emplaced PerCpuCountReader to Monitor's state.
    sync_();
    return it->second;
  }

  bool eraseCountReader(const MuxGroupId& mux_group_id, const ElemId& elem_id) {
    std::lock_guard<std::mutex> lock{mutex_};
    if (!count_readers_.count(elem_id)) {
      return false;
    }
    if (!removeMuxEntry_(mux_group_id, elem_id)) {
      return false;
    }
    count_readers_.erase(elem_id);
    sync_();
    return true;
  }

#ifdef HBT_ENABLE_BPERF
  /// Read counts for all events opened in counting mode
  /// in all BPerfCountReaders.
  std::map<ElemId, std::optional<TBPerfCountReader::ReadValues>>
  readAllBPerfCounts(bool skip_offset = false) const {
    std::lock_guard<std::mutex> lock{mutex_};
    std::map<ElemId, std::optional<TBPerfCountReader::ReadValues>> rvs;

    for (auto& [k, cr] : bperf_count_readers_) {
      HBT_THROW_ASSERT_IF(cr == nullptr);
      if (cr->isEnabled()) {
        rvs.emplace(k, cr->read(skip_offset));
      }
    }
    return rvs;
  }

  /// Read counts for all events opened in counting mode
  /// in BPerfCountReader given by elem_id (independent from the mux group).
  std::optional<TBPerfCountReader::ReadValues> readBPerfCounts(
      const ElemId& elem_id,
      bool skip_offset = false) const {
    std::lock_guard<std::mutex> lock{mutex_};

    if (auto it = bperf_count_readers_.find(elem_id);
        it != bperf_count_readers_.end()) {
      HBT_THROW_ASSERT_IF(it->second == nullptr);
      return it->second->read(skip_offset);
    }
    HBT_LOG_WARNING() << fmt::format("No BPerfCountReader with id {}", elem_id);
    return std::nullopt;
  }

  /// Create and register a new BPerfCountReader, it returns a shared ptr to
  /// newly created TraceMonitor, but it can also be retrieved later using
  /// the elem_id. Note that the state of this BPerfCountReader will be managed
  /// by Monitor.
  std::shared_ptr<TBPerfCountReader> emplaceBPerfCountReader(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id,
      const std::string& bpf_map_name,
      std::shared_ptr<const perf_event::MetricDesc> metric_desc,
      std::shared_ptr<const perf_event::PmuDeviceManager> pmu_manager,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper) {
    std::lock_guard<std::mutex> lock{mutex_};

    // Check for key before creating new count generator.
    HBT_ARG_CHECK_EQ(bperf_count_readers_.count(elem_id), 0)
        << "There is already a BPerfCountReader  with key: \"" << elem_id
        << "\"";

    addMuxEntry_(mux_group_id, elem_id);

    auto [it, emplaced] = bperf_count_readers_.emplace(
        elem_id,
        std::make_unique<Monitor::TBPerfCountReader>(
            bpf_map_name, metric_desc, pmu_manager, cgroup_fd_wrapper));

    // Transition newly emplaced BPerfCountReader to Monitor's state.
    sync_();
    return it->second;
  }

  bool eraseBPerfCountReader(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id) {
    std::lock_guard<std::mutex> lock{mutex_};
    if (!bperf_count_readers_.count(elem_id)) {
      return false;
    }
    if (!removeMuxEntry_(mux_group_id, elem_id)) {
      return false;
    }
    bperf_count_readers_.erase(elem_id);
    sync_();
    return true;
  }
#endif // HBT_ENABLE_BPERF

  std::shared_ptr<IntelPTMonitor> getIptMonitor(const ElemId& mon_id) {
    std::lock_guard<std::mutex> lock{mutex_};
    auto it = ipt_monitors_.find(mon_id);
    if (it == ipt_monitors_.end()) {
      HBT_LOG_WARNING() << fmt::format("No IntelPT Monitor with id {}", mon_id);
      return nullptr;
    }
    return it->second;
  }

  /// Create and register a new IntelPTMonitor, it returns a shared ptr to
  /// newly created IntelPTMonitor, but it can also be retrieved later using
  /// the elem_id. Note that the state of this IntelPTMonitor will be managed
  /// by Monitor.
  std::shared_ptr<IntelPTMonitor> emplaceIptMonitor(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id,
      IntelPTGenCtxt&& ipt_gen_ctxt) {
    std::lock_guard<std::mutex> lock{mutex_};

    // Check for key before creating new count generator.
    HBT_ARG_CHECK_EQ(ipt_monitors_.count(elem_id), 0)
        << "There is already a IntelPTMonitor  with key: \"" << elem_id << "\"";

    addMuxEntry_(mux_group_id, elem_id);

    auto [it, emplaced] = ipt_monitors_.emplace(
        elem_id, std::make_unique<IntelPTMonitor>(std::move(ipt_gen_ctxt)));

    // Transition newly emplaced IntelPTMonitor to Monitor's state.
    sync_();
    return it->second;
  }

  std::ostream& printTraceMonitorsStatus(
      std::ostream& os,
      const cpu_set_t& cpus) const;

  std::ostream& printCountReadersStatus(std::ostream& os, const cpu_set_t& cpus)
      const;

  std::ostream& printBPerfCountReadersStatus(std::ostream& os) const;

  std::ostream& printMuxQueueStatus(std::ostream& os) const;

  std::string statusStr(const CpuSet& cpus) const {
    std::ostringstream os;

    auto cpuset = cpus.cpu_set;
    printMuxQueueStatus(os);
    printTraceMonitorsStatus(os, cpuset);
    printCountReadersStatus(os, cpuset);
    printBPerfCountReadersStatus(os);
    return os.str();
  }

#ifdef HBT_ENABLE_TRACING
  size_t numTraceMonitors() const {
    std::lock_guard<std::mutex> lock{mutex_};
    return trace_monitors_.size();
  }
#endif // HBT_ENABLE_TRACING

  size_t numCountReaders() const {
    std::lock_guard<std::mutex> lock{mutex_};
    return count_readers_.size();
  }

#ifdef HBT_ENABLE_BPERF
  size_t numBPerfCountReaders() const {
    std::lock_guard<std::mutex> lock{mutex_};
    return bperf_count_readers_.size();
  }
#endif // HBT_ENABLE_BPERF

 protected:
  State state_ = State::Closed;

#ifdef HBT_ENABLE_TRACING
  std::unordered_map<ElemId, std::shared_ptr<TraceMonitor>> trace_monitors_;
#endif // HBT_ENABLE_TRACING

  std::unordered_map<ElemId, std::shared_ptr<TCountReader>> count_readers_;

#ifdef HBT_ENABLE_BPERF
  std::unordered_map<ElemId, std::shared_ptr<TBPerfCountReader>>
      bperf_count_readers_;
#endif // HBT_ENABLE_BPERF

  /// Mapping from MuxGroupId to MuxGroup. Each MuxGroup contains
  /// ElemIds of the TraceMonitors, CountReaders, BPerfCountReaders
  /// and IntelPTMonitors in it.
  std::unordered_map<ElemId, std::shared_ptr<IntelPTMonitor>> ipt_monitors_;

  std::unordered_map<MuxGroupId, MuxGroup> mux_groups_;

  std::vector<MuxGroupId> mux_queue_;

  // Mark as mutable to allow usage from const methods.
  mutable std::mutex mutex_;

  State getState_() const {
    return state_;
  }

  bool toState_(State s) {
    if (state_ == s) {
      return false;
    }
    state_ = s;
    sync_();
    return true;
  }

  void sync_();

  // Transition all elements in container.
  template <class TContainer>
  void syncElems_(TContainer& elems_container);

  void addMuxEntry_(const MuxGroupId& mux_group_id, const ElemId& elem_id) {
    auto& g = mux_groups_[mux_group_id];
    if (g.empty()) {
      mux_queue_.push_back(mux_group_id);
    }
    g.insert(elem_id);
    sync_();
  }

  bool removeMuxEntry_(const MuxGroupId& mux_group_id, const ElemId& elem_id) {
    if (!mux_groups_.count(mux_group_id) ||
        !mux_groups_[mux_group_id].count(elem_id)) {
      return false;
    }
    auto& g = mux_groups_[mux_group_id];
    g.erase(elem_id);
    if (g.empty()) {
      mux_groups_.erase(mux_group_id);
      const auto groupIdIt =
          std::find(mux_queue_.begin(), mux_queue_.end(), mux_group_id);
      // monitor must be in an inconsistent state if a mux_group_id is in
      // mux_groups_ but not in mux_queue_
      if (groupIdIt == mux_queue_.cend()) {
        HBT_THROW_ASSERT() << "mux_group_id \""
                           << mux_group_id.value_or("nullopt")
                           << "\" exists in mux_groups_ but not in mux_queue_";
      }
      mux_queue_.erase(groupIdIt);
    }
    sync_();
    return true;
  }
};

#ifdef HBT_ENABLE_TRACING
template <class MuxGroupId, class ElemId>
std::ostream& Monitor<MuxGroupId, ElemId>::printTraceMonitorsStatus(
    std::ostream& os,
    const cpu_set_t& cpus) const {
  std::lock_guard<std::mutex> lock{mutex_};
  for (const auto& [k, tm] : trace_monitors_) {
    os << fmt::format("\n<TraceMonitor {}>\n", k);
    tm->printSliceGenStatus(os, cpus);
    tm->printSlicerStatus(os);
    tm->printCountGeneratorsStatus(os, cpus);
    os << "<End of TraceMonitor>\n";
  }
  return os;
}
#endif // HBT_ENABLE_TRACING

template <class MuxGroupId, class ElemId>
std::ostream& Monitor<MuxGroupId, ElemId>::printCountReadersStatus(
    std::ostream& os,
    const cpu_set_t& cpus) const {
  std::lock_guard<std::mutex> lock{mutex_};
  if (count_readers_.size() == 0) {
    os << "\nNo Count Readers\n";
    return os;
  }
  os << "\n<PerCpuCountReaders>\n";
  for (const auto& [k, cr] : count_readers_) {
    if (cr == nullptr) {
      os << "No status for: " << k << "\n";
    } else {
      os << fmt::format("PerCpuCountReader {}\n", k);
      cr->printStatus(os, cpus);
      os << "\n";
    }
  }
  os << "<End of PerCpuCountReaders>\n";
  return os;
}

#ifdef HBT_ENABLE_BPERF
template <class MuxGroupId, class ElemId>
std::ostream& Monitor<MuxGroupId, ElemId>::printBPerfCountReadersStatus(
    std::ostream& os) const {
  std::lock_guard<std::mutex> lock{mutex_};
  if (bperf_count_readers_.size() == 0) {
    os << "\nNo BPerf Count Readers\n";
    return os;
  }
  os << "\n<BPerfCountReaders>\n";
  for (const auto& [k, cr] : bperf_count_readers_) {
    if (cr == nullptr) {
      os << "No status for: " << k << "\n";
    } else {
      os << fmt::format("key: {}\n", k);
      cr->printStatus(os);
    }
  }
  os << "<End of BPerfCountReaders>\n";
  return os;
}
#endif // HBT_ENABLE_BPERF

template <class MuxGroupId, class ElemId>
std::ostream& Monitor<MuxGroupId, ElemId>::printMuxQueueStatus(
    std::ostream& os) const {
  std::lock_guard<std::mutex> lock{mutex_};
  os << "MuxQueue: ";

  switch (state_) {
    case State::Closed:
      os << "Closed";
      break;
    case State::Open:
      os << "Open";
      break;
    case State::Enabled:
      os << "Enabled";
      break;
  }
  if (mux_queue_.size() == 0) {
    os << " <No Groups>";
    return os;
  }

  for (const auto& g_id : mux_queue_) {
    os << fmt::format(
        " <{}: {}>", g_id.value_or("<None>"), mux_groups_.at(g_id));
  }
  return os;
}

//
// Finite State Machine to handle state transitions.
//

template <class TMonitor, class TGen, class... Args>
void tryOpen_(TGen& gen, Args&&... args) {
  // BPerfCountReader does not define open method.
  // It's only enable and disable.
#ifdef HBT_ENABLE_BPERF
  if constexpr (!std::is_same_v<TGen, typename TMonitor::TBPerfCountReader>) {
    if (!gen.isOpen()) {
      gen.open(std::forward<Args>(args)...);
    }
  }
#else
  if (!gen.isOpen()) {
    gen.open(std::forward<Args>(args)...);
  }
#endif // HBT_ENABLE_BPERF
}

template <class TGen>
void tryEnable_(TGen& gen) {
  if (!gen.isEnabled()) {
    gen.enable();
  }
}

template <class TMonitor, class TGen>
void tryClose_(TGen& gen) {
  // BPerfCountReader does not define open method.
  // It's only enable and disable.
#ifdef HBT_ENABLE_BPERF
  if constexpr (!std::is_same_v<TGen, typename TMonitor::TBPerfCountReader>) {
    if (gen.isOpen()) {
      gen.close();
    }
  }
#endif // HBT_ENABLE_BPERF
}

template <class TGen>
void tryDisable_(TGen& gen) {
  if (gen.isEnabled()) {
    gen.disable();
  }
}

/// Transition all elements (TraceMonitors, PerCpuCountReaders,
/// and BPerfCountReaders) inside elems_container to state.
template <class MuxGroupId, class ElemId>
template <class TContainer>
void Monitor<MuxGroupId, ElemId>::syncElems_(TContainer& elems_container) {
  using TMonitor = std::decay_t<decltype(*this)>;

  for (auto& [k, elem_ptr] : elems_container) {
    HBT_THROW_ASSERT_IF(elem_ptr == nullptr);
    auto& elem = *elem_ptr;
    switch (state_) {
      case State::Closed:
        tryDisable_(elem);
        tryClose_<TMonitor>(elem);
        break;
      case State::Open:
        tryDisable_(elem);
        tryOpen_<TMonitor>(elem);
        break;
      case State::Enabled:
        tryOpen_<TMonitor>(elem);
        HBT_DCHECK_GT(mux_queue_.size(), 0);
        const auto& active_elem_ids = mux_groups_.at(mux_queue_.front());
        HBT_DCHECK_GT(active_elem_ids.size(), 0);
        // Only enable if it's at front of its multiplexing queue.
        if (active_elem_ids.count(k) > 0) {
          tryEnable_(elem);
        } else {
          tryDisable_(elem);
        }
        break;
    }
  }
}

/// Transitions (enable/disable, open/close)
/// all components in Monitor to the new state.
template <class MuxGroupId, class ElemId>
void Monitor<MuxGroupId, ElemId>::sync_() {
  if (mux_queue_.size() == 0) {
    // Empty queues have no elements to sync.
    return;
  }
#ifdef HBT_ENABLE_TRACING
  syncElems_(trace_monitors_);
#endif // HBT_ENABLE_TRACING
  syncElems_(count_readers_);
#ifdef HBT_ENABLE_BPERF
  syncElems_(bperf_count_readers_);
#endif // HBT_ENABLE_BPERF
  syncElems_(ipt_monitors_);
}

} // namespace facebook::hbt::mon
