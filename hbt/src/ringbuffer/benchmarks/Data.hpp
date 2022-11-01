// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <type_traits>

namespace {

struct POD16 {
  int32_t a;
  int32_t b;
  int32_t c;
  int32_t d;
};

static_assert(std::is_pod<POD16>::value, "POD16 is not a POD.");
static_assert(sizeof(POD16) == 16, "Size of POD16 is not 16 bytes");

template <class T>
struct DataTraits;

template <>
struct DataTraits<int> {
  static constexpr int data = 13;
  static constexpr int terminationToken = 0xFFFFFFFF;
  static bool isTerminationToken(int tok) {
    return tok == terminationToken;
  }
};

template <>
struct DataTraits<POD16> {
  static constexpr POD16 data = {1, 2, 3, 4};
  static constexpr POD16 terminationToken = {-1, -1, -1, -1};
  static bool isTerminationToken(const POD16& tok) {
    return tok.a == terminationToken.a;
  }
};

} // end of namespace
