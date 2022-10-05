// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/CpuEventsGroup.h"
#include "hbt/src/perf_event/PerCpuSampleGeneratorBase.h"
#include "hbt/src/perf_event/PmuEvent.h"

#include <optional>

namespace facebook::hbt::perf_event {

// Move-only wrapper type of the AUX buffer's data
struct AuxSpaceData {
  // Construct from AUX buffer in OVERWRITE mode.
  AuxSpaceData(size_t total_size, uint8_t* aux_base, size_t aux_head) {
    /*
     * When the AUX space is configured as a ring buffer, the aux_head keeps
     * wrapping around the buffer and its not possible to detect if/how many
     * times the buffer wrapped around. See the below for an illustration.
     *
     * d - data (bytes of trace packets)
     * x - undefined data (random data initally in the buffer)
     *
     * Case 1:
     * aux_base [d,d,d,d,d,d,d,d,d,x,x,x,x,x,x,x,x,x,x] aux_size
     *                 aux_head->||<- firstpartsize ->|
     *
     * Case 2:
     * aux_base [d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d] aux_size
     *                 aux_head->||<- firstpartsize ->|
     *
     * Notice how there is no way to detect whether the aux_head has wrapped
     * around. Given this, we must always copy the entire buffer. To do this, we
     * first copy from the head to the end of the buffer (firstpartsize bytes),
     * then copy from base to the head, exclusive (aux_head bytes).
     *
     * Since decoders must synchronize on a PSB packet before decoding,
     * undefined data in the buffer will be ignored.
     */

    data.reserve(total_size);

    // Copy from the head to the end of the buffer.
    data.insert(data.end(), aux_base + aux_head, aux_base + total_size);
    // Copy from the start of the buffer to the head.
    data.insert(data.end(), aux_base, aux_base + aux_head);
  }

