// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <net/if.h>
#include <time.h>
#include <cstdint>

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

struct RxTx {
  uint64_t rxBytes, rxPackets;
  uint64_t rxErrors, rxDrops;
  uint64_t txBytes, txPackets;
  uint64_t txErrors, txDrops;

  RxTx operator-(const RxTx& prev) const {
    return RxTx{
        .rxBytes = rxBytes - prev.rxBytes,
        .rxPackets = rxPackets - prev.rxPackets,
        .rxErrors = rxErrors - prev.rxErrors,
        .rxDrops = rxDrops - prev.rxDrops,
        .txBytes = txBytes - prev.txBytes,
        .txPackets = txPackets - prev.txPackets,
        .txErrors = txErrors - prev.txErrors,
        .txDrops = txDrops - prev.txDrops,
    };
  }

  void operator+=(const RxTx& other) {
    rxBytes += other.rxBytes;
    rxPackets += other.rxPackets;
    rxErrors += other.rxErrors;
    rxDrops += other.rxDrops;
    txBytes += other.txBytes;
    txPackets += other.txPackets;
    txErrors += other.txErrors;
    txDrops += other.txDrops;
  }
};

} // namespace dynolog
