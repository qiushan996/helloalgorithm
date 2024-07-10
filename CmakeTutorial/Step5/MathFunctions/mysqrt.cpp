#include "mysqrt.h"
#include<iostream>

//使用牛顿迭代法实现的一个开平方函数
double mysqrt(double number, double tolerance) {
  std::cout<<"the custom square root implementation"<<std::endl;
    if (number < 0) {
        throw std::invalid_argument("Negative input not allowed");
    }

    if (number == 0) {
        return 0;
    }

    double guess = number / 2.0;
    while (std::abs(guess * guess - number) > tolerance) {
        guess = (guess + number / guess) / 2.0;
    }
    return guess;
}