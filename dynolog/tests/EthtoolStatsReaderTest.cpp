/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <linux/ethtool.h>
#include <linux/sockios.h>
#include <sys/uio.h>
#include <unistd.h>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

#include "dynolog/src/EthtoolStatsReader.h"
#include "dynolog/tests/FakeEthtoolIoctl.h"

using namespace ::testing;

namespace dynolog {

class MockEthtoolIoctl : public EthtoolIoctlInterface {
 public:
  MOCK_METHOD(int, openSocket, (), (override));
  MOCK_METHOD(
      int,
      doIoctl,
      (int fd, unsigned long req, struct ifreq* ifr),
      (override));
  MOCK_METHOD(void, closeSocket, (int fd), (override));
};

class EthtoolStatsReaderTest : public ::testing::Test {
 protected:
  static constexpr int kFakeFd = 42;

  // Helper to set up a mock that handles the 3 init ioctls
  void setupInitMock(
      MockEthtoolIoctl& mock,
      uint32_t nStats,
      const std::vector<std::string>& names) {
    EXPECT_CALL(mock, openSocket()).WillOnce(Return(kFakeFd));
    EXPECT_CALL(mock, closeSocket(kFakeFd)).Times(AtLeast(0));

    EXPECT_CALL(mock, doIoctl(kFakeFd, SIOCETHTOOL, _))
        .WillOnce([nStats](int, unsigned long, struct ifreq* ifr) {
          // ETHTOOL_GSSET_INFO response
          auto* sset =
              reinterpret_cast<struct ethtool_sset_info*>(ifr->ifr_data);
          if (sset->cmd != ETHTOOL_GSSET_INFO) {
            return -1;
          }
          sset->sset_mask = 1;
          sset->data[0] = nStats;
          return 0;
        })
        .WillOnce([&names](int, unsigned long, struct ifreq* ifr) {
          // ETHTOOL_GSTRINGS response
          auto* gstr =
              reinterpret_cast<struct ethtool_gstrings*>(ifr->ifr_data);
          if (gstr->cmd != ETHTOOL_GSTRINGS) {
            return -1;
          }
          for (size_t i = 0; i < names.size(); i++) {
            memset(&gstr->data[i * ETH_GSTRING_LEN], 0, ETH_GSTRING_LEN);
            strncpy(
                reinterpret_cast<char*>(&gstr->data[i * ETH_GSTRING_LEN]),
                names[i].c_str(),
                ETH_GSTRING_LEN);
          }
          return 0;
        });
  }
};

TEST_F(EthtoolStatsReaderTest, InitSuccess) {
  auto mock = std::make_unique<MockEthtoolIoctl>();
  std::vector<std::string> names = {
      "rx_q-0_pkts", "rx_q-0_bytes", "tx_q-0_pkts"};
  setupInitMock(*mock, 3, names);

  EthtoolStatsReader reader(std::move(mock));
  EXPECT_TRUE(reader.init("eth0"));
  EXPECT_EQ(reader.size(), 3);
  EXPECT_EQ(reader.name(0), "rx_q-0_pkts");
  EXPECT_EQ(reader.name(1), "rx_q-0_bytes");
  EXPECT_EQ(reader.name(2), "tx_q-0_pkts");
}

TEST_F(EthtoolStatsReaderTest, InitSocketFailure) {
  auto mock = std::make_unique<MockEthtoolIoctl>();
  EXPECT_CALL(*mock, openSocket()).WillOnce(Return(-1));

  EthtoolStatsReader reader(std::move(mock));
  EXPECT_FALSE(reader.init("eth0"));
  EXPECT_EQ(reader.size(), 0);
}

TEST_F(EthtoolStatsReaderTest, InitIoctlFailure) {
  auto mock = std::make_unique<MockEthtoolIoctl>();
  EXPECT_CALL(*mock, openSocket()).WillOnce(Return(kFakeFd));
  EXPECT_CALL(*mock, doIoctl(kFakeFd, SIOCETHTOOL, _)).WillOnce(Return(-1));
  EXPECT_CALL(*mock, closeSocket(kFakeFd)).Times(1);

  EthtoolStatsReader reader(std::move(mock));
  EXPECT_FALSE(reader.init("eth0"));
}

TEST_F(EthtoolStatsReaderTest, SampleAndGetAllStats) {
  auto mock = std::make_unique<MockEthtoolIoctl>();
  std::vector<std::string> names = {"rx_q-0_pkts", "tx_q-0_pkts"};

  EXPECT_CALL(*mock, openSocket()).WillOnce(Return(kFakeFd));
  EXPECT_CALL(*mock, closeSocket(kFakeFd)).Times(AtLeast(0));

  EXPECT_CALL(*mock, doIoctl(kFakeFd, SIOCETHTOOL, _))
      .WillOnce([](int, unsigned long, struct ifreq* ifr) {
        // ETHTOOL_GSSET_INFO
        auto* sset = reinterpret_cast<struct ethtool_sset_info*>(ifr->ifr_data);
        sset->sset_mask = 1;
        sset->data[0] = 2;
        return 0;
      })
      .WillOnce([&names](int, unsigned long, struct ifreq* ifr) {
        // ETHTOOL_GSTRINGS
        auto* gstr = reinterpret_cast<struct ethtool_gstrings*>(ifr->ifr_data);
        for (size_t i = 0; i < names.size(); i++) {
          memset(&gstr->data[i * ETH_GSTRING_LEN], 0, ETH_GSTRING_LEN);
          strncpy(
              reinterpret_cast<char*>(&gstr->data[i * ETH_GSTRING_LEN]),
              names[i].c_str(),
              ETH_GSTRING_LEN);
        }
        return 0;
      })
      .WillOnce([](int, unsigned long, struct ifreq* ifr) {
        // ETHTOOL_GSTATS
        auto* stats = reinterpret_cast<struct ethtool_stats*>(ifr->ifr_data);
        stats->data[0] = 1000;
        stats->data[1] = 500;
        return 0;
      });

  EthtoolStatsReader reader(std::move(mock));
  ASSERT_TRUE(reader.init("eth0"));
  ASSERT_TRUE(reader.sample());

  auto allStats = reader.getAllStats();
  EXPECT_EQ(allStats.size(), 2);
  EXPECT_EQ(allStats["rx_q-0_pkts"], 1000);
  EXPECT_EQ(allStats["tx_q-0_pkts"], 500);
  EXPECT_EQ(reader.value(0), 1000);
  EXPECT_EQ(reader.value(1), 500);
}

namespace {
// Writes like the kernel's copy_to_user: faults are reported, not raised.
bool kernelWrite(void* dst, size_t len) {
  std::vector<char> src(len, 'x');
  struct iovec local{src.data(), len};
  struct iovec remote{dst, len};
  return process_vm_writev(getpid(), &local, 1, &remote, 1, 0) ==
      static_cast<ssize_t>(len);
}
} // namespace

TEST(GuardedBufferTest, WritesPastTheEndFault) {
  GuardedBuffer buf(100);
  ASSERT_TRUE(buf);
  EXPECT_EQ(reinterpret_cast<uintptr_t>(buf.data()) % 8, 0);
  // Size is rounded up to 8: 104 writable bytes, then the guard page.
  EXPECT_TRUE(kernelWrite(buf.data(), 104));
  EXPECT_FALSE(kernelWrite(buf.data(), 105));
  EXPECT_FALSE(kernelWrite(buf.data() + 104, 1));

  GuardedBuffer moved(std::move(buf));
  EXPECT_FALSE(buf); // NOLINT(bugprone-use-after-move)
  EXPECT_TRUE(kernelWrite(moved.data(), 104));
}

TEST_F(EthtoolStatsReaderTest, StatCountGrowthIsContainedAndNeedsReinit) {
  fakes::FakeEthtoolNic nic{{"rx_q-0_pkts", "tx_q-0_pkts"}, {10, 20}};
  EthtoolStatsReader reader(std::make_unique<fakes::FakeEthtoolIoctl>(&nic));
  ASSERT_TRUE(reader.init("eth0"));
  ASSERT_TRUE(reader.sample());
  EXPECT_FALSE(reader.needsReinit());

  // Queue reconfiguration from 1 to 32 queue pairs: far more than the buffer
  // holds. The copy stops at the guard page (EFAULT) instead of overrunning,
  // and the count written back first triggers a re-init.
  for (int q = 1; q < 32; q++) {
    nic.names.push_back("rx_q-" + std::to_string(q) + "_pkts");
    nic.names.push_back("tx_q-" + std::to_string(q) + "_pkts");
  }
  nic.values.assign(nic.names.size(), 7);
  nic.values[0] = 11;
  EXPECT_FALSE(reader.sample());
  EXPECT_TRUE(reader.needsReinit());
  // The last good values are kept.
  EXPECT_EQ(reader.value(0), 10);
  EXPECT_EQ(reader.value(1), 20);

  // Keeps failing, without ioctls, until re-initialized.
  nic.commands.clear();
  EXPECT_FALSE(reader.sample());
  EXPECT_TRUE(nic.commands.empty());

  ASSERT_TRUE(reader.init("eth0"));
  EXPECT_FALSE(reader.needsReinit());
  ASSERT_TRUE(reader.sample());
  ASSERT_EQ(reader.size(), 64);
  EXPECT_EQ(reader.value(0), 11);
  EXPECT_EQ(reader.value(63), 7);
}

TEST_F(EthtoolStatsReaderTest, StatCountShrinkNeedsReinit) {
  fakes::FakeEthtoolNic nic{{"rx_q-0_pkts", "tx_q-0_pkts"}, {10, 20}};
  EthtoolStatsReader reader(std::make_unique<fakes::FakeEthtoolIoctl>(&nic));
  ASSERT_TRUE(reader.init("eth0"));
  ASSERT_TRUE(reader.sample());

  nic.names.pop_back();
  nic.values = {11};
  EXPECT_FALSE(reader.sample());
  EXPECT_TRUE(reader.needsReinit());
  EXPECT_EQ(reader.value(0), 10);
  EXPECT_EQ(reader.value(1), 20);
}

TEST_F(EthtoolStatsReaderTest, StatCountGrowthDuringInitIsContained) {
  // The count grows between GSSET_INFO (reports 1) and GSTRINGS (64 names).
  fakes::FakeEthtoolNic nic;
  for (int i = 0; i < 64; i++) {
    nic.names.push_back("rx_q-" + std::to_string(i) + "_pkts");
  }
  nic.values.assign(nic.names.size(), 1);
  nic.staleSsetInfoCount = 1;
  EthtoolStatsReader reader(std::make_unique<fakes::FakeEthtoolIoctl>(&nic));
  EXPECT_FALSE(reader.init("eth0"));
  EXPECT_EQ(reader.size(), 0);

  nic.staleSsetInfoCount = 0;
  ASSERT_TRUE(reader.init("eth0"));
  EXPECT_EQ(reader.size(), 64);
}

TEST_F(EthtoolStatsReaderTest, SampleFailureKeepsValuesWithoutReinit) {
  fakes::FakeEthtoolNic nic{{"rx_q-0_pkts"}, {10}};
  EthtoolStatsReader reader(std::make_unique<fakes::FakeEthtoolIoctl>(&nic));
  ASSERT_TRUE(reader.init("eth0"));
  ASSERT_TRUE(reader.sample());

  nic.failStats = true;
  nic.values = {15};
  EXPECT_FALSE(reader.sample());
  EXPECT_FALSE(reader.needsReinit());
  EXPECT_EQ(reader.value(0), 10);

  nic.failStats = false;
  ASSERT_TRUE(reader.sample());
  EXPECT_EQ(reader.value(0), 15);
}

// Minimal fake that answers init with one stat and counts socket closes.
class CountingIoctl : public EthtoolIoctlInterface {
 public:
  explicit CountingIoctl(int* closes) : closes_(closes) {}
  int openSocket() override {
    return 7;
  }
  int doIoctl(int, unsigned long, struct ifreq* ifr) override {
    auto* cmd = reinterpret_cast<uint32_t*>(ifr->ifr_data);
    if (*cmd == ETHTOOL_GSSET_INFO) {
      auto* sset = reinterpret_cast<struct ethtool_sset_info*>(ifr->ifr_data);
      sset->sset_mask = 1;
      sset->data[0] = 1;
    } else if (*cmd == ETHTOOL_GSTRINGS) {
      auto* gstr = reinterpret_cast<struct ethtool_gstrings*>(ifr->ifr_data);
      strncpy(reinterpret_cast<char*>(gstr->data), "rx_q-0_pkts", 16);
    }
    return 0;
  }
  void closeSocket(int) override {
    (*closes_)++;
  }

