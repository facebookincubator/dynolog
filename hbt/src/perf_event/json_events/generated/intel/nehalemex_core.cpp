// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace nehalemex_core {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from NehalemEX_core.json (553 events).

    Supported SKUs:
        - Arch: x86, Model: NHM-EX id: 46
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.CYCLES_DIV_BUSY",
      EventDef::Encoding{
          .code = 0x14, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Cycles the divider is busy)",
      R"(Cycles the divider is busy)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.DIV",
      EventDef::Encoding{
          .code = 0x14,
          .umask = 0x1,
          .edge = true,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Divide Operations executed)",
      R"(Divide Operations executed)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ARITH.MUL",
      EventDef::Encoding{
          .code = 0x14, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Multiply operations executed)",
      R"(Multiply operations executed)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEAR.BAD_TARGET",
      EventDef::Encoding{
          .code = 0xE6, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(BACLEAR asserted with bad target address)",
      R"(BACLEAR asserted with bad target address)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEAR.CLEAR",
      EventDef::Encoding{
          .code = 0xE6, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(BACLEAR asserted, regardless of cause )",
      R"(BACLEAR asserted, regardless of cause )",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BACLEAR_FORCE_IQ",
      EventDef::Encoding{
          .code = 0xA7, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Instruction queue forced BACLEAR)",
      R"(Instruction queue forced BACLEAR)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BPU_CLEARS.EARLY",
      EventDef::Encoding{
          .code = 0xE8, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Early Branch Prediciton Unit clears)",
      R"(Early Branch Prediciton Unit clears)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BPU_CLEARS.LATE",
      EventDef::Encoding{
          .code = 0xE8, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Late Branch Prediction Unit clears)",
      R"(Late Branch Prediction Unit clears)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BPU_MISSED_CALL_RET",
      EventDef::Encoding{
          .code = 0xE5, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Branch prediction unit missed call or return)",
      R"(Branch prediction unit missed call or return)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_DECODED",
      EventDef::Encoding{
          .code = 0xE0, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Branch instructions decoded)",
      R"(Branch instructions decoded)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.ANY",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x7F, .cmask = 0, .msr_values = {0}},
      R"(Branch instructions executed)",
      R"(Branch instructions executed)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.COND",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Conditional branch instructions executed)",
      R"(Conditional branch instructions executed)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.DIRECT",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Unconditional branches executed)",
      R"(Unconditional branches executed)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.DIRECT_NEAR_CALL",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Unconditional call branches executed)",
      R"(Unconditional call branches executed)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.INDIRECT_NEAR_CALL",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Indirect call branches executed)",
      R"(Indirect call branches executed)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.INDIRECT_NON_CALL",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Indirect non call branches executed)",
      R"(Indirect non call branches executed)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.NEAR_CALLS",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(Call branches executed)",
      R"(Call branches executed)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.NON_CALLS",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x7, .cmask = 0, .msr_values = {0}},
      R"(All non call branches executed)",
      R"(All non call branches executed)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.RETURN_NEAR",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(Indirect return branches executed)",
      R"(Indirect return branches executed)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_EXEC.TAKEN",
      EventDef::Encoding{
          .code = 0x88, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Taken branches executed)",
      R"(Taken branches executed)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.ALL_BRANCHES",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Retired branch instructions (Precise Event))",
      R"(Retired branch instructions (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.CONDITIONAL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Retired conditional branch instructions (Precise Event))",
      R"(Retired conditional branch instructions (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_INST_RETIRED.NEAR_CALL",
      EventDef::Encoding{
          .code = 0xC4, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Retired near call instructions (Precise Event))",
      R"(Retired near call instructions (Precise Event))",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.ANY",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x7F, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted branches executed)",
      R"(Mispredicted branches executed)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.COND",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted conditional branches executed)",
      R"(Mispredicted conditional branches executed)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.DIRECT",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted unconditional branches executed)",
      R"(Mispredicted unconditional branches executed)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.DIRECT_NEAR_CALL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted non call branches executed)",
      R"(Mispredicted non call branches executed)",
      2000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.INDIRECT_NEAR_CALL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted indirect call branches executed)",
      R"(Mispredicted indirect call branches executed)",
      2000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.INDIRECT_NON_CALL",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted indirect non call branches executed)",
      R"(Mispredicted indirect non call branches executed)",
      2000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.NEAR_CALLS",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted call branches executed)",
      R"(Mispredicted call branches executed)",
      2000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.NON_CALLS",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x7, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted non call branches executed)",
      R"(Mispredicted non call branches executed)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.RETURN_NEAR",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted return branches executed)",
      R"(Mispredicted return branches executed)",
      2000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_EXEC.TAKEN",
      EventDef::Encoding{
          .code = 0x89, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted taken branches executed)",
      R"(Mispredicted taken branches executed)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "BR_MISP_RETIRED.NEAR_CALL",
      EventDef::Encoding{
          .code = 0xC5, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Mispredicted near retired calls (Precise Event))",
      R"(Mispredicted near retired calls (Precise Event))",
      2000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CACHE_LOCK_CYCLES.L1D",
      EventDef::Encoding{
          .code = 0x63, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Cycles L1D locked)",
      R"(Cycles L1D locked)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CACHE_LOCK_CYCLES.L1D_L2",
      EventDef::Encoding{
          .code = 0x63, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Cycles L1D and L2 locked)",
      R"(Cycles L1D and L2 locked)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF",
      EventDef::Encoding{
          .code = 0x0, .umask = 0x0, .cmask = 0, .msr_values = {0}},
      R"(Reference cycles when thread is not halted (fixed counter))",
      R"(Reference cycles when thread is not halted (fixed counter))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.REF_P",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Reference base clock (133 Mhz) cycles when thread is not halted (programmable counter))",
      R"(Reference base clock (133 Mhz) cycles when thread is not halted (programmable counter))",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD",
      EventDef::Encoding{
          .code = 0x0, .umask = 0x0, .cmask = 0, .msr_values = {0}},
      R"(Cycles when thread is not halted (fixed counter))",
      R"(Cycles when thread is not halted (fixed counter))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.THREAD_P",
      EventDef::Encoding{
          .code = 0x3C, .umask = 0x0, .cmask = 0, .msr_values = {0}},
      R"(Cycles when thread is not halted (programmable counter))",
      R"(Cycles when thread is not halted (programmable counter))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "CPU_CLK_UNHALTED.TOTAL_CYCLES",
      EventDef::Encoding{
          .code = 0x3C,
          .umask = 0x0,
          .inv = true,
          .cmask = 2,
          .msr_values = {0}},
      R"(Total CPU cycles)",
      R"(Total CPU cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.ANY",
      EventDef::Encoding{
          .code = 0x8, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(DTLB load misses)",
      R"(DTLB load misses)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.PDE_MISS",
      EventDef::Encoding{
          .code = 0x8, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(DTLB load miss caused by low part of address)",
      R"(DTLB load miss caused by low part of address)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x8, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(DTLB second level hit)",
      R"(DTLB second level hit)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_LOAD_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x8, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(DTLB load miss page walks complete)",
      R"(DTLB load miss page walks complete)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_MISSES.ANY",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(DTLB misses)",
      R"(DTLB misses)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_MISSES.STLB_HIT",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(DTLB first level misses but second level hit)",
      R"(DTLB first level misses but second level hit)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "DTLB_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x49, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(DTLB miss page walks)",
      R"(DTLB miss page walks)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ES_REG_RENAMES",
      EventDef::Encoding{
          .code = 0xD5, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(ES segment renames)",
      R"(ES segment renames)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.ALL",
      EventDef::Encoding{
          .code = 0xF7, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(X87 Floating point assists (Precise Event))",
      R"(X87 Floating point assists (Precise Event))",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.INPUT",
      EventDef::Encoding{
          .code = 0xF7, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(X87 Floating poiint assists for invalid input value (Precise Event))",
      R"(X87 Floating poiint assists for invalid input value (Precise Event))",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_ASSIST.OUTPUT",
      EventDef::Encoding{
          .code = 0xF7, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(X87 Floating point assists for invalid output value (Precise Event))",
      R"(X87 Floating point assists for invalid output value (Precise Event))",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.MMX",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(MMX Uops)",
      R"(MMX Uops)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.SSE_DOUBLE_PRECISION",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(SSE* FP double precision Uops)",
      R"(SSE* FP double precision Uops)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.SSE_FP",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(SSE and SSE2 FP Uops)",
      R"(SSE and SSE2 FP Uops)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.SSE_FP_PACKED",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(SSE FP packed Uops)",
      R"(SSE FP packed Uops)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.SSE_FP_SCALAR",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(SSE FP scalar Uops)",
      R"(SSE FP scalar Uops)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.SSE_SINGLE_PRECISION",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(SSE* FP single precision Uops)",
      R"(SSE* FP single precision Uops)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.SSE2_INTEGER",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(SSE2 integer Uops)",
      R"(SSE2 integer Uops)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_COMP_OPS_EXE.X87",
      EventDef::Encoding{
          .code = 0x10, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Computational floating-point operations executed)",
      R"(Computational floating-point operations executed)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_MMX_TRANS.ANY",
      EventDef::Encoding{
          .code = 0xCC, .umask = 0x3, .cmask = 0, .msr_values = {0}},
      R"(All Floating Point to and from MMX transitions)",
      R"(All Floating Point to and from MMX transitions)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_MMX_TRANS.TO_FP",
      EventDef::Encoding{
          .code = 0xCC, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Transitions from MMX to Floating Point instructions)",
      R"(Transitions from MMX to Floating Point instructions)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "FP_MMX_TRANS.TO_MMX",
      EventDef::Encoding{
          .code = 0xCC, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Transitions from Floating Point to MMX instructions)",
      R"(Transitions from Floating Point to MMX instructions)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ILD_STALL.ANY",
      EventDef::Encoding{
          .code = 0x87, .umask = 0xF, .cmask = 0, .msr_values = {0}},
      R"(Any Instruction Length Decoder stall cycles)",
      R"(Any Instruction Length Decoder stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ILD_STALL.IQ_FULL",
      EventDef::Encoding{
          .code = 0x87, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Instruction Queue full stall cycles)",
      R"(Instruction Queue full stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ILD_STALL.LCP",
      EventDef::Encoding{
          .code = 0x87, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Length Change Prefix stall cycles)",
      R"(Length Change Prefix stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ILD_STALL.MRU",
      EventDef::Encoding{
          .code = 0x87, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Stall cycles due to BPU MRU bypass)",
      R"(Stall cycles due to BPU MRU bypass)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ILD_STALL.REGEN",
      EventDef::Encoding{
          .code = 0x87, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(Regen stall cycles)",
      R"(Regen stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_DECODED.DEC0",
      EventDef::Encoding{
          .code = 0x18, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Instructions that must be decoded by decoder 0)",
      R"(Instructions that must be decoded by decoder 0)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_QUEUE_WRITE_CYCLES",
      EventDef::Encoding{
          .code = 0x1E, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Cycles instructions are written to the instruction queue)",
      R"(Cycles instructions are written to the instruction queue)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_QUEUE_WRITES",
      EventDef::Encoding{
          .code = 0x17, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Instructions written to instruction queue.)",
      R"(Instructions written to instruction queue.)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0x0, .umask = 0x0, .cmask = 0, .msr_values = {0}},
      R"(Instructions retired (fixed counter))",
      R"(Instructions retired (fixed counter))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.ANY_P",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Instructions retired (Programmable counter and Precise Event))",
      R"(Instructions retired (Programmable counter and Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.MMX",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Retired MMX instructions (Precise Event))",
      R"(Retired MMX instructions (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.TOTAL_CYCLES",
      EventDef::Encoding{
          .code = 0xC0,
          .umask = 0x1,
          .inv = true,
          .cmask = 16,
          .msr_values = {0}},
      R"(Total cycles (Precise Event))",
      R"(Total cycles (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.X87",
      EventDef::Encoding{
          .code = 0xC0, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Retired floating-point operations (Precise Event))",
      R"(Retired floating-point operations (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "IO_TRANSACTIONS",
      EventDef::Encoding{
          .code = 0x6C, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(I/O transactions)",
      R"(I/O transactions)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_FLUSH",
      EventDef::Encoding{
          .code = 0xAE, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(ITLB flushes)",
      R"(ITLB flushes)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISS_RETIRED",
      EventDef::Encoding{
          .code = 0xC8, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Retired instructions that missed the ITLB (Precise Event))",
      R"(Retired instructions that missed the ITLB (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.ANY",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(ITLB miss)",
      R"(ITLB miss)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "ITLB_MISSES.WALK_COMPLETED",
      EventDef::Encoding{
          .code = 0x85, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(ITLB miss page walks)",
      R"(ITLB miss page walks)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D.M_EVICT",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L1D cache lines replaced in M state)",
      R"(L1D cache lines replaced in M state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D.M_REPL",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L1D cache lines allocated in the M state)",
      R"(L1D cache lines allocated in the M state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D.M_SNOOP_EVICT",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(L1D snoop eviction of cache lines in M state)",
      R"(L1D snoop eviction of cache lines in M state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D.REPL",
      EventDef::Encoding{
          .code = 0x51, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache lines allocated)",
      R"(L1 data cache lines allocated)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_ALL_REF.ANY",
      EventDef::Encoding{
          .code = 0x43, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(All references to the L1 data cache)",
      R"(All references to the L1 data cache)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_ALL_REF.CACHEABLE",
      EventDef::Encoding{
          .code = 0x43, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L1 data cacheable reads and writes)",
      R"(L1 data cacheable reads and writes)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_LD.E_STATE",
      EventDef::Encoding{
          .code = 0x40, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache read in E state)",
      R"(L1 data cache read in E state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_LD.I_STATE",
      EventDef::Encoding{
          .code = 0x40, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache read in I state (misses))",
      R"(L1 data cache read in I state (misses))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_LD.M_STATE",
      EventDef::Encoding{
          .code = 0x40, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache read in M state)",
      R"(L1 data cache read in M state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_LD.MESI",
      EventDef::Encoding{
          .code = 0x40, .umask = 0xF, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache reads)",
      R"(L1 data cache reads)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_LD.S_STATE",
      EventDef::Encoding{
          .code = 0x40, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache read in S state)",
      R"(L1 data cache read in S state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_LOCK.E_STATE",
      EventDef::Encoding{
          .code = 0x42, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache load locks in E state)",
      R"(L1 data cache load locks in E state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_LOCK.HIT",
      EventDef::Encoding{
          .code = 0x42, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache load lock hits)",
      R"(L1 data cache load lock hits)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_LOCK.M_STATE",
      EventDef::Encoding{
          .code = 0x42, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache load locks in M state)",
      R"(L1 data cache load locks in M state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_LOCK.S_STATE",
      EventDef::Encoding{
          .code = 0x42, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache load locks in S state)",
      R"(L1 data cache load locks in S state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_LOCK_FB_HIT",
      EventDef::Encoding{
          .code = 0x53, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L1D load lock accepted in fill buffer)",
      R"(L1D load lock accepted in fill buffer)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_PREFETCH_LOCK_FB_HIT",
      EventDef::Encoding{
          .code = 0x52, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L1D prefetch load lock accepted in fill buffer)",
      R"(L1D prefetch load lock accepted in fill buffer)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_ST.E_STATE",
      EventDef::Encoding{
          .code = 0x41, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache stores in E state)",
      R"(L1 data cache stores in E state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_ST.M_STATE",
      EventDef::Encoding{
          .code = 0x41, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache stores in M state)",
      R"(L1 data cache stores in M state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_CACHE_ST.S_STATE",
      EventDef::Encoding{
          .code = 0x41, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L1 data cache stores in S state)",
      R"(L1 data cache stores in S state)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PREFETCH.MISS",
      EventDef::Encoding{
          .code = 0x4E, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L1D hardware prefetch misses)",
      R"(L1D hardware prefetch misses)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PREFETCH.REQUESTS",
      EventDef::Encoding{
          .code = 0x4E, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L1D hardware prefetch requests)",
      R"(L1D hardware prefetch requests)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_PREFETCH.TRIGGERS",
      EventDef::Encoding{
          .code = 0x4E, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L1D hardware prefetch requests triggered)",
      R"(L1D hardware prefetch requests triggered)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_WB_L2.E_STATE",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L1 writebacks to L2 in E state)",
      R"(L1 writebacks to L2 in E state)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_WB_L2.I_STATE",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L1 writebacks to L2 in I state (misses))",
      R"(L1 writebacks to L2 in I state (misses))",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_WB_L2.M_STATE",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(L1 writebacks to L2 in M state)",
      R"(L1 writebacks to L2 in M state)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_WB_L2.MESI",
      EventDef::Encoding{
          .code = 0x28, .umask = 0xF, .cmask = 0, .msr_values = {0}},
      R"(All L1 writebacks to L2)",
      R"(All L1 writebacks to L2)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1D_WB_L2.S_STATE",
      EventDef::Encoding{
          .code = 0x28, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L1 writebacks to L2 in S state)",
      R"(L1 writebacks to L2 in S state)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1I.CYCLES_STALLED",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L1I instruction fetch stall cycles)",
      R"(L1I instruction fetch stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1I.HITS",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L1I instruction fetch hits)",
      R"(L1I instruction fetch hits)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1I.MISSES",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L1I instruction fetch misses)",
      R"(L1I instruction fetch misses)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L1I.READS",
      EventDef::Encoding{
          .code = 0x80, .umask = 0x3, .cmask = 0, .msr_values = {0}},
      R"(L1I Instruction fetches)",
      R"(L1I Instruction fetches)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DATA_RQSTS.ANY",
      EventDef::Encoding{
          .code = 0x26, .umask = 0xFF, .cmask = 0, .msr_values = {0}},
      R"(All L2 data requests)",
      R"(All L2 data requests)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DATA_RQSTS.DEMAND.E_STATE",
      EventDef::Encoding{
          .code = 0x26, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L2 data demand loads in E state)",
      R"(L2 data demand loads in E state)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DATA_RQSTS.DEMAND.I_STATE",
      EventDef::Encoding{
          .code = 0x26, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L2 data demand loads in I state (misses))",
      R"(L2 data demand loads in I state (misses))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DATA_RQSTS.DEMAND.M_STATE",
      EventDef::Encoding{
          .code = 0x26, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(L2 data demand loads in M state)",
      R"(L2 data demand loads in M state)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DATA_RQSTS.DEMAND.MESI",
      EventDef::Encoding{
          .code = 0x26, .umask = 0xF, .cmask = 0, .msr_values = {0}},
      R"(L2 data demand requests)",
      R"(L2 data demand requests)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DATA_RQSTS.DEMAND.S_STATE",
      EventDef::Encoding{
          .code = 0x26, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L2 data demand loads in S state)",
      R"(L2 data demand loads in S state)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DATA_RQSTS.PREFETCH.E_STATE",
      EventDef::Encoding{
          .code = 0x26, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(L2 data prefetches in E state)",
      R"(L2 data prefetches in E state)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DATA_RQSTS.PREFETCH.I_STATE",
      EventDef::Encoding{
          .code = 0x26, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(L2 data prefetches in the I state (misses))",
      R"(L2 data prefetches in the I state (misses))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DATA_RQSTS.PREFETCH.M_STATE",
      EventDef::Encoding{
          .code = 0x26, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(L2 data prefetches in M state)",
      R"(L2 data prefetches in M state)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DATA_RQSTS.PREFETCH.MESI",
      EventDef::Encoding{
          .code = 0x26, .umask = 0xF0, .cmask = 0, .msr_values = {0}},
      R"(All L2 data prefetches)",
      R"(All L2 data prefetches)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_DATA_RQSTS.PREFETCH.S_STATE",
      EventDef::Encoding{
          .code = 0x26, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(L2 data prefetches in the S state)",
      R"(L2 data prefetches in the S state)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.ANY",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x7, .cmask = 0, .msr_values = {0}},
      R"(L2 lines alloacated)",
      R"(L2 lines alloacated)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.E_STATE",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L2 lines allocated in the E state)",
      R"(L2 lines allocated in the E state)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_IN.S_STATE",
      EventDef::Encoding{
          .code = 0xF1, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L2 lines allocated in the S state)",
      R"(L2 lines allocated in the S state)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.ANY",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0xF, .cmask = 0, .msr_values = {0}},
      R"(L2 lines evicted)",
      R"(L2 lines evicted)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.DEMAND_CLEAN",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L2 lines evicted by a demand request)",
      R"(L2 lines evicted by a demand request)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.DEMAND_DIRTY",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L2 modified lines evicted by a demand request)",
      R"(L2 modified lines evicted by a demand request)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.PREFETCH_CLEAN",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L2 lines evicted by a prefetch request)",
      R"(L2 lines evicted by a prefetch request)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_LINES_OUT.PREFETCH_DIRTY",
      EventDef::Encoding{
          .code = 0xF2, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(L2 modified lines evicted by a prefetch request)",
      R"(L2 modified lines evicted by a prefetch request)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.IFETCH_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(L2 instruction fetch hits)",
      R"(L2 instruction fetch hits)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.IFETCH_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(L2 instruction fetch misses)",
      R"(L2 instruction fetch misses)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.IFETCHES",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x30, .cmask = 0, .msr_values = {0}},
      R"(L2 instruction fetches)",
      R"(L2 instruction fetches)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.LD_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L2 load hits)",
      R"(L2 load hits)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.LD_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L2 load misses)",
      R"(L2 load misses)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.LOADS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x3, .cmask = 0, .msr_values = {0}},
      R"(L2 requests)",
      R"(L2 requests)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xAA, .cmask = 0, .msr_values = {0}},
      R"(All L2 misses)",
      R"(All L2 misses)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.PREFETCH_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(L2 prefetch hits)",
      R"(L2 prefetch hits)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.PREFETCH_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(L2 prefetch misses)",
      R"(L2 prefetch misses)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.PREFETCHES",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xC0, .cmask = 0, .msr_values = {0}},
      R"(All L2 prefetches)",
      R"(All L2 prefetches)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.REFERENCES",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xFF, .cmask = 0, .msr_values = {0}},
      R"(All L2 requests)",
      R"(All L2 requests)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.RFO_HIT",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L2 RFO hits)",
      R"(L2 RFO hits)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.RFO_MISS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(L2 RFO misses)",
      R"(L2 RFO misses)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_RQSTS.RFOS",
      EventDef::Encoding{
          .code = 0x24, .umask = 0xC, .cmask = 0, .msr_values = {0}},
      R"(L2 RFO requests)",
      R"(L2 RFO requests)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANSACTIONS.ANY",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(All L2 transactions)",
      R"(All L2 transactions)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANSACTIONS.FILL",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(L2 fill transactions)",
      R"(L2 fill transactions)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANSACTIONS.IFETCH",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(L2 instruction fetch transactions)",
      R"(L2 instruction fetch transactions)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANSACTIONS.L1D_WB",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(L1D writeback to L2 transactions)",
      R"(L1D writeback to L2 transactions)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANSACTIONS.LOAD",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L2 Load transactions)",
      R"(L2 Load transactions)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANSACTIONS.PREFETCH",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(L2 prefetch transactions)",
      R"(L2 prefetch transactions)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANSACTIONS.RFO",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L2 RFO transactions)",
      R"(L2 RFO transactions)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_TRANSACTIONS.WB",
      EventDef::Encoding{
          .code = 0xF0, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(L2 writeback to LLC transactions)",
      R"(L2 writeback to LLC transactions)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_WRITE.LOCK.E_STATE",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(L2 demand lock RFOs in E state)",
      R"(L2 demand lock RFOs in E state)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_WRITE.LOCK.HIT",
      EventDef::Encoding{
          .code = 0x27, .umask = 0xE0, .cmask = 0, .msr_values = {0}},
      R"(All demand L2 lock RFOs that hit the cache)",
      R"(All demand L2 lock RFOs that hit the cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_WRITE.LOCK.I_STATE",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(L2 demand lock RFOs in I state (misses))",
      R"(L2 demand lock RFOs in I state (misses))",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_WRITE.LOCK.M_STATE",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(L2 demand lock RFOs in M state)",
      R"(L2 demand lock RFOs in M state)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_WRITE.LOCK.MESI",
      EventDef::Encoding{
          .code = 0x27, .umask = 0xF0, .cmask = 0, .msr_values = {0}},
      R"(All demand L2 lock RFOs)",
      R"(All demand L2 lock RFOs)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_WRITE.LOCK.S_STATE",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(L2 demand lock RFOs in S state)",
      R"(L2 demand lock RFOs in S state)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_WRITE.RFO.HIT",
      EventDef::Encoding{
          .code = 0x27, .umask = 0xE, .cmask = 0, .msr_values = {0}},
      R"(All L2 demand store RFOs that hit the cache)",
      R"(All L2 demand store RFOs that hit the cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_WRITE.RFO.I_STATE",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(L2 demand store RFOs in I state (misses))",
      R"(L2 demand store RFOs in I state (misses))",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_WRITE.RFO.M_STATE",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(L2 demand store RFOs in M state)",
      R"(L2 demand store RFOs in M state)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_WRITE.RFO.MESI",
      EventDef::Encoding{
          .code = 0x27, .umask = 0xF, .cmask = 0, .msr_values = {0}},
      R"(All L2 demand store RFOs)",
      R"(All L2 demand store RFOs)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "L2_WRITE.RFO.S_STATE",
      EventDef::Encoding{
          .code = 0x27, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(L2 demand store RFOs in S state)",
      R"(L2 demand store RFOs in S state)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LARGE_ITLB.HIT",
      EventDef::Encoding{
          .code = 0x82, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Large ITLB hit)",
      R"(Large ITLB hit)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_DISPATCH.ANY",
      EventDef::Encoding{
          .code = 0x13, .umask = 0x7, .cmask = 0, .msr_values = {0}},
      R"(All loads dispatched)",
      R"(All loads dispatched)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_DISPATCH.MOB",
      EventDef::Encoding{
          .code = 0x13, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Loads dispatched from the MOB)",
      R"(Loads dispatched from the MOB)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_DISPATCH.RS",
      EventDef::Encoding{
          .code = 0x13, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Loads dispatched that bypass the MOB)",
      R"(Loads dispatched that bypass the MOB)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_DISPATCH.RS_DELAYED",
      EventDef::Encoding{
          .code = 0x13, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Loads dispatched from stage 305)",
      R"(Loads dispatched from stage 305)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LOAD_HIT_PRE",
      EventDef::Encoding{
          .code = 0x4C, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Load operations conflicting with software prefetches)",
      R"(Load operations conflicting with software prefetches)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.MISS",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x41, .cmask = 0, .msr_values = {0}},
      R"(Longest latency cache miss)",
      R"(Longest latency cache miss)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LONGEST_LAT_CACHE.REFERENCE",
      EventDef::Encoding{
          .code = 0x2E, .umask = 0x4F, .cmask = 0, .msr_values = {0}},
      R"(Longest latency cache reference)",
      R"(Longest latency cache reference)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD.ACTIVE",
      EventDef::Encoding{
          .code = 0xA8, .umask = 0x1, .cmask = 1, .msr_values = {0}},
      R"(Cycles when uops were delivered by the LSD)",
      R"(Cycles when uops were delivered by the LSD)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD.INACTIVE",
      EventDef::Encoding{
          .code = 0xA8,
          .umask = 0x1,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles no uops were delivered by the LSD)",
      R"(Cycles no uops were delivered by the LSD)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "LSD_OVERFLOW",
      EventDef::Encoding{
          .code = 0x20, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Loops that can't stream from the instruction queue)",
      R"(Loops that can't stream from the instruction queue)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.CYCLES",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Cycles machine clear asserted)",
      R"(Cycles machine clear asserted)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.MEM_ORDER",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Execution pipeline restart due to Memory ordering conflicts)",
      R"(Execution pipeline restart due to Memory ordering conflicts)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACHINE_CLEARS.SMC",
      EventDef::Encoding{
          .code = 0xC3, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Self-Modifying Code detected)",
      R"(Self-Modifying Code detected)",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACRO_INSTS.DECODED",
      EventDef::Encoding{
          .code = 0xD0, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Instructions decoded)",
      R"(Instructions decoded)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MACRO_INSTS.FUSIONS_DECODED",
      EventDef::Encoding{
          .code = 0xA6, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Macro-fused instructions decoded)",
      R"(Macro-fused instructions decoded)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LOADS",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Instructions retired which contains a load (Precise Event))",
      R"(Instructions retired which contains a load (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.STORES",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Instructions retired which contains a store (Precise Event))",
      R"(Instructions retired which contains a store (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.DTLB_MISS",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Retired loads that miss the DTLB (Precise Event))",
      R"(Retired loads that miss the DTLB (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.HIT_LFB",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Retired loads that miss L1D and hit an previously allocated LFB (Precise Event))",
      R"(Retired loads that miss L1D and hit an previously allocated LFB (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L1D_HIT",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Retired loads that hit the L1 data cache (Precise Event))",
      R"(Retired loads that hit the L1 data cache (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.L2_HIT",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Retired loads that hit the L2 cache (Precise Event))",
      R"(Retired loads that hit the L2 cache (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.LLC_MISS",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Retired loads that miss the LLC cache (Precise Event))",
      R"(Retired loads that miss the LLC cache (Precise Event))",
      10000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.LLC_UNSHARED_HIT",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Retired loads that hit valid versions in the LLC cache (Precise Event))",
      R"(Retired loads that hit valid versions in the LLC cache (Precise Event))",
      40000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_LOAD_RETIRED.OTHER_CORE_L2_HIT_HITM",
      EventDef::Encoding{
          .code = 0xCB, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(Retired loads that hit sibling core's L2 in modified or unmodified states (Precise Event))",
      R"(Retired loads that hit sibling core's L2 in modified or unmodified states (Precise Event))",
      40000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_STORE_RETIRED.DTLB_MISS",
      EventDef::Encoding{
          .code = 0xC, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Retired stores that miss the DTLB (Precise Event))",
      R"(Retired stores that miss the DTLB (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS.L1D_WRITEBACK",
      EventDef::Encoding{
          .code = 0xB0, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Offcore L1 data cache writebacks)",
      R"(Offcore L1 data cache writebacks)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_REQUESTS_SQ_FULL",
      EventDef::Encoding{
          .code = 0xB2, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Offcore requests blocked due to Super Queue full)",
      R"(Offcore requests blocked due to Super Queue full)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "PARTIAL_ADDRESS_ALIAS",
      EventDef::Encoding{
          .code = 0x7, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(False dependencies due to partial address aliasing)",
      R"(False dependencies due to partial address aliasing)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RAT_STALLS.ANY",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0xF, .cmask = 0, .msr_values = {0}},
      R"(All RAT stall cycles)",
      R"(All RAT stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RAT_STALLS.FLAGS",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Flag stall cycles)",
      R"(Flag stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RAT_STALLS.REGISTERS",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Partial register stall cycles)",
      R"(Partial register stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RAT_STALLS.ROB_READ_PORT",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(ROB read port stalls cycles)",
      R"(ROB read port stalls cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RAT_STALLS.SCOREBOARD",
      EventDef::Encoding{
          .code = 0xD2, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(Scoreboard stall cycles)",
      R"(Scoreboard stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.ANY",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Resource related stall cycles)",
      R"(Resource related stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.FPCW",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(FPU control word write stall cycles)",
      R"(FPU control word write stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.LOAD",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Load buffer stall cycles)",
      R"(Load buffer stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.MXCSR",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(MXCSR rename stall cycles)",
      R"(MXCSR rename stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.OTHER",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x80, .cmask = 0, .msr_values = {0}},
      R"(Other Resource related stall cycles)",
      R"(Other Resource related stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.ROB_FULL",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(ROB full stall cycles)",
      R"(ROB full stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.RS_FULL",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Reservation Station full stall cycles)",
      R"(Reservation Station full stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "RESOURCE_STALLS.STORE",
      EventDef::Encoding{
          .code = 0xA2, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(Store buffer stall cycles)",
      R"(Store buffer stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SB_DRAIN.ANY",
      EventDef::Encoding{
          .code = 0x4, .umask = 0x7, .cmask = 0, .msr_values = {0}},
      R"(All Store buffer stall cycles)",
      R"(All Store buffer stall cycles)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SEG_RENAME_STALLS",
      EventDef::Encoding{
          .code = 0xD4, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Segment rename stall cycles)",
      R"(Segment rename stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_128.PACK",
      EventDef::Encoding{
          .code = 0x12, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(128 bit SIMD integer pack operations)",
      R"(128 bit SIMD integer pack operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_128.PACKED_ARITH",
      EventDef::Encoding{
          .code = 0x12, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(128 bit SIMD integer arithmetic operations)",
      R"(128 bit SIMD integer arithmetic operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_128.PACKED_LOGICAL",
      EventDef::Encoding{
          .code = 0x12, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(128 bit SIMD integer logical operations)",
      R"(128 bit SIMD integer logical operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_128.PACKED_MPY",
      EventDef::Encoding{
          .code = 0x12, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(128 bit SIMD integer multiply operations)",
      R"(128 bit SIMD integer multiply operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_128.PACKED_SHIFT",
      EventDef::Encoding{
          .code = 0x12, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(128 bit SIMD integer shift operations)",
      R"(128 bit SIMD integer shift operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_128.SHUFFLE_MOVE",
      EventDef::Encoding{
          .code = 0x12, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(128 bit SIMD integer shuffle/move operations)",
      R"(128 bit SIMD integer shuffle/move operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_128.UNPACK",
      EventDef::Encoding{
          .code = 0x12, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(128 bit SIMD integer unpack operations)",
      R"(128 bit SIMD integer unpack operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_64.PACK",
      EventDef::Encoding{
          .code = 0xFD, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(SIMD integer 64 bit pack operations)",
      R"(SIMD integer 64 bit pack operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_64.PACKED_ARITH",
      EventDef::Encoding{
          .code = 0xFD, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(SIMD integer 64 bit arithmetic operations)",
      R"(SIMD integer 64 bit arithmetic operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_64.PACKED_LOGICAL",
      EventDef::Encoding{
          .code = 0xFD, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(SIMD integer 64 bit logical operations)",
      R"(SIMD integer 64 bit logical operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_64.PACKED_MPY",
      EventDef::Encoding{
          .code = 0xFD, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(SIMD integer 64 bit packed multiply operations)",
      R"(SIMD integer 64 bit packed multiply operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_64.PACKED_SHIFT",
      EventDef::Encoding{
          .code = 0xFD, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(SIMD integer 64 bit shift operations)",
      R"(SIMD integer 64 bit shift operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_64.SHUFFLE_MOVE",
      EventDef::Encoding{
          .code = 0xFD, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(SIMD integer 64 bit shuffle/move operations)",
      R"(SIMD integer 64 bit shuffle/move operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SIMD_INT_64.UNPACK",
      EventDef::Encoding{
          .code = 0xFD, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(SIMD integer 64 bit unpack operations)",
      R"(SIMD integer 64 bit unpack operations)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SNOOP_RESPONSE.HIT",
      EventDef::Encoding{
          .code = 0xB8, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Thread responded HIT to snoop)",
      R"(Thread responded HIT to snoop)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SNOOP_RESPONSE.HITE",
      EventDef::Encoding{
          .code = 0xB8, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Thread responded HITE to snoop)",
      R"(Thread responded HITE to snoop)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SNOOP_RESPONSE.HITM",
      EventDef::Encoding{
          .code = 0xB8, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Thread responded HITM to snoop)",
      R"(Thread responded HITM to snoop)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SQ_FULL_STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xF6, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Super Queue full stall cycles)",
      R"(Super Queue full stall cycles)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SQ_MISC.SPLIT_LOCK",
      EventDef::Encoding{
          .code = 0xF4, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(Super Queue lock splits across a cache line)",
      R"(Super Queue lock splits across a cache line)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SSEX_UOPS_RETIRED.PACKED_DOUBLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(SIMD Packed-Double Uops retired (Precise Event))",
      R"(SIMD Packed-Double Uops retired (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SSEX_UOPS_RETIRED.PACKED_SINGLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(SIMD Packed-Single Uops retired (Precise Event))",
      R"(SIMD Packed-Single Uops retired (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SSEX_UOPS_RETIRED.SCALAR_DOUBLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(SIMD Scalar-Double Uops retired (Precise Event))",
      R"(SIMD Scalar-Double Uops retired (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SSEX_UOPS_RETIRED.SCALAR_SINGLE",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(SIMD Scalar-Single Uops retired (Precise Event))",
      R"(SIMD Scalar-Single Uops retired (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "SSEX_UOPS_RETIRED.VECTOR_INTEGER",
      EventDef::Encoding{
          .code = 0xC7, .umask = 0x10, .cmask = 0, .msr_values = {0}},
      R"(SIMD Vector Integer Uops retired (Precise Event))",
      R"(SIMD Vector Integer Uops retired (Precise Event))",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "STORE_BLOCKS.AT_RET",
      EventDef::Encoding{
          .code = 0x6, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Loads delayed with at-Retirement block code)",
      R"(Loads delayed with at-Retirement block code)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "STORE_BLOCKS.L1D_BLOCK",
      EventDef::Encoding{
          .code = 0x6, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(Cacheable loads delayed with L1D block code)",
      R"(Cacheable loads delayed with L1D block code)",
      200000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "TWO_UOP_INSTS_DECODED",
      EventDef::Encoding{
          .code = 0x19, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Two Uop instructions decoded)",
      R"(Two Uop instructions decoded)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOP_UNFUSION",
      EventDef::Encoding{
          .code = 0xDB, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Uop unfusions due to FP exceptions)",
      R"(Uop unfusions due to FP exceptions)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DECODED.ESP_FOLDING",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Stack pointer instructions decoded)",
      R"(Stack pointer instructions decoded)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DECODED.ESP_SYNC",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x8, .cmask = 0, .msr_values = {0}},
      R"(Stack pointer sync operations)",
      R"(Stack pointer sync operations)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DECODED.MS_CYCLES_ACTIVE",
      EventDef::Encoding{
          .code = 0xD1, .umask = 0x2, .cmask = 1, .msr_values = {0}},
      R"(Uops decoded by Microcode Sequencer)",
      R"(Uops decoded by Microcode Sequencer)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_DECODED.STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xD1,
          .umask = 0x1,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles no Uops are decoded)",
      R"(Cycles no Uops are decoded)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_ACTIVE_CYCLES",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x3F,
          .any = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles Uops executed on any port (core count))",
      R"(Cycles Uops executed on any port (core count))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_ACTIVE_CYCLES_NO_PORT5",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x1F,
          .any = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles Uops executed on ports 0-4 (core count))",
      R"(Cycles Uops executed on ports 0-4 (core count))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_STALL_COUNT",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x3F,
          .edge = true,
          .any = true,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Uops executed on any port (core count))",
      R"(Uops executed on any port (core count))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_STALL_COUNT_NO_PORT5",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x1F,
          .edge = true,
          .any = true,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Uops executed on ports 0-4 (core count))",
      R"(Uops executed on ports 0-4 (core count))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x3F,
          .any = true,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles no Uops issued on any port (core count))",
      R"(Cycles no Uops issued on any port (core count))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.CORE_STALL_CYCLES_NO_PORT5",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x1F,
          .any = true,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles no Uops issued on ports 0-4 (core count))",
      R"(Cycles no Uops issued on ports 0-4 (core count))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.PORT0",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Uops executed on port 0)",
      R"(Uops executed on port 0)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.PORT015",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x40, .cmask = 0, .msr_values = {0}},
      R"(Uops issued on ports 0, 1 or 5)",
      R"(Uops issued on ports 0, 1 or 5)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.PORT015_STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x40,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles no Uops issued on ports 0, 1 or 5)",
      R"(Cycles no Uops issued on ports 0, 1 or 5)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.PORT1",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Uops executed on port 1)",
      R"(Uops executed on port 1)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.PORT2_CORE",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x4,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Uops executed on port 2 (core count))",
      R"(Uops executed on port 2 (core count))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.PORT234_CORE",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x80,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Uops issued on ports 2, 3 or 4)",
      R"(Uops issued on ports 2, 3 or 4)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.PORT3_CORE",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x8,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Uops executed on port 3 (core count))",
      R"(Uops executed on port 3 (core count))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.PORT4_CORE",
      EventDef::Encoding{
          .code = 0xB1,
          .umask = 0x10,
          .any = true,
          .cmask = 0,
          .msr_values = {0}},
      R"(Uops executed on port 4 (core count))",
      R"(Uops executed on port 4 (core count))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_EXECUTED.PORT5",
      EventDef::Encoding{
          .code = 0xB1, .umask = 0x20, .cmask = 0, .msr_values = {0}},
      R"(Uops executed on port 5)",
      R"(Uops executed on port 5)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.ANY",
      EventDef::Encoding{
          .code = 0xE, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Uops issued)",
      R"(Uops issued)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.CORE_STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xE,
          .umask = 0x1,
          .any = true,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles no Uops were issued on any thread)",
      R"(Cycles no Uops were issued on any thread)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.CYCLES_ALL_THREADS",
      EventDef::Encoding{
          .code = 0xE,
          .umask = 0x1,
          .any = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles Uops were issued on either thread)",
      R"(Cycles Uops were issued on either thread)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.FUSED",
      EventDef::Encoding{
          .code = 0xE, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Fused Uops issued)",
      R"(Fused Uops issued)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_ISSUED.STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xE,
          .umask = 0x1,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles no Uops were issued)",
      R"(Cycles no Uops were issued)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.ACTIVE_CYCLES",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x1, .cmask = 1, .msr_values = {0}},
      R"(Cycles Uops are being retired)",
      R"(Cycles Uops are being retired)",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.ANY",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x1, .cmask = 0, .msr_values = {0}},
      R"(Uops retired (Precise Event))",
      R"(Uops retired (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.MACRO_FUSED",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x4, .cmask = 0, .msr_values = {0}},
      R"(Macro-fused Uops retired (Precise Event))",
      R"(Macro-fused Uops retired (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.RETIRE_SLOTS",
      EventDef::Encoding{
          .code = 0xC2, .umask = 0x2, .cmask = 0, .msr_values = {0}},
      R"(Retirement slots used (Precise Event))",
      R"(Retirement slots used (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.STALL_CYCLES",
      EventDef::Encoding{
          .code = 0xC2,
          .umask = 0x1,
          .inv = true,
          .cmask = 1,
          .msr_values = {0}},
      R"(Cycles Uops are not retiring (Precise Event))",
      R"(Cycles Uops are not retiring (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "UOPS_RETIRED.TOTAL_CYCLES",
      EventDef::Encoding{
          .code = 0xC2,
          .umask = 0x1,
          .inv = true,
          .cmask = 16,
          .msr_values = {0}},
      R"(Total cycles using precise uop retired event (Precise Event))",
      R"(Total cycles using precise uop retired event (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 1},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "INST_RETIRED.TOTAL_CYCLES_PS",
      EventDef::Encoding{
          .code = 0xC0,
          .umask = 0x1,
          .inv = true,
          .cmask = 16,
          .msr_values = {0}},
      R"(Total cycles (Precise Event))",
      R"(Total cycles (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_0",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x0}},
      R"(Memory instructions retired above 0 clocks (Precise Event))",
      R"(Memory instructions retired above 0 clocks (Precise Event))",
      2000000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_1024",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x400}},
      R"(Memory instructions retired above 1024 clocks (Precise Event))",
      R"(Memory instructions retired above 1024 clocks (Precise Event))",
      100,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_128",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x80}},
      R"(Memory instructions retired above 128 clocks (Precise Event))",
      R"(Memory instructions retired above 128 clocks (Precise Event))",
      1000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_16",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x10}},
      R"(Memory instructions retired above 16 clocks (Precise Event))",
      R"(Memory instructions retired above 16 clocks (Precise Event))",
      10000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_16384",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x4000}},
      R"(Memory instructions retired above 16384 clocks (Precise Event))",
      R"(Memory instructions retired above 16384 clocks (Precise Event))",
      5,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_2048",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x800}},
      R"(Memory instructions retired above 2048 clocks (Precise Event))",
      R"(Memory instructions retired above 2048 clocks (Precise Event))",
      50,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_256",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x100}},
      R"(Memory instructions retired above 256 clocks (Precise Event))",
      R"(Memory instructions retired above 256 clocks (Precise Event))",
      500,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_32",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x20}},
      R"(Memory instructions retired above 32 clocks (Precise Event))",
      R"(Memory instructions retired above 32 clocks (Precise Event))",
      5000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_32768",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x8000}},
      R"(Memory instructions retired above 32768 clocks (Precise Event))",
      R"(Memory instructions retired above 32768 clocks (Precise Event))",
      3,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_4",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x4}},
      R"(Memory instructions retired above 4 clocks (Precise Event))",
      R"(Memory instructions retired above 4 clocks (Precise Event))",
      50000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_4096",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x1000}},
      R"(Memory instructions retired above 4096 clocks (Precise Event))",
      R"(Memory instructions retired above 4096 clocks (Precise Event))",
      20,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_512",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x200}},
      R"(Memory instructions retired above 512 clocks (Precise Event))",
      R"(Memory instructions retired above 512 clocks (Precise Event))",
      200,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_64",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x40}},
      R"(Memory instructions retired above 64 clocks (Precise Event))",
      R"(Memory instructions retired above 64 clocks (Precise Event))",
      2000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_8",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x8}},
      R"(Memory instructions retired above 8 clocks (Precise Event))",
      R"(Memory instructions retired above 8 clocks (Precise Event))",
      20000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "MEM_INST_RETIRED.LATENCY_ABOVE_THRESHOLD_8192",
      EventDef::Encoding{
          .code = 0xB, .umask = 0x10, .cmask = 0, .msr_values = {0x2000}},
      R"(Memory instructions retired above 8192 clocks (Precise Event))",
      R"(Memory instructions retired above 8192 clocks (Precise Event))",
      10,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{.pebs = 2},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F11}},
      R"(Offcore data reads satisfied by any cache or DRAM)",
      R"(Offcore data reads satisfied by any cache or DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6011}},
      R"(Offcore data reads satisfied by any DRAM)",
      R"(Offcore data reads satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF811}},
      R"(Offcore data reads that missed the LLC)",
      R"(Offcore data reads that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF11}},
      R"(All offcore data reads)",
      R"(All offcore data reads)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8011}},
      R"(Offcore data reads satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore data reads satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x111}},
      R"(Offcore data reads satisfied by the LLC and not found in a sibling core)",
      R"(Offcore data reads satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x211}},
      R"(Offcore data reads satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore data reads satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x411}},
      R"(Offcore data reads satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore data reads satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x711}},
      R"(Offcore data reads satisfied by the LLC)",
      R"(Offcore data reads satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4711}},
      R"(Offcore data reads satisfied by the LLC or local DRAM)",
      R"(Offcore data reads satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4011}},
      R"(Offcore data reads satisfied by the local DRAM)",
      R"(Offcore data reads satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1811}},
      R"(Offcore data reads satisfied by a remote cache)",
      R"(Offcore data reads satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3811}},
      R"(Offcore data reads satisfied by a remote cache or remote DRAM)",
      R"(Offcore data reads satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1011}},
      R"(Offcore data reads that HIT in a remote cache)",
      R"(Offcore data reads that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x811}},
      R"(Offcore data reads that HITM in a remote cache)",
      R"(Offcore data reads that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_DATA.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2011}},
      R"(Offcore data reads satisfied by a remote DRAM)",
      R"(Offcore data reads satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F44}},
      R"(Offcore code reads satisfied by any cache or DRAM)",
      R"(Offcore code reads satisfied by any cache or DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6044}},
      R"(Offcore code reads satisfied by any DRAM)",
      R"(Offcore code reads satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF844}},
      R"(Offcore code reads that missed the LLC)",
      R"(Offcore code reads that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF44}},
      R"(All offcore code reads)",
      R"(All offcore code reads)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8044}},
      R"(Offcore code reads satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore code reads satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x144}},
      R"(Offcore code reads satisfied by the LLC and not found in a sibling core)",
      R"(Offcore code reads satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x244}},
      R"(Offcore code reads satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore code reads satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x444}},
      R"(Offcore code reads satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore code reads satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x744}},
      R"(Offcore code reads satisfied by the LLC)",
      R"(Offcore code reads satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4744}},
      R"(Offcore code reads satisfied by the LLC or local DRAM)",
      R"(Offcore code reads satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4044}},
      R"(Offcore code reads satisfied by the local DRAM)",
      R"(Offcore code reads satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1844}},
      R"(Offcore code reads satisfied by a remote cache)",
      R"(Offcore code reads satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3844}},
      R"(Offcore code reads satisfied by a remote cache or remote DRAM)",
      R"(Offcore code reads satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1044}},
      R"(Offcore code reads that HIT in a remote cache)",
      R"(Offcore code reads that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x844}},
      R"(Offcore code reads that HITM in a remote cache)",
      R"(Offcore code reads that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_IFETCH.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2044}},
      R"(Offcore code reads satisfied by a remote DRAM)",
      R"(Offcore code reads satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7FFF}},
      R"(Offcore requests satisfied by any cache or DRAM)",
      R"(Offcore requests satisfied by any cache or DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x60FF}},
      R"(Offcore requests satisfied by any DRAM)",
      R"(Offcore requests satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF8FF}},
      R"(Offcore requests that missed the LLC)",
      R"(Offcore requests that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFFFF}},
      R"(All offcore requests)",
      R"(All offcore requests)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x80FF}},
      R"(Offcore requests satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore requests satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1FF}},
      R"(Offcore requests satisfied by the LLC and not found in a sibling core)",
      R"(Offcore requests satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2FF}},
      R"(Offcore requests satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore requests satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4FF}},
      R"(Offcore requests satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore requests satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7FF}},
      R"(Offcore requests satisfied by the LLC)",
      R"(Offcore requests satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x47FF}},
      R"(Offcore requests satisfied by the LLC or local DRAM)",
      R"(Offcore requests satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x40FF}},
      R"(Offcore requests satisfied by the local DRAM)",
      R"(Offcore requests satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x18FF}},
      R"(Offcore requests satisfied by a remote cache)",
      R"(Offcore requests satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x38FF}},
      R"(Offcore requests satisfied by a remote cache or remote DRAM)",
      R"(Offcore requests satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x10FF}},
      R"(Offcore requests that HIT in a remote cache)",
      R"(Offcore requests that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8FF}},
      R"(Offcore requests that HITM in a remote cache)",
      R"(Offcore requests that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_REQUEST.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x20FF}},
      R"(Offcore requests satisfied by a remote DRAM)",
      R"(Offcore requests satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F22}},
      R"(Offcore RFO requests satisfied by any cache or DRAM)",
      R"(Offcore RFO requests satisfied by any cache or DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6022}},
      R"(Offcore RFO requests satisfied by any DRAM)",
      R"(Offcore RFO requests satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF822}},
      R"(Offcore RFO requests that missed the LLC)",
      R"(Offcore RFO requests that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF22}},
      R"(All offcore RFO requests)",
      R"(All offcore RFO requests)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8022}},
      R"(Offcore RFO requests satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore RFO requests satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x122}},
      R"(Offcore RFO requests satisfied by the LLC and not found in a sibling core)",
      R"(Offcore RFO requests satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x222}},
      R"(Offcore RFO requests satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore RFO requests satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x422}},
      R"(Offcore RFO requests satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore RFO requests satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x722}},
      R"(Offcore RFO requests satisfied by the LLC)",
      R"(Offcore RFO requests satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4722}},
      R"(Offcore RFO requests satisfied by the LLC or local DRAM)",
      R"(Offcore RFO requests satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4022}},
      R"(Offcore RFO requests satisfied by the local DRAM)",
      R"(Offcore RFO requests satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1822}},
      R"(Offcore RFO requests satisfied by a remote cache)",
      R"(Offcore RFO requests satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3822}},
      R"(Offcore RFO requests satisfied by a remote cache or remote DRAM)",
      R"(Offcore RFO requests satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1022}},
      R"(Offcore RFO requests that HIT in a remote cache)",
      R"(Offcore RFO requests that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x822}},
      R"(Offcore RFO requests that HITM in a remote cache)",
      R"(Offcore RFO requests that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.ANY_RFO.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2022}},
      R"(Offcore RFO requests satisfied by a remote DRAM)",
      R"(Offcore RFO requests satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F08}},
      R"(Offcore writebacks to any cache or DRAM.)",
      R"(Offcore writebacks to any cache or DRAM.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6008}},
      R"(Offcore writebacks to any DRAM)",
      R"(Offcore writebacks to any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF808}},
      R"(Offcore writebacks that missed the LLC)",
      R"(Offcore writebacks that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF08}},
      R"(All offcore writebacks)",
      R"(All offcore writebacks)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8008}},
      R"(Offcore writebacks to the IO, CSR, MMIO unit.)",
      R"(Offcore writebacks to the IO, CSR, MMIO unit.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x108}},
      R"(Offcore writebacks to the LLC and not found in a sibling core)",
      R"(Offcore writebacks to the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x408}},
      R"(Offcore writebacks to the LLC  and HITM in a sibling core)",
      R"(Offcore writebacks to the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x708}},
      R"(Offcore writebacks to the LLC)",
      R"(Offcore writebacks to the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4708}},
      R"(Offcore writebacks to the LLC or local DRAM)",
      R"(Offcore writebacks to the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4008}},
      R"(Offcore writebacks to the local DRAM)",
      R"(Offcore writebacks to the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1808}},
      R"(Offcore writebacks to a remote cache)",
      R"(Offcore writebacks to a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3808}},
      R"(Offcore writebacks to a remote cache or remote DRAM)",
      R"(Offcore writebacks to a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1008}},
      R"(Offcore writebacks that HIT in a remote cache)",
      R"(Offcore writebacks that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x808}},
      R"(Offcore writebacks that HITM in a remote cache)",
      R"(Offcore writebacks that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.COREWB.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2008}},
      R"(Offcore writebacks to a remote DRAM)",
      R"(Offcore writebacks to a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F77}},
      R"(Offcore code or data read requests satisfied by any cache or DRAM.)",
      R"(Offcore code or data read requests satisfied by any cache or DRAM.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6077}},
      R"(Offcore code or data read requests satisfied by any DRAM)",
      R"(Offcore code or data read requests satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF877}},
      R"(Offcore code or data read requests that missed the LLC)",
      R"(Offcore code or data read requests that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF77}},
      R"(All offcore code or data read requests)",
      R"(All offcore code or data read requests)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8077}},
      R"(Offcore code or data read requests satisfied by the IO, CSR, MMIO unit.)",
      R"(Offcore code or data read requests satisfied by the IO, CSR, MMIO unit.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x177}},
      R"(Offcore code or data read requests satisfied by the LLC and not found in a sibling core)",
      R"(Offcore code or data read requests satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x277}},
      R"(Offcore code or data read requests satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore code or data read requests satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x477}},
      R"(Offcore code or data read requests satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore code or data read requests satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x777}},
      R"(Offcore code or data read requests satisfied by the LLC)",
      R"(Offcore code or data read requests satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4777}},
      R"(Offcore code or data read requests satisfied by the LLC or local DRAM)",
      R"(Offcore code or data read requests satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4077}},
      R"(Offcore code or data read requests satisfied by the local DRAM)",
      R"(Offcore code or data read requests satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1877}},
      R"(Offcore code or data read requests satisfied by a remote cache)",
      R"(Offcore code or data read requests satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3877}},
      R"(Offcore code or data read requests satisfied by a remote cache or remote DRAM)",
      R"(Offcore code or data read requests satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1077}},
      R"(Offcore code or data read requests that HIT in a remote cache)",
      R"(Offcore code or data read requests that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x877}},
      R"(Offcore code or data read requests that HITM in a remote cache)",
      R"(Offcore code or data read requests that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IFETCH.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2077}},
      R"(Offcore code or data read requests satisfied by a remote DRAM)",
      R"(Offcore code or data read requests satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F33}},
      R"(Offcore request = all data, response = any cache_dram)",
      R"(Offcore request = all data, response = any cache_dram)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6033}},
      R"(Offcore request = all data, response = any DRAM)",
      R"(Offcore request = all data, response = any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF833}},
      R"(Offcore request = all data, response = any LLC miss)",
      R"(Offcore request = all data, response = any LLC miss)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF33}},
      R"(Offcore request = all data, response = any location)",
      R"(Offcore request = all data, response = any location)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8033}},
      R"(Offcore data reads, RFOs, and prefetches satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore data reads, RFOs, and prefetches satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x133}},
      R"(Offcore data reads, RFOs, and prefetches satisfied by the LLC and not found in a sibling core)",
      R"(Offcore data reads, RFOs, and prefetches satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x233}},
      R"(Offcore data reads, RFOs, and prefetches satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore data reads, RFOs, and prefetches satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x433}},
      R"(Offcore data reads, RFOs, and prefetches satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore data reads, RFOs, and prefetches satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x733}},
      R"(Offcore request = all data, response = local cache)",
      R"(Offcore request = all data, response = local cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4733}},
      R"(Offcore request = all data, response = local cache or dram)",
      R"(Offcore request = all data, response = local cache or dram)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4033}},
      R"(Offcore data reads, RFOs, and prefetches satisfied by the local DRAM.)",
      R"(Offcore data reads, RFOs, and prefetches satisfied by the local DRAM.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1833}},
      R"(Offcore request = all data, response = remote cache)",
      R"(Offcore request = all data, response = remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3833}},
      R"(Offcore request = all data, response = remote cache or dram)",
      R"(Offcore request = all data, response = remote cache or dram)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1033}},
      R"(Offcore data reads, RFOs, and prefetches that HIT in a remote cache )",
      R"(Offcore data reads, RFOs, and prefetches that HIT in a remote cache )",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x833}},
      R"(Offcore data reads, RFOs, and prefetches that HITM in a remote cache)",
      R"(Offcore data reads, RFOs, and prefetches that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DATA_IN.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2033}},
      R"(Offcore data reads, RFOs, and prefetches satisfied by the remote DRAM)",
      R"(Offcore data reads, RFOs, and prefetches satisfied by the remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F03}},
      R"(Offcore demand data requests satisfied by any cache or DRAM)",
      R"(Offcore demand data requests satisfied by any cache or DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6003}},
      R"(Offcore demand data requests satisfied by any DRAM)",
      R"(Offcore demand data requests satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF803}},
      R"(Offcore demand data requests that missed the LLC)",
      R"(Offcore demand data requests that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF03}},
      R"(All offcore demand data requests)",
      R"(All offcore demand data requests)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8003}},
      R"(Offcore demand data requests satisfied by the IO, CSR, MMIO unit.)",
      R"(Offcore demand data requests satisfied by the IO, CSR, MMIO unit.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x103}},
      R"(Offcore demand data requests satisfied by the LLC and not found in a sibling core)",
      R"(Offcore demand data requests satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x203}},
      R"(Offcore demand data requests satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore demand data requests satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x403}},
      R"(Offcore demand data requests satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore demand data requests satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x703}},
      R"(Offcore demand data requests satisfied by the LLC)",
      R"(Offcore demand data requests satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4703}},
      R"(Offcore demand data requests satisfied by the LLC or local DRAM)",
      R"(Offcore demand data requests satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4003}},
      R"(Offcore demand data requests satisfied by the local DRAM)",
      R"(Offcore demand data requests satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1803}},
      R"(Offcore demand data requests satisfied by a remote cache)",
      R"(Offcore demand data requests satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3803}},
      R"(Offcore demand data requests satisfied by a remote cache or remote DRAM)",
      R"(Offcore demand data requests satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1003}},
      R"(Offcore demand data requests that HIT in a remote cache)",
      R"(Offcore demand data requests that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x803}},
      R"(Offcore demand data requests that HITM in a remote cache)",
      R"(Offcore demand data requests that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2003}},
      R"(Offcore demand data requests satisfied by a remote DRAM)",
      R"(Offcore demand data requests satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F01}},
      R"(Offcore demand data reads satisfied by any cache or DRAM.)",
      R"(Offcore demand data reads satisfied by any cache or DRAM.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6001}},
      R"(Offcore demand data reads satisfied by any DRAM)",
      R"(Offcore demand data reads satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF801}},
      R"(Offcore demand data reads that missed the LLC)",
      R"(Offcore demand data reads that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF01}},
      R"(All offcore demand data reads)",
      R"(All offcore demand data reads)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8001}},
      R"(Offcore demand data reads satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore demand data reads satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x101}},
      R"(Offcore demand data reads satisfied by the LLC and not found in a sibling core)",
      R"(Offcore demand data reads satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x201}},
      R"(Offcore demand data reads satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore demand data reads satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x401}},
      R"(Offcore demand data reads satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore demand data reads satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x701}},
      R"(Offcore demand data reads satisfied by the LLC)",
      R"(Offcore demand data reads satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4701}},
      R"(Offcore demand data reads satisfied by the LLC or local DRAM)",
      R"(Offcore demand data reads satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4001}},
      R"(Offcore demand data reads satisfied by the local DRAM)",
      R"(Offcore demand data reads satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1801}},
      R"(Offcore demand data reads satisfied by a remote cache)",
      R"(Offcore demand data reads satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3801}},
      R"(Offcore demand data reads satisfied by a remote cache or remote DRAM)",
      R"(Offcore demand data reads satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1001}},
      R"(Offcore demand data reads that HIT in a remote cache)",
      R"(Offcore demand data reads that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x801}},
      R"(Offcore demand data reads that HITM in a remote cache)",
      R"(Offcore demand data reads that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_DATA_RD.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2001}},
      R"(Offcore demand data reads satisfied by a remote DRAM)",
      R"(Offcore demand data reads satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F04}},
      R"(Offcore demand code reads satisfied by any cache or DRAM.)",
      R"(Offcore demand code reads satisfied by any cache or DRAM.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6004}},
      R"(Offcore demand code reads satisfied by any DRAM)",
      R"(Offcore demand code reads satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF804}},
      R"(Offcore demand code reads that missed the LLC)",
      R"(Offcore demand code reads that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF04}},
      R"(All offcore demand code reads)",
      R"(All offcore demand code reads)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8004}},
      R"(Offcore demand code reads satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore demand code reads satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x104}},
      R"(Offcore demand code reads satisfied by the LLC and not found in a sibling core)",
      R"(Offcore demand code reads satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x204}},
      R"(Offcore demand code reads satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore demand code reads satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x404}},
      R"(Offcore demand code reads satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore demand code reads satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x704}},
      R"(Offcore demand code reads satisfied by the LLC)",
      R"(Offcore demand code reads satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4704}},
      R"(Offcore demand code reads satisfied by the LLC or local DRAM)",
      R"(Offcore demand code reads satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4004}},
      R"(Offcore demand code reads satisfied by the local DRAM)",
      R"(Offcore demand code reads satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1804}},
      R"(Offcore demand code reads satisfied by a remote cache)",
      R"(Offcore demand code reads satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3804}},
      R"(Offcore demand code reads satisfied by a remote cache or remote DRAM)",
      R"(Offcore demand code reads satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1004}},
      R"(Offcore demand code reads that HIT in a remote cache)",
      R"(Offcore demand code reads that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x804}},
      R"(Offcore demand code reads that HITM in a remote cache)",
      R"(Offcore demand code reads that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_IFETCH.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2004}},
      R"(Offcore demand code reads satisfied by a remote DRAM)",
      R"(Offcore demand code reads satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F02}},
      R"(Offcore demand RFO requests satisfied by any cache or DRAM.)",
      R"(Offcore demand RFO requests satisfied by any cache or DRAM.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6002}},
      R"(Offcore demand RFO requests satisfied by any DRAM)",
      R"(Offcore demand RFO requests satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF802}},
      R"(Offcore demand RFO requests that missed the LLC)",
      R"(Offcore demand RFO requests that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF02}},
      R"(All offcore demand RFO requests)",
      R"(All offcore demand RFO requests)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8002}},
      R"(Offcore demand RFO requests satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore demand RFO requests satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x102}},
      R"(Offcore demand RFO requests satisfied by the LLC and not found in a sibling core)",
      R"(Offcore demand RFO requests satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x202}},
      R"(Offcore demand RFO requests satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore demand RFO requests satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x402}},
      R"(Offcore demand RFO requests satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore demand RFO requests satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x702}},
      R"(Offcore demand RFO requests satisfied by the LLC)",
      R"(Offcore demand RFO requests satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4702}},
      R"(Offcore demand RFO requests satisfied by the LLC or local DRAM)",
      R"(Offcore demand RFO requests satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4002}},
      R"(Offcore demand RFO requests satisfied by the local DRAM)",
      R"(Offcore demand RFO requests satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1802}},
      R"(Offcore demand RFO requests satisfied by a remote cache)",
      R"(Offcore demand RFO requests satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3802}},
      R"(Offcore demand RFO requests satisfied by a remote cache or remote DRAM)",
      R"(Offcore demand RFO requests satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1002}},
      R"(Offcore demand RFO requests that HIT in a remote cache)",
      R"(Offcore demand RFO requests that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x802}},
      R"(Offcore demand RFO requests that HITM in a remote cache)",
      R"(Offcore demand RFO requests that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.DEMAND_RFO.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2002}},
      R"(Offcore demand RFO requests satisfied by a remote DRAM)",
      R"(Offcore demand RFO requests satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F80}},
      R"(Offcore other requests satisfied by any cache or DRAM.)",
      R"(Offcore other requests satisfied by any cache or DRAM.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6080}},
      R"(Offcore other requests satisfied by any DRAM)",
      R"(Offcore other requests satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF880}},
      R"(Offcore other requests that missed the LLC)",
      R"(Offcore other requests that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF80}},
      R"(All offcore other requests)",
      R"(All offcore other requests)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8080}},
      R"(Offcore other requests satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore other requests satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x180}},
      R"(Offcore other requests satisfied by the LLC and not found in a sibling core)",
      R"(Offcore other requests satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x280}},
      R"(Offcore other requests satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore other requests satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x480}},
      R"(Offcore other requests satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore other requests satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x780}},
      R"(Offcore other requests satisfied by the LLC)",
      R"(Offcore other requests satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4780}},
      R"(Offcore other requests satisfied by the LLC or local DRAM)",
      R"(Offcore other requests satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1880}},
      R"(Offcore other requests satisfied by a remote cache)",
      R"(Offcore other requests satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3880}},
      R"(Offcore other requests satisfied by a remote cache or remote DRAM)",
      R"(Offcore other requests satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1080}},
      R"(Offcore other requests that HIT in a remote cache)",
      R"(Offcore other requests that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x880}},
      R"(Offcore other requests that HITM in a remote cache)",
      R"(Offcore other requests that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.OTHER.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2080}},
      R"(Offcore other requests satisfied by a remote DRAM)",
      R"(Offcore other requests satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F30}},
      R"(Offcore prefetch data requests satisfied by any cache or DRAM)",
      R"(Offcore prefetch data requests satisfied by any cache or DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6030}},
      R"(Offcore prefetch data requests satisfied by any DRAM)",
      R"(Offcore prefetch data requests satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF830}},
      R"(Offcore prefetch data requests that missed the LLC)",
      R"(Offcore prefetch data requests that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF30}},
      R"(All offcore prefetch data requests)",
      R"(All offcore prefetch data requests)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8030}},
      R"(Offcore prefetch data requests satisfied by the IO, CSR, MMIO unit.)",
      R"(Offcore prefetch data requests satisfied by the IO, CSR, MMIO unit.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x130}},
      R"(Offcore prefetch data requests satisfied by the LLC and not found in a sibling core)",
      R"(Offcore prefetch data requests satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x230}},
      R"(Offcore prefetch data requests satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore prefetch data requests satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x430}},
      R"(Offcore prefetch data requests satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore prefetch data requests satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x730}},
      R"(Offcore prefetch data requests satisfied by the LLC)",
      R"(Offcore prefetch data requests satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4730}},
      R"(Offcore prefetch data requests satisfied by the LLC or local DRAM)",
      R"(Offcore prefetch data requests satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4030}},
      R"(Offcore prefetch data requests satisfied by the local DRAM)",
      R"(Offcore prefetch data requests satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1830}},
      R"(Offcore prefetch data requests satisfied by a remote cache)",
      R"(Offcore prefetch data requests satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3830}},
      R"(Offcore prefetch data requests satisfied by a remote cache or remote DRAM)",
      R"(Offcore prefetch data requests satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1030}},
      R"(Offcore prefetch data requests that HIT in a remote cache)",
      R"(Offcore prefetch data requests that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x830}},
      R"(Offcore prefetch data requests that HITM in a remote cache)",
      R"(Offcore prefetch data requests that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2030}},
      R"(Offcore prefetch data requests satisfied by a remote DRAM)",
      R"(Offcore prefetch data requests satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F10}},
      R"(Offcore prefetch data reads satisfied by any cache or DRAM.)",
      R"(Offcore prefetch data reads satisfied by any cache or DRAM.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6010}},
      R"(Offcore prefetch data reads satisfied by any DRAM)",
      R"(Offcore prefetch data reads satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF810}},
      R"(Offcore prefetch data reads that missed the LLC)",
      R"(Offcore prefetch data reads that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF10}},
      R"(All offcore prefetch data reads)",
      R"(All offcore prefetch data reads)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8010}},
      R"(Offcore prefetch data reads satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore prefetch data reads satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x110}},
      R"(Offcore prefetch data reads satisfied by the LLC and not found in a sibling core)",
      R"(Offcore prefetch data reads satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x210}},
      R"(Offcore prefetch data reads satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore prefetch data reads satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x410}},
      R"(Offcore prefetch data reads satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore prefetch data reads satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x710}},
      R"(Offcore prefetch data reads satisfied by the LLC)",
      R"(Offcore prefetch data reads satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4710}},
      R"(Offcore prefetch data reads satisfied by the LLC or local DRAM)",
      R"(Offcore prefetch data reads satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4010}},
      R"(Offcore prefetch data reads satisfied by the local DRAM)",
      R"(Offcore prefetch data reads satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1810}},
      R"(Offcore prefetch data reads satisfied by a remote cache)",
      R"(Offcore prefetch data reads satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3810}},
      R"(Offcore prefetch data reads satisfied by a remote cache or remote DRAM)",
      R"(Offcore prefetch data reads satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1010}},
      R"(Offcore prefetch data reads that HIT in a remote cache)",
      R"(Offcore prefetch data reads that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x810}},
      R"(Offcore prefetch data reads that HITM in a remote cache)",
      R"(Offcore prefetch data reads that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_DATA_RD.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2010}},
      R"(Offcore prefetch data reads satisfied by a remote DRAM)",
      R"(Offcore prefetch data reads satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F40}},
      R"(Offcore prefetch code reads satisfied by any cache or DRAM.)",
      R"(Offcore prefetch code reads satisfied by any cache or DRAM.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6040}},
      R"(Offcore prefetch code reads satisfied by any DRAM)",
      R"(Offcore prefetch code reads satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF840}},
      R"(Offcore prefetch code reads that missed the LLC)",
      R"(Offcore prefetch code reads that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF40}},
      R"(All offcore prefetch code reads)",
      R"(All offcore prefetch code reads)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8040}},
      R"(Offcore prefetch code reads satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore prefetch code reads satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x140}},
      R"(Offcore prefetch code reads satisfied by the LLC and not found in a sibling core)",
      R"(Offcore prefetch code reads satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x240}},
      R"(Offcore prefetch code reads satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore prefetch code reads satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x440}},
      R"(Offcore prefetch code reads satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore prefetch code reads satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x740}},
      R"(Offcore prefetch code reads satisfied by the LLC)",
      R"(Offcore prefetch code reads satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4740}},
      R"(Offcore prefetch code reads satisfied by the LLC or local DRAM)",
      R"(Offcore prefetch code reads satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4040}},
      R"(Offcore prefetch code reads satisfied by the local DRAM)",
      R"(Offcore prefetch code reads satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1840}},
      R"(Offcore prefetch code reads satisfied by a remote cache)",
      R"(Offcore prefetch code reads satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3840}},
      R"(Offcore prefetch code reads satisfied by a remote cache or remote DRAM)",
      R"(Offcore prefetch code reads satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1040}},
      R"(Offcore prefetch code reads that HIT in a remote cache)",
      R"(Offcore prefetch code reads that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x840}},
      R"(Offcore prefetch code reads that HITM in a remote cache)",
      R"(Offcore prefetch code reads that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_IFETCH.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2040}},
      R"(Offcore prefetch code reads satisfied by a remote DRAM)",
      R"(Offcore prefetch code reads satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F20}},
      R"(Offcore prefetch RFO requests satisfied by any cache or DRAM.)",
      R"(Offcore prefetch RFO requests satisfied by any cache or DRAM.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6020}},
      R"(Offcore prefetch RFO requests satisfied by any DRAM)",
      R"(Offcore prefetch RFO requests satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF820}},
      R"(Offcore prefetch RFO requests that missed the LLC)",
      R"(Offcore prefetch RFO requests that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF20}},
      R"(All offcore prefetch RFO requests)",
      R"(All offcore prefetch RFO requests)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8020}},
      R"(Offcore prefetch RFO requests satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore prefetch RFO requests satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x120}},
      R"(Offcore prefetch RFO requests satisfied by the LLC and not found in a sibling core)",
      R"(Offcore prefetch RFO requests satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x220}},
      R"(Offcore prefetch RFO requests satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore prefetch RFO requests satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x420}},
      R"(Offcore prefetch RFO requests satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore prefetch RFO requests satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x720}},
      R"(Offcore prefetch RFO requests satisfied by the LLC)",
      R"(Offcore prefetch RFO requests satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4720}},
      R"(Offcore prefetch RFO requests satisfied by the LLC or local DRAM)",
      R"(Offcore prefetch RFO requests satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4020}},
      R"(Offcore prefetch RFO requests satisfied by the local DRAM)",
      R"(Offcore prefetch RFO requests satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1820}},
      R"(Offcore prefetch RFO requests satisfied by a remote cache)",
      R"(Offcore prefetch RFO requests satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3820}},
      R"(Offcore prefetch RFO requests satisfied by a remote cache or remote DRAM)",
      R"(Offcore prefetch RFO requests satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1020}},
      R"(Offcore prefetch RFO requests that HIT in a remote cache)",
      R"(Offcore prefetch RFO requests that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x820}},
      R"(Offcore prefetch RFO requests that HITM in a remote cache)",
      R"(Offcore prefetch RFO requests that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PF_RFO.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2020}},
      R"(Offcore prefetch RFO requests satisfied by a remote DRAM)",
      R"(Offcore prefetch RFO requests satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.ANY_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x7F70}},
      R"(Offcore prefetch requests satisfied by any cache or DRAM.)",
      R"(Offcore prefetch requests satisfied by any cache or DRAM.)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.ANY_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x6070}},
      R"(Offcore prefetch requests satisfied by any DRAM)",
      R"(Offcore prefetch requests satisfied by any DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.ANY_LLC_MISS",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xF870}},
      R"(Offcore prefetch requests that missed the LLC)",
      R"(Offcore prefetch requests that missed the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.ANY_LOCATION",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0xFF70}},
      R"(All offcore prefetch requests)",
      R"(All offcore prefetch requests)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.IO_CSR_MMIO",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x8070}},
      R"(Offcore prefetch requests satisfied by the IO, CSR, MMIO unit)",
      R"(Offcore prefetch requests satisfied by the IO, CSR, MMIO unit)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.LLC_HIT_NO_OTHER_CORE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x170}},
      R"(Offcore prefetch requests satisfied by the LLC and not found in a sibling core)",
      R"(Offcore prefetch requests satisfied by the LLC and not found in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.LLC_HIT_OTHER_CORE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x270}},
      R"(Offcore prefetch requests satisfied by the LLC and HIT in a sibling core)",
      R"(Offcore prefetch requests satisfied by the LLC and HIT in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.LLC_HIT_OTHER_CORE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x470}},
      R"(Offcore prefetch requests satisfied by the LLC  and HITM in a sibling core)",
      R"(Offcore prefetch requests satisfied by the LLC  and HITM in a sibling core)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.LOCAL_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x770}},
      R"(Offcore prefetch requests satisfied by the LLC)",
      R"(Offcore prefetch requests satisfied by the LLC)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.LOCAL_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4770}},
      R"(Offcore prefetch requests satisfied by the LLC or local DRAM)",
      R"(Offcore prefetch requests satisfied by the LLC or local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.LOCAL_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x4070}},
      R"(Offcore prefetch requests satisfied by the local DRAM)",
      R"(Offcore prefetch requests satisfied by the local DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.REMOTE_CACHE",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1870}},
      R"(Offcore prefetch requests satisfied by a remote cache)",
      R"(Offcore prefetch requests satisfied by a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.REMOTE_CACHE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x3870}},
      R"(Offcore prefetch requests satisfied by a remote cache or remote DRAM)",
      R"(Offcore prefetch requests satisfied by a remote cache or remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.REMOTE_CACHE_HIT",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x1070}},
      R"(Offcore prefetch requests that HIT in a remote cache)",
      R"(Offcore prefetch requests that HIT in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.REMOTE_CACHE_HITM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x870}},
      R"(Offcore prefetch requests that HITM in a remote cache)",
      R"(Offcore prefetch requests that HITM in a remote cache)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::cpu,
      "OFFCORE_RESPONSE_0.PREFETCH.REMOTE_DRAM",
      EventDef::Encoding{
          .code = 0xB7, .umask = 0x1, .cmask = 0, .msr_values = {0x2070}},
      R"(Offcore prefetch requests satisfied by a remote DRAM)",
      R"(Offcore prefetch requests satisfied by a remote DRAM)",
      100000,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace nehalemex_core
} // namespace facebook::hbt::perf_event::generated
