// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/StaticEventDef.h"

#include "hbt/src/perf_event/PmuEvent.h"

#include <string>
#include <vector>

namespace facebook::hbt::perf_event {
namespace {

std::vector<uint64_t> materializeMsrValues(
    const std::variant<std::monostate, uint64_t, std::array<uint64_t, 2>>&
        msr_values) {
  if (std::holds_alternative<std::monostate>(msr_values)) {
    return {};
  }
  if (const auto* value = std::get_if<uint64_t>(&msr_values)) {
    return {*value};
  }
  const auto& values = std::get<std::array<uint64_t, 2>>(msr_values);
  return {values[0], values[1]};
}

EventDef::Encoding materializeEncoding(
    const StaticEventDef::Encoding& encoding) {
  return EventDef::Encoding{
      .code = encoding.code,
      .umask = encoding.umask,
      .umaskExt = encoding.umask_ext,
      .edge = encoding.edge,
      .any = encoding.any,
      .inv = encoding.inv,
      .cmask = encoding.cmask,
      .msr_values = materializeMsrValues(encoding.msr_values)};
}

std::optional<EventDef::ScaleData> materializeScaleData(
    const std::optional<StaticEventDef::ScaleData>& scale_data) {
  if (!scale_data.has_value()) {
    return std::nullopt;
  }
  return EventDef::ScaleData{
      .scale_factor = scale_data->scale_factor,
      .scale_unit = scale_data->scale_unit};
}

std::optional<EventDef::IntelFeatures> materializeIntelFeatures(
    const std::optional<StaticEventDef::IntelFeatures>& features) {
  if (!features.has_value()) {
    return std::nullopt;
  }
  return EventDef::IntelFeatures{
      .data_la = features->data_la,
      .l1_hit_indication = features->l1_hit_indication,
      .ellc = features->ellc,
      .pebs = features->pebs};
}

std::optional<std::string> materializeErrata(
    const std::optional<std::string_view>& errata) {
  if (!errata.has_value()) {
    return std::nullopt;
  }
  return std::string{*errata};
}

} // namespace

EventDef materializeEventDef(const StaticEventDef& event) {
  return EventDef{
      event.pmu_type,
      std::string{event.id},
      materializeEncoding(event.encoding),
      std::string{event.brief_desc},
      std::string{event.full_desc},
      event.default_sampling_period,
      materializeScaleData(event.scale_data),
      materializeIntelFeatures(event.features),
      materializeErrata(event.errata)};
}

} // namespace facebook::hbt::perf_event
