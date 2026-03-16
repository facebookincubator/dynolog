/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <stdint.h>
#include <sys/types.h>
#include <algorithm>
#include <chrono>
#include <string>

namespace dynolog {

using timestamp = std::chrono::time_point<std::chrono::steady_clock>;

struct TaskStat {
  time_t t = 0;
  timestamp ts;
  uint32_t seq = 0;

  pid_t tid = 0;
  pid_t ppid = 0;
  std::string comm;

  std::string tcomm;

  uint64_t cpuCount = 0; /* number of schedules */
  uint64_t cpuDelayTotalNs = 0; /* ns waiting to be scheduled */
  uint64_t cpuRunRealTotalNs = 0; /* total real cpu running time */
  uint64_t acMinflt = 0; /* Minor Page Fault Count - copy on write */
  uint64_t acMajflt = 0; /* Major Page Fault Count - virtual memory */
  /* Delay waiting for page fault I/O (swap in only) */
  uint64_t swapinCount = 0;
  uint64_t swapinDelayTotal = 0;
  uint64_t voluntaryCSW = 0; /* Voluntary Context Switches */
  uint64_t involuntaryCSW = 0; /* Involuntary Context Switches */
  uint64_t etime = 0; /* elapsed time in us */
  uint64_t utime = 0; /* User cpu time in us */
  uint64_t stime = 0; /* System cpu time in us */
  int64_t memdelayUs = 0; /* type waiting for memory page */
  uint64_t io_read_bytes = 0; /* bytes of read i/o */
  uint64_t io_write_bytes = 0; /* bytes of write i/o */
  /* High watermark of RSS usage in duration of a task, in KBytes. */
  uint64_t hiwaterRssKb = 0; /* High-watermark of RSS usage in KBytes */
};

// calculate difference assuming possible 32-bit counter overflow
static inline uint64_t deltaWrap32(uint64_t cur, uint64_t prev) {
  return cur < prev ? (UINT32_MAX - prev) + cur : cur - prev;
}

struct TaskStatsDelta {
  uint64_t cpuCount = 0;
  uint64_t cpuDelayUs = 0; /* time waiting to be scheduled */
  uint64_t cpuRunRealUs = 0; /* total real cpu running time */
  uint64_t acMinflt = 0;
  uint64_t acMajflt = 0;
  uint64_t swapinCount = 0;
  uint64_t swapinDelayUs = 0;
  uint64_t voluntaryCSW = 0; /* Voluntary Context Switches */
  uint64_t involuntaryCSW = 0; /* Involuntary Context Switches */
  uint64_t utimeUs = 0; /* user cpu time in us */
  uint64_t stimeUs = 0; /* time spent in System */
  uint64_t etimeUs = 0; /* time elapsed */
  int64_t memdelayUs = 0; /* time waiting for memory page */
  uint64_t io_read_bytes = 0; /* bytes of read i/o */
  uint64_t io_write_bytes = 0; /* bytes of write i/o */
  uint64_t hiwaterRssKb = 0;

