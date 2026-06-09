# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

# OTLPProto.cmake - Compiles opentelemetry-proto .proto files into C++ stubs
# using protoc. Creates the 'otlp_proto' static library target.

find_package(Protobuf REQUIRED)

set(OTLP_PROTO_ROOT "${PROJECT_SOURCE_DIR}/third_party/opentelemetry-proto")
set(OTLP_PROTO_GENERATED_DIR "${CMAKE_BINARY_DIR}/generated/otlp_proto")

# The four .proto files required for OTLP metrics export.
# Order matters: dependencies must be listed before dependents.
set(OTLP_PROTO_FILES
  "opentelemetry/proto/common/v1/common.proto"
  "opentelemetry/proto/resource/v1/resource.proto"
  "opentelemetry/proto/metrics/v1/metrics.proto"
  "opentelemetry/proto/collector/metrics/v1/metrics_service.proto"
)

set(OTLP_PROTO_GENERATED_SRCS "")
set(OTLP_PROTO_GENERATED_HDRS "")

foreach(PROTO_FILE ${OTLP_PROTO_FILES})
  # Compute generated file paths by replacing .proto with .pb.cc / .pb.h
  string(REPLACE ".proto" ".pb.cc" PROTO_CC "${PROTO_FILE}")
  string(REPLACE ".proto" ".pb.h" PROTO_H "${PROTO_FILE}")

  set(PROTO_CC_FULL "${OTLP_PROTO_GENERATED_DIR}/${PROTO_CC}")
  set(PROTO_H_FULL "${OTLP_PROTO_GENERATED_DIR}/${PROTO_H}")
  set(PROTO_FILE_FULL "${OTLP_PROTO_ROOT}/${PROTO_FILE}")

  add_custom_command(
    OUTPUT "${PROTO_CC_FULL}" "${PROTO_H_FULL}"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${OTLP_PROTO_GENERATED_DIR}"
    COMMAND ${Protobuf_PROTOC_EXECUTABLE}
      --experimental_allow_proto3_optional
      --cpp_out=${OTLP_PROTO_GENERATED_DIR}
      --proto_path=${OTLP_PROTO_ROOT}
      ${PROTO_FILE}
    DEPENDS "${PROTO_FILE_FULL}"
    WORKING_DIRECTORY "${OTLP_PROTO_ROOT}"
    COMMENT "Generating C++ stubs from ${PROTO_FILE}"
    VERBATIM
  )

  list(APPEND OTLP_PROTO_GENERATED_SRCS "${PROTO_CC_FULL}")
  list(APPEND OTLP_PROTO_GENERATED_HDRS "${PROTO_H_FULL}")
endforeach()

add_library(otlp_proto STATIC ${OTLP_PROTO_GENERATED_SRCS} ${OTLP_PROTO_GENERATED_HDRS})
target_include_directories(otlp_proto PUBLIC "${OTLP_PROTO_GENERATED_DIR}")
target_link_libraries(otlp_proto PUBLIC protobuf::libprotobuf)

# Suppress warnings on generated code
target_compile_options(otlp_proto PRIVATE -Wno-unused-parameter -Wno-array-bounds)
set_target_properties(otlp_proto PROPERTIES CXX_STANDARD 17)
