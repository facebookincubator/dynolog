// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/ringbuffer/RingBuffer.h"
#include "hbt/src/ringbuffer/Consumer.h"
#include "hbt/src/ringbuffer/Producer.h"

#include <gtest/gtest.h>

using namespace facebook::hbt::ringbuffer;

struct TestData {
  uint16_t a;
  uint16_t b;
  uint16_t c;

  bool operator==(const TestData& other) const {
    return a == other.a && b == other.b && c == other.c;
  }
};

struct MockExtraData {
  bool canRead() const {
    return true;
  }
  bool canWrite() const {
    return true;
  }
};

using TRingBuffer = RingBuffer<MockExtraData>;
using TProducer = Producer<MockExtraData>;
using TConsumer = Consumer<MockExtraData>;

TEST(RingBuffer, WriteCopy) {
  EXPECT_EQ(sizeof(TestData), 6);

  // 16 bytes buffer. Fits two full TestData (each 6).
  size_t size = 1u << 4;

  auto rb = std::make_shared<TRingBuffer>(size);
  // Make a producer.
  TProducer p{rb};
  // Make a consumer.
  TConsumer c{rb};

  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);

  TestData d0{.a = 0xBA98, .b = 0x7654, .c = 0xA312};
  TestData d1{.a = 0xA987, .b = 0x7777, .c = 0x2812};
  TestData d2{.a = 0xFFFF, .b = 0x3333, .c = 0x1212};

  {
    ssize_t ret = p.template write<TestData>(d0);
    EXPECT_EQ(ret, sizeof(TestData));
  }
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 6);

  {
    ssize_t ret = p.template write<TestData>(d1);
    EXPECT_EQ(ret, sizeof(TestData));
  }
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 12);

  {
    ssize_t ret = p.template write<TestData>(d2);
    EXPECT_EQ(ret, -ENOSPC) << "Needs 2 more bytes to write the 6 required, "
                               "because 12 out of 16 are used.";
  }

  TestData r;

  {
    ssize_t ret = c.copy(r);
    EXPECT_EQ(ret, sizeof(r));
    EXPECT_EQ(r, d0);
  }

  {
    ssize_t ret = c.copy(r);
    EXPECT_EQ(ret, sizeof(r));
    EXPECT_EQ(r, d1);
  }
  // It should be empty by now.
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);

  {
    ssize_t ret = p.template write<TestData>(d2);
    EXPECT_EQ(ret, sizeof(TestData));
  }
  {
    ssize_t ret = c.copy(r);
    EXPECT_EQ(ret, sizeof(r));
    EXPECT_EQ(r, d2);
  }
  // It should be empty by now.
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);
}

