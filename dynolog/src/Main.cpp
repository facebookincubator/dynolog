// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Dynomin : A portable telemetry monitoring daemon.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <chrono>
#include <cstdlib>
#include <thread>
#include "dynolog/src/CompositeLogger.h"
#include "dynolog/src/FBRelayLogger.h"
#include "dynolog/src/KernelCollector.h"
#include "dynolog/src/Logger.h"
#include "dynolog/src/ODSJsonLogger.h"
#include "dynolog/src/PerfMonitor.h"
#include "dynolog/src/ScubaLogger.h"
#include "dynolog/src/ServiceHandler.h"
#include "dynolog/src/gpumon/DcgmGroupInfo.h"
#include "dynolog/src/rpc/SimpleJsonServer.h"
#include "dynolog/src/rpc/SimpleJsonServerInl.h"
#include "dynolog/src/tracing/IPCMonitor.h"
#include "hbt/src/perf_event/BuiltinMetrics.h"

using namespace dynolog;
using json = nlohmann::json;
namespace hbt = facebook::hbt;

DEFINE_int32(port, 1778, "Port for listening RPC requests : FUTURE");
DEFINE_int32(
    kernel_monitor_reporting_interval_s,
    60,
    "Duration in seconds to read and report metrics for kernel monitor");
DEFINE_int32(
    perf_monitor_reporting_interval_s,
    60,
    "Duration in seconds to read and report metrics for performance monitor");
DEFINE_int32(
    dcgm_reporting_interval_s,
    10,
    "Duration in seconds to read and report metrics for DCGM");
DEFINE_bool(use_fbrelay, false, "Emit metrics to FB Relay on Lab machines");
DEFINE_bool(
    enable_ipc_monitor,
    false,
    "Enabled IPC monitor for on system tracing requests.");
DEFINE_bool(use_ODS, false, "Emit metrics to ODS through ODS logger");
DEFINE_bool(use_JSON, false, "Emit metrics to JSON file through JSON logger");
DEFINE_bool(use_scuba, false, "Emit metrics to Scuba through Scuba logger");
DEFINE_bool(
    enable_gpu_monitor,
    false,
    "Enabled GPU monitorng, currently supports NVIDIA GPUs.");
DEFINE_bool(enable_perf_monitor, false, "Enable heartbeat perf monitoring.");

std::unique_ptr<Logger> getLogger(const std::string& scribe_category = "") {
  std::vector<std::unique_ptr<Logger>> loggers;
  if (FLAGS_use_fbrelay) {
    loggers.push_back(std::make_unique<FBRelayLogger>());
  }
  if (FLAGS_use_ODS) {
    loggers.push_back(std::make_unique<ODSJsonLogger>());
  }
  if (FLAGS_use_JSON) {
    loggers.push_back(std::make_unique<JsonLogger>());
  }
  if (FLAGS_use_scuba && !scribe_category.empty()) {
    loggers.push_back(std::make_unique<ScubaLogger>(scribe_category));
  }
  return std::make_unique<CompositeLogger>(std::move(loggers));
}

auto next_wakeup(int sec) {
  return std::chrono::steady_clock::now() + std::chrono::seconds(sec);
}

void kernel_monitor_loop() {
  KernelCollector kc;

  LOG(INFO) << "Running kernel monitor loop : interval = "
            << FLAGS_kernel_monitor_reporting_interval_s << " s.";

  while (1) {
    auto logger = getLogger();
    auto wakeup_timepoint =
        next_wakeup(FLAGS_kernel_monitor_reporting_interval_s);

    kc.step();
    kc.log(*logger);
    logger->finalize();

    /* sleep override */
    std::this_thread::sleep_until(wakeup_timepoint);
  }
}

void perf_monitor_loop() {
  PerfMonitor pm(
      hbt::CpuSet::makeAllOnline(),
      std::vector<ElemId>{"instructions", "cycles"},
      getDefaultPmuDeviceManager(),
      getDefaultMetrics());

  LOG(INFO) << "Running perf monitor loop : interval = "
            << FLAGS_perf_monitor_reporting_interval_s << " s.";

  while (1) {
    auto logger = getLogger();
    auto wakeup_timepoint =
        next_wakeup(FLAGS_perf_monitor_reporting_interval_s);

    pm.step();
    pm.log(*logger);

    logger->finalize();
    /* sleep override */
    std::this_thread::sleep_until(wakeup_timepoint);
  }
}

auto setup_server(std::shared_ptr<ServiceHandler> handler) {
  return std::make_unique<SimpleJsonServer<ServiceHandler>>(
      handler, FLAGS_port);
}

void gpu_monitor_loop() {
  LOG(INFO) << "Setting up DCGM (GPU)  monitoring.";
  std::unique_ptr<gpumon::DcgmGroupInfo> dcgm = gpumon::DcgmGroupInfo::factory(
      gpumon::FLAGS_dcgm_fields, FLAGS_dcgm_reporting_interval_s * 1000);

  auto logger = getLogger(FLAGS_scribe_category);

  LOG(INFO) << "Running DCGM loop : interval = "
            << FLAGS_dcgm_reporting_interval_s << " s.";
  LOG(INFO) << "DCGM fields: " << gpumon::FLAGS_dcgm_fields;

  while (1) {
    auto wakeup_timepoint = next_wakeup(FLAGS_dcgm_reporting_interval_s);

    dcgm->update();
    dcgm->log(*logger);

    /* sleep override */
    std::this_thread::sleep_until(wakeup_timepoint);
  }
}

int main(int argc, char** argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;
  google::InitGoogleLogging(argv[0]);

  LOG(INFO) << "Starting dynolog, version = " DYNOLOG_VERSION
            << ", build git-hash = " DYNOLOG_GIT_REV;

  // setup service
  auto handler = std::make_shared<ServiceHandler>();

  // use simple json RPC server for now
  auto server = setup_server(handler);
  server->run();

  std::unique_ptr<tracing::IPCMonitor> ipcmon;
  std::unique_ptr<std::thread> ipcmon_thread, gpumon_thread, pm_thread;

  if (FLAGS_enable_ipc_monitor) {
    LOG(INFO) << "Starting IPC Monitor";
    ipcmon = std::make_unique<tracing::IPCMonitor>();
    ipcmon_thread =
        std::make_unique<std::thread>([&ipcmon]() { ipcmon->loop(); });
  }

  if (FLAGS_enable_gpu_monitor) {
    gpumon_thread = std::make_unique<std::thread>(gpu_monitor_loop);
  }
  std::thread km_thread{kernel_monitor_loop};
  if (FLAGS_enable_perf_monitor) {
    pm_thread = std::make_unique<std::thread>(perf_monitor_loop);
  }

  km_thread.join();
  if (pm_thread) {
    pm_thread->join();
  }
  if (gpumon_thread) {
    gpumon_thread->join();
  }

  server->stop();

  return 0;
}
