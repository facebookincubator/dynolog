// Copyright 2004-present Facebook. All Rights Reserved.

#include "IPCMonitor.h"

#include <glog/logging.h>
#include <string.h>
#include <unistd.h>
#include <cstdint>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "LibkinetoConfigManager.h" // @manual=//dynolog/src:libkinetomanagerbase
// included from ipcfabric/
#include "Utils.h" // @manual=//dynolog/src/ipcfabric:ipcfabric

namespace dynolog {
namespace tracing {

constexpr int kSleepUs = 10000;
const std::string kLibkinetoRequest = "req";
const std::string kLibkinetoContext = "ctxt";

IPCMonitor::IPCMonitor() {
  ipc_manager_ = FabricManager::factory("dynolog");
  // below ensures singleton exists
  LOG(INFO) << "Kineto config manager : active processes = "
            << LibkinetoConfigManager::getInstance()->processCount(0);
}

void IPCMonitor::loop() {
  while (ipc_manager_) {
    if (ipc_manager_->recv()) {
      std::unique_ptr<ipcfabric::Message> msg = ipc_manager_->retrieve_msg();
      processMsg(std::move(msg));
    }
    /* sleep override */
    usleep(kSleepUs);
  }
}

void IPCMonitor::processMsg(std::unique_ptr<ipcfabric::Message> msg) {
  if (!ipc_manager_) {
    LOG(ERROR) << "Fabric Manager not initialized";
    return;
  }
  if (memcmp(msg->metadata.type, kLibkinetoContext.c_str(), 4) == 0) {
    registerLibkinetoContext(std::move(msg));
  } else if (memcmp(msg->metadata.type, kLibkinetoRequest.c_str(), 3) == 0) {
    getLibkinetoOnDemandRequest(std::move(msg));
  } else {
    LOG(ERROR) << "TYPE UNKOWN: " << msg->metadata.type;
  }
}

void IPCMonitor::getLibkinetoOnDemandRequest(
    std::unique_ptr<ipcfabric::Message> msg) {
  if (!ipc_manager_) {
    LOG(ERROR) << "Fabric Manager not initialized";
    return;
  }
  std::string ret_config = "";
  ipcfabric::LibkinetoRequest* req =
      (ipcfabric::LibkinetoRequest*)msg->buf.get();
  if (req->n == 0) {
    LOG(ERROR) << "Missing pids parameter";
  }
  std::vector<int32_t> pids(req->pids, req->pids + req->n);
  try {
    ret_config = LibkinetoConfigManager::getInstance()->obtainOnDemandConfig(
        req->jobid, pids, req->type);
    VLOG(0) << "getLibkinetoOnDemandRequest() : job id " << req->jobid
            << " pids = " << pids[0];
  } catch (const std::runtime_error& ex) {
    LOG(ERROR) << "Kineto config manager exception : " << ex.what();
  }
  std::unique_ptr<ipcfabric::Message> ret =
      ipcfabric::Message::constructMessage<decltype(ret_config)>(
          ret_config, kLibkinetoRequest);
  if (!ipc_manager_->sync_send(*ret, msg->src)) {
    LOG(ERROR) << "Failed to return config to libkineto: IPC sync_send fail";
  }

  return;
}

void IPCMonitor::registerLibkinetoContext(
    std::unique_ptr<ipcfabric::Message> msg) {
  if (!ipc_manager_) {
    LOG(ERROR) << "Fabric Manager not initialized";
    return;
  }
  ipcfabric::LibkinetoContext* ctxt =
      (ipcfabric::LibkinetoContext*)msg->buf.get();
  int32_t size = -1;
  try {
    size = LibkinetoConfigManager::getInstance()->registerLibkinetoContext(
        ctxt->jobid, ctxt->pid, ctxt->gpu);
  } catch (const std::runtime_error& ex) {
    LOG(ERROR) << "Kineto config manager exception : " << ex.what();
  }
  std::unique_ptr<ipcfabric::Message> ret =
      ipcfabric::Message::constructMessage<decltype(size)>(
          size, kLibkinetoContext);
  if (!ipc_manager_->sync_send(*ret, msg->src)) {
    LOG(ERROR) << "Failed to send ctxt from dyno: IPC sync_send fail";
  }

  return;
}

} // namespace tracing
} // namespace dynolog
