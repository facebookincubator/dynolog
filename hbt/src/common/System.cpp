// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/common/System.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <system_error>
#include <thread>

namespace facebook::hbt {

std::string tstampToStr(TimeStamp ts) {
  if (ts == kInvalidTimeStamp) {
    return "NA";
  }
  // print timestaps in milliseconds.
  constexpr TimeStamp kDiv = 1000000u;
  std::stringstream ss;
  ss << ts / kDiv;
  ss << "." << std::setw(6) << std::setfill('0') << ts % kDiv << "ms";
  return ss.str();
}

std::ostream& operator<<(std::ostream& os, const TimeStampRange& r) {
  return os << "[" << tstampToStr(r.first) << ", " << tstampToStr(r.second)
            << ")";
}

// Read in chunks of read_size.
std::pair<std::error_code, std::vector<unsigned char>> readProcFsByteStr(
    const char* path,
    size_t read_size) noexcept {
  if (read_size == 0) {
    return {{}, {}};
  }

  int fd = ::open(path, 0);
  if (0 > fd) {
    return {toErrorCode(errno), {}};
  }

  std::vector<unsigned char> content(read_size);

  size_t offset = 0;

  while (true) {
    ssize_t r = ::read(fd, content.data() + offset, read_size);
    if (0 > r) {
      ::close(fd);
      return {toErrorCode(errno), {}};
    }
    size_t delta = static_cast<size_t>(r);
    offset += delta;
    if (r < read_size) {
      ::close(fd);
      // Drop empty space.
      content.resize(offset);
      return {{}, content};
    }
    // Grow to be able to hold next chunk.
    content.resize(read_size + offset);
  }
}

std::string removeBlanks(std::string s) {
  // Remove blanks.
  s.erase(
      std::remove_if(
          s.begin(), s.end(), [](unsigned char c) { return std::isspace(c); }),
      s.end());
  return s;
}

std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
  str.erase(0, str.find_first_not_of(chars));
  return str;
}

std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
  str.erase(str.find_last_not_of(chars) + 1);
  return str;
}

std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
  return ltrim(rtrim(str, chars), chars);
}

/// Parse a CPU range or a single CPU id.
/// CPU_RANGE := <unsigned> | <unsigned>-<unsigned>
cpu_set_t parseCpusRange(std::string cpu_range_str) {
  cpu_range_str = removeBlanks(cpu_range_str);

  cpu_set_t cpus;
  CPU_ZERO(&cpus);

  if (cpu_range_str.size() == 0) {
    return cpus;
  }

  std::istringstream s(cpu_range_str);
  std::string cpu_str;

  // Get first CPU in range (or one CPU).
  std::getline(s, cpu_str, '-');

  unsigned long cpu_start = std::stoul(cpu_str);
  if (s.eof()) {
    // No range, just one CPU.
    CPU_SET(cpu_start, &cpus);
    return cpus;
  }

  // Get second CPU in range.
  std::getline(s, cpu_str);
  unsigned long cpu_end = std::stoul(cpu_str);
  if (cpu_end <= cpu_start) {
    HBT_THROW_EINVAL() << "Ill-formed CPU range. "
                       << "End CPU id must be larger than start CPU id. "
                       << "String: \"" << cpu_range_str << "\"";
  }

  for (unsigned long c = cpu_start; c <= cpu_end; ++c) {
    CPU_SET(c, &cpus);
  }
  return cpus;
}

cpu_set_t parseCpusList(std::string cpus_str) {
  cpu_set_t cpus;
  CPU_ZERO(&cpus);

  cpus_str = removeBlanks(cpus_str);
  std::istringstream cpus_stream(cpus_str);

  std::string cpu_range_str;
  do {
    std::getline(cpus_stream, cpu_range_str, ',');
    cpu_set_t new_cpus = parseCpusRange(cpu_range_str);
    CPU_OR(&cpus, &new_cpus, &cpus);
  } while (!cpus_stream.eof());
  return cpus;
}

