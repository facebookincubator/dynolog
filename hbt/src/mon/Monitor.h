// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <hbt/src/common/Defs.h>
#include <pfs/procfs.hpp>
#include <mutex>
#include "hbt/src/common/Defaults.h"
#include "hbt/src/common/System.h"
#include "hbt/src/mon/IntelPTMonitor.h"
#include "hbt/src/mon/MonData.h"
#include "hbt/src/perf_event/PerCpuCountReader.h"
#include "hbt/src/perf_event/PerUncoreCountReader.h"

#ifdef HBT_ENABLE_TRACING
#include "hbt/src/mon/TraceMonitor.h"
#endif // HBT_ENABLE_TRACING

#ifdef HBT_ENABLE_BPERF
#include "hbt/src/perf_event/BPerfCountReader.h"
#include "hbt/src/perf_event/BPerfEventsGroup.h"
#endif // HBT_ENABLE_BPERF

namespace facebook::hbt::mon {

template <class MuxGroupIdType>
struct ManagedBPerfEventInfo {
  explicit ManagedBPerfEventInfo(MuxGroupIdType muxId)
      : muxId{std::move(muxId)}, refCount{0} {}
  MuxGroupIdType muxId;
  size_t refCount;
};

/// Class to consolidate initialization, polling,  processing
/// and lifetime of TraceMonitor, CountReaders, and BPerfCountReaders.
///
/// It has a Dummy Generator to provide a convenient TSC converter.
/// Multiplexing:
/// Elements are arranged into MuxGroups, each contains multiple elements
/// (TraceMonitor, CountReaders, BPerfCountReaders, etc).
/// Groups are rotated in the MuxQueue. Only elements at the front of the
/// MuxQueue are enabled when the queue is enabled.
/// There might be multiple MuxQueus indexed by PmuType, all elements in the
/// front of each MuxQueue will be enabled independently.
/// All elements in the queue are opened when the queue is open, regadless of
/// their position in the queue.
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
  using TCpuCountReader = perf_event::PerCpuCountReader;
  using TUncoreCountReader = perf_event::PerUncoreCountReader;
#ifdef HBT_ENABLE_BPERF
  using TBPerfCountReader = perf_event::BPerfCountReader;
  using TBPerfEventsGroup = perf_event::BPerfEventsGroup;
#endif // HBT_ENABLE_BPERF

  using ElemId = ElemIdType;
  using MuxGroupId = MuxGroupIdType;
  using MuxGroup = std::set<ElemId>;

  void muxRotate(bool uncore_local = false, bool core_local = false) {
    std::lock_guard<std::mutex> lock{mutex_};
    for (auto& [pmu_type, queue] : mux_queue_) {
      if (queue.empty()) {
        return;
      }
      std::rotate(queue.rbegin(), queue.rbegin() + 1, queue.rend());
    }
    sync_(uncore_local, core_local);
  }

  explicit Monitor(bool mux_queue_per_pmu_type = false, bool reset = true)
      : mux_queue_per_pmu_type_{mux_queue_per_pmu_type}, reset_{reset} {}

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