TEST(RingBuffer, ReadWriteString) {
  // 32 bytes.
  size_t size = 1u << 5;
  EXPECT_EQ(size, 32);

  auto rb = std::make_shared<TRingBuffer>(size);
  // Make a producer.
  TProducer p{rb};
  // Make a consumer.
  TConsumer c{rb};

  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);

  size_t exp_size = 4 + sizeof(uint32_t); // 8 bytes
  {
    ssize_t ret = p.writeSizedChunk<uint32_t>("hola");
    EXPECT_EQ(ret, exp_size);
  }
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), exp_size);

  {
    ssize_t ret = p.writeSizedChunk<uint32_t>("adios");
    EXPECT_EQ(ret, 5 + sizeof(uint32_t));
  }
  exp_size += 5 + sizeof(uint32_t); // 17 bytes
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), exp_size);

  {
    ssize_t ret = p.template writeSizedChunk<uint32_t>("this will fail");
    // 14 bytes in string. Needs 14 + sizeof(uint32_t) to write, but only 15
    // left.
    EXPECT_EQ(ret, -ENOSPC) << "Needs more bytes to write the full string";
  }

  { // Read the first string out.
    auto [ret, str] = c.template readSizedChunk<uint32_t>();
    EXPECT_EQ(ret, sizeof(uint32_t) + 4);
    EXPECT_EQ(str, "hola");
  }
  exp_size -= 4 + sizeof(uint32_t); // 9 bytes
  EXPECT_EQ(exp_size, 9);
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), exp_size);

  {
    // Write one more, this one fits and will wrap around.
    ssize_t ret =
        p.writeSizedChunk<uint32_t>("  another very long"); // 19 bytes long.
    EXPECT_EQ(ret, 19 + sizeof(uint32_t));
  }
  exp_size += 19 + sizeof(uint32_t); // 32 bytes
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), exp_size);

  {
    // Read second string.
    auto [ret, str] = c.template readSizedChunk<uint32_t>();
    EXPECT_EQ(ret, sizeof(uint32_t) + 5);
    EXPECT_EQ(str, "adios");
  }
  exp_size -= 5 + sizeof(uint32_t); // 9 bytes less, 23.
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), exp_size);

  {
    // Read last string
    auto [ret, str] = c.template readSizedChunk<uint32_t>();
    EXPECT_EQ(ret, sizeof(uint32_t) + 19);
    EXPECT_EQ(str, "  another very long");
  }

  // It should be empty by now.
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);
}

TEST(RingBuffer, ReadMultipleElems) {
  // 256 bytes buffer.
  size_t size = 1u << 8u;

  auto rb = std::make_shared<TRingBuffer>(size);
  // Make a producer.
  TProducer p{rb};
  // Make a consumer.
  TConsumer c{rb};

  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);

  uint16_t n = 0xACAC; // fits 128 times

  {
    for (int i = 0; i < 128; ++i) {
      ssize_t ret = p.write(&n, sizeof(n));
      EXPECT_EQ(ret, sizeof(n));
    }

    // It must be full by now.
    EXPECT_EQ(rb->getHeader().usedSizeWeak(), 256);

    ssize_t ret = p.write(&n, sizeof(n));
    EXPECT_EQ(ret, -ENOSPC);
  }

  {
    uint8_t b = 0xEE;

    ssize_t ret = p.write(&b, sizeof(b));
    EXPECT_EQ(ret, -ENOSPC) << "Needs an extra byte";
  }

  {
    // read the three bytes at once.
    auto [ret, ptr] = c.startReadTx(sizeof(uint8_t) * 3);
    EXPECT_EQ(ret, 3);
    EXPECT_TRUE(ptr != nullptr);
    auto r = static_cast<const uint8_t*>(ptr);
    EXPECT_EQ(r[0], 0xAC);
    EXPECT_EQ(r[1], 0xAC);
    EXPECT_EQ(r[2], 0xAC);
    ret = c.commitTx();
    EXPECT_EQ(ret, 0);
  }

  {
    // read 253 bytes at once.
    auto [ret, ptr] = c.startReadTx(sizeof(uint8_t) * 253);
    EXPECT_EQ(ret, 253);
    EXPECT_TRUE(ptr != nullptr);
    auto r = static_cast<const uint8_t*>(ptr);
    for (int i = 0; i < 253; ++i) {
      EXPECT_EQ(r[i], 0xAC);
    }
    ret = c.commitTx();
    EXPECT_EQ(ret, 0);
  }

  {
    // No more elements
    auto [ret, ptr] = c.startReadTx(sizeof(uint8_t));
    EXPECT_EQ(ret, -ENODATA);
    EXPECT_TRUE(ptr == nullptr);
    EXPECT_TRUE(!c.inTx()) << "Failed transaction should've be canceled";
  }
}

