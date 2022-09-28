// Copyright 2004-present Facebook. All Rights Reserved.

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "FabricManager.h" // @manual=//dynolog/src/ipcfabric:ipcfabric

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
