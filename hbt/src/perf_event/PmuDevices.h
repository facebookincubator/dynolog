// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/perf_event/PmuEvent.h"
#include "hbt/src/perf_event/json_events/generated/CpuArch.h"

#include <bitset>
#include <map>
#include <memory>
#include <numeric>
#include <variant>
#include <vector>

namespace facebook::hbt::perf_event {

inline std::string toCanonicalEventId(EventId ev_id) {
  transform(ev_id.begin(), ev_id.end(), ev_id.begin(), ::tolower);
  std::replace(ev_id.begin(), ev_id.end(), '-', '_');
  return ev_id;
}

struct LibPfm4EventGroup {
  std::string key;
  uint64_t code;
  std::vector<EventDef> ev_defs;

  /// Best effort attempt to get description.
  std::optional<std::string> getDescription() const {
    if (ev_defs.size() == 0) {
      return std::nullopt;
    }
    if (ev_defs.size() == 1) {
      return ev_defs.at(0).brief_desc;
    }

    // Most event descriptions have a ';' separating
    // the common part from the umask specific part.
    const auto& s = ev_defs.at(0).brief_desc;
    return s.substr(0, s.find_first_of(';'));
  }

  /// Get first part of event name.
  static std::string groupKeyFromEventId(const EventId& ev_id) {
    return ev_id.substr(0, ev_id.find_first_of('.'));
  }

  /// Get last part of event name. May be empty.
  static std::optional<std::string> eventVariationFromEventId(
      const EventId& ev_id) {
    auto pos = ev_id.find_first_of('.');
    if (pos == std::string::npos || pos == ev_id.size()) {
      return std::nullopt;
    }
    return ev_id.substr(pos + 1);
  }
};

using LibPfm4EventGroups = std::map<std::string, LibPfm4EventGroup>;

/// An instance representing a system's PMU (a Performance Monitoring Unit).
/// It can be statically enumerated PMU or a dynamic one.
class PmuDevice {
 public:
  PmuDevice(
      const std::string& pmu_name,
      PmuType pmu_type,
      std::optional<unsigned> pmu_device_enumeration,
      uint32_t perf_pmu_id,
      const std::string& desc,
      bool in_sysfs)
      : pmu_name_{pmu_name},
        pmu_type_{pmu_type},
        pmu_device_enumeration_{pmu_device_enumeration},
        perf_pmu_id_{perf_pmu_id},
        desc_{desc},
        in_sysfs_{in_sysfs} {}

  PmuDevice(const PmuDevice&) = delete;
  PmuDevice(PmuDevice&&) = delete;

  auto getName() const noexcept {
    return pmu_name_;
  }

  auto getPmuType() const noexcept {
    return pmu_type_;
  }

  auto getPmuId() const noexcept {
    return perf_pmu_id_;
  }

  auto getDesc() const noexcept {
    return desc_;
  }

  auto getPmuDevEnumeration() const noexcept {
    return pmu_device_enumeration_;
  }

  auto inSysFs() const noexcept {
    return in_sysfs_;
  }

  auto getFullName() const noexcept {
    if (getPmuDevEnumeration()) {
      return getName() + "_" + std::to_string(*pmu_device_enumeration_);
    }

    return getName();
  }

  auto getCpuMask() const noexcept {
    return cpu_mask_;
  }

  const auto& getEventDefs() const noexcept {
    return event_defs_;
  }

  // perf_event_attr config fields.
  enum class ConfigType {
    config,
    config1,
    config2,
  };

  struct FormatAttr {
    std::string name;
    ConfigType type;
    uint8_t msb;
    uint8_t len;
  };

  using SysFsDeviceCaps = std::map<std::string, std::string>;
  using SysFsDeviceFormat = std::map<std::string, FormatAttr>;

  // Entries in format subfolder
  // (/sys/devices/<pmu_name>/format).
  SysFsDeviceFormat format;

  // Entries in capabilities subfolder (caps)
  // (/sys/devices/<pmu_name>/caps).
  SysFsDeviceCaps caps;

  /// Get EventDefs grouped by preffix of event_id until first dot.
  /// If no dot, then take the full name.
  std::unique_ptr<LibPfm4EventGroups> makeLibPfm4Groups() const;