TEST(RingBuffer, CopyWrapping) {
  // 8 bytes buffer.
  size_t size = 1u << 3;

  auto rb = std::make_shared<TRingBuffer>(size);
  // Make a producer.
  TProducer p{rb};
  // Make a consumer.
  TConsumer c{rb};

  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);

  uint8_t ch = 0xA7;
  uint64_t n = 0xFFFFFFFFFFFFFFFF;

  // Put one byte.
  EXPECT_EQ(rb->getHeader().readHead(), 0);
  EXPECT_EQ(rb->getHeader().readTail(), 0);
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);
  ssize_t ret = p.write(&ch, sizeof(ch));
  EXPECT_EQ(ret, sizeof(ch));
  EXPECT_EQ(rb->getHeader().readHead(), 1);
  EXPECT_EQ(rb->getHeader().readTail(), 0);
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 1);

  // Next 8 bytes won't fit.
  ret = p.write(&n, sizeof(n));
  EXPECT_EQ(ret, -ENOSPC)
      << "Needs an extra byte to write the 8 bytes element. "
         "Capacity 8, used 1.";

  // Remove the one byte in, now head is one off.
  uint8_t cr;
  uint64_t nr;

  ret = c.copy(cr);
  EXPECT_EQ(ret, sizeof(cr));
  EXPECT_EQ(cr, ch);
  EXPECT_EQ(rb->getHeader().readHead(), 1);
  EXPECT_EQ(rb->getHeader().readTail(), 1);

  // Next 8 bytes will fit, but wrap.
  ret = p.write(&n, sizeof(n));
  EXPECT_EQ(ret, sizeof(n));
  EXPECT_EQ(rb->getHeader().readHead(), 9);
  EXPECT_EQ(rb->getHeader().readTail(), 1);

  ret = c.copy(nr);
  EXPECT_EQ(ret, sizeof(nr));
  EXPECT_EQ(nr, n);
  EXPECT_EQ(rb->getHeader().readHead(), 9);
  EXPECT_EQ(rb->getHeader().readTail(), 9);
}

