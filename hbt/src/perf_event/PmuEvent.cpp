// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/PmuEvent.h"

#include <string>

namespace facebook::hbt::perf_event {

ScaleUnit scaleUnitFromStr(const std::string& s) {
  if (s == "Bytes")
    return ScaleUnit::Bytes;
  if (s == "Joules")
    return ScaleUnit::Joules;
  if (s == "MiB")
    return ScaleUnit::MiB;
  HBT_THROW_EINVAL() << "Unknown ScaleUnit string \"" + s + "\"";
  __builtin_unreachable();
}

std::string scaleUnitToStr(ScaleUnit u) {
  switch (u) {
    case ScaleUnit::Bytes:
      return "Bytes";
    case ScaleUnit::Joules:
      return "Joules";
    case ScaleUnit::MiB:
      return "MiB";
    default:
      HBT_THROW_EINVAL() << "Unknown ScaleUnit " + std::to_string((int)u);
      __builtin_unreachable();
  }
}

std::string preciseIpLevelToStr(PreciseIpLevel p) {
  switch (p) {
    case PreciseIpLevel::kNone:
      return "Any skid";
    case PreciseIpLevel::kConstantSkid:
      return "Constant skid";
    case PreciseIpLevel::kRequestZeroSkid:
      return "Request zero skid";
    case PreciseIpLevel::kRequireZeroSkid:
      return "Require zero skid";
    default:
      __builtin_unreachable();
  }
}

std::ostream& operator<<(std::ostream& os, const EventDef::Encoding& ec) {
  os << "code: 0x" << std::hex << ec.code << " ";
  if (ec.umask != 0x0) {
    os << "umask: 0x" << std::hex << ec.umask << " ";
  }

  if (ec.edge) {
    os << "edge ";
  }
  if (ec.any) {
    os << "any ";
  }
  if (ec.inv) {
    os << "inv ";
  }

  if (ec.cmask != 0) {
    os << " cmask: 0x" << std::hex << ec.cmask;
  }

  if (ec.msr_values.size()) {
    os << "MSR Values: [ ";
    for (auto v : ec.msr_values) {
      os << "0x" << v << " ";
    }
    os << "] ";
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const EventDef::ScaleData& s) {
  if (std::holds_alternative<int>(s.scale_factor)) {
    auto f = std::get<int>(s.scale_factor);
    if (f != 1) {
      os << " scale_unit: " << std::dec << f;
    }
  } else if (std::holds_alternative<double>(s.scale_factor)) {
    auto f = std::get<double>(s.scale_factor);
    if (f != 1.0) {
      os << " scale_unit: " << std::dec << f;
    }
  }
  os << " " << scaleUnitToStr(s.scale_unit) << " ";
  return os;
}

std::ostream& operator<<(std::ostream& os, const EventDef::IntelFeatures& f) {
  os << "<Intel JSON features: [";
  if (f.data_la) {
    os << " <Data Linear Address>";
  }
  if (f.l1_hit_indication) {
    os << " <PEBS with L1 hit/miss>";
  }
  if (f.ellc) {
    os << " <eLLC>";
  }
  if (f.pebs == 1) {
    os << " <PEBS supported>";
  } else if (f.pebs == 2) {
    os << " <PEBS only>";
  }
  os << "]> ";
  return os;
}

std::ostream& operator<<(std::ostream& os, const EventExtraAttr& attr) {
  if (attr.exclude_user || attr.exclude_kernel || attr.exclude_idle) {
    os << "exclude: [ ";
    if (attr.exclude_user) {
      os << "user ";
    }
    if (attr.exclude_kernel) {
      os << "kernel ";
    }
    if (attr.exclude_hv) {
      os << "hv ";
    }
    if (attr.exclude_idle) {
      os << "idle ";
    }
    if (attr.exclude_host) {
      os << "host ";
    }
    if (attr.exclude_guest) {
      os << "guest ";
    }

    os << "] ";
  }

  os << " Precise IP: " << preciseIpLevelToStr(attr.precise_ip);

  return os;
}

std::ostream& operator<<(std::ostream& os, const EventValueTransforms& t) {
  if (t.flags & EventValueTransforms::Flags::TscToKernelTime) {
    os << "TscToKernelTime";
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const EventConfigs& ev_configs) {
  os << "type: " << std::dec << ev_configs.type << " ";
  if (ev_configs.config != 0x0) {
    os << "config: 0x" << std::hex << ev_configs.config;
  }
  if (ev_configs.config1 != 0x0) {
    os << "config1: 0x" << std::hex << ev_configs.config1;
  }
  if (ev_configs.config2 != 0x0) {
    os << "config2: 0x" << std::hex << ev_configs.config2;
  }

  return os;
}

std::ostream& operator<<(std::ostream& os, const EventConf& ev_conf) {
  os << "<EventConf id: \"" << ev_conf.id << "\" ";
  os << ev_conf.configs << " ";
  os << std::dec << ev_conf.extra_attr;

  return os << ">";
}

std::ostream& operator<<(std::ostream& os, const EventDef& ev) {
  os << "<EventDef id: \"" << ev.id << "\" ";
  os << ev.encoding;
  if (ev.scale_data.has_value()) {
    os << *ev.scale_data;
  }
  if (ev.features.has_value()) {
    os << *ev.features;
  }

  if (ev.default_sampling_period.has_value()) {
    os << " Default Sampling Period: " << *ev.default_sampling_period << " ";
  }
  os << "Brief: \"" << ev.brief_desc << "\"";
  if (ev.errata) {
    os << " Errata: \"" << *ev.errata << "\"";
  }

  return os << ">";
}

} // namespace facebook::hbt::perf_event
