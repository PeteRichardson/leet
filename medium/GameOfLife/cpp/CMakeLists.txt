cmake_minimum_required(VERSION 3.18)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG        release-1.11.0
)
            
FetchContent_MakeAvailable(googletest)

project(GameOfLife)

add_executable(GameOfLife
    main.cpp
    board.cpp
)

set_property(TARGET GameOfLife PROPERTY CXX_STANDARD 17)

enable_testing()
add_subdirectory(tests)

