# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

# Builds only the example program. The dynolog_rdc_lib library target (and the
# FB_ROCM_VERSION define / include paths it propagates) is defined by the parent
# directory's CMakeLists.txt (dynolog/src/gpumon/amd).

add_executable(RdcWrapperExample RdcWrapperExample.cpp)

if (TARGET gflags::gflags)
    target_link_libraries(RdcWrapperExample PRIVATE dynolog_rdc_lib gflags::gflags)
else ()
    find_library(GFLAGS_LIBRARY NAMES gflags REQUIRED)
    target_link_libraries(
        RdcWrapperExample PRIVATE dynolog_rdc_lib ${GFLAGS_LIBRARY})
endif ()
