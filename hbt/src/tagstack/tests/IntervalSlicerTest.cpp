// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>

#include "hbt/src/tagstack/IntervalSlicer.h"

using namespace facebook::hbt::tagstack;
using namespace facebook::hbt::tagstack::slice;

TEST(IntervalSlicer, EmptySlices) {
  IntervalSlicer islicer{20, 0};
  auto [s, num_processed] =
      islicer.makeIntervalIntersectingSlices(0, 0, 100, false, false);

  EXPECT_TRUE(s == nullptr);
  EXPECT_EQ(num_processed, 0);
  EXPECT_EQ(islicer.numProcessedSlices(), 0);
  islicer.discardConsumed();
}

TEST(IntervalSlicer, SingleConsumerOneSliceNoTrim) {
  IntervalSlicer islicer{20, 0};
  auto s1 = Slice::makeSlice(
      10,
      20,
      1,
      Slice::TransitionType::Analysis,
      Slice::TransitionType::Analysis);
  ssize_t ret = islicer.write(s1);
  EXPECT_GE(ret, 0);
  auto [s, n] = islicer.makeIntervalIntersectingSlices(0, 0, 100, false, false);

  EXPECT_TRUE(s != nullptr);
  EXPECT_EQ(s->size(), 1);
  EXPECT_EQ(s->at(0), s1);
  EXPECT_EQ(islicer.numActiveSlices(), 1);
  EXPECT_EQ(n, 1);
  EXPECT_EQ(islicer.numProcessedSlices(), 0);
}

TEST(IntervalSlicer, SingleConsumerOneSliceTrim) {
  IntervalSlicer islicer{20, 0};
  auto s1 = Slice::makeSlice(
      10,
      20,
      1,
      Slice::TransitionType::Analysis,
      Slice::TransitionType::Analysis);
  ssize_t ret = islicer.write(s1);
  EXPECT_GE(ret, 0);

  auto [s, n] = islicer.makeIntervalIntersectingSlices(0, 0, 100, true, true);
  EXPECT_TRUE(s == nullptr);
  EXPECT_EQ(n, 0);
  EXPECT_EQ(islicer.numActiveSlices(), 1);
  EXPECT_EQ(islicer.numProcessedSlices(), 0);
}

TEST(IntervalSlicer, SingleConsumerOneSliceMissingStart) {
  IntervalSlicer islicer{20, 0};
  {
    // Starts after but ends exactly.
    auto s1 = Slice::makeSlice(
        10,
        90,
        1,
        Slice::TransitionType::Analysis,
        Slice::TransitionType::Analysis);
    ssize_t ret = islicer.write(s1);
    EXPECT_GE(ret, 0);
  }
  auto [s, n] = islicer.makeIntervalIntersectingSlices(0, 0, 100, true, true);
  EXPECT_TRUE(s == nullptr);
  EXPECT_EQ(n, 0);
  EXPECT_EQ(islicer.numActiveSlices(), 1);
  EXPECT_EQ(islicer.numProcessedSlices(), 0);
}

TEST(IntervalSlicer, SingleConsumerOneSliceMissingEnd) {
  IntervalSlicer islicer{20, 0};

  // Starts exactly but misses one.
  auto s1 = Slice::makeSlice(
      0,
      99,
      1,
      Slice::TransitionType::Analysis,
      Slice::TransitionType::Analysis);
  ssize_t ret = islicer.write(s1);
  EXPECT_GE(ret, 0);

  auto [s, n] = islicer.makeIntervalIntersectingSlices(0, 0, 100, true, true);
  EXPECT_TRUE(s == nullptr);
  EXPECT_EQ(n, 0);
  EXPECT_EQ(islicer.numActiveSlices(), 1);
  EXPECT_EQ(islicer.numProcessedSlices(), 0);
}

TEST(IntervalSlicer, SingleConsumerOneSliceMissingEndNoFail) {
  IntervalSlicer islicer{20, 0};

  // Starts exactly but misses one.
  auto s1 = Slice::makeSlice(
      0,
      99,
      1,
      Slice::TransitionType::Analysis,
      Slice::TransitionType::Analysis);
  ssize_t ret = islicer.write(s1);
  EXPECT_GE(ret, 0);

  auto [s, n] = islicer.makeIntervalIntersectingSlices(0, 0, 100, true, false);
  EXPECT_TRUE(s != nullptr);
  EXPECT_EQ(n, 1);
  EXPECT_EQ(islicer.numActiveSlices(), 1);
  EXPECT_EQ(islicer.numProcessedSlices(), 0);
  EXPECT_EQ(s->at(0), s1);
}

