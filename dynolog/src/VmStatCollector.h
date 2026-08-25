/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <cstdint>
#include <string>

namespace dynolog {

/**
 * VmStats: Selected virtual-memory statistics from /proc/vmstat.
 *
 * Every field here is a monotonically increasing since-boot event counter. The
 * collector exposes per-read deltas via getDelta(); callers accumulate those
 * deltas over their reporting interval to obtain the total increase.
 */
struct VmStats {
  // Reclaim
  uint64_t pgscanDirect = 0;
  uint64_t pgscanKswapd = 0;
  uint64_t pgstealKswapd = 0;
  uint64_t pageoutrun = 0;

  // Compaction
  uint64_t compactStall = 0;
  uint64_t compactFail = 0;
  uint64_t compactSuccess = 0;
  uint64_t compactFreeScanned = 0;
  uint64_t compactMigrateScanned = 0;
  uint64_t compactIsolated = 0;

  // Faults / working set / NUMA promotion
  uint64_t pgmajfault = 0;
  uint64_t workingsetRefaultAnon = 0;
  uint64_t workingsetRefaultFile = 0;
  uint64_t pgpromoteCandidate = 0;

  // Delta between two readings. A counter reset (cur < prev), or a field that
  // appeared/disappeared across kernels, yields 0 rather than underflowing.
  VmStats operator-(const VmStats& prev) const;

  bool operator==(const VmStats&) const = default;
};

/**
 * VmStatCollector: parses the subset of /proc/vmstat fields in VmStats.
 *
 * Usage:
 *   VmStatCollector collector;
 *   collector.readStats();
 *   const auto& delta = collector.getDelta();
 */
class VmStatCollector {
 public:
  explicit VmStatCollector(const std::string& vmStatPath = "/proc/vmstat");

  // Read current values from the vmstat file. Returns true if the file was
  // read successfully. The first successful read only seeds the baseline, so
  // getDelta() stays zero until the second read.
  bool readStats();

  bool isAvailable() const {
    return available_;
  }

  const VmStats& getStats() const {
    return stats_;
  }

  const VmStats& getDelta() const {
    return delta_;
  }

 protected:
  std::string vmStatPath_;
  bool available_ = false;
  bool first_ = true;
  VmStats stats_;
  VmStats prevStats_;
  VmStats delta_;
};

} // namespace dynolog
