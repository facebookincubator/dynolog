cmake_minimum_required(VERSION 3.20)

project(Dynolog VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE True)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

file (GLOB dynomin_src "src/*.h" "src/*.cpp")
add_executable (dynomin src/Main.cpp ${dynomin_src})

# Third party deps
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
set(BUILD_SAMPLES OFF CACHE BOOL "")
set(BUILD_TEST OFF CACHE BOOL "")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "")

add_subdirectory(third_party/gflags)
target_link_libraries(dynomin PRIVATE gflags::gflags)

add_subdirectory(third_party/glog)
target_link_libraries(dynomin PRIVATE glog::glog)

# https://github.com/nlohmann/json#cmake
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(third_party/json)
target_link_libraries(dynomin PRIVATE nlohmann_json::nlohmann_json)

add_subdirectory(third_party/pfs)
target_include_directories(dynomin PRIVATE third_party/pfs/include)
target_link_libraries(dynomin PRIVATE pfs)

add_subdirectory(third_party/fmt)
target_link_libraries(dynomin PRIVATE fmt::fmt)
