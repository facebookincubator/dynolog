// Copyright (c) Meta Platforms, Inc. and affiliates.

// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <map>
#include "dynolog/src/rdmamon/RdmaMonitor.h"

using namespace dynolog::rdmamon;

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  std::map<std::string, int64_t> counters;
  std::unique_ptr<RdmaMonitor> monitor;
  try {
    monitor = std::make_unique<RdmaMonitor>();
  } catch (std::exception& ex) {
    std::cerr << " Failed to create RDMA monitor" << ex.what() << std::endl;
    monitor = nullptr;
  }
  if (monitor && !monitor->setupRdmaMonitor()) {
    std::cerr << "Unable to setup the RDMA monitor" << std::endl;
  }
  while (true) {
    usleep(1000000); // NOLINT(facebook-hte-BadCall-sleep)
    if (monitor && !monitor->sampleRdmaMonitor(counters)) {
      std::cerr << "Unable to sample the RDMA monitor" << std::endl;
    }
    std::cout << "+++++++++++++++++++++++++" << std::endl;
    for (auto it = counters.begin(); it != counters.end(); it++) {
      std::cout << it->first << "-->" << it->second << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
  }

  return 0;
}
