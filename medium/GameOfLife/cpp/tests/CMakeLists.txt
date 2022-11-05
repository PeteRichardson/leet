cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable( board_tests
    board_tests.cpp
    ../board.cpp
)

target_link_libraries( board_tests
    gtest_main
)

include(GoogleTest)
gtest_discover_tests( 
    board_tests 
)