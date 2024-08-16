cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(560_sumequalK 560_sumequalK.cpp)
target_link_libraries(560_sumequalK ${GTEST_LIBRARIES} pthread)

add_executable(239_slidingwinMax 239_slidingwinMax.cpp)
target_link_libraries(239_slidingwinMax ${GTEST_LIBRARIES} pthread)

add_executable(76_minwindow 76_minwindow.cpp)
target_link_libraries(76_minwindow ${GTEST_LIBRARIES} pthread)
