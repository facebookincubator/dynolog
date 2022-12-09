#!/usr/bin/env python3
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

import argparse
import os
import shutil
import subprocess
import sys
import time

DYNO_BUILD_PATH = "./build/release/dyno"
SQUEUE_BIN = "/usr/local/bin/squeue"
SCONTROL_BIN = "/usr/local/bin/scontrol"


def dyno_bin():
    # first seach in PATH
    binpath = shutil.which("dyno")
    if binpath is not None:
        return binpath

    # try looking up build based binary
    if os.path.isfile(DYNO_BUILD_PATH):
        return DYNO_BUILD_PATH

    return None


def get_hosts(job):
    squeue_out = subprocess.check_output(
        [SQUEUE_BIN, "-j", job], universal_newlines=True
    )

    if squeue_out == "":
        print("Failed to run squeue command")
        return

    last_line = squeue_out.splitlines()[-1]
    print(last_line)
    # 64533952  learnlab     bash ansongni  R    2:44:49      1 learnfair2270
    host_str = last_line.split()[7]
    print(f"Found hosts string = {host_str}")

    # we may need to decode the host string
    # learnfair[1758,1765,1767-1768,1809-1812]
    hosts = []

    if "[" not in host_str:
        hosts = [host_str]
    else:
        scontrol_out = subprocess.check_output(
            [SCONTROL_BIN, "show", "hostnames", host_str], universal_newlines=True
        )
        hosts = scontrol_out.splitlines()

    print(f"Hosts = {hosts}")
    return hosts


def main():

    parser = argparse.ArgumentParser(
        usage="%(prog)s [options] [slurm_job_id]...",
        description="Triggers GPU tracing simultaneously on a distributed job.",
    )
    parser.add_argument(
        "job_id",
        help="The job_id to trigger trace for. "
        "Currently supports SLURM job scheduler. The script will "
        "query slurm to get list of hosts automatically.",
    )
    parser.add_argument(
        "--hosts",
        type=str,
        nargs="+",
        help="Optionally provide a list of hosts to send requests to.",
    )
    parser.add_argument(
        "-o",
        "--output-dir",
        type=str,
        default="/tmp/",
        help="Output directory to strore traces to. "
        "Files are named as <output-dir>/libkineto_<hostname>_<pid>.json.gz",
    )
    parser.add_argument(
        "-d",
        "--duration-ms",
        type=int,
        default=500,
        help="Duration in ms to collect trace for. Please also see --iterations"
        " as an alternate option.",
    )
    parser.add_argument(
        "--start-time-delay",
        type=int,
        default=10,
        help="Delay to start the duration based profile."
        "This helps to synchronize start iteration among traces",
    )
    parser.add_argument(
        "-i",
        "--iterations",
        type=int,
        default=0,
        help="Number of iterations to capture the trace for. Setting the value "
        "> 0 will override the duration option.",
    )
    parser.add_argument(
        "--iteration-roundup",
        type=int,
        default=1000,
        help="Starts an iteration based trace at a multiple of this value. "
        "This helps to synchronize start iteration among traces",
    )
    args = parser.parse_args()
    job = args.job_id
    outdir = args.output_dir

    dyno_cmdline = dyno_bin()
    if dyno_cmdline is None:
        print("Error: could not find dyno cmd line in path or at", DYNO_BUILD_PATH)
        print("Please run this script from dynolog project root or install dyno.")
        sys.exit(0)

    if "_" in job:
        print(
            "Currently dynolog does not support job names with '_' for "
            "trace targeting, only numeric job ids are supported."
        )
        sys.exit(1)

    if not os.path.isdir(outdir):
        os.mkdir(outdir)
    outdir = os.path.abspath(outdir)

    print(f"Tracing job: {job} to output dir: {outdir}")

    trace_options = ""
    if args.iterations > 0:
        trace_options = f"--iterations {args.iterations} --profile-start-iteration-roundup {args.iteration_roundup}"
    else:
        print(
            f" traces will start in {args.start_time_delay} seconds and "
            "may take 5-10 seconds to appear in the directory"
        )
        future_timestamp = int((time.time() + args.start_time_delay) * 1000)
        trace_options = (
            f"--duration-ms {args.duration_ms} --profile-start-time {future_timestamp}"
        )

    hosts = get_hosts(job) if args.hosts is None else args.hosts
    for host in hosts:
        cmd = (
            f"{dyno_cmdline} --hostname {host} gputrace "
            f"--job-id {job} --log-file {outdir}/libkineto_trace_{host}.json "
            f"{trace_options}"
        )
        print(f"Running cmd: {cmd}")
        os.system(cmd)


if __name__ == "__main__":
    main()
