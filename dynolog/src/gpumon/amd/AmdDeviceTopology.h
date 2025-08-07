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
  bool isPartition() const {
    return numPartitions_ > 1;
  }
  size_t getNumPartitions() const {
    return numPartitions_;
  }
  void setPartition(size_t numPartitions) {
    numPartitions_ = numPartitions;
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
  static std::vector<LogicalDevice> parseTopologyNodes(
      const std::filesystem::path& root = "/sys/class/kfd");

 protected:
  LogicalDevice(uint32_t kfdNodeId, uint64_t uniqueId, int minorId)
      : kfdNodeId_(kfdNodeId), uniqueId_(uniqueId), minorId_(minorId) {}
  uint32_t kfdNodeId_;
  uint64_t uniqueId_;
  int minorId_;
  // to be updated after all devices are parsed
  size_t numPartitions_ = 1;
};

class PhysicalDevice {
 protected:
  uint64_t uniqueId_;
  std::string pciAddr_;
  int oamId_;
};

} // namespace amdgpu
} // namespace gpumon
} // namespace dynolog
