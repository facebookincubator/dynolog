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
    : pin_name_(std::move(pin_name)), event_cnt_(event_cnt) {
  // TODO: to be really backward/forward compatible, it is necessary to
  // adjust mmap_size_ based after mmap.
  mmap_size_ = (sizeof(struct bperf_thread_data) +
                event_cnt * sizeof(struct bperf_perf_event_data)) *
      BPERF_MAX_THREAD_READER;
}

static __u64 getRefMonoTime(void) {
  struct timespec ts;

  clock_gettime(CLOCK_MONOTONIC, &ts);
  return ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

int BPerfPerThreadReader::enable() {
  int idx_fd, tid, idx = 0, err;

  idx_fd =
      ::bpf_obj_get(BPerfEventsGroup::perThreadIndexMapPath(pin_name_).c_str());
  data_fd_ =
      ::bpf_obj_get(BPerfEventsGroup::perThreadArrayMapPath(pin_name_).c_str());

  if (idx_fd < 0 || data_fd_ < 0) {
    HBT_LOG_ERROR() << "cannot open fds " << idx_fd << " " << data_fd_;
    goto error;
  }

  mmap_ptr_ = mmap(
      nullptr, mmap_size_, PROT_READ | PROT_WRITE, MAP_SHARED, data_fd_, 0);

  if (mmap_ptr_ == MAP_FAILED) {
    HBT_LOG_ERROR() << "mmap failed with " << errno;
    goto error;
  }

  tid = gettid();
  err = ::bpf_map_lookup_elem(idx_fd, &tid, &idx);

  if (err != 0) {
    HBT_LOG_ERROR() << "cannot lookup the idx";
    goto error;
  }

  ::close(idx_fd);

  data_ = (struct bperf_thread_data*)mmap_ptr_;
  data_ += idx;

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
