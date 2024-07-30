cmake_minimum_required(VERSION 3.10)
project(Leetcode_01_hash)

# C++ standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 添加测试文件
add_executable(twosum  1_twosum.cpp)
add_executable(groupanagrams  49_Groupanagrams.cpp)
add_executable(longestseq  128_Longest_Consecutive_Sequence.cpp)

# 链接到googletest库
target_link_libraries(twosum ${GTEST_LIBRARIES} pthread)
target_link_libraries(groupanagrams  ${GTEST_LIBRARIES}  ${GTEST_MAIN_LIBRARIES}  pthread)
target_link_libraries(longestseq ${GTEST_LIBRARIES}  pthread)
