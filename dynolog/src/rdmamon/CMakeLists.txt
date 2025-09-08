# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

file (GLOB dynolog_rdmamon_files "*.h" "*.cpp")
add_library(dynolog_rdmamon_lib ${dynolog_rdmamon_files})
target_link_libraries(dynolog_rdmamon_lib PUBLIC gflags::gflags)
target_link_libraries(dynolog_rdmamon_lib PUBLIC glog::glog)
target_link_libraries(dynolog_rdmamon_lib PUBLIC fmt::fmt)