TEST(RingBuffer, ReadTxWrappingOneCons) {
  // 8 bytes buffer.
  size_t size = 1u << 3;

  auto rb = std::make_shared<TRingBuffer>(size);
  // Make a producer.
  TProducer p{rb};
  // Make a consumer.
  TConsumer c1{rb};

  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);

  uint8_t ch = 0xA7;
  uint64_t n = 0xFFFFFFFFFFFFFFFF;

  // Put one byte.
  {
    EXPECT_EQ(rb->getHeader().readHead(), 0);
    EXPECT_EQ(rb->getHeader().readTail(), 0);
    EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);
    ssize_t ret = p.write(&ch, sizeof(ch));
    EXPECT_EQ(ret, sizeof(ch));
    EXPECT_EQ(rb->getHeader().readHead(), 1);
    EXPECT_EQ(rb->getHeader().readTail(), 0);
    EXPECT_EQ(rb->getHeader().usedSizeWeak(), 1);
  }

  // Next 8 bytes won't fit.
  {
    ssize_t ret = p.write(&n, sizeof(n));
    EXPECT_EQ(ret, -ENOSPC)
        << "Needs an extra byte to write the 8 bytes element. "
           "Capacity 8, used 1.";
  }

  // Remove the one byte in, now head is one off.
  EXPECT_FALSE(c1.inTx());

  {
    // Start c1 read Tx
    auto [ret, ptrch] = c1.template startReadTx<uint8_t>();
    EXPECT_EQ(ret, sizeof(uint8_t));
    EXPECT_TRUE(ptrch != nullptr);
    EXPECT_EQ(*ptrch, ch);
    EXPECT_EQ(rb->getHeader().readHead(), 1);
    EXPECT_EQ(rb->getHeader().readTail(), 0);
    EXPECT_TRUE(c1.inTx());
  }

  {
    // Complete c1's Tx.
    ssize_t ret = c1.commitTx();
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(rb->getHeader().readHead(), 1);
    EXPECT_EQ(rb->getHeader().readTail(), 1);
  }
  {
    // Retrying to commit should fail.
    ssize_t ret = c1.commitTx();
    EXPECT_EQ(ret, -EINVAL);
  }

  {
    // Next 8 bytes will fit, but wrap.
    ssize_t ret = p.write(&n, sizeof(n));
    EXPECT_EQ(ret, sizeof(n));
    EXPECT_EQ(rb->getHeader().readHead(), 9);
    EXPECT_EQ(rb->getHeader().readTail(), 1);
  }

  {
    // Start c1 read Tx again.
    auto [ret, ptrn] = c1.template startReadTx<uint64_t>();
    EXPECT_EQ(ret, sizeof(uint64_t));
    EXPECT_TRUE(ptrn != nullptr);
    EXPECT_EQ((*ptrn), n);
    EXPECT_EQ(rb->getHeader().readHead(), 9);
    EXPECT_EQ(rb->getHeader().readTail(), 1);
    EXPECT_TRUE(c1.inTx());
  }

  {
    // Complete c1.
    ssize_t ret = c1.commitTx();
    EXPECT_EQ(ret, 0);
    ret = c1.commitTx();
    EXPECT_EQ(ret, -EINVAL);
  }

  {
    // Next 8 bytes will fit, but wrap.
    ssize_t ret = p.write(&n, sizeof(n));
    EXPECT_EQ(ret, sizeof(n));
    EXPECT_EQ(rb->getHeader().readHead(), 17);
    EXPECT_EQ(rb->getHeader().readTail(), 9);
  }
  {
    auto [ret, ptrn] = c1.template startReadTx<uint64_t>();
    EXPECT_EQ(ret, sizeof(uint64_t));
    EXPECT_TRUE(ptrn != nullptr);
    EXPECT_EQ((*ptrn), n);
    EXPECT_EQ(rb->getHeader().readHead(), 17);
    EXPECT_EQ(rb->getHeader().readTail(), 9);
  }

  {
    // Cancel tx, data should be readable again.
    ssize_t ret = c1.cancelTx();
    EXPECT_GE(ret, 0);
  }

  {
    // Now c1 can read.
    auto [ret, ptrnr] = c1.template startReadTx<uint64_t>();
    EXPECT_EQ(ret, sizeof(uint64_t));
    EXPECT_TRUE(ptrnr != nullptr);
    EXPECT_EQ((*ptrnr), n);
    EXPECT_EQ(rb->getHeader().readHead(), 17);
    EXPECT_EQ(rb->getHeader().readTail(), 9);
  }

  {
    // Commit succeds.
    ssize_t ret = c1.commitTx();
    EXPECT_EQ(ret, 0);
    EXPECT_FALSE(c1.inTx());
  }
}

