// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/Defs.h"
#include "hbt/src/perf_event/json_events/generated/CpuArch.h"
#include "pfs/procfs.hpp"

#include <fmt/core.h>
#include <fmt/ostream.h>
#include <limits.h>
#include <sys/prctl.h>
#include <unistd.h>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <system_error>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/utsname.h>
#if defined(__i386__) || defined(__x86_64__)
#include <x86intrin.h>
#endif

namespace facebook::hbt {

struct FdWrapper {
  FdWrapper(const FdWrapper&) = delete;
  FdWrapper(FdWrapper&&) = delete;

  explicit FdWrapper() {}

  explicit FdWrapper(int fd) : fd{fd} {}

  explicit FdWrapper(const std::string& path, int flags = O_RDONLY) {
    fd = ::open(path.c_str(), flags);
    HBT_THROW_SYSTEM_IF(0 > fd, errno)
        << "Error opening file \"" << path << "\"";
    close_on_destruction = true;
  }

  __u64 getInode() {
    struct stat s = {};
    int err = ::fstat(fd, &s);
    HBT_THROW_SYSTEM_IF(0 != err, errno)
        << "Error obtaining inode for fd " << fd;
    return s.st_ino;
  }

  int fd = -1;
  bool close_on_destruction = false;

  ~FdWrapper() {
    if (!close_on_destruction) {
      return;
    }
    if (0 > fd) {
      // Do not throw in destructor or program will crash.
      HBT_LOG_ERROR() << "Cannot close invalid file descriptor";
      return;
    }
    auto ret = ::close(fd);
    HBT_LOG_ERROR_IF(0 > ret) << "Unexpected error closing file descriptor";
  }
};

/// Set Proccess' name for current process.
inline int setProcName(const std::string& name) {
  constexpr size_t kMaxBuff = 16;
  char* buff[kMaxBuff];
  if (name.length() > kMaxBuff) {
    return -EINVAL;
  }
  ::strncpy((char*)buff, name.c_str(), kMaxBuff);
  return ::prctl(PR_SET_NAME, buff, 0, 0, 0);
}

///
/// TimeStamp is a 64 bit value representing
/// a high-resolution clock. It is usually
/// in nanoseconds or in TSC cycles.
///
using TimeStamp = uint64_t;
constexpr TimeStamp kInvalidTimeStamp = std::numeric_limits<TimeStamp>::max();
constexpr TimeStamp kMaxTimeStamp = std::numeric_limits<TimeStamp>::max() - 1;

std::string tstampToStr(TimeStamp ts);

struct TimeStampRange : public std::pair<TimeStamp, TimeStamp> {
  using std::pair<TimeStamp, TimeStamp>::pair;
};
std::ostream& operator<<(std::ostream& os, const TimeStampRange& r);

// std::chronos::duration to TSC.
template <class TDuration>
TimeStamp DurationToTimeStamp(TDuration d) {
  if constexpr (std::is_same_v<TDuration, TimeStamp>) {
    return d;
  }
  auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(d).count();
  if (ns < 0) {
    HBT_THROW_EINVAL() << "Negative time durations are not valid";
  }
  return static_cast<TimeStamp>(ns);
}

///
/// TimeStamp in Heartbeat are measured in nanoseconds since boot,
/// as exposed by kernel's perf_event. TSC values are converted to
/// timestamp using conversion paramaters provided by perf_event.
/// These times are not subject to NTP adjustments and drift corrections,
/// while wall-time is.
///
/// TimeStampNsConverter converts between TClock's time_points and TimeStamps
/// by storing timestamps of both TClock's time and TimeStamp, then doing
/// simply arithmetic. In ignores NTP and other adjustments and therefore it's
/// a best effort converter, but has reasonable accuracy when used to convert
/// timestamps that are close to its creation time (in the order of minutes).
///
struct TimeStampNsConverter {
  using TClock = std::chrono::high_resolution_clock;

  // TClock's version of time since boot.
  TClock::time_point tp0;
  // TimeStamp's version of time since boot.
  TimeStamp tstamp0;

