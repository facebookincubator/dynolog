// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>
#include <linux/perf_event.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include "dynolog/src/ipcfabric/FabricManager.h"

using namespace dynolog::ipcfabric;

TEST(Endpoint, PodDataOneWay) {
  static const unsigned kNumRetries = 10;
  pid_t cpid;

  cpid = fork();
  ASSERT_NE(cpid, -1);

  if (cpid > 0) {
    // Parent is a sender.
    int data = 1000;

    const size_t num_fd = 0;
    // sender having "" name will be autobound to name 5 hexidecimal characters
    EndPoint<num_fd> sender("");

    auto ctxt =
        sender.buildSendCtxt("mydest", {Payload(sizeof(data), &data)}, {});

    ASSERT_EQ(std::string(sender.getName(*ctxt)), std::string("mydest"));

    // Try to send kNumRetries times.
    for (unsigned i = 0; i < kNumRetries && !sender.trySendMsg(*ctxt); ++i) {
      sleep(1);
    }

    int wstatus;
    // Wait for child thread to either change state or stopped.
    pid_t wpid = waitpid(cpid, &wstatus, WUNTRACED);
    ASSERT_EQ(cpid, wpid);
    ASSERT_EQ(WIFEXITED(wstatus), true);
  } else {
    // Child is a receiver.
    int data = -1;
    EndPoint<0> receiver{"mydest"};
    auto ctxt = receiver.buildRcvCtxt({Payload(sizeof(data), &data)});

    // Try to receive kNumRetries times.
    for (unsigned i = 0; i < kNumRetries && !receiver.tryRcvMsg(*ctxt); ++i) {
      sleep(1);
    }

    ASSERT_EQ(data, 1000);

    exit(0);
  }
}

static long perf_event_open(
    struct perf_event_attr* hw_event,
    pid_t pid,
    int cpu,
    int group_fd,
    unsigned long flags) {
  int ret;

  ret = syscall(__NR_perf_event_open, hw_event, pid, cpu, group_fd, flags);
  return ret;
}

int create_perf_event_fd(pid_t pid) {
  struct perf_event_attr pe;
  int fd;

  memset(&pe, 0, sizeof(struct perf_event_attr));
  pe.type = PERF_TYPE_HARDWARE;
  pe.size = sizeof(struct perf_event_attr);
  pe.config = PERF_COUNT_HW_INSTRUCTIONS;
  pe.disabled = 1;
  pe.exclude_kernel = 1;
  pe.exclude_hv = 1;

  fd = perf_event_open(&pe, pid, -1, -1, 0);
  if (fd == -1) {
    fprintf(stderr, "Error opening leader %llx\n", pe.config);
    exit(EXIT_FAILURE);
  }
  return fd;
}

TEST(Endpoint, PerfEventFdAndDataOneWay) {
  // Disabled on CI
  if (std::getenv("GITHUB_WORKFLOW") != nullptr) {
    GTEST_SKIP() << "Skipping perf_event related test on CI";
  }

  static const unsigned kNumRetries = 10;
  static const std::string dest = "perf_event_fd_dest";
  pid_t cpid;

  cpid = fork();
  ASSERT_NE(cpid, -1);

  if (cpid > 0) {
    // Parent is a sender.
    int data = 1000, fd_event;

    // Monitor child process
    fd_event = create_perf_event_fd(cpid);

    const size_t num_fd = 3;
    // sender having "" name will be autobound to name 5 hexidecimal characters
    EndPoint<num_fd> sender("");

    auto ctxt =
        sender.buildSendCtxt(dest, {Payload(sizeof(data), &data)}, {fd_event});

    ASSERT_EQ(std::string(sender.getName(*ctxt)), dest);

    // Try to send kNumRetries times.
    for (unsigned i = 0; i < kNumRetries && !sender.trySendMsg(*ctxt); ++i) {
      sleep(1);
    }
    int wstatus;
    // Wait for child thread to either change state or stopped.
    pid_t wpid = waitpid(cpid, &wstatus, WUNTRACED);
    ASSERT_EQ(cpid, wpid);
    ASSERT_EQ(WIFEXITED(wstatus), true);
    close(fd_event);
  } else {
    // Child is a receiver.
    int data = -1;

    const size_t num_fd = 2;
    EndPoint<num_fd> receiver{dest};

    auto ctxt = receiver.buildRcvCtxt({Payload(sizeof(data), &data)});

    // Try to receive kNumRetries times.
    for (unsigned i = 0; i < kNumRetries && !receiver.tryRcvMsg(*ctxt); ++i) {
      sleep(1);
    }
    std::cout << "Got data" << std::endl;

    ASSERT_EQ(data, 1000);
    auto fds = receiver.getFds(*ctxt);
    ASSERT_EQ(fds.size(), 1);

    long long count;
    int fd = fds[0];
    ioctl(fd, PERF_EVENT_IOC_RESET, 0);
    ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);

    std::cout << "Measuring instruction count for this std::cout" << std::endl;

    ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
    read(fd, &count, sizeof(long long));

    printf("Used %lld instructions\n", count);

    ASSERT_LT(count, 10000);
    ASSERT_GT(count, 100);
    exit(0);
  }
}

