/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/UdsRelayLogger.h"
#include <fmt/format.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <nlohmann/json.hpp>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include "hbt/src/common/System.h"

using json = nlohmann::json;

DEFINE_string(
    udsrelay_socket_path,
    "/var/run/dyno-relay-logger.sock",
    "Path to the Unix domain socket for UDS Relay Logger.");

DECLARE_int32(dcgm_reporting_interval_s);
DECLARE_int32(kernel_monitor_reporting_interval_s);

namespace dynolog {

void UdsRelayLogger::initSocket() {
  socket = std::make_unique<UdsSocketWrapper>(FLAGS_udsrelay_socket_path);
}

UdsRelayLogger::UdsRelayLogger() : hostname_(facebook::hbt::getHostName()) {
  initSocket();
}

void UdsRelayLogger::finalize() {
  std::time_t now = std::chrono::system_clock::to_time_t(ts_);

  if (!socket || !socket->success()) {
    LOG(WARNING) << "Failed to connect to UDS Relay";
    initSocket();
    return;
  }

  nlohmann::json metrics = sampleJson();

  if (metrics.size() > 1) {
    metrics["hostname"] = hostname_;
    metrics["t"] = now;

    // if log info is about GPUs
    if (metrics.find("device") != metrics.end()) {
      metrics["interval_s"] = FLAGS_dcgm_reporting_interval_s;
      socket->send("dynolog_dcgm_gpu_monitor", metrics.dump());

    // if log info is about CPUs
    } else if (metrics.find("cpu_i") != metrics.end()) {
      metrics["interval_s"] = FLAGS_kernel_monitor_reporting_interval_s;
      socket->send("dynolog_cpu_monitor", metrics.dump());

    // catch anything else
    } else {
      LOG(ERROR) << "Metrics not logged. No destination: " << metrics.dump();
    }

    LOG(INFO) << " Json data = " << metrics.dump(4);
    JsonLogger::finalize();
  }
}

UdsSocketWrapper::UdsSocketWrapper(const std::string& socket_path) {
  if (sock_fd_ < 0) {
    success_ = true;
    sock_fd_ = ::socket(AF_UNIX, SOCK_STREAM, 0);

    if (sock_fd_ < 0) {
      LOG(ERROR) << "Socket creation error " << sock_fd_;
      std::perror("socket()");
      return;
    }

    struct sockaddr_un serv_addr;
    std::memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;

    if (socket_path.size() >= sizeof(serv_addr.sun_path)) {
      LOG(ERROR) << "Socket path too long: " << socket_path;
      ::close(sock_fd_);
      sock_fd_ = -1;
      return;
    }
    std::strncpy(serv_addr.sun_path, socket_path.c_str(), sizeof(serv_addr.sun_path) - 1);

    if (::access(socket_path.c_str(), F_OK) != 0) {
      LOG(WARNING) << "Socket file does not exist: " << socket_path;
      ::close(sock_fd_);
      sock_fd_ = -1;
      return;
    }

    if (::connect(sock_fd_, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      LOG(ERROR) << "Unix domain socket connection failed to " << socket_path;
      std::perror("connect()");
      ::close(sock_fd_);
      sock_fd_ = -1;
      return;
    }

    success_ = true;
    LOG(INFO) << "Unix domain socket connection successful to " << socket_path;
  }
}

UdsSocketWrapper::~UdsSocketWrapper() {
}

void UdsSocketWrapper::close() {
  if (sock_fd_ >= 0) {
    ::close(sock_fd_);
  }
}

bool UdsSocketWrapper::success() const {
  return success_;
}

bool UdsSocketWrapper::send(const std::string& category,
    const std::string& msg) {
  std::string send_msg = fmt::format("::{},{}\n", category, msg);
  int ret = ::send(sock_fd_, send_msg.c_str(), send_msg.size(), MSG_NOSIGNAL);
  LOG(INFO) << "Sent message to UDS Relay";
  if (ret < 0) {
    std::perror("send()");
    ::close(sock_fd_);
    sock_fd_ = -1;
    success_ = false;
  }
  return ret >= 0;
}

} // namespace dynolog
