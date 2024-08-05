cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(46_permutations 46_permutations.cpp)
target_link_libraries(46_permutations ${GTEST_LIBRARIES} pthread)

add_executable(78_subsets 78_subsets.cpp)
target_link_libraries(78_subsets ${GTEST_LIBRARIES} pthread)
