// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"

#include <linux/perf_event.h>

#include <iostream>
#include <memory>
#include <string>
#include <variant>
#include <vector>

namespace facebook::hbt::perf_event {

/// Linux's perf_event has PMUs that are statically enumerated, present
/// in linux/include/perf_event.h, and PMUs that are instantiated dynamically.
/// /sys/devices exposes some of the statically enumerated PMUs and all of the
/// dynamic ones.
///
/// This enumeration handles both static and dynamic PMUs.
enum class PmuType : uint16_t {

  generic_hardware, // Equivalent to PERF_TYPE_HARDWARE: architecture
                    // independent CPU events
  software, // Equivalent to PERF_TYPE_SOFTWARE
  tracepoint, // Equivalent to PERF_TYPE_TRACEPOINT
  generic_hw_cache, // Equivalent to PERF_TYPE_HW_CACHE
  cpu, // Equivalent to PERF_TYPE_RAW: architecture specific CPU events
  breakpoint, // Equivalent to PERF_TYPE_BREAKPOINT

  kprobe,
  uprobe,
  power,

  // Intel Uncore
  uncore_cbox,
  uncore_cha,
  uncore_ha,
  uncore_imc,
  uncore_iio,
  uncore_irp,
  uncore_m2m,
  uncore_m3upi,
  uncore_pcu,
  uncore_qpi,
  uncore_r2pcie,
  uncore_r3qpi,
  uncore_sbox,
  uncore_ubox,
  uncore_upi,

  // XXX: Below are Icelake PMUs, need to test them.
  uncore_ncu, // Similar to cbox
  uncore_arb, // Arbitration unit.
  uncore_edc_uclk, // EDC is a memory controller for MCDRAM (3D-stacked)
  uncore_edc_eclk,

  // Memory controller.
  uncore_imc_uclk,
  uncore_imc_dclk,

  // Memory to PCIe.
  uncore_m2pcie,

  // Intel PT
  intel_pt,

  // HBM Memory Controller
  // XXX: Need to test them?
  uncore_mchbm,
};

std::string PmuTypeToStr(PmuType);

enum class ScaleUnit {
  Bytes, // Bytes
  Joules, // Joules
  MiB // MebiBytes
};

ScaleUnit scaleUnitFromStr(const std::string& s);

std::string scaleUnitToStr(ScaleUnit u);

enum class PreciseIpLevel : uint8_t {
  // Follows man perf_event_open
  kNone = 0,
  kConstantSkid = 1,
  kRequestZeroSkid = 2,
  kRequireZeroSkid = 3
};

std::string preciseIpLevelToStr(PreciseIpLevel p);

/// Event Ids must be unique and C-like variable names.
// XXX: Enforce that the string has a C-like variable name.
using EventId = std::string;

/// Event attributes that do not depend on event encoding.
struct EventExtraAttr {
  bool exclude_user = false;
  bool exclude_kernel = false;
  bool exclude_hv = false;
  bool exclude_idle = false;
  bool exclude_host = false;
  bool exclude_guest = false;
  PreciseIpLevel precise_ip = PreciseIpLevel::kNone;

  static auto makeUserOnly(PreciseIpLevel precise_ip = PreciseIpLevel::kNone) {
    return EventExtraAttr{
        .exclude_kernel = true,
        .exclude_hv = true,
        .exclude_idle = true,
        .precise_ip = precise_ip,
    };
  }

  static auto makeIgnoreUserOnly(
      PreciseIpLevel precise_ip = PreciseIpLevel::kNone) {
    return EventExtraAttr{
        .exclude_user = true,
        .precise_ip = precise_ip,
    };
  }

  static auto makeKernelOnly(
      PreciseIpLevel precise_ip = PreciseIpLevel::kNone) {
    return EventExtraAttr{
        .exclude_user = true,
        .exclude_hv = true,
        .exclude_idle = true,
        .precise_ip = precise_ip,
    };
  }

  static auto makeIdleOnly(PreciseIpLevel precise_ip = PreciseIpLevel::kNone) {
    return EventExtraAttr{
        .exclude_user = true,
        .exclude_kernel = true,
        .exclude_hv = true,
        .precise_ip = precise_ip,
    };
  }

