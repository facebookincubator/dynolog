# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

add_library (dynolog_ipcmonitor_lib IPCMonitor.cpp IPCMonitor.h
  ${CMAKE_CURRENT_SOURCE_DIR}/../LibkinetoConfigManager.h
)

target_include_directories(dynolog_ipcmonitor_lib
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
target_include_directories(dynolog_ipcmonitor_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(dynolog_ipcmonitor_lib PUBLIC glog::glog)
target_link_libraries(dynolog_ipcmonitor_lib PUBLIC dynolog_ipcfabric_lib)
