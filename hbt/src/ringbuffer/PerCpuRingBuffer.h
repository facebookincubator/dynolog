// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/ringbuffer/Consumer.h"
#include "hbt/src/ringbuffer/Producer.h"
#include "hbt/src/ringbuffer/RingBuffer.h"
#include "hbt/src/shm/Segment.h"

#include <sys/types.h>
#include <algorithm>
#include <atomic>
#include <cstring>
#include <memory>
#include <tuple>
#include <type_traits>

///
/// PerCpuRingBuffer, PerCpuProducer and PerCpuConsumer.
///
namespace facebook::hbt::ringbuffer {

using MemOffset = ssize_t;

///
/// Auxiliary function to obtain the offset of the element
/// at the <cpu_id>-th position.
///
template <class T, bool kPadFalseSharing>
constexpr size_t perCpuOffset(unsigned cpu_id) {
  size_t s = sizeof(T);
  if constexpr (kPadFalseSharing) {
    // XXX: the default c library doesn't define the value of
    // this constant despite being in the
    // C++17 standard. Uncomment when this is fixed.
    // s = std::max(std::hardware_destructive_interference_size, s);
    s = std::max(64ul /* known L1 cache size */, s);
  }
  return s * cpu_id;
}

///
/// Contains THeader but not data pool buffer.
/// Can be placed into shared memory with emplacement new or use in an
/// allocator. Does not generate allocations.
///
template <class TExtraData>
class PerCpuRingBufferHeader {
 public:
  using THeader = RingBufferHeader<TExtraData>;

  const CpuSet cpu_set;
  // Size of RingBuffer's data per CPU, excluding padding.
  const uint64_t kRingBufferByteSize;
  // Size of RingBuffer's data per CPU, including padding.
  const uint64_t kPerCpuDataByteSize;
  // Contiguous chunk of memory to cover CPUs
  const uint64_t kDataPoolByteSize;

  PerCpuRingBufferHeader(const PerCpuRingBufferHeader&) = delete;
  PerCpuRingBufferHeader(PerCpuRingBufferHeader&&) = delete;

  // XXX: A future possible optimization is to pad to avoid false sharing.
  explicit PerCpuRingBufferHeader(
      uint64_t min_rb_byte_size,
      std::optional<CpuSet> opt_cpu_set)
      : cpu_set{CpuSet::getOrDefault(opt_cpu_set)},
        kRingBufferByteSize{nextPow2(min_rb_byte_size)},
        // XXX: Add padding if necessary.
        kPerCpuDataByteSize{kRingBufferByteSize},
        // with ids in range [0, cpu_set.max_cpu_id]
        kDataPoolByteSize{kPerCpuDataByteSize * (cpu_set.max_cpu_id + 1)} {
    for_each_cpu(cpu_id, cpu_set) {
      auto header_offset = perCpuOffset<THeader, true>(cpu_id);
      uint8_t* header_base = &rb_headers_storage_[header_offset];
      // Placement new to initialize RingBuffer header in per-CPU memory.
      new (header_base) RingBufferHeader<TExtraData>(kRingBufferByteSize);
      auto data_offset = static_cast<MemOffset>(cpu_id * kPerCpuDataByteSize);
      rb_data_offsets_[cpu_id] = data_offset;
    }
  }

  THeader* getHeader(CpuId cpu_id) {
    if (unlikely(!cpu_set.hasCpu(cpu_id))) {
      HBT_THROW_EINVAL() << "No CPU with ID: " << cpu_id;
    }
    auto header_offset = perCpuOffset<THeader, true>(cpu_id);
    uint8_t* ptr = &rb_headers_storage_[header_offset];
    return reinterpret_cast<THeader*>(ptr);
  }

  MemOffset getDataOffset(CpuId cpu_id) const {
    if (unlikely(!cpu_set.hasCpu(cpu_id))) {
      HBT_THROW_EINVAL() << "No CPU with ID: " << cpu_id;
    }
    return rb_data_offsets_[cpu_id];
  }

 protected:
  // To keep it shared memory friendly, we want all data as part of the class.
  // We use in-place new to initialize to
  // "Avoid gratuitous default constructors", More Effective C++, Scott Meyers.
  uint8_t rb_headers_storage_[perCpuOffset<THeader, true>(kMaxCpus)];
  MemOffset rb_data_offsets_[kMaxCpus];
};

/// Note that PerCpuRingBuffer object itself cannot be in shared_memory.
/// It lives in process private memory space.
template <class THeaderExtraData>
class PerCpuRingBuffer final {
 public:
  // Typenames in class namespace for templates that take PerCpuRingBuffer.
  using TExtraData = THeaderExtraData;
  // This alias specifies how are CPUs described for this PerCpuRinBuffer, it
  // is different for single RingBuffers.
  using TCpuDesc = CpuSet;
  using THeader = PerCpuRingBufferHeader<TExtraData>;
  using TRingBuffer = RingBuffer<TExtraData>;

  // This assert is in another class to avoid incomplete type issue.
  static_assert(
      std::is_trivially_copyable<THeader>::value,
      "PerCpuRingBufferHeader could be used in shared memory and"
      " therefore cannot have pointers");

