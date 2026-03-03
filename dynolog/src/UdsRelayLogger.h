/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <gflags/gflags.h>
#include "dynolog/src/Logger.h"

DECLARE_string(udsrelay_socket_path);

namespace dynolog {

// A standalone Unix domain socket wrapper intended to persist for the
// lifetime of the daemon.
class UdsSocketWrapper {
 public:
  explicit UdsSocketWrapper(const std::string& socket_path);
  ~UdsSocketWrapper();
  void close();

  bool success() const;
  bool send(const std::string& category, const std::string& msg);

 private:
  static inline int sock_fd_ = -1;
  static inline bool success_ = false;
  static inline std::mutex mutex_;
};

// A logger that sends JSON metrics over a Unix domain socket.
//  1. Create a class with this interface for each log entry
//  2. Add data to it using log* methods
//  3. Publish the data data with finalize()
class UdsRelayLogger : public JsonLogger {
 public:
  explicit UdsRelayLogger();
  ~UdsRelayLogger() override = default;

  void finalize() override;

 private:
  void initSocket();

  std::unique_ptr<UdsSocketWrapper> socket;
  std::string hostname_;
};

} // namespace dynolog
