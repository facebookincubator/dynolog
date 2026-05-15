# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

# K8s platform-discovery libraries used by dynolog. Built only when
# USE_K8S_PODRESOURCES=ON; otherwise this directory is empty for the
# OSS CMake build.

if(NOT USE_K8S_PODRESOURCES)
    return()
endif()

# Generate C++ + gRPC stubs from the vendored kubelet pod-resources v1
# proto. Requires protobuf-compiler with the gRPC plugin.
find_package(Protobuf REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(CURL REQUIRED)

set(_kubelet_proto
    ${CMAKE_CURRENT_SOURCE_DIR}/kubelet_podresources/api.proto)
set(_kubelet_proto_outdir
    ${CMAKE_CURRENT_BINARY_DIR}/kubelet_podresources)
file(MAKE_DIRECTORY ${_kubelet_proto_outdir})

set(_kubelet_pb_h    ${_kubelet_proto_outdir}/api.pb.h)
set(_kubelet_pb_cc   ${_kubelet_proto_outdir}/api.pb.cc)
set(_kubelet_grpc_h  ${_kubelet_proto_outdir}/api.grpc.pb.h)
set(_kubelet_grpc_cc ${_kubelet_proto_outdir}/api.grpc.pb.cc)

get_target_property(_protoc_exec protobuf::protoc LOCATION)
get_target_property(_grpc_cpp_plugin gRPC::grpc_cpp_plugin LOCATION)

add_custom_command(
    OUTPUT
        ${_kubelet_pb_h} ${_kubelet_pb_cc}
        ${_kubelet_grpc_h} ${_kubelet_grpc_cc}
    COMMAND ${_protoc_exec}
        --proto_path=${CMAKE_CURRENT_SOURCE_DIR}/kubelet_podresources
        --cpp_out=${_kubelet_proto_outdir}
        --grpc_out=${_kubelet_proto_outdir}
        --plugin=protoc-gen-grpc=${_grpc_cpp_plugin}
        ${_kubelet_proto}
    DEPENDS ${_kubelet_proto} protobuf::protoc gRPC::grpc_cpp_plugin
    COMMENT "Generating C++/gRPC stubs from kubelet podresources api.proto"
    VERBATIM
)

add_library(dynolog_kubelet_podresources_lib
    ${_kubelet_pb_cc} ${_kubelet_grpc_cc})
target_include_directories(dynolog_kubelet_podresources_lib PUBLIC
    # ${CMAKE_BINARY_DIR} so consumers can include the generated header
    # with its full BUCK-style path:
    #   "dynolog/src/k8s/kubelet_podresources/api.grpc.pb.h"
    ${CMAKE_BINARY_DIR}
    # ${CMAKE_CURRENT_BINARY_DIR} so the generated .pb.cc / .grpc.pb.cc
    # can include their own short-form siblings (e.g. "api.pb.h").
    ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(dynolog_kubelet_podresources_lib PUBLIC
    protobuf::libprotobuf
    gRPC::grpc++)

# K8s integration library: PodResourcesClient (gRPC over kubelet socket)
# and K8sPodCache (HTTP+JSON to the K8s API).
add_library(dynolog_k8s_lib
    PodResourcesClient.cpp PodResourcesClient.h
    K8sPodCache.cpp        K8sPodCache.h
)
target_include_directories(dynolog_k8s_lib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(dynolog_k8s_lib PUBLIC
    glog::glog
    gflags::gflags
    nlohmann_json::nlohmann_json
    dynolog_kubelet_podresources_lib
    gRPC::grpc++
    CURL::libcurl)
