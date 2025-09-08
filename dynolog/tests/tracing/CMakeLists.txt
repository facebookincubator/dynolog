# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

dynolog_add_test(IPCMonitorTest IPCMonitorTest.cpp)

target_link_libraries(IPCMonitorTest PRIVATE glog::glog)
target_link_libraries(IPCMonitorTest PRIVATE dynolog_ipcmonitor_lib)
target_link_libraries(IPCMonitorTest PRIVATE dynolog_lib)