TEST(RingBuffer, ReadTxWrapping) {
  // 8 bytes buffer.
  size_t size = 1u << 3;

  auto rb = std::make_shared<TRingBuffer>(size);
  // Make a producer.
  TProducer p{rb};
  // Make consumers.
  TConsumer c1{rb};
  TConsumer c2{rb};

  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);

  uint8_t ch = 0xA7;
  uint64_t n = 0x3333333333333333;

  // Put one byte.
  {
    EXPECT_EQ(rb->getHeader().readHead(), 0);
    EXPECT_EQ(rb->getHeader().readTail(), 0);
    EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);
    ssize_t ret = p.write(&ch, sizeof(ch));
    EXPECT_EQ(ret, sizeof(ch));
    EXPECT_EQ(rb->getHeader().readHead(), 1);
    EXPECT_EQ(rb->getHeader().readTail(), 0);
    EXPECT_EQ(rb->getHeader().usedSizeWeak(), 1);
  }

  // Next 8 bytes won't fit.
  {
    ssize_t ret = p.write(&n, sizeof(n));
    EXPECT_EQ(ret, -ENOSPC)
        << "Needs an extra byte to write the 8 bytes element. "
           "Capacity 8, used 1.";
  }

  // Remove the one byte in, now head is one off.
  EXPECT_FALSE(c1.inTx());
  EXPECT_FALSE(c2.inTx());

  {
    // Start c1 read Tx
    auto [ret, ptrch] = c1.template startReadTx<uint8_t>();
    EXPECT_EQ(ret, sizeof(uint8_t));
    EXPECT_TRUE(ptrch != nullptr);
    EXPECT_EQ(*ptrch, ch);
    EXPECT_EQ(rb->getHeader().readHead(), 1);
    EXPECT_EQ(rb->getHeader().readTail(), 0);
    EXPECT_TRUE(c1.inTx());
  }

  {
    // Complete c1's Tx.
    ssize_t ret = c1.commitTx();
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(rb->getHeader().readHead(), 1);
    EXPECT_EQ(rb->getHeader().readTail(), 1);
  }
  {
    // Retrying to commit should fail.
    ssize_t ret = c1.commitTx();
    EXPECT_EQ(ret, -EINVAL);
  }

  {
    // Next 8 bytes will fit, but wrap.
    ssize_t ret = p.write(&n, sizeof(n));
    EXPECT_EQ(ret, sizeof(n));
    EXPECT_EQ(rb->getHeader().readHead(), 9);
    EXPECT_EQ(rb->getHeader().readTail(), 1);
  }

  {
    // Start c1 read Tx again.
    auto [ret, ptrn] = c1.template startReadTx<uint64_t>();
    EXPECT_EQ(ret, sizeof(uint64_t));
    EXPECT_TRUE(ptrn != nullptr);
    EXPECT_EQ((*ptrn), n);
    EXPECT_EQ(rb->getHeader().readHead(), 9);
    EXPECT_EQ(rb->getHeader().readTail(), 1);
    EXPECT_TRUE(c1.inTx());
  }

  {
    // Try to read before c1 completing and get -EBUSY because buffer is busy.
    auto [ret, ptrn] = c2.template startReadTx<uint64_t>();
    EXPECT_EQ(ret, -EBUSY);
    EXPECT_TRUE(ptrn == nullptr);
  }

  {
    // Complete c1.
    ssize_t ret = c1.commitTx();
    EXPECT_EQ(ret, 0);
    ret = c1.commitTx();
    EXPECT_EQ(ret, -EINVAL);
  }

  {
    // Next 8 bytes will fit, but wrap.
    ssize_t ret = p.write(&n, sizeof(n));
    EXPECT_EQ(ret, sizeof(n));
    EXPECT_EQ(rb->getHeader().readHead(), 17);
    EXPECT_EQ(rb->getHeader().readTail(), 9);
  }
  {
    auto [ret, ptrn] = c2.template startReadTx<uint64_t>();
    EXPECT_EQ(ret, sizeof(uint64_t));
    EXPECT_TRUE(ptrn != nullptr);
    EXPECT_EQ((*ptrn), n);
    EXPECT_EQ(rb->getHeader().readHead(), 17);
    EXPECT_EQ(rb->getHeader().readTail(), 9);
  }

  {
    // Cancel tx, data should be readable again.
    ssize_t ret = c2.cancelTx();
    EXPECT_GE(ret, 0);
  }

  {
    // Now c1 can read.
    auto [ret, ptrnr] = c1.template startReadTx<uint64_t>();
    EXPECT_EQ(ret, sizeof(uint64_t));
    EXPECT_TRUE(ptrnr != nullptr);
    EXPECT_EQ((*ptrnr), n);
    EXPECT_EQ(rb->getHeader().readHead(), 17);
    EXPECT_EQ(rb->getHeader().readTail(), 9);
  }

  {
    // Commit succeds.
    ssize_t ret = c1.commitTx();
    EXPECT_EQ(ret, 0);
    EXPECT_FALSE(c1.inTx());
    EXPECT_FALSE(c2.inTx());
  }
}

