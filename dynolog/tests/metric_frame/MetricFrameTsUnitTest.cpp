// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>

#include "dynolog/src/metric_frame/MetricFrameTsUnit.h"

using namespace ::testing;
using namespace ::facebook::dynolog;

using namespace std::literals;
using namespace std::literals::chrono_literals;

class MetricFrameTsUnitFixIntervalTest : public MetricFrameTsUnitFixInterval {
 public:
  MetricFrameTsUnitFixIntervalTest() : MetricFrameTsUnitFixInterval{60s, 10} {}
};

TEST(MetricFrameTsUnitTest, constructor) {
  MetricFrameTsUnitFixIntervalTest t;
}

TEST(MetricFrameTsUnitTest, smokeTest) {
  MetricFrameTsUnitFixIntervalTest t;
  MetricFrameTsUnitInterface& i = t;
  auto now = std::chrono::steady_clock::now();
  i.addSample(now - 120s);
  i.addSample(now - 60s);
  i.addSample(now);

  EXPECT_EQ(i.lastSampleTime(), now);
  EXPECT_EQ(i.firstSampleTime(), now - 120s);
  EXPECT_EQ(i.length(), 3);
  EXPECT_EQ(i.maxLength(), 10);

  auto resMaybe = i.getRange(now - 120s, now);
  EXPECT_TRUE(resMaybe.has_value());
  auto& res = resMaybe.value();
  EXPECT_EQ(res.start.offset, 0);
  EXPECT_EQ(res.start.time, now - 120s);
  EXPECT_EQ(res.end.offset, 2);
  EXPECT_EQ(res.end.time, now);
}

TEST(MetricFrameTsUnitTest, emptyFrame) {
  MetricFrameTsUnitFixIntervalTest t;
  MetricFrameTsUnitInterface& i = t;
  auto now = std::chrono::steady_clock::now();
  auto resMaybe = i.getRange(now - 120s, now);
  EXPECT_FALSE(resMaybe.has_value());
  EXPECT_FALSE(i.lastSampleTime().has_value());
  EXPECT_FALSE(i.firstSampleTime().has_value());
  EXPECT_EQ(i.length(), 0);
  EXPECT_EQ(i.maxLength(), 10);
}

TEST(MetricFrameTsUnitTest, interpolationPolicies) {
  MetricFrameTsUnitFixIntervalTest t;
  MetricFrameTsUnitInterface& i = t;
  auto now = std::chrono::steady_clock::now();
  i.addSample(now - 120s);
  i.addSample(now - 60s);
  i.addSample(now);

  /*
  ------*---120----------60---------now-----#---
        |-----------------------------------|
  */

  auto res = i.getRange(now - 144s, now + 36s).value();
  EXPECT_EQ(res.start.offset, 0);
  EXPECT_EQ(res.start.time, now - 120s);
  EXPECT_EQ(res.end.offset, 2);
  EXPECT_EQ(res.end.time, now);

  EXPECT_FALSE(i.getRange(
                    now - 144s,
                    now + 36s,
                    MATCH_POLICY::NEXT_CLOSEST,
                    MATCH_POLICY::NEXT_CLOSEST)
                   .has_value());

  EXPECT_FALSE(i.getRange(
                    now - 144s,
                    now + 36s,
                    MATCH_POLICY::PREV_CLOSEST,
                    MATCH_POLICY::PREV_CLOSEST)
                   .has_value());

  EXPECT_TRUE(i.getRange(
                   now - 144s,
                   now + 36s,
                   MATCH_POLICY::NEXT_CLOSEST,
                   MATCH_POLICY::PREV_CLOSEST)
                  .has_value());

  /*
  ----------120--*-------60-------#-now---------
                 |----------------|
  */

  res = i.getRange(now - 102s, now - 12s).value();
  EXPECT_EQ(res.start.offset, 0);
  EXPECT_EQ(res.end.offset, 2);

  res = i.getRange(now - 102s, now - 12s, MATCH_POLICY::NEXT_CLOSEST).value();
  EXPECT_EQ(res.start.offset, 1);
  EXPECT_EQ(res.end.offset, 2);

  res = i.getRange(
             now - 102s,
             now - 12s,
             MATCH_POLICY::NEXT_CLOSEST,
             MATCH_POLICY::PREV_CLOSEST)
            .value();
  EXPECT_EQ(res.start.offset, 1);
  EXPECT_EQ(res.end.offset, 1);

  /*
  ----------120-----*----60-------#-now---------
                    |-------------|
  */

  res = i.getRange(now - 89s, now - 12s).value();
  EXPECT_EQ(res.start.offset, 1);
  EXPECT_EQ(res.end.offset, 2);
}
