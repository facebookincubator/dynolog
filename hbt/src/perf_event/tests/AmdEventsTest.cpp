// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/AmdEvents.h"
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "hbt/src/perf_event/PmuDevices.h"

#include <gtest/gtest.h>

using namespace facebook::hbt;
using namespace facebook::hbt::perf_event;

namespace {

constexpr unsigned int kDeviceEnum = 0;
constexpr uint32_t kAmdDfPerfType = 52;

PmuDeviceManager makeAmdDfPmuManager(CpuArch arch) {
  CpuInfo cpuInfo("AuthenticAMD", 26, 80, 2, 2);
  cpuInfo.cpu_arch = arch;
  PmuDeviceManager pmuManager(cpuInfo);
  pmuManager.addPmu(
      std::make_shared<PmuDevice>(
          "amd_df",
          PmuType::amd_df,
          kDeviceEnum,
          kAmdDfPerfType,
          "A dummy amd_df device",
          true));
  return pmuManager;
}

std::string csDataBwEventId(const std::string& type, uint32_t port) {
  return "zen6::cs_data_bw." + type + ".cs" + std::to_string(port);
}

} // namespace

// The Zen4 DF UMC request constants were written out field by field from the
// PPR, and their event selects (0x01F, 0x0DF, 0x19F, 0x25F) are CS ports 0, 3,
// 6 and 9 with the same unit masks. Ports 3 and 9 do not have 0x1F as the low
// event byte, so a wrong low-byte encoding cannot pass.
TEST(AmdEventsTest, CsDataBwCodeMatchesFieldWiseDfEncoding) {
  struct Case {
    uint32_t port;
    uint32_t unitMask;
    uint64_t expected;
  };
  using namespace amd_msr;
  const std::vector<Case> cases{
      {0, kCsZen6DataBwReadLocal, kDfZen4UmcAReadReqsLocal.val},
      {3, kCsZen6DataBwReadLocal, kDfZen4UmcDReadReqsLocal.val},
      {6, kCsZen6DataBwReadLocal, kDfZen4UmcGReadReqsLocal.val},
      {9, kCsZen6DataBwReadLocal, kDfZen4UmcJReadReqsLocal.val},
      {0, kCsZen6DataBwReadRemote, kDfZen4UmcAReadReqsRemote.val},
      {3, kCsZen6DataBwReadRemote, kDfZen4UmcDReadReqsRemote.val},
      {6, kCsZen6DataBwReadRemote, kDfZen4UmcGReadReqsRemote.val},
      {9, kCsZen6DataBwReadRemote, kDfZen4UmcJReadReqsRemote.val},
      {0, kCsZen6DataBwWriteLocal, kDfZen4UmcAWriteReqsLocal.val},
      {3, kCsZen6DataBwWriteLocal, kDfZen4UmcDWriteReqsLocal.val},
      {6, kCsZen6DataBwWriteLocal, kDfZen4UmcGWriteReqsLocal.val},
      {9, kCsZen6DataBwWriteLocal, kDfZen4UmcJWriteReqsLocal.val},
      {0, kCsZen6DataBwWriteRemote, kDfZen4UmcAWriteReqsRemote.val},
      {3, kCsZen6DataBwWriteRemote, kDfZen4UmcDWriteReqsRemote.val},
      {6, kCsZen6DataBwWriteRemote, kDfZen4UmcGWriteReqsRemote.val},
      {9, kCsZen6DataBwWriteRemote, kDfZen4UmcJWriteReqsRemote.val},
  };
  for (const auto& c : cases) {
    EXPECT_EQ(csZen6DataBwCode(c.port, c.unitMask), c.expected)
        << "cs" << c.port << " unit mask 0x" << std::hex << c.unitMask;
  }
}

// Hand-assembled from the kernel amd_df format (event = config:0-7,32-37,
// umask = config:8-15,24-27) for ports that need the event select high bits.
TEST(AmdEventsTest, CsDataBwCodeUsesHighEventSelectBits) {
  using namespace amd_msr;
  // cs12: event 0x31F, umask 0x7FE.
  EXPECT_EQ(csZen6DataBwCode(12, kCsZen6DataBwReadLocal), 0x3'0700'FE1FULL);
  // cs15: event 0x3DF, umask 0xBFE.
  EXPECT_EQ(csZen6DataBwCode(15, kCsZen6DataBwReadRemote), 0x3'0B00'FEDFULL);
  // cs1: event 0x05F, umask 0xBFF.
  EXPECT_EQ(csZen6DataBwCode(1, kCsZen6DataBwWriteRemote), 0x0'0B00'FF5FULL);
}

TEST(AmdEventsTest, AddsVeniceCsDataBwEventsOnDfPmu) {
  auto pmuManager = makeAmdDfPmuManager(CpuArch::VENICE);
  addAmdEvents(pmuManager.cpuInfo, pmuManager);

  struct Type {
    const char* id;
    uint32_t unitMask;
  };
  const std::vector<Type> types{
      {"rd_local", amd_msr::kCsZen6DataBwReadLocal},
      {"rd_remote", amd_msr::kCsZen6DataBwReadRemote},
      {"wr_local", amd_msr::kCsZen6DataBwWriteLocal},
      {"wr_remote", amd_msr::kCsZen6DataBwWriteRemote},
  };
  for (uint32_t port = 0; port < amd_msr::kNumZen6CsPorts; ++port) {
    for (const auto& type : types) {
      const auto id = csDataBwEventId(type.id, port);
      const auto event = pmuManager.findEventDef(id);
      ASSERT_NE(event, nullptr) << id;
      EXPECT_EQ(event->pmu_type, PmuType::amd_df) << id;
      EXPECT_EQ(
          event->encoding.code, amd_msr::csZen6DataBwCode(port, type.unitMask))
          << id;
    }
  }
}

TEST(AmdEventsTest, DoesNotAddCsDataBwEventsOnTurin) {
  auto pmuManager = makeAmdDfPmuManager(CpuArch::TURIN);
  addAmdEvents(pmuManager.cpuInfo, pmuManager);

  EXPECT_EQ(pmuManager.findEventDef(csDataBwEventId("rd_local", 0)), nullptr);
  EXPECT_EQ(pmuManager.findEventDef(csDataBwEventId("wr_remote", 15)), nullptr);
}
