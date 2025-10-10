// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/common/System.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace facebook::hbt;

TEST(Defs, CpuSet) {
  // Skip on CI due to offline CPUs
  // Error = <CpuSet max_cpu_id: 1 max_cpu_id_online: 1 cpus: 1 > unknown file:
  // Failure
  if (std::getenv("GITHUB_WORKFLOW") != nullptr) {
    GTEST_SKIP() << "Skipping CPU set test on CI.";
  }
  {
    auto c = CpuSet::makeAllOnline();
    EXPECT_TRUE(c.hasCpu(0));
  }
  {
    auto c = CpuSet::makeFromCont(std::vector<unsigned>{});
    EXPECT_FALSE(c.hasCpu(1));
  }

  {
    auto c = CpuSet::makeFromCont(std::initializer_list<CpuId>{1});
    std::cout << c;
    EXPECT_FALSE(c.hasCpu(0));
    EXPECT_TRUE(c.hasCpu(1));
    EXPECT_FALSE(c.hasCpu(11));
  }

  {
    auto c = CpuSet::makeFromCont(std::set<int>{0, 12});
    std::cout << c;
    EXPECT_TRUE(c.hasCpu(0));
    EXPECT_FALSE(c.hasCpu(1));
    EXPECT_FALSE(c.hasCpu(1));
    EXPECT_FALSE(c.hasCpu(11));
    EXPECT_TRUE(c.hasCpu(12));
    EXPECT_FALSE(c.hasCpu(21));
  }

  {
    // Test implicit copy constructor.
    auto c0 = CpuSet::makeAllOnline();
    CpuSet c(c0);
    EXPECT_TRUE(c.hasCpu(0));
  }

  {
    // Test move constructor.
    auto c0 = CpuSet::makeAllOnline();
    CpuSet c(std::move(c0));
    EXPECT_TRUE(c.hasCpu(0));
  }
}

