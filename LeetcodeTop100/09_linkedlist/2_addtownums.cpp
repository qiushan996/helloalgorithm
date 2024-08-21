/*题目描述:  2_两数之和
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
给您两个表示两个非负整数的非空链表。这些数字以相反的顺序存储，并且每个节点都包含一个数字。将两个数字相加并以链接列表的形式返回总和。

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
您可以假设这两个数字不包含任何前导零，除了数字 0 本身。

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>
#include"utils/linkedlist.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dump = new ListNode(0);
    ListNode* current = dump;
    int carry = 0;

    while(l1 != NULL || l2!=NULL){
      int x = (l1 != NULL) ? l1->val : 0;
      int y = (l2 != NULL) ? l2->val : 0;

      int sum = x + y + carry;

      carry = sum /10;
      current->next = new ListNode(sum %10);
      current = current->next;

      if(l1 != NULL) l1 = l1->next;
      if(l2 != NULL) l2 = l2->next;
    }
    if(carry > 0){
      current->next = new ListNode(carry);
    }

    return dump->next;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    ListNode* list1 = new ListNode(2);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(5);
    list2->next  = new ListNode(6);
    list2->next->next = new ListNode(4);

    ListNode* target = new ListNode(7);
    target->next = new ListNode(0);
    target->next->next = new ListNode(8);
  

    EXPECT_TRUE(isEqualLinkedlists(target, solut.addTwoNumbers(list1, list2)));

    delete target->next->next;
    delete target->next;
    delete target;

    delete list2->next->next;
    delete list2->next;
    delete list2;

    delete list1->next->next;
    delete list1->next;
    delete list1;
}

TEST(XXXTest, Case2){

  ListNode* l1 = new ListNode(0);
  ListNode* l2 = new ListNode(0);
  ListNode* target = new ListNode(0);

  Solution solut;
  EXPECT_TRUE(isEqualLinkedlists(target, solut.addTwoNumbers(l1, l2)));

  delete l1;
  delete l2;
  delete target;
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
