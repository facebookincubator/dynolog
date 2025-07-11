// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <string>
#include <vector>


namespace facebook::dynolog {

/*
 * Split a line into a vector of non-empty tokens by delimiter.
 *
 * Usage example:
 *
 *  const std::string line = "hello world";
 *  std::vector<std::string_view> tokens = split(line, ' ');
 *  assert(tokens == {"hello", "world"});
 */
std::vector<std::string> split(const std::string& line, char delim);

} // namespace facebook::dynolog

