/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// Dynolog : A portable telemetry monitoring daemon.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <algorithm>
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

#ifdef USE_TPU
#include "dynolog/src/tpumon/TpuGroupInfo.h"
#endif

#ifdef USE_AMD_GPU
// x86_64-only dependency, added through select() in BUCK.
#include "dynolog/src/gpumon/amd/AmdGpuMonitor.h" // @manual
#endif

#ifdef USE_PROMETHEUS
#include "dynolog/src/PrometheusLogger.h"
#endif
#ifdef USE_OTEL
#include "dynolog/src/OtlpLogger.h"
#endif

#ifdef USE_OTLP
#include "dynolog/src/OtlpMetricsLogger.h"
#endif

using namespace dynolog;
using json = nlohmann::json;
namespace hbt = facebook::hbt;

DEFINE_int32(port, 1778, "Port for listening RPC requests.");
DEFINE_bool(use_JSON, false, "Emit metrics to JSON file through JSON logger");
#ifdef USE_PROMETHEUS
DEFINE_bool(use_prometheus, false, "Emit metrics to Prometheus");
#endif
#ifdef USE_OTLP
DEFINE_bool(use_otlp, false, "Emit metrics to OTLP endpoint");
#endif
DEFINE_bool(use_fbrelay, false, "Emit metrics to FB Relay on Lab machines");
DEFINE_bool(use_ODS, false, "Emit metrics to ODS through ODS logger");
DEFINE_bool(use_scuba, false, "Emit metrics to Scuba through Scuba logger");
#ifdef USE_OTEL
DEFINE_bool(
    use_otel,
    false,
    "Emit metrics via OTLP to an OpenTelemetry collector");
DEFINE_bool(
    use_otel_for_kernel_monitor,
    false,
    "Include OtlpLogger in the kernel monitor loop. Off by default because "
    "OtlpLogger emits one record per finalize() and the kernel monitor has "
    "no per-device key, producing rows with NULL device_id downstream.");
#endif
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
    "Duration in seconds to read and report metrics for GPU monitoring "
    "(DCGM or AMD)");
#ifdef USE_TPU
DEFINE_bool(
    enable_tpu_monitor,
    false,
    "Enable TPU monitor. Scrapes tpu-device-plugin's Prometheus /metrics "
    "endpoint on the local node (see --tpu_device_plugin_url) and emits "
    "one metric record per chip per cycle.");
DEFINE_int32(
    tpu_reporting_interval_s,
    10,
    "Duration in seconds between TPU scrapes.");
DEFINE_int32(
    tpu_scrape_timeout_ms,
    2000,
    "Per-scrape HTTP timeout in ms for --tpu_device_plugin_url.");
#endif
DEFINE_bool(
    enable_ipc_monitor,
    false,
    "Enabled IPC monitor for on system tracing requests.");
DEFINE_bool(
    enable_gpu_monitor,
    false,
    "Enable GPU monitoring. Uses AMD GPU monitoring (KFD sysfs, amd-smi, "
    "RDC) if AMD GPUs are found on the host and dynolog was built with "
    "USE_AMD_GPU, otherwise NVIDIA DCGM.");
DEFINE_bool(enable_perf_monitor, false, "Enable heartbeat perf monitoring.");

std::unique_ptr<Logger> getLogger(
    const std::string& scribe_category = "",
    bool include_otel = false) {
  std::vector<std::unique_ptr<Logger>> loggers;
#ifdef USE_PROMETHEUS
  if (FLAGS_use_prometheus) {
    loggers.push_back(std::make_unique<PrometheusLogger>());
  }
#endif
#ifdef USE_OTLP
  if (FLAGS_use_otlp) {
    loggers.push_back(std::make_unique<OTLPLogger>());
  }
#endif
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
#ifdef USE_OTEL
  // OtlpLogger is per-device (DcgmGroupInfo emits one finalize() per GPU).
  // Only the GPU loop opts in; including it in the kernel/perf loops would
  // produce a host-level record with NULL device_id every cycle.
  if (include_otel && FLAGS_use_otel) {
    loggers.push_back(std::make_unique<OtlpLogger>());
  }
#endif
  return std::make_unique<CompositeLogger>(std::move(loggers));
}

auto next_wakeup(int sec) {
  return std::chrono::steady_clock::now() + std::chrono::seconds(sec);
}

