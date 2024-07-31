cmake_minimum_required(VERSION 3.10)
project(leetodeTop100_Array)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(maxsubarray   53_MaxSubArray.cpp)


target_link_libraries(maxsubarray  ${GTEST_LIBRARIES}  pthread)