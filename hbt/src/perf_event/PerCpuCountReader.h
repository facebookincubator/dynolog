// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/CpuEventsGroup.h"
#include "hbt/src/perf_event/Metrics.h"
#include "hbt/src/perf_event/PerCpuBase.h"

#include <memory>

namespace facebook::hbt::perf_event {

//
// CRTP extension of CpuEventsGroupBase<>.
//
// Read counters from perf_event groups.
// It relies on perf_events opened on counting mode.
//
class CpuCountReader final
    : public CpuEventsGroupBase<CpuCountReader, mode::Counting> {
 public:
  using TBase = CpuEventsGroupBase<CpuCountReader, mode::Counting>;

  /// Convenience type definition to create structure to store read values.
  using ReadValues = GroupReadValues<mode::Counting>;

  CpuCountReader(
      const std::vector<std::string>& ev_names,
      CpuId cpu,
      int cgroup_fd,
      EventConfs event_confs)
      : TBase{cpu, -1, cgroup_fd, event_confs}, event_names_{ev_names} {}

  void enableImpl() {}

  void disableImpl() {}

  void open(bool pinned) {
    this->open_counting_(0, pinned);
    HBT_THROW_ASSERT_IF(!isOpen());
  }

  const auto& getEventNames() const noexcept {
    return event_names_;
  }

 protected:
  std::vector<std::string> event_names_;
};

// Wrap many instances of CpuCountReader, one per CPU.
class PerCpuCountReader : public PerCpuBase<CpuCountReader> {
 public:
  using TBase = PerCpuBase<CpuCountReader>;
  using ReadValues = CpuCountReader::ReadValues;

  PerCpuCountReader(
      const CpuSet& mon_cpus,
      std::shared_ptr<const MetricDesc> metric_desc_in,
      std::shared_ptr<const PmuDeviceManager> pmu_manager_in,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper)
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
      this->cpu_generators_[cpu] = std::make_shared<CpuCountReader>(
          metric_desc->eventNicknames(pmu_manager->cpuInfo.cpu_arch),
          cpu,
          cgroup_fd,
          per_cpu_event_confs.at(cpu));
    }
  }

  void open(bool pinned = false) {
    try {
      for_each_cpu(cpu, this->getMonCpus()) {
        this->getCpuGenerator(cpu).open(pinned);
      }
    } catch (...) {
      close();
      throw;
    }
  }

  size_t getNumEvents() const {
    return *this->metric_desc->getNumEvents(pmu_manager->cpuInfo.cpu_arch);
  }

  /// Utility method to create ReadValues structure of the right size.
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
      os << "Counter Reader \"" << metric_desc->id;
      if (this->isEnabled()) {
        os << "\" active.\n";
        auto val = this->read();
        if (val.has_value()) {
          os << *val << "\n";
        } else {
          os << " Failed to read\n";
        }
      } else {
        os << "\" inactive.\n";
      }
      return os;
    }

    os << "Counter Reader for \"" << metric_desc->id << "\":\n";
    for_each_cpu_set_t(cpu_id, cpus) {
      const auto& gen = this->getCpuGenerator(cpu_id);
      os << "\tCPU: " << cpu_id << " is "
         << (gen.isEnabled() ? "enabled" : "disabled") << "\n";
    }
    return os;
  }

  const std::shared_ptr<const PmuDeviceManager> pmu_manager;
  const std::shared_ptr<const MetricDesc> metric_desc;
};

} // namespace facebook::hbt::perf_event