void kernel_monitor_loop() {
  KernelCollector kc;

  LOG(INFO) << "Running kernel monitor loop : interval = "
            << FLAGS_kernel_monitor_reporting_interval_s << " s.";

  bool include_otel = false;
#ifdef USE_OTEL
  include_otel = FLAGS_use_otel_for_kernel_monitor;
#endif

  while (true) {
    auto logger = getLogger(/*scribe_category=*/"", include_otel);
    auto wakeup_timepoint =
        next_wakeup(FLAGS_kernel_monitor_reporting_interval_s);

    try {
      kc.step();
      kc.log(*logger);
      logger->finalize();
    } catch (const std::system_error& e) {
      LOG(ERROR) << "Kernel monitor error: " << e.what()
                 << " (code=" << e.code() << "). Skipping cycle.";
    }

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

  while (true) {
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

auto setup_server(const std::shared_ptr<ServiceHandler>& handler) {
  return std::make_unique<SimpleJsonServer<ServiceHandler>>(
      handler, FLAGS_port);
}

[[noreturn]] void gpu_monitor_loop(
    const std::shared_ptr<gpumon::DcgmGroupInfo>& dcgm) {
  auto logger = getLogger(FLAGS_scribe_category, /*include_otel=*/true);

  LOG(INFO) << "Running DCGM loop : interval = "
            << FLAGS_dcgm_reporting_interval_s << " s.";
  LOG(INFO) << "DCGM fields: " << gpumon::FLAGS_dcgm_fields;

  while (true) {
    auto wakeup_timepoint = next_wakeup(FLAGS_dcgm_reporting_interval_s);

    dcgm->update();
    dcgm->log(*logger);

    /* sleep override */
    std::this_thread::sleep_until(wakeup_timepoint);
  }
}

#ifdef USE_TPU
[[noreturn]] void tpu_monitor_loop(
    const std::shared_ptr<tpumon::TpuGroupInfo>& tpu) {
  auto logger = getLogger(FLAGS_scribe_category, /*include_otel=*/true);

  LOG(INFO) << "Running TPU loop : interval = "
            << FLAGS_tpu_reporting_interval_s
            << " s, url = " << tpumon::FLAGS_tpu_device_plugin_url;

  const auto interval =
      std::chrono::seconds(std::max(1, FLAGS_tpu_reporting_interval_s));
  auto lastTick = std::chrono::system_clock::time_point::min();
  while (true) {
    // Stamp with the scheduled tick rather than the time the scrape finished,
    // so scrape latency can't put two samples in one interval-wide bucket.
    const auto now = std::chrono::system_clock::now();
    const auto tick = tpumon::nextAlignedTick(now, interval);
    // sleep_for runs on the monotonic clock, so a wall-clock step during the
    // wait delays at most one interval.
    /* sleep override */
    std::this_thread::sleep_for(tick - now);
    // After the wall clock steps back, skip ticks already emitted rather
    // than stamping a newer sample with an older or duplicate time.
    if (tick <= lastTick) {
      LOG_EVERY_N(WARNING, 6)
          << "Wall clock moved backwards; skipping TPU sample for tick "
          << std::chrono::system_clock::to_time_t(tick);
      continue;
    }
    lastTick = tick;

    tpu->update();
    tpu->log(*logger, tick);
  }
}

bool start_tpu_monitor(std::unique_ptr<std::thread>& thread) {
  if (!FLAGS_enable_tpu_monitor) {
    return true;
  }

  auto tpu = tpumon::TpuGroupInfo::factory(
      tpumon::FLAGS_tpu_device_plugin_url,
      FLAGS_tpu_scrape_timeout_ms,
      FLAGS_tpu_reporting_interval_s * 1000);
  if (!tpu) {
    LOG(ERROR) << "Failed to initialize TpuGroupInfo";
    return false;
  }
  thread = std::make_unique<std::thread>(tpu_monitor_loop, std::move(tpu));
  return true;
}
#else
bool start_tpu_monitor(std::unique_ptr<std::thread>&) {
  return true;
}
#endif

int main(int argc, char** argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = true;
  google::InitGoogleLogging(argv[0]);

  LOG(INFO) << "Starting dynolog, version = " DYNOLOG_VERSION
            << ", build git-hash = " DYNOLOG_GIT_REV;

  std::shared_ptr<gpumon::DcgmGroupInfo> dcgm;

  std::unique_ptr<tracing::IPCMonitor> ipcmon;
  std::unique_ptr<std::thread> ipcmon_thread, gpumon_thread, tpumon_thread,
      pm_thread;

  if (FLAGS_enable_ipc_monitor) {
    LOG(INFO) << "Starting IPC Monitor";
    ipcmon = std::make_unique<tracing::IPCMonitor>();
    ipcmon_thread =
        std::make_unique<std::thread>([&ipcmon]() { ipcmon->loop(); });
  }

  if (FLAGS_enable_gpu_monitor) {
#ifdef USE_AMD_GPU
    if (gpumon::AmdGpuMonitor::hostHasAmdGpus()) {
      auto amd = gpumon::AmdGpuMonitor::factory();
      if (!amd) {
        LOG(ERROR) << "Failed to initialize AMD GPU monitoring";
        return 1;
      }
      gpumon_thread = gpumon::AmdGpuMonitor::startMonitoring(
          std::move(amd),
          getLogger(FLAGS_scribe_category, /*include_otel=*/true),
          std::chrono::seconds(FLAGS_dcgm_reporting_interval_s));
    }
#endif
    if (!gpumon_thread) {
      dcgm = gpumon::DcgmGroupInfo::factory(
          gpumon::FLAGS_dcgm_fields, FLAGS_dcgm_reporting_interval_s * 1000);
      if (!dcgm) {
        LOG(ERROR) << "Failed to initialize DCGM";
        return 1;
      } else {
        gpumon_thread = std::make_unique<std::thread>(gpu_monitor_loop, dcgm);
      }
    }
  }
  if (!start_tpu_monitor(tpumon_thread)) {
    return 1;
  }

  std::thread km_thread{kernel_monitor_loop};
  if (FLAGS_enable_perf_monitor) {
    pm_thread = std::make_unique<std::thread>(perf_monitor_loop);
  }

  // setup service
  auto handler = std::make_shared<ServiceHandler>(dcgm);

  // use simple json RPC server for now
  auto server = setup_server(handler);
  server->run();

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
