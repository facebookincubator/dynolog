// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <bpf/libbpf.h>
#include <errno.h>
#include <stdlib.h>

#include "hbt/src/perf_event/Metrics.h"
#include "hbt/src/perf_event/PerfEventsGroup.h"
#include "hbt/src/perf_event/PmuDevices.h"
#include "hbt/src/perf_event/PmuEvent.h"
#include "hbt/src/perf_event/bpf/bperf.h"

struct bperf_leader_cgroup;

namespace facebook::hbt::perf_event {

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

  __u32 trigger_prog_id;

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
  BPerfEventsGroup(
      const std::string& name,
      const EventConfs& confs,
      int cgroup_update_level);
  BPerfEventsGroup(
      const std::string& name,
      const MetricDesc& metric,
      const PmuDeviceManager& pmu_manager,
      int cgroup_update_level);

  ~BPerfEventsGroup();

  size_t getNumEvents() const;
  bool open();
  void close();
  bool isOpen() const;
  bool enable(bool reset = false);
  bool disable();
  bool isEnabled() const {
    return enabled_;
  }

  bool addCgroup(std::shared_ptr<hbt::FdWrapper> fd, int cgroup_update_level);
  bool removeCgroup(__u64 id);

  // eBPF like interface to read counters from all CPUs and accumulate them.
  int readGlobal(struct bpf_perf_event_value* output, bool skip_offset = false);
  bool readGlobal(ReadValues& rv, bool skip_offset = false);

  int readCgroup(struct bpf_perf_event_value* output, __u64 id);
  bool readCgroup(ReadValues& rv, __u64 id);

 protected:
  const std::string name_;
  const EventConfs confs_;

  // set of cgrup inodes that the BPerfEventsGroup is monitoring
  // inode # => fd wrapper
  std::map<__u64, std::shared_ptr<hbt::FdWrapper>> cgroup_fds_;

  std::vector<struct perf_event_attr> attrs_;
  int leader_link_fd_ = -1;
  int leader_prog_fd_ = -1;
  int trigger_prog_fd_ = -1;
  int global_output_fd_ = -1;
  int cgroup_output_fd_ = -1;

  bool opened_ = false;
  bool enabled_ = false;
  int cpu_cnt_;
  std::vector<int> pe_fds_;
  int cgroup_update_level_;

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

  int read(
      struct bpf_perf_event_value* output,
      int fd,
      __u64 id,
      bool skip_offset = false);

  int reloadSkel_(struct bperf_attr_map_elem* entry);
  int loadPerfEvent_(struct bperf_leader_cgroup* skel);

  static int syncCpu_(__u32 cpu, int leader_pd);
  static void toReadValues(ReadValues& rv, struct bpf_perf_event_value*);
  void syncGlobal_();
};

} // namespace facebook::hbt::perf_event
