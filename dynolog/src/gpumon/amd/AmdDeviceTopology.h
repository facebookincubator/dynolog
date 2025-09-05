// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

namespace dynolog {
namespace gpumon {
namespace amdgpu {

class LogicalDevice {
 public:
  uint32_t getKfdNodeId() const {
    return kfdNodeId_;
  }
  uint64_t getUniqueId() const {
    return uniqueId_;
  }
  int getMinorId() const {
    return minorId_;
  }

  /**
   * parse AMD GPU topology information from sysfs.
   *
   * reads device information from KFD topology nodes directory.
   * each node directory contains a properties file with device details.
   * only nodes with SIMD units (actual GPUs) are included.
   *
   * @param root base sysfs path, defaults to "/sys/class/kfd"
   * @return vector of LogicalDevice instances for each logical GPU
   */
  static std::vector<std::shared_ptr<LogicalDevice>> parseTopologyNodes(
      const std::filesystem::path& root = "/sys/class/kfd");

  LogicalDevice(uint32_t kfdNodeId, uint64_t uniqueId, int minorId)
      : kfdNodeId_(kfdNodeId), uniqueId_(uniqueId), minorId_(minorId) {}

 protected:
  uint32_t kfdNodeId_;
  uint64_t uniqueId_;
  int minorId_;
};

class PhysicalDevice {
 public:
  static std::vector<std::shared_ptr<PhysicalDevice>> parsePciDevices(
      const std::vector<std::string>& pciAddrs,
      const std::filesystem::path& root = "/sys/bus/pci/drivers/amdgpu");

  static std::shared_ptr<PhysicalDevice> createFromPciDir(
      const std::filesystem::path& pciDir);

  void addLogicalDevice(std::shared_ptr<LogicalDevice> logicalDevice);
  std::vector<std::shared_ptr<LogicalDevice>> getLogicalDevices() const {
    return logicalDevices_;
  }

  uint64_t getUniqueId() const {
    return uniqueId_;
  }

  std::string getPciAddr() const {
    return pciAddr_;
  }

  int getOamId() const {
    return oamId_;
  }

  PhysicalDevice(uint64_t uniqueId, std::string pciAddr, int oamId)
      : uniqueId_(uniqueId), pciAddr_(std::move(pciAddr)), oamId_(oamId) {}

 protected:
  std::vector<std::shared_ptr<LogicalDevice>> logicalDevices_;
  uint64_t uniqueId_;
  std::string pciAddr_;
  int oamId_;
};

std::vector<std::shared_ptr<PhysicalDevice>> buildAmdDeviceTopology(
    std::vector<std::string> pciAddrs,
    const std::filesystem::path& kfdRoot = "/sys/class/kfd",
    const std::filesystem::path& pciRoot = "/sys/bus/pci/drivers/amdgpu");

} // namespace amdgpu
} // namespace gpumon
} // namespace dynolog
