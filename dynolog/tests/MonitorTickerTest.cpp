// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include <glog/logging.h>
#include <gtest/gtest.h>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "dynolog/src/MonitorBase.h"
#include "dynolog/src/Ticker.h"

using namespace ::testing;

namespace facebook {
namespace dynolog {

using TestTickerTwoLevels = Ticker<100, 10, 10, 2>;
using TestTickerThreeLevels = Ticker<100, 10, 10, 3>;
using TestTickerFourLevels = Ticker<100, 10, 10, 4>;

class MonitorTickerTest : public ::testing::Test {};

template <typename TTicker>
class MonitorDerivedTest : public MonitorBase<TTicker> {
 public:
  using typename MonitorBase<TTicker>::TMask;
  MonitorDerivedTest(
      std::shared_ptr<TTicker> ticker,
      std::vector<double> subminor_tick_sample_rates,
      std::string name = "MonitorDerivedTest")
      : MonitorBase<TTicker>(ticker, name, subminor_tick_sample_rates),
        start(std::chrono::steady_clock::now()) {}

  std::map<std::size_t, uint64_t> tick_counter;

  void tick(TMask mask) {
    std::string annotation;
    if (TTicker::is_major_tick(mask)) {
      annotation = "MAJOR_TICK";
    } else if (TTicker::is_minor_tick(mask)) {
      annotation = "MINOR_TICK";
    }
    std::bitset<sizeof(mask) * 8> bset(mask);
    LOG(INFO) << "ticking at levels " << bset.to_string() << " "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::steady_clock::now() - start)
                     .count()
              << " " << annotation;
    for (std::size_t i = 0; i < sizeof(mask) * 8; i++) {
      if (bset[i]) {
        tick_counter[i]++;
      }
    }
  }

  void reset_tick_counter() {
    tick_counter.clear();
  }

  void validate_tick_counter(std::size_t major_ticks_ran) {
    LOG(INFO) << "validate_ticks_counter for " << this->get_name();
    EXPECT_EQ(major_ticks_ran, tick_counter[0]);
    std::size_t minor_ticks_expected =
        major_ticks_ran * TTicker::_major_tick_ms / TTicker::_minor_tick_ms;
    EXPECT_EQ(minor_ticks_expected, tick_counter[1]);
    for (std::size_t i = 2; i != TTicker::_levels; i++) {
      LOG(INFO) << "sublevel " << i << ": " << pow(TTicker::_base, i - 1) << " "
                << this->get_subminor_tick_sample_rates()[i - 2] << " "
                << minor_ticks_expected << " " << tick_counter[i];
      EXPECT_EQ(
          pow(TTicker::_base, i - 1) *
              this->get_subminor_tick_sample_rates()[i - 2] *
              minor_ticks_expected,
          tick_counter[i]);
    }
  }

  const std::chrono::steady_clock::time_point start;
};

TEST(MonitorTickerTest, testSimpleTwoLevels) {
  std::shared_ptr<TestTickerTwoLevels> ticker =
      std::make_shared<TestTickerTwoLevels>();
  std::srand(std::time(nullptr));
  MonitorDerivedTest<TestTickerTwoLevels> monitor(ticker, {});
  ticker->run_inner(2);
  monitor.validate_tick_counter(2);
}

TEST(MonitorTickerTest, testSimpleThreeLevels) {
  std::shared_ptr<TestTickerThreeLevels> ticker =
      std::make_shared<TestTickerThreeLevels>();
  std::srand(std::time(nullptr));
  MonitorDerivedTest<TestTickerThreeLevels> monitor(ticker, {0.5});
  ticker->run_inner(2);
  monitor.validate_tick_counter(2);
}

TEST(MonitorTickerTest, testSimpleFourLevels) {
  std::shared_ptr<TestTickerFourLevels> ticker =
      std::make_shared<TestTickerFourLevels>();
  std::srand(std::time(nullptr));
  MonitorDerivedTest<TestTickerFourLevels> monitor(ticker, {0.5, 0.1});
  ticker->run_inner(2);
  monitor.validate_tick_counter(2);
}

TEST(MonitorTickerTest, testFullSampling) {
  std::shared_ptr<TestTickerFourLevels> ticker =
      std::make_shared<TestTickerFourLevels>();
  std::srand(std::time(nullptr));
  MonitorDerivedTest<TestTickerFourLevels> monitor(ticker, {1.0, 1.0});
  ticker->run_inner(2);
  monitor.validate_tick_counter(2);
}

TEST(MonitorTickerTest, testZeroSampling) {
  std::shared_ptr<TestTickerFourLevels> ticker =
      std::make_shared<TestTickerFourLevels>();
  std::srand(std::time(nullptr));
  MonitorDerivedTest<TestTickerFourLevels> monitor(ticker, {0.0, 0.0});
  ticker->run_inner(2);
  monitor.validate_tick_counter(2);
}

TEST(MonitorTickerTest, testTwoSubcribers) {
  std::shared_ptr<TestTickerFourLevels> ticker =
      std::make_shared<TestTickerFourLevels>();
  std::srand(std::time(nullptr));
  MonitorDerivedTest<TestTickerFourLevels> monitor(
      ticker, {0.5, 0.1}, "Monitor1");
  MonitorDerivedTest<TestTickerFourLevels> monitor2(ticker, {0.5}, "Monitor2");
  ticker->run_inner(2);
  monitor.validate_tick_counter(2);
  monitor2.validate_tick_counter(2);
}

TEST(MonitorTickerTest, testChangeSampling) {
  std::shared_ptr<TestTickerFourLevels> ticker =
      std::make_shared<TestTickerFourLevels>();
  std::srand(std::time(nullptr));
  MonitorDerivedTest<TestTickerFourLevels> monitor(ticker, {0.5, 0.1});
  ticker->run_inner(2);
  monitor.validate_tick_counter(2);
  // Too many sample rates for the ticker levels, should fail
  EXPECT_EQ(monitor.try_change_sample_rates({0.5, 0.1, 0.01}), false);
  // Sample rate > 1.0 is invalid
  EXPECT_EQ(monitor.try_change_sample_rates({0.5, 10.0}), false);
  // Sample rate < 0.0 is invalid
  EXPECT_EQ(monitor.try_change_sample_rates({0.5, -0.1}), false);

  // Monitor should still be subscribing at the old rate
  monitor.reset_tick_counter();
  ticker->run_inner(2);
  monitor.validate_tick_counter(2);

  // This should be a valid change
  EXPECT_EQ(monitor.try_change_sample_rates({0.1, 0.5}), true);
  monitor.reset_tick_counter();
  ticker->run_inner(2);
  monitor.validate_tick_counter(2);
}

} // namespace dynolog
} // namespace facebook
