cmake_minimum_required(VERSION 3.10)
project(Leetcode_01_hash)

# C++ standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加测试文件
add_executable(array  array.cpp)
add_executable(test_list01  linked_list.cpp)  # 不能有逗号
add_executable(test_vector  list_vector.cpp)