// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/PerCpuBase.h"

#include <map>
#include <memory>

namespace facebook::hbt::perf_event {

// Utility class that makes a per-CPU generator (multiple CPUs)
// from a type defined for a single CPU.
template <class TCpuGenerator>
class PerCpuSampleGeneratorBase : public PerCpuBase<TCpuGenerator> {
 public:
  using TBase = PerCpuBase<TCpuGenerator>;

  PerCpuSampleGeneratorBase(
      const CpuSet& mon_cpus,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper)
      : TBase{mon_cpus, cgroup_fd_wrapper} {}

  void changeSamplePeriod(uint64_t new_sample_period) {
    for_each_cpu(cpu, this->mon_cpus_) {
      this->getCpuGenerator(cpu).changeSamplePeriod(new_sample_period);
    }
  }

  TimeStamp getLastTimeStamp(CpuId cpu) const {
    return this->getCpuGenerator(cpu).getLastTimeStamp();
  }

  /// Convert TSC timestamp to kernel's high resolution clock.
  TimeStamp tstampFromTsc(TimeStamp tsc) const {
    return this->getCpuGenerator(this->mon_cpus_.cpu_first_set())
        .kernelTimeFromTsc(tsc);
  }

  /// Convert kernel's high resolution clock to TSC timestamp.
  TimeStamp tscFromTimeStamp(TimeStamp tstamp) const {
    return this->getCpuGenerator(this->mon_cpus_.cpu_first_set())
        .tscFromKernelTime(tstamp);
  }

  /// Current timestamp in kernel's scheduler high resolution clock (nanoseconds
  /// since boot). Note that this is implemented as getting TSC clock and then
  /// converting it into nanoseconds since boot using kernel provided scaling
  /// and offset. See CpuEventsGroup::now() for more details.
  TimeStamp now() const noexcept {
    return this->getCpuGenerator(this->mon_cpus_.cpu_first_set()).now();
  }

  /// Build a TimeStampNsConverter to convert between TSC and kernel time
  /// timestamps. Useful to release MonData objects in Monitor.
  auto buildTimeStampNsConverter() const {
    HBT_DCHECK(this->isEnabled());
    // Similar to <now>.
    return this->getCpuGenerator(this->mon_cpus_.cpu_first_set())
        .buildTimeStampNsConverter();
  }

  /// Process events in CPU ringbuffers until either an error, ENODATA or
  /// last event's timestamp is larger than stop_ts.
  /// Returns number of CPUs for which we processed events beyond stop_ts.
  unsigned accumUntil(unsigned batch_size, TimeStamp stop_ts) {
    HBT_ARG_CHECK_GT(batch_size, 0);
    unsigned num_done = 0;
    for_each_cpu(cpu, this->getMonCpus()) {
      ssize_t ret = 0;
      auto& gen = this->getCpuGenerator(cpu);
      while (gen.getLastTimeStamp() <= stop_ts) {
        ret = gen.consume(batch_size);
        HBT_THROW_ASSERT_IF(
            0 > ret && ret != -ENODATA && ret != -EAGAIN && ret != EBUSY)
            << "Unexpected error processing batch: " << ret << " "
            << toErrorCode(-ret);
        if (ret == -ENODATA) {
          // No data in the ringbuffer is not considered an error.
          ret = 0;
          break;
        }
      }

      // At this point it either finished because it hit stop_ts or
      // an unhandled error.
      if (likely(ret >= 0)) {
        ++num_done;
      }
    }
    return num_done;
  }
};

} // namespace facebook::hbt::perf_event
