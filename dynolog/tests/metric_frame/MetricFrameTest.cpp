// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>
#include <cstdint>

#include "dynolog/src/metric_frame/MetricFrame.h"
#include "dynolog/src/metric_frame/MetricFrameTsUnit.h"
#include "dynolog/src/metric_frame/MetricSeries.h"

using namespace ::testing;
using namespace ::facebook::dynolog;

using namespace std::literals::chrono_literals;

TEST(PerfReadValuesTest, operator) {
  PerfReadValues v1, v2;
  v1.timeEnabled = 100;
  v1.timeRunning = 50;
  v2.timeEnabled = 150;
  v2.timeRunning = 80;
  v1.count = 50;
  v2.count = 80;

  auto diff = v2 - v1;
  EXPECT_EQ(diff.timeEnabled, 50);
  EXPECT_EQ(diff.timeRunning, 30);
  EXPECT_EQ(diff.count, 30);

  std::cerr << diff << std::endl;
}

TEST(PerfReadValuesTest, getCount) {
  PerfReadValues v;
  v.timeEnabled = 50;
  v.timeRunning = 30;
  v.count = 30;
  EXPECT_NEAR(v.getCount<double>(), 30.0 * 50.0 / 30.0, 1e-6);
  EXPECT_EQ(v.getCount<uint64_t>(), static_cast<uint64_t>(30.0 * 50.0 / 30.0));
}

TEST(MetricSeriesSliceTest, constructor) {
  auto ts = std::make_shared<MetricFrameTsUnitFixInterval>(
      std::chrono::seconds{60}, 10);
  auto tsLong = std::make_shared<MetricFrameTsUnitFixInterval>(
      std::chrono::seconds{60}, 100);
  MetricFrameMap frameMap(10, "test", "test metric frame", std::move(ts));

  EXPECT_EQ(frameMap.length(), 0);
  EXPECT_EQ(frameMap.width(), 0);
  EXPECT_EQ(frameMap.maxLength(), 10);
  EXPECT_EQ(frameMap.name(), "test");
  EXPECT_EQ(frameMap.description(), "test metric frame");
  EXPECT_FALSE(frameMap.firstSampleTime().has_value());
  EXPECT_FALSE(frameMap.lastSampleTime().has_value());

  EXPECT_THROW(
      MetricFrameMap(10, "test", "test metric frame", std::move(tsLong)),
      std::invalid_argument);
}

