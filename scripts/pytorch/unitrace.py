#!/usr/bin/env python3
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

import os
import subprocess
import sys
import shutil

DYNO_BUILD_PATH = "./build/release/dyno"


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
        ["/usr/local/bin/squeue", "-j", job], text=True)

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

    if '[' not in host_str:
        hosts = [host_str]
    else:
        scontrol_out = subprocess.check_output(
            ["/usr/local/bin/scontrol", "show", "hostnames", host_str], 
            text=True)
        hosts = scontrol_out.splitlines()
    
    print(f"Hosts = {hosts}")
    return hosts

def main():

    if len(sys.argv) <= 2:
        print(f"Usage: {sys.argv[0]} [slurm_job_id] [output_dir]")
        sys.exit(0)

    dyno_cmdline = dyno_bin()
    if dyno_cmdline is None:
        print("Error: could not find dyno cmd line in path or at", DYNO_BUILD_PATH)
        print("Please run this script from dynolog project root or install dyno.")
        sys.exit(0)

    job = sys.argv[1]
    outdir = sys.argv[2]

    if "_" in job:
        print(f"Currently dynolog does not support job names with '_' for "
              "trace targeting, only numeric job ids are supported");
        sys.exit(1)

    if not os.path.isdir(outdir):
        os.mkdir(outdir)
    outdir = os.path.abspath(outdir)

    print(f"Tracing job: {job} to output dir: {outdir}")

    for host in get_hosts(job):
        cmd = f"{dyno_cmdline} --hostname {host} gputrace "\
              f"--job-id {job} --log-file {outdir}/libkineto_trace_{host}.json"
        print(f"Running cmd: {cmd}")
        os.system(cmd)

if __name__ == "__main__":
    main()
