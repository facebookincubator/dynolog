// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/ringbuffer/RingBuffer.h"

namespace facebook::hbt::ringbuffer {

///
/// Producer of data for RingBuffer.
///
/// Provides method to write into ringbuffer.
///
template <class THeaderExtraData>
class Producer : public RingBufferWrapper<THeaderExtraData> {
 public:
  // Declare TExtraData in class namespace.
  using TExtraData = THeaderExtraData;

  // Use base class constructor.
  using RingBufferWrapper<THeaderExtraData>::RingBufferWrapper;

  Producer(const Producer&) = delete;
  Producer(Producer&&) = delete;

  //
  // Transaction based API.
  //
  // Only one writer can have an active transaction at any time.
  // *InTx* operations that fail do not cancel transaction.
  //
  bool inTx() const noexcept {
    return this->header_.in_write_tx;
  }

  /// Return -EBUSY if there is contention and -EAGAIN if
  /// a temporal error occured.
  [[nodiscard]] ssize_t startTx() {
    if (unlikely(inTx())) {
      return -EBUSY;
    }
    bool f = false;
    // Weak exchange is fine because caller must
    // handle unpredictable failures.
    if (!this->header_.in_write_tx.compare_exchange_weak(f, true)) {
      return -EAGAIN;
    }
    HBT_DCHECK_EQ(this->tx_size_, 0);
    return 0;
  }

  [[nodiscard]] ssize_t writeInTx(size_t size, const void* data) noexcept {
    if (unlikely(!inTx())) {
      return -EINVAL;
    }
    return this->copyToRingBuffer_(
        static_cast<const uint8_t*>(data), size, this->tx_size_);
  }

  template <class T>
  [[nodiscard]] ssize_t writeInTx(const T& d) noexcept {
    return writeInTx(sizeof(T), &d);
  }

  template <class TSize>
  [[nodiscard]] ssize_t writeInTxWithSize(
      TSize length,
      const void* data) noexcept {
    static_assert(std::is_integral<TSize>::value);

    if (unlikely(!inTx())) {
      return -EINVAL;
    }

    // Copy length.
    auto plen = reinterpret_cast<const uint8_t*>(&length);
    auto s = this->copyToRingBuffer_(plen, sizeof(TSize), this->tx_size_);
    if (0 > s) {
      return s;
    }

    // Copy data.
    auto ptr = static_cast<const uint8_t*>(data);
    auto sdata = this->copyToRingBuffer_(ptr, length, this->tx_size_);
    if (0 > sdata) {
      return sdata;
    }
    return s + sdata;
  }

  [[nodiscard]] ssize_t commitTx() noexcept {
    if (unlikely(!inTx())) {
      return -EINVAL;
    }
    this->header_.incHead(this->tx_size_);
    this->tx_size_ = 0;
    // <in_write_tx> flags that we are in a transaction,
    // so enforce no stores pass it.
    this->header_.in_write_tx.store(false, std::memory_order_release);
    return 0;
  }

  [[nodiscard]] ssize_t cancelTx() noexcept {
    if (unlikely(!inTx())) {
      return -EINVAL;
    }
    auto old_tx_size = static_cast<ssize_t>(this->tx_size_);
    this->tx_size_ = 0;
    // <in_write_tx> flags that we are in a transaction,
    // so enforce no stores pass it.
    this->header_.in_write_tx.store(false, std::memory_order_release);
    return old_tx_size;
  }

  // Write a chunk with a size preffix of type TSize.
  template <class TSize>
  [[nodiscard]] ssize_t writeInTxSizedChunk(const std::string& str) noexcept {
    static_assert(std::is_integral_v<TSize>);
    if (unlikely(!inTx())) {
      return -EINVAL;
    }
    if (unlikely(str.size() > std::numeric_limits<TSize>::max())) {
      return -EINVAL;
    }
    auto byte_size = static_cast<TSize>(str.size());
    return this->writeInTxWithSize(byte_size, str.data());
  }

