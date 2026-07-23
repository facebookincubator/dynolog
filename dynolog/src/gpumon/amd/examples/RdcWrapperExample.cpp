/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/amd/RdcWrapper.h"

#include <gflags/gflags.h>
#include <unistd.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <variant>
#include <vector>

#ifdef DYNOLOG_ROCM_VERSION
#include <dlfcn.h>
#include <array>
#include <cstdlib>
#include <filesystem>
#endif

DEFINE_int32(
    update_interval_ms,
    1000,
    "Update interval in milliseconds for RDC metrics collection");
DEFINE_int32(
    max_keep_age_seconds,
    10,
    "Maximum age in seconds to keep RDC samples");
DEFINE_int32(max_keep_samples, 100, "Maximum number of samples to keep");

#ifdef DYNOLOG_ROCM_VERSION
constexpr int kRocmVersion = DYNOLOG_ROCM_VERSION;
#else
constexpr int kRocmVersion = 0;
#endif

namespace {

const std::vector<rdc_field_t> kEnabledMetrics = {
#if DYNOLOG_ROCM_VERSION >= 60200
    RDC_FI_GPU_UTIL,
    RDC_FI_OAM_ID,
    RDC_FI_PCIE_BANDWIDTH,
    RDC_FI_POWER_USAGE,
    RDC_FI_PROF_OCCUPANCY_PERCENT,
#endif
#if DYNOLOG_ROCM_VERSION >= 60201
    RDC_FI_PROF_EVAL_MEM_R_BW,
    RDC_FI_PROF_EVAL_MEM_W_BW,
    RDC_FI_PROF_EVAL_FLOPS_16,
    RDC_FI_PROF_EVAL_FLOPS_32,
    RDC_FI_PROF_EVAL_FLOPS_64,
    RDC_FI_PROF_ACTIVE_CYCLES,
    RDC_FI_PROF_ELAPSED_CYCLES,
    RDC_FI_XGMI_0_READ_KB,
    RDC_FI_XGMI_1_READ_KB,
    RDC_FI_XGMI_2_READ_KB,
    RDC_FI_XGMI_3_READ_KB,
    RDC_FI_XGMI_4_READ_KB,
    RDC_FI_XGMI_5_READ_KB,
    RDC_FI_XGMI_6_READ_KB,
    RDC_FI_XGMI_7_READ_KB,
    RDC_FI_XGMI_0_WRITE_KB,
    RDC_FI_XGMI_1_WRITE_KB,
    RDC_FI_XGMI_2_WRITE_KB,
    RDC_FI_XGMI_3_WRITE_KB,
    RDC_FI_XGMI_4_WRITE_KB,
    RDC_FI_XGMI_5_WRITE_KB,
    RDC_FI_XGMI_6_WRITE_KB,
    RDC_FI_XGMI_7_WRITE_KB,
#endif
#if DYNOLOG_ROCM_VERSION >= 70000
    RDC_FI_KFD_ID,
    RDC_FI_PROF_SIMD_UTILIZATION,
#elif DYNOLOG_ROCM_VERSION >= 60402
    RDC_FI_PROF_KFD_ID,
    RDC_FI_PROF_SIMD_UTILIZATION,
#endif
};

#ifdef DYNOLOG_ROCM_VERSION
// Preload the ROCm RDC shared libraries from ROCM_PATH as a workaround for
// dependency loading issues. Only compiled and run when DYNOLOG_ROCM_VERSION is
// defined.
void preloadRocmLibs() {
  const char* rocmHome = getenv("ROCM_PATH");
  if (rocmHome == nullptr) {
    std::cerr << "ROCM_PATH is not set, skipping RDC preload\n";
    return;
  }
  std::filesystem::path rocmPath(rocmHome);
  const std::array<std::filesystem::path, 3> rdcLibs = {
      rocmPath / "lib/rdc/librdc_rocp.so",
      rocmPath / "lib/rdc/librdc_rvs.so",
      rocmPath / "lib/rdc/librdc_rocr.so"};
  for (const auto& lib : rdcLibs) {
    void* rdc = dlopen(lib.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    if (rdc == nullptr) {
      std::cerr << "Failed to load " << lib << ": " << dlerror() << "\n";
      continue;
    }
    std::cout << "Loaded " << lib << "\n";
  }
}
#endif

} // namespace

int main(int argc, char** argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);

#ifdef DYNOLOG_ROCM_VERSION
  preloadRocmLibs();
#endif

  std::cout << "Initializing RDC example, ROCM version: " << kRocmVersion
            << std::endl;
  std::cout << "RDC watch config: update_interval=" << FLAGS_update_interval_ms
            << "ms, max_keep_age=" << FLAGS_max_keep_age_seconds
            << "s, max_keep_samples=" << FLAGS_max_keep_samples << std::endl;

  std::cout << "Collecting " << kEnabledMetrics.size()
            << " metrics:" << std::endl;
  for (const auto field : kEnabledMetrics) {
    std::cout << "  metric " << field_id_string(field) << " (id=" << field
              << ")" << std::endl;
  }

  dynolog::gpumon::RdcWrapper rdcWrapper(
      kEnabledMetrics,
      std::chrono::milliseconds(FLAGS_update_interval_ms),
      std::chrono::seconds(FLAGS_max_keep_age_seconds),
      FLAGS_max_keep_samples);

  const auto entities = rdcWrapper.getMonitoredEntities();
  std::cout << "Monitoring " << entities.size()
            << " entities (physical GPUs + partitions):" << std::endl;
  for (const auto entity : entities) {
    std::cout << "  entity index=" << entity << std::endl;
  }

  // This example runs until killed (Ctrl-C / SIGTERM): the worker loops
  // forever polling metrics, so worker.join() below never returns and there is
  // no clean shutdown path by design.
  auto worker = std::thread([&]() {
    while (true) {
      sleep(1);
      for (const auto entity : entities) {
        const auto metricMap = rdcWrapper.getRdcMetricsForDevice(entity);
        std::cout << "entity " << entity << ": collected " << metricMap.size()
                  << " metrics" << std::endl;
        for (const auto& [field, value] : metricMap) {
          std::visit(
              [entity, field](auto&& arg) {
                std::cout << "  entity " << entity << " "
                          << field_id_string(field) << " (id=" << field
                          << ")=" << arg << std::endl;
              },
              value);
        }
      }
    }
  });

  worker.join();
  return 0;
}
