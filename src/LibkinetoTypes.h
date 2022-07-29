// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.
#pragma once

#include <vector>

namespace dynolog {

enum class LibkinetoConfigType {
  NONE = 0,
  EVENTS = 1,
  ACTIVITIES = 2,
};

struct GpuProfilerResult {
  std::vector<int32_t> processesMatched;
  std::vector<int32_t> eventProfilersTriggered;
  std::vector<int32_t> activityProfilersTriggered;
  int32_t eventProfilersBusy;
  int32_t activityProfilersBusy;
};

} // namespace dynolog
