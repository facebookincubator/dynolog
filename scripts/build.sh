#!/bin/bash
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

# Please run this script from the root level of the project.
#  ./scripts/build.sh <optional cmake args>

set -eux -o pipefail

# Check dependencies
cmake --version || echo "Please install cmake for your platform using dnf/apt-get etc."
ninja-build --version || echo "Please install ninja for your platform using dnf/apt-get etc."
rustc --version || echo "Please install Rust and Cargo - see https://www.rust-lang.org/tools/install"
cargo --version || echo "Please install Rust and Cargo - see https://www.rust-lang.org/tools/install"

## Build dynolog
echo "Running cmake"
mkdir -p build; cd build;

# note we can build without ninja if not available on this system
cmake -DCMAKE_BUILD_TYPE=Release -G=Ninja "$@" ..
cmake --build .

echo "Binary files ="
echo "$PWD/dynolog/src/dynolog" "$PWD/release/dyno"
