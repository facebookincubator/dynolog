// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <limits>
#include <memory>
#include <optional>
#include <type_traits>

#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/PmuDevices.h"
#include "hbt/src/perf_event/PmuEvent.h"

namespace facebook::hbt::intel_pt {

void verifyFormatExistsThrowOnError(
    std::optional<perf_event::PmuDevice::FormatAttr> formatMaybe,
    const std::string& key,
    const std::string& errorMsg);

// IptEventBuilder is a helper class that provides a more readable and
// user-friendly interface for checking intel pt capability on the localhost and
// building config consumed by perf(2) or heartbeat.
class IptEventBuilder {
 public:
  static std::unique_ptr<IptEventBuilder> createIptEventBuilder(
      const perf_event::PmuDeviceManager& pmuDeviceManager);

  // Helper function to check if the machine has IntelPT capabilities.
  //
  // createIptEventBuilder() internally does this check but we provide this
  // separate "lightweight" check for callers who are only interested in if the
  // host has the caps, but don't need to create a new instance of this class.
  static bool hasIptCaps(const perf_event::PmuDeviceManager& pmuDeviceManager);

  uint64_t getPerfConfig() const;

  std::unique_ptr<perf_event::EventDef> createHbtEventDef(
      const perf_event::EventId& eventId,
      const std::string& brief_desc,
      const std::string& full_desc) const;

  std::unique_ptr<perf_event::EventConf> createHbtEventConf(
      const perf_event::EventId& eventId,
      std::optional<perf_event::EventExtraAttr> extraAttr = std::nullopt) const;

  // Master swich for enable/disable Intel PT. If set to true, a series of
  // packets may be generated.
  IptEventBuilder& setPt(bool enable);

  // Enable tracing change of flow instruction such as conditional branch,
  // indirect transfer or far transfer.
  IptEventBuilder& setBranch(bool enable);

  // Enable cycle-accurate mode. Intel PT can be run in a cycle-accurate mode
  // which enables CYC packets that provide low-level information in the
  // processor core clock domain.
  //
  // @param threshold: an 0-15 integer. threshold defines CYC packet will not be
  // generated within
  //      threshold cycles. CYC packets will be sent with the first
  //      eligible packet after 2^(threshold - 1) cycles have passed since the
  //      last CYC packet except if threshold == 0, then 0 cycle.
  IptEventBuilder& setCyc(bool enable, uint8_t threshold);
  bool hasCycSupport(uint8_t threshold) const;

  // Enable generating MTC packets. An MTC packet provides a periodic indication
  // of wall-clock time.
  //
  // @param period: an 0-15 integer. period defines MTC packet Frequency, which
  // is based on the core
  //      crystal clock, or Always Running Timer (ART). A MTC packet will be
  //      sent every 2^period ART cycles.
  IptEventBuilder& setMtc(bool enable, uint8_t period);
  bool hasMtcSupport(uint8_t period) const;

  // Enable generating PTW packets. PTW packet will be generated when PTWRITE
  // CPU instrcution is executed.
  //
  // @param fupOnPtw: whether enable generating a FUP packets after a PTW
  // packet. FUP packets provide the
  //      IP to which they bind. They are never standalone, but are coupled with
  //      other packets.
  IptEventBuilder& setPtw(bool enable, bool fupOnPtw);
  bool hasPtwSupport() const;

  // Enable RET compression. A special case is applied if the target of the RET
  // is consistent with what would be expected from tracking the CALL stack. If
  // it is assured that the decoder has seen the corresponding CALL (with
  // “corresponding” defined as the CALL with matching stack depth), and the RET
  // target is the instruction after that CALL, the RET target may be
  // “compressed”. In this case, only a single TNT bit of “taken” is generated
  // instead of a Target IP Packet.
  IptEventBuilder& setRetComp(bool enable);

  // Set PSB packets generation period. PSB is a unique pattern in the packet
  // output log, and hence serves as a sync point for the decoder. PSB packet
  // period is based on the number of Intel PT packet bytes output, so this
  // field allows the user to determine the increment of IPT output bytes that
  // should cause a PSB to be generated.
  //
  // @param period: an 0-15 interger. An PSB packet will be generated every 2K *
  // 2^period bytes roughly.
  IptEventBuilder& setPsbPeriod(uint8_t period);
  bool hasPsbPeriodSupport(uint8_t period) const;

  // Enable tracing power events. Power event trace is a capability that exposes
  // core- and thread-level sleep state and power down transition information.
  IptEventBuilder& setPwrEvt(bool enable);
  bool hasPwrEvtSupport() const;

  // Eanble generating TSC packet. A TSC packet provides the lower 7 bytes of
  // the current TSC value, as returned by the RDTSC instruction. This may be
  // useful for tracking wall-clock time, and synchronizing the packets in the
  // log with other timestamped logs.
  IptEventBuilder& setTsc(bool enable);

 private:
  // Construct helper function from sysfs entrie in
  // /sys/devices/<pmu_name>/format and /sys/devices/<pmu_name>/caps
  // respectively.
  IptEventBuilder(
      uint32_t perfType,
      const perf_event::PmuDevice::SysFsDeviceFormat& format,
      const perf_event::PmuDevice::SysFsDeviceCaps& caps);

  // Check if format exists identified by key.
  std::optional<perf_event::PmuDevice::FormatAttr> getFormatAttr(
      const std::string& key) const;
  template <class T>
  std::optional<T> getCap(const std::string& key) const {
    perf_event::PmuDevice::SysFsDeviceCaps::const_iterator it = caps_.find(key);
    if (it == caps_.end()) {
      HBT_LOG_WARNING() << "Cannot find cap entry " << key << " in sysfs";
      return std::nullopt;
    }
    uint64_t val = 0;
    try {
      val = std::stoull(it->second, nullptr, 16);
    } catch (const std::exception& e) {
      HBT_LOG_WARNING() << "Cannot convert string " << it->second
                        << " to unsigned integer for caps key " << key << ". "
                        << e.what();
      return std::nullopt;
    }
    if constexpr (std::is_same_v<T, bool>) {
      return val > 0 ? true : false;
    } else {
      return val > std::numeric_limits<T>::max() ? std::nullopt
                                                 : std::optional<uint16_t>(val);
    }
  }
  // Set corresponding bits defined in FormatAttr to the val provided.
  // throw invalid_argument if set bits in FormatAttr is not conseutive
  // or val is out of range.
  void setConfigBits(
      const perf_event::PmuDevice::FormatAttr& format,
      uint8_t val);
  void setConfigBit(bool val, size_t pos);

  perf_event::PmuDevice::SysFsDeviceFormat format_;
  perf_event::PmuDevice::SysFsDeviceCaps caps_;
  uint64_t config_ = 0;
  uint32_t perfType_ = 0;
};

} // namespace facebook::hbt::intel_pt
