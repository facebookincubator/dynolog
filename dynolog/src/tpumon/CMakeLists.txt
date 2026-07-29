# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

# TPU scraper needs libcurl for HTTP scrape of tpu-device-plugin /metrics.
# Keep discovery local so builds without USE_TPU do not require libcurl.
if(NOT TARGET CURL::libcurl)
  find_package(CURL REQUIRED)
endif()

add_library(dynolog_tpu_lib
    TpuScraper.cpp TpuScraper.h
    TpuGroupInfo.cpp TpuGroupInfo.h
)
target_include_directories(dynolog_tpu_lib
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(dynolog_tpu_lib PUBLIC glog::glog)
target_link_libraries(dynolog_tpu_lib PUBLIC fmt::fmt)
target_link_libraries(dynolog_tpu_lib PUBLIC gflags::gflags)
target_link_libraries(dynolog_tpu_lib PUBLIC nlohmann_json::nlohmann_json)
target_link_libraries(dynolog_tpu_lib PRIVATE CURL::libcurl)

# libenvattribution is unconditional (used regardless of USE_K8S_PODRESOURCES
# because the shared env-attribution CSV parser lives there).
target_link_libraries(dynolog_tpu_lib PUBLIC dynolog_envattribution_lib)

# Optional: K8s pod-resources attribution. When USE_K8S_PODRESOURCES=ON,
# TpuGroupInfo::update() joins chip -> pod via kubelet pod-resources gRPC
# and enriches per-chip records with operator-configured env vars via
# K8sPodCache (e.g. MAST_* for Meta's MAST scheduler).
# Compile flag propagates through dynolog_k8s_lib (defined at Flags level).
if(USE_K8S_PODRESOURCES)
    target_compile_definitions(dynolog_tpu_lib PUBLIC USE_K8S_PODRESOURCES)
    target_link_libraries(dynolog_tpu_lib PUBLIC dynolog_k8s_lib)
endif()
