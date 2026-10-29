// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "pfs/procfs.hpp"

#include <optional>
#include <string>
#include <system_error>

namespace facebook::hbt {

inline std::optional<std::string> readProcFsCmdLine(pid_t tid) noexcept {
  pfs::procfs pfs;
  try {
    auto vec = pfs.get_task(tid).get_cmdline();
    std::string cmdline;
    for (size_t i = 0; i < vec.size(); ++i) {
      if (i > 0) {
        cmdline += ' ';
      }
      cmdline += vec[i];
    }
    return cmdline;
  } catch (const std::system_error&) {
    return std::nullopt;
  }
}

} // namespace facebook::hbt
