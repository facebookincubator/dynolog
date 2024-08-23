// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Reordering of these includes can lead to broken builds, so we disable
// formatting.
/* clang-format off */
#include <bpf/vmlinux/vmlinux.h>
#include <bpf/bpf_core_read.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include "bperf.h"
/* clang-format off */

#define MAX_CGROUP_LEVELS 10
#define DEFAULT_CGROUP_MAP_SIZE 64

typedef struct {
  __uint(type, BPF_MAP_TYPE_PERCPU_ARRAY);
  __uint(key_size, sizeof(__u32));
  __uint(
      value_size,
      sizeof(struct bpf_perf_event_value) * BPERF_MAX_GROUP_SIZE);
  __uint(max_entries, 1);
} value_array;

struct {
  __uint(type, BPF_MAP_TYPE_PERF_EVENT_ARRAY);
  __uint(key_size, sizeof(__u32));
  __uint(value_size, sizeof(int));
  __uint(max_entries, 1); /* # of cpu, updated before load */
  __uint(map_flags, BPF_F_PRESERVE_ELEMS);
} events SEC(".maps");

value_array diff_readings SEC(".maps");
value_array global_output SEC(".maps");
value_array prev_readings SEC(".maps");

struct {
  __uint(type, BPF_MAP_TYPE_PERCPU_HASH);
  __uint(key_size, sizeof(__u64));
  __uint(
      value_size,
      sizeof(struct bpf_perf_event_value) * BPERF_MAX_GROUP_SIZE);
  __uint(max_entries, DEFAULT_CGROUP_MAP_SIZE);
} cgroup_output SEC(".maps");

static void update_prev_user_page(struct bpf_perf_event_value* diff_val,
                                  struct task_struct *task);

const volatile int event_cnt = 0;
int cpu_cnt = 0;
int cgroup_update_level = 0;

#define PF_IDLE 0x00000002

static void update_cgroup_output(struct bpf_perf_event_value* diff_val,
                                 struct task_struct *task) {
  struct bpf_perf_event_value* val;
  __u64 id;
  __u32 i;

  id  = bpf_get_current_ancestor_cgroup_id(cgroup_update_level);
  val = bpf_map_lookup_elem(&cgroup_output, &id);
  if (!val)
    return;

  for (i = 0; i < BPERF_MAX_GROUP_SIZE; i++) {
    if (i >= event_cnt)
      break;

    val[i].counter += diff_val[i].counter;
    val[i].enabled += diff_val[i].enabled;
    val[i].running += diff_val[i].running;
  }
}

static __always_inline int bperf_leader_prog(struct task_struct *prev) {
  struct bpf_perf_event_value val, *prev_val, *diff_val, *sys_val;
  __u32 cpu = bpf_get_smp_processor_id();
  __u32 zero = 0, i;
  long err;

  prev_val = bpf_map_lookup_elem(&prev_readings, &zero);
  if (!prev_val)
    return 0;

  diff_val = bpf_map_lookup_elem(&diff_readings, &zero);
  if (!diff_val)
    return 0;

  sys_val = bpf_map_lookup_elem(&global_output, &zero);
  if (!sys_val)
    return 0;

  for (i = 0; i < BPERF_MAX_GROUP_SIZE; i++) {
    __u32 idx = i * cpu_cnt + cpu;

    if (i >= event_cnt)
      break;

    err = bpf_perf_event_read_value(&events, idx, &val, sizeof(val));
    if (err)
      continue;

    diff_val[i].counter = val.counter - prev_val[i].counter;
    diff_val[i].enabled = val.enabled - prev_val[i].enabled;
    diff_val[i].running = val.running - prev_val[i].running;
    prev_val[i] = val;

    sys_val[i].counter += diff_val[i].counter;
    sys_val[i].enabled += diff_val[i].enabled;
    sys_val[i].running += diff_val[i].running;
  }

  /* If previous task is idle (PF_IDLE), it means we are switching _from_
   * idle to non-idle task, and current "slice" of counts belongs to idle.
   * It is ok to skip cgroup walk for idle task.
   */
  if (prev->flags & PF_IDLE)
    return 0;

  update_cgroup_output(diff_val, prev);
  return 0;
}

