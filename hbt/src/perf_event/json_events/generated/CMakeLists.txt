# Copyright (c) Meta Platforms, Inc. and affiliates.

add_library(CpuArchGen CpuArch.h)
set_target_properties(CpuArchGen PROPERTIES LINKER_LANGUAGE CXX)

if(USE_JSON_GENERATED_PERF_EVENTS)
  add_subdirectory(intel)
endif()
