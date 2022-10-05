// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/mon/Filter.h"

#include <list>

using namespace facebook::hbt::mon;
using namespace facebook::hbt::mon::filter;
using namespace facebook::hbt::phase;

// Build with all selected.
CuSel::CuSel(const CuMonData& cu_md) {
  if (cu_md.count_data) {
    sel_counts = CuCountSel(cu_md.count_data->numIntervals(), true);
  }
  if (cu_md.per_interval_slices) {
    const auto& pis = *cu_md.per_interval_slices;
    sel_slices = CuSlicesSel(pis.numIntervals());
    for (size_t i = 0; i < pis.numIntervals(); ++i) {
      auto& s = pis[i];
      // Vector is empty, so resize will create all new elements.
      sel_slices->operator[](i).resize(s.size(), true);
    }
    if (cu_md.count_data) {
      HBT_ARG_CHECK_EQ(
          cu_md.count_data->numIntervals(), cu_md.per_interval_slices->size())
          << "Counts and slices have different sizes";
    }
  }
}

std::ostream& CuSel::toStr(std::ostream& os) const {
  auto print_v = [&os](const auto& v) {
    for (auto b : v) {
      os << (b ? "T " : "F ");
    }
  };

  os << "<CuSel \tsel_counts: ";
  if (sel_counts.has_value()) {
    print_v(*sel_counts);
  } else {
    os << "<NA>";
  }

  os << "\n\tsel_slices:\n\t";
  if (sel_slices.has_value()) {
    for (const auto& slices : *sel_slices) {
      os << "\n\t";
      print_v(slices);
    }
  } else {
    os << "<NA>";
  }
  return os << "\n";
}

std::ostream& Sel::toStr(std::ostream& os) const {
  os << "<Sel";
  for (const auto& [cu_id, cu_sel] : *this) {
    os << "\n\tcu_id:" << cu_id;
    cu_sel.toStr(os);
  }
  return os << ">\n";
}

/// Apply filter to all CuMonDatas.
Sel FilterChain::Step::apply(const Sel& initial_sel, const MonData& md) const {
  // Make a copy.
  Sel new_sel = initial_sel;
  for (const auto& [cu_id, cu_md] : md.per_cu_mon_data) {
    if (cpus.has_value() && !CPU_ISSET(cu_id, &(*cpus))) {
      continue;
    }
    new_sel.at(cu_id) =
        applyCu(new_sel.at(cu_id), *md.per_cu_mon_data.at(cu_id));
  }
  return new_sel;
}

/// Applies all steps and generate a new MonData.
std::shared_ptr<MonData> FilterChain::apply() const {
  // Start with all slices and all counts selected.
  Sel sel;
  for (const auto& [cu_id, cu_md_ptr] : md_->per_cu_mon_data) {
    sel.emplace(cu_id, *cu_md_ptr);
  }

  // Apply all filters.
  for (const auto& filter : steps_) {
    sel = filter->apply(sel, *md_);
  }

  return makeMonData_(sel);
}

std::shared_ptr<MonData> FilterChain::makeMonData_(const Sel& sel) const {
  MonData::PerCuMonData per_cu_md;
  for (const auto& [cu_id, cu_sel] : sel) {
    per_cu_md[cu_id] = makeCuMonData_(cu_id, cu_sel);
  }
  std::shared_ptr<MetaDataContainer> metadata;
  if (md_->metadata) {
    metadata = md_->metadata->clone();
    HBT_THROW_ASSERT_IF(metadata == nullptr);
  }
  return std::make_unique<MonData>(
      md_->short_desc,
      md_->long_desc,
      md_->ts_converter,
      md_->partition_source_key,
      std::move(per_cu_md),
      metadata);
}

std::unique_ptr<CuMonData> FilterChain::makeCuMonData_(
    tagstack::CompUnitId cu_id,
    const CuSel& sel) const {
  auto it = md_->per_cu_mon_data.find(cu_id);
  HBT_DCHECK(it != md_->per_cu_mon_data.end());
  const auto& cu_md = it->second;
  HBT_THROW_ASSERT_IF(cu_md == nullptr);

  std::unique_ptr<CountData> cd;
  std::unique_ptr<tagstack::PerIntervalSlices> pislices;

  if (cu_md->count_data) {
    HBT_DCHECK(sel.sel_counts.has_value());
    cd = cu_md->count_data->filter(*sel.sel_counts);
  }
  if (cu_md->per_interval_slices) {
    HBT_DCHECK(sel.sel_slices.has_value());
    pislices = cu_md->per_interval_slices->filter(*sel.sel_slices);
  }
  return std::make_unique<CuMonData>(std::move(cd), std::move(pislices));
}