 private:
  int* closes_;
};

TEST_F(EthtoolStatsReaderTest, MoveTransfersSocketOwnership) {
  int closes = 0;
  {
    EthtoolStatsReader a(std::make_unique<CountingIoctl>(&closes));
    ASSERT_TRUE(a.init("eth0"));
    EthtoolStatsReader b(std::move(a));
    // The moved-from state is part of the contract.
    EXPECT_EQ(a.size(), 0); // NOLINT(bugprone-use-after-move)
    EXPECT_EQ(b.size(), 1);
    EXPECT_EQ(b.name(0), "rx_q-0_pkts");

    // Move-assigning over an initialized reader closes its old socket.
    EthtoolStatsReader c(std::make_unique<CountingIoctl>(&closes));
    ASSERT_TRUE(c.init("eth1"));
    c = std::move(b);
    EXPECT_EQ(closes, 1);
    EXPECT_EQ(c.name(0), "rx_q-0_pkts");
  }
  // a and b are empty; only c closes its socket on destruction.
  EXPECT_EQ(closes, 2);
}

TEST_F(EthtoolStatsReaderTest, SampleWithoutInit) {
  EthtoolStatsReader reader;
  EXPECT_FALSE(reader.sample());
  EXPECT_EQ(reader.size(), 0);
  EXPECT_TRUE(reader.getAllStats().empty());
}

} // namespace dynolog