  TimeStamp TimePointToTimeStamp(TClock::time_point tp) const {
    auto d = std::chrono::duration_cast<std::chrono::nanoseconds>(tp - tp0);
    auto t = static_cast<long>(tstamp0) + d.count();
    HBT_DCHECK_GE(t, 0)
        << "Negative timestamps are invalid because all clocks start at boot";
    return static_cast<TimeStamp>(t);
  }

  auto TimeStampToTimePoint(TimeStamp tstamp) const {
    auto elapsed_ns = tstamp - tstamp0;
    return tp0 + std::chrono::nanoseconds(elapsed_ns);
  }

  /// Build converter by estimating reasonable starting points
  /// for system clock and Tstamp counter.
  /// As parameter, takes a function that provides current timestamp
  static auto makeFromNow(std::function<TimeStamp(void)> now_function) {
    auto before = std::chrono::high_resolution_clock::now();
    auto tstamp = now_function(); // Capture tstamp that is within (before,
                                  // start) interval.
    auto after = std::chrono::high_resolution_clock::now();
    // half-point between before and start to reduce the effect of execution
    // delays between the times both timestamps are calculated. Subtract first
    // to obtain delta because timepoints cannot be added.
    auto t = before + (after - before) / 2;

    return TimeStampNsConverter{.tp0 = t, .tstamp0 = tstamp};
  }
};

/// Values necessary to convert between TSC (reference bus-cycles) and kernel
/// time (nanoseconds since boot). These params are read from the base
/// perf_event_mmap_page - see CpuEventsGroup::kernelTimeFromTsc() and
/// CpuEventsGroup::tscFromKernelTime() for more information on these values.
struct TscConversionParams {
  uint16_t time_shift;
  uint32_t time_mult;
  uint64_t time_zero;
};

std::ostream& operator<<(std::ostream& os, const TimeStampNsConverter&);

///
/// Utility functions to access number of CPUs.
///
/// HotPlug CPU is not supported. Facebook does not use it currently.
/// XXX: Add HotPlug CPU support.
///
/// Immutable class to make it safe to be shared among multiple threads.
///
using CpuId = unsigned;

// Used for CPU_* macros and for fixed size per-CPU arrays.
// XXX: Expose this as a configuration parameter.
constexpr unsigned kMaxCpus = 512;
static_assert(kMaxCpus <= CPU_SETSIZE);

struct CpuSet {
  // Bitset of CPUs.
  const cpu_set_t cpu_set;

  // Maximum Id for CPUs in set.
  const CpuId max_cpu_id;

  /// Maximum Id for online CPUs.
  const CpuId max_cpu_id_online;

  CpuSet(cpu_set_t cpu_set, CpuId max_cpu_id, CpuId max_cpu_id_online)
      : cpu_set{cpu_set},
        max_cpu_id{max_cpu_id},
        max_cpu_id_online{max_cpu_id_online} {}

  template <class TCont>
  CpuSet(const TCont& cont, CpuId max_cpu_id, CpuId max_cpu_id_online)
      : CpuSet(make_cpu_set_t(cont), max_cpu_id, max_cpu_id_online) {}

  bool operator==(const CpuSet& other) const {
    return CPU_EQUAL(&cpu_set, &other.cpu_set) != 0 &&
        max_cpu_id == other.max_cpu_id &&
        max_cpu_id_online == other.max_cpu_id_online;
  }

  bool operator!=(const CpuSet& other) const {
    return !((*this) == other);
  }

  /// Initialize given cpu_set or to all online if nullopt.
  static CpuSet makeAllOnline();

  static CpuSet makeFromCpuSet(cpu_set_t cpu_set);

