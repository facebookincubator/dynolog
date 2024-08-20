// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/perf_event/Metrics.h"
#include "hbt/src/perf_event/PerfEventsGroup.h"
#include "hbt/src/perf_event/PmuDevices.h"
#include "hbt/src/perf_event/PmuEvent.h"
#include "hbt/src/perf_event/bpf/bperf.h"

namespace facebook::hbt::perf_event {

struct BPerfThreadData {
  __u64 cpuTime;
  __u64 monoTime;
  __u64 counters[BPERF_MAX_GROUP_SIZE];
};

class BPerfPerThreadReader {
 public:
  BPerfPerThreadReader(std::string pin_name, int event_cnt);
  ~BPerfPerThreadReader();
  int read(struct BPerfThreadData* data);
  int enable();
  void disable();

 protected:
  void* mmap_ptr_ = nullptr;
  struct bperf_thread_data* data_ = nullptr;
  int data_fd_ = -1;
  const std::string pin_name_;
  __s64 initial_clock_drift_ = 0;
  int event_cnt_;
  int mmap_size_;
};

} // namespace facebook::hbt::perf_event
