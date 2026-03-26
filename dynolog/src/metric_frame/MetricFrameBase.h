/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <chrono>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <variant>
#include <vector>

#include "dynolog/src/metric_frame/ExtraTypes.h"
#include "dynolog/src/metric_frame/MetricFrameTsUnitInterface.h"
#include "dynolog/src/metric_frame/MetricSeries.h"
#include "dynolog/src/metric_frame/TextTable.h"

namespace facebook::dynolog {

using SampleVarT = std::variant<int64_t, uint64_t, double, PerfReadValues>;
using MetricSeriesInt64Ptr = std::shared_ptr<MetricSeries<int64_t>>;
using MetricSeriesUint64Ptr = std::shared_ptr<MetricSeries<uint64_t>>;
using MetricSeriesDoublePtr = std::shared_ptr<MetricSeries<double>>;
using MetricSeriesPerfReadValuePtr =
    std::shared_ptr<MetricSeries<PerfReadValues>>;
using MetricSeriesVar = std::variant<
    MetricSeriesInt64Ptr,
    MetricSeriesUint64Ptr,
    MetricSeriesDoublePtr,
    MetricSeriesPerfReadValuePtr>;

class MetricFrameSlice;

class MetricFrameBase {
 public:
  MetricFrameBase(
      std::string name,
      std::string description,
      std::shared_ptr<MetricFrameTsUnitInterface> ts);
  virtual ~MetricFrameBase() = default;
  const std::string& name() const;
  const std::string& description() const;
  size_t length() const;
  size_t maxLength() const;
  std::optional<TimePoint> firstSampleTime() const;
  std::optional<TimePoint> lastSampleTime() const;
  std::optional<MetricFrameSlice> slice(
      TimePoint startTime,
      TimePoint endTime,
      MATCH_POLICY startTimePolicy = MATCH_POLICY::CLOSEST,
      MATCH_POLICY endTimePolicy = MATCH_POLICY::CLOSEST) const;
  // this returns a slice only containing the latest sample regardless of time
  std::optional<MetricFrameSlice> latest() const;
  std::optional<MetricFrameSlice> latest(size_t n) const;
  virtual size_t width() const = 0;
  virtual std::optional<MetricSeriesVar> series(
      const std::string& name) const = 0;
  virtual std::optional<MetricSeriesVar> series(int name) const = 0;
  virtual std::vector<MetricSeriesVar> allSeriesVec() const = 0;
  virtual void show(std::ostream& s) const = 0;

 protected:
  void addSample(const SampleVarT& sampleVar, MetricSeriesVar& seriesVar);
  void incFromLastSample(
      const SampleVarT& deltaVar,
      MetricSeriesVar& seriesVar);
  template <typename It>
  static void show(
      It begin,
      It end,
      const MetricFrameTsUnitInterface& ts,
      std::ostream& s) {
    std::vector<std::vector<std::string>> textTable;
    auto tsVector = ts.getTimeVector();
    textTable.emplace_back(ts.length() + 1);
    for (size_t i = 0; i < tsVector.size(); i++) {
      textTable.back()[i + 1] = std::to_string(
          std::chrono::duration_cast<std::chrono::milliseconds>(
              tsVector[i].time_since_epoch())
              .count());
    }
    for (auto it = begin; it != end; it++) {
      textTable.emplace_back();
      const MetricSeriesVar& metricSeriesVar = *it;
      std::visit(
          [&textTable](auto&& metricSeriesPtr) {
            textTable.back().push_back(metricSeriesPtr->name());
            for (auto sample : *metricSeriesPtr) {
              textTable.back().push_back(std::to_string(sample));
            }
          },
          metricSeriesVar);
    }
    TextTable table(std::move(textTable));
    table.show(s);
  }
  std::string name_;
  std::string description_;
  std::shared_ptr<MetricFrameTsUnitInterface> ts_;
};

template <typename T>
class MetricSeriesSlice {
 public:
  const std::string& name() const {
    return series_.name();
  }
  const std::string& description() const {
    return series_.description();
  }
  size_t size() const {
    return series_.size();
  }

