// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/ScubaLogger.h"
#include <string>
#ifdef USE_GRAPH_ENDPOINT
#include <cpr/cpr.h> // @manual
#include <curl/curl.h> // @manual
#endif
#include <fmt/format.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <unistd.h>
#include <chrono>

namespace dynolog {
constexpr int HOSTNAME_MAX = 50;
constexpr char kScubaUrl[] = "https://graph.facebook.com/scribe_logs";
DEFINE_string(
    scribe_category,
    "perfpipe_fair_cluster_gpu_stats",
    "The scribe category name for scuba logging");

ScubaLogger::ScubaLogger(const std::string& scribe_category)
    : scribe_category_(scribe_category) {
  char hostname[HOSTNAME_MAX] = "";
  gethostname(hostname, HOSTNAME_MAX);
  hostname_ = std::string(hostname);
}

void ScubaLogger::logInt(const std::string& key, int64_t val) {
  metrics_int_[key] = val;
}

void ScubaLogger::logUint(const std::string& key, uint64_t val) {
  metrics_int_[key] = val;
}

void ScubaLogger::logFloat(const std::string& key, float val) {
  metrics_double_[key] = val;
}

void ScubaLogger::logStr(const std::string& key, const std::string& val) {
  metrics_str_[key] = val;
}

void ScubaLogger::clearMetrics() {
  metrics_int_.clear();
  metrics_str_.clear();
  metrics_double_.clear();
}

void ScubaLogger::finalize() {
  metrics_str_["host_name"] = hostname_;

  // user of logger need to set time
  metrics_int_["time"] =
      std::chrono::duration_cast<std::chrono::seconds>(ts_.time_since_epoch())
          .count();

  nlohmann::json scuba_message = {
      {"int", metrics_int_},
      {"normal", metrics_str_},
      {"double", metrics_double_},
  };

  nlohmann::json log = {
      {"category", scribe_category_},
      {"message", scuba_message.dump()},
      {"line_escape", false},
  };

  nlohmann::json logs;
  logs.push_back(log);

#ifdef USE_GRAPH_ENDPOINT
  cpr::SslOptions sslOpts =
      cpr::Ssl(cpr::ssl::CaInfo{FLAGS_certificate_path.c_str()});

  cpr::Response r = cpr::Post(
      cpr::Url{kScubaUrl},
      cpr::Payload{{"access_token", FLAGS_access_token}, {"logs", logs.dump()}},
      sslOpts);

  // flush the logger
  if (r.status_code != 200) {
    LOG(ERROR) << "Scuba publish request failed: " << r.text;
  }
#else
  LOG_FIRST_N(WARNING, 1) << "Scuba logger was not included in the build";
#endif

  LOG(INFO) << logs.dump();
  clearMetrics();
}

} // namespace dynolog
