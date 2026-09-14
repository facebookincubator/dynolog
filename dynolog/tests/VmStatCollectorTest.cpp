/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/VmStatCollector.h"

#include <gtest/gtest.h>
#include <cstdlib>
#include <fstream>
#include <string>

namespace dynolog {

namespace {

std::string vmStatPath(const std::string& file) {
  const char* root = std::getenv("TESTROOT");
  return std::string(root ? root : "") + "/proc/" + file;
}

// Writes a synthetic /proc/vmstat so a test can advance the counters between
// reads, which the read-only testroot fixtures cannot express.
void writeVmStat(const std::string& path, const std::string& contents) {
  std::ofstream out(path, std::ios::trunc);
  ASSERT_TRUE(out.is_open()) << "could not write " << path;
  out << contents;
}

} // namespace

TEST(VmStatCollectorTest, ParsesTargetFields) {
  VmStatCollector collector(vmStatPath("vmstat"));
  ASSERT_TRUE(collector.readStats());
  EXPECT_TRUE(collector.isAvailable());

  const VmStats expected{
      .pgscanDirect = 250000,
      .pgscanKswapd = 5000000,
      .pgscanProactive = 90000,
      .pgstealKswapd = 4800000,
      .pageoutrun = 60000,
      .compactStall = 4000,
      .compactFail = 1500,
      .compactSuccess = 2500,
      .compactFreeScanned = 6000000,
      .compactMigrateScanned = 3000000,
      .compactIsolated = 1500000,
      .pgfault = 7654321098,
      .pgmajfault = 123456,
      .workingsetRefaultAnon = 111111,
      .workingsetRefaultFile = 222222,
      .workingsetActivateAnon = 55555,
      .workingsetActivateFile = 66666,
      .pgpromoteCandidate = 777777,
      .pgpgin = 9876543210,
      .pgpgout = 8765432109,
      .pswpin = 12,
      .pswpout = 34,
      .zswpin = 4444,
      .zswpout = 8888,
      .pgallocNormal = 4321098765,
      .pgfree = 4321000000,
  };
  EXPECT_EQ(collector.getStats(), expected);
}

TEST(VmStatCollectorTest, MissingKeysDefaultToZero) {
  // vmstat_legacy models an older kernel lacking NUMA-tiering / workingset
  // counters, zswap, and pgscan_proactive (which only exists from 6.15, where
  // that work otherwise lands in pgscan_direct). Absent keys must stay 0 while
  // present keys still parse.
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
      .pgfault = 5000000000,
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

TEST(VmStatCollectorTest, DeltaAcrossSimulatedReads) {
  // Simulates /proc/vmstat advancing between two collection ticks: the same
  // path is re-read after the counters move, which is how the collector is
  // driven in production.
  const std::string path = ::testing::TempDir() + "/vmstat_simulated";

  writeVmStat(
      path,
      "nr_free_pages 1000000\n" // unparsed key, must be ignored
      "pgscan_proactive 300\n"
      "pgfault 50000\n"
      "pgmajfault 500\n"
      "workingset_activate_anon 40\n"
      "workingset_activate_file 80\n"
      "pgpgin 1000\n"
      "pgpgout 2000\n"
      "pswpin 10\n"
      "pswpout 20\n"
      "zswpin 100\n"
      "zswpout 200\n"
      "pgalloc_normal 900000\n"
      "pgfree 880000\n");

  VmStatCollector collector(path);
  ASSERT_TRUE(collector.readStats());
  ASSERT_EQ(collector.getDelta(), VmStats{});

  // pgmajfault goes backwards (counter reset) and pgscan_proactive disappears;
  // both must clamp to 0 instead of underflowing.
  writeVmStat(
      path,
      "nr_free_pages 999000\n"
      "pgfault 62000\n"
      "pgmajfault 400\n"
      "workingset_activate_anon 55\n"
      "workingset_activate_file 80\n"
      "pgpgin 1500\n"
      "pgpgout 2600\n"
      "pswpin 13\n"
      "pswpout 20\n"
      "zswpin 180\n"
      "zswpout 350\n"
      "pgalloc_normal 950000\n"
      "pgfree 925000\n");
  ASSERT_TRUE(collector.readStats());

  const VmStats expectedDelta{
      .pgfault = 12000,
      .workingsetActivateAnon = 15,
      .pgpgin = 500,
      .pgpgout = 600,
      .pswpin = 3,
      .zswpin = 80,
      .zswpout = 150,
      .pgallocNormal = 50000,
      .pgfree = 45000,
  };
  EXPECT_EQ(collector.getDelta(), expectedDelta);

  // The absolute snapshot tracks the newest read, so a key absent from it
  // reads back as 0 rather than retaining the previous value.
  EXPECT_EQ(collector.getStats().pgfault, 62000u);
  EXPECT_EQ(collector.getStats().pgscanProactive, 0u);
}

} // namespace dynolog
