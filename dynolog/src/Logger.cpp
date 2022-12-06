// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/Logger.h"
#include <fmt/format.h>
#include <glog/logging.h>
#include <ctime>

using json = nlohmann::json;

namespace dynolog {

DEFINE_string(
    access_token,
    "",
    "The ODS access token to publish through Graph API");
DEFINE_string(
    certificate_path,
    "/etc/ssl/certs/ca-certificates.crt",
    "The path for SSL certificate");

std::string JsonLogger::timestampStr() const {
  std::time_t ts_time_t = std::chrono::system_clock::to_time_t(ts_);
  std::tm ts_tm = *std::localtime(&ts_time_t);
  char buf[512];
  auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(
      ts_.time_since_epoch());
  std::strftime(buf, 512, "%Y-%m-%dT%H:%M:%S", &ts_tm);
  return fmt::format("{}.{:03d}Z", buf, millis.count() % 1000);
}

json JsonLogger::sampleJson() const {
  return json_;
}

void JsonLogger::logInt(const std::string& key, int64_t val) {
  json_[key] = val;
}

void JsonLogger::logFloat(const std::string& key, float val) {
  json_[key] = fmt::format("{:.3f}", val);
}

void JsonLogger::logUint(const std::string& key, uint64_t val) {
  json_[key] = val;
}

void JsonLogger::logStr(const std::string& key, const std::string& val) {
  json_[key] = val;
}

void JsonLogger::finalize() {
  LOG(INFO) << "Logging : " << json_.size() << " values";
  LOG(INFO) << "time = " << timestampStr() << " data = " << sampleJson().dump();
  json_.clear();
}

} // namespace dynolog
