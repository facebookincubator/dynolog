# Copyright (c) Meta Platforms, Inc. and affiliates.

include(${PROJECT_SOURCE_DIR}/testing/BuildTests.cmake)

dynolog_add_test(KernelCollecterTest KernelCollecterTest.cpp)
if(USE_PROMETHEUS)
  add_definitions(-DUSE_PROMETHEUS)
  dynolog_add_test(PrometheusLoggerTest PrometheusLoggerTest.cpp)
endif()

add_subdirectory(rpc)
add_subdirectory(tracing)
add_subdirectory(metric_frame)
