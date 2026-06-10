// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <string>

namespace facebook::hbt::perf_event {

// Naming convention for the per-thread BPF maps pinned in bpffs. Shared by the
// leader (BPerfEventsGroup) that pins the maps and the reader
// (BPerfPerThreadReader) that opens them, so both agree on the same path.
inline std::string perThreadArrayMapFileName(const std::string& n) {
  return "bperf_per_thread_array_" + n;
}

inline std::string perThreadIndexMapFileName(const std::string& n) {
  return "bperf_per_thread_index_" + n;
}

} // namespace facebook::hbt::perf_event