TEST(MetricSeriesSliceTest, metricFrameMapSmokeTest) {
  auto ts = std::make_shared<MetricFrameTsUnitFixInterval>(
      std::chrono::seconds{60}, 10);
  MetricFrameMap frameMap(10, "test", "test metric frame", std::move(ts));

  std::string series1Key = "metric1";
  std::string series2Key = "metric2";

  auto series1 =
      std::make_shared<MetricSeries<int64_t>>(10, series1Key, "test metric 1");
  auto series2 =
      std::make_shared<MetricSeries<double>>(10, series2Key, "test metric 2");

  frameMap.addSeries(series1Key, std::move(series1));
  frameMap.addSeries(series2Key, std::move(series2));

  EXPECT_EQ(frameMap.length(), 0);
  EXPECT_EQ(frameMap.maxLength(), 10);
  EXPECT_EQ(frameMap.width(), 2);

  auto now = std::chrono::steady_clock::now();

  frameMap.addSamples({{"metric1", 42l}, {"metric2", 23.9f}}, now);
  EXPECT_EQ(frameMap.length(), 1);
  EXPECT_EQ(frameMap.maxLength(), 10);
  for (int i = 1; i <= 10; i++) {
    frameMap.addSamples(
        {{"metric1", 42l + i}, {"metric2", 23.9f + i}}, now + 60s * i);
  }
  // |  60s | 120s | 180s | 240s | 300s | 360s | 420s | 480s | 540s | 600s |
  // |  43  |  44  |  45  |  46  |  47  |  48  |  49  |  50  |  51  | 52   |
  // | 24.9 | 25.9 | 26.9 | 27.9 | 28.9 | 29.9 | 30.9 | 31.9 | 32.9 | 33.9 |
  //           |-----------------------------------|
  EXPECT_EQ(frameMap.length(), 10);
  EXPECT_EQ(frameMap.maxLength(), 10);
  EXPECT_EQ(frameMap.firstSampleTime().value(), now + 60s);
  EXPECT_EQ(frameMap.lastSampleTime().value(), now + 600s);

  ASSERT_TRUE(frameMap.slice(now + 100s, now + 400s).has_value());
  auto frameSlice = frameMap.slice(now + 100s, now + 400s).value();

  auto seriesSlice1 = frameSlice.series<int64_t>("metric1");
  auto seriesSlice2 = frameSlice.series<double>("metric2");
  ASSERT_TRUE(seriesSlice1.has_value());
  ASSERT_TRUE(seriesSlice2.has_value());
  EXPECT_FALSE(frameSlice.series<int64_t>("not_exist").has_value());

  EXPECT_EQ(seriesSlice1->avg<int>(), 46);
  EXPECT_NEAR(seriesSlice1->avg<double>(), 46.5, 1e-3);
  EXPECT_EQ(seriesSlice1->percentile(0.2), 45);
  EXPECT_NEAR(seriesSlice1->rate<double>(1s), 0.01667, 1e-3);
  EXPECT_EQ(seriesSlice1->rate<int>(1min), 1);
  EXPECT_EQ(seriesSlice1->diff(), 5);

  EXPECT_NEAR(seriesSlice2->avg<double>(), 28.4, 1e-3);
  EXPECT_NEAR(seriesSlice2->percentile(0.4), 27.9, 1e-3);
  EXPECT_NEAR(seriesSlice2->rate<double>(1s), 0.01667, 1e-3);
  EXPECT_EQ(seriesSlice2->rate<int>(1min), 1);
  EXPECT_NEAR(seriesSlice2->diff(), 5.0, 1e-3);

  EXPECT_TRUE(frameMap.eraseSeries(series1Key));
  EXPECT_FALSE(frameMap.eraseSeries("not_exist"));
  EXPECT_FALSE(
      frameMap.slice(now, now + 140s)->series<int64_t>(series1Key).has_value());
  EXPECT_FALSE(frameMap.series(series1Key));
}

TEST(MetricSeriesSliceTest, metricFrameVectorSmokeTest) {
  std::string series1Key = "metric1";
  std::string series2Key = "metric2";

  auto ts = std::make_shared<MetricFrameTsUnitFixInterval>(
      std::chrono::seconds{60}, 10);
  MetricFrameVector frameVector(
      {std::make_shared<MetricSeries<int64_t>>(10, series1Key, "test metric 1"),
       std::make_shared<MetricSeries<double>>(10, series2Key, "test metric 2")},
      "test",
      "test metric frame",
      std::move(ts));

  EXPECT_EQ(frameVector.length(), 0);
  EXPECT_EQ(frameVector.maxLength(), 10);
  EXPECT_EQ(frameVector.width(), 2);

  auto now = std::chrono::steady_clock::now();
  frameVector.addSamples({42l, 23.9f}, now);
  EXPECT_EQ(frameVector.length(), 1);
  EXPECT_EQ(frameVector.maxLength(), 10);
  for (int i = 1; i <= 10; i++) {
    frameVector.addSamples({42l + i, 23.9f + i}, now + 60s * i);
  }
  // |  60s | 120s | 180s | 240s | 300s | 360s | 420s | 480s | 540s | 600s |
  // |  43  |  44  |  45  |  46  |  47  |  48  |  49  |  50  |  51  | 52   |
  // | 24.9 | 25.9 | 26.9 | 27.9 | 28.9 | 29.9 | 30.9 | 31.9 | 32.9 | 33.9 |
  //           |-----------------------------------|
  EXPECT_EQ(frameVector.length(), 10);
  EXPECT_EQ(frameVector.maxLength(), 10);
  EXPECT_EQ(frameVector.firstSampleTime().value(), now + 60s);
  EXPECT_EQ(frameVector.lastSampleTime().value(), now + 600s);

  ASSERT_TRUE(frameVector.slice(now + 100s, now + 400s).has_value());
  auto frameSlice = frameVector.slice(now + 100s, now + 400s).value();

  auto seriesSlice1 = frameSlice.series<int64_t>(0);
  auto seriesSlice2 = frameSlice.series<double>(1);
  ASSERT_TRUE(seriesSlice1.has_value());
  ASSERT_TRUE(seriesSlice2.has_value());
  EXPECT_FALSE(frameSlice.series<int64_t>(10).has_value());

  EXPECT_EQ(seriesSlice1->avg<int>(), 46);
  EXPECT_NEAR(seriesSlice1->avg<double>(), 46.5, 1e-3);
  EXPECT_EQ(seriesSlice1->percentile(0.2), 45);
  EXPECT_NEAR(seriesSlice1->rate<double>(1s), 0.01667, 1e-3);
  EXPECT_EQ(seriesSlice1->rate<int>(1min), 1);
  EXPECT_EQ(seriesSlice1->diff(), 5);

  EXPECT_NEAR(seriesSlice2->avg<double>(), 28.4, 1e-3);
  EXPECT_NEAR(seriesSlice2->percentile(0.4), 27.9, 1e-3);
  EXPECT_NEAR(seriesSlice2->rate<double>(1s), 0.01667, 1e-3);
  EXPECT_EQ(seriesSlice2->rate<int>(1min), 1);
  EXPECT_NEAR(seriesSlice2->diff(), 5, 1e-3);
}

