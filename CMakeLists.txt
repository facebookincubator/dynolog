# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

cmake_minimum_required(VERSION 3.16)

cmake_policy(SET CMP0079 NEW)
project(Dynolog VERSION 1.0 LANGUAGES CXX)

# Same compiler floor as PyTorch, which Dynolog's Kineto integration builds
# against.
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 11.3)
  message(FATAL_ERROR
    "GCC 11.3 or newer is required to compile Dynolog, but found ${CMAKE_CXX_COMPILER_VERSION}")
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 16)
  message(FATAL_ERROR
    "Clang 16 or newer is required to compile Dynolog, but found ${CMAKE_CXX_COMPILER_VERSION}")
endif()

option(BUILD_TESTS "Build the unit tests" ON)
option(USE_ODS_GRAPH_API "Enable logger to Meta ODS using public Graph API."
OFF)
option(USE_JSON_GENERATED_PERF_EVENTS "Add performance events generated using
Intel json spec, see hbt/src/perf_event/json_events/intel"
OFF)
option(USE_PROMETHEUS "Enable logging to prometheus, this requires
prometheus-cpp to be installed on the system"
OFF)
option(USE_OTLP "Enable OTLP metrics export" OFF)
option(USE_OTEL "Enable OTLP export via OpenTelemetry, requires
libprotobuf-dev and libcurl4-openssl-dev on the system"
OFF)
option(USE_TPU "Enable TPU metrics scraping, requires libcurl" OFF)
option(BUILD_DYNO_CLI "Build the dyno CLI (Rust, requires cargo) with dynolog"
ON)

# CMake 4 rejects projects whose cmake_minimum_required is below 3.5, which
# includes some vendored third_party dependencies (e.g. gflags). Let them
# configure unless the caller chose a minimum explicitly. Older CMake versions
# ignore this variable.
if(NOT DEFINED CMAKE_POLICY_VERSION_MINIMUM)
  set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
endif()

if(USE_PROMETHEUS)
  find_package(prometheus-cpp CONFIG REQUIRED)
endif()

if(USE_OTLP)
  find_package(CURL REQUIRED)
  include(cmake/OTLPProto.cmake)
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

# C++20 requires GCC >= 10 or Clang >= 10
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE True)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third_party/googletest)
endif()

include_directories(".")
add_subdirectory(dynolog)
if(BUILD_DYNO_CLI)
  add_subdirectory(cli)
  # The following dummy dependency ensures the cli is built
  add_dependencies(dynolog_lib dyno)
endif()
add_subdirectory(hbt)

# Third party deps
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
set(BUILD_SAMPLES OFF CACHE BOOL "")
set(BUILD_TEST OFF CACHE BOOL "")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "")

set(BUILD_TESTING OFF CACHE BOOL "")
find_package(Threads REQUIRED)
target_link_libraries(dynolog_lib PRIVATE Threads::Threads)

# Add gflags before glog so glog registers its flags (--logtostderr, --v,
# ...) with gflags. glog looks for gflags with find_package(), which cannot
# see a sibling subproject, so answer it with a config file that reports the
# in-tree gflags as found. The namespace is preset because glog's probe for
# it links a gflags library that is not built yet.
set(GFLAGS_BUILD_TESTING OFF CACHE BOOL "")
add_subdirectory(third_party/gflags)
target_link_libraries(dynolog_lib PUBLIC gflags::gflags)

get_directory_property(_gflags_version
  DIRECTORY third_party/gflags DEFINITION PACKAGE_VERSION)
set(_gflags_config_dir "${CMAKE_CURRENT_BINARY_DIR}/gflags-config")
file(WRITE "${_gflags_config_dir}/gflags-config.cmake"
  "set(gflags_FOUND TRUE)\n")
file(WRITE "${_gflags_config_dir}/gflags-config-version.cmake"
  "set(PACKAGE_VERSION \"${_gflags_version}\")\n"
  "set(PACKAGE_VERSION_COMPATIBLE TRUE)\n")
set(gflags_DIR "${_gflags_config_dir}" CACHE PATH "" FORCE)
set(gflags_NAMESPACE gflags CACHE INTERNAL "")
set(WITH_GFLAGS ON CACHE BOOL "")
add_subdirectory(third_party/glog)
target_link_libraries(dynolog_lib PUBLIC glog::glog)

# glog's export rules reject a link to the in-tree gflags target, which
# gflags exports twice. Dynolog exports nothing, so link glog's users to the
# gflags library file instead and give them its generated headers.
get_target_property(_gflags_target gflags::gflags ALIASED_TARGET)
get_target_property(_gflags_includes ${_gflags_target}
  INTERFACE_INCLUDE_DIRECTORIES)
foreach(_property LINK_LIBRARIES INTERFACE_LINK_LIBRARIES)
  get_target_property(_glog_links glog ${_property})
  list(REMOVE_ITEM _glog_links gflags::gflags)
  set_target_properties(glog PROPERTIES ${_property} "${_glog_links}")
endforeach()
target_include_directories(glog PUBLIC ${_gflags_includes})
target_link_libraries(glog INTERFACE "$<TARGET_FILE:${_gflags_target}>")
add_dependencies(glog ${_gflags_target})

# https://github.com/nlohmann/json#cmake
set(JSON_BuildTests OFF CACHE INTERNAL "")
if(NOT TARGET nlohmann_json)
  add_subdirectory(third_party/json)
endif()
target_link_libraries(dynolog_lib PUBLIC nlohmann_json::nlohmann_json)

# OTel add_subdirectory placed after third_party/json so that
# opentelemetry-cpp detects the existing nlohmann_json target
# and after CMAKE_CXX_STANDARD is set.
if(USE_OTEL)
  set(WITH_OTLP_HTTP ON CACHE BOOL "")
  set(WITH_OTLP_GRPC OFF CACHE BOOL "")
  set(WITH_OTLP_FILE OFF CACHE BOOL "")
  set(WITH_EXAMPLES OFF CACHE BOOL "")
  set(BUILD_TESTING OFF CACHE BOOL "")
  set(WITH_BENCHMARK OFF CACHE BOOL "")
  set(WITH_PROMETHEUS OFF CACHE BOOL "")
  set(OTELCPP_MAINTAINER_MODE OFF CACHE BOOL "")
  add_subdirectory(third_party/opentelemetry-cpp)
endif()

add_subdirectory(third_party/pfs)
target_compile_options(
  pfs PRIVATE
  $<$<COMPILE_LANG_AND_ID:CXX,GNU>:-Wno-error=deprecated-enum-enum-conversion>)
target_include_directories(dynolog_lib PUBLIC third_party/pfs/include)
target_link_libraries(dynolog_lib PUBLIC pfs)

add_subdirectory(third_party/fmt)
target_link_libraries(dynolog_lib PUBLIC fmt::fmt)

if(USE_ODS_GRAPH_API)
  add_subdirectory(third_party/cpr)
  target_link_libraries(dynolog_lib PUBLIC cpr::cpr)
endif()
