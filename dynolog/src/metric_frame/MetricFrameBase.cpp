/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/metric_frame/MetricFrameBase.h"

namespace facebook::dynolog {

MetricFrameBase::MetricFrameBase(
    std::string name,
    std::string description,
    std::shared_ptr<MetricFrameTsUnitInterface> ts)
    : name_{std::move(name)},
      description_{std::move(description)},
      ts_{std::move(ts)} {}

const std::string& MetricFrameBase::name() const {
  return name_;
}

const std::string& MetricFrameBase::description() const {
  return description_;
}

size_t MetricFrameBase::length() const {
  return ts_->length();
}

size_t MetricFrameBase::maxLength() const {
  return ts_->maxLength();
}

std::optional<TimePoint> MetricFrameBase::firstSampleTime() const {
  return ts_->firstSampleTime();
}

std::optional<TimePoint> MetricFrameBase::lastSampleTime() const {
  return ts_->lastSampleTime();
}

std::optional<MetricFrameSlice> MetricFrameBase::slice(
    TimePoint startTime,
    TimePoint endTime,
    MATCH_POLICY startTimePolicy,
    MATCH_POLICY endTimePolicy) const {
  auto rangeMaybe =
      ts_->getRange(startTime, endTime, startTimePolicy, endTimePolicy);
  if (!rangeMaybe.has_value()) {
    return std::nullopt;
  }
  return MetricFrameSlice(*this, rangeMaybe.value());
}

std::optional<MetricFrameSlice> MetricFrameBase::latest() const {
  auto rangeMaybe = ts_->getLatest();
  if (!rangeMaybe.has_value()) {
    return std::nullopt;
  }
  return MetricFrameSlice(*this, ts_->getLatest().value());
}

template <bool flag = false>
void unknown_type_assert() {
  static_assert(flag, "type provided to add samples is not supported");
}

void MetricFrameBase::addSample(
    const SampleVarT& sampleVar,
    MetricSeriesVar& seriesVar) {
  std::visit(
      [&sampleVar](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<MetricSeriesInt64Ptr, T>) {
          arg->addSample(std::get<int64_t>(sampleVar));
        } else if constexpr (std::is_same_v<MetricSeriesUint64Ptr, T>) {
          arg->addSample(std::get<uint64_t>(sampleVar));
        } else if constexpr (std::is_same_v<T, MetricSeriesDoublePtr>) {
          arg->addSample(std::get<double>(sampleVar));
        } else if constexpr (std::is_same_v<T, MetricSeriesPerfReadValuePtr>) {
          arg->addSample(std::get<PerfReadValues>(sampleVar));
        } else {
          unknown_type_assert();
        }
      },
      seriesVar);
}

void MetricFrameBase::incFromLastSample(
    const SampleVarT& deltaVar,
    MetricSeriesVar& seriesVar) {
  std::visit(
      [&deltaVar](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<MetricSeriesInt64Ptr, T>) {
          arg->incFromLastSample(std::get<int64_t>(deltaVar));
        } else if constexpr (std::is_same_v<MetricSeriesUint64Ptr, T>) {
          arg->incFromLastSample(std::get<uint64_t>(deltaVar));
        } else if constexpr (std::is_same_v<T, MetricSeriesDoublePtr>) {
          arg->incFromLastSample(std::get<double>(deltaVar));
        } else if constexpr (std::is_same_v<T, MetricSeriesPerfReadValuePtr>) {
          arg->incFromLastSample(std::get<PerfReadValues>(deltaVar));
        } else {
          unknown_type_assert();
        }
      },
      seriesVar);
}

std::ostream& operator<<(std::ostream& s, const MetricFrameBase& frame) {
  frame.show(s);
  return s;
}

MetricFrameSlice::MetricFrameSlice(
    const MetricFrameBase& frame,
    MetricFrameRange range)
    : frame_{frame}, range_{range} {}

