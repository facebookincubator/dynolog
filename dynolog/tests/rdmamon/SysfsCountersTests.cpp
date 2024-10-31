// Copyright (c) Meta Platforms, Inc. and affiliates.

// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>

#include <filesystem>
#include "dynolog/src/rdmamon/SysfsCounter.h"

using namespace dynolog::rdmamon;

TEST(SysfsCounters, getCounterTest) {
  char buffer[256];
  std::string tmpfile_path = std::tmpnam(nullptr);
  std::string test_counter_name = "foobar";
  uint64_t expected_val1 = 101;

  // Create a temprary file and write a counter to that file.
  std::sprintf(buffer, "%lu", expected_val1);
  std::FILE* tmpf = fopen(tmpfile_path.c_str(), "w+");
  std::fputs(buffer, tmpf);
  fclose(tmpf);

  auto sysfs_counters =
      std::make_shared<SysfsCounter>(test_counter_name, tmpfile_path);
  EXPECT_TRUE(sysfs_counters->openSysfsCounter());

  auto actual_val1_ref = sysfs_counters->getSysfsCounter();
  EXPECT_TRUE(actual_val1_ref);
  EXPECT_EQ(expected_val1, *actual_val1_ref);

  // Update the content of the file
  uint64_t expected_val2 = 202;
  std::sprintf(buffer, "%lu", expected_val2);
  tmpf = fopen(tmpfile_path.c_str(), "w+");
  std::fputs(buffer, tmpf);
  fclose(tmpf);
  auto actual_val2_ref = sysfs_counters->getSysfsCounter();
  EXPECT_TRUE(actual_val2_ref);
  EXPECT_EQ(expected_val2, *actual_val2_ref);

  // Check the name of the counter
  EXPECT_EQ(test_counter_name, sysfs_counters->getSysfsCounterName());

  remove(tmpfile_path.c_str());
}
