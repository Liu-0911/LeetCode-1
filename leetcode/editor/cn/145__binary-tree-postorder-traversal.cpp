#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 递归
//    void trans(TreeNode* cur,vector<int>& res){
//        if(cur == nullptr)
//            return;
//        trans(cur->left,res);
//        trans(cur->right,res);
//        res.emplace_back(cur->val);
//    }
//    vector<int> postorderTraversal(TreeNode* root) {
//        vector<int> res;
//        trans(root,res);
//        return res;
//    }
//     非递归  先序遍历为 中左右  调整左右子树放分顺序->中右左 反转res数组->左右中
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if(root == nullptr)
            return {};
        stk.push(root);
        while(!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            res.emplace_back(cur->val);
            if(cur->left != nullptr) stk.push(cur->left);
            if(cur->right != nullptr) stk.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
//    vector<int> postorderTraversal(TreeNode* root) {
//        vector<int> res;
//        stack<TreeNode*> stk;
//        if(root == nullptr)
//            return {};
//        stk.push(root);
//        while(!stk.empty()){
//            auto cur = stk.top();
//            stk.pop();
//            if(cur->right != nullptr) stk.push(cur->right);
//            if(cur->left != nullptr) stk.push(cur->left);
//            res.emplace_back(cur->val);
//        }
//        reverse(res.begin(), res.end());
//        return res;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}