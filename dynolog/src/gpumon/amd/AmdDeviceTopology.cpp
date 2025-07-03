// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

/*
 * Implementation of AMD GPU device topology parsing.
 * Reads device information from the KFD sysfs interface.
 */

#include "dynolog/src/gpumon/amd/AmdDeviceTopology.h"

#include <glog/logging.h>
#include <filesystem>
#include <fstream>
#include <optional>
#include <stdexcept>
#include <unordered_map>

namespace dynolog {
namespace gpumon {
namespace amdgpu {

std::vector<LogicalDevice> LogicalDevice::parseTopologyNodes(
    const std::filesystem::path& root) {
  const auto topologyPath = root / "kfd" / "topology" / "nodes";
  std::vector<LogicalDevice> devices;

  try {
    for (const auto& entry :
         std::filesystem::directory_iterator(topologyPath)) {
      if (!entry.is_directory()) {
        continue;
      }

      // Read and parse the properties file for this node
      auto propertiesPath = entry.path() / "properties";
      std::ifstream props(propertiesPath);
      if (!props.is_open()) {
        throw std::runtime_error(
            "Failed to open properties file: " + propertiesPath.string());
      }

      uint32_t kfdNodeId = std::stoul(entry.path().filename());
      std::string line;
      std::optional<uint64_t> uniqueId;
      std::optional<int> minorId;
      std::optional<int> simdCount;

      // Parse key properties: unique_id, drm_render_minor, simd_count
      while (std::getline(props, line)) {
        // Find first space that separates property name from value
        auto pos = line.find(' ');
        if (pos == std::string::npos) {
          continue;
        }

        // Extract and compare property name
        std::string prop = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        if (prop == "drm_render_minor") {
          minorId = std::stoi(value);
        } else if (prop == "unique_id") {
          uniqueId = std::stoull(value);
        } else if (prop == "simd_count") {
          simdCount = std::stoi(value);
        }
      }

      if (!simdCount.has_value() || simdCount.value() <= 0) {
        // This node is not a GPU, skip it
        continue;
      }

      // Validate that all required properties were found
      if (!minorId.has_value()) {
        LOG(ERROR) << "Missing drm_render_minor field for node "
                   << std::to_string(kfdNodeId);
        continue;
      }
      if (!uniqueId.has_value()) {
        LOG(ERROR) << "Missing or invalid unique_id field for node "
                   << std::to_string(kfdNodeId);
        continue;
      }

      // Only include nodes that have SIMD units (actual GPUs) and all of the
      // required properties
      devices.push_back(
          LogicalDevice(kfdNodeId, uniqueId.value(), minorId.value()));
    }
  } catch (const std::exception& e) {
    LOG(ERROR) << "Error parsing topology nodes: " << e.what();
    return {};
  }

  std::unordered_map<uint64_t, int> numPartitions;
  for (const auto& device : devices) {
    numPartitions[device.getUniqueId()]++;
  }
  for (auto& device : devices) {
    device.setPartition(numPartitions.at(device.getUniqueId()) > 1);
  }

  return devices;
}

} // namespace amdgpu
} // namespace gpumon
} // namespace dynolog
