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
  // Cumulative runqueue wait (ns); see cumulative_sched_delay_ns in bperf.h.
  __u64 schedDelay;
  struct bpf_perf_event_value values[BPERF_MAX_GROUP_SIZE];
};

class BPerfPerThreadReader {
 public:
  BPerfPerThreadReader(
      std::string pin_name,
      const std::vector<std::filesystem::path>& bpf_pinned_map_dirs,
      int event_cnt);
  ~BPerfPerThreadReader();
  BPerfPerThreadReader(const BPerfPerThreadReader&) = delete;
  BPerfPerThreadReader& operator=(const BPerfPerThreadReader&) = delete;
  BPerfPerThreadReader(BPerfPerThreadReader&&) = delete;
  BPerfPerThreadReader& operator=(BPerfPerThreadReader&&) = delete;
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
  const std::vector<std::filesystem::path> bpf_pinned_map_dirs_;
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
  // Checks whether the bpf program supporting per-thread bperf is still
  // running. If `version_out` is non-null, the 8-bit version stored in
  // bits 0-7 of the metadata flags is written to it from the SAME
  // atomic 32-bit load of `metadata->flags` that produced the return
  // value, so the caller gets a consistent snapshot of both
  // BPERF_FLAG_ENABLED and the version counter.
  bool isLeaderRunning_(__u32* version_out = nullptr);
  // returns the 8-bit version stored in the metadata flags. The version is
  // bumped by the writer every time BPERF_FLAG_ENABLED changes, so readers
  // can detect a flag transition that occurred between two reads.
  __u32 flagsVersion_();
};

} // namespace facebook::hbt::perf_event
