// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include "hbt/src/perf_event/PmuDevices.h"
#include "hbt/src/perf_event/PmuEvent.h"

namespace facebook::hbt::perf_event::generated {

namespace nehalemex_core_v2 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace nehalemex_core_v2

namespace goldmont_core_v13 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace goldmont_core_v13

namespace sandybridge_core_v16 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace sandybridge_core_v16

namespace sandybridge_uncore_v16 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace sandybridge_uncore_v16

namespace ivybridge_core_v21 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace ivybridge_core_v21

namespace ivybridge_uncore_v21 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace ivybridge_uncore_v21

namespace haswellx_core_v20 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace haswellx_core_v20

namespace haswellx_uncore_v20 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace haswellx_uncore_v20

namespace broadwell_core_v25 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwell_core_v25

namespace broadwell_uncore_v25 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwell_uncore_v25

namespace broadwellx_core_v14 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwellx_core_v14

namespace broadwellx_uncore_v14 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwellx_uncore_v14

namespace broadwellde_core_v7 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwellde_core_v7

namespace broadwellde_uncore_v7 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace broadwellde_uncore_v7

namespace skylake_core_v48 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace skylake_core_v48

namespace skylake_uncore_v48 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace skylake_uncore_v48

namespace knightslanding_core_v9 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace knightslanding_core_v9

namespace knightslanding_uncore_v9 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace knightslanding_uncore_v9

namespace skylakex_core_v1_21 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace skylakex_core_v1_21

namespace skylakex_uncore_v1_21 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace skylakex_uncore_v1_21

namespace skylakex_uncore_v1_21_experimental {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace skylakex_uncore_v1_21_experimental

namespace cascadelakex_core_v1_08 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace cascadelakex_core_v1_08

namespace cascadelakex_uncore_v1_08 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace cascadelakex_uncore_v1_08

namespace cascadelakex_uncore_v1_08_experimental {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace cascadelakex_uncore_v1_08_experimental

namespace icelake_core_v1_05 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace icelake_core_v1_05

namespace icelake_uncore_v1_05 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace icelake_uncore_v1_05

namespace snowridgex_core_v1_07 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace snowridgex_core_v1_07

namespace snowridgex_uncore_v1_07 {
void addEvents(PmuDeviceManager& pmu_manager);
} // namespace snowridgex_uncore_v1_07

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
      // from sandybridge_core_v16.json
      sandybridge_core_v16::addEvents(pmu_manager);
      // from sandybridge_uncore_v16.json
      sandybridge_uncore_v16::addEvents(pmu_manager);
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
      // from NehalemEX_core_V2.json
      nehalemex_core_v2::addEvents(pmu_manager);
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
      // from ivybridge_core_v21.json
      ivybridge_core_v21::addEvents(pmu_manager);
      // from ivybridge_uncore_v21.json
      ivybridge_uncore_v21::addEvents(pmu_manager);
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
      // from broadwell_core_v25.json
      broadwell_core_v25::addEvents(pmu_manager);
      // from broadwell_uncore_v25.json
      broadwell_uncore_v25::addEvents(pmu_manager);
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
      // from haswellx_core_v20.json
      haswellx_core_v20::addEvents(pmu_manager);
      // from haswellx_uncore_v20.json
      haswellx_uncore_v20::addEvents(pmu_manager);
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
      // from broadwell_core_v25.json
      broadwell_core_v25::addEvents(pmu_manager);
      // from broadwell_uncore_v25.json
      broadwell_uncore_v25::addEvents(pmu_manager);
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
      // from skylake_core_v48.json
      skylake_core_v48::addEvents(pmu_manager);
      // from skylake_uncore_v48.json
      skylake_uncore_v48::addEvents(pmu_manager);
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
      // from broadwellx_core_v14.json
      broadwellx_core_v14::addEvents(pmu_manager);
      // from broadwellx_uncore_v14.json
      broadwellx_uncore_v14::addEvents(pmu_manager);
      break;

    case toCpuKey(85, 0x0): // fall-through
    case toCpuKey(85, 0x1): // fall-through
    case toCpuKey(85, 0x2): // fall-through
    case toCpuKey(85, 0x3): // fall-through
    case toCpuKey(85, 0x4): // fall-through
      // from skylakex_core_v1.21.json
      skylakex_core_v1_21::addEvents(pmu_manager);
      // from skylakex_uncore_v1.21.json
      skylakex_uncore_v1_21::addEvents(pmu_manager);
      // from skylakex_uncore_v1.21_experimental.json
      skylakex_uncore_v1_21_experimental::addEvents(pmu_manager);
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
      // from cascadelakex_core_v1.08.json
      cascadelakex_core_v1_08::addEvents(pmu_manager);
      // from cascadelakex_uncore_v1.08.json
      cascadelakex_uncore_v1_08::addEvents(pmu_manager);
      // from cascadelakex_uncore_v1.08_experimental.json
      cascadelakex_uncore_v1_08_experimental::addEvents(pmu_manager);
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
      // from broadwellde_core_v7.json
      broadwellde_core_v7::addEvents(pmu_manager);
      // from broadwellde_uncore_v7.json
      broadwellde_uncore_v7::addEvents(pmu_manager);
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
      // from KnightsLanding_core_V9.json
      knightslanding_core_v9::addEvents(pmu_manager);
      // from KnightsLanding_uncore_V9.json
      knightslanding_uncore_v9::addEvents(pmu_manager);
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
      // from goldmont_core_v13.json
      goldmont_core_v13::addEvents(pmu_manager);
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
      // from skylake_core_v48.json
      skylake_core_v48::addEvents(pmu_manager);
      // from skylake_uncore_v48.json
      skylake_uncore_v48::addEvents(pmu_manager);
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
      // from goldmont_core_v13.json
      goldmont_core_v13::addEvents(pmu_manager);
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
      // from icelake_core_v1.05.json
      icelake_core_v1_05::addEvents(pmu_manager);
      // from icelake_uncore_v1.05.json
      icelake_uncore_v1_05::addEvents(pmu_manager);
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
      // from KnightsLanding_core_V9.json
      knightslanding_core_v9::addEvents(pmu_manager);
      // from KnightsLanding_uncore_V9.json
      knightslanding_uncore_v9::addEvents(pmu_manager);
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
      // from snowridgex_core_v1.07.json
      snowridgex_core_v1_07::addEvents(pmu_manager);
      // from snowridgex_uncore_v1.07.json
      snowridgex_uncore_v1_07::addEvents(pmu_manager);
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
      // from skylake_core_v48.json
      skylake_core_v48::addEvents(pmu_manager);
      // from skylake_uncore_v48.json
      skylake_uncore_v48::addEvents(pmu_manager);
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
      // from skylake_core_v48.json
      skylake_core_v48::addEvents(pmu_manager);
      // from skylake_uncore_v48.json
      skylake_uncore_v48::addEvents(pmu_manager);
      break;

    default:
      HBT_THROW_EINVAL() << "Unknown CPU model ID " + std::to_string(cpu_model);
  }
}

} // namespace facebook::hbt::perf_event::generated
