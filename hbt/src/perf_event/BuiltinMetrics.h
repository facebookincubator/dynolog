// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/perf_event/Metrics.h"
#include "hbt/src/perf_event/json_events/generated/CpuArch.h"

namespace facebook::hbt::perf_event {

std::shared_ptr<PmuDeviceManager> makePmuDeviceManager();
std::shared_ptr<Metrics> makeAvailableMetrics();
struct HwCacheEventInfo {
  // this is not unique, but enum of different cache event
  uint32_t id;
  std::string description;
  HwCacheEventInfo(uint32_t id, std::string descrption)
      : id(id), description(descrption) {}
};

} // namespace facebook::hbt::perf_event