struct FlexArrStruct {
  int num;
  size_t size;
  int array[];
};

TEST(FabricManager, PodDataOneWay) {
  pid_t cpid;

  cpid = fork();
  ASSERT_NE(cpid, -1);

  if (cpid > 0) {
    // Sender side example:

    // Create FabricManager object with optional name argument
    // Unix socket will autobind empty name to a 5 hexadecimal char name
    auto sender = FabricManager::factory("sender");

    // Construct Message object to send through the manager

    // Example of int data
    int data = 1000;
    // this field construct Message.Metadata.type, and is used
    // for sender/receiver to recognize the underlying data type.
    // Only sender and receiver need to agree on it.
    // FabricManager doesn't care about its value
    std::string type_int = "int";
    std::unique_ptr<Message> msgint =
        Message::constructMessage<decltype(data)>(data, type_int);

    // Example of string data
    std::string datastring = "this";
    std::string type_string = "string";
    std::unique_ptr<Message> msgstring =
        Message::constructMessage<decltype(datastring)>(
            datastring, type_string);

    FlexArrStruct* arrStruct =
        (FlexArrStruct*)malloc(sizeof(FlexArrStruct) + sizeof(int) * 3);
    arrStruct->num = 10;
    arrStruct->size = 3;
    arrStruct->array[0] = 0;
    arrStruct->array[1] = 1;
    arrStruct->array[2] = 3;
    std::string type_flex = "flex";
    std::unique_ptr<Message> msgflex =
        Message::constructMessage<FlexArrStruct, int>(*arrStruct, type_flex, 3);

    // Send messages to the socket bound to "mydest"
    sender->sync_send(*msgint, "mydest");
    sender->sync_send(*msgstring, "mydest");
    sender->sync_send(*msgint, "mydest");
    sender->sync_send(*msgflex, "mydest");

    int wstatus;
    // Wait for child thread to either change state or stopped.
    pid_t wpid = waitpid(cpid, &wstatus, WUNTRACED);
    ASSERT_EQ(cpid, wpid);
    ASSERT_EQ(WIFEXITED(wstatus), true);
    free(arrStruct);
  } else {
    // Receiver side Example:

    // Create FabricManager object bound to socket name "mydest"
    auto receiver = FabricManager::factory("mydest");

    int received_data_cnt = 0;
    while (received_data_cnt < 4) {
      // Receiver side loop-checks recv()
      if (receiver->recv()) {
        received_data_cnt++;
        // receiver gains ownership of the message
        std::unique_ptr<Message> msg = receiver->retrieve_msg();
        ASSERT_EQ(msg->src, "sender");

        // receiver check the data type received, and read it accordingly
        if (memcmp(msg->metadata.type, "int", 3) == 0) {
          ASSERT_EQ(msg->metadata.size, sizeof(int));
          ASSERT_EQ(*(int*)msg->buf.get(), 1000);
        } else if (memcmp(msg->metadata.type, "string", 6) == 0) {
          ASSERT_EQ(msg->metadata.size, 4);
          std::string data((char*)msg->buf.get(), msg->metadata.size);
          ASSERT_EQ(data, "this");
        } else if (memcmp(msg->metadata.type, "flex", 4) == 0) {
          FlexArrStruct* flexdata = (FlexArrStruct*)msg->buf.get();
          ASSERT_EQ(flexdata->num, 10);
          ASSERT_EQ(flexdata->size, 3);
          ASSERT_EQ(flexdata->array[0], 0);
          ASSERT_EQ(flexdata->array[1], 1);
          ASSERT_EQ(flexdata->array[2], 3);
        } else {
          std::cout << "Unrecognized message of type" << msg->metadata.type
                    << "\n";
        }
      }
    }

    exit(0);
  }
}
