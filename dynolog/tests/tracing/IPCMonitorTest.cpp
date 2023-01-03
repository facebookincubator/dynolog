// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/tracing/IPCMonitor.h"
#include <gtest/gtest.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <chrono>
#include <iostream>
#include "dynolog/src/LibkinetoConfigManager.h"
#include "dynolog/src/ipcfabric/FabricManager.h"

using namespace dynolog;
using namespace dynolog::tracing;
using namespace dynolog::ipcfabric;

constexpr int kJobID = 42;

int32_t processId() {
  static int32_t _pid = 0;
  if (!_pid) {
#ifndef _MSC_VER
    _pid = (int32_t)getpid();
#else
    _pid = (int32_t)GetCurrentProcessId();
#endif
  }
  return _pid;
}

TEST(IPCMonitorTest, LibkinetoRegisterAndOndemandTest) {
  pid_t cpid;

  cpid = fork();
  ASSERT_NE(cpid, -1);

  if (cpid == 0) {
    // Child send sends requests to IPCMonitor.
    auto client = FabricManager::factory("client");

    // Construct Register object to send through the manager
    LibkinetoContext ctx{.gpu = 2, .pid = processId(), .jobid = kJobID};
    std::unique_ptr<Message> msg =
        Message::constructMessage<decltype(ctx)>(ctx, "ctxt");
    LOG(INFO) << "Client sending ctx message";
    client->sync_send(*msg, "dynolog_unittest");

    LOG(INFO) << "Client waiting for response";
    auto resp_msg = client->poll_recv(100 /*retries*/, 1000000 /*sleep us*/);
    ASSERT_NE(resp_msg, nullptr);

    // Construct OnDemand Request object to send through the manager
    std::vector<int32_t> pids{processId()};
    int size = pids.size();
    LibkinetoRequest* req = (LibkinetoRequest*)malloc(
        sizeof(LibkinetoRequest) + sizeof(int32_t) * size);

    req->type = int(LibkinetoConfigType::ACTIVITIES);
    req->n = size;
    req->jobid = kJobID;
    for (int i = 0; i < size; i++) {
      req->pids[i] = pids[i];
    }

    msg =
        Message::constructMessage<LibkinetoRequest, int32_t>(*req, "req", size);
    LOG(INFO) << "Client sending req message";
    client->sync_send(*msg, "dynolog_unittest");

    LOG(INFO) << "Client waiting for response";
    resp_msg = client->poll_recv(100 /*retries*/, 1000000 /*sleep us*/);
    ASSERT_NE(resp_msg, nullptr);

    LOG(INFO) << "Client is done.";
    exit(0);

  } else {
    // Receiver side - IPC Monitor
    auto monitor = std::make_unique<IPCMonitor>("dynolog_unittest");
    EXPECT_EQ(LibkinetoConfigManager::getInstance()->processCount("0"), 0);

    /* sleep override */
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Receive the libkinetocontext message
    ASSERT_TRUE(monitor->ipc_manager_->recv())
        << "Did not receive context message";
    auto msg = monitor->ipc_manager_->retrieve_msg();
    monitor->processMsg(std::move(msg));

    /* sleep override */
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Receive the getOndemand Request message
    ASSERT_TRUE(monitor->ipc_manager_->recv())
        << "Did not receive request message";
    msg = monitor->ipc_manager_->retrieve_msg();
    ASSERT_TRUE(msg != nullptr);

    monitor->processMsg(std::move(msg));

    EXPECT_EQ(
        LibkinetoConfigManager::getInstance()->processCount(
            std::to_string(kJobID)),
        1);

    // Wait for child thread to either change state or stopped.
    int wstatus;
    pid_t wpid = waitpid(cpid, &wstatus, WUNTRACED);
    ASSERT_EQ(cpid, wpid);
    ASSERT_EQ(WIFEXITED(wstatus), true);
  }
}
