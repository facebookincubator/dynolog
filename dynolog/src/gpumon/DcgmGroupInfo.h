// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once
#include <string.h>
#include <cstdint>
#include <memory>
#include <unordered_map>
#include <variant>
#include <vector>
#include "dynolog/src/Logger.h"
#include "dynolog/src/gpumon/dcgm_structs.h"

namespace dynolog {
namespace gpumon {

DECLARE_string(dcgm_fields);

constexpr char kDcgmDefaultFieldIds[] =
    "100,155,204,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012";
class DcgmGroupInfo {
 public:
  ~DcgmGroupInfo();
  static std::unique_ptr<DcgmGroupInfo> factory(
      const std::string& fields_str,
      int updateIntervalMs);
  void update();
  dcgmStatus_t getDcgmStatus() {
    return errorCode_;
  }
  bool isFailing() {
    return errorCode_ != DCGM_ST_OK;
  }
  void log(Logger& logger);

 private:
  DcgmGroupInfo(
      const std::vector<unsigned short>& fields,
      const std::vector<unsigned short>& prof_fields,
      int updateIntervalMs);
  void init();
  void createGroups();
  void createFieldGroups(const std::vector<unsigned short>& fields);
  void watchFields();
  void watchProfFields(const std::vector<unsigned short>& prof_fields);

  std::vector<unsigned int> gpuIdList_;
  int deviceCount_ = 0;
  bool prof_enabled_ = false;
  int updateIntervalMs_;
  dcgmReturn_t errorCode_{DCGM_ST_OK};
  dcgmReturn_t retCode_{DCGM_ST_OK};
  dcgmHandle_t dcgmHandle_;
  dcgmGpuGrp_t groupId_;
  std::unordered_map<int, std::unordered_map<std::string, double>>
      metricsMapDouble_;
  std::unordered_map<int, std::unordered_map<std::string, int64_t>>
      metricsMapInt_;
  // We currently assume at most one pid running on each GPU entity
  // This maps from gpu device_id to a map containing environment variables
  // and their values for the pid running on that gpu (if it exists).
  std::unordered_map<int, std::unordered_map<std::string, std::string>>
      envMetadataMapString_;
  std::vector<dcgmFieldGrp_t> fieldGroupIds_;
};

} // namespace gpumon
} // namespace dynolog
