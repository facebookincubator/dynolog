# Follow recipe here: https://cliutils.gitlab.io/modern-cmake/chapters/testing/googletest.html

# Add this to top level CMake
# add_subdirectory("${PROJECT_SOURCE_DIR}/third_party/googletest" "third_party/googletest")

include(GoogleTest)
macro(dynolog_add_test_base TESTNAME)
    # create an executable in which the tests will be stored
    add_executable(${TESTNAME} ${ARGN})
    # link the Google test infrastructure, mocking library, and a default main function.
    target_link_libraries(${TESTNAME} PRIVATE gtest gmock gtest_main)
    # gtest_discover_tests replaces gtest_add_tests,
    # see https://cmake.org/cmake/help/v3.10/module/GoogleTest.html for more options to pass to it
    gtest_discover_tests(${TESTNAME}
        # set a working directory so your project root so that you can find test data via paths relative to the project root
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES ENVIRONMENT "TESTROOT=${PROJECT_SOURCE_DIR}/tests/root/"
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

macro(dynolog_add_test TESTNAME)
    dynolog_add_test_base(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE dynolog_lib)
    target_include_directories(${TESTNAME} PRIVATE "${PROJECT_SOURCE_DIR}/src")
endmacro()
