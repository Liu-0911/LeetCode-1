#include<vector>
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, * slow = head; // 快指针一次走两步，慢指针一次走一步，若再次相遇则证明有环
        while(fast != nullptr && fast->next != nullptr )
//        while(fast->next != nullptr && fast->next->next != nullptr)   注意题目条件 链表中节点的数目范围在范围 [0, 104] 内 即有可能节点数目为0
        {
            fast = fast->next->next;
            slow = slow->next;
            if( fast == slow){
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    return 0;
}