// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/tests/rpc/SimpleJsonClientTest.h"
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <condition_variable>
#include <mutex>
#include "dynolog/src/LibkinetoConfigManager.h"
#include "dynolog/src/rpc/SimpleJsonServer.h"
#include "dynolog/src/rpc/SimpleJsonServerInl.h"

namespace dynolog {

using json = nlohmann::json;

struct MockServiceHandler {
  int getStatus() {
    statusCalls_++;
    return status_;
  }

  GpuProfilerResult setKinetOnDemandRequest(
      int job_id,
      const std::set<int>& pids,
      const std::string& config,
      int limit) {
    job_id_ = job_id;
    limit_ = limit;
    pids_ = pids;
    config_ = config;
    setKinetoOnDemandCalls_++;

    return result;
  }

  int status_ = 0;
  int statusCalls_ = 0;
  GpuProfilerResult result;

  int setKinetoOnDemandCalls_ = 0;
  int job_id_ = -1;
  std::set<int> pids_;
  std::string config_;
  int limit_ = -1;
};

using TestSimpleJsonServer = SimpleJsonServer<MockServiceHandler>;

class SimpleJsonClientTest : public ::testing::Test {
 protected:
  void SetUp() override {
    handler_ = std::make_shared<MockServiceHandler>();
    server_ = std::make_unique<TestSimpleJsonServer>(handler_, 0 /*port*/);

    ASSERT_TRUE(server_->initSuccessful());
    port_ = server_->getPort();

    thread_ = std::make_unique<std::thread>([this]() {
      while (1) {
        std::unique_lock lk(mutex_);
        rpc_ready_.wait(lk);
        if (!run_) {
          break;
        }
        server_->processOne();
      }
    });

    // wait for setup of thread
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  void TearDown() override {
    run_ = false;
    rpc_ready_.notify_one();
    thread_->join();
  }

  std::shared_ptr<MockServiceHandler> handler_;
  std::unique_ptr<TestSimpleJsonServer> server_;
  int port_;
  bool run_ = true;
  std::unique_ptr<std::thread> thread_;
  std::condition_variable rpc_ready_;
  std::mutex mutex_;
};

TEST_F(SimpleJsonClientTest, StatusTest) {
  rpc_ready_.notify_one();

  auto client = std::make_unique<SimpleJsonServerClient>("::1", port_);
  ASSERT_TRUE(client->initSuccessful())
      << "Failed to connect to port " << port_;

  json request{
      {"fn", "getStatus"},
  };

  auto resp_str = client->invoke_rpc(request.dump());
  client.reset(); // disconnect

  ASSERT_TRUE(resp_str) << "Null response on getStatus()";
  EXPECT_EQ(handler_->statusCalls_, 1);

  json resp = json::parse(resp_str.value());
  EXPECT_EQ(resp["status"], 0);

  handler_->status_ = 1;
  rpc_ready_.notify_one();

  // Create a new connection for new rpc
  client = std::make_unique<SimpleJsonServerClient>("::1", port_);
  resp_str = client->invoke_rpc(request.dump());
  client.reset(); // disconnect

  ASSERT_TRUE(resp_str) << "Null response on getStatus()";
  EXPECT_EQ(handler_->statusCalls_, 2);

  resp = json::parse(resp_str.value());
  EXPECT_EQ(resp["status"], 1);
}

TEST_F(SimpleJsonClientTest, SetKinetoOnDemandRequestTest) {
  rpc_ready_.notify_one();

  auto client = std::make_unique<SimpleJsonServerClient>("::1", port_);
  ASSERT_TRUE(client->initSuccessful())
      << "Failed to connect to port " << port_;

  GpuProfilerResult expected_result{
      .processesMatched = {123},
      .eventProfilersTriggered = {},
      .activityProfilersTriggered = {123},
      .eventProfilersBusy = 0,
      .activityProfilersBusy = 1};

  handler_->result = expected_result;

  json bad_request{
      {"fn", "setKinetOnDemandRequest"},
      {"config", "TEST_CONFIG_STRING"},
      {"pids", {123, 456}},
      {"job_id", "10"}, // job_id is formatted wrong - should be int
      {"process_limit", 42},
  };

  auto resp_str = client->invoke_rpc(bad_request.dump());
  client.reset(); // disconnect

  ASSERT_TRUE(resp_str) << "Null response on setKinetOnDemandRequest()";

  json resp = json::parse(resp_str.value());
  ASSERT_TRUE(resp.contains("status"));
  LOG(INFO) << "Returned status " << resp["status"];
  ASSERT_NE(
      resp["status"].get<std::string>().find("json.exception"),
      std::string::npos);

  rpc_ready_.notify_one();

  // A good request is now sent
  json request{
      {"fn", "setKinetOnDemandRequest"},
      {"config", "TEST_CONFIG_STRING"},
      {"pids", {123, 456}},
      {"job_id", 10},
      {"process_limit", 42},
  };

  // Create a new connection for new rpc
  client = std::make_unique<SimpleJsonServerClient>("::1", port_);
  resp_str = client->invoke_rpc(request.dump());
  client.reset(); // disconnect

  ASSERT_TRUE(resp_str) << "Null response on setKinetOnDemandRequest()";
  EXPECT_EQ(handler_->setKinetoOnDemandCalls_, 1);

  EXPECT_EQ(handler_->config_, request["config"]);
  EXPECT_EQ(handler_->pids_, request["pids"]);
  EXPECT_EQ(handler_->job_id_, 10);
  EXPECT_EQ(handler_->limit_, 42);

  resp = json::parse(resp_str.value());

  EXPECT_EQ(
      resp["processesMatched"].get<std::vector<int>>(),
      expected_result.processesMatched);
  EXPECT_EQ(
      resp["activityProfilersTriggered"].get<std::vector<int>>(),
      expected_result.activityProfilersTriggered);
  EXPECT_EQ(
      resp["eventProfilersTriggered"].get<std::vector<int>>(),
      expected_result.eventProfilersTriggered);

  EXPECT_EQ(resp["eventProfilersBusy"], expected_result.eventProfilersBusy);
  EXPECT_EQ(
      resp["activityProfilersBusy"], expected_result.activityProfilersBusy);
}

} // namespace dynolog
