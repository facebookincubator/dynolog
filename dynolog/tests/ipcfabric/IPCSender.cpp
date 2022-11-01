// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/ipcfabric/FabricManager.h"

int main() {
  int data = 1000;
  std::string datastring = "this";
  auto sender = dynolog::ipcfabric::FabricManager::factory("sender");
  std::string type_int = "int";
  std::unique_ptr<dynolog::ipcfabric::Message> msgint =
      dynolog::ipcfabric::Message::constructMessage<decltype(data)>(
          data, type_int);
  std::string type_string = "string";
  std::unique_ptr<dynolog::ipcfabric::Message> msgstring =
      dynolog::ipcfabric::Message::constructMessage<decltype(datastring)>(
          datastring, type_string);

  sender->sync_send(*msgint, "dynolog");
  sender->sync_send(*msgstring, "dynolog");
  sender->sync_send(*msgint, "dynolog");

  return 0;
}
