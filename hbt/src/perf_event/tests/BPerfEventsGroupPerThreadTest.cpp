// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/BPerfEventsGroup.h"
#include "hbt/src/perf_event/BPerfPerThreadReader.h"
#include "hbt/src/perf_event/BuiltinMetrics.h"

#include <gtest/gtest.h>
#include <time.h>
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace facebook::hbt;
using namespace facebook::hbt::perf_event;

namespace {

std::shared_ptr<BPerfPerThreadReader> createReader(void) {
  auto reader = std::make_shared<BPerfPerThreadReader>("cycles", 1);
  auto second_reader = std::make_shared<BPerfPerThreadReader>("cycles", 1);

  EXPECT_EQ(reader->enable(), 0);
  // second_read will fail to enable
  EXPECT_EQ(second_reader->enable(), -1);
  return reader;
}

int createPerfEvent() {
  struct perf_event_attr attr = {.size = sizeof(struct perf_event_attr)};

  attr.type = PERF_TYPE_HARDWARE;
  attr.config = PERF_COUNT_HW_CPU_CYCLES;
  attr.read_format =
      PERF_FORMAT_TOTAL_TIME_ENABLED | PERF_FORMAT_TOTAL_TIME_RUNNING;

  int fd = syscall(
      __NR_perf_event_open,
      &attr,
      0 /* pid */,
      -1 /* cpu */,
      -1 /* group_fd */,
      0 /* flags */);
  EXPECT_GE(fd, 0);
  return fd;
}

volatile __u64 __work = 0;

static void doSomeWork(long count) {
  long i;

  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  for (i = 0; i < count; i++) {
    __work += i * count;
  }
}

__u64 normalizedValue(const struct bpf_perf_event_value& value) {
  if (value.running == 0)
    return 0;
  return (__u64)((double)value.counter * value.enabled / value.running);
}

static __u64 get_time_nanosecond(clockid_t clockid) {
  struct timespec ts;

  clock_gettime(clockid, &ts);
  return ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

#define TESTS 4

void printBPerfThreadData(
    const std::string& name,
    const struct BPerfThreadData& data) {
  GTEST_LOG_(INFO) << name << " counter = " << data.values[0].counter;
  GTEST_LOG_(INFO) << name << " enabled = " << data.values[0].enabled;
  GTEST_LOG_(INFO) << name << " running = " << data.values[0].running;
}

void userThread(void) {
  auto reader = createReader();
  auto pmu_fd = createPerfEvent();
  struct bpf_perf_event_value beforeValue, afterValue;
  struct BPerfThreadData beforeData, afterData;
  __u64 monoTimeBefore, monoTimeDiff;
  __u64 cpuTimeBefore, cpuTimeDiff;

  long workSizes[TESTS] = {1000000, 10000000, 100000000, 1000000000};

  for (int i = 0; i < TESTS; i++) {
    int err;

    err = ::read(pmu_fd, &beforeValue, sizeof(beforeValue));
    EXPECT_EQ(err, 24);
    err = reader->read(&beforeData);
    EXPECT_EQ(err, 0);
    monoTimeBefore = get_time_nanosecond(CLOCK_MONOTONIC);
    cpuTimeBefore = get_time_nanosecond(CLOCK_THREAD_CPUTIME_ID);

    doSomeWork(workSizes[i]);
    err = ::read(pmu_fd, &afterValue, sizeof(afterValue));
    err = reader->read(&afterData);
    EXPECT_EQ(err, 0);
    monoTimeDiff = get_time_nanosecond(CLOCK_MONOTONIC) - monoTimeBefore;
    cpuTimeDiff = get_time_nanosecond(CLOCK_THREAD_CPUTIME_ID) - cpuTimeBefore;

    auto perfDiff = normalizedValue(afterValue) - normalizedValue(beforeValue);
    auto bperfDiff = normalizedValue(afterData.values[0]) -
        normalizedValue(beforeData.values[0]);
    auto ratio = (double)bperfDiff / perfDiff;

    GTEST_LOG_(INFO) << "work = " << workSizes[i]
                     << " bperf/perf value = " << (double)bperfDiff / perfDiff;

    GTEST_LOG_(INFO) << "perfDiff = " << perfDiff;
    GTEST_LOG_(INFO) << "bperfDiff = " << bperfDiff;
    printBPerfThreadData("before", beforeData);
    printBPerfThreadData("after ", afterData);

    // We are within 1% in most cases. Give a bigger margin so that the
    // test is more stable.
    EXPECT_GE(ratio, 0.95);
    EXPECT_LE(ratio, 1.05);

    auto monoTimeRatio =
        (double)monoTimeDiff / (afterData.monoTime - beforeData.monoTime);
    EXPECT_GE(monoTimeRatio, 0.95);
    EXPECT_LE(monoTimeRatio, 1.05);

    auto cpuTimeRatio =
        (double)cpuTimeDiff / (afterData.cpuTime - beforeData.cpuTime);
    EXPECT_GE(cpuTimeRatio, 0.95);
    EXPECT_LE(cpuTimeRatio, 1.05);
  }

  reader->disable();
  close(pmu_fd);
}

} // namespace

#define BPERF_TEST_PARALLEL_THREADS 8

TEST(BPerfEventsGroupPerThreadTest, TestCycles) {
  auto pmu_manager = makePmuDeviceManager();
  auto pmu = pmu_manager->findPmuDeviceByName("generic_hardware");
  auto ev_def = pmu_manager->findEventDef("cycles");
  if (!ev_def) {
    GTEST_SKIP() << "Cannot find event cycles";
  }
  auto ev_conf =
      pmu->makeConf(ev_def->id, EventExtraAttr(), EventValueTransforms());

  auto system = BPerfEventsGroup(EventConfs({ev_conf}), 0, true, "cycles");
  EXPECT_EQ(system.open(), true);

  std::thread threads[BPERF_TEST_PARALLEL_THREADS];

  for (int i = 0; i < BPERF_TEST_PARALLEL_THREADS; i++) {
    threads[i] = std::thread(userThread);
  }

  for (int i = 0; i < BPERF_TEST_PARALLEL_THREADS; i++) {
    threads[i].join();
  }
}
