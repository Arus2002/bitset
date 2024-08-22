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

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(Bitset ${GTEST_LIBRARIES} pthread)


set(SOURCE_DIR ${CMAKE_SOURCE_DIR})
set(DEST_DIR "${CMAKE_BINARY_DIR}")
