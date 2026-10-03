/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/k8s/K8sPodCache.h"

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <unistd.h>

#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <fstream>
#include <mutex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

namespace dynolog::k8s {
namespace {

using namespace std::chrono_literals;
using json = nlohmann::json;

class TempToken {
 public:
  TempToken() {
    char path[] = "/tmp/k8s-pod-cache-token-XXXXXX";
    const int fd = mkstemp(path);
    EXPECT_NE(fd, -1);
    if (fd != -1) {
      close(fd);
    }
    path_ = path;
    write("token-one");
  }

  ~TempToken() {
    std::remove(path_.c_str());
  }

  void write(const std::string& token) const {
    std::ofstream output(path_, std::ios::trunc);
    output << token << '\n';
  }

  const std::string& path() const {
    return path_;
  }

 private:
  std::string path_;
};

template <typename Predicate>
void waitFor(
    std::mutex& mutex,
    std::condition_variable& cv,
    Predicate predicate) {
  std::unique_lock<std::mutex> lock(mutex);
  ASSERT_TRUE(cv.wait_for(lock, 5s, std::move(predicate)));
}

json makePod(
    std::string uid,
    std::string phase,
    std::string resourceVersion,
    std::string name = "pod-a") {
  return {
      {"metadata",
       {{"namespace", "test-ns"},
        {"name", std::move(name)},
        {"uid", std::move(uid)},
        {"resourceVersion", std::move(resourceVersion)},
        {"labels", {{"app.kubernetes.io/component", "trainer"}}},
        {"ownerReferences", {{{"kind", "Job"}, {"name", "train-job"}}}}}},
      {"spec",
       {{"nodeName", "node-a"},
        {"serviceAccountName", "trainer-sa"},
        {"containers",
         {{{"name", "worker"},
           {"env",
            {{{"name", "LITERAL"}, {"value", "value"}},
             {{"name", "POD_UID"},
              {"valueFrom",
               {{"fieldRef", {{"fieldPath", "metadata.uid"}}}}}}}}}}}}},
      {"status", {{"phase", std::move(phase)}}},
  };
}

std::string listResponse(
    std::vector<json> pods,
    std::string resourceVersion,
    std::string continueToken = {}) {
  return json{
      {"metadata",
       {{"resourceVersion", std::move(resourceVersion)},
        {"continue", std::move(continueToken)}}},
      {"items", std::move(pods)},
  }
      .dump();
}

std::string watchEvent(const std::string& type, json object) {
  return json{{"type", type}, {"object", std::move(object)}}.dump() + "\n";
}

K8sPodCache::HttpResult emit(
    const K8sPodCache::ChunkCallback& onChunk,
    const std::string& body,
    long statusCode = 200) {
  return {onChunk(body), statusCode};
}

K8sPodCache::Options watchOptions(
    const TempToken& token,
    K8sPodCache::HttpRequest request) {
  K8sPodCache::Options opts;
  opts.apiBase = "https://kubernetes.test";
  opts.tokenPath = token.path();
  opts.caPath.clear();
  opts.enableWatch = true;
  opts.nodeName = "node-a";
  opts.reconnectDelay = 1ms;
  opts.httpRequest = std::move(request);
  return opts;
}

const K8sPodCache::EnvKeyMap kEnvMap = {
    {"LITERAL", "literal"},
    {"POD_UID", "downward_uid"},
};
const K8sPodCache::LabelKeyMap kLabelMap = {
    {"app.kubernetes.io/component", "component"},
};

TEST(K8sPodCacheTest, PaginatedListAndUidMatchedWatchDelete) {
  TempToken token;
  struct State {
    std::mutex mutex;
    std::condition_variable cv;
    int listCalls = 0;
    bool mismatchApplied = false;
    bool releaseMatchingDelete = false;
    bool matchingDeleteApplied = false;
    std::vector<std::string> urls;
  } state;

  auto request = [&](const std::string& url,
                     const std::string&,
                     bool streaming,
                     const K8sPodCache::ChunkCallback& onChunk,
                     const K8sPodCache::StopCallback& shouldStop) {
    {
      std::lock_guard<std::mutex> lock(state.mutex);
      state.urls.push_back(url);
    }
    if (!streaming) {
      if (url.find("/namespaces/") != std::string::npos) {
        return K8sPodCache::HttpResult{true, 404};
      }
      int page = 0;
      {
        std::lock_guard<std::mutex> lock(state.mutex);
        page = state.listCalls++;
      }
      if (page == 0) {
        return emit(
            onChunk,
            listResponse(
                {makePod("uid-a", "Running", "10")}, "10", "next/+ token"));
      }
      return emit(
          onChunk,
          listResponse({makePod("uid-b", "Pending", "10", "pod-b")}, "10"));
    }

    const std::string modified =
        watchEvent("MODIFIED", makePod("uid-a", "Succeeded", "11"));
    const std::string staleDelete =
        watchEvent("DELETED", makePod("old-uid", "Failed", "12"));
    const std::string firstFrames = modified + staleDelete;
    EXPECT_TRUE(onChunk(std::string_view(firstFrames).substr(0, 17)));
    EXPECT_TRUE(onChunk(std::string_view(firstFrames).substr(17)));
    {
      std::unique_lock<std::mutex> lock(state.mutex);
      state.mismatchApplied = true;
      state.cv.notify_all();
      state.cv.wait(
          lock, [&] { return state.releaseMatchingDelete || shouldStop(); });
    }
    if (!shouldStop()) {
      EXPECT_TRUE(
          onChunk(watchEvent("DELETED", makePod("uid-a", "Succeeded", "13"))));
      std::lock_guard<std::mutex> lock(state.mutex);
      state.matchingDeleteApplied = true;
      state.cv.notify_all();
    }
    while (!shouldStop()) {
      std::this_thread::yield();
    }
    return K8sPodCache::HttpResult{false, 200};
  };

  K8sPodCache cache(watchOptions(token, request));
  waitFor(state.mutex, state.cv, [&] { return state.mismatchApplied; });

  const auto podA =
      cache.lookupAttribution("test-ns", "pod-a", "worker", kEnvMap, kLabelMap);
  EXPECT_EQ(podA.at("pod_uid"), "uid-a");
  EXPECT_EQ(podA.at("pod_phase"), "Succeeded");
  EXPECT_EQ(podA.at("downward_uid"), "uid-a");
  EXPECT_EQ(podA.at("literal"), "value");
  EXPECT_EQ(podA.at("component"), "trainer");
  EXPECT_EQ(podA.at("service_account"), "trainer-sa");
  EXPECT_EQ(podA.at("controller_kind"), "Job");
  EXPECT_EQ(podA.at("controller_name"), "train-job");

  const auto podB =
      cache.lookupAttribution("test-ns", "pod-b", "worker", kEnvMap, kLabelMap);
  EXPECT_EQ(podB.at("pod_uid"), "uid-b");
  EXPECT_EQ(podB.at("pod_phase"), "Pending");

  {
    std::lock_guard<std::mutex> lock(state.mutex);
    ASSERT_GE(state.urls.size(), 3u);
    EXPECT_NE(
        state.urls[0].find("fieldSelector=spec.nodeName%3Dnode-a"),
        std::string::npos);
    EXPECT_NE(
        state.urls[1].find("continue=next%2F%2B%20token"), std::string::npos);
    EXPECT_NE(state.urls[2].find("resourceVersion=10"), std::string::npos);
    state.releaseMatchingDelete = true;
    state.cv.notify_all();
  }
  waitFor(state.mutex, state.cv, [&] { return state.matchingDeleteApplied; });
  EXPECT_TRUE(
      cache.lookupAttribution("test-ns", "pod-a", "worker", kEnvMap, kLabelMap)
          .empty());
}

TEST(K8sPodCacheTest, RelistsOnHttpAndEventGoneAndRereadsToken) {
  TempToken token;
  struct State {
    std::mutex mutex;
    std::condition_variable cv;
    int listCalls = 0;
    int watchCalls = 0;
    bool firstWatchEntered = false;
    bool releaseHttpGone = false;
    bool failedRelistEntered = false;
    bool releaseFailedRelist = false;
    bool finalWatchEntered = false;
    std::vector<std::string> urls;
    std::vector<std::string> tokens;
  } state;

  auto request = [&](const std::string& url,
                     const std::string& bearerToken,
                     bool streaming,
                     const K8sPodCache::ChunkCallback& onChunk,
                     const K8sPodCache::StopCallback& shouldStop) {
    {
      std::lock_guard<std::mutex> lock(state.mutex);
      state.urls.push_back(url);
      state.tokens.push_back(bearerToken);
    }
    if (!streaming) {
      int listCall = 0;
      {
        std::lock_guard<std::mutex> lock(state.mutex);
        listCall = state.listCalls++;
      }
      if (listCall == 0) {
        return emit(
            onChunk, listResponse({makePod("uid-old", "Running", "1")}, "1"));
      }
      if (listCall == 1) {
        std::unique_lock<std::mutex> lock(state.mutex);
        state.failedRelistEntered = true;
        state.cv.notify_all();
        state.cv.wait(
            lock, [&] { return state.releaseFailedRelist || shouldStop(); });
        return K8sPodCache::HttpResult{true, 500};
      }
      if (listCall == 2) {
        return emit(
            onChunk,
            listResponse({makePod("uid-middle", "Pending", "2")}, "2"));
      }
      return emit(
          onChunk, listResponse({makePod("uid-new", "Succeeded", "3")}, "3"));
    }

    int watchCall = 0;
    {
      std::lock_guard<std::mutex> lock(state.mutex);
      watchCall = state.watchCalls++;
    }
    if (watchCall == 0) {
      std::unique_lock<std::mutex> lock(state.mutex);
      state.firstWatchEntered = true;
      state.cv.notify_all();
      state.cv.wait(
          lock, [&] { return state.releaseHttpGone || shouldStop(); });
      return K8sPodCache::HttpResult{true, 410};
    }
    if (watchCall == 1) {
      const auto error =
          json{
              {"type", "ERROR"},
              {"object",
               {{"kind", "Status"}, {"code", 410}, {"reason", "Expired"}}},
          }
              .dump() +
          "\n";
      return K8sPodCache::HttpResult{onChunk(error), 200};
    }

    {
      std::lock_guard<std::mutex> lock(state.mutex);
      state.finalWatchEntered = true;
      state.cv.notify_all();
    }
    while (!shouldStop()) {
      std::this_thread::yield();
    }
    return K8sPodCache::HttpResult{false, 200};
  };

  K8sPodCache cache(watchOptions(token, request));
  waitFor(state.mutex, state.cv, [&] { return state.firstWatchEntered; });
  token.write("token-two");
  {
    std::lock_guard<std::mutex> lock(state.mutex);
    state.releaseHttpGone = true;
    state.cv.notify_all();
  }
  waitFor(state.mutex, state.cv, [&] { return state.failedRelistEntered; });
  EXPECT_EQ(
      cache.lookupAttribution("test-ns", "pod-a", "worker", kEnvMap, kLabelMap)
          .at("pod_uid"),
      "uid-old");
  {
    std::lock_guard<std::mutex> lock(state.mutex);
    state.releaseFailedRelist = true;
    state.cv.notify_all();
  }
  waitFor(state.mutex, state.cv, [&] { return state.finalWatchEntered; });

  const auto attrs =
      cache.lookupAttribution("test-ns", "pod-a", "worker", kEnvMap, kLabelMap);
  EXPECT_EQ(attrs.at("pod_uid"), "uid-new");
  EXPECT_EQ(attrs.at("pod_phase"), "Succeeded");

  std::lock_guard<std::mutex> lock(state.mutex);
  ASSERT_GE(state.tokens.size(), 7u);
  EXPECT_EQ(state.tokens[0], "token-one");
  EXPECT_EQ(state.tokens[1], "token-one");
  EXPECT_EQ(state.tokens[2], "token-two");
  EXPECT_NE(state.urls[1].find("resourceVersion=1"), std::string::npos);
  EXPECT_NE(state.urls[4].find("resourceVersion=2"), std::string::npos);
  EXPECT_NE(state.urls[6].find("resourceVersion=3"), std::string::npos);
}

TEST(K8sPodCacheTest, BookmarkReconnectAndOversizedFrameRelist) {
  TempToken token;
  struct State {
    std::mutex mutex;
    std::condition_variable cv;
    int listCalls = 0;
    int watchCalls = 0;
    bool oversizedRejected = false;
    bool finalWatchEntered = false;
    std::vector<std::string> watchUrls;
  } state;

  auto request = [&](const std::string& url,
                     const std::string&,
                     bool streaming,
                     const K8sPodCache::ChunkCallback& onChunk,
                     const K8sPodCache::StopCallback& shouldStop) {
    if (!streaming) {
      int call = 0;
      {
        std::lock_guard<std::mutex> lock(state.mutex);
        call = state.listCalls++;
      }
      return emit(onChunk, listResponse({}, call == 0 ? "1" : "3"));
    }

    int call = 0;
    {
      std::lock_guard<std::mutex> lock(state.mutex);
      state.watchUrls.push_back(url);
      call = state.watchCalls++;
    }
    if (call == 0) {
      EXPECT_TRUE(onChunk(watchEvent(
          "BOOKMARK", json{{"metadata", {{"resourceVersion", "2"}}}})));
      return K8sPodCache::HttpResult{true, 200};
    }
    if (call == 1) {
      const std::string oversizedFrame =
          watchEvent("ADDED", makePod("uid-large", "Running", "3"));
      EXPECT_GT(oversizedFrame.size(), 128u);
      const bool accepted = onChunk(oversizedFrame);
      std::lock_guard<std::mutex> lock(state.mutex);
      state.oversizedRejected = !accepted;
      state.cv.notify_all();
      return K8sPodCache::HttpResult{accepted, 200};
    }
    {
      std::lock_guard<std::mutex> lock(state.mutex);
      state.finalWatchEntered = true;
      state.cv.notify_all();
    }
    while (!shouldStop()) {
      std::this_thread::yield();
    }
    return K8sPodCache::HttpResult{false, 200};
  };

  auto opts = watchOptions(token, request);
  opts.maxWatchEventBytes = 128;
  K8sPodCache cache(std::move(opts));
  waitFor(state.mutex, state.cv, [&] { return state.finalWatchEntered; });

  std::lock_guard<std::mutex> lock(state.mutex);
  EXPECT_TRUE(state.oversizedRejected);
  ASSERT_EQ(state.listCalls, 2);
  ASSERT_GE(state.watchUrls.size(), 3u);
  EXPECT_NE(state.watchUrls[1].find("resourceVersion=2"), std::string::npos);
  EXPECT_NE(state.watchUrls[2].find("resourceVersion=3"), std::string::npos);
}

TEST(K8sPodCacheTest, DeleteTombstoneRejectsOlderFallbackGet) {
  TempToken token;
  struct State {
    std::mutex mutex;
    std::condition_variable cv;
    bool watchEntered = false;
    bool getEntered = false;
    bool deleteApplied = false;
    int getCalls = 0;
  } state;

  auto request = [&](const std::string& url,
                     const std::string&,
                     bool streaming,
                     const K8sPodCache::ChunkCallback& onChunk,
                     const K8sPodCache::StopCallback& shouldStop) {
    if (!streaming && url.find("/namespaces/") == std::string::npos) {
      return emit(onChunk, listResponse({}, "1"));
    }
    if (streaming) {
      {
        std::unique_lock<std::mutex> lock(state.mutex);
        state.watchEntered = true;
        state.cv.notify_all();
        state.cv.wait(lock, [&] { return state.getEntered || shouldStop(); });
      }
      if (!shouldStop()) {
        EXPECT_TRUE(
            onChunk(watchEvent("DELETED", makePod("uid-old", "Failed", "2"))));
        std::lock_guard<std::mutex> lock(state.mutex);
        state.deleteApplied = true;
        state.cv.notify_all();
      }
      while (!shouldStop()) {
        std::this_thread::yield();
      }
      return K8sPodCache::HttpResult{false, 200};
    }

    {
      std::unique_lock<std::mutex> lock(state.mutex);
      ++state.getCalls;
      state.getEntered = true;
      state.cv.notify_all();
      state.cv.wait(lock, [&] { return state.deleteApplied || shouldStop(); });
    }
    return emit(onChunk, makePod("uid-old", "Running", "1").dump());
  };

  K8sPodCache cache(watchOptions(token, request));
  waitFor(state.mutex, state.cv, [&] { return state.watchEntered; });
  const auto attrs =
      cache.lookupAttribution("test-ns", "pod-a", "worker", kEnvMap, kLabelMap);
  EXPECT_TRUE(attrs.empty());
  EXPECT_TRUE(
      cache.lookupAttribution("test-ns", "pod-a", "worker", kEnvMap, kLabelMap)
          .empty());
  EXPECT_EQ(state.getCalls, 1);
}

TEST(K8sPodCacheTest, FallbackGetIsSingleFlightPerPod) {
  TempToken token;
  struct State {
    std::mutex mutex;
    std::condition_variable cv;
    bool getEntered = false;
    bool secondLookupWaiting = false;
    int getCalls = 0;
  } state;

  K8sPodCache::Options opts;
  opts.apiBase = "https://kubernetes.test";
  opts.tokenPath = token.path();
  opts.caPath.clear();
  opts.onFallbackWait = [&] {
    std::lock_guard<std::mutex> lock(state.mutex);
    state.secondLookupWaiting = true;
    state.cv.notify_all();
  };
  opts.httpRequest = [&](const std::string&,
                         const std::string&,
                         bool,
                         const K8sPodCache::ChunkCallback& onChunk,
                         const K8sPodCache::StopCallback&) {
    {
      std::unique_lock<std::mutex> lock(state.mutex);
      ++state.getCalls;
      state.getEntered = true;
      state.cv.notify_all();
      state.cv.wait(lock, [&] { return state.secondLookupWaiting; });
    }
    return emit(onChunk, makePod("uid-one", "Running", "1").dump());
  };

  K8sPodCache cache(std::move(opts));
  std::unordered_map<std::string, std::string> first;
  std::unordered_map<std::string, std::string> second;
  std::thread firstLookup([&] {
    first = cache.lookupAttribution(
        "test-ns", "pod-a", "worker", kEnvMap, kLabelMap);
  });
  waitFor(state.mutex, state.cv, [&] { return state.getEntered; });
  std::thread secondLookup([&] {
    second = cache.lookupAttribution(
        "test-ns", "pod-a", "worker", kEnvMap, kLabelMap);
  });
  waitFor(state.mutex, state.cv, [&] { return state.secondLookupWaiting; });
  firstLookup.join();
  secondLookup.join();

  EXPECT_EQ(state.getCalls, 1);
  EXPECT_EQ(first.at("pod_uid"), "uid-one");
  EXPECT_EQ(second.at("pod_uid"), "uid-one");
  EXPECT_EQ(first.at("pod_phase"), "Running");
}

TEST(K8sPodCacheTest, ListReconcileRejectsOlderFallbackGet) {
  TempToken token;
  struct State {
    std::mutex mutex;
    std::condition_variable cv;
    int listCalls = 0;
    int watchCalls = 0;
    bool firstWatchEntered = false;
    bool getEntered = false;
    bool secondWatchEntered = false;
    int getCalls = 0;
  } state;

  auto request = [&](const std::string& url,
                     const std::string&,
                     bool streaming,
                     const K8sPodCache::ChunkCallback& onChunk,
                     const K8sPodCache::StopCallback& shouldStop) {
    if (!streaming && url.find("/namespaces/") == std::string::npos) {
      int call = 0;
      {
        std::lock_guard<std::mutex> lock(state.mutex);
        call = state.listCalls++;
      }
      return emit(onChunk, listResponse({}, call == 0 ? "1" : "2"));
    }
    if (streaming) {
      int call = 0;
      {
        std::lock_guard<std::mutex> lock(state.mutex);
        call = state.watchCalls++;
      }
      if (call == 0) {
        std::unique_lock<std::mutex> lock(state.mutex);
        state.firstWatchEntered = true;
        state.cv.notify_all();
        state.cv.wait(lock, [&] { return state.getEntered || shouldStop(); });
        return K8sPodCache::HttpResult{true, 410};
      }
      {
        std::lock_guard<std::mutex> lock(state.mutex);
        state.secondWatchEntered = true;
        state.cv.notify_all();
      }
      while (!shouldStop()) {
        std::this_thread::yield();
      }
      return K8sPodCache::HttpResult{false, 200};
    }

    {
      std::unique_lock<std::mutex> lock(state.mutex);
      ++state.getCalls;
      state.getEntered = true;
      state.cv.notify_all();
      state.cv.wait(
          lock, [&] { return state.secondWatchEntered || shouldStop(); });
    }
    return emit(onChunk, makePod("uid-stale", "Running", "1").dump());
  };

  K8sPodCache cache(watchOptions(token, request));
  waitFor(state.mutex, state.cv, [&] { return state.firstWatchEntered; });
  const auto attrs =
      cache.lookupAttribution("test-ns", "pod-a", "worker", kEnvMap, kLabelMap);
  EXPECT_TRUE(attrs.empty());
  EXPECT_TRUE(
      cache.lookupAttribution("test-ns", "pod-a", "worker", kEnvMap, kLabelMap)
          .empty());
  EXPECT_EQ(state.getCalls, 1);
}

TEST(K8sPodCacheTest, DestructorCancelsAndJoinsIdleWatch) {
  TempToken token;
  std::atomic<bool> watchEntered{false};
  std::atomic<bool> watchExited{false};
  auto request = [&](const std::string&,
                     const std::string&,
                     bool streaming,
                     const K8sPodCache::ChunkCallback& onChunk,
                     const K8sPodCache::StopCallback& shouldStop) {
    if (!streaming) {
      return emit(onChunk, listResponse({}, "1"));
    }
    watchEntered.store(true);
    while (!shouldStop()) {
      std::this_thread::yield();
    }
    watchExited.store(true);
    return K8sPodCache::HttpResult{false, 200};
  };

  {
    K8sPodCache cache(watchOptions(token, request));
    for (size_t i = 0; i < 100000 && !watchEntered.load(); ++i) {
      std::this_thread::yield();
    }
    ASSERT_TRUE(watchEntered.load());
  }
  EXPECT_TRUE(watchExited.load());
}

} // namespace
} // namespace dynolog::k8s
