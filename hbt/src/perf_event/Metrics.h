// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/perf_event/PmuDevices.h"
#include "hbt/src/perf_event/PmuEvent.h"
#include "hbt/src/perf_event/json_events/generated/CpuArch.h"

#include <map>
#include <memory>
#include <variant>

namespace facebook::hbt::perf_event {

using MetricId = std::string;

struct EventRef {
  /// The way the event is named within the context of the enclosing metric.
  std::string nickname;
  PmuType pmu_type;
  EventId event_id;
  EventExtraAttr extra_attr;
  EventValueTransforms transforms;
};

std::ostream& operator<<(std::ostream& os, const EventRef& ev_ref);

using EventRefs = std::vector<EventRef>;

// TOptCpuArch is an optional, note that TOptCpuArch == std::nullopt
// means that CpuArch is unspecified (architecture may be known or unknown).
// This is different from CpuArch::Unknown that implies an unknown
// architecture (we know that the archictecture is unknown).
using TOptCpuArch = std::optional<CpuArch>;

std::ostream& operator<<(std::ostream& os, const TOptCpuArch& cpu_arch);

/// Heartbeat users mostly interact with Metrics.
/// Metrics encompass sets of events and ways to model their interactions
/// into an useful value.
// XXX: Sampling rate and analysis type should be part of the metric.
struct MetricDesc {
  MetricId id;
  std::string brief_desc;
  std::string full_desc;
  std::map<TOptCpuArch, EventRefs> event_refs_by_arch;
  uint64_t default_sampling_period;
  System::Permissions req_permissions;
  std::vector<std::string> dives;

  MetricDesc(
      MetricId id,
      const std::string& brief_desc,
      const std::string& full_desc,
      const std::map<TOptCpuArch, EventRefs>& event_refs_by_arch,
      uint64_t default_sampling_period,
      const System::Permissions& req_permissions,
      const std::vector<std::string> dives)
      : id{id},
        brief_desc{brief_desc},
        full_desc{full_desc},
        event_refs_by_arch{event_refs_by_arch},
        default_sampling_period{default_sampling_period},
        req_permissions{req_permissions},
        dives{dives} {
    HBT_ARG_CHECK_GT(id.size(), 0);
    HBT_ARG_CHECK_GT(brief_desc.size(), 0);
    HBT_ARG_CHECK_GT(full_desc.size(), 0);
    HBT_ARG_CHECK_GT(event_refs_by_arch.size(), 0);
  }

  MetricDesc(const MetricDesc&) = delete;
  MetricDesc(MetricDesc&&) = delete;

  /// Make EventConfs for each CPU in mon_cpus.
  EventConfs makeNoCpuTopologyConfs(const PmuDeviceManager& pmu_manager) const {
    const auto& event_refs = getEventRefs(pmu_manager.cpuInfo.cpu_arch);
    HBT_ARG_CHECK(event_refs.has_value())
        << "No EventRefs for CPU " << pmu_manager.cpuInfo.cpu_arch
        << " in metric: " << id;

    EventConfs ev_confs;
    for (const auto& ev_ref : *event_refs) {
      ev_confs.push_back(pmu_manager.makeNoCpuTopologyConf(
          ev_ref.pmu_type,
          ev_ref.event_id,
          ev_ref.extra_attr,
          ev_ref.transforms));
    }

    return ev_confs;
  }

  /// Make EventConfs for each CPU in mon_cpus.
  PerCpuEventConfs makePerCpuConfs(
      const CpuSet& mon_cpus,
      const PmuDeviceManager& pmu_manager) const {
    PerCpuEventConfs per_cpu_confs;

    const auto& event_refs = getEventRefs(pmu_manager.cpuInfo.cpu_arch);
    HBT_ARG_CHECK(event_refs.has_value())
        << "No EventRefs for CPU " << pmu_manager.cpuInfo.cpu_arch
        << " in metric: " << id;

    for (const auto& ev_ref : *event_refs) {
      pmu_manager.makePerCpuConfs(
          ev_ref.pmu_type,
          ev_ref.event_id,
          ev_ref.extra_attr,
          ev_ref.transforms,
          mon_cpus.cpu_set,
          per_cpu_confs);
    }

    return per_cpu_confs;
  }

  // List nicknames for all events for the provided CPU architecture.
  auto eventNicknames(TOptCpuArch cpu_arch) const {
    const auto& event_refs = getEventRefs(cpu_arch);
    HBT_ARG_CHECK(event_refs.has_value())
        << "No EventRefs for CPU " << cpu_arch << " in metric: " << id;
    std::vector<std::string> nicknames;
    std::transform(
        event_refs->begin(),
        event_refs->end(),
        std::back_inserter(nicknames),
        [](const auto& ev_ref) { return ev_ref.nickname; });
    return nicknames;
  }

  // Event index by nickname for current CPU architecture.
  std::optional<size_t> eventIdxFromNicknames(
      TOptCpuArch cpu_arch,
      const std::string& nickname) const {
    const auto& event_refs = getEventRefs(cpu_arch);
    if (event_refs.has_value()) {
      size_t i = 0;
      for (const auto& ev_ref : *event_refs) {
        if (ev_ref.nickname == nickname) {
          return i;
        }
        ++i;
      }
    }
    return std::nullopt;
  }

  std::optional<size_t> getNumEvents(TOptCpuArch cpu_arch) const {
    const auto& event_refs = getEventRefs(cpu_arch);
    if (!event_refs.has_value()) {
      return std::nullopt;
    } else {
      return event_refs->size();
    }
  }

  /// Return the EventRefs associated with the given CpuArch.
  std::optional<EventRefs> getEventRefs(TOptCpuArch cpu_arch) const {
    auto it = event_refs_by_arch.end();

    // First search for architecture specific events
    if (cpu_arch.has_value()) {
      it = event_refs_by_arch.find(*cpu_arch);
    }

    // Second, try with events registered for any CPU architecture.
    if (it == event_refs_by_arch.end()) {
      it = event_refs_by_arch.find(std::nullopt);
    }

    if (it == event_refs_by_arch.end()) {
      return std::nullopt;
    }
    return it->second;
  }

  std::optional<EventRefs> getEventRefs(const CpuInfo& cpu_info) const {
    return getEventRefs(cpu_info.cpu_arch);
  }
};

std::ostream& operator<<(std::ostream& os, const MetricDesc& desc);

/// Container for Metrics and their supporting event definitions.
class Metrics {
 public:
  Metrics() {}

  Metrics(const Metrics&) = delete;
  Metrics(Metrics&&) = delete;

  auto getMetricIDs() const {
    std::vector<MetricId> ids;
    for (const auto& [k, _] : metric_descs_) {
      ids.push_back(k);
    }
    return ids;
  }

  const auto& getMetricDescs() const {
    return metric_descs_;
  }

  auto getMetricDesc(const MetricId& id) const {
    const auto it = metric_descs_.find(id);
    HBT_ARG_CHECK(it != metric_descs_.end())
        << "No metric with id: \"" + id + "\"";
    return it->second;
  }

  void add(std::shared_ptr<MetricDesc> desc) {
    HBT_ARG_CHECK_EQ(metric_descs_.count(desc->id), 0)
        << "Metric ids must be unique, but \"" << desc->id
        << " \" already exists.";
    metric_descs_.emplace(desc->id, desc);
  }

 protected:
  std::map<std::string, std::shared_ptr<const MetricDesc>> metric_descs_;
};

} // namespace facebook::hbt::perf_event
