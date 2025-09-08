/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/metric_frame/ExtraTypes.h"

namespace facebook::dynolog {

std::ostream& operator<<(
    std::ostream& os,
    const PerfReadValues& perfReadValues) {
  os << perfReadValues.toString();
  return os;
}

} // namespace facebook::dynolog
