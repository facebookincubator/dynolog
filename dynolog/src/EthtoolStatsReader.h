/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <linux/ethtool.h>
#include <net/if.h>
#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace dynolog {

// Interface for ioctl system calls — the testable seam.
class EthtoolIoctlInterface {
 public:
  virtual ~EthtoolIoctlInterface() = default;
  virtual int openSocket() = 0;
  virtual int doIoctl(int fd, unsigned long req, struct ifreq* ifr) = 0;
  virtual void closeSocket(int fd) = 0;
};

// Reads per-NIC ethtool stats via legacy ETHTOOL_GSTATS ioctl.
// This is the same data path as `ethtool -S <interface>`.
//
// Usage:
//   EthtoolStatsReader reader;
//   if (reader.init("eth0")) {
//     reader.sample();
//     auto stats = reader.getAllStats();
//   }
//
// For testing, inject a mock:
//   EthtoolStatsReader reader(std::make_unique<MockIoctl>());
class EthtoolStatsReader {
 public:
  EthtoolStatsReader() = default;
  explicit EthtoolStatsReader(std::unique_ptr<EthtoolIoctlInterface> ioctl)
      : ioctl_(std::move(ioctl)) {}
  ~EthtoolStatsReader();

  EthtoolStatsReader(const EthtoolStatsReader&) = delete;
  EthtoolStatsReader& operator=(const EthtoolStatsReader&) = delete;
  EthtoolStatsReader(EthtoolStatsReader&&) = default;
  EthtoolStatsReader& operator=(EthtoolStatsReader&&) = default;

  bool init(const std::string& ifname);
  bool sample();
  size_t size() const;
  const std::string& name(size_t i) const;
  uint64_t value(size_t i) const;
  std::map<std::string, uint64_t> getAllStats() const;

 private:
  std::unique_ptr<EthtoolIoctlInterface> ioctl_;
  int fd_{-1};
  struct ifreq ifr_{};
  uint32_t nStats_{0};
  std::vector<std::string> names_;
  std::vector<uint64_t> values_;
  bool initialized_{false};

  void cleanup();
};

} // namespace dynolog
