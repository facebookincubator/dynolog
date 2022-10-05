// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/Metrics.h"

namespace facebook::hbt::perf_event {

std::ostream& operator<<(std::ostream& os, const EventRef& ev_ref) {
  auto pmu_type = ev_ref.pmu_type;
  os << "pmu: " << PmuTypeToStr(pmu_type);
  os << " \"" << ev_ref.nickname << "\" id: \"" << ev_ref.event_id << "\" ";
  os << ev_ref.extra_attr;
  os << ev_ref.transforms;

  return os;
}

std::ostream& operator<<(std::ostream& os, const TOptCpuArch& cpu_arch) {
  if (cpu_arch.has_value()) {
    return os << *cpu_arch;
  } else {
    return os << "<UNSPECIFIED>";
  }
}

std::ostream& operator<<(std::ostream& os, const MetricDesc& desc) {
  os << "\nMetricDesc id:\"" << desc.id << "\"\n  brief: \"" << desc.brief_desc
     << "\"\n  Default sampling period: " << desc.default_sampling_period
     << "\n"
     << "\n  Events:\n";
  for (const auto& [arch_info, event_refs] : desc.event_refs_by_arch) {
    if (arch_info.has_value()) {
      os << *arch_info << "\n";
    } else {
      os << "Generic\n";
    }
    for (const auto& r : event_refs) {
      os << "    " << r << "\n";
    }
  }

  if (desc.dives.size()) {
    os << "\n  dives=[ ";
    for (const auto& d : desc.dives) {
      os << d << " ";
    }
    os << "]";
  }
  return os << "\n";
}

} // namespace facebook::hbt::perf_event
