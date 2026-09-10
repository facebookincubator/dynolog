// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

namespace facebook::hbt::perf_event {

enum class ScaleUnit {
  Bytes, // Bytes
  Joules, // Joules
  MiB // MebiBytes
};

} // namespace facebook::hbt::perf_event
