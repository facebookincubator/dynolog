# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

add_executable(json_client SimpleJsonClientTestCLI.cpp SimpleJsonClientTest.h)

target_link_libraries(json_client PUBLIC gflags::gflags)
target_link_libraries(json_client PUBLIC glog::glog)

dynolog_add_test(SimpleJsonClientTest
  SimpleJsonClientTest.cpp SimpleJsonClientTest.h)

target_link_libraries(SimpleJsonClientTest PRIVATE dynolog_rpc_lib)
