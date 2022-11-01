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

int event_cnt = 0;
int cpu_cnt = 0;

static void update_cgroup_output(struct bpf_perf_event_value* diff_val) {
  struct task_struct* task = bpf_get_current_task_btf();
  struct cgroup* cgrp = BPF_CORE_READ(task, cgroups, dfl_cgrp);
  __u32 i, level;

  for (level = 0; level < MAX_CGROUP_LEVELS; level++) {
    __u64 id = BPF_CORE_READ(cgrp, kn, id);
    struct bpf_perf_event_value* val;

    cgrp = (struct cgroup*)BPF_CORE_READ(cgrp, self.parent);
    if (cgrp == NULL)
      break;

    val = bpf_map_lookup_elem(&cgroup_output, &id);
    if (!val)
      continue;

    for (i = 0; i < BPERF_MAX_GROUP_SIZE; i++) {
      if (i >= event_cnt)
        break;

      val[i].counter += diff_val[i].counter;
      val[i].enabled += diff_val[i].enabled;
      val[i].running += diff_val[i].running;
    }
  }
}

SEC("raw_tp/sched_switch")
int BPF_PROG(on_switch) {
  struct bpf_perf_event_value val, *prev_val, *diff_val, *sys_val;
  __u32 key = bpf_get_smp_processor_id();
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
    __u32 idx = i * cpu_cnt + key;

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
  update_cgroup_output(diff_val);
  return 0;
}

char _license[] SEC("license") = "GPL";
