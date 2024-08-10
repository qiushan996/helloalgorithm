/* 题目描述: 19_删除链表的倒数第N个节点

Given the head of a linked list, remove the nth node from the end of the list and return its head.

给定一个链表的头，从链表末尾移除第 n 个节点并返回其头。

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>
#include"utils/linkedlist.h"

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //可以使用双指针法，让两个指针之间保持一定的距离（n个节点），然后同时移动两个指针，
    //当前指针到达链表末尾时，另一个指针正好指向需要删除的节点的前一个节点。

    ListNode dump(0);

    dump.next = head;
    ListNode* first = &dump;
    ListNode* second = &dump;

    //先让first移动n
    for(int i = 0; i<=n; i++){
      first = first->next;
    }

    while (first != NULL)
    {
      first = first->next;
      second = second->next;
    }
    
    //此时second的下一个节点是需要删除的节点
    ListNode* nodeDelete = second->next;
    second->next = nodeDelete->next;

    //delete node
    delete nodeDelete;

    return dump.next;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = solut.removeNthFromEnd(head, 2);
    ListNode* target = new ListNode(1);
    target->next = new ListNode(2);
    target->next->next = new ListNode(3);
    target->next->next->next = new ListNode(5);


    EXPECT_TRUE(isEqualLinkedlists(target, result));

    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    delete target->next->next->next;
    delete target->next->next;
    delete target->next;
    delete target;
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
