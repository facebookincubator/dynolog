/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <cstdint>
#include <functional>
#include <map>
#include <optional>
#include <string>
#include <vector>

#include "dynolog/src/EthtoolStatsReader.h"

namespace dynolog {

// Aggregate rx/tx byte and packet counters for one NIC.
struct NicCounters {
  uint64_t rxBytes{0};
  uint64_t rxPackets{0};
  uint64_t txBytes{0};
  uint64_t txPackets{0};
};

// Sums per-queue rx/tx bytes and packets from ethtool -S style stats. Only
// names of the form (rx|tx)(_q-|-)<N>(_|.)(bytes|pkts|packets) count, e.g.
// idpf "rx_q-0_pkts" and i40e/iavf "rx-0.packets"; port-level stats and
// per-queue sub-counters (idpf "rx-unicast_pkts", "tx_q-0_lso_pkts") do not.
// Returns nullopt unless rx/tx bytes and packets all matched, so a NIC with
// other naming (ice "rx_queue_0_packets", mlx5 "rx0_packets") is reported as
// unsupported rather than as zeros. An idle NIC returns zeros.
//
// Per-queue packets count what the host stack sees: on idpf, TX counts wire
// segments (TSO split), RX counts skbs (fewer than wire packets if HW GRO is
// on). Drops and errors are not included.
std::optional<NicCounters> sumPerQueueCounters(
    const std::vector<std::string>& names,
    const std::vector<uint64_t>& values);
std::optional<NicCounters> sumPerQueueCounters(
    const EthtoolStatsReader& reader);

// Driver name of a NIC via ETHTOOL_GDRVINFO, or nullopt on failure.
std::optional<std::string> getNicDriverName(const std::string& ifname);

// Some NIC drivers report broken netdev (/proc/net/dev) counters. On affected
// idpf NICs, packets read 0 or move in 2^32 steps and bytes move in 2^32 steps,
// while the ethtool per-queue counters are accurate.
//
// Decides per NIC whether to use the ethtool per-queue sums instead of the
// netdev counters. A NIC switches when its driver is known to be affected
// (idpf), or when it shows the firmware-bug signature (packets == 0 while
// bytes > 0, in either direction). The decision is sticky: the signature alone
// is not stable, because the broken packet counters can move off 0 later,
// which would silently flip the NIC back to the broken counters.
class NicCounterSourceSelector {
 public:
  enum class Reason { kNone, kDriver, kSignature };

  struct Decision {
    bool useEthtool{false};
    // Set only on the call that switched the NIC, so callers can log once.
    Reason switchedBecause{Reason::kNone};
  };

  using DriverLookup =
      std::function<std::optional<std::string>(const std::string&)>;

  // Uses getNicDriverName().
  NicCounterSourceSelector();
  // An empty driverLookup falls back to getNicDriverName().
  explicit NicCounterSourceSelector(DriverLookup driverLookup);

  Decision decide(const std::string& ifname, const NicCounters& netdev);
  // Called when ethtool per-queue counters can't be used for a NIC (no
  // matching names). The NIC stays on netdev counters from then on.
  void markUnsupported(const std::string& ifname);
  [[nodiscard]] bool usesEthtool(const std::string& ifname) const;
  // Drops all state for a NIC, e.g. one that no longer exists.
  void forget(const std::string& ifname);

  static bool hasFirmwareBugSignature(const NicCounters& netdev);
  static const char* reasonName(Reason reason);

 private:
  // Driver lookups are retried a few times (e.g. a NIC still coming up), then
  // given up on: some interfaces never answer ETHTOOL_GDRVINFO, and callers
  // may sample every second.
  static constexpr int kMaxDriverLookupAttempts = 3;

  struct NicState {
    int driverLookupAttempts{0};
    bool driverChecked{false};
    bool useEthtool{false};
    bool unsupported{false};
  };

