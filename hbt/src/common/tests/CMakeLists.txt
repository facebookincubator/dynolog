add_executable(DefsTest DefsTest.cpp)
target_compile_options(DefsTest PUBLIC ${HBT_COMMON_COMPILE_OPTIONS})
target_include_directories(DefsTest PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(DefsTest PUBLIC gtest_main)
target_link_libraries(DefsTest PUBLIC Defs)

add_executable(SystemTest SystemTest.cpp)
target_compile_options(SystemTest PUBLIC ${HBT_COMMON_COMPILE_OPTIONS})
target_include_directories(SystemTest PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(SystemTest PUBLIC gtest_main)
target_link_libraries(SystemTest PUBLIC System)

# todo: include folly:subprocess library (or alternative) for SystemProcFsTest.cpp