//
// Filters
//

CuSel ByTimeStamp::applyCu(const CuSel& sel, const CuMonData& cu_md) const {
  if (sel.sel_counts.has_value() && sel.sel_slices.has_value()) {
    HBT_DCHECK_EQ(sel.sel_counts->size(), sel.sel_slices->size())
        << "Inconsistent sizes between count and slices.";
  }
  if (!filterCountIntervals && !filterSliceIntervals) {
    return sel;
  }

  CuSel new_sel = sel;
  if (filterCountIntervals) {
    new_sel = filterCounts(new_sel, cu_md);
  }
  if (filterSliceIntervals) {
    new_sel = filterSlices(new_sel, cu_md);
  }
  return new_sel;
}

// Drop slices with no intersection at all with range.
CuSel ByTimeStamp::filterSlices(const CuSel& sel, const CuMonData& cu_md)
    const {
  HBT_THROW_ASSERT_IF(
      sel.sel_slices.has_value() != (cu_md.per_interval_slices != nullptr));
  HBT_ARG_CHECK(sel.sel_slices.has_value());

  auto range = cu_md.getPerIntervalSlicesTimeStampRange();
  if (!range.has_value()) {
    return sel;
  }

  auto [rstart, rend] = range.value();
  HBT_DCHECK_LE(rstart, rend);
  size_t num = sel.sel_slices->size();
  HBT_DCHECK_GT(num, 0);
  // Inclusive indices.
  size_t start_idx = 0, end_idx = num - 1;
  if (start != kInvalidTimeStamp) {
    if (start >= rend) {
      start_idx = num;
    } else {
      auto last = cu_md.findSliceIntervalAt(start);
      HBT_DCHECK(last.has_value());
      start_idx = *last;
    }
  }

  if (end != kInvalidTimeStamp) {
    if (end <= rstart) {
      HBT_DCHECK_EQ(start_idx, 0);
      end_idx = 0;
    } else {
      auto last = cu_md.findSliceIntervalAt(end);
      HBT_DCHECK(last.has_value());
      end_idx = *last;
    }
  }
  HBT_DCHECK_GE(end_idx, start_idx);

  // Trim the last element to return up to max_num_elems.
  if (end_idx - start_idx + 1 > max_num_elems) {
    end_idx = max_num_elems - 1;
  }

  // Set to false everything outside [rstart, rend),
  // the selection of the slices within the range
  // is unchanged.
  auto new_sel = sel;
  auto& sel_slices = *new_sel.sel_slices;

  for (size_t idx = 0; idx < start_idx; ++idx) {
    auto& si = sel_slices[idx];
    std::fill(si.begin(), si.end(), false);
  }

  auto new_size = new_sel.sel_slices->size();
  for (size_t idx = end_idx + 1; idx < new_size; ++idx) {
    auto& si = sel_slices[idx];
    std::fill(si.begin(), si.end(), false);
  }

  return new_sel;
}

/// Drop counts with no intersection at all with range.
CuSel ByTimeStamp::filterCounts(const CuSel& sel, const CuMonData& cu_md)
    const {
  HBT_THROW_ASSERT_IF(
      sel.sel_counts.has_value() != (cu_md.count_data != nullptr));
  HBT_ARG_CHECK(sel.sel_counts.has_value());

  auto range = cu_md.getCountDataTimeStampRange();
  if (!range.has_value()) {
    return sel;
  }

  auto [rstart, rend] = range.value();
  HBT_DCHECK_LE(rstart, rend);
  size_t num = sel.sel_counts->size();
  HBT_DCHECK_GT(num, 0);
  // Inclusive indices.
  size_t start_idx = 0, end_idx = num - 1;
  if (start != kInvalidTimeStamp) {
    if (start >= rend) {
      start_idx = num;
    } else {
      auto last = cu_md.findCountAt(start);
      HBT_DCHECK(last.has_value());
      start_idx = *last;
    }
  }

  if (end != kInvalidTimeStamp) {
    if (end <= rstart) {
      HBT_DCHECK_EQ(start_idx, 0);
      end_idx = 0;
    } else {
      auto last = cu_md.findCountAt(end);
      HBT_DCHECK(last.has_value());
      end_idx = *last;
    }
  }
  HBT_DCHECK_GE(end_idx, start_idx);

  // Trim the last element to return up to max_num_elems.
  if (end_idx - start_idx + 1 > max_num_elems) {
    end_idx = max_num_elems - 1;
  }

  // Set to false everything outside [rstart, rend),
  // the selection of the slices within the range
  // is unchanged.
  auto new_sel = sel;
  std::fill(
      new_sel.sel_counts->begin(),
      new_sel.sel_counts->begin() + static_cast<ssize_t>(start_idx),
      false);

  std::fill(
      new_sel.sel_counts->begin() + static_cast<ssize_t>(end_idx) + 1,
      new_sel.sel_counts->end(),
      false);

  return new_sel;
}

