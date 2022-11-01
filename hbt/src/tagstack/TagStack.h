// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "hbt/src/common/System.h"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>

namespace facebook::hbt::tagstack {

// An identifier that is stacked together to form TagStacks.
using Tag = uint32_t;

// Value to represent an Unkwon Tag, aka Non-Applicable, aka missing value.
constexpr Tag kNA = std::numeric_limits<Tag>::max();

// The level of a Tag inside a TagStack. Tagstacks grow
// from level zero upwards.
using Level = uint8_t;
constexpr Level kInvalidLevel = std::numeric_limits<Level>::max();

// Utility function to convert the Tag to string.
inline std::string tagToStr(Tag tag) {
  switch (tag) {
    case kNA:
      return "<NA>";
    default:
      return std::to_string(tag);
  }
}

//
// A Stack (tag stack) represent an Execution context or a "Phase".
//
// A tag stack is a generalization of callstacks to include elements that are
// not function calls, like operators, networks or requesets.
//
// Tags in a tag stack can be pushed and/or popped or can be swith in/out
// of multiple levels at once (e.g. a kernel thread context switch
// switches out all tags in user-space).
//
// Examples of stacks are (shown an [level] tag interpretation):
//   - Program Phases:
//     [0] kernel thread ID
//     [1] user space defined program phase (e.g. Caffe2 operator)
//     [2] (optional) thread's callstack
//
//  - Requests:
//    [0] kernel thread ID
//    [1] request context ID
//    [2] (optional) thread's callstack
//
//  - Caffe2 operators:
//    [0] kernel thread ID
//    [1] network ID
//    [2] operator ID
//
// A key element in design is the support for missing values. A tag
// stack may be missing values by either having a tag with a kNA value
// or by having <known_num_levels> == false. The latter means that
// even though we have non-NA tags, we are uncertain if we are missing
// some tags extra tags in the stack. I.e. the first time we observe
// a thread running we know that its thread ID is active but we don't
// know if there should be an user-space tag stacked on top of it.
//
// A tag is fully determined if it has no kNA tags and <known_num_levels> == 1.
// When instrumenting an application, to guarantee that fully determined
// tags are unique system-wide. In CPUs this is easily achievable by
// making the thread ID the level 0 tag.
//
struct Stack {
  static constexpr Level kMaxNumLevels = 6;
  using Tags = std::array<Tag, kMaxNumLevels>;

  static constexpr Tags makeNaTags() {
    return {kNA, kNA, kNA, kNA, kNA, kNA};
  }
  // Tags in this Stack. Static initialization must match <kMaxNumLevels>.
  const Tags tags = makeNaTags();
  // Num of tags with a valid value (tags at a level at or
  // above num_levels have trash).
  const Level num_set_tags = 0;
  // Whether it's know that <tags> are all tags (even if they are NAs).
  const bool known_num_levels = false;

  explicit Stack() noexcept {}

  /// Fill <num_set_tags> with NA.
  explicit Stack(Level num_set_tags, bool known_num_levels) noexcept
      : num_set_tags{num_set_tags}, known_num_levels{known_num_levels} {
    HBT_DCHECK_LT(num_set_tags, kMaxNumLevels);
  }

  explicit Stack(Tags tags, Level num_set_tags, bool known_num_levels) noexcept
      : tags{tags},
        num_set_tags{num_set_tags},
        known_num_levels{known_num_levels} {}

  // Create a partial copy of this Stack, copying the lowest <num_tags_to_copy>
  // and filling up with kNA if needed.
  Stack copyTruncated(Level num_tags_to_copy, bool new_known_num_levels)
      const noexcept {
    HBT_DCHECK_LT((int)num_tags_to_copy, (int)kMaxNumLevels);
    Tags new_tags;
    // Unset tags are kNA, so they can be copied without worries.
    auto end_it = tags.begin() + num_tags_to_copy;
    std::copy(tags.begin(), end_it, new_tags.begin());
    return Stack{new_tags, num_tags_to_copy, new_known_num_levels};
  }

  Stack copyFillUpTo(Level idx, Tag tag_at_top, bool new_known_num_levels)
      const noexcept {
    Tags new_tags;
    std::copy(tags.begin(), tags.begin() + idx, new_tags.begin());
    new_tags[idx] = tag_at_top;
    return Stack{new_tags, static_cast<Level>(idx + 1), new_known_num_levels};
  }

  // Test if this stack could contain the in s.
  bool contains(const Stack& s, Level num_levels) const noexcept {
    // If  all tags are not known then we cannot tell.
    if (known_num_levels != s.known_num_levels) {
      return false;
    }

    // Tags stacks of zero size are always equal.
    if (num_levels == 0) {
      return num_set_tags == 0;
    }

    if (num_set_tags < num_levels) {
      return false;
    }
    return std::equal(
        std::begin(s.tags), std::begin(s.tags) + num_levels, std::begin(tags));
  }

  bool operator==(const Stack& other) const noexcept {
    HBT_DCHECK_LT(num_set_tags, kMaxNumLevels);
    HBT_DCHECK_LT(other.num_set_tags, kMaxNumLevels);

    return known_num_levels == other.known_num_levels &&
        num_set_tags == other.num_set_tags &&
        std::equal(
               std::begin(tags),
               std::begin(tags) + num_set_tags,
               std::begin(other.tags));
  }

  long numNAs() const noexcept {
    return std::count(tags.begin(), tags.begin() + num_set_tags, kNA);
  }

  bool hasNAs() const noexcept {
    return 0 < numNAs();
  }

  size_t calculateHash() const noexcept {
    static_assert(sizeof(size_t) >= sizeof(Tag));
    static_assert(sizeof(size_t) % sizeof(Tag) == 0);

    const size_t kNum = sizeof(size_t) / sizeof(Tag);

    size_t h = known_num_levels ? 86969 : 76963;

    // Division should be optimized away.
    for (Level i = 0; i < num_set_tags; i += kNum) {
      for (Level j = i; j < std::min((size_t)num_set_tags, i + kNum); ++j) {
        h = h << 1;
        // XOR by large prime number.
        size_t temp = tags[j] ^ 0x9e3779b9;
        h ^= (temp << ((j - i) * sizeof(Tag) * 8));
        h = h >> 1;
      }
    }
    return h;
  }
};

inline std::ostream& operator<<(std::ostream& os, const Stack& s) {
  os << "[ ";
  for (Level i = 0; i < s.num_set_tags; ++i) {
    os << tagToStr(s.tags[i]) << " ";
  }
  if (!s.known_num_levels)
    os << "? ";
  return os << "]";
}

} // namespace facebook::hbt::tagstack

namespace std {

template <>
struct hash<facebook::hbt::tagstack::Stack> {
  // XXX: This hash function is a generic implementation as recommended
  // on stackover. Revisit this before productionizing and chose a
  // final implementation.
  size_t operator()(const facebook::hbt::tagstack::Stack& s) const {
    return s.calculateHash();
  }
};

} // namespace std
