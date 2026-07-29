/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/k8s/EnvAttribution.h"

#include <glog/logging.h>

#include <fstream>
#include <string>

DEFINE_string(
    env_attribution_mappings_file,
    "",
    "Path to a CSV file defining env-var → column-name attribution mappings. "
    "Each non-empty, non-'#' line is: <env_var_name>,<output_column_name>. "
    "When empty, the built-in Slurm default mapping is used.");

namespace dynolog {

const std::unordered_map<std::string, std::string>&
getDefaultEnvAttributionMap() {
  // Used on bare-metal Slurm hosts when no --env_attribution_mappings_file
  // is provided. Mirrors the historical hardcoded mapping in
  // DcgmGroupInfo.cpp so non-K8s deployments behave identically.
  static const std::unordered_map<std::string, std::string> kDefault = {
      {"SLURM_JOB_ID", "job_id"},
      {"USER", "username"},
      {"SLURM_JOB_ACCOUNT", "slurm_account"},
      {"SLURM_JOB_PARTITION", "slurm_partition"},
  };
  return kDefault;
}

std::unordered_map<std::string, std::string> loadEnvAttributionMap(
    const std::string& path) {
  std::unordered_map<std::string, std::string> result;
  std::ifstream file(path);
  if (!file.is_open()) {
    LOG(WARNING) << "Could not open env_attribution_mappings_file: " << path
                 << "; falling back to built-in default map";
    return getDefaultEnvAttributionMap();
  }
  std::string line;
  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '#') {
      continue;
    }
    // Split on first comma: env_var_name,output_column_name
    auto pos = line.find(',');
    if (pos == std::string::npos || pos == 0 || pos + 1 >= line.size()) {
      LOG(WARNING) << "Skipping malformed env-attribution line: " << line;
      continue;
    }
    std::string env_key = line.substr(0, pos);
    std::string column = line.substr(pos + 1);
    // Trim leading + trailing whitespace/CR (handles CRLF input and
    // tolerates user-friendly spacing around the comma separator).
    auto isWs = [](char c) {
      return c == '\r' || c == '\n' || c == ' ' || c == '\t';
    };
    auto trim = [&](std::string& s) {
      while (!s.empty() && isWs(s.back())) {
        s.pop_back();
      }
      size_t i = 0;
      while (i < s.size() && isWs(s[i])) {
        ++i;
      }
      if (i > 0) {
        s.erase(0, i);
      }
    };
    trim(env_key);
    trim(column);
    if (env_key.empty() || column.empty()) {
      continue;
    }
    result[env_key] = column;
  }
  LOG(INFO) << "Loaded " << result.size() << " env-attribution mappings from "
            << path;
  return result;
}

const std::unordered_map<std::string, std::string>&
getEnvAttributionMappings() {
  static const auto mappings = [] {
    if (!FLAGS_env_attribution_mappings_file.empty()) {
      return loadEnvAttributionMap(FLAGS_env_attribution_mappings_file);
    }
    return getDefaultEnvAttributionMap();
  }();
  return mappings;
}

} // namespace dynolog
