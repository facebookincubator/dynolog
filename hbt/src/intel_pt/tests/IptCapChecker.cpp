// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <iostream>

#include "hbt/src/intel_pt/IptEventBuilder.h"
#include "hbt/src/perf_event/BuiltinMetrics.h"

using namespace facebook::hbt::intel_pt;
using namespace facebook::hbt::perf_event;

int main() {
  auto pmuManager = makePmuDeviceManager();
  if (!pmuManager) {
    std::cout << "Failed to make pmu manager" << std::endl;
    return -1;
  }
  auto iptEventBuilder = IptEventBuilder::createIptEventBuilder(*pmuManager);
  for (int i = 0; i <= 15; i++) {
    std::cout << "Support CYC(" << i
              << "): " << iptEventBuilder->hasCycSupport(i) << std::endl;
  }
  for (int i = 0; i <= 15; i++) {
    std::cout << "Support MTC(" << i
              << "): " << iptEventBuilder->hasMtcSupport(i) << std::endl;
  }
  std::cout << "Support PTW: " << iptEventBuilder->hasPtwSupport() << std::endl;
  for (int i = 0; i <= 15; i++) {
    std::cout << "Support PSB(" << i
              << "): " << iptEventBuilder->hasPsbPeriodSupport(i) << std::endl;
  }
  std::cout << "SupportPwrEvt: " << iptEventBuilder->hasPwrEvtSupport()
            << std::endl;

  std::cout << "Set pt to true: ";
  iptEventBuilder->setPt(true);
  std::cout << "0x" << std::hex << iptEventBuilder->getPerfConfig()
            << std::endl;

  std::cout << "Set branch to true: ";
  iptEventBuilder->setBranch(true);
  std::cout << "0x" << std::hex << iptEventBuilder->getPerfConfig()
            << std::endl;

  std::cout << "Set tsc to true: ";
  iptEventBuilder->setTsc(true);
  std::cout << "0x" << std::hex << iptEventBuilder->getPerfConfig()
            << std::endl;

  return 0;
}
