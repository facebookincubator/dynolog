# Copyright (c) Meta Platforms, Inc. and affiliates.

add_library(IptCapChecker IptCapChecker.cpp)
target_link_libraries(IptCapChecker PUBLIC IptEventBuilder)
target_link_libraries(IptCapChecker PUBLIC BuiltinMetrics)
