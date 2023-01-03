// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include "hbt/src/perf_event/PmuDevices.h"
#include "hbt/src/perf_event/PmuEvent.h"

namespace facebook::hbt::perf_event::generated {

namespace nehalemex_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace nehalemex_core

namespace goldmont_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace goldmont_core

namespace sandybridge_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace sandybridge_core

namespace sandybridge_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace sandybridge_uncore

namespace ivybridge_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace ivybridge_core

namespace ivybridge_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace ivybridge_uncore

namespace haswellx_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace haswellx_core

namespace haswellx_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace haswellx_uncore

namespace broadwell_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwell_core

namespace broadwell_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwell_uncore

namespace broadwellx_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwellx_core

namespace broadwellx_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwellx_uncore

namespace broadwellde_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwellde_core

namespace broadwellde_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwellde_uncore

namespace skylake_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace skylake_core

namespace skylake_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace skylake_uncore

namespace knightslanding_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace knightslanding_core

namespace knightslanding_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace knightslanding_uncore

namespace skylakex_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace skylakex_core

namespace skylakex_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace skylakex_uncore

namespace skylakex_uncore_experimental {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace skylakex_uncore_experimental

namespace cascadelakex_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace cascadelakex_core

namespace cascadelakex_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace cascadelakex_uncore

namespace cascadelakex_uncore_experimental {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace cascadelakex_uncore_experimental

namespace icelake_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace icelake_core

namespace icelake_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace icelake_uncore

namespace snowridgex_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace snowridgex_core

namespace snowridgex_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace snowridgex_uncore

namespace snowridgex_uncore_experimental {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace snowridgex_uncore_experimental

namespace sapphirerapids_core {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace sapphirerapids_core

namespace sapphirerapids_uncore {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace sapphirerapids_uncore

namespace sapphirerapids_uncore_experimental {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace sapphirerapids_uncore_experimental

// Make a key by combining cpu_model ond cpu_step
constexpr uint64_t toCpuKey(uint32_t cpu_model, uint32_t cpu_step) {
  uint64_t r = cpu_model;
  return (r << 31) | cpu_step;
}

inline void
addEvents(uint32_t cpu_model, uint32_t step, PmuDeviceManager& pmu_manager) {
  uint64_t cpu_key = toCpuKey(cpu_model, step);

  switch (cpu_key) {
    case toCpuKey(42, 0x0): // fall-through
    case toCpuKey(42, 0x1): // fall-through
    case toCpuKey(42, 0x2): // fall-through
    case toCpuKey(42, 0x3): // fall-through
    case toCpuKey(42, 0x4): // fall-through
    case toCpuKey(42, 0x5): // fall-through
    case toCpuKey(42, 0x6): // fall-through
    case toCpuKey(42, 0x7): // fall-through
    case toCpuKey(42, 0x8): // fall-through
    case toCpuKey(42, 0x9): // fall-through
    case toCpuKey(42, 0x10): // fall-through
    case toCpuKey(42, 0x11): // fall-through
    case toCpuKey(42, 0x12): // fall-through
    case toCpuKey(42, 0x13): // fall-through
    case toCpuKey(42, 0x14): // fall-through
    case toCpuKey(42, 0x15): // fall-through
      // from sandybridge_core.json
      sandybridge_core::addEvents(pmu_manager);
      // from sandybridge_uncore.json
      sandybridge_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(46, 0x0): // fall-through
    case toCpuKey(46, 0x1): // fall-through
    case toCpuKey(46, 0x2): // fall-through
    case toCpuKey(46, 0x3): // fall-through
    case toCpuKey(46, 0x4): // fall-through
    case toCpuKey(46, 0x5): // fall-through
    case toCpuKey(46, 0x6): // fall-through
    case toCpuKey(46, 0x7): // fall-through
    case toCpuKey(46, 0x8): // fall-through
    case toCpuKey(46, 0x9): // fall-through
    case toCpuKey(46, 0x10): // fall-through
    case toCpuKey(46, 0x11): // fall-through
    case toCpuKey(46, 0x12): // fall-through
    case toCpuKey(46, 0x13): // fall-through
    case toCpuKey(46, 0x14): // fall-through
    case toCpuKey(46, 0x15): // fall-through
      // from NehalemEX_core.json
      nehalemex_core::addEvents(pmu_manager);
      break;

    case toCpuKey(58, 0x0): // fall-through
    case toCpuKey(58, 0x1): // fall-through
    case toCpuKey(58, 0x2): // fall-through
    case toCpuKey(58, 0x3): // fall-through
    case toCpuKey(58, 0x4): // fall-through
    case toCpuKey(58, 0x5): // fall-through
    case toCpuKey(58, 0x6): // fall-through
    case toCpuKey(58, 0x7): // fall-through
    case toCpuKey(58, 0x8): // fall-through
    case toCpuKey(58, 0x9): // fall-through
    case toCpuKey(58, 0x10): // fall-through
    case toCpuKey(58, 0x11): // fall-through
    case toCpuKey(58, 0x12): // fall-through
    case toCpuKey(58, 0x13): // fall-through
    case toCpuKey(58, 0x14): // fall-through
    case toCpuKey(58, 0x15): // fall-through
      // from ivybridge_core.json
      ivybridge_core::addEvents(pmu_manager);
      // from ivybridge_uncore.json
      ivybridge_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(61, 0x0): // fall-through
    case toCpuKey(61, 0x1): // fall-through
    case toCpuKey(61, 0x2): // fall-through
    case toCpuKey(61, 0x3): // fall-through
    case toCpuKey(61, 0x4): // fall-through
    case toCpuKey(61, 0x5): // fall-through
    case toCpuKey(61, 0x6): // fall-through
    case toCpuKey(61, 0x7): // fall-through
    case toCpuKey(61, 0x8): // fall-through
    case toCpuKey(61, 0x9): // fall-through
    case toCpuKey(61, 0x10): // fall-through
    case toCpuKey(61, 0x11): // fall-through
    case toCpuKey(61, 0x12): // fall-through
    case toCpuKey(61, 0x13): // fall-through
    case toCpuKey(61, 0x14): // fall-through
    case toCpuKey(61, 0x15): // fall-through
      // from broadwell_core.json
      broadwell_core::addEvents(pmu_manager);
      // from broadwell_uncore.json
      broadwell_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(63, 0x0): // fall-through
    case toCpuKey(63, 0x1): // fall-through
    case toCpuKey(63, 0x2): // fall-through
    case toCpuKey(63, 0x3): // fall-through
    case toCpuKey(63, 0x4): // fall-through
    case toCpuKey(63, 0x5): // fall-through
    case toCpuKey(63, 0x6): // fall-through
    case toCpuKey(63, 0x7): // fall-through
    case toCpuKey(63, 0x8): // fall-through
    case toCpuKey(63, 0x9): // fall-through
    case toCpuKey(63, 0x10): // fall-through
    case toCpuKey(63, 0x11): // fall-through
    case toCpuKey(63, 0x12): // fall-through
    case toCpuKey(63, 0x13): // fall-through
    case toCpuKey(63, 0x14): // fall-through
    case toCpuKey(63, 0x15): // fall-through
      // from haswellx_core.json
      haswellx_core::addEvents(pmu_manager);
      // from haswellx_uncore.json
      haswellx_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(71, 0x0): // fall-through
    case toCpuKey(71, 0x1): // fall-through
    case toCpuKey(71, 0x2): // fall-through
    case toCpuKey(71, 0x3): // fall-through
    case toCpuKey(71, 0x4): // fall-through
    case toCpuKey(71, 0x5): // fall-through
    case toCpuKey(71, 0x6): // fall-through
    case toCpuKey(71, 0x7): // fall-through
    case toCpuKey(71, 0x8): // fall-through
    case toCpuKey(71, 0x9): // fall-through
    case toCpuKey(71, 0x10): // fall-through
    case toCpuKey(71, 0x11): // fall-through
    case toCpuKey(71, 0x12): // fall-through
    case toCpuKey(71, 0x13): // fall-through
    case toCpuKey(71, 0x14): // fall-through
    case toCpuKey(71, 0x15): // fall-through
      // from broadwell_core.json
      broadwell_core::addEvents(pmu_manager);
      // from broadwell_uncore.json
      broadwell_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(78, 0x0): // fall-through
    case toCpuKey(78, 0x1): // fall-through
    case toCpuKey(78, 0x2): // fall-through
    case toCpuKey(78, 0x3): // fall-through
    case toCpuKey(78, 0x4): // fall-through
    case toCpuKey(78, 0x5): // fall-through
    case toCpuKey(78, 0x6): // fall-through
    case toCpuKey(78, 0x7): // fall-through
    case toCpuKey(78, 0x8): // fall-through
    case toCpuKey(78, 0x9): // fall-through
    case toCpuKey(78, 0x10): // fall-through
    case toCpuKey(78, 0x11): // fall-through
    case toCpuKey(78, 0x12): // fall-through
    case toCpuKey(78, 0x13): // fall-through
    case toCpuKey(78, 0x14): // fall-through
    case toCpuKey(78, 0x15): // fall-through
      // from skylake_core.json
      skylake_core::addEvents(pmu_manager);
      // from skylake_uncore.json
      skylake_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(79, 0x0): // fall-through
    case toCpuKey(79, 0x1): // fall-through
    case toCpuKey(79, 0x2): // fall-through
    case toCpuKey(79, 0x3): // fall-through
    case toCpuKey(79, 0x4): // fall-through
    case toCpuKey(79, 0x5): // fall-through
    case toCpuKey(79, 0x6): // fall-through
    case toCpuKey(79, 0x7): // fall-through
    case toCpuKey(79, 0x8): // fall-through
    case toCpuKey(79, 0x9): // fall-through
    case toCpuKey(79, 0x10): // fall-through
    case toCpuKey(79, 0x11): // fall-through
    case toCpuKey(79, 0x12): // fall-through
    case toCpuKey(79, 0x13): // fall-through
    case toCpuKey(79, 0x14): // fall-through
    case toCpuKey(79, 0x15): // fall-through
      // from broadwellx_core.json
      broadwellx_core::addEvents(pmu_manager);
      // from broadwellx_uncore.json
      broadwellx_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(85, 0x0): // fall-through
    case toCpuKey(85, 0x1): // fall-through
    case toCpuKey(85, 0x2): // fall-through
    case toCpuKey(85, 0x3): // fall-through
    case toCpuKey(85, 0x4): // fall-through
      // from skylakex_core.json
      skylakex_core::addEvents(pmu_manager);
      // from skylakex_uncore.json
      skylakex_uncore::addEvents(pmu_manager);
      // from skylakex_uncore_experimental.json
      skylakex_uncore_experimental::addEvents(pmu_manager);
      break;

    case toCpuKey(85, 0x5): // fall-through
    case toCpuKey(85, 0x6): // fall-through
    case toCpuKey(85, 0x7): // fall-through
    case toCpuKey(85, 0x8): // fall-through
    case toCpuKey(85, 0x9): // fall-through
    case toCpuKey(85, 0xA): // fall-through
    case toCpuKey(85, 0xB): // fall-through
    case toCpuKey(85, 0xC): // fall-through
    case toCpuKey(85, 0xD): // fall-through
    case toCpuKey(85, 0xE): // fall-through
    case toCpuKey(85, 0xF): // fall-through
      // from cascadelakex_core.json
      cascadelakex_core::addEvents(pmu_manager);
      // from cascadelakex_uncore.json
      cascadelakex_uncore::addEvents(pmu_manager);
      // from cascadelakex_uncore_experimental.json
      cascadelakex_uncore_experimental::addEvents(pmu_manager);
      break;

    case toCpuKey(86, 0x0): // fall-through
    case toCpuKey(86, 0x1): // fall-through
    case toCpuKey(86, 0x2): // fall-through
    case toCpuKey(86, 0x3): // fall-through
    case toCpuKey(86, 0x4): // fall-through
    case toCpuKey(86, 0x5): // fall-through
    case toCpuKey(86, 0x6): // fall-through
    case toCpuKey(86, 0x7): // fall-through
    case toCpuKey(86, 0x8): // fall-through
    case toCpuKey(86, 0x9): // fall-through
    case toCpuKey(86, 0x10): // fall-through
    case toCpuKey(86, 0x11): // fall-through
    case toCpuKey(86, 0x12): // fall-through
    case toCpuKey(86, 0x13): // fall-through
    case toCpuKey(86, 0x14): // fall-through
    case toCpuKey(86, 0x15): // fall-through
      // from broadwellde_core.json
      broadwellde_core::addEvents(pmu_manager);
      // from broadwellde_uncore.json
      broadwellde_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(87, 0x0): // fall-through
    case toCpuKey(87, 0x1): // fall-through
    case toCpuKey(87, 0x2): // fall-through
    case toCpuKey(87, 0x3): // fall-through
    case toCpuKey(87, 0x4): // fall-through
    case toCpuKey(87, 0x5): // fall-through
    case toCpuKey(87, 0x6): // fall-through
    case toCpuKey(87, 0x7): // fall-through
    case toCpuKey(87, 0x8): // fall-through
    case toCpuKey(87, 0x9): // fall-through
    case toCpuKey(87, 0x10): // fall-through
    case toCpuKey(87, 0x11): // fall-through
    case toCpuKey(87, 0x12): // fall-through
    case toCpuKey(87, 0x13): // fall-through
    case toCpuKey(87, 0x14): // fall-through
    case toCpuKey(87, 0x15): // fall-through
      // from KnightsLanding_core.json
      knightslanding_core::addEvents(pmu_manager);
      // from KnightsLanding_uncore.json
      knightslanding_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(92, 0x0): // fall-through
    case toCpuKey(92, 0x1): // fall-through
    case toCpuKey(92, 0x2): // fall-through
    case toCpuKey(92, 0x3): // fall-through
    case toCpuKey(92, 0x4): // fall-through
    case toCpuKey(92, 0x5): // fall-through
    case toCpuKey(92, 0x6): // fall-through
    case toCpuKey(92, 0x7): // fall-through
    case toCpuKey(92, 0x8): // fall-through
    case toCpuKey(92, 0x9): // fall-through
    case toCpuKey(92, 0x10): // fall-through
    case toCpuKey(92, 0x11): // fall-through
    case toCpuKey(92, 0x12): // fall-through
    case toCpuKey(92, 0x13): // fall-through
    case toCpuKey(92, 0x14): // fall-through
    case toCpuKey(92, 0x15): // fall-through
      // from goldmont_core.json
      goldmont_core::addEvents(pmu_manager);
      break;

    case toCpuKey(94, 0x0): // fall-through
    case toCpuKey(94, 0x1): // fall-through
    case toCpuKey(94, 0x2): // fall-through
    case toCpuKey(94, 0x3): // fall-through
    case toCpuKey(94, 0x4): // fall-through
    case toCpuKey(94, 0x5): // fall-through
    case toCpuKey(94, 0x6): // fall-through
    case toCpuKey(94, 0x7): // fall-through
    case toCpuKey(94, 0x8): // fall-through
    case toCpuKey(94, 0x9): // fall-through
    case toCpuKey(94, 0x10): // fall-through
    case toCpuKey(94, 0x11): // fall-through
    case toCpuKey(94, 0x12): // fall-through
    case toCpuKey(94, 0x13): // fall-through
    case toCpuKey(94, 0x14): // fall-through
    case toCpuKey(94, 0x15): // fall-through
      // from skylake_core.json
      skylake_core::addEvents(pmu_manager);
      // from skylake_uncore.json
      skylake_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(95, 0x0): // fall-through
    case toCpuKey(95, 0x1): // fall-through
    case toCpuKey(95, 0x2): // fall-through
    case toCpuKey(95, 0x3): // fall-through
    case toCpuKey(95, 0x4): // fall-through
    case toCpuKey(95, 0x5): // fall-through
    case toCpuKey(95, 0x6): // fall-through
    case toCpuKey(95, 0x7): // fall-through
    case toCpuKey(95, 0x8): // fall-through
    case toCpuKey(95, 0x9): // fall-through
    case toCpuKey(95, 0x10): // fall-through
    case toCpuKey(95, 0x11): // fall-through
    case toCpuKey(95, 0x12): // fall-through
    case toCpuKey(95, 0x13): // fall-through
    case toCpuKey(95, 0x14): // fall-through
    case toCpuKey(95, 0x15): // fall-through
      // from goldmont_core.json
      goldmont_core::addEvents(pmu_manager);
      break;

    case toCpuKey(125, 0x0): // fall-through
    case toCpuKey(125, 0x1): // fall-through
    case toCpuKey(125, 0x2): // fall-through
    case toCpuKey(125, 0x3): // fall-through
    case toCpuKey(125, 0x4): // fall-through
    case toCpuKey(125, 0x5): // fall-through
    case toCpuKey(125, 0x6): // fall-through
    case toCpuKey(125, 0x7): // fall-through
    case toCpuKey(125, 0x8): // fall-through
    case toCpuKey(125, 0x9): // fall-through
    case toCpuKey(125, 0x10): // fall-through
    case toCpuKey(125, 0x11): // fall-through
    case toCpuKey(125, 0x12): // fall-through
    case toCpuKey(125, 0x13): // fall-through
    case toCpuKey(125, 0x14): // fall-through
    case toCpuKey(125, 0x15): // fall-through
      // from icelake_core.json
      icelake_core::addEvents(pmu_manager);
      // from icelake_uncore.json
      icelake_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(126, 0x0): // fall-through
    case toCpuKey(126, 0x1): // fall-through
    case toCpuKey(126, 0x2): // fall-through
    case toCpuKey(126, 0x3): // fall-through
    case toCpuKey(126, 0x4): // fall-through
    case toCpuKey(126, 0x5): // fall-through
    case toCpuKey(126, 0x6): // fall-through
    case toCpuKey(126, 0x7): // fall-through
    case toCpuKey(126, 0x8): // fall-through
    case toCpuKey(126, 0x9): // fall-through
    case toCpuKey(126, 0x10): // fall-through
    case toCpuKey(126, 0x11): // fall-through
    case toCpuKey(126, 0x12): // fall-through
    case toCpuKey(126, 0x13): // fall-through
    case toCpuKey(126, 0x14): // fall-through
    case toCpuKey(126, 0x15): // fall-through
      // from icelake_core.json
      icelake_core::addEvents(pmu_manager);
      // from icelake_uncore.json
      icelake_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(133, 0x0): // fall-through
    case toCpuKey(133, 0x1): // fall-through
    case toCpuKey(133, 0x2): // fall-through
    case toCpuKey(133, 0x3): // fall-through
    case toCpuKey(133, 0x4): // fall-through
    case toCpuKey(133, 0x5): // fall-through
    case toCpuKey(133, 0x6): // fall-through
    case toCpuKey(133, 0x7): // fall-through
    case toCpuKey(133, 0x8): // fall-through
    case toCpuKey(133, 0x9): // fall-through
    case toCpuKey(133, 0x10): // fall-through
    case toCpuKey(133, 0x11): // fall-through
    case toCpuKey(133, 0x12): // fall-through
    case toCpuKey(133, 0x13): // fall-through
    case toCpuKey(133, 0x14): // fall-through
    case toCpuKey(133, 0x15): // fall-through
      // from KnightsLanding_core.json
      knightslanding_core::addEvents(pmu_manager);
      // from KnightsLanding_uncore.json
      knightslanding_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(134, 0x0): // fall-through
    case toCpuKey(134, 0x1): // fall-through
    case toCpuKey(134, 0x2): // fall-through
    case toCpuKey(134, 0x3): // fall-through
    case toCpuKey(134, 0x4): // fall-through
    case toCpuKey(134, 0x5): // fall-through
    case toCpuKey(134, 0x6): // fall-through
    case toCpuKey(134, 0x7): // fall-through
    case toCpuKey(134, 0x8): // fall-through
    case toCpuKey(134, 0x9): // fall-through
    case toCpuKey(134, 0x10): // fall-through
    case toCpuKey(134, 0x11): // fall-through
    case toCpuKey(134, 0x12): // fall-through
    case toCpuKey(134, 0x13): // fall-through
    case toCpuKey(134, 0x14): // fall-through
    case toCpuKey(134, 0x15): // fall-through
      // from snowridgex_core.json
      snowridgex_core::addEvents(pmu_manager);
      // from snowridgex_uncore.json
      snowridgex_uncore::addEvents(pmu_manager);
      // from snowridgex_uncore_experimental.json
      snowridgex_uncore_experimental::addEvents(pmu_manager);
      break;

    case toCpuKey(142, 0x0): // fall-through
    case toCpuKey(142, 0x1): // fall-through
    case toCpuKey(142, 0x2): // fall-through
    case toCpuKey(142, 0x3): // fall-through
    case toCpuKey(142, 0x4): // fall-through
    case toCpuKey(142, 0x5): // fall-through
    case toCpuKey(142, 0x6): // fall-through
    case toCpuKey(142, 0x7): // fall-through
    case toCpuKey(142, 0x8): // fall-through
    case toCpuKey(142, 0x9): // fall-through
    case toCpuKey(142, 0x10): // fall-through
    case toCpuKey(142, 0x11): // fall-through
    case toCpuKey(142, 0x12): // fall-through
    case toCpuKey(142, 0x13): // fall-through
    case toCpuKey(142, 0x14): // fall-through
    case toCpuKey(142, 0x15): // fall-through
      // from skylake_core.json
      skylake_core::addEvents(pmu_manager);
      // from skylake_uncore.json
      skylake_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(143, 0x0): // fall-through
    case toCpuKey(143, 0x1): // fall-through
    case toCpuKey(143, 0x2): // fall-through
    case toCpuKey(143, 0x3): // fall-through
    case toCpuKey(143, 0x4): // fall-through
    case toCpuKey(143, 0x5): // fall-through
    case toCpuKey(143, 0x6): // fall-through
    case toCpuKey(143, 0x7): // fall-through
    case toCpuKey(143, 0x8): // fall-through
    case toCpuKey(143, 0x9): // fall-through
    case toCpuKey(143, 0x10): // fall-through
    case toCpuKey(143, 0x11): // fall-through
    case toCpuKey(143, 0x12): // fall-through
    case toCpuKey(143, 0x13): // fall-through
    case toCpuKey(143, 0x14): // fall-through
    case toCpuKey(143, 0x15): // fall-through
      // from sapphirerapids_core.json
      sapphirerapids_core::addEvents(pmu_manager);
      // from sapphirerapids_uncore.json
      sapphirerapids_uncore::addEvents(pmu_manager);
      // from sapphirerapids_uncore_experimental.json
      sapphirerapids_uncore_experimental::addEvents(pmu_manager);
      break;

    case toCpuKey(158, 0x0): // fall-through
    case toCpuKey(158, 0x1): // fall-through
    case toCpuKey(158, 0x2): // fall-through
    case toCpuKey(158, 0x3): // fall-through
    case toCpuKey(158, 0x4): // fall-through
    case toCpuKey(158, 0x5): // fall-through
    case toCpuKey(158, 0x6): // fall-through
    case toCpuKey(158, 0x7): // fall-through
    case toCpuKey(158, 0x8): // fall-through
    case toCpuKey(158, 0x9): // fall-through
    case toCpuKey(158, 0x10): // fall-through
    case toCpuKey(158, 0x11): // fall-through
    case toCpuKey(158, 0x12): // fall-through
    case toCpuKey(158, 0x13): // fall-through
    case toCpuKey(158, 0x14): // fall-through
    case toCpuKey(158, 0x15): // fall-through
      // from skylake_core.json
      skylake_core::addEvents(pmu_manager);
      // from skylake_uncore.json
      skylake_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(165, 0x0): // fall-through
    case toCpuKey(165, 0x1): // fall-through
    case toCpuKey(165, 0x2): // fall-through
    case toCpuKey(165, 0x3): // fall-through
    case toCpuKey(165, 0x4): // fall-through
    case toCpuKey(165, 0x5): // fall-through
    case toCpuKey(165, 0x6): // fall-through
    case toCpuKey(165, 0x7): // fall-through
    case toCpuKey(165, 0x8): // fall-through
    case toCpuKey(165, 0x9): // fall-through
    case toCpuKey(165, 0x10): // fall-through
    case toCpuKey(165, 0x11): // fall-through
    case toCpuKey(165, 0x12): // fall-through
    case toCpuKey(165, 0x13): // fall-through
    case toCpuKey(165, 0x14): // fall-through
    case toCpuKey(165, 0x15): // fall-through
      // from skylake_core.json
      skylake_core::addEvents(pmu_manager);
      // from skylake_uncore.json
      skylake_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(166, 0x0): // fall-through
    case toCpuKey(166, 0x1): // fall-through
    case toCpuKey(166, 0x2): // fall-through
    case toCpuKey(166, 0x3): // fall-through
    case toCpuKey(166, 0x4): // fall-through
    case toCpuKey(166, 0x5): // fall-through
    case toCpuKey(166, 0x6): // fall-through
    case toCpuKey(166, 0x7): // fall-through
    case toCpuKey(166, 0x8): // fall-through
    case toCpuKey(166, 0x9): // fall-through
    case toCpuKey(166, 0x10): // fall-through
    case toCpuKey(166, 0x11): // fall-through
    case toCpuKey(166, 0x12): // fall-through
    case toCpuKey(166, 0x13): // fall-through
    case toCpuKey(166, 0x14): // fall-through
    case toCpuKey(166, 0x15): // fall-through
      // from skylake_core.json
      skylake_core::addEvents(pmu_manager);
      // from skylake_uncore.json
      skylake_uncore::addEvents(pmu_manager);
      break;

    case toCpuKey(167, 0x0): // fall-through
    case toCpuKey(167, 0x1): // fall-through
    case toCpuKey(167, 0x2): // fall-through
    case toCpuKey(167, 0x3): // fall-through
    case toCpuKey(167, 0x4): // fall-through
    case toCpuKey(167, 0x5): // fall-through
    case toCpuKey(167, 0x6): // fall-through
    case toCpuKey(167, 0x7): // fall-through
    case toCpuKey(167, 0x8): // fall-through
    case toCpuKey(167, 0x9): // fall-through
    case toCpuKey(167, 0x10): // fall-through
    case toCpuKey(167, 0x11): // fall-through
    case toCpuKey(167, 0x12): // fall-through
    case toCpuKey(167, 0x13): // fall-through
    case toCpuKey(167, 0x14): // fall-through
    case toCpuKey(167, 0x15): // fall-through
      // from icelake_core.json
      icelake_core::addEvents(pmu_manager);
      // from icelake_uncore.json
      icelake_uncore::addEvents(pmu_manager);
      break;

    default:
      HBT_THROW_EINVAL() << "Unknown CPU model ID " + std::to_string(cpu_model);
  }
}

} // namespace facebook::hbt::perf_event::generated
