/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

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

namespace dynolog {
namespace gpumon {
namespace amdgpu {

std::vector<std::shared_ptr<LogicalDevice>> LogicalDevice::parseTopologyNodes(
    const std::filesystem::path& root) {
  const auto topologyPath = root / "kfd" / "topology" / "nodes";
  std::vector<std::shared_ptr<LogicalDevice>> devices;

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
          std::make_shared<LogicalDevice>(
              kfdNodeId, uniqueId.value(), minorId.value()));
    }
  } catch (const std::exception& e) {
    LOG(ERROR) << "Error parsing topology nodes: " << e.what();
    return {};
  }
  return devices;
}

// Convert hex string to uint64_t
uint64_t hexToUint64(const std::string& hexStr) {
  uint64_t value = 0;
  std::istringstream iss(hexStr);
  iss >> std::hex >> value;
  return value;
}

std::shared_ptr<PhysicalDevice> PhysicalDevice::createFromPciDir(
    const std::filesystem::path& pciDir) {
  std::filesystem::path uniqueIdPath = pciDir / "unique_id";
  std::filesystem::path xgmiIdPath = pciDir / "xgmi_physical_id";
  // Read unique_id
  std::ifstream uniqueIdFile(uniqueIdPath);
  if (!uniqueIdFile) {
    LOG(ERROR) << "Failed to open " << uniqueIdPath;
    return nullptr;
  }
  std::string uniqueIdStr;
  std::getline(uniqueIdFile, uniqueIdStr);
  uint64_t uniqueId = hexToUint64(uniqueIdStr);
  // Read xgmi_physical_id
  std::ifstream xgmiIdFile(xgmiIdPath);
  if (!xgmiIdFile) {
    LOG(ERROR) << "Failed to open " << xgmiIdPath;
    return nullptr;
  }
  std::string xgmiIdStr;
  std::getline(xgmiIdFile, xgmiIdStr);
  int xgmiId = std::stoi(xgmiIdStr);

  // Parse minor ID from drm/renderD*/uevent
  int minorId = -1;
  std::filesystem::path drmPath = pciDir / "drm";
  try {
    if (std::filesystem::exists(drmPath) &&
        std::filesystem::is_directory(drmPath)) {
      for (const auto& entry : std::filesystem::directory_iterator(drmPath)) {
        if (entry.is_directory() &&
            entry.path().filename().string().rfind("render", 0) == 0) {
          std::filesystem::path ueventPath = entry.path() / "uevent";
          std::ifstream ueventFile(ueventPath);
          if (ueventFile) {
            std::string line;
            while (std::getline(ueventFile, line)) {
              if (line.rfind("MINOR=", 0) == 0) {
                minorId = std::stoi(line.substr(6));
                break;
              }
            }
          }
          break;
        }
      }
    }
  } catch (const std::exception& e) {
    LOG(ERROR) << "Failed to parse minor ID from " << drmPath << ": "
               << e.what();
  }

  return std::make_shared<PhysicalDevice>(
      uniqueId, pciDir.filename(), xgmiId, minorId);
}

std::vector<std::shared_ptr<PhysicalDevice>> PhysicalDevice::parsePciDevices(
    const std::vector<std::string>& pciAddrs,
    const std::filesystem::path& root) {
  std::vector<std::shared_ptr<PhysicalDevice>> res;
  for (const auto& addr : pciAddrs) {
    auto device = createFromPciDir(root / addr);
    if (device) {
      res.push_back(std::move(device));
    }
  }
  return res;
}

void PhysicalDevice::addLogicalDevice(std::shared_ptr<LogicalDevice> device) {
  logicalDevices_.push_back(std::move(device));
}

std::vector<std::shared_ptr<PhysicalDevice>> buildAmdDeviceTopology(
    std::vector<std::string> pciAddrs,
    const std::filesystem::path& sysFsRootPath) {
  const auto kfdRoot = sysFsRootPath / "sys/class/kfd";
  const auto pciRoot = sysFsRootPath / "sys/bus/pci/drivers/amdgpu";
  // Parse logical device info from KFD interface
  auto logicalDevices = LogicalDevice::parseTopologyNodes(kfdRoot);
  // Parse physical device info from PCI sysfs interface
  auto physicalDevices =
      PhysicalDevice::parsePciDevices(std::move(pciAddrs), pciRoot);
  // Correlate logical and physical devices using uniqueId
  for (const auto& physical : physicalDevices) {
    for (const auto& logical : logicalDevices) {
      if (physical->getUniqueId() == logical->getUniqueId()) {
        physical->addLogicalDevice(logical);
      }
    }
    // Fallback to minor id if no matched unique id for some reason
    if (physical->getLogicalDevices().empty()) {
      for (const auto& logical : logicalDevices) {
        if (logical->getMinorId() / 8 == physical->getMinorId() / 8) {
          physical->addLogicalDevice(logical);
        }
      }
    }
  }
  return physicalDevices;
}

} // namespace amdgpu
} // namespace gpumon
} // namespace dynolog
