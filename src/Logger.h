// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <nlohmann/json.hpp>
#include <chrono>
#include <map>
#include <string>
#include <type_traits>

namespace dynolog {

// An abstract class for logging metrics
//  1. Create a class with this interface for each log entry
//  2. Add data to it using log* methods
//  3. Publish the data data with finalize()
class Logger {
 public:
  using Timestamp = std::chrono::time_point<std::chrono::system_clock>;
  virtual ~Logger() {}

  virtual void setTimestamp(
      Timestamp ts = std::chrono::system_clock::now()) = 0;

  // Logs an integer value
  virtual void logInt(const std::string& key, int64_t val) = 0;

  // Logs a floating point value
  virtual void logFloat(const std::string& key, float val) = 0;

  // Logs an unsigned integer value
  virtual void logUint(const std::string& key, uint64_t val) = 0;

  virtual void finalize() = 0;

  template <typename T>
  void log(const std::string& key, T val) {
    if (std::is_same<T, int64_t>::value) {
      logInt(key, val);
    } else if (std::is_same<T, uint64_t>::value) {
      logUint(key, val);
    } else if (std::is_same<T, float>::value) {
      logFloat(key, val);
    } else {
      static_assert("unsupported type in log()");
    }
  }
};

class JsonLogger : public Logger {
 public:
  void setTimestamp(Timestamp ts) override {
    ts_ = ts;
  }

  void logInt(const std::string& key, int64_t val) override;

  void logFloat(const std::string& key, float val) override;

  void logUint(const std::string& key, uint64_t val) override;

  void finalize() override;

 protected:
  Timestamp ts_;
  nlohmann::json sampleJson() const;
  std::string timestampStr() const;

 private:
  nlohmann::json json_;
};

} // namespace dynolog