TEST(MetricSeriesSliceTest, perfReadValuesCompabilityTest) {
  auto ts = std::make_shared<MetricFrameTsUnitFixInterval>(
      std::chrono::seconds{60}, 10);
  MetricFrameMap frame(10, "test", "test metric frame", std::move(ts));
  auto series = std::make_shared<MetricSeries<PerfReadValues>>(
      10, "perf_values", "perf read values metric");
  ASSERT_TRUE(frame.addSeries("perf_values_1", std::move(series)));

  auto now = std::chrono::steady_clock::now();
  PerfReadValues sample = {.timeEnabled = 60, .timeRunning = 60, .count = 60};
  ASSERT_TRUE(frame.addSamples({{"perf_values_1", sample}}, now));
  sample.timeEnabled = 120;
  sample.timeRunning = 90;
  sample.count = 90;
  ASSERT_TRUE(frame.addSamples({{"perf_values_1", sample}}, now + 60s));

  ASSERT_TRUE(frame.slice(now, now + 60s).has_value());
  auto frameSlice = frame.slice(now, now + 60s).value();
  auto seriesSlice = frameSlice.series<PerfReadValues>("perf_values_1");
  ASSERT_TRUE(seriesSlice.has_value());
  auto rate = seriesSlice->rate<double>(1s);
  EXPECT_NEAR(rate, 1, 1e-3);

  sample.timeEnabled = 180;
  sample.timeRunning = 90;
  sample.count = 90;
  ASSERT_TRUE(frame.addSamples({{"perf_values_1", sample}}, now + 120s));

  ASSERT_TRUE(frame.slice(now + 60s, now + 120s).has_value());
  auto frameSlice2 = frame.slice(now + 60s, now + 120s).value();
  auto seriesSlice2 = frameSlice2.series<PerfReadValues>("perf_values_1");
  ASSERT_TRUE(seriesSlice2.has_value());
  rate = seriesSlice2->rate<double>(1s);
  EXPECT_NEAR(rate, 0, 1e-3);

  ASSERT_TRUE(frame.slice(now, now + 120s).has_value());
  auto frameSlice3 = frame.slice(now, now + 120s).value();
  auto seriesSlice3 = frameSlice3.series<PerfReadValues>("perf_values_1");
  ASSERT_TRUE(seriesSlice3.has_value());
  rate = seriesSlice3->rate<double>(1s);
  EXPECT_NEAR(rate, 1, 1e-3);
}