  template <typename R>
  R rate(std::chrono::steady_clock::duration period) const {
    return series_.template rate<R>(
        period,
        range_.end.time - range_.start.time,
        series_.begin() + range_.start.offset,
        series_.begin() + range_.end.offset + 1);
  }
  template <typename R>
  R avg() const {
    return series_.template avg<R>(
        series_.begin() + range_.start.offset,
        series_.begin() + range_.end.offset + 1);
  }
  T percentile(float percentage) const {
    return series_.percentile(
        percentage,
        series_.begin() + range_.start.offset,
        series_.begin() + range_.end.offset + 1);
  }
  T diff() const {
    return series_.diff(
        series_.begin() + range_.start.offset,
        series_.begin() + range_.end.offset + 1);
  }
  std::vector<T> raw() const {
    return series_.raw(
        series_.begin() + range_.start.offset,
        series_.begin() + range_.end.offset + 1);
  }

 protected:
  MetricSeriesSlice(
      const MetricSeries<T>& series,
      const MetricFrameRange& range)
      : series_{series}, range_{range} {}
  const MetricSeries<T>& series_;
  MetricFrameRange range_;

  friend class MetricFrameSlice;
};

class MetricFrameSlice {
 public:
  template <typename T>
  std::optional<MetricSeriesSlice<T>> series(const std::string& name) const {
    auto seriesVar = frame_.series(name);
    if (!seriesVar.has_value()) {
      return std::nullopt;
    }
    return getSeriesFromVar<T>(seriesVar.value(), range_);
  }
  template <typename T>
  std::optional<MetricSeriesSlice<T>> series(int name) const {
    auto seriesVar = frame_.series(name);
    if (!seriesVar.has_value()) {
      return std::nullopt;
    }
    return getSeriesFromVar<T>(seriesVar.value(), range_);
  }
  template <typename T>
  std::vector<MetricSeriesSlice<T>> allSeriesVec() const {
    std::vector<MetricSeriesSlice<T>> res;
    auto allSeriesVec = frame_.allSeriesVec();
    for (const auto& series : allSeriesVec) {
      auto seriesSliceMaybe = getSeriesFromVar<T>(series, range_);
      if (seriesSliceMaybe.has_value()) {
        res.push_back(seriesSliceMaybe.value());
      }
    }
    return res;
  }

  size_t length() const {
    return range_.end.offset - range_.start.offset + 1;
  }

  TimeDuration duration() const {
    return range_.end.time - range_.start.time;
  }

 protected:
  MetricFrameSlice(const MetricFrameBase& frame, MetricFrameRange range);
  const MetricFrameBase& frame_;
  MetricFrameRange range_;

 private:
  template <typename T>
  static std::optional<MetricSeriesSlice<T>> getSeriesFromVar(
      const MetricSeriesVar& seriesVar,
      const MetricFrameRange& range) {
    auto seriesPtrMaybe =
        std::get_if<std::shared_ptr<MetricSeries<T>>>(&seriesVar);
    if (!seriesPtrMaybe) {
      return std::nullopt;
    }
    return MetricSeriesSlice<T>(**seriesPtrMaybe, range);
  }

  friend class MetricFrameBase;
};

std::ostream& operator<<(std::ostream& s, const MetricFrameBase& frame);

// validation rule types
enum class Type {
  GREATER_EQUAL_THAN, // value >= target_value
  LESS_EQUAL_THAN, // value <= target_value
  LESS_THAN, // value < target_value
  GREATER_THAN, // value > target_value
};

class ValidationRule {
 public:
  // Validation rule types
  explicit ValidationRule(Type type, double targetValue);

  // generate a validation rule with min/max range
  static ValidationRule greaterEqualThan(double minValue);
  static ValidationRule lessEqualThan(double maxValue);
  static ValidationRule greaterThan(double targetValue);
  static ValidationRule lessThan(double targetValue);

  // Validate a value against its validation rule
  bool validate(double value, ValidationRule validationRule) const;

