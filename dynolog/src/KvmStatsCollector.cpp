/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/KvmStatsCollector.h"

#include <sys/stat.h>
#include <fstream>

namespace dynolog {

KvmStats KvmStats::operator-(const KvmStats& prev) const {
  return KvmStats{
      // Core VM exit statistics (deltas)
      .exits = exits - prev.exits,
      .halt_exits = halt_exits - prev.halt_exits,
      .io_exits = io_exits - prev.io_exits,
      .mmio_exits = mmio_exits - prev.mmio_exits,
      .irq_exits = irq_exits - prev.irq_exits,
      .irq_window_exits = irq_window_exits - prev.irq_window_exits,
      .signal_exits = signal_exits - prev.signal_exits,

      // Emulation statistics (deltas)
      .insn_emulation = insn_emulation - prev.insn_emulation,
      .insn_emulation_fail = insn_emulation_fail - prev.insn_emulation_fail,
      .hypercalls = hypercalls - prev.hypercalls,

      // Halt polling statistics (deltas)
      .halt_wakeup = halt_wakeup - prev.halt_wakeup,
      .halt_successful_poll = halt_successful_poll - prev.halt_successful_poll,
      .halt_attempted_poll = halt_attempted_poll - prev.halt_attempted_poll,

      // MMU statistics (deltas)
      .mmu_cache_miss = mmu_cache_miss - prev.mmu_cache_miss,
      .mmu_flooded = mmu_flooded - prev.mmu_flooded,

      // TLB statistics (deltas)
      .remote_tlb_flush = remote_tlb_flush - prev.remote_tlb_flush,
      .tlb_flush = tlb_flush - prev.tlb_flush,

      // Page stats are gauges, not counters - delta doesn't make sense
      // but we include them for completeness (using current values)
      .pages_4k = pages_4k,
      .pages_2m = pages_2m,
      .pages_1g = pages_1g,
  };
}

KvmStatsCollector::KvmStatsCollector(const std::string& kvmPath)
    : kvmPath_(kvmPath) {
  // Check if KVM debugfs is available
  struct stat st;
  kvmAvailable_ = (stat(kvmPath_.c_str(), &st) == 0 && S_ISDIR(st.st_mode));
}

uint64_t KvmStatsCollector::readStatFile(const std::string& name) {
  std::string path = kvmPath_ + "/" + name;
  std::ifstream file(path);
  if (!file.is_open()) {
    return 0;
  }
  uint64_t value = 0;
  file >> value;
  return value;
}

bool KvmStatsCollector::readStats() {
  if (!kvmAvailable_) {
    return false;
  }

  prevStats_ = stats_;

  // Core VM exit statistics
  stats_.exits = readStatFile("exits");
  stats_.halt_exits = readStatFile("halt_exits");
  stats_.io_exits = readStatFile("io_exits");
  stats_.mmio_exits = readStatFile("mmio_exits");
  stats_.irq_exits = readStatFile("irq_exits");
  stats_.irq_window_exits = readStatFile("irq_window_exits");
  stats_.signal_exits = readStatFile("signal_exits");

  // Emulation statistics
  stats_.insn_emulation = readStatFile("insn_emulation");
  stats_.insn_emulation_fail = readStatFile("insn_emulation_fail");
  stats_.hypercalls = readStatFile("hypercalls");

  // Halt polling statistics
  stats_.halt_wakeup = readStatFile("halt_wakeup");
  stats_.halt_successful_poll = readStatFile("halt_successful_poll");
  stats_.halt_attempted_poll = readStatFile("halt_attempted_poll");

  // MMU statistics
  stats_.mmu_cache_miss = readStatFile("mmu_cache_miss");
  stats_.mmu_flooded = readStatFile("mmu_flooded");

  // TLB statistics
  stats_.remote_tlb_flush = readStatFile("remote_tlb_flush");
  stats_.tlb_flush = readStatFile("tlb_flush");

  // Page statistics (gauges)
  stats_.pages_4k = readStatFile("pages_4k");
  stats_.pages_2m = readStatFile("pages_2m");
  stats_.pages_1g = readStatFile("pages_1g");

  if (first_) {
    first_ = false;
    delta_ = KvmStats{};
  } else {
    delta_ = stats_ - prevStats_;
  }

  return true;
}

} // namespace dynolog
