# Copyright (c) Meta Platforms, Inc. and affiliates.

add_library(dynolog_rpc_lib STATIC
    SimpleJsonServer.cpp SimpleJsonServer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../ServiceHandler.h
)
target_include_directories(dynolog_rpc_lib
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(dynolog_rpc_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)
target_link_libraries(dynolog_rpc_lib PRIVATE dynolog_lib)
target_link_libraries(dynolog_rpc_lib PUBLIC gflags::gflags)
target_link_libraries(dynolog_rpc_lib PUBLIC glog::glog)
target_link_libraries(dynolog_rpc_lib PUBLIC nlohmann_json::nlohmann_json)
target_link_libraries(dynolog_rpc_lib PUBLIC fmt::fmt)
