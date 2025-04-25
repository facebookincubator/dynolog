// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/Defaults.h"
#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/PerCpuTraceAuxGenerator.h"
#include "hbt/src/perf_event/PmuDevices.h"

#include <filesystem>
#include <mutex>
#include <unordered_map>

namespace facebook::hbt::mon {

class IntelPTGenCtxt {
 public:
  // Factory method for IntelPT context.
  // returns `std::nullopt` in the case of failure.
  static std::optional<IntelPTGenCtxt> create(
      const hbt::perf_event::PmuDeviceManager& pmuDeviceManager,
      const CpuSet& mon_cpus,
      const std::optional<std::filesystem::path>& cgroup_name,
      size_t trace_buffer_size_pages,
      perf_event::EventExtraAttr extra_attr);

  // AUX buffer generator.
  std::unique_ptr<hbt::perf_event::PerCpuTraceAuxGenerator> trace_aux_gen;

  // The CPUs that are being traced.
  const hbt::CpuSet mon_cpus;

  // Size of the AUX buffer (in pages).
  size_t trace_buffer_size_pages;

 private:
  IntelPTGenCtxt(
      std::unique_ptr<perf_event::PerCpuTraceAuxGenerator> trace_aux_gen,
      const CpuSet& mon_cpus,
      size_t trace_buffer_size_pages)
      : trace_aux_gen{std::move(trace_aux_gen)},
        mon_cpus{mon_cpus},
        trace_buffer_size_pages{trace_buffer_size_pages} {}
};

class IntelPTMonitor {
  // State of the monitor.
  enum class State {
    Closed, // No perf_events are opened.
    Open, // perf_events are opened but disabled.
    Enabled // perf_events are opened and enabled.
  };

 public:
  explicit IntelPTMonitor(IntelPTGenCtxt&& ipt_gen_ctxt)
      : state_{State::Closed}, ipt_gen_ctxt_{std::move(ipt_gen_ctxt)} {}

  void open() {
    std::lock_guard<std::mutex> lock{state_mutex_};
    state_ = State::Open;
    sync_();
  }

  void openForCpu(CpuId cpu) {
    HBT_THROW_EINVAL() << "openForCpu() is not implemented for IntelPTMonitor";
  }

  bool isOpenOnCpu(CpuId) {
    HBT_THROW_EINVAL() << "isOpenOnCpu() is not implemented for IntelPTMonitor";
    return false;
  }

  // Enabled implies open.
  bool isOpen() const {
    std::lock_guard<std::mutex> lock{state_mutex_};
    return state_ == State::Open || state_ == State::Enabled;
  }

  void close() {
    std::lock_guard<std::mutex> lock{state_mutex_};
    state_ = State::Closed;
    sync_();
  }

  void closeForCpu(CpuId cpu) {
    HBT_THROW_EINVAL() << "closeForCpu() is not implemented for IntelPTMonitor";
  }

  void enable(bool reset = false) {
    HBT_ARG_CHECK_EQ(reset, false)
        << "IntelPTMonitor does not support resetting counters";
    std::lock_guard<std::mutex> lock{state_mutex_};
    state_ = State::Enabled;
    sync_();
  }

  void enableForCpu(bool reset, CpuId) {
    HBT_THROW_EINVAL()
        << "enableForCpu() is not implemented for IntelPTMonitor";
  }

  bool isEnabled() const {
    std::lock_guard<std::mutex> lock{state_mutex_};
    return state_ == State::Enabled;
  }

  bool isEnabledOnCpu(CpuId) const {
    HBT_THROW_EINVAL()
        << "isEnabledOnCpu() is not implemented for IntelPTMonitor";
    return false;
  }

  void disable() {
    std::lock_guard<std::mutex> lock{state_mutex_};
    state_ = State::Open;
    sync_();
  }

  void disableForCpu(CpuId) {
    HBT_THROW_EINVAL()
        << "disableForCpu() is not implemented for IntelPTMonitor";
  }

  std::set<CpuId> listCpus() const {
    std::lock_guard<std::mutex> lock{state_mutex_};
    return getMonCpus().asSet();
  }

  ~IntelPTMonitor() {
    close();
  }

  // Collect the per CPU trace data.
  // Returns std::nullopt if collection fails for any CPU.
  std::optional<std::unordered_map<CpuId, perf_event::AuxSpaceData>>
  collectTraceData() const;

  const CpuSet& getMonCpus() const {
    return ipt_gen_ctxt_.mon_cpus;
  }

  // Calls `callback` on each CPUs trace buffer.
  // Throws an exception if collecting the trace data or `callback` encounters
  // an error.
  //
  // This method provides a "zero-copy" way to operate on the trace data.
  // For example, `callback` could contain the logic to directly upload the
  // trace data to remote storage without requiring unncessary copy operations.
  void onCpusTraceBufferRead(perf_event::OnRbReadCallback callback);

 private:
  // Current state of the monitor, initally Closed.
  State state_;

  // Mark as mutable to allow usage from const methods.
  mutable std::mutex state_mutex_;

  // Context to configure and control the trace (AUX) buffer.
  IntelPTGenCtxt ipt_gen_ctxt_;

  void sync_();
};

} // namespace facebook::hbt::mon
