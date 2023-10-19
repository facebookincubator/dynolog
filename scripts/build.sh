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

## Build dynolog
echo "Running cmake"
mkdir -p build; cd build;

# note we can build without ninja if not available on this system
cmake "-DUSE_PROMETHEUS=${USE_PROMETHEUS}" \
  -DCMAKE_BUILD_TYPE=Release -G Ninja "$@" ..
cmake --build .

mkdir -p bin
ln -sf "$PWD/dynolog/src/dynolog" bin/dynolog
ln -sf "$PWD/release/dyno" bin/dyno

echo "Binary files ="
echo "$PWD/dynolog/src/dynolog" "$PWD/release/dyno"
