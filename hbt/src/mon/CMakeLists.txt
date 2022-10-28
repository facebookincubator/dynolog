# Copyright (c) Meta Platforms, Inc. and affiliates.

add_compile_options("-Wconversion")

add_library(Monitor Monitor.h)
set_target_properties(Monitor PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Monitor PUBLIC System)
target_link_libraries(Monitor PUBLIC IntelPTMonitor)
target_link_libraries(Monitor PUBLIC MonData)

add_library(IntelPTMonitor IntelPTMonitor.h IntelPTMonitor.cpp)
target_link_libraries(IntelPTMonitor PUBLIC System)
target_link_libraries(IntelPTMonitor PUBLIC Defaults)
target_link_libraries(IntelPTMonitor PUBLIC IptEventBuilder)
target_link_libraries(IntelPTMonitor PUBLIC PerCpuTraceAuxGenerator)

add_library(MonData MonData.h MonData.cpp)
target_link_libraries(MonData PUBLIC pfs)
target_link_libraries(MonData PUBLIC System)

add_subdirectory(tests)

add_library(PerCpuSliceGenerator PerCpuSliceGenerator.h)
set_target_properties(PerCpuSliceGenerator PROPERTIES LINKER_LANGUAGE CXX)
