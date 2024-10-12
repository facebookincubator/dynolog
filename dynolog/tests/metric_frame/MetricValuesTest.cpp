// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>

#include "dynolog/src/metric_frame/MetricValues.h"

#include <optional>

using namespace ::testing;
using namespace ::facebook::dynolog;

TEST(MetricValuesTest, basicTest) {
  MetricValues<int> v(5);
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v[3], 0);

  MetricValues<float> v1({0.1, 0.2, 0.3});
  EXPECT_EQ(v1.size(), 3);

  EXPECT_FLOAT_EQ(v1[0], 0.1);
  EXPECT_FLOAT_EQ(v1[1], 0.2);

  v1.resize(5);
  EXPECT_EQ(v1.size(), 5);

  v1.push_back(42);
  EXPECT_EQ(v1.size(), 6);
}

TEST(MetricValuesTest, aggTest) {
  MetricValues<uint32_t> v;

  // empty lists will fail in some aggregations
  EXPECT_FALSE(v.avg());
  EXPECT_FALSE(v.minmax());
  EXPECT_FALSE(v.percentile(0.5));
  EXPECT_EQ(v.sum(), 0);

  for (int i = 0; i < 5; i++) {
    v.push_back(i);
  }

  EXPECT_EQ(v.sum(), 10);

  auto minmaxMaybe = v.minmax();
  EXPECT_TRUE(minmaxMaybe);
  EXPECT_EQ(minmaxMaybe.value().first, 0);
  EXPECT_EQ(minmaxMaybe.value().second, 4);

  auto avgMaybe = v.avg();
  EXPECT_TRUE(avgMaybe);
  EXPECT_EQ(avgMaybe.value(), 2.0);

  auto p50Maybe = v.percentile(0.5);
  EXPECT_TRUE(p50Maybe);
  EXPECT_EQ(p50Maybe.value(), 2.0);
}

TEST(MetricValuesTest, mergeTest) {
  MetricValues<uint32_t> u, v;
  for (int i = 0; i < 5; i++) {
    u.push_back(i);
  }
  for (int i = 0; i < 5; i++) {
    v.push_back(i);
  }
  EXPECT_EQ(u.size(), 5);

  u.merge(v);
  EXPECT_EQ(u.size(), 10);
  EXPECT_EQ(u.sum(), 20);

  auto avgMaybe = u.avg();
  EXPECT_TRUE(avgMaybe);
  EXPECT_EQ(avgMaybe.value(), 2.0);
}
