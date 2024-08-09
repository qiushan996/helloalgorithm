/* 题目描述: 21_合并两个有序链表

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>
#include"utils/linkedlist.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      //使用递归法解
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    if(list1->val <list2->val){
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    }else{
      list2->next = mergeTwoLists(list2->next, list1);
      return list2;
    }
  }

};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next  = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* target = new ListNode(1);
    target->next = new ListNode(1);
    target->next->next = new ListNode(2);
    target->next->next->next = new ListNode(3);
    target->next->next->next->next = new ListNode(4);
    target->next->next->next->next->next = new ListNode(4);

    EXPECT_TRUE(isEqualLinkedlists(target, solut.mergeTwoLists(list1, list2)));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
