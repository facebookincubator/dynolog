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

    # ROCm version code, e.g. 70000 == ROCm 7.0.x.
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
    # Link the bootstrap library, as the Buck build does: it loads librdc.so
    # only when RDC is started, while librdc.so runs amdsmi_init() from a static
    # initializer and aborts the process on hosts without AMD GPUs.
    target_link_libraries(dynolog_rdc_lib PUBLIC rdc_bootstrap ${GLOG_LIBRARY})

    add_library(dynolog_amdsmi_lib STATIC AmdSmiWrapper.cpp AmdSmiWrapper.h)
    target_include_directories(dynolog_amdsmi_lib PUBLIC "${DYNOLOG_REPO_ROOT}")
    target_link_libraries(dynolog_amdsmi_lib PUBLIC amd_smi)

    add_subdirectory(examples)
    return()
endif ()

# --- Integrated build (add_subdirectory() from the top-level dynolog build) ---

find_package(PkgConfig)
if (PkgConfig_FOUND)
    pkg_check_modules(LIBCAP libcap)
endif ()

# AMD GPU monitoring always builds in all of its sources: KFD/PCI sysfs,
# amd-smi and RDC (which also needs libcap). RDC is still only started at
# runtime with --enable_amd_rdc.
if (USE_AMD_GPU)
    find_package(amd_smi PATHS /opt/rocm REQUIRED)
    find_package(rdc PATHS /opt/rocm REQUIRED)
    if (NOT LIBCAP_FOUND)
        message(FATAL_ERROR "USE_AMD_GPU requires libcap, which ROCm RDC needs")
    endif ()
else ()
    find_package(amd_smi PATHS /opt/rocm)
    find_package(rdc PATHS /opt/rocm)
endif ()

if (amd_smi_FOUND)
    add_library(dynolog_amdsmi_lib AmdSmiWrapper.cpp AmdSmiWrapper.h)
    target_link_libraries(dynolog_amdsmi_lib PUBLIC amd_smi)

    add_library(dynolog_amd_device_lib AmdDeviceTopology.cpp AmdDeviceTopology.h)
    target_link_libraries(dynolog_amd_device_lib glog::glog)
endif ()

if (rdc_FOUND AND amd_smi_FOUND AND LIBCAP_FOUND)
    message(STATUS "RDC package found at ${ROCM_RDC_INCLUDE_DIR}")

    # RdcWrapper.h needs DYNOLOG_ROCM_VERSION. The standalone build above sets
    # it explicitly; detect it here for the integrated build. Pass
    # -DROCM_VERSION=<code> to override the detection.
    if (NOT DEFINED ROCM_VERSION)
        # Derive the ROCm root from the RDC package that was actually found so
        # this honours CMAKE_PREFIX_PATH and versioned paths like
        # /opt/rocm-10.0.0.
        get_filename_component(_dynolog_rocm_root "${rdc_DIR}/../../.." ABSOLUTE)
        set(_dynolog_rocm_version_file "${_dynolog_rocm_root}/.info/version")
        if (NOT EXISTS "${_dynolog_rocm_version_file}" AND DEFINED ENV{ROCM_PATH})
            set(_dynolog_rocm_version_file "$ENV{ROCM_PATH}/.info/version")
        endif ()
        if (EXISTS "${_dynolog_rocm_version_file}")
            file(STRINGS "${_dynolog_rocm_version_file}"
                 _dynolog_rocm_version_raw LIMIT_COUNT 1)
            string(REGEX MATCHALL "[0-9]+"
                   _dynolog_rocm_parts "${_dynolog_rocm_version_raw}")
            list(LENGTH _dynolog_rocm_parts _dynolog_rocm_nparts)
            if (_dynolog_rocm_nparts GREATER_EQUAL 3)
                list(GET _dynolog_rocm_parts 0 _dynolog_rocm_major)
                list(GET _dynolog_rocm_parts 1 _dynolog_rocm_minor)
                list(GET _dynolog_rocm_parts 2 _dynolog_rocm_patch)
                math(EXPR ROCM_VERSION
                     "${_dynolog_rocm_major} * 10000 + ${_dynolog_rocm_minor} * 100 + ${_dynolog_rocm_patch}")
            endif ()
        endif ()
    endif ()
    if (NOT DEFINED ROCM_VERSION)
        message(FATAL_ERROR
            "dynolog: unable to determine the ROCm version. Pass "
            "-DROCM_VERSION=<code> (e.g. 70000 for ROCm 7.0.x) to set it.")
    endif ()
    message(STATUS
        "dynolog RDC integration using DYNOLOG_ROCM_VERSION=${ROCM_VERSION}")

    add_library(dynolog_rdc_lib RdcWrapper.cpp RdcWrapper.h)
    target_compile_definitions(
        dynolog_rdc_lib PUBLIC DYNOLOG_ROCM_VERSION=${ROCM_VERSION})
    # rdc_bootstrap, not rdc: see the standalone section above.
    target_link_libraries(dynolog_rdc_lib rdc_bootstrap glog::glog)

    add_library(dynolog_amd_rdc_lib AmdRdcCollector.cpp AmdRdcCollector.h)
    target_link_libraries(dynolog_amd_rdc_lib PUBLIC
        dynolog_rdc_lib
        dynolog_amd_device_lib
        glog::glog
        ${CMAKE_DL_LIBS})

    add_subdirectory(examples)
else ()
    message(STATUS "RDC package not found. Ignore AMD RDC targets")
endif ()

# The AMD GPU monitor orchestrates the sources above.
if (USE_AMD_GPU)
    add_library(dynolog_amd_gpu_monitor_lib AmdGpuMonitor.cpp AmdGpuMonitor.h)
    target_link_libraries(dynolog_amd_gpu_monitor_lib PUBLIC
        dynolog_amdsmi_lib
        dynolog_amd_device_lib
        dynolog_amd_rdc_lib
        gflags::gflags
        glog::glog
        nlohmann_json::nlohmann_json)
endif ()
