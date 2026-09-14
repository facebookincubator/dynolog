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

constexpr std::array<VmStatField, 26> kVmStatFields = {{
    {"pgscan_direct", &VmStats::pgscanDirect},
    {"pgscan_kswapd", &VmStats::pgscanKswapd},
    {"pgscan_proactive", &VmStats::pgscanProactive},
    {"pgsteal_kswapd", &VmStats::pgstealKswapd},
    {"pageoutrun", &VmStats::pageoutrun},
    {"compact_stall", &VmStats::compactStall},
    {"compact_fail", &VmStats::compactFail},
    {"compact_success", &VmStats::compactSuccess},
    {"compact_free_scanned", &VmStats::compactFreeScanned},
    {"compact_migrate_scanned", &VmStats::compactMigrateScanned},
    {"compact_isolated", &VmStats::compactIsolated},
    {"pgfault", &VmStats::pgfault},
    {"pgmajfault", &VmStats::pgmajfault},
    {"workingset_refault_anon", &VmStats::workingsetRefaultAnon},
    {"workingset_refault_file", &VmStats::workingsetRefaultFile},
    {"workingset_activate_anon", &VmStats::workingsetActivateAnon},
    {"workingset_activate_file", &VmStats::workingsetActivateFile},
    {"pgpromote_candidate", &VmStats::pgpromoteCandidate},
    {"pgpgin", &VmStats::pgpgin},
    {"pgpgout", &VmStats::pgpgout},
    {"pswpin", &VmStats::pswpin},
    {"pswpout", &VmStats::pswpout},
    {"zswpin", &VmStats::zswpin},
    {"zswpout", &VmStats::zswpout},
    {"pgalloc_normal", &VmStats::pgallocNormal},
    {"pgfree", &VmStats::pgfree},
}};

// Counters are monotonic, so cur >= prev normally. The comparison avoids
// unsigned underflow when a counter resets or a field disappears.
uint64_t clampDelta(uint64_t cur, uint64_t prev) {
  return cur >= prev ? cur - prev : 0;
}

} // namespace

VmStats VmStats::operator-(const VmStats& prev) const {
  // Driven off kVmStatFields so a field cannot be parsed but then silently
  // left out of the delta.
  VmStats delta;
  for (const auto& [_, member] : kVmStatFields) {
    delta.*member = clampDelta(this->*member, prev.*member);
  }
  return delta;
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
