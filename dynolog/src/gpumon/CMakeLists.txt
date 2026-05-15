# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

add_library(dynolog_dcgm_lib
    DcgmApiStub.cpp DcgmApiStub.h
    DcgmGroupInfo.cpp DcgmGroupInfo.h
    Utils.h Utils.cpp
    Entity.cpp Entity.h
    dcgm_fields.h
    dcgm_agent.h
    dcgm_errors.h
    dcgm_structs.h
    dcgm_api_export.h
)
target_include_directories(dynolog_dcgm_lib
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
target_include_directories(dynolog_dcgm_lib PUBLIC
                            ${PROJECT_SOURCE_DIR}/third_party/pfs/include)
target_link_libraries(dynolog_dcgm_lib PUBLIC gflags::gflags)
target_link_libraries(dynolog_dcgm_lib PUBLIC glog::glog)
target_link_libraries(dynolog_dcgm_lib PUBLIC nlohmann_json::nlohmann_json)
target_link_libraries(dynolog_dcgm_lib PUBLIC pfs)

# Optional: K8s pod-resources / API attribution. The K8s libraries themselves
# are built (or skipped) by the parent CMakeLists.txt's add_subdirectory(k8s);
# we only wire them into dynolog_dcgm_lib here when enabled, so DcgmGroupInfo
# can call into them.
if(USE_K8S_PODRESOURCES)
    target_compile_definitions(dynolog_dcgm_lib PUBLIC USE_K8S_PODRESOURCES)
    target_link_libraries(dynolog_dcgm_lib PUBLIC dynolog_k8s_lib)
endif()

add_subdirectory(amd)
