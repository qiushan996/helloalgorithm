### CMake使用 官方教程

网址： https://cmake.org/cmake/help/latest/guide/tutorial/index.html


[An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/)

#### 目录

**Step 1: A Basic Starting Point**

- cmake_minimum_required(): 指定一个最小的CMAKE版本，确保一下的CMAKE函数在兼容的版本下运行

- project(): 指定项目名称、语言、版本号等信息

- add_executable(): 使用指定的源文件生成可执行文件

- 使用set():  指定构建项目使用的C++标准
  ```
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
  ```

- 使用set(): 设置项目版本号
  ```
  set(Tutorial_VERSION_MAJOR 1)
  set(Tutorial_VERSION_MINOR 5) 
  ```

- configure_file():将一个给定的输入文件复制到一个输出文件中，并在输入文件内容中替换一些变量值。

- target_include_directories(): 指定可执行目标应在哪里查找包含文件

- 一些常见的CMAKE变量
  ```
  CMAKE_SOURCE_DIR: 根源文件目录，即包含顶层 CMakeLists.txt 文件的目录。
  CMAKE_BINARY_DIR: 根构建目录，即运行 CMake 生成构建文件的目录。
  PROJECT_SOURCE_DIR: 当前项目的源文件目录。对于主项目，它与 CMAKE_SOURCE_DIR 相同；对于子项目，它指向子项目的源文件目录。
  PROJECT_BINARY_DIR: 当前项目的构建目录。对于主项目，它与 CMAKE_BINARY_DIR 相同；对于子项目，它指向子项目的构建目录。
  CMAKE_CURRENT_SOURCE_DIR: 当前处理的 CMakeLists.txt 文件所在的源文件目录。
  CMAKE_CURRENT_BINARY_DIR: 当前处理的 CMakeLists.txt 文件的构建目录。
  CMAKE_INSTALL_PREFIX: 安装前缀，通常用于指定安装路径，默认为 /usr/local。
  CMAKE_CXX_COMPILER: 指定的 C++ 编译器的路径。
  CMAKE_C_COMPILER: 指定的 C 编译器的路径。
  CMAKE_BUILD_TYPE: 指定构建类型，如 Debug、Release、MinSizeRel 或 RelWithDebInfo。
  CMAKE_PROJECT_NAME: 顶层项目的名称。
  PROJECT_NAME: 当前项目的名称。
  ```
**Step 2: Adding a Library**
  - Exercise 1 - Creating a Library
  - Exercise 2 - Adding an Option

**Step 3: Adding Usage Requirements for a Library**
  - Exercise 1 - Adding Usage Requirements for a Library
  - Exercise 2 - Setting the C++ Standard with Interface Libraries

**Step 4: Adding Generator Expressions**
  - Exercise 1 - Adding Compiler Warning Flags with Generator Expressions

**Step 5: Installing and Testing**
  - Exercise 1 - Install Rules
  - Exercise 2 - Testing Support

**Step 6: Adding Support for a Testing Dashboard**
  - Exercise 1 - Send Results to a Testing Dashboard

**Step 7: Adding System Introspection**
  - Exercise 1 - Assessing Dependency Availability

**Step 8: Adding a Custom Command and Generated File**

**Step 9: Packaging an Installer**

**Step 10: Selecting Static or Shared Libraries**

**Step 11: Adding Export Configuration**

**Step 12: Packaging Debug and Release**

