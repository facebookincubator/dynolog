# Copyright (c) Meta Platforms, Inc. and affiliates.

include_directories(${PROJECT_SOURCE_DIR})

add_library(IptEventBuilder IptEventBuilder.h IptEventBuilder.cpp)
target_link_libraries(IptEventBuilder PUBLIC PmuDevices)
target_link_libraries(IptEventBuilder PUBLIC PmuEvent)

add_subdirectory(tests)
