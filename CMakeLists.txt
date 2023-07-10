# Copyright (c) Meta Platforms, Inc. and affiliates.
cmake_minimum_required(VERSION 3.16)

project(Dynolog VERSION 1.0)
option(BUILD_TESTS "Build the unit tests" ON)
option(USE_ODS_GRAPH_API "Enable logger to Meta ODS using public Graph API."
  OFF)
option(USE_JSON_GENERATED_PERF_EVENTS "Add performance events generated using
Intel json spec, see hbt/src/perf_event/json_events/intel"
  OFF)
option(USE_SYSTEM_LIBS "Use system libraries" OFF)
option(USE_SYSTEM_GOOGLETEST "Use system-provided Google Test" ${USE_SYSTEM_LIBS})
option(USE_SYSTEM_GLOG "Use system-provided glog" ${USE_SYSTEM_LIBS})
option(USE_SYSTEM_GFLAGS "Use system-provided gflags" ${USE_SYSTEM_LIBS})
option(USE_SYSTEM_JSON "Use system-provided json" ${USE_SYSTEM_LIBS})
option(USE_SYSTEM_PFS "Use system-provided pfs" ${USE_SYSTEM_LIBS})
option(USE_SYSTEM_FMT "Use system-provided fmt" ${USE_SYSTEM_LIBS})
option(USE_SYSTEM_CPR "Use system-provided cpr" ${USE_SYSTEM_LIBS})

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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

if(BUILD_TESTS)
  enable_testing()

  if(USE_SYSTEM_GOOGLETEST)
    find_package(GTest REQUIRED)
  else()
    add_subdirectory(third_party/googletest)
  endif()
endif()

include_directories(".")
add_subdirectory(dynolog)
add_subdirectory(cli)

# The following dummy depdendency ensures the cli is built
add_dependencies(dynolog_lib dyno)
add_subdirectory(hbt)

# Third party deps
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
set(BUILD_SAMPLES OFF CACHE BOOL "")
set(BUILD_TEST OFF CACHE BOOL "")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "")

set(BUILD_TESTING OFF CACHE BOOL "")
set(WITH_GFLAGS OFF CACHE BOOL "")

if(USE_SYSTEM_GLOG)
  find_package(glog REQUIRED)
else()
  add_subdirectory(third_party/glog)
endif()

target_link_libraries(dynolog_lib PUBLIC glog::glog)

set(GFLAGS_BUILD_TESTING OFF CACHE BOOL "")

if(USE_SYSTEM_GFLAGS)
  find_package(gflags REQUIRED)
else()
  add_subdirectory(third_party/gflags)
endif()

target_link_libraries(dynolog_lib PUBLIC gflags::gflags)

# https://github.com/nlohmann/json#cmake
set(JSON_BuildTests OFF CACHE INTERNAL "")

if(USE_SYSTEM_JSON)
  find_package(nlohmann_json REQUIRED)
else()
  add_subdirectory(third_party/json)
endif()

target_link_libraries(dynolog_lib PUBLIC nlohmann_json::nlohmann_json)

if(USE_SYSTEM_PFS)
  find_package(pfs REQUIRED)
else()
  add_subdirectory(third_party/pfs)
  target_include_directories(dynolog_lib PUBLIC third_party/pfs/include)
endif()

target_link_libraries(dynolog_lib PUBLIC pfs)

if(USE_SYSTEM_FMT)
  find_package(fmt REQUIRED)
else()
  add_subdirectory(third_party/fmt)
endif()

target_link_libraries(dynolog_lib PUBLIC fmt::fmt)

if(USE_ODS_GRAPH_API)
  if(USE_SYSTEM_CPR)
    find_package(cpr REQUIRED)
  else()
    add_subdirectory(third_party/cpr)
  endif()

  target_link_libraries(dynolog_lib PUBLIC cpr::cpr)
endif()