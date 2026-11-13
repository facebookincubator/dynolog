/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/NicCounters.h"

#include <glog/logging.h>
#include <linux/ethtool.h>
#include <linux/sockios.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <algorithm>
#include <array>
#include <cstring>
#include <string_view>
#include <utility>

namespace dynolog {

namespace {

// Drivers whose netdev counters are known to be broken.
constexpr std::array<std::string_view, 1> kBrokenNetdevCounterDrivers = {
    "idpf"};

enum class QueueCounter { kNone, kRxBytes, kRxPackets, kTxBytes, kTxPackets };

// Accepts exactly (rx|tx)(_q-|-)<digits>(_|.)(bytes|pkts|packets), e.g. idpf
// "rx_q-0_pkts" and i40e/iavf "rx-0.packets". Everything else is rejected,
// notably idpf port-level stats ("rx-unicast_pkts", which sum to the broken
// netdev rx_packets) and per-queue sub-counters ("tx_q-0_lso_pkts",
// "rx_q-0_rx_gro_hw_pkts").
QueueCounter classify(std::string_view name) {
  bool isRx = name.starts_with("rx");
  if (!isRx && !name.starts_with("tx")) {
    return QueueCounter::kNone;
  }
  name.remove_prefix(2);
  if (name.starts_with("_q-")) {
    name.remove_prefix(3);
  } else if (name.starts_with("-")) {
    name.remove_prefix(1);
  } else {
    return QueueCounter::kNone;
  }
  size_t digits = 0;
  while (digits < name.size() && name[digits] >= '0' && name[digits] <= '9') {
    digits++;
  }
  if (digits == 0 || digits == name.size()) {
    return QueueCounter::kNone;
  }
  name.remove_prefix(digits);
  if (name.front() != '_' && name.front() != '.') {
    return QueueCounter::kNone;
  }
  name.remove_prefix(1);
  if (name == "bytes") {
    return isRx ? QueueCounter::kRxBytes : QueueCounter::kTxBytes;
  }
  if (name == "pkts" || name == "packets") {
    return isRx ? QueueCounter::kRxPackets : QueueCounter::kTxPackets;
  }
  return QueueCounter::kNone;
}

// Accumulates per-queue counters and tracks which of the four kinds matched.
struct QueueSums {
  NicCounters sums;
  bool rxBytes{false};
  bool rxPackets{false};
  bool txBytes{false};
  bool txPackets{false};

  void add(std::string_view name, uint64_t value) {
    switch (classify(name)) {
      case QueueCounter::kRxBytes:
        sums.rxBytes += value;
        rxBytes = true;
        break;
      case QueueCounter::kRxPackets:
        sums.rxPackets += value;
        rxPackets = true;
        break;
      case QueueCounter::kTxBytes:
        sums.txBytes += value;
        txBytes = true;
        break;
      case QueueCounter::kTxPackets:
        sums.txPackets += value;
        txPackets = true;
        break;
      case QueueCounter::kNone:
        break;
    }
  }

