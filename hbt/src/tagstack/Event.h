// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"
#include "hbt/src/tagstack/TagStack.h"

#include <cstring>
#include <iostream>
#include <limits>

namespace facebook::hbt::tagstack {

// Identifier for compute unit (CPU, GPU, etc).
using CompUnitId = uint16_t;

// CompUnitId must have enough precision to contain all possible
// IDs in all supported Compute Units spaces (e.g. CPUs, GPUs, AI Accelerators).
static_assert(std::numeric_limits<CompUnitId>::max() >= kMaxCpus);

/// Event are changes in a TagStack or are control events.
///
/// Events are part of a stream where Slicer will push or pop tags
/// depending in the event.
struct Event {
  enum class Type : uint8_t {
    // Phase events.
    Start = 0,
    End,

    // Thread lifetime.
    ThreadCreation,
    ThreadDestruction,

    // Switch events.
    SwitchIn,
    SwitchOutPreempt,
    SwitchOutYield,

    // Control events.
    WriteErrorsStart,
    WriteErrorsEnd,
  };

  TimeStamp tstamp;
  Type type;
  Level level;

  // The compute unit this events belong to.
  CompUnitId comp_unit_id;

  Tag tag;

  inline TimeStamp getTimeStamp() const noexcept {
    return tstamp;
  }

  inline bool isValid() const noexcept {
    return tstamp != kInvalidTimeStamp;
  }

  //
  // Factory methods.
  //
  inline static Event makeStart(
      TimeStamp tstamp,
      Level level,
      Tag tag,
      CompUnitId comp_unit_id) DEXCEPT {
    HBT_DCHECK_NE(tag, kNA);
    return Event{
        .tstamp = tstamp,
        .type = Type::Start,
        .level = level,
        .comp_unit_id = comp_unit_id,
        .tag = tag};
  }

  inline static Event
  makeEnd(TimeStamp tstamp, Level level, CompUnitId comp_unit_id) DEXCEPT {
    return Event{
        .tstamp = tstamp,
        .type = Type::End,
        .level = level,
        .comp_unit_id = comp_unit_id,
        .tag = kNA};
  }

  inline static Event makeThreadCreation(
      TimeStamp tstamp,
      Level level,
      Tag tag,
      CompUnitId comp_unit_id) DEXCEPT {
    HBT_DCHECK_NE(tag, kNA);
    return Event{
        .tstamp = tstamp,
        .type = Type::ThreadCreation,
        .level = level,
        .comp_unit_id = comp_unit_id,
        .tag = tag};
  }

  inline static Event makeThreadDestruction(
      TimeStamp tstamp,
      Level level,
      Tag tag,
      CompUnitId comp_unit_id) DEXCEPT {
    HBT_DCHECK_NE(tag, kNA);
    return Event{
        .tstamp = tstamp,
        .type = Type::ThreadDestruction,
        .level = level,
        .comp_unit_id = comp_unit_id,
        .tag = tag};
  }

  inline static Event makeSwitchIn(
      TimeStamp tstamp,
      Level level,
      Tag tag,
      CompUnitId comp_unit_id) DEXCEPT {
    HBT_DCHECK_NE(tag, kNA);
    return Event{
        .tstamp = tstamp,
        .type = Type::SwitchIn,
        .level = level,
        .comp_unit_id = comp_unit_id,
        .tag = tag};
  }

  inline static Event makeSwitchOutPreempt(
      TimeStamp tstamp,
      Level level,
      CompUnitId comp_unit_id) noexcept {
    return Event{
        .tstamp = tstamp,
        .type = Type::SwitchOutPreempt,
        .level = level,
        .comp_unit_id = comp_unit_id,
        .tag = kNA};
  }

  inline static Event makeSwitchOutYield(
      TimeStamp tstamp,
      Level level,
      CompUnitId comp_unit_id) noexcept {
    return Event{
        .tstamp = tstamp,
        .type = Type::SwitchOutYield,
        .level = level,
        .comp_unit_id = comp_unit_id,
        .tag = kNA};
  }

