// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#include "dynolog/src/metric_frame/TextTable.h"

namespace facebook::dynolog {

TextTable::TextTable(std::vector<std::vector<std::string>>&& data)
    : data_{std::move(data)} {}

std::ostream& TextTable::show(std::ostream& s) {
  updateCachedWidth();
  for (size_t row = 0; row < height(); row++) {
    writeLine(s);
    writeRow(row, s);
  }
  writeLine(s);
  return s;
}

size_t TextTable::width() const {
  return data_.empty() ? 0 : data_[0].size();
}

size_t TextTable::height() const {
  return data_.size();
}

void TextTable::updateCachedWidth() {
  colWidthCache_.resize(width());
  for (size_t col = 0; col < width(); col++) {
    colWidthCache_[col] = getColWidth(col);
  }
}

[[nodiscard]] size_t TextTable::getColWidth(size_t col) const {
  size_t width = 0;
  for (const auto& row : data_) {
    width = std::max(width, row[col].size());
  }
  return width;
}

void TextTable::writeRow(size_t row, std::ostream& s) const {
  for (size_t col = 0; col < width(); col++) {
    size_t cellWidth = colWidthCache_[col] + extraPad_;
    size_t textWidth = data_[row][col].size();
    size_t lPad = (cellWidth - textWidth) / 2;
    size_t rPad = cellWidth - textWidth - lPad;
    s << '|';
    for (int i = 0; i < lPad; i++) {
      s << ' ';
    }
    s << data_[row][col];
    for (int i = 0; i < rPad; i++) {
      s << ' ';
    }
  }
  s << '|' << std::endl;
}

void TextTable::writeLine(std::ostream& s) const {
  for (auto cellWidth : colWidthCache_) {
    for (int i = 0; i < cellWidth + 1 + extraPad_; i++) {
      s << '-';
    }
  }
  s << '-' << std::endl;
}

} // namespace facebook::dynolog
