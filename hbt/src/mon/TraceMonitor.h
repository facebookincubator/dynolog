// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/mon/MonData.h"
#include "hbt/src/mon/TraceCollector.h"

namespace facebook::hbt::mon {

/// An extension of TraceCollector that adds the creation
/// on CuMonData objects from slices and counts.
/// It provides a higher abstraction to access to the
/// data collected by TraceCollector, providing an API
/// that releases the data collected..
class TraceMonitor : public TraceCollector {
 public:
  explicit TraceMonitor(const CpuSet& mon_cpus) : TraceCollector{mon_cpus} {}

  // Consumes slice and count data and generates slices from it.
  // The slices and metadata are stored in a new MonData object
  // that contains a CuMonData object for each Compute Unit (CUs).
  std::shared_ptr<MonData> releaseMonData(
      const std::string& key,
      std::optional<TimeStamp> stop_ts_opt,
      const std::string& short_desc,
      const std::string& long_desc);

  /// Read events from each CPU's ringbuffer and apply <func> to it.
  /// The reads are done
  template <class TFunc>
  void applyToCountSamplesAndConsume(
      const std::string& count_gen_key,
      TFunc& func) {
    std::lock_guard<std::mutex> counts_lock{counts_mutex_};

    auto it = interval_sources_.find(count_gen_key);
    HBT_ARG_CHECK(it != interval_sources_.end())
        << "Invalid count_gen_key: " << count_gen_key;

    // Get count generator corresponding to count countGenKey_
    HBT_DCHECK(it->second != nullptr)
        << "No Count Generator for key \"" << count_gen_key
        << "\". Try printing class status.";
    auto& cg_ctxt = it->second;
    HBT_DCHECK(cg_ctxt->count_gen != nullptr);
    auto& cg = cg_ctxt->count_gen;

    // To avoid taking too long and degrade overall service, check elapsed time
    // and cut if it's taking too long.
    auto deadline =
        std::chrono::steady_clock::now() + std::chrono::milliseconds(900);
    const int kEventsBatchSize = 1000;

    const auto& cpuset = getMonCpus();
    const auto& event_nicknames =
        cg->metric_desc->eventNicknames(cg->pmu_manager->cpuInfo.cpu_arch);
    const auto kNumEvents = cg->getNumEvents();
    HBT_DCHECK_EQ(event_nicknames.size(), kNumEvents);
    for_each_cpu(cpu, cpuset) {
      int count_idx = 0;
      bool cpu_done = false;

      while (!cpu_done && std::chrono::steady_clock::now() < deadline) {
        auto& cpu_cg = cg->getCpuGenerator(cpu);
        const auto kWriteByteSize = cpu_cg.kWriteByteSize;
        auto& consumer = cg_ctxt->count_gen_consumers.at(cpu);
        auto ret = consumer.startTx();
        HBT_THROW_SYSTEM_CODE_IF(0 > ret, toErrorCode(-ret));

        for (int i = 0; i < kEventsBatchSize; ++i) {
          auto [nread, d] = consumer.readInTx(kWriteByteSize);
          if (0 > nread) {
            // ENODATA is an acceptable error as it means we are done.
            // Anything else should be logged.
            HBT_THROW_SYSTEM_CODE_IF(
                0 > nread && nread != -ENODATA, toErrorCode(-nread));
            // Stop at first error or ENODATA.
            cpu_done = true;
            break;
          }
          HBT_THROW_ASSERT_IF(nread != kWriteByteSize) << fmt::format(
              "RingBuffer read error. Expected {} bytes, read {} bytes",
              kWriteByteSize,
              nread);
          auto p = reinterpret_cast<const uint64_t*>(d);
          HBT_DCHECK_NOT_NULLPTR(p)
              << fmt::format("Timestamp cannot be null pointer");
          TimeStamp tstamp = *p, duration = *(p + 1);
          // All fields after first two are counts.
          const uint64_t* event_count_ptr = p + 2;
          func(
              cpu,
              count_idx,
              event_nicknames,
              tstamp,
              duration,
              event_count_ptr,
              kNumEvents);
          ++count_idx;
        }
        ret = consumer.commitTx();
        HBT_THROW_SYSTEM_CODE_IF(0 > ret, toErrorCode(-ret));
      }
    }
  }

  virtual ~TraceMonitor() = default;

 protected:
  std::unique_ptr<CuMonData> releasePerIntervalSlicesOnly_(
      CpuId cpu_id,
      const std::string& key,
      TimeStamp stop_ts);

  std::unique_ptr<CuMonData> releaseCountData_(
      TraceCollector::CountGenCtxt& ctxt,
      uint64_t* slices_offset,
      CpuId cpu_id,
      TimeStamp stop_ts);
};

} // namespace facebook::hbt::mon
