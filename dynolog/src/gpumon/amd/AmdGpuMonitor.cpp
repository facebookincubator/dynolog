/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/amd/AmdGpuMonitor.h"

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <cmath>
#include <exception>
#include <filesystem>
#include <limits>
#include <string>
#include <system_error>
#include <type_traits>
#include <utility>

#include "dynolog/src/gpumon/amd/AmdRdcCollector.h"

DEFINE_bool(
    enable_amd_rdc,
    false,
    "With --enable_gpu_monitor on AMD GPUs, also collect profiling metrics "
    "(occupancy, FLOPs, HBM and XGMI bandwidth) from ROCm RDC.");
DEFINE_int32(
    amd_rdc_update_interval_ms,
    10000,
    "Sampling interval in ms for RDC profiling metrics.");

namespace dynolog::gpumon {

namespace {

constexpr double kBytesPerMegabit = 1e6 / 8;

// Datasheet peak HBM bandwidth (decimal TB/s), as used by asicmon's amd.conf.
std::optional<double> hbmPeakBytesPerSec(const std::string& modelName) {
  if (modelName.find("MI350") != std::string::npos ||
      modelName.find("MI355") != std::string::npos) {
    return 8e12;
  }
  if (modelName.find("MI300X") != std::string::npos) {
    return 5.3e12;
  }
  return std::nullopt;
}

template <typename T>
bool isSet(T value) {
  if constexpr (std::is_unsigned_v<T>) {
    return value != std::numeric_limits<T>::max();
  } else {
    return value >= 0;
  }
}

template <typename T>
void setInt(
    std::map<std::string, int64_t>& out,
    const std::string& key,
    T value) {
  if (isSet(value)) {
    out[key] = static_cast<int64_t>(value);
  }
}

void setFloat(
    std::map<std::string, double>& out,
    const std::string& key,
    std::optional<double> value) {
  if (value.has_value() && *value >= 0) {
    out[key] = *value;
  }
}

std::optional<double> optionalIfSet(int64_t value) {
  return value >= 0 ? std::optional<double>(value) : std::nullopt;
}

size_t countLogicalDevices(
    const std::vector<std::shared_ptr<amdgpu::PhysicalDevice>>& gpus) {
  size_t count = 0;
  for (const auto& gpu : gpus) {
    count += gpu->getLogicalDevices().size();
  }
  return count;
}

// The device topology of every PCI device bound to the amdgpu driver; empty
// without the driver.
std::vector<std::shared_ptr<amdgpu::PhysicalDevice>> discoverAmdGpus(
    const std::filesystem::path& sysfsRoot) {
  std::error_code ec;
  // Checked up front so hosts without the amdgpu driver don't log a parse
  // error.
  if (!std::filesystem::exists(
          sysfsRoot / "sys/class/kfd/kfd/topology/nodes", ec)) {
    return {};
  }
  // The driver directory also holds non-device entries (bind, module, ...);
  // devices are the subdirectories with a unique_id.
  std::vector<std::string> pciAddrs;
  for (const auto& entry : std::filesystem::directory_iterator(
           sysfsRoot / "sys/bus/pci/drivers/amdgpu", ec)) {
    if (std::filesystem::exists(entry.path() / "unique_id", ec)) {
      pciAddrs.push_back(entry.path().filename());
    }
  }
  return amdgpu::buildAmdDeviceTopology(std::move(pciAddrs), sysfsRoot);
}

void addAmdSmiMetrics(
    const AmdSmiMetrics& m,
    std::map<std::string, int64_t>& ints,
    std::map<std::string, double>& floats) {
  setInt(ints, "gpu_device_utilization", m.gpu_util_percent);
  setInt(ints, "gpu_frequency_mhz", m.gpu_frequency_mhz);
  setInt(ints, "gpu_memory_total_bytes", m.vram_total_bytes);
  setInt(ints, "gpu_memory_used_bytes", m.vram_used_bytes);
  setInt(ints, "gpu_temperature_hotspot_c", m.temperature_hotspot_c);
  setFloat(
      floats, "gpu_power_draw", optionalIfSet(m.current_socket_power_watt));
  setFloat(floats, "gpu_power_limit", optionalIfSet(m.power_limit_watt));
  if (m.pcie_bandwidth_megabits_per_sec >= 0) {
    floats["pcie_total_bytes"] =
        m.pcie_bandwidth_megabits_per_sec * kBytesPerMegabit;
  }
}

void addRdcMetrics(
    const AmdRdcMetrics& m,
    std::map<std::string, int64_t>& ints,
    std::map<std::string, double>& floats) {
  setFloat(floats, "sm_occupancy", m.occupancyRatio);
  setFloat(floats, "graphics_engine_active_ratio", m.activeCyclesRatio);
  setFloat(floats, "simd_utilization", m.simdUtilization);
  setFloat(floats, "fp16_flops_per_sec", m.fp16FlopsPerSec);
  setFloat(floats, "fp32_flops_per_sec", m.fp32FlopsPerSec);
  setFloat(floats, "fp64_flops_per_sec", m.fp64FlopsPerSec);
  setFloat(floats, "hbm_read_bytes", m.hbmReadBytesPerSec);
  setFloat(floats, "hbm_write_bytes", m.hbmWriteBytesPerSec);
  setFloat(floats, "xgmi_rx_bytes", m.xgmiRxBytesPerSec);
  setFloat(floats, "xgmi_tx_bytes", m.xgmiTxBytesPerSec);
  // Fallbacks for values amd-smi also reports; amd-smi overwrites them.
  if (m.gpuUtilPercent.has_value() && *m.gpuUtilPercent >= 0) {
    ints["gpu_device_utilization"] = std::lround(*m.gpuUtilPercent);
  }
  setFloat(floats, "gpu_power_draw", m.powerWatts);
  setFloat(floats, "pcie_total_bytes", m.pcieBytesPerSec);
}

// Aborts the process if RDC can't initialize amd-smi.
std::shared_ptr<AmdRdcCollector> initRdc() {
  const std::chrono::milliseconds interval(FLAGS_amd_rdc_update_interval_ms);
  auto rdc = AmdRdcCollector::factory(interval);
  if (rdc) {
    LOG(INFO) << "RDC initialized, interval = " << interval.count() << " ms";
  } else {
    LOG(WARNING) << "Skipping RDC: failed to initialize";
  }
  return rdc;
}

} // namespace

AmdGpuMonitor::AmdGpuMonitor(
    std::vector<std::shared_ptr<amdgpu::PhysicalDevice>> gpus,
    std::shared_ptr<AmdSmiWrapper> amdSmi,
    std::shared_ptr<AmdRdcCollector> rdc)
    : gpus_(std::move(gpus)), amdSmi_(std::move(amdSmi)), rdc_(std::move(rdc)) {
  if (amdSmi_) {
    try {
      modelName_ = amdSmi_->getModelName();
      hbmPeakBytesPerSec_ = hbmPeakBytesPerSec(modelName_);
    } catch (const std::exception& e) {
      LOG(WARNING) << "Failed to get the AMD GPU model name: " << e.what();
    }
  }
}

AmdGpuMonitor::~AmdGpuMonitor() = default;

std::shared_ptr<AmdGpuMonitor> AmdGpuMonitor::factory(
    const std::filesystem::path& sysfsRoot) {
  auto gpus = discoverAmdGpus(sysfsRoot);
  if (countLogicalDevices(gpus) == 0) {
    LOG(ERROR) << "No AMD GPUs found in KFD sysfs";
    return nullptr;
  }
  LOG(INFO) << "Found " << gpus.size() << " AMD GPUs with "
            << countLogicalDevices(gpus) << " logical devices in KFD sysfs";

  std::shared_ptr<AmdSmiWrapper> amdSmi = std::make_shared<AmdSmiWrapper>();
  try {
    amdSmi->init();
    LOG(INFO) << "amd-smi initialized";
  } catch (const std::exception& e) {
    LOG(WARNING) << "Skipping amd-smi: " << e.what();
    amdSmi = nullptr;
  }

  std::shared_ptr<AmdRdcCollector> rdc;
  if (FLAGS_enable_amd_rdc) {
    rdc = initRdc();
  }

  if (!amdSmi && !rdc) {
    LOG(ERROR) << "No AMD GPU metrics source could be initialized";
    return nullptr;
  }
  return std::make_shared<AmdGpuMonitor>(
      std::move(gpus), std::move(amdSmi), std::move(rdc));
}

bool AmdGpuMonitor::hostHasAmdGpus(const std::filesystem::path& sysfsRoot) {
  return countLogicalDevices(discoverAmdGpus(sysfsRoot)) > 0;
}

std::unique_ptr<std::thread> AmdGpuMonitor::startMonitoring(
    std::shared_ptr<AmdGpuMonitor> monitor,
    std::unique_ptr<Logger> logger,
    std::chrono::seconds interval) {
  LOG(INFO) << "Running AMD GPU loop : interval = " << interval.count()
            << " s.";
  return std::make_unique<std::thread>(
      [monitor = std::move(monitor), logger = std::move(logger), interval]() {
        while (true) {
          const auto wakeup = std::chrono::steady_clock::now() + interval;
          monitor->update();
          monitor->log(*logger);
          /* sleep override */
          std::this_thread::sleep_until(wakeup);
        }
      });
}

void AmdGpuMonitor::update() {
  bool anySourceRead = false;

  std::map<AmdSmiNodeId, AmdSmiMetrics> amdSmiMetrics;
  if (amdSmi_) {
    try {
      amdSmiMetrics = amdSmi_->getMetrics();
      anySourceRead = true;
    } catch (const std::exception& e) {
      LOG_EVERY_N(ERROR, 10)
          << "Failed to collect amd-smi metrics: " << e.what();
    }
  }

  std::map<uint32_t, AmdRdcMetrics> rdcMetrics;
  if (rdc_) {
    try {
      rdcMetrics = rdc_->collect(gpus_, std::chrono::steady_clock::now());
      anySourceRead = true;
    } catch (const std::exception& e) {
      LOG_EVERY_N(ERROR, 10) << "Failed to collect RDC metrics: " << e.what();
    }
  }

  failing_ = !anySourceRead;
  records_.clear();
  for (const auto& gpu : gpus_) {
    for (const auto& logical : gpu->getLogicalDevices()) {
      const auto nodeId = logical->getKfdNodeId();
      Record record;
      if (const auto it = rdcMetrics.find(nodeId); it != rdcMetrics.end()) {
        addRdcMetrics(it->second, record.ints, record.floats);
      }
      const auto amdSmiIt = amdSmiMetrics.find(nodeId);
      const AmdSmiMetrics* amdSmi =
          amdSmiIt == amdSmiMetrics.end() ? nullptr : &amdSmiIt->second;
      if (amdSmi != nullptr) {
        addAmdSmiMetrics(*amdSmi, record.ints, record.floats);
      }

      const auto read = record.floats.find("hbm_read_bytes");
      const auto write = record.floats.find("hbm_write_bytes");
      if (hbmPeakBytesPerSec_.has_value() && read != record.floats.end() &&
          write != record.floats.end()) {
        record.floats["hbm_mem_bw_util"] =
            (read->second + write->second) / *hbmPeakBytesPerSec_;
      }

      if (record.ints.empty() && record.floats.empty()) {
        continue;
      }
      record.ints["kfd_id"] = static_cast<int64_t>(logical->getKfdGpuId());
      setInt(record.ints, "minor_id", logical->getMinorId());
      setInt(record.ints, "oam_id", gpu->getOamId());
      // Only amd-smi knows a device's partition index.
      if (amdSmi != nullptr) {
        setInt(record.ints, "partition_id", amdSmi->partition_id);
      }
      records_[nodeId] = std::move(record);
    }
  }
}

void AmdGpuMonitor::log(Logger& logger) const {
  logger.setTimestamp();
  for (const auto& [nodeId, record] : records_) {
    for (const auto& [key, value] : record.floats) {
      logger.logFloat(key, static_cast<float>(value));
    }
    for (const auto& [key, value] : record.ints) {
      logger.logInt(key, value);
    }
    if (!modelName_.empty()) {
      logger.logStr("gpu_name", modelName_);
    }
    logger.logInt("device", nodeId);
    logger.finalize();
  }
}

} // namespace dynolog::gpumon
