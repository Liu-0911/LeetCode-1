#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


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
    TreeNode* invertTree(TreeNode* root) {
        // 递归法
//        if(root == nullptr)
//            return root;
//        swap(root->left,root->right);
//        invertTree(root->left);
//        invertTree(root->right);
//        return root;


        // 迭代法---前序遍历
//        if(root == nullptr)
//            return root;
//        stack<TreeNode*> stk;
//        stk.push(root);
//        while(!stk.empty()){
//            TreeNode *cur = stk.top();    // 中
//            stk.pop();
//            swap(cur->left,cur->right);
//            if(cur->right) stk.push(cur->right); // 右
//            if(cur->left) stk.push(cur->left); // 左
//        }
//        return root;

        // 层序遍历
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i < size;i++){
                TreeNode* cur = que.front();
                que.pop();
                swap(cur->left,cur->right);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return root;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}