#include "hbt/src/common/Defs.h"

#include <gtest/gtest.h>

TEST(Defs, Exception) {
  EXPECT_THROW(HBT_THROW_EINVAL(), std::invalid_argument);
  EXPECT_THROW(HBT_THROW_EINVAL() << "hola", std::invalid_argument);
  EXPECT_THROW(HBT_THROW_EINVAL() << "adioshola", std::invalid_argument);
  EXPECT_THROW(HBT_THROW_SYSTEM(ENODATA) << "adioshola", std::system_error);
  EXPECT_THROW(HBT_THROW_SYSTEM(EBUSY), std::system_error);
  EXPECT_THROW(HBT_THROW_SYSTEM(EBUSY) << "my message", std::system_error);
}
