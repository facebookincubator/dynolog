// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/perf_event/BPerfCountReader.h"
#include "hbt/src/perf_event/BPerfEventsGroup.h"

#include "hbt/src/perf_event/PerfEventsGroup.h"

namespace facebook::hbt::perf_event {

BPerfCountReader::BPerfCountReader(
    std::shared_ptr<BPerfEventsGroup> bperf_eg_in,
    std::shared_ptr<FdWrapper> cgroup_fd_wrapper,
    int cgroup_update_level)
    : bperf_eg_{std::move(bperf_eg_in)},
      cgroup_fd_wrapper_{std::move(cgroup_fd_wrapper)},
      cgroup_update_level_{cgroup_update_level} {}

size_t BPerfCountReader::getNumEvents() const {
  return bperf_eg_->getNumEvents();
}

BPerfCountReader::ReadValues BPerfCountReader::makeReadValues() const {
  return BPerfCountReader::ReadValues{getNumEvents()};
}

bool BPerfCountReader::enable() {
  if (cgroup_fd_wrapper_) {
    if (bperf_eg_->addCgroup(cgroup_fd_wrapper_, cgroup_update_level_)) {
      cgroup_tracking_ = true;
    }
    return cgroup_tracking_;
  }
  // if BPerfCountReader is open for global perf counter, then enable() is a
  // no-op
  return false;
}

bool BPerfCountReader::disable() {
  if (cgroup_fd_wrapper_) {
    if (bperf_eg_->removeCgroup(cgroup_fd_wrapper_->getInode())) {
      cgroup_tracking_ = false;
    }
    return !cgroup_tracking_;
  }
  // if BPerfCountReader is open for global perf counter, then disable() is a
  // no-op
  return false;
}

bool BPerfCountReader::read(
    BPerfCountReader::ReadValues& rv,
    bool skip_offset) {
  if (cgroup_fd_wrapper_) {
    return bperf_eg_->readCgroup(rv, cgroup_fd_wrapper_->getInode());
  } else {
    return bperf_eg_->readGlobal(rv, skip_offset);
  }
}

std::optional<BPerfCountReader::ReadValues> BPerfCountReader::read(
    bool skip_offset) {
  auto rv = makeReadValues();
  if (read(rv, skip_offset)) {
    return std::make_optional(rv);
  } else {
    return std::nullopt;
  }
}

bool BPerfCountReader::isEnabled() const {
  // if BPerfCountRedaer is open for a certain cgroup
  // check if underlying BPerfEventsGroup is enabled and if cgroup is being
  // tracked as well
  return bperf_eg_->isEnabled() && (cgroup_tracking_ || !cgroup_fd_wrapper_);
}

std::ostream& BPerfCountReader::printStatus(std::ostream& os) {
  os << "BPerfCounterReader for ";
  if (cgroup_fd_wrapper_) {
    os << "cgroup " << cgroup_fd_wrapper_->getInode();
  } else {
    os << " global";
  }
  os << "\n";
  if (this->isEnabled()) {
    auto val = this->read(false);
    if (val.has_value()) {
      return os << *val << "\n";
    } else {
      return os << " Failed to read\n";
    }
  }
  return os << " is inactive.\n";
}

BPerfEventsGroup* BPerfCountReader::getBPerfEventsGroup() const {
  return bperf_eg_.get();
}

BPerfCountReader::~BPerfCountReader() {
  disable();
  HBT_DCHECK(bperf_eg_ != nullptr);
}

} // namespace facebook::hbt::perf_event
