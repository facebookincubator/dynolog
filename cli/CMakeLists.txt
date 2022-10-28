# Copyright (c) Meta Platforms, Inc. and affiliates.

# Rust project build

# Locate cargo instance
find_program(CARGO cargo)

set(ARGS --target-dir ${CMAKE_BINARY_DIR})

# Add release or debug args
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(ARGS ${ARGS} --release)
endif()

add_custom_target(
    dyno
    COMMAND ${CARGO} build ${ARGS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
