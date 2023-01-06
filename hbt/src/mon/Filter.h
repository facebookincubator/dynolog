// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/mon/MonData.h"
#include "hbt/src/tagstack/Event.h"
#include "hbt/src/tagstack/Slicer.h"

#include <list>

namespace facebook::hbt::mon::filter {

using CuSliceSel = std::vector<bool>;
using CuSlicesSel = std::vector<CuSliceSel>;
using CuCountSel = std::vector<bool>;

/// A selection for counts and slices for a ComputeUnit.
/// The higher level vector represents counts. Count is selected if it
/// has a value. The lower level vector (when present) represents slices.
struct CuSel {
  std::optional<CuCountSel> sel_counts;
  std::optional<CuSlicesSel> sel_slices;

  // Build with all selected.
  explicit CuSel(const CuMonData& cu_md);

  CuSel(const CuSel& other)
      : sel_counts(other.sel_counts), sel_slices{other.sel_slices} {}

  CuSel(CuSel&& other) noexcept
      : sel_counts(std::move(other.sel_counts)),
        sel_slices{std::move(other.sel_slices)} {}

  CuSel& operator=(const CuSel& other) {
    sel_counts = other.sel_counts;
    sel_slices = other.sel_slices;
    return *this;
  }

  CuSel& operator=(CuSel&& other) noexcept {
    sel_counts = std::move(other.sel_counts);
    sel_slices = std::move(other.sel_slices);
    return *this;
  }

  std::ostream& toStr(std::ostream& os) const;
};

struct Sel : public std::unordered_map<tagstack::CompUnitId, CuSel> {
  std::ostream& toStr(std::ostream& os) const;
};

class FilterChain {
 public:
  /// A discrete step in the multi-step filtering process.
  struct Step {
    std::optional<cpu_set_t> cpus;

    Step(std::optional<cpu_set_t> cpus = std::nullopt) : cpus{cpus} {}

    /// Apply filter to all CuMonDatas.
    virtual Sel apply(const Sel& initial_sel, const MonData& md) const;

    /// Apply filter to CuMonData.
    virtual CuSel applyCu(const CuSel& sel, const CuMonData& cu_md) const = 0;

    virtual ~Step() {}
  };

  explicit FilterChain(std::shared_ptr<MonData> md) : md_{md} {}

  FilterChain& add(std::shared_ptr<Step> step) {
    steps_.push_back(step);
    return *this;
  }

  /// Applies all steps and generate a new MonData.
  std::shared_ptr<MonData> apply() const;

  virtual ~FilterChain() {}

 protected:
  std::shared_ptr<MonData> md_;
  std::list<std::shared_ptr<Step>> steps_;

  std::shared_ptr<MonData> makeMonData_(const Sel& sel) const;

  std::unique_ptr<CuMonData> makeCuMonData_(
      tagstack::CompUnitId cu_id,
      const CuSel& sel) const;
};

/// Keep all counts and slices that overlap with interval [start, end),
/// up to <max_num>.
struct ByTimeStamp : public FilterChain::Step {
  TimeStamp start = kInvalidTimeStamp;
  TimeStamp end = kInvalidTimeStamp;
  size_t max_num_elems = std::numeric_limits<size_t>::max();

  /// Apply timestamp range to counts.
  bool filterCountIntervals = true;
  /// Apply timestamp range to slice intervals.
  bool filterSliceIntervals = true;

  virtual CuSel applyCu(const CuSel& sel, const CuMonData& cu_md)
      const override;

  CuSel filterCounts(const CuSel& sel, const CuMonData& cu_md) const;

  CuSel filterSlices(const CuSel& sel, const CuMonData& cu_md) const;
};

// Trim all slice intervals without an associated count.
struct TrimSlices : public FilterChain::Step {
  virtual CuSel applyCu(const CuSel& sel, const CuMonData& cu_md)
      const override;
};

/// Filter out slices not with stack ID not in <keep>.
struct HasTagStackId : public FilterChain::Step {
  using TagStackId = hbt::tagstack::slice::TagStackId;

  HasTagStackId(
      const std::vector<TagStackId>& to_keep,
      bool keep_interval,
      std::optional<cpu_set_t> cpus = std::nullopt)
      : FilterChain::Step{cpus},
        to_keep{to_keep},
        keep_interval{keep_interval} {}

