// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <cstdint>

namespace facebook::hbt::perf_event {

/// The configuration data passed to CpuEventsGroup to select the
/// perf_event_attr in perf_event_open.
struct EventConfigs {
  uint32_t type; // The PMU type.
  uint64_t config;
  uint64_t config1 = 0;
  uint64_t config2 = 0;
};

} // namespace facebook::hbt::perf_event
