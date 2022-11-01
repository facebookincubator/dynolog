// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"

#include <sys/types.h>
#include <atomic>
#include <cstring>
#include <memory>
#include <type_traits>

///
/// C++17 implementation of shared-memory friendly perf_event style ringbuffer.
/// It's designed to avoid parallel access and provide (almost) zero-copy
///
///
/// A ringbuffer has a header and a data members that can be allocated
/// independently from the ringbuffer object, allowing the ringbuffer object
/// to be stored in process' exclusive memory while header and data
/// could be in shared memory.
///
/// Multiple ringbuffers can reference the same header + data.
///
/// Multiple producers (or consumers) can reference the same ringbuffer.
///
/// Synchronization between all producers/consumers of all ringbuffers that
/// reference the same header + pair pairs is done using atomic operations
/// care is taken to guarantee lock-free implementations, reduce the usage
/// of LOCK prefixes and the access to non-exclusive cache lines by CPUs.
///
/// Producers write data atomically at ringbuffer's head, while Consumers
/// write data atomically at ringbuffer's tail.
///
namespace facebook::hbt::ringbuffer {

///
/// RingBufferHeader contains the head, tail and other control information
/// of the RingBuffer.
///
/// <kMinByteSize_> is the minimum byte size of the circular buffer. The actual
/// size is the smallest power of 2 larger than kMinByteSize_. Enforcing the
/// size to be a power of two avoids costly division/modulo operations.
///
/// TExtraData is an additional POD used to store user-defined additional
/// data that can be accesible by all producers and consumers.
///
template <class ExtraDataType>
class RingBufferHeader {
 public:
  using TExtraData = ExtraDataType;

  const uint64_t kDataPoolByteSize;
  const uint64_t kDataModMask;

  RingBufferHeader(const RingBufferHeader&) = delete;
  RingBufferHeader(RingBufferHeader&&) = delete;

  // Implementation uses power of 2 arithmetic to avoid costly modulo.
  // So build the largest RingBuffer with size of the smallest power of 2 >=
  // <byte_size>.
  // Use <cpu> for NUMA.
  RingBufferHeader(
      size_t min_data_byte_size,
      std::optional<CpuId> /*cpu*/ = std::nullopt)
      : kDataPoolByteSize{nextPow2(min_data_byte_size)},
        kDataModMask{kDataPoolByteSize - 1} {
    // Minimum size where implementation of bit shift arithmetic works.
    HBT_DCHECK_GE(kDataPoolByteSize, 2)
        << "Minimum supported ringbuffer data size is 2 bytes";
    HBT_DCHECK(isPow2(kDataPoolByteSize))
        << kDataPoolByteSize << " is not a power of 2";
  }

  // Get size that is only guaranteed to be correct when producers and consumers
  // are synchronized.
  size_t usedSizeWeak() const {
    return atomicHead_ - atomicTail_;
  }

  size_t freeSizeWeak() const {
    return kDataPoolByteSize - usedSizeWeak();
  }

  uint64_t readHead() const {
    return atomicHead_;
  }

  uint64_t readTail() const {
    return atomicTail_;
  }

  void incHead(uint64_t inc) {
    atomicHead_ += inc;
  }
  void incTail(uint64_t inc) {
    atomicTail_ += inc;
  }

  void drop() {
    atomicTail_.store(atomicHead_.load());
  }

  void dropN(uint64_t n) {
    atomicTail_ += n;
    HBT_DCHECK_LE(atomicTail_.load(), atomicHead_.load());
  }

  // acquired by producers.
  std::atomic_bool in_write_tx = false;
  // acquired by consumers.
  std::atomic_bool in_read_tx = false;

  TExtraData extra_data;

  // Enforce that TExtraData is a POD to make it safe to live in shared-memory.
  // There may be weaker requirements but POD works is sufficient.
  static_assert(
      std::is_trivially_copyable_v<TExtraData>,
      "RingBuffer ExtraData must live in shared memory and "
      "therefore have no pointers");

