// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/mon/Monitor.h"
#include <gtest/gtest.h>
#include "hbt/src/perf_event/BuiltinMetrics.h"

#include <chrono>
#include <filesystem>
#include <fstream>

using namespace facebook::hbt;
using namespace facebook::hbt::mon;
using namespace facebook::hbt::perf_event;

#ifdef HBT_ENABLE_TRACING
using namespace facebook::hbt::phase;
using namespace facebook::hbt::tagstack;
#endif // HBT_ENABLE_TRACING

#ifdef HBT_ENABLE_TRACING
void runSlices(std::vector<CpuId> cpus) {
  EXPECT_GE(cpus.size(), 1);

  auto cpu_set = CpuSet::makeFromCont(cpus);

  using TPerCpuRingBuffer = typename PerCpuPhaseLogger::TPerCpuRingBuffer;
  // Large enough to hold all data produced between ts_start and ts_deadline.
  auto phase_logger_rb =
      std::make_shared<TPerCpuRingBuffer>(1024 * 1024, cpu_set);
  // Metadata buffer large enough to hold all productions.
  auto md_logger_rb = std::make_shared<TPerCpuRingBuffer>(1024, cpu_set);

  Monitor mon;

  Monitor<>::ElemId kTraceMonElemId = "tc_mon";

  auto& tc = *mon.emplaceTraceMonitor(std::nullopt, kTraceMonElemId, cpu_set);
  tc.emplaceTagStackGeneratorFromRbs(
      phase_logger_rb,
      md_logger_rb,
      1024 * 1024 *
          64, // sizeof(tagstack::Slice) * 64 MB of space to store slices.
      std::nullopt, // use TraceCollector::kDefaultThreadGenParams' values for
                    // `perf_event_per_cpu_num_pages` and
                    // `thread_switch_aux_rb_min_num_events`
      0); // do not discard oldest slices if full.

  // Register an output to allow querying the slices later.
  const std::string kSlicesKey = "output_slices_key";
  tc.emplaceSlicesOutput(kSlicesKey);

  // Used to move CPUs. Note that the idx is used modulo the number of monitored
  // CPUs we will deterministically chose an (often) different CPU.
  auto changeCpuAffinity = [&](unsigned idx) -> CpuId {
    cpu_set_t new_cpu_set;
    CPU_ZERO(&new_cpu_set);
    CpuId cpu = cpus[idx % cpus.size()];
    CPU_SET(cpu, &new_cpu_set);
    int ret = sched_setaffinity(0, sizeof(new_cpu_set), &new_cpu_set);
    if (0 > ret) {
      HBT_THROW_SYSTEM(errno) << "Error setting CPU " << cpu << " affinity.";
    }
    // Yield to guarantee that the thread switches CPUs.
    std::this_thread::yield();
    return cpu;
  };

  CpuId cpu0 = changeCpuAffinity(0);
  std::cout << "CPU affinity changed to cpu: " << cpu0;

  // Will log Phase at level 2 (index 1).
  auto phase_logger =
      std::make_shared<PerCpuPhaseLogger>(tagstack::Level{1}, phase_logger_rb);

  mon.open();

  TimeStamp ts_start = tc.now();

  mon.enable();

  sleep(1);

  // Start logging, these 2 events will go to <cpu0>.
  phase_logger->logPhaseStart(10);
  phase_logger->logPhaseEnd();

  // Move to <cpu1> and log.
  CpuId cpu1 = changeCpuAffinity(1);
  std::cout << "CPU affinity changed to cpu: " << cpu1;
  phase_logger->logPhaseStart(12);
  phase_logger->logPhaseEnd();

  // Move to <cpu2> and log.
  CpuId cpu2 = changeCpuAffinity(2);
  std::cout << "CPU affinity changed to cpu: " << cpu2;
  phase_logger->logPhaseStart(11);
  phase_logger->logPhaseEnd();
  phase_logger->logPhaseStart(14);
  phase_logger->logPhaseEnd();

  // Move to <cpu3> and log.
  CpuId cpu3 = changeCpuAffinity(3);
  std::cout << "CPU affinity changed to cpu: " << cpu3;
  phase_logger->logPhaseStart(11);

  // XXX: Check that each phase is reported in the right CPU.

  // Phase 11 stays as active in thread.

  sleep(1);

  phase_logger->logPhaseEnd();
  TimeStamp ts_deadline = tc.now();
  TimeStamp ts_after_deadline = tc.now();
  HBT_LOG_INFO() << "Deadline: " << tc.now();

  // Process available events to free up buffers.
  tc.processNext(1000, ts_deadline, std::nullopt);

  sleep(1); // Give time to all threads to context switch and generate events
            // pass the deadline.

  HBT_LOG_INFO() << "After sleeps the tstamp is: " << tc.now();

  // Process up to deadline, this will contain all events with phases.
  tc.processNext(1000, ts_deadline, std::nullopt);

  const unsigned min_number_slices =
      20; // arbitrarily chosen number of slices happened in the time that we've
          // waited.

  unsigned found_slices = 0;

  auto mon_data = mon.releaseMonData(
      kTraceMonElemId, kSlicesKey, ts_deadline, "test", "test_long");
  for (const auto& [cpu_id, cu_md] : mon_data->per_cu_mon_data) {
    auto n = cu_md->countSlices();
    EXPECT_TRUE(n.has_value());
    found_slices += *n;
    // XXX: Add some correctness check to slices.
  }

  EXPECT_GT(found_slices, min_number_slices);

  // {tag : number of times seen}
  std::map<Tag, unsigned> seen_l1_tags;

  auto d = tc.getTagStackStatsDump();
  for (const auto& [key, ss] : *d) {
    const auto& stack = ss.stack;
    HBT_LOG_INFO() << " stack: " << stack;
    if (stack.tags.size() > 1) {
      seen_l1_tags[stack.tags.at(1)]++;
    }
  }

  // Make sure that phases were captured in the stack.
  // If there was a context switch while a phase was active, then
  // the phase id will appear in one extra slice.
  EXPECT_GE(seen_l1_tags[10], 1);
  EXPECT_GE(seen_l1_tags[12], 1);
  EXPECT_GE(seen_l1_tags[11], 1);
  EXPECT_GE(seen_l1_tags[14], 1);

  // Just dump all slices.
  for (const auto& [cpu_id, cu_md] : mon_data->per_cu_mon_data) {
    std::cout << "CPU: " << cpu_id << std::endl;
    std::cout << *cu_md->per_interval_slices;
  }

  mon.disable();

  // Total duration of slices in [ts_start, ts_deadline].
  TimeStamp total_duration = 0;
  TimeStamp last_ts = 0;
  // Get slices in first interval. It's the only one because there are no
  // counts.
  const auto& all_slices =
      mon_data->per_cu_mon_data.at(8)->per_interval_slices->at(0);
  for (const auto& slice : all_slices) {
    EXPECT_GT(slice.tstamp, last_ts);
    last_ts = slice.tstamp;
    EXPECT_GT(slice.tstamp, ts_start);
    EXPECT_LE(slice.tstamp, ts_deadline);
    total_duration += slice.duration;
  }
  EXPECT_LE(total_duration, ts_deadline - ts_start);

  // Process after deadline.
  tc.processNext(1000, ts_after_deadline, std::nullopt);

  tc.processNext(1000, tc.now(), std::nullopt);

  //
  // Add a count generator.
  //
  const std::string cg_key = "cg_key";
  auto pmu_manager = makePmuDeviceManager();
  auto metrics = makeAvailableMetrics();

  auto ipc_desc = metrics->getMetricDesc("ipc");

  tc.emplaceCountGenerator(
      cg_key, ipc_desc, pmu_manager, nullptr, 4, std::nullopt, 1000, 10);

  tc.processNext(1000, tc.now(), std::nullopt);

  // Functor that loads events.
  size_t total = 0;
  auto func = [&](CpuId cpu,
                  int count_idx,
                  const std::vector<std::string>& eventNicknames,
                  TimeStamp tstamp,
                  TimeStamp duration,
                  uint64_t const* count_ptr,
                  const auto kNumEvents) {
    for (int eventIndex = 0; eventIndex < kNumEvents; eventIndex++) {
      uint64_t eventValue = *(count_ptr + eventIndex);
      total += eventValue;
    }
  };

  std::cout << tc.statusStr(cpu_set);
  tc.applyToCountSamplesAndConsume(cg_key, func);

  mon.close();
}

