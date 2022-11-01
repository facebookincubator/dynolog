// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <folly/Subprocess.h>
#include <gtest/gtest.h>

#include "hbt/src/common/System.h"
#include "pfs/task.hpp"

using namespace facebook::hbt;

TEST(ParseCmdLine, readProcFsCmdLine) {
  pid_t mypid = getpid();
  folly::Subprocess proc(
      {"/usr/bin/ps", "-p", std::to_string(mypid), "-o", "cmd="},
      folly::Subprocess::Options().pipeStdout());
  std::pair<std::string, std::string> output = proc.communicate();
  proc.wait();

  auto cmdline = output.first;
  if (cmdline.back() == '\n') {
    cmdline.pop_back();
  }

  auto pfsCmdline = readProcFsCmdLine(mypid);
  EXPECT_TRUE(pfsCmdline != std::nullopt);
  EXPECT_TRUE(pfsCmdline.value().compare(cmdline) == 0);

  EXPECT_TRUE(readProcFsCmdLine(0) == std::nullopt);
}