std::set<CpuId> parseCpusListToSet(std::string cpus_str) {
  auto cpus = parseCpusList(cpus_str);
  std::set<CpuId> cpu_set;
  for_each_cpu_set_t(c, cpus) {
    cpu_set.insert(c);
  }
  return cpu_set;
}

// Parse a text file with one line of text that is a comma-separated
// list of CPU ranges. E.g. 0,1-2,10-11,14.
cpu_set_t parseCpuLineFile(const std::string& path) {
  // Open file.
  std::ifstream s;
  s.open(path, std::ios::in);
  if (!s.is_open()) {
    HBT_THROW_SYSTEM(ENFILE) << "File \"" << path << "\" not found";
  }

  // Parse line of CPUs. Expect only one line.
  std::string cpu_list;
  std::getline(s, cpu_list);
  if (!s.eof()) {
    std::string next_line;
    std::getline(s, next_line);
    if (next_line.size() > 0) {
      s.close();
      HBT_THROW_SYSTEM(EINVAL)
          << "File " << path << " must contain only one line. "
          << "Superfluous content starts at: \"" << next_line << "\"";
    }
  }
  s.close();
  return parseCpusList(cpu_list);
}

/// Parse online and offline CPU IDs from proc fs.
/// If cpus are provided, make CpuSet with only given CPUs as online,
/// all given cpus are validated to actually be online.
CpuSet makeCpuSet(std::optional<cpu_set_t> cpus) {
  auto online_cpus = parseCpuLineFile("/sys/devices/system/cpu/online");
  auto offline_cpus = parseCpuLineFile("/sys/devices/system/cpu/offline");

  if (CPU_COUNT(&online_cpus) == 0) {
    HBT_THROW_SYSTEM(EPERM) << "At least one CPU must be online";
  }
  if (CPU_COUNT(&offline_cpus) != 0) {
    HBT_LOG_ERROR() << "Hot-plug CPU currently not supported.";
  }

  CpuId max_cpu_id_online = 0;
  for (CpuId c = 0; c < CPU_SETSIZE; ++c) {
    if (CPU_ISSET(c, &online_cpus)) {
      max_cpu_id_online = std::max(max_cpu_id_online, c);
    }
  }
  static_assert(kMaxCpus > 0);
  if (max_cpu_id_online > kMaxCpus - 1) {
    HBT_THROW_SYSTEM(ENOTSUP)
        << "Larger online  CPU ID found to be " << max_cpu_id_online
        << " but compile-time hard maximum is " << kMaxCpus - 1
        << " Do you want to increase kMaxCpus?";
  }

  if (!cpus.has_value()) {
    // if no value is passed, then use all online CPUs.
    return CpuSet(online_cpus, max_cpu_id_online, max_cpu_id_online);
  }

  // cpus are provided, use them.
  CpuId max_cpu_id = 0;
  for_each_cpu_set_t(c, *cpus) {
    if (CPU_ISSET(c, &(*cpus))) {
      if (!CPU_ISSET(c, &online_cpus)) {
        HBT_THROW_SYSTEM(ENOTSUP) << "CPU " << c << " not online";
      }
      max_cpu_id = std::max(max_cpu_id, c);
    }
  }

  return CpuSet(*cpus, max_cpu_id, max_cpu_id_online);
}

CpuSet CpuSet::makeAllOnline() {
  return makeCpuSet(std::nullopt);
}

CpuSet CpuSet::makeFromCpuSet(cpu_set_t cpu_set) {
  return makeCpuSet(cpu_set);
}

CpuSet CpuSet::getOrDefault(std::optional<CpuSet> opt) {
  if (opt.has_value()) {
    return *opt;
  } else {
    return makeAllOnline();
  }
}

std::set<CpuId> CpuSet::asSet() const {
  std::set<CpuId> s;
  for_each_cpu(cpu, *this) {
    s.insert(cpu);
  }
  return s;
}

// Return index of next set CPU.
CpuId CpuSet::cpu_set_next(CpuId cpu) const noexcept {
  ++cpu;
  for (; cpu <= max_cpu_id; ++cpu) {
    if (CPU_ISSET(cpu, &cpu_set)) {
      break;
    }
  }
  return cpu;
}

