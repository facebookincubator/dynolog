// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/mon/IntelPTMonitor.h"

#include <hbt/src/common/Defs.h>
#include "hbt/src/intel_pt/IptEventBuilder.h"

#include <filesystem>

namespace facebook::hbt::mon {

std::optional<IntelPTGenCtxt> IntelPTGenCtxt::create(
    const hbt::perf_event::PmuDeviceManager& pmuDeviceManager,
    const CpuSet& mon_cpus,
    const std::optional<std::filesystem::path>& cgroup_name,
    size_t trace_buffer_size_pages,
    perf_event::EventExtraAttr extra_attr) {
  if (auto ipt_builder_up =
          hbt::intel_pt::IptEventBuilder::createIptEventBuilder(
              pmuDeviceManager)) {
    // createHbtEventConf() always returns a non-null pointer
    auto eventConf =
        *ipt_builder_up->setBranch(true).setTsc(true).createHbtEventConf(
            "ipt_branch_tsc", extra_attr);
    std::shared_ptr<FdWrapper> cgroup_fd_wrapper;
    if (cgroup_name.has_value()) {
      cgroup_fd_wrapper = std::make_shared<FdWrapper>(cgroup_name->string());
    }
    auto trace_aux_gen =
        std::make_unique<hbt::perf_event::PerCpuTraceAuxGenerator>(
            mon_cpus, /*pid*/ -1, cgroup_fd_wrapper, eventConf);

    HBT_LOG_INFO() << "Intel PT buffer size (bytes): "
                   << trace_buffer_size_pages * (size_t)getpagesize();

    return IntelPTGenCtxt{
        std::move(trace_aux_gen), mon_cpus, trace_buffer_size_pages};
  } else {
    HBT_LOG_WARNING() << "Unable to create IntelPT perf event";
    return std::nullopt;
  }
}

void IntelPTMonitor::onCpusTraceBufferRead(
    perf_event::OnRbReadCallback callback) {
  std::lock_guard<std::mutex> lock{state_mutex_};
  HBT_ARG_CHECK(state_ != State::Closed)
      << "Cannot collect from IntelPTMonitor when it's in State::Closed.";

  ipt_gen_ctxt_.trace_aux_gen->onCpusAuxBufferRead(callback);
}

std::optional<std::unordered_map<CpuId, perf_event::AuxSpaceData>>
IntelPTMonitor::collectTraceData() const {
  std::lock_guard<std::mutex> lock{state_mutex_};
  if (state_ == State::Closed) {
    HBT_LOG_WARNING()
        << "Cannot collect from IntelPTMonitor when it's in State::Closed. ";
    return std::nullopt;
  }

  std::unordered_map<CpuId, perf_event::AuxSpaceData> trace_data_per_cpu;
  for_each_cpu(cpu, getMonCpus()) {
    if (auto trace_data = ipt_gen_ctxt_.trace_aux_gen->readAuxSpaceData(cpu)) {
      trace_data_per_cpu.emplace(cpu, std::move(*trace_data));
    } else {
      return std::nullopt;
    }
  }
  return trace_data_per_cpu;
}

//
// Finite State Machine to handle state transitions.
//

void tryOpen_(
    hbt::perf_event::PerCpuTraceAuxGenerator& gen,
    size_t trace_buffer_size_pages) {
  if (!gen.isOpen()) {
    gen.open(
        trace_buffer_size_pages,
        hbt::perf_event::CpuTraceAuxGenerator::AUXBufferMode::OVERWRITABLE);
  }
}

void tryEnable_(hbt::perf_event::PerCpuTraceAuxGenerator& gen) {
  if (!gen.isEnabled()) {
    gen.enable();
  }
}

void tryClose_(hbt::perf_event::PerCpuTraceAuxGenerator& gen) {
  if (gen.isOpen()) {
    gen.close();
  }
}

void tryDisable_(hbt::perf_event::PerCpuTraceAuxGenerator& gen) {
  if (gen.isEnabled()) {
    gen.disable();
  }
}

void IntelPTMonitor::sync_() {
  auto& trace_aux_gen = *ipt_gen_ctxt_.trace_aux_gen;
  switch (state_) {
    case State::Closed:
      tryDisable_(trace_aux_gen);
      tryClose_(trace_aux_gen);
      break;
    case State::Open:
      tryDisable_(trace_aux_gen);
      tryOpen_(trace_aux_gen, ipt_gen_ctxt_.trace_buffer_size_pages);
      break;
    case State::Enabled:
      tryOpen_(trace_aux_gen, ipt_gen_ctxt_.trace_buffer_size_pages);
      tryEnable_(trace_aux_gen);
      break;
  }
}

} // namespace facebook::hbt::mon
