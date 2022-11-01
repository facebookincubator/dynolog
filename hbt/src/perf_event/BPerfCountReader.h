// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/CpuEventsGroup.h"
#include "hbt/src/perf_event/Metrics.h"

namespace facebook::hbt::perf_event {

class BPerfEventsGroup;

// Wrap BPerfEventsGroup. Do not inherit because
// BPerfEventsGroup expands eBPF macros that very lenient on type conversions
// and other compilation warnings. This gets in the way of HBT's usage of strict
// compilation mode. To avoid conflict, we keep BPerf compilation unit
// separated.
class BPerfCountReader {
 public:
  using ReadValues = GroupReadValues<mode::Counting>;

  BPerfCountReader(
      const std::string& bpf_map_name,
      std::shared_ptr<const MetricDesc> metric_desc_in,
      std::shared_ptr<const PmuDeviceManager> pmu_manager_in,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper);

  size_t getNumEvents() const;

  ReadValues makeReadValues() const;

  bool enable();

  bool disable();

  bool read(ReadValues& rv, bool skip_offset = false);

  std::optional<ReadValues> read(bool skip_offset = false);

  bool isEnabled() const;

  std::ostream& printStatus(std::ostream& os);

  const std::shared_ptr<const PmuDeviceManager> pmu_manager;
  const std::shared_ptr<const MetricDesc> metric_desc;

  ~BPerfCountReader();

 protected:
  // Use raw pointer because BPerfEventsGroup is only a forward declaration
  // here, as we don't want to include BPerfEventsGroup due to different
  // compilation flags.
  BPerfEventsGroup* bperf_eg_;
};

} // namespace facebook::hbt::perf_event
