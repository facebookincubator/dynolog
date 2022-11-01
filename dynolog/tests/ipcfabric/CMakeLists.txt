# Copyright (c) Meta Platforms, Inc. and affiliates.

include(${PROJECT_SOURCE_DIR}/tests/BuildTests.cmake)

macro(ipcfabric_add_test TESTNAME)
    dynolog_add_test_base(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE dynolog_ipcfabric_lib)
    target_link_libraries(${TESTNAME} PRIVATE glog::glog)
    target_include_directories(${TESTNAME} PRIVATE
    "${PROJECT_SOURCE_DIR}/src/ipcfabric")
endmacro()

ipcfabric_add_test(IPCFabricTest IPCFabricTest.cpp)

add_executable(ipcsender IPCSender.cpp)
target_link_libraries(ipcsender PRIVATE dynolog_ipcfabric_lib glog)
