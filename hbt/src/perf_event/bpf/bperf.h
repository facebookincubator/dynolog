// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#ifndef BPERF_H
#define BPERF_H

#define BPERF_MAX_GROUP_SIZE 8

#define BPERF_MAX_THREAD_READER 65535
// index 0 is reserved for metadata, and will never be used for a thread
#define BPERF_INVALID_THREAD_IDX 0
typedef __u16 idx_t;

_Static_assert(
    (1 << (sizeof(idx_t) * 8)) > BPERF_MAX_THREAD_READER,
    "idx_t need to be an unsigned type with the max value >= BPERF_MAX_THREAD_READER");

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
  /* Layout of `flags`:
   *   bits 0-7  : 8-bit version counter, bumped on every change of
   *               BPERF_FLAG_ENABLED.
   *   bit 8     : BPERF_FLAG_ENABLED. Notifies BPerfPerThreadReader that
   *               the BPF programs supporting per-thread BPerf event
   *               updates have been stopped. When disabled, the values in
   *               the per-thread BPF map are no longer being updated and
   *               should not be trusted.
   *
   * The version allows readers to detect a transition of BPERF_FLAG_ENABLED
   * that happened in between an earlier check and a subsequent rdpmc().
   *
   * Only one thread (the dynolog main thread) ever modifies `flags`,
   * so the variable assignment does not need to be atomic. Use the
   * bperf_flags_*() helpers below to keep the version counter in sync
   * with BPERF_FLAG_ENABLED.
   */
#define BPERF_FLAG_VERSION_MASK 0xFFu
#define BPERF_FLAG_ENABLED (1u << 8)
  __u32 flags;
};

/* Returns the 8-bit version stored in bits 0-7 of `flags`. */
static inline __u32 bperf_flags_version(__u32 flags) {
  return flags & BPERF_FLAG_VERSION_MASK;
}

/* Returns true if BPERF_FLAG_ENABLED (bit 8) is set in `flags`. */
static inline int bperf_flags_is_enabled(__u32 flags) {
  return (flags & BPERF_FLAG_ENABLED) != 0;
}

/* Returns a new value of `flags` with BPERF_FLAG_ENABLED set and the
 * version bumped by 1.
 */
static inline __u32 bperf_flags_set_enabled(__u32 flags) {
  __u32 next_version =
      (bperf_flags_version(flags) + 1u) & BPERF_FLAG_VERSION_MASK;
  return (flags & ~(BPERF_FLAG_VERSION_MASK | BPERF_FLAG_ENABLED)) |
      BPERF_FLAG_ENABLED | next_version;
}

/* Returns a new value of `flags` with BPERF_FLAG_ENABLED cleared and the
 * version bumped by 1.
 */
static inline __u32 bperf_flags_clear_enabled(__u32 flags) {
  __u32 next_version =
      (bperf_flags_version(flags) + 1u) & BPERF_FLAG_VERSION_MASK;
  return (flags & ~(BPERF_FLAG_VERSION_MASK | BPERF_FLAG_ENABLED)) |
      next_version;
}

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
  /* when the perf value offset is updated */
  __u64 offset_update_time;

  /* runtime = runtime_until_offset_update + tsc_time - offset_time; */
  __u64 runtime_until_offset_update;

  /* Snapshot of task->sched_info.run_delay (cumulative runqueue wait, ns).
   * Same value as field 2 of /proc/<pid>/task/<tid>/schedstat. 0 on
   * kernels without CONFIG_SCHED_INFO.
   */
  __u64 cumulative_sched_delay_ns;

  struct bperf_perf_event_data events[];
};

#define BPERF_MAX_THREAD_DATA_SIZE    \
  (sizeof(struct bperf_thread_data) + \
   sizeof(struct bperf_perf_event_data) * BPERF_MAX_GROUP_SIZE)

inline int bperf_roundup(int size, int align) {
  return (size + align - 1) / align * align;
}

#endif