  template <class TCont>
  static cpu_set_t make_cpu_set_t(const TCont& s) {
    cpu_set_t cpus;
    CPU_ZERO(&cpus);
    for (auto cpu : s) {
      if (unlikely(cpu < 0)) {
        HBT_THROW_EINVAL() << "Invalid CPU ID: " << cpu;
      } else if (unlikely(cpu >= kMaxCpus)) {
        HBT_THROW_EINVAL() << "Maximum CPU ID is " << kMaxCpus - 1
                           << " Got CPU ID: " << cpu
                           << ". Do you want to increase kMaxCpus?";
      }
      CPU_SET(static_cast<CpuId>(cpu), &cpus);
    }
    return cpus;
  }

  template <class TCont>
  static CpuSet makeFromCont(const TCont& s) {
    return makeFromCpuSet(make_cpu_set_t(s));
  }

  std::set<CpuId> asSet() const;

  std::string cpusStr() const;

  /// The default behaviour for when user do not specify CpuSet.
  static CpuSet getOrDefault(std::optional<CpuSet> opt);

  bool hasCpu(CpuId cpu) const {
    return CPU_ISSET(static_cast<CpuId>(cpu), &cpu_set);
  }

  bool hasCpu(int cpu) const {
    if (cpu < 0) {
      return false;
    }
    auto id = static_cast<CpuId>(cpu);
    if (id > max_cpu_id) {
      return false;
    }
    return CPU_ISSET(id, &cpu_set);
  }

  CpuId cpu_set_next(CpuId cpu) const noexcept;

  CpuId cpu_first_set() const noexcept;

  size_t numCpus() const {
    int count = CPU_COUNT(&cpu_set);
    // Always non-negative. Safe to cast.
    return static_cast<size_t>(count);
  }
};

std::ostream& operator<<(std::ostream& os, const CpuSet& cpu_set);

struct CpuInfo {
  perf_event::CpuFamily cpu_family;
  perf_event::CpuArch cpu_arch;

  std::string vendor_id;
  uint32_t cpu_family_num;
  uint32_t cpu_model_num;
  uint32_t cpu_step_num;

  CpuInfo(
      const std::string& vendor_id,
      uint32_t cpu_family_num,
      uint32_t cpu_model_num,
      uint32_t cpu_step_num)
      : cpu_family(perf_event::makeCpuFamily(cpu_family_num)),
        cpu_arch(perf_event::makeCpuArch(
            cpu_family_num,
            cpu_model_num,
            cpu_step_num)),
        vendor_id(vendor_id),
        cpu_family_num(cpu_family_num),
        cpu_model_num(cpu_model_num),
        cpu_step_num(cpu_step_num) {}

  static CpuInfo load();

  bool operator==(const CpuInfo& o) const {
    return std::tie(vendor_id, cpu_family_num, cpu_model_num, cpu_step_num) ==
        std::tie(
               o.vendor_id, o.cpu_family_num, o.cpu_model_num, o.cpu_step_num);
  }
  bool operator<(const CpuInfo& o) const {
    return std::tie(cpu_family_num, cpu_model_num, cpu_step_num, vendor_id) <
        std::tie(
               o.cpu_family_num, o.cpu_model_num, o.cpu_step_num, o.vendor_id);
  }
};

std::ostream& operator<<(std::ostream& os, const CpuInfo& cpu_info);

/// Macro to iterate over all CPUs in CpuSet.
/// Similar functionality to Linux's kernel identically named macro.
#define for_each_cpu(cpu, cpu_set)                            \
  for (facebook::hbt::CpuId(cpu) = (cpu_set).cpu_first_set(); \
       (cpu) <= (cpu_set).max_cpu_id;                         \
       (cpu) = (cpu_set).cpu_set_next((cpu)))

CpuId cpu_set_next(CpuId cpu, const cpu_set_t& cpu_set) noexcept;

CpuId cpu_first_set(const cpu_set_t& cpu_set) noexcept;

/// Macro to iterate over all CPUs in <cpu_set>
/// Similar functionality to Linux's kernel identically named macro.
#define for_each_cpu_set_t(cpu, cpu_set)                                       \
  for (facebook::hbt::CpuId(cpu) = cpu_first_set((cpu_set)); (cpu) < kMaxCpus; \
       (cpu) = cpu_set_next((cpu), (cpu_set)))

/// Get a validated CPU ID.
CpuId getCpu();

struct System {
  enum class Permission {
    // By Default it is allowed to do TaskUser without tracepoints or
    // SchedStats.
    Tracepoints,
    CpuWideEvents,
    TaskKernel,
    SchedStats
  };
  using Permissions = std::set<Permission>;