 protected:
  // Written by producer.
  std::atomic_uint64_t atomicHead_ = 0;
  // Written by consumer.
  std::atomic_uint64_t atomicTail_ = 0;

  // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2427.html#atomics.lockfree
  static_assert(
      decltype(atomicHead_)::is_always_lock_free,
      "Only lock-free atomics are supported");
  static_assert(
      decltype(atomicTail_)::is_always_lock_free,
      "Only lock-free atomics are supported");
  static_assert(
      decltype(in_write_tx)::is_always_lock_free,
      "Only lock-free atomics are supported");
  static_assert(
      decltype(in_read_tx)::is_always_lock_free,
      "Only lock-free atomics are supported");
};

///
/// Process' view of a ring buffer.
/// This cannot reside in shared memory since it has pointers.
///
template <class THeaderExtraData>
class RingBuffer final {
 public:
  // Typenames in class namespace for templates that take RingBuffer.
  using THeader = RingBufferHeader<THeaderExtraData>;
  using TExtraData = THeaderExtraData;
  // This alias specifies how CPUs are described for this ringbuffer.
  // It is different for PerCpuRingBuffer.
  using TCpuDesc = CpuId;

  RingBuffer(const RingBuffer&) = delete;
  RingBuffer(RingBuffer&&) = delete;

  RingBuffer(THeader* header, uint8_t* data)
      : owns_data{false}, header_{header}, data_{data} {
    HBT_THROW_IF_NULLPTR(header_) << "Header cannot be nullptr";
    HBT_THROW_IF_NULLPTR(data_) << "Data cannot be nullptr";
  }

  /// Allocate header and data. Throwing function
  RingBuffer(size_t size, std::optional<CpuId> cpu = std::nullopt) noexcept(
      false)
      : owns_data{true} {
    header_ = new THeader(size, cpu);
    data_ = new uint8_t[header_->kDataPoolByteSize];
  }

  ~RingBuffer() {
    if (owns_data) {
      delete header_;
      delete[] this->data_;
    }
  }

  const THeader& getHeader() const {
    return *header_;
  }

  THeader& getHeader() {
    return *header_;
  }

  const uint8_t* getData() const {
    return data_;
  }

  uint8_t* getData() {
    return data_;
  }

  auto& getExtraData() {
    return header_->extra_data;
  }

  const auto& getExtraData() const {
    return header_->extra_data;
  }

 protected:
  const bool owns_data;
  THeader* header_;
  uint8_t* data_;
};

///
/// Ringbuffer wrapper.
///
/// An utility base class for Producers and Consumers.
///
template <class THeaderExtraData>
class RingBufferWrapper {
 public:
  // Declare TExtraData in class namespace.
  using TExtraData = THeaderExtraData;
  using TRingBuffer = RingBuffer<TExtraData>;

  RingBufferWrapper(const RingBufferWrapper&) = delete;

  RingBufferWrapper(std::shared_ptr<TRingBuffer> rb)
      : rb_{rb}, header_{rb->getHeader()}, data_{rb->getData()} {
    HBT_THROW_IF_NULLPTR(rb);
    HBT_THROW_IF_NULLPTR(data_);
  }

  auto& getHeader() noexcept {
    return header_;
  }

  const auto& getHeader() const noexcept {
    return header_;
  }

  auto getRingBuffer() noexcept {
    return rb_;
  }

  const auto& getRingBufferRef() const noexcept {
    return rb_;
  }

  auto& refHeaderExtraData() noexcept {
    return this->header_.extra_data;
  }

  const auto& refHeaderExtraData() const noexcept {
    return this->header_.extra_data;
  }

 protected:
  std::shared_ptr<TRingBuffer> rb_;
  typename TRingBuffer::THeader& header_;
  uint8_t* const data_;
  size_t tx_size_ = 0;
};

} // namespace facebook::hbt::ringbuffer
