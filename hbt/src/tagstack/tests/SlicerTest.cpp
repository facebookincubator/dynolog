// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/tagstack/Slicer.h"
#include "hbt/src/ringbuffer/RingBuffer.h"
#include "hbt/src/tagstack/Stream.h"

#include <gtest/gtest.h>

using namespace facebook::hbt;
using namespace facebook::hbt::ringbuffer;
using namespace facebook::hbt::tagstack;
using namespace facebook::hbt::tagstack::slice;

template <class TProd>
void expectWriteNext(TProd& p, const Event& e) {
  auto ret = p.write(e);
  EXPECT_GE(ret, 0) << "Failed to write event: " << e
                    << " with error: " << toErrorCode(-ret);
}

struct MockRingBufferExtraData {};

using TRingBuffer = RingBuffer<MockRingBufferExtraData>;
using TRingBufferStream = stream::RingBufferStream<MockRingBufferExtraData>;
using TProducer = Producer<MockRingBufferExtraData>;

template <class TSliceProducer>
using TSlicer = Slicer<TRingBufferStream, TSliceProducer>;

using TGroupedSlices = GroupedSlices<SlicesMap>;

template <class TStackStates>
void expectExistsEqual(
    const TStackStates& stack_states,
    const Stack& exp_stack,
    TagStackId stack_id) {
  auto it = stack_states.find(exp_stack);
  HBT_LOG_INFO() << "Stack states:";
  for (const auto& p : stack_states) {
    HBT_LOG_INFO() << "stack: " << p.first;
  }
  EXPECT_TRUE(it != stack_states.end())
      << " stack not found. Expected: " << exp_stack;
  EXPECT_EQ(it->first, exp_stack);
  EXPECT_EQ(it->second.stats.stack, exp_stack);
  EXPECT_EQ(it->second.stats.stack_id, stack_id) << "stack: " << exp_stack;
};

TEST(SliceMapTest, Lifetime) {
  SlicesMap m;
  m.write(Slice::makeSlice(
      100,
      10000,
      1,
      Slice::TransitionType::Analysis,
      Slice::TransitionType::PhaseChange));
}

