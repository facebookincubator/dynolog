# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

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