  virtual CuSel applyCu(const CuSel& sel, const CuMonData& cu_md)
      const override;

  std::vector<TagStackId> to_keep;
  bool keep_interval;
};

/// Negate logical.
struct NotOp : public FilterChain::Step {
  explicit NotOp(std::shared_ptr<FilterChain::Step> operand)
      : operand{operand} {}

  virtual CuSel applyCu(const CuSel& sel, const CuMonData& cu_md)
      const override;

  std::shared_ptr<FilterChain::Step> operand;
};

enum class BinaryOpType {
  Or,
  And,
  Xor,
};

// Accumulate with a binary operation.
template <BinaryOpType kType>
struct BinaryOp : public FilterChain::Step {
  explicit BinaryOp(std::vector<std::shared_ptr<FilterChain::Step>> operands)
      : operands{operands} {
    HBT_ARG_CHECK_GE(operands.size(), 2)
        << "At least two operands required for accumulating binary operation";
  }

  /// Apply binary filter.
  virtual CuSel applyCu(const CuSel& sel, const CuMonData& cu_md)
      const override {
    // Apply first filter.
    CuSel new_sel = operands.at(0)->applyCu(sel, cu_md);

    HBT_THROW_ASSERT_IF(
        sel.sel_counts.has_value() != new_sel.sel_counts.has_value());
    HBT_THROW_ASSERT_IF(
        sel.sel_slices.has_value() != new_sel.sel_slices.has_value());

    // Apply the rest of the filters.
    for (size_t i = 1; i < operands.size(); ++i) {
      auto b_sel = operands.at(i)->applyCu(sel, cu_md);

      HBT_THROW_ASSERT_IF(
          sel.sel_counts.has_value() != b_sel.sel_counts.has_value());

      HBT_THROW_ASSERT_IF(
          sel.sel_slices.has_value() != b_sel.sel_slices.has_value());

      if (b_sel.sel_counts.has_value()) {
        HBT_DCHECK_EQ(new_sel.sel_counts->size(), b_sel.sel_counts->size())
            << "Inconsistent number of count intervals in selections";
      }
      if (b_sel.sel_slices.has_value()) {
        HBT_DCHECK_EQ(new_sel.sel_slices->size(), b_sel.sel_slices->size())
            << "Inconsistent number of slice intervals in selections";
      }

      // Apply to counts.
      if (b_sel.sel_counts.has_value()) {
        auto new_it = new_sel.sel_counts->begin();
        auto b_it = b_sel.sel_counts->cbegin();

        while (new_it != new_sel.sel_counts->end()) {
          HBT_DCHECK(b_it != b_sel.sel_counts->cend());
          if constexpr (BinaryOpType::Or == kType) {
            *new_it = *new_it || *b_it;
          } else if (BinaryOpType::And == kType) {
            *new_it = *new_it && *b_it;
          } else if (BinaryOpType::Xor == kType) {
            *new_it = *new_it ^ *b_it;
          }
        }
      }
      // Apply to slices
      if (b_sel.sel_slices.has_value()) {
        for (size_t c = 0; c < b_sel.sel_slices->size(); ++c) {
          auto& new_sel_slices = new_sel.sel_slices->at(c);
          const auto& b_sel_slices = b_sel.sel_slices->at(c);

          for (size_t s = 0; s < b_sel_slices.size(); ++s) {
            if constexpr (BinaryOpType::Or == kType) {
              new_sel_slices[s] = new_sel_slices[s] || b_sel_slices[s];
            } else if (BinaryOpType::And == kType) {
              new_sel_slices[s] = new_sel_slices[s] && b_sel_slices[s];
            } else if (BinaryOpType::Xor == kType) {
              new_sel_slices[s] = new_sel_slices[s] ^ b_sel_slices[s];
            }
          }
        }
      }
    }
    return new_sel;
  }

  std::vector<std::shared_ptr<FilterChain::Step>> operands;
};

using LogicalOr = BinaryOp<filter::BinaryOpType::Or>;
using LogicalAnd = BinaryOp<filter::BinaryOpType::And>;
using LogicalXor = BinaryOp<filter::BinaryOpType::Xor>;

} // namespace facebook::hbt::mon::filter
