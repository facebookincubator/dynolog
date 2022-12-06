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

DEFINE_string(category_id, "", "The category id of the ODS endpoint");
DEFINE_string(ods_entity_prefix, "", "The prefix for ODS entity name");

namespace dynolog {
constexpr int HOSTNAME_MAX = 50;
constexpr char kODSUrl[] = "https://graph.facebook.com/v2.2/ods_metrics";

ODSJsonLogger::ODSJsonLogger() {
  char hostname[HOSTNAME_MAX];
  gethostname(hostname, HOSTNAME_MAX);
  hostname_ = std::string(hostname);
}

void ODSJsonLogger::finalize() {
  std::string entity = FLAGS_ods_entity_prefix + hostname_;
  nlohmann::json metrics = sampleJson();

  if (metrics.find("device") != metrics.end()) {
    entity += ".gpu." + std::to_string(metrics["device"].get<int>());
  }

  nlohmann::json out_array;
  for (auto it = metrics.begin(); it != metrics.end(); ++it) {
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

  JsonLogger::finalize();
}

} // namespace dynolog
