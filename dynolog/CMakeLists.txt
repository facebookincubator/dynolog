# (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.
cmake_minimum_required(VERSION 3.20)

project(Dynolog VERSION 1.0)
option(BUILD_TESTS "Build the unit tests" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

if(BUILD_TESTS)
  add_subdirectory("${PROJECT_SOURCE_DIR}/third_party/googletest"
  "third_party/googletest")
endif()

# our build script will first create a src/ dir where all source code will exist
file (GLOB dynomin_src "src/*.h" "src/*.cpp")
include_directories("${PROJECT_SOURCE_DIR}/src/")

# Remove main from library, only needed for exec.
list(REMOVE_ITEM dynomin_src "src/Main.cc")
add_library(dynolog_lib ${dynomin_src})

add_subdirectory(src/rpc)
include_directories("${PROJECT_SOURCE_DIR}/src/rpc")

add_subdirectory(src/ipcfabric)
target_link_libraries(dynolog_lib PUBLIC dynolog_ipcfabric_lib)

# depends on ipcfabric
add_subdirectory(src/tracing)
target_link_libraries(dynolog_lib PUBLIC dynolog_ipcmonitor_lib)

# cli is written in Rust and uses cargo for build
add_subdirectory(src/cli)
add_dependencies(dynolog_lib dyno2)

# Third party deps
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
set(BUILD_SAMPLES OFF CACHE BOOL "")
set(BUILD_TEST OFF CACHE BOOL "")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "")

set(GFLAGS_BUILD_TESTING OFF CACHE BOOL "")
add_subdirectory(third_party/gflags)
target_link_libraries(dynolog_lib PUBLIC gflags::gflags)

set(BUILD_TESTING OFF CACHE BOOL "")
add_subdirectory(third_party/glog)
target_link_libraries(dynolog_lib PUBLIC glog::glog)

# https://github.com/nlohmann/json#cmake
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(third_party/json)
target_link_libraries(dynolog_lib PUBLIC nlohmann_json::nlohmann_json)

add_subdirectory(third_party/pfs)
target_include_directories(dynolog_lib PUBLIC third_party/pfs/include)
target_link_libraries(dynolog_lib PUBLIC pfs)

add_subdirectory(third_party/fmt)
target_link_libraries(dynolog_lib PUBLIC fmt::fmt)

set(BUILD_SAMPLES OFF CACHE BOOL "")
add_subdirectory(third_party/range-v3)
#target_link_libraries(dynolog_lib PUBLIC range-v3)

add_executable(dynomin src/Main.cpp)
target_link_libraries(dynomin PRIVATE dynolog_lib dynolog_rpc_lib)

add_subdirectory(hbt/src/common)

# ------------------------------------------------------------
# Unit testing
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