  // Return a null optional if the element is not found.
  std::optional<bool> isMetricEnabled(const ElemId& elem_id) {
    if (cpu_count_readers_.contains(elem_id)) {
      return cpu_count_readers_.at(elem_id)->isEnabled();
    }
    if (uncore_count_readers_.contains(elem_id)) {
      return uncore_count_readers_.at(elem_id)->isEnabled();
    }
#ifdef HBT_ENABLE_TRACING
    if (trace_monitors_.contains(elem_id)) {
      return trace_monitors_.at(elem_id)->isEnabled();
    }
#endif // HBT_ENABLE_TRACING
#ifdef HBT_ENABLE_BPERF
    if (bperf_count_readers_.contains(elem_id)) {
      return bperf_count_readers_.at(elem_id)->isEnabled();
    }
#endif // HBT_ENABLE_BPERF
    if (ipt_monitors_.contains(elem_id)) {
      return ipt_monitors_.at(elem_id)->isEnabled();
    }
    return std::nullopt;
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
    std::lock_guard lock{mutex_};
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

  /// Read counts for all cpu events opened in counting mode
  /// in all PerCpuCountReaders.
  std::map<ElemId, std::optional<TCpuCountReader::ReadValues>>
  readAllCpuCounts() const {
    std::lock_guard<std::mutex> lock{mutex_};
    std::map<ElemId, std::optional<TCpuCountReader::ReadValues>> rvs;

    for (auto& [k, cr] : cpu_count_readers_) {
      HBT_THROW_ASSERT_IF(cr == nullptr);
      rvs.emplace(k, cr->read());
    }
    return rvs;
  }

  /// Read counts for all cpu events opened in counting mode
  /// in all PerCpuCountReaders.
  std::map<ElemId, std::optional<std::map<int, TCpuCountReader::ReadValues>>>
  readAllCpuCountsPerCpu() const {
    std::lock_guard<std::mutex> lock{mutex_};
    std::map<ElemId, std::optional<std::map<int, TCpuCountReader::ReadValues>>>
        rvs;

    for (auto& [k, cr] : cpu_count_readers_) {
      HBT_THROW_ASSERT_IF(cr == nullptr);
      rvs.emplace(k, cr->readPerCpu());
    }
    return rvs;
  }

  /// Read counts for all cpu events opened in counting mode
  /// in PerCpuCountReader given by elem_id.
  std::optional<TCpuCountReader::ReadValues> readCpuCounts(
      const ElemId& elem_id) const {
    std::lock_guard<std::mutex> lock{mutex_};

    if (auto it = cpu_count_readers_.find(elem_id);
        it != cpu_count_readers_.end()) {
      HBT_THROW_ASSERT_IF(it->second == nullptr);
      return it->second->read();
    }
    HBT_LOG_WARNING() << fmt::format("No CountReader with id {}", elem_id);
    return std::nullopt;
  }

  std::map<ElemId, std::vector<TUncoreCountReader::ReadValues>>
  readAllUncoreCountsPerPerfEvent() const {
    std::lock_guard<std::mutex> lock{mutex_};
    std::map<ElemId, std::vector<TUncoreCountReader::ReadValues>> rvs;
    for (const auto& [k, cr] : uncore_count_readers_) {
      HBT_THROW_ASSERT_IF(cr == nullptr);
      rvs.emplace(k, cr->readPerPerfEventsGroup());
    }
    return rvs;
  }

  // migrage current thread to the CPU that owns specific uncore perf events
  // before reading to avoid IPI before CPUs.
  // **Warning:** Invoking this function may cause one or more context switches,
  // potentially resulting in significant performance degradation compared to a
  // standard read function.
  std::map<ElemId, std::vector<TUncoreCountReader::ReadValues>>
  readAllUncoreCountsPerPerfEventOnLocalCpu() const {
    std::lock_guard<std::mutex> lock{mutex_};
    std::map<ElemId, std::vector<TUncoreCountReader::ReadValues>> rvs;
    // group by CPU first to minimize # of thread migration required
    std::set<CpuId> cpus;
    for (const auto& [k, cr] : uncore_count_readers_) {
      HBT_THROW_ASSERT_IF(cr == nullptr);
      cpus.merge(cr->listCpus());
    }
    cpu_set_t prev_mask, mask;
    CPU_ZERO(&prev_mask);
    if (sched_getaffinity(0, sizeof(cpu_set_t), &prev_mask) != 0) {
      HBT_LOG_ERROR() << "Failed to get CPU affinity: " << errno;
      return {};
    }
    for (auto cpu : cpus) {
      CPU_ZERO(&mask);
      CPU_SET(cpu, &mask);
      if (sched_setaffinity(0, sizeof(mask), &mask) != 0) {
        HBT_LOG_ERROR() << "Failed to set sched affinity on CPU " << cpu;
        // all or nothing
        return {};
      }
      // read perf counter value per CPU per per hbt metric
      // then merge values from the same hbt metric and different CPU to a
      // single list
      for (const auto& [k, cr] : uncore_count_readers_) {
        auto counters = cr->readPerPerfEventsGroupOnCpu(cpu);
        auto& list = rvs[k];
        std::for_each(
            counters.begin(), counters.end(), [&list](const auto& pair) {
              list.push_back(pair.second);
            });
      }
    }
    // restore previous CPU affinity
    if (sched_setaffinity(0, sizeof(prev_mask), &prev_mask) != 0) {
      HBT_LOG_ERROR() << "Failed to restore to pervious affinity mask";
    }
    return rvs;
  }

  /// Read counts for all uncore events opened in counting mode
  /// in all PerUncoreCountReaders.
  std::map<ElemId, std::optional<TUncoreCountReader::ReadValues>>
  readAllUncoreCounts() const {
    std::lock_guard<std::mutex> lock{mutex_};
    std::map<ElemId, std::optional<TUncoreCountReader::ReadValues>> rvs;

    for (auto& [k, cr] : uncore_count_readers_) {
      HBT_THROW_ASSERT_IF(cr == nullptr);
      rvs.emplace(k, cr->read());
    }
    return rvs;
  }

  /// Read counts for all uncore events opened in counting mode
  /// in PerUncoreCountReader given by elem_id.
  std::optional<TUncoreCountReader::ReadValues> readUncoreCounts(
      const ElemId& elem_id) const {
    std::lock_guard<std::mutex> lock{mutex_};

    if (auto it = uncore_count_readers_.find(elem_id);
        it != uncore_count_readers_.end()) {
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

    addMuxEntry_(mux_group_id, elem_id, std::nullopt);
    auto [it, emplaced] = trace_monitors_.emplace(
        elem_id, std::make_unique<TraceMonitor>(mon_cpus));
    HBT_THROW_ASSERT_IF(!emplaced);

    // Transition newly emplaced TraceMonitor to Monitor's state.
    sync_();

    return it->second;
  }
#endif // HBT_ENABLE_TRACING

  /// Create and register a new PerCpuCountReader, it returns a shared ptr to
  /// newly created PerCpuCountReader, but it can also be retrieved later using
  /// the elem_id. Note that the state of this PerCpuCountReader will be managed
  /// by Monitor.
  std::shared_ptr<TCpuCountReader> emplaceCpuCountReader(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id,
      std::shared_ptr<const perf_event::MetricDesc> metric_desc,
      std::shared_ptr<const perf_event::PmuDeviceManager> pmu_manager,
      const CpuSet& mon_cpus,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper) {
    std::lock_guard<std::mutex> lock{mutex_};

    // Check for key before creating new count generator.
    HBT_ARG_CHECK_EQ(cpu_count_readers_.count(elem_id), 0)
        << "There is already an interval source with key: \"" << elem_id
        << "\"";

    auto pmu_type = getPmuTypeOfMetric(*metric_desc, *pmu_manager);

    addMuxEntry_(mux_group_id, elem_id, pmu_type);
    auto [it, emplaced] = cpu_count_readers_.emplace(
        elem_id,
        std::make_unique<Monitor::TCpuCountReader>(
            mon_cpus, metric_desc, pmu_manager, cgroup_fd_wrapper));

    // Transition newly emplaced PerCpuCountReader to Monitor's state.
    sync_();
    return it->second;
  }

  bool eraseCpuCountReader(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id) {
    std::lock_guard<std::mutex> lock{mutex_};
    if (!cpu_count_readers_.count(elem_id)) {
      return false;
    }
    if (!removeMuxEntry_(mux_group_id, elem_id)) {
      return false;
    }
    cpu_count_readers_.erase(elem_id);
    sync_();
    return true;
  }

  /// Create and register a new PerUncoreCountReader, it returns a shared ptr to
  /// newly created PerUncoreCountReader, but it can also be retrieved later
  /// using the elem_id. Note that the state of this PerUncoreCountReader will
  /// be managed by Monitor.
  std::shared_ptr<TUncoreCountReader> emplaceUncoreCountReader(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id,
      std::shared_ptr<const perf_event::MetricDesc> metric_desc,
      std::shared_ptr<const perf_event::PmuDeviceManager> pmu_manager,
      perf_event::uncore_scope::Scope scope) {
    try {
      std::lock_guard<std::mutex> lock{mutex_};

      // Check for key before creating new count generator.
      HBT_ARG_CHECK_EQ(uncore_count_readers_.count(elem_id), 0)
          << "There is already an interval source with key: \"" << elem_id
          << "\"";

      auto pmu_type = getPmuTypeOfMetric(*metric_desc, *pmu_manager);

      addMuxEntry_(mux_group_id, elem_id, pmu_type);
      auto [it, emplaced] = uncore_count_readers_.emplace(
          elem_id,
          std::make_unique<Monitor::TUncoreCountReader>(
              scope, metric_desc, pmu_manager));

      // Transition newly emplaced PerUncoreCountReader to Monitor's state.
      sync_();
      return it->second;
    } catch (const std::exception& e) {
      HBT_LOG_ERROR() << fmt::format(
          "Failed to create Uncore Count Reader with key: \"{}\"", elem_id);
      HBT_LOG_ERROR() << fmt::format("Error: {}", e.what());
      return std::shared_ptr<TUncoreCountReader>();
    }
  }

  bool eraseUncoreCountReader(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id) {
    std::lock_guard<std::mutex> lock{mutex_};
    if (!uncore_count_readers_.count(elem_id)) {
      return false;
    }
    if (!removeMuxEntry_(mux_group_id, elem_id)) {
      return false;
    }
    uncore_count_readers_.erase(elem_id);
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

  std::shared_ptr<TBPerfCountReader> emplaceBPerfCountReader(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id,
      std::shared_ptr<perf_event::BPerfEventsGroup> bperf_eg,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper,
      int cgroup_update_level) {
    std::lock_guard<std::mutex> lock{mutex_};
    // Check for key before creating new count generator.
    HBT_ARG_CHECK_EQ(bperf_count_readers_.count(elem_id), 0)
        << "There is already a BPerfCountReader  with key: \"" << elem_id
        << "\"";
    HBT_ARG_CHECK_NE(bperf_eg, nullptr);
    // Check if BPerfEventsGroup exists with a different mux group id
    HBT_ARG_CHECK_TRUE(
        !mux_bperf_event_map_.count(mux_group_id) ||
        mux_bperf_event_map_[mux_group_id] == bperf_eg.get())
        << "The provided BPerfEventsGroup has been used by another BPerfCountReader"
        << " under a different mux group id. The same BPerfEventsGroup should have the"
        << " same mux group id.";
    auto bperf_cnt_reader = std::make_unique<Monitor::TBPerfCountReader>(
        std::move(bperf_eg), cgroup_fd_wrapper, cgroup_update_level);
    if (!bperf_cnt_reader->enable()) {
      return nullptr;
    }
    // Add mux entry as other Readers.
    // But Monitor will multiplex BPerfEventsGroup rather than BPerfCountReader.
    // This is specially handled during sync_().
    addMuxEntry_(mux_group_id, elem_id, std::nullopt);
    // emplace BPerfCountReader
    auto [it, emplaced] =
        bperf_count_readers_.emplace(elem_id, std::move(bperf_cnt_reader));
    auto bperf_eg_ptr = it->second->getBPerfEventsGroup();

    // maintain managed_bperf_events_
    auto bperf_event_info_it = managed_bperf_events_.find(bperf_eg_ptr);
    if (bperf_event_info_it == managed_bperf_events_.end()) {
      bperf_event_info_it =
          managed_bperf_events_
              .insert(
                  {bperf_eg_ptr,
                   ManagedBPerfEventInfo<MuxGroupIdType>(mux_group_id)})
              .first;
    }
    auto& bperf_event_info = bperf_event_info_it->second;
    bperf_event_info.refCount++;

    // maintain mux_bperf_event_map_
    mux_bperf_event_map_[mux_group_id] = bperf_eg_ptr;

    // Transition newly emplaced BPerfCountReader and BPerfEventsGroup to
    // Monitor's state.
    sync_();
    return it->second;
  }

  bool eraseBPerfCountReader(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id) {
    std::lock_guard<std::mutex> lock{mutex_};
    auto bperf_count_reader_it = bperf_count_readers_.find(elem_id);
    if (bperf_count_reader_it == bperf_count_readers_.end()) {
      return false;
    }
    // maintain managed_bperf_events_
    auto bperf_event_info_it = managed_bperf_events_.find(
        bperf_count_reader_it->second->getBPerfEventsGroup());
    HBT_THROW_ASSERT_IF(bperf_event_info_it == managed_bperf_events_.end())
        << "Internl state inconsistent: a BPerfEventsGroup is owned by an "
        << "existing BPerfCountReader but is missing in managed_bperf_events_.";
    auto& bperf_event_info = bperf_event_info_it->second;
    bperf_event_info.refCount--;
    if (bperf_event_info.refCount == 0) {
      mux_bperf_event_map_.erase(bperf_event_info.muxId);
      managed_bperf_events_.erase(bperf_event_info_it);
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

    addMuxEntry_(mux_group_id, elem_id, std::nullopt);

    auto [it, emplaced] = ipt_monitors_.emplace(
        elem_id, std::make_unique<IntelPTMonitor>(std::move(ipt_gen_ctxt)));

    // Transition newly emplaced IntelPTMonitor to Monitor's state.
    sync_();
    return it->second;
  }

  std::ostream& printTraceMonitorsStatus(
      std::ostream& os,
      const cpu_set_t& cpus) const;

  std::ostream& printCpuCountReadersStatus(
      std::ostream& os,
      const cpu_set_t& cpus) const;

  std::ostream& printUncoreCountReadersStatus(std::ostream& os) const;

  std::ostream& printBPerfCountReadersStatus(std::ostream& os) const;

  std::ostream& printMuxQueueStatus(std::ostream& os) const;

  std::string statusStr(const CpuSet& cpus) const {
    std::ostringstream os;

    auto cpuset = cpus.cpu_set;
    printMuxQueueStatus(os);
    printTraceMonitorsStatus(os, cpuset);
    printCpuCountReadersStatus(os, cpuset);
    printBPerfCountReadersStatus(os);
    printUncoreCountReadersStatus(os);
    return os.str();
  }

#ifdef HBT_ENABLE_TRACING
  size_t numTraceMonitors() const {
    std::lock_guard<std::mutex> lock{mutex_};
    return trace_monitors_.size();
  }
#endif // HBT_ENABLE_TRACING

  size_t numCpuCountReaders() const {
    std::lock_guard<std::mutex> lock{mutex_};
    return cpu_count_readers_.size();
  }

  size_t numUncoreCountReaders() const {
    std::lock_guard<std::mutex> lock{mutex_};
    return uncore_count_readers_.size();
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

  std::unordered_map<ElemId, std::shared_ptr<TCpuCountReader>>
      cpu_count_readers_;
  std::unordered_map<ElemId, std::shared_ptr<TUncoreCountReader>>
      uncore_count_readers_;

#ifdef HBT_ENABLE_BPERF
  std::unordered_map<ElemId, std::shared_ptr<TBPerfCountReader>>
      bperf_count_readers_;
  // a ref count to BPerfEventsGroup shared by the BPerfCountReaders above
  // BPerfEventsGroup is owned by any BPerfCountReader that takes a shared
  // pointer to it bperf_count_readers_ doesn't own the object and need to
  // synchronize with insert/erase of BPerfCountReader to make sure the stored
  // raw pointer is always valid.
  std::unordered_map<TBPerfEventsGroup*, ManagedBPerfEventInfo<MuxGroupIdType>>
      managed_bperf_events_;
  std::unordered_map<MuxGroupId, TBPerfEventsGroup*> mux_bperf_event_map_;
#endif // HBT_ENABLE_BPERF

  /// Mapping from MuxGroupId to MuxGroup. Each MuxGroup contains
  /// ElemIds of the TraceMonitors, CountReaders, BPerfCountReaders
  /// and IntelPTMonitors in it.
  std::unordered_map<ElemId, std::shared_ptr<IntelPTMonitor>> ipt_monitors_;

  std::unordered_map<MuxGroupId, MuxGroup> mux_groups_;

  std::
      unordered_map<std::optional<perf_event::PmuType>, std::vector<MuxGroupId>>
          mux_queue_;

  bool mux_queue_per_pmu_type_;

  // Whether reset a counter's value to 0 at the moment when state is transited
  // to State::Enabled.
  // Note only value will be reset. Enabled/running time will not reset. Check
  // perf_event_open(2): PERF_EVENT_IOC_RESET for more details.
  // BPerf doesn't support reset = true mode.
  bool reset_;

  // Mark as mutable to allow usage from const methods.
  mutable std::mutex mutex_;

  std::unordered_set<MuxGroupId> getEnabledMuxGroupId_() const {
    std::unordered_set<MuxGroupId> ret;
    for (const auto& [perf_event_type, queue] : mux_queue_) {
      if (queue.size() > 0) {
        ret.insert(queue.front());
      }
    }
    return ret;
  }

  std::optional<perf_event::PmuType> getPmuTypeOfMetric(
      const perf_event::MetricDesc& metric_desc,
      const perf_event::PmuDeviceManager& pmu_manager) const {
    if (mux_queue_per_pmu_type_) {
      auto event_refs = metric_desc.getEventRefs(pmu_manager.cpuInfo.cpu_arch);
      HBT_THROW_ASSERT_IF(!event_refs.has_value() || event_refs.value().empty())
          << "No event refs found for metric " << metric_desc;
      // If a metric contains events of different PmuTypes, this metric cannot
      // be emplaced into a Monitor with mux_queue_per_pmu_type_.
      for (const auto& event_ref : event_refs.value()) {
        HBT_THROW_ASSERT_IF(event_ref.pmu_type != event_refs->at(0).pmu_type)
            << "Expect all events in the metric " << metric_desc
            << " have the same PmuType but not";
      }
      return event_refs->at(0).pmu_type;
    }
    return std::nullopt;
  }

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

  void sync_(
      bool uncore_local = false, /* enable/disable uncore events on the CPU owns that perf event */
      bool core_local = false /* enable/disable core events on the CPU owns that perf event */);

  template <class TElemType>
  void commitElemChange_(
      const std::vector<TElemType*>& to_close,
      const std::vector<TElemType*>& to_open,
      const std::vector<TElemType*>& to_enable);
  template <class TElemType>
  void commitElemChangeOnLocalCpu_(
      const std::vector<TElemType*>& to_close,
      const std::vector<TElemType*>& to_open,
      const std::vector<TElemType*>& to_enable);
  // Transition all elements in container.
  template <class TContainer>
  void syncElems_(TContainer& elems_container, bool on_local_cpu);
#ifdef HBT_ENABLE_BPERF
  void syncElems_(
      std::unordered_map<MuxGroupId, TBPerfEventsGroup*>& bperf_events,
      bool on_local_cpu);
#endif
  void addMuxEntry_(
      const MuxGroupId& mux_group_id,
      const ElemId& elem_id,
      std::optional<perf_event::PmuType> pmu_type) {
    auto& g = mux_groups_[mux_group_id];
    if (g.empty()) {
      mux_queue_[pmu_type].push_back(mux_group_id);
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
      bool removed = false;
      mux_groups_.erase(mux_group_id);
      for (auto& [pmu_type, queue] : mux_queue_) {
        const auto groupIdIt =
            std::find(queue.begin(), queue.end(), mux_group_id);
        if (groupIdIt == queue.cend()) {
          continue;
        }
        queue.erase(groupIdIt);
        removed = true;
      }
      if (!removed) {
        HBT_THROW_ASSERT() << "mux_group_id \""
                           << mux_group_id.value_or("nullopt")
                           << "\" exists in mux_groups_ but not in mux_queue_";
      }
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
std::ostream& Monitor<MuxGroupId, ElemId>::printCpuCountReadersStatus(
    std::ostream& os,
    const cpu_set_t& cpus) const {
  std::lock_guard<std::mutex> lock{mutex_};
  if (cpu_count_readers_.size() == 0) {
    os << "\nNo Cpu Count Readers\n";
    return os;
  }
  os << "\n<PerCpuCountReaders>\n";
  for (const auto& [k, cr] : cpu_count_readers_) {
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

template <class MuxGroupId, class ElemId>
std::ostream& Monitor<MuxGroupId, ElemId>::printUncoreCountReadersStatus(
    std::ostream& os) const {
  std::lock_guard<std::mutex> lock{mutex_};
  if (uncore_count_readers_.size() == 0) {
    os << "\nNo Uncore Count Readers\n";
    return os;
  }
  os << "\n<PerUncoreCountReaders>\n";
  for (const auto& [k, cr] : uncore_count_readers_) {
    if (cr == nullptr) {
      os << "No status for: " << k << "\n";
    } else {
      os << fmt::format("PerUncoreCountReader {}\n", k);
      cr->printStatus(os);
      os << "\n";
    }
  }
  os << "<End of PerUncoreCountReaders>\n";
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
  os << "\n";
  if (mux_queue_.size() == 0) {
    os << " <No Groups>";
    return os;
  }
  for (const auto& [pmu_type, queue] : mux_queue_) {
    if (pmu_type.has_value()) {
      os << '[' << perf_event::PmuTypeToStr(pmu_type.value()) << ']' << '\n';
    } else {
      os << '[' << "all_pmus" << ']' << "\n";
    }
    for (const auto& g_id : queue) {
      os << fmt::format(
          " <{}: {}>", g_id.value_or("<None>"), mux_groups_.at(g_id));
    }
  }
  return os;
}

//
// Finite State Machine to handle state transitions.
//

template <class TMonitor, class TGen, class... Args>
void tryOpen_(TGen& gen, Args&&... args) {
  // BPerfEventsGroup does not define open method.
  // It's only enable and disable.
  if (!gen.isOpen()) {
    gen.open(std::forward<Args>(args)...);
  }
}

template <class TMonitor, class TGen, class... Args>
void tryOpenForCpu_(TGen& gen, CpuId cpu, Args&&... args) {
  if (!gen.isOpenOnCpu(cpu)) {
    gen.openForCpu(cpu);
  }
}

template <class TGen>
void tryEnable_(TGen& gen, bool reset) {
  if (!gen.isEnabled()) {
    gen.enable(reset);
  }
}

template <class TGen>
void tryEnableForCpu_(TGen& gen, bool reset, CpuId cpu) {
  if (!gen.isEnabledOnCpu(cpu)) {
    gen.enableForCpu(cpu, reset);
  }
}

template <class TMonitor, class TGen>
void tryClose_(TGen& gen) {
  if (gen.isOpen()) {
    gen.close();
  }
}

template <class TMonitor, class TGen>
void tryCloseForCpu_(TGen& gen, CpuId cpu) {
  if (gen.isOpenOnCpu(cpu)) {
    gen.closeForCpu(cpu);
  }
}

template <class TGen>
void tryDisable_(TGen& gen) {
  if (gen.isEnabled()) {
    gen.disable();
  }
}

template <class TGen>
void tryDisableForCpu_(TGen& gen, CpuId cpu) {
  if (gen.isEnabledOnCpu(cpu)) {
    gen.disableForCpu(cpu);
  }
}

template <class MuxGroupId, class ElemId>
template <class TElemType>
void Monitor<MuxGroupId, ElemId>::commitElemChange_(
    const std::vector<TElemType*>& to_close,
    const std::vector<TElemType*>& to_open,
    const std::vector<TElemType*>& to_enable) {
  using TMonitor = std::decay_t<decltype(*this)>;
// Following the order of elemToClose -> elemToOpen -> elemToEnable to
// guarantee enable happened after, or there might be a burst of multiplexing
#ifdef HBT_ENABLE_BPERF
  constexpr bool bperf = std::is_same_v<TElemType*, TBPerfEventsGroup*>;
#else
  constexpr bool bperf = false;
#endif
  // BPerf doesn't support reset = true mode.
  bool reset = bperf ? false : reset_;
  for (const auto elem_ptr : to_close) {
    tryDisable_(*elem_ptr);
    tryClose_<TMonitor>(*elem_ptr);
  }
  for (const auto elem_ptr : to_open) {
    tryDisable_(*elem_ptr);
    tryOpen_<TMonitor>(*elem_ptr);
  }
  for (const auto& elem_ptr : to_enable) {
    tryOpen_<TMonitor>(*elem_ptr);
    tryEnable_(*elem_ptr, reset);
  }
}

template <class MuxGroupId, class ElemId>
template <class TElemType>
void Monitor<MuxGroupId, ElemId>::commitElemChangeOnLocalCpu_(
    const std::vector<TElemType*>& to_close,
    const std::vector<TElemType*>& to_open,
    const std::vector<TElemType*>& to_enable) {
  using TMonitor = std::decay_t<decltype(*this)>;
  std::set<CpuId> cpus;
  for (const auto& elem : to_close) {
    cpus.merge(elem->listCpus());
  }
  for (const auto& elem : to_open) {
    cpus.merge(elem->listCpus());
  }
  for (const auto& elem : to_enable) {
    cpus.merge(elem->listCpus());
  }
  cpu_set_t prev_mask, mask;
  CPU_ZERO(&prev_mask);
  if (sched_getaffinity(0, sizeof(cpu_set_t), &prev_mask) != 0) {
    HBT_LOG_ERROR() << "Failed to get CPU affinity: " << errno;
    return;
  }
  for (auto cpu : cpus) {
    CPU_ZERO(&mask);
    CPU_SET(cpu, &mask);
    if (sched_setaffinity(0, sizeof(mask), &mask) != 0) {
      HBT_LOG_ERROR() << "Failed to set sched affinity on CPU " << cpu;
      return;
    }
    for (const auto elem_ptr : to_close) {
      tryDisableForCpu_(*elem_ptr, cpu);
      tryCloseForCpu_<TMonitor>(*elem_ptr, cpu);
    }
    for (const auto elem_ptr : to_open) {
      tryDisableForCpu_(*elem_ptr, cpu);
      tryOpenForCpu_<TMonitor>(*elem_ptr, cpu);
    }
    for (const auto elem_ptr : to_enable) {
      tryOpenForCpu_<TMonitor>(*elem_ptr, cpu);
      tryEnableForCpu_(*elem_ptr, reset_, cpu);
    }
  }
  // restore previous CPU affinity
  if (sched_setaffinity(0, sizeof(prev_mask), &prev_mask) != 0) {
    HBT_LOG_ERROR() << "Failed to restore to pervious affinity mask";
  }
}

#ifdef HBT_ENABLE_BPERF
template <class MuxGroupId, class ElemId>
void Monitor<MuxGroupId, ElemId>::syncElems_(
    std::unordered_map<MuxGroupId, TBPerfEventsGroup*>& bperf_events,
    bool on_local_cpu) {
  HBT_ARG_CHECK_EQ(on_local_cpu, false)
      << "BPerf events doesn't support enable/disable on local cpu opt";
  std::vector<TBPerfEventsGroup*> to_close, to_open, to_enable;
  auto active_mux_ids = getEnabledMuxGroupId_();
  for (auto& [mux, bperf_events_group] : bperf_events) {
    switch (state_) {
      case State::Closed:
        to_close.push_back(bperf_events_group);
        break;
      case State::Open:
        to_open.push_back(bperf_events_group);
        break;
      case State::Enabled:
        HBT_DCHECK_GT(mux_queue_.size(), 0);
        // Only enable if it's at front of its multiplexing queue.
        if (active_mux_ids.count(mux)) {
          to_enable.push_back(bperf_events_group);
        } else {
          to_open.push_back(bperf_events_group);
        }
        break;
    }
  }
  commitElemChange_(to_close, to_open, to_enable);
}
#endif

/// Transition all elements (TraceMonitors, PerCpuCountReaders,
/// and BPerfCountReaders) inside elems_container to state.
template <class MuxGroupId, class ElemId>
template <class TContainer>
void Monitor<MuxGroupId, ElemId>::syncElems_(
    TContainer& elems_container,
    bool on_local_cpu) {
  using TElemSmartPtrType = std::decay_t<typename TContainer::mapped_type>;
  using TElemType = typename TElemSmartPtrType::element_type;
  // prepare all elements in mux enabled status
  MuxGroup enabled_elems;
  auto active_mux_ids = getEnabledMuxGroupId_();
  for (auto mux_id : active_mux_ids) {
    enabled_elems.insert(
        mux_groups_.at(mux_id).begin(), mux_groups_.at(mux_id).end());
  }
  std::vector<TElemType*> elem_to_close, elem_to_open, elem_to_enable;
  for (auto& [k, elem_ptr] : elems_container) {
    HBT_THROW_ASSERT_IF(elem_ptr == nullptr);
    switch (state_) {
      case State::Closed:
        elem_to_close.push_back(elem_ptr.get());
        break;
      case State::Open:
        elem_to_open.push_back(elem_ptr.get());
        break;
      case State::Enabled:
        // Only enable if it's at front of its multiplexing queue.
        if (enabled_elems.count(k) > 0) {
          elem_to_enable.push_back(elem_ptr.get());
        } else {
          elem_to_open.push_back(elem_ptr.get());
        }
    }
  }
  if (on_local_cpu) {
    commitElemChangeOnLocalCpu_(elem_to_close, elem_to_open, elem_to_enable);
  } else {
    commitElemChange_(elem_to_close, elem_to_open, elem_to_enable);
  }
}

/// Transitions (enable/disable, open/close)
/// all components in Monitor to the new state.
template <class MuxGroupId, class ElemId>
void Monitor<MuxGroupId, ElemId>::sync_(bool uncore_local, bool core_local) {
  if (mux_queue_.size() == 0) {
    // Empty queues have no elements to sync.
    return;
  }
#ifdef HBT_ENABLE_TRACING
  syncElems_(trace_monitors_, false);
#endif // HBT_ENABLE_TRACING
  syncElems_(cpu_count_readers_, core_local);
  syncElems_(uncore_count_readers_, uncore_local);
#ifdef HBT_ENABLE_BPERF
  syncElems_(mux_bperf_event_map_, false);
#endif // HBT_ENABLE_BPERF
  syncElems_(ipt_monitors_, false);
}

} // namespace facebook::hbt::mon