  DriverLookup driverLookup_;
  std::map<std::string, NicState> state_;
};

// The per-NIC counters to publish for NICs with broken netdev counters. Owns
// the NicCounterSourceSelector decision, an EthtoolStatsReader per NIC, and the
// policy for read failures, so that every agent handles them the same way:
//
// - The published ethtool counters never go backwards. Drivers zero their
//   per-queue counters when queues are reallocated (on idpf: ifdown/up, MTU,
//   ethtool -L/-G, any vport reset), and when the vport is down they read as
//   zero; a counter that goes backwards is folded into a per-counter offset.
// - A failed read reports the last published counters (a zero delta, with the
//   traffic accounted for on the next good read) instead of falling back to
//   the broken netdev counters. The reader is re-initialized right away if the
//   driver's stat layout changed, else after kMaxConsecutiveFailures. Failed
//   inits and re-created readers are retried with exponential backoff (up to
//   kMaxRetryBackoff samples between attempts), never given up on.
// - Only a NIC whose ethtool stats were read but have no recognizable
//   per-queue counters is marked unsupported and stays on netdev counters.
class NicCounterSource {
 public:
  using ReaderFactory = std::function<EthtoolStatsReader()>;

  struct Sample {
    // The counters to publish instead of the netdev ones; nullopt to keep the
    // netdev counters.
    std::optional<NicCounters> counters;
    // The source (netdev or ethtool) differs from the previous sample of this
    // NIC, or this is the first ethtool sample since construction or reset().
    // Counters on either side of the change aren't comparable, so the caller
    // must re-baseline any deltas it computes.
    bool sourceChanged{false};
  };

  // Uses the real driver lookup and ethtool ioctls.
  NicCounterSource();
  // For tests; an empty readerFactory creates default readers.
  NicCounterSource(NicCounterSourceSelector selector, ReaderFactory factory);

  Sample sample(const std::string& ifname, const NicCounters& netdev);

  // Drops the state of every NIC not sampled since the previous prune(), so
  // that interfaces which come and go (veth, tap) don't accumulate. Call once
  // per collection round, after sampling every NIC.
  void prune();

  // Closes all readers and forgets all published counters, e.g. when the
  // fallback is disabled. Returns the NICs that were on ethtool counters, which
  // the caller must re-baseline onto the netdev counters. Per-NIC decisions
  // are kept, so re-enabling resumes with the same NICs on ethtool.
  std::vector<std::string> reset();

  [[nodiscard]] bool usesEthtool(const std::string& ifname) const;

  // Consecutive failed reads after which the reader is re-initialized.
  static constexpr int kMaxConsecutiveFailures = 10;
  // Most samples skipped between retries of a failing reader.
  static constexpr int kMaxRetryBackoff = 32;

 private:
  enum class Read { kOk, kFailed, kUnsupported };

  struct NicState {
    std::optional<EthtoolStatsReader> reader;
    int consecutiveFailures{0};
    // Samples to skip before the next attempt, and the next backoff.
    int skipSamples{0};
    int retryBackoff{1};
    // Raw per-queue sums from the last good read.
    std::optional<NicCounters> lastRaw;
    // Added to the raw sums to keep the published counters monotonic.
    NicCounters offset;
    std::optional<NicCounters> published;
    // Whether the previous sample returned ethtool counters.
    bool usedEthtool{false};
    bool sampledSincePrune{false};

    // Drops the reader and the published counters.
    void clearEthtool() {
      reader.reset();
      consecutiveFailures = 0;
      skipSamples = 0;
      retryBackoff = 1;
      lastRaw.reset();
      offset = {};
      published.reset();
    }
  };

  Read read(const std::string& ifname, NicState& st, NicCounters& raw);
  // Creates and initializes st.reader if needed; false on failure.
  bool ensureReader(const std::string& ifname, NicState& st);
  static void backOff(NicState& st);

  NicCounterSourceSelector selector_;
  ReaderFactory readerFactory_;
  std::map<std::string, NicState> nics_;
};

} // namespace dynolog
