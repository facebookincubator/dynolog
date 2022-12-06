// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <sys/types.h>
#include <unistd.h>
#include <vector>

namespace dynolog {

std::vector<pid_t> getPidsOnGpu();

} // namespace dynolog
