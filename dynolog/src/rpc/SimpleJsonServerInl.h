// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <fmt/format.h>
#include <glog/logging.h>
#include <nlohmann/json.hpp>
#include "dynolog/src/rpc/SimpleJsonServer.h"

namespace dynolog {

template <class TServiceHandler = ServiceHandler>
class SimpleJsonServer : public SimpleJsonServerBase {
 public:
  explicit SimpleJsonServer(std::shared_ptr<TServiceHandler> handler, int port)
      : SimpleJsonServerBase(port), handler_(std::move(handler)) {}

  ~SimpleJsonServer() {}

  std::string processOneImpl(const std::string& request) override;

 private:
  std::shared_ptr<TServiceHandler> handler_;
};

// convert to json and validate the request message
// the request should contain :
//   { "fn" : "<rpc_function>"
//    .. <add other args>
//   }

nlohmann::json toJson(const std::string& message) {
  using json = nlohmann::json;
  json result;
  if (message.empty()) {
    return result;
  }
  try {
    result = json::parse(message);
  } catch (json::parse_error& ex) {
    LOG(ERROR) << "Error parsing message = " << message;
    return result;
  }

  if (result.empty() || !result.is_object()) {
    LOG(ERROR)
        << "Request message should not be empty and should be json object.";
    return json();
  }

  if (!result.contains("fn")) {
    LOG(ERROR) << "Request must contain a 'fn' field for the RPC call "
               << " request json = " << result.dump();
    return json();
  }

  return result;
}

template <class TServiceHandler>
std::string SimpleJsonServer<TServiceHandler>::processOneImpl(
    const std::string& request_str) {
  using json = nlohmann::json;
  json request = toJson(request_str);
  json response;

  if (request.empty()) {
    LOG(ERROR) << "Failed parsing request, continuing ...";
    return "";
  }

  if (request["fn"] == "getStatus") {
    int status = handler_->getStatus();
    response["status"] = status;
  } else if (request["fn"] == "setKinetOnDemandRequest") {
    if (!request.contains("config") || !request.contains("pids")) {
      response["status"] = "failed";
    } else {
      try {
        std::string config = request.value("config", "");
        std::vector<int> pids = request.at("pids").get<std::vector<int>>();
        std::set<int> pids_set{
            pids.begin(), pids.end()}; // TODO directly convert?

        int job_id = request.value("job_id", 0);
        int process_limit = request.value("process_limit", 1000);
        auto result = handler_->setKinetOnDemandRequest(
            job_id, pids_set, config, process_limit);
        response["processesMatched"] = result.processesMatched;
        response["eventProfilersTriggered"] = result.eventProfilersTriggered;
        response["activityProfilersTriggered"] =
            result.activityProfilersTriggered;
        response["eventProfilersBusy"] = result.eventProfilersBusy;
        response["activityProfilersBusy"] = result.activityProfilersBusy;
      } catch (const std::exception& ex) {
        LOG(ERROR) << "setKinetOnDemandRequest: parsing exception = "
                   << ex.what();
        response["status"] =
            fmt::format("failed with exception = {}", ex.what());
      }
    }
  } else {
    LOG(ERROR) << "Unknown RPC call = " << request["fn"];
    return "";
  }

  return response.dump();
}

} // namespace dynolog
