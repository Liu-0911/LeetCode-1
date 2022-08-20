#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return {};
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr){
            if(fast->val != slow->val){
                slow = slow->next;
                slow->val = fast->val;
            }
            fast = fast->next;
        }
        slow->next = nullptr;   // 注意链表的最后需要把指针置空
        return  head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution sloution;
    return 0;
}