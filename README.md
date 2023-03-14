<p align="center">
  <img src="https://github.com/facebookincubator/dynolog/blob/main/docs/dyno_logo.svg" />
</p>

# Dynolog: a performance monitoring daemon for heterogeneous CPU-GPU systems

[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/facebookincubator/dynolog/blob/main/LICENSE)
[![DynologCI](https://github.com/facebookincubator/dynolog/actions/workflows/dynolog-ci.yml/badge.svg)](https://github.com/facebookincubator/dynolog/actions)
[![GitHub Release](https://img.shields.io/github/release/tterb/PlayMusic.svg?style=flat)](https://github.com/facebookincubator/dynolog/releases)
[![Issues](https://img.shields.io/github/issues-raw/tterb/PlayMusic.svg?maxAge=25000)](https://github.com/facebookincubator/dynolog/issues)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](https://makeapullrequest.com)

<!-- TOC is a TODO -->

## Introduction<!-- {#introduction} -->

Dynolog is a lightweight monitoring daemon for heterogeneous CPU-GPU systems. It supports both **always-on performance monitoring**, as well as **deep-dive profiling** modes. The latter can be activated by making a remote procedure call to the daemon.

Below are some of the key features, which we will explore in more detail later in this Readme.
* Dynolog integrates with the [PyTorch Profiler](https://pytorch.org/tutorials/recipes/recipes/profiler_recipe.html) and provides **[on-demand remote tracing features](https://pytorch.org/blog/performance-debugging-of-production-pytorch-models-at-meta/).** One can use a single command line tool (dyno CLI) to **simultaneously trace hundreds of GPUs** and examine the collected traces (available from PyTorch v1.13.0 onwards).
* It incorporates **[GPU performance monitoring](#gpu-monitoring)** for NVIDIA GPUs using [DCGM](https://docs.nvidia.com/datacenter/dcgm/latest/user-guide/index.html#).
* Dynolog manages counters for **micro-architecture specific performance events** related to CPU Cache, TLBs etc on **Intel** and **AMD** CPUs. Additionally, it instruments telemetry from the Linux kernel including **CPU, network and IO** resource usage.
* We are actively implementing new features, including support for **[Intel Processor Trace](https://engineering.fb.com/2021/04/27/developer-tools/reverse-debugging/)** as well as **memory latency and bandwidth monitoring**.

We focus on Linux platforms as it is leveraged heavily in cloud environments.

### Motivation<!-- {#motivation} -->

Large scale AI models use **distributed AI training** across multiple compute nodes. They also leverage hardware accelerators like **GPUs** to boost performance. One has to carefully optimize their AI applications to make the most of the underlying hardware while avoiding performance bottlenecks. This is where great performance monitoring and profiling tools become indispensable.

While there are existing solutions for monitoring ([1](https://www.intel.com/content/www/us/en/cloud-computing/telemetry.html), [2](https://cloud.google.com/learn/what-is-opentelemetry)) and profiling CPUs ([Intel’s VTune](https://www.intel.com/content/www/us/en/developer/tools/oneapi/vtune-profiler.html)) and GPUs ([NSight](https://developer.nvidia.com/nsight-compute)); it is challenging to assemble them together to get a holistic view of the system. For example, we need to understand whether an inefficiency on one resource like the communication fabric is slowing down the overall computation. Additionally, these solutions need to work in a production enviroment without causing performance degradation.

Dynolog leverages the underlying monitoring and profiling interfaces from the Linux kernel, CPU Performance Monitoring Units (PMUs) and GPUs. It also interacts with the pytorch profiler within the application to support on-demand profiling. In this way, it helps identify bottlenecks at various points in the system.


### Supported Metrics<!-- {#supported-metrics} -->

Dynolog’s always-on or continuous monitoring supports the following class of metrics:

1. System/kernel metrics.
2. CPU Performance Monitoring Unit (PMU) metrics using linux perf_event.
3. NVIDIA GPU metrics from DCGM if enabled.

Detailed list of covered metrics are provided in [docs/Metrics.md](docs/Metrics.md).

## Getting Started<!-- {#getting=started} -->

### Installation<!-- {#install-rpm-deb} -->

Dynolog can be installed using the package manager of your choice with either RPM for CentoOS or Debian for Ubuntu like distros. We do not support non-Linux platforms.
There are no required dependencies except for DCGM if you need to monitor GPUs, please see the section on [GPU monitoring](#gpu-monitoring) below.

Obtain the latest dynolog release or pick up one of the releases [here](https://github.com/facebookincubator/dynolog/releases)
```bash
# for CentoOS
wget https://github.com/facebookincubator/dynolog/releases/downdload/v0.2.1/dynolog-0.2.1-1.el8.x86_64.rpm
sudo rpm -i dynolog-0.2.1-1.el8.x86_64.rpm

# for Ubuntu or similar Debian based linux distros
wget https://github.com/facebookincubator/dynolog/releases/download/v0.2.1/dynolog_0.2.1-0-amd64.deb
sudo dpkg -i dynolog_0.2.1-0-amd64.deb
```

#### No sudo access?
Dynolog can run in userspace mode with most features functional. There are a few options to run dynolog userspace.
One way is to simply decompress the RPM or debian packages as shown below.
```bash
mkdir -p dynolog_pkg; cd dynolog_pkg
wget https://github.com/facebookincubator/dynolog/releases/download/v0.2.1/dynolog_0.2.1-0-amd64.deb
ar x dynolog_0.2.1-0-amd64.deb; tar xvf data.tar.xz
# binaries should now be available in ./usr/local/bin, you can add this directory to your $PATH.
```

Alternatively, you can [build dynolog from source](#building-dynolog). The binaries should be present in the `build/bin` directory.
The packages provides systemd support to run the server as a daemon. You can however still run dynolog server directly in a separate terminal.

### Running dynolog<!-- {#running-dynolog} -->

Start the Dynolog service using systemd -
```bash
sudo systemctl start dynolog
```
Note:
* The dynolog service picks up runtime flags from `/etc/dynolog.gflags` if the file is present.
* Output logs will be written to `/var/logs/dynolog.log` and logs are automatically rotated.

One can check the values of the metrics emitted in the output log file.
```bash
$> tail /var/log/dynolog.log
I20220721 23:42:34.141083 3632432 Logger.cpp:37] Logging : 12 values
I20220721 23:42:34.141104 3632432 Logger.cpp:38] time = 2022-07-21T23:42:34.141Z data = {"cpu_i":"71.342" …
```

The `dyno` command line tool communicates with the dynolog daemon on the local or remote system.
For example, we can verify if the daemon is running using the `status` subcommand.
```bash
$> dyno status
response length = 12
response = {"status":1}

$> dyno --hostname some_remote_host.com status
response length = 12
response = {"status":1}
```
Run `dyno --help` for help on other subcommands.

**Server Command Line options**
Lastly, the dynolog server provides various flags, we list the key ones here. Run `dynolog --help` for more info.
* `--port` (default = 1778) - the port used to setup a service for remote queries.
* `--reporting_interval_s` (default=60) - the reporting interval for metrics. Please see the [Logging](#logging) section for more details.
* `--enable_ipc_monitor` sets up inter-process communication endpoint. This can be used to talk to applications like pytorch trainers.

### Collecting pytorch/GPU traces<!-- {#collecting-pytorch-gpu-traces} -->

To enable pytorch profiling add the flag `--enable_ipc_monitor`. This enables the server to communicate with the pytorch process.
If you are running the server with systemd, do the following-
```bash
echo "--enable_ipc_monitor" | sudo tee -a /etc/dynolog.gflags
sudo systemctl restart dynolog
```

You also need to use a compatible version of **pytorch v1.13.0** and set the env variable `KINETO_USE_DAEMON=1` before running the pytorch program.
See [docs/pytorch_profiler.md](docs/pytorch_profiler.md) for details.

Traces can now be captured using the `gputrace` subcommand
```bash
dyno gputrace --pids <pid of process> --log_file <output file path>
```

Dynolog can also 1) capture traces on remote nodes, 2) co-ordinate tracing across a distributed training job (with slurm job scheduler). Please see the recipe in [docs/pytorch_profiler.md](docs/pytorch_profiler.md) for a detailed walkthrough of this feature.


### GPU Monitoring<!-- {#gpu-monitoring} -->

Dynolog leverages NVIDIA Datacenter GPU Manager [DCGM](https://developer.nvidia.com/dcgm) for NVIDIA GPUs today. DCGM supports GPU models from Kepler/Volta V100 onwards, Please see [this page](https://docs.nvidia.com/datacenter/dcgm/latest/user-guide/getting-started.html#supported-platforms) for details. Currently Dynolog dynamically supports both DCGM 2.x and DCGM 3.x based on the version of the shared library `libdcgm.so` installed on the system.

**Prerequisite:** Install DCGM on your system following the instructions [here](https://docs.nvidia.com/datacenter/dcgm/latest/user-guide/getting-started.html#ubuntu-lts-and-debian). After the installation please make sure to initialize the dcgm service using -

```bash
sudo systemctl --now enable nvidia-dcgm
```

To run dynolog with GPU monitoring you can add/tweak these flags

* `--enable_gpu_monitor` (default=false): enable GPU monitoring using DCGM.
* `--dcgm_lib_path` (default=/lib64/libdcgm.so): the path to DCGM shared library libdcgm.so. If the default path does not exist please adjust it.
* `--dcgm_fields` (default=”100,155,204,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012”): comma separated string of DCGM field ids to monitor, please see [Nvidia headers](https://fburl.com/p3zpudyj) for field definitions
* `--dcgm_report_interval_s` (default=10): the interval between each DCGM counter update in second. Please note when this value is too small DCGM may start multiplexing the counters and potentially affect counter accuracy.

```
echo "--enable_gpu_monitor" | sudo tee -a /etc/dynolog.gflags
sudo systemctl restart dynolog
```

### CPU Performance Events<!-- {#cpu-performance-events} -->
Dynolog also supports collection of CPU hardware performance events. We added CPU instructions and cycles as the first set of counters; referred to as `mips` (millions of instructions per second) and `mega_instructions_per_second`. See [docs/Metrics.md](docs/Metrics.md) for more details.

The following flags are relevant to hardware PMU performance monitoring:
* `--enable_perf_monitor` (default=false): enable hardware PMU performance monitoring.
* `--perf_monitor_reporting_interval_s` (default=60): set the reporting interval of performance metrics in seconds.

Sample logs emitted to the log file:
```
I20221208 15:28:34.730270 3345417 Logger.cpp:55] Logging : 2 values
I20221208 15:28:34.730316 3345417 Logger.cpp:56] time = 1969-12-31T16:00:00.000Z data = {"mega_cycles_per_second":"735.696","mips":"691.497"}
I20221208 15:29:34.731652 3345417 Logger.cpp:55] Logging : 2 values
I20221208 15:29:34.731690 3345417 Logger.cpp:56] time = 1969-12-31T16:00:00.000Z data = {"mega_cycles_per_second":"514.156","mips":"479.397"}

```
## Building from source<!-- {#building-dynolog} -->

Dynolog consists of two binaries - 1) dynolog server and 2) dyno command line tool.
To build from source please check out the project and initialize submodules.

```bash
git clone https://github.com/facebookincubator/dynolog.git
git submodule update --init --recursive
```

### Requirements<!-- {#requirements} -->

This project mainly depends on C++17 and Rust compiler tool chains. Other dependencies include cmake and the ninja build system.
We have tested dynolog works with the following versions of C++ and Rust toolchains

<table>
  <tr>
   <td>Language
   </td>
   <td>Toolchain
   </td>
  </tr>
  <tr>
   <td>C++
   </td>
   <td>gcc 8.5.0+
   </td>
  </tr>
  <tr>
   <td>Rust
   </td>
   <td>Rust 1.58.1 (1.56+ required for clap dependency)
   </td>
  </tr>
</table>


Based on your system you could use one of the following instructions:

**RHEL/CentOS**

Install cmake, ninja, and [cargo](https://docs.rs/cargo/latest/cargo/) (for Rust).
```bash
sudo dnf install cmake ninja cargo
```

Alternatively, you can install rust using the script provided [here](https://www.rust-lang.org/tools/install).
```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

**Ubuntu/Debian**

Install cmake and ninja
```bash
sudo apt-get install -y cmake ninja-build
```

Install rust using this script provided [here](https://www.rust-lang.org/tools/install).

**Conda**

In case of no root access you can install these dependencies in a conda environment as well.
A few features may not work without root access (we will document more details soon).
```bash
conda install cmake ninja
conda install -c conda-forge "rust=1.64.0"
```

**GPU Monitoring**

For NVIDIA GPUs (currently the only ones supported) you can install DCGM as described in [GPU monitoring](#gpu-monitoring) section.

### Building<!-- {#building} -->

Please use the build script, this should generate files in ./build relative to your project root. The script will print the path to the server and client.
```bash
./scripts/build.sh
```
Note that the build system for Rust will need an internet connection for the first time.

### Building packages
The preferred method to run dynolog is by deploying a package - either RPM or debian. Please see [scripts/README.md](scripts/README.md) for instructions on how to build dynolog packages.

## Logging<!-- {#logging} -->

By default dynolog will save monitoring metrics to the standard output -

```
I20220721 23:42:34.141104 3632432 Logger.cpp:38] time = 2022-07-21T23:42:34.141Z data = {"cpu_i":"71.342" ...
```

Dynolog includes an abstract Logger class that can be specialized for different logging destinations. Currently, Dynolog support logging to Meta ODS datastore, and Meta Scuba data system, instructions can be found in [docs/logging_to_ods.md](docs/logging_to_ods.md) and [docs/logging_to_scuba.md](docs/logging_to_scuba.md). Dynolog team is happy to support new loggers.

## Releases<!-- {#release} -->

Please see our [releases](https://github.com/facebookincubator/dynolog/releases) page for latest releases and features/fixes included in them.

In the next and near term release we plan to add
* Disk usage metrics like storage size and IO operations per second.
* Memory latency and bandwidth monitoring per socket for Intel and AMD CPUs.

At some future point we would also like to add -
* Capability to collect CPU traces using Intel Processor Trace.
* [Open telemetry](https://cloud.google.com/learn/what-is-opentelemetry) support for logging.

## Contact Us

Dynolog is actively maintained by Meta engineers: [Brian Coutinho](https://github.com/briancoutinho/), [Zachary Jones](https://github.com/bigzachattack/), [Hao Wang](https://github.com/haowangludx/), [William Sumendap](https://github.com/williamsumendap/), [Jakob Johnson](https://github.com/jj10306/),[Alston Tang](https://github.com/Alston-Tang/), [Walter Erquinigo](https://github.com/a20012251/),[David Carrillo Cisneros](https://github.com/ccdavid/). We would also like to thank various contributors to the dynolog project internally- Sam Crossley, Jayesh Lahori, Matt Skach, Darshan Sanghani, Lucas Molander, Parth Malani, Jason Taylor - this is by no means an exhaustive list. Special thanks to Herman Chin, Victor Henriquez, Anupam Bhatnagar, Caleb Ho, Aaron Shi, Jay Chae, Song Liu, Susan Zhang, Geeta Chauhan and Gisle Dankel for supporting this initiative

## Join the dynolog community
Please file bugs or feature requests as [issues](https://github.com/facebookincubator/dynolog/issues) on github.
See the [CONTRIBUTING](CONTRIBUTING.md) file for how to help out.

## License
Dynolog is licensed under the [MIT License](LICENSE).
