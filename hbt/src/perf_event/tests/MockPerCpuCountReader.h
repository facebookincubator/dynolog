// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <gmock/gmock.h>

#include <utility>
#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/PerCpuCountReader.h"

namespace facebook::hbt::perf_event {

class MockPerCpuCountReader : public PerCpuCountReader {
 public:
  MockPerCpuCountReader(
      const CpuSet& mon_cpus,
      std::shared_ptr<const MetricDesc> metric_desc,
      std::shared_ptr<const PmuDeviceManager> pmu_manager,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper)
      : PerCpuCountReader(
            CpuSet::makeAllOnline(),
            std::move(metric_desc),
            std::move(pmu_manager),
            std::move(cgroup_fd_wrapper)) {}
  ~MockPerCpuCountReader() override = default;
  MOCK_METHOD(void, open, (bool), (override));
  MOCK_METHOD(void, openForCpu, (CpuId, bool), (override));
  MOCK_METHOD(bool, isOpen, (), (const, override));
  MOCK_METHOD(void, enable, (bool), (override));
  MOCK_METHOD(void, enableForCpu, (CpuId, bool), (override));
  MOCK_METHOD(bool, isEnabled, (), (const, override));
  MOCK_METHOD(bool, isEnabledOnCpu, (CpuId), (const, override));
  MOCK_METHOD(void, close, (), (override));
  MOCK_METHOD(void, closeForCpu, (CpuId), (override));
  MOCK_METHOD(void, disable, (), (override));
  MOCK_METHOD(void, disableForCpu, (CpuId), (override));
  MOCK_METHOD(std::optional<ReadValues>, read, (), (const, override));
  MOCK_METHOD(
      (std::optional<std::map<int, ReadValues>>),
      readPerCpu,
      (),
      (const, override));
};

class MockPerCpuCountReaderFactory : public PerCpuCountReaderFactory {
 public:
  MockPerCpuCountReaderFactory() = default;
  ~MockPerCpuCountReaderFactory() override = default;
  std::unique_ptr<PerCpuCountReader> make(
      const std::string& element_id,
      const CpuSet& mon_cpus,
      std::shared_ptr<const MetricDesc> metric_desc,
      std::shared_ptr<const PmuDeviceManager> pmu_manager,
      std::shared_ptr<FdWrapper> cgroup_fd_wrapper) override {
    auto mockReader = std::make_unique<MockPerCpuCountReader>(
        mon_cpus, metric_desc, pmu_manager, cgroup_fd_wrapper);
    mockReaders_[element_id] = mockReader.get();
    if (expectations_.find(element_id) != expectations_.end()) {
      expectations_[element_id](mockReader.get());
    }
    return std::move(mockReader);
  }

  void setExpectation(
      const std::string& element_id,
      std::function<void(MockPerCpuCountReader*)> expects) {
    expectations_[element_id] = std::move(expects);
  }

 private:
  std::unordered_map<std::string, MockPerCpuCountReader*> mockReaders_;
  std::unordered_map<std::string, std::function<void(MockPerCpuCountReader*)>>
      expectations_;
};

} // namespace facebook::hbt::perf_event
