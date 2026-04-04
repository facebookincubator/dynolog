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
#include <cstring>

#include "dynolog/src/EthtoolStatsReader.h"

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

TEST_F(EthtoolStatsReaderTest, SampleWithoutInit) {
  EthtoolStatsReader reader;
  EXPECT_FALSE(reader.sample());
  EXPECT_EQ(reader.size(), 0);
  EXPECT_TRUE(reader.getAllStats().empty());
}

} // namespace dynolog
