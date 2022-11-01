// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/CpuEventsGroup.h"

#include <map>
#include <memory>

namespace facebook::hbt::perf_event {

// Base class to make a per-CPU generator (multiple CPUs)
// from a type defined for a single CPU.
template <class TCpuBase>
class PerCpuBase {
 public:
  PerCpuBase(
      const CpuSet& mon_cpus,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper)
      : mon_cpus_{mon_cpus}, cgroup_fd_wrapper_{cgroup_fd_wrapper} {
    // Base class must initialize <cpu_generators_> entries.
    cpu_generators_.resize(mon_cpus.max_cpu_id + 1);
  }

  void close() {
    for_each_cpu(cpu, mon_cpus_) {
      getCpuGenerator(cpu).close();
    }
  }

  void enable() {
    try {
      for_each_cpu(cpu, mon_cpus_) {
        getCpuGenerator(cpu).enable();
      }
    } catch (std::exception& /*e*/) {
      for_each_cpu(cpu, mon_cpus_) {
        auto& cg = getCpuGenerator(cpu);
        if (cg.isEnabled()) {
          cg.disable();
        }
      }
      throw;
    }
  }

  bool isEnabled() const {
    // It should be all enabled or none.
    bool enabled = getCpuGenerator(mon_cpus_.cpu_first_set()).isEnabled();
    for_each_cpu(cpu, mon_cpus_) {
      HBT_THROW_ASSERT_IF(enabled != getCpuGenerator(cpu).isEnabled())
          << "CPU : " << cpu << " is not enabled while others are.";
    }
    return enabled;
  }

  void disable() {
    for_each_cpu(cpu, mon_cpus_) {
      getCpuGenerator(cpu).disable();
    }
  }

  bool isOpen() const {
    // It should be all open or none.
    bool is_open = getCpuGenerator(mon_cpus_.cpu_first_set()).isOpen();
    for_each_cpu(cpu, mon_cpus_) {
      HBT_THROW_ASSERT_IF(is_open != getCpuGenerator(cpu).isOpen())
          << "CPU : " << cpu << " is not open while others are.";
    }
    return is_open;
  }

  const TCpuBase& getCpuGenerator(CpuId cpu) const {
    HBT_ARG_CHECK(
        cpu < cpu_generators_.size() && cpu_generators_.at(cpu) != nullptr)
        << "CPU " + std::to_string(cpu) + " not monitored";
    HBT_ARG_CHECK(cpu_generators_.at(cpu) != nullptr)
        << "No generator in CPU " << cpu;
    return *cpu_generators_.at(cpu);
  }

  TCpuBase& getCpuGenerator(CpuId cpu) {
    HBT_ARG_CHECK(
        cpu < cpu_generators_.size() && cpu_generators_.at(cpu) != nullptr)
        << "CPU " + std::to_string(cpu) + " not monitored";
    return *cpu_generators_.at(cpu);
  }

  auto getCpuGeneratorPtr(CpuId cpu) {
    HBT_ARG_CHECK(
        cpu < cpu_generators_.size() && cpu_generators_.at(cpu) != nullptr)
        << "CPU " + std::to_string(cpu) + " not monitored";
    return cpu_generators_.at(cpu);
  }

  auto getMonCpus() const {
    return mon_cpus_;
  }

  template <class T = typename TCpuBase::TMode>
  mode::enable_if_counting_or_sampling<T, bool> read(
      GroupReadValues<T>& rv) const {
    if (!isOpen()) {
      return false;
    }
    rv.zero();
    GroupReadValues<T> aux(rv.getNumEvents());
    for_each_cpu(cpu, this->getMonCpus()) {
      if (!this->getCpuGenerator(cpu).read(aux)) {
        return false;
      }
      rv.accum(aux);
    }
    return true;
  }

 protected:
  CpuSet mon_cpus_;
  std::shared_ptr<FdWrapper> cgroup_fd_wrapper_;
  // Must be initialized by base class.
  std::vector<std::shared_ptr<TCpuBase>> cpu_generators_;
};

} // namespace facebook::hbt::perf_event