 private:
  Type type_;
  double targetValue_;
};

// Metric info enum types
enum class MFBMetricName {
  CPU_UTIL,
  CPU_CORES_USAGE,
  CPU_CORES_LIMIT,
  CPU_CYCLES_USAGE,
  CPU_INSTRUCTIONS_USAGE,
  CPU_BUSY_MS,
  USER_CPU_CORES,
  SYS_CPU_CORES,
  MEM_FOOTPRINT,
  MEM_ANON_FOOTPRINT,
  MEM_FILE_FOOTPRINT,
  CPU_SATURATION
};

enum class MFBScope {
  HOST,
  TW_TASK,
  ALLOTMENT,
};

enum class MFBGranularity {
  ALL,
  HUNDRED_MS,
  SECOND,
  MINUTE,
  FIVE_SECONDS,
  FIFTEEN_SECONDS,
};

enum class MFBAggregation {
  NONE,
  AVG,
  MIN,
  MAX,
  P90,
  P95,
  P99,
};

enum class MFBIdentifier {
  HOST_NAME,
  TW_TASK_HANDLE,
};

struct MFBDynoLogSchematizedResponseRow {
  std::string metric_name;
  MFBGranularity granularity;
  double metric_value;
  MFBScope scope;
  MFBAggregation aggregation;
  std::string identifier;
  int64_t interval;
};

struct MFBDynoLogSchematizedResponse {
  std::vector<MFBDynoLogSchematizedResponseRow> responseRow;
  std::vector<std::string> error_messages;
};

// Criticality levels for metrics
enum class Criticality {
  LOW,
  HIGH,
};

// Include/exclude category for metrics
enum class Category {
  LST,
  LSST,
  CPU_ARCH,
  CPU_MODEL,
  KERNEL_VERSION,
};

// Templated handler function - ResponseType is specified when creating
// handlers
template <typename ResponseType>
using HandlerFunc = std::function<void(
    ResponseType&,
    MFBIdentifier&,
    MFBGranularity,
    MFBAggregation,
    uint64_t)>;

using MFBHandlerFunc = HandlerFunc<MFBDynoLogSchematizedResponse>;

class MetricInfo {
 public:
  MetricInfo(
      MFBMetricName metricName,
      std::vector<MFBGranularity> granularities,
      std::vector<MFBAggregation> aggregations,
      MFBAggregation defaultAggregation,
      MFBHandlerFunc handler,
      std::vector<ValidationRule> validationRules,
      std::map<Category, std::vector<std::string>> inclusion,
      std::map<Category, std::vector<std::string>> exclusion,
      Criticality criticality);

  ~MetricInfo() = default;
  MetricInfo(const MetricInfo&) = default;
  MetricInfo& operator=(const MetricInfo&) = default;
  MetricInfo(MetricInfo&&) = default;
  MetricInfo& operator=(MetricInfo&&) = default;

  const MFBMetricName& metricName() const;
  const std::vector<MFBGranularity>& granularities() const;
  const std::vector<MFBAggregation>& aggregations() const;
  const MFBAggregation& defaultAggregation() const;
  MFBHandlerFunc handler() const;
  const std::vector<ValidationRule>& validationRules() const;
  const std::map<Category, std::vector<std::string>>& inclusion() const;
  const std::map<Category, std::vector<std::string>>& exclusion() const;
  Criticality criticality() const;

 private:
  MFBMetricName metricName_;
  std::vector<MFBGranularity> granularities_;
  std::vector<MFBAggregation> aggregations_;
  MFBAggregation defaultAggregation_;
  MFBHandlerFunc handler_;
  std::vector<ValidationRule> validationRules_;
  std::map<Category, std::vector<std::string>> inclusion_;
  std::map<Category, std::vector<std::string>> exclusion_;
  Criticality criticality_;
};

class MetricInfoMap {
 public:
  explicit MetricInfoMap(std::map<MFBMetricName, MetricInfo> metricInfoMap);

  // Get the entire map
  const std::map<MFBMetricName, MetricInfo>& getMetricInfoMap() const;

  // Get MetricInfo for a specific metric name
  std::optional<MetricInfo> getMetricInfo(MFBMetricName metricName) const;

  // Check if a metric is registered
  bool contains(MFBMetricName metricName) const;

  // Add or update a MetricInfo
  void add(MFBMetricName metricName, const MetricInfo& metricInfo);

 private:
  std::map<MFBMetricName, MetricInfo> metricInfoMap_;
};

} // namespace facebook::dynolog
