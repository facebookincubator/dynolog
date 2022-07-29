// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <map>
#include <memory>
#include <string>

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "Logger.h"

namespace dynolog {

class SocketWrapper;

// An abstract class for logging metrics
//  1. Create a class with this interface for each log entry
//  2. Add data to it using log* methods
//  3. Publish the data data with finalize()
// Todo add timestamp to constructor
class FBRelayLogger : public JsonLogger {
 public:
  explicit FBRelayLogger();
  ~FBRelayLogger() override {}

  void finalize() override;

 private:
  class SocketWrapper {
   public:
    explicit SocketWrapper(const std::string& addr, int port);
    ~SocketWrapper();

    bool success() const;
    bool send(const std::string& msg);

   private:
    int sock_fd_ = 0;
    bool success_ = false;
  };

  void initSocket();

  std::unique_ptr<SocketWrapper> socket;
};

} // namespace dynolog
