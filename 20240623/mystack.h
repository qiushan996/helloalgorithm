/*
使用数组和链表两种方式实现一个栈，包含标准库中的基本操作：

- 入栈：向栈顶添加元
- 出栈：弹出栈顶元素
- 判断是否为空：
- 获取栈大小
- 访问栈顶元素
*/

#include <stdexcept>
#include<stack>
#include<iostream>
#include<vector>

struct LinkedNode
{
  int value;
  LinkedNode* next;
  LinkedNode(int val): value(val), next(nullptr){};
};


//方式1:使用链表
class Stacklink
{
private:
  LinkedNode* stacktop;  //栈顶
  int  stack_size;   //栈大小

public:
  Stacklink(/* args */){
  stack_size =0;
  stacktop = nullptr;
  }
  ~Stacklink(){
    delete stacktop;  //待考虑
  }

  //获取栈大小
  int size(){
    return stack_size;
  }
  //判断栈是否为空
  bool isEmpty(){
    return size()==0;
  }
  //或栈栈顶元素
  int top(){
    //先判断栈是否为空
    if(isEmpty()) 
    throw std::out_of_range("栈为空");
    //若栈不为空，返回栈顶元素
    return stacktop->value;
  }

  //入栈操作：push
  void  push(int target){
    LinkedNode* newtop = new LinkedNode(target);
    newtop->next = stacktop;
    stacktop = newtop;
    stack_size++;   //栈大小+1
  }

  //出栈操作：pop
  int pop(){
    int etop = top();  //获取栈顶元素
    LinkedNode* newtop  = stacktop;
    stacktop = stacktop->next;
    delete newtop;
    stack_size--;
    return etop;
  }

  //返回栈中的所有元素，转化为vector
  std::vector<int> tovector(){
    std::vector<int>  res(size());
    LinkedNode* node = stacktop;
    // while(!isEmpty()){
    //   res.push_back(node->value);
    //   node = node->next;
    //   }
    for(int i=0; i<size(); i++){
      res[i] = node->value;
      node = node->next;
    }
    std::cout<<"转换成功！"<<std::endl;
    return res;
    }
};


//方式2: 使用数组(动态数组)
class StackArry
{
private:
  std::vector<int>  stack;
public:
  StackArry(/* args */){
    
  }
  ~StackArry(){
   
  }
  int size(){
    return stack.size();
  }

  bool isempty(){
    return stack.size()==0;
  }

  //获取栈顶元素
  int top(){
    if(isempty())
      throw std::out_of_range("栈为空");
    return stack.back();
  }

  //入栈
  void push(int value){
    stack.push_back(value);
  }
  //出栈
  int pop(){
    int num = top();
    stack.pop_back();
    return num;
  }
};

