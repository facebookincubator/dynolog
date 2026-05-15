#!/bin/bash
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

# Please run this script from the root level of the project.
#  ./scripts/build.sh <optional cmake args>

set -eux -o pipefail
BUILD_PROMETHEUS="${BUILD_PROMETHEUS:-0}"
USE_PROMETHEUS="OFF"

# Check dependencies
cmake --version || echo "Please install cmake for your platform using dnf/apt-get etc."
ninja --version || echo "Please install ninja for your platform using dnf/apt-get etc."
rustc --version || echo "Please install Rust and Cargo - see https://www.rust-lang.org/tools/install"
cargo --version || echo "Please install Rust and Cargo - see https://www.rust-lang.org/tools/install"

## Build Prometheus if enabled
if [ "${BUILD_PROMETHEUS}" -eq 1 ]
then
  mkdir -p ./third_party/prometheus-cpp/_build
  pushd ./third_party/prometheus-cpp/

  git submodule init
  git submodule update

  cd ./_build
  cmake .. -DBUILD_SHARED_LIBS=ON -DENABLE_PUSH=OFF -DENABLE_COMPRESSION=OFF \
     -DENABLE_TESTING=OFF
  cmake --build . --parallel 4
  cmake --install .

  USE_PROMETHEUS="ON"
  popd
fi

## Build with OpenTelemetry if enabled
BUILD_OTEL="${BUILD_OTEL:-0}"
USE_OTEL="OFF"
if [ "${BUILD_OTEL}" -eq 1 ]; then
  if ! pkg-config --exists protobuf 2>/dev/null; then
    echo "Error: protobuf not found. Install with:"
    echo "  apt-get install libprotobuf-dev protobuf-compiler  # Debian/Ubuntu"
    echo "  dnf install protobuf-devel protobuf-compiler       # Fedora/RHEL"
    exit 1
  fi
  if ! pkg-config --exists libcurl 2>/dev/null; then
    echo "Error: libcurl not found. Install with:"
    echo "  apt-get install libcurl4-openssl-dev               # Debian/Ubuntu"
    echo "  dnf install libcurl-devel                          # Fedora/RHEL"
    exit 1
  fi
  pushd ./third_party/opentelemetry-cpp
  git submodule init && git submodule update
  popd
  USE_OTEL="ON"
fi

## Build with K8s pod-resources gRPC + K8s API HTTP attribution if enabled.
## Requires protoc + grpc_cpp_plugin + grpc++ (C++ headers) + libcurl.
BUILD_K8S_PODRESOURCES="${BUILD_K8S_PODRESOURCES:-0}"
USE_K8S_PODRESOURCES="OFF"
if [ "${BUILD_K8S_PODRESOURCES}" -eq 1 ]; then
  if ! command -v protoc >/dev/null 2>&1; then
    echo "Error: protoc not found. Install with:"
    echo "  apt-get install protobuf-compiler                  # Debian/Ubuntu"
    echo "  dnf install protobuf-compiler                      # Fedora/RHEL"
    exit 1
  fi
  if ! command -v grpc_cpp_plugin >/dev/null 2>&1; then
    echo "Error: grpc_cpp_plugin not found. Install with:"
    echo "  apt-get install protobuf-compiler-grpc             # Debian/Ubuntu"
    echo "  dnf install grpc-plugins                           # Fedora/RHEL"
    exit 1
  fi
  if ! pkg-config --exists grpc++ 2>/dev/null; then
    echo "Error: grpc++ not found. Install with:"
    echo "  apt-get install libgrpc++-dev libprotobuf-dev      # Debian/Ubuntu"
    echo "  dnf install grpc-devel grpc-cpp protobuf-devel     # Fedora/RHEL"
    exit 1
  fi
  if ! pkg-config --exists libcurl 2>/dev/null; then
    echo "Error: libcurl not found. Install with:"
    echo "  apt-get install libcurl4-openssl-dev               # Debian/Ubuntu"
    echo "  dnf install libcurl-devel                          # Fedora/RHEL"
    exit 1
  fi
  USE_K8S_PODRESOURCES="ON"
fi

## Build dynolog
echo "Running cmake"
mkdir -p build; cd build;

# note we can build without ninja if not available on this system
cmake "-DUSE_PROMETHEUS=${USE_PROMETHEUS}" "-DUSE_OTEL=${USE_OTEL}" \
  "-DUSE_K8S_PODRESOURCES=${USE_K8S_PODRESOURCES}" \
  -DCMAKE_BUILD_TYPE=Release -G Ninja "$@" ..
cmake --build .

mkdir -p bin
ln -sf "$PWD/dynolog/src/dynolog" bin/dynolog
ln -sf "$PWD/release/dyno" bin/dyno

echo "Binary files ="
echo "$PWD/dynolog/src/dynolog" "$PWD/release/dyno"
