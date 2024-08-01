cmake_minimum_required(VERSION 3.10)
project(leetodeTop100_BinarySearch)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Searchinsertpos   35_SearchInsertPos.cpp)


target_link_libraries(Searchinsertpos  ${GTEST_LIBRARIES}  pthread)
