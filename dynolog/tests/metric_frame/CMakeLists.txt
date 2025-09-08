# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

dynolog_add_test(TextTableTest TextTableTest.cpp)
target_link_libraries(TextTableTest PRIVATE text_table)

dynolog_add_test(MetricSeriesTest MetricSeriesTest.cpp)
target_link_libraries(MetricSeriesTest PRIVATE metric_series)

dynolog_add_test(MetricValuesTest MetricValuesTest.cpp)
target_link_libraries(MetricValuesTest PRIVATE metric_values)

dynolog_add_test(MetricFrameTsUnitTest MetricFrameTsUnitTest.cpp)
target_link_libraries(MetricFrameTsUnitTest PRIVATE metric_frame_ts_unit)

dynolog_add_test(MetricFrameTest MetricFrameTest.cpp)
target_link_libraries(MetricFrameTest PRIVATE metric_frame)
