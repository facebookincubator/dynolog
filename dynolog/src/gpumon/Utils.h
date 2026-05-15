/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace dynolog {

// Assume at most one pid running on each gpu device_id
// Result[i] is the pid running on device_id i,
// or -1 if no process is running
std::vector<pid_t> getPidsOnGpu();
// Input map is type <environment variable name, metadata name>
// output map is type <metadata name, metadata value>
std::unordered_map<std::string, std::string> getMetadataForPid(
    pid_t pid,
    const std::unordered_map<std::string, std::string>& keysMap);

// Built-in default env-attribution map, used on bare-metal Slurm when
// no --env_attribution_mappings_file is supplied.
const std::unordered_map<std::string, std::string>&
getDefaultEnvAttributionMap();

// Loads a 2-column CSV of <env_var_name>,<output_column_name> rows.
// Lines beginning with '#' and empty lines are ignored.
// Returns the loaded map; on failure, returns the built-in default map and
// logs a warning.
std::unordered_map<std::string, std::string> loadEnvAttributionMap(
    const std::string& path);

} // namespace dynolog
