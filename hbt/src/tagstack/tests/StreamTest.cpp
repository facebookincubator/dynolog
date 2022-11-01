// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/tagstack/Stream.h"
#include "hbt/src/perf_event/PerCpuDummyGenerator.h"
#include "hbt/src/tagstack/PerfEventStream.h"

#include <gtest/gtest.h>

using namespace facebook::hbt;
using namespace facebook::hbt::ringbuffer;
using namespace facebook::hbt::tagstack;

const auto maxTimeStamp = std::numeric_limits<facebook::hbt::TimeStamp>::max();

struct MockRingBufferExtraData {};

using TRingBuffer = RingBuffer<MockRingBufferExtraData>;

using TRingBufferStream = stream::RingBufferStream<MockRingBufferExtraData>;

using TProducer = Producer<MockRingBufferExtraData>;

template <class TStream>
void expectNext(
    TStream& s,
    const Event& expected,
    TimeStamp stop_ts = kMaxTimeStamp) {
  const Event* e = s.prepareNext(stop_ts);
  EXPECT_TRUE(e != nullptr) << expected;
  EXPECT_EQ(*e, expected);
  s.complete();
}

TEST(TagStackStream, EventConsumer) {
  auto rb = std::make_shared<TRingBuffer>(sizeof(Event) * 4);
  TProducer p{rb};

  auto e1 = Event::makeSwitchIn(20, 1, 2, 0);
  auto e2 = Event::makeSwitchOutPreempt(30, 1, 0);
  auto e3 = Event::makeSwitchOutPreempt(30, 1, 0);

  ssize_t ret;
  ret = p.write(e1);
  EXPECT_GE(ret, 0);
  ret = p.write(e2);
  EXPECT_GE(ret, 0);

  TRingBufferStream c{rb};

  expectNext(c, e1);
  expectNext(c, e2);

  ret = p.write(e3);
  EXPECT_GE(ret, 0);
  expectNext(c, e3);
}

TEST(Stream, BinaryCombinator) {
  // CompUnitId should match the producer where is written.
  auto e1 = Event::makeSwitchIn(20, 0, 2, 2);
  auto e2 = Event::makeSwitchOutPreempt(21, 0, 2);
  auto e3 = Event::makeSwitchIn(24, 1, 2, 1);
  auto e4 = Event::makeSwitchOutPreempt(30, 1, 1);
  auto e5 = Event::makeSwitchIn(30, 1, 5, 2);
  auto e6 = Event::makeSwitchOutPreempt(31, 1, 1);

  auto rb1 = std::make_shared<TRingBuffer>(sizeof(Event) * 2);
  auto rb2 = std::make_shared<TRingBuffer>(sizeof(Event) * 1);

  TProducer p1{rb1};
  TProducer p2{rb2};

  ssize_t ret;

  // Start adding one element to each buffer.
  // Note that there are no consumers created yet.
  ret = p1.write(e3);
  EXPECT_GE(ret, 0);
  ret = p2.write(e1);
  EXPECT_GE(ret, 0);

  stream::BinaryCombinator<TRingBufferStream> s{
      std::make_shared<TRingBufferStream>(rb1),
      std::make_shared<TRingBufferStream>(rb2)};

  // Read the first element.
  expectNext(s, e1);

  // Combinator caches one event per stream.
  EXPECT_EQ(rb1->getHeader().usedSizeWeak(), 0);
  EXPECT_EQ(rb2->getHeader().usedSizeWeak(), 0);

  // Add more.
  ret = p1.write(e4);
  EXPECT_GE(ret, 0);
  ret = p2.write(e2);
  EXPECT_GE(ret, 0);
  EXPECT_EQ(rb1->getHeader().usedSizeWeak(), 1 * sizeof(Event));
  EXPECT_EQ(rb2->getHeader().usedSizeWeak(), 1 * sizeof(Event));

  expectNext(s, e2);

  ret = p2.write(e5);
  EXPECT_GE(ret, 0);
  EXPECT_EQ(rb1->getHeader().usedSizeWeak(), 1 * sizeof(Event));
  EXPECT_EQ(rb2->getHeader().usedSizeWeak(), 1 * sizeof(Event));

  // Consume both events.
  expectNext(s, e3);
  expectNext(s, e4);

  EXPECT_EQ(rb1->getHeader().usedSizeWeak(), 0);
  EXPECT_EQ(rb2->getHeader().usedSizeWeak(), 0);

  ret = p1.write(e6);
  EXPECT_GE(ret, 0);

  EXPECT_EQ(rb1->getHeader().usedSizeWeak(), 1 * sizeof(Event));
  EXPECT_EQ(rb2->getHeader().usedSizeWeak(), 0);

  expectNext(s, e5);
  expectNext(s, e6);

  // Both buffers should be empty by now.
  EXPECT_EQ(rb1->getHeader().usedSizeWeak(), 0);
  EXPECT_EQ(rb2->getHeader().usedSizeWeak(), 0);

  EXPECT_EQ(s.prepareNext(kMaxTimeStamp), nullptr);
}