  AuxSpaceData(AuxSpaceData&&) = default;
  AuxSpaceData& operator=(AuxSpaceData&&) = default;
  explicit AuxSpaceData(const AuxSpaceData&) = default;
  AuxSpaceData& operator=(const AuxSpaceData&) = delete;
  // Bytes of the Aux buffer
  std::vector<uint8_t> data;
};

//
// CPTR extension of CpuEventsGroup<>.
//
// CpuAuxGenerator is used to enable hardware writing large amount
// of data stream directly to perf aux ring buffer (e.g. Intel PT).
// It also consume aux buffer related perf events (PERF_RECORD_AUX
// and PERF_RECORD_ITRACE_START).
//

class CpuTraceAuxGenerator final
    : public CpuEventsGroup<CpuTraceAuxGenerator, mode::AUXSpace> {
 public:
  using TBase = CpuEventsGroup<CpuTraceAuxGenerator, mode::AUXSpace>;

  enum class AUXBufferMode {
    // new tracing data will automatically overwrite old data.
    OVERWRITABLE,
    // user need to consume tracing data by setting aux_tail,
    // or tracing will stop once out of buffer space.
    NON_OVERWRITABLE,
  };

  CpuTraceAuxGenerator(
      CpuId cpu,
      pid_t pid,
      int cgroup_fd,
      EventConf event_conf)
      : TBase{cpu, pid, cgroup_fd, {event_conf}} {}

  void open(size_t num_aux_pages, AUXBufferMode mode) {
    HBT_ARG_CHECK(mode == AUXBufferMode::OVERWRITABLE)
        << "Only support AUXBufferMode::OVERWRITABLE currently.";
    // set main buffer to 4KiB by default.
    // it's expected that only 2 events
    // (1 PERF_RECRORD_AUX and 1 PERT_RECORD_ITRACE_START)
    // get fired in OVERWRITABLE mode.
    open(1u, num_aux_pages, mode);
  }

  void open(size_t num_data_pages, size_t num_aux_pages, AUXBufferMode mode) {
    HBT_ARG_CHECK(mode == AUXBufferMode::OVERWRITABLE)
        << "Only support AUXBufferMode::OVERWRITABLE currently.";
    aux_buffer_mode_ = mode;
    open_(num_data_pages, 1u, false, num_aux_pages);
  }

  void enableImpl() {
    buffer_ready_ = aux_buffer_mode_ == AUXBufferMode::NON_OVERWRITABLE;
  }

  void disableImpl() {
    buffer_ready_ = true;
  }

  // handle PERF_RECORD_AUX
  int handleRecordAux(const typename mode::AUXSpace::Aux&) noexcept {
    // ignore PERF_RECORD_AUX for now.
    // only rely on data from struct perf_event_mmap_page for simlicity.
    // but we still need to consume this event
    // so that we can free main buffer space.
    return 0;
  }

  // handle PERF_RECORD_ITRACE_START
  int handleRecordItraceStart(
      const typename mode::AUXSpace::ItraceStart&) noexcept {
    num_itrace_start_++;
    return 0;
  }

  size_t getNumItraceStart() {
    return num_itrace_start_;
  }

  void onCpuAuxBufferRead(OnRbReadCallback callback) {
    HBT_ARG_CHECK(aux_buffer_mode_ == AUXBufferMode::OVERWRITABLE)
        << "Only support AUXBufferMode::OVERWRITABLE currently.";

    HBT_ARG_CHECK(buffer_ready_)
        << "AUX buffer cannot be copied. Please ensure the generator has been enabled and "
           " if mode == OVERWRITEABLE, disable the generator then call copyToSink() to get a reasonable result.";

    size_t totalSize = auxSpaceSize();
    const uint8_t* basePtr = static_cast<const uint8_t*>(auxSpaceBase());
    size_t head = auxSpaceHeadWeak();
    CpuId cpuId = getCpu();

    if (head == 0) {
      callback(cpuId, RbDataSlices(basePtr, totalSize));
    } else {
      const uint8_t* ptr1 = basePtr + head;
      size_t size1 = totalSize - head;
      const uint8_t* ptr2 = basePtr;
      size_t size2 = head;
      callback(cpuId, RbDataSlices(ptr1, size1, ptr2, size2));
    }
  }

  // Read the data in the AUX buffer.
  // Currently, only supports OVERWRITABLE mode (ring buffer).
  // Returns std::nullopt on failure.
  std::optional<AuxSpaceData> readAuxSpaceData() {
    if (!buffer_ready_) {
      HBT_LOG_WARNING()
          << "AUX buffer cannot be copied. Please ensure the generator has been enabled and "
             " if mode == OVERWRITEABLE, disable the generator then call readAuxSpaceData() to get a reasonable result.";
      return std::nullopt;
    }
    return AuxSpaceData{
        auxSpaceSize(),
        static_cast<uint8_t*>(auxSpaceBase()),
        auxSpaceHeadWeak()};
  }

 protected:
  AUXBufferMode aux_buffer_mode_;
  size_t num_itrace_start_ = 0;
  // Flag indicating if the AUX buffer is ready to be copied.
  bool buffer_ready_ = false;
};

class PerCpuTraceAuxGenerator
    : public PerCpuSampleGeneratorBase<CpuTraceAuxGenerator> {
 public:
  using TCpuGenerator = CpuTraceAuxGenerator;

  PerCpuTraceAuxGenerator(
      const CpuSet& mon_cpus,
      pid_t pid,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper,
      EventConf event_conf)
      : PerCpuSampleGeneratorBase<CpuTraceAuxGenerator>{
            mon_cpus,
            cgroup_fd_wrapper} {
    for_each_cpu(cpu, mon_cpus) {
      this->cpu_generators_[cpu] = std::make_shared<TCpuGenerator>(
          cpu, pid, cgroup_fd_wrapper ? cgroup_fd_wrapper->fd : -1, event_conf);
    }
  }

  void open(size_t num_aux_pages, CpuTraceAuxGenerator::AUXBufferMode mode) {
    open(1u, num_aux_pages, mode);
  }

  void open(
      size_t num_data_pages,
      size_t num_aux_pages,
      CpuTraceAuxGenerator::AUXBufferMode mode) {
    HBT_ARG_CHECK(mode == CpuTraceAuxGenerator::AUXBufferMode::OVERWRITABLE)
        << "Only support AUXBufferMode::OVERWRITABLE currently.";
    for_each_cpu(cpu, mon_cpus_) {
      this->cpu_generators_.at(cpu)->open(num_data_pages, num_aux_pages, mode);
    }
  }
  void onCpusAuxBufferRead(OnRbReadCallback callback) {
    for_each_cpu(cpu, mon_cpus_) {
      this->cpu_generators_.at(cpu)->onCpuAuxBufferRead(callback);
    }
  }

  std::optional<AuxSpaceData> readAuxSpaceData(CpuId cpu) {
    return this->cpu_generators_.at(cpu)->readAuxSpaceData();
  }
};

} // namespace facebook::hbt::perf_event