CpuId CpuSet::cpu_first_set() const noexcept {
  if (CPU_ISSET(0, &cpu_set)) {
    return 0u;
  } else {
    return cpu_set_next(0);
  }
}

std::string CpuSet::cpusStr() const {
  std::ostringstream oss;

  // Print comma separated ranges.
  CpuId first = cpu_first_set();
  CpuId last = first;

  // Iterate starting after first.
  for (CpuId cpu = cpu_set_next(first); cpu <= max_cpu_id;
       cpu = cpu_set_next(cpu)) {
    if (cpu == last + 1) {
      last = cpu;
    } else {
      if (first == last) {
        oss << first << ",";
      } else {
        oss << first << "-" << last << ",";
      }
      first = last = cpu;
    }
  }

  if (first == last) {
    oss << first;
  } else {
    oss << first << "-" << last;
  }
  return oss.str();
}

std::ostream& operator<<(std::ostream& os, const CpuSet& cpu_set) {
  os << "<CpuSet max_cpu_id: " << cpu_set.max_cpu_id
     << " max_cpu_id_online: " << cpu_set.max_cpu_id_online
     << " cpus: " << cpu_set.cpusStr() << " > ";
  return os;
}

CpuInfo readCpu(std::ifstream& s) {
  std::string _;

  // Fields we care.
  unsigned processor;
  uint32_t cpu_family, cpu_model, cpu_step;
  std::string vendor_id, model_name;

  std::getline(s, _, ':');
  HBT_ARG_CHECK_EQ(trim(_), "processor");
  s >> processor;

  std::getline(s, _, ':');
  HBT_ARG_CHECK_EQ(trim(_), "vendor_id");
  std::getline(s, vendor_id);
  vendor_id = trim(vendor_id);

  std::getline(s, _, ':');
  HBT_ARG_CHECK_EQ(trim(_), "cpu family");
  s >> cpu_family;

  std::getline(s, _, ':');
  HBT_ARG_CHECK_EQ(trim(_), "model");
  s >> cpu_model;

  std::getline(s, _, ':');
  HBT_ARG_CHECK_EQ(trim(_), "model name");
  std::getline(s, model_name);
  model_name = trim(model_name);

  std::getline(s, _, ':');
  HBT_ARG_CHECK_EQ(trim(_), "stepping");
  s >> cpu_step;

  return CpuInfo(vendor_id, cpu_family, cpu_model, cpu_step);
}

CpuInfo CpuInfo::load() {
  std::ifstream s("/proc/cpuinfo");

  // Only read CPU 0.
  return readCpu(s);
}

std::ostream& operator<<(std::ostream& os, const CpuInfo& cpu_info) {
  os << fmt::format(
      "<CpuInfo {0} {1}({2}) {3}({4}) Step: {5}>",
      cpu_info.vendor_id,
      cpu_info.cpu_family,
      cpu_info.cpu_family_num,
      cpu_info.cpu_arch,
      cpu_info.cpu_model_num,
      cpu_info.cpu_step_num);
  return os;
}

// Return index of next set CPU.
CpuId cpu_set_next(CpuId cpu, const cpu_set_t& cpu_set) noexcept {
  ++cpu;
  for (; cpu < kMaxCpus; ++cpu) {
    if (CPU_ISSET(cpu, &cpu_set)) {
      break;
    }
  }
  return cpu;
}

CpuId cpu_first_set(const cpu_set_t& cpu_set) noexcept {
  if (CPU_ISSET(0, &cpu_set)) {
    return 0u;
  } else {
    return cpu_set_next(0, cpu_set);
  }
}

CpuId getCpu() {
  int ret = sched_getcpu();
  if (unlikely(0 > ret)) {
    HBT_THROW_SYSTEM(errno) << "Error reading ID of current CPU.";
  }
  if (ret > kMaxCpus - 1) {
    HBT_THROW_SYSTEM(ENOTSUP)
        << "CPU ID found to be " << ret << " but compile-time hard maximum is "
        << kMaxCpus - 1;
  }

  return static_cast<CpuId>(ret);
}

} // namespace facebook::hbt
