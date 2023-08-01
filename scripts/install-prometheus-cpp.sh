#!/bin/bash

set -eux -o pipefail

DOWNLOAD_DIR=$(mktemp -d)
PROMETHEUS_CPP_VERSION="${PROMETHEUS_CPP_VERSION:-v1.1.0}"

curl "https://github.com/jupp0r/prometheus-cpp/releases/download/${PROMETHEUS_CPP_VERSION}/prometheus-cpp-with-submodules.tar.gz" -o "${DOWNLOAD_DIR}/prometheus-cpp.tar.gz" -L
tar -xf "${DOWNLOAD_DIR}/prometheus-cpp.tar.gz" -C "${DOWNLOAD_DIR}"

mkdir "${DOWNLOAD_DIR}/prometheus-cpp-with-submodules/build"

pushd "${DOWNLOAD_DIR}/prometheus-cpp-with-submodules/build"
cmake -DENABLE_PUSH=OFF -DENABLE_TESTING=OFF ..
cmake --build .
cmake --install .
popd