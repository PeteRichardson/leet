cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable( StrongPasswordCheckerTests
    StrongPasswordCheckerTests.cxx
    ../sources/StrongPasswordChecker.cxx 
)

target_link_libraries( StrongPasswordCheckerTests
    gtest_main
)

include(GoogleTest)
gtest_discover_tests( StrongPasswordCheckerTests )