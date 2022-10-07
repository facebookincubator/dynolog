// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/ringbuffer/PerCpuRingBuffer.h"

#include <gtest/gtest.h>

using namespace facebook::hbt::ringbuffer;

struct CustomExtraData {
  int my_int = 0;
};

TEST(PerCpuRingBuffer, ReadWriteTest) {
  using TProducer = Producer<CustomExtraData>;
  using TConsumer = Consumer<CustomExtraData>;

  // Do not explicitly pass CPUs to get all online. 0, and 1 must be available.
  auto rb =
      std::make_shared<PerCpuRingBuffer<CustomExtraData>>(1024, std::nullopt);
  EXPECT_TRUE(rb->getCpuSet().hasCpu(0));
  EXPECT_TRUE(rb->getCpuSet().hasCpu(1));

  // Create producer and consumer.
  PerCpuRingBufferHelper<TProducer> p{rb};
  PerCpuRingBufferHelper<TConsumer> c{rb};

  // Check extra data is accessible.
  EXPECT_EQ(rb->getCpuRingBuffer(0)->getExtraData().my_int, 0);
  rb->getCpuRingBuffer(0)->getExtraData().my_int = 0xFFFF;
  EXPECT_EQ(rb->getCpuRingBuffer(0)->getExtraData().my_int, 0xFFFF);

  EXPECT_EQ(p.atCpu(0).getRingBuffer()->getExtraData().my_int, 0xFFFF);

  // Write at CPU 0.
  {
    auto ret = p.atCpu(0).template writeSizedChunk<uint16_t>("hola");
    EXPECT_EQ(ret, sizeof(uint16_t) + 4);
  }

  // Read in different CPU than the one written on.
  {
    auto [ret, opt_str] = c.atCpu(1).template readSizedChunk<uint16_t>();
    EXPECT_EQ(ret, -ENODATA);
    EXPECT_FALSE(opt_str.has_value());
  }

  // Read in same CPU as was written.
  {
    auto [ret, opt_str] = c.atCpu(0).template readSizedChunk<uint16_t>();
    EXPECT_EQ(ret, sizeof(uint16_t) + 4);
    EXPECT_TRUE(opt_str.has_value());
    EXPECT_EQ(*opt_str, "hola");
  }

  // Read in same CPU as was written but find no data.
  {
    auto [ret, opt_str] = c.atCpu(0).template readSizedChunk<uint16_t>();
    EXPECT_EQ(ret, -ENODATA);
    EXPECT_FALSE(opt_str.has_value());
  }
};
