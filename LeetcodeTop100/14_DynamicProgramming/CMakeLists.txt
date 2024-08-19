cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(70_climbingStairs 70_climbingStairs.cpp)
target_link_libraries(70_climbingStairs ${GTEST_LIBRARIES} pthread)

add_executable(118_pascaltriangle 118_pascaltriangle.cpp)
target_link_libraries(118_pascaltriangle ${GTEST_LIBRARIES} pthread)
