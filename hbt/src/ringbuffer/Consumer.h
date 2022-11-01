// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/ringbuffer/RingBuffer.h"

namespace facebook::hbt::ringbuffer {

///
/// Consumer of data for a RingBuffer.
///
/// Provides method to read data ringbuffer.
///
template <class THeaderExtraData>
class Consumer : public RingBufferWrapper<THeaderExtraData> {
 public:
  using TExtraData = THeaderExtraData;

  // Use base class constructor.
  using RingBufferWrapper<THeaderExtraData>::RingBufferWrapper;

  Consumer(const Consumer&) = delete;
  Consumer(Consumer&&) = delete;

  virtual ~Consumer() {
    if (inTx()) {
      auto r = this->cancelTx();
      HBT_DCHECK_GE(r, 0);
    }
    releaseAuxBuffer();
  }

  void releaseAuxBuffer() {
    if (aux_buffer_ == nullptr) {
      return;
    }
    free(aux_buffer_);
    aux_buffer_ = nullptr;
    aux_buffer_size_ = 0;
  }

  //
  // Transaction based API.
  // Only one writer can have an active transaction at any time.
  // *InTx* operations that fail do not cancel transaction.
  //
  bool inTx() const DEXCEPT {
    return this->header_.in_read_tx;
  }

  /// Returns -EBUSY if there is contention and -EAGAIN if
  /// a temporal error occured.
  [[nodiscard]] ssize_t startTx() DEXCEPT {
    if (unlikely(inTx())) {
      return -EBUSY;
    }
    bool f = false;
    // Weak exchange is fine because caller must
    // handle unpredictable failures.
    if (!this->header_.in_read_tx.compare_exchange_weak(f, true)) {
      return -EAGAIN;
    }
    HBT_DCHECK_EQ(this->tx_size_, 0);
    return 0;
  }

  /// Returns {size, ptr) if succeded.
  std::pair<ssize_t, const void*> readInTx(const size_t size) DEXCEPT {
    if (unlikely(!inTx())) {
      return {-EINVAL, nullptr};
    }
    if (unlikely(size > this->header_.kDataPoolByteSize)) {
      return {-EINVAL, nullptr};
    }
    auto ptr = this->read_(size);
    if (ptr == nullptr) {
      return {-ENODATA, nullptr};
    }
    return {size, ptr};
  }

  // Pointer may become invalid in next read or when transaction completes.
  template <class T>
  std::pair<ssize_t, const T*> readInTx() DEXCEPT {
    static_assert(std::is_trivial<T>::value);
    static_assert(std::is_standard_layout<T>::value);

    auto [ret, ptr] = readInTx(sizeof(T));
    return {ret, static_cast<const T*>(ptr)};
  }

  // Reads the next sizeof(TSize) in ringbuffer and use it as the size for
  // next chunk of data.
  // On success, returns <size, ptr> where size is the number of bytes in
  // next chunk and ptr is the pointer to it.
  // On failure, returns <-ERROR CODE, nullptr>.
  // Pointer may become invalid in next read or when transaction completes.
  template <class TSize>
  std::pair<ssize_t, const void*> readInTxWithSize() DEXCEPT {
    static_assert(std::is_integral<TSize>::value);
    if (unlikely(!inTx())) {
      return {-EINVAL, nullptr};
    }

    TSize length;

    auto [ret_size, length_ptr] = this->readInTx<TSize>();
    if (0 > ret_size) {
      return {ret_size, nullptr};
    }
    HBT_DCHECK_EQ(ret_size, sizeof(TSize));
    length = *length_ptr;

    auto [ret, data_ptr] = this->readInTx(length);
    if (0 > ret) {
      return {ret, nullptr};
    }
    HBT_DCHECK_EQ(ret, length);
    return {length, static_cast<const void*>(data_ptr)};
  }

