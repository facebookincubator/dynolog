# On-demand Profiling For PyTorch application

## Introduction
Debugging performance on distributed AI applications can be challenging. Currently, developers can examine their PyTorch training applications programmatically using the [PyTorch Profiler API](https://pytorch.org/docs/stable/profiler.html).
However, this needs modification to the python code and likely a relaunch of their jobs.

Dynolog enables profiling distributed AI applications on-demand i.e without any code changes. Using the Dynolog service the user can request a PyTorch profile collection. On receiving a profiling request Dynolog uses inter-process communication (IPC) to configure the PyTorch profiler on the fly. This is illustrated in the following diagram.
![Profiler activation flow with Dynolog and PyTorch](./profiler_flow.png)

The following instructions walk through:
1. Configuring the PyTorch application environment to enable on-demand trace collection.
1. Collecting GPU traces on-demand locally or remotely.
1. Profiling a distributed training job.

## PyTorch Setup
> Note that these instructions continue to evolve as we add more features to PyTorch profiler and Dynolog.

> There are several known issues for PyTorch > 2.3.0. Presently, these have been fixed in the nighly branch that you can download from [here](https://pytorch.org/get-started/locally/). We will update this document once pytorch 2.7.0 is out. See the Known Issues Section.

Please use the latest [PyTorch 2.0 release](https://pytorch.org/get-started/pytorch-2.0/). For more information on obtaining PyTorch nightly see [here](https://pytorch.org/get-started/locally/).
Older versions of PyTorch (< 2.0) are currently not supported.

## On-demand tracing locally
On a local machine you can run Dynolog and use the command line tool to trace your application.

### Spin up Dynolog
Dynolog can communicate with PyTorch when `--enable_ipc_monitor` option is passed.
If you are running Dynolog using systemd (RPM or debian) you can add this flags to the '/etc/dynolog.gflags' by running:
```bash
echo "--enable_ipc_monitor" | sudo tee -a /etc/dynolog.gflags
sudo systemctl restart dynolog
```
Alternatively, you can also run dynolog server in user mode with -
```bash
./build/bin/dynolog --enable_ipc_monitor
```

### Running the PyTorch program
For PyTorch to register with Dynolog we need to set the following environment variables:
```bash
export KINETO_USE_DAEMON=1
export KINETO_DAEMON_INIT_DELAY_S=3
```
The initialization delay is recommended to avoid dynamic library loading race condition that [manifests as a segfault](https://github.com/pytorch/pytorch/issues/131020).
The delay is no longer needed in later versions of PyTorch but is recommended in case users are leveraging an older version.

Now you can run the PyTorch program. We included a simple example PyTorch script for you to test out this flow.
```bash
python3 scripts/pytorch/linear_model_example.py
```
Alternatively, set the environment variables on the command line -
```bash
KINETO_USE_DAEMON=1 python3 scripts/pytorch/linear_model_example.py
```

In the output of the script you should see a message as follows, this means the PyTorch attempted to register with Dynolog.
```
INFO:2022-10-22 00:59:13 151209:151209 init.cpp:98] Registering daemon config loader
```

### Triggering an on-demand trace
You can now trigger trace collection using the dyno command line tool. Dynolog will try to match PyTorch processes running on the machine. We can also filter processes by `pid` or `job id`. On successful matches the tool prints the paths where the trace files will be saved to stdout:
```bash
# building from source? use ./build/bin/dyno
$> dyno gputrace --log-file /tmp/libkineto_trace.json

Matched 1 processes
Trace output files will be written to:
    /tmp/libkineto_trace_151419.json
```
The collected trace file can be visualized using [Chrome Trace Viewer](chrome://tracing) or [Perfetto](https://perfetto.dev/).
Also, the generated trace file names include the process id as a suffix. This allows you to profile multiple processes on the node simultaneously.

### Duration based vs iteration based traces
By default the traces are captured for a specific time duration. One can configure this trace duration in ms using the `--duration-ms` flag of the dyno command line tool.

A common requirement is to capture 3-5 trainging iterations of your AI model. This is now possible as PyTorch includes a profiling hook in the optimizer. Generally speaking, training involves at least one optimizer operation in each iteration.

We can make a request to capture iteration based traces using the `--iterations` flag.
```bash
$> dyno gputrace --log-file /tmp/libkineto_trace.json --iterations 5
```
For a working example of the above you can run the `scripts/pytorch/xor.py` that contains a training loop with an optimizer. If PyTorch profiler is unable to capture an iteration based trace it **defaults back to a duration based trace**.

### On-demand tracing on a remote node
To trigger a PyTorch trace on a remote node you can use the `--host-name` flag. Note that Dynolog should be running on that remote node.
```bash
dyno --host-name remote_host gputrace --log-file /path/to/log/file/libkineto_trace.json
```
**Tip**: If your cluster supports NFS you can set the log file path to a directory backed by NFS.

Also, it is possible that a single node can run multiple cluster jobs. PyTorch profiler can recognize job IDs
of processes launched using the SLURM job scheduler. One can pass a job ID to filter processes as follows.
```bash
dyno --host-name remote_host gputrace --job-id 4242 --log-file /path/to/log/file/libkineto_trace.json
```

## Known Issues

Recent versions of PyTorch have known issues wth the initialization and interaction with Kineto. Fixing them would require upgrading to the latest nighly branch to get working correctly.

### Initializetion failures: pytorch >= 2.3.0

With the `KINETO_DAEMON_INIT_DELAY_S`  environment variable set you may see the folloing error:
```
ERROR: External init callback must run in same thread as registerClient (1258501696 != 107225088)
```

The initialization delay is implemented by using a different thread to init the profiler state. This was clashing with an existing [check](https://github.com/pytorch/kineto/blob/d9753139d181b9ff42872465aac0e5d3018be415/libkineto/src/libkineto_api.cpp#L23-L31)

Long story short you would need to use PyTorch nightly or 2.7.0 once it is out, to fix this.
There are two fixes that help with addressing the problem.
A detailed discussion can be found at [issue/1302](https://github.com/pytorch/kineto/issues/1032)

#### Fix 1: Avoid delayed init workaround
We currently, do not need the delay anymore as the init function is now called when we "import torch" [pytorch/pytorch#131448](https://github.com/pytorch/pytorch/pull/131448)

With the above fix we still see a “Failed to match processes error” on CUDA/NVIDIA GPUs.

Our init flow for CUDA GPUs relies on CUPTI callback .
1. However, with new `global_init_flow` there appears to be a race condition to register the callbacks and setting up CUDA contexts. For some reason callbacks are not being called.
2. Secondly, we are no longer need this deferred init as we have a global init flow now.
3. We can also avoid loading CUPTI library right at the start.

#### Fix 2 : PyTorch nightly, and future 2.7.0
See [kineto/kineto#1035](https://github.com/pytorch/kineto/pull/1035) and [pytorch/pytorch#147195](https://github.com/pytorch/pytorch/pull/147195)
This fix Cleans up the initialization process in Kineto
* The current method to init Kineto for CUDA builds is to add a callback on CUDA context. But this leads to CUPTI being enabled right from the start.
* For the case where profiling daemon is enabled (dynolog), we always initialize the profiler and config loader, for both CPU and CUDA builds. This should be safe to do as kineto init now happens when torch is imported.

The second fix is available on **PyTorch nighly versions past Feb 17th, 2025**.

## Coordinated Tracing on a distributed application
Lastly, this section talks about how to profile a distributed training job running on multiple nodes simultaneously.
This assumes that Dynolog is present on remote nodes in the cluster - either 1) it is installed and running on all remote nodes, 2) or you can launch an instance of Dynolog with your job (see [launching jobs with Dynolog](#launching-jobs-with-dynolog) below).

### Profiling a distributed job (unitrace.py)
Assuming Dynolog is running on remote nodes, we can use a utility script `unitrace.py` to profile the entire training job.
The `unitrace.py` script will accept a SLURM **job id** as an input and:
1. Lookup the nodes running the job.
2. Send `dyno gputrace` requests to all nodes as required.

> Currently, this script only works with SLURM job scheduler. Further, job IDs with an underscore or `_` in the name are not supported. This can be easily extended to more schedulers, please file an issue or reach out to us for support on this.

The usage of the `unitrace.py` script is straightforward.
```
Usage: ./scripts/pytorch/unitrace.py [slurm_job_id] [output_dir]
```
- where output_dir will be the top level directory for saving traces. `unitrace.py` will save a new trace file for each job using the naming convention `libkineto_trace_<slurm_job_id>_<pid_of_process>.json`

For example, the following command traces the job 65788044
```bash
./scripts/pytorch/unitrace.py 65788044 /tmp/trace_65788044/
```

This produces the output shown below:
```
Hosts = ['machine1773', 'machine1775', 'machine1776', 'machine1798', 'machine1800', 'machine1809', 'machine1811', 'machine1812']
Running cmd: ./build/release/dyno --hostname machine1773 gputrace --job-id 65788044 --log-file /tmp/trace_65788044/libkineto_trace_machine1773.json
...
```

### Launching a job with Dynolog<!-- {#launching-jobs-with-dynolog} -->
In case Dynolog is not deployed on your cloud setup/cluster you can launch the Dynolog binary
with your job. The script `run_with_dyno_wrapper.sh` can be used for this purpose.

This script will spin up a Dynolog process first and then run your job's command. It will also
setup the required environment variables. An example is shown below:
```bash
# srun ./scripts/slurm/run_with_dyno_wrapper.sh <desired launch cmd>
# example
srun ./scripts/slurm/run_with_dyno_wrapper.sh python3 ./scripts/pytorch/linear_model_example.py
```

## Questions?

For support on this feature please feel free to raise a github [issue]((https://github.com/facebookincubator/dynolog/issues) or contact us directly, see the[README](../README.md) page for details. Thanks for reading!
