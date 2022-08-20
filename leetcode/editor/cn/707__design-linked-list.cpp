#include<vector>
#include<iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class MyLinkedList {
public:
    struct  LinkNode{
        int val;
        LinkNode* next;
        LinkNode():val(0),next(nullptr){}
        LinkNode(int val):val(val),next(nullptr){}
    };
    MyLinkedList() {
        dummyHead = new LinkNode(0);
        size =0;
    }
    
    int get(int index) {
        if(index > size -1 || index < 0)
            return -1;
        LinkNode* cur = dummyHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkNode* tmp = new LinkNode(val);
        tmp->next = dummyHead->next;
        dummyHead->next = tmp;
        size++;
    }
    
    void addAtTail(int val) {
        LinkNode* tmp = new LinkNode(val);
        LinkNode* cur = dummyHead;
        while(cur->next != nullptr)
            cur = cur->next;
        cur->next = tmp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size)
            return;
        LinkNode* tmp = new LinkNode(val);
        LinkNode* cur = dummyHead;
        while(index--)
            cur = cur->next;
        tmp->next = cur->next;
        cur->next = tmp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size || index < 0)
            return;
        LinkNode* cur = dummyHead;
        while(index--)
            cur = cur->next;
        LinkNode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        size--;
    }

    void printLinkList(){
        LinkNode* cur = dummyHead;
        while(cur->next != nullptr){
            cout<<cur->next->val<<"->";
            cur = cur->next;
        }
        cout<<endl;
    }
private:
    LinkNode* dummyHead;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    return 0;
}