TEST(PerCpuSlicer, OneCPU) {
  // Only care about the following CPUs. XXX: This is flaky because system
  // may not have those CPU ids enabled/online.
  runSlices({8});
};

TEST(PerCpuSlicer, TwoCpus) {
  // Only care about the following CPUs. XXX: This is flaky because system
  // may not have those CPU ids enabled/online.
  runSlices({0, 8});
};

TEST(PerCpuSlicer, TwoCpusNoZeroCpu) {
  // Only care about the following CPUs. XXX: This is flaky because system
  // may not have those CPU ids enabled/online.
  runSlices({10, 8});
};
#endif // HBT_ENABLE_TRACING

TEST(IntelPTMonitor, SystemWideTraceCollection) {
  auto cpus = CpuSet::makeAllOnline();

  auto pmu_manager = makePmuDeviceManager();
  ASSERT_NE(pmu_manager, nullptr);

  Monitor mon;
  Monitor<>::ElemId kIptMonElemId = "ipt_mon";

  size_t trace_buffer_size_pages = 8;
  perf_event::EventExtraAttr extra_attr =
      perf_event::EventExtraAttr::makeUserOnly();
  auto ctxt = IntelPTGenCtxt::create(
      *pmu_manager, cpus, std::nullopt, trace_buffer_size_pages, extra_attr);

  ASSERT_NE(ctxt, std::nullopt);

  mon.emplaceIptMonitor(std::nullopt, kIptMonElemId, std::move(*ctxt));
  auto& ipt_mon = *mon.getIptMonitor(kIptMonElemId);

  mon.open();

  auto trace_data = ipt_mon.collectTraceData();
  // The monitor is open but is yet to be enabled, so there's no data to be
  // collected.
  EXPECT_EQ(trace_data, std::nullopt);

  const size_t EXPECTED_BUFFER_SIZE_BYTES =
      trace_buffer_size_pages * static_cast<size_t>(getpagesize());

  auto do_collection = [&]() {
    mon.enable();
    trace_data = ipt_mon.collectTraceData();
    // Cannot collect data from OVERWRITE AUX buffer while the monitor is
    // enabled.
    EXPECT_EQ(trace_data, std::nullopt);

    sleep(1);

    mon.disable();
    trace_data = ipt_mon.collectTraceData();
    // The monitor is disabled but was previously enabled, so there is data to
    // be collected.
    EXPECT_NE(trace_data, std::nullopt);

    // Check that we have trace data for each CPU.
    for_each_cpu(cpu, ipt_mon.getMonCpus()) {
      auto it = trace_data->find(cpu);
      EXPECT_NE(it, trace_data->end());
      EXPECT_EQ(it->second.data.size(), EXPECTED_BUFFER_SIZE_BYTES);
    }
  };

  // Collect twice to ensure successive collections work as expected
  do_collection();
  do_collection();

  mon.close();
  trace_data = ipt_mon.collectTraceData();
  // The monitor is closed so there's no data to be collected.
  EXPECT_EQ(trace_data, std::nullopt);
}

