/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "dynolog/src/String.h"

using facebook::dynolog::split;

TEST(StringTest, Example) {
  const std::string line = "hello world";
  std::vector<std::string> tokens = split(line, ' ');

  const std::vector<std::string> expected = {"hello", "world"};
  EXPECT_EQ(tokens, expected);
}

TEST(StringTest, Empty) {
  const std::string line;
  std::vector<std::string> tokens = split(line, ' ');

  EXPECT_TRUE(tokens.empty());
}

TEST(StringTest, SkipEmpty) {
  const std::string line = " 1 2     3 ";
  std::vector<std::string> tokens = split(line, ' ');

  const std::vector<std::string> expected = {"1", "2", "3"};
  EXPECT_EQ(tokens, expected);
}

TEST(StringTest, Single) {
  const std::string line = "1 2 3";
  std::vector<std::string> tokens = split(line, ',');

  const std::vector<std::string> expected = {"1 2 3"};
  EXPECT_EQ(tokens, expected);
}
