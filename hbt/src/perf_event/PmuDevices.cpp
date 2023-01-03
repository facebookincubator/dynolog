// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/PmuDevices.h"

#include <hbt/src/perf_event/PmuEvent.h>
#include <string>

#include <filesystem>

namespace fs = std::filesystem;

namespace facebook::hbt::perf_event {

/// Get EventDefs grouped by preffix of event_id until first dot.
/// If no dot, then take the full name.
std::unique_ptr<LibPfm4EventGroups> PmuDevice::makeLibPfm4Groups() const {
  auto groups = std::make_unique<LibPfm4EventGroups>();

  for (const auto& [ev_id, ev_def] : event_defs_) {
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
  };
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

  HBT_THROW_EINVAL() << "Unrecognized ConfigType string: \"" + str + "\"";
  __builtin_unreachable();
}

void parseSysFsPmuFormat_(fs::directory_entry dentry, PmuDevice& pmu_device) {
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
    HBT_LOG_INFO() << caps_dir << " is not a directory";
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

/// Parse string published by kernel in /sys/devices to a pair of
/// PmuType and device id.
std::pair<PmuType, std::optional<uint32_t>> parseDeviceTypeFromStr(
    const std::string& str) {
  const auto pos = str.find_last_of("_");
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

  auto pmu_device =
      std::make_shared<PmuDevice>(p, pmu_type, pmu_idx, pmu_id, p, true);
  parseSysFsPmuFormat_(dentry, *pmu_device);
  parseSysFsPmuCaps_(dentry, *pmu_device);

  pmu_manager.addPmu(std::move(pmu_device));
}

void PmuDeviceManager::loadSysFsPmus() {
  const fs::path p = "/sys/devices";
  for (const auto& dentry : fs::directory_iterator(p)) {
    if (!fs::is_directory(dentry.path())) {
      continue;
    }
    try {
      parseSysFsPmu_(dentry, *this);
    } catch (const std::invalid_argument& e) {
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
      } catch (const std::invalid_argument& e) {
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

int PmuDeviceManager::addAliases(
    const EventId& ev_id,
    const std::vector<EventId>& aliases) {
  auto ev = findEventDef(ev_id, std::nullopt);
  if (!ev) {
    return -EINVAL;
  }

  return addAliases(ev, aliases);
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
    auto [_, added] = aliases_.emplace(alias, ev_id);
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
