// Copyright (c) Meta Platforms, Inc. and affiliates.

// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "dynolog/src/rdmamon/SysfsCounter.h"

// @lint-ignore-every CLANGTIDY facebook-hte-BadCall-strerror

namespace dynolog {
namespace rdmamon {

bool SysfsCounter::openSysfsCounter() {
  fd_ = open(path_.c_str(), O_RDONLY);
  if (fd_ < 0) {
    LOG(WARNING) << "Unable to open " << path_ << "(" << std::strerror(errno)
                 << ")";
    return false;
  }
  return true;
}

std::optional<uint64_t> SysfsCounter::getSysfsCounter() {
  return get_current_sysfs_counters_();
}

} // namespace rdmamon
} // namespace dynolog
