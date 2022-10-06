// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/rpc/SimpleJsonServer.h"
#include <arpa/inet.h>
#include <fmt/format.h>
#include <glog/logging.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cerrno>

constexpr int CLIENT_QUEUE_LEN = 50;

namespace dynolog {

SimpleJsonServerBase::SimpleJsonServerBase(int port) : port_(port) {
  initSocket();
}

SimpleJsonServerBase::~SimpleJsonServerBase() {
  if (thread_) {
    stop();
  }
  close(sock_fd_);
}

void SimpleJsonServerBase::initSocket() {
  struct sockaddr_in6 server_addr;

  /* Create socket for listening (client requests).*/
  sock_fd_ = ::socket(AF_INET6, SOCK_STREAM, 0);
  if (sock_fd_ == -1) {
    std::perror("socket()");
    return;
  }

  /* Set socket to reuse address in case server is restarted.*/
  int flag = 1;
  int ret =
      ::setsockopt(sock_fd_, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
  if (ret == -1) {
    std::perror("setsockopt()");
    return;
  }

  // in6addr_any allows us to bind to both IPv4 and IPv6 clients.
  server_addr.sin6_addr = in6addr_any;
  server_addr.sin6_family = AF_INET6;
  server_addr.sin6_port = htons(port_);

  /* Bind address and socket together */
  ret = ::bind(sock_fd_, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if (ret == -1) {
    std::perror("bind()");
    close(sock_fd_);
    return;
  }

  /* Create listening queue (client requests) */
  ret = ::listen(sock_fd_, CLIENT_QUEUE_LEN);
  if (ret == -1) {
    std::perror("listen()");
    close(sock_fd_);
    return;
  }

  /* Get port if assigned 0 */
  if (port_ == 0) {
    socklen_t len_out = sizeof(server_addr);
    ret = ::getsockname(sock_fd_, (struct sockaddr*)&server_addr, &len_out);
    if (ret < 0 || len_out != sizeof(server_addr)) {
      std::perror("getsockname()");
    } else {
      port_ = ntohs(server_addr.sin6_port);
      LOG(INFO) << "System assigned port = " << ntohs(server_addr.sin6_port);
    }
  }

  LOG(INFO) << "Listening to connections on port " << port_;
  initSuccess_ = true;
}

/* A simple wrapper to accept connections and read data
 *
 *  Messages are prefixed using the length so we know how long a message
 *  to actually read.
 *     : int32_t len
 *     : char json[]
 */
class ClientSocketWrapper {
 public:
  ~ClientSocketWrapper() {
    if (::close(client_sock_fd_) < 0) {
      std::perror("close()");
    }
  }

  bool accept(int server_socket) {
    struct sockaddr_in6 client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    std::array<char, INET6_ADDRSTRLEN> client_addr_str;

    client_sock_fd_ = ::accept(
        server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_sock_fd_ == -1) {
      std::perror("accept()");
      return false;
    }

    inet_ntop(
        AF_INET6,
        &(client_addr.sin6_addr),
        client_addr_str.data(),
        client_addr_str.size());
    LOG(INFO) << "Received connection from " << client_addr_str.data();
    return true;
  }

  /* Reads an entire message from the client,
   * expected to return json*/
  std::string get_message() {
    /* Wait for data from client */
    int32_t msg_size = -1;
    // TODO use decltype or type alias
    if (!read_helper((uint8_t*)&msg_size, sizeof(msg_size)) || msg_size <= 0) {
      LOG(ERROR) << "Invalid message size = " << msg_size;
      return "";
    }

    std::string message;
    message.resize(msg_size);
    int recv = 0;

    /* Wait for data from client */
    int ret = 1;
    while (recv < msg_size && ret > 0) {
      ret = read_helper((uint8_t*)&message[recv], msg_size - recv);
      recv += ret > 0 ? ret : 0;
    }

    if (recv != msg_size) {
      LOG(ERROR) << "Received parital message, expected size " << msg_size
                 << "found : " << recv;
      LOG(ERROR) << "Message received = " << message;
      return "";
    }

    return message;
  }

  bool send_response(const std::string& response) {
    // send size prefixed response
    int32_t size = response.size();
    int ret = ::write(client_sock_fd_, (void*)&size, sizeof(size));
    if (ret == -1) {
      std::perror("read()");
    }

    int sent = 0;
    while (sent < size && ret > 0) {
      ret = ::write(client_sock_fd_, (void*)&response[sent], size - sent);
      if (ret == -1) {
        std::perror("read()");
      } else {
        sent += ret;
      }
    }

    if (sent < response.size()) {
      LOG(ERROR) << "Unable to write full response";
      return false;
    }
    return ret > 0;
  }

 private:
  int read_helper(uint8_t* buf, int size) {
    int ret = ::read(client_sock_fd_, (void*)buf, size);
    if (ret == -1) {
      std::perror("read()");
    }
    return ret;
  }

  int client_sock_fd_ = -1;
};

/* Accepts socket connections and processes the payloads.
 * This will inturn call the Handler functions*/
void SimpleJsonServerBase::loop() noexcept {
  if (sock_fd_ == -1 || !initSuccess_) {
    return;
  }

  while (run_) {
    processOne();
  }
}

void SimpleJsonServerBase::processOne() noexcept {
  int ret, flag;

  /* Wait for incoming connections, the accept call is blocking*/
  LOG(INFO) << "Waiting for connection.";
  ClientSocketWrapper client;
  if (!client.accept(sock_fd_)) {
    return;
  }

  std::string request_str = client.get_message();
  LOG(INFO) << "RPC message received = " << request_str;

  auto response_str = processOneImpl(request_str);
  if (response_str.empty()) {
    return;
  }

  if (!client.send_response(response_str)) {
    LOG(ERROR) << "Failed to send response";
  }

  return;
}

void SimpleJsonServerBase::run() {
  LOG(INFO) << "Launching RPC thread";
  thread_ = std::make_unique<std::thread>([this]() { this->loop(); });
}

} // namespace dynolog
