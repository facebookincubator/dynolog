// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/perf_event/PerPerfEventsGroupBase.h"

namespace facebook::hbt::perf_event {

template <class TPerfEventGroupGenBase>
class PerCpuBase : public PerPerfEventsGroupBase<TPerfEventGroupGenBase> {
 public:
  using TBase = PerPerfEventsGroupBase<TPerfEventGroupGenBase>;
  PerCpuBase(
      const CpuSet& mon_cpus,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper)
      : TBase(cgroup_fd_wrapper), mon_cpus_{mon_cpus} {
    for_each_cpu(cpu, mon_cpus) {
      TBase::generators_.insert(std::make_pair(static_cast<int>(cpu), nullptr));
    }
  }
  auto getMonCpus() const {
    return mon_cpus_;
  }
  const TPerfEventGroupGenBase& getCpuGenerator(CpuId cpu) const {
    auto key = static_cast<int>(cpu);
    HBT_ARG_CHECK(TBase::generators_.count(key))
        << "CPU " << std::to_string(key) + " not monitored";
    HBT_ARG_CHECK(TBase::generators_.at(key) != nullptr)
        << "No generator in CPU " << key;
    return *TBase::generators_.at(key);
  }

  TPerfEventGroupGenBase& getCpuGenerator(CpuId cpu) {
    auto key = static_cast<int>(cpu);
    HBT_ARG_CHECK(TBase::generators_.count(key))
        << "CPU " << std::to_string(key) + " not monitored";
    HBT_ARG_CHECK(TBase::generators_.at(key) != nullptr)
        << "No generator in CPU " << key;
    return *TBase::generators_.at(key);
  }

  auto getCpuGeneratorPtr(CpuId cpu) {
    auto key = static_cast<int>(cpu);
    HBT_ARG_CHECK(TBase::generators_.count(key))
        << "CPU " << std::to_string(key) + " not monitored";
    HBT_ARG_CHECK(TBase::generators_.at(key) != nullptr)
        << "No generator in CPU " << key;
    return TBase::generators_.at(key);
  }

 protected:
  CpuSet mon_cpus_;
};

} // namespace facebook::hbt::perf_event
