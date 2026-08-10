# dynolog

Dynolog is a lightweight performance monitoring daemon for heterogeneous
CPU-GPU systems, supporting both always-on monitoring and on-demand deep-dive
profiling (for example, integration with the PyTorch Profiler and GPU/CPU
telemetry).

This folder holds the daemon source (`src/`), the `dyno` CLI (`cli/`), tests
(`tests/`, `testing/`), and the open-source distribution files (`public_root/`,
mirrored to https://github.com/facebookincubator/dynolog).
