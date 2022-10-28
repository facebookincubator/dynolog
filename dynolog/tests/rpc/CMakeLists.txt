# Copyright (c) Meta Platforms, Inc. and affiliates.

add_executable(json_client SimpleJsonClientTestCLI.cpp SimpleJsonClientTest.h)

target_link_libraries(json_client PUBLIC gflags::gflags)
target_link_libraries(json_client PUBLIC glog::glog)

dynolog_add_test(SimpleJsonClientTest
  SimpleJsonClientTest.cpp SimpleJsonClientTest.h)

target_link_libraries(SimpleJsonClientTest PRIVATE dynolog_rpc_lib)
