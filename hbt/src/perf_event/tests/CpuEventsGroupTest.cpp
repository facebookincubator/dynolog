// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/CpuEventsGroup.h"

#include <gtest/gtest.h>
#include <filesystem>

using namespace facebook::hbt;
using namespace facebook::hbt::perf_event;

namespace fs = std::filesystem;

const static std::string kConsumeErrorString =
    "Expected to either get all samples"
    " or fail with error indicating not enough samples";

// Construct EventConfs dynamically from sysfs.
// Return empty vector if machine doesn't support required feature.
EventConfs constructIntelPTEventConfs() {
  EventConfs event_confs;
  // test if Intel PT is supported
  const fs::path p = "/sys/devices/intel_pt";
  if (!fs::is_directory(p)) {
    HBT_LOG_INFO() << "Machine doesn't support Intel PT.";
    return event_confs;
  }
  // get pmu id dynamically
  auto is = std::ifstream("/sys/devices/intel_pt/type");
  int64_t type = -1;
  is >> type;
  // get event dynamically
  std::string line;
  int pt_event = -1;
  int branch_event = -1;
  is = std::ifstream("/sys/devices/intel_pt/format/pt");
  is >> line;
  pt_event = std::stoi(line.substr(7));
  is = std::ifstream("/sys/devices/intel_pt/format/branch");
  is >> line;
  branch_event = std::stoi(line.substr(7));
  if (type < 0 || pt_event < 0 || branch_event < 0) {
    HBT_LOG_INFO() << "Machine doesn't support pt/branch event.";
    return event_confs;
  }
  event_confs.push_back(EventConf{
      .id = "test_intel_pt",
      .configs = EventConfigs{
          .type = (uint32_t)type,
          .config = (1u << pt_event) | (1u << branch_event),
      }});
  return event_confs;
}

// Create a CRTP implementation for test purposes.
class SamplingEvents : public CpuEventsGroup<SamplingEvents, mode::Sampling> {
 public:
  using TBase = CpuEventsGroup<SamplingEvents, mode::Sampling>;
  using TMode = TBase::TMode;

  SamplingEvents(CpuId cpu, const EventConfs& confs)
      : TBase(cpu, -1, -1, confs) {}

  int handleRecordLost(const typename TMode::Lost& /* r */) {
    return 0;
  }

  int handleRecordRead(const typename TMode::Read& r) {
    HBT_LOG_INFO() << r << std::endl;
    return 0;
  }

  int handleRecordSample(const typename TMode::Sample& r) {
    HBT_LOG_INFO() << r << std::endl;
    return 0;
  }

  void enableImpl() {}

  void disableImpl() {}

  template <class... Args>
  void open(Args&&... args) {
    this->open_(std::forward<Args>(args)...);
  }
};

// Create a CRTP implementation for test purposes.
class ContextSwitchEvents
    : public CpuEventsGroup<ContextSwitchEvents, mode::ContextSwitch> {
 public:
  using TBase = CpuEventsGroup<ContextSwitchEvents, mode::ContextSwitch>;
  using TMode = TBase::TMode;

  ContextSwitchEvents(CpuId cpu, const EventConfs& confs)
      : TBase(cpu, -1, -1, confs) {}

  int handleRecordLost(const typename TMode::Lost& /* r */) {
    return 0;
  }

  int handleRecordComm(
      const typename TMode::Comm_Lower& /* r_lower */,
      size_t /* name_len */,
      const TMode::sample_id_t* /* sample_id_ptr */) {
    return 0;
  }

  int handleRecordExit(const typename TMode::Exit& /* r */) {
    return 0;
  }

  int handleRecordFork(const typename TMode::Fork& /* r */) {
    return 0;
  }

  int handleRecordSwitchCpuWide(const typename TMode::SwitchCpuWide& r) {
    HBT_LOG_INFO() << r << std::endl;
    return 0;
  }

  void enableImpl() {}

  void disableImpl() {}

  template <class... Args>
  void open(Args&&... args) {
    this->open_(std::forward<Args>(args)...);
  }
};

class IntelPTEvents : public CpuEventsGroup<IntelPTEvents, mode::AUXSpace> {
 public:
  using TBase = CpuEventsGroup<IntelPTEvents, mode::AUXSpace>;
  using TMode = TBase::TMode;

  IntelPTEvents(CpuId cpu, pid_t pid, const EventConfs& confs)
      : TBase{cpu, pid, -1, confs} {}

  int handleRecordAux(const typename TMode::Aux& /* r */) {
    return 0;
  }

  int handleRecordItraceStart(const typename TMode::ItraceStart& /* r */) {
    return 0;
  }

  void enableImpl() {}