  static auto makeCountAll(PreciseIpLevel precise_ip = PreciseIpLevel::kNone) {
    return EventExtraAttr{
        .precise_ip = precise_ip,
    };
  }

  static auto makeFromString(const std::string& str) {
    // Follow perf tool convention.
    HBT_ARG_CHECK(str.find_first_not_of("ukhIGH"))
        << "Invalid ExtraAtrributes " << str << " to PmuEvent";

    if (str.size() == 0) {
      return makeCountAll();
    }

    auto has_any = [&](std::string s) {
      return str.find_first_of(s) != std::string::npos;
    };

    auto count_char = [&](char c) {
      return std::count(str.begin(), str.end(), c);
    };
    auto num_precises = count_char('p');
    HBT_ARG_CHECK_GE(num_precises, 0) << "Invalid negative precise_ip";
    HBT_ARG_CHECK_LE(num_precises, 3)
        << "Cannot have precise level higher than 3";

    PreciseIpLevel precise_ip;
    switch (num_precises) {
      case 0:
        precise_ip = PreciseIpLevel::kNone;
        break;
      case 1:
        precise_ip = PreciseIpLevel::kConstantSkid;
        break;
      case 2:
        precise_ip = PreciseIpLevel::kRequestZeroSkid;
        break;
      case 3:
        precise_ip = PreciseIpLevel::kRequireZeroSkid;
        break;
      default:
        __builtin_unreachable();
    }

    return EventExtraAttr{
        .exclude_user = !has_any("u"),
        .exclude_kernel = !has_any("k"),
        .exclude_hv = !has_any("h"),
        .exclude_idle = !has_any("I"),
        .exclude_host = !has_any("G"),
        .exclude_guest = !has_any("H"),
        .precise_ip = precise_ip};
  }
};

std::ostream& operator<<(std::ostream&, const EventExtraAttr&);

using EventExtraAttrs = std::vector<EventExtraAttr>;

/// The configuration data passed to CpuEventsGroup to be used to
/// select the perf_event_attr in perf_event_open.
struct EventConfigs {
  uint32_t type; // The PMU type.
  uint64_t config;
  uint64_t config1 = 0x0;
  uint64_t config2 = 0x0;
};

std::ostream& operator<<(std::ostream&, const EventConfigs&);

/// Parameters to transform event values.
struct EventValueTransforms {
  enum Flags : uint8_t { None = 0x0, TscToKernelTime = 0x1 };

  Flags flags = Flags::None;

  bool any() const {
    return flags == Flags::None;
  }
};

std::ostream& operator<<(std::ostream&, const EventValueTransforms&);

// This is the full description of a perf_event_attr configuration.
struct EventConf {
  EventId id;
  EventConfigs configs;
  EventExtraAttr extra_attr;
  EventValueTransforms transforms;
};

std::ostream& operator<<(std::ostream&, const EventConf&);

using EventConfs = std::vector<EventConf>;

/// Definition of an event.
/// Defined with respect to a PmuType, not a PmuDevice, therefore it is assumed
/// that are valid for any device of the same type.
struct EventDef {
  const PmuType pmu_type;
  const EventId id;

  /// Stores all information required to encode an event.
  /// Note that Offcore response event use config1 and (optionally) config2.
  /// Linux perf_event knows the special Offcore response MSRs for each CPU
  /// and hence we don't need to store them.
  struct Encoding {
    uint64_t code;
    uint64_t umask = 0x0;
    bool edge = false; // Edge Detect.
    bool any = false; // Any Thread.
    bool inv = false; // Invert.
    uint64_t cmask = 0x0; // Counter Mask.

    // Some events have a MSR Value passed to config1.
    // No need to store the MSR Index because the kernel already
    // knows the Offcore response MSRs for each CPU.
    std::vector<uint64_t> msr_values;
  } const encoding;

  struct ScaleData {
    std::variant<int, double> scale_factor;
    ScaleUnit scale_unit;
  };
  // If scaling data is provided.
  std::optional<ScaleData> scale_data = std::nullopt;

  struct IntelFeatures {
    /// Fields in this structure follow Intel's JSON and are described
    /// in https://download.01.org/perfmon/readme.txt

