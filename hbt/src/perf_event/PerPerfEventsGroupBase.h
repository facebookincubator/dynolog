// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/Defs.h"
#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/PerfEventsGroup.h"

#include <map>
#include <memory>

namespace facebook::hbt::perf_event {

// Base class to manage a list of perf events group generators with the same
// config.
template <class TPerfEventGroupGenBase>
class PerPerfEventsGroupBase {
 public:
  explicit PerPerfEventsGroupBase(std::shared_ptr<FdWrapper> cgroup_fd_wrapper)
      : cgroup_fd_wrapper_{cgroup_fd_wrapper} {}

  void close() {
    for (auto& [_, gen] : generators_) {
      gen->close();
    }
  }

  void enable(bool reset = true) {
    try {
      for (auto& [_, gen] : generators_) {
        gen->enable(reset);
      }
    } catch (std::exception& /*e*/) {
      for (auto& [_, gen] : generators_) {
        if (gen->isEnabled()) {
          gen->disable();
        }
      }
      throw;
    }
  }

  bool isEnabled() const {
    HBT_THROW_ASSERT_IF(generators_.empty())
        << "PerPerfEventsGroupBase should always contain at least one generator.";
    // It should be all enabled or none.
    bool enabled = getFirstGenerator().isEnabled();
    for (const auto& [key, gen] : generators_) {
      HBT_THROW_ASSERT_IF(enabled != gen->isEnabled())
          << "Generator with key=" << key
          << " has a different isEnabled() status comparing to some other generators.";
    }
    return enabled;
  }

  void disable() {
    for (auto& [_, gen] : generators_) {
      gen->disable();
    }
  }

  bool isOpen() const {
    HBT_THROW_ASSERT_IF(generators_.empty())
        << "PerPerfEventsGroupBase should always contain at least one generator.";
    // It should be all open or none.
    bool is_open = getFirstGenerator().isOpen();
    for (const auto& [key, gen] : generators_) {
      HBT_THROW_ASSERT_IF(is_open != gen->isOpen())
          << "Generator with key=" << key
          << " has a different isOpen() status comparing to some other generators.";
    }
    return is_open;
  }

  const TPerfEventGroupGenBase& getFirstGenerator() const {
    HBT_ARG_CHECK(!generators_.empty()) << "No generator exists";
    return *generators_.begin()->second;
  }

  TPerfEventGroupGenBase& getFirstGenerator() {
    HBT_ARG_CHECK(!generators_.empty()) << "No generator exists";
    return *generators_.begin()->second;
  }

  const TPerfEventGroupGenBase& getGenerator(int key) const {
    HBT_ARG_CHECK(generators_.count(key)) << "No generator with key " << key;
    return *generators_.at(key);
  }

  TPerfEventGroupGenBase& getGenerator(int key) {
    HBT_ARG_CHECK(generators_.count(key)) << "No generator with key " << key;
    return *generators_.at(key);
  }

  auto getGeneratorPtr(int key) {
    HBT_ARG_CHECK(generators_.count(key)) << "No generator with key " << key;
    return generators_.at(key);
  }

  template <class T = typename TPerfEventGroupGenBase::TMode>
  mode::enable_if_counting_or_sampling<T, bool> read(
      GroupReadValues<T>& rv) const {
    if (!isOpen()) {
      return false;
    }
    rv.zero();
    GroupReadValues<T> aux(rv.getNumEvents());
    for (const auto& [_, gen] : generators_) {
      if (!gen->read(aux)) {
        return false;
      }
      rv.accum(aux);
    }
    HBT_LOG_WARNING()
        << "read() function will return the sum of accumulated time_enabled, time_running, and raw_value "
           "of all events. This is not the same as the sum of the kernel multiplexing adjusted values of "
           "those events. Often this is not the expected behavior.";
    return true;
  }

  // Read all events from all monitored perf events group.
  template <class T = typename TPerfEventGroupGenBase::TMode>
  mode::enable_if_counting_or_sampling<T, bool> readPerPerfEventsGroup(
      std::map<int, GroupReadValues<T>>& rv,
      size_t numEvents) const {
    if (!isOpen()) {
      return false;
    }
    GroupReadValues<T> aux(numEvents);
    for (const auto& [key, gen] : generators_) {
      if (!gen->read(aux)) {
        return false;
      }
      rv.insert(std::make_pair(key, aux));
    }
    return true;
  }

 protected:
  std::shared_ptr<FdWrapper> cgroup_fd_wrapper_;
  // a hashmap contains per perf event group generators.
  // definition of the key depends on the implementation of the class inherite
  // from this class.
  std::map<int, std::shared_ptr<TPerfEventGroupGenBase>> generators_;
};

} // namespace facebook::hbt::perf_event
