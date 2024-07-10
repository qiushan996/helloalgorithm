cmake_minimum_required(VERSION 3.10)
project(tutorial_step5)

# 错误的写法
# set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX, ARMClang, AppleClang, Clang, GNU, LCC> ")
# set(msvc_cxx "$<COMPLIE_LANG_AND_ID: CXX, MSVC>")


set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)
target_compile_options(tutorial_compiler_flags INTERFACE 
                      "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
                      "$<${msvc_cxx}:$<BUILDINTERFACE:-W3>>")
# 在执行cmake ..时会额外的输出编译器信息，如:
# -- The C compiler identification is AppleClang 15.0.0.15000309
# -- The CXX compiler identification is AppleClang 15.0.0.15000309


# 调用MathFunctions库函数
include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
add_subdirectory(MathFunctions)

add_executable(tutorial tutorial.cpp)

target_link_libraries(tutorial PUBLIC MathFunctions tutorial_compiler_flags )  # 唯一调用库函数的地方
target_include_directories(tutorial PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          )
install(TARGETS tutorial  DESTINATION bin)
install(FILES TutorialConfig.h
        DESTINATION  include)     



########################################################
# CTest support
# enabel CTest
enable_testing()
# add some test case
add_test(NAME Uasge COMMAND tutorial )
set_tests_properties(Uasge
    PROPERTIES PASS_REGULAR_EXPRESSION "Uasge:.*number"
    )
add_test(NAME StandardUse COMMAND Tutorial 4)
set_tests_properties(StandardUse
  PROPERTIES PASS_REGULAR_EXPRESSION "4 is 2"
  )  
    
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# do a bunch of result based tests
do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 81 "81 is 9")
do_test(Tutorial 100 "100 is 10")