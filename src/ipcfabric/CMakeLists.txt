add_library (dynolog_ipcfabric_lib INTERFACE)
target_include_directories(dynolog_ipcfabric_lib
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
# Unit testing
if(BUILD_TESTS)
  enable_testing()
  include(GoogleTest)
  add_subdirectory(tests)
endif()
