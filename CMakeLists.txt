# (c) Meta Platforms, Inc. and affiliates.
cmake_minimum_required(VERSION 3.20)

project(Dynolog VERSION 1.0)
option(BUILD_TESTS "Build the unit tests" ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory("third_party/googletest" "third_party/googletest")
endif()

include_directories(".")
add_subdirectory(dynolog)
add_subdirectory(cli)
# The following dummy depdendency ensures the cli is built
add_dependencies(dynolog_lib dyno2)
add_subdirectory(hbt)

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
