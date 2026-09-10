// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/perf_event/EventConfigs.h"
#include "hbt/src/perf_event/EventScale.h"
#include "hbt/src/perf_event/PmuType.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <string_view>
#include <variant>

namespace facebook::hbt::perf_event {

struct EventDef;

/// Non-owning event definition for generated constexpr catalogs.
///
/// Strings must refer to static storage. Runtime-created definitions continue
/// to use the owning EventDef representation.
struct StaticEventDef {
  struct Encoding {
    uint64_t code;
    uint64_t umask = 0;
    uint64_t umask_ext = 0;
    bool edge = false;
    bool any = false;
    bool inv = false;
    uint64_t cmask = 0;
    std::variant<std::monostate, uint64_t, std::array<uint64_t, 2>> msr_values;
  };

  struct ScaleData {
    std::variant<int, double> scale_factor;
    ScaleUnit scale_unit;
  };

  struct IntelFeatures {
    bool data_la = false;
    bool l1_hit_indication = false;
    bool ellc = false;
    uint8_t pebs = 0;
  };

  PmuType pmu_type;
  std::string_view id;
  Encoding encoding;
  std::optional<ScaleData> scale_data = std::nullopt;
  std::optional<IntelFeatures> features = std::nullopt;
  std::string_view brief_desc;
  std::string_view full_desc;
  std::optional<uint64_t> default_sampling_period = std::nullopt;
  std::optional<std::string_view> errata = std::nullopt;
};

/// Whether a table has unique entries sorted by (pmu_type, id).
constexpr bool isStaticEventDefTableSorted(
    std::span<const StaticEventDef> events) noexcept {
  for (size_t i = 1; i < events.size(); ++i) {
    const StaticEventDef& prev = events[i - 1];
    const StaticEventDef& current = events[i];
    if (prev.pmu_type > current.pmu_type) {
      return false;
    }
    if (prev.pmu_type == current.pmu_type && !(prev.id < current.id)) {
      return false;
    }
  }
  return true;
}

/// Binary-search a generated table sorted by (pmu_type, id).
constexpr const StaticEventDef* findStaticEventDef(
    std::span<const StaticEventDef> events,
    PmuType pmu_type,
    std::string_view id) noexcept {
  size_t lo = 0;
  size_t hi = events.size();
  while (lo < hi) {
    const size_t mid = lo + (hi - lo) / 2;
    const StaticEventDef& event = events[mid];
    if (event.pmu_type < pmu_type ||
        (event.pmu_type == pmu_type && event.id < id)) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  if (lo == events.size() || events[lo].pmu_type != pmu_type ||
      events[lo].id != id) {
    return nullptr;
  }
  return &events[lo];
}

/// Encode a static definition exactly as EventDef::makeConfigs() does.
constexpr EventConfigs makeEventConfigs(
    const StaticEventDef& event,
    uint32_t new_pmu_type) {
  const uint64_t config = (event.encoding.umask_ext << 32) |
      (event.encoding.cmask << 24) |
      (static_cast<uint64_t>(event.encoding.inv) << 23) |
      (static_cast<uint64_t>(event.encoding.any) << 21) |
      (static_cast<uint64_t>(event.encoding.edge) << 18) |
      (event.encoding.umask << 8) | event.encoding.code;

  uint64_t config1 = 0;
  uint64_t config2 = 0;
  if (const auto* value = std::get_if<uint64_t>(&event.encoding.msr_values)) {
    config1 = *value;
  } else if (
      const auto* values =
          std::get_if<std::array<uint64_t, 2>>(&event.encoding.msr_values)) {
    config1 = (*values)[0];
    config2 = (*values)[1];
  }

  return EventConfigs{
      .type = new_pmu_type,
      .config = config,
      .config1 = config1,
      .config2 = config2};
}

/// Convert a static definition to the existing owning representation.
EventDef materializeEventDef(const StaticEventDef& event);

} // namespace facebook::hbt::perf_event