  //
  // High-level atomic operations.
  //
  template <class T>
  [[nodiscard]] ssize_t write(const T& t) noexcept {
    static_assert(std::is_trivial<T>::value);
    static_assert(std::is_standard_layout<T>::value);
    return write(&t, sizeof(T));
  }

  [[nodiscard]] ssize_t write(const void* d, size_t size) noexcept {
    if (ssize_t ret = startTx(); 0 > ret) {
      return ret;
    }

    auto ret = this->writeInTx(size, static_cast<const uint8_t*>(d));
    if (0 > ret) {
      auto r = cancelTx();
      HBT_DCHECK_GE(r, 0);
      return ret;
    }
    ret = commitTx();
    HBT_DCHECK_EQ(ret, 0);
    return static_cast<ssize_t>(size);
  }

  // Write a chunk with a size preffix of type TSize.
  template <class TSize>
  [[nodiscard]] ssize_t writeSizedChunk(const std::string& str) noexcept {
    if (auto ret = startTx(); 0 > ret) {
      return ret;
    }
    ssize_t s;
    if (s = this->writeInTxSizedChunk<TSize>(str); 0 > s) {
      auto r = cancelTx();
      HBT_DCHECK_GE(r, 0);
      return s;
    }
    {
      auto ret = commitTx();
      HBT_DCHECK_EQ(ret, 0);
    }
    return s;
  }

  /// Drop <n> bytes from buffer. If <n> is larger than buffer content,
  /// then drop all content.
  /// Note that this is a consumer method (i.e. modifies the tail).
  [[nodiscard]] ssize_t dropN(size_t n) noexcept {
    if (n > this->header_.kDataPoolByteSize) {
      return -EINVAL;
    }

    { // Similar to Consumer's startTx.
      bool f = false;
      // Weak exchange is fine because caller must
      // handle unpredictable failures.
      if (!this->header_.in_read_tx.compare_exchange_weak(f, true)) {
        return -EAGAIN;
      }
    }
    this->header_.dropN(n);
    this->header_.in_read_tx.store(false, std::memory_order_release);
    return 0;
  }

 protected:
  // Return 0 if succeded, otherwise return negative error code.
  // If successful, increases tx_size_ by size.
  [[nodiscard]] ssize_t copyToRingBuffer_(
      const uint8_t* d,
      const size_t size,
      const size_t rb_offset) noexcept {
    HBT_THROW_IF_NULLPTR(d);

    if (unlikely(size == 0)) {
      HBT_LOG_WARNING() << "Copies of size zero are not supported. "
                        << "Is size set correctly?";
      return -EINVAL;
    }

    if (unlikely(size > this->header_.kDataPoolByteSize)) {
      HBT_LOG_WARNING() << "Asked to write " << size << " bytes in a buffer"
                        << " of size " << this->header_.kDataPoolByteSize;
      return -EINVAL;
    }

    // Single writer, safe to read head.
    uint64_t head = this->header_.readHead();
    uint64_t tail = this->header_.readTail();
    HBT_DCHECK_LE(tail, head);

    uint64_t used = head - tail;
    if (unlikely(used > this->header_.kDataPoolByteSize)) {
      HBT_LOG_ERROR()
          << "number of used bytes found to be larger than ring buffer size";
      return -EPERM;
    }

    // Check that there is enough space.
    uint64_t space = this->header_.kDataPoolByteSize - used;
    if (unlikely(rb_offset + size > space)) {
      return -ENOSPC;
    }

    uint64_t start = (rb_offset + head) & this->header_.kDataModMask;
    uint64_t end = (start + size) & this->header_.kDataModMask;

    if (likely(start < end)) {
      // d's content won't wrap around end of buffer.
      std::memcpy(&this->data_[start], d, size);
    } else {
      // d's content will wrap around end of buffer.
      size_t size0 = this->header_.kDataPoolByteSize - start;
      std::memcpy(&this->data_[start], d, size0);
      std::memcpy(&this->data_[0], static_cast<const uint8_t*>(d) + size0, end);
    }
    this->tx_size_ += size;
    return static_cast<ssize_t>(size);
  }
};

} // namespace facebook::hbt::ringbuffer
