// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once
#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/PmuDevices.h"

namespace facebook::hbt::perf_event {
namespace neoverse_v2 {
void setTestRootDir(const std::string& rootDir);
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace neoverse_v2

void addArmEvents(const CpuInfo& cpu_info, PmuDeviceManager& pmu_manager);

} // namespace facebook::hbt::perf_event