  explicit TaskStatsDelta(const TaskStat& prev, const TaskStat& cur) {
    // It's quite annoying, but even though taskstats return 64-bit counters,
    // kernel actually keeps track of some of them in 32-bit counters, some in
    // 64-bit counters. To add to that confusion, taskstats has additional logic
    // to not roll-over counters on overflow and truncate it to zero (but that
    // will be relevant only to per-process stats, which can accumulate large
    // enough value across many threads, not per-thread stats, because for
    // single thread signed 64-bit overflow can happen only after 292 years). We
    // carefully take all that into account here when calculating deltas.

    // cpuCount is unsigned 64-bit counter (good for 584 years)
    cpuCount = cur.cpuCount - prev.cpuCount;

    // cpuDelay is signed 64-bit counter (good for 292 years)
    cpuDelayUs = (cur.cpuDelayTotalNs - prev.cpuDelayTotalNs) / 1000;

    // cpuRunReal is signed 64-bit counter (good for 292 years)
    cpuRunRealUs = (cur.cpuRunRealTotalNs - prev.cpuRunRealTotalNs) / 1000;

    // swapinCount is 32-bit counter
    swapinCount = deltaWrap32(cur.swapinCount, prev.swapinCount);

    // swapinDelay is unsigned 64-bit counter (good for 584 years)
    swapinDelayUs = (cur.swapinDelayTotal - prev.swapinDelayTotal) / 1000;

    // faults and context switches are unsigned 64-bit counters
    acMinflt = cur.acMinflt - prev.acMinflt;
    acMajflt = cur.acMajflt - prev.acMajflt;
    voluntaryCSW = cur.voluntaryCSW - prev.voluntaryCSW;
    involuntaryCSW = cur.involuntaryCSW - prev.involuntaryCSW;

    // etime is 64-bit counter always, we are good for at least 584 years
    etimeUs = cur.etime - prev.etime;

    // utime/stime are unsigned 64-bit counters tracked as nanoseconds.
    utimeUs = cur.utime - prev.utime;
    stimeUs = cur.stime - prev.stime;

    memdelayUs = prev.memdelayUs >= 0 && cur.memdelayUs >= prev.memdelayUs
        ? cur.memdelayUs - prev.memdelayUs
        : 0;

    // io reads and writes are unsigned 64-bit counters
    io_read_bytes = cur.io_read_bytes - prev.io_read_bytes;
    io_write_bytes = cur.io_write_bytes - prev.io_write_bytes;

    // at least is all straightforward with memory high watermark
    hiwaterRssKb = cur.hiwaterRssKb > prev.hiwaterRssKb ? cur.hiwaterRssKb
                                                        : prev.hiwaterRssKb;
  }
};

// aggregated thread stats
struct ThreadSummaryStats {
  uint32_t activeThreads = 0; /* number of live threads */
  uint32_t exitedThreads = 0; /* number of exited threads */
  uint64_t schedThreads = 0; /* number of threads scheduled to be run on CPU */

  uint64_t utimeUs = 0; /* time spent in User */
  uint64_t stimeUs = 0; /* time spent in System */
  uint64_t etimeUs = 0; /* time elapsed */
  uint64_t utimeMaxUs = 0; /* max utimeUs of all threads */
  uint64_t stimeMaxUs = 0; /* max stimeUs of all threads */
  uint64_t cpuTimeMaxUs = 0; /* max total cpu time of all threads */

  uint64_t hiwaterRssKb = 0; /* maximum RSS in KB */

  uint64_t schedDelayUs = 0; /* time waiting to be scheduled */
  uint64_t schedCount = 0; /* number of times thread was scheduled */
  uint64_t voluntaryCSW = 0; /* voluntary context switches */
  uint64_t involuntaryCSW = 0; /* involuntary context switches */
  uint64_t acMinflt = 0; /* minor faults */
  uint64_t acMajflt = 0; /* major faults */
  uint64_t swapinCount = 0; /* number of memory swap ins */
  uint64_t swapinDelayUs = 0; /* memory swap in elapsed time */
  int64_t memdelayUs = 0; /* amount of time thread waited to get memory */

  uint64_t io_read_bytes = 0; /* bytes of read i/o */
  uint64_t io_write_bytes = 0; /* bytes of write i/o */

