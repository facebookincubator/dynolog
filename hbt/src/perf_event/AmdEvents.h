// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once
#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/PmuDevices.h"

namespace facebook::hbt::perf_event {

namespace amd_msr {
// 2.1.16.3 MSRs - MSRC001_0xxx - Processor Programming
// Reference (PPR) for AMD Family 19h Model 01h, Revision B1
// Processors Volume 1
struct CorePmuMsrAmd {
  uint64_t event : 8;
  uint64_t unitMask : 8;
  uint64_t userMode : 1;
  uint64_t osMode : 1;
  uint64_t edge : 1;
  uint64_t : 1;
  uint64_t interrupt : 1;
  uint64_t : 1;
  uint64_t enable : 1;
  uint64_t invert : 1;
  uint64_t counterMask : 8;
  uint64_t event_11_8 : 4;
  uint64_t : 4;
  uint64_t hostGuest : 2;
  uint64_t : 22;
};

static_assert(
    sizeof(CorePmuMsrAmd) == sizeof(uint64_t),
    "CorePmuMsrAmd is packed to be 64 bits to fit in MSR.");

struct L3PmuMsrAmd {
  uint64_t event : 8;
  uint64_t unitMask : 8;
  uint64_t : 6;
  uint64_t enable : 1;
  uint64_t : 19;
  uint64_t coreId : 3;
  uint64_t : 1;
  uint64_t enAllSlices : 1;
  uint64_t enAllCores : 1;
  uint64_t sliceId : 3;
  uint64_t : 5;
  uint64_t threadMask : 4;
  uint64_t : 4;
};

static_assert(
    sizeof(L3PmuMsrAmd) == sizeof(uint64_t),
    "L3PmuMsrAmd is packed to be 64 bits to fit in MSR.");

struct DFPmuMsrAmd {
  uint64_t event : 8;
  uint64_t unitMask : 8;
  uint64_t : 6;
  uint64_t enable : 1;
  uint64_t : 9;
  uint64_t event_11_8 : 4;
  uint64_t : 23;
  uint64_t event_13_12 : 2;
  uint64_t : 3;
};

static_assert(
    sizeof(DFPmuMsrAmd) == sizeof(uint64_t),
    "DFPmuMsrAmd is packed to be 64 bits to fit in MSR.");

union PmuMsr {
  uint64_t val = 0;
  CorePmuMsrAmd amdCore;
  L3PmuMsrAmd amdL3;
  DFPmuMsrAmd amdDf;
};

/*
Events and formulas for this file come from AMD Processor Programming
Reference (PPR) for AMD Family 19h Model 01h, Revision B1 Processors
Volume 1

The section that defines them is 2.1.17.2 Performance Measurement and
Table 25: Guidance for Common Performance Statistics with Complex Event Selects
*/

constexpr PmuMsr kRetiredInstructions{.amdCore = {.event = 0xc0}};
constexpr PmuMsr kUnhaltedCycles{.amdCore = {.event = 0x76}};

// L1 iCache
constexpr PmuMsr kL1ICacheFillMisses{
    .amdCore = {.event = 0x64, .unitMask = 0x7}}; // Same as e=0x60,u=0x10

// L1 dCache
constexpr PmuMsr kL1DCacheMisses{
    .amdCore = {.event = 0x41, .unitMask = 0x1f}}; // AMD recommended way

// L2 Cache
constexpr PmuMsr kL2ICacheFillMisses{
    .amdCore = {.event = 0x64, .unitMask = 0x1}};
constexpr PmuMsr kL2DCacheAccesses{
    .amdCore = {.event = 0x64, .unitMask = 0x78}}; // Same as e=0x60,u=0xc8
constexpr PmuMsr kL2DCacheMisses{.amdCore = {.event = 0x64, .unitMask = 0x8}};

// L2 with Prefetcher
constexpr PmuMsr kL2Accesses{.amdCore = {.event = 0x64, .unitMask = 0x7f}};
constexpr PmuMsr kL2Misses{.amdCore = {.event = 0x64, .unitMask = 0x9}};
constexpr PmuMsr kL2PrefetcherHitsInL2{.amdCore = {.event = 0x70}};
constexpr PmuMsr kL2PrefetcherHitsInL3{.amdCore = {.event = 0x71}};
constexpr PmuMsr kL2PrefetcherMissesInL3{.amdCore = {.event = 0x72}};

// Flops
constexpr PmuMsr kRetiredX87Flops{.amdCore = {.event = 0x2, .unitMask = 0x7}};
constexpr PmuMsr kRetiredSseAvxFlops{
    .amdCore = {.event = 0x3, .unitMask = 0xf}};

// Branches
constexpr PmuMsr kRetiredBranchInstructions{.amdCore = {.event = 0xc2}};
constexpr PmuMsr kRetiredBranchMispred{.amdCore = {.event = 0xc3}};
constexpr PmuMsr kRetiredFarControlTransfer{.amdCore = {.event = 0xc6}};

// TLB
constexpr PmuMsr kDTlbMisses{.amdCore = {.event = 0x45, .unitMask = 0xf0}};
constexpr PmuMsr kDTlbAccesses{.amdCore = {.event = 0x45, .unitMask = 0xff}};
constexpr PmuMsr kITlbMisses{.amdCore = {.event = 0x85, .unitMask = 0xf}};
constexpr PmuMsr kITlbAccesses{.amdCore = {.event = 0x84}};

// Stall cycles
// Found in kernel perf_events
// https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/tree/tools/perf/pmu-events/arch/x86/amdzen3/cache.json?h=v6.0
constexpr PmuMsr kStalledCyclesBackPressure{
    .amdCore = {.event = 0x87, .unitMask = 0x1}};
constexpr PmuMsr kStalledCyclesIdqEmpty{
    .amdCore = {.event = 0x87, .unitMask = 0x2}};
constexpr PmuMsr kStalledCyclesAny{.amdCore = {.event = 0x87, .unitMask = 0x4}};

// Retired uops
constexpr PmuMsr kRetiredUOps{.amdCore = {.event = 0xc1}};
constexpr PmuMsr kDeUopsDispatchedOpCache{
    .amdCore = {.event = 0xaa, .unitMask = 0x2}};
constexpr PmuMsr kDeUopsDispatchedDecoder{
    .amdCore = {.event = 0xaa, .unitMask = 0x1}};

// IC Fill Source
constexpr PmuMsr kIcCacheFillL2{.amdCore = {.event = 0x82}};
constexpr PmuMsr kIcCacheFillSys{.amdCore = {.event = 0x83}};

// MAB Latency
constexpr PmuMsr kLsAllocMabCount{.amdCore = {.event = 0x5f}};
constexpr PmuMsr kLsMabAllocPipes{.amdCore = {.event = 0x41, .unitMask = 0x1f}};
constexpr PmuMsr kIcMabRequestsPrefetch{
    .amdCore = {.event = 0x84, .event_11_8 = 0x2}};
constexpr PmuMsr kIcMabRequestsDemad{
    .amdCore = {.event = 0x85, .event_11_8 = 0x2}};

// L3 counters
constexpr PmuMsr kL3FillRdRespLat{.amdL3 = {.event = 0x90}};
constexpr PmuMsr kL3FillRdCnt{.amdL3 = {.event = 0x9A, .unitMask = 0x1F}};

} // namespace amd_msr

void addAmdEvents(const CpuInfo& info, PmuDeviceManager& pmu_manager);

} // namespace facebook::hbt::perf_event
