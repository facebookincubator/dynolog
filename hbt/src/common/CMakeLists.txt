# Copyright (c) Meta Platforms, Inc. and affiliates.

add_compile_options("-Wconversion")

add_library(Defs Defs.h)
set_target_properties(Defs PROPERTIES LINKER_LANGUAGE CXX)

add_library(System System.h System.cpp)
target_include_directories(System PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(System PUBLIC fmt::fmt)
target_link_libraries(System PUBLIC pfs)
target_link_libraries(System PUBLIC Defs)
target_link_libraries(System PUBLIC CpuArch)

add_library(Defaults Defaults.h)
set_target_properties(Defaults PROPERTIES LINKER_LANGUAGE CXX)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