TEST(IntervalSlicer, SingleConsumerMultiple) {
  IntervalSlicer islicer{20, 0};

  // Insert slice in [0, 99)
  auto s1 = Slice::makeSlice(
      0,
      99,
      1,
      Slice::TransitionType::Analysis,
      Slice::TransitionType::Analysis);
  ssize_t ret = islicer.write(s1);
  EXPECT_GE(ret, 0);

  {
    auto [s, n] = islicer.makeIntervalIntersectingSlices(0, 0, 100, true, true);
    EXPECT_EQ(n, 0);
    EXPECT_EQ(islicer.numProcessedSlices(), 0);
    EXPECT_TRUE(s == nullptr);
  }

  // Insert slice in [99, 101)
  auto s2 = Slice::makeSlice(
      99,
      2,
      1,
      Slice::TransitionType::Analysis,
      Slice::TransitionType::Analysis);
  ret = islicer.write(s2);
  EXPECT_GE(ret, 0);

  {
    auto [s, n] = islicer.makeIntervalIntersectingSlices(0, 0, 100, true, true);

    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(n, 1);
    EXPECT_EQ(s->size(), 2);
    EXPECT_EQ(s->at(0), s1);

    auto s2_exp = Slice::makeSlice(
        99,
        1,
        1,
        Slice::TransitionType::Analysis,
        Slice::TransitionType::Analysis);
    EXPECT_EQ(s->at(1), s2_exp);
  }

  {
    auto [s, n] = islicer.makeIntervalIntersectingSlices(1, 0, 101, true, true);
    EXPECT_TRUE(s == nullptr);
    EXPECT_EQ(n, 0);
  }

  {
    auto [s, n] =
        islicer.makeIntervalIntersectingSlices(0, 99, 101, true, true);
    EXPECT_TRUE(s == nullptr);
    EXPECT_EQ(n, 0);
  }

  {
    auto [s, n] =
        islicer.makeIntervalIntersectingSlices(0, 100, 102, true, true);
    EXPECT_TRUE(s == nullptr);
    EXPECT_EQ(n, 0);
  }

  HBT_LOG_INFO() << "About to start final query";
  auto [s, n] = islicer.makeIntervalIntersectingSlices(0, 100, 1, true, true);
  EXPECT_TRUE(s != nullptr);
  // Processed 2, event though only one is parts of the intersecting slices,
  // because first one is skipped.
  EXPECT_EQ(n, 2);
  EXPECT_EQ(s->size(), 1);

  // Insert slice in [100, 101)
  auto s3_exp = Slice::makeSlice(
      100,
      1,
      1,
      Slice::TransitionType::Analysis,
      Slice::TransitionType::Analysis);
  EXPECT_EQ(s->at(0), s3_exp);
}

