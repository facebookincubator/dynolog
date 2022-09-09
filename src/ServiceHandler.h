// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <string>

namespace dynolog {

// Service Handler : acts as a generic handler for requests made to the
//   daemmon. This can be wrapped inside RPC protocols to handle the
//   communication over the network.

class ServiceHandler {
 public:
  // returns the state of the service
  int getStatus();

  // ... more to come
};

} // namespace dynolog