CuSel TrimSlices::applyCu(const CuSel& sel, const CuMonData& cu_md) const {
  HBT_THROW_ASSERT_IF(
      sel.sel_counts.has_value() != (cu_md.count_data != nullptr));
  HBT_ARG_CHECK(sel.sel_counts.has_value());

  HBT_THROW_ASSERT_IF(
      sel.sel_slices.has_value() != (cu_md.per_interval_slices != nullptr));
  HBT_ARG_CHECK(sel.sel_slices.has_value());

  HBT_DCHECK_EQ(sel.sel_counts->size(), sel.sel_slices->size());

  // Make a copy.
  auto new_sel = sel;
  if (sel.sel_counts.has_value() && sel.sel_slices.has_value()) {
    HBT_DCHECK_EQ(new_sel.sel_counts->size(), new_sel.sel_slices->size());
  }

  const auto& selc = *new_sel.sel_counts;
  auto& sels = *new_sel.sel_slices;
  HBT_THROW_ASSERT_IF(selc.size() != sels.size());
  // Unselect slice intervals in unselected count intervals.
  for (size_t c = 0; c < sel.sel_counts->size(); ++c) {
    if (!selc[c]) {
      auto& v = sels[c];
      std::fill(v.begin(), v.end(), false);
    }
  }
  return new_sel;
}

CuSel HasTagStackId::applyCu(const CuSel& sel, const CuMonData& cu_md) const {
  HBT_ARG_CHECK(sel.sel_slices.has_value());
  HBT_THROW_ASSERT_IF(cu_md.per_interval_slices == nullptr);
  if (sel.sel_counts.has_value() && sel.sel_slices.has_value()) {
    HBT_DCHECK_EQ(sel.sel_counts->size(), sel.sel_slices->size());
  }

  CuSel new_sel = sel;
  size_t c_idx = 0;
  for (const auto& slices : *cu_md.per_interval_slices) {
    if (keep_interval) {
      // Keep all slices in count intervals where there is at least
      // one slice of a tagstack id to keep.
      auto& sel_slices = new_sel.sel_slices->at(c_idx);
      std::fill(sel_slices.begin(), sel_slices.end(), false);
      for (const auto& s : slices) {
        auto it = std::find(to_keep.begin(), to_keep.end(), s.stack_id);
        if (it != to_keep.end()) {
          std::fill(sel_slices.begin(), sel_slices.end(), true);
          break;
        }
      }
    } else {
      size_t s_idx = 0;
      for (const auto& s : slices) {
        auto it = std::find(to_keep.begin(), to_keep.end(), s.stack_id);
        if (it == to_keep.end()) {
          // stack_id not found in slice, unselect this slice.
          auto& sel_slices = new_sel.sel_slices->at(c_idx);
          HBT_DCHECK_LT(s_idx, sel_slices.size());
          sel_slices[s_idx] = false;
        }
        ++s_idx;
      }
    }
    ++c_idx;
  }
  return new_sel;
}

CuSel NotOp::applyCu(const CuSel& sel, const CuMonData& cu_md) const {
  if (sel.sel_counts.has_value() && sel.sel_slices.has_value()) {
    HBT_DCHECK_EQ(sel.sel_counts->size(), sel.sel_slices->size());
  }

  CuSel new_sel = operand->applyCu(sel, cu_md);
  if (new_sel.sel_counts.has_value()) {
    new_sel.sel_counts->flip();
  }
  if (new_sel.sel_slices.has_value()) {
    for (auto& ssel : *new_sel.sel_slices) {
      ssel.flip();
    }
  }
  return new_sel;
}