// This test focuses on testing the onCpusTraceBufferRead() function,
// specifically, it validates that the (pointer,size) combos passed to the
// OnRbRead are correct.
TEST(IntelPTMonitor, SystemWideTraceCopy) {
  auto cpus = CpuSet::makeAllOnline();

  auto pmu_manager = makePmuDeviceManager();
  ASSERT_NE(pmu_manager, nullptr);

  Monitor mon;
  Monitor<>::ElemId kIptMonElemId = "ipt_mon";

  size_t trace_buffer_size_pages = 1;
  perf_event::EventExtraAttr extra_attr =
      perf_event::EventExtraAttr::makeUserOnly();
  auto ctxt = IntelPTGenCtxt::create(
      *pmu_manager, cpus, std::nullopt, trace_buffer_size_pages, extra_attr);

  ASSERT_NE(ctxt, std::nullopt);

  mon.emplaceIptMonitor(std::nullopt, kIptMonElemId, std::move(*ctxt));
  auto& ipt_mon = *mon.getIptMonitor(kIptMonElemId);

  mon.open();
  mon.enable();
  sleep(1);
  mon.disable();

  auto trace_data_opt = ipt_mon.collectTraceData();
  ASSERT_NE(trace_data_opt, std::nullopt);
  auto& trace_data = *trace_data_opt;

  // Ensure the (ptr,size) combos passed into the lambda are correct by
  // comparing the buffers with the bytes from collectTraceData.
  auto callback = [&trace_data](
                      CpuId cpuId, const perf_event::RbDataSlices& rb) {
    ASSERT_NE(rb.first.from, nullptr);
    auto it = trace_data.find(cpuId);
    ASSERT_NE(it, trace_data.end());

    auto& cpuTraceBuffer = it->second.data;

    const uint8_t* byte_ptr1 = static_cast<const uint8_t*>(rb.first.from);

    std::vector<uint8_t> sink;
    sink.insert(sink.end(), byte_ptr1, byte_ptr1 + rb.first.size);

    if (rb.second.has_value()) {
      const uint8_t* byte_ptr2 = static_cast<const uint8_t*>(rb.second->from);
      sink.insert(sink.end(), byte_ptr2, byte_ptr2 + rb.second->size);
    }
    ASSERT_EQ(sink, cpuTraceBuffer);
  };

  ipt_mon.onCpusTraceBufferRead(callback);
  mon.close();
}

#ifdef HBT_ENABLE_TRACING
TEST(ContextSwitch, CopyToSink) {
  Monitor mon;

  Monitor<>::ElemId kTraceMonElemId = "context_switch_mon";

  auto cpu_set = CpuSet::makeAllOnline();

  auto& tc = *mon.emplaceTraceMonitor(std::nullopt, kTraceMonElemId, cpu_set);

  tc.emplaceThreadGenerator();

  std::set<CpuId> seenCpus;
  auto callback = [&seenCpus](CpuId cpuId, const perf_event::RbDataSlices& rb) {
    ASSERT_NE(rb.first.from, nullptr);
    seenCpus.insert(cpuId);
  };

  mon.open();
  mon.enable();
  sleep(1);
  mon.disable();

  tc.onCpusDataBufferRead(callback, false /*consume*/);

  // Ensure that the copy lambda was called for each CPU.
  ASSERT_EQ(seenCpus, cpu_set.asSet());
}
#endif // HBT_ENABLE_TRACING
