# (c) Meta Platforms, Inc. and affiliates.
cmake_minimum_required(VERSION 3.20)

# our build script will first create a src/ dir where all source code will exist
file (GLOB dynomin_src "*.h" "*.cpp")

# Remove main from library, only needed for exec.
list(REMOVE_ITEM dynomin_src "dynolog/src/Main.cc")
add_library(dynolog_lib ${dynomin_src})
target_compile_options(dynolog_lib PUBLIC "-DUSE_GRAPH_ENDPOINT")

add_subdirectory(rpc)

add_subdirectory(ipcfabric)
target_link_libraries(dynolog_lib PUBLIC dynolog_ipcfabric_lib)

# depends on ipcfabric
add_subdirectory(tracing)
target_link_libraries(dynolog_lib PUBLIC dynolog_ipcmonitor_lib)

add_subdirectory(gpumon)
target_link_libraries(dynolog_lib PUBLIC dynolog_dcgm_lib)

add_executable(dynomin Main.cpp)
target_link_libraries(dynomin PRIVATE dynolog_lib dynolog_rpc_lib)
