#include<iostream>
#include<stack>

int main(){
  //初始化
  std::stack<int>  st;


  //入栈操作
  st.push(445);
  st.push(89);
  st.push(88);
  st.push(112);

  //遍历栈中的元素
  // std::cout<<"栈中的元素: ";
  // while (!st.empty())
  // {
  //   std::cout<<st.top()<<", ";
  //   st.pop();
  // }
  // std::cout<<std::endl;

  //访问栈顶元素
  std::cout<<"当前的栈顶元素："<<st.top()<<std::endl;

  //获取栈大小
  std::cout<<"栈大小："<<st.size()<<std::endl;
  //判断是对否为空
  std::cout<<"是否为空栈： "<<st.empty()<<std::endl;


  //出栈
  st.pop();  //函数无返回值
  std::cout<<"出栈后大小："<<st.size()<<" 出栈后的栈顶元素："<<st.top()<<std::endl;
  
  return 0;

}