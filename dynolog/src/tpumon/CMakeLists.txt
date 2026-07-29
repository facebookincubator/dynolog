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
)
target_include_directories(dynolog_tpu_lib
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(dynolog_tpu_lib PUBLIC glog::glog)
target_link_libraries(dynolog_tpu_lib PUBLIC fmt::fmt)
target_link_libraries(dynolog_tpu_lib PRIVATE CURL::libcurl)
