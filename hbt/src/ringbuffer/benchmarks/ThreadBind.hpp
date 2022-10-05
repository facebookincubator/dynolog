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
