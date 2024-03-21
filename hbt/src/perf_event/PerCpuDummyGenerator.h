// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/Metrics.h"
#include "hbt/src/perf_event/PerCpuSampleGeneratorBase.h"
#include "hbt/src/perf_event/PerfEventsGroup.h"

#include <functional>
#include <memory>

namespace facebook::hbt::perf_event {

//
// CRTP extension of CpuEventsGroup<>.
//
// Uses a dummy event that does trigger samples but still
// builds perf_event mmap pages.
// Useful to access to TSC and other information available
// in perf_event mmap page.
//
class CpuDummyGenerator final
    : public PerfEventsGroup<CpuDummyGenerator, mode::Dummy> {
 public:
  using TBase = PerfEventsGroup<CpuDummyGenerator, mode::Dummy>;

  inline static const EventConfs event_confs = {EventConf{
      .id = "sw_dummy",
      .configs = EventConfigs{
          .type = PERF_TYPE_SOFTWARE,
          .config = PERF_COUNT_SW_DUMMY}}};

  CpuDummyGenerator(CpuId cpu) : TBase{cpu, -1, -1, event_confs} {}

  void enableImpl() noexcept {}

  void disableImpl() noexcept {}

  void open() {
    TBase::open_(0, 0, true, 0);
  }

  TimeStamp getLastTimeStamp() const noexcept {
    return kInvalidTimeStamp;
  }
};

using TBasePerCpuDummyGenerator = PerCpuSampleGeneratorBase<CpuDummyGenerator>;

// Wrap many instances of CpuDummyGenerator, one per CPU.
class PerCpuDummyGenerator : public TBasePerCpuDummyGenerator {
 public:
  explicit PerCpuDummyGenerator(const CpuSet& mon_cpus)
      : TBasePerCpuDummyGenerator{mon_cpus, nullptr} {
    for_each_cpu(cpu, mon_cpus) {
      this->generators_[static_cast<int>(cpu)] =
          std::make_shared<CpuDummyGenerator>(cpu);
    }
  }

  void open() {
    for (const auto& [_, gen] : this->generators_) {
      gen->open();
    }
  }
};

} // namespace facebook::hbt::perf_event
