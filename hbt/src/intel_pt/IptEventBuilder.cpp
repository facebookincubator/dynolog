// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/intel_pt/IptEventBuilder.h"
#include "hbt/src/perf_event/PmuEvent.h"

#include <hbt/src/perf_event/PmuDevices.h>
#include <cstdint>
#include <limits>
#include <string>

namespace facebook::hbt::intel_pt {

using namespace ::facebook::hbt::perf_event;

void verifyFormatExistsThrowOnError(
    std::optional<perf_event::PmuDevice::FormatAttr> formatMaybe,
    const std::string& key,
    const std::string& err) {
  HBT_THROW_ASSERT_IF(!formatMaybe.has_value())
      << "Intel PT format " << key << " not found. " << err;
}

std::unique_ptr<IptEventBuilder> IptEventBuilder::createIptEventBuilder(
    const perf_event::PmuDeviceManager& pmuDeviceManager) {
  const auto& pmus = pmuDeviceManager.getPmuGroups();
  auto iptPmusIt = pmus.find(PmuType::intel_pt);
  if (iptPmusIt == pmus.end()) {
    HBT_LOG_WARNING()
        << "Intel PT is not available on this machine. Is the machine running with"
        << " a Intel Broadwell or later CPU?";
    return nullptr;
  }
  if (iptPmusIt->second.size() != 1) {
    HBT_LOG_WARNING()
        << "Number of pmus with type intel_pt != 1. Assume Intel PT is not available"
        << ": size == " << iptPmusIt->second.size();
    return nullptr;
  }

  auto iptPmuDevPtr = iptPmusIt->second.begin()->second;
  return std::unique_ptr<IptEventBuilder>(new IptEventBuilder(
      iptPmuDevPtr->getPmuId(), iptPmuDevPtr->format, iptPmuDevPtr->caps));
}

bool IptEventBuilder::hasIptCaps(
    const perf_event::PmuDeviceManager& pmuDeviceManager) {
  const auto& pmus = pmuDeviceManager.getPmuGroups();
  auto iptPmusIt = pmus.find(PmuType::intel_pt);
  if (iptPmusIt == pmus.end() || iptPmusIt->second.size() != 1) {
    return false;
  }
  return true;
}

uint64_t IptEventBuilder::getPerfConfig() const {
  return config_;
}

std::unique_ptr<EventDef> IptEventBuilder::createHbtEventDef(
    const EventId& eventId,
    const std::string& brief_desc,
    const std::string& full_desc) const {
  EventDef::Encoding encoding = {.code = config_};
  return std::make_unique<EventDef>(
      PmuType::intel_pt, eventId, encoding, brief_desc, full_desc);
}

std::unique_ptr<EventConf> IptEventBuilder::createHbtEventConf(
    const perf_event::EventId& eventId,
    std::optional<perf_event::EventExtraAttr> extraAttr) const {
  EventConf res{
      .id = eventId,
      .configs = EventConfigs{.type = perfType_, .config = config_},
      .extra_attr = extraAttr.value_or(EventExtraAttr{})};
  return std::make_unique<EventConf>(res);
}

// This function can most likely be deleted in the future as setting the pt bit
// to 0 causes an error when opening the event. See:
// https://www.internalfb.com/code/kernel-linux/[v5.6-fb%3A7c5f87571159]/arch/x86/events/intel/pt.c?lines=285-292
IptEventBuilder& IptEventBuilder::setPt(bool enable) {
  auto formatAttrMaybe = getFormatAttr("pt");
  verifyFormatExistsThrowOnError(
      formatAttrMaybe,
      "pt",
      "setPt() has no effect."
      " Is this machine a physical machine running with Intel Broadwell or later CPUs?");
  const auto& format = formatAttrMaybe.value();
  try {
    setConfigBits(format, static_cast<uint8_t>(enable));
  } catch (const std::invalid_argument& e) {
    HBT_LOG_WARNING() << e.what() << " setPt() has no effect.";
  }
  return *this;
}

IptEventBuilder& IptEventBuilder::setBranch(bool enable) {
  auto formatAttrMaybe = getFormatAttr("branch");
  verifyFormatExistsThrowOnError(
      formatAttrMaybe, "branch", "setBranch() has no effect.");
  const auto& format = formatAttrMaybe.value();
  try {
    setConfigBits(format, static_cast<uint8_t>(enable));
  } catch (const std::invalid_argument& e) {
    HBT_LOG_WARNING() << e.what() << " setBranch() has no effect.";
  }
  return *this;
}

IptEventBuilder& IptEventBuilder::setCyc(bool enable, uint8_t threshold) {
  if (!hasCycSupport(threshold)) {
    HBT_LOG_WARNING() << "CPU doesn't support cyc mode with threshold "
                      << threshold << ". setCyc() has no effect.";
    return *this;
  }
  auto cycAttrMaybe = getFormatAttr("cyc");
  auto cycThreshAttrMaybe = getFormatAttr("cyc_thresh");
  verifyFormatExistsThrowOnError(
      cycAttrMaybe, "cyc", "setCyc() has no effect.");
  verifyFormatExistsThrowOnError(
      cycThreshAttrMaybe, "cyc_thresh", "setCyc() has no effect.");
  const auto& cycFormat = cycAttrMaybe.value();
  const auto& cycThreshFormat = cycThreshAttrMaybe.value();
  try {
    setConfigBits(cycFormat, static_cast<uint8_t>(enable));
    setConfigBits(cycThreshFormat, threshold);
  } catch (const std::invalid_argument& e) {
    HBT_LOG_WARNING() << e.what() << " setCyc() has no effect.";
  }
  return *this;
}

bool IptEventBuilder::hasCycSupport(uint8_t threshold) const {
  if (threshold > 15) {
    HBT_LOG_WARNING() << "threshold should be within 0-15";
  }
  // threshold == 0 is supported by all CPU generations that support intel pt.
  if (threshold == 0) {
    return true;
  }
  auto cycThresholdCapMaybe = getCap<uint16_t>("cycle_thresholds");
  if (!cycThresholdCapMaybe.has_value()) {
    return false;
  }
  auto cycThresholdCap = cycThresholdCapMaybe.value();
  return ((1UL << threshold) & cycThresholdCap);
}

IptEventBuilder& IptEventBuilder::setMtc(bool enable, uint8_t period) {
  if (!hasMtcSupport(period)) {
    HBT_LOG_WARNING() << "CPU doesn't support mtc mode with period " << period
                      << ". setMtc() has no effect.";
    return *this;
  }
  auto mtcAttrMaybe = getFormatAttr("mtc");
  auto mtcPeriodAttrMaybe = getFormatAttr("mtc_period");
  verifyFormatExistsThrowOnError(
      mtcAttrMaybe, "mtc", "setMtc() has no effect.");
  verifyFormatExistsThrowOnError(
      mtcPeriodAttrMaybe, "mtc_period", "setMtc() has no effect.");
  const auto& mtcFormat = mtcAttrMaybe.value();
  const auto& mtcPeriodFormat = mtcPeriodAttrMaybe.value();
  try {
    setConfigBits(mtcFormat, static_cast<uint8_t>(enable));
    setConfigBits(mtcPeriodFormat, period);
  } catch (const std::invalid_argument& e) {
    HBT_LOG_WARNING() << e.what() << " setMtc() has no effect.";
  }
  return *this;
}

bool IptEventBuilder::hasMtcSupport(uint8_t period) const {
  if (period > 15) {
    HBT_LOG_WARNING() << "period should be within 0-15";
    return false;
  }
  auto mtcCap = getCap<bool>("mtc").value_or(false);
  auto mtcPeriodCapMaybe = getCap<uint16_t>("mtc_periods");
  if (!mtcPeriodCapMaybe.has_value()) {
    return false;
  }
  auto mtcPeriodCap = mtcPeriodCapMaybe.value();
  return (mtcCap && ((1UL << period) & mtcPeriodCap));
}

IptEventBuilder& IptEventBuilder::setPtw(bool enable, bool fupOnPtw) {
  if (!hasPtwSupport()) {
    HBT_LOG_WARNING() << "CPU doesn't support ptwrite. setPtw() has no effect.";
    return *this;
  }
  auto ptwAttrMaybe = getFormatAttr("ptw");
  auto fupOnPtwAttrMaybe = getFormatAttr("fup_on_ptw");
  verifyFormatExistsThrowOnError(
      ptwAttrMaybe, "ptw", "setPtw() has no effect.");
  verifyFormatExistsThrowOnError(
      fupOnPtwAttrMaybe, "fup_on_ptw", "setPtw() has no effect.");
  const auto& ptwFormat = ptwAttrMaybe.value();
  const auto& fupOnPtwFormat = fupOnPtwAttrMaybe.value();
  try {
    setConfigBits(ptwFormat, static_cast<uint8_t>(enable));
    setConfigBits(fupOnPtwFormat, fupOnPtw);
  } catch (const std::invalid_argument& e) {
    HBT_LOG_WARNING() << e.what() << " setPtw() has no effect.";
  }
  return *this;
}

bool IptEventBuilder::hasPtwSupport() const {
  return getCap<bool>("ptwrite").value_or(false);
}

IptEventBuilder& IptEventBuilder::setRetComp(bool enable) {
  auto noRetCompAttrMaybe = getFormatAttr("noretcomp");
  verifyFormatExistsThrowOnError(
      noRetCompAttrMaybe, "noretcomp", "setRetComp() has no effect.");
  const auto& noRetCompFormat = noRetCompAttrMaybe.value();
  try {
    setConfigBits(noRetCompFormat, static_cast<uint8_t>(!enable));
  } catch (const std::invalid_argument& e) {
    HBT_LOG_WARNING() << e.what() << " setRetComp() has no effect.";
  }
  return *this;
}

IptEventBuilder& IptEventBuilder::setPsbPeriod(uint8_t period) {
  if (!hasPsbPeriodSupport(period)) {
    HBT_LOG_WARNING()
        << "CPU doesn't support psb period. setPsbPeriod() has no effect.";
    return *this;
  }
  auto psbPeriodAttrMaybe = getFormatAttr("psb_periods");
  verifyFormatExistsThrowOnError(
      psbPeriodAttrMaybe, "psb_periods", "setPsbPeriod() has no effect.");
  const auto& psbPeriodFormat = psbPeriodAttrMaybe.value();
  try {
    setConfigBits(psbPeriodFormat, period);
  } catch (const std::invalid_argument& e) {
    HBT_LOG_WARNING() << e.what() << " setPsbPeriod() has no effect.";
  }
  return *this;
}

bool IptEventBuilder::hasPsbPeriodSupport(uint8_t period) const {
  if (period > 15) {
    HBT_LOG_WARNING() << "period should be within 0-15";
    return false;
  }
  auto psbPeriodCapMaybe = getCap<uint16_t>("psb_periods");
  if (!psbPeriodCapMaybe.has_value()) {
    return false;
  }
  auto psbPeriodCap = psbPeriodCapMaybe.value();
  return ((1UL << period) & psbPeriodCap);
}

IptEventBuilder& IptEventBuilder::setPwrEvt(bool enable) {
  if (!hasPwrEvtSupport()) {
    HBT_LOG_WARNING()
        << "CPU doesn't support power events. setPwrEvt() has no effect.";
    return *this;
  }
  auto pwrEvtAttrMaybe = getFormatAttr("pwr_evt");
  verifyFormatExistsThrowOnError(
      pwrEvtAttrMaybe, "pwr_evt", "setPwrEvt() has no effect.");
  const auto& pwrEvtFormat = pwrEvtAttrMaybe.value();
  try {
    setConfigBits(pwrEvtFormat, static_cast<uint8_t>(enable));
  } catch (const std::invalid_argument& e) {
    HBT_LOG_WARNING() << e.what() << " setPwrEvt() has no effect.";
  }
  return *this;
}

bool IptEventBuilder::hasPwrEvtSupport() const {
  return getCap<bool>("power_event_trace").value_or(false);
}

IptEventBuilder& IptEventBuilder::setTsc(bool enable) {
  auto tscAttrMaybe = getFormatAttr("tsc");
  verifyFormatExistsThrowOnError(
      tscAttrMaybe, "tsc", "setTsc() has no effect.");
  const auto& tscFormat = tscAttrMaybe.value();
  try {
    setConfigBits(tscFormat, static_cast<uint8_t>(enable));
  } catch (const std::invalid_argument& e) {
    HBT_LOG_WARNING() << e.what() << " setTsc() has no effect.";
  }
  return *this;
}

IptEventBuilder::IptEventBuilder(
    uint32_t perfType,
    const PmuDevice::SysFsDeviceFormat& format,
    const PmuDevice::SysFsDeviceCaps& caps)
    : format_{format}, caps_{caps}, perfType_{perfType} {
  setPt(true);
}

std::optional<PmuDevice::FormatAttr> IptEventBuilder::getFormatAttr(
    const std::string& key) const {
  PmuDevice::SysFsDeviceFormat::const_iterator it = format_.find(key);
  if (it != format_.end()) {
    return it->second;
  }
  return std::nullopt;
}

void IptEventBuilder::setConfigBits(
    const PmuDevice::FormatAttr& format,
    uint8_t val) {
  for (int i = format.msb; i < format.msb + format.len; i++) {
    setConfigBit(val & 1UL, i);
    val >>= 1;
  }
}

void IptEventBuilder::setConfigBit(bool val, size_t pos) {
  HBT_DCHECK_LE(val, 1) << "val should be either 0 or 1";
  config_ = (config_ & ~(1UL << pos)) | (val << pos);
}

} // namespace facebook::hbt::intel_pt
