/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// Dynolog : A portable telemetry monitoring daemon.

#include "dynolog/src/Daemon.h"

int main(int argc, char** argv) {
  return dynolog::runDynolog(argc, argv);
}
