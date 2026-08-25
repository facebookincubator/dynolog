/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/VmStatCollector.h"

#include <array>
#include <fstream>
#include <string_view>
#include <utility>

#if __has_include(<folly/logging/xlog.h>)
#include <folly/logging/xlog.h>
#define DYNOLOG_HAS_XLOG 1
#else
#include <glog/logging.h>
#define DYNOLOG_HAS_XLOG 0
#endif

namespace dynolog {

namespace {

using VmStatField = std::pair<std::string_view, uint64_t VmStats::*>;

constexpr std::array<VmStatField, 14> kVmStatFields = {{
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
}};

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
#if DYNOLOG_HAS_XLOG
    XLOG_EVERY_MS(WARN, 60000)
#else
    LOG_EVERY_N(WARNING, 60)
#endif
        << "VmStatCollector: failed to open " << vmStatPath_;
    return false;
  }
  available_ = true;

  prevStats_ = stats_;
  stats_ = VmStats{};

  std::string key;
  uint64_t value = 0;
  // /proc/vmstat is a flat list of "name value" lines.
  while (file >> key >> value) {
    for (const auto& [fieldName, member] : kVmStatFields) {
      if (key == fieldName) {
        stats_.*member = value;
        break;
      }
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

#undef DYNOLOG_HAS_XLOG
