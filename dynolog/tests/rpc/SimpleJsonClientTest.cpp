// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/tests/rpc/SimpleJsonClientTest.h"
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

  std::string getVersion() {
    versionCalls_++;
    return version_;
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

  bool dcgmProfPause(int duration_s) {
    duration_s_ = duration_s;
    dcgm_prof_enabled_ = false;
    dcgmProfPauseCalls_++;
    return true;
  }

  bool dcgmProfResume() {
    dcgm_prof_enabled_ = true;
    dcgmProfResumeCalls_++;
    return true;
  }

  int status_ = 0;
  std::string version_ = "0.0.0";
  int statusCalls_ = 0;
  int versionCalls_ = 0;
  GpuProfilerResult result;

  int setKinetoOnDemandCalls_ = 0;
  int job_id_ = -1;
  std::set<int> pids_;
  std::string config_;
  int limit_ = -1;
  int duration_s_ = -1;
  bool dcgm_prof_enabled_ = true;
  int dcgmProfPauseCalls_ = 0;
  int dcgmProfResumeCalls_ = 0;
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
  std::mutex serialized_test_mutex_;
};

TEST_F(SimpleJsonClientTest, DISABLED_StatusTest) {
  std::unique_lock slk(serialized_test_mutex_);

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

TEST_F(SimpleJsonClientTest, DISABLED_SetKinetoOnDemandRequestTest) {
  std::unique_lock slk(serialized_test_mutex_);

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

  EXPECT_EQ(request["config"], handler_->config_);
  EXPECT_EQ(request["pids"], handler_->pids_);
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

TEST_F(SimpleJsonClientTest, DISABLED_DcgmTest) {
  std::unique_lock slk(serialized_test_mutex_);

  rpc_ready_.notify_one();
  auto client = std::make_unique<SimpleJsonServerClient>("::1", port_);
  ASSERT_TRUE(client->initSuccessful())
      << "Failed to connect to port " << port_;

  json request_pause{
      {"fn", "dcgmProfPause"},
      {"duration_s", 100},
  };

  auto resp_str = client->invoke_rpc(request_pause.dump());
  client.reset(); // disconnect

  ASSERT_TRUE(resp_str) << "Null response on dcgmProfPause()";
  EXPECT_EQ(handler_->dcgmProfPauseCalls_, 1);
  EXPECT_EQ(handler_->dcgm_prof_enabled_, false);
  EXPECT_EQ(handler_->duration_s_, 100);

  json resp = json::parse(resp_str.value());
  EXPECT_EQ(resp["status"], true);

  rpc_ready_.notify_one();

  json request_resume{
      {"fn", "dcgmProfResume"},
  };
  // Create a new connection for new rpc
  client = std::make_unique<SimpleJsonServerClient>("::1", port_);
  resp_str = client->invoke_rpc(request_resume.dump());
  client.reset(); // disconnect

  ASSERT_TRUE(resp_str) << "Null response on dcgmProfResume()";
  EXPECT_EQ(handler_->dcgmProfResumeCalls_, 1);

  resp = json::parse(resp_str.value());
  EXPECT_EQ(resp["status"], true);
  EXPECT_EQ(handler_->dcgm_prof_enabled_, true);
}

TEST_F(SimpleJsonClientTest, DISABLED_VersionTest) {
  std::unique_lock slk(serialized_test_mutex_);

  rpc_ready_.notify_one();
  auto client = std::make_unique<SimpleJsonServerClient>("::1", port_);
  ASSERT_TRUE(client->initSuccessful())
      << "Failed to connect to port " << port_;

  json request{
      {"fn", "getVersion"},
  };

  auto resp_str = client->invoke_rpc(request.dump());
  client.reset(); // disconnect

  ASSERT_TRUE(resp_str) << "Null response on getVersion()";
  EXPECT_EQ(handler_->versionCalls_, 1);

  json resp = json::parse(resp_str.value());
  EXPECT_EQ(resp["version"], "0.0.0");

  handler_->status_ = 1;
  rpc_ready_.notify_one();

  // Create a new connection for new rpc
  client = std::make_unique<SimpleJsonServerClient>("::1", port_);
  resp_str = client->invoke_rpc(request.dump());
  client.reset(); // disconnect

  ASSERT_TRUE(resp_str) << "Null response on getVersion()";
  EXPECT_EQ(handler_->versionCalls_, 2);

  resp = json::parse(resp_str.value());
  EXPECT_EQ(resp["version"], "0.0.0");
}

} // namespace dynolog
