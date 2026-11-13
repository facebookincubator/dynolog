/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <gtest/gtest.h>

#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "dynolog/src/NicCounters.h"
#include "dynolog/tests/FakeEthtoolIoctl.h"

namespace dynolog {

namespace {

NicCounters makeCounters(
    uint64_t rxBytes,
    uint64_t rxPackets,
    uint64_t txBytes,
    uint64_t txPackets) {
  NicCounters c;
  c.rxBytes = rxBytes;
  c.rxPackets = rxPackets;
  c.txBytes = txBytes;
  c.txPackets = txPackets;
  return c;
}

using Reason = NicCounterSourceSelector::Reason;

struct DriverStub {
  std::optional<std::string> driver;
  int lookups = 0;

  NicCounterSourceSelector selector() {
    return NicCounterSourceSelector([this](const std::string&) {
      lookups++;
      return driver;
    });
  }
};

} // namespace

TEST(SumPerQueueCountersTest, Idpf) {
  auto sums = sumPerQueueCounters(
      {"rx_q-0_pkts",
       "rx_q-0_bytes",
       "rx_q-1_pkts",
       "rx_q-1_bytes",
       "tx_q-0_pkts",
       "tx_q-0_bytes",
       "rx-hsplit",
       "tx_q-0_lso_pkts"},
      {1, 100, 2, 200, 3, 300, 7, 9});
  ASSERT_TRUE(sums.has_value());
  EXPECT_EQ(sums->rxPackets, 3);
  EXPECT_EQ(sums->rxBytes, 300);
  EXPECT_EQ(sums->txPackets, 3);
  EXPECT_EQ(sums->txBytes, 300);
}

TEST(SumPerQueueCountersTest, FullIdpfNameList) {
  // Port-level stats and per-queue sub-counters as exported by idpf
  // (idpf_ethtool.c); none of them may be counted. rx-*_pkts sum to the
  // broken netdev rx_packets.
  std::vector<std::string> names = {
      "rx-csum_errors",     "rx-hsplit",         "rx-hsplit_hbo",
      "rx-bad_descs",       "tx-skb_drops",      "tx-dma_map_errs",
      "tx-linearized_pkts", "tx-busy_events",    "rx-unicast_pkts",
      "rx-multicast_pkts",  "rx-broadcast_pkts", "rx-unknown_protocol",
      "tx-unicast_pkts",    "tx-multicast_pkts", "tx-broadcast_pkts",
      "tx_q-0_pkts",        "tx_q-0_bytes",      "tx_q-0_lso_pkts",
      "tx_q-1_pkts",        "tx_q-1_bytes",      "tx_q-1_lso_pkts",
      "rx_q-0_pkts",        "rx_q-0_bytes",      "rx_q-0_rx_gro_hw_pkts",
      "rx_q-1_pkts",        "rx_q-1_bytes",      "rx_q-1_rx_gro_hw_pkts"};
  constexpr uint64_t kBroken = 1ULL << 36;
  std::vector<uint64_t> values = {
      7,
      7,
      7,
      7,
      7,
      7,
      1000,
      7,
      kBroken,
      kBroken,
      kBroken,
      7,
      kBroken,
      kBroken,
      kBroken,
      // tx_q-0, tx_q-1
      10,
      1000,
      99,
      20,
      2000,
      99,
      // rx_q-0, rx_q-1
      30,
      3000,
      99,
      40,
      4000,
      99};
  auto sums = sumPerQueueCounters(names, values);
  ASSERT_TRUE(sums.has_value());
  EXPECT_EQ(sums->txPackets, 30);
  EXPECT_EQ(sums->txBytes, 3000);
  EXPECT_EQ(sums->rxPackets, 70);
  EXPECT_EQ(sums->rxBytes, 7000);
}

TEST(SumPerQueueCountersTest, I40eDottedNames) {
  auto sums = sumPerQueueCounters(
      {"rx-0.packets", "rx-0.bytes", "tx-0.packets", "tx-0.bytes"},
      {1, 10, 2, 20});
  ASSERT_TRUE(sums.has_value());
  EXPECT_EQ(sums->rxPackets, 1);
  EXPECT_EQ(sums->rxBytes, 10);
  EXPECT_EQ(sums->txPackets, 2);
  EXPECT_EQ(sums->txBytes, 20);
}

TEST(SumPerQueueCountersTest, IdleNicReturnsZerosNotNullopt) {
  auto sums = sumPerQueueCounters(
      {"rx_q-0_pkts", "rx_q-0_bytes", "tx_q-0_pkts", "tx_q-0_bytes"},
      {0, 0, 0, 0});
  ASSERT_TRUE(sums.has_value());
  EXPECT_EQ(sums->rxPackets, 0);
  EXPECT_EQ(sums->txBytes, 0);
}

TEST(SumPerQueueCountersTest, UnsupportedNamingIsNullopt) {
  // ice and mlx5 per-queue names are not recognized.
  EXPECT_FALSE(sumPerQueueCounters(
                   {"rx_queue_0_packets",
                    "rx_queue_0_bytes",
                    "tx_queue_0_packets",
                    "tx_queue_0_bytes"},
                   {1, 2, 3, 4})
                   .has_value());
  EXPECT_FALSE(sumPerQueueCounters(
                   {"rx0_packets", "rx0_bytes", "tx0_packets", "tx0_bytes"},
                   {1, 2, 3, 4})
                   .has_value());
}

TEST(SumPerQueueCountersTest, PartialMatchIsNullopt) {
  // Only rx matched: tx zeros must not overwrite valid netdev tx counters.
  EXPECT_FALSE(
      sumPerQueueCounters({"rx_q-0_pkts", "rx_q-0_bytes"}, {1, 2}).has_value());
}

TEST(SumPerQueueCountersTest, NoMatchingNames) {
  EXPECT_FALSE(
      sumPerQueueCounters({"rx_crc_errors", "tx_timeout"}, {1, 2}).has_value());
}

TEST(SumPerQueueCountersTest, NearMissesAreNotSummed) {
  // Each near miss of the grammar, next to a valid queue pair, must leave the
  // sums alone.
  for (const char* nearMiss :
       {"rx_q-0_bytes_old",
        "rx_q-_pkts",
        "rx_q-0",
        "rxq-0_pkts",
        "rx_q-0_lso_pkts",
        "rx-0.bytes.x",
        "rx-unicast_pkts",
        "tx-0_bytes_"}) {
    auto sums = sumPerQueueCounters(
        {"rx_q-0_pkts",
         "rx_q-0_bytes",
         "tx_q-0_pkts",
         "tx_q-0_bytes",
         nearMiss},
        {1, 2, 3, 4, 1ULL << 40});
    ASSERT_TRUE(sums.has_value()) << nearMiss;
    EXPECT_EQ(sums->rxPackets, 1) << nearMiss;
    EXPECT_EQ(sums->rxBytes, 2) << nearMiss;
    EXPECT_EQ(sums->txPackets, 3) << nearMiss;
    EXPECT_EQ(sums->txBytes, 4) << nearMiss;
  }
}

TEST(NicCounterSourceSelectorTest, FirmwareBugSignature) {
  using S = NicCounterSourceSelector;
  EXPECT_TRUE(S::hasFirmwareBugSignature(makeCounters(1, 0, 0, 0)));
  // TX only: rx_packets has moved off zero, tx_packets is still 0.
  EXPECT_TRUE(
      S::hasFirmwareBugSignature(
          makeCounters(1ULL << 32, 1ULL << 36, 1ULL << 33, 0)));
  EXPECT_FALSE(S::hasFirmwareBugSignature(makeCounters(0, 0, 0, 0)));
  EXPECT_FALSE(S::hasFirmwareBugSignature(makeCounters(10, 1, 20, 2)));
}

TEST(NicCounterSourceSelectorTest, TxOnlySignatureSwitches) {
  DriverStub d{"some_other_driver"};
  auto selector = d.selector();
  auto decision = selector.decide(
      "eth0", makeCounters(1ULL << 32, 1ULL << 36, 1ULL << 33, 0));
  EXPECT_TRUE(decision.useEthtool);
  EXPECT_EQ(decision.switchedBecause, Reason::kSignature);
}

TEST(NicCounterSourceSelectorTest, IdpfDriverWithoutSignature) {
  DriverStub d{"idpf"};
  auto selector = d.selector();
  // Non-zero rx_packets: no firmware-bug signature.
  auto decision =
      selector.decide("eth0", makeCounters(1ULL << 32, 1ULL << 36, 0, 0));
  EXPECT_TRUE(decision.useEthtool);
  EXPECT_EQ(decision.switchedBecause, Reason::kDriver);
  EXPECT_TRUE(selector.usesEthtool("eth0"));
}

TEST(NicCounterSourceSelectorTest, SignatureSwitchIsSticky) {
  DriverStub d{"some_other_driver"};
  auto selector = d.selector();

  auto first =
      selector.decide("eth0", makeCounters(1ULL << 32, 0, 1ULL << 33, 0));
  EXPECT_TRUE(first.useEthtool);
  EXPECT_EQ(first.switchedBecause, Reason::kSignature);

  // netdev rx_packets moves off zero: stay on ethtool, and don't report a new
  // switch.
  auto second = selector.decide(
      "eth0", makeCounters(1ULL << 32, 1ULL << 36, 1ULL << 33, 1ULL << 32));
  EXPECT_TRUE(second.useEthtool);
  EXPECT_EQ(second.switchedBecause, Reason::kNone);
}

TEST(NicCounterSourceSelectorTest, SignatureInOneDirection) {
  DriverStub d{"some_other_driver"};
  auto selector = d.selector();
  // tx looks healthy, rx shows the signature.
  auto decision = selector.decide("eth0", makeCounters(1000, 0, 2000, 20));
  EXPECT_TRUE(decision.useEthtool);
  EXPECT_EQ(decision.switchedBecause, Reason::kSignature);
}

TEST(NicCounterSourceSelectorTest, HealthyNicStaysOnNetdev) {
  DriverStub d{"mlx5_core"};
  auto selector = d.selector();
  for (int i = 0; i < 3; i++) {
    auto decision = selector.decide("eth2", makeCounters(5000, 50, 6000, 60));
    EXPECT_FALSE(decision.useEthtool);
  }
  EXPECT_FALSE(selector.usesEthtool("eth2"));
  // Driver looked up once, then cached.
  EXPECT_EQ(d.lookups, 1);
}

TEST(NicCounterSourceSelectorTest, IdleNicIsNotSignature) {
  DriverStub d{"mlx5_core"};
  auto selector = d.selector();
  EXPECT_FALSE(selector.decide("eth2", makeCounters(0, 0, 0, 0)).useEthtool);
}

TEST(NicCounterSourceSelectorTest, DriverLookupRetriedWhenUnknown) {
  DriverStub d{std::nullopt};
  auto selector = d.selector();
  EXPECT_FALSE(
      selector.decide("eth0", makeCounters(5000, 50, 6000, 60)).useEthtool);

  d.driver = "idpf";
  auto decision = selector.decide("eth0", makeCounters(5000, 50, 6000, 60));
  EXPECT_TRUE(decision.useEthtool);
  EXPECT_EQ(decision.switchedBecause, Reason::kDriver);
  EXPECT_EQ(d.lookups, 2);
}

TEST(NicCounterSourceSelectorTest, DriverLookupGivesUpAfterRetries) {
  DriverStub d{std::nullopt};
  auto selector = d.selector();
  for (int i = 0; i < 10; i++) {
    selector.decide("lo", makeCounters(5000, 50, 6000, 60));
  }
  EXPECT_EQ(d.lookups, 3);
  // The signature still switches the NIC after giving up on the driver.
  EXPECT_TRUE(
      selector.decide("lo", makeCounters(5000, 0, 6000, 60)).useEthtool);
}

TEST(NicCounterSourceSelectorTest, MarkUnsupportedStaysOnNetdev) {
  DriverStub d{"idpf"};
  auto selector = d.selector();
  EXPECT_TRUE(selector.decide("eth0", makeCounters(1000, 0, 0, 0)).useEthtool);
  selector.markUnsupported("eth0");
  EXPECT_FALSE(selector.usesEthtool("eth0"));
  EXPECT_FALSE(
      selector.decide("eth0", makeCounters(1000, 0, 2000, 0)).useEthtool);
}

TEST(NicCounterSourceSelectorTest, PerNicState) {
  DriverStub d{"mlx5_core"};
  auto selector = d.selector();
  EXPECT_TRUE(selector.decide("eth0", makeCounters(1000, 0, 0, 0)).useEthtool);
  EXPECT_FALSE(
      selector.decide("eth1", makeCounters(1000, 10, 0, 0)).useEthtool);
  EXPECT_TRUE(selector.usesEthtool("eth0"));
  EXPECT_FALSE(selector.usesEthtool("eth1"));
}

namespace {

// One NIC behind a NicCounterSource with a stubbed driver and fake ioctls.
// Per-queue sums of idpfNic(): rx 10 pkts / 1000 bytes, tx 20 pkts / 2000.
struct SourceFixture {
  DriverStub driver{"idpf"};
  fakes::FakeEthtoolNic nic = idpfNic();
  int readersCreated = 0;

