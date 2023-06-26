// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>

#include "dynolog/src/metric_frame/TextTable.h"

using namespace ::testing;
using namespace ::facebook::dynolog;

/*
-------------------------------
|         |    t1 |  t2 |  t3 |
--------------------------
| metric1 |    12 |  21 |  38 |
--------------------------
| metric2 | 17423 | 992 | 157 |
-------------------------------
*/

TEST(TextTableTest, checkOutputHasRightShape) {
  std::vector<std::vector<std::string>> data = {
      {"", "t1", "t2", "t3"},
      {"metric1", "12", "21", "38"},
      {"metric2", "17423", "992", "157"}};

  TextTable t(std::move(data));
  std::stringstream s;

  t.show(s);
  size_t nLine = 0;
  auto output = s.str();
  int lastLineWidth = -1;
  while (true) {
    auto nl = output.find('\n');
    if (nl == std::string::npos) {
      break;
    }
    nLine++;
    EXPECT_TRUE(lastLineWidth == -1 || lastLineWidth == nl);
    lastLineWidth = nl;
    output = output.substr(nl + 1, output.size() - nl - 1);
  }
  EXPECT_EQ(nLine, 7);
}
