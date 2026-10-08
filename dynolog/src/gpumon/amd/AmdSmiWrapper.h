/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <cstdint>
#include <limits>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#include "amd_smi/amdsmi.h" // @manual=fbsource//third-party/rocm:amd_smi-lazy

namespace dynolog {
namespace gpumon {

using AmdSmiNodeId = uint32_t;

struct AmdSmiMetrics {
  uint64_t kfd_id = std::numeric_limits<uint64_t>::max();
  uint32_t oam_id = std::numeric_limits<uint32_t>::max();
  uint32_t partition_id = std::numeric_limits<uint32_t>::max();
  uint32_t node_id = std::numeric_limits<uint32_t>::max();
  int gpu_util_percent = -1;

  // Physical-device metrics, copied to every partition. -1 when amd-smi
  // cannot report them.
  int64_t vram_total_bytes = -1;
  int64_t vram_used_bytes = -1;
  int64_t current_socket_power_watt = -1;
  int64_t power_limit_watt = -1;
  // rx + tx
  int64_t pcie_bandwidth_megabits_per_sec = -1;
  int64_t pcie_max_link_speed_mts = -1;
  int64_t pcie_max_link_width = -1;
  int64_t gpu_frequency_mhz = -1;
  int64_t temperature_hotspot_c = -1;
};

// Thread-safe wrapper around the AMD SMI library. All methods throw
// std::runtime_error on failure.
class AmdSmiWrapper {
 public:
  // Idempotent; subsequent calls after a successful init are no-ops.
  void init();
  bool isInitialized() const;
  // Model name of the first GPU found; all GPUs on a host are assumed to be
  // the same model.
  std::string getModelName();
  // Metrics for every logical device (partition), keyed by KFD node id.
  std::map<AmdSmiNodeId, AmdSmiMetrics> getMetrics();

 protected:
  std::vector<amdsmi_socket_handle> getSocketHandles_();
  std::vector<amdsmi_processor_handle> getProcessorHandles_(
      amdsmi_socket_handle socketHandle);
  std::map<AmdSmiNodeId, AmdSmiMetrics> getMetricsFromSocket_(
      amdsmi_socket_handle socketHandle);
  std::string getModelNameFromSocket_(amdsmi_socket_handle socketHandle);

  bool initialized_ = false;
  // amdsmi calls are serialized through this lock
  mutable std::mutex amdsmiMutex_;
};

} // namespace gpumon
} // namespace dynolog
