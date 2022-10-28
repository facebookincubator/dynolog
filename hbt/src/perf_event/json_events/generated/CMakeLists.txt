# Copyright (c) Meta Platforms, Inc. and affiliates.

add_library(CpuArch CpuArch.h)
set_target_properties(CpuArch PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(intel)
