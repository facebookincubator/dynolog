/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/Utils.h"
#include <glog/logging.h>
#include <sys/types.h>
#include <cstdio>
#include <fstream>
#include <optional>
#include <sstream>
#include <unordered_set>
#include "pfs/procfs.hpp"

namespace dynolog {
constexpr char kParsePidCmd[] =
    "nvidia-smi pmon -c 1 | awk '{print $2}' | tail -n +3";
// max length of pid
constexpr int PID_SIZE_MAX = 10;

bool is_number(const std::string& s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) {
    ++it;
  }
  return !s.empty() && it == s.end();
}

std::vector<pid_t> getPidsOnGpu() {
  FILE* fp = popen(kParsePidCmd, "r");
  char pid[PID_SIZE_MAX];
  std::vector<pid_t> res;
  if (fp == nullptr) {
    LOG(ERROR) << "Cannot run command " << kParsePidCmd;
    return res;
  }

  while (fgets(pid, PID_SIZE_MAX, fp) != nullptr) {
    std::string pid_str(pid);
    pid_str.erase(pid_str.find_last_not_of(" \n\r\t") + 1);

    if (is_number(pid_str)) {
      res.push_back(std::stoi(pid_str));
    } else {
      res.push_back(-1);
    }
  }

  int status = pclose(fp);
  if (status == -1) {
    LOG(ERROR) << "pclose() failed";
  }
  return res;
}

std::unordered_map<std::string, std::string> getMetadataForPid(
    pid_t pid,
    const std::unordered_map<std::string, std::string>& keysMap) {
  std::unordered_map<std::string, std::string> varsMap;
  if (pid < 0) {
    return varsMap;
  }
  try {
    auto task = pfs::procfs().get_task(pid);
    auto env = task.get_environ();
    for (const auto& key : keysMap) {
      if (auto val = env.find(key.first); val != env.end()) {
        varsMap[key.second] = val->second;
      }
    }
  } catch (const std::system_error& e) {
    LOG(WARNING) << "Could not read env for pid " << pid << ": " << e.what();
  }
  return varsMap;
}

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

} // namespace dynolog
