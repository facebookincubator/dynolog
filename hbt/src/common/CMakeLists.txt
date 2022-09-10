set(HBT_COMMON_COMPILE_OPTIONS "-Wconversion")

add_library(Defs Defs.h)
set_target_properties(Defs PROPERTIES LINKER_LANGUAGE CXX)
target_compile_options(Defs PUBLIC ${HBT_COMMON_COMPILE_OPTIONS})

add_library(System System.h System.cpp)
target_include_directories(System PUBLIC ${PROJECT_SOURCE_DIR}/third_party/pfs/include)
target_include_directories(System PUBLIC ${PROJECT_SOURCE_DIR})
target_compile_options(System PUBLIC ${HBT_COMMON_COMPILE_OPTIONS})
target_link_libraries(System PUBLIC fmt::fmt)
target_link_libraries(System PUBLIC ${CMAKE_BINARY_DIR}/lib/libpfs.a)
target_link_libraries(System PUBLIC range-v3::range-v3)
target_link_libraries(System PUBLIC Defs)
#todo: build CpuArch in hbt/perf_event/json_events/generated

add_library(Defaults Defaults.h)
set_target_properties(Defaults PROPERTIES LINKER_LANGUAGE CXX)
target_compile_options(Defaults PUBLIC ${HBT_COMMON_COMPILE_OPTIONS})
