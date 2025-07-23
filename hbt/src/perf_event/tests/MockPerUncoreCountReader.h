// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <gmock/gmock.h>

#include <utility>
#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/PerUncoreCountReader.h"

namespace facebook::hbt::perf_event {

class MockPerUncoreCountReader : public PerUncoreCountReader {
 public:
  MockPerUncoreCountReader(
      uncore_scope::Scope scope,
      std::shared_ptr<const MetricDesc> metric_desc_in,
      std::shared_ptr<const PmuDeviceManager> pmu_manager_in)
      : PerUncoreCountReader(scope, metric_desc_in, pmu_manager_in) {}
  ~MockPerUncoreCountReader() override = default;
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
      (std::vector<ReadValues>),
      readPerPerfEventsGroup,
      (),
      (const, override));
  MOCK_METHOD(
      (std::map<int, ReadValues>),
      readPerPerfEventsGroupOnCpu,
      (CpuId),
      (const, override));
};

class MockPerUncoreCountReaderFactory : public PerUncoreCountReaderFactory {
 public:
  MockPerUncoreCountReaderFactory() = default;
  ~MockPerUncoreCountReaderFactory() override = default;
  std::unique_ptr<PerUncoreCountReader> make(
      const std::string& element_id,
      uncore_scope::Scope scope,
      std::shared_ptr<const MetricDesc> metric_desc,
      std::shared_ptr<const PmuDeviceManager> pmu_manager) override {
    auto mockReader = std::make_unique<MockPerUncoreCountReader>(
        scope, metric_desc, pmu_manager);
    mockReaders_[element_id] = mockReader.get();
    if (expectations_.find(element_id) != expectations_.end()) {
      expectations_[element_id](mockReader.get());
    }
    return std::move(mockReader);
  }

  void setExpectation(
      const std::string& element_id,
      std::function<void(MockPerUncoreCountReader*)> expects) {
    expectations_[element_id] = std::move(expects);
  }

 private:
  std::unordered_map<std::string, MockPerUncoreCountReader*> mockReaders_;
  std::
      unordered_map<std::string, std::function<void(MockPerUncoreCountReader*)>>
          expectations_;
};

} // namespace facebook::hbt::perf_event
