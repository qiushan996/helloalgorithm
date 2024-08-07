cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(121_besttimestock 121_besttimestock.cpp)
target_link_libraries(121_besttimestock ${GTEST_LIBRARIES} pthread)

add_executable(55_Jumpgame 55_Jumpgame.cpp)
target_link_libraries(55_Jumpgame ${GTEST_LIBRARIES} pthread)

add_executable(763_partitionLables 763_partitionLables.cpp)
target_link_libraries(763_partitionLables ${GTEST_LIBRARIES} pthread)
