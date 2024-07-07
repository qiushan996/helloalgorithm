cmake_minimum_required(VERSION 3.10)
project(cpputils)

# C++ standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 添加测试文件
add_executable(vectorcmp  vectorcmp.cpp)

# 链接到googletest库
target_link_libraries(vectorcmp ${GTEST_LIBRARIES} pthread)
