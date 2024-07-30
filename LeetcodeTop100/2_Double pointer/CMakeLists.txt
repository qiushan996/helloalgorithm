cmake_minimum_required(VERSION 3.10)
project(Leetcode_02_DoublePointer)

set(CMAKE_CXX_STANDARD_REQUIRED 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(move_zeros 283_movezeros.cpp)
add_executable(3sums 15_3sum.cpp)


target_link_libraries(move_zeros ${GTEST_LIBRARIES} pthread)
target_link_libraries(3sums ${GTEST_LIBRARIES} pthread)