  static fakes::FakeEthtoolNic idpfNic() {
    return fakes::FakeEthtoolNic{
        {"rx-unicast_pkts",
         "rx_q-0_pkts",
         "rx_q-0_bytes",
         "tx_q-0_pkts",
         "tx_q-0_bytes",
         "tx_q-0_lso_pkts"},
        {1ULL << 36, 10, 1000, 20, 2000, 7}};
  }

  NicCounterSource make() {
    return NicCounterSource(driver.selector(), [this]() {
      readersCreated++;
      return EthtoolStatsReader(
          std::make_unique<fakes::FakeEthtoolIoctl>(&nic));
    });
  }

  void setQueueCounters(
      uint64_t rxPackets,
      uint64_t rxBytes,
      uint64_t txPackets,
      uint64_t txBytes) {
    nic.values[1] = rxPackets;
    nic.values[2] = rxBytes;
    nic.values[3] = txPackets;
    nic.values[4] = txBytes;
  }
};

// Broken idpf netdev counters: rx_packets off zero in 2^32 steps, tx_packets 0.
const NicCounters kBrokenNetdev = makeCounters(1ULL << 32, 1ULL << 36, 0, 0);

void expectCounters(
    const std::optional<NicCounters>& c,
    uint64_t rxBytes,
    uint64_t rxPackets,
    uint64_t txBytes,
    uint64_t txPackets) {
  ASSERT_TRUE(c.has_value());
  EXPECT_EQ(c->rxBytes, rxBytes);
  EXPECT_EQ(c->rxPackets, rxPackets);
  EXPECT_EQ(c->txBytes, txBytes);
  EXPECT_EQ(c->txPackets, txPackets);
}

} // namespace

TEST(NicCounterSourceTest, IdpfUsesPerQueueSums) {
  SourceFixture f;
  auto source = f.make();

  auto first = source.sample("eth0", kBrokenNetdev);
  expectCounters(first.counters, 1000, 10, 2000, 20);
  // First ethtool sample: callers must re-baseline off the netdev counters.
  EXPECT_TRUE(first.sourceChanged);
  EXPECT_TRUE(source.usesEthtool("eth0"));

  f.setQueueCounters(15, 1500, 25, 2500);
  auto second = source.sample("eth0", kBrokenNetdev);
  expectCounters(second.counters, 1500, 15, 2500, 25);
  EXPECT_FALSE(second.sourceChanged);
  EXPECT_EQ(f.readersCreated, 1);
}

TEST(NicCounterSourceTest, HealthyNicKeepsNetdev) {
  SourceFixture f;
  f.driver.driver = "mlx5_core";
  auto source = f.make();
  for (int i = 0; i < 3; i++) {
    auto s = source.sample("eth2", makeCounters(5000, 50, 6000, 60));
    EXPECT_FALSE(s.counters.has_value());
    EXPECT_FALSE(s.sourceChanged);
  }
  EXPECT_EQ(f.readersCreated, 0);
}

TEST(NicCounterSourceTest, QueueCounterResetStaysMonotonic) {
  SourceFixture f;
  auto source = f.make();
  f.setQueueCounters(100, 10000, 200, 20000);
  expectCounters(
      source.sample("eth0", kBrokenNetdev).counters, 10000, 100, 20000, 200);

  // Vport down (all queue counters read 0), then queues reallocated and
  // counting from 0 again: carry on from the last published values.
  f.setQueueCounters(0, 0, 0, 0);
  auto down = source.sample("eth0", kBrokenNetdev);
  expectCounters(down.counters, 10000, 100, 20000, 200);
  EXPECT_FALSE(down.sourceChanged);

  f.setQueueCounters(5, 500, 7, 700);
  expectCounters(
      source.sample("eth0", kBrokenNetdev).counters, 10500, 105, 20700, 207);

  // Only rx packets go backwards (e.g. a partial queue reallocation): only
  // that counter is folded, the others keep counting without a jump.
  f.setQueueCounters(1, 600, 8, 800);
  expectCounters(
      source.sample("eth0", kBrokenNetdev).counters, 10600, 106, 20800, 208);
}

TEST(NicCounterSourceTest, ReadFailureReportsLastPublished) {
  SourceFixture f;
  auto source = f.make();
  expectCounters(
      source.sample("eth0", kBrokenNetdev).counters, 1000, 10, 2000, 20);

  f.nic.failStats = true;
  f.setQueueCounters(15, 1500, 25, 2500);
  auto failed = source.sample("eth0", kBrokenNetdev);
  expectCounters(failed.counters, 1000, 10, 2000, 20);
  EXPECT_FALSE(failed.sourceChanged);

  f.nic.failStats = false;
  expectCounters(
      source.sample("eth0", kBrokenNetdev).counters, 1500, 15, 2500, 25);
  EXPECT_EQ(f.readersCreated, 1);
}

TEST(NicCounterSourceTest, ReaderRecreatedAfterConsecutiveFailures) {
  SourceFixture f;
  auto source = f.make();
  source.sample("eth0", kBrokenNetdev);

  f.nic.failStats = true;
  for (int i = 0; i < NicCounterSource::kMaxConsecutiveFailures; i++) {
    expectCounters(
        source.sample("eth0", kBrokenNetdev).counters, 1000, 10, 2000, 20);
  }
  EXPECT_EQ(f.readersCreated, 1);

  f.nic.failStats = false;
  f.setQueueCounters(15, 1500, 25, 2500);
  // The reader was dropped; the new one comes after one skipped sample.
  expectCounters(
      source.sample("eth0", kBrokenNetdev).counters, 1000, 10, 2000, 20);
  EXPECT_EQ(f.readersCreated, 1);
  auto recovered = source.sample("eth0", kBrokenNetdev);
  EXPECT_EQ(f.readersCreated, 2);
  // Same kernel counters through a new reader: no reset, no source change.
  expectCounters(recovered.counters, 1500, 15, 2500, 25);
  EXPECT_FALSE(recovered.sourceChanged);
}

TEST(NicCounterSourceTest, PersistentReadFailuresKeepRetrying) {
  SourceFixture f;
  auto source = f.make();
  source.sample("eth0", kBrokenNetdev);

  // Each reader gets 10 tries, then a growing pause before the next one
  // (readers at the 1st, 12th and 24th failure). The last published counters
  // are reported throughout, and the NIC is never given up on.
  f.nic.failStats = true;
  for (int i = 0; i < 3 * NicCounterSource::kMaxConsecutiveFailures; i++) {
    expectCounters(
        source.sample("eth0", kBrokenNetdev).counters, 1000, 10, 2000, 20);
  }
  EXPECT_EQ(f.readersCreated, 3);
  EXPECT_TRUE(source.usesEthtool("eth0"));

  f.nic.failStats = false;
  f.setQueueCounters(15, 1500, 25, 2500);
  auto recovered = source.sample("eth0", kBrokenNetdev);
  expectCounters(recovered.counters, 1500, 15, 2500, 25);
  EXPECT_FALSE(recovered.sourceChanged);
}

TEST(NicCounterSourceTest, GoodReadResetsBackoff) {
  SourceFixture f;
  auto source = f.make();
  source.sample("eth0", kBrokenNetdev);

  for (int round = 0; round < 3; round++) {
    // Reader dropped after 10 failures, then one skipped sample: backoff is
    // back at 1 because the previous round ended with a good read.
    f.nic.failStats = true;
    for (int i = 0; i < NicCounterSource::kMaxConsecutiveFailures + 1; i++) {
      source.sample("eth0", kBrokenNetdev);
    }
    EXPECT_EQ(f.readersCreated, round + 1);
    f.nic.failStats = false;
    expectCounters(
        source.sample("eth0", kBrokenNetdev).counters, 1000, 10, 2000, 20);
    EXPECT_EQ(f.readersCreated, round + 2);
  }
  EXPECT_TRUE(source.usesEthtool("eth0"));
}

TEST(NicCounterSourceTest, ReaderThatNeverInitsIsRetriedWithBackoff) {
  SourceFixture f;
  f.nic.failSsetInfo = true;
  auto source = f.make();
  // Attempts at samples 1, 3, 6, 11, 20, 37, 70: the pause doubles up to 32.
  for (int i = 0; i < 100; i++) {
    EXPECT_FALSE(source.sample("eth0", kBrokenNetdev).counters.has_value());
  }
  EXPECT_EQ(f.readersCreated, 7);

  // Never given up on: once ethtool works again, the next attempt (at most
  // kMaxRetryBackoff samples later) switches the NIC over.
  f.nic.failSsetInfo = false;
  int waited = 0;
  NicCounterSource::Sample s = source.sample("eth0", kBrokenNetdev);
  while (!s.counters && waited < NicCounterSource::kMaxRetryBackoff) {
    waited++;
    s = source.sample("eth0", kBrokenNetdev);
  }
  expectCounters(s.counters, 1000, 10, 2000, 20);
  EXPECT_TRUE(s.sourceChanged);
}

TEST(NicCounterSourceTest, StatLayoutChangeReinitsImmediately) {
  SourceFixture f;
  auto source = f.make();
  source.sample("eth0", kBrokenNetdev);

  // Driver reload with a second queue pair.
  f.nic.names.insert(
      f.nic.names.end(),
      {"rx_q-1_pkts", "rx_q-1_bytes", "tx_q-1_pkts", "tx_q-1_bytes"});
  f.nic.values.insert(f.nic.values.end(), {1, 100, 2, 200});
  auto s = source.sample("eth0", kBrokenNetdev);
  EXPECT_EQ(f.readersCreated, 2);
  expectCounters(s.counters, 1100, 11, 2200, 22);
  EXPECT_FALSE(s.sourceChanged);
}

TEST(NicCounterSourceTest, FailureBeforeFirstReadKeepsNetdev) {
  SourceFixture f;
  f.nic.failSsetInfo = true;
  auto source = f.make();

  auto failed = source.sample("eth0", kBrokenNetdev);
  EXPECT_FALSE(failed.counters.has_value());
  EXPECT_FALSE(failed.sourceChanged);

  f.nic.failSsetInfo = false;
  // The retry waits one sample (backoff), still on netdev.
  auto skipped = source.sample("eth0", kBrokenNetdev);
  EXPECT_FALSE(skipped.counters.has_value());
  EXPECT_FALSE(skipped.sourceChanged);
  auto ok = source.sample("eth0", kBrokenNetdev);
  expectCounters(ok.counters, 1000, 10, 2000, 20);
  EXPECT_TRUE(ok.sourceChanged);
}

TEST(NicCounterSourceTest, UnsupportedNamingStaysOnNetdev) {
  SourceFixture f;
  f.driver.driver = "some_other_driver";
  f.nic = fakes::FakeEthtoolNic{
      {"rx0_packets", "rx0_bytes", "tx0_packets", "tx0_bytes"}, {1, 2, 3, 4}};
  auto source = f.make();
  // Switches on the signature, then finds no per-queue counters.
  const auto signature = makeCounters(1ULL << 32, 0, 1ULL << 33, 0);
  for (int i = 0; i < 3; i++) {
    auto s = source.sample("eth0", signature);
    EXPECT_FALSE(s.counters.has_value());
    EXPECT_FALSE(s.sourceChanged);
  }
  // Looked at once, not on every sample.
  EXPECT_EQ(f.readersCreated, 1);
}

TEST(NicCounterSourceTest, NamingChangeAfterGoodReadsFallsBackToNetdev) {
  SourceFixture f;
  auto source = f.make();
  source.sample("eth0", kBrokenNetdev);

  // Driver reload with names we don't recognize.
  f.nic = fakes::FakeEthtoolNic{
      {"rx0_packets", "rx0_bytes", "tx0_packets", "tx0_bytes"}, {1, 2, 3, 4}};
  auto s = source.sample("eth0", kBrokenNetdev);
  EXPECT_FALSE(s.counters.has_value());
  EXPECT_TRUE(s.sourceChanged);
  EXPECT_FALSE(source.usesEthtool("eth0"));
  EXPECT_FALSE(source.sample("eth0", kBrokenNetdev).sourceChanged);
}

TEST(NicCounterSourceTest, ResetForgetsCountersButNotDecisions) {
  SourceFixture f;
  auto source = f.make();
  source.sample("eth0", kBrokenNetdev);
  f.setQueueCounters(0, 0, 0, 0);
  // Published counters now carry an offset.
  expectCounters(
      source.sample("eth0", kBrokenNetdev).counters, 1000, 10, 2000, 20);

  EXPECT_EQ(source.reset(), std::vector<std::string>{"eth0"});
  EXPECT_FALSE(source.usesEthtool("eth0"));

  // Re-enabled: back on ethtool without a new driver lookup, from the raw
  // counters, reported as a source change.
  f.setQueueCounters(1, 100, 2, 200);
  auto s = source.sample("eth0", kBrokenNetdev);
  expectCounters(s.counters, 100, 1, 200, 2);
  EXPECT_TRUE(s.sourceChanged);
  EXPECT_EQ(f.driver.lookups, 1);
  EXPECT_EQ(f.readersCreated, 2);
}

TEST(NicCounterSourceTest, PruneStillWorksAfterReset) {
  SourceFixture f;
  auto source = f.make();
  source.sample("eth0", kBrokenNetdev);
  source.reset();

  // eth0 disappears while disabled: it is still forgotten, so a new NIC with
  // the same name gets a fresh decision.
  source.prune();
  source.prune();
  source.sample("eth0", kBrokenNetdev);
  EXPECT_EQ(f.driver.lookups, 2);
}

TEST(NicCounterSourceTest, PruneDropsNicsNotSampled) {
  SourceFixture f;
  f.driver.driver = "mlx5_core";
  auto source = f.make();
  const auto healthy = makeCounters(5000, 50, 6000, 60);
  source.sample("veth0", healthy);
  source.sample("eth2", healthy);
  source.prune();
  EXPECT_EQ(f.driver.lookups, 2);

  // veth0 is gone; eth2 is kept and not looked up again.
  source.sample("eth2", healthy);
  source.prune();
  source.sample("eth2", healthy);
  source.sample("veth0", healthy);
  EXPECT_EQ(f.driver.lookups, 3);
}

} // namespace dynolog
