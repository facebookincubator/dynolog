// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include "dynolog/tests/rpc/SimpleJsonClientTest.h"

DEFINE_int32(port, 1778, "Port for sending RPC requests");
DEFINE_string(
    message,
    "{\"fn\":\"getStatus\"",
    "A Json formatted message to send to server.");
DEFINE_string(host_ip, "::1", "Host ipv6 address.");

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;

  auto client = dynolog::SimpleJsonServerClient(FLAGS_host_ip, FLAGS_port);
  if (!client.initSuccessful()) {
    LOG(ERROR) << "Failed to initialize RPC client, check if server is running";
    return -1;
  }

  auto response = client.invoke_rpc(FLAGS_message);
  if (!response) {
    LOG(ERROR) << "Failed to call RPC on :" << response.value();
    return -1;
  }

  return 0;
}