  // Copy next <size> bytes to buffer.
  [[nodiscard]] ssize_t copyInTx(const size_t size, uint8_t* buffer) DEXCEPT {
    if (unlikely(!inTx())) {
      return -EINVAL;
    }
    if (size == 0) {
      return 0;
    }
    if (unlikely(size > this->header_.kDataPoolByteSize)) {
      return -EINVAL;
    }
    auto [ptr, resized] = readFromRingBuffer_<true, false>(
        size, static_cast<uint8_t*>(buffer), size);
    if (unlikely(resized)) {
      HBT_LOG_ERROR() << "Unexpeted resizing of buffers";
      return -EPERM;
    }
    if (ptr == nullptr) {
      return -ENODATA;
    }
    return static_cast<ssize_t>(size);
  }

  template <class T>
  [[nodiscard]] ssize_t copyInTx(T* buffer) DEXCEPT {
    static_assert(std::is_trivially_copyable<T>::value);
    return copyInTx(sizeof(T), buffer);
  }

  [[nodiscard]] ssize_t commitTx() DEXCEPT {
    if (unlikely(!inTx())) {
      return -EINVAL;
    }
    this->header_.incTail(this->tx_size_);
    this->tx_size_ = 0;
    // <in_read_tx> flags that we are in a transaction,
    // so enforce no stores pass it.
    this->header_.in_read_tx.store(false, std::memory_order_release);
    return 0;
  }

  /// If kContiguous, look for end of contiguous data and ignore kElem.
  /// Else, search for first occurrence of kElem in buffer.
  /// Both modes take into account bytes already read in transaction.
  /// If found, returns size of read that ends at matched position (inclusive).
  /// if not found, return -ENODATA.
  /// It does not update <tx_size_>.
  template <bool kContiguous, uint8_t kElem = 0x0>
  ssize_t findInBufferInTx() const DEXCEPT {
    if (unlikely(!inTx())) {
      return -EINVAL;
    }
    uint64_t head = this->header_.readHead();
    // Single reader because we are in Tx, safe to read tail.
    uint64_t tail = this->header_.readTail();

    HBT_DCHECK_LE(head - tail, this->header_.kDataPoolByteSize);
    HBT_DCHECK_LE(
        head + this->tx_size_ - tail, this->header_.kDataPoolByteSize);

    HBT_DCHECK_LE(tail + this->tx_size_, head);

    if (tail + this->tx_size_ == head) {
      return -ENODATA;
    }

    // start and end are head and tail in module arithmetic.
    uint64_t start = (this->tx_size_ + tail) & this->header_.kDataModMask;
    uint64_t end = head & this->header_.kDataModMask;

    const bool wrap = start >= end;

    if constexpr (kContiguous) {
      // if no elem is provided, then find contiguous chunk.
      if (wrap) {
        return static_cast<ssize_t>(this->header_.kDataPoolByteSize - start);
      } else {
        return static_cast<ssize_t>(end - start);
      }
    }

    const auto loop1_end = wrap ? this->header_.kDataPoolByteSize : end;
    for (auto i = start; i < loop1_end; ++i) {
      if (unlikely(this->data_[i] == kElem)) {
        return static_cast<ssize_t>(i - start) + 1;
      }
    }
    if (unlikely(wrap)) {
      // Search in wrapped part of buffer.
      for (decltype(end) i = 0; i < end; ++i) {
        if (unlikely(this->data_[i] == kElem)) {
          return static_cast<ssize_t>(
              this->header_.kDataPoolByteSize - start + i + 1);
        }
      }
    }
    return -ENODATA;
  }

  /// If kContiguous, read chunk of data until wrapping or end of buffer.
  /// Else, read next chunk of data until kStopByte (or -ENODATA).
  /// Both modes takes into account bytes already read in transaction.
  template <bool kContiguous, const uint8_t kStopByte = '\0'>
  [[nodiscard]] std::pair<ssize_t, const void*> readInTxChunk() {
    if (unlikely(!inTx())) {
      return {-EINVAL, nullptr};
    }
    auto ret = findInBufferInTx<kContiguous, kStopByte>();
    if (0 > ret) {
      return {ret, nullptr};
    }
    // Single reader because we are in Tx, safe to read tail.
    uint64_t tail = this->header_.readTail();
    uint64_t start = (this->tx_size_ + tail) & this->header_.kDataModMask;
    this->tx_size_ += ret;
    // Now ret is the size of first contiguous chunk.
    return {ret, &this->data_[start]};
  }

