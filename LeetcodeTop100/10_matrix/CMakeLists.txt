cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(73_set_matrix_zeroes 73_set_matrix_zeroes.cpp)
target_link_libraries(73_set_matrix_zeroes ${GTEST_LIBRARIES} pthread)

add_executable(54_sprial_matrix 54_sprial_matrix.cpp)
target_link_libraries(54_sprial_matrix ${GTEST_LIBRARIES} pthread)

add_executable(48_rotateImage 48_rotateImage.cpp)
target_link_libraries(48_rotateImage ${GTEST_LIBRARIES} pthread)

add_executable(240_search2Dmatrix 240_search2Dmatrix.cpp)
target_link_libraries(240_search2Dmatrix ${GTEST_LIBRARIES} pthread)
