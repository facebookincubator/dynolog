// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <optional>
#include <string>

namespace facebook::hbt::defaults {

inline auto shmRbNames(const std::string& shm_base_path) {
  return std::make_pair(shm_base_path + "/events", shm_base_path + "/metadata");
}

inline auto shmRbNames(std::optional<std::string> shm_base_path_opt) {
  // XXX: Currently depends on hard-coded paths in hbt/src/shm and in CLI.
  return shmRbNames(shm_base_path_opt.value_or("hbt"));
}

inline auto shmRbNames(const char* shm_base_path) {
  return shmRbNames(std::string{shm_base_path});
}

} // namespace facebook::hbt::defaults