  PerCpuRingBuffer(const PerCpuRingBuffer&) = delete;

  explicit PerCpuRingBuffer(
      std::shared_ptr<THeader> header,
      std::shared_ptr<uint8_t[]> data_pool) {
    HBT_THROW_IF_NULLPTR(header);
    HBT_THROW_IF_NULLPTR(data_pool);
    // XXX: Do extra checks, probably have some magic numbers.
    header_ = header;
    data_pool_ = data_pool;
    initRingBuffers_();
  }

  explicit PerCpuRingBuffer(
      size_t min_rb_byte_size,
      std::optional<CpuSet> opt_cpu_set) {
    header_ = std::make_shared<THeader>(min_rb_byte_size, opt_cpu_set);
    // XXX: Replace this with std::make_shared(int) once C++20 arrives.
    data_pool_ =
        std::shared_ptr<uint8_t[]>(new uint8_t[header_->kDataPoolByteSize]);
    initRingBuffers_();
  }

  std::shared_ptr<TRingBuffer> getCpuRingBuffer(CpuId cpu) {
    auto rb = rbs_.at(cpu);
    HBT_THROW_IF_NULLPTR(rb) << "RingBuffer at CPU " << cpu
                             << " has not been initialized, is CPU set?: "
                             << header_->cpu_set.hasCpu(cpu);
    return rb;
  }

  size_t usedSizeWeak(CpuId cpu) const {
    return this->getCpuRingBuffer(cpu)->usedSizeWeak();
    ;
  }

  auto getHeader() {
    return header_;
  }

  const auto& getCpuSet() const noexcept {
    return header_->cpu_set;
  }

 protected:
  std::shared_ptr<THeader> header_;
  std::shared_ptr<uint8_t[]> data_pool_;

  // Only used CPUs are initialized.
  std::array<std::shared_ptr<RingBuffer<TExtraData>>, kMaxCpus> rbs_;

  void initRingBuffers_() {
    // Initialize buffers for all online CPUs.
    for_each_cpu(cpu, header_->cpu_set) {
      uint8_t* data = data_pool_.get() + header_->getDataOffset(cpu);

      // Keep references to head and data_pool in shared_ptr deleter
      // to guarantee is released after the new RingBuffer.
      auto capture_header = this->header_;
      auto capture_data = this->data_pool_;
      auto deleter = [capture_header, capture_data](TRingBuffer* rb) {
        delete rb;
      };
      rbs_[cpu] = std::shared_ptr<TRingBuffer>(
          new TRingBuffer(header_->getHeader(cpu), data), deleter);
    }
  }
};

///
/// A helper class to create producer/consumer view of a PerCpuRingBuffer.
///
/// TProdCons can either be a Producer or a Consumer.
///
template <class TProdCons>
class PerCpuRingBufferHelper {
 public:
  using TExtraData = typename TProdCons::TExtraData;
  using TPerCpuRingBuffer = PerCpuRingBuffer<TExtraData>;

  PerCpuRingBufferHelper(const PerCpuRingBufferHelper<TProdCons>&) = delete;

  explicit PerCpuRingBufferHelper(std::shared_ptr<TPerCpuRingBuffer> per_cpu_rb)
      : per_cpu_rb_{per_cpu_rb} {
    HBT_THROW_IF_NULLPTR(per_cpu_rb_);
    // Initialize pointers to Producers/Consumers in advance
    // to avoid races when accessing per_cpu_prodcons_.
    for_each_cpu(cpu, per_cpu_rb_->getHeader()->cpu_set) {
      auto cpu_rb = this->per_cpu_rb_->getCpuRingBuffer(cpu);
      per_cpu_prodcons_[cpu] = std::make_unique<TProdCons>(cpu_rb);
    }
  }

  TProdCons* atCpuPtr(CpuId cpu) {
    auto& ptr = per_cpu_prodcons_[cpu];
    return ptr.get();
  }

  TProdCons& atCpu(CpuId cpu) {
    auto& ptr = per_cpu_prodcons_[cpu];
    if (unlikely(ptr == nullptr)) {
      std::ostringstream oss;
      oss << "No RingBuffer at CPU: " << cpu;
      throw std::out_of_range(oss.str());
    }
    return *ptr;
  }

  auto getRingBuffer() {
    return per_cpu_rb_;
  }

  auto getCpuRingBuffer(CpuId cpu) const {
    return per_cpu_rb_->getCpuRingBuffer(cpu);
  }

  const auto& getCpuSet() const noexcept {
    return per_cpu_rb_->getCpuSet();
  }

 protected:
  std::shared_ptr<TPerCpuRingBuffer> per_cpu_rb_;
  std::array<std::unique_ptr<TProdCons>, kMaxCpus> per_cpu_prodcons_;
};

template <class TExtraData>
using PerCpuProducer = PerCpuRingBufferHelper<Producer<TExtraData>>;

template <class TExtraData>
using PerCpuConsumer = PerCpuRingBufferHelper<Consumer<TExtraData>>;

} // namespace facebook::hbt::ringbuffer
