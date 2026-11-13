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
#include <optional>
#include <string>
#include <vector>

namespace dynolog {

// A writable buffer that ends right at an inaccessible guard page. The legacy
// ethtool ioctls (ETHTOOL_GSTRINGS, ETHTOOL_GSTATS) ignore the caller's length
// and copy the driver's current stat count, which may have grown since it was
// queried (driver reload, queue reconfiguration). With this buffer such an
// overrun makes the kernel's copy fail with EFAULT at the guard page instead
// of writing past the allocation.
class GuardedBuffer {
 public:
  GuardedBuffer() = default;
  // Empty (operator bool false) if the mapping fails.
  explicit GuardedBuffer(size_t size);
  ~GuardedBuffer();

  GuardedBuffer(const GuardedBuffer&) = delete;
  GuardedBuffer& operator=(const GuardedBuffer&) = delete;
  GuardedBuffer(GuardedBuffer&& other) noexcept;
  GuardedBuffer& operator=(GuardedBuffer&& other) noexcept;

  // 8-byte aligned; at least the requested size.
  char* data() const {
    return data_;
  }
  explicit operator bool() const {
    return data_ != nullptr;
  }

 private:
  void release();

  void* map_{nullptr};
  size_t mapSize_{0};
  char* data_{nullptr};
};

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
  // Moves transfer the socket; the moved-from reader is left uninitialized.
  EthtoolStatsReader(EthtoolStatsReader&& other) noexcept;
  EthtoolStatsReader& operator=(EthtoolStatsReader&& other) noexcept;

  bool init(const std::string& ifname);
  // Returns false if the ioctl fails or the driver's stat count changed since
  // init() (e.g. driver reload). In the latter case needsReinit() is true and
  // every later sample() fails until init() is called again. The previous
  // values are kept either way.
  bool sample();
  bool needsReinit() const {
    return needsReinit_;
  }
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
  // ETHTOOL_GSTATS buffer: struct ethtool_stats followed by nStats_ values.
  GuardedBuffer statsBuf_;
  bool initialized_{false};
  bool needsReinit_{false};

  void cleanup();
  // ETHTOOL_GSSET_INFO; returns the driver's current stat count, or nullopt
  // with errno set if the ioctl fails.
  std::optional<uint32_t> queryStatCount();
};

} // namespace dynolog
