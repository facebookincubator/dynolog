// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/FBRelayLogger.h"
#include <arpa/inet.h>
#include <fmt/format.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cerrno>

using json = nlohmann::json;

DEFINE_int32(fbrelay_port, 10000, "Port for sending metrics to FB Relay");
DEFINE_string(
    fbrelay_address,
    "127.0.0.1",
    "IP Address of FBRelate to connect to.");

namespace dynolog {

namespace {

std::string hostname = []() {
  static std::string hostname;
  char buf[1024];
  gethostname(buf, sizeof(buf));
  hostname = buf;
  return hostname;
}();

};

int setup_ipv4_socket(const std::string& addr, int port) {
  int sock_fd, domain = AF_INET;
  struct sockaddr_in serv_addr;

  if ((sock_fd = ::socket(domain, SOCK_STREAM, 0)) < 0) {
    LOG(ERROR) << "Socket creation error " << sock_fd;
    std::perror("socket()");
    return -1;
  }

  serv_addr.sin_family = domain;
  serv_addr.sin_port = htons(port);

  // Convert IPv4 addresses from text to binary form
  if (::inet_pton(domain, addr.c_str(), &serv_addr.sin_addr) <= 0) {
    LOG(ERROR) << "Invalid address/ Address not supported";
    std::perror("inet_ptons()");
    close(sock_fd);
    return -1;
  }

  if (::connect(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    LOG(ERROR) << "Socket connection failed = ";
    std::perror("connect()");
    close(sock_fd);
    return -1;
  }
  return sock_fd;
}

int setup_ipv6_socket(const std::string& addr, int port) {
  int sock_fd, domain = AF_INET6;
  struct sockaddr_in6 serv_addr;

  if ((sock_fd = ::socket(domain, SOCK_STREAM, 0)) < 0) {
    LOG(ERROR) << "Socket creation error " << sock_fd;
    std::perror("socket()");
    return -1;
  }

  serv_addr.sin6_family = domain;
  serv_addr.sin6_port = htons(port);

  // Convert IPv6 addresses from text to binary form
  if (::inet_pton(domain, addr.c_str(), &serv_addr.sin6_addr) <= 0) {
    LOG(ERROR) << "Invalid address/ Address not supported";
    std::perror("inet_ptons()");
    close(sock_fd);
    return -1;
  }

  if (::connect(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    LOG(ERROR) << "Socket connection failed = ";
    std::perror("connect()");
    close(sock_fd);
    return -1;
  }
  return sock_fd;
}

FBRelayLogger::SocketWrapper::SocketWrapper(const std::string& addr, int port) {
  if (addr.find(".") != std::string::npos) {
    LOG(INFO) << "Using IPv4 address";
    sock_fd_ = setup_ipv4_socket(addr, port);
  } else if (addr.find(":") != std::string::npos) {
    LOG(INFO) << "Using IPv6 address";
    sock_fd_ = setup_ipv6_socket(addr, port);
  } else {
    LOG(ERROR) << "Bad address? does not contain '.' or ':' " << addr;
    return;
  }
  if (sock_fd_ < 0) {
    return;
  }

  success_ = true;
  LOG(INFO) << "Socket creation successful";
}

FBRelayLogger::SocketWrapper::~SocketWrapper() {
  if (sock_fd_ > 0) {
    close(sock_fd_);
  }
}

bool FBRelayLogger::SocketWrapper::success() const {
  return success_;
}

bool FBRelayLogger::SocketWrapper::send(const std::string& msg) {
  int ret = ::send(sock_fd_, msg.c_str(), msg.size(), 0);
  LOG(INFO) << "Sent message to FBRelay";
  if (ret < 0) {
    std::perror("send()");
  }
  return ret >= 0;
}

void FBRelayLogger::initSocket() {
  socket = std::make_unique<SocketWrapper>(
      FLAGS_fbrelay_address, FLAGS_fbrelay_port);
}

FBRelayLogger::FBRelayLogger() {
  initSocket();
}

void FBRelayLogger::finalize() {
  LOG(INFO) << "Checking socket";

  if (!socket || !socket->success()) {
    LOG(WARNING) << "Failed to connect to FB Relay";
    initSocket();
    return;
  }

  // see fbcode/fava/monitoring/monitoring/favametrics.py?lines=97
  json data{
      {"@timestamp", timestampStr()},
      {"agent",
       {
           {"hostname", hostname},
           {"name", hostname},
           {"type", "dyno"},
           {"version", "0.1.0"},
       }},
      {"event", {{"module", "dyno"}}},
      {"backend", 0}, // 0 : ODS
      {"stack_metrics", false},
      {"dyno", sampleJson()},
  };

  // pretty print data
  LOG(INFO) << " Json data = " << data.dump(4);

  // try send
  if (!socket->send(data.dump())) {
    LOG(WARNING) << "Failed to send socket data";
  }
}

} // namespace dynolog
