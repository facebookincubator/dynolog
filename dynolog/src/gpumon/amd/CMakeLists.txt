# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

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

    add_executable(RdcWrapperExample examples/RdcWrapperExample.cpp)
    target_link_libraries(RdcWrapperExample dynolog_rdc_lib)
else ()
    message(STATUS "RDC package not found. Ignore AMD GPU targets")
endif ()
