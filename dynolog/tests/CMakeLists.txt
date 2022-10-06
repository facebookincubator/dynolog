# (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

include(${PROJECT_SOURCE_DIR}/testing/BuildTests.cmake)

dynolog_add_test(KernelCollecterTest KernelCollecterTest.cpp)

add_subdirectory(rpc)
add_subdirectory(tracing)
