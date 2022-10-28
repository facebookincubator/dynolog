# Copyright (c) Meta Platforms, Inc. and affiliates.

add_compile_options("-Wconversion")
add_compile_options("-Wconversion-null")

add_executable(MonitorTest MonitorTest.cpp)
target_link_libraries(MonitorTest PUBLIC Monitor)
target_link_libraries(MonitorTest PUBLIC BuiltinMetrics)
target_link_libraries(MonitorTest PRIVATE gtest gmock gtest_main)
