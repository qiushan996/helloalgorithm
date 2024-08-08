#include<vector>
#include<algorithm>
#include<gtest/gtest.h>
#include"../utils/linkedlist.h"

using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };



class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    //使用递归法实现
    // if(head == NULL || head->next == NULL){
    //   return head;
    // }

    // ListNode* p = reverseList(head->next);
    // head->next->next = head;
    // head->next =  NULL;
    // return p;

    ListNode* prve = NULL;
    ListNode* curr = head;
    while (curr != NULL)
    {
      ListNode* next = curr->next;
      curr->next = prve;
      prve = curr;
      curr = next;
    }
    return prve;
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
  
    ListNode* target = new ListNode(5);
    target->next = new ListNode(4);
    target->next->next = new ListNode(3);
    target->next->next->next = new ListNode(2);
    target->next->next->next->next = new ListNode(1);

    ListNode* result = solut.reverseList(head);
    EXPECT_TRUE(isEqualLinkedlists(target, result));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
