// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include <fmt/format.h>
#include <glog/logging.h>
#include <nlohmann/json.hpp>

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "SimpleJsonServer.h"

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
  } else {
    LOG(ERROR) << "Unknown RPC call = " << request["fn"];
    return "";
  }

  return response.dump();
}

} // namespace dynolog
