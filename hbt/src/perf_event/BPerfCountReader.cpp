// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/BPerfCountReader.h"
#include "hbt/src/perf_event/BPerfEventsGroup.h"
#include "hbt/src/perf_event/CpuEventsGroup.h"
#include "hbt/src/perf_event/Metrics.h"

namespace facebook::hbt::perf_event {

BPerfCountReader::BPerfCountReader(
    const std::string& bpf_map_name,
    std::shared_ptr<const MetricDesc> metric_desc_in,
    std::shared_ptr<const PmuDeviceManager> pmu_manager_in,
    std::shared_ptr<FdWrapper> cgroup_fd_wrapper)
    : pmu_manager{pmu_manager_in}, metric_desc{metric_desc_in} {
  HBT_DCHECK(pmu_manager != nullptr);
  HBT_DCHECK(metric_desc != nullptr);

  bperf_eg_ = new BPerfEventsGroup(
      bpf_map_name,
      metric_desc_in->makeNoCpuTopologyConfs(*pmu_manager_in),
      cgroup_fd_wrapper);
}

size_t BPerfCountReader::getNumEvents() const {
  auto opt_num_events =
      this->metric_desc->getNumEvents(pmu_manager->cpuInfo.cpu_arch);
  HBT_DCHECK(opt_num_events.has_value())
      << "Must have been checked at construction";
  return opt_num_events.value_or(0);
}

BPerfCountReader::ReadValues BPerfCountReader::makeReadValues() const {
  return BPerfCountReader::ReadValues{getNumEvents()};
}

bool BPerfCountReader::enable() {
  return bperf_eg_->enable();
}

bool BPerfCountReader::disable() {
  return bperf_eg_->disable();
}

bool BPerfCountReader::read(
    BPerfCountReader::ReadValues& rv,
    bool skip_offset) {
  return bperf_eg_->read(rv, skip_offset);
}

std::optional<BPerfCountReader::ReadValues> BPerfCountReader::read(
    bool skip_offset) {
  auto rv = makeReadValues();
  if (bperf_eg_->read(rv, skip_offset)) {
    return std::make_optional(rv);
  } else {
    return std::nullopt;
  }
}

bool BPerfCountReader::isEnabled() const {
  return bperf_eg_->isEnabled();
}

std::ostream& BPerfCountReader::printStatus(std::ostream& os) {
  os << "BPerfCounterReader for \"" << metric_desc->id << "\"";
  if (this->isEnabled()) {
    auto val = this->read(false);
    if (val.has_value()) {
      return os << *val << "\n";
    } else {
      return os << " Failed to read\n";
    }
  }
  return os << " is inactive.\n";
}

BPerfCountReader::~BPerfCountReader() {
  HBT_DCHECK(bperf_eg_ != nullptr);
  delete bperf_eg_;
}

} // namespace facebook::hbt::perf_event
