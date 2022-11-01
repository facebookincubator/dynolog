// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <arpa/inet.h>
#include <glog/logging.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cerrno>
#include <optional>

namespace dynolog {

class SimpleJsonServerClient {
 public:
  explicit SimpleJsonServerClient(const std::string& host_ip, int32_t port) {
    LOG(INFO) << "Conneting dynolog on host : " << host_ip << " port " << port;

    /* Create socket for communication with server */
    sock_fd_ = ::socket(AF_INET6, SOCK_STREAM, 0);
    if (sock_fd_ == -1) {
      LOG(ERROR) << "Failed to setup socket.";
      std::perror("socket()");
      return;
    }

    struct sockaddr_in6 server_addr;
    server_addr.sin6_family = AF_INET6;
    inet_pton(AF_INET6, host_ip.c_str(), &server_addr.sin6_addr);
    server_addr.sin6_port = htons(port);

    /* Connect to server */
    int ret = ::connect(
        sock_fd_, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret == -1) {
      LOG(ERROR) << "Failed to connect to " << host_ip;
      std::perror("connect()");
      close(sock_fd_);
      return;
    }
    initSuccess_ = true;
  }

  ~SimpleJsonServerClient() {
    if (sock_fd_ > 0) {
      close(sock_fd_);
    }
  }

  bool initSuccessful() const {
    return initSuccess_;
  }

  std::optional<std::string> invoke_rpc(const std::string& request) {
    /* Send RPC Request to server */
    // prefix with size of message
    int32_t message_size = request.size();
    LOG(INFO) << "Writing message size = " << message_size;
    int ret = ::write(sock_fd_, (void*)&message_size, sizeof(message_size));
    if (ret == -1) {
      std::perror("write");
      return std::nullopt;
    }

    ret = ::write(sock_fd_, request.c_str(), request.size());
    if (ret == -1) {
      std::perror("write");
      return std::nullopt;
    }

    /* Wait for response from server */
    std::string response;
    int32_t response_size = 0;

    ret = ::read(sock_fd_, &response_size, sizeof(response_size));
    if (ret == -1) {
      std::perror("read() for size");
      return std::nullopt;
    }
    LOG(INFO) << "Response size = " << response_size;

    if (response_size > 0) {
      response.resize(response_size);
      ret = ::read(sock_fd_, response.data(), response_size);
      if (ret == -1) {
        std::perror("read() for message");
        return std::nullopt;
      }
      LOG(INFO) << "Response from server = " << response;
    } else {
      LOG(INFO) << "Failure obtaining resonse.";
    }

    ret = close(sock_fd_);
    if (ret == -1) {
      std::perror("close()");
    }

    return response;
  }

 private:
  int sock_fd_ = -1;
  bool initSuccess_ = false;
};

} // namespace dynolog