  [[nodiscard]] ssize_t cancelTx() DEXCEPT {
    if (unlikely(!inTx())) {
      return -EINVAL;
    }
    auto old_tx_size = static_cast<ssize_t>(this->tx_size_);
    this->tx_size_ = 0;
    // <in_read_tx> flags that we are in a transaction,
    // so enforce no stores pass it.
    this->header_.in_read_tx.store(false, std::memory_order_release);
    return old_tx_size;
  }

  /// Drop the contents of buffer and commits transaction.
  /// Note that this is a writing operation.
  [[nodiscard]] ssize_t dropInTx() DEXCEPT {
    if (unlikely(!inTx())) {
      return -EINVAL;
    }
    auto old_tx_size = static_cast<ssize_t>(this->tx_size_);
    this->tx_size_ = 0;
    this->header_.drop();
    this->header_.in_read_tx.store(false, std::memory_order_release);
    return old_tx_size;
  }

  /// Move to pos, an unwrapped value (like head or tail).
  /// Clamps in [tail, head).
  /// Does not terminate transaction in error.
  [[nodiscard]] ssize_t seekInTx(size_t pos) DEXCEPT {
    if (unlikely(!inTx())) {
      return -EINVAL;
    }
    auto h = this->header_.readHead();
    auto t = this->header_.readTail();
    HBT_DCHECK_LE(t, h);

    pos = std::clamp(pos, t, h);
    auto tx_size = static_cast<ssize_t>(pos) - static_cast<ssize_t>(t);
    HBT_DCHECK_GE(tx_size, 0);
    this->tx_size_ = static_cast<size_t>(tx_size);
    return tx_size;
  }

  /// Move <size> bytes in ongoing transaction.
  /// Clamps in [tail, head).
  /// Does not terminate transaction in error.
  [[nodiscard]] ssize_t relSeekInTx(ssize_t delta) DEXCEPT {
    if (unlikely(!inTx())) {
      return -EINVAL;
    }
    auto h = static_cast<ssize_t>(this->header_.readHead());
    auto t = static_cast<ssize_t>(this->header_.readTail());
    HBT_DCHECK_LE(t, h);
    auto size = h - t;

    auto tx_size = static_cast<ssize_t>(this->tx_size_);
    tx_size = std::clamp(tx_size + delta, 0l, size);
    this->tx_size_ = static_cast<size_t>(tx_size);
    return tx_size;
  }

  //
  // High-level atomic operations.
  //

  /// Drop all buffer's content.
  [[nodiscard]] ssize_t drop() DEXCEPT {
    if (auto ret = startTx(); 0 > ret) {
      return ret;
    }
    // Drops and commits.
    return dropInTx();
  }

  /// Drop <n> bytes from buffer, if <n> is larger that buffer content,
  /// then drop all content.
  [[nodiscard]] ssize_t dropN(size_t n) DEXCEPT {
    if (auto ret = startTx(); 0 > ret) {
      return ret;
    }
    HBT_DCHECK_EQ(this->tx_size_, 0);
    this->header_.dropN(std::min(this->header_.usedSizeWeak(), n));
    this->header_.in_read_tx.store(false, std::memory_order_release);
    return 0;
  }

  /// Makes a copy to <buffer>, buffer must be of size <size> or larger.
  [[nodiscard]] ssize_t copy(const size_t size, void* buffer) DEXCEPT {
    if (auto ret = startTx(); 0 > ret) {
      return ret;
    }

    auto ret = copyInTx(size, static_cast<uint8_t*>(buffer));
    if (0 > ret) {
      auto r = cancelTx();
      HBT_DCHECK_GE(r, 0);
      return ret;
    }
    HBT_DCHECK_EQ(ret, size);

    ret = commitTx();
    HBT_DCHECK_EQ(ret, 0);
    return static_cast<ssize_t>(size);
  }

  /// Makes a copy to <t>.
  template <class T>
  [[nodiscard]] ssize_t copy(T& t) DEXCEPT {
    static_assert(std::is_trivially_copyable<T>::value);
    return copy(sizeof(T), &t);
  }

