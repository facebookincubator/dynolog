// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

#pragma once

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "KernelCollectorBase.h"
#include "Logger.h"

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
