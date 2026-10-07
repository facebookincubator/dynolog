# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

dynolog_add_test(K8sPodCacheTest K8sPodCacheTest.cpp)
target_link_libraries(K8sPodCacheTest PRIVATE dynolog_k8s_lib)