TEST(ParseCpu, CpuRange) {
  {
    auto cpus = parseCpusRange("");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }

  {
    auto cpus = parseCpusRange(" \n ");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }

  {
    auto cpus = parseCpusRange(" ");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }

  {
    auto cpus = parseCpusRange("5");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    CPU_SET(5, &exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }

  {
    auto cpus = parseCpusRange("0-1");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    CPU_SET(0, &exp);
    CPU_SET(1, &exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }
}

TEST(ParseCpu, CpuList) {
  {
    auto cpus = parseCpusList("");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }

  {
    auto cpus = parseCpusList("\n");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }

  {
    auto cpus = parseCpusList(" \n ");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }
  {
    auto cpus = parseCpusList("5");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    CPU_SET(5, &exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }

  {
    auto cpus = parseCpusList("0-1");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    CPU_SET(0, &exp);
    CPU_SET(1, &exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }

  {
    auto cpus = parseCpusList("5, 0-1");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    CPU_SET(0, &exp);
    CPU_SET(1, &exp);
    CPU_SET(5, &exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }
  {
    auto cpus = parseCpusList("5-6, 0-1,9");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    CPU_SET(0, &exp);
    CPU_SET(1, &exp);
    CPU_SET(5, &exp);
    CPU_SET(6, &exp);
    CPU_SET(9, &exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }
  {
    auto cpus = parseCpusList("49-55");
    cpu_set_t exp;
    CPU_ZERO(&exp);
    CPU_SET(49, &exp);
    CPU_SET(50, &exp);
    CPU_SET(51, &exp);
    CPU_SET(52, &exp);
    CPU_SET(53, &exp);
    CPU_SET(54, &exp);
    CPU_SET(55, &exp);
    EXPECT_TRUE(CPU_EQUAL(&cpus, &exp));
  }
}

TEST(CpuSet, MakeFromCpusList) {
  // Skip on CI due to offline CPUs
  // Error = <CpuSet max_cpu_id: 1 max_cpu_id_online: 1 cpus: 1 > unknown file:
  // Failure
  if (std::getenv("GITHUB_WORKFLOW") != nullptr) {
    GTEST_SKIP() << "Skipping CPU set test on CI.";
  }

  {
    auto cpuSet = CpuSet::makeFromCpusList("");
    EXPECT_EQ(cpuSet.asSet().size(), 0);
  }

  {
    auto cpuSet = CpuSet::makeFromCpusList("\n");
    EXPECT_EQ(cpuSet.asSet().size(), 0);
  }

  {
    auto cpuSet = CpuSet::makeFromCpusList(" \n ");
    EXPECT_EQ(cpuSet.asSet().size(), 0);
  }
  {
    auto cpuSet = CpuSet::makeFromCpusList("5");
    EXPECT_EQ(cpuSet.asSet().size(), 1);
    EXPECT_TRUE(cpuSet.hasCpu(5));
  }

  {
    auto cpuSet = CpuSet::makeFromCpusList("0-1");
    EXPECT_EQ(cpuSet.asSet().size(), 2);
    EXPECT_TRUE(cpuSet.hasCpu(0));
    EXPECT_TRUE(cpuSet.hasCpu(1));
  }

  {
    auto cpuSet = CpuSet::makeFromCpusList("3, 0-1");
    EXPECT_EQ(cpuSet.asSet().size(), 3);
    EXPECT_TRUE(cpuSet.hasCpu(0));
    EXPECT_TRUE(cpuSet.hasCpu(1));
    EXPECT_TRUE(cpuSet.hasCpu(3));
  }
  {
    auto cpuSet = CpuSet::makeFromCpusList("4-5, 0-1,7");
    EXPECT_EQ(cpuSet.asSet().size(), 5);
    EXPECT_TRUE(cpuSet.hasCpu(0));
    EXPECT_TRUE(cpuSet.hasCpu(1));
    EXPECT_TRUE(cpuSet.hasCpu(4));
    EXPECT_TRUE(cpuSet.hasCpu(5));
    EXPECT_TRUE(cpuSet.hasCpu(7));
  }
  {
    auto cpuSet = CpuSet::makeFromCpusList(" 0,2,  4, 6");
    EXPECT_EQ(cpuSet.asSet().size(), 4);
    EXPECT_TRUE(cpuSet.hasCpu(0));
    EXPECT_TRUE(cpuSet.hasCpu(2));
    EXPECT_TRUE(cpuSet.hasCpu(4));
    EXPECT_TRUE(cpuSet.hasCpu(6));
  }
}

TEST(Pow2, isPow2) {
  for (uint64_t i = 0; i < 63; ++i) {
    EXPECT_TRUE(isPow2(1ull << i));
  }

  EXPECT_FALSE(isPow2(3));
  EXPECT_FALSE(isPow2(5));
  EXPECT_FALSE(isPow2(10));
  EXPECT_FALSE(isPow2(15));
  EXPECT_TRUE(isPow2(16));
  EXPECT_FALSE(isPow2(17));
  EXPECT_FALSE(isPow2(18));
  EXPECT_FALSE(isPow2(25));
  EXPECT_FALSE(isPow2(1028));
}

TEST(Pow2, nextPow2) {
  EXPECT_EQ(nextPow2(1u), 1);
  EXPECT_EQ(nextPow2(2u), 2);
  EXPECT_EQ(nextPow2(3u), 4);
  EXPECT_EQ(nextPow2(4u), 4);
  EXPECT_EQ(nextPow2(8u), 8);

  for (uint64_t i = 0; i < 63; ++i) {
    uint64_t p2 = 1ull << i;
    uint64_t next_p2 = 1ull << (i + 1);
    EXPECT_EQ(nextPow2(p2), p2);
    EXPECT_EQ(nextPow2(p2 + 1), next_p2);
  }
}

TEST(Pow2, log2NextPow2) {
  EXPECT_EQ(log2NextPow2((uint32_t)1), 0);
  EXPECT_EQ(log2NextPow2((uint32_t)2), 1);
  EXPECT_EQ(log2NextPow2((uint32_t)3), 2);
  EXPECT_EQ(log2NextPow2((uint32_t)4), 2);
  EXPECT_EQ(log2NextPow2((uint32_t)5), 3);
  EXPECT_EQ(log2NextPow2((uint32_t)6), 3);
  EXPECT_EQ(log2NextPow2((uint32_t)8), 3);

  EXPECT_EQ(log2NextPow2((uint64_t)1), 0);
  EXPECT_EQ(log2NextPow2((uint64_t)2), 1);
  EXPECT_EQ(log2NextPow2((uint64_t)3), 2);
  EXPECT_EQ(log2NextPow2((uint64_t)4), 2);
  EXPECT_EQ(log2NextPow2((uint64_t)5), 3);
  EXPECT_EQ(log2NextPow2((uint64_t)6), 3);
  EXPECT_EQ(log2NextPow2((uint64_t)8), 3);
}

TEST(SystemTest, CpuInfoTest) {
  auto cpu_info = CpuInfo::load();
  HBT_LOG_INFO() << "CpuInfo = " << cpu_info;
}

TEST(SystemTest, GetHostNameTest) {
  auto hostname = getHostName();
  EXPECT_GT(hostname.size(), 0);
  HBT_LOG_INFO() << "hostname = " << hostname;
}

TEST(SystemTest, GetSocketCoreMapFromSysfsTest) {
  // Create a mock sysfs directory structure for testing
  const char* testRootEnv = getenv("TESTROOT");
  if (!testRootEnv) {
    GTEST_SKIP() << "TESTROOT environment variable not set, skipping test";
  }
  std::string testRootDir = testRootEnv;

  // Test with the mock filesystem - uses arbitrary physical package IDs
  // (285212672 and 268435456) which get normalized to sequential socket IDs
  auto result = getSocketCoreMapFromSysfs(testRootDir);

  // Verify the result structure
  ASSERT_EQ(result.size(), 2) << "Expected exactly 2 sockets";

  // Physical package IDs are normalized to sequential socket IDs:
  // - CPUs 0-7 (package 285212672) → socket 0
  // - CPUs 8-15 (package 268435456) → socket 1
  EXPECT_THAT(result[0], testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7))
      << "Socket 0 should have cores 0-7 in order";

  EXPECT_THAT(result[1], testing::ElementsAre(8, 9, 10, 11, 12, 13, 14, 15))
      << "Socket 1 should have cores 8-15 in order";
}
