# Copyright (c) Meta Platforms, Inc. and affiliates.

add_compile_options("-Wconversion")

include_directories(${PROJECT_SOURCE_DIR}/third_party/googletest/googletest/include)

add_executable(CpuEventsGroupTest CpuEventsGroupTest.cpp)
target_link_libraries(CpuEventsGroupTest PRIVATE gtest gmock gtest_main)
target_link_libraries(CpuEventsGroupTest PUBLIC stdc++fs)
target_link_libraries(CpuEventsGroupTest PUBLIC CpuEventsGroup)

# add_executable(PmuDevicesTest PmuDevicesTest.cpp)
# target_link_libraries(PmuDevicesTest PRIVATE gtest gmock gtest_main)
# target_link_libraries(PmuDevicesTest PUBLIC PerCpuCountSampleGenerator)
# target_link_libraries(PmuDevicesTest PUBLIC PmuDevices)

# add_executable(MetricsTest BuiltinMetricsTest.cpp)
# target_link_libraries(MetricsTest PRIVATE gtest gmock gtest_main)
# target_link_libraries(MetricsTest BuiltinMetrics)
# target_link_libraries(MetricsTest PerCpuCountSampleGenerator)

# add_executable(ClocksTest ClocksTest.cpp)
# target_link_libraries(ClocksTest PRIVATE gtest gmock gtest_main)
# target_link_libraries(ClocksTest PUBLIC BuiltinMetrics)
# target_link_libraries(ClocksTest PUBLIC PerCpuCountSampleGenerator)
# target_link_libraries(ClocksTest PUBLIC PerCpuThreadSwitchGenerator)
# target_link_libraries(ClocksTest PUBLIC RingBuffer)
