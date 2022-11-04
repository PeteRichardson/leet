cmake_minimum_required(VERSION 3.18)

project(RomanToInteger)

add_executable(RomanToInteger
    main.cpp
    RomanToInteger.cpp
)

set_property(TARGET RomanToInteger PROPERTY CXX_STANDARD 17)