    // Data Linear Address support (when configured as PEBS).
    // This replaced precise store on Haswell and onwards.
    bool data_la = false;

    // Whether the DCU field in PEBS record is set when event is run as PEBS.
    bool l1_hit_indication = false;
    // XXX: This field is related to Last-Level Cache and is only set
    // for events that use persistent memory as LLC.
    bool ellc = false;
    // 1 means can be PEBS or regular event. 2 means only PEBS.
    // As described in PEBS section of
    // https://download.01.org/perfmon/readme.txt
    uint8_t pebs = 0;
  };
  const std::optional<IntelFeatures> features;

  const std::string brief_desc;
  const std::string full_desc;
  std::optional<uint64_t> default_sampling_period;
  const std::optional<std::string> errata;

  /// For some events, it's only known at runtime if they are precise
  /// (like generic events), so return std::nullopt for those.
  /// For events defined in Intel JSON, PEBS capability implies
  /// that they are precise.
  std::optional<bool> isPrecise() const {
    if (!features.has_value()) {
      return std::nullopt;
    }
    return features->pebs;
  }

  explicit EventDef(const EventDef&) = default;

  explicit EventDef(EventDef&&) = default;

  EventDef(
      const PmuType& pmu_type,
      const EventId& id,
      const Encoding& encoding,
      const std::string& brief_desc,
      const std::string& full_desc,
      std::optional<uint64_t> default_sampling_period = std::nullopt,
      std::optional<ScaleData> scale_data = std::nullopt,
      std::optional<IntelFeatures> features = std::nullopt,
      std::optional<std::string> errata = std::nullopt)
      : pmu_type{pmu_type},
        id{id},
        encoding{encoding},
        scale_data{scale_data},
        features{features},
        brief_desc{brief_desc},
        full_desc{full_desc},
        default_sampling_period{default_sampling_period},
        errata{errata} {
    HBT_ARG_CHECK_GT(id.size(), 0);
    // XXX: Check that id is well-formed (i.e. is c-like variable string).
    // Use unsigned char instructed in
    // https://en.cppreference.com/w/cpp/string/byte/isblank.
    auto is_blank = [](unsigned char c) { return std::isblank(c); };
    HBT_ARG_CHECK_EQ(std::count_if(id.begin(), id.end(), is_blank), 0)
        << "Spaces not allowed in event_id \"" << id << "\"";

    HBT_ARG_CHECK_GT(brief_desc.size(), 0)
        << "event_id: " << id << " missing brief description";
    HBT_ARG_CHECK_GT(full_desc.size(), 0)
        << "event_id: " << id << " missing full description";
    if (errata.has_value()) {
      HBT_ARG_CHECK_GT(errata->size(), 0);
    }
  }

  /// Create perf_event_attr config field,
  /// as done in kernel's
  /// linux/arch/x86/include/asm/perf_event.h macro X86_RAW_EVENT_MASK.
  EventConfigs makeConfigs(uint32_t pmu_type) const {
    uint64_t config = (encoding.cmask << 24) |
        (((uint64_t)encoding.inv) << 23) | (((uint64_t)encoding.any) << 21) |
        (((uint64_t)encoding.edge) << 18) | (encoding.umask << 8u) |
        encoding.code;

    uint64_t config1 = 0x0, config2 = 0x0;
    size_t num_msr_values = encoding.msr_values.size();
    if (num_msr_values > 0) {
      HBT_ARG_CHECK_GE(num_msr_values, 1);
      HBT_ARG_CHECK_LE(num_msr_values, 2);
      if (num_msr_values >= 1) {
        config1 = encoding.msr_values[0];
      }
      if (num_msr_values == 2) {
        config2 = encoding.msr_values[1];
      }
    }
    return EventConfigs{
        .type = pmu_type,
        .config = config,
        .config1 = config1,
        .config2 = config2};
  }
};

std::ostream& operator<<(std::ostream&, const EventDef::Encoding&);
std::ostream& operator<<(std::ostream&, const EventDef::ScaleData&);
std::ostream& operator<<(std::ostream&, const EventDef::IntelFeatures&);
std::ostream& operator<<(std::ostream&, const EventDef&);

using EventDefs = std::vector<std::shared_ptr<EventDef>>;

} // namespace facebook::hbt::perf_event