  // Partial matches would overwrite valid netdev counters with zeros.
  std::optional<NicCounters> result() const {
    if (rxBytes && rxPackets && txBytes && txPackets) {
      return sums;
    }
    return std::nullopt;
  }
};

NicCounters operator+(const NicCounters& a, const NicCounters& b) {
  NicCounters r;
  r.rxBytes = a.rxBytes + b.rxBytes;
  r.rxPackets = a.rxPackets + b.rxPackets;
  r.txBytes = a.txBytes + b.txBytes;
  r.txPackets = a.txPackets + b.txPackets;
  return r;
}

// Folds a counter that went backwards (driver reset) into its offset. Per
// counter, so a reset that only hits some counters (e.g. only RX queues
// reallocated) doesn't push the others forward by their whole history. Returns
// true if any counter went backwards.
bool foldResets(
    NicCounters& offset,
    const NicCounters& prev,
    const NicCounters& cur) {
  bool reset = false;
  auto fold = [&reset](uint64_t& off, uint64_t p, uint64_t c) {
    if (c < p) {
      off += p;
      reset = true;
    }
  };
  fold(offset.rxBytes, prev.rxBytes, cur.rxBytes);
  fold(offset.rxPackets, prev.rxPackets, cur.rxPackets);
  fold(offset.txBytes, prev.txBytes, cur.txBytes);
  fold(offset.txPackets, prev.txPackets, cur.txPackets);
  return reset;
}

} // namespace

std::optional<NicCounters> sumPerQueueCounters(
    const std::vector<std::string>& names,
    const std::vector<uint64_t>& values) {
  QueueSums q;
  for (size_t i = 0; i < names.size() && i < values.size(); i++) {
    q.add(names[i], values[i]);
  }
  return q.result();
}

std::optional<NicCounters> sumPerQueueCounters(
    const EthtoolStatsReader& reader) {
  QueueSums q;
  for (size_t i = 0; i < reader.size(); i++) {
    q.add(reader.name(i), reader.value(i));
  }
  return q.result();
}

std::optional<std::string> getNicDriverName(const std::string& ifname) {
  struct ifreq ifr{};
  if (ifname.size() >= sizeof(ifr.ifr_name)) {
    return std::nullopt;
  }
  int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
  if (fd < 0) {
    return std::nullopt;
  }
  memcpy(ifr.ifr_name, ifname.data(), ifname.size());

  struct ethtool_drvinfo drvinfo{};
  drvinfo.cmd = ETHTOOL_GDRVINFO;
  ifr.ifr_data = reinterpret_cast<char*>(&drvinfo);
  int rc = ioctl(fd, SIOCETHTOOL, &ifr);
  close(fd);
  if (rc != 0) {
    return std::nullopt;
  }
  return std::string(
      drvinfo.driver, strnlen(drvinfo.driver, sizeof(drvinfo.driver)));
}

NicCounterSourceSelector::NicCounterSourceSelector()
    : NicCounterSourceSelector(getNicDriverName) {}

NicCounterSourceSelector::NicCounterSourceSelector(DriverLookup driverLookup)
    : driverLookup_(
          driverLookup ? std::move(driverLookup)
                       : DriverLookup(getNicDriverName)) {}

bool NicCounterSourceSelector::hasFirmwareBugSignature(
    const NicCounters& netdev) {
  return (netdev.rxPackets == 0 && netdev.rxBytes > 0) ||
      (netdev.txPackets == 0 && netdev.txBytes > 0);
}

const char* NicCounterSourceSelector::reasonName(Reason reason) {
  switch (reason) {
    case Reason::kDriver:
      return "driver";
    case Reason::kSignature:
      return "firmware-bug signature";
    case Reason::kNone:
      return "none";
  }
  return "none";
}

NicCounterSourceSelector::Decision NicCounterSourceSelector::decide(
    const std::string& ifname,
    const NicCounters& netdev) {
  auto& st = state_[ifname];
  if (st.unsupported) {
    return {false, Reason::kNone};
  }
  if (st.useEthtool) {
    return {true, Reason::kNone};
  }
  if (!st.driverChecked) {
    auto driver = driverLookup_(ifname);
    st.driverChecked = driver.has_value() ||
        ++st.driverLookupAttempts >= kMaxDriverLookupAttempts;
    if (driver) {
      for (auto broken : kBrokenNetdevCounterDrivers) {
        if (*driver == broken) {
          st.useEthtool = true;
          return {true, Reason::kDriver};
        }
      }
    }
  }
  if (hasFirmwareBugSignature(netdev)) {
    st.useEthtool = true;
    return {true, Reason::kSignature};
  }
  return {false, Reason::kNone};
}

void NicCounterSourceSelector::markUnsupported(const std::string& ifname) {
  auto& st = state_[ifname];
  st.unsupported = true;
  st.useEthtool = false;
}

bool NicCounterSourceSelector::usesEthtool(const std::string& ifname) const {
  auto it = state_.find(ifname);
  return it != state_.end() && it->second.useEthtool;
}

void NicCounterSourceSelector::forget(const std::string& ifname) {
  state_.erase(ifname);
}

NicCounterSource::NicCounterSource() : NicCounterSource({}, {}) {}

NicCounterSource::NicCounterSource(
    NicCounterSourceSelector selector,
    ReaderFactory factory)
    : selector_(std::move(selector)), readerFactory_(std::move(factory)) {}

bool NicCounterSource::ensureReader(const std::string& ifname, NicState& st) {
  if (st.reader) {
    return true;
  }
  st.reader.emplace(readerFactory_ ? readerFactory_() : EthtoolStatsReader());
  if (!st.reader->init(ifname)) {
    st.reader.reset();
    return false;
  }
  return true;
}

void NicCounterSource::backOff(NicState& st) {
  st.skipSamples = st.retryBackoff;
  st.retryBackoff = std::min(2 * st.retryBackoff, kMaxRetryBackoff);
}

NicCounterSource::Read NicCounterSource::read(
    const std::string& ifname,
    NicState& st,
    NicCounters& raw) {
  if (st.skipSamples > 0) {
    st.skipSamples--;
    return Read::kFailed;
  }
  bool ok = ensureReader(ifname, st) && st.reader->sample();
  if (!ok && st.reader && st.reader->needsReinit()) {
    // The stat layout changed (e.g. driver reload): re-read it right away.
    st.reader.reset();
    ok = ensureReader(ifname, st) && st.reader->sample();
  }
  if (!ok) {
    // Failures are treated as transient and retried with backoff, never as a
    // reason to give up on the NIC: a broken NIC must not be pinned to its
    // broken netdev counters by an outage.
    if (!st.reader) {
      backOff(st); // init failed
    } else if (++st.consecutiveFailures >= kMaxConsecutiveFailures) {
      st.reader.reset();
      st.consecutiveFailures = 0;
      backOff(st);
    }
    return Read::kFailed;
  }
  st.consecutiveFailures = 0;
  st.retryBackoff = 1;
  auto sums = sumPerQueueCounters(*st.reader);
  if (!sums) {
    return Read::kUnsupported;
  }
  raw = *sums;
  return Read::kOk;
}

NicCounterSource::Sample NicCounterSource::sample(
    const std::string& ifname,
    const NicCounters& netdev) {
  auto& st = nics_[ifname];
  st.sampledSincePrune = true;

  auto decision = selector_.decide(ifname, netdev);
  if (decision.switchedBecause != NicCounterSourceSelector::Reason::kNone) {
    LOG(WARNING) << "Using ethtool per-queue counters for NIC " << ifname
                 << " ("
                 << NicCounterSourceSelector::reasonName(
                        decision.switchedBecause)
                 << ")";
  }

  Sample out;
  if (decision.useEthtool) {
    NicCounters raw;
    switch (read(ifname, st, raw)) {
      case Read::kOk:
        // The driver zeroed its queue counters: carry on from where the
        // published counters were.
        if (st.lastRaw && foldResets(st.offset, *st.lastRaw, raw)) {
          LOG(INFO) << "Ethtool per-queue counters for NIC " << ifname
                    << " were reset";
        }
        st.lastRaw = raw;
        st.published = st.offset + raw;
        out.counters = st.published;
        break;
      case Read::kFailed:
        LOG_EVERY_N(WARNING, 100)
            << "Reading ethtool per-queue counters failed for NIC " << ifname;
        out.counters = st.published;
        break;
      case Read::kUnsupported:
        LOG(WARNING) << "No usable per-queue ethtool counters for NIC "
                     << ifname << ", staying on netdev counters";
        selector_.markUnsupported(ifname);
        st.clearEthtool();
        break;
    }
  }

  bool usedEthtool = out.counters.has_value();
  out.sourceChanged = usedEthtool != st.usedEthtool;
  st.usedEthtool = usedEthtool;
  return out;
}

void NicCounterSource::prune() {
  for (auto it = nics_.begin(); it != nics_.end();) {
    if (it->second.sampledSincePrune) {
      it->second.sampledSincePrune = false;
      ++it;
    } else {
      selector_.forget(it->first);
      it = nics_.erase(it);
    }
  }
}

std::vector<std::string> NicCounterSource::reset() {
  std::vector<std::string> wasOnEthtool;
  for (auto& [ifname, st] : nics_) {
    if (st.usedEthtool) {
      wasOnEthtool.push_back(ifname);
    }
    // Entries stay, so that prune() still forgets NICs that go away.
    st.clearEthtool();
    st.usedEthtool = false;
  }
  return wasOnEthtool;
}

bool NicCounterSource::usesEthtool(const std::string& ifname) const {
  auto it = nics_.find(ifname);
  return it != nics_.end() && it->second.usedEthtool;
}

} // namespace dynolog
