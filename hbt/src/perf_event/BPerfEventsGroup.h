// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/perf_event/CpuEventsGroup.h"
#include "hbt/src/perf_event/PmuDevices.h"
#include "hbt/src/perf_event/PmuEvent.h"
#include "hbt/src/perf_event/bperf_leader_cgroup.skel.h"
#include "hbt/src/perf_event/bpf/bperf.h"

namespace facebook::hbt::perf_event {

enum class BPerfEventType {
  SystemWide = 1,
  Cgroup = 2,
};

#define BPERF_METRIC_NAME_SIZE 16

// This is the data we stored in a pinned BPF map
//   /sys/fs/bpf/bperf_attr_map_vXXX
// where XXX is the version number ATTR_MAP_VERSION.
//
// This map doesn't hold reference on any of these programs or maps.
struct bperf_attr_map_key {
  __u32 size;
  __u32 flags = 0;
  char name[BPERF_METRIC_NAME_SIZE];
  bperf_attr_map_key(std::string n, int s);
};

struct bperf_attr_map_elem {
  __u32 perf_event_array_id;
  __u32 leader_prog_link_id;
  __u32 diff_reading_map_id;

  __u32 global_output_map_id;
  __u32 cgroup_output_map_id;

  void loadFromSkelLink(
      struct bperf_leader_cgroup* skel,
      struct bpf_link* link);
};

class BPerfEventsGroup {
 public:
  using ReadValues = GroupReadValues<mode::Counting>;
  ///
  ///  - name: Name for eBPF maps.
  ///  - confs: Event Confs for group.
  ///  - type: the type of event.
  ///  - id:
  BPerfEventsGroup(
      const std::string& name,
      const EventConfs& confs,
      BPerfEventType type,
      __u64 id);

  BPerfEventsGroup(
      const std::string& name,
      const EventConfs& confs,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper);

  ~BPerfEventsGroup();
  static std::string attrMapPath();
  bool enable();
  bool disable();
  bool isEnabled() const {
    return enabled_;
  }

  // eBPF like interface to read counters from all CPUs and accumulate them.
  int read(struct bpf_perf_event_value* output, bool skip_offset = false);

  bool read(ReadValues& rv, bool skip_offset = false);

 protected:
  const std::string name_;
  const EventConfs confs_;
  const enum BPerfEventType type_;
  const __u64 id_;

  std::vector<struct perf_event_attr> attrs_;
  int leader_link_fd_ = -1;
  int leader_prog_fd_ = -1;
  int output_fd_ = -1;

  bool enabled_ = false;
  int cpu_cnt_;
  std::vector<int> pe_fds_;

  // There could be multiple users of a given metric, e.g., global cycles.
  // To make them work in parallel, the BPF side never stop counting. Each
  // User needs to maintain an offset in user space from the events group is
  // enabled. The logic around the offset is like:
  //
  //   On enable:
  //     syncGlobal_();
  //     read(&offset_);
  //
  //   On read:
  //     syncGlobal_();
  //     read(&output);
  //     output -= offset;
  //
  //   On Pause:
  //     syncGlobal_();
  //     close(leader_link_fd_);
  //     ioctl(PERF_EVENT_IOC_DISABLE)
  //
  //   On Resume:
  //     ioctl(PERF_EVENT_IOC_ENABLE)
  //     leader_link_fd_ = reattach(leader_prog_fd_);
  //     syncGlobal_();
  //     read(&offset_);
  struct bpf_perf_event_value offsets_[BPERF_MAX_GROUP_SIZE];

  int lockAttrMap_();
  int reloadSkel_(int attr_map_fd, struct bperf_attr_map_elem* entry);
  int loadPerfEvent_(struct bperf_leader_cgroup* skel);

  static int syncCpu_(__u32 cpu, int leader_pd);
  void syncGlobal_();
  bool reenable_();
};

} // namespace facebook::hbt::perf_event
