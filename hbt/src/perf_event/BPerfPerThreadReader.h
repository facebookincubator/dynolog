// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <bpf/libbpf.h>

#include "hbt/src/perf_event/Metrics.h"
#include "hbt/src/perf_event/PerfEventsGroup.h"
#include "hbt/src/perf_event/PmuDevices.h"
#include "hbt/src/perf_event/PmuEvent.h"
#include "hbt/src/perf_event/bpf/bperf.h"

namespace facebook::hbt::perf_event {

struct BPerfThreadData {
  __u64 cpuTime;
  __u64 monoTime;
  struct bpf_perf_event_value values[BPERF_MAX_GROUP_SIZE];
};

class BPerfPerThreadReader {
 public:
  BPerfPerThreadReader(std::string pin_name, int event_cnt);
  ~BPerfPerThreadReader();
  int read(struct BPerfThreadData* data);
  int enable();
  void disable();
  bool isEnabled() {
    return enabled_;
  }

 protected:
  void* mmap_ptr_ = nullptr;
  struct bperf_thread_data* data_ = nullptr;
  // For compatibility (newer leader with older reader), we cannot use
  // data_->events directly. Instead use event_data_ which is adjusted
  // based on leader data structure.
  struct bperf_perf_event_data* event_data_[BPERF_MAX_GROUP_SIZE] = {nullptr};
  int data_fd_ = -1;
  const std::string pin_name_;
  __s64 initial_clock_drift_ = 0;
  int event_cnt_ = -1;
  int data_size_ = 0;
  int mmap_size_ = 0;
  int getDataSize_();
  int dummy_pe_fd_ = -1;
  void* dummy_pe_mmap_ = nullptr;
  bool enabled_ = false;
  // Previous reading of event 0, used to detect when the lead exits
  __u64 prev_counter_zero_;
  bool leadExited(__u64 counter_zero);
};

} // namespace facebook::hbt::perf_event