  std::shared_ptr<EventDef> findEventDef(const EventId& ev_id) const {
    auto it = event_defs_.find(ev_id);
    if (it == event_defs_.end()) {
      auto opt_ev_id = findEventIdByAlias_(ev_id);
      if (opt_ev_id.has_value()) {
        return findEventDef(*opt_ev_id);
      } else {
        return nullptr;
      }
    }
    HBT_ARG_CHECK_EQ(it->first, ev_id);
    return it->second;
  }

  /// If aliases is nullopt, add default aliases.
  /// Default aliases are non-empty iff the event id contains a '-' or a '_'.
  /// And they are:
  ///  - A version of event_id with all '-' as '_' (if distinct to event id).
  ///  - A version of event_id with all '_' as '-' (if distinct to event id).
  void addEvent(
      std::shared_ptr<EventDef> ev_def,
      std::optional<std::vector<EventId>> aliases = std::nullopt) {
    // Validate before adding so there is no need to rollback in error.
    HBT_ARG_CHECK(event_defs_.count(ev_def->id) == 0)
        << "An event with id \"" << ev_def->id
        << "\" already exists in PMU with id: \"" << getPmuId()
        << "\" and name: \"" << getFullName() << "\"";

    if (aliases.has_value()) {
      for (const auto& alias : *aliases) {
        HBT_ARG_CHECK(ev_def->id != alias && event_defs_.count(alias) == 0)
            << "Tried to register an alias equal to an already existing event id. "
            << "Event ID: \"" << alias << "\" "
            << "already exists in PMU with id: \"" << getPmuId() << "\""
            << " and name: \"" << getFullName() << "\"";

        HBT_ARG_CHECK_EQ(aliases_.count(alias), 0)
            << "Alias \"" << alias << "\" already exists in PMU with "
            << "id: \"" << getPmuId() << "\" and name: \"" << getFullName()
            << "\"";
      }
    }

    bool has_dashes = ev_def->id.find("-") != std::string::npos;
    bool has_upper =
        std::any_of(ev_def->id.begin(), ev_def->id.end(), ::isupper);
    if (has_dashes || has_upper) {
      aliases = std::vector<EventId>();
      // Make a copy to hold replaced values.
      auto s = toCanonicalEventId(ev_def->id);
      HBT_DCHECK_NE(s, ev_def->id);
      aliases->push_back(s);
    }

    // Now add, validation already happened so there should be no errors.
    auto [_, added] = event_defs_.emplace(ev_def->id, ev_def);
    HBT_DCHECK(added);
    if (aliases.has_value()) {
      addAliases(ev_def->id, *aliases);
    }
  }

  void addAliases(const EventId& ev_id, const std::vector<EventId>& aliases);

  /// Calculate perf_event_attr::config, as done in kernel's
  /// linux/arch/x86/include/asm/perf_event.h macro X86_RAW_EVENT_MASK.
  EventConf makeConf(
      const EventId& ev_id,
      EventExtraAttr extra_attr,
      EventValueTransforms transforms) const {
    auto evdef = this->findEventDef(ev_id);
    HBT_ARG_CHECK(evdef != nullptr) << "No event with ev_id \"" << ev_id
                                    << "\" in PMU with id:  " << getPmuId()
                                    << " and name: \"" << getFullName() << "\"";
    auto configs = evdef->makeConfigs(getPmuId());
    return {
        .id = ev_id,
        .configs = configs,
        .extra_attr = extra_attr,
        .transforms = transforms};
  }

 protected:
  const std::string pmu_name_;

  // A PMU Device can be identified uniquely in two distinct
  // ways:
  //   1. (pmu_type_, pmu_device_enumarition), this is akin to how
  //   devices are exposed in sys fs.
  //   2. perf_pmu_id_ an unique ID internally by the kernel and exposed
  //   in sys fs as a file. This is what is passed into perf_event_attr.
  //
  //   Note that multiple devices of the same PmuType is normal (like
  //   it is the case for uncore PMUs).
  const PmuType pmu_type_;
  // Index for this device among others of the same type.
  std::optional<unsigned> pmu_device_enumeration_;
  // PMU's kernel ID.
  const uint32_t perf_pmu_id_;

  const std::string desc_;

  bool in_sysfs_;

  // Alias as key, original event ID as value.
  std::map<EventId, std::shared_ptr<EventDef>> event_defs_;
  std::map<EventId, EventId> aliases_;

  // PMUs that are not per-core can be opened for any
  // CPU within a CPU group. In uncore PMUs, this is
  // equivalent to the cpu_mask attr in its sys fs entry.
  std::optional<cpu_set_t> cpu_mask_ = std::nullopt;