TEST(Stream, BinaryCombinatorStop) {
  // Fit 3 events.
  auto rb0 = std::make_shared<TRingBuffer>(sizeof(Event) * 3);
  TProducer p0(rb0);

  // Fit 3 events.
  auto rb1 = std::make_shared<TRingBuffer>(sizeof(Event) * 3);
  TProducer p1(rb1);

  const Tag t = 100;

  // Events that wil be written in p0 get CompUnitId 0
  // Events that wil be written in p1 get CompUnitId 1
  auto ev0 = Event::makeSwitchOutPreempt(0, 0, 0);
  auto ev1 = Event::makeSwitchIn(0, 0, t, 0);
  auto ev2 = Event::makeSwitchOutPreempt(0, 0, 0);

  auto ev3 = Event::makeSwitchIn(1, 0, t, 1);
  auto ev4 = Event::makeSwitchOutPreempt(30, 0, 1);
  auto ev5 = Event::makeSwitchIn(30, 0, t, 0);
  auto ev6 = Event::makeSwitchOutPreempt(35, 0, 0);

  {
    ssize_t ret = p0.write(ev0);
    EXPECT_GE(ret, 0);
  }
  {
    ssize_t ret = p0.write(ev1);
    EXPECT_GE(ret, 0);
  }
  {
    ssize_t ret = p0.write(ev2);
    EXPECT_GE(ret, 0);
  }
  {
    ssize_t ret = p1.write(ev3);
    EXPECT_GE(ret, 0);
  }
  {
    ssize_t ret = p1.write(ev4);
    EXPECT_GE(ret, 0);
  }
  {
    ssize_t ret = p0.write(ev5);
    EXPECT_GE(ret, 0);
  }
  {
    // ev6 does not fit.
    ssize_t ret = p0.write(ev6);
    EXPECT_EQ(ret, -ENOSPC) << toErrorCode(-ret);
  }

  EXPECT_EQ(rb0->getHeader().usedSizeWeak(), sizeof(Event) * 4);
  EXPECT_EQ(rb1->getHeader().usedSizeWeak(), sizeof(Event) * 2);

  auto combinator =
      std::make_shared<stream::BinaryCombinator<TRingBufferStream>>(
          std::make_unique<TRingBufferStream>(rb0),
          std::make_unique<TRingBufferStream>(rb1));

  expectNext(*combinator, ev0, 1);
  expectNext(*combinator, ev1, 1);
  expectNext(*combinator, ev2, 1);
  expectNext(*combinator, ev3, 1);

  // Cannot get next event because stop_ts is 1
  EXPECT_EQ(combinator->prepareNext(1), nullptr);

  // Because stream_id is part of the total order of events. ev5 in stream 0
  // comes before ev4 in stream 1.
  expectNext(*combinator, ev5, 30);

  EXPECT_EQ(rb0->getHeader().usedSizeWeak(), 0);
  EXPECT_EQ(rb1->getHeader().usedSizeWeak(), 0);

  expectNext(*combinator, ev4, 30);

  // write <ev6>.
  {
    ssize_t ret = p0.write(ev6);
    EXPECT_GE(ret, 0);
  }

  // Cannot get next event because stop_ts is 1
  EXPECT_EQ(combinator->prepareNext(34), nullptr);

  // Get ev6 because no other event is coming from p1.
  expectNext(*combinator, ev6, 35);
}

TEST(Stream, PerfEventStream) {
  auto rb = std::make_shared<TRingBuffer>(10);
  auto gen = std::make_shared<perf_event::CpuDummyGenerator>(0);
  auto s = stream::PerfEventStream(rb, gen);
  gen->open();
  auto ev = s.prepareNext(10);
  // Buffer is empty.
  EXPECT_EQ(ev, nullptr);
}
