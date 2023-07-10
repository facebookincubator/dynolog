# Copyright (c) Meta Platforms, Inc. and affiliates.
cmake_minimum_required(VERSION 3.16)

if(NOT USE_SYSTEM_PFS)
  include_directories(${PROJECT_SOURCE_DIR}/third_party/pfs/include)
endif()

add_subdirectory(common)
add_subdirectory(intel_pt)
add_subdirectory(perf_event)
add_subdirectory(mon)
