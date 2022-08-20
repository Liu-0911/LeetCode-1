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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 不添加虚头结点
//    ListNode* removeElements(ListNode* head, int val) {
//        // 删除头节点
//        ListNode *tmp = NULL;
//        while(head != NULL && head->val == val){
//            tmp = head;
////            ListNode *tmp = head;
//            head = head->next;
//            delete tmp;
//        }
//        // 删除非头节点
//        ListNode *cur = head;
//        while(cur != NULL && cur->next != NULL){
//            if(cur->next->val == val)
//            {
//                ListNode *tmp = cur -> next;
//                cur -> next = tmp -> next;
//                delete tmp;
//            } else
//                cur =  cur -> next;
//        }
//        return head;
//    }


    // 添加虚头结点
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyHead = new ListNode(0,head);
        ListNode *cur = dummyHead;
        while(cur -> next != NULL )
        {
            if(cur -> next ->val == val){
                ListNode *tmp = cur -> next;
                cur -> next = tmp -> next;
                delete tmp;
            } else
                cur = cur -> next;
        }
        head = dummyHead -> next;
        delete dummyHead;
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    return 0;
}