TEST(IntervalSlicer, MultipleSlicerInSequence) {
  IntervalSlicer islicer{20, 0};
  islicer.registerConsumerMark("c1");
  islicer.registerConsumerMark("c2");

  // Introduce one slice that covers [0, 99) with stack_id 1.
  auto s1 = Slice::makeSlice(
      0,
      99,
      1,
      Slice::TransitionType::Analysis,
      Slice::TransitionType::Analysis);
  ssize_t ret = islicer.write(s1);
  EXPECT_GE(ret, 0);
  EXPECT_EQ(islicer.numActiveSlices(), 1);

  {
    // IntervalSlicer1 tries to get the first slice but not all range is
    // covered.
    auto s = islicer.consumeSlices("c1", 0, 100, true, true);
    EXPECT_EQ(islicer.getMark("c1"), 0);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 0);
    EXPECT_EQ(islicer.numProcessedSlices(), 0);
  }

  // Write another slice, now the interval [0, 101) is covered with stack_id 33.
  auto s2 = Slice::makeSlice(
      99,
      2,
      33,
      Slice::TransitionType::ThreadPreempted,
      Slice::TransitionType::PhaseChange);
  ret = islicer.write(s2);
  EXPECT_GE(ret, 0);
  EXPECT_EQ(islicer.numActiveSlices(), 2);

  {
    // IntervalSlicer2 successfully gets the full slice, without any trimming.
    auto s = islicer.consumeSlices("c2", 0, 99, true, true);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(islicer.getMark("c2"), 1);
    EXPECT_EQ(islicer.numProcessedSlices(), 0);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).at(0), s1);
  }

  {
    auto s2_exp = Slice::makeSlice(
        99,
        1,
        1,
        Slice::TransitionType::Analysis,
        Slice::TransitionType::Analysis);

    // IntervalSlicer1 succesfully gets the full slice without any trimming.
    // It's the last user and islicer can release the slice.
    EXPECT_EQ(islicer.numActiveSlices(), 2);
    auto s = islicer.consumeSlices("c1", 0, 99, true, true);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).at(0), s1);
    EXPECT_EQ(islicer.getMark("c1"), 1);
    EXPECT_EQ(islicer.numActiveSlices(), 1);
  }

  // Did not consume the last slice because it has one more unit of time than
  // end.
  EXPECT_EQ(islicer.getMark("c1"), 1);

  //
  // Test bunch of queries that cannot complete due to patchy slice coverage.
  //
  {
    auto s = islicer.consumeSlices("c1", 0, 101, true, true);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 0);
  }
  {
    auto s = islicer.consumeSlices("c2", 0, 101, true, true);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 0);
  }
  {
    auto s = islicer.consumeSlices("c1", 99, 101, true, true);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 0);
  }
  {
    auto s = islicer.consumeSlices("c2", 99, 101, true, true);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 0);
  }
  {
    auto s = islicer.consumeSlices("c1", 100, 102, true, true);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 0);
  }
  {
    auto s = islicer.consumeSlices("c2", 100, 102, true, true);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 0);
  }

  // Get last slice in c1.
  {
    EXPECT_EQ(islicer.numActiveSlices(), 1);
    auto s = islicer.consumeSlices("c1", 100, 1, true, true);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 1);
    EXPECT_EQ(
        s->at(0).at(0),
        Slice::makeSlice(
            100,
            1,
            33,
            Slice::TransitionType::Analysis,
            Slice::TransitionType::PhaseChange));
  }

  // Add another slice right after the last one. Now [0, 102) is covered.
  auto s3 = Slice::makeSlice(
      101,
      1,
      1,
      Slice::TransitionType::Analysis,
      Slice::TransitionType::Analysis);
  ret = islicer.write(s3);
  EXPECT_GE(ret, 0);
  EXPECT_EQ(islicer.numActiveSlices(), 2);

  {
    // Query for slices in [100, 101). This will cut the first part of the
    // second slice.
    auto s = islicer.consumeSlices("c2", 100, 1, true, true);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 1);
    EXPECT_EQ(
        s->at(0).at(0),
        Slice::makeSlice(
            100,
            1,
            33,
            Slice::TransitionType::Analysis,
            Slice::TransitionType::PhaseChange));
  }

  // Add another slice on [200, 210), so this one is not contiguous to the
  // previous ones.
  auto s4 = Slice::makeSlice(
      200,
      10,
      1,
      Slice::TransitionType::PhaseChange,
      Slice::TransitionType::PhaseChange);
  ret = islicer.write(s4);
  EXPECT_GE(ret, 0);
  EXPECT_EQ(islicer.numActiveSlices(), 2);

  {
    // Query whole interval, fail because is not fully covered.
    auto s = islicer.consumeSlices("c2", 100, 200, true, true);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 0);
  }

  {
    EXPECT_EQ(islicer.getMark("c1"), 2);
    EXPECT_EQ(islicer.getMark("c2"), 2);
    // Query again, this time allowing patchy cover.
    auto s = islicer.consumeSlices("c2", 100, 200, true, false);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 2);
    EXPECT_EQ(islicer.getMark("c2"), 4);
    EXPECT_EQ(
        s->at(0).at(0),
        Slice::makeSlice(
            101,
            1,
            1,
            Slice::TransitionType::Analysis,
            Slice::TransitionType::Analysis));
    EXPECT_EQ(s->at(0).at(1), s4);
    // islicer1 has not consumed the latest yet, so number does not decrease.
    EXPECT_EQ(islicer.numActiveSlices(), 2);
  }

  {
    EXPECT_EQ(islicer.getMark("c1"), 2);
    // Query partial region, allowing patchy cover.
    auto s = islicer.consumeSlices("c1", 100, 105, true, false);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(s->at(0).size(), 2);
    EXPECT_EQ(islicer.getMark("c1"), 3);
    EXPECT_EQ(
        s->at(0).at(0),
        Slice::makeSlice(
            101,
            1,
            1,
            Slice::TransitionType::Analysis,
            Slice::TransitionType::Analysis));
    EXPECT_EQ(
        s->at(0).at(1),
        Slice::makeSlice(
            200,
            5,
            1,
            Slice::TransitionType::PhaseChange,
            Slice::TransitionType::Analysis));

    // islicer1 fully consumed one.
    EXPECT_EQ(islicer.numActiveSlices(), 1);
  }

  EXPECT_EQ(islicer.getMark("c1"), 3);
  EXPECT_EQ(islicer.getMark("c2"), 4);

  {
    // Query for [100, 205), allowing patchy cover.
    auto s = islicer.consumeSlices("c1", 100, 105, true, false);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    // Did not fully processed the fourth slice.
    EXPECT_EQ(islicer.getMark("c1"), 3);
    EXPECT_EQ(islicer.getMark("c2"), 4);
    EXPECT_EQ(
        s->at(0).at(0),
        Slice::makeSlice(
            200,
            5,
            1,
            Slice::TransitionType::PhaseChange,
            Slice::TransitionType::Analysis));

    // islicer1 did not fully consumed slice 4.
    EXPECT_EQ(islicer.numActiveSlices(), 1);
  }

  {
    // Query partial region, allowing patchy cover.
    auto s = islicer.consumeSlices("c1", 100, 210, true, false);
    EXPECT_TRUE(s != nullptr);
    EXPECT_EQ(s->size(), 1);
    EXPECT_EQ(islicer.getMark("c2"), 4);
    // Get full slice even though the previous query got a piece of it
    // because the query acts upon unprocessed slices.
    EXPECT_EQ(
        s->at(0).at(0),
        Slice::makeSlice(
            200,
            10,
            1,
            Slice::TransitionType::PhaseChange,
            Slice::TransitionType::PhaseChange));

    // islicer1 fully consumed all.
    EXPECT_EQ(islicer.numActiveSlices(), 0);
  }

  islicer.discardConsumed();
}
