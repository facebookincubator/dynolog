// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"

#include <pthread.h>
#include <thread>

namespace {

inline void threadBind(
    std::thread& thread,
    const facebook::hbt::CpuSet& cpuSet) {
  pthread_setaffinity_np(
      thread.native_handle(), sizeof(cpu_set_t), &cpuSet.cpu_set);
}

} // end of namespace
