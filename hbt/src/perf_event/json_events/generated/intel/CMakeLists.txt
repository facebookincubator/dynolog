file (GLOB json_events_src "*.h" "*.cpp")
add_library(JsonEvents ${json_events_src})
target_link_libraries(JsonEvents PUBLIC PmuDevices)
target_link_libraries(JsonEvents PUBLIC PmuEvent)
