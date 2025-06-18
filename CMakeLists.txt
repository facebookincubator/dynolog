# Copyright (c) Meta Platforms, Inc. and affiliates.
cmake_minimum_required(VERSION 3.16)

cmake_policy(SET CMP0079 NEW)
project(Dynolog VERSION 1.0 LANGUAGES CXX)
option(BUILD_TESTS "Build the unit tests" ON)
option(USE_ODS_GRAPH_API "Enable logger to Meta ODS using public Graph API."
OFF)
option(USE_JSON_GENERATED_PERF_EVENTS "Add performance events generated using
Intel json spec, see hbt/src/perf_event/json_events/intel"
OFF)
option(USE_PROMETHEUS "Enable logging to prometheus, this requires
prometheus-cpp to be installed on the system"
OFF)

if(USE_PROMETHEUS)
  find_package(prometheus-cpp CONFIG REQUIRED)
endif()

file(READ "version.txt" DYNOLOG_VERSION)
string(STRIP ${DYNOLOG_VERSION} DYNOLOG_VERSION)

execute_process(
  COMMAND git rev-parse --short HEAD
  OUTPUT_VARIABLE DYNOLOG_GIT_REV
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(DYNOLOG_VERSION "\"${DYNOLOG_VERSION}\"")
set(DYNOLOG_GIT_REV "\"${DYNOLOG_GIT_REV}\"")
message("Dynolog version = ${DYNOLOG_VERSION}")
message("Dynolog git rev = ${DYNOLOG_GIT_REV}")

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE True)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third_party/googletest)
endif()

include_directories(".")
add_subdirectory(dynolog)
add_subdirectory(cli)
# The following dummy dependency ensures the cli is built
add_dependencies(dynolog_lib dyno)
add_subdirectory(hbt)

# Third party deps
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
set(BUILD_SAMPLES OFF CACHE BOOL "")
set(BUILD_TEST OFF CACHE BOOL "")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "")

set(BUILD_TESTING OFF CACHE BOOL "")
set(WITH_GFLAGS OFF CACHE BOOL "")
find_package(Threads REQUIRED)
target_link_libraries(dynolog_lib PRIVATE Threads::Threads)
add_subdirectory(third_party/glog)
target_link_libraries(dynolog_lib PUBLIC glog::glog)

set(GFLAGS_BUILD_TESTING OFF CACHE BOOL "")
add_subdirectory(third_party/gflags)
target_link_libraries(dynolog_lib PUBLIC gflags::gflags)

# https://github.com/nlohmann/json#cmake
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(third_party/json)
target_link_libraries(dynolog_lib PUBLIC nlohmann_json::nlohmann_json)

add_subdirectory(third_party/pfs)
target_include_directories(dynolog_lib PUBLIC third_party/pfs/include)
target_link_libraries(dynolog_lib PUBLIC pfs)

add_subdirectory(third_party/fmt)
target_link_libraries(dynolog_lib PUBLIC fmt::fmt)

if(USE_ODS_GRAPH_API)
  add_subdirectory(third_party/cpr)
  target_link_libraries(dynolog_lib PUBLIC cpr::cpr)
endif()
