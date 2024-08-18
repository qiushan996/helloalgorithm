cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(136_SingleNumber 136_SingleNumber.cpp)
target_link_libraries(136_SingleNumber ${GTEST_LIBRARIES} pthread)

add_executable(169_majorityelement 169_majorityelement.cpp)
target_link_libraries(169_majorityelement ${GTEST_LIBRARIES} pthread)

add_executable(75_sortColor 75_sortColor.cpp)
target_link_libraries(75_sortColor ${GTEST_LIBRARIES} pthread)
