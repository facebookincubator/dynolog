// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include "dynolog/src/String.h"

#include <string>
#include <string_view>
#include <vector>

namespace facebook {
namespace dynolog {

std::vector<std::string> split(const std::string& line, char delim) {
  std::vector<std::string> ret;

  auto emplaceNonEmptySubstr = [&ret, &line](size_t beg, size_t end) {
    size_t len = end - beg;
    if (len > 0) {
      ret.emplace_back(line.begin() + beg, line.begin() + end);
    }
  };

  size_t beg = 0;
  size_t n = line.size();
  for (size_t i = 0; i < n; ++i) {
    if (line[i] == delim) {
      emplaceNonEmptySubstr(beg, i);
      beg = i + 1;
    }
  }
  emplaceNonEmptySubstr(beg, n);

  return ret;
}

} // namespace dynolog
} // namespace facebook
