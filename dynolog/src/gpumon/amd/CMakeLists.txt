# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

cmake_minimum_required(VERSION 3.16)

# When this directory is configured directly (standalone) rather than pulled in
# via add_subdirectory() from the top-level dynolog build, set up a minimal
# project that builds just the RDC wrapper library and the example:
#
#   cd dynolog/src/gpumon/amd
#   cmake -B build -G Ninja -DROCM_VERSION=70000
#   cmake --build build
#
# Prerequisites: RDC SDK + amd_smi (typically under /opt/rocm), glog, gflags.
# Point CMake at non-standard locations with -DCMAKE_PREFIX_PATH=... if needed.
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(RdcWrapperStandalone LANGUAGES CXX)

    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)

    # ROCm version code, e.g. 70000 == ROCm 7.0.x. Compiled in as
    set(ROCM_VERSION 70000 CACHE STRING "ROCm version, e.g. 70000 for 7.0.x")

    # Repo-rooted includes like "dynolog/src/gpumon/amd/RdcWrapper.h" resolve
    # from the repository root, four levels up from this directory.
    get_filename_component(DYNOLOG_REPO_ROOT
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../.." ABSOLUTE)

    find_package(rdc PATHS /opt/rocm REQUIRED)
    find_package(amd_smi PATHS /opt/rocm REQUIRED)
    # EPEL glog ships no cmake config, so locate the library directly.
    find_library(GLOG_LIBRARY NAMES glog REQUIRED)

    add_library(dynolog_rdc_lib STATIC RdcWrapper.cpp RdcWrapper.h)
    target_include_directories(dynolog_rdc_lib PUBLIC "${DYNOLOG_REPO_ROOT}")
    target_compile_definitions(
        dynolog_rdc_lib PUBLIC DYNOLOG_ROCM_VERSION=${ROCM_VERSION})
    target_link_libraries(dynolog_rdc_lib PUBLIC rdc ${GLOG_LIBRARY})

    add_subdirectory(examples)
    return()
endif ()

# --- Integrated build (add_subdirectory() from the top-level dynolog build) ---

find_package(rdc PATHS /opt/rocm)
find_package(amd_smi PATHS /opt/rocm)
find_package(PkgConfig)

if (PkgConfig_FOUND)
    pkg_check_modules(LIBCAP libcap)
endif ()

if (rdc_FOUND AND amd_smi_FOUND AND LIBCAP_FOUND)
    message(STATUS "RDC package found at ${ROCM_RDC_INCLUDE_DIR}")
    add_library(dynolog_rdc_lib RdcWrapper.cpp RdcWrapper.h)
    target_link_libraries(dynolog_rdc_lib rdc glog::glog)

    add_library(dynolog_amd_device_lib AmdDeviceTopology.cpp AmdDeviceTopology.h)
    target_link_libraries(dynolog_amd_device_lib glog::glog)

    add_subdirectory(examples)
else ()
    message(STATUS "RDC package not found. Ignore AMD GPU targets")
endif ()
