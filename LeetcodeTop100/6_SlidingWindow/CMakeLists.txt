cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(3_withoutrepstr 3_withoutrepstr.cpp)
target_link_libraries(3_withoutrepstr ${GTEST_LIBRARIES} pthread)

add_executable(438_Allanagrams 438_Allanagrams.cpp)
target_link_libraries(438_Allanagrams ${GTEST_LIBRARIES} pthread)
