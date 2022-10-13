// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "dynolog/src/Logger.h"

namespace dynolog {

class ODSJsonLogger : public JsonLogger {
 public:
  ODSJsonLogger();
  void setTimestamp(Timestamp ts) override {
    ts_ = ts;
  }

  void logInt(const std::string& key, int64_t val) override;

  void logFloat(const std::string& key, float val) override;

  void finalize() override;

 private:
  std::string hostname_;
  nlohmann::json metrics_json_;
};

} // namespace dynolog
