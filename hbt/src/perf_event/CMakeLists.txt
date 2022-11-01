# Copyright (c) Meta Platforms, Inc. and affiliates.

add_compile_options("-Wconversion")

add_subdirectory(json_events)
add_subdirectory(tests)

include_directories(${PROJECT_SOURCE_DIR})

add_library(PmuEvent PmuEvent.h PmuEvent.cpp)
target_link_libraries(PmuEvent PUBLIC System)

add_library(AmdEvents AmdEvents.h AmdEvents.cpp)
target_link_libraries(AmdEvents PUBLIC PmuDevices)

add_library(CpuEventsGroup CpuEventsGroup.h)
target_link_libraries(CpuEventsGroup PUBLIC System)
target_link_libraries(CpuEventsGroup PUBLIC PmuEvent)

add_library(PmuDevices PmuDevices.h PmuDevices.cpp)
target_link_libraries(PmuDevices PUBLIC CpuEventsGroup)
target_link_libraries(PmuDevices PUBLIC stdc++fs)
target_link_libraries(PmuDevices PUBLIC PmuEvent)
target_link_libraries(PmuDevices PUBLIC CpuArch)

add_library(Metrics Metrics.h Metrics.cpp)
target_link_libraries(Metrics PUBLIC PmuDevices)
target_link_libraries(Metrics PUBLIC CpuArch)

add_library(BuiltinMetrics BuiltinMetrics.h BuiltinMetrics.cpp)
target_link_libraries(BuiltinMetrics
                        PUBLIC AmdEvents
                        PUBLIC PmuDevices
                        PUBLIC System
                        PUBLIC IptEventBuilder
                        PUBLIC JsonEvents
                        PUBLIC Metrics
                        PUBLIC CpuArch)

add_library(PerCpuBase PerCpuBase.h)
target_link_libraries(PerCpuBase PUBLIC CpuEventsGroup)
target_link_libraries(PerCpuBase PUBLIC Metrics)

add_library(PerCpuCountReader PerCpuCountReader.h)
target_link_libraries(PerCpuCountReader PUBLIC PerCpuBase)

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
target_link_libraries(PerCpuThreadSwitchGenerator PUBLIC Event)
target_link_libraries(PerCpuThreadSwitchGenerator PUBLIC ValueTimeSeries)

add_library(PerCpuDummyGenerator PerCpuDummyGenerator.h)
target_link_libraries(PerCpuDummyGenerator PUBLIC PerCpuSampleGeneratorBase)
target_link_libraries(PerCpuDummyGenerator PUBLIC System)

add_library(PerCpuTraceAuxGenerator PerCpuTraceAuxGenerator.h)
target_link_libraries(PerCpuTraceAuxGenerator PUBLIC PerCpuSampleGeneratorBase)
