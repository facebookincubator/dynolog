#!/bin/bash
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

# Please run this script from the root level of the project.
#  ./scripts/slurm/run_with_dyno_wrapper.sh <program and cmd line args>
#
# This script can be used to wrap a command launched on slurm.
# It will spin up dynolog daemon in parallel before launching the full cmd.

set -eux -o pipefail

BASEPATH=/private/home/${USER}/
PROJECTROOT=${PROJECTROOT:-"."}
DYNOBINPATH=${DYNOBINPATH:-"${PROJECTROOT}/build/dynolog/src/"}

echo "Starting dynolog"
"${DYNOBINPATH}/dynolog" --enable_ipc_monitor &

dyno_pid=$!
echo " dyno pid = ${dyno_pid}"
sleep 2s;

echo "Running command"
export KINETO_CONFIG=${BASEPATH}/libkineto.conf
export KINETO_USE_DAEMON=1
"$@"

echo "Cleaning up dynolog"
kill -9 $dyno_pid
