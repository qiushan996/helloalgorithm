cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(1925_countsquare 1925_countsquare.cpp)
target_link_libraries(1925_countsquare ${GTEST_LIBRARIES} pthread)

add_executable(1450_NumberOfStudents 1450_NumberOfStudents.cpp)
target_link_libraries(1450_NumberOfStudents ${GTEST_LIBRARIES} pthread)

add_executable(23_MergekSortedLists 23_MergekSortedLists.cpp)
target_link_libraries(23_MergekSortedLists ${GTEST_LIBRARIES} pthread)
