# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

include(${PROJECT_SOURCE_DIR}/testing/BuildTests.cmake)

dynolog_add_test(KernelCollecterTest KernelCollecterTest.cpp)
dynolog_add_test(EthtoolStatsReaderTest EthtoolStatsReaderTest.cpp)
if(USE_PROMETHEUS)
  add_definitions(-DUSE_PROMETHEUS)
  dynolog_add_test(PrometheusLoggerTest PrometheusLoggerTest.cpp)
endif()
if(USE_OTLP)
  dynolog_add_test(OTLPLoggerTest OtlpMetricsLoggerTest.cpp)
  target_compile_definitions(OTLPLoggerTest PRIVATE USE_OTLP)
  option(OTLP_INTEGRATION_TEST
    "Enable OTLP integration tests (requires Docker)"
    OFF)
  if(OTLP_INTEGRATION_TEST)
    target_compile_definitions(OTLPLoggerTest PRIVATE OTLP_INTEGRATION_TEST)
  endif()
endif()

add_subdirectory(rpc)
add_subdirectory(tracing)
add_subdirectory(metric_frame)
