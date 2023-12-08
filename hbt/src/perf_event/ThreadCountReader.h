// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/Metrics.h"
#include "hbt/src/perf_event/PerfEventsGroup.h"

#include <memory>

namespace facebook::hbt::perf_event {

//
// CRTP extension of CpuEventsGroupBase<>.
//
// Read counters from perf_event groups.
// It relies on perf_events opened on counting mode.
//

class ThreadCountReaderImpl
    : public PerfEventsGroupBase<ThreadCountReaderImpl, mode::Counting> {
 public:
  using TBase = PerfEventsGroupBase<ThreadCountReaderImpl, mode::Counting>;

  /// Convenience type definition to create structure to store read values.
  using ReadValues = GroupReadValues<mode::Counting>;

  ThreadCountReaderImpl(
      const std::vector<std::string>& ev_names,
      EventConfs event_confs,
      pid_t pid = 0)
      : TBase{0 /*cpu*/, pid, -1 /*cgroup_fd*/, event_confs},
        event_names_{ev_names} {}

  void enableImpl() {}

  void disableImpl() {}

  void open(bool pinned) {
    this->open_counting_(0, pinned, true /*thread*/);
    HBT_THROW_ASSERT_IF(!isOpen());
  }

  const auto& getEventNames() const noexcept {
    return event_names_;
  }

 protected:
  std::vector<std::string> event_names_;
};

// A thread level counting mode performance counter
//  (1) pid argument can be left 0 (default) to measure the current thread
//      or set to pid/tid of thread you wish to track.
//  (2) Currently, this will track the thread on all CPUs.
class ThreadCountReader final : public ThreadCountReaderImpl {
 public:
  using TBase = ThreadCountReaderImpl;
  using ReadValues = ThreadCountReaderImpl::ReadValues;

  ThreadCountReader(
      std::shared_ptr<const MetricDesc> metric_desc_in,
      std::shared_ptr<const PmuDeviceManager> pmu_manager_in,
      pid_t pid = 0)
      : TBase{
        metric_desc_in->eventNicknames(pmu_manager_in->cpuInfo.cpu_arch),
        metric_desc_in->makeNoCpuTopologyConfs(*pmu_manager_in),
        pid
      },
        pmu_manager{pmu_manager_in},
        metric_desc{metric_desc_in} {
    HBT_DCHECK(pmu_manager != nullptr);
    HBT_DCHECK(metric_desc != nullptr);
  }

  size_t getNumEvents() const {
    return metric_desc->getNumEvents(pmu_manager->cpuInfo.cpu_arch).value_or(0);
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

  const std::shared_ptr<const PmuDeviceManager> pmu_manager;
  const std::shared_ptr<const MetricDesc> metric_desc;
};

inline std::ostream& operator<<(
    std::ostream& os,
    const ThreadCountReader& reader) {
  os << "Thread Counter Reader \"" << reader.metric_desc->id;
  if (reader.isEnabled()) {
    os << "\" active.\n";
    auto val = reader.read();
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

} // namespace facebook::hbt::perf_event
