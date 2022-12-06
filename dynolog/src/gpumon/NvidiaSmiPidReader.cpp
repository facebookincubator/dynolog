// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include "dynolog/src/gpumon/NvidiaSmiPidReader.h"
#include <glog/logging.h>
#include <stdio.h>

// Nvidia DCGM deprecates PID related fields (220, 221)
// so it is not feasible to get running GPU processes directly from DCGM
// Reading from nvidia-smi directly provides easier integration that importing
// NVML dependency and mixing the NVML call between DCGM

namespace dynolog {
constexpr char kParsePidCmd[] = " pmon -c 1 | awk '{print $2}' | tail -n +3";

DEFINE_string(
    nvidia_smi_path,
    "nvidia-smi",
    "The path to nvidia-smi binary, used to fetch GPU processes");

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
  std::string cmd = FLAGS_nvidia_smi_path + kParsePidCmd;
  FILE* fp = popen(cmd.c_str(), "r");
  char pid[PID_SIZE_MAX];
  std::vector<pid_t> res;
  if (!fp) {
    LOG(ERROR) << "Cannot run command " << cmd;
    return res;
  }

  while (fgets(pid, PID_SIZE_MAX, fp)) {
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

} // namespace dynolog
