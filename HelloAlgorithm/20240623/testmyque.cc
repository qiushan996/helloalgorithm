#include"myqueue.h"
#include<iostream>

using namespace std;

void test_linked_que(){
  // Queuelinked  lique;
  // lique.push(25.90);
  // lique.push(45.0089);
  // lique.push(78.98);
  // lique.push(90.999);

  // lique.dispaly();
  // cout<<"队列大小："<<lique.size()<<", 队列首元素："<<lique.top()<<endl;
  // //插入新元素
  // lique.push(777.89);
  // lique.push(565.0075);
  // cout<<"队列大小："<<lique.size()<<", 队列首元素："<<lique.top()<<endl;
}

void test_array_que(){

  //定义变量:指定类型，初始化容量
  ArrayQue<string>  arrque(6);
  arrque.push("English");
  arrque.push("French");
  arrque.push("Chinese");
  arrque.push("Japanese");

  cout<<"队列容量:"<<arrque.Capacity()<<"  队列大小: "<<arrque.Size()<<"队列首元素："<<arrque.peek()<<endl;

  //遍历队列
  arrque.display();

  arrque.push("Rusine");
  arrque.push("German");
  arrque.push("Vitname");
  arrque.push("Indan");
  arrque.display();  

}
int main(){
  test_array_que();
}