#!/usr/bin/env python3
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

import argparse
import time

from hbt.intel_pt.tracer import Tracer


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Intel PT tracer.")
    parser.add_argument("pid", type=int, default=None, help="PIDs to filter on.")
    parser.add_argument(
        "-c", "--cpus", type=str, default=None, help="CPUs to filter on. E.g. 1-3,5"
    )
    parser.add_argument(
        "-t", "--timeout", type=int, default=5, help="Number of seconds to run for."
    )

    args = parser.parse_args()

    t = Tracer(cpus=args.cpus, pid=args.pid)
    t.start()

    print(f"Running for {args.timeout} seconds")
    for i in range(args.timeout):
        time.sleep(1)

        for p in t.read():
            print(f"Event at iteration {i}: {p}")
    t.stop()
