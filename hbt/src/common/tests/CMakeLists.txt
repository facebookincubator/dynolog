# Copyright (c) Meta Platforms, Inc. and affiliates.

include(${PROJECT_SOURCE_DIR}/testing/BuildTests.cmake)
macro(hbt_common_add_test TESTNAME)
  dynolog_add_test_base(${TESTNAME} ${ARGN})
  target_compile_options(${TESTNAME} PRIVATE ${HBT_COMMON_COMPILE_OPTIONS})
  target_include_directories(${TESTNAME} PRIVATE ${PROJECT_SOURCE_DIR})
endmacro()

hbt_common_add_test(DefsTest DefsTest.cpp)
target_link_libraries(DefsTest PRIVATE Defs)

hbt_common_add_test(SystemTest SystemTest.cpp)
target_link_libraries(SystemTest PRIVATE System)

# todo: include folly:subprocess library (or alternative) for SystemProcFsTest.cpp
