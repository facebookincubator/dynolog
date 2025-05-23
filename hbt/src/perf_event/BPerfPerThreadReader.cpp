// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/BPerfPerThreadReader.h"
#include <bpf/bpf.h>
#include <time.h>
#include "hbt/src/perf_event/BPerfEventsGroup.h"

namespace facebook::hbt::perf_event {

BPerfPerThreadReader::BPerfPerThreadReader(std::string pin_name, int event_cnt)
    : pin_name_(std::move(pin_name)), event_cnt_(event_cnt) {}

static __u64 getRefMonoTime(void) {
  struct timespec ts;

  clock_gettime(CLOCK_MONOTONIC, &ts);
  return ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

int BPerfPerThreadReader::getDataSize_() {
  struct bpf_map_info map_info;
  __u32 map_info_len = sizeof(map_info);
  int err;

  memset(&map_info, 0, sizeof(map_info));
  err = bpf_obj_get_info_by_fd(data_fd_, &map_info, &map_info_len);

  if (err) {
    return err;
  }

  data_size_ = map_info.value_size;
  mmap_size_ = data_size_ * map_info.max_entries;
  return 0;
}

int BPerfPerThreadReader::enable() {
  struct perf_event_attr attr;
  int idx_fd, tid, idx = 0, err;
  struct bperf_thread_metadata* metadata;
  struct BPerfThreadData data;

  if (enabled_) {
    return 0;
  }

  idx_fd =
      ::bpf_obj_get(BPerfEventsGroup::perThreadIndexMapPath(pin_name_).c_str());
  data_fd_ =
      ::bpf_obj_get(BPerfEventsGroup::perThreadArrayMapPath(pin_name_).c_str());

  if (idx_fd < 0 || data_fd_ < 0) {
    HBT_LOG_ERROR() << "cannot open fds " << idx_fd << " " << data_fd_;
    goto error;
  }

  if (getDataSize_() != 0) {
    goto error;
  }

  tid = gettid();
  if (::bpf_map_lookup_elem(idx_fd, &tid, &idx) == 0) {
    // We haven't registered this tid yet. If the tid is already added,
    // it must be added by a different instance of BPerfPerThreadReader
    // for the same thread. BPerfPerThreadReader does not support two
    // instances for the same thread, so we abort this enable().
    HBT_LOG_ERROR() << "cannot register the same thread twice";
    goto error;
  }

  mmap_ptr_ = mmap(nullptr, mmap_size_, PROT_READ, MAP_SHARED, data_fd_, 0);

  if (mmap_ptr_ == MAP_FAILED) {
    HBT_LOG_ERROR() << "mmap failed with " << errno;
    goto error;
  }

  err = ::bpf_map_lookup_elem(idx_fd, &tid, &idx);

  if (err != 0) {
    HBT_LOG_ERROR() << "cannot lookup the idx ";
    goto error;
  }

  metadata = (struct bperf_thread_metadata*)mmap_ptr_;

  ::close(idx_fd);

  data_ = (struct bperf_thread_data*)((unsigned long long)mmap_ptr_ +
                                      idx * data_size_);

  for (int i = 0; i < event_cnt_; i++) {
    event_data_[i] =
        (struct bperf_perf_event_data*)((unsigned long long)data_ +
                                        metadata->thread_data_size +
                                        i * metadata->event_data_size);
  }

  // Create a disabled hardware event. This is needed, otherwise rdpmc
  // instruction will cause segmentation fault.
  memset(&attr, 0, sizeof(attr));
  attr.type = PERF_TYPE_HARDWARE;
  attr.config = PERF_COUNT_HW_CPU_CYCLES;
  attr.size = sizeof(attr);
  attr.disabled = 1;

  dummy_pe_fd_ = syscall(
      __NR_perf_event_open,
      &attr,
      0 /* pid */,
      -1 /* cpu */,
      -1 /* group_fd */,
      0 /* flags */);

  if (dummy_pe_fd_ < 0) {
    HBT_LOG_ERROR() << "cannot create dummy perf event";
    goto error;
  }

  dummy_pe_mmap_ =
      ::mmap(nullptr, getpagesize(), PROT_READ, MAP_SHARED, dummy_pe_fd_, 0);
  if (dummy_pe_mmap_ == MAP_FAILED) {
    goto error;
  }

  // There is a small drift between time from clock_gettime() and tsc.
  // On a skylake host, I get about 0.02% difference. Get the initial
  // drift at the moment and use it to fix future readings.
  enabled_ = true;
  read(&data);
  initial_clock_drift_ = getRefMonoTime() - data.monoTime;
  return 0;

error:
  ::close(idx_fd);
  disable();
  return -1;
}

void BPerfPerThreadReader::disable() {
  if (!enabled_) {
    return;
  }
  ::munmap(mmap_ptr_, mmap_size_);
  mmap_ptr_ = nullptr;
  data_ = nullptr;
  ::close(data_fd_);
  data_fd_ = -1;
  initial_clock_drift_ = 0LL;
  ::munmap(dummy_pe_mmap_, getpagesize());
  dummy_pe_mmap_ = nullptr;
  ::close(dummy_pe_fd_);
  dummy_pe_fd_ = -1;
  enabled_ = false;
}

BPerfPerThreadReader::~BPerfPerThreadReader() {
  disable();
}

#define barrier() asm volatile("" ::: "memory")

int BPerfPerThreadReader::read(struct BPerfThreadData* data) {
  struct bperf_clock_param *ptr = &data_->tsc_param, p;
  struct bperf_thread_data raw_thread_data;
  struct bperf_perf_event_data raw_event_data[event_cnt_];
  __u64 pmc_val[event_cnt_];
  __u64 tsc, time_after_offset_update;
  __u32 lock;
  int i, idx;

  if (!enabled_) {
    return -1;
  }

  do {
    lock = data_->lock;
    barrier();
    tsc = rdtsc();
    p = *ptr;
    raw_thread_data = *data_;
    for (i = 0; i < event_cnt_; i++) {
      raw_event_data[i] = *event_data_[i];
      idx = raw_event_data[i].idx;
      if (idx > 0) {
        pmc_val[i] = rdpmc(idx - 1);
      } else {
        pmc_val[i] = 0;
      }
    }
    barrier();
  } while (lock != data_->lock);

  data->monoTime = (((__uint128_t)tsc * p.multi) >> p.shift) + p.offset +
      initial_clock_drift_;
  time_after_offset_update =
      data->monoTime - raw_thread_data.offset_update_time;
  data->cpuTime =
      raw_thread_data.runtime_until_offset_update + time_after_offset_update;

  // TODO: Detect when the lead program stops. It is a bit tricky, as
  //       it may look like current thread is always running.
  //       This will be easier once with some perf event.
  for (i = 0; i < event_cnt_; i++) {
    data->values[i] = raw_event_data[i].output_value;
    data->values[i].enabled += time_after_offset_update;

    if (raw_event_data[i].idx) {
      data->values[i].counter += pmc_val[i] - raw_event_data[i].offset;
      data->values[i].running += time_after_offset_update;
    }
  }
  if (leadExited(data->values[0].counter)) {
    disable();
    return -1;
  }
  return 0;
}

// Heuristic to check whether the lead program has exited.
bool BPerfPerThreadReader::leadExited(__u64 counter_zero) {
  bool ret;

  if (!enabled_) {
    return true;
  }

  ret = counter_zero == prev_counter_zero_;
  prev_counter_zero_ = counter_zero;
  return ret;
}

} // namespace facebook::hbt::perf_event
