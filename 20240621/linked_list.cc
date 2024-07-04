#include<iostream>
#include<string>

//单链表的一个节点: 主要用途实现栈、队列、哈希表、图等复杂的数据结构
struct linked_list
{
  std::string  value;
  linked_list* next;
  linked_list(std::string x): value(x), next(nullptr){};
};

//双向链表的节点结构
struct ListNode{
  int value;
  ListNode* preNode;
  ListNode* NextNode;
  ListNode(int x): value(x), preNode(nullptr), NextNode(nullptr){};
};

//打印显示链表
void display_linked_list(linked_list* l1){
  linked_list* tmp = l1;
  while (tmp!= nullptr)
  {
    std::cout<<tmp->value<<"  ";
    tmp = tmp->next;
  }
  std::cout<<std::endl;
  return;
}

//删除链表元素
linked_list*  delete_linked_list_element(linked_list* n1, std::string x){
  //删除链表中值为x的节点
  //方法1:添加虚拟头节点
  // linked_list* tmp ;
  // tmp->next =n1;

  // linked_list* first = tmp;
  // while (first->next!=nullptr)
  // {
  //   if(first->next->value==x){
  //     first->next = first->next->next;
  //   }else first = first->next;
  // }
  // return tmp->next;

  // 方式2:递归法
  if(n1==NULL) return NULL;
  linked_list*  p = delete_linked_list_element(n1->next, x);
  if(n1->value == x)return p;
  else{
    n1->next = p;
    return n1;
  }
}

//查找链表元素
void search_element(linked_list* nodes, std::string target){
  int index = 0;
  while (nodes!=nullptr)
  {
    if(nodes->value==target){
      std::cout<<"find it:" <<nodes->value<<" in "<<index<<"th element"<<std::endl;
      break;
    }
    index++;
    nodes = nodes->next;
  }

  std::cout<<"can't find the target element in linked_list"<<std::endl;
  
}

//在尾部插入一个元素
linked_list* insert_tail(linked_list* n1, std::string target){
  //创建一个新的节点
  linked_list* newnode = new linked_list(target);
  if(n1==nullptr){
    n1 = newnode;
    return n1;
  }else{
    linked_list* tmp = n1;
    while (tmp->next!=nullptr)
    {
      tmp = tmp->next;
    }
    tmp->next = newnode;
    
    return n1;
  }
}


//单链表练习
void signle_linked_list(){
  //初始化一个单链表
  linked_list* n1 = new linked_list("Java");
  linked_list* n2 = new linked_list("c++");
  linked_list* n3 = new linked_list("javascript");
  linked_list* n4 = new linked_list("python");
  linked_list* n5 = new linked_list("rust");

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = nullptr;    //n5->next = n1 就是一个循环链表了

  //遍历单链表
  std::cout<<"初始化的单链表:"<<std::endl;
  display_linked_list(n1);

  //删除链表元素
  std::string target = "c++";
  linked_list* dele_list = delete_linked_list_element(n1, "c++");
  std::cout<<"删除单链表元素后:"<<std::endl;
  display_linked_list(dele_list);

  search_element(n1, "rusts");
}

int main(){

   //signle_linked_list();
   linked_list* n1 = new linked_list("hello");
   linked_list* n2 = new linked_list("linked list");
   linked_list* n3 = new linked_list("single ");
   n1->next = n2;
   n2->next = n3;
   std::cout<<"原始链表："<<std::endl;
   display_linked_list(n1);

   linked_list* new_list = insert_tail(n1, "new elements");
   display_linked_list(new_list);


   linked_list* listnull = new linked_list("");
   linked_list* listnull_a = insert_tail(listnull, "nulllist");
   display_linked_list(listnull_a);

   return 0;
}