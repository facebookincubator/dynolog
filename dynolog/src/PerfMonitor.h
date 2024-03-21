// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "dynolog/src/Logger.h"
#include "hbt/src/mon/Monitor.h"
#include "hbt/src/perf_event/BuiltinMetrics.h"

namespace hbt = facebook::hbt;

namespace dynolog {

/* Open source dynolog Performance Monitor
 *  - no dependency on Meta infra
 *  - support generic logging
 */

using MuxGroupId = hbt::mon::Monitor<>::MuxGroupId;
using TCpuCountReader = hbt::mon::Monitor<>::TCpuCountReader;
using ElemId = hbt::mon::Monitor<>::ElemId;

class PerfMonitor {
 public:
  explicit PerfMonitor(
      const hbt::CpuSet& monCpus,
      const std::vector<ElemId>& metricIds,
      std::shared_ptr<hbt::perf_event::PmuDeviceManager> pmuDeviceManager,
      std::shared_ptr<hbt::perf_event::Metrics> availableMetrics);

  // perform metric lookups
  void step();
  void log(Logger& logger);

 protected:
  hbt::mon::Monitor<> hbtMon_;
  const hbt::CpuSet& monCpus_;
  std::shared_ptr<hbt::perf_event::PmuDeviceManager> pmuDeviceManager_;
  const MuxGroupId defaultMuxGroupId_;
  std::map<ElemId, std::optional<TCpuCountReader::ReadValues>> readValues_;
  std::map<ElemId, std::shared_ptr<TCpuCountReader>> countReaders_;
};

// singleton object for default Metrics and PmuDeviceManager
std::shared_ptr<hbt::perf_event::Metrics> getDefaultMetrics();
std::shared_ptr<hbt::perf_event::PmuDeviceManager> getDefaultPmuDeviceManager();

} // namespace dynolog
