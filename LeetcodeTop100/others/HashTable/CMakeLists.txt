cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(705_DesignHashSet 705_DesignHashSet.cpp)
target_link_libraries(705_DesignHashSet ${GTEST_LIBRARIES} pthread)

add_executable(706_DesignHashMap 706_DesignHashMap.cpp)
target_link_libraries(706_DesignHashMap ${GTEST_LIBRARIES} pthread)

add_executable(1941_CheckifAllCharEqual 1941_CheckifAllCharEqual.cpp)
target_link_libraries(1941_CheckifAllCharEqual ${GTEST_LIBRARIES} pthread)

add_executable(41_FirstMissingPositive 41_FirstMissingPositive.cpp)
target_link_libraries(41_FirstMissingPositive ${GTEST_LIBRARIES} pthread)
