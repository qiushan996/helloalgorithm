add_library(MathFunctions MathFunctions.cpp)
option(USE_MYMATH "Use tutorial provide math implementation " ON)

if(USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
  # Add usage requirements for a library.
  target_include_directories(MathFunctions
                            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})   

  add_library(Sqrtlibrary STATIC
              mysqrt.cpp)    
              
  #target_link_libraries(MathFunctions PUBLIC  tutorial_compiler_flags)
  target_link_libraries(Sqrtlibrary PUBLIC tutorial_compiler_flags)
  target_link_libraries(MathFunctions PRIVATE Sqrtlibrary)

endif()