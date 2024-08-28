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
  int idx_fd, tid, idx = 0, err;
  struct bperf_thread_metadata* metadata;

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

  mmap_ptr_ = mmap(nullptr, mmap_size_, PROT_READ, MAP_SHARED, data_fd_, 0);

  if (mmap_ptr_ == MAP_FAILED) {
    HBT_LOG_ERROR() << "mmap failed with " << errno;
    goto error;
  }

  tid = gettid();
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

  // There is a small drift between time from clock_gettime() and tsc.
  // On a skylake host, I get about 0.02% difference. Get the initial
  // drift at the moment and use it to fix future readings.
  struct BPerfThreadData data;
  read(&data);
  initial_clock_drift_ = getRefMonoTime() - data.monoTime;
  return 0;

error:
  ::close(idx_fd);
  disable();
  return -1;
}

void BPerfPerThreadReader::disable() {
  munmap(mmap_ptr_, mmap_size_);
  mmap_ptr_ = nullptr;
  data_ = nullptr;
  ::close(data_fd_);
  data_fd_ = -1;
  initial_clock_drift_ = 0LL;
}

BPerfPerThreadReader::~BPerfPerThreadReader() {
  disable();
}

int BPerfPerThreadReader::read(struct BPerfThreadData* data) {
  struct bperf_clock_param *ptr = &data_->tsc_param, p;
  __u64 tsc;
  __u32 lock;

  do {
    lock = data_->lock;
    tsc = rdtsc();
    memcpy(&p, ptr, sizeof(p));
  } while (lock != data_->lock);

  data->monoTime = (((__uint128_t)tsc * p.multi) >> p.shift) + p.offset +
      initial_clock_drift_;
  data->cpuTime =
      data_->runtime_until_schedin + (data->monoTime - data_->schedin_time);

  // TODO: Detect when the lead program exists. It is a bit tricky, as
  //       it may look like current thread is always running.
  //       This will be easier once with some perf event.
  return 0;
}

} // namespace facebook::hbt::perf_event
