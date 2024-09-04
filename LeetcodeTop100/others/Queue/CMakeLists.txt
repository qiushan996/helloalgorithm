cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(622_DesignCircularQueue 622_DesignCircularQueue.cpp)
target_link_libraries(622_DesignCircularQueue ${GTEST_LIBRARIES} pthread)

add_executable(225_ImplementStackuseQueue 225_ImplementStackuseQueue.cpp)
target_link_libraries(225_ImplementStackuseQueue ${GTEST_LIBRARIES} pthread)
