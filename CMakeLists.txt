cmake_minimum_required(VERSION 3.5.0)
project(Bitset VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(Bitset 
    main.cpp
    tests/bitset_test1.cpp
    tests/bitset_test2.cpp
    tests/bitset_test3.cpp
    tests/bitset_test4.cpp
    tests/bitset_test5.cpp
    tests/bitset_test6.cpp)

add_subdirectory(googletest)
include_directories(googletest/googletest/include)
target_link_libraries(Bitset gtest gtest_main)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR})
set(DEST_DIR "${CMAKE_BINARY_DIR}")
