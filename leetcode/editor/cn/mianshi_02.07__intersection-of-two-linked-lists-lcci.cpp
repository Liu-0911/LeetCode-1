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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *strA = headA;
        ListNode *strB = headB;
        int lenA = 0, lenB = 0;
        while(strA){
            lenA++;
            strA = strA->next;
        }
        while (strB){
            lenB++;
            strB = strB->next;
        }
        strA = headA;
        strB = headB;
        if(lenB > lenA){
            swap(headA,headB);
            swap(strB,strA);
        }
        int diff = lenA - lenB;
        while(diff--){
            strA = strA->next;
        }
        while(strA != nullptr){
            if(strA == strB)
                return strA;
            strA = strA->next;
            strB = strB->next;
        }
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    return 0;
}