  /// Start transaction and get ptr to first element.
  std::pair<ssize_t, const void*> startReadTx(size_t size) DEXCEPT {
    if (unlikely(size > this->header_.kDataPoolByteSize)) {
      return {-EINVAL, nullptr};
    }

    if (auto ret = startTx(); 0 > ret) {
      return {ret, nullptr};
    }

    auto [ret, ptr] = this->readInTx(size);
    if (0 > ret) {
      ssize_t r = cancelTx();
      HBT_DCHECK_GE(r, 0);
      HBT_DCHECK(ptr == nullptr);
    }
    return {ret, ptr};
  }

  template <class T>
  std::pair<ssize_t, const T*> startReadTx() DEXCEPT {
    static_assert(std::is_trivially_copyable<T>::value);
    auto [ret, ptr] = this->startReadTx(sizeof(T));
    return {ret, reinterpret_cast<const T*>(ptr)};
  }

  /// Read next size bytes.
  /// Return nummber of bytes read and, if successfull an object
  /// of type TRet with read data.
  template <class TRet = std::string>
  std::pair<ssize_t, std::optional<TRet>> read(size_t size) {
    auto [ret, ptr] = startReadTx(size);
    if (0 > ret) {
      return {ret, {}};
    }
    HBT_DCHECK_GE(ret, 0);
    auto length = static_cast<size_t>(ret);
    HBT_DCHECK(ptr != nullptr);
    TRet obj_ret{reinterpret_cast<const char*>(ptr), length};
    ret = this->commitTx();
    HBT_DCHECK_EQ(ret, 0);
    return {length, obj_ret};
  }

  /// Read next chunk that has a size preffix of type TSize.
  /// TRet must have a constructor that takes a pointer and a length.
  /// Return number of bytes read and, if successful, an object
  /// of type TRet with read data.
  template <class TSize, class TRet = std::string>
  std::pair<ssize_t, std::optional<TRet>> readSizedChunk() {
    static_assert(std::is_integral_v<TSize>);

    if (auto ret = startTx(); 0 > ret) {
      return {ret, std::nullopt};
    }

    auto [ret, ptr] = this->template readInTxWithSize<TSize>();
    if (0 > ret) {
      auto r = cancelTx();
      HBT_DCHECK_GE(r, 0);
      return {ret, std::nullopt};
    }
    HBT_DCHECK(ptr != nullptr);
    static_assert(
        std::numeric_limits<TSize>::max() <=
            std::numeric_limits<decltype(ret)>::max(),
        "Selected TSize can encode numbers larger than the largest size "
        "this function can return. This may cause silent overflow");
    TSize length = static_cast<TSize>(ret);

    // Build string and complete transaction.
    TRet obj_ret{reinterpret_cast<const char*>(ptr), length};
    ret = this->commitTx();
    HBT_DCHECK_EQ(ret, 0);
    return {sizeof(TSize) + length, obj_ret};
  }

  /// If kContiguous, read chunk of data until wrapping or end of buffer.
  /// Both modes takes into account bytes already read in transaction.
  template <bool kContiguous, const uint8_t kStopByte, class TRet = std::string>
  std::pair<ssize_t, std::optional<TRet>> readChunk() {
    if (auto ret = startTx(); 0 > ret) {
      return {ret, std::nullopt};
    }

    auto [ssize_ret, ptr] =
        this->template readInTxChunk<kContiguous, kStopByte>();
    if (0 > ssize_ret) {
      auto r = cancelTx();
      HBT_DCHECK_GE(r, 0);
      return {ssize_ret, std::nullopt};
    }
    auto length = static_cast<size_t>(ssize_ret);
    HBT_DCHECK(ptr != nullptr);
    TRet obj_ret{reinterpret_cast<const char*>(ptr), length};
    auto ret = this->commitTx();
    HBT_DCHECK_EQ(ret, 0);
    return {ssize_ret, obj_ret};
  }

 protected:
  uint8_t* aux_buffer_ = nullptr;
  size_t aux_buffer_size_ = 0;

