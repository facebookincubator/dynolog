# (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.
dynolog_add_test(IPCMonitorTest IPCMonitorTest.cpp)

target_link_libraries(IPCMonitorTest PRIVATE glog::glog)
target_link_libraries(IPCMonitorTest PRIVATE dynolog_ipcmonitor_lib)
target_link_libraries(IPCMonitorTest PRIVATE dynolog_lib)
