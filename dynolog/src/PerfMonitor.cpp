// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/PerfMonitor.h"
#include <glog/logging.h>

namespace dynolog {

PerfMonitor::PerfMonitor(
    const hbt::CpuSet& monCpus,
    const std::vector<ElemId>& metricIds,
    std::shared_ptr<hbt::perf_event::PmuDeviceManager> pmuDeviceManager,
    std::shared_ptr<hbt::perf_event::Metrics> availableMetrics)
    : monCpus_(monCpus),
      pmuDeviceManager_{pmuDeviceManager},
      defaultMuxGroupId_() {
  for (ElemId id : metricIds) {
    countReaders_.emplace(
        id,
        hbtMon_.emplaceCountReader(
            defaultMuxGroupId_,
            id,
            availableMetrics->getMetricDesc(id),
            pmuDeviceManager_,
            monCpus_,
            nullptr));
  }
  hbtMon_.open();
  hbtMon_.enable();
}

void PerfMonitor::step() {
  readValues_ = hbtMon_.readAllCounts();
}

void PerfMonitor::log(Logger& logger) {
  for (auto& [id, countReader] : countReaders_) {
    if (countReader == nullptr) {
      LOG(ERROR) << "Encountered null countReader for ElemId " << id;
      continue;
    }
    auto eventRefsOpt = countReader->metric_desc->getEventRefs(
        countReader->pmu_manager->cpuInfo.cpu_arch);
    auto readValueOpt = readValues_[id];
    if (!eventRefsOpt.has_value() || !readValueOpt.has_value()) {
      LOG(ERROR) << "Invalid EventRefs or ReadValue encountered for ElemId "
                 << id;
      continue;
    }
    uint64_t time = readValueOpt->getTimeRunning();
    for (int i = 0; i < eventRefsOpt->size(); i++) {
      std::string nickname = (*eventRefsOpt)[i].nickname;
      uint64_t count = readValueOpt->getCount(i);
      if (id == "instructions" && nickname == "instructions") {
        // * 10^9 (nanoseconds) / 10^6 (millions of instructions)
        float countPerSec = static_cast<float>(
            static_cast<double>(count) * 1e3 / static_cast<double>(time));
        std::string key = "mips";
        logger.logFloat(key, countPerSec);
      } else if (id == "cycles" && nickname == "cycles") {
        // * 10^9 (nanoseconds) / 10^6 (millions of instructions)
        float countPerSec = static_cast<float>(
            static_cast<double>(count) * 1e3 / static_cast<double>(time));
        std::string key = "mega_cycles_per_second";
        logger.logFloat(key, countPerSec);
      } else {
        logger.logUint(nickname, count);
      }
    }
  }
}

std::shared_ptr<hbt::perf_event::Metrics> getDefaultMetrics() {
  static auto am = hbt::perf_event::makeAvailableMetrics();
  return am;
}

std::shared_ptr<hbt::perf_event::PmuDeviceManager>
getDefaultPmuDeviceManager() {
  static auto pmudm = hbt::perf_event::makePmuDeviceManager();
  return pmudm;
}

} // namespace dynolog