  // Get a pointer to next contiguous <size> bytes in ringbuffer's data.
  // May copy to auxiliar buffer if no contiguous.
  const uint8_t* read_(const size_t size) DEXCEPT {
    if (size == 0) {
      return nullptr;
    }
    auto [ptr, resized] =
        readFromRingBuffer_<false, true>(size, aux_buffer_, aux_buffer_size_);
    if (ptr == nullptr) {
      return nullptr;
    }
    if (resized != nullptr) {
      aux_buffer_ = resized;
      aux_buffer_size_ = size;
    }
    return ptr;
  }

  /// If <kCanResizeCopyBuffer> is true, then <copy_buffer> will be resized
  /// as needed.
  ///
  /// Returns a pair with ptr to data (or null if no data available), and ptr to
  /// resized buffer iff resized (nullptr otherwise).
  /// If succeeds, increases <tx_size_> by size.
  template <bool kAlwaysCopy, bool kCanResizeCopyBuffer>
  std::pair<const uint8_t*, uint8_t*> readFromRingBuffer_(
      const size_t size,
      uint8_t* copy_buffer,
      size_t buffer_size) DEXCEPT {
    // Caller must have taken care of this.
    HBT_DCHECK_LE(size, this->header_.kDataPoolByteSize);

    if constexpr (kAlwaysCopy) {
      if (unlikely(copy_buffer == nullptr)) {
        HBT_LOG_ERROR() << "kAlwaysCopy requires non-null copy_buffer";
        return {nullptr, nullptr};
      }
    }

    if constexpr (!kCanResizeCopyBuffer) {
      if (unlikely(buffer_size < size)) {
        HBT_LOG_ERROR() << "Copy buffer is too small and "
                        << "kCanResizeCopyBuffer is set to false";
        return {nullptr, nullptr};
      }
    }

    if (unlikely(0 >= size)) {
      HBT_LOG_ERROR() << "Cannot copy value of zero size";
      return {nullptr, nullptr};
    }

    if (unlikely(size > this->header_.kDataPoolByteSize)) {
      HBT_LOG_ERROR() << "reads larger than buffer are not supported";
      return {nullptr, nullptr};
    }

    uint64_t head = this->header_.readHead();
    // Single reader because we are in Tx, safe to read tail.
    uint64_t tail = this->header_.readTail();

    HBT_DCHECK_LE(head - tail, this->header_.kDataPoolByteSize);

    // Check if there is enough data.
    if (this->tx_size_ + size > head - tail) {
      return {nullptr, nullptr};
    }

    // start and end are head and tail in module arithmetic.
    uint64_t start = (this->tx_size_ + tail) & this->header_.kDataModMask;
    uint64_t end = (start + size) & this->header_.kDataModMask;

    bool wrap = start >= end;

    if (bool needs_copy = kAlwaysCopy || wrap; !needs_copy) {
      this->tx_size_ += size;
      // if no copy required, return pointer to data.
      return {&this->data_[start], nullptr};
    }

    bool needs_resize = buffer_size < size;
    if (unlikely(needs_resize)) {
      if constexpr (!kCanResizeCopyBuffer) {
        HBT_LOG_ERROR() << "resizing is needed but kCanResizeCopyBuffer"
                        << " is set to false. Make buffer larger?";
        return {nullptr, nullptr};
      }
      copy_buffer = static_cast<uint8_t*>(realloc(copy_buffer, size));
      if (unlikely(copy_buffer == nullptr)) {
        HBT_LOG_ERROR() << "Bad alloc";
        return {nullptr, nullptr};
      }
    }

    if (likely(!wrap)) {
      std::memcpy(copy_buffer, &this->data_[start], size);
    } else {
      size_t size0 = this->header_.kDataPoolByteSize - start;
      std::memcpy(copy_buffer, &this->data_[start], size0);
      std::memcpy(copy_buffer + size0, &this->data_[0], end);
    }
    this->tx_size_ += size;
    return {copy_buffer, needs_resize ? copy_buffer : nullptr};
  }
};

} // namespace facebook::hbt::ringbuffer
