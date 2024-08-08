/*  题目描述: 234_回文链表
Given the head of a singly linked list, return true if it is a  palindrome or false otherwise.
给定一个单链表的头，如果它是一个则返回 true 回文 否则为假。

Example1:
Input: head = [1,2,2,1]
Output: true

Example2:
Input: head = [1,2]
Output: false
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>
#include"./utils/linkedlist.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
      if(head == NULL || head->next == NULL) return true;

      //找中点：快慢指针
      ListNode* slow = head;
      ListNode* fast = head;

      while (fast != NULL && fast->next !=NULL)
      {
        slow = slow->next;
        fast = fast->next->next;
      }
      
      //反转剩下的部分
      ListNode* secondHalfstart = reverseList(slow);
      ListNode* firstHalfStart = head;

      //对比前后两部分是否相同
      bool  palindrome = true;
      ListNode* p1 = firstHalfStart;
      ListNode* p2 = secondHalfstart;

      while (palindrome && p2!=NULL)
      {
        if(p1->val != p2->val) palindrome = false;
        p1 = p1->next;
        p2 = p2->next;
      }
      
      reverseList(secondHalfstart);
      return palindrome;
    }

private:
  ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL)
    {
      ListNode* nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }
    return prev;
  }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    EXPECT_TRUE(solut.isPalindrome(head));
}

TEST(XXXTest, Case2){
    Solution solut;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    EXPECT_FALSE(solut.isPalindrome(head));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
