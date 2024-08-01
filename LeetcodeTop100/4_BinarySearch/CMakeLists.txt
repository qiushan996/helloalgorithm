cmake_minimum_required(VERSION 3.10)
project(leetodeTop100_BinarySearch)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Searchinsertpos   35_SearchInsertPos.cpp)
add_executable(Searchi2DMatrix   74_Search_2D_Matrix.cpp)
add_executable(LastPos           34_find_lastPos.cpp)

target_link_libraries(Searchinsertpos  ${GTEST_LIBRARIES}  pthread)
target_link_libraries(Searchi2DMatrix  ${GTEST_LIBRARIES}  pthread)
target_link_libraries(LastPos          ${GTEST_LIBRARIES}  pthread)

add_executable(33_RotatedSortArray 33_RotatedSortArray.cpp)
target_link_libraries(33_RotatedSortArray ${GTEST_LIBRARIES} pthread)

add_executable(153_MimRotatArray 153_MimRotatArray.cpp)
target_link_libraries(153_MimRotatArray ${GTEST_LIBRARIES} pthread)
