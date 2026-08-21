/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/VmStatCollector.h"

#include <folly/logging/xlog.h>
#include <fstream>
#include <unordered_map>

namespace dynolog {

namespace {

// Maps the /proc/vmstat key to the VmStats member it populates. Keys that are
// absent on a given kernel (e.g. pgpromote_candidate without NUMA tiering)
// simply never match and leave their field at 0.
const std::unordered_map<std::string, uint64_t VmStats::*>& fieldMap() {
  static const std::unordered_map<std::string, uint64_t VmStats::*> kMap = {
      {"pgscan_direct", &VmStats::pgscanDirect},
      {"pgscan_kswapd", &VmStats::pgscanKswapd},
      {"pgsteal_kswapd", &VmStats::pgstealKswapd},
      {"pageoutrun", &VmStats::pageoutrun},
      {"compact_stall", &VmStats::compactStall},
      {"compact_fail", &VmStats::compactFail},
      {"compact_success", &VmStats::compactSuccess},
      {"compact_free_scanned", &VmStats::compactFreeScanned},
      {"compact_migrate_scanned", &VmStats::compactMigrateScanned},
      {"compact_isolated", &VmStats::compactIsolated},
      {"pgmajfault", &VmStats::pgmajfault},
      {"workingset_refault_anon", &VmStats::workingsetRefaultAnon},
      {"workingset_refault_file", &VmStats::workingsetRefaultFile},
      {"pgpromote_candidate", &VmStats::pgpromoteCandidate},
  };
  return kMap;
}

// Counters are monotonic, so cur >= prev normally. The comparison avoids
// unsigned underflow when a counter resets or a field disappears.
uint64_t clampDelta(uint64_t cur, uint64_t prev) {
  return cur >= prev ? cur - prev : 0;
}

} // namespace

VmStats VmStats::operator-(const VmStats& prev) const {
  return VmStats{
      .pgscanDirect = clampDelta(pgscanDirect, prev.pgscanDirect),
      .pgscanKswapd = clampDelta(pgscanKswapd, prev.pgscanKswapd),
      .pgstealKswapd = clampDelta(pgstealKswapd, prev.pgstealKswapd),
      .pageoutrun = clampDelta(pageoutrun, prev.pageoutrun),
      .compactStall = clampDelta(compactStall, prev.compactStall),
      .compactFail = clampDelta(compactFail, prev.compactFail),
      .compactSuccess = clampDelta(compactSuccess, prev.compactSuccess),
      .compactFreeScanned =
          clampDelta(compactFreeScanned, prev.compactFreeScanned),
      .compactMigrateScanned =
          clampDelta(compactMigrateScanned, prev.compactMigrateScanned),
      .compactIsolated = clampDelta(compactIsolated, prev.compactIsolated),
      .pgmajfault = clampDelta(pgmajfault, prev.pgmajfault),
      .workingsetRefaultAnon =
          clampDelta(workingsetRefaultAnon, prev.workingsetRefaultAnon),
      .workingsetRefaultFile =
          clampDelta(workingsetRefaultFile, prev.workingsetRefaultFile),
      .pgpromoteCandidate =
          clampDelta(pgpromoteCandidate, prev.pgpromoteCandidate),
  };
}

VmStatCollector::VmStatCollector(const std::string& vmStatPath)
    : vmStatPath_(vmStatPath) {}

bool VmStatCollector::readStats() {
  std::ifstream file(vmStatPath_);
  if (!file.is_open()) {
    available_ = false;
    XLOG_EVERY_MS(WARN, 60000)
        << "VmStatCollector: failed to open " << vmStatPath_;
    return false;
  }
  available_ = true;

  prevStats_ = stats_;
  stats_ = VmStats{};

  const auto& map = fieldMap();
  std::string key;
  uint64_t value = 0;
  // /proc/vmstat is a flat list of "name value" lines.
  while (file >> key >> value) {
    auto it = map.find(key);
    if (it != map.end()) {
      stats_.*(it->second) = value;
    }
  }

  if (first_) {
    first_ = false;
    delta_ = VmStats{};
  } else {
    delta_ = stats_ - prevStats_;
  }

  return true;
}

} // namespace dynolog