TEST(RingBuffer, InTx) {
  // Enough to fit the bytes required to fit all writes.
  size_t size = (1 + 4) + 2 + 2 + 2;

  auto rb = std::make_shared<TRingBuffer>(size);
  // Make a producer.
  TProducer p{rb};

  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);

  {
    ssize_t ret = p.startTx();
    EXPECT_EQ(ret, 0);
  }
  {
    // 1 + 4 bytes.
    ssize_t ret = p.writeInTxWithSize<uint8_t>(4u, "hola");
    EXPECT_EQ(ret, sizeof(uint8_t) + 4);
  }
  {
    // 2 bytes.
    ssize_t ret = p.writeInTx<uint16_t>(8u);
    EXPECT_EQ(ret, sizeof(uint16_t));
  }
  {
    // 2 bytes.
    ssize_t ret = p.writeInTx<uint16_t>(9u);
    EXPECT_EQ(ret, sizeof(uint16_t));
  }
  {
    // 2 bytes.
    ssize_t ret = p.writeInTx<uint16_t>(9u);
    EXPECT_EQ(ret, sizeof(uint16_t));
  }
  {
    ssize_t ret = p.commitTx();
    EXPECT_EQ(ret, 0);
  }

  EXPECT_EQ(rb->getHeader().usedSizeWeak(), size);

  // Make a consumer.
  TConsumer c{rb};
  {
    ssize_t ret = c.startTx();
    EXPECT_EQ(ret, 0);
  }

  constexpr size_t kBytesInStrSize = sizeof(uint8_t);
  {
    ssize_t s0 = c.findInBufferInTx<false, 'h'>();
    EXPECT_EQ(s0, kBytesInStrSize + 1);
    // Read again to ensure that does not change.
    ssize_t s1 = c.findInBufferInTx<false, 'h'>();
    EXPECT_EQ(s1, kBytesInStrSize + 1);

    // Read size of written data (no wrapping yet).
    ssize_t s2 = c.findInBufferInTx<true>();
    EXPECT_EQ(s2, c.getHeader().usedSizeWeak());
  }
  {
    ssize_t s0 = c.findInBufferInTx<false, 'a'>();
    EXPECT_EQ(s0, kBytesInStrSize + 4);
    // Read again to ensure that does not change.
    ssize_t s1 = c.findInBufferInTx<false, 'a'>();
    EXPECT_EQ(s1, kBytesInStrSize + 4);
  }
  {
    // Search for a character that does not exist.
    ssize_t s = c.findInBufferInTx<false, 0x7>();
    EXPECT_EQ(s, -ENODATA);
    EXPECT_EQ(s, -ENODATA);
  }

  {
    auto [size, d_ptr] = c.readInTxWithSize<uint8_t>();
    EXPECT_EQ(size, 4u);
    EXPECT_TRUE(memcmp(d_ptr, "hola", 4u) == 0);
  }

  {
    // Verify has been consumed in transaction.
    ssize_t s = c.findInBufferInTx<false, 'h'>();
    EXPECT_EQ(s, -ENODATA);
  }

  // Cancel transaction and start over.
  ssize_t ret = c.cancelTx();
  EXPECT_GE(ret, 0);
  ret = c.startTx();
  EXPECT_EQ(ret, 0);
  {
    ssize_t s0 = c.findInBufferInTx<false, 'h'>();
    EXPECT_EQ(s0, kBytesInStrSize + 1);
    // Read again to ensure that does not change.
    ssize_t s1 = c.findInBufferInTx<false, 'h'>();
    EXPECT_EQ(s1, kBytesInStrSize + 1);
  }
  {
    ssize_t s0 = c.findInBufferInTx<false, 'a'>();
    EXPECT_EQ(s0, kBytesInStrSize + 4);
    // Read again to ensure that does not change.
    ssize_t s1 = c.findInBufferInTx<false, 'a'>();
    EXPECT_EQ(s1, kBytesInStrSize + 4);
  }
  {
    // Search for a character that does not exist.
    ssize_t s = c.findInBufferInTx<false, 0x7>();
    EXPECT_EQ(s, -ENODATA);
    EXPECT_EQ(s, -ENODATA);
  }

  {
    auto [size, d_ptr] = c.readInTxWithSize<uint8_t>();
    EXPECT_EQ(size, 4u);
    EXPECT_TRUE(memcmp(d_ptr, "hola", 4u) == 0);
  }

  {
    // Transaction has already read 'hola', so there should be no match.
    ssize_t s = c.findInBufferInTx<false, 'h'>();
    EXPECT_EQ(s, -ENODATA);
  }

  {
    auto [ret, d_ptr] = c.readInTx<uint16_t>();
    EXPECT_EQ(ret, 2);
    EXPECT_EQ(*d_ptr, 8u);
  }
  {
    auto [ret, d_ptr] = c.readInTx<uint16_t>();
    EXPECT_EQ(ret, 2);
    EXPECT_EQ(*d_ptr, 9u);
  }
  {
    auto [ret, d_ptr] = c.readInTx<uint16_t>();
    EXPECT_EQ(ret, 2);
    EXPECT_EQ(*d_ptr, 9u);
  }
  {
    auto [ret, d_ptr] = c.readInTxWithSize<uint8_t>();
    EXPECT_EQ(ret, -ENODATA);
  }

  ret = c.commitTx();
  EXPECT_EQ(ret, 0);
  EXPECT_EQ(c.getHeader().usedSizeWeak(), 0) << "There should be no data left";
  {
    // Verify has been consumed after committing transaction.
    ret = c.startTx();
    EXPECT_EQ(ret, 0);

    ssize_t s = c.findInBufferInTx<false, 'h'>();
    EXPECT_EQ(s, -ENODATA);

    ret = c.dropInTx();
    EXPECT_EQ(ret, 0);
  }
}

