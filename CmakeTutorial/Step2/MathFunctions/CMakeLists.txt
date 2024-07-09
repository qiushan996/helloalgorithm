add_library(MathFunctions MathFunctions.cpp)
option(USE_MYMATH "Use tutorial provide math implementation " ON)

if(USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  add_library(Sqrtlibrary STATIC
              mysqrt.cpp)    
              
  target_link_libraries(MathFunctions PRIVATE Sqrtlibrary)
endif()