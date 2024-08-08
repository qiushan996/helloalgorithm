/* 题目描述: 141_环形链表

*/
#include<vector>
#include"utils/linkedlist.h"
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //基本思想：快慢指针法
        //快慢指针遍历链表，如果存在环，快指针时钟会追上慢指针
        if(head == NULL || head->next == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow!=fast)
        {
          if(fast == NULL || fast->next == NULL) return false;
          slow = slow->next;
          fast = fast->next->next;
        }
        return true;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    ListNode* head = new ListNode(3);
    ListNode* secode = new ListNode(2);
    ListNode* third = new ListNode(1);
    ListNode* forth = new ListNode(-4);

    head->next = secode;
    secode->next = third;
    third->next = forth;
    forth->next = secode;
    EXPECT_TRUE(solut.hasCycle(head));
}

TEST(XXXTest, Case2){
    Solution solut;
    ListNode* head = new ListNode(3);
    ListNode* secode = new ListNode(2);
    head->next = secode;
    secode->next = head;
    EXPECT_TRUE(solut.hasCycle(head));
}

TEST(XXXTest, Case3){
    Solution solut;
    ListNode* head = new ListNode(1);
    EXPECT_FALSE(solut.hasCycle(head));
}
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