/* This is triggered on context switch */
SEC("tp_btf/sched_switch")
int BPF_PROG(bperf_on_sched_switch, bool preempt, struct task_struct *prev,
            struct task_struct *next) {
  return bperf_leader_prog(prev);
}

/* This program is NOT attached. Instead, this is only triggered by user
 * space via BPF_PROG_TEST_RUN before reading the output. This is need to
 * gather current running data to the output maps.
 * We need a separate program because BPF_PROG_TEST_RUN does not work on
 * tp_btf program (bperf_on_sched_switch). tp_btf program is slightly
 * faster.
 */
SEC("raw_tp/sched_switch")
int BPF_PROG(bperf_read_trigger) {
  /* Account for current task */
  return bperf_leader_prog(bpf_get_current_task_btf());
}

/* bperf per thread monitoring */

/* per_thread_idx and per_thread_data map the channel that lead program,
 * e.g. dynolog, communicates with per thread users. The user will mmap
 * per_thread_data and check per_thread_idx for its index to use in the
 * mmapped area.
 */
struct {
  __uint(type, BPF_MAP_TYPE_HASH);
  __uint(key_size, sizeof(int)); /* pid */
  __uint(value_size, sizeof(int)); /* idx in per_thread_data */
  __uint(max_entries, BPERF_MAX_THREAD_READER);
} per_thread_idx SEC(".maps");

struct {
  __uint(type, BPF_MAP_TYPE_ARRAY);
  __uint(key_size, sizeof(int));
  /* for variable size bperf_thread_data, update value_size before load */
  __uint(value_size, 1);
  __uint(max_entries, BPERF_MAX_THREAD_READER);
  __uint(map_flags, BPF_F_MMAPABLE);
} per_thread_data SEC(".maps");

/* The following is a simple bitmap for per_thread_idx */
#define BITS_PER_U64 64
__u64 bitmap[BPERF_MAX_THREAD_READER / BITS_PER_U64];
#define NULL_BIT 0xffffffff

#define private(name) SEC(".data." #name) __hidden __attribute__((aligned(8)))
private(A) struct bpf_spin_lock bitmap_lock;

static __u32 __always_inline find_free_bit(void) {
  int i, j;

  for (i = 0; i < BPERF_MAX_THREAD_READER / BITS_PER_U64; i++) {
    if (bitmap[i] == ~0ULL)
      continue;
    for (j = 0; j < BITS_PER_U64; j++) {
      if (((1ULL << j) & bitmap[i]) == 0) {
        bitmap[i] |= 1ULL << j;
        return i * BITS_PER_U64 + j;
      }
    }
  }
  return NULL_BIT;
}

static void __always_inline clear_bit(__u32 idx) {
  __u32 key, shift;

  if (idx >= BPERF_MAX_THREAD_READER)
    return;

  key = idx / BITS_PER_U64;
  shift = idx % BITS_PER_U64;

  bitmap[key] &= ~(1ULL << shift);
}

static int __always_inline bperf_update_thread_time(struct bperf_thread_data *data, __u64 now);

__u32 per_thread_data_id; /* map id of per_thread_data */

