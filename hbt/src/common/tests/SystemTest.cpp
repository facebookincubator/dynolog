// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/common/System.h"
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