// validation rule constructor and methods
ValidationRule::ValidationRule(Type type, double targetValue)
    : type_(type), targetValue_(targetValue) {}

ValidationRule ValidationRule::greaterEqualThan(double minValue) {
  return ValidationRule(Type::GREATER_EQUAL_THAN, minValue);
}

ValidationRule ValidationRule::lessEqualThan(double maxValue) {
  return ValidationRule(Type::LESS_EQUAL_THAN, maxValue);
}

ValidationRule ValidationRule::greaterThan(double targetValue) {
  return ValidationRule(Type::GREATER_THAN, targetValue);
}

ValidationRule ValidationRule::lessThan(double targetValue) {
  return ValidationRule(Type::LESS_THAN, targetValue);
}

bool ValidationRule::validate(double value, ValidationRule validationRule)
    const {
  auto& type = this->type_;
  auto& targetValue = this->targetValue_;
  switch (type) {
    case Type::GREATER_EQUAL_THAN:
      return value >= targetValue;

    case Type::LESS_EQUAL_THAN:
      return value <= targetValue;

    case Type::LESS_THAN:
      return value < targetValue;

    case Type::GREATER_THAN:
      return value > targetValue;

    default:
      return false;
  }
}

// MetricInfo constructor and methods
MetricInfo::MetricInfo(
    MFBMetricName metricName,
    std::vector<MFBGranularity> granularities,
    std::vector<MFBAggregation> aggregations,
    MFBAggregation defaultAggregation,
    MFBHandlerFunc handler,
    std::vector<ValidationRule> validationRules,
    std::map<Category, std::vector<std::string>> inclusion,
    std::map<Category, std::vector<std::string>> exclusion,
    Criticality criticality)
    : metricName_(metricName),
      granularities_(std::move(granularities)),
      aggregations_(std::move(aggregations)),
      defaultAggregation_(defaultAggregation),
      handler_(std::move(handler)),
      validationRules_(std::move(validationRules)),
      inclusion_(std::move(inclusion)),
      exclusion_(std::move(exclusion)),
      criticality_(criticality) {}

const MFBMetricName& MetricInfo::metricName() const {
  return metricName_;
}

const std::vector<MFBGranularity>& MetricInfo::granularities() const {
  return granularities_;
}

const std::vector<MFBAggregation>& MetricInfo::aggregations() const {
  return aggregations_;
}

const MFBAggregation& MetricInfo::defaultAggregation() const {
  return defaultAggregation_;
}

MFBHandlerFunc MetricInfo::handler() const {
  return handler_;
}

const std::vector<ValidationRule>& MetricInfo::validationRules() const {
  return validationRules_;
}

const std::map<Category, std::vector<std::string>>& MetricInfo::inclusion()
    const {
  return inclusion_;
}

const std::map<Category, std::vector<std::string>>& MetricInfo::exclusion()
    const {
  return exclusion_;
}

Criticality MetricInfo::criticality() const {
  return criticality_;
}

// MetricInfoMap constructor and methods
MetricInfoMap::MetricInfoMap(std::map<MFBMetricName, MetricInfo> metricInfoMap)
    : metricInfoMap_(std::move(metricInfoMap)) {}

std::optional<MetricInfo> MetricInfoMap::getMetricInfo(
    MFBMetricName metricName) const {
  auto it = metricInfoMap_.find(metricName);
  if (it != metricInfoMap_.end()) {
    return it->second;
  }
  return std::nullopt;
}

bool MetricInfoMap::contains(MFBMetricName metricName) const {
  return metricInfoMap_.find(metricName) != metricInfoMap_.end();
}

const std::map<MFBMetricName, MetricInfo>& MetricInfoMap::getMetricInfoMap()
    const {
  return metricInfoMap_;
}

void MetricInfoMap::add(
    MFBMetricName metricName,
    const MetricInfo& metricInfo) {
  metricInfoMap_.insert_or_assign(metricName, std::move(metricInfo));
}

} // namespace facebook::dynolog
