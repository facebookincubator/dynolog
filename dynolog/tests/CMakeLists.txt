# Copyright (c) Meta Platforms, Inc. and affiliates.

include(${PROJECT_SOURCE_DIR}/testing/BuildTests.cmake)

dynolog_add_test(KernelCollecterTest KernelCollecterTest.cpp)

add_subdirectory(rpc)
add_subdirectory(tracing)
add_subdirectory(metric_frame)
