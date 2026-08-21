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

  // Values mirror testing/root/proc/vmstat; unrelated lines must be ignored.
  const auto& s = collector.getStats();
  EXPECT_EQ(s.pgscanDirect, 250000);
  EXPECT_EQ(s.pgscanKswapd, 5000000);
  EXPECT_EQ(s.pgstealKswapd, 4800000);
  EXPECT_EQ(s.pageoutrun, 60000);
  EXPECT_EQ(s.compactStall, 4000);
  EXPECT_EQ(s.compactFail, 1500);
  EXPECT_EQ(s.compactSuccess, 2500);
  EXPECT_EQ(s.compactFreeScanned, 6000000);
  EXPECT_EQ(s.compactMigrateScanned, 3000000);
  EXPECT_EQ(s.compactIsolated, 1500000);
  EXPECT_EQ(s.pgmajfault, 123456);
  EXPECT_EQ(s.workingsetRefaultAnon, 111111);
  EXPECT_EQ(s.workingsetRefaultFile, 222222);
  EXPECT_EQ(s.pgpromoteCandidate, 777777);
}

TEST(VmStatCollectorTest, MissingKeysDefaultToZero) {
  // vmstat_legacy models an older kernel lacking NUMA-tiering / workingset
  // refault counters. Absent keys must stay 0 while present keys still parse.
  VmStatCollector collector(vmStatPath("vmstat_legacy"));
  ASSERT_TRUE(collector.readStats());

  const auto& s = collector.getStats();
  EXPECT_EQ(s.pgpromoteCandidate, 0);
  EXPECT_EQ(s.workingsetRefaultAnon, 0);
  EXPECT_EQ(s.workingsetRefaultFile, 0);
  EXPECT_EQ(s.pgscanDirect, 200000);
  EXPECT_EQ(s.pgmajfault, 100000);
}

TEST(VmStatCollectorTest, FirstReadHasZeroDelta) {
  VmStatCollector collector(vmStatPath("vmstat"));
  ASSERT_TRUE(collector.readStats());

  const auto& d = collector.getDelta();
  EXPECT_EQ(d.pgscanDirect, 0);
  EXPECT_EQ(d.pgmajfault, 0);
  EXPECT_EQ(d.compactStall, 0);
}

TEST(VmStatCollectorTest, UnchangedSnapshotYieldsZeroDelta) {
  // Reading the same file twice: the counters did not move, so the delta is 0
  // (proves the previous snapshot is subtracted rather than double counted).
  VmStatCollector collector(vmStatPath("vmstat"));
  ASSERT_TRUE(collector.readStats());
  ASSERT_TRUE(collector.readStats());

  const auto& d = collector.getDelta();
  EXPECT_EQ(d.pgscanDirect, 0);
  EXPECT_EQ(d.pgscanKswapd, 0);
  EXPECT_EQ(d.pgpromoteCandidate, 0);
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

  const VmStats delta = cur - prev;
  EXPECT_EQ(delta.pgscanDirect, 75);
  EXPECT_EQ(delta.pgmajfault, 0); // reset (cur < prev) clamped, no underflow
  EXPECT_EQ(delta.compactStall, 0); // unchanged
}

} // namespace dynolog
