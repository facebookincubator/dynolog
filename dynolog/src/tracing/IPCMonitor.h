/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <memory>

// Use glog for FabricManager.h
#define USE_GOOGLE_LOG

#include "dynolog/src/ipcfabric/FabricManager.h"

namespace dynolog::tracing {

class IPCMonitor {
 public:
  using FabricManager = dynolog::ipcfabric::FabricManager;
  IPCMonitor(const std::string& ipc_fabric_name = "dynolog");
  virtual ~IPCMonitor() = default;

  void loop();

 public:
  virtual void processMsg(std::unique_ptr<ipcfabric::Message> msg);
  void getLibkinetoOnDemandRequest(std::unique_ptr<ipcfabric::Message> msg);
  void registerLibkinetoContext(std::unique_ptr<ipcfabric::Message> msg);

  std::unique_ptr<ipcfabric::FabricManager> ipc_manager_;

  // friend class test_case_name##_##test_name##_Test
  friend class IPCMonitorTest_LibkinetoRegisterAndOndemandTest_Test;
};

} // namespace dynolog::tracing
