#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
//    Node* connect(Node* root) {
//        queue<Node*> que;
//        if(root != nullptr) que.push(root);
//        while(!que.empty()){
//            int size = que.size();
//            Node* pre = nullptr;
//            Node* cur;
//            for(int i = 0;i < size;i++){
//                cur = que.front();
//                que.pop();
//                if(pre != nullptr)
//                    pre->next = cur;
//                pre = cur;
//                if(cur->left) que.push(cur->left);
//                if(cur->right) que.push(cur->right);
//            }
////            cur->next = nullptr;
//        }
//        return root;
//    }
    // 优化版本——不需要队列,使用链表思想
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        Node * cur = root;
        Node *dummy = new Node();
        while(cur != nullptr){   // 遍历当前层
            Node *pre = dummy;
            while(cur != nullptr){ // 处理下一层
                if(cur->left){
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if(cur->right){
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            cur = dummy->next;
            dummy->next = nullptr;  // 与上一层断开连接
        }
        delete dummy;
        return root;
}
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    Node * a = new Node(1);
    Node * a1 = new Node(2);
    Node * a2 = new Node(3);
    a->left = a1;
    a->right = a2;
    Node * b = a;
    b->left = a2;
    cout<<a->left->val<<endl;
    cout<<b->left->val;
    return 0;
}