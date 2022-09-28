// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <memory>

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
// included from ipcfabric/
#include "FabricManager.h" // @manual=//dynolog/src/ipcfabric:ipcfabric

namespace dynolog {
namespace tracing {

class IPCMonitor {
 public:
  using FabricManager = dynolog::ipcfabric::FabricManager;
  IPCMonitor();

  void loop();

 public:
  void processMsg(std::unique_ptr<ipcfabric::Message> msg);
  void getLibkinetoOnDemandRequest(std::unique_ptr<ipcfabric::Message> msg);
  void registerLibkinetoContext(std::unique_ptr<ipcfabric::Message> msg);

  std::unique_ptr<ipcfabric::FabricManager> ipc_manager_;

  // friend class test_case_name##_##test_name##_Test
  friend class IPCMonitorTest_LibkinetoRegisterAndOndemandTest_Test;
};

} // namespace tracing
} // namespace dynolog