TEST(TagStackSlice, 1LevelsOnePhaseWithThreadSwOut) {
  // Create one ring buffer and populate with events.
  auto events_rb = std::make_shared<TRingBuffer>(sizeof(Event) * 16);

  // Start with active stack [].
  TProducer event_p(events_rb);
  // Now active stack is [ 2 ].
  expectWriteNext(event_p, Event::makeSwitchIn(20, 0, 2, 0));
  // Now active stack is [ <Anon> ].
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(30, 0, 0));
  // Now active stack is [ 4 ].
  expectWriteNext(event_p, Event::makeSwitchIn(30, 0, 4, 0));
  // Now active stack is [ <Anon> ].
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(50, 0, 0));
  // Now active stack is [ 1 ].
  expectWriteNext(event_p, Event::makeSwitchIn(60, 0, 1, 0));
  // Now active stack is [ <Anon> ].
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(80, 0, 0));

  auto grouped_slices = std::make_shared<TGroupedSlices>();
  auto slices = std::make_shared<SlicesMap>();
  grouped_slices->push_back(slices);
  TSlicer<SlicesMap> slicer{
      std::make_shared<TRingBufferStream>(events_rb), grouped_slices};

  auto num_processed = slicer.processNext(2, 5);
  EXPECT_EQ(num_processed, 0);
  num_processed = slicer.processNext(2, 29);
  EXPECT_EQ(num_processed, 1);
  num_processed = slicer.processNext(10, 90);
  EXPECT_EQ(num_processed, 5);

  // Check that slices formed TagStacks in the expected order.
  const auto& stack_states = slicer.getTagStackStates();
  EXPECT_EQ(stack_states.size(), 5);

  EXPECT_EQ(stack_states.size(), 5);

  // This stack is created by the recursive creation of parents.
  expectExistsEqual(stack_states, Stack(0, false), 0);

  expectExistsEqual(stack_states, Stack({2}, 1, false), 1);
  expectExistsEqual(stack_states, Stack(0, true), 2);
  expectExistsEqual(stack_states, Stack({4}, 1, false), 3);
  // The Anon after the [ 4 ] TagStack uses the already created stack at
  // index 1.
  expectExistsEqual(stack_states, Stack({1}, 1, false), 4);

  EXPECT_EQ(slices->size(), 4);
  // Starts at 20 time units, stack [ 2 ].
  Slice exp_s1{
      .tstamp = 20,
      .duration = 10,
      .stack_id = 1,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  // Starts at 30 time units, stack [ 4 ].
  Slice exp_s2{
      .tstamp = 30,
      .duration = 20,
      .stack_id = 3,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  // Starts at 50 time units, stack [ <Anon> ]
  Slice exp_s3{
      .tstamp = 50,
      .duration = 10,
      .stack_id = 2,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  // Starts at 60 time units. Stack [ <Anon> ] switches out and {1} resumes.
  Slice exp_s4{
      .tstamp = 60,
      .duration = 20,
      .stack_id = 4,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  EXPECT_EQ(slices->at(20), exp_s1);
  EXPECT_EQ(slices->at(30), exp_s2);
  EXPECT_EQ(slices->at(50), exp_s3);
  EXPECT_EQ(slices->at(60), exp_s4);
}

TEST(TagStackSlice, 2LevelsOnePhaseWithThreadSwOutAndStartOneLevelAbove) {
  // Create one ring buffer and populate with events.
  auto events_rb = std::make_shared<TRingBuffer>(sizeof(Event) * 4);
  TProducer event_p(events_rb);
  expectWriteNext(event_p, Event::makeSwitchIn(20, 1, 2, 0));
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(30, 1, 0));
  expectWriteNext(event_p, Event::makeSwitchIn(31, 1, 2, 0));
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(32, 1, 0));

  // Create slicer and process events.
  auto grouped_slices = std::make_shared<TGroupedSlices>();
  auto slices = std::make_shared<SlicesMap>();
  grouped_slices->push_back(slices);
  TSlicer<SlicesMap> slicer{
      std::make_shared<TRingBufferStream>(events_rb), grouped_slices};
  {
    auto num_processed = slicer.processNext(3, 30);
    EXPECT_EQ(num_processed, 2);
  }
  {
    auto num_processed = slicer.processNext(2, 50);
    EXPECT_EQ(num_processed, 2);
  }
  // Check that slices formed TagStacks in the expected order.
  const auto& stack_states = slicer.getTagStackStates();
  EXPECT_EQ(stack_states.size(), 6);
  for (const auto& [k, ss] : stack_states) {
    HBT_LOG_INFO() << ss.stats;
  }
  expectExistsEqual(stack_states, Stack(0, false), 0);
  expectExistsEqual(stack_states, Stack({kNA}, 1, false), 1);
  expectExistsEqual(stack_states, Stack({kNA, 2}, 2, false), 2);
  expectExistsEqual(stack_states, Stack({kNA}, 0, true), 3);
  expectExistsEqual(stack_states, Stack({kNA}, 1, true), 4);
  expectExistsEqual(stack_states, Stack({kNA, 2}, 2, true), 5);

  EXPECT_EQ(slices->size(), 3);
  Slice exp_s1{
      .tstamp = 20,
      .duration = 10,
      .stack_id = 2,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  Slice exp_s2{
      .tstamp = 30,
      .duration = 1,
      .stack_id = 4,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  Slice exp_s3{
      .tstamp = 31,
      .duration = 1,
      .stack_id = 5,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  EXPECT_EQ(slices->at(exp_s1.tstamp), exp_s1);
  EXPECT_EQ(slices->at(exp_s2.tstamp), exp_s2);
  EXPECT_EQ(slices->at(exp_s3.tstamp), exp_s3);
}

TEST(TagStackSlice, 2LevelsOnePhaseWithThreadSwOutLong) {
  /*
   * Two TagStack levels: 0: Thread ID, 1: Program Phase.
   */

  auto events_rb = std::make_shared<TRingBuffer>(sizeof(Event) * 40);

  TProducer event_p(events_rb);

  // Switch in thread 0.
  expectWriteNext(event_p, Event::makeSwitchIn(100, 0, 0, 0));
  // Swich out thread 0.
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(130, 0, 0));
  // Switch in thread 1.
  expectWriteNext(event_p, Event::makeSwitchIn(131, 0, 1, 0));
  // Switch in phase 10, it will be placed on top of thread 1.
  expectWriteNext(event_p, Event::makeStart(140, 1, 10, 0));
  // Switch out thread 1.
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(160, 0, 0));

  auto grouped_slices = std::make_shared<TGroupedSlices>();
  auto slices = std::make_shared<SlicesMap>();
  grouped_slices->push_back(slices);
  TSlicer<SlicesMap> slicer{
      std::make_shared<TRingBufferStream>(events_rb), grouped_slices};

  {
    auto num_processed = slicer.processNext(200, kMaxTimeStamp);
    // There are only 5.
    EXPECT_EQ(num_processed, 5);
  }

  // Check that slices formed TagStacks in the expected order.
  const auto& stack_states = slicer.getTagStackStates();
  EXPECT_EQ(stack_states.size(), 6);
  // Created as parent.
  expectExistsEqual(stack_states, Stack(0, false), 0);
  expectExistsEqual(stack_states, Stack({0}, 1, false), 1);
  expectExistsEqual(stack_states, Stack(0, true), 2);
  expectExistsEqual(stack_states, Stack({1}, 1, false), 3);
  // Created as parent.
  expectExistsEqual(stack_states, Stack({1}, 1, true), 4);
  expectExistsEqual(stack_states, Stack({1, 10}, 2, true), 5);

  EXPECT_EQ(slices->size(), 4);
  Slice exp_s1{
      .tstamp = 100,
      .duration = 30,
      .stack_id = 1,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  Slice exp_s2{
      .tstamp = 130,
      .duration = 1,
      .stack_id = 2,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  Slice exp_s3{
      .tstamp = 131,
      .duration = 9,
      .stack_id = 3,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::PhaseChange};

  Slice exp_s4{
      .tstamp = 140,
      .duration = 20,
      .stack_id = 5,
      .swin_type = Slice::TransitionType::PhaseChange,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  EXPECT_EQ(slices->at(100), exp_s1);
  EXPECT_EQ(slices->at(130), exp_s2);
  EXPECT_EQ(slices->at(131), exp_s3);
  EXPECT_EQ(slices->at(140), exp_s4);

  // Switch in thread 1, comes with phase 10.
  expectWriteNext(event_p, Event::makeSwitchIn(170, 0, 1, 0));
  // Switch out thread 1.
  expectWriteNext(event_p, Event::makeSwitchOutYield(190, 0, 0));
  {
    slices->clear();
    auto num_processed = slicer.processNext(200, kMaxTimeStamp);
    // There are only 2.
    EXPECT_EQ(num_processed, 2);
  }

  // No new slices have been formed.
  EXPECT_EQ(stack_states.size(), 6);

  Slice exp_s5{
      .tstamp = 160,
      .duration = 10,
      .stack_id = 2,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  Slice exp_s6{
      .tstamp = 170,
      .duration = 20,
      .stack_id = 5,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadYield};

  EXPECT_EQ(slices->at(160), exp_s5);
  EXPECT_EQ(slices->at(170), exp_s6);
}

TEST(TagStackSlice, 3LevelsMultiplePhasesNoNesting) {
  // Fit 12 events.
  auto events_rb = std::make_shared<TRingBuffer>(sizeof(Event) * 12);

  TProducer event_p(events_rb);

  Tag t = 100;
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(0, 0, 0));
  expectWriteNext(event_p, Event::makeSwitchIn(0, 0, t, 0));
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(0, 0, 0));
  expectWriteNext(event_p, Event::makeSwitchIn(1, 0, t, 0));
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(30, 0, 0));
  expectWriteNext(event_p, Event::makeSwitchIn(30, 0, t, 0));
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(35, 0, 0));
  expectWriteNext(event_p, Event::makeSwitchIn(36, 0, t, 0));
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(40, 0, 0));
  expectWriteNext(event_p, Event::makeSwitchIn(42, 0, t, 0));
  expectWriteNext(event_p, Event::makeSwitchOutPreempt(42, 0, 0));
  expectWriteNext(event_p, Event::makeSwitchIn(50, 0, t, 0));

  auto grouped_slices = std::make_shared<TGroupedSlices>();
  auto slices = std::make_shared<SlicesMap>();
  grouped_slices->push_back(slices);
  TSlicer<SlicesMap> slicer{
      std::make_shared<TRingBufferStream>(events_rb), grouped_slices};

  // Process events until 30 tstamp (inclusive).
  {
    EXPECT_EQ(events_rb->getHeader().usedSizeWeak(), sizeof(Event) * 12);
    auto num_processed = slicer.processNext(100, 30);
    EXPECT_EQ(num_processed, 6);
    EXPECT_EQ(events_rb->getHeader().usedSizeWeak(), sizeof(Event) * 6);
  }
  // Process the rest.
  {
    auto num_processed = slicer.processNext(100, 100);
    // There are only 6.
    EXPECT_EQ(num_processed, 6);
    EXPECT_EQ(events_rb->getHeader().usedSizeWeak(), 0);
  }

  // Check that slices formed TagStacks in the expected order.
  const auto& stack_states = slicer.getTagStackStates();
  EXPECT_EQ(stack_states.size(), 3);
  // Created by recursive creation of parent
  expectExistsEqual(stack_states, Stack(0, false), 1);

  expectExistsEqual(stack_states, Stack(0, true), 0);
  expectExistsEqual(stack_states, Stack({100}, 1, false), 2);

  EXPECT_EQ(slices->size(), 7);
  Slice exp_s1{
      .tstamp = 0,
      .duration = 1,
      .stack_id = 0,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  Slice exp_s2{
      .tstamp = 1,
      .duration = 29,
      .stack_id = 2,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  Slice exp_s3{
      .tstamp = 30,
      .duration = 5,
      .stack_id = 2,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  Slice exp_s4{
      .tstamp = 35,
      .duration = 1,
      .stack_id = 0,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  Slice exp_s5{
      .tstamp = 36,
      .duration = 4,
      .stack_id = 2,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  Slice exp_s6{
      .tstamp = 40,
      .duration = 2,
      .stack_id = 0,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  Slice exp_s7{
      .tstamp = 42,
      .duration = 8,
      .stack_id = 0,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  EXPECT_EQ(slices->at(0), exp_s1);
  EXPECT_EQ(slices->at(1), exp_s2);
  EXPECT_EQ(slices->at(30), exp_s3);
  EXPECT_EQ(slices->at(35), exp_s4);
  EXPECT_EQ(slices->at(36), exp_s5);
  EXPECT_EQ(slices->at(40), exp_s6);
  EXPECT_EQ(slices->at(42), exp_s7);
}

TEST(TagStackSlice, 3LevelsMultiplePhasesTwoStreams) {
  // Fit 5 events.
  auto rb0 = std::make_shared<TRingBuffer>(sizeof(Event) * 5);
  TProducer p0(rb0);

  // Fit 4 events.
  auto rb1 = std::make_shared<TRingBuffer>(sizeof(Event) * 4);
  TProducer p1(rb1);

  // Add 6 events, some of them have the same timestamp
  // and will form slices of duration 0 that will be discaraded.
  Tag t = 100;
  expectWriteNext(p0, Event::makeSwitchOutPreempt(0, 0, 0));
  expectWriteNext(p0, Event::makeSwitchIn(0, 0, t, 0));
  expectWriteNext(p0, Event::makeSwitchOutPreempt(0, 0, 0));
  expectWriteNext(p1, Event::makeSwitchIn(1, 0, t, 1));
  expectWriteNext(p1, Event::makeSwitchOutPreempt(30, 0, 1));
  expectWriteNext(p0, Event::makeSwitchIn(31, 0, t, 0));

  // Setup Combinator to combine two Event streams.
  auto combinator =
      std::make_shared<stream::BinaryCombinator<TRingBufferStream>>(
          std::make_unique<TRingBufferStream>(rb0),
          std::make_unique<TRingBufferStream>(rb1));

  // build one <SlicesMap> for each of the 2 streams.
  auto slices = std::make_shared<GroupedSlices<SlicesMap>>(2);
  (*slices)[0] = std::make_shared<SlicesMap>();
  (*slices)[1] = std::make_shared<SlicesMap>();

  Slicer<std::decay_t<decltype(*combinator)>, SlicesMap> slicer{
      combinator, slices};

  // Process events until 30 tstamp (inclusive) and succeed.
  {
    EXPECT_EQ(rb0->getHeader().usedSizeWeak(), sizeof(Event) * 4);
    EXPECT_EQ(rb1->getHeader().usedSizeWeak(), sizeof(Event) * 2);
    auto num_processed = slicer.processNext(100, 30);
    EXPECT_EQ(num_processed, 5);
    EXPECT_EQ(rb0->getHeader().usedSizeWeak(), sizeof(Event) * 1);
    EXPECT_EQ(rb1->getHeader().usedSizeWeak(), sizeof(Event) * 0);
    EXPECT_EQ(slicer.getLastTimeStamp(), 30);
  }

  {
    // Check that slices formed TagStacks in the expected order.
    const auto& stack_states = slicer.getTagStackStates();
    EXPECT_EQ(stack_states.size(), 3);
    expectExistsEqual(stack_states, Stack(0, true), 0);
    // Created by recursive creation of parents.
    expectExistsEqual(stack_states, Stack(0, false), 1);
    expectExistsEqual(stack_states, Stack({100}, 1, false), 2);
  }

  // Add an extra event. This new event will allow Combinator to move
  // pass the last event at tstamp 30 because now there is an event after.
  expectWriteNext(p0, Event::makeSwitchOutPreempt(35, 0, 0));

  // Process next event with tstamp 30.
  {
    EXPECT_EQ(rb0->getHeader().usedSizeWeak(), sizeof(Event) * 2);
    EXPECT_EQ(rb1->getHeader().usedSizeWeak(), sizeof(Event) * 0);
    auto num_processed = slicer.processNext(100, 31);
    // One event until timestamp 31.
    EXPECT_EQ(num_processed, 1);
    EXPECT_EQ(slicer.getLastTimeStamp(), 31);
    EXPECT_EQ(rb0->getHeader().usedSizeWeak(), sizeof(Event) * 1);
    EXPECT_EQ(rb1->getHeader().usedSizeWeak(), sizeof(Event) * 0);

    // Check that slices formed TagStacks in the expected order.
    const auto& stack_states = slicer.getTagStackStates();
    EXPECT_EQ(stack_states.size(), 3);
    expectExistsEqual(stack_states, Stack(0, true), 0);
    expectExistsEqual(stack_states, Stack(0, false), 1);
    expectExistsEqual(stack_states, Stack({100}, 1, false), 2);
  }

  Slice exp_s1_0{
      .tstamp = 1,
      .duration = 29,
      .stack_id = 2,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  HBT_LOG_INFO() << "about to check expect";

  {
    EXPECT_EQ(slices->size(), 2);
    auto& slices0 = slices->at(0);
    auto& slices1 = slices->at(1);
    EXPECT_EQ(slices0->size(), 1);
    EXPECT_EQ(slices1->size(), 1);

    EXPECT_EQ(slices1->at(exp_s1_0.tstamp), exp_s1_0);
  }

  // Add 5 more events for a total of 6. No new TagStack is created.
  expectWriteNext(p1, Event::makeSwitchIn(36, 0, t, 1));
  expectWriteNext(p1, Event::makeSwitchOutPreempt(40, 0, 1));
  expectWriteNext(p0, Event::makeSwitchIn(42, 0, t, 0));
  expectWriteNext(p0, Event::makeSwitchOutPreempt(42, 0, 0));
  expectWriteNext(p1, Event::makeSwitchIn(50, 0, t, 1));

  // Process the rest.
  {
    auto num_processed = slicer.processNext(100, 100);
    // Consumed the 8 events are is empty now.
    EXPECT_EQ(num_processed, 6);
    EXPECT_EQ(rb0->getHeader().usedSizeWeak(), 0);
    EXPECT_EQ(rb1->getHeader().usedSizeWeak(), 0);
    EXPECT_EQ(slicer.getLastTimeStamp(), 50);

    // Check that slices formed TagStacks in the expected order.
    const auto& stack_states = slicer.getTagStackStates();
    for (const auto& [key, ss] : stack_states) {
      HBT_LOG_INFO() << ss.stats.stack;
    }
    EXPECT_EQ(stack_states.size(), 3);
    expectExistsEqual(stack_states, Stack(0, true), 0);
    // Created as parent.
    expectExistsEqual(stack_states, Stack(0, false), 1);
    expectExistsEqual(stack_states, Stack({100}, 1, false), 2);
  }

  Slice exp_s0_0{
      .tstamp = 0,
      .duration = 31,
      .stack_id = 0,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  Slice exp_s0_1{
      .tstamp = 31,
      .duration = 4,
      .stack_id = 2,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  Slice exp_s0_2{
      .tstamp = 35,
      .duration = 7,
      .stack_id = 0,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  Slice exp_s1_1{
      .tstamp = 30,
      .duration = 6,
      .stack_id = 0,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  Slice exp_s1_2{
      .tstamp = 36,
      .duration = 4,
      .stack_id = 2,
      .swin_type = Slice::TransitionType::ThreadYield,
      .swout_type = Slice::TransitionType::ThreadPreempted};

  Slice exp_s1_3{
      .tstamp = 40,
      .duration = 10,
      .stack_id = 0,
      .swin_type = Slice::TransitionType::ThreadPreempted,
      .swout_type = Slice::TransitionType::ThreadYield};

  {
    EXPECT_EQ(slices->size(), 2);
    auto& slices0 = slices->at(0);
    auto& slices1 = slices->at(1);
    EXPECT_EQ(slices0->size(), 3);
    EXPECT_EQ(slices1->size(), 4);

    EXPECT_EQ(slices0->at(exp_s0_0.tstamp), exp_s0_0);
    EXPECT_EQ(slices0->at(exp_s0_1.tstamp), exp_s0_1);
    EXPECT_EQ(slices0->at(exp_s0_2.tstamp), exp_s0_2);

    EXPECT_EQ(slices1->at(exp_s1_0.tstamp), exp_s1_0);
    EXPECT_EQ(slices1->at(exp_s1_1.tstamp), exp_s1_1);
    EXPECT_EQ(slices1->at(exp_s1_2.tstamp), exp_s1_2);
    EXPECT_EQ(slices1->at(exp_s1_3.tstamp), exp_s1_3);
  }
}
