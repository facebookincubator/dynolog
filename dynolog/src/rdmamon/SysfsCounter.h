// Copyright (c) Meta Platforms, Inc. and affiliates.

// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <fcntl.h>
#include <glog/logging.h>
#include <unistd.h>
#include <charconv>
#include <cstring>
#include <map>
#include <optional>
#include <string>

// @lint-ignore-every CLANGTIDY facebook-hte-BadCall-strerror

namespace dynolog {
namespace rdmamon {

class SysfsCounter {
 public:
  explicit SysfsCounter(const std::string& name, const std::string& path)
      : name_(name), path_(path) {}
  virtual ~SysfsCounter() {
    if (fd_ >= 0) {
      close(fd_);
    }
  }

  bool openSysfsCounter();
  std::optional<uint64_t> getSysfsCounter();
  std::string getSysfsCounterName() const {
    return name_;
  }

 private:
  int fd_ = -1;
  std::string name_;
  std::string path_;

// Sysfs couunters are 64-bit integers.
// Their string representation should not exceed 128 bytes.
#define BUFSZ (128)
  bool get_line_(char* line) {
    if (lseek(fd_, 0, SEEK_SET) < 0) {
      LOG(ERROR) << "Unable to lseek for sysfs counter ("
                 << std::strerror(errno) << ")";
      return false;
    }
    if (ssize_t sz = read(fd_, line, BUFSZ); sz <= 0) {
      LOG(ERROR) << "Unable to read sysfs counter (" << std::strerror(errno)
                 << ")";
      return false;
    }
    return true;
  }

  std::optional<uint64_t> get_current_sysfs_counters_() {
    char line[BUFSZ] = {'\0'};
    if (!get_line_(line)) {
      return std::nullopt;
    }

    uint64_t cntr = 0;
    const auto res = std::from_chars(line, line + strlen(line), cntr, 10);
    if (res.ec != std::errc()) {
      LOG(ERROR) << "Unable to convert " << line << " to integer";
      return std::nullopt;
    }

    return cntr;
  }
};

} // namespace rdmamon
} // namespace dynolog
