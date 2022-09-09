// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <condition_variable>
#include <mutex>

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "SimpleJsonClientTest.h"
#include "SimpleJsonServer.h" // @manual=//dynolog/src/rpc:libsimplejsonserver
#include "SimpleJsonServerInl.h" // @manual=//dynolog/src/rpc:libsimplejsonserver

namespace dynolog {

using json = nlohmann::json;

struct MockServiceHandler {
  int getStatus() {
    statusCalls_++;
    return status_;
  }

  int status_ = 0;
  int statusCalls_ = 0;
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

} // namespace dynolog