  std::optional<EventId> findEventIdByAlias_(const EventId& ev_id) const {
    auto it = aliases_.find(ev_id);
    if (it == aliases_.end()) {
      return std::nullopt;
    }
    return it->second;
  }
};

using PerCpuEventConfs = std::map<CpuId, EventConfs>;

/// Container for all types and instances of PMUs in the system.
class PmuDeviceManager {
 public:
  static constexpr char kSysFsTracingEventsRoot[] =
      "/sys/kernel/debug/tracing/events";

  /// A PmuDevice is mapped to one or more CPUs.
  /// A PmuGroup is the map of all PmuDevices of same type.
  /// The key in the group is the PmuDevice index.
  /// Use ordered maps to keep order consistent between runs.
  using TPmuGroup =
      std::map<std::optional<unsigned>, std::shared_ptr<PmuDevice>>;

  /// First key is PmuType.
  /// Use ordered maps to keep order consistent between runs.
  using TPmuGroups = std::map<PmuType, TPmuGroup>;

  const CpuInfo cpuInfo;

  explicit PmuDeviceManager(CpuInfo cpu_info_in) : cpuInfo(cpu_info_in) {}

  // Sync PMUs exposed in /sys/devices with those in pmu_groups_.
  void loadSysFsPmus();

  void addPmu(std::shared_ptr<PmuDevice> pmu);

  /// Add event to all PMU devices of event's pmu_type.
  /// It could be a specific PMU device or a type.
  int addEvent(
      std::shared_ptr<EventDef> ev,
      std::optional<std::vector<EventId>> aliases = std::nullopt);

  /// List all static tracepoint categories defined
  /// in /sys/kernel/debug/tracing/events.
  std::vector<std::string> listTracepointCategories();

  /// Read all pairs (event_name, event_id) for all static tracepoints of the
  /// given category defined in /sys/kernel/debug/tracing/events/<category>.
  std::vector<std::pair<std::string, int32_t>> listTracepointEvents(
      const std::string& category);

  const auto& getPmuGroups() const {
    return pmu_groups_;
  }

  size_t getPmuGroupSize(PmuType pmu_type) const {
    auto it = pmu_groups_.find(pmu_type);
    if (it == pmu_groups_.end()) {
      return 0;
    }
    return it->second.size();
  }

  size_t getNumPmus() const {
    return std::accumulate(
        pmu_groups_.begin(),
        pmu_groups_.end(),
        0u,
        [](const size_t& s, const auto& pmus_it) -> size_t {
          return s + pmus_it.second.size();
        });
  }

  std::shared_ptr<PmuDevice> findPmuDeviceByName(std::string pmu_id_str);

  std::set<std::string> getPmuNames() const;

  /// Some PMUs are package-wide (or another domain).
  /// Those require events to be opened in only one CPU in domain.
  /// Also, some PMU types have multiple devices and one event
  /// must be created in each.
  /// This method returns a map of CpuId to EventConfs that
  /// need to be opened in each CPU for the desired event
  /// to be monitored.
  /// (Recall that events may be defined per-PMU type, not
  /// PMU device).
  void makePerCpuConfs(
      PmuType pmu_type,
      EventId ev_id,
      EventExtraAttr extra_attrs,
      EventValueTransforms transforms,
      cpu_set_t mon_cpus,
      PerCpuEventConfs& per_cpu_confs) const;

  /// Utility method to simplify initialization
  /// of events that do not change with CPU ID
  /// (e.g. core or software events).
  EventConf makeNoCpuTopologyConf(
      PmuType pmu_type,
      EventId ev_id,
      EventExtraAttr extra_attrs,
      EventValueTransforms transforms) const;

  std::shared_ptr<EventDef> findEventDef(
      std::string ev_id_str,
      std::optional<PmuType> pmu_type_arg = std::nullopt,
      std::optional<std::string> pmu_name_arg = std::nullopt);

  int addAliases(const EventId& ev_id, const std::vector<EventId>& aliases);

  int addAliases(
      std::shared_ptr<EventDef> ev,
      const std::vector<EventId>& aliases);

 protected:
  TPmuGroups pmu_groups_;

  void updateSysFsPmus_();
};

inline std::ostream& operator<<(
    std::ostream& os,
    const PmuDeviceManager& pmu_m) {
  os << "<PmuDeviceManager " << pmu_m.getNumPmus() << " PMUs ";
  os << ">";
  return os;
}

} // namespace facebook::hbt::perf_event
