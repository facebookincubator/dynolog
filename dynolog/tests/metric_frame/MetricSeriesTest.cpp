// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>

#include "dynolog/src/metric_frame/MetricSeries.h"

#include <optional>

using namespace ::testing;
using namespace ::facebook::dynolog;

TEST(MetricSeriesTest, constructor) {
  MetricSeries<int> t(5, "test_metric", "this is a test metric in unittest");
  EXPECT_EQ(t.size(), 0);
  EXPECT_EQ(t.begin(), t.end());
  EXPECT_EQ(t.name(), "test_metric");
  EXPECT_EQ(t.description(), "this is a test metric in unittest");
}

TEST(MetricSeriesTest, testAddSample) {
  MetricSeries<int> t(3, "test_metric", "this is a test metric in unittest");
  t.addSample(5);
  EXPECT_EQ(t.size(), 1);
  t.addSample(4);
  EXPECT_EQ(t.size(), 2);
  t.addSample(3);
  EXPECT_EQ(t.size(), 3);
  size_t count = 0;
  for (const auto e : t) {
    EXPECT_EQ(e, 5 - count);
    count++;
  }
  t.addSample(2);
  EXPECT_EQ(t.size(), 3);
  count = 0;
  for (const auto e : t) {
    EXPECT_EQ(e, 4 - count);
    count++;
  }
}

TEST(MetricSeriesTest, testRate) {
  MetricSeries<int> t(3, "test_metric", "this is a test metric in unittest");
  t.addSample(0);
  t.addSample(5);
  t.addSample(12);
  EXPECT_EQ(
      t.rate<int>(
          std::chrono::seconds(1), std::chrono::seconds(2), t.begin(), t.end()),
      6);
  EXPECT_EQ(t.rate<int>(std::chrono::seconds(1), std::chrono::seconds(2)), 6);
  EXPECT_EQ(
      t.rate<int>(std::chrono::seconds(1), std::chrono::seconds(2), t.begin()),
      6);

  EXPECT_EQ(
      t.rate<int>(
          std::chrono::minutes(1),
          std::chrono::seconds(2),
          t.begin(),
          t.end() - 1),
      150);

  // get float result instead of int
  EXPECT_NEAR(
      t.rate<float>(
          std::chrono::seconds(1),
          std::chrono::seconds(2),
          t.begin(),
          t.end() - 1),
      5.0 / 2.0,
      1e-3);
}

TEST(MetricSeriesTest, testAvg) {
  MetricSeries<int> t(3, "test_metric", "this is a test metric in unittest");
  t.addSample(0);
  t.addSample(12);
  t.addSample(8);
  EXPECT_EQ(t.avg<int>(t.begin(), t.end() - 1), 6);
  EXPECT_EQ(t.avg<int>(t.begin(), t.end()), 6);
  EXPECT_EQ(t.avg<int>(t.begin()), 6);
  EXPECT_EQ(t.avg<int>(), 6);
  // get float
  EXPECT_NEAR(t.avg<float>(), 20.0 / 3, 1e-3);
}

TEST(MetricSeriesTest, testPercentile) {
  MetricSeries<int> t(101, "test_metric", "this is a test metric in unittest");
  std::vector<int> candidates(101);
  for (int i = 0; i <= 100; i++) {
    candidates[i] = i;
  }
  for (int i = 0; i <= 100; i++) {
    auto idx = std::rand() % (101 - i);
    t.addSample(candidates[idx]);
    std::swap(candidates[100 - i], candidates[idx]);
  }

  EXPECT_EQ(t.percentile(0.57, t.begin(), t.end()), 57);
  EXPECT_EQ(t.percentile(0.0, t.begin(), t.end()), 0);
  EXPECT_EQ(t.percentile(1.0, t.begin(), t.end()), 100);
  EXPECT_EQ(t.percentile(0.124, t.begin(), t.end()), 12);
  EXPECT_EQ(t.percentile(0.125, t.begin(), t.end()), 13);
}

TEST(MetricSeriesTest, testDiff) {
  MetricSeries<int> t(3, "test_metric", "this is a test metric in unittest");
  t.addSample(0);
  t.addSample(12);
  t.addSample(8);

  EXPECT_EQ(t.diff(), 8);
  EXPECT_EQ(t.diff(t.begin(), t.end() - 1), 12);
  EXPECT_EQ(t.diff(t.begin() + 1, t.end()), -4);
}
