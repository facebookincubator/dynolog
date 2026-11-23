/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <functional>
#include <memory>
#include <vector>

#include "dynolog/src/Logger.h"

namespace dynolog {

// Each call returns a new logger that writes to every sink the --use_* flags
// enable (JSON, ODS, Scuba, Prometheus, ...), the same set the built-in
// monitors use. include_otel also adds the OTLP logger, which expects one
// finalize() per device record. A monitor may call it once and keep the
// logger, or call it per cycle.
using LoggerFactory = std::function<std::unique_ptr<Logger>(bool include_otel)>;

struct DaemonOptions {
  // Monitors to run in addition to the ones enabled by flags, each on its
  // own thread for the life of the daemon. Flags are parsed by the time a
  // monitor is called, so it should read its own flags (for example an
  // enable flag) then, not when it is constructed. A monitor that throws is
  // logged and stops; the daemon keeps running.
  std::vector<std::function<void(const LoggerFactory&)>> monitors;
};

// Runs the dynolog daemon: parses gflags, initializes glog, starts the
// monitors enabled by flags and `options.monitors`, and serves RPC requests.
// Returns the exit code.
//
// Builds that add their own monitors call this from their own main(). Because
// flag parsing and logging start here, that main() must not read flags or
// log before calling it.
int runDynolog(int argc, char** argv, DaemonOptions options = {});

} // namespace dynolog
