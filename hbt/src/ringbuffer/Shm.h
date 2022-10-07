// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/ringbuffer/PerCpuRingBuffer.h"
#include "hbt/src/ringbuffer/RingBuffer.h"
#include "hbt/src/shm/Segment.h"

#include <type_traits>

namespace facebook::hbt::ringbuffer::shm {

template <class TRingBuffer>
std::pair<std::string, std::string> segmentNames(const std::string& preffix) {
  using TExtraData = typename TRingBuffer::TExtraData;

  using URingBuffer = RingBuffer<TExtraData>;
  using UPerCpuRingBuffer = PerCpuRingBuffer<TExtraData>;

  static_assert(
      std::is_same<TRingBuffer, URingBuffer>::value ||
          std::is_same<TRingBuffer, UPerCpuRingBuffer>::value,
      "Unknown type");

  if constexpr (std::is_same<TRingBuffer, URingBuffer>::value) {
    return {preffix + "/rb/header", preffix + "/rb/data"};
  } else {
    return {preffix + "/per_cpu_rb/header", preffix + "/per_cpu_rb/data"};
  }
}

/// Creates ringbuffer on shared memory.
///
/// RingBuffer's data can have any <hbt::shm::PageType>
/// (e.g. 4KB or a HugeTLB Page of 2MB or 1GB). If  <data_page_type> is not
/// provided, then choose the largest page that would result in
/// close to full occupancy.
///
/// If <persistent>, the shared memory will not be unlinked
/// when RingBuffer is destroyed.
///
/// <min_rb_byte_size> is the minimum size of the data section
/// of a RingBuffer (or each CPU's RingBuffer).
///
/// The type of buffer is controlled by TCpuSet as follows:
///   - TCpuSet is CpuId, returns a RingBuffer, using
///       cpu_spec for NUMA bindings (if available).
///   - TCpuSet is CpuSet, returns a TPerCpuRingBuffer, using cpu_spec
///       to create desired per-CPU RingBuffers (if available).
template <class TRingBuffer>
auto create(
    const std::string& segment_preffix,
    size_t min_rb_byte_size,
    bool persistent,
    std::optional<typename TRingBuffer::TCpuDesc> cpu_desc = std::nullopt,
    std::optional<hbt::shm::PageType> data_page_type = std::nullopt,
    bool perm_write = true) {
  auto [header_name, data_name] = segmentNames<TRingBuffer>(segment_preffix);
  // if buffer is not persistent, it's underlying shared memory segment will
  // be unlinked with it.
  // Do not link the shared memory segment to a path on creation because
  // the ringbuffer needs to be initialized first.
  const auto link_flags = persistent
      ? hbt::shm::CreationMode::None
      : hbt::shm::CreationMode::UnlinkOnDestruction;

  auto [header, header_segment] =
      hbt::shm::Segment::create<typename TRingBuffer::THeader>(
          header_name,
          perm_write,
          hbt::shm::PageType::Default,
          link_flags,
          min_rb_byte_size,
          cpu_desc);

  auto [data, data_segment] = hbt::shm::Segment::create<uint8_t[]>(
      header->kDataPoolByteSize,
      data_name,
      perm_write,
      data_page_type,
      link_flags);

  // RingBuffer needs a shared_ptr with custom deleter. Special case it.
  using URingBuffer = RingBuffer<typename TRingBuffer::TExtraData>;

  std::shared_ptr<TRingBuffer> rb;
  if constexpr (std::is_same<TRingBuffer, URingBuffer>::value) {
    // create local variables to allow lambda to capture.
    auto header_ptr = header;
    auto data_ptr = data;
    auto deleter = [header_ptr, data_ptr](TRingBuffer* rb) { delete rb; };

    // custom destructor for shared_ptr to release shared_ptr's captured by
    // lambda.
    rb = std::shared_ptr<TRingBuffer>(
        new TRingBuffer(header.get(), data.get()), deleter);
  } else {
    rb = std::make_shared<TRingBuffer>(header, data);
  }
  // Link to final paths to make data segments accessible to other processes.
  header_segment->link();
  data_segment->link();
  return rb;
}

template <class TRingBuffer>
std::shared_ptr<TRingBuffer> load(
    const std::string& segment_preffix,
    std::optional<hbt::shm::PageType> data_page_type = std::nullopt,
    bool perm_write = true) {
  auto [header_name, data_name] = segmentNames<TRingBuffer>(segment_preffix);
  auto [header, header_segment] =
      hbt::shm::Segment::load<typename TRingBuffer::THeader>(
          header_name, perm_write, hbt::shm::PageType::Default);

  constexpr auto kHeaderSize = sizeof(typename TRingBuffer::THeader);
  if (unlikely(kHeaderSize != header_segment->getSize())) {
    HBT_THROW_SYSTEM(EPERM) << "Header segment of unexpected size";
  }

  auto [data, data_segment] =
      hbt::shm::Segment::load<uint8_t[]>(data_name, perm_write, data_page_type);

  if (unlikely(header->kDataPoolByteSize != data_segment->getSize())) {
    HBT_THROW_SYSTEM(EPERM) << "Data segment of unexpected size";
  }

  // RingBuffer cannot take shared_ptr's. Special case it.
  using URingBuffer = RingBuffer<typename TRingBuffer::TExtraData>;
  if constexpr (std::is_same<TRingBuffer, URingBuffer>::value) {
    // Lambdas can only capture identifiers, so create new local share_ptrs that
    // can be captured.
    auto capture_header = header;
    auto capture_data = data;
    auto deleter = [capture_header, capture_data](TRingBuffer* rb) {
      delete rb;
    };
    // custom destructor for shared_ptr to release shared_ptr's captured by
    // lambda.
    return std::shared_ptr<TRingBuffer>(
        new TRingBuffer(header.get(), data.get()), deleter);
  } else {
    return std::make_shared<TRingBuffer>(header, data);
  }
}

template <class TRingBuffer>
inline void unlink(const std::string& segment_preffix) {
  auto [header_name, data_name] = segmentNames<TRingBuffer>(segment_preffix);
  hbt::shm::Segment::unlink(header_name);
  hbt::shm::Segment::unlink(data_name);
}

} // namespace facebook::hbt::ringbuffer::shm
