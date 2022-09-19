# (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

include(BuildTests.cmake)
dynolog_add_test(KernelCollecterTest KernelCollecterTest.cpp)

add_subdirectory(rpc)
