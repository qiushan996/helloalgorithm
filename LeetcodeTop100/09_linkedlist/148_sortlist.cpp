#include<vector>
#include<iostream>
#include<gtest/gtest.h>
#include"utils/linkedlist.h"

using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
      // 归并排序：链表最常见的排序方式
      if(head == NULL || head->next == NULL)  return head;

      ListNode* second = head;
      ListNode* first= head->next;
      while (first != NULL && first->next != NULL)
      {
        second = second->next;
        first = first->next->next;
      }

      ListNode* mid = second->next;
      second->next = NULL;
      
      ListNode* left = sortList(head);
      ListNode* right = sortList(mid);

      
      return merge(left, right);
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);  // 哑节点，用于简化合并操作
        ListNode* tail = &dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // 将剩余的链表部分连接到结果链表中
        tail->next = (l1 != NULL) ? l1 : l2;

        //std::cout<<"result: "<<dummy.val <<std::endl;
        return dummy.next;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    ListNode* target = new ListNode(1);
    target->next = new ListNode(2);
    target->next->next = new ListNode(3);
    target->next->next->next = new ListNode(4);
    
    ListNode* result = solut.sortList(head);
    //测试
    
    EXPECT_TRUE(isEqualLinkedlists(target, result));

    // delete head->next->next->next;
    // delete head->next->next;
    // delete head->next;
    // delete head;

    // delete target->next->next->next;
    // delete target->next->next;
    // delete target->next;
    // delete target;
}

TEST(XXXTest, Case2){
    Solution solut;
    
    ListNode* head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);

    ListNode* target = new ListNode(-1);
    target->next = new ListNode(0);
    target->next->next = new ListNode(3);
    target->next->next->next = new ListNode(4);
    target->next->next->next->next = new ListNode(5);

    EXPECT_TRUE(isEqualLinkedlists(target, solut.sortList(head)));

    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    delete target->next->next->next->next;
    delete target->next->next->next;
    delete target->next->next;
    delete target->next;
    delete target;
}

TEST(XXXTest, Case3){
    Solution solut;
    
    ListNode* head = new ListNode(0,NULL);
    ListNode* target = new ListNode(0,NULL);

    EXPECT_TRUE(isEqualLinkedlists(target, solut.sortList(head)));

    delete head;
    delete target;
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
