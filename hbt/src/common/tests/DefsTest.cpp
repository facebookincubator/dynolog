// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/common/Defs.h"

#include <gtest/gtest.h>
#include <stdexcept>

TEST(Defs, Exception) {
  EXPECT_THROW(HBT_THROW_EINVAL(), std::invalid_argument);
  EXPECT_THROW(HBT_THROW_EINVAL() << "hola", std::invalid_argument);
  EXPECT_THROW(HBT_THROW_EINVAL() << "adioshola", std::invalid_argument);
  EXPECT_THROW(HBT_THROW_SYSTEM(ENODATA) << "adioshola", std::system_error);
  EXPECT_THROW(HBT_THROW_SYSTEM(EBUSY), std::system_error);
  EXPECT_THROW(HBT_THROW_SYSTEM(EBUSY) << "my message", std::system_error);
  EXPECT_THROW(HBT_DCHECK_NOT_NULLPTR(nullptr), std::runtime_error);
  EXPECT_NO_THROW(HBT_DCHECK_NOT_NULLPTR((void*)1));
}