  inline static Event makeWriteErrorsStart(
      TimeStamp tstamp,
      CompUnitId comp_unit_id) noexcept {
    return Event{
        .tstamp = tstamp,
        .type = Type::WriteErrorsStart,
        .level = kInvalidLevel,
        .comp_unit_id = comp_unit_id,
        .tag = kNA};
  }

  inline static Event makeWriteErrorsEnd(
      TimeStamp tstamp,
      CompUnitId comp_unit_id) noexcept {
    return Event{
        .tstamp = tstamp,
        .type = Type::WriteErrorsEnd,
        .level = kInvalidLevel,
        .comp_unit_id = comp_unit_id,
        .tag = kNA};
  }

  //
  // Accesors.
  //

  bool isThreadLifetime() const noexcept {
    return type == Type::ThreadCreation || type == Type::ThreadDestruction;
  }

  bool isSwitchOut() const noexcept {
    return type == Type::SwitchOutPreempt || type == Type::SwitchOutYield;
  }

  bool isSwitch() const noexcept {
    return type == Type::SwitchIn || isSwitchOut();
  }

  bool isPhase() const noexcept {
    return type == Type::Start || type == Type::End;
  }

  bool isOut() const noexcept {
    return isSwitchOut() || type == Type::End;
  }

  bool isIn() const noexcept {
    return type == Type::SwitchIn || type == Type::Start;
  }

  //
  // Comparators.
  //
  bool operator==(const Event& other) const noexcept {
    return tstamp == other.tstamp && type == other.type &&
        level == other.level && tag == other.tag;
  }

  // Required for Stream interface.
  bool happenedBefore(const Event& other) const noexcept {
    if (this->tstamp > other.tstamp) {
      return false;
    }
    return this->tstamp < other.tstamp ||
        this->comp_unit_id < other.comp_unit_id;
  }
};

// Expect packing to total 16 bytes.
static_assert(sizeof(Event) == 8 + 1 + 1 + 2 + 4);

static_assert(
    std::is_trivially_copyable<Event>::value,
    "Code assumes that Event is trivially copiable.");

inline std::ostream& operator<<(std::ostream& os, const Event::Type& type) {
  switch (type) {
    case Event::Type::Start:
      os << " Start";
      break;
    case Event::Type::End:
      os << " End";
      break;
    case Event::Type::ThreadCreation:
      os << " ThreadCreation";
      break;
    case Event::Type::ThreadDestruction:
      os << " ThreadDestruction";
      break;
    case Event::Type::SwitchIn:
      os << " SwitchIn";
      break;
    case Event::Type::SwitchOutPreempt:
      os << " SwitchOutPreempt";
      break;
    case Event::Type::SwitchOutYield:
      os << " SwitchOutYield";
      break;
    case Event::Type::WriteErrorsStart:
      os << "WriteErrorsStart";
      break;
    case Event::Type::WriteErrorsEnd:
      os << "WriteErrorsEnd";
      break;
  }
  return os;
}

inline std::ostream& operator<<(std::ostream& os, const Event& ev) {
  os << "<Event tstamp: " << tstampToStr(ev.tstamp) << " " << ev.type;
  switch (ev.type) {
    case Event::Type::Start:
      os << " level: " << static_cast<int>(ev.level);
      os << " tag: " << ev.tag;
      break;
    case Event::Type::End:
      os << " level: " << static_cast<int>(ev.level);
      break;
    case Event::Type::ThreadCreation:
      os << " level: " << static_cast<int>(ev.level);
      os << " tag: " << ev.tag;
      break;
    case Event::Type::ThreadDestruction:
      os << " level: " << static_cast<int>(ev.level);
      os << " tag: " << ev.tag;
      break;
    case Event::Type::SwitchIn:
      os << " level: " << static_cast<int>(ev.level);
      os << " tag: " << ev.tag;
      break;
    case Event::Type::SwitchOutPreempt:
      os << " level: " << static_cast<int>(ev.level);
      break;
    case Event::Type::SwitchOutYield:
      os << " level: " << static_cast<int>(ev.level);
      break;
    case Event::Type::WriteErrorsStart:
      break;
    case Event::Type::WriteErrorsEnd:
      break;
  }
  os << " comp_unit_id: " << ev.comp_unit_id;
  return os << " >";
}

} // namespace facebook::hbt::tagstack
