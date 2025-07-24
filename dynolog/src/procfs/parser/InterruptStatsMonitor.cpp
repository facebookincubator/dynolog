#include "dynolog/src/procfs/parser/InterruptStatsMonitor.h"

#include <filesystem>
#include <string>
#include <vector>

#include "dynolog/src/String.h"

namespace facebook {
namespace dynolog {

using Granularity = InterruptStatsMonitor::Granularity;
static std::chrono::steady_clock::time_point lastLogTime =
    std::chrono::steady_clock::now();

InterruptStatsMonitor::InterruptStatsMonitor(
    std::shared_ptr<TTicker> ticker,
    const std::string& rootDir)
    : MonitorBase<TTicker>(std::move(ticker), "InterruptStatsMonitor", {}),
      procInterrupts_(rootDir + "/proc/interrupts") {
  cpuCount_ = (int)sysconf(_SC_NPROCESSORS_CONF);
}

InterruptStatsMonitor InterruptStatsMonitor::makeTestClass(
    const std::string& rootDir) {
  std::shared_ptr<InterruptStatsMonitor::TTicker> intTicker =
      std::make_shared<InterruptStatsMonitor::TTicker>();
  return InterruptStatsMonitor(std::move(intTicker), rootDir);
}

InterruptStats InterruptStatsMonitor::getInterruptStatsPerMinute() {
  return statsAtMinuteTick_;
}

InterruptStats InterruptStatsMonitor::getInterruptStatsPerSecond() {
  return statsAtSecondTick_;
}

InterruptStats InterruptStatsMonitor::getInterruptStats(
    Granularity granularity) {
  if (granularity == Granularity::MINUTE) {
    return getInterruptStatsPerMinute();
  } else if (granularity == Granularity::SECOND) {
    return getInterruptStatsPerSecond();
  } else {
    throw std::runtime_error(
        "InterruptStatsMonitor doesn't support requested granularity");
  }
}

void InterruptStatsMonitor::tick(TMask mask) {
  std::unique_lock lock(dataLock_);
  if (TTicker::is_major_tick(mask)) {
    InterruptStats freshStats = interruptsRefresh();
    statsAtMinuteTick_ = std::move(freshStats);
  } else if (TTicker::is_minor_tick(mask)) {
    InterruptStats freshStats = interruptsRefresh();
    statsAtSecondTick_ = std::move(freshStats);
  }
}

InterruptStats InterruptStatsMonitor::interruptsRefresh() {
  int64_t eth0IntrpsSum = 0, eth0Intrps;
  stats.eth0Intrps = 0;

  try {
    if (!procInterrupts_.is_open()) {
      return stats;
    }
    procInterrupts_.clear();
    procInterrupts_.seekg(0);

    for (std::string line; std::getline(procInterrupts_, line);) {
      // expected line format where xxxx refers to a TLB shootdown value for a
      // core One value for one core. So, the number of values should match
      // cpuCount_
      //   TLB xxxx xxxx xxxx .... xxxx xxxx TLB shootdowns
      if (line.find("TLB shootdowns") != std::string::npos) {
        const std::vector<std::string> words = split(line, ' ');
        int64_t tlbshootdowns = 0;
        size_t valueCount = 0;
        for (const auto& word : words) {
          if (std::all_of(word.begin(), word.end(), ::isdigit)) {
            int64_t tlbshootdown = std::stoll(word);
            tlbshootdowns += tlbshootdown;
            valueCount++;
          }
        }
        if (valueCount == cpuCount_) {
          stats.tlbshootdowns = tlbshootdowns - stats.tlbshootdownsPrev;
          stats.tlbshootdowns += (stats.tlbshootdowns < 0) *
              (((stats.tlbshootdowns * -1) - 1) / UINT32_MAX + 1) * UINT32_MAX;
          stats.tlbshootdownsPrev = tlbshootdowns;
        } else {
          LOG(ERROR) << "CPU count from procfs interrupts: " << valueCount
                     << " Expected: " << cpuCount_;
        }
      }

      // expected line format where xxxx refers to a eth0Intrp value for a core
      // One value for one core. So, the number of values should match cpuCount_
      //   IRQ#: xxxx xxxx xxxx .... xxxx xxxx PCI-MSI-edge eth0-#
      // In the some versions of kernel, PCI-MSI-edge part may be separated by a
      // space
      if (line.find("eth0-") != std::string::npos ||
          line.find("mlx5_comp") != std::string::npos) {
        const std::vector<std::string> words = split(line, ' ');
        int64_t eth0IntrpRow = 0;
        size_t valueCount = 0;
        for (const auto& word : words) {
          if (std::all_of(word.begin(), word.end(), ::isdigit)) {
            int64_t eth0Intrp = std::stoll(word);
            eth0IntrpRow += eth0Intrp;
            valueCount++;
          }
        }
        if (valueCount == cpuCount_) {
          eth0IntrpsSum += eth0IntrpRow;
        } else {
          if (std::chrono::steady_clock::now() - lastLogTime >=
              std::chrono::seconds(60)) {
            LOG(WARNING) << "CPU count from procfs interrupts: " << valueCount
                         << " Expected: " << cpuCount_;
            lastLogTime = std::chrono::steady_clock::now();
          }
        }
      }
    }

    if (eth0IntrpsSum) {
      eth0Intrps = eth0IntrpsSum - stats.eth0IntrpsPrev;
      eth0Intrps += (int64_t)(eth0Intrps < 0) *
          (((eth0Intrps * -1) - 1) / UINT32_MAX + 1) * UINT32_MAX;
      stats.eth0IntrpsPrev = eth0IntrpsSum;
      stats.eth0Intrps = eth0Intrps;
    }
  } catch (const std::exception& e) {
    LOG(ERROR) << "Error in reading the procfs interrupts file: " << e.what();
  }
  return stats;
}

} // namespace dynolog
} // namespace facebook
