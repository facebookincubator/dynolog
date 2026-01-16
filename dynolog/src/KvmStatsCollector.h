/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <cstdint>
#include <string>

namespace dynolog {

/**
 * KvmStats: Structure to hold KVM statistics from /sys/kernel/debug/kvm
 *
 * These are the key virtualization metrics for monitoring KVM hypervisor
 * overhead and behavior. Each field maps to a file in /sys/kernel/debug/kvm.
 *
 * Selected metrics rationale:
 * - exits: Total VM exits - THE primary indicator of virtualization overhead
 * - halt_exits: VM idle time exits (guest has nothing to do)
 * - io_exits, mmio_exits: I/O causing VM exits (disk/network activity)
 * - irq_exits, irq_window_exits: Interrupt handling overhead
 * - signal_exits: Signal delivery to guest
 * - insn_emulation, insn_emulation_fail: Instruction emulation (expensive)
 * - hypercalls: Guest-to-hypervisor calls
 * - halt_wakeup, halt_successful_poll, halt_attempted_poll: Halt polling
 *   efficiency (ratio of successful/attempted indicates tuning quality)
 * - mmu_cache_miss, mmu_flooded: Memory management unit overhead
 * - remote_tlb_flush, tlb_flush: TLB invalidation overhead
 * - pages_4k, pages_2m, pages_1g: Memory page size distribution (gauges)
 */
struct KvmStats {
  // Core VM exit statistics (deltas)
  uint64_t exits = 0;
  uint64_t halt_exits = 0;
  uint64_t io_exits = 0;
  uint64_t mmio_exits = 0;
  uint64_t irq_exits = 0;
  uint64_t irq_window_exits = 0;
  uint64_t signal_exits = 0;

  // Emulation statistics (deltas)
  uint64_t insn_emulation = 0;
  uint64_t insn_emulation_fail = 0;
  uint64_t hypercalls = 0;

  // Halt polling statistics (deltas)
  uint64_t halt_wakeup = 0;
  uint64_t halt_successful_poll = 0;
  uint64_t halt_attempted_poll = 0;

  // MMU statistics (deltas)
  uint64_t mmu_cache_miss = 0;
  uint64_t mmu_flooded = 0;

  // TLB statistics (deltas)
  uint64_t remote_tlb_flush = 0;
  uint64_t tlb_flush = 0;

  // Page statistics (gauges - current values, not deltas)
  uint64_t pages_4k = 0;
  uint64_t pages_2m = 0;
  uint64_t pages_1g = 0;

  // Operator overloads for delta calculation
  KvmStats operator-(const KvmStats& prev) const;
};

/**
 * KvmStatsCollector: Collects KVM statistics from /sys/kernel/debug/kvm
 *
 * Usage:
 *   KvmStatsCollector collector;
 *   collector.readStats();
 *   const auto& stats = collector.getStats();
 *   const auto& delta = collector.getDelta();
 */
class KvmStatsCollector {
 public:
  explicit KvmStatsCollector(
      const std::string& kvmPath = "/sys/kernel/debug/kvm");

  // Read current stats from /sys/kernel/debug/kvm
  // Returns true if KVM is available and stats were read successfully
  bool readStats();

  // Check if KVM is available on this system
  bool isKvmAvailable() const {
    return kvmAvailable_;
  }

  // Get current stats
  const KvmStats& getStats() const {
    return stats_;
  }

  // Get delta from previous reading
  const KvmStats& getDelta() const {
    return delta_;
  }

 protected:
  std::string kvmPath_;
  bool kvmAvailable_ = false;
  bool first_ = true;
  KvmStats stats_;
  KvmStats prevStats_;
  KvmStats delta_;

  // Read a single stat file
  uint64_t readStatFile(const std::string& name);
};

} // namespace dynolog
