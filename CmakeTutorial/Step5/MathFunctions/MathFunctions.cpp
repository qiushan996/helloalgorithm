#include "MathFunctions.h"
#include<string>
#include<iostream>

#ifdef USE_MYMATH
#include "mysqrt.h"
#endif


#include<cmath>


void toString(std::string input)
{
  int len = input.length();
  for(int i=0; i<len; i++){
    std::cout<<input[i]<<"_";
  }
  std::cout<<std::endl;
  return ;
}


double ssqrt(int x){
#ifdef USE_MYMATH
  return mysqrt(x);
#else 
  return sqrt(x);
#endif
}