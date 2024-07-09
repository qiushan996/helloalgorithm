

//note:
// 在 .h 文件中声明函数并设置默认参数时，不需要在 .cpp 文件中重复指定默认参数。否则会引起冲突
// 这是因为默认参数只能在函数声明（通常在头文件中）中指定，而不能在函数定义（通常在源文件中）中重复指定。
double mysqrt(double number, double tolerance = 1e-10);