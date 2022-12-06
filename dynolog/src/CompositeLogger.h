// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once
#include "dynolog/src/Logger.h"

namespace dynolog {

class CompositeLogger : public Logger {
 public:
  explicit CompositeLogger(std::vector<std::unique_ptr<Logger>> loggers);

  void setTimestamp(Timestamp ts) override;

  void logInt(const std::string& key, int64_t val) override;

  void logUint(const std::string& key, uint64_t val) override;

  void logFloat(const std::string& key, float val) override;

  void logStr(const std::string& key, const std::string& val) override;

  void finalize() override;

 private:
  std::vector<std::unique_ptr<Logger>> loggers_;
};

} // namespace dynolog
