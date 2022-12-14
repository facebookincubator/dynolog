// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "dynolog/src/Logger.h"

namespace dynolog {

DECLARE_string(scribe_category);

class ScubaLogger final : public Logger {
 public:
  explicit ScubaLogger(const std::string& scribe_category);
  void setTimestamp(Timestamp ts) override {
    ts_ = ts;
  }

  void logInt(const std::string& key, int64_t val) override;

  void logFloat(const std::string& key, float val) override;

  void logUint(const std::string& key, uint64_t val) override;

  void logStr(const std::string& key, const std::string& val) override;

  void finalize() override;

 private:
  void clearMetrics();

  Timestamp ts_;
  std::string scribe_category_;
  std::string hostname_;
  nlohmann::json metrics_int_;
  nlohmann::json metrics_double_;
  nlohmann::json metrics_str_;
};

} // namespace dynolog
