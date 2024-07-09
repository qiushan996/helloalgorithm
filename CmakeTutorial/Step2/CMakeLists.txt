cmake_minimum_required(VERSION 3.10)
project(tutorial_step2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# 调用MathFunctions库函数
include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
add_subdirectory(MathFunctions)
add_executable(tutorial tutorial.cpp)


target_link_libraries(tutorial PUBLIC MathFunctions )
target_include_directories(tutorial PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions")

