// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/ODSJsonLogger.h"
#ifdef USE_GRAPH_ENDPOINT
#include <cpr/cpr.h> // @manual
#include <curl/curl.h> // @manual
#endif
#include <fmt/format.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <unistd.h>

DEFINE_string(
    access_token,
    "",
    "The ODS access token to publish through Graph API");
DEFINE_string(category_id, "", "The category id of the ODS endpoint");
DEFINE_string(
    certificate_path,
    "/etc/ssl/certs/ca-certificates.crt",
    "The path for SSL certificate");
DEFINE_string(ods_entity_prefix, "", "The prefix for ODS entity name");

namespace dynolog {
constexpr int HOSTNAME_MAX = 50;
constexpr char kODSUrl[] = "https://graph.facebook.com/v2.2/ods_metrics";

ODSJsonLogger::ODSJsonLogger() {
  char hostname[HOSTNAME_MAX];
  gethostname(hostname, HOSTNAME_MAX);
  hostname_ = std::string(hostname);
}

void ODSJsonLogger::logInt(const std::string& key, int64_t val) {
  metrics_json_[key] = val;
}

void ODSJsonLogger::logFloat(const std::string& key, float val) {
  metrics_json_[key] = fmt::format("{:.3f}", val);
}

void ODSJsonLogger::finalize() {
  std::string entity = FLAGS_ods_entity_prefix + hostname_;

  if (metrics_json_.find("device") != metrics_json_.end()) {
    entity += ".gpu." + std::to_string(metrics_json_["device"].get<int>());
  }

  nlohmann::json out_array;
  for (auto it = metrics_json_.begin(); it != metrics_json_.end(); ++it) {
    if (it.key() == "device") {
      continue;
    }
    nlohmann::json datapoint = {
        {"entity", entity},
        {"key", "dynolog." + it.key()},
        {"value", it.value()},
    };
    out_array.push_back(datapoint);
  }

  std::string s = out_array.dump();
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '\"') {
      s[i] = '\'';
    }
  }

#ifdef USE_GRAPH_ENDPOINT
  cpr::SslOptions sslOpts =
      cpr::Ssl(cpr::ssl::CaInfo{FLAGS_certificate_path.c_str()});

  cpr::Response r = cpr::Post(
      cpr::Url{kODSUrl},
      cpr::Payload{
          {"access_token", FLAGS_access_token},
          {"datapoints", out_array.dump()},
          {"category_id", FLAGS_category_id}},
      sslOpts);

  // flush the logger
  if (r.status_code != 200) {
    LOG(ERROR) << "ODS publish request failed: " << r.text;
  }
#else
  LOG_FIRST_N(WARNING, 1) << "ODS logger was not included in the build";
#endif

  LOG(INFO) << out_array.dump();
  metrics_json_.clear();
}

} // namespace dynolog
