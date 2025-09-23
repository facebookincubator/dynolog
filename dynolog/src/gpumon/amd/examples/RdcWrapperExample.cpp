/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/amd/RdcWrapper.h"

#include <unistd.h>
#include <iostream>
#include <thread>

static std::vector<rdc_field_t> kRdcWatchedFields = {
    RDC_FI_GPU_UTIL,
    RDC_FI_OAM_ID,
    RDC_FI_PCIE_BANDWIDTH,
    RDC_FI_POWER_USAGE,
    RDC_FI_PROF_OCCUPANCY_PERCENT,
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
    RDC_FI_PROF_KFD_ID,
    RDC_FI_PROF_SIMD_UTILIZATION};

int main() {
  dynolog::gpumon::RdcWrapper rdcWrapper(kRdcWatchedFields);
  auto entities = rdcWrapper.getMonitoredEntities();

  auto worker = std::thread([&]() {
    while (true) {
      sleep(1);
      for (auto entity : entities) {
        auto metricMap = rdcWrapper.getRdcMetricsForDevice(entity);
        std::cout << "entity: " << entity << std::endl;
        for (const auto& [field, value] : metricMap) {
          std::visit(
              [field](auto&& arg) {
                std::cout << field << ": " << arg << std::endl;
              },
              value);
        }
      }
    }
  });

  worker.join();
  return 0;
}
