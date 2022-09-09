// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

// Dynomin : A portable telemetry monitoring daemon.

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <chrono>
#include <thread>

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "FBRelayLogger.h"
#include "KernelCollector.h"
#include "Logger.h"
#include "ServiceHandler.h"
#include "SimpleJsonServer.h"
#include "SimpleJsonServerInl.h"

using namespace dynolog;

constexpr const char* VERSION = "0.0.1";

DEFINE_int32(port, 1778, "Port for listening RPC requests : FUTURE");
DEFINE_int32(
    reporting_interval_s,
    60,
    "Duration in seconds to read and report metrics");
DEFINE_bool(use_fbrelay, false, "Emit metrics to FB Relay on Lab machines");

std::unique_ptr<Logger> makeLogger() {
  return FLAGS_use_fbrelay ? std::make_unique<FBRelayLogger>()
                           : std::make_unique<JsonLogger>();
}

auto next_wakeup() {
  return std::chrono::steady_clock::now() +
      std::chrono::seconds(FLAGS_reporting_interval_s);
}

void kernel_monitor_loop() {
  KernelCollector kc;

  while (1) {
    auto logger = makeLogger();
    auto wakeup_timepoint = next_wakeup();

    LOG(INFO) << "Running kernel monitor loop : interval = "
              << FLAGS_reporting_interval_s << " s.";
    kc.step();
    kc.log(*logger);

    logger->finalize();
    /* sleep override */
    std::this_thread::sleep_until(wakeup_timepoint);
  }
}

auto setup_server(std::shared_ptr<ServiceHandler> handler) {
  return std::make_unique<SimpleJsonServer<ServiceHandler>>(
      handler, FLAGS_port);
}

int main(int argc, char** argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;
  google::InitGoogleLogging(argv[0]);

  LOG(INFO) << "Starting dynolog min, version " << VERSION;

  // setup service
  auto handler = std::make_shared<ServiceHandler>();

  // use simple json RPC server for now
  auto server = setup_server(handler);
  server->run();

  std::thread km_thread{kernel_monitor_loop};

  km_thread.join();
  server->stop();

  return 0;
}
