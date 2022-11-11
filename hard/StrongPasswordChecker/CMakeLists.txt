cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)

project(StrongPasswordChecker LANGUAGES CXX)

add_executable(StrongPasswordChecker
    sources/main.cxx    
    sources/StrongPasswordChecker.cxx
)

enable_testing()
add_subdirectory(tests)

