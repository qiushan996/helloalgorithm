cmake_minimum_required(VERSION 3.10)
project(tutorial_step3)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)


# 调用MathFunctions库函数
include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
add_subdirectory(MathFunctions)

add_executable(tutorial tutorial.cpp)

target_link_libraries(tutorial PUBLIC MathFunctions tutorial_compiler_flags )  # 唯一调用库函数的地方
target_include_directories(tutorial PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          )

