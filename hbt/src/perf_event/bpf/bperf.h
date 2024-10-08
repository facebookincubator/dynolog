// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#ifndef BPERF_H
#define BPERF_H

#define BPERF_MAX_GROUP_SIZE 8

#define BPERF_MAX_THREAD_READER 1024

/* x86
 * struct cyc2ns_data {
 *   u32 cyc2ns_mul;
 *   u32 cyc2ns_shift;
 *   u64 cyc2ns_offset;
 *  };
 *
 * time_ns = (tsc * multi) >> shift - offset
 *
 * On arm64
 *   time_ns = TODO
 */
struct bperf_clock_param {
  __u32 multi;
  __u32 shift;
  __u64 offset;
  __u64 reserved;
};

/* data of a single perf_event */
struct bperf_perf_event_data {
  struct bpf_perf_event_value output_value;
  __u64 offset;
  __u32 idx;
};

struct bperf_thread_metadata {
  __u32 metadata_size; /* sizeof(bperf_thread_metadata) */
  __u32 thread_data_size; /* sizeof(bperf_thread_data) */
  __u32 event_data_size; /* sizeof(bperf_perf_event_data) */
  __u32 event_cnt;
  __u32 flags;
};

/* BPerfEventsGroup may have variable number of perf events.
 * Therefore, the bperf_thread_data used for each thread may
 * change. To show the data, we use fixed size header for per
 * group data (time, etc.), and a variable sized array for
 * per event data (bperf_perf_event_data).
 */
struct bperf_thread_data {
  __u32 lock;
  __u32 __reserved;
  struct bperf_clock_param tsc_param;

  /* all the times are in nano seconds */
  /* when the task got scheduled the last time */
  __u64 schedule_time;

  /* runtime = runtime_until_schedin + tsc_time - schedin_time; */
  __u64 runtime_until_schedin;

  struct bperf_perf_event_data events[];
};

inline int bperf_roundup(int size, int align) {
  return (size + align - 1) / align * align;
}

#endif
