// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/PmuDevices.h"
#include <hbt/src/perf_event/PmuEvent.h>
#include <cstdint>
#include <string>

#include <filesystem>
#include <map>
#include <mutex>
#include <set>
#include <string_view>

namespace fs = std::filesystem;
namespace facebook::hbt::perf_event {

class StaticEventDefTableState {
 public:
  explicit StaticEventDefTableState(std::span<const StaticEventDef> events)
      : events_{events} {}

  std::span<const StaticEventDef> events() const noexcept {
    return events_;
  }

  std::shared_ptr<EventDef> materialize(const StaticEventDef& event) {
    std::lock_guard lock{mutex_};
    if (const auto it = materialized_.find(&event); it != materialized_.end()) {
      return it->second;
    }

    auto materialized = std::make_shared<EventDef>(materializeEventDef(event));
    materialized_.emplace(&event, materialized);
    return materialized;
  }

 private:
  const std::span<const StaticEventDef> events_;
  std::mutex mutex_;
  std::map<const StaticEventDef*, std::shared_ptr<EventDef>> materialized_;
};

std::optional<EventId> PmuDevice::findEventIdByAlias_(
    const EventId& ev_id) const {
  const auto it = aliases_.find(ev_id);
  if (it == aliases_.end()) {
    return std::nullopt;
  }
  return it->second;
}

const StaticEventDef* PmuDevice::findStaticEventDef_(
    const EventId& ev_id) const {
  for (const auto& state : static_event_defs_) {
    if (const auto* event = perf_event::findStaticEventDef(
            state->events(), getPmuType(), ev_id)) {
      return event;
    }
  }
  return nullptr;
}

bool PmuDevice::hasPrimaryEventId_(std::string_view ev_id) const {
  const EventId id{ev_id};
  return event_defs_.count(id) != 0 || findStaticEventDef_(id) != nullptr;
}

std::optional<EventId> PmuDevice::findPrimaryEventId_(
    const EventId& ev_id) const {
  if (hasPrimaryEventId_(ev_id)) {
    return ev_id;
  }
  auto primary = findEventIdByAlias_(ev_id);
  if (primary.has_value() && hasPrimaryEventId_(*primary)) {
    return primary;
  }
  return std::nullopt;
}

std::shared_ptr<EventDef> PmuDevice::materializeStaticEventDef_(
    const StaticEventDef& ev_def) const {
  for (const auto& state : static_event_defs_) {
    const auto* event = perf_event::findStaticEventDef(
        state->events(), getPmuType(), ev_def.id);
    if (event == &ev_def) {
      return state->materialize(ev_def);
    }
  }
  HBT_THROW_ASSERT_IF(true)
      << "Static event definition is not registered with PMU " << getFullName();
  __builtin_unreachable();
}

std::shared_ptr<EventDef> PmuDevice::findEventDef(const EventId& ev_id) const {
  const auto primary = findPrimaryEventId_(ev_id);
  if (!primary.has_value()) {
    return nullptr;
  }

  if (const auto it = event_defs_.find(*primary); it != event_defs_.end()) {
    HBT_ARG_CHECK_EQ(it->first, *primary);
    return it->second;
  }
  return materializeStaticEventDef_(*findStaticEventDef_(*primary));
}

const std::map<EventId, std::shared_ptr<EventDef>>& PmuDevice::getEventDefs()
    const {
  for (const auto& state : static_event_defs_) {
    for (const StaticEventDef& event : state->events()) {
      event_defs_.try_emplace(EventId{event.id}, state->materialize(event));
    }
  }
  return event_defs_;
}

void PmuDevice::validateStaticEventDefs_(
    const std::shared_ptr<StaticEventDefTableState>& state) const {
  std::set<EventId> incoming_primary_ids;
  std::set<EventId> incoming_aliases;
  for (const StaticEventDef& event : state->events()) {
    HBT_ARG_CHECK(event.pmu_type == getPmuType());
    HBT_ARG_CHECK(!event.id.empty());
    HBT_ARG_CHECK(
        std::none_of(
            event.id.begin(),
            event.id.end(),
            [](unsigned char c) { return std::isblank(c); }))
        << "Spaces not allowed in event_id \"" << event.id << "\"";
    HBT_ARG_CHECK(!event.brief_desc.empty())
        << "event_id: " << event.id << " missing brief description";
    HBT_ARG_CHECK(!event.full_desc.empty())
        << "event_id: " << event.id << " missing full description";
    HBT_ARG_CHECK(!event.errata.has_value() || !event.errata->empty());

    const EventId id{event.id};
    HBT_ARG_CHECK(!hasPrimaryEventId_(id))
        << "An event with id \"" << id << "\" already exists in PMU with id: \""
        << getPmuId() << "\" and name: \"" << getFullName() << "\"";
    HBT_ARG_CHECK_EQ(aliases_.count(id), 0)
        << "Event ID \"" << id << "\" collides with an existing alias in PMU "
        << getFullName();
    HBT_ARG_CHECK(incoming_primary_ids.insert(id).second);

    const EventId canonical_id = toCanonicalEventId(id);
    if (canonical_id != id) {
      HBT_ARG_CHECK(!hasPrimaryEventId_(canonical_id))
          << "Canonical alias \"" << canonical_id
          << "\" collides with an existing event in PMU " << getFullName();
      HBT_ARG_CHECK_EQ(aliases_.count(canonical_id), 0)
          << "Canonical alias \"" << canonical_id << "\" already exists in PMU "
          << getFullName();
      HBT_ARG_CHECK(incoming_aliases.insert(canonical_id).second)
          << "Duplicate canonical alias \"" << canonical_id << "\"";
    }
  }

  for (const auto& alias : incoming_aliases) {
    HBT_ARG_CHECK_EQ(incoming_primary_ids.count(alias), 0)
        << "Canonical alias \"" << alias
        << "\" collides with an event in the same static table";
  }
}

void PmuDevice::addStaticEventDefs_(
    std::shared_ptr<StaticEventDefTableState> state) {
  for (const StaticEventDef& event : state->events()) {
    const EventId id{event.id};
    const EventId canonical_id = toCanonicalEventId(id);
    if (canonical_id != id) {
      aliases_.emplace(canonical_id, id);
    }
  }
  static_event_defs_.push_back(std::move(state));
}

void PmuDevice::addEvent(
    std::shared_ptr<EventDef> ev_def,
    std::optional<std::vector<EventId>> aliases) {
  HBT_ARG_CHECK(!hasPrimaryEventId_(ev_def->id))
      << "An event with id \"" << ev_def->id
      << "\" already exists in PMU with id: \"" << getPmuId()
      << "\" and name: \"" << getFullName() << "\"";
  HBT_ARG_CHECK_EQ(aliases_.count(ev_def->id), 0)
      << "Event ID \"" << ev_def->id
      << "\" collides with an existing alias in PMU with id: \"" << getPmuId()
      << "\" and name: \"" << getFullName() << "\"";

  const bool has_dashes = ev_def->id.find('-') != std::string::npos;
  const bool has_upper =
      std::any_of(ev_def->id.begin(), ev_def->id.end(), ::isupper);
  if (has_dashes || has_upper) {
    aliases = std::vector<EventId>{toCanonicalEventId(ev_def->id)};
  }

  if (aliases.has_value()) {
    for (const auto& alias : *aliases) {
      HBT_ARG_CHECK(ev_def->id != alias && !hasPrimaryEventId_(alias))
          << "Tried to register an alias equal to an already existing event id. "
          << "Event ID: \"" << alias << "\" "
          << "already exists in PMU with id: \"" << getPmuId() << "\""
          << " and name: \"" << getFullName() << "\"";
      HBT_ARG_CHECK_EQ(aliases_.count(alias), 0)
          << "Alias \"" << alias << "\" already exists in PMU with id: \""
          << getPmuId() << "\" and name: \"" << getFullName() << "\"";
    }
  }

  auto [_, added] = event_defs_.emplace(ev_def->id, ev_def);
  HBT_DCHECK(added);
  if (aliases.has_value()) {
    addAliases(ev_def->id, *aliases);
  }
}

EventConf PmuDevice::makeConf(
    const EventId& ev_id,
    EventExtraAttr extra_attr,
    EventValueTransforms transforms) const {
  const auto primary = findPrimaryEventId_(ev_id);
  HBT_ARG_CHECK(primary.has_value())
      << "No event with ev_id \"" << ev_id
      << "\" in PMU with id:  " << getPmuId() << " and name: \""
      << getFullName() << "\"";

  EventConfigs configs{};
  if (const auto it = event_defs_.find(*primary); it != event_defs_.end()) {
    configs = it->second->makeConfigs(getPmuId());
  } else {
    configs = makeEventConfigs(*findStaticEventDef_(*primary), getPmuId());
  }
  return {
      .id = ev_id,
      .configs = configs,
      .extra_attr = extra_attr,
      .transforms = transforms};
}

/// Get EventDefs grouped by preffix of event_id until first dot.
/// If no dot, then take the full name.
std::unique_ptr<LibPfm4EventGroups> PmuDevice::makeLibPfm4Groups() const {
  auto groups = std::make_unique<LibPfm4EventGroups>();

  for (const auto& [ev_id, ev_def] : getEventDefs()) {
    HBT_THROW_ASSERT_IF(ev_def == nullptr);
    uint64_t code = ev_def->encoding.code;
    auto gkey = LibPfm4EventGroup::groupKeyFromEventId(ev_id);
    auto it = groups->find(gkey);

    if (it != groups->end() && it->second.ev_defs.at(0).encoding.code != code) {
      // Handle the uncommon case where events with same group_key
      // have different event codes by extending the group name.
      gkey += "__" + std::to_string(code);
      it = groups->find(gkey);
    }
    if (it == groups->end()) {
      groups->emplace(gkey, LibPfm4EventGroup{.key = gkey, .code = code});
    }
    groups->at(gkey).ev_defs.push_back(*ev_def);
  }
  return groups;
}

// Use it to reduce likeness of typos.
#define CASE_PMU_TYPE(__name__) \
  case PmuType::__name__:       \
    return #__name__

/// Map pmuType enum to the string preffix published
/// by kernel in /sys/devices (without device number).
std::string PmuTypeToStr(PmuType pmu_type) {
  switch (pmu_type) {
    CASE_PMU_TYPE(generic_hardware);
    CASE_PMU_TYPE(software);
    CASE_PMU_TYPE(tracepoint);
    CASE_PMU_TYPE(generic_hw_cache);
    CASE_PMU_TYPE(cpu);
    CASE_PMU_TYPE(breakpoint);

    CASE_PMU_TYPE(kprobe);
    CASE_PMU_TYPE(uprobe);
    CASE_PMU_TYPE(power);

    CASE_PMU_TYPE(uncore_cbox);
    CASE_PMU_TYPE(uncore_cha);
    CASE_PMU_TYPE(uncore_ha);
    CASE_PMU_TYPE(uncore_chacms);
    CASE_PMU_TYPE(uncore_imc);
    CASE_PMU_TYPE(uncore_iio);
    CASE_PMU_TYPE(uncore_irp);
    CASE_PMU_TYPE(uncore_m2m);
    CASE_PMU_TYPE(uncore_m3upi);
    CASE_PMU_TYPE(uncore_pcu);
    CASE_PMU_TYPE(uncore_qpi);
    CASE_PMU_TYPE(uncore_r2pcie);
    CASE_PMU_TYPE(uncore_r3qpi);
    CASE_PMU_TYPE(uncore_sbox);
    CASE_PMU_TYPE(uncore_ubox);
    CASE_PMU_TYPE(uncore_upi);

    CASE_PMU_TYPE(uncore_ncu);
    CASE_PMU_TYPE(uncore_arb);
    CASE_PMU_TYPE(uncore_edc_uclk);
    CASE_PMU_TYPE(uncore_edc_eclk);
    CASE_PMU_TYPE(uncore_imc_uclk);
    CASE_PMU_TYPE(uncore_imc_dclk);
    CASE_PMU_TYPE(uncore_m2pcie);

    CASE_PMU_TYPE(intel_pt);

    CASE_PMU_TYPE(uncore_mchbm);

    CASE_PMU_TYPE(armv8_pmuv3);
    CASE_PMU_TYPE(arm_cspmu_mc);
    CASE_PMU_TYPE(arm_cmn);

    CASE_PMU_TYPE(nvidia_scf_pmu);
    CASE_PMU_TYPE(nvidia_nvlink_c2c0_pmu);
    CASE_PMU_TYPE(nvidia_nvlink_c2c1_pmu);
    CASE_PMU_TYPE(nvidia_pcie_pmu);

    CASE_PMU_TYPE(nvidia_ucf_pmu);
    CASE_PMU_TYPE(nvidia_nvlink_c2c_pmu);
    CASE_PMU_TYPE(nvidia_cmem_latency_pmu);
    CASE_PMU_TYPE(nvidia_nvclink_pmu);
    CASE_PMU_TYPE(nvidia_nvdlink_pmu);
    CASE_PMU_TYPE(nvidia_pcie_tgt_pmu);

    CASE_PMU_TYPE(amd_l3);

    CASE_PMU_TYPE(amd_umc);

    CASE_PMU_TYPE(amd_df);

    CASE_PMU_TYPE(cs_etm);
  }
  return "";
}

/// Macro to generate "if" statements for PMU string names.
// Use it to reduce likeness of typos.
#define IF_PMU_TYPE(__str__, __name__) \
  if (__str__ == #__name__)            \
  return PmuType::__name__

PmuType PmuTypeFromStr(const std::string& str) {
  IF_PMU_TYPE(str, generic_hardware);
  IF_PMU_TYPE(str, software);
  IF_PMU_TYPE(str, tracepoint);
  IF_PMU_TYPE(str, generic_hw_cache);
  IF_PMU_TYPE(str, cpu);
  IF_PMU_TYPE(str, breakpoint);

  IF_PMU_TYPE(str, kprobe);
  IF_PMU_TYPE(str, uprobe);
  IF_PMU_TYPE(str, power);

  IF_PMU_TYPE(str, uncore_cbox);
  IF_PMU_TYPE(str, uncore_cha);
  IF_PMU_TYPE(str, uncore_ha);
  IF_PMU_TYPE(str, uncore_imc);
  IF_PMU_TYPE(str, uncore_iio);
  IF_PMU_TYPE(str, uncore_irp);
  IF_PMU_TYPE(str, uncore_m2m);
  IF_PMU_TYPE(str, uncore_m3upi);
  IF_PMU_TYPE(str, uncore_pcu);
  IF_PMU_TYPE(str, uncore_qpi);
  IF_PMU_TYPE(str, uncore_r2pcie);
  IF_PMU_TYPE(str, uncore_r3qpi);
  IF_PMU_TYPE(str, uncore_sbox);
  IF_PMU_TYPE(str, uncore_ubox);
  IF_PMU_TYPE(str, uncore_upi);

  IF_PMU_TYPE(str, uncore_ncu);
  IF_PMU_TYPE(str, uncore_arb);
  IF_PMU_TYPE(str, uncore_edc_uclk);
  IF_PMU_TYPE(str, uncore_edc_eclk);
  IF_PMU_TYPE(str, uncore_imc_uclk);
  IF_PMU_TYPE(str, uncore_imc_dclk);
  IF_PMU_TYPE(str, uncore_m2pcie);

  IF_PMU_TYPE(str, intel_pt);

  IF_PMU_TYPE(str, uncore_mchbm);

  IF_PMU_TYPE(str, armv8_pmuv3);
  IF_PMU_TYPE(str, arm_cspmu_mc);
  IF_PMU_TYPE(str, arm_cmn);

  IF_PMU_TYPE(str, nvidia_scf_pmu);
  IF_PMU_TYPE(str, nvidia_nvlink_c2c0_pmu);
  IF_PMU_TYPE(str, nvidia_nvlink_c2c1_pmu);
  IF_PMU_TYPE(str, nvidia_pcie_pmu);

  IF_PMU_TYPE(str, nvidia_ucf_pmu);
  IF_PMU_TYPE(str, nvidia_nvlink_c2c_pmu);
  IF_PMU_TYPE(str, nvidia_cmem_latency_pmu);
  IF_PMU_TYPE(str, nvidia_nvclink_pmu);
  IF_PMU_TYPE(str, nvidia_nvdlink_pmu);
  IF_PMU_TYPE(str, nvidia_pcie_tgt_pmu);

  IF_PMU_TYPE(str, amd_l3);

  IF_PMU_TYPE(str, amd_umc);

  IF_PMU_TYPE(str, amd_df);

  IF_PMU_TYPE(str, cs_etm);

  HBT_THROW_EINVAL() << "Unrecognized PmuType string: \"" + str + "\"";
  __builtin_unreachable();
}

#define IF_CONFIG_TYPE(__str__, __name__) \
  if (__str__ == #__name__)               \
  return PmuDevice::ConfigType::__name__

PmuDevice::ConfigType ConfigTypeFromStr(const std::string& str) {
  IF_CONFIG_TYPE(str, config);
  IF_CONFIG_TYPE(str, config1);
  IF_CONFIG_TYPE(str, config2);
  IF_CONFIG_TYPE(str, config3);

  HBT_THROW_EINVAL() << "Unrecognized ConfigType string: \"" + str + "\"";
  __builtin_unreachable();
}

void parseSysFsPmuFormat_(
    const fs::directory_entry& dentry,
    PmuDevice& pmu_device) {
  auto format_dir = dentry.path() / "format";
  if (!fs::is_directory(format_dir)) {
    return;
  }

  for (const auto& format_entry : fs::directory_iterator(format_dir)) {
    if (!fs::is_regular_file(format_entry.path())) {
      HBT_LOG_WARNING() << format_entry.path() << " is not a regular file.";
      continue;
    }
    auto is = std::ifstream(format_entry.path().string(), std::ifstream::in);
    std::string format_str;
    is >> format_str;
    // Expect format to be "config:\d+(-\d+)?"
    auto sep_pos = format_str.find(':');
    if (sep_pos == std::string::npos) {
      HBT_LOG_WARNING() << "Format entry " << format_entry.path()
                        << " missing ':'. It can not be understood.";
      continue;
    }
    PmuDevice::FormatAttr format_attr = {
        .name = format_entry.path().filename().string()};
    try {
      format_attr.type = ConfigTypeFromStr(format_str.substr(0, sep_pos));
    } catch (std::invalid_argument& e) {
      HBT_LOG_EXCEPTION(e);
      continue;
    }

    auto bit_range_str = format_str.substr(sep_pos + 1);
    sep_pos = bit_range_str.find('-');
    try {
      if (sep_pos == std::string::npos) {
        auto bit = std::stoul(bit_range_str);
        HBT_THROW_ASSERT_IF(sizeof(EventConfigs::config) * 8 <= bit)
            << "Format entry " << format_entry.path()
            << " contains out of range bit " << bit;
        format_attr.msb = static_cast<uint8_t>(bit);
        format_attr.len = 1;
      } else {
        auto start_bit = std::stoul(bit_range_str.substr(0, sep_pos));
        HBT_THROW_ASSERT_IF(sizeof(EventConfigs::config) * 8 <= start_bit)
            << "Format entry " << format_entry.path()
            << " contains out of range bit " << start_bit;
        auto end_bit = std::stoul(bit_range_str.substr(
            sep_pos + 1, bit_range_str.length() - sep_pos - 1));
        HBT_THROW_ASSERT_IF(sizeof(EventConfigs::config) * 8 <= end_bit)
            << "Format entry " << format_entry.path()
            << " contains out of range bit " << end_bit;
        HBT_THROW_ASSERT_IF(end_bit < start_bit)
            << "Format entry " << format_entry.path()
            << " start bit is larger than end bit";
        format_attr.msb = static_cast<uint8_t>(start_bit);
        format_attr.len = static_cast<uint8_t>(end_bit - start_bit + 1);
      }
    } catch (std::out_of_range&) {
      continue;
    } catch (std::exception& e) {
      HBT_LOG_EXCEPTION(e) << "Failed to parse format entry ";
      continue;
    }
    // Insert format into pmu devices
    pmu_device.format[format_attr.name] = format_attr;
  }
}

void parseSysFsPmuCaps_(fs::directory_entry dentry, PmuDevice& pmu_device) {
  auto caps_dir = dentry.path() / "caps";
  if (!fs::is_directory(caps_dir)) {
    HBT_DLOG_INFO() << caps_dir << " is not a directory";
    return;
  }
  for (const auto& cap_entry : fs::directory_iterator(caps_dir)) {
    if (!fs::is_regular_file(cap_entry.path())) {
      HBT_LOG_ERROR() << cap_entry.path() << " is not a regular file";
      continue;
    }
    auto is = std::ifstream(cap_entry.path().string(), std::ifstream::in);
    std::string cap;
    is >> cap;
    // Expect any non empty string
    if (is.fail() || is.eof()) {
      HBT_LOG_ERROR() << "Cap entry " << cap_entry.path()
                      << " contains invalid character or is empty";
      continue;
    }
    // Insert cap into pmu devices
    pmu_device.caps[cap_entry.path().filename().string()] = cap;
  }
}

std::optional<cpu_set_t> parseSysFsPmuCpuMask_(fs::directory_entry dentry) {
  auto cpu_mask_path = dentry.path() / "cpumask";
  if (!fs::is_regular_file(cpu_mask_path)) {
    // not all pmu devices have cpumask file
    return std::nullopt;
  }
  auto is = std::ifstream(cpu_mask_path, std::ifstream::in);
  std::string cpu_mask_str;
  is >> cpu_mask_str;
  if (is.fail() || is.eof()) {
    HBT_LOG_ERROR() << "CpuMask entry " << cpu_mask_path
                    << " contains invalid character or is empty";
    return std::nullopt;
  }
  cpu_set_t res;
  CPU_ZERO(&res);
  // parse cpumask string to cpu_set_t
  // string format is expected to be ^\d+(,\d+)*$
  size_t start_pos = 0;
  while (true) {
    auto end_pos = cpu_mask_str.find(',', start_pos);
    size_t len = end_pos == std::string::npos ? cpu_mask_str.size() - start_pos
                                              : end_pos - start_pos;
    size_t cpu_idx;
    try {
      cpu_idx = std::stoul(cpu_mask_str.substr(start_pos, len));
    } catch (const std::logic_error& e) {
      HBT_LOG_ERROR() << "Failed to parse cpu mask string " << cpu_mask_str
                      << "(" << cpu_mask_str.substr(start_pos, len) << ") from "
                      << cpu_mask_path << " because " << e.what();
      return std::nullopt;
    }
    CPU_SET(cpu_idx, &res);
    start_pos = end_pos + 1;
    if (end_pos >= cpu_mask_str.size()) {
      break;
    }
  }
  return res;
}

/// Parse string published by kernel in /sys/devices to a pair of
/// PmuType and device id.
std::pair<PmuType, std::optional<uint32_t>> parseDeviceTypeFromStr(
    const std::string& str) {
  // NVIDIA per-root-complex PMUs (Vera-Rubin) are named
  // <prefix>_<socket>_rc_<rc>, e.g. nvidia_pcie_pmu_0_rc_3 or
  // nvidia_pcie_tgt_pmu_1_rc_5. The single-trailing-index parser below would
  // mis-split these (leaving "..._rc" as the type), so handle them explicitly.
  // The device enumeration is packed as socket * kMaxRootComplexesPerSocket +
  // rc (unique per instance).
  constexpr uint32_t kMaxRootComplexesPerSocket = 64;
  if (const auto rc_pos = str.rfind("_rc_"); rc_pos != std::string::npos) {
    const auto before_rc = str.substr(0, rc_pos); // "<prefix>_<socket>"
    const auto sock_pos = before_rc.find_last_of('_');
    if (sock_pos != std::string::npos) {
      std::optional<uint32_t> enum_id;
      try {
        const uint32_t socket =
            static_cast<uint32_t>(std::stoi(before_rc.substr(sock_pos + 1)));
        const uint32_t rc =
            static_cast<uint32_t>(std::stoi(str.substr(rc_pos + 4)));
        // Guard the packing so a socket's root complexes never alias into the
        // next socket's id range if a future part exposes more than
        // kMaxRootComplexesPerSocket root complexes.
        HBT_THROW_ASSERT_IF(rc >= kMaxRootComplexesPerSocket)
            << "Root complex index " << rc << " in /sys/devices/" << str
            << " exceeds the packing limit of " << kMaxRootComplexesPerSocket
            << " root complexes per socket";
        enum_id = socket * kMaxRootComplexesPerSocket + rc;
      } catch (const std::invalid_argument&) {
        // Not the <socket>_rc_<rc> shape; fall through to default handling.
      }
      if (enum_id.has_value()) {
        return std::make_pair(
            PmuTypeFromStr(before_rc.substr(0, sock_pos)), enum_id);
      }
    }
  }
  const auto pos = str.find_last_of('_');
  if (pos != std::string::npos) {
    std::optional<uint32_t> num_device;
    auto s = str.substr(pos + 1);
    // Try to parse PMUs with number suffix.
    try {
      int idx = std::stoi(s);
      num_device = static_cast<uint32_t>(idx);
    } catch (const std::invalid_argument&) {
      // pass-through.
    }
    if (num_device.has_value()) {
      HBT_THROW_ASSERT_IF(0 > *num_device)
          << "Unexpected negative integer in name at /sys/devices/" << str;
      const auto device_type_str = str.substr(0, pos);
      return std::make_pair(PmuTypeFromStr(device_type_str), num_device);
    }
  }
  return std::make_pair(PmuTypeFromStr(str), std::nullopt);
}

void parseSysFsPmu_(fs::directory_entry dentry, PmuDeviceManager& pmu_manager) {
  HBT_ARG_CHECK(fs::is_directory(dentry.path()));

  // Parse device type and index from name.
  auto p = dentry.path().filename().string();
  auto [pmu_type, pmu_idx] = parseDeviceTypeFromStr(p);

  // Read pmu_id from "type" file.
  auto is = std::ifstream((dentry.path() / "type").string(), std::ifstream::in);
  uint32_t pmu_id;
  is >> pmu_id;

  // Read cpumask
  auto cpu_mask = parseSysFsPmuCpuMask_(dentry);

  auto pmu_device = std::make_shared<PmuDevice>(
      p, pmu_type, pmu_idx, pmu_id, p, true, cpu_mask);
  parseSysFsPmuFormat_(dentry, *pmu_device);
  parseSysFsPmuCaps_(dentry, *pmu_device);

  pmu_manager.addPmu(std::move(pmu_device));
}

void PmuDeviceManager::loadSysFsPmus() {
  const fs::path p = rootDir_ + "/sys/bus/event_source/devices";
  for (const auto& dentry : fs::directory_iterator(p)) {
    if (!fs::is_directory(dentry.path())) {
      continue;
    }
    try {
      parseSysFsPmu_(dentry, *this);
    } catch (const std::invalid_argument&) {
      // HBT_LOG_INFO()
      //    << "Ignoring unrecognized /sys/devices entry: \""
      //    << e.what() << "\"";
      continue;
    }
  }
}

void PmuDeviceManager::addPmu(std::shared_ptr<PmuDevice> pmu) {
  HBT_ARG_CHECK(findPmuDeviceByName(pmu->getName()) == nullptr)
      << "PMU " << pmu->getName() << " already adedd to PmuDeviceManager";
  auto pmu_type = pmu->getPmuType();
  auto pmu_instance_enum = pmu->getPmuDevEnumeration();
  auto [_, added] = pmu_groups_[pmu_type].try_emplace(pmu_instance_enum, pmu);
  HBT_THROW_ASSERT_IF(!added);
}

std::vector<std::string> PmuDeviceManager::listTracepointCategories() {
  std::vector<std::string> categories;
  try {
    for (const auto& dentry : fs::directory_iterator(kSysFsTracingEventsRoot)) {
      if (!fs::is_directory(dentry.path())) {
        continue;
      }
      categories.emplace_back(dentry.path().filename().string());
    }
  } catch (const fs::filesystem_error& ex) {
    if (ex.code().value() == EACCES) {
      HBT_LOG_INFO()
          << "User has no permissions to open tracepoint events. "
          << "Do you want to run as root or add CAP_PERFMON to your user?";
    } else {
      HBT_LOG_ERROR() << "Error loading Tracepoint Categories. " << ex.what();
    }
  }
  return categories;
}

std::vector<std::pair<std::string, int32_t>>
PmuDeviceManager::listTracepointEvents(const std::string& category) {
  std::vector<std::pair<std::string, int32_t>> tracepoints;
  const fs::path p = fs::path(kSysFsTracingEventsRoot) / category;
  try {
    for (const auto& dentry : fs::directory_iterator(p)) {
      if (!fs::is_directory(dentry.path())) {
        continue;
      }
      auto& tp = tracepoints.emplace_back();
      tp.first = dentry.path().filename().string();

      try {
        tp.second = readIntFromFile((dentry.path() / "id").string());
      } catch (const std::invalid_argument&) {
        // HBT_LOG_INFO()
        //    << "Ignoring tracepoint : \""
        //    << dentry.path.string()
        //    << e.what() << "\"";
        continue;
      }
    }
  } catch (const fs::filesystem_error& ex) {
    if (ex.code().value() == EACCES) {
      HBT_LOG_INFO()
          << "User has no permissions to open tracepoint events. "
          << "Do you want to run as root or add CAP_PERFMON to your user?";
    } else {
      HBT_LOG_ERROR() << "Error loading Tracepoint Categories. " << ex.what();
    }
  }
  return tracepoints;
}

int PmuDeviceManager::addEvent(
    std::shared_ptr<EventDef> ev,
    std::optional<std::vector<EventId>> aliases) {
  auto pmu_type = ev->pmu_type;
  // Adding to dynamic. There may be multiple.
  auto it = pmu_groups_.find(pmu_type);
  if (it == pmu_groups_.end()) {
    return -ENXIO;
  }
  for (auto& [dev_idx, device] : it->second) {
    device->addEvent(ev, aliases);
  }

  return 0;
}

int PmuDeviceManager::addStaticEventDefs(
    std::span<const StaticEventDef> events) {
  if (events.empty()) {
    return 0;
  }
  HBT_ARG_CHECK(isStaticEventDefTableSorted(events))
      << "Static event definitions must be unique and sorted by PMU type and ID";

  struct ApplicablePartition {
    std::shared_ptr<StaticEventDefTableState> state;
    TPmuGroup* devices;
  };
  std::vector<ApplicablePartition> applicable;

  size_t begin = 0;
  while (begin < events.size()) {
    size_t end = begin + 1;
    while (end < events.size() &&
           events[end].pmu_type == events[begin].pmu_type) {
      ++end;
    }

    if (auto it = pmu_groups_.find(events[begin].pmu_type);
        it != pmu_groups_.end()) {
      auto state = std::make_shared<StaticEventDefTableState>(
          events.subspan(begin, end - begin));
      applicable.push_back(
          ApplicablePartition{
              .state = std::move(state), .devices = &it->second});
    }
    begin = end;
  }

  if (applicable.empty()) {
    return -ENXIO;
  }

  for (const auto& partition : applicable) {
    for (const auto& [_, device] : *partition.devices) {
      device->validateStaticEventDefs_(partition.state);
    }
  }
  for (auto& partition : applicable) {
    for (auto& [_, device] : *partition.devices) {
      device->addStaticEventDefs_(partition.state);
    }
  }
  return 0;
}

int PmuDeviceManager::addAliases(
    const EventId& ev_id,
    const std::vector<EventId>& aliases) {
  const EventId canonical_id = toCanonicalEventId(ev_id);
  for (auto& [_, pmu_devices] : pmu_groups_) {
    for (const auto& [__, device] : pmu_devices) {
      auto primary = device->findPrimaryEventId_(ev_id);
      if (!primary.has_value()) {
        primary = device->findPrimaryEventId_(canonical_id);
      }
      if (!primary.has_value()) {
        continue;
      }
      for (auto& [___, target] : pmu_devices) {
        target->addAliases(*primary, aliases);
      }
      return 0;
    }
  }
  return -EINVAL;
}

int PmuDeviceManager::addAliases(
    std::shared_ptr<EventDef> ev,
    const std::vector<EventId>& aliases) {
  auto pmu_type = ev->pmu_type;
  auto it = pmu_groups_.find(pmu_type);
  if (it != pmu_groups_.end()) {
    for (auto& [dev_idx, device] : it->second) {
      device->addAliases(ev->id, aliases);
    }
    return 0;
  }

  return -ENXIO;
}

void PmuDevice::addAliases(
    const EventId& ev_id,
    const std::vector<EventId>& aliases) {
  for (const auto& alias : aliases) {
    aliases_.emplace(alias, ev_id);
  }
}

void PmuDeviceManager::makePerCpuConfs(
    PmuType pmu_type,
    EventId ev_id,
    EventExtraAttr extra_attr,
    EventValueTransforms transforms,
    cpu_set_t mon_cpus,
    PerCpuEventConfs& per_cpu_confs) const {
  // Iterate over all sys fs PMU devices of this type.
  auto it = pmu_groups_.find(pmu_type);
  HBT_ARG_CHECK(it != pmu_groups_.end())
      << "Invalid pmu_type: " + PmuTypeToStr(pmu_type);
  // Get all PmuDevices of this type (e.g one per package).
  for (const auto& [dev_idx, device] : it->second) {
    HBT_THROW_ASSERT_IF(device->getCpuMask() != std::nullopt)
        << "Per-package PMUs currently unsupported";
    for_each_cpu_set_t(cpu, mon_cpus) {
      auto& confs = per_cpu_confs[cpu];
      confs.push_back(device->makeConf(ev_id, extra_attr, transforms));
    }
  }
}

void PmuDeviceManager::makePerUncoreConfs(
    PmuType pmu_type,
    EventId ev_id,
    EventExtraAttr extra_attrs,
    EventValueTransforms transforms,
    uncore_scope::Scope scope,
    PerUncoreEventConfs& per_uncore_confs) const {
  std::vector<TPerfPmuDevice> perf_pmu_group =
      getPerfPmuGroupByScope(pmu_type, scope);

  for (const auto& perf_pmu : perf_pmu_group) {
    auto& confs = per_uncore_confs[perf_pmu];
    confs.push_back(perf_pmu.second->makeConf(ev_id, extra_attrs, transforms));
  }
}

EventConf PmuDeviceManager::makeNoCpuTopologyConf(
    PmuType pmu_type,
    EventId ev_id,
    EventExtraAttr extra_attr,
    EventValueTransforms transforms) const {
  // There can only be one PmuDevice per PmuType for PMUs without topology.
  auto it = pmu_groups_.find(pmu_type);
  HBT_ARG_CHECK(it != pmu_groups_.end())
      << "Invalid pmu_type: " + PmuTypeToStr(pmu_type);
  HBT_ARG_CHECK_EQ(it->second.size(), 1)
      << "PmuType " << PmuTypeToStr(pmu_type) << " has more than one PmuDevice."
      << " Use makePerCpuConfs";

  // Get the only PmuDevice for this PmuType.
  const auto device = it->second.begin()->second;
  return device->makeConf(ev_id, extra_attr, transforms);
}

std::set<std::string> PmuDeviceManager::getPmuNames() const {
  std::set<std::string> pmu_ids;
  std::set<std::string> dyn_pmu_ids;
  for (const auto& [pmu_type, pmu_devices] : getPmuGroups()) {
    for (const auto& [pmu_idx, pmu] : pmu_devices) {
      auto [it, inserted] = dyn_pmu_ids.insert(pmu->getName());
      HBT_DCHECK(inserted) << "PMU with name: \"" << pmu->getName()
                           << "\" already exists";
      pmu_ids.insert(pmu->getName());
    }
  }
  return pmu_ids;
}

std::vector<TPerfPmuDevice> PmuDeviceManager::getPerfPmuGroupByScope(
    PmuType pmu_type,
    uncore_scope::Scope scope) const {
  auto it = pmu_groups_.find(pmu_type);
  HBT_ARG_CHECK(it != pmu_groups_.end())
      << "Invalid pmu_type: " + PmuTypeToStr(pmu_type);
  std::vector<TPerfPmuDevice> perf_pmu_group;
  // Get all PmuDevices of this type (e.g one per package).
  for (const auto& [dev_idx, device] : it->second) {
    if (device->getCpuMask() == std::nullopt) {
      HBT_LOG_ERROR() << "Cannot find cpu mask info from pmu device "
                      << device->getName() << ". Ignore this device.";
      continue;
    }
    for_each_cpu_set_t(cpu, device->getCpuMask().value()) {
      // Filter by CPU socket if scope is CpuSocket
      if (std::holds_alternative<uncore_scope::CpuSocket>(scope)) {
        uint32_t socketId = std::get<uncore_scope::CpuSocket>(scope).socket_id;
        if (socketId >= cpuSocketToCores_.size()) {
          HBT_LOG_ERROR() << "Invalid socket id: " << socketId;
          continue;
        }
        // Skip this CPU if it doesn't belong to the specified socket. Note that
        // cpus are sorted.
        const auto& cpus = cpuSocketToCores_.at(socketId);
        if (!std::binary_search(cpus.begin(), cpus.end(), cpu)) {
          continue;
        }
      }
      perf_pmu_group.emplace_back(cpu, device);
    }
  }
  return perf_pmu_group;
}

std::shared_ptr<PmuDevice> PmuDeviceManager::findPmuDeviceByName(
    std::string pmu_name) {
  for (const auto& [pmu_type, pmu_devices] : getPmuGroups()) {
    for (auto& [dev_idx, pmu_device] : pmu_devices) {
      if (pmu_name == pmu_device->getName()) {
        return pmu_device;
      }
    }
  }
  return nullptr;
}

/// Optionally pass PmuType and or pmu name to only add event to those PMUs.
std::shared_ptr<EventDef> PmuDeviceManager::findEventDef(
    std::string ev_id_str,
    std::optional<PmuType> pmu_type_arg,
    std::optional<std::string> pmu_name_arg) {
  std::string canonical_name = toCanonicalEventId(ev_id_str);
  std::shared_ptr<EventDef> ev_def;

  for (const auto& [pmu_type, pmu_devices] : getPmuGroups()) {
    if (pmu_type_arg.has_value() && *pmu_type_arg != pmu_type) {
      continue;
    }
    for (auto& [dev_idx, pmu_device] : pmu_devices) {
      if (pmu_name_arg.has_value() && *pmu_name_arg != pmu_device->getName()) {
        continue;
      }
      if ((ev_def = pmu_device->findEventDef(ev_id_str)) ||
          (ev_def = pmu_device->findEventDef(canonical_name))) {
        return ev_def;
      }
    }
  }
  return nullptr;
}

} // namespace facebook::hbt::perf_event
