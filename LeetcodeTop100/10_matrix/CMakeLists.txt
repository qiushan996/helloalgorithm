cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(73_set_matrix_zeroes 73_set_matrix_zeroes.cpp)
target_link_libraries(73_set_matrix_zeroes ${GTEST_LIBRARIES} pthread)
