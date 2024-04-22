# Copyright (c) Meta Platforms, Inc. and affiliates.

add_compile_options("-Wconversion")
if(USE_JSON_GENERATED_PERF_EVENTS)
  add_definitions(-DUSE_JSON_GENERATED_PERF_EVENTS)
endif()

add_subdirectory(json_events)
add_subdirectory(tests)

include_directories(${PROJECT_SOURCE_DIR})

add_library(CpuArch CpuArch.h)
set_target_properties(CpuArch PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(CpuArch PUBLIC CpuArchGen)

add_library(PmuEvent PmuEvent.h PmuEvent.cpp)
target_link_libraries(PmuEvent PUBLIC System)

add_library(AmdEvents AmdEvents.h AmdEvents.cpp)
target_link_libraries(AmdEvents PUBLIC PmuDevices)

add_library(ArmEvents ArmEvents.h ArmEvents.cpp)
target_link_libraries(ArmEvents PUBLIC PmuDevices)

add_library(PerfEventsGroup PerfEventsGroup.h)
target_link_libraries(PerfEventsGroup PUBLIC System)
target_link_libraries(PerfEventsGroup PUBLIC PmuEvent)

add_library(PmuDevices PmuDevices.h PmuDevices.cpp)
target_link_libraries(PmuDevices PUBLIC PerfEventsGroup)
target_link_libraries(PmuDevices PUBLIC stdc++fs)
target_link_libraries(PmuDevices PUBLIC PmuEvent)
target_link_libraries(PmuDevices PUBLIC CpuArch)

add_library(Metrics Metrics.h Metrics.cpp)
target_link_libraries(Metrics PUBLIC PmuDevices)
target_link_libraries(Metrics PUBLIC CpuArch)

add_library(BuiltinMetrics BuiltinMetrics.h BuiltinMetrics.cpp)
target_link_libraries(BuiltinMetrics
                        PUBLIC AmdEvents
                        PUBLIC ArmEvents
                        PUBLIC PmuDevices
                        PUBLIC System
                        PUBLIC IptEventBuilder
                        PUBLIC Metrics
                        PUBLIC CpuArch)
if(USE_JSON_GENERATED_PERF_EVENTS)
  target_link_libraries(BuiltinMetrics PUBLIC JsonEvents)
endif()

add_library(PerPerfEventsGroupBase PerPerfEventsGroupBase.h)
target_link_libraries(PerPerfEventsGroupBase PUBLIC PerfEventsGroup)
target_link_libraries(PerPerfEventsGroupBase PUBLIC Metrics)

add_library(PerCpuBase PerCpuBase.h)
target_link_libraries(PerCpuBase PerPerfEventsGroupBase)

add_library(PerCpuCountReader PerCpuCountReader.h)
target_link_libraries(PerCpuCountReader PUBLIC PerCpuBase)

add_library(ThreadCountReader ThreadCountReader.h)
target_link_libraries(ThreadCountReader PUBLIC PerfEventsGroup)
target_link_libraries(ThreadCountReader PUBLIC Metrics)

add_library(PerCpuSampleGeneratorBase PerCpuSampleGeneratorBase.h)
target_link_libraries(PerCpuSampleGeneratorBase PUBLIC PerCpuBase)

add_library(PerCpuCountSampleGenerator PerCpuCountSampleGenerator.h)
target_link_libraries(PerCpuCountSampleGenerator PUBLIC
    PerCpuSampleGeneratorBase)
target_link_libraries(PerCpuCountSampleGenerator PUBLIC PerCpuRingBuffer)
target_link_libraries(PerCpuCountSampleGenerator PUBLIC Event)

add_library(PerCpuThreadSwitchGenerator PerCpuThreadSwitchGenerator.h)
target_link_libraries(PerCpuThreadSwitchGenerator PUBLIC
    PerCpuSampleGeneratorBase)
target_link_libraries(PerCpuThreadSwitchGenerator PUBLIC PerCpuRingBuffer)
target_link_libraries(PerCpuThreadSwitchGenerator PUBLIC ProcFsHelpers)
target_link_libraries(PerCpuThreadSwitchGenerator PUBLIC Event)
target_link_libraries(PerCpuThreadSwitchGenerator PUBLIC ValueTimeSeries)

add_library(PerCpuDummyGenerator PerCpuDummyGenerator.h)
target_link_libraries(PerCpuDummyGenerator PUBLIC PerCpuSampleGeneratorBase)
target_link_libraries(PerCpuDummyGenerator PUBLIC System)

add_library(PerCpuTraceAuxGenerator PerCpuTraceAuxGenerator.h)
target_link_libraries(PerCpuTraceAuxGenerator PUBLIC PerCpuSampleGeneratorBase)
