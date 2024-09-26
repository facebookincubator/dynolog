// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include "dynolog/src/gpumon/amd/RdcWrapper.h"
#include <gtest/gtest.h>

using namespace ::testing;
using namespace ::dynolog::gpumon;

class RdcRuntimeContextSynchronizedTest : public RdcRuntimeContextSynchronized {
 public:
  std::shared_mutex& getMutex() {
    return sharedDataLock_;
  }
};

TEST(RdcWrapperTest, testRdcRuntimeContextSynchronized) {
  RdcRuntimeContextSynchronizedTest t;
  {
    // two readers
    auto a = t.rlock();
    std::shared_lock<std::shared_mutex> b(t.getMutex(), std::defer_lock);
    EXPECT_TRUE(b.try_lock());
  }

  {
    // two writers
    auto a = t.wlock();
    std::unique_lock<std::shared_mutex> b(t.getMutex(), std::defer_lock);
    EXPECT_FALSE(b.try_lock());
  }

  {
    // reader then writer
    auto a = t.rlock();
    std::unique_lock<std::shared_mutex> b(t.getMutex(), std::defer_lock);
    EXPECT_FALSE(b.try_lock());
  }

  { auto a = t.rlock(); }
  // lock released outside of scope
  std::unique_lock<std::shared_mutex> b(t.getMutex(), std::defer_lock);
  EXPECT_TRUE(b.try_lock());
}
