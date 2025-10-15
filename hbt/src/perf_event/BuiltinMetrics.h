// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <utility>

#include "hbt/src/perf_event/CpuArch.h"
#include "hbt/src/perf_event/Metrics.h"

namespace facebook::hbt::perf_event {

std::shared_ptr<PmuDeviceManager> makePmuDeviceManager();
void populatePmuDeviceManager(std::shared_ptr<PmuDeviceManager>& pmu_manager);
std::shared_ptr<Metrics> makeAvailableMetrics();
std::shared_ptr<Metrics> makeAvailableMetricsForCpu(const CpuInfo& cpu_info);
void addArmCoreMetrics(std::shared_ptr<Metrics>& metrics);
void addIntelCoreMetrics(std::shared_ptr<Metrics>& metrics);
void addUncoreMetrics(std::shared_ptr<Metrics>& metrics);
void addArmUncoreMetrics(
    std::shared_ptr<Metrics>& metrics,
    uint32_t cpuSockets = 1);
void addIntelUncoreMetrics(std::shared_ptr<Metrics>& metrics);

struct HwCacheEventInfo {
  // this is not unique, but enum of different cache event
  uint32_t id;
  std::string description;
  HwCacheEventInfo(uint32_t id, std::string descrption)
      : id(id), description(std::move(descrption)) {}
};

const ReducerFunc& getAddReducer();
const ReducerFunc& getRateReducer();
} // namespace facebook::hbt::perf_event
