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
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> res;
    void order(Node* node){
        if(node == nullptr)
            return ;
        res.emplace_back(node->val);
        for(int i = 0; i < node->children.size();i++){
            order(node->children[i]);
        }
    }
public:
    // 递归
//    vector<int> preorder(Node* root) {
//        order(root);
//        return res;
//    }

    // 非递归
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == nullptr)
            return res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node *cur = stk.top();
            stk.pop();
            res.emplace_back(cur->val);
            for(int i = cur->children.size() - 1; i >= 0;i--){   // 因为栈是先进后出，所以需要倒叙遍历
                if(cur->children[i])
                    stk.push(cur->children[i]);
            }
        }
        return res;
    }
};

  // 一个函数递归的时候代价太大
//class Solution {
//private:
//    vector<int> res;
//public:
//    vector<int> preorder(Node* root) {
//        if(root == nullptr)
//            return res;
//        res.emplace_back(root->val);
//        for(int i = 0; i < root->children.size();i++){
//            preorder(root->children[i]);
//        }
//        return res;
//    }
//};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}