  void disableImpl() {}

  template <class... Args>
  void open(Args&&... args) {
    this->open_(std::forward<Args>(args)...);
  }
};

TEST(ContextSwitchEvents, JustHwLeader_DropMany) {
  EventConfs event_confs = {EventConf{
      .id = "test_clock",
      .configs = EventConfigs{
          .type = PERF_TYPE_HARDWARE, .config = PERF_COUNT_HW_CPU_CYCLES}}};

  // CPU 4
  SamplingEvents eg{4, event_confs};

  // One page only, open with a very tiny period to generate many lost records.
  eg.open(1u, 1024u * 128u * 1u, true, 0u);
  eg.enable();
  for (int i = 0; i < 4; ++i) {
    // Wait for one second to collect some records.
    // This is a smoke test, so no flakiness risk due to sleep.
    sleep(1);

    auto ret = eg.consume(1000);
    EXPECT_TRUE(ret >= 0 || ret == -ENODATA);
    HBT_LOG_INFO() << "Processed records: " << ret << std::endl;
  }
  eg.close();
  HBT_LOG_INFO() << "Total number of PERF_RECORD_LOST: "
                 << eg.getNumRecordLost() << std::endl;
  HBT_LOG_INFO() << "Total number of PERF_RECORD_SAMPLE: "
                 << eg.getNumRecordSample() << std::endl;
  EXPECT_GT(eg.getNumRecordLost(), 100);
  EXPECT_LE(eg.getNumRecordSample(), 4000)
      << "Only asked to consume 4000 events";
}

TEST(ContextSwitchEvents, JustHwLeader_NoDrops) {
  EventConfs event_confs = {EventConf{
      .id = "test_hw_instructions",
      .configs = EventConfigs{
          .type = PERF_TYPE_HARDWARE, .config = PERF_COUNT_HW_INSTRUCTIONS}}};

  // CPU 10
  SamplingEvents eg{10, event_confs};

  // Many pages, do not expect dropped records.
  eg.open(256u, 1024u * 1024u * 10u, true, 0u);
  eg.enable();
  for (int i = 0; i < 4; ++i) {
    auto ret = eg.consume(10000);
    EXPECT_TRUE(ret >= 0 || ret == -ENODATA);
    HBT_LOG_INFO() << "Processed records: " << ret << std::endl;
    // Wait for one second to collect some records.
    // This is a smoke test, so no flakiness risk due to sleep.
    sleep(1);
  }
  // Keep open until end.
  HBT_LOG_INFO() << "Total number of PERF_RECORD_LOST: "
                 << eg.getNumRecordLost() << std::endl;
  HBT_LOG_INFO() << "Total number of PERF_RECORD_SAMPLE: "
                 << eg.getNumRecordSample() << std::endl;

  EXPECT_EQ(eg.getNumRecordLost(), 0);
  EXPECT_LE(eg.getNumRecordSample(), 40000)
      << "Only asked to consume 40000 events";
  eg.close();
}

TEST(ContextSwitchEvents, SmokeTest_EachContextSwitch) {
  EventConfs event_confs = {EventConf{
      .id = "my_test_sw_event",
      .configs = EventConfigs{
          .type = PERF_TYPE_SOFTWARE,
          // Generates a record on switch out.
          .config = PERF_COUNT_SW_CONTEXT_SWITCHES}}};

  // CPU 10
  SamplingEvents eg{10, event_confs};

  // 16 pages. Each context switch.
  eg.open(16u, 1u, true, 0u);
  eg.enable();
  for (int i = 0; i < 10; ++i) {
    auto ret = eg.consume(1000);
    EXPECT_TRUE(ret >= 0 || ret == -ENODATA) << kConsumeErrorString;
    HBT_LOG_INFO() << "Processed records: " << ret << std::endl;
    // Wait for one second to collect some records.
    // This is a smoke test, so no flakiness risk due to sleep.
    sleep(1);
  }
  eg.close();
  HBT_LOG_INFO() << "Total number of PERF_RECORD_LOST: "
                 << eg.getNumRecordLost() << std::endl;
  HBT_LOG_INFO() << "Total number of PERF_RECORD_SAMPLE: "
                 << eg.getNumRecordSample() << std::endl;
}

