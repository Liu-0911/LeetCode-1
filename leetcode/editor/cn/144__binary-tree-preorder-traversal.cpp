#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>


//Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    // 递归
//    void trans(TreeNode* cur,vector<int>& res){
//        if(cur == nullptr)
//            return;
//        res.emplace_back(cur->val);
//        trans(cur->left,res);
//        trans(cur->right,res);
//    }
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> res;
//        trans(root,res);
//        return res;
//    }


    // 非递归
        vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if(root == nullptr)
            return {};
        stk.push(root);
        while(!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            res.emplace_back(cur->val);
            if(cur->right != nullptr) stk.push(cur->right); // 栈为先进后出，所以右子树先入栈
            if(cur->left != nullptr) stk.push(cur->left);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}