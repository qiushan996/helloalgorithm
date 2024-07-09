# #Exercise 1
# # specifying a minimum CMake version
# cmake_minimum_required(VERSION 3.10)

# # set the project name
# project(Tutorial_step1)

# # create an executable using the specified source code files.
# add_executable(tutorial tutorial.cpp)


# Excerise 2
# cmake_minimum_required(VERSION 3.10)
# project(tutorial_step1)

# # specific C++ standard in CMake
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# add_executable(tutorial tutorial.cpp)


# Excerise 3
cmake_minimum_required(VERSION 3.10)
project(tutorila)
# set VERSION
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 5) 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# 配置一个头文件将一些 CMake 设置传入到源代码中
# 以 TutorialConfig.h.in 为模版，替换相关变量
# 以生成 TutorialConfig.h
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h"
  )


add_executable(tutorial tutorial.cpp)

# 将构建目录添加到 include 的搜索路径中以便找到
# target_include_directories 必须在add_executable之后
target_include_directories(tutorial PUBLIC "${PROJEC_BINARY_DIR}")



