// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

#include <ostream>
#include <string>
#include <vector>

namespace facebook::dynolog {

// for basic visualizaion of a MetricFrame
// print a text table like below
/*
-------------------------------
|         |  t1   | t2  | t3  |
-------------------------------
| metric1 |  12   | 21  | 38  |
-------------------------------
| metric2 | 17423 | 992 | 157 |
-------------------------------
*/

class TextTable {
 public:
  explicit TextTable(std::vector<std::vector<std::string>>&& data);
  std::ostream& show(std::ostream& s);

 private:
  size_t width() const;
  size_t height() const;
  void updateCachedWidth();
  [[nodiscard]] size_t getColWidth(size_t col) const;
  void writeRow(size_t row, std::ostream& s) const;
  void writeLine(std::ostream& s) const;

  std::vector<std::vector<std::string>> data_;
  std::vector<size_t> colWidthCache_;
  const size_t extraPad_ = 2;
};

} // namespace facebook::dynolog
