# Copyright (c) Meta Platforms, Inc. and affiliates.

add_library (dynolog_ipcfabric_lib INTERFACE)
target_compile_options(dynolog_ipcfabric_lib INTERFACE "-DENABLE_IPC_FABRIC")
