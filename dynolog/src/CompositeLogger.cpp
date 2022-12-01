// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include "dynolog/src/CompositeLogger.h"

namespace dynolog {

CompositeLogger::CompositeLogger(std::vector<std::unique_ptr<Logger>> loggers) {
  loggers_ = std::move(loggers);
}

void CompositeLogger::setTimestamp(Timestamp ts) {
  for (const auto& logger : loggers_) {
    logger->setTimestamp(ts);
  }
}

void CompositeLogger::logInt(const std::string& key, int64_t val) {
  for (const auto& logger : loggers_) {
    logger->logInt(key, val);
  }
}

void CompositeLogger::logUint(const std::string& key, uint64_t val) {
  for (const auto& logger : loggers_) {
    logger->logUint(key, val);
  }
}

void CompositeLogger::logFloat(const std::string& key, float val) {
  for (const auto& logger : loggers_) {
    logger->logFloat(key, val);
  }
}

void CompositeLogger::logStr(const std::string& key, const std::string& val) {
  for (const auto& logger : loggers_) {
    logger->logStr(key, val);
  }
}

void CompositeLogger::finalize() {
  for (const auto& logger : loggers_) {
    logger->finalize();
  }
}

} // namespace dynolog
