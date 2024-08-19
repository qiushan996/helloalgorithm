cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(215_kthlargest_elemArray 215_kthlargest_elemArray.cpp)
target_link_libraries(215_kthlargest_elemArray ${GTEST_LIBRARIES} pthread)

add_executable(347_Topk_frequElement 347_Topk_frequElement.cpp)
target_link_libraries(347_Topk_frequElement ${GTEST_LIBRARIES} pthread)