  void aggregate(const TaskStatsDelta& d, bool exited) {
    activeThreads += exited ? 0 : 1;
    exitedThreads += exited ? 1 : 0;
    schedThreads += d.cpuCount > 0 ? 1 : 0;

    utimeUs += d.utimeUs;
    stimeUs += d.stimeUs;
    etimeUs += d.etimeUs;
    utimeMaxUs = std::max(utimeMaxUs, d.utimeUs);
    stimeMaxUs = std::max(stimeMaxUs, d.stimeUs);
    cpuTimeMaxUs = std::max(cpuTimeMaxUs, d.utimeUs + d.stimeUs);

    hiwaterRssKb =
        hiwaterRssKb > d.hiwaterRssKb ? hiwaterRssKb : d.hiwaterRssKb;

    schedDelayUs += d.cpuDelayUs;
    schedCount += d.cpuCount;
    voluntaryCSW += d.voluntaryCSW;
    involuntaryCSW += d.involuntaryCSW;
    acMinflt += d.acMinflt;
    acMajflt += d.acMajflt;
    swapinCount += d.swapinCount;
    swapinDelayUs += d.swapinDelayUs;
    memdelayUs += d.memdelayUs;

    io_read_bytes += d.io_read_bytes;
    io_write_bytes += d.io_write_bytes;
  }

  void aggregate(const ThreadSummaryStats& s) {
    activeThreads += s.activeThreads;
    exitedThreads += s.exitedThreads;
    schedThreads += s.schedThreads;

    utimeUs += s.utimeUs;
    stimeUs += s.stimeUs;
    etimeUs += s.etimeUs;
    utimeMaxUs = std::max(utimeMaxUs, s.utimeMaxUs);
    stimeMaxUs = std::max(stimeMaxUs, s.stimeMaxUs);
    cpuTimeMaxUs = std::max(cpuTimeMaxUs, s.cpuTimeMaxUs);

    hiwaterRssKb =
        hiwaterRssKb > s.hiwaterRssKb ? hiwaterRssKb : s.hiwaterRssKb;

    schedDelayUs += s.schedDelayUs;
    schedCount += s.schedCount;
    voluntaryCSW += s.voluntaryCSW;
    involuntaryCSW += s.involuntaryCSW;
    acMinflt += s.acMinflt;
    acMajflt += s.acMajflt;
    swapinCount += s.swapinCount;
    swapinDelayUs += s.swapinDelayUs;
    memdelayUs += s.memdelayUs;

    io_read_bytes += s.io_read_bytes;
    io_write_bytes += s.io_write_bytes;
  }
};

// counters maintained by ThreadMonitor
// calculated from aggregating thread-level data
struct ThreadAggCounters {
  uint64_t sumEtimeUs = 0;
  uint64_t countEtimeUs = 0;
  uint8_t maxThreadCpuUtil = 0;
  unsigned int swapinCount = 0;
  unsigned int swapinDelayUs = 0;
  unsigned int taskCount = 0;
  unsigned int taskActiveCount = 0;
  uint64_t majorFaultCount = 0;
  uint64_t minorFaultCount = 0;
  uint64_t voluntaryCSW = 0;
  uint64_t involuntaryCSW = 0;
  uint64_t cpuDelayUs = 0;
  uint64_t cpuRunRealUs = 0;

  void updateThreadAggCounters(const TaskStatsDelta& delta) {
    sumEtimeUs += delta.etimeUs;
    countEtimeUs++;

    float cpuUtil = 0.0;
    if (delta.etimeUs > 0) {
      auto util =
          100.0 * (delta.utimeUs + delta.stimeUs) / (delta.etimeUs * 1.0);
      // utime and stime may be rounded to the closest ms while etime remains
      // accurate, this could result in a cpu util above 100%, for now no clear
      // way to avoid this in the bfp probe so clamp down the value to 100%
      cpuUtil = (util > 100.0) ? 100.0 : util;
    }
    maxThreadCpuUtil = std::max(maxThreadCpuUtil, (uint8_t)cpuUtil);
    swapinCount += delta.swapinCount;
    swapinDelayUs += delta.swapinCount;
    majorFaultCount += delta.acMajflt;
    minorFaultCount += delta.acMinflt;
    voluntaryCSW += delta.voluntaryCSW;
    involuntaryCSW += delta.involuntaryCSW;
    cpuDelayUs += delta.cpuDelayUs;
    cpuRunRealUs += delta.cpuRunRealUs;
    taskCount++;
    if (delta.cpuCount) {
      taskActiveCount++;
    }
  }
};

} // namespace dynolog
