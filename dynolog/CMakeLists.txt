# Copyright (c) Meta Platforms, Inc. and affiliates.
cmake_minimum_required(VERSION 3.16)

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
