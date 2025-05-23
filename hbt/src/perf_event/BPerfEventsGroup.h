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
  static std::string perThreadArrayMapPath(const std::string& n);
  static std::string perThreadIndexMapPath(const std::string& n);

  using ReadValues = GroupReadValues<mode::Counting>;
  ///
  ///  - confs: Event Confs for group.
  BPerfEventsGroup(
      const EventConfs& confs,
      int cgroup_update_level,
      bool support_per_thread = false,
      const std::string& pin_name = "");
  BPerfEventsGroup(
      const MetricDesc& metric,
      const PmuDeviceManager& pmu_manager,
      int cgroup_update_level,
      bool support_per_thread = false,
      const std::string& pin_name = "");

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
  int readGlobal(struct bpf_perf_event_value* output, bool skip_offset = false)
      const;
  bool readGlobal(ReadValues& rv, bool skip_offset = false) const;
  int readGlobalPerCpu(
      std::map<
          int,
          std::array<struct bpf_perf_event_value, BPERF_MAX_GROUP_SIZE>>&
          output) const;
  bool readGlobalPerCpu(std::map<int, ReadValues>& rv) const;

  int readCgroup(struct bpf_perf_event_value* output, __u64 id) const;
  bool readCgroup(ReadValues& rv, __u64 id) const;

  EventConfs getEventConfs() const;

 protected:
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

  std::vector<struct bpf_perf_event_value> readFromBpf_(int fd, __u64 id) const;

  int read(
      struct bpf_perf_event_value* output,
      int fd,
      __u64 id,
      bool skip_offset = false) const;

  int readPerCpu(
      std::map<
          int,
          std::array<struct bpf_perf_event_value, BPERF_MAX_GROUP_SIZE>>&
          output,
      int fd,
      __u64 id) const;

  int reloadSkel_(struct bperf_attr_map_elem* entry);
  int loadPerfEvent_(struct bperf_leader_cgroup* skel);

  static int syncCpu_(__u32 cpu, int leader_pd);
  static void toReadValues(ReadValues& rv, struct bpf_perf_event_value*);
  void syncGlobal_() const;

  // For per thread monitoring
  bool per_thread_;
  const std::string pin_name_;

  int pinThreadMaps_(bperf_leader_cgroup* skel);
  int preparePerThreadBPerf_(bperf_leader_cgroup* skel);
  int lookupPerfEvent_(struct bperf_leader_cgroup* skel);

  ::bpf_link* register_thread_link_ = nullptr;
  ::bpf_link* unregister_thread_link_ = nullptr;
  int per_thread_data_size_ = 0;
  ::bpf_link* pmu_enable_exit_link_ = nullptr;
};
} // namespace facebook::hbt::perf_event