/* Trace mmap of per_thread_data */
SEC("fentry/array_map_mmap")
int BPF_PROG(bperf_register_thread, struct bpf_map *map) {
  struct bperf_thread_data *data;
  __u32 map_id = map->id;
  __u32 tid;
  __u32 idx;

  if (map_id != per_thread_data_id)
    return 0;

  bpf_spin_lock(&bitmap_lock);
  idx = find_free_bit();
  bpf_spin_unlock(&bitmap_lock);

  if (idx == NULL_BIT)
    return 0;

  data = bpf_map_lookup_elem(&per_thread_data, &idx);
  if (!data)
    return 0;

  data->header_size = sizeof(struct bperf_thread_data);
  data->event_data_size = sizeof(struct bperf_perf_event_data);
  data->event_cnt = event_cnt;
  data->flags = 0;
  data->lock = 1;

  tid = bpf_get_current_pid_tgid() & 0xffffffff;
  bpf_map_update_elem(&per_thread_idx, &tid, &idx, BPF_ANY);

  data->runtime_until_schedin = 0;
  bperf_update_thread_time(data, bpf_ktime_get_ns());
  return 0;
}

/* Trace munmap of per_thread_data */
SEC("fentry/bpf_map_mmap_close")
int BPF_PROG(bperf_unregister_thread, struct vm_area_struct *vma) {
  struct bpf_map *map = bpf_core_cast(vma->vm_file->private_data,
                                      struct bpf_map);
  __u32 map_id = map->id;
  __u32 tid;
  __u32 *idx;

  if (map_id != per_thread_data_id)
    return 0;

  tid = bpf_get_current_pid_tgid() & 0xffffffff;

  idx = bpf_map_lookup_elem(&per_thread_idx, &tid);
  if (!idx)
    return 0;

  bpf_map_delete_elem(&per_thread_idx, &tid);

  bpf_spin_lock(&bitmap_lock);
  clear_bit(*idx);
  bpf_spin_unlock(&bitmap_lock);

  return 0;
}

/* The following handle monotonic time and thread run time */
#if __x86_64__
extern const struct cyc2ns cyc2ns __ksym;
#endif

static int __always_inline bperf_update_thread_time(struct bperf_thread_data *data, __u64 now)
{
#if __x86_64__
  struct cyc2ns *c;
  int seq, idx, i;

  /* Get tsc parameters, the logic is from kernel code:
   *
   *   arch/x86/kernel/tsc.c __cyc2ns_read
   */
  c = bpf_this_cpu_ptr(&cyc2ns);

  /* TODO: Consider adding some warning when i hit 10,
   * which shouldn't really happen
   */
  for (i = 0; i < 10; i++) {
    struct cyc2ns_data *cd;

    seq = c->seq.seqcount.sequence;
    idx = seq & 1;

    cd = bpf_core_cast(&c->data[idx], struct cyc2ns_data);
    data->tsc_param.offset = cd->cyc2ns_offset;
    data->tsc_param.multi = cd->cyc2ns_mul;
    data->tsc_param.shift = cd->cyc2ns_shift;

    if (seq == c->seq.seqcount.sequence)
      break;
  }

#elif __aarch64__
  /* TODO add arm64 support */
#endif

  data->schedin_time = now;
}

static void __always_inline update_prev_task(struct task_struct *prev, __u64 now) {
  struct bperf_thread_data *data;
  int pid = prev->pid;
  int *idx;

  idx = bpf_map_lookup_elem(&per_thread_idx, &pid);
  if (!idx)
    return;

  data = bpf_map_lookup_elem(&per_thread_data, idx);
  if (!data)
    return;

  data->runtime_until_schedin += now - data->schedin_time;
}

static void __always_inline update_next_task(struct task_struct *next, __u64 now) {
  struct bperf_thread_data *data;
  int pid = next->pid;
  int *idx;

  idx = bpf_map_lookup_elem(&per_thread_idx, &pid);
  if (!idx)
    return;

  data = bpf_map_lookup_elem(&per_thread_data, idx);
  if (!data)
    return;

  data->lock += 1;
  bperf_update_thread_time(data, now);
}

SEC("tp_btf/sched_switch")
int BPF_PROG(bperf_update_thread, bool preempt, struct task_struct *prev,
             struct task_struct *next) {
  __u64 now = bpf_ktime_get_ns();
  update_prev_task(prev, now);
  update_next_task(next, now);
  return 0;
}

char _license[] SEC("license") = "GPL";
