# (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.
dynolog_add_test(MetricSeriesTest MetricSeriesTest.cpp)
target_link_libraries(MetricSeriesTest PRIVATE metric_series)

dynolog_add_test(MetricFrameTsUnitTest MetricFrameTsUnitTest.cpp)
target_link_libraries(MetricFrameTsUnitTest PRIVATE metric_frame_ts_unit)

dynolog_add_test(MetricFrameTest MetricFrameTest.cpp)
target_link_libraries(MetricFrameTest PRIVATE metric_frame)
