add_library(extra_types STATIC ExtraTypes.h ExtraTypes.cpp)
add_library(metric_series STATIC MetricSeries.h)
set_target_properties(metric_series PROPERTIES LINKER_LANGUAGE CXX)
add_library(metric_frame_ts_unit STATIC
    MetricFrameTsUnit.h MetricFrameTsUnit.cpp MetricFrameTsUnitInterface.h)
add_library(metric_frame STATIC
    MetricFrame.h MetricFrame.cpp MetricFrameBase.h MetricFrameBase.cpp)
target_link_libraries(metric_frame
    metric_series metric_frame_ts_unit extra_types)