TEST(RingBuffer, DropN) {
  EXPECT_EQ(sizeof(TestData), 6);

  // 16 bytes buffer. Fits two full TestData (each 6).
  size_t size = 1u << 4;

  auto rb = std::make_shared<TRingBuffer>(size);
  // Make a producer.
  TProducer p{rb};
  // Make a consumer.
  TConsumer c{rb};

  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);

  TestData d0{.a = 0xBA98, .b = 0x7654, .c = 0xA312};
  TestData d1{.a = 0xA987, .b = 0x7777, .c = 0x2812};
  TestData d2{.a = 0xFFFF, .b = 0x3333, .c = 0x1212};

  {
    ssize_t ret = p.template write<TestData>(d0);
    EXPECT_EQ(ret, sizeof(TestData));
  }
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 6);

  {
    ssize_t ret = p.template write<TestData>(d1);
    EXPECT_EQ(ret, sizeof(TestData));
  }
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 12);

  {
    ssize_t ret = p.template write<TestData>(d2);
    EXPECT_EQ(ret, -ENOSPC) << "Needs 2 more bytes to write the 6 required, "
                               "because 12 out of 16 are used.";
  }

  {
    // Free the first element.
    ssize_t ret = p.dropN(sizeof(TestData));
    EXPECT_EQ(ret, 0);
  }

  {
    // Now suceeds too write.
    ssize_t ret = p.template write<TestData>(d2);
    EXPECT_EQ(ret, sizeof(TestData));
  }

  TestData r;

  {
    // Read the second element, because first one was dropped.
    ssize_t ret = c.copy(r);
    EXPECT_EQ(ret, sizeof(r));
    EXPECT_EQ(r, d1);
  }

  {
    ssize_t ret = c.copy(r);
    EXPECT_EQ(ret, sizeof(r));
    EXPECT_EQ(r, d2);
  }
  // It should be empty by now.
  EXPECT_EQ(rb->getHeader().usedSizeWeak(), 0);
}
