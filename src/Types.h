// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <time.h>

#define MAX_CPU_SOCKETS 8

namespace dynolog {

// Ensure consistent 'ticks' handling
using TIC_t = unsigned long long;

// This structure stores a frame's cpu tics used in history
// calculations.  It exists primarily for SMP support but serves
// all environments.
struct CpuTime {
  TIC_t u = 0, n = 0, s = 0, i = 0, w = 0, x = 0, y = 0,
        z = 0; // as represented in /proc/stat
  /*
   * u - user: normal processes executing in user mode
   * n - nice: niced processes executing in user mode
   * s - system: processes executing in kernel mode
   * i - idle: twiddling thumbs
   * w - iowait: waiting for I/O to complete
   * x - irq: servicing interrupts
   * y - softirq: servicing softirqs
   * z - unused?
   */

  CpuTime operator-(const CpuTime& prev) const {
    return CpuTime{
        .u = u - prev.u,
        .n = n - prev.n,
        .s = s - prev.s,
        .i = i - prev.i,
        .w = w - prev.w,
        .x = x - prev.x,
        .y = y - prev.y,
        .z = z - prev.z,
    };
  }

  void operator+=(const CpuTime& other) {
    u += other.u;
    n += other.n;
    s += other.s;
    i += other.i;
    w += other.w;
    x += other.x;
    y += other.y;
    z += other.z;
  }

  TIC_t total() const {
    return u + n + s + i + w + x + y + z;
  }
};

} // namespace dynolog
