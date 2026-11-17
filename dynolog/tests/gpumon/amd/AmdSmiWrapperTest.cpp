/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/amd/AmdSmiWrapper.h"
#include <gtest/gtest.h>

using namespace ::dynolog::gpumon;

TEST(AmdSmiWrapperTest, notInitializedByDefault) {
  AmdSmiWrapper wrapper;
  EXPECT_FALSE(wrapper.isInitialized());
}

TEST(AmdSmiWrapperTest, getMetricsThrowsBeforeInit) {
  AmdSmiWrapper wrapper;
  EXPECT_THROW(wrapper.getMetrics(), std::runtime_error);
}
