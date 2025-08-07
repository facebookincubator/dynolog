// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/Metrics.h"
#include "hbt/src/perf_event/PerPerfEventsGroupBase.h"
#include "hbt/src/perf_event/PerfEventsGroup.h"

#include <memory>
#include <utility>
#include <vector>

namespace facebook::hbt::perf_event {

//
// CRTP extension of CpuEventsGroupBase<>.
//
// Read counters from perf_event groups.
// It relies on perf_events opened on counting mode.
//
class UncoreCountReader final
    : public PerfEventsGroupBase<UncoreCountReader, mode::Counting> {
 public:
  using TBase = PerfEventsGroupBase<UncoreCountReader, mode::Counting>;

  /// Convenience type definition to create structure to store read values.
  using ReadValues = GroupReadValues<mode::Counting>;

  UncoreCountReader(
      const std::vector<std::string>& ev_names,
      CpuId cpu,
      const EventConfs& event_confs)
      : TBase{cpu, -1, -1, event_confs}, event_names_{ev_names} {}

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

class PerUncoreCountReader : public PerPerfEventsGroupBase<UncoreCountReader> {
 public:
  using TBase = PerPerfEventsGroupBase<UncoreCountReader>;
  using ReadValues = UncoreCountReader::ReadValues;

  // a unique identifier for uncore PMU devices of the same type
  // e.g. all uncore_cha devices
  struct UncoreDeviceId {
    uint16_t cpu;
    uint16_t pmu_id;
    int toInt() const {
      return static_cast<uint16_t>(pmu_id) << 16 | static_cast<uint16_t>(cpu);
    }
    explicit UncoreDeviceId(int id)
        : cpu(cpu = id & 0xffff), pmu_id(static_cast<uint32_t>(id) >> 16) {}
    UncoreDeviceId(CpuId cpu, uint32_t pmu_id)
        : cpu(static_cast<uint16_t>(cpu)),
          pmu_id(static_cast<uint16_t>(pmu_id)) {
      HBT_ARG_CHECK(
          pmu_id <= std::numeric_limits<uint16_t>::max() &&
          cpu <= std::numeric_limits<uint16_t>::max())
          << "pmu id or cpu must be equal to or smaller than 2^16-1";
    }
  };

  static int32_t generateEventsGroupId(uint32_t pmu_id, CpuId cpu) {
    return static_cast<uint16_t>(pmu_id) << 16 | static_cast<uint16_t>(cpu);
  }

  PerUncoreCountReader(
      uncore_scope::Scope scope,
      std::shared_ptr<const MetricDesc> metric_desc_in,
      std::shared_ptr<const PmuDeviceManager> pmu_manager_in)
      : TBase{nullptr},
        pmu_manager{std::move(pmu_manager_in)},
        metric_desc{std::move(metric_desc_in)} {
    HBT_DCHECK(pmu_manager != nullptr);
    HBT_DCHECK(metric_desc != nullptr);

    // theoritically, uncore events are often not belonged to a certain CPU.
    // however, linux perf system uses CPU as a part of the identifier to
    // identify a certain uncore PMU device.
    auto per_uncore_event_confs =
        metric_desc->makePerUncoreConfs(scope, *pmu_manager);

    for (const auto& [perf_pmu, conf] : per_uncore_event_confs) {
      const auto& [cpu, pmu] = perf_pmu;
      UncoreDeviceId id(cpu, pmu->getPmuId());
      this->generators_[id.toInt()] = std::make_shared<UncoreCountReader>(
          metric_desc->eventNicknames(pmu_manager->cpuInfo.cpu_arch),
          cpu,
          conf);
    }
  }
  virtual ~PerUncoreCountReader() = default;

  virtual void open(bool pinned = false) {
    try {
      for (const auto& [cpu, gen] : this->generators_) {
        gen->open(pinned);
      }
    } catch (...) {
      close();
      throw;
    }
  }

  virtual void openForCpu(CpuId cpu, bool pinned = false) {
    try {
      for (const auto& [key, gen] : this->generators_) {
        if (gen->getCpu() == cpu) {
          gen->open(pinned);
        }
      }
    } catch (...) {
      closeForCpu(cpu);
      throw;
    }
  }

  virtual void close() {
    TBase::close();
  }

  virtual void closeForCpu(CpuId cpu) {
    TBase::closeForCpu(cpu);
  }

  virtual void enable(bool reset = true) {
    TBase::enable(reset);
  }

  virtual void enableForCpu(CpuId cpu, bool reset = true) {
    TBase::enableForCpu(cpu, reset);
  }

  virtual bool isEnabled() const {
    return TBase::isEnabled();
  }

  virtual bool isEnabledOnCpu(CpuId cpu) const {
    return TBase::isEnabledOnCpu(cpu);
  }

  virtual void disable() {
    TBase::disable();
  }

  virtual void disableForCpu(CpuId cpu) {
    TBase::disableForCpu(cpu);
  }

  virtual bool isOpen() const {
    return TBase::isOpen();
  }

  virtual bool isOpenOnCpu(CpuId cpu) const {
    return TBase::isOpenOnCpu(cpu);
  }

  size_t getNumEvents() const {
    return this->metric_desc->getNumEvents(pmu_manager->cpuInfo.cpu_arch)
        .value_or(0);
  }

  /// Utility method to create ReadValues structure of the right size.
  ReadValues makeReadValues() const {
    return ReadValues{getNumEvents()};
  }

  using TBase::read;

  virtual std::optional<ReadValues> read() const {
    auto rv = makeReadValues();
    if (TBase::read(rv)) {
      return std::make_optional(rv);
    } else {
      return std::nullopt;
    }
  }

  virtual std::vector<ReadValues> readPerPerfEventsGroup() const {
    std::vector<ReadValues> rvs;
    std::map<int, GroupReadValues<mode::Counting>> res;
    TBase::readPerPerfEventsGroup(res, getNumEvents());
    rvs.reserve(res.size());
    for (const auto& [_, val] : res) {
      rvs.push_back(val);
    }
    return rvs;
  }

  virtual std::map<int, ReadValues> readPerPerfEventsGroupOnCpu(
      CpuId cpu) const {
    return TBase::readPerPerfEventsGroupOnCpu(cpu);
  }

  std::ostream& printStatus(std::ostream& os) const {
    os << "Uncore Count Reader \"" << metric_desc->id;
    if (this->isEnabled()) {
      os << "\" active.\n";
      auto val = this->read();
      if (val.has_value()) {
        os << "*val" << "\n";
      } else {
        os << " Failed to read\n";
      }
    } else {
      os << "\" inactive.\n";
    }
    return os;
  }

  const std::shared_ptr<const PmuDeviceManager> pmu_manager;
  const std::shared_ptr<const MetricDesc> metric_desc;
};

class PerUncoreCountReaderFactory {
 public:
  PerUncoreCountReaderFactory() = default;
  virtual ~PerUncoreCountReaderFactory() = default;
  virtual std::unique_ptr<PerUncoreCountReader> make(
      const std::string& /*element_id*/,
      uncore_scope::Scope scope,
      std::shared_ptr<const MetricDesc> metric_desc,
      std::shared_ptr<const PmuDeviceManager> pmu_manager) {
    return std::make_unique<PerUncoreCountReader>(
        scope, metric_desc, pmu_manager);
  }
};

} // namespace facebook::hbt::perf_event