  bool hasPerfMonCap() const {
    // XXX: Implement
    return false;
  }

  bool hasSysAdminCap() const {
    // XXX: Implement
    return false;
  }

  int paranoidLevel() const {
    // XXX: Implement
    return -1;
  }

  bool setPermissions(const Permissions& ps) {
    std::optional<bool> can_do_cpu_wide;
    std::optional<bool> can_do_task_kernel;

    if (ps.count(Permission::Tracepoints)) {
      // XXX: Set /proc/sys/kernel/perf_event_paranoid to -1
      // XXX: Set CAP_PERFMON or CAP_SYS_ADMIN
    }
    if (ps.count(Permission::CpuWideEvents) &&
        (!can_do_cpu_wide.has_value() || !*can_do_cpu_wide)) {
      // XXX: Set /proc/sys/kernel/perf_event_paranoid to -1 or
      // XXX: Set CAP_PERFMON or CAP_SYS_ADMIN
    }
    if (ps.count(Permission::TaskKernel) &&
        (!can_do_task_kernel.has_value() || !*can_do_task_kernel)) {
      // XXX: Set /proc/sys/kernel/perf_event_paranoid to 0
      // XXX: Set CAP_PERFMON or CAP_SYS_ADMIN
    }

    if (ps.count(Permission::SchedStats)) {
      // XXX: Set /proc/sys/kernel/sched_stats
    }
    return false;
  }
};

struct Kernel {
  // The expected path to the Linux kernel image, which is
  // "/boot/vmlinux-`uname`" by default. If the kernel image doesn't exist on
  // the default path, user need to modify "trace.json" file before loading it
  // into lldb.
  std::string release;

 public:
  static Kernel create() {
    struct utsname buffer;
    int err = uname(&buffer);
    std::string release;

    HBT_THROW_SYSTEM_IF(err != 0, errno)
        << "uname threw an error when trying to identify the kernel image";
    return Kernel(buffer.release);
  }

  std::optional<std::string> image_expected_path() const {
    std::string image_expected_path = fmt::format("/boot/vmlinux-{}", release);
    if (!std::filesystem::exists(image_expected_path)) {
      HBT_LOG_WARNING() << image_expected_path << " not exist";
      return std::nullopt;
    }
    return image_expected_path;
  }

