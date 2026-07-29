/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <gflags/gflags.h>

#include <string>
#include <unordered_map>

// Shared env-var attribution helpers used by both gpumon (DcgmGroupInfo)
// and tpumon (TpuGroupInfo) to translate pod-spec / process-environment
// key/value pairs into Scuba column names via a CSV mapping.
//
// Not USE_K8S_PODRESOURCES-guarded: the same mapping format is used on
// bare-metal Slurm (via /proc/<pid>/environ) as on K8s (via
// K8sPodCache::lookupAttribution). Placed under dynolog/src/k8s/ because
// the primary consumer is K8sPodCache; the SLURM path is a smaller
// legacy consumer.

DECLARE_string(env_attribution_mappings_file);

namespace dynolog {

// Built-in default env-attribution map, used on bare-metal Slurm when
// no --env_attribution_mappings_file is supplied.
const std::unordered_map<std::string, std::string>&
getDefaultEnvAttributionMap();

// Loads a 2-column CSV of <env_var_name>,<output_column_name> rows.
// Lines beginning with '#' and empty lines are ignored.
// Returns the loaded map; on failure, returns the built-in default map
// and logs a warning.
std::unordered_map<std::string, std::string> loadEnvAttributionMap(
    const std::string& path);

// Returns the process-wide env-attribution map. Reads
// FLAGS_env_attribution_mappings_file on first call and caches the
// result. Falls back to getDefaultEnvAttributionMap() when the flag is
// empty. Both gpumon and tpumon use this so the mapping loads exactly
// once per process regardless of which module first invokes it.
const std::unordered_map<std::string, std::string>& getEnvAttributionMappings();

} // namespace dynolog
