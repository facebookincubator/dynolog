/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/VmStatCollector.h"

#include <gtest/gtest.h>
#include <cstdlib>
#include <string>

namespace dynolog {

namespace {

std::string vmStatPath(const std::string& file) {
  const char* root = std::getenv("TESTROOT");
  return std::string(root ? root : "") + "/proc/" + file;
}

} // namespace

TEST(VmStatCollectorTest, ParsesTargetFields) {
  VmStatCollector collector(vmStatPath("vmstat"));
  ASSERT_TRUE(collector.readStats());
  EXPECT_TRUE(collector.isAvailable());

  const VmStats expected{
      .pgscanDirect = 250000,
      .pgscanKswapd = 5000000,
      .pgstealKswapd = 4800000,
      .pageoutrun = 60000,
      .compactStall = 4000,
      .compactFail = 1500,
      .compactSuccess = 2500,
      .compactFreeScanned = 6000000,
      .compactMigrateScanned = 3000000,
      .compactIsolated = 1500000,
      .pgmajfault = 123456,
      .workingsetRefaultAnon = 111111,
      .workingsetRefaultFile = 222222,
      .pgpromoteCandidate = 777777,
  };
  EXPECT_EQ(collector.getStats(), expected);
}

TEST(VmStatCollectorTest, MissingKeysDefaultToZero) {
  // vmstat_legacy models an older kernel lacking NUMA-tiering / workingset
  // refault counters. Absent keys must stay 0 while present keys still parse.
  VmStatCollector collector(vmStatPath("vmstat_legacy"));
  ASSERT_TRUE(collector.readStats());

  const VmStats expected{
      .pgscanDirect = 200000,
      .pgscanKswapd = 4000000,
      .pgstealKswapd = 3800000,
      .pageoutrun = 50000,
      .compactStall = 3000,
      .compactFail = 1000,
      .compactSuccess = 2000,
      .compactFreeScanned = 5000000,
      .compactMigrateScanned = 2000000,
      .compactIsolated = 1000000,
      .pgmajfault = 100000,
  };
  EXPECT_EQ(collector.getStats(), expected);
}

TEST(VmStatCollectorTest, FirstReadHasZeroDelta) {
  VmStatCollector collector(vmStatPath("vmstat"));
  ASSERT_TRUE(collector.readStats());

  EXPECT_EQ(collector.getDelta(), VmStats{});
}

TEST(VmStatCollectorTest, UnchangedSnapshotYieldsZeroDelta) {
  // Reading the same file twice: the counters did not move, so the delta is 0
  // (proves the previous snapshot is subtracted rather than double counted).
  VmStatCollector collector(vmStatPath("vmstat"));
  ASSERT_TRUE(collector.readStats());
  ASSERT_TRUE(collector.readStats());

  EXPECT_EQ(collector.getDelta(), VmStats{});
}

TEST(VmStatCollectorTest, InvalidPathIsUnavailable) {
  VmStatCollector collector(vmStatPath("does_not_exist"));
  EXPECT_FALSE(collector.readStats());
  EXPECT_FALSE(collector.isAvailable());
}

TEST(VmStatCollectorTest, DeltaSubtractsAndClampsCounterReset) {
  VmStats prev;
  prev.pgscanDirect = 100;
  prev.pgmajfault = 500; // higher than cur -> counter reset
  prev.compactStall = 10;

  VmStats cur;
  cur.pgscanDirect = 175;
  cur.pgmajfault = 400;
  cur.compactStall = 10;

  const VmStats expected{
      .pgscanDirect = 75,
  };
  EXPECT_EQ(cur - prev, expected);
}

} // namespace dynolog
