// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include "dynolog/src/KernelCollectorBase.h"
#include "dynolog/src/Logger.h"

namespace dynolog {

/* New and improved Kernel Monitor
 *  - no dependency on Meta infra
 *  - support generic logging
 */
class KernelCollector : public KernelCollectorBase {
 public:
  explicit KernelCollector();

  // perform metric lookups
  void step();

  void log(Logger& logger);
};

} // namespace dynolog