 private:
  explicit Kernel(std::string release) : release(release) {}
};

#if defined(__i386__) || defined(__x86_64__)
inline TimeStamp rdtscp(CpuId& cpu) {
  TimeStamp tstamp = __rdtscp(&cpu);
  // Lower 12 bits are the CPU, next 12 are socket.
  cpu = cpu & 0xFFF;
  return tstamp;
}

#elif defined(__aarch64__)
inline TimeStamp rdtscp(CpuId& cpu) {
  TimeStamp tstamp;
  // we don't have an equivalent to rdtscp, so we have to live with
  // a racey rdtsc-equivalent + sched_getcpu()
  asm volatile("mrs %0, cntvct_el0" : "=r"(tstamp));
  cpu = getCpu();
  return tstamp;
}
#endif

inline std::pair<TimeStamp, CpuId> rdtscp() {
  CpuId cpu_id;
  auto tstamp = rdtscp(cpu_id);
  return std::make_pair(tstamp, cpu_id);
}

cpu_set_t parseCpusRange(std::string cpu_range_str);

cpu_set_t parseCpusList(std::string cpus_str);

std::set<CpuId> parseCpusListToSet(std::string cpus_str);

/// Open path and read content in chunks of <read_size> bytes.
std::pair<std::error_code, std::vector<unsigned char>> readProcFsByteStr(
    const char* path,
    size_t read_size = 128) noexcept;

inline std::optional<std::string> readProcFsComm(pid_t tid) noexcept {
  // Read size is one byte more than the 16 Linux keeps in comm
  // so it detects the end of string at the first iteration.
  std::string path = "/proc/" + std::to_string(tid) + "/comm";
  auto [err, s] = readProcFsByteStr(path.c_str(), 17);
  if (err) {
    return std::nullopt;
  }
  // There is always a null character, stop at breakline if there is one.
  std::vector<char> ends = {'\0', '\n'};
  auto end_it =
      std::find_first_of(s.begin(), s.end(), ends.begin(), ends.end());
  return std::string(s.begin(), end_it);
}

inline std::optional<std::string> readProcFsCmdLine(pid_t tid) noexcept {
  pfs::procfs pfs;
  try {
    auto vec = pfs.get_task(tid).get_cmdline();
    return fmt::format("{}", fmt::join(vec, " "));
  } catch (const std::system_error&) {
    return std::nullopt;
  }
}

inline std::optional<std::string> readProcFsCgroup(pid_t tid) noexcept {
  std::string path = "/proc/" + std::to_string(tid) + "/cgroup";
  auto [err, s] = readProcFsByteStr(path.c_str());
  if (err) {
    return std::nullopt;
  }
  // There is always a null character, stop at breakline if there is one.
  std::vector<char> ends = {'\0', '\n'};
  auto end_it =
      std::find_first_of(s.begin(), s.end(), ends.begin(), ends.end());
  return std::string(s.begin(), end_it);
}

inline int readIntFromFile(std::string filepath) {
  auto [err, s] = readProcFsByteStr(filepath.c_str());
  if (!err) {
    return std::stoi(std::string(s.begin(), s.end()));
  }
  return 0;
}

//
// System functions
//

/// Wrapper for gethostname
inline std::string getHostName() {
  char b[HOST_NAME_MAX];
  int ret = ::gethostname(b, HOST_NAME_MAX);
  HBT_THROW_SYSTEM_IF(0 > ret, errno);
  return std::string{b};
}

// Wrapper for getlogin
inline std::string getLoginId() {
  return {::getlogin()};
}

//
// Useful math functions to work with CPU and binary integers
//

/// Is it a Power of 2?.
/// n must be 1, 2, or another value such that n = 2^k for a natural k.
constexpr bool isPow2(uint64_t n) noexcept {
  return n > 0 && !((n - 1) & n);
}

/// Smallest power of 2 larger or equal to <n>.
/// Undefined for n == 0.
constexpr uint32_t nextPow2(uint32_t n) noexcept {
  --n;

  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;

  return n + 1;
}

/// Smallest power of 2 larger or equal to <n>.
/// Undefined for n == 0.
constexpr uint64_t nextPow2(uint64_t n) noexcept {
  --n;

  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n |= n >> 32;

  return n + 1;
}

/// Largest power of 2 less or equal to <n>
/// Undefined for n == 0.
constexpr uint64_t maxPow2LessEqualThan(uint64_t n) noexcept {
  if (isPow2(n)) {
    return n;
  }
  return nextPow2(n) >> 1;
}

/// Logarithm base 2 of the smallest power of 2 larger or equal to <n>.
/// This is equivalent to the depth of the smallest perfectly balanced
/// binary tree with at least <n> leaf nodes.
/// Undefined for n == 0.
inline uint32_t log2NextPow2(uint32_t n) noexcept {
  return static_cast<uint32_t>(__builtin_ctz(nextPow2(n)));
}

/// Logarithm base 2 of the smallest power of 2 larger or equal to <n>.
/// This is equivalent to the depth of the smallest perfectly balanced
/// binary tree with at least <n> leaf nodes.
/// Undefined for n == 0.
inline uint32_t log2NextPow2(uint64_t n) noexcept {
  return static_cast<uint32_t>(__builtin_ctzl(nextPow2(n)));
}

} // namespace facebook::hbt
