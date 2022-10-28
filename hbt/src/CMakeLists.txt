# Copyright (c) Meta Platforms, Inc. and affiliates.
cmake_minimum_required(VERSION 3.20)

include_directories(${PROJECT_SOURCE_DIR}/third_party/pfs/include)

add_subdirectory(common)
add_subdirectory(intel_pt)
add_subdirectory(perf_event)
add_subdirectory(mon)