TEST(ContextSwitchEvents, SmokeTest_TwoEventsGroup) {
  EventConfs event_confs = {
      EventConf{
          .id = "test_hw_cache_misses",
          .configs =
              EventConfigs{
                  .type = PERF_TYPE_HARDWARE,
                  .config = PERF_COUNT_HW_CACHE_MISSES},
      },
      EventConf{
          .id = "test_hw_instructions",
          .configs = EventConfigs{
              .type = PERF_TYPE_HARDWARE,
              .config = PERF_COUNT_HW_INSTRUCTIONS}}};

  // CPU 1
  SamplingEvents eg{1, event_confs};

  // 4 pages.
  eg.open(8u, 1024u, true, 0u);
  eg.enable();
  for (int i = 0; i < 10; ++i) {
    auto ret = eg.consume(1000);
    EXPECT_TRUE(ret >= 0 || ret == -ENODATA)
        << "Expected to either get 1000 samples or fail "
        << "with error reporting that there are not 1000 samples";
    HBT_LOG_INFO() << "Processed records: " << ret << std::endl;
    // Wait for one second to collect some records.
    // This is a smoke test, so no flakiness risk due to sleep.
    sleep(1);
  }
  eg.close();
  HBT_LOG_INFO() << "Total number of PERF_RECORD_LOST: "
                 << eg.getNumRecordLost() << std::endl;
  HBT_LOG_INFO() << "Total number of PERF_RECORD_SAMPLE: "
                 << eg.getNumRecordSample() << std::endl;
}

TEST(ContextSwitchEvents, SmokeTest_DummyContextSwitch) {
  EventConfs event_confs = {EventConf{
      .id = "my_test_sw_dummy_event",
      .configs = EventConfigs{
          .type = PERF_TYPE_SOFTWARE, .config = PERF_COUNT_SW_DUMMY}}};

  // CPU 10
  ContextSwitchEvents eg{10, event_confs};

  // 16 pages. Each context switch.
  eg.open(16u, 0u, true, 0u);
  eg.enable();
  for (int i = 0; i < 10; ++i) {
    auto ret = eg.consume(1000);
    EXPECT_TRUE(ret >= 0 || ret == -ENODATA) << kConsumeErrorString;
    HBT_LOG_INFO() << "Processed records: " << ret << std::endl;
    // Wait for one second to collect some records.
    // This is a smoke test, so no flakiness risk due to sleep.
    sleep(1);
  }
  eg.close();
  HBT_LOG_INFO() << "Total number of PERF_RECORD_LOST: "
                 << eg.getNumRecordLost() << std::endl;
  HBT_LOG_INFO() << "Total number of PERF_RECORD_SAMPLE: "
                 << eg.getNumRecordSample() << std::endl;
}

TEST(IntelPTEvents, SmokeTest_IntelPT) {
  auto event_confs = constructIntelPTEventConfs();
  if (event_confs.empty()) {
    HBT_LOG_WARNING() << "Skip SmokeTest_IntelPT";
    return;
  }
  IntelPTEvents eg{2, -1, event_confs};
  // 16KB main buffer, 64KB AUX buffer
  eg.open(4u, 1u, false, 16u);
  eg.enable();
  // wait for PERF_RECORD_ITRACE_START
  eg.consume(1);
  EXPECT_EQ(eg.getNumRecordItraceStart(), 1);
  eg.disable();
  // consume remaining records
  // should contain at lest one PERF_RECORD_AUX
  while (eg.usedSizeWeak() > 0) {
    eg.consume(1);
  }
  eg.close();
}

TEST(ContextSwitchEvents, SmokeTest_IntelPTSpecificProcess) {
  /*
   * XXX: Temporarily comment because this test requires
   * IntelPT availablity that is not always available in SandCastle.
  // Fork a new process for testing
  auto pid = fork();
  ASSERT_NE(pid, -1);
  // child process for testing
  if (pid == 0) {
    // spin forever
    while (true);
  }
  // set child process CPU affinity to CPU 3
  cpu_set_t set;
  CPU_ZERO(&set);
  CPU_SET(3, &set);
  ASSERT_EQ(sched_setaffinity(pid, sizeof(set), &set), 0);
  // parent process running test case
  EventConfs event_confs = constructIntelPTEventConfs();
  if (event_confs.empty()) {
    HBT_LOG_WARNING() << "Skip SmokeTest_IntelPTSpecificProcess";
    return;
  }

  // CPU 3
  IntelPTEvents eg{3, pid, event_confs};
  // 16KB main buffer, 64KB AUX buffer
  eg.open(4u, 1u, false, 16u);
  eg.enable();
  // wait for PERF_RECORD_ITRACE_START
  eg.consume(1);
  EXPECT_EQ(eg.getNumRecordItraceStart(), 1);
  eg.disable();
  // consume remaining records
  // should contain at lest one PERF_RECORD_AUX
  while (eg.usedSizeWeak() > 0) {
    eg.consume(1);
  }
  eg.close();

  // terminate child process
  ASSERT_EQ(kill(pid, SIGKILL), 0);
  */
}
