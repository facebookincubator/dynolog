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

  void logStr(const std::string& /* key */, const std::string& /* val */)
      override {}

  void finalize() override;

 private:
  std::string hostname_;
};

} // namespace dynolog
