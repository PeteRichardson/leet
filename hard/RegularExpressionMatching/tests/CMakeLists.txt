cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable( regexmatch_tests
    regexmatch_tests.cpp
    ../regexmatch.cpp
)

target_link_libraries( regexmatch_tests
    gtest_main
)

include(GoogleTest)
gtest_discover_tests( regexmatch_tests )