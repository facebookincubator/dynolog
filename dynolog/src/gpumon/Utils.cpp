// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include "dynolog/src/gpumon/Utils.h"
#include <glog/logging.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fstream>
#include <optional>
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
  auto task = pfs::procfs().get_task(pid);
  auto env = task.get_environ();
  for (auto key : keysMap) {
    if (auto val = env.find(key.first); val != env.end()) {
      varsMap[key.second] = val->second;
    }
  }
  return varsMap;
}

} // namespace dynolog
