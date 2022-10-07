// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/ringbuffer/PerCpuRingBuffer.h"
#include "hbt/src/ringbuffer/Shm.h"

#include <gtest/gtest.h>
#include <sys/types.h>
#include <thread>

using namespace facebook::hbt;

struct MockExtraData {
  int dummy_data;
};

using TPerCpuRingBuffer = ringbuffer::PerCpuRingBuffer<MockExtraData>;
using TPerCpuProducer = ringbuffer::PerCpuProducer<MockExtraData>;
using TPerCpuConsumer = ringbuffer::PerCpuConsumer<MockExtraData>;

// Same process produces and consumes share memory through different mappings.
TEST(ShmPerCpuRingBuffer, SameProducerConsumer) {
  // Set affinity of producer to CPU zero so that consumer only has to read from
  // that one CPU's buffer.
  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);
  CPU_SET(0, &cpuset);
  sched_setaffinity(0, sizeof(cpu_set_t), &cpuset);

  // Make unique file name for shared memory
  auto base_name = shm::Segment::createTempDir("hbt_test");
  std::string name_id = base_name + "SameProducerConsumer__test";

  { // Producer part.

    // Buffer large enough to fit all data and persistent
    // (needs to be unlinked up manually).
    auto rb = ringbuffer::shm::create<TPerCpuRingBuffer>(
        name_id, 256 * 1024, true, CpuSet::makeFromCpuSet(cpuset));
    TPerCpuProducer per_cpu_producer{rb};

    // SingleProducer for ringbuffer at CPU 0.
    auto& prod = per_cpu_producer.atCpu(0);

    // Producer loop. It all fits in buffer.
    int i = 0;
    while (i < 2000) {
      ssize_t ret = prod.write(i);
      EXPECT_EQ(ret, sizeof(i));
      ++i;
    }
  }

  { // Consumer part.

    // Map file again (to a different address) and consume it.
    auto rb = ringbuffer::shm::load<TPerCpuRingBuffer>(name_id);
    TPerCpuConsumer per_cpu_consumer{rb};

    // SingleConsumer for ringbuffer at CPU 0.
    auto& cons = per_cpu_consumer.atCpu(0);

    int i = 0;
    while (i < 2000) {
      int value;
      ssize_t ret = cons.copy(value);
      EXPECT_EQ(ret, sizeof(value));
      EXPECT_EQ(value, i);
      ++i;
    }
  }

  // All done. Unlink to cleanup.
  ringbuffer::shm::unlink<TPerCpuRingBuffer>(name_id);
};

TEST(ShmPerCpuRingBuffer, SingleProducer_SingleConsumer) {
  // Make unique file name for shared memory
  auto base_name = shm::Segment::createTempDir("hbt_test");
  std::string name_id = base_name + "SingleProducer_SingleConsumer__test";

  int pid = fork();

  if (pid < 0) {
    HBT_THROW_SYSTEM(errno) << "Failed to fork";
  }

  if (pid == 0) {
    // children, the producer

    // XXX: buck test runner for gtests is hard-coded to expect only one
    // gtest summary, otherwise considers the test as failure.
    //
    // When terminating with exit(0), the calling process is terminated
    // without application level tear-down, therefore not completing
    // gtest logging.
    //
    // Leverage this behavior to hack a work-around to buck test hard-codeness.
    //
    { // Make a scope so shared_ptr's are released even on exit(0).

      // Set affinity of producer to CPU zero so that consumer only
      // has to read from that one CPU's buffer.
      cpu_set_t cpuset;
      CPU_ZERO(&cpuset);
      CPU_SET(0, &cpuset);
      sched_setaffinity(0, sizeof(cpu_set_t), &cpuset);

      // Shared memory segment is set to be non-persistent. It will be removed
      // when rb goes out of scope.
      auto rb = ringbuffer::shm::create<TPerCpuRingBuffer>(
          name_id, 1024, false, CpuSet::makeFromCpuSet(cpuset));
      TPerCpuProducer per_cpu_producer{rb};

      // SingleProducer for ringbuffer at CPU 0.
      auto& prod = per_cpu_producer.atCpu(0);

      int i = 0;
      while (i < 2000) {
        ssize_t ret = prod.write(i);
        if (ret == -ENOSPC) {
          std::this_thread::yield();
          continue;
        }
        EXPECT_EQ(ret, sizeof(i));
        ++i;
      }
      // Because of buffer size smaller than amount of data written, producer
      // cannot have completed the loop before consumer started consuming the
      // data. This guarantees that children can complete (and unlink before,
      // since it's set to be non-persistent) safely.
    }

    // Children exits. Careful when calling exit() directly, because it does not
    // call destructors. We ensured shared_ptrs were destroyed before by calling
    // exit(0).
    HBT_LOG_INFO() << "Children (producer). Start internal C++ teardown.";
    exit(0);
  } else {
    // parent, the consumer

    // wait for other process to create buffer, one second wait is long enough
    // to reasonably guarantee that the buffer has been created.
    sleep(1);
    auto rb = ringbuffer::shm::load<TPerCpuRingBuffer>(name_id);
    TPerCpuConsumer per_cpu_consumer{rb};

    // SingleConsumer for ringbuffer at CPU 0.
    auto& cons = per_cpu_consumer.atCpu(0);

    int i = 0;
    while (i < 2000) {
      int value;
      ssize_t ret = cons.copy(value);
      if (ret == -ENODATA) {
        std::this_thread::yield();
        continue;
      }
      EXPECT_EQ(ret, sizeof(value));
      EXPECT_EQ(value, i);
      ++i;
    }

    HBT_LOG_INFO() << "Start wait for children";
    // Wait for children to make gtest happy.
    wait(nullptr);
    HBT_LOG_INFO() << "Finished wait for children";